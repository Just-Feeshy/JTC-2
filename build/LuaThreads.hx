package;

#if (USING_LUA && cpp)
import llua.Lua;
import llua.Lua.Lua_helper;
import llua.State;
#end

#if sys
import sys.FileSystem;
import sys.thread.Thread;
import sys.thread.Mutex;
import sys.thread.Deque;
#end

import openfl.display.BitmapData;
import openfl.utils.Assets as OpenFlAssets;
import openfl.media.Sound;

import flixel.FlxG;
import flixel.graphics.FlxGraphic;
import flixel.graphics.frames.FlxAtlasFrames;

import lime.graphics.opengl.GL;
import lime.utils.Log;

import haxe.Json;

/**
 * Worker thread pool that lets Lua scripts offload asset I/O (PNG decode,
 * sound load, atlas XML read, character JSON read) so heavy preload work
 * doesn't stall the song-loading frame.
 *
 * GPU upload steps stay on the main thread (textures must be created on the
 * GL context thread); tick() drains finished jobs each frame and finishes the
 * upload + optional Lua completion callback that the script registered with
 * the job.
 */
class LuaThreads {
    // 4 workers covers a typical frostbeat-class song without saturating the
    // CPU (engine main + audio + Discord still need cores). Songs that queue
    // more jobs at once just round-trip through the pool. Tunable from Lua
    // via luaThreadSetMaxWorkers() before the first job is submitted.
    public static var maxWorkers:Int = 4;

    static inline var STATE_PENDING:String = "pending";
    static inline var STATE_RUNNING:String = "running";
    static inline var STATE_DONE:String = "done";
    static inline var STATE_FAILED:String = "failed";
    static inline var STATE_CANCELLED:String = "cancelled";

    #if sys
    static var workers:Array<Thread> = [];
    static var jobQueue:Deque<LuaThreadJob> = new Deque<LuaThreadJob>();
    static var doneQueue:Deque<LuaThreadJob> = new Deque<LuaThreadJob>();
    static var stateMutex:Mutex = new Mutex();
    static var jobStates:Map<String, String> = new Map<String, String>();
    static var ownerJobs:Map<ModLua, Map<String, Bool>> = new Map<ModLua, Map<String, Bool>>();
    static var activeWorkers:Int = 0;
    #end

    static var bootstrapped:Bool = false;
    static var maxCompletionsPerTick:Int = 4;

    /**
     * Register Lua-facing callbacks on a ModLua. Safe to call multiple times
     * (each ModLua gets its own wrapped closures). Call from ModLua.execute()
     * once the underlying state is ready.
     */
    public static function attach(modLua:ModLua):Void {
        #if (USING_LUA && cpp && sys)
        ensureWorkers();
        registerCallbacks(modLua);
        #end
    }

    /**
     * Drop pending completions belonging to the given ModLua so we don't
     * call into a closed Lua state. Call from ModLua.close().
     */
    public static function detach(modLua:ModLua):Void {
        #if sys
        var drained:Array<LuaThreadJob> = [];

        while(true) {
            var entry = doneQueue.pop(false);
            if(entry == null) break;
            if(entry.owner != modLua) drained.push(entry);
        }

        for(job in drained) doneQueue.add(job);

        stateMutex.acquire();
        if(ownerJobs.exists(modLua)) {
            for(id in ownerJobs.get(modLua).keys()) {
                if(jobStates.exists(id) && jobStates.get(id) == STATE_RUNNING) {
                    jobStates.set(id, STATE_CANCELLED);
                }
            }
            ownerJobs.remove(modLua);
        }
        stateMutex.release();
        #end
    }

    /**
     * Pump finished jobs back to Lua. Bounded so a burst doesn't spike the
     * frame; remaining jobs roll over to the next tick.
     */
    public static function tick():Void {
        #if sys
        var processed:Int = 0;

        while(processed < maxCompletionsPerTick) {
            var entry = doneQueue.pop(false);
            if(entry == null) break;
            applyJobResult(entry);
            processed++;
        }
        #end
    }

