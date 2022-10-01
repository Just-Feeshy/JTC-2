package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxObject;
import flixel.FlxCamera;
import flixel.text.FlxText;
import flixel.tweens.FlxTween;
import flixel.tweens.FlxEase;
import flixel.util.FlxColor;

import feshixl.FeshCamera;

class PlayState extends BetterUIStates {
	private var camGame:FeshCamera;
	private var camGen:FeshCamera;

	private var camFollow:FlxObject;

	private var player:Player;
	private var terrain:Terrain;
	private var river:River;

	private var scoreTxt:FlxText; 
	private var highScore:FlxText;

	private var gravity:Float = 100000;
	private var jumpForce:Float = 0;

	private var addJumpForce:Bool = false;
	private var doubleJump:Bool = true;

	private var wallCollided:Bool = false;

	public static var score:Int = 0;

	private var stopGame(default, set):Bool = false;

	@:final private var playerCamOffset:Int = 128;

	private var bloodMoon:Bool = false;

	override public function create():Void {
		//FlxG.mouse.visible = false;

		if (FlxG.sound.music != null) {
			FlxG.sound.music.stop();
		}

		FlxG.sound.playMusic(AssetPath.music("pixel-river"));

		camGame = new FeshCamera();

		FlxG.cameras.setDefaultDrawTarget(camGame, true);
		FlxG.cameras.reset(camGame);

		persistentUpdate = true;
		persistentDraw = true;

		var sky:SkyBackground = new SkyBackground();
		sky.cyan = 5;
		add(sky);

		var moon:FlxSprite = new FlxSprite(0, 0).loadGraphic(AssetPath.image("assets/images/moon"));
		moon.scrollFactor.set(0.1, 0.1);
		moon.scale.x *= 2;
		moon.scale.y *= 2;
		moon.x = FlxG.width - (moon.width * 3) - 30;
		
		moon.updateHitbox();
		add(moon);

		terrain = new Terrain();
		river = new River(360);

		var riverBottom:FlxSprite = new FlxSprite(0, 420).makeGraphic(FlxG.width, Std.int(FlxG.height * 0.75), 0xff005784);
		riverBottom.scrollFactor.set(0, 1);

		player = new Player(0, terrain.maxiumHeight - (terrain.firstGenHeight * 64) - 64);
		player.setGraphicSize(64, 64);
		player.updateHitbox();

		var moon:FlxSprite = new FlxSprite(0, 0).loadGraphic(AssetPath.image("assets/images/moon"));
		moon.scale.x *= 2;
		moon.scale.y *= 2;
		moon.updateHitbox();
		moon.x = FlxG.width - moon.width - 90;
		moon.scrollFactor.set(0.1, 0.1);
		add(moon);

		add(player);
		add(terrain);
		add(riverBottom);
		add(river);

		camFollow = new FlxObject(0, 0, 1, 1);
		camFollow.x = playerCamOffset;
		add(camFollow);

		FlxG.camera.follow(camFollow, LOCKON, 0.04);

		scoreTxt = new FlxText(20, 20, "Score: ", 32);
		scoreTxt.scrollFactor.set(0, 0);
		scoreTxt.borderSize = 20;
		add(scoreTxt);

		highScore = new FlxText(20, 20 + scoreTxt.height, "High Score: " + FlxG.save.data.highScore, 16);
		highScore.scrollFactor.set(0, 0);
		add(highScore);

		super.create();
	}

