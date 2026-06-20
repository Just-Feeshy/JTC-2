package compat;

#if macro
import haxe.macro.Context;
import haxe.macro.Expr;

class MoraFlxSpriteCompat
{
  public static function build():Array<Field>
  {
    var fields:Array<Field> = Context.getBuildFields();
    var pos:Position = Context.currentPos();

    addField(fields, {
      name: "frameOffset",
      access: [APublic],
      kind: FVar(macro:flixel.math.FlxPoint, macro flixel.math.FlxPoint.get()),
      pos: pos
    });

    addField(fields, {
      name: "frameOffsetAngle",
      access: [APublic],
      kind: FVar(macro:Null<Float>, macro null),
      pos: pos
    });

    addField(fields, {
      name: "layer",
      access: [APublic],
      kind: FVar(macro:Dynamic, macro null),
      pos: pos
    });

    addField(fields, {
      name: "shaderEnabled",
      access: [APublic],
      kind: FVar(macro:Bool, macro true),
      pos: pos
    });

    addField(fields, {
      name: "doAdditionalMatrixStuff",
      access: [APublic],
      kind: FFun({
        args: [
          {name: "matrix", type: macro:flixel.math.FlxMatrix},
          {name: "camera", type: macro:flixel.FlxCamera}
        ],
        ret: macro:Void,
        expr: macro {}
      }),
      pos: pos
    });

    return fields;
  }

  static function addField(fields:Array<Field>, field:Field):Void
  {
    for (existing in fields)
    {
      if (existing.name == field.name) return;
    }

    fields.push(field);
  }
}
#end
