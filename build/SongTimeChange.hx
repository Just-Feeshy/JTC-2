package;

class SongTimeChange
{
	public var timeStamp:Float;
	public var bpm:Int;
	public var timeSignatureNum:Int;
	public var timeSignatureDen:Int;
	public var beatTime:Float = 0.0;

	public function new(timeStamp:Float, bpm:Int, timeSignatureNum:Int = Constants.DEFAULT_TIME_SIGNATURE_NUM, timeSignatureDen:Int = Constants.DEFAULT_TIME_SIGNATURE_DEN)
	{
		this.timeStamp = timeStamp;
		this.bpm = bpm;
		this.timeSignatureNum = timeSignatureNum;
		this.timeSignatureDen = timeSignatureDen;
	}
}