    #if (USING_LUA && cpp && sys)
    static function registerCallbacks(modLua:ModLua):Void {
        modLua.addCallback("luaThreadPreloadImage", function(taskId:String, path:String, ?completionLuaFn:String) {
            return submit(modLua, taskId, LuaThreadJobKind.KImage(path), completionLuaFn);
        });

        modLua.addCallback("luaThreadPreloadSound", function(taskId:String, path:String, ?completionLuaFn:String) {
            return submit(modLua, taskId, LuaThreadJobKind.KSound(path), completionLuaFn);
        });

        modLua.addCallback("luaThreadPreloadAtlas", function(taskId:String, path:String, ?atlasType:String, ?completionLuaFn:String) {
            if(atlasType == null) atlasType = "sparrow";
            return submit(modLua, taskId, LuaThreadJobKind.KAtlas(path, atlasType), completionLuaFn);
        });

        modLua.addCallback("luaThreadPreloadCharacter", function(taskId:String, characterName:String, ?completionLuaFn:String) {
            return submit(modLua, taskId, LuaThreadJobKind.KCharacter(characterName), completionLuaFn);
        });

        modLua.addCallback("luaThreadGpuWarmBatch", function(taskId:String, paths:String, ?completionLuaFn:String) {
            return submit(modLua, taskId, LuaThreadJobKind.KGpuWarmBatch(splitPaths(paths)), completionLuaFn);
        });

        modLua.addCallback("luaThreadGetState", function(taskId:String) {
            stateMutex.acquire();
            var s = jobStates.exists(taskId) ? jobStates.get(taskId) : "unknown";
            stateMutex.release();
            return s;
        });

        modLua.addCallback("luaThreadIsDone", function(taskId:String) {
            stateMutex.acquire();
            var s = jobStates.exists(taskId) ? jobStates.get(taskId) : null;
            stateMutex.release();
            return s == STATE_DONE || s == STATE_FAILED || s == STATE_CANCELLED;
        });

        modLua.addCallback("luaThreadIsRunning", function(taskId:String) {
            stateMutex.acquire();
            var s = jobStates.exists(taskId) ? jobStates.get(taskId) : null;
            stateMutex.release();
            return s == STATE_RUNNING || s == STATE_PENDING;
        });

        modLua.addCallback("luaThreadActiveCount", function() {
            stateMutex.acquire();
            var n = activeWorkers;
            stateMutex.release();
            return n;
        });

        modLua.addCallback("luaThreadPendingCount", function() {
            var n = 0;
            stateMutex.acquire();
            for(state in jobStates) {
                if(state == STATE_PENDING || state == STATE_RUNNING) n++;
            }
            stateMutex.release();
            return n;
        });

        modLua.addCallback("luaThreadCancel", function(taskId:String) {
            stateMutex.acquire();
            if(jobStates.exists(taskId)) {
                var s = jobStates.get(taskId);
                if(s == STATE_PENDING || s == STATE_RUNNING) {
                    jobStates.set(taskId, STATE_CANCELLED);
                }
            }
            stateMutex.release();
        });

        modLua.addCallback("luaThreadClear", function(taskId:String) {
            stateMutex.acquire();
            jobStates.remove(taskId);
            stateMutex.release();
        });

        modLua.addCallback("luaThreadSetMaxWorkers", function(count:Int) {
            // No-op once workers are spun up — pool size is fixed for the
            // life of the process. Scripts should call this before submitting
            // their first job (e.g. at the top of generatedStage).
            if(bootstrapped) return false;
            if(count < 1) count = 1;
            if(count > 8) count = 8;
            maxWorkers = count;
            return true;
        });

        modLua.addCallback("luaThreadGetMaxWorkers", function() {
            return maxWorkers;
        });
    }

    static function submit(modLua:ModLua, taskId:String, kind:LuaThreadJobKind, completionLuaFn:String):Bool {
        if(taskId == null || taskId == "") return false;

        stateMutex.acquire();
        if(jobStates.exists(taskId)) {
            var s = jobStates.get(taskId);
            if(s == STATE_PENDING || s == STATE_RUNNING) {
                stateMutex.release();
                return false;
            }
        }

        jobStates.set(taskId, STATE_PENDING);
        rememberOwnerJob(modLua, taskId);
        stateMutex.release();

        var job:LuaThreadJob = {
            id: taskId,
            owner: modLua,
            kind: kind,
            completionLuaFn: completionLuaFn,
            bitmaps: new Map<String, BitmapData>(),
            sounds: new Map<String, Sound>(),
            atlasXml: null,
            characterJson: null,
            error: null
        };

        jobQueue.add(job);
        return true;
    }

