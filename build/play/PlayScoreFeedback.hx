package play;

import Conductor;
import GhostTapping;
import Paths;
import PlayState;
import flixel.FlxG;
import flixel.FlxSprite;
import flixel.text.FlxText;
import flixel.tweens.FlxTween;

@:access(PlayState)
class PlayScoreFeedback
{
	private var playState:PlayState;

	public function new(playState:PlayState)
	{
		this.playState = playState;
	}

	public function popUpScore(strumtime:Float, id:Int, abby:String, ?judgeSongPosition:Float, ?noteTag:String):Void
	{
		var noteDiff:Float = Math.abs(strumtime - (judgeSongPosition == null ? Conductor.instance.trackedSongPosition : judgeSongPosition));
		playState.setPlayerVocalsVolume(1, noteTag);

		var placement:String = Std.string(playState.combo);
		var coolText:FlxText = new FlxText(0, 0, 0, placement, 32);
		coolText.screenCenter();
		coolText.x = FlxG.width * 0.55;

		var rating:FlxSprite = new FlxSprite();
		var score:Int = 350;

		if (noteDiff > Conductor.instance.safeZoneOffset * 0.9)
		{
			if(playState.modifierCheckList('get good')) {
				playState.setHealth(playState.health - 2);
			}

			playState.daRating = 'shit';
			score = 50;
			playState.totalRatingAcc -= 0.75 * GhostTapping.consequence;
			playState.combo = 0;
			playState.setHealth(playState.health - 0.05);
		}
		else if (noteDiff > Conductor.instance.safeZoneOffset * 0.75)
		{
			if(playState.modifierCheckList('get good')) {
				playState.setHealth(playState.health - 2);
			}

			playState.daRating = 'bad';
			score = 100;
			playState.totalRatingAcc -= 0.50 * GhostTapping.consequence;
			playState.combo = 0;
			playState.setHealth(playState.health - 0.03);
		}
		else if (noteDiff > Conductor.instance.safeZoneOffset * 0.2)
		{
			playState.daRating = 'good';
			score = 200;
			playState.totalRatingAcc -= 0.10 * GhostTapping.consequence;
			playState.setHealth(playState.health - 0.015);
		}else {
			playState.daRating = 'sick';
		}

		playState.songScore += Std.int(score / GhostTapping.consequence);

		var pixelShitPart1:String = "";
		var pixelShitPart2:String = '';
		var comboUCM:String = '';

		if(playState.combo > 50) {
			comboUCM = '2';
		}

		if (playState.isPixel)
		{
			pixelShitPart1 = 'weeb/pixelUI/';
			pixelShitPart2 = '-pixel';
		}

		rating.loadGraphic(Paths.image(pixelShitPart1 + playState.daRating + pixelShitPart2 + comboUCM));
		rating.screenCenter();
		rating.x = coolText.x - 40;
		rating.y -= 60;
		rating.acceleration.y = 550;
		rating.velocity.y -= FlxG.random.int(140, 175);
		rating.velocity.x -= FlxG.random.int(0, 10);

		var comboSpr:FlxSprite = new FlxSprite().loadGraphic(Paths.image(pixelShitPart1 + 'combo' + pixelShitPart2));
		comboSpr.screenCenter();
		comboSpr.x = coolText.x;
		comboSpr.acceleration.y = 600;
		comboSpr.velocity.y -= 150;
		comboSpr.velocity.x += FlxG.random.int(1, 10);
		playState.add(rating);

		if (!playState.isPixel)
		{
			rating.setGraphicSize(Std.int(rating.width * 0.7));
			rating.antialiasing = FlxG.save.data.showAntialiasing;
			comboSpr.setGraphicSize(Std.int(comboSpr.width * 0.7));
			comboSpr.antialiasing = FlxG.save.data.showAntialiasing;
		}
		else
		{
			rating.setGraphicSize(Std.int(rating.width * PlayState.daPixelZoom * 0.7));
			comboSpr.setGraphicSize(Std.int(comboSpr.width * PlayState.daPixelZoom * 0.7));
		}

		comboSpr.updateHitbox();
		rating.updateHitbox();

		var seperatedScore:Array<Int> = [];
		seperatedScore.push(Math.floor(playState.combo / 100));
		seperatedScore.push(Math.floor((playState.combo - (seperatedScore[0] * 100)) / 10));
		seperatedScore.push(playState.combo % 10);

		var daLoop:Int = 0;
		for (i in seperatedScore)
		{
			var numScore:FlxSprite = new FlxSprite().loadGraphic(Paths.image(pixelShitPart1 + 'num' + Std.int(i) + pixelShitPart2));
			numScore.screenCenter();
			numScore.x = coolText.x + (43 * daLoop) - 90;
			numScore.y += 80;

			if (!playState.isPixel)
			{
				numScore.antialiasing = FlxG.save.data.showAntialiasing;
				numScore.setGraphicSize(Std.int(numScore.width * 0.5));
			}
			else
			{
				numScore.setGraphicSize(Std.int(numScore.width * PlayState.daPixelZoom));
			}
			numScore.updateHitbox();

			numScore.acceleration.y = FlxG.random.int(200, 300);
			numScore.velocity.y -= FlxG.random.int(140, 160);
			numScore.velocity.x = FlxG.random.float(-5, 5);

			if (playState.combo >= 10 || playState.combo == 0) {
				playState.add(numScore);
			}

			FlxTween.tween(numScore, {alpha: 0}, 0.2, {
				onComplete: function(_:FlxTween)
				{
					numScore.destroy();
				},
				startDelay: Conductor.instance.beatLengthMs * 0.002
			});

			daLoop++;
		}

		coolText.text = Std.string(seperatedScore);

		FlxTween.tween(rating, {alpha: 0}, 0.2, {
			startDelay: Conductor.instance.beatLengthMs * 0.001
		});

		FlxTween.tween(comboSpr, {alpha: 0}, 0.2, {
			onComplete: function(_:FlxTween)
			{
				coolText.destroy();
				comboSpr.destroy();
				rating.destroy();
			},
			startDelay: Conductor.instance.beatLengthMs * 0.001
		});

		playState.curSection += 1;
	}
}
