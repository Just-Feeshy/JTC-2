package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.group.FlxGroup.FlxTypedGroup;
import flixel.graphics.frames.FlxAtlasFrames;
import flixel.graphics.frames.FlxFilterFrames;
import flixel.math.FlxPoint;
import flixel.math.FlxRect;
import flixel.math.FlxMath;
import flixel.util.FlxColor;
import flixel.tweens.FlxTween;
import flixel.tweens.FlxEase;
import flixel.util.FlxTimer;
import flixel.util.FlxDestroyUtil;
import flixel.system.FlxSound;
import flixel.text.FlxText;
import feshixl.math.FeshMath;
import feshixl.FeshCamera;

import template.CustomNote;
import SaveData.SaveType;

using StringTools;

class Note extends feshixl.FeshSprite implements INote {
	public static final swagWidth:Float = 160 * 0.7;
	public static final PURP_NOTE:Int = 0;
	public static final GREEN_NOTE:Int = 2;
	public static final BLUE_NOTE:Int = 1;
	public static final RED_NOTE:Int = 3;

	public static var AFFECTED_SCROLLSPEED:Float = 1;
	public static var AFFECTED_STRUMTIME:Float = 0;

	public var prevNote:INote;
	public var downscrollNote:Bool;
	public var setupPosition:Float = 0;

	public var playAnyAnimation:Bool = true;

	public var sound:FlxSound;

	public var strumTime:Float = 0;
	public var swayTime:Float = 0;

	public var mustPress:Bool = false;
	public var noteData:Int = 0;
	public var canBeHit:Bool = false;
	public var tooLate:Bool = false;
	public var wasGoodHit:Bool = false;
	public var shouldBeDead:Bool = false;
	public var isEndStrum:Bool = false;

	public var caculatePos:Float = 0;

	public var noteOffset:FlxPoint;

	public var sustainLength:Float = 0;
	public var isSustainNote:Bool = false;
	public var wasSustainNote:Bool = false;
	public var ignore:Bool = false;

	public var noteScore:Float = 1;

	public var rating:String = "shit";

	public var noteAbstract:String = "regular";

	public var trail:FlxTypedGroup<FlxSprite>;

	public var hasCustomAddon(default, null):ICustomNote;

	private var ifPlayState:Bool = false;
	private var tickDivider:Float = 1;

	public var howSpeed(default, null):Null<Float> = 0;
	public var earlyHit(default, null):Float = 0.5;

	public var endPieceOffsetX(default, null):Float = 0;
	public var endPieceOffsetY(default, null):Float = 0;

	public var tag:String = "";

	public var modifiedSymbol:FlxText;

