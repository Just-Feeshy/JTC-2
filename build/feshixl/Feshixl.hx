package feshixl;

class Feshixl {
    public static function removeNumbersFromString(str:String):String {
        var newString:String = "";

        for(i in 0...str.length) {
            var char:String = str.charAt(i);

            if(Std.parseInt(char) == null) {
                newString += char;
            }
        }

        return newString;
    }
}