package play.notes;

import flixel.util.FlxColor;

/**
 * The direction of a note.
 * This has implicit casting set up, so you can use this as an integer.
 */
enum abstract NoteDirection(Int) from Int to Int
{
  var LEFT = 0;
  var DOWN = 1;
  var SPACE = 2;
  var UP = 3;
  var RIGHT = 4;
  public var name(get, never):String;
  public var nameUpper(get, never):String;
  public var color(get, never):FlxColor;
  public var colorName(get, never):String;

  @:from
  public static function fromInt(value:Int):NoteDirection
  {
    return fromLane(value, false);
  }

  public static function fromLane(value:Int, fifthKey:Bool = false):NoteDirection
  {
    if (fifthKey) return fromFiveKeyLane(value);

    return switch (value % 4)
    {
      case 0: LEFT;
      case 1: DOWN;
      case 2: UP;
      case 3: RIGHT;
      default: LEFT;
    }
  }

  public static function fromFiveKeyLane(value:Int):NoteDirection
  {
    return switch (value % 5)
    {
      case 0: LEFT;
      case 1: DOWN;
      case 2: SPACE;
      case 3: UP;
      case 4: RIGHT;
      default: LEFT;
    }
  }

  public function toLane(fifthKey:Bool = false):Int
  {
    return if (fifthKey)
    {
      switch (abstract)
      {
        case LEFT: 0;
        case DOWN: 1;
        case SPACE: 2;
        case UP: 3;
        case RIGHT: 4;
        default: 0;
      }
    }
    else
    {
      switch (abstract)
      {
        case LEFT: 0;
        case DOWN: 1;
        case SPACE: 2;
        case UP: 2;
        case RIGHT: 3;
        default: 0;
      }
    }
  }

  public static function list(fifthKey:Bool = false):Array<NoteDirection>
  {
    return fifthKey ? [LEFT, DOWN, SPACE, UP, RIGHT] : [LEFT, DOWN, UP, RIGHT];
  }

  function get_name():String
  {
    return switch (abstract)
    {
      case LEFT:
        'left';
      case DOWN:
        'down';
      case SPACE:
        'space';
      case UP:
        'up';
      case RIGHT:
        'right';
      default:
        'unknown';
    }
  }

  function get_nameUpper():String
  {
    return abstract.name.toUpperCase();
  }

  function get_color():FlxColor
  {
    return switch (abstract)
    {
      case LEFT:
        0xFFC24B99;
      case DOWN:
        0xFF00FFFF;
      case SPACE:
        0xFFFFFF00;
      case UP:
        0xFF12FA05;
      case RIGHT:
        0xFFF9393F;
      default:
        FlxColor.WHITE;
    }
  }

  function get_colorName():String
  {
    return switch (abstract)
    {
      case LEFT:
        'purple';
      case DOWN:
        'blue';
      case SPACE:
        'diamond';
      case UP:
        'green';
      case RIGHT:
        'red';
      default:
        'unknown';
    }
  }

  public function toString():String
  {
    return abstract.name;
  }
}
