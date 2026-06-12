package;

/**
 * Utilities for sorting.
 *
 * Ported from Funkin's `funkin.util.SortUtil` (the bits the animation editor needs).
 */
class SortUtil
{
	/**
	 * Sort two strings alphabetically. Use with `Array.sort()`.
	 */
	public static function alphabetically(a:String, b:String):Int
	{
		a = a.toUpperCase();
		b = b.toUpperCase();

		// Sort alphabetically. Yes that's how this works.
		return a == b ? 0 : (a > b ? 1 : -1);
	}
}
