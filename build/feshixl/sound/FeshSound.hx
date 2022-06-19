package feshixl.sound;

import flixel.system.FlxSound;
import openfl.events.Event;
import openfl.utils.ByteArray;
import openfl.media.Sound;

class FeshSound {
    public static function loadSoundFromByteArray(Bytes:ByteArray, Looped:Bool = false, AutoDestroy:Bool = false, ?OnComplete:Void->Void):FlxSound {
        var sound:FlxSound = new FlxSound();

        @:privateAccess
        sound.cleanup(true);

        @:privateAccess
        sound._sound = new Sound();

        @:privateAccess
        sound._sound.addEventListener(Event.ID3, sound.gotID3);

        @:privateAccess
        sound._sound.loadCompressedDataFromByteArray(Bytes, Bytes.length);

        @:privateAccess
        return sound.init(Looped, AutoDestroy, OnComplete);
    }
}