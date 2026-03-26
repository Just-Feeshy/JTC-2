package;

class MemoryUtil
{
	public static function collect(major:Bool = false):Void
	{
		#if cpp
		cpp.vm.Gc.run(major);
		#else
		openfl.system.System.gc();
		#end
	}

	public static function compact():Void
	{
		#if cpp
		cpp.vm.Gc.compact();
		#else
		openfl.system.System.gc();
		#end
	}
}