    static function rememberOwnerJob(modLua:ModLua, taskId:String):Void {
        var ids:Map<String, Bool> = ownerJobs.get(modLua);

        if(ids == null) {
            ids = new Map<String, Bool>();
            ownerJobs.set(modLua, ids);
        }

        ids.set(taskId, true);
    }

    static function ensureWorkers():Void {
        if(bootstrapped) return;
        bootstrapped = true;

        var count = maxWorkers;
        if(count < 1) count = 1;

        for(_ in 0...count) {
            workers.push(Thread.create(workerLoop));
        }
    }

    static function workerLoop():Void {
        while(true) {
            var job:LuaThreadJob = jobQueue.pop(true);
            if(job == null) break;

            stateMutex.acquire();
            if(jobStates.exists(job.id) && jobStates.get(job.id) == STATE_CANCELLED) {
                stateMutex.release();
                continue;
            }
            jobStates.set(job.id, STATE_RUNNING);
            activeWorkers++;
            stateMutex.release();

            try {
                runJob(job);
            }catch(e:Dynamic) {
                job.error = Std.string(e);
            }

            stateMutex.acquire();
            activeWorkers--;
            var finalState:String = (job.error != null) ? STATE_FAILED : STATE_DONE;
            if(jobStates.exists(job.id) && jobStates.get(job.id) == STATE_CANCELLED) {
                finalState = STATE_CANCELLED;
            }
            jobStates.set(job.id, finalState);
            stateMutex.release();

            doneQueue.add(job);
        }
    }

    static function runJob(job:LuaThreadJob):Void {
        switch(job.kind) {
            case KImage(path):
                preloadImageBytes(job, path);

            case KSound(path):
                preloadSoundBytes(job, path);

            case KAtlas(path, atlasType):
                preloadImageBytes(job, path);
                job.atlasXml = readAtlasDescription(path, atlasType);

            case KCharacter(name):
                preloadCharacterBytes(job, name);

            case KGpuWarmBatch(paths):
                for(p in paths) preloadImageBytes(job, p);
        }
    }

    static function preloadImageBytes(job:LuaThreadJob, key:String):Void {
        if(key == null || key == "") return;
        if(job.bitmaps.exists(key)) return;

        var path:String = Paths.getPath('images/$key.png', IMAGE, null);
        var bmp:BitmapData = null;

        if(OpenFlAssets.exists(path, IMAGE)) {
            bmp = OpenFlAssets.getBitmapData(path, false);
        }
        #if sys
        else if(FileSystem.exists(path)) {
            bmp = BitmapData.fromFile(path);
        }
        #end

        if(bmp != null) {
            job.bitmaps.set(key, bmp);
        }
    }

    static function preloadSoundBytes(job:LuaThreadJob, key:String):Void {
        if(key == null || key == "") return;
        if(job.sounds.exists(key)) return;

        var path:String = Paths.getPath('sounds/$key.${Paths.SOUND_EXT}', SOUND, null);
        var snd:Sound = null;

        if(OpenFlAssets.exists(path, SOUND)) {
            snd = OpenFlAssets.getSound(path, false);
        }
        #if sys
        else if(FileSystem.exists(path)) {
            snd = Sound.fromFile(path);
        }
        #end

        if(snd != null) {
            job.sounds.set(key, snd);
        }
    }

    static function readAtlasDescription(key:String, atlasType:String):String {
        var ext:String = (atlasType != null && atlasType.toLowerCase() == "packer") ? "txt" : "xml";
        var path:String = Paths.getPath('images/$key.$ext', TEXT, null);

        if(Paths.assetExists(path, TEXT)) {
            return Paths.readText(path);
        }

        return null;
    }

    static function preloadCharacterBytes(job:LuaThreadJob, name:String):Void {
        if(name == null || name == "") return;

        var infoPath:String = Paths.getPreloadPath('characters/$name.json');

        if(!Paths.assetExists(infoPath, TEXT)) {
            infoPath = Paths.getPath('characters/$name.json', TEXT, "shared");
        }

        if(!Paths.assetExists(infoPath, TEXT)) return;

        var rawJson:String = Paths.readText(infoPath);
        if(rawJson == null) return;

        job.characterJson = rawJson;

        try {
            var info:Dynamic = Json.parse(rawJson);
            if(info != null && info.file != null) {
                for(entry in cast(info.file, String).split(",")) {
                    var trimmed:String = StringTools.trim(entry);
                    if(trimmed.length > 0) preloadImageBytes(job, trimmed);
                }
            }
        }catch(e:Dynamic) {
            // tolerate malformed JSON; main-thread fallback still works
        }
    }

    /**
     * Main-thread side of a finished job: actually upload bitmaps to the GPU,
     * register them in Flixel's cache, parse the XML into FlxAtlasFrames, then
     * fire the Lua completion callback so the script can hook the result.
     */
    static function applyJobResult(job:LuaThreadJob):Void {
        if(job.owner == null || job.owner.closed) return;

        try {
            switch(job.kind) {
                case KImage(path):
                    uploadBitmap(job, path);

                case KSound(path):
                    registerSound(job, path);

                case KAtlas(path, atlasType):
                    uploadBitmap(job, path);
                    registerAtlas(job, path, atlasType);

                case KCharacter(name):
                    for(key in job.bitmaps.keys()) uploadBitmap(job, key);

                case KGpuWarmBatch(paths):
                    for(p in paths) uploadBitmap(job, p);
                    // explicit pipeline flush so warmup cost is paid now, not at first draw
                    try { GL.finish(); }catch(_:Dynamic) {}
            }
        }catch(e:Dynamic) {
            Log.warn("LuaThreads applyJobResult failed for " + job.id + ": " + Std.string(e));
        }

        invokeCompletion(job);
    }

    static function uploadBitmap(job:LuaThreadJob, key:String):Void {
        var bmp:BitmapData = job.bitmaps.get(key);
        if(bmp == null) return;

        var path:String = Paths.getPath('images/$key.png', IMAGE, null);

        if(FlxG.bitmap.get(path) != null) return;

        var graphic:FlxGraphic = FlxGraphic.fromBitmapData(bmp, false, path);
        if(graphic != null) graphic.persist = false;
    }

    static function registerSound(job:LuaThreadJob, key:String):Void {
        // OpenFL caches by path once the Sound is constructed; touching Paths.sound
        // ensures the engine's tracking maps mark it loaded too.
        Paths.sound(key);
    }

    static function registerAtlas(job:LuaThreadJob, key:String, atlasType:String):Void {
        if(job.atlasXml == null || job.atlasXml == "") return;

        var path:String = Paths.getPath('images/$key.png', IMAGE, null);
        var graphic:FlxGraphic = FlxG.bitmap.get(path);
        if(graphic == null) return;

        try {
            if(atlasType != null && atlasType.toLowerCase() == "packer") {
                FlxAtlasFrames.fromSpriteSheetPacker(graphic, job.atlasXml);
            }else {
                FlxAtlasFrames.fromSparrow(graphic, job.atlasXml);
            }
        }catch(e:Dynamic) {
            Log.warn("LuaThreads registerAtlas failed for " + key + ": " + Std.string(e));
        }
    }

    static function invokeCompletion(job:LuaThreadJob):Void {
        if(job.completionLuaFn == null || job.completionLuaFn == "") return;
        if(job.owner == null || job.owner.closed) return;

        var state:String;
        stateMutex.acquire();
        state = jobStates.exists(job.id) ? jobStates.get(job.id) : "unknown";
        stateMutex.release();

        job.owner.call(job.completionLuaFn, [job.id, state, job.error]);
    }

    static function splitPaths(raw:String):Array<String> {
        var out:Array<String> = [];
        if(raw == null || raw == "") return out;

        for(piece in raw.split(",")) {
            var trimmed:String = StringTools.trim(piece);
            if(trimmed.length > 0) out.push(trimmed);
        }

        return out;
    }
    #end
}

#if (USING_LUA && cpp && sys)
private enum LuaThreadJobKind {
    KImage(path:String);
    KSound(path:String);
    KAtlas(path:String, atlasType:String);
    KCharacter(name:String);
    KGpuWarmBatch(paths:Array<String>);
}

private typedef LuaThreadJob = {
    var id:String;
    var owner:ModLua;
    var kind:LuaThreadJobKind;
    var completionLuaFn:String;
    var bitmaps:Map<String, BitmapData>;
    var sounds:Map<String, Sound>;
    var atlasXml:String;
    var characterJson:String;
    var error:String;
};
#end
