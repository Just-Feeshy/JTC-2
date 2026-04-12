package;

class Constants
{
	public static inline var DEFAULT_CAMERA_FOLLOW_RATE:Float = 0.04;
	public static inline var DEFAULT_VIBRATION_DURATION:Int = 0;
	public static inline var DEFAULT_CHARACTER:String = "bf";
	public static inline var DEFAULT_BPM:Int = 100;
	public static inline var DEFAULT_TIME_SIGNATURE_NUM:Int = 4;
	public static inline var DEFAULT_TIME_SIGNATURE_DEN:Int = 4;
	public static inline var SECS_PER_MIN:Int = 60;
	public static inline var MS_PER_SEC:Int = 1000;
	public static inline var STEPS_PER_BEAT:Int = 4;
	public static inline var HEALTH_MAX:Float = 2.0;
	public static inline var HEALTH_HOLD_BONUS_PER_SECOND:Float = 6.0 / 100.0 * HEALTH_MAX;
	public static inline var HEALTH_MISS_PENALTY:Float = -4.0 / 100.0 * HEALTH_MAX;
	public static inline var HEALTH_GHOST_MISS_PENALTY:Float = -4.0 / 100.0 * HEALTH_MAX;
	public static inline var HEALTH_HOLD_DROP_PENALTY_PER_SECOND:Float = 0 / 100.0 * HEALTH_MAX;
	public static inline var HEALTH_HOLD_DROP_PENALTY_MAX:Float = 0 / 100.0 * HEALTH_MAX;
	public static inline var SCORE_HOLD_BONUS_PER_SECOND:Float = 250.0;
	public static inline var SCORE_HOLD_DROP_PENALTY_PER_SECOND:Float = -125.0;
	public static inline var HOLD_DROP_PENALTY_THRESHOLD_MS:Float = 160.0;
	public static inline var ANIMATION_HOLD_SUFFIX:String = "-hold";
	public static inline var ANIMATION_END_SUFFIX:String = "-end";
}