	public function new(strumTime:Float, noteData:Int, ?prevNote:INote, ?sustainNote:Bool = false, ?noteType:String = "regular",  ?ifcircle:Bool, ?ifPlayState:Bool)
	{
		super();

		useAdvanceClipping = false;

		noteOffset = FlxPoint.get();

		noteAbstract = noteType;
		
		if(hasCustomAddon != null)
			howSpeed += hasCustomAddon.addToNoteSpeed();
		else
			howSpeed = PlayState.SONG.speed;


		hasCustomAddon = getAddon();

		switch(noteType) {
			default:
				downscrollNote = FlxG.save.data.helpme;
		}

		switch(noteType) {
			default:
				isSustainNote = sustainNote;

				if(hasCustomAddon != null) {
					if(hasCustomAddon.cantHaveHold()) {
						isSustainNote = false;
						wasSustainNote = true;
					}
				}
		}

		switch(noteType) {
			default:
				ignore = false;

				if(hasCustomAddon != null)
					ignore = hasCustomAddon.shouldBeIgnored();
		}

		if(hasCustomAddon != null) {
			if(hasCustomAddon.hasOppositeScroll()) {
				downscrollNote = !FlxG.save.data.helpme;
			}

			if(downscrollNote) {
				noteOffset.x = -hasCustomAddon.getNoteOffsetX(isSustainNote);
				noteOffset.y = -hasCustomAddon.getNoteOffsetY(isSustainNote);
			}else {
				noteOffset.x = hasCustomAddon.getNoteOffsetX(isSustainNote);
				noteOffset.y = hasCustomAddon.getNoteOffsetY(isSustainNote);
			}
		}

		if(CustomNoteHandler.lowNotesTick.contains(noteType))
			tickDivider = 1.5;

		if(FlxG.save.data.showAntialiasing)
			tickDivider = 3;

		x += 50;
		// MAKE SURE ITS DEFINITELY OFF SCREEN?
		y -= 2000;

		this.strumTime = strumTime;
		this.noteData = noteData;

		this.ifPlayState = ifPlayState;

		if(FlxG.save.data.showAntialiasing)
			antialiasing = true;

		switch (noteType)
		{
			case "spiritual star":
				if(PlayState.curStage == "school" || PlayState.curStage == "schoolEvil")
					loadGraphic(Paths.image('notes/$noteType/Base-pixel'));
				else
					loadGraphic(Paths.image('notes/$noteType/Base'));

				if(PlayState.curStage == "school" || PlayState.curStage == "schoolEvil") {
					setGraphicSize(Std.int(width * 4));
					updateHitbox();
					antialiasing = false;
				}else {
					setGraphicSize(Std.int(width * 0.8));
					updateHitbox();
				}	

				if(ifPlayState) {
					trail = new FlxTypedGroup<FlxSprite>();

					for(i in 1...3) {
						var trailSpirit:FlxSprite = new FlxSprite(this.x+(this.width/2), this.y+(this.height/2));

						if(PlayState.curStage == "school" || PlayState.curStage == "schoolEvil") {
							trailSpirit.loadGraphic(Paths.image('notes/$noteType/Base-pixel'));
							trailSpirit.setGraphicSize(Std.int(width * 0.4));
						}else {
							trailSpirit.loadGraphic(Paths.image('notes/$noteType/Base'));
							trailSpirit.setGraphicSize(Std.int(trailSpirit.width * 0.4));
						}	

						trailSpirit.updateHitbox();
						trailSpirit.alpha = 0.25;
						trailSpirit.angle = angle;
						trailSpirit.cameras = [PlayState.camNOTE];
						trailSpirit.setColorTransform(1,1,1,2,0,0,0,0);

						trail.add(trailSpirit);
					}
				}

			default:
				if(noteType == "regular" && (PlayState.curStage == "school" || PlayState.curStage == "schoolEvil")) {
					loadGraphic(Paths.image('weeb/pixelUI/arrows-pixels'), true, 17, 17);

					animation.add('greenScroll', [6]);
					animation.add('redScroll', [7]);
					animation.add('blueScroll', [5]);
					animation.add('purpleScroll', [4]);
					animation.add('diamondScroll', [21]);

					if (isSustainNote)
					{
						loadGraphic(Paths.image('weeb/pixelUI/arrowEnds'), true, 7, 6);

						animation.add('purplehold end', [4]);
						animation.add('greenhold end', [6]);
						animation.add('redhold end', [7]);
						animation.add('bluehold end', [5]);

						animation.add('purplehold', [0]);
						animation.add('greenhold', [2]);
						animation.add('redhold', [3]);
						animation.add('bluehold', [1]);
					}

					setGraphicSize(Std.int(width * PlayState.daPixelZoom));
					updateHitbox();
					antialiasing = false;
				}else {
					if(noteType == "planet notes")
						frames = Paths.getNoteAtlas('$noteType/planet_notes');
					else
						frames = Paths.getNoteAtlas('$noteType/NOTE_assets');

					if(noteType == "planet notes") {
						animation.addByPrefix('greenScroll', 'planet up');
						animation.addByPrefix('redScroll', 'planet left');
						animation.addByPrefix('blueScroll', 'planet down');
						animation.addByPrefix('purpleScroll', 'planet right');
						animation.addByPrefix('diamondScroll', 'planet down');
					}else if(hasCustomAddon != null) {
						if(!hasCustomAddon.useCustomPrefix(animation))
							setupPrefixes();
					}else {
						setupPrefixes();
					}

					setGraphicSize(Std.int(width * 0.7));
					updateHitbox();

					if(hasCustomAddon != null && ifPlayState)
						trail = hasCustomAddon.getTrailGroup();

					if(trail != null)
						trail.cameras = [PlayState.camNOTE];
				}
		}

		switch (noteData)
		{
			case 0:
				x += swagWidth * 0;
				animation.play('purpleScroll');
			case 1:
				x += swagWidth * 1;
				animation.play('blueScroll');
			case 2:
				x += swagWidth * 2;
				animation.play('greenScroll');
			case 3:
				x += swagWidth * 3;
				animation.play('redScroll');
		}

		// trace(prevNote);

		if (prevNote == null)
			prevNote = this;

		this.prevNote = prevNote;

		if (FlxG.save.data.helpme && sustainNote)
			flipY = true;

		if (isSustainNote && prevNote != null)
		{
			noteScore * 0.2;

			alpha = 1;

			if (PlayState.curStage.startsWith('school') && noteAbstract == "regular") {
				x += 30;
			}

			if(PlayState.SONG.fifthKey) {
				switch (noteData)
				{
					case 2:
						if(noteAbstract == "regular")
							setColorTransform(2,2,0,2,100,100,0,0);
						
						animation.play('redhold end');
					case 3:
						animation.play('greenhold end');
					case 4:
						animation.play('redhold end');
					case 1:
						animation.play('bluehold end');
					case 0:
						animation.play('purplehold end');
				}
			}else {
				switch (noteData)
				{
					case 2:
						animation.play('greenhold end');
					case 3:
						animation.play('redhold end');
					case 1:
						animation.play('bluehold end');
					case 0:
						animation.play('purplehold end');
				}		
			}

			updateHitbox();

			if (PlayState.curStage.startsWith('school'))
				x += 30;

			if (prevNote.isSustainNote)
			{
				if(PlayState.SONG.fifthKey) {
					switch (prevNote.noteData)
					{
						case 0:
							prevNote.animation.play('purplehold');
						case 1:
							prevNote.animation.play('bluehold');
						case 2:
							if(noteAbstract == "regular")
								setColorTransform(2,2,0,2,100,100,0,0);

							prevNote.animation.play('redhold');
						case 3:
							prevNote.animation.play('greenhold');
						case 4:
							prevNote.animation.play('redhold');
					}
				}else {	
					switch (prevNote.noteData)
					{
						case 0:
							prevNote.animation.play('purplehold');
						case 1:
							prevNote.animation.play('bluehold');
						case 2:
							prevNote.animation.play('greenhold');
						case 3:
							prevNote.animation.play('redhold');
					}
				}

				trace("haha");
				makeLongNote(prevNote);
			}
		}else if(!isSustainNote) {
			earlyHit = 1;
		}
	}