	override public function update(elapsed:Float):Void {
		if(!stopGame) {
			river.getX = terrain.x;

			camFollow.y = player.getMidpoint().y + playerCamOffset;
			terrain.clearBlocksBeforeX(terrain.collisionMembers, player.x - 64);
			player.gravity = topCollision(player, elapsed);

			wallCollided = wallCollision(player);

			if(controls.DOWN) {
				gravity += (elapsed * 4500 * 64) * 8;
			}

			if(controls.UP && (jumpForce > -1500 && player.isTouchingGround) && !wallCollided) {
				doubleJump = true;

				jumpForce -= 750;
				addJumpForce = true;
			}else if(addJumpForce) {
				player.jumpForce = jumpForce;
				addJumpForce = false;
				jumpForce = 0;
			}

			if(controls.UP_P && !player.isTouchingGround && doubleJump) {
				doubleJump = false;
				gravity = 0;
				player.gravity = 0;
				jumpForce -= 1500;
				addJumpForce = true;
			}

			if(controls.ACCEPT || controls.BACK) {
				pause();
			}

			if(player.isTouchingGround) {
				doubleJump = true;
			}
			
			ded();

			if(!bloodMoon && score > 100) {
				bloodMoon = true;

				trace("it's a blood moon");
				FlxG.camera.color = FlxColor.RED;
			}

			score = Std.int(-terrain.x * 0.01);
			scoreTxt.text = "Score: " + score;
		}else {
			player.gravity = elapsed * 4500 * 64;
		}

		super.update(elapsed);
	}

	function wallCollision(p:Player):Bool {
		var c:Float = 64;

		for(i in 0...terrain.collisionMembers.length) {
			if(p.x > terrain.collisionMembers[i].x - 65 && p.x < terrain.collisionMembers[i].x + 65) {
<<<<<<< Updated upstream
				if(p.y > terrain.collisionMembers[i].y - c && p.y < terrain.collisionMembers[i].y + 64) {
=======
				var c:Int = 64;

				if(p.isTouchingGround) {
					c = 0;
				}

				if((p.y > terrain.collisionMembers[i].y - c && p.y < terrain.collisionMembers[i].y + 64)) {
>>>>>>> Stashed changes
					terrain.stopVelocity = true;
					p.x = terrain.collisionMembers[i].x - 64;

					return true;
				}
			}
		}

		p.x = 0;
		terrain.stopVelocity = false;
		return false;
	}

	function topCollision(p:Player, elapsed:Float):Float {
		player.isTouchingGround = false;

		if(gravity <= 0) {
			gravity = 90000;
		}

		for(i in 0...terrain.collisionMembers.length) {
			if(Math.floor(terrain.collisionMembers[i].x / 64) * 64 == Math.floor(p.x / 64) * 64 || Math.ceil(terrain.collisionMembers[i].x / 64) * 64 == Math.ceil(p.x / 64) * 64) {
				if(p.y >= terrain.collisionMembers[i].y - 88 && p.y < terrain.collisionMembers[i].y) {
					p.isTouchingGround = true;

					if(p.gravity != 0) {
						player.jumpForce = 0;
					}

					gravity = 0;
					break;
				}
			}
		}

		if(gravity > 0) {
			gravity += elapsed * 4500 * 64;
		}

		return gravity;
	}

	function start_HelloWorld():Void {
		var helloWorld:FlxText = new FlxText("Hello World", 32);
		helloWorld.screenCenter();
		add(helloWorld);
	}

	function pause():Void {
		persistentUpdate = false;
		persistentDraw = true;

		openSubState(new PauseSubstate());
	}

	function ded():Void {
		for(i in 0...terrain.collisionMembers.length) {
			if(player.y < terrain.collisionMembers[i].y) {
				return;
			}
		}

		FlxG.sound.music.stop();

		if(score > FlxG.save.data.highScore) {
			FlxG.save.data.highScore = score;
			FlxG.save.flush();
		}

		stopGame = true;
		openSubState(new GameOverSubstate());
	}

	function set_stopGame(value:Bool):Bool {
		if(terrain != null) {
			terrain.stopVelocity = true;
		}

		if(FlxG.sound.music.playing) {
			FlxG.sound.music.stop();
		}

		player.jumpForce = 0;
		return stopGame = value;
	}

	public override function closeSubState():Void {
		persistentUpdate = true;
		persistentDraw = true;

		super.closeSubState();
	}
}