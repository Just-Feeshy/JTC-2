package util;

#if (ios || macos)
@:buildXml('
<files id="haxe">
	<compilerflag value="-Ibuild/util" />
</files>
')
@:headerCode('
#include <mach/mach.h>
#include <mach/task_info.h>

#ifdef TRUE
#undef TRUE
#endif

#ifdef FALSE
#undef FALSE
#endif
')
class AppleMemoryUtil
{
	@:functionCode('
		mach_task_basic_info_data_t taskInfo;
		mach_msg_type_number_t infoCount = MACH_TASK_BASIC_INFO_COUNT;
		kern_return_t result = task_info(
			mach_task_self(),
			MACH_TASK_BASIC_INFO,
			(task_info_t)&taskInfo,
			&infoCount
		);

		if (result == KERN_SUCCESS)
		{
			return (double)taskInfo.resident_size;
		}

		return 0.0;
	')
	public static function getCurrentProcessRss():Float
	{
		return 0.0;
	}
}
#end