	public function refresh(fifth:Bool):Void {
		if(fifth && !isSustainNote) {
			switch (noteData) {
				case 0:
					animation.play('purpleScroll');
				case 1:
					animation.play('blueScroll');
				case 2:
					animation.play('diamondScroll');
				case 3:
					animation.play('greenScroll');
				case 4:
					animation.play('redScroll');
			}
		}else if(!fifth && !isSustainNote) {
			switch (noteData) {
				case 0:
					animation.play('purpleScroll');
				case 1:
					animation.play('blueScroll');
				case 2:
					animation.play('greenScroll');
				case 3:
					animation.play('redScroll');
			}
		}
	}

	public function placeModifierSymbol(char:String = "M"):Void {
		if(modifiedSymbol == null) {
			modifiedSymbol = new FlxText(0, 0, 0, char, 24);
			modifiedSymbol.setFormat(Paths.font("PhantomMuff.ttf"), 24, FlxColor.WHITE, CENTER, FlxTextBorderStyle.OUTLINE, FlxColor.BLACK);
			modifiedSymbol.antialiasing = this.antialiasing;
		}else {
			modifiedSymbol.text += char;
		}
	}

	public function pressedByPlayer(boyfriend:Character, dad:Character, girlfriend:Character):Void {
		if(hasCustomAddon != null) {
			hasCustomAddon.pressedByPlayer(this, boyfriend, dad, girlfriend);
		}
	}

	public function getInverseAxis():Float {
		return x;
	}

	public function setInverseAxis(strumPos:Float, strumAngle:Float):Void {
		x = (strumPos + noteOffset.x) + Math.sin(strumAngle) * caculatePos;
	}

	public function getNoteAxis():Float {
		return y;
	}

	public function setNoteAxis(strumPos:Float, strumAngle:Float):Void {
		y = (strumPos + noteOffset.y) + Math.cos(strumAngle) * caculatePos;

		if(height < 50) {
			endPieceOffsetY = (Note.swagWidth - height) * (getProperAngle() / Math.PI);
		}

		y += endPieceOffsetY;
	}

	//More complicated method
	public function setNoteAlpha(value:Float, fadeIn:Int):Void {
		var fadeValue:Float = 1;

		if(DefaultHandler.modifiers != null) {
			if(Main.feeshmoraModifiers && DefaultHandler.modifiers.fadeInNotes.enabled) {
				fadeValue = getNoteStrumPosition(fadeIn);
			}
		}

		if(hasCustomAddon == null) {
			alpha = Math.min(value, fadeValue);
		}else if(hasCustomAddon != null) {
			alpha = Math.min(hasCustomAddon.setNoteAlpha(this, value), fadeValue);
		}
	}

	public function setNoteAngle(value:Float, value2:Float):Void {
		if(hasCustomAddon != null) {
			if(!isSustainNote) {
				angle = hasCustomAddon.setNoteAngle(this, value);
			}else {
				angle = hasCustomAddon.setNoteAngle(this, value2);
			}
		} else {
			if(!isSustainNote) {
				angle = value;
			}else {
				angle = value2;
			}
		}
	}

	public function getNoteY():Float {
		return ((Conductor.trackPosition - DefaultHandler.getNoteTime(strumTime)) * Note.AFFECTED_SCROLLSPEED) * (0.45 * FlxMath.roundDecimal(howSpeed, 2));
	}

	public function getNoteStrumPosition(offset:Int = 0):Float {
		return Math.max(0, (((Conductor.trackPosition - strumTime) * (-0.45 * FlxMath.roundDecimal(howSpeed * AFFECTED_SCROLLSPEED, 2))) - offset)/100);
	}

	public function setVisibility(visibility:Bool) {
		if(hasCustomAddon != null)
			visible = hasCustomAddon.setVisibility(this, visibility);
		else
			visible = visibility;
	}

	public function setXaxisSustain(strums:Array<Strum>, strumX:Float, alreadyX:Float, strumAngle:Float) {
		if(hasCustomAddon != null)
			setInverseAxis(hasCustomAddon.setSustainXPosition(this, strums, alreadyX), strumAngle);
		else
			setInverseAxis(alreadyX, strumAngle);
	}

	public function setXaxis(strums:Array<Strum>, strumX:Float, alreadyX:Float, strumAngle:Float) {
		if(hasCustomAddon != null)
			setInverseAxis(hasCustomAddon.setXPosition(this, strums, alreadyX), strumAngle);
		else {
			setInverseAxis(alreadyX, strumAngle);
		}
	}

