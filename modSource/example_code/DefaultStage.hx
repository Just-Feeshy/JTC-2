package example_code;

import template.StageBuilder;

class DefaultStage extends StageBuilder {
    public function new(song:String) {
        super(song);
    }

    /**
    * Not important, if you want to make your own stage builder.
    **/
    static public function setMainGameStage(song:String) {
        switch(song.toLowerCase()) {
            case 'spookeez' | 'monster' | 'south':
                return 'spooky';
            case 'pico' | 'blammed' | 'philly':
                return 'philly';
            case 'milf' | 'satin-panties' | 'high':
                return 'limo';
            case 'cocoa' | 'eggnog':
                return 'mall';
            case 'winter-horrorland':
                return 'mallEvil';
            case 'senpai' | 'roses':
                return 'school';
            case 'thorns':
                return 'schoolEvil';
            default:
                return 'stage';
        }
    }
}