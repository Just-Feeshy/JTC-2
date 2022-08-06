package feshixl.utils;

import flixel.system.FlxSound;
import openfl.events.Event;
import openfl.media.Sound;
import openfl.utils.ByteArray;
import haxe.io.Bytes;

class FeshBytesHandler {
    public static function loadSoundFromByteArray(Bytes:ByteArray, Looped:Bool = false, AutoDestroy:Bool = false, ?OnComplete:Void->Void):FlxSound {
        var sound:FlxSound = new FlxSound();

        @:privateAccess {
            sound.cleanup(true);
            sound._sound = new Sound();
            sound._sound.addEventListener(Event.ID3, sound.gotID3);
            sound._sound.loadCompressedDataFromByteArray(Bytes, Bytes.length);

            return sound.init(Looped, AutoDestroy, OnComplete);
        }
    }

    public static function bytesFromArray(byteArray:ByteArray):Bytes {
        #if display
        return null;
        #elseif flash
        return Bytes.ofData(byteArray);
        #else
        return (byteArray:ByteArrayData);
        #end
    }
}