	public function splash(splashThing:SplashSprite, strumNote:Strum, rating:String):Void {
		if(!SaveData.getData(SaveType.SHOW_NOTE_SPLASH) || isSustainNote)
			return;

		if(hasCustomAddon != null) {
			if(!hasCustomAddon.noDefaultSplash()) {
				if((rating == "sick" || rating == "good") && splashThing != null) {
					splashThing.texture = "regular/splash";
					splashThing.setPosition(strumNote.x-(splashThing.width/3), strumNote.y-(splashThing.height/3));
					splashThing.animation.play('sploosh' + strumNote.ID);
				}
			}

			splashThing.texture = hasCustomAddon.getSplashTexture();
			hasCustomAddon.createSplashSprite(splashThing, FlxRect.get(strumNote.x, strumNote.y, strumNote.width, strumNote.height), rating);
		}else {
			switch(noteAbstract) {
				default:
					if((rating == "sick" || rating == "good") && splashThing != null) {
						splashThing.texture = "regular/splash";
						splashThing.setPosition(strumNote.x-(splashThing.width/3), strumNote.y-(splashThing.height/3));
						splashThing.animation.play('sploosh' + strumNote.ID);
					}
			}
		}
	}

	public function hit(strumNote:Strum):Void {
		if(hasCustomAddon != null) {
			var soundName:String = hasCustomAddon.playSoundWhenNoteIsHit(mustPress, isSustainNote);

			if(soundName.trim() != "") {
				if(sound == null)sound = new FlxSound();

				sound.loadEmbedded(Paths.sound(soundName));
				
				if(sound.name != soundName && !sound.playing) {
					FlxG.sound.list.add(sound);
					sound.play();
				}
			}

			if(hasCustomAddon.whenNoteIsHit(strumNote)) {
				strumNote.setColorTransform(1,1,1,1,0,0,0,0);
				strumNote.playAnim('confirm', true);
			}
		}else {
			strumNote.setColorTransform(1,1,1,1,0,0,0,0);
			strumNote.playAnim('confirm', true);
		}
	}

	function setupPrefixes():Void {
		animation.addByPrefix('greenScroll', 'green0');
		animation.addByPrefix('redScroll', 'red0');
		animation.addByPrefix('blueScroll', 'blue0');
		animation.addByPrefix('purpleScroll', 'purple0');
		animation.addByPrefix('diamondScroll', 'diamond0');

		animation.addByPrefix('purplehold end', 'pruple end hold');
		animation.addByPrefix('greenhold end', 'green hold end');
		animation.addByPrefix('redhold end', 'red hold end');
		animation.addByPrefix('bluehold end', 'blue hold end');

		animation.addByPrefix('purplehold', 'purple hold piece');
		animation.addByPrefix('greenhold', 'green hold piece');
		animation.addByPrefix('redhold', 'red hold piece');
		animation.addByPrefix('bluehold', 'blue hold piece');
	}

	function getAddon():ICustomNote {
		var customNote:ICustomNote = cast Type.createInstance(CustomNoteHandler.customNoteAddon.get(noteAbstract), []);

		if(customNote != null) {
			if(customNote.playerShouldntHit() && !CustomNoteHandler.dontHitNotes.contains(noteAbstract))
				CustomNoteHandler.dontHitNotes.push(noteAbstract);

			if(customNote.noDefaultSplash() && !CustomNoteHandler.noNoteAbstractStrum.contains(noteAbstract))
				CustomNoteHandler.noNoteAbstractStrum.push(noteAbstract);

			if(customNote.giveHealth(isSustainNote) < 0 && !CustomNoteHandler.ouchyNotes.contains(noteAbstract)) {
				CustomNoteHandler.ouchyNotes.push(noteAbstract);

				if(!CustomNoteHandler.dontHitNotes.contains(noteAbstract))
					CustomNoteHandler.dontHitNotes.push(noteAbstract);
			}
		}

		return customNote;
	}

	function makeLongNote(note:Note):Void {
		if(hasCustomAddon != null) {
			if(hasCustomAddon.makeLongNoteLong()) {
				note.scale.y *= Conductor.stepCrochet / 100 * 1.5 * howSpeed;
			}
		}else {
			note.scale.y *= Conductor.stepCrochet / 100 * 1.5 * howSpeed;
		}

		note.updateHitbox();
	}

	override function update(elapsed:Float) {
		super.update(elapsed / tickDivider);

		if(hasCustomAddon != null)
			hasCustomAddon.noteUpdate(this);

		if (mustPress)
		{
			var safeHit:Float = 0.5;

			if (DefaultHandler.getNoteTime(strumTime) > Conductor.trackPosition - Conductor.safeZoneOffset
				&& DefaultHandler.getNoteTime(strumTime) < Conductor.trackPosition + (Conductor.safeZoneOffset * safeHit))
				canBeHit = true;
			else
				canBeHit = false;

			if (DefaultHandler.getNoteTime(strumTime) < Conductor.trackPosition - Conductor.safeZoneOffset && !wasGoodHit)
				tooLate = true;
		}
		else
		{
			canBeHit = false;
	
			if (DefaultHandler.getNoteTime(strumTime) < Conductor.trackPosition + (Conductor.safeZoneOffset * earlyHit)) {
				if((isSustainNote && prevNote.wasGoodHit) || DefaultHandler.getNoteTime(strumTime) <= Conductor.trackPosition) {
					wasGoodHit = true;
				}
			}
		}
	
		if (tooLate) {
			if (alpha > 0.3)
				alpha = 0.3;
		}

		if(modifiedSymbol != null) {
			modifiedSymbol.setPosition(this.x + ((this.width - modifiedSymbol.width) / 2), this.y + ((this.height - modifiedSymbol.height) / 2));
		}
	}

	public function getNoteHittable(list:Array<Note>):Note {
		for(i in 0...list.length) {
			if(SaveData.getData(PRESET_INPUTS) == true) {
				if(Math.abs(DefaultHandler.getNoteTime(list[i].strumTime) - DefaultHandler.getNoteTime(strumTime)) < 10) {
					return this;
				}
			}else {
				if((Math.abs(list[i].getNoteY()) < Note.swagWidth || Math.abs(getNoteY()) < Note.swagWidth)) {
					return this;
				}
			}
		}

		return null;
	}

	public function giveHealth():Float {
		if(hasCustomAddon != null) {
			return hasCustomAddon.giveHealth(isSustainNote);
		}else {
			return 0.023;
		}
	}

	public function missDamage():Float {
		if(hasCustomAddon != null) {
			return hasCustomAddon.missNoteDamage();
		}else {
			return 0.069;
		}
	}

	override function getProperAngle():Float {
		var returnAngle = super.getProperAngle();
		if(downscrollNote)returnAngle += Math.PI;

		return returnAngle % (Math.PI * 2);
	}

	static public function getColorFacing(noteID:Int):String {
		if(PlayState.SONG.fifthKey) {
			switch(noteID) {
				case 0: return "purple";
				case 1: return "blue";
				case 2: return "diamond";
				case 3: return "green";
				case 4: return "red";
			}
		}else {
			switch(noteID) {
				case 0: return "purple";
				case 1: return "blue";
				case 2: return "green";
				case 3: return "red";
			}
		}

		return "";
	}

	@:noCompletion
	override function set_visible(Value:Bool):Bool {
		if(modifiedSymbol != null) {
			modifiedSymbol.visible = Value;
		}

		return visible = Value;
	}

	override function kill():Void {
		if(modifiedSymbol != null) {
			modifiedSymbol.kill();
		}

		super.kill();
	}

	override function destroy():Void {
		super.destroy();

		hasCustomAddon = null;

		trail = FlxDestroyUtil.destroy(trail);
		modifiedSymbol = FlxDestroyUtil.destroy(modifiedSymbol);
	}
}