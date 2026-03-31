package;

import flixel.FlxSprite;

class FunkinSprite extends FlxSprite
{
	public function new(?x:Float = 0, ?y:Float = 0)
	{
		super(x, y);
	}

	public function makeSolidColor(width:Int, height:Int, color:Int):FunkinSprite
	{
		makeGraphic(width, height, color);
		return this;
	}
}
