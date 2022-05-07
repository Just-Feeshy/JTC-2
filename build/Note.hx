package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.util.FlxAxes;
import flixel.group.FlxGroup.FlxTypedGroup;
import flixel.graphics.frames.FlxAtlasFrames;
import flixel.graphics.frames.FlxFilterFrames;
import flixel.math.FlxMath;
import flixel.util.FlxColor;
import flixel.tweens.FlxTween;
import flixel.tweens.FlxEase;
import flixel.util.FlxTimer;
import flixel.util.FlxDestroyUtil;
import betterShit.BetterCams;

#if polymod
import polymod.format.ParseRules.TargetSignatureElement;
#end

import template.CustomNote;

using StringTools;

class Note extends FlxSprite
{
	public static final swagWidth:Float = 160 * 0.7;
	public static final PURP_NOTE:Int = 0;
	public static final GREEN_NOTE:Int = 2;
	public static final BLUE_NOTE:Int = 1;
	public static final RED_NOTE:Int = 3;

	public static var AFFECTED_SCROLLSPEED:Float = 1;
	public static var AFFECTED_STRUMTIME:Float = 0;

	public var prevNote:Note;
	public var downscrollNote:Bool;
	public var howSpeed:Float = 0;
	public var setupPosition:Float = 0;

	public var strumTime:Float = 0;
	public var swayTime:Float = 0;

	public var mustPress:Bool = false;
	public var noteData:Int = 0;
	public var canBeHit:Bool = false;
	public var tooLate:Bool = false;
	public var wasGoodHit:Bool = false;

	public var caculatePos:Float = 0;
	public var distanceAxis:FlxAxes;

	public var sustainLength:Float = 0;
	public var isSustainNote:Bool = false;
	public var wasSustainNote:Bool = false;
	public var ignore:Bool = false;

	public var noteScore:Float = 1;

	public var rating:String = "shit";

	public var noteAbstract:String = "regular";

	public var trail:FlxTypedGroup<FlxSprite>;

	public var hasCustomAddon:CustomNote;

	private var ifPlayState:Bool = false;
	private var tickDivider:Float = 1;

	private var reverseDebounce:Bool = false;

	public function new(strumTime:Float, noteData:Int, ?prevNote:Note, ?sustainNote:Bool = false, ?noteType:String = "regular",  ?ifcircle:Bool, ?ifPlayState:Bool)
		{
			super();
			noteAbstract = noteType;
			howSpeed = PlayState.SONG.speed;
			hasCustomAddon = getAddon();

			distanceAxis = Y;

			switch(noteType) {
				case "reverse" | "reverse poison":
					downscrollNote = !FlxG.save.data.helpme;
					howSpeed += 0.5;
				case "side note":
					downscrollNote = FlxG.save.data.helpme;
					howSpeed += 0.75;
				default:
					downscrollNote = FlxG.save.data.helpme;
			}

			switch(noteType) {
				case "spiritual star":
					isSustainNote = false;
					wasSustainNote = true;
				case "reverse":
					isSustainNote = false;
					wasSustainNote = true;
				case "ghost":
					isSustainNote = false;
					wasSustainNote = true;
				case "cherry":
					isSustainNote = false;
					wasSustainNote = true;
				case "trippy":
					isSustainNote = false;
					wasSustainNote = true;
				case "planet notes":
					isSustainNote = false;
					wasSustainNote = true;
				case "side note":
					isSustainNote = false;
					wasSustainNote = true;
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
				case "poison" | "reverse poison":
					ignore = true;
				default:
					ignore = false;

					if(hasCustomAddon != null)
						ignore = hasCustomAddon.shouldBeIgnored();
			}

			if(hasCustomAddon != null) {
				if(hasCustomAddon.hasOppositeScroll())
					downscrollNote = !FlxG.save.data.helpme;

				howSpeed += hasCustomAddon.getIndividualSpeed();
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
							if(!hasCustomAddon.useCustomPrefix(this))
								setupPrefixes();
						}else {
							setupPrefixes();
						}

						//trace(FeeshMain.getAddonThing(noteType, PlaceHolder.placeholderAddon, "customNote") + " " + noteType);
						
						if(noteType == "trippy" && ifPlayState) {
							trail = new FlxTypedGroup<FlxSprite>();

							var trailSpirit:FlxSprite = new FlxSprite(this.x, this.y);
							trailSpirit.frames = Paths.getNoteAtlas('$noteType/NOTE_assets');

							trailSpirit.animation.addByPrefix('spiral', 'swirl');

							trailSpirit.updateHitbox();
							trailSpirit.alpha = 0.25;
							trailSpirit.angle = angle;
							trailSpirit.cameras = [PlayState.camNOTE];
							//trailSpirit.setColorTransform(1,1,1,1.5,0,0,0,0);

							trailSpirit.animation.play('spiral');

							trail.add(trailSpirit);
						}

						setGraphicSize(Std.int(width * 0.7));
						updateHitbox();

						if(hasCustomAddon != null && ifPlayState)
							trail = hasCustomAddon.getTrailGroup();

						if(trail != null)
							trail.cameras = [PlayState.camNOTE];

						if(noteType == "reverse poison" && !isSustainNote && ifPlayState) {
							trail = new FlxTypedGroup<FlxSprite>();

							var trailSpirit:FlxSprite = new FlxSprite(this.x-(this.width/2), this.y-(this.width/2)).loadGraphic(Paths.image('reversePoison'));
							trailSpirit.setGraphicSize(Std.int(this.width*2));
							trailSpirit.updateHitbox();
							trailSpirit.alpha = 0.5;
							trailSpirit.angle = angle;
							trailSpirit.cameras = [PlayState.camNOTE];
							//trailSpirit.setColorTransform(1,1,1,1.5,0,0,0,0);

							trail.add(trailSpirit);
						}

						if(noteType == "ocean" && ifPlayState && !isSustainNote) {
							trail = new FlxTypedGroup<FlxSprite>();

							var trailSpirit:FlxSprite = new FlxSprite(this.x, this.y);
							trailSpirit.frames = Paths.getNoteAtlas('$noteType/NOTE_assets');
							trailSpirit.scrollFactor.set();

							trailSpirit.animation.addByPrefix('coolFlow', 'flow');

							trailSpirit.setGraphicSize(Std.int(this.width), Std.int(this.height/1.15));
							trailSpirit.updateHitbox();
							trailSpirit.alpha = 0.5;
							trailSpirit.visible = false;

							trailSpirit.animation.play('coolFlow');

							trail.add(trailSpirit);
						}
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
	
				if(noteAbstract != "poison" && noteAbstract != "reverse poison") {
					x += width;
				}else {
					x += width/2;
				}

				if (PlayState.curStage.startsWith('school') && noteAbstract == "regular")
					x += 30;

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

				if(noteAbstract != "poison" && prevNote.noteAbstract != "reverse poison")
					x -= width;
	
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
	
					if(prevNote.noteAbstract != "poison" && prevNote.noteAbstract != "reverse poison" && prevNote.noteAbstract != "ocean")
						prevNote.scale.y *= Conductor.stepCrochet / 100 * 1.5 * howSpeed;

					if(prevNote.noteAbstract == "ocean")
						prevNote.scale.y *= Conductor.stepCrochet / 100 * 1.26 * howSpeed;

					if(prevNote.noteAbstract == "poison" || prevNote.noteAbstract == "reverse poison")
						prevNote.setGraphicSize(Std.int(prevNote.width*1.5));

					prevNote.updateHitbox();
					// prevNote.setGraphicSize();
				}
			}
		}

		public function refresh(fifth:Bool, ?findSus:Bool):Void {
			if(!findSus) {
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

			if(findSus) {
				if(!isSustainNote)
					return;

				if(fifth) {
					if(animation.curAnim.name.split(" ")[1] == "") {
						switch (noteData) {
							case 0:
								animation.play('purplehold');
							case 1:
								animation.play('bluehold');
							case 2:
								animation.play('redhold');
							case 3:
								animation.play('greenhold');
							case 4:
								animation.play('redhold');
						}
					}else {
						switch (noteData) {
							case 0:
								animation.play('purplehold end');
							case 1:
								animation.play('bluehold end');
							case 2:
								animation.play('redhold end');
							case 3:
								animation.play('greenhold end');
							case 4:
								animation.play('redhold end');
						}
					}
				}else {
					if(animation.curAnim.name.split(" ")[1] == null) {
						switch (noteData) {
							case 0:
								animation.play('purplehold');
							case 1:
								animation.play('bluehold');
							case 2:
								animation.play('greenhold');
							case 3:
								animation.play('redhold');
						}
					}else {
						switch (noteData) {
							case 0:
								animation.play('purplehold end');
							case 1:
								animation.play('bluehold end');
							case 2:
								animation.play('greenhold end');
							case 3:
								animation.play('redhold end');
						}
					}	
				}
			}
		}

		public function pressedByPlayer(boyfriend:Boyfriend, dad:Character, girlfriend:Character):Void {
			if(hasCustomAddon != null) {
				hasCustomAddon.pressedByPlayer(this, boyfriend, dad, girlfriend);
			}else {
				if(noteAbstract == "poison" || noteAbstract == "reverse poison") {
					boyfriend.playAnim('poisoned', true);
					girlfriend.playAnim('scared', true);
				}else if(noteAbstract == "spiritual star") {
					boyfriend.playAnim('AHHHHH', true);
					girlfriend.playAnim('cheer', true);
				}else if(noteAbstract == "side note") {
					boyfriend.playAnim('dodge', true);
				}
			}
		}

		public function getInverseAxis(ax:FlxAxes):Float {
			if(ax == FlxAxes.Y)
				return x;
			else
				return y;
		}

		public function setInverseAxis(ax:FlxAxes, value:Float) {
			if(ax == FlxAxes.Y)
				x = value;
			else
				y = value;
		}

		public function setNoteAxis(ax:FlxAxes) {
			if(ax == FlxAxes.Y)
				y = caculatePos;
			else
				x = caculatePos;
		}

		//More complicated method
		public function setNoteAlpha(value) {
			var fadeValue:Float = 1;

			if(PlayState.modifierCheckList('fade battle'))
				fadeValue = getNoteStrumPosition(400);

			if(noteAbstract != "ghost" && hasCustomAddon == null) {
				if(noteAbstract == "ocean" && isSustainNote)
					alpha = Math.min(Math.min(0.5, value), fadeValue);
				else
					alpha = Math.min(value, fadeValue);
			}else if(noteAbstract == "ghost") {
				alpha = Math.min(getNoteStrumPosition(250), fadeValue);
			}else if(hasCustomAddon != null) {
				alpha = Math.min(hasCustomAddon.setNoteAlpha(value), fadeValue);
			}
		}

		public function setNoteAngle(value:Float) {
			if(hasCustomAddon != null) {
				angle = hasCustomAddon.setNoteAngle(value);
			} else {
				if(!isSustainNote && noteAbstract != "spiritual star" && noteAbstract != "cherry") {
					angle = value;
				}else if(isSustainNote) {
					if(distanceAxis == FlxAxes.X)
						angle = value - 90;
				}
			}
		}

		public function getNoteY():Float {
			return ((Conductor.trackPosition - Compile.getNoteTime(strumTime)) * Note.AFFECTED_SCROLLSPEED) * (0.45 * FlxMath.roundDecimal(howSpeed, 2));
		}

		public function getNoteStrumPosition(offset:Int):Float {
			return Math.max(0, (((Conductor.trackPosition - strumTime) * (-0.45 * FlxMath.roundDecimal(howSpeed * AFFECTED_SCROLLSPEED, 2))) - offset)/100);
		}

		public function setVisibility(visibility:Bool) {
			if(hasCustomAddon != null)
				visible = hasCustomAddon.setVisibility(visibility);
			else
				visible = visibility;
		}

		public function setXaxis(alreadyX:Float) {
			if(hasCustomAddon != null)
				setInverseAxis(distanceAxis, hasCustomAddon.setXPosition(alreadyX));
			else {
				if(noteAbstract != "side note")
					setInverseAxis(distanceAxis, alreadyX);
			}
		}

		public function splash(splashThing:SplashSprite, strumNote:Strum, rating:String):Void {
			if(hasCustomAddon != null) {
				hasCustomAddon.createSplashSprite(splashThing, strumNote, rating);
			}else {
				switch(noteAbstract) {
					default:
						if(rating == "sick" || rating == "good") {
							splashThing.texture = "regular/splash";
							splashThing.setPosition(strumNote.x-(splashThing.width/3), strumNote.y-(splashThing.height/3));
							splashThing.animation.play('sploosh' + strumNote.ID);

							strumNote.setColorTransform(1,1,1,1,0,0,0,0);
							strumNote.animation.play('confirm');

							strumNote.centerOffsets();
							strumNote.offset.x -= 13;
							strumNote.offset.y -= 13;
						}
				}
			}
		}

		function setupPrefixes() {
			animation.addByPrefix('greenScroll', 'green0');
			animation.addByPrefix('redScroll', 'red0');
			animation.addByPrefix('blueScroll', 'blue0');
			animation.addByPrefix('purpleScroll', 'purple0');
			animation.addByPrefix('diamondScroll', 'diamond0');

			if(!wasSustainNote && noteAbstract != "ocean") {
				animation.addByPrefix('purplehold end', 'pruple end hold');
				animation.addByPrefix('greenhold end', 'green hold end');
				animation.addByPrefix('redhold end', 'red hold end');
				animation.addByPrefix('bluehold end', 'blue hold end');

				animation.addByPrefix('purplehold', 'purple hold piece');
				animation.addByPrefix('greenhold', 'green hold piece');
				animation.addByPrefix('redhold', 'red hold piece');
				animation.addByPrefix('bluehold', 'blue hold piece');
			}else if(noteAbstract == "ocean") {
				animation.addByPrefix('purplehold end', 'hold end');
				animation.addByPrefix('greenhold end', 'hold end');
				animation.addByPrefix('redhold end', 'hold end');
				animation.addByPrefix('bluehold end', 'hold end');

				animation.addByPrefix('purplehold', 'hold piece');
				animation.addByPrefix('greenhold', 'hold piece');
				animation.addByPrefix('redhold', 'hold piece');
				animation.addByPrefix('bluehold', 'hold piece');
			}
		}

		function getAddon():CustomNote {
			var customNote:CustomNote = cast Type.createInstance(CustomNoteHandler.customNoteAddon.get(noteAbstract), []);

			if(customNote != null) {
				if(customNote.playerShouldntHit() && !CustomNoteHandler.dontHitNotes.contains(noteAbstract))
					CustomNoteHandler.dontHitNotes.push(noteAbstract);

				if(customNote.noDefaultSplash() && !CustomNoteHandler.noNoteAbstractStrum.contains(noteAbstract))
					CustomNoteHandler.noNoteAbstractStrum.push(noteAbstract);

				if(customNote.giveHealth() < 0 && !CustomNoteHandler.ouchyNotes.contains(noteAbstract))
					CustomNoteHandler.ouchyNotes.push(noteAbstract);
			}
	
			return customNote;
		}

		override function update(elapsed:Float) {
			super.update(elapsed / tickDivider);

			if(ifPlayState) {
				if((noteAbstract == "reverse" || noteAbstract == "reverse poison") && !reverseDebounce) {
					if(getNoteStrumPosition(250) == 0) {
						reverseDebounce = true;

						if(PlayState.SONG.fifthKey)
							noteData = Std.int(Math.abs(noteData-(5-1)));
						else
							noteData = Std.int(Math.abs(noteData-(4-1)));

						refresh(PlayState.SONG.fifthKey);
						refresh(PlayState.SONG.fifthKey, true);
					}
				}
			}

			if(hasCustomAddon != null)
				hasCustomAddon.noteUpdate(this);

			if(trail != null && noteAbstract == "spiritual star") {
				var currentSway:Float = swayTime*(Conductor.bpm/120);
				swayTime += 0.004;

				for(i in 0...trail.length) {
					trail.members[i].y = y+(height/4);
					trail.members[i].alpha = alpha;

					if(1%(i+1) == 0)
						trail.members[i].x = (x+(width/4))+64*(Math.sin(currentSway * Math.PI*(2.5+howSpeed))*1.25);
					else
						trail.members[i].x = (x+(width/4))+64*(-Math.sin(currentSway * Math.PI*(2.5+howSpeed))*1.25);

					trail.members[i].angle = angle;
				}
			}

			if(noteAbstract == "spiritual star") {

				if(PlayState.curStage == "school" || PlayState.curStage == "schoolEvil")
					angle += 4.5*(Conductor.bpm/120);
				else
					angle += 9*(Conductor.bpm/120);	
			}	

			if(trail != null) {
				if(noteAbstract == "trippy") {
					trail.members[0].angle += 3*(Conductor.bpm/120);

					trail.members[0].y = y-(height/4);
					trail.members[0].x = x-(width/4);
				}

				if(noteAbstract == "reverse poison") {
					trail.members[0].angle += 4.5*(Conductor.bpm/120);

					trail.members[0].y = y-(width/2.5);
					trail.members[0].x = x-(width/2);
				}

				if(noteAbstract == "ocean") {
					trail.members[0].x = x;
					trail.members[0].y = y-15;
				}

				if(hasCustomAddon != null && ifPlayState)
					hasCustomAddon.trailUpdate(this);
			}

			if(noteAbstract == "cherry") {
				var currentSway:Float = swayTime*(Conductor.bpm/120);
				swayTime += 0.004;

				angle = 15*Math.sin(currentSway * Math.PI);
			}
	
			if (mustPress)
			{
				var safeHit:Float = 0.5;

				if (Compile.getNoteTime(strumTime) > Conductor.trackPosition - Conductor.safeZoneOffset
					&& Compile.getNoteTime(strumTime) < Conductor.trackPosition + (Conductor.safeZoneOffset * safeHit))
					canBeHit = true;
				else
					canBeHit = false;

				if (Compile.getNoteTime(strumTime) < Conductor.trackPosition - Conductor.safeZoneOffset && !wasGoodHit)
					tooLate = true;
			}
			else
			{
				canBeHit = false;
		
				if (Compile.getNoteTime(strumTime) <= Conductor.trackPosition)
					wasGoodHit = true;
			}
		
			if (tooLate)
			{
				if (alpha > 0.3)
					alpha = 0.3;
			}
		}

		public function getNoteHittable(list:Array<Note>):Note {
			for(i in 0...list.length) {
				if(SaveData.getData(PRESET_INPUTS) == true) {
					if(Math.abs(list[i].strumTime - strumTime) < 1 && (prevNote != this && (!prevNote.canBeHit && noteData != prevNote.noteData))) {
						return this;
					}
				}else {
					if((Math.abs(list[i].getNoteY()) < Note.swagWidth || Math.abs(getNoteY()) < Note.swagWidth)
					&& (prevNote != this && (!prevNote.canBeHit && noteData != prevNote.noteData))) {
						return this;
					}
				}
			}

			return null;
		}

		override function destroy() {
			super.destroy();

			hasCustomAddon = null;

			trail = FlxDestroyUtil.destroy(trail);
		}
}