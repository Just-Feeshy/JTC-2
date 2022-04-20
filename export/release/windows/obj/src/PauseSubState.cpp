#include <hxcpp.h>

#ifndef INCLUDED_Alphabet
#include <Alphabet.h>
#endif
#ifndef INCLUDED_Compile
#include <Compile.h>
#endif
#ifndef INCLUDED_Controls
#include <Controls.h>
#endif
#ifndef INCLUDED_CoolUtil
#include <CoolUtil.h>
#endif
#ifndef INCLUDED_HelperStates
#include <HelperStates.h>
#endif
#ifndef INCLUDED_KeyboardScheme
#include <KeyboardScheme.h>
#endif
#ifndef INCLUDED_MainMenuState
#include <MainMenuState.h>
#endif
#ifndef INCLUDED_MusicBeatState
#include <MusicBeatState.h>
#endif
#ifndef INCLUDED_MusicBeatSubstate
#include <MusicBeatSubstate.h>
#endif
#ifndef INCLUDED_Paths
#include <Paths.h>
#endif
#ifndef INCLUDED_PauseSubState
#include <PauseSubState.h>
#endif
#ifndef INCLUDED_PlayState
#include <PlayState.h>
#endif
#ifndef INCLUDED_PlayerSettings
#include <PlayerSettings.h>
#endif
#ifndef INCLUDED_SaveType
#include <SaveType.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_betterShit_BetterCams
#include <betterShit/BetterCams.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxCamera
#include <flixel/FlxCamera.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_FlxGame
#include <flixel/FlxGame.h>
#endif
#ifndef INCLUDED_flixel_FlxObject
#include <flixel/FlxObject.h>
#endif
#ifndef INCLUDED_flixel_FlxSprite
#include <flixel/FlxSprite.h>
#endif
#ifndef INCLUDED_flixel_FlxState
#include <flixel/FlxState.h>
#endif
#ifndef INCLUDED_flixel_FlxSubState
#include <flixel/FlxSubState.h>
#endif
#ifndef INCLUDED_flixel_addons_transition_FlxTransitionableState
#include <flixel/addons/transition/FlxTransitionableState.h>
#endif
#ifndef INCLUDED_flixel_addons_ui_FlxUIState
#include <flixel/addons/ui/FlxUIState.h>
#endif
#ifndef INCLUDED_flixel_addons_ui_interfaces_IEventGetter
#include <flixel/addons/ui/interfaces/IEventGetter.h>
#endif
#ifndef INCLUDED_flixel_addons_ui_interfaces_IFlxUIState
#include <flixel/addons/ui/interfaces/IFlxUIState.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedSpriteGroup
#include <flixel/group/FlxTypedSpriteGroup.h>
#endif
#ifndef INCLUDED_flixel_input_actions_FlxAction
#include <flixel/input/actions/FlxAction.h>
#endif
#ifndef INCLUDED_flixel_input_actions_FlxActionDigital
#include <flixel/input/actions/FlxActionDigital.h>
#endif
#ifndef INCLUDED_flixel_input_actions_FlxActionSet
#include <flixel/input/actions/FlxActionSet.h>
#endif
#ifndef INCLUDED_flixel_math_FlxPoint
#include <flixel/math/FlxPoint.h>
#endif
#ifndef INCLUDED_flixel_math_FlxRandom
#include <flixel/math/FlxRandom.h>
#endif
#ifndef INCLUDED_flixel_system_FlxSound
#include <flixel/system/FlxSound.h>
#endif
#ifndef INCLUDED_flixel_system_FlxSoundGroup
#include <flixel/system/FlxSoundGroup.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_SoundFrontEnd
#include <flixel/system/frontEnds/SoundFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_text_FlxText
#include <flixel/text/FlxText.h>
#endif
#ifndef INCLUDED_flixel_text_FlxTextBorderStyle
#include <flixel/text/FlxTextBorderStyle.h>
#endif
#ifndef INCLUDED_flixel_tweens_FlxEase
#include <flixel/tweens/FlxEase.h>
#endif
#ifndef INCLUDED_flixel_tweens_FlxTween
#include <flixel/tweens/FlxTween.h>
#endif
#ifndef INCLUDED_flixel_tweens_misc_VarTween
#include <flixel/tweens/misc/VarTween.h>
#endif
#ifndef INCLUDED_flixel_util_FlxSave
#include <flixel/util/FlxSave.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxDestroyable
#include <flixel/util/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxPooled
#include <flixel/util/IFlxPooled.h>
#endif
#ifndef INCLUDED_haxe_Exception
#include <haxe/Exception.h>
#endif
#ifndef INCLUDED_lime_utils_Assets
#include <lime/utils/Assets.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObject
#include <openfl/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObjectContainer
#include <openfl/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_openfl_display_IBitmapDrawable
#include <openfl/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl_display_InteractiveObject
#include <openfl/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_openfl_display_Sprite
#include <openfl/display/Sprite.h>
#endif
#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_17d383cbce329512_18_new,"PauseSubState","new",0x00d575d9,"PauseSubState.new","PauseSubState.hx",18,0x953dc7b7)
static const ::String _hx_array_data_08e59567_3[] = {
	HX_("Resume",cd,dd,18,3d),HX_("Restart Song",06,b6,fe,13),HX_("Change Controls",26,2b,ef,e8),HX_("Exit to menu",82,87,9a,a9),
};
HX_LOCAL_STACK_FRAME(_hx_pos_17d383cbce329512_106_update,"PauseSubState","update",0x6d53d230,"PauseSubState.update","PauseSubState.hx",106,0x953dc7b7)
HX_LOCAL_STACK_FRAME(_hx_pos_17d383cbce329512_186_destroy,"PauseSubState","destroy",0xc2ba82f3,"PauseSubState.destroy","PauseSubState.hx",186,0x953dc7b7)
HX_LOCAL_STACK_FRAME(_hx_pos_17d383cbce329512_193_changeSelection,"PauseSubState","changeSelection",0x8f960fb5,"PauseSubState.changeSelection","PauseSubState.hx",193,0x953dc7b7)

void PauseSubState_obj::__construct(Float x,Float y){
            	HX_GC_STACKFRAME(&_hx_pos_17d383cbce329512_18_new)
HXLINE(  26)		this->curSelected = 0;
HXLINE(  25)		this->menuItems = ::Array_obj< ::String >::fromData( _hx_array_data_08e59567_3,4);
HXLINE(  32)		super::__construct();
HXLINE(  34)		 ::flixel::_hx_system::FlxSound _hx_tmp =  ::flixel::_hx_system::FlxSound_obj::__alloc( HX_CTX );
HXDLIN(  34)		::String library = null();
HXDLIN(  34)		::String _hx_tmp1;
HXDLIN(  34)		if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("music/",ea,bf,1b,3f) + HX_("breakfast",db,b2,0c,49)) + HX_(".",2e,00,00,00)) + HX_("ogg",4f,94,54,00)),HX_("MUSIC",85,08,49,8e),library),null())) {
HXLINE(  34)			_hx_tmp1 = ::Paths_obj::getPath((((HX_("music/",ea,bf,1b,3f) + HX_("breakfast",db,b2,0c,49)) + HX_(".",2e,00,00,00)) + HX_("ogg",4f,94,54,00)),HX_("MUSIC",85,08,49,8e),library);
            		}
            		else {
HXLINE(  34)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate music - ",82,28,df,2c) + HX_("breakfast",db,b2,0c,49))));
            		}
HXDLIN(  34)		this->pauseMusic = _hx_tmp->loadEmbedded(_hx_tmp1,true,true,null());
HXLINE(  35)		this->pauseMusic->set_volume(( (Float)(0) ));
HXLINE(  36)		 ::flixel::_hx_system::FlxSound _hx_tmp2 = this->pauseMusic;
HXDLIN(  36)		 ::flixel::math::FlxRandom _hx_tmp3 = ::flixel::FlxG_obj::random;
HXDLIN(  36)		_hx_tmp2->play(false,_hx_tmp3->_hx_int(0,::Std_obj::_hx_int((this->pauseMusic->_length / ( (Float)(2) ))),null()),null());
HXLINE(  38)		::flixel::FlxG_obj::sound->list->add(this->pauseMusic).StaticCast<  ::flixel::_hx_system::FlxSound >();
HXLINE(  40)		 ::flixel::FlxSprite bg =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,null(),null(),null())->makeGraphic(::flixel::FlxG_obj::width,::flixel::FlxG_obj::height,-16777216,null(),null());
HXLINE(  41)		bg->set_alpha(( (Float)(0) ));
HXLINE(  42)		bg->scrollFactor->set(null(),null());
HXLINE(  43)		this->add(bg);
HXLINE(  45)		 ::flixel::text::FlxText levelInfo =  ::flixel::text::FlxText_obj::__alloc( HX_CTX ,20,15,0,HX_("",00,00,00,00),32,null());
HXLINE(  46)		levelInfo->set_text(( (::String)((levelInfo->text + ::PlayState_obj::SONG->__Field(HX_("song",d5,23,58,4c),::hx::paccDynamic))) ));
HXLINE(  47)		levelInfo->scrollFactor->set(null(),null());
HXLINE(  48)		levelInfo->setFormat((HX_("assets/fonts/",37,ff,a5,9c) + HX_("vcr.ttf",9d,d2,a7,82)),32,null(),null(),null(),null(),null());
HXLINE(  49)		levelInfo->updateHitbox();
HXLINE(  50)		this->add(levelInfo);
HXLINE(  52)		 ::flixel::text::FlxText levelDifficulty =  ::flixel::text::FlxText_obj::__alloc( HX_CTX ,20,47,0,HX_("",00,00,00,00),32,null());
HXLINE(  53)		::String levelDifficulty1 = levelDifficulty->text;
HXDLIN(  53)		levelDifficulty->set_text((levelDifficulty1 + ::CoolUtil_obj::difficultyString()));
HXLINE(  54)		levelDifficulty->scrollFactor->set(null(),null());
HXLINE(  55)		levelDifficulty->setFormat((HX_("assets/fonts/",37,ff,a5,9c) + HX_("vcr.ttf",9d,d2,a7,82)),32,null(),null(),null(),null(),null());
HXLINE(  56)		levelDifficulty->updateHitbox();
HXLINE(  57)		this->add(levelDifficulty);
HXLINE(  60)		this->otherStuff =  ::flixel::text::FlxText_obj::__alloc( HX_CTX ,20,111,0,HX_("",00,00,00,00),32,null());
HXLINE(  62)		{
HXLINE(  62)			 ::Dynamic _g;
HXDLIN(  62)			switch((int)(::SaveType_obj::PRESET_KEYBINDS_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE(  62)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  62)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN(  62)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE(  62)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  62)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE(  62)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  62)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN(  62)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE(  62)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  62)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN(  62)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE(  62)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  62)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN(  62)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE(  62)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  62)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN(  62)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE(  62)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  62)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  62)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE(  62)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  62)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  62)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE(  62)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  62)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN(  62)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE(  62)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  62)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN(  62)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE(  62)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  62)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN(  62)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE(  62)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  62)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE(  62)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  62)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN(  62)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE(  62)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  62)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN(  62)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE(  62)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  62)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN(  62)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE(  62)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  62)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN(  62)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE(  62)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  62)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN(  62)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE(  62)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  62)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN(  62)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE(  62)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  62)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN(  62)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE(  62)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  62)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN(  62)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE(  62)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  62)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN(  62)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE(  62)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  62)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN(  62)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE(  62)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  62)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN(  62)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE(  62)					_g = null();
            				}
            			}
HXDLIN(  62)			 ::Dynamic _hx_switch_0 = _g;
            			if (  (_hx_switch_0==0) ){
HXLINE(  64)				this->otherStuff->set_text((HX_("SCHEME: ",0b,12,eb,24) + HX_("WASD",1b,2b,b3,39)));
HXDLIN(  64)				goto _hx_goto_0;
            			}
            			if (  (_hx_switch_0==1) ){
HXLINE(  66)				this->otherStuff->set_text((HX_("SCHEME: ",0b,12,eb,24) + HX_("DFJK",c3,e0,27,2d)));
HXDLIN(  66)				goto _hx_goto_0;
            			}
            			if (  (_hx_switch_0==2) ){
HXLINE(  68)				this->otherStuff->set_text((HX_("SCHEME: ",0b,12,eb,24) + HX_("ZX12",1f,25,c0,3b)));
HXDLIN(  68)				goto _hx_goto_0;
            			}
            			if (  (_hx_switch_0==3) ){
HXLINE(  70)				this->otherStuff->set_text((HX_("SCHEME: ",0b,12,eb,24) + HX_("CUSTOM",b1,33,15,f2)));
HXDLIN(  70)				goto _hx_goto_0;
            			}
            			_hx_goto_0:;
            		}
HXLINE(  73)		this->otherStuff->scrollFactor->set(null(),null());
HXLINE(  74)		this->otherStuff->setFormat((HX_("assets/fonts/",37,ff,a5,9c) + HX_("vcr.ttf",9d,d2,a7,82)),32,null(),null(),null(),null(),null());
HXLINE(  75)		this->otherStuff->updateHitbox();
HXLINE(  76)		this->add(this->otherStuff);
HXLINE(  78)		levelDifficulty->set_alpha(( (Float)(0) ));
HXLINE(  79)		levelInfo->set_alpha(( (Float)(0) ));
HXLINE(  80)		this->otherStuff->set_alpha(( (Float)(0) ));
HXLINE(  82)		int _hx_tmp4 = ::flixel::FlxG_obj::width;
HXDLIN(  82)		levelInfo->set_x((( (Float)(_hx_tmp4) ) - (levelInfo->get_width() + 20)));
HXLINE(  83)		int _hx_tmp5 = ::flixel::FlxG_obj::width;
HXDLIN(  83)		levelDifficulty->set_x((( (Float)(_hx_tmp5) ) - (levelDifficulty->get_width() + 20)));
HXLINE(  84)		 ::flixel::text::FlxText _hx_tmp6 = this->otherStuff;
HXDLIN(  84)		int _hx_tmp7 = ::flixel::FlxG_obj::width;
HXDLIN(  84)		_hx_tmp6->set_x((( (Float)(_hx_tmp7) ) - (this->otherStuff->get_width() + 20)));
HXLINE(  86)		::flixel::tweens::FlxTween_obj::tween(bg, ::Dynamic(::hx::Anon_obj::Create(1)
            			->setFixed(0,HX_("alpha",5e,a7,96,21),((Float)0.6))),((Float)0.4), ::Dynamic(::hx::Anon_obj::Create(1)
            			->setFixed(0,HX_("ease",ee,8b,0c,43),::flixel::tweens::FlxEase_obj::quartInOut_dyn())));
HXLINE(  87)		::flixel::tweens::FlxTween_obj::tween(levelInfo, ::Dynamic(::hx::Anon_obj::Create(2)
            			->setFixed(0,HX_("y",79,00,00,00),20)
            			->setFixed(1,HX_("alpha",5e,a7,96,21),1)),((Float)0.4), ::Dynamic(::hx::Anon_obj::Create(2)
            			->setFixed(0,HX_("startDelay",c1,af,3d,f3),((Float)0.3))
            			->setFixed(1,HX_("ease",ee,8b,0c,43),::flixel::tweens::FlxEase_obj::quartInOut_dyn())));
HXLINE(  88)		::flixel::tweens::FlxTween_obj::tween(levelDifficulty, ::Dynamic(::hx::Anon_obj::Create(2)
            			->setFixed(0,HX_("y",79,00,00,00),(levelDifficulty->y + 5))
            			->setFixed(1,HX_("alpha",5e,a7,96,21),1)),((Float)0.4), ::Dynamic(::hx::Anon_obj::Create(2)
            			->setFixed(0,HX_("startDelay",c1,af,3d,f3),((Float)0.5))
            			->setFixed(1,HX_("ease",ee,8b,0c,43),::flixel::tweens::FlxEase_obj::quartInOut_dyn())));
HXLINE(  90)		this->grpMenuShit =  ::flixel::group::FlxTypedGroup_obj::__alloc( HX_CTX ,null());
HXLINE(  91)		this->add(this->grpMenuShit);
HXLINE(  93)		{
HXLINE(  93)			int _g1 = 0;
HXDLIN(  93)			int _g2 = this->menuItems->length;
HXDLIN(  93)			while((_g1 < _g2)){
HXLINE(  93)				_g1 = (_g1 + 1);
HXDLIN(  93)				int i = (_g1 - 1);
HXLINE(  95)				 ::Alphabet songText =  ::Alphabet_obj::__alloc( HX_CTX ,( (Float)(0) ),( (Float)(((70 * i) + 30)) ),this->menuItems->__get(i),true,false,null());
HXLINE(  96)				songText->isMenuItem = true;
HXLINE(  97)				songText->targetY = i;
HXLINE(  98)				this->grpMenuShit->add(songText).StaticCast<  ::Alphabet >();
            			}
            		}
HXLINE( 101)		this->changeSelection(null());
HXLINE( 103)		this->set_cameras(::Array_obj< ::Dynamic>::__new(1)->init(0,::PlayState_obj::camHUD));
            	}

Dynamic PauseSubState_obj::__CreateEmpty() { return new PauseSubState_obj; }

void *PauseSubState_obj::_hx_vtable = 0;

Dynamic PauseSubState_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< PauseSubState_obj > _hx_result = new PauseSubState_obj();
	_hx_result->__construct(inArgs[0],inArgs[1]);
	return _hx_result;
}

bool PauseSubState_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x62817b24) {
		if (inClassId<=(int)0x5661ffbf) {
			if (inClassId<=(int)0x519cdafb) {
				return inClassId==(int)0x00000001 || inClassId==(int)0x519cdafb;
			} else {
				return inClassId==(int)0x5661ffbf;
			}
		} else {
			return inClassId==(int)0x62817b24;
		}
	} else {
		if (inClassId<=(int)0x7ccf8994) {
			return inClassId==(int)0x7c795c9f || inClassId==(int)0x7ccf8994;
		} else {
			return inClassId==(int)0x7fce3ab0;
		}
	}
}

void PauseSubState_obj::update(Float elapsed){
            	HX_GC_STACKFRAME(&_hx_pos_17d383cbce329512_106_update)
HXLINE( 107)		if ((this->pauseMusic->_volume < ((Float)0.5))) {
HXLINE( 108)			 ::flixel::_hx_system::FlxSound fh = this->pauseMusic;
HXDLIN( 108)			fh->set_volume((fh->_volume + (((Float)0.01) * elapsed)));
            		}
HXLINE( 110)		this->super::update(elapsed);
HXLINE( 112)		bool upP = ::PlayerSettings_obj::player1->controls->_upP->check();
HXLINE( 113)		bool downP = ::PlayerSettings_obj::player1->controls->_downP->check();
HXLINE( 114)		bool accepted = ::PlayerSettings_obj::player1->controls->_accept->check();
HXLINE( 116)		if (upP) {
HXLINE( 118)			this->changeSelection(-1);
            		}
HXLINE( 120)		if (downP) {
HXLINE( 122)			this->changeSelection(1);
            		}
HXLINE( 125)		if (accepted) {
HXLINE( 127)			::String daSelected = this->menuItems->__get(this->curSelected);
HXLINE( 129)			::String _hx_switch_0 = daSelected;
            			if (  (_hx_switch_0==HX_("Change Controls",26,2b,ef,e8)) ){
HXLINE( 139)				 ::flixel::_hx_system::frontEnds::SoundFrontEnd _hx_tmp = ::flixel::FlxG_obj::sound;
HXDLIN( 139)				::String library = null();
HXDLIN( 139)				::String _hx_tmp1;
HXDLIN( 139)				if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("sounds/",eb,02,a5,b6) + HX_("scrollMenu",4c,d4,18,06)) + HX_(".",2e,00,00,00)) + HX_("ogg",4f,94,54,00)),HX_("SOUND",af,c4,ba,fe),library),null())) {
HXLINE( 139)					_hx_tmp1 = ::Paths_obj::getPath((((HX_("sounds/",eb,02,a5,b6) + HX_("scrollMenu",4c,d4,18,06)) + HX_(".",2e,00,00,00)) + HX_("ogg",4f,94,54,00)),HX_("SOUND",af,c4,ba,fe),library);
            				}
            				else {
HXLINE( 139)					HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate sound - ",98,e2,ed,38) + HX_("scrollMenu",4c,d4,18,06))));
            				}
HXDLIN( 139)				_hx_tmp->play(_hx_tmp1,((Float)0.4),null(),null(),null(),null());
HXLINE( 141)				 ::Dynamic fh = ::flixel::FlxG_obj::save->data;
HXDLIN( 141)				fh->__SetField(HX_("dfjk",c3,18,67,42),(fh->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) + 1),::hx::paccDynamic);
HXLINE( 143)				if (::hx::IsGreater( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic),3 )) {
HXLINE( 144)					::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            				}
HXLINE( 146)				{
HXLINE( 146)					 ::Dynamic _g;
HXDLIN( 146)					switch((int)(::SaveType_obj::PRESET_KEYBINDS_dyn()->_hx_getIndex())){
            						case (int)1: {
HXLINE( 146)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 146)								::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            							}
HXDLIN( 146)							_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            						}
            						break;
            						case (int)2: {
HXLINE( 146)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 146)								::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            							}
            							else {
HXLINE( 146)								if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 146)									::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            								}
            							}
HXDLIN( 146)							_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            						}
            						break;
            						case (int)3: {
HXLINE( 146)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 146)								::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            							}
HXDLIN( 146)							_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            						}
            						break;
            						case (int)4: {
HXLINE( 146)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 146)								::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            							}
HXDLIN( 146)							_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            						}
            						break;
            						case (int)5: {
HXLINE( 146)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 146)								::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            							}
HXDLIN( 146)							_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            						}
            						break;
            						case (int)6: {
HXLINE( 146)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 146)								::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            							}
HXDLIN( 146)							_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            						}
            						break;
            						case (int)7: {
HXLINE( 146)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 146)								::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            							}
HXDLIN( 146)							_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            						}
            						break;
            						case (int)8: {
HXLINE( 146)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 146)								::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            							}
HXDLIN( 146)							_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            						}
            						break;
            						case (int)9: {
HXLINE( 146)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 146)								::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            							}
HXDLIN( 146)							_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            						}
            						break;
            						case (int)10: {
HXLINE( 146)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 146)								::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            							}
HXDLIN( 146)							_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            						}
            						break;
            						case (int)11: {
HXLINE( 146)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 146)								::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            							}
            							else {
HXLINE( 146)								if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 146)									::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            								}
            							}
HXDLIN( 146)							_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            						}
            						break;
            						case (int)12: {
HXLINE( 146)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 146)								::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            							}
HXDLIN( 146)							_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            						}
            						break;
            						case (int)13: {
HXLINE( 146)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 146)								::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            							}
HXDLIN( 146)							_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            						}
            						break;
            						case (int)14: {
HXLINE( 146)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 146)								::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            							}
HXDLIN( 146)							_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            						}
            						break;
            						case (int)15: {
HXLINE( 146)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 146)								::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            							}
HXDLIN( 146)							_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            						}
            						break;
            						case (int)16: {
HXLINE( 146)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 146)								::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            							}
HXDLIN( 146)							_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            						}
            						break;
            						case (int)17: {
HXLINE( 146)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 146)								::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            							}
HXDLIN( 146)							_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            						}
            						break;
            						case (int)18: {
HXLINE( 146)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 146)								::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            							}
HXDLIN( 146)							_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            						}
            						break;
            						case (int)19: {
HXLINE( 146)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 146)								::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            							}
HXDLIN( 146)							_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            						}
            						break;
            						case (int)20: {
HXLINE( 146)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 146)								::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            							}
HXDLIN( 146)							_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            						}
            						break;
            						case (int)21: {
HXLINE( 146)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 146)								::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            							}
HXDLIN( 146)							_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            						}
            						break;
            						default:{
HXLINE( 146)							_g = null();
            						}
            					}
HXDLIN( 146)					 ::Dynamic _hx_switch_1 = _g;
            					if (  (_hx_switch_1==0) ){
HXLINE( 148)						::PlayerSettings_obj::player1->controls->setKeyboardScheme(::KeyboardScheme_obj::Duo(true),true);
HXDLIN( 148)						goto _hx_goto_5;
            					}
            					if (  (_hx_switch_1==1) ){
HXLINE( 150)						::PlayerSettings_obj::player1->controls->setKeyboardScheme(::KeyboardScheme_obj::Solo_dyn(),true);
HXDLIN( 150)						goto _hx_goto_5;
            					}
            					if (  (_hx_switch_1==2) ){
HXLINE( 152)						::PlayerSettings_obj::player1->controls->setKeyboardScheme(::KeyboardScheme_obj::Duo(false),true);
HXDLIN( 152)						goto _hx_goto_5;
            					}
            					if (  (_hx_switch_1==3) ){
HXLINE( 154)						::PlayerSettings_obj::player1->controls->setKeyboardScheme(::KeyboardScheme_obj::Custom_dyn(),true);
HXDLIN( 154)						goto _hx_goto_5;
            					}
            					_hx_goto_5:;
            				}
HXLINE( 157)				{
HXLINE( 157)					 ::Dynamic _g1;
HXDLIN( 157)					switch((int)(::SaveType_obj::PRESET_KEYBINDS_dyn()->_hx_getIndex())){
            						case (int)1: {
HXLINE( 157)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 157)								::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            							}
HXDLIN( 157)							_g1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            						}
            						break;
            						case (int)2: {
HXLINE( 157)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 157)								::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            							}
            							else {
HXLINE( 157)								if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 157)									::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            								}
            							}
HXDLIN( 157)							_g1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            						}
            						break;
            						case (int)3: {
HXLINE( 157)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 157)								::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            							}
HXDLIN( 157)							_g1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            						}
            						break;
            						case (int)4: {
HXLINE( 157)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 157)								::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            							}
HXDLIN( 157)							_g1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            						}
            						break;
            						case (int)5: {
HXLINE( 157)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 157)								::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            							}
HXDLIN( 157)							_g1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            						}
            						break;
            						case (int)6: {
HXLINE( 157)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 157)								::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            							}
HXDLIN( 157)							_g1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            						}
            						break;
            						case (int)7: {
HXLINE( 157)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 157)								::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            							}
HXDLIN( 157)							_g1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            						}
            						break;
            						case (int)8: {
HXLINE( 157)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 157)								::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            							}
HXDLIN( 157)							_g1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            						}
            						break;
            						case (int)9: {
HXLINE( 157)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 157)								::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            							}
HXDLIN( 157)							_g1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            						}
            						break;
            						case (int)10: {
HXLINE( 157)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 157)								::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            							}
HXDLIN( 157)							_g1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            						}
            						break;
            						case (int)11: {
HXLINE( 157)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 157)								::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            							}
            							else {
HXLINE( 157)								if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 157)									::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            								}
            							}
HXDLIN( 157)							_g1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            						}
            						break;
            						case (int)12: {
HXLINE( 157)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 157)								::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            							}
HXDLIN( 157)							_g1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            						}
            						break;
            						case (int)13: {
HXLINE( 157)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 157)								::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            							}
HXDLIN( 157)							_g1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            						}
            						break;
            						case (int)14: {
HXLINE( 157)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 157)								::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            							}
HXDLIN( 157)							_g1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            						}
            						break;
            						case (int)15: {
HXLINE( 157)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 157)								::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            							}
HXDLIN( 157)							_g1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            						}
            						break;
            						case (int)16: {
HXLINE( 157)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 157)								::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            							}
HXDLIN( 157)							_g1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            						}
            						break;
            						case (int)17: {
HXLINE( 157)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 157)								::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            							}
HXDLIN( 157)							_g1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            						}
            						break;
            						case (int)18: {
HXLINE( 157)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 157)								::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            							}
HXDLIN( 157)							_g1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            						}
            						break;
            						case (int)19: {
HXLINE( 157)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 157)								::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            							}
HXDLIN( 157)							_g1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            						}
            						break;
            						case (int)20: {
HXLINE( 157)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 157)								::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            							}
HXDLIN( 157)							_g1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            						}
            						break;
            						case (int)21: {
HXLINE( 157)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 157)								::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            							}
HXDLIN( 157)							_g1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            						}
            						break;
            						default:{
HXLINE( 157)							_g1 = null();
            						}
            					}
HXDLIN( 157)					 ::Dynamic _hx_switch_2 = _g1;
            					if (  (_hx_switch_2==0) ){
HXLINE( 159)						this->otherStuff->set_text((HX_("SCHEME: ",0b,12,eb,24) + HX_("WASD",1b,2b,b3,39)));
HXDLIN( 159)						goto _hx_goto_6;
            					}
            					if (  (_hx_switch_2==1) ){
HXLINE( 161)						this->otherStuff->set_text((HX_("SCHEME: ",0b,12,eb,24) + HX_("DFJK",c3,e0,27,2d)));
HXDLIN( 161)						goto _hx_goto_6;
            					}
            					if (  (_hx_switch_2==2) ){
HXLINE( 163)						this->otherStuff->set_text((HX_("SCHEME: ",0b,12,eb,24) + HX_("ZX12",1f,25,c0,3b)));
HXDLIN( 163)						goto _hx_goto_6;
            					}
            					if (  (_hx_switch_2==3) ){
HXLINE( 165)						this->otherStuff->set_text((HX_("SCHEME: ",0b,12,eb,24) + HX_("CUSTOM",b1,33,15,f2)));
HXDLIN( 165)						goto _hx_goto_6;
            					}
            					_hx_goto_6:;
            				}
HXLINE( 168)				 ::flixel::text::FlxText _hx_tmp2 = this->otherStuff;
HXDLIN( 168)				int _hx_tmp3 = ::flixel::FlxG_obj::width;
HXDLIN( 168)				_hx_tmp2->set_x((( (Float)(_hx_tmp3) ) - (this->otherStuff->get_width() + 20)));
HXLINE( 138)				goto _hx_goto_4;
            			}
            			if (  (_hx_switch_0==HX_("Exit to menu",82,87,9a,a9)) ){
HXLINE( 136)				::Compile_obj::kill();
HXLINE( 137)				{
HXLINE( 137)					 ::flixel::FlxState nextState =  ::MainMenuState_obj::__alloc( HX_CTX ,null());
HXDLIN( 137)					if (::flixel::FlxG_obj::game->_state->switchTo(nextState)) {
HXLINE( 137)						::flixel::FlxG_obj::game->_requestedState = nextState;
            					}
            				}
HXLINE( 135)				goto _hx_goto_4;
            			}
            			if (  (_hx_switch_0==HX_("Restart Song",06,b6,fe,13)) ){
HXLINE( 134)				 ::flixel::FlxState nextState = ( ( ::flixel::FlxState)(::Type_obj::createInstance(::Type_obj::getClass(::flixel::FlxG_obj::game->_state),::cpp::VirtualArray_obj::__new(0))) );
HXDLIN( 134)				if (::flixel::FlxG_obj::game->_state->switchTo(nextState)) {
HXLINE( 134)					::flixel::FlxG_obj::game->_requestedState = nextState;
            				}
HXDLIN( 134)				goto _hx_goto_4;
            			}
            			if (  (_hx_switch_0==HX_("Resume",cd,dd,18,3d)) ){
HXLINE( 132)				this->close();
HXDLIN( 132)				goto _hx_goto_4;
            			}
            			_hx_goto_4:;
            		}
HXLINE( 172)		if ((this->menuItems->__get(this->curSelected) == HX_("Change Controls",26,2b,ef,e8))) {
HXLINE( 173)			if (!(this->doneHover)) {
HXLINE( 174)				this->doneHover = true;
HXLINE( 175)				::flixel::tweens::FlxTween_obj::tween(this->otherStuff, ::Dynamic(::hx::Anon_obj::Create(2)
            					->setFixed(0,HX_("y",79,00,00,00),(this->otherStuff->y - ( (Float)(5) )))
            					->setFixed(1,HX_("alpha",5e,a7,96,21),1)),((Float)0.4), ::Dynamic(::hx::Anon_obj::Create(2)
            					->setFixed(0,HX_("startDelay",c1,af,3d,f3),0)
            					->setFixed(1,HX_("ease",ee,8b,0c,43),::flixel::tweens::FlxEase_obj::quartInOut_dyn())));
            			}
            		}
            		else {
HXLINE( 178)			if (this->doneHover) {
HXLINE( 179)				this->doneHover = false;
HXLINE( 180)				::flixel::tweens::FlxTween_obj::tween(this->otherStuff, ::Dynamic(::hx::Anon_obj::Create(2)
            					->setFixed(0,HX_("y",79,00,00,00),(this->otherStuff->y + 5))
            					->setFixed(1,HX_("alpha",5e,a7,96,21),0)),((Float)0.4), ::Dynamic(::hx::Anon_obj::Create(2)
            					->setFixed(0,HX_("startDelay",c1,af,3d,f3),0)
            					->setFixed(1,HX_("ease",ee,8b,0c,43),::flixel::tweens::FlxEase_obj::quartInOut_dyn())));
            			}
            		}
            	}


void PauseSubState_obj::destroy(){
            	HX_STACKFRAME(&_hx_pos_17d383cbce329512_186_destroy)
HXLINE( 187)		this->pauseMusic->destroy();
HXLINE( 189)		this->super::destroy();
            	}


void PauseSubState_obj::changeSelection(::hx::Null< int >  __o_change){
            		int change = __o_change.Default(0);
            	HX_STACKFRAME(&_hx_pos_17d383cbce329512_193_changeSelection)
HXLINE( 194)		 ::PauseSubState _hx_tmp = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN( 194)		_hx_tmp->curSelected = (_hx_tmp->curSelected + change);
HXLINE( 196)		 ::flixel::_hx_system::frontEnds::SoundFrontEnd _hx_tmp1 = ::flixel::FlxG_obj::sound;
HXDLIN( 196)		::String library = null();
HXDLIN( 196)		::String _hx_tmp2;
HXDLIN( 196)		if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("sounds/",eb,02,a5,b6) + HX_("scrollMenu",4c,d4,18,06)) + HX_(".",2e,00,00,00)) + HX_("ogg",4f,94,54,00)),HX_("SOUND",af,c4,ba,fe),library),null())) {
HXLINE( 196)			_hx_tmp2 = ::Paths_obj::getPath((((HX_("sounds/",eb,02,a5,b6) + HX_("scrollMenu",4c,d4,18,06)) + HX_(".",2e,00,00,00)) + HX_("ogg",4f,94,54,00)),HX_("SOUND",af,c4,ba,fe),library);
            		}
            		else {
HXLINE( 196)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate sound - ",98,e2,ed,38) + HX_("scrollMenu",4c,d4,18,06))));
            		}
HXDLIN( 196)		_hx_tmp1->play(_hx_tmp2,((Float)0.4),null(),null(),null(),null());
HXLINE( 198)		if ((this->curSelected < 0)) {
HXLINE( 199)			this->curSelected = (this->menuItems->length - 1);
            		}
HXLINE( 200)		if ((this->curSelected >= this->menuItems->length)) {
HXLINE( 201)			this->curSelected = 0;
            		}
HXLINE( 203)		int bullShit = 0;
HXLINE( 205)		{
HXLINE( 205)			int _g = 0;
HXDLIN( 205)			::Array< ::Dynamic> _g1 = this->grpMenuShit->members;
HXDLIN( 205)			while((_g < _g1->length)){
HXLINE( 205)				 ::Alphabet item = _g1->__get(_g).StaticCast<  ::Alphabet >();
HXDLIN( 205)				_g = (_g + 1);
HXLINE( 207)				item->targetY = (bullShit - this->curSelected);
HXLINE( 208)				bullShit = (bullShit + 1);
HXLINE( 210)				item->set_alpha(((Float)0.6));
HXLINE( 213)				if ((item->targetY == 0)) {
HXLINE( 215)					item->set_alpha(( (Float)(1) ));
            				}
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(PauseSubState_obj,changeSelection,(void))


::hx::ObjectPtr< PauseSubState_obj > PauseSubState_obj::__new(Float x,Float y) {
	::hx::ObjectPtr< PauseSubState_obj > __this = new PauseSubState_obj();
	__this->__construct(x,y);
	return __this;
}

::hx::ObjectPtr< PauseSubState_obj > PauseSubState_obj::__alloc(::hx::Ctx *_hx_ctx,Float x,Float y) {
	PauseSubState_obj *__this = (PauseSubState_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(PauseSubState_obj), true, "PauseSubState"));
	*(void **)__this = PauseSubState_obj::_hx_vtable;
	__this->__construct(x,y);
	return __this;
}

PauseSubState_obj::PauseSubState_obj()
{
}

void PauseSubState_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PauseSubState);
	HX_MARK_MEMBER_NAME(doneHover,"doneHover");
	HX_MARK_MEMBER_NAME(otherStuff,"otherStuff");
	HX_MARK_MEMBER_NAME(grpMenuShit,"grpMenuShit");
	HX_MARK_MEMBER_NAME(menuItems,"menuItems");
	HX_MARK_MEMBER_NAME(curSelected,"curSelected");
	HX_MARK_MEMBER_NAME(pauseMusic,"pauseMusic");
	 ::flixel::FlxSubState_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void PauseSubState_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(doneHover,"doneHover");
	HX_VISIT_MEMBER_NAME(otherStuff,"otherStuff");
	HX_VISIT_MEMBER_NAME(grpMenuShit,"grpMenuShit");
	HX_VISIT_MEMBER_NAME(menuItems,"menuItems");
	HX_VISIT_MEMBER_NAME(curSelected,"curSelected");
	HX_VISIT_MEMBER_NAME(pauseMusic,"pauseMusic");
	 ::flixel::FlxSubState_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val PauseSubState_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return ::hx::Val( update_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return ::hx::Val( destroy_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"doneHover") ) { return ::hx::Val( doneHover ); }
		if (HX_FIELD_EQ(inName,"menuItems") ) { return ::hx::Val( menuItems ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"otherStuff") ) { return ::hx::Val( otherStuff ); }
		if (HX_FIELD_EQ(inName,"pauseMusic") ) { return ::hx::Val( pauseMusic ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"grpMenuShit") ) { return ::hx::Val( grpMenuShit ); }
		if (HX_FIELD_EQ(inName,"curSelected") ) { return ::hx::Val( curSelected ); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"changeSelection") ) { return ::hx::Val( changeSelection_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val PauseSubState_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"doneHover") ) { doneHover=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"menuItems") ) { menuItems=inValue.Cast< ::Array< ::String > >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"otherStuff") ) { otherStuff=inValue.Cast<  ::flixel::text::FlxText >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pauseMusic") ) { pauseMusic=inValue.Cast<  ::flixel::_hx_system::FlxSound >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"grpMenuShit") ) { grpMenuShit=inValue.Cast<  ::flixel::group::FlxTypedGroup >(); return inValue; }
		if (HX_FIELD_EQ(inName,"curSelected") ) { curSelected=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PauseSubState_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("doneHover",da,4d,03,32));
	outFields->push(HX_("otherStuff",04,ee,1a,46));
	outFields->push(HX_("grpMenuShit",04,32,b8,f0));
	outFields->push(HX_("menuItems",e1,15,e5,5c));
	outFields->push(HX_("curSelected",fb,eb,ab,32));
	outFields->push(HX_("pauseMusic",cf,6d,d3,e5));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo PauseSubState_obj_sMemberStorageInfo[] = {
	{::hx::fsBool,(int)offsetof(PauseSubState_obj,doneHover),HX_("doneHover",da,4d,03,32)},
	{::hx::fsObject /*  ::flixel::text::FlxText */ ,(int)offsetof(PauseSubState_obj,otherStuff),HX_("otherStuff",04,ee,1a,46)},
	{::hx::fsObject /*  ::flixel::group::FlxTypedGroup */ ,(int)offsetof(PauseSubState_obj,grpMenuShit),HX_("grpMenuShit",04,32,b8,f0)},
	{::hx::fsObject /* ::Array< ::String > */ ,(int)offsetof(PauseSubState_obj,menuItems),HX_("menuItems",e1,15,e5,5c)},
	{::hx::fsInt,(int)offsetof(PauseSubState_obj,curSelected),HX_("curSelected",fb,eb,ab,32)},
	{::hx::fsObject /*  ::flixel::_hx_system::FlxSound */ ,(int)offsetof(PauseSubState_obj,pauseMusic),HX_("pauseMusic",cf,6d,d3,e5)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *PauseSubState_obj_sStaticStorageInfo = 0;
#endif

static ::String PauseSubState_obj_sMemberFields[] = {
	HX_("doneHover",da,4d,03,32),
	HX_("otherStuff",04,ee,1a,46),
	HX_("grpMenuShit",04,32,b8,f0),
	HX_("menuItems",e1,15,e5,5c),
	HX_("curSelected",fb,eb,ab,32),
	HX_("pauseMusic",cf,6d,d3,e5),
	HX_("update",09,86,05,87),
	HX_("destroy",fa,2c,86,24),
	HX_("changeSelection",bc,98,b5,48),
	::String(null()) };

::hx::Class PauseSubState_obj::__mClass;

void PauseSubState_obj::__register()
{
	PauseSubState_obj _hx_dummy;
	PauseSubState_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("PauseSubState",67,95,e5,08);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(PauseSubState_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< PauseSubState_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = PauseSubState_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = PauseSubState_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

