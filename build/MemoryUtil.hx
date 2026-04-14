package;

class MemoryUtil
{
	public static function supportsTaskMem():Bool
	{
		#if ((cpp && (ios || macos)) || linux || android)
		return true;
		#else
		return false;
		#end
	}

	public static function getTaskMemory():Float
	{
		#if ((ios || macos) && cpp)
		return util.AppleMemoryUtil.getCurrentProcessRss();
		#elseif (linux || android)
		try
		{
			#if cpp
			final input:sys.io.FileInput = sys.io.File.read('/proc/${cpp.NativeSys.sys_get_pid()}/status', false);
			#else
			final input:sys.io.FileInput = sys.io.File.read('/proc/self/status', false);
			#end

			final regex:EReg = ~/^VmRSS:\s+(\d+)\s+kB/m;
			var line:String;
			do
			{
				if (input.eof())
				{
					input.close();
					return 0.0;
				}
				line = input.readLine();
			}
			while (!regex.match(line));

			input.close();

			final kb:Float = Std.parseFloat(regex.matched(1));
			if (!Math.isNaN(kb))
			{
				return kb * 1024.0;
			}
		}
		catch (e:Dynamic)
		{
		}
		#end

		return 0.0;
	}

	public static function getGCMemory():Float
	{
		return openfl.system.System.totalMemory;
	}

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
