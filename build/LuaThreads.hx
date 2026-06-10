package;

#if (USING_LUA && cpp)
import llua.Lua;
import llua.Lua.Lua_helper;
import llua.State;
#end

#if sys
import sys.FileSystem;
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
 * Synchronous shim that preserves the LuaThreads callback surface that
 * existing song scripts (e.g. frostbeat) depend on, but runs every job
 * inline on the main thread. No worker pool, no mutexes, no done queue.
 *
 * Kept because removing the API would require rewriting every script that
 * submits prewarm jobs. State queries (luaThreadIsDone, luaThreadGetState)
 * still answer correctly because each submit completes before returning.
 */
class LuaThreads {
    public static var maxWorkers:Int = 1;

    static inline var STATE_PENDING:String = "pending";
    static inline var STATE_DONE:String = "done";
    static inline var STATE_FAILED:String = "failed";
    static inline var STATE_CANCELLED:String = "cancelled";

    static var jobStates:Map<String, String> = new Map<String, String>();

    public static function attach(modLua:ModLua):Void {
        #if (USING_LUA && cpp && sys)
        registerCallbacks(modLua);
        #end
    }

    public static function detach(modLua:ModLua):Void {
        // No async state to drain.
    }

    public static function tick():Void {
        // No async completions to apply.
    }

    #if (USING_LUA && cpp && sys)
    static function registerCallbacks(modLua:ModLua):Void {
        modLua.addCallback("luaThreadPreloadImage", function(taskId:String, path:String, ?completionLuaFn:String) {
            return runSync(modLua, taskId, LuaThreadJobKind.KImage(path), completionLuaFn);
        });

        modLua.addCallback("luaThreadPreloadSound", function(taskId:String, path:String, ?completionLuaFn:String) {
            return runSync(modLua, taskId, LuaThreadJobKind.KSound(path), completionLuaFn);
        });

        modLua.addCallback("luaThreadPreloadAtlas", function(taskId:String, path:String, ?atlasType:String, ?completionLuaFn:String) {
            if(atlasType == null) atlasType = "sparrow";
            return runSync(modLua, taskId, LuaThreadJobKind.KAtlas(path, atlasType), completionLuaFn);
        });

        modLua.addCallback("luaThreadPreloadCharacter", function(taskId:String, characterName:String, ?completionLuaFn:String) {
            return runSync(modLua, taskId, LuaThreadJobKind.KCharacter(characterName), completionLuaFn);
        });

        modLua.addCallback("luaThreadGpuWarmBatch", function(taskId:String, paths:String, ?completionLuaFn:String) {
            return runSync(modLua, taskId, LuaThreadJobKind.KGpuWarmBatch(splitPaths(paths)), completionLuaFn);
        });

        modLua.addCallback("luaThreadGetState", function(taskId:String) {
            return jobStates.exists(taskId) ? jobStates.get(taskId) : "unknown";
        });

        modLua.addCallback("luaThreadIsDone", function(taskId:String) {
            var s = jobStates.exists(taskId) ? jobStates.get(taskId) : null;
            return s == STATE_DONE || s == STATE_FAILED || s == STATE_CANCELLED;
        });

        modLua.addCallback("luaThreadIsRunning", function(taskId:String) {
            // Synchronous: nothing is ever in-flight by the time Lua observes it.
            return false;
        });

        modLua.addCallback("luaThreadActiveCount", function() {
            return 0;
        });

        modLua.addCallback("luaThreadPendingCount", function() {
            return 0;
        });

        modLua.addCallback("luaThreadCancel", function(taskId:String) {
            if(jobStates.exists(taskId)) {
                var s = jobStates.get(taskId);
                if(s == STATE_PENDING) {
                    jobStates.set(taskId, STATE_CANCELLED);
                }
            }
        });

        modLua.addCallback("luaThreadClear", function(taskId:String) {
            jobStates.remove(taskId);
        });

        modLua.addCallback("luaThreadSetMaxWorkers", function(count:Int) {
            // Honoured for API compatibility; the synchronous shim ignores it.
            return true;
        });

        modLua.addCallback("luaThreadGetMaxWorkers", function() {
            return 1;
        });
    }

    static function runSync(modLua:ModLua, taskId:String, kind:LuaThreadJobKind, completionLuaFn:String):Bool {
        if(taskId == null || taskId == "") return false;

        if(jobStates.exists(taskId)) {
            var existing = jobStates.get(taskId);
            if(existing == STATE_DONE) {
                invokeCompletion(modLua, taskId, completionLuaFn, STATE_DONE, null);
                return true;
            }
        }

        jobStates.set(taskId, STATE_PENDING);

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

        try {
            runJob(job);
            applyJobResult(job);
        }catch(e:Dynamic) {
            job.error = Std.string(e);
        }

        var finalState:String = (job.error != null) ? STATE_FAILED : STATE_DONE;
        jobStates.set(taskId, finalState);

        invokeCompletion(modLua, taskId, completionLuaFn, finalState, job.error);
        return true;
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
                    try { GL.finish(); }catch(_:Dynamic) {}
            }
        }catch(e:Dynamic) {
            Log.warn("LuaThreads applyJobResult failed for " + job.id + ": " + Std.string(e));
        }
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

    static function invokeCompletion(owner:ModLua, taskId:String, completionLuaFn:String, state:String, error:String):Void {
        if(completionLuaFn == null || completionLuaFn == "") return;
        if(owner == null || owner.closed) return;

        owner.call(completionLuaFn, [taskId, state, error]);
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
