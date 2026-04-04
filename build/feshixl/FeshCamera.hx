package feshixl;

import play.PlayCamera;

/**
 * Legacy menu/options camera wrapper.
 * The old custom draw pipeline has been removed; only the camera behavior
 * still used by non-gameplay states is kept through PlayCamera.
 */
class FeshCamera extends PlayCamera
{
	public function new()
	{
		super();
	}
}
