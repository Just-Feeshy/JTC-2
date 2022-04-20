#include <hxcpp.h>

#ifndef INCLUDED_Alphabet
#include <Alphabet.h>
#endif
#ifndef INCLUDED_Controls
#include <Controls.h>
#endif
#ifndef INCLUDED_GhostTapping
#include <GhostTapping.h>
#endif
#ifndef INCLUDED_HelperStates
#include <HelperStates.h>
#endif
#ifndef INCLUDED_KeyboardScheme
#include <KeyboardScheme.h>
#endif
#ifndef INCLUDED_Main
#include <Main.h>
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
#ifndef INCLUDED_Options
#include <Options.h>
#endif
#ifndef INCLUDED_OptionsMenuState
#include <OptionsMenuState.h>
#endif
#ifndef INCLUDED_OptionsSubState
#include <OptionsSubState.h>
#endif
#ifndef INCLUDED_Paths
#include <Paths.h>
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
#ifndef INCLUDED__OptionsMenuState_StupidVibeShader
#include <_OptionsMenuState/StupidVibeShader.h>
#endif
#ifndef INCLUDED_betterShit_BetterCams
#include <betterShit/BetterCams.h>
#endif
#ifndef INCLUDED_feshixl_filters_GuassianBlur
#include <feshixl/filters/GuassianBlur.h>
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
#ifndef INCLUDED_flixel_animation_FlxAnimation
#include <flixel/animation/FlxAnimation.h>
#endif
#ifndef INCLUDED_flixel_animation_FlxAnimationController
#include <flixel/animation/FlxAnimationController.h>
#endif
#ifndef INCLUDED_flixel_animation_FlxBaseAnimation
#include <flixel/animation/FlxBaseAnimation.h>
#endif
#ifndef INCLUDED_flixel_graphics_tile_FlxGraphicsShader
#include <flixel/graphics/tile/FlxGraphicsShader.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedSpriteGroup
#include <flixel/group/FlxTypedSpriteGroup.h>
#endif
#ifndef INCLUDED_flixel_input_FlxPointer
#include <flixel/input/FlxPointer.h>
#endif
#ifndef INCLUDED_flixel_input_IFlxInputManager
#include <flixel/input/IFlxInputManager.h>
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
#ifndef INCLUDED_flixel_input_mouse_FlxMouse
#include <flixel/input/mouse/FlxMouse.h>
#endif
#ifndef INCLUDED_flixel_math_FlxPoint
#include <flixel/math/FlxPoint.h>
#endif
#ifndef INCLUDED_flixel_system_FlxSound
#include <flixel/system/FlxSound.h>
#endif
#ifndef INCLUDED_flixel_system_FlxSoundGroup
#include <flixel/system/FlxSoundGroup.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_CameraFrontEnd
#include <flixel/system/frontEnds/CameraFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_SoundFrontEnd
#include <flixel/system/frontEnds/SoundFrontEnd.h>
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
#ifndef INCLUDED_flixel_util_FlxAxes
#include <flixel/util/FlxAxes.h>
#endif
#ifndef INCLUDED_flixel_util_FlxDestroyUtil
#include <flixel/util/FlxDestroyUtil.h>
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
#ifndef INCLUDED_lime_app_IModule
#include <lime/app/IModule.h>
#endif
#ifndef INCLUDED_lime_utils_Assets
#include <lime/utils/Assets.h>
#endif
#ifndef INCLUDED_openfl_Lib
#include <openfl/Lib.h>
#endif
#ifndef INCLUDED_openfl_display_BitmapData
#include <openfl/display/BitmapData.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObject
#include <openfl/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObjectContainer
#include <openfl/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_openfl_display_GraphicsShader
#include <openfl/display/GraphicsShader.h>
#endif
#ifndef INCLUDED_openfl_display_IBitmapDrawable
#include <openfl/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl_display_InteractiveObject
#include <openfl/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_openfl_display_MovieClip
#include <openfl/display/MovieClip.h>
#endif
#ifndef INCLUDED_openfl_display_Shader
#include <openfl/display/Shader.h>
#endif
#ifndef INCLUDED_openfl_display_Sprite
#include <openfl/display/Sprite.h>
#endif
#ifndef INCLUDED_openfl_display_Stage
#include <openfl/display/Stage.h>
#endif
#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_filters_BitmapFilter
#include <openfl/filters/BitmapFilter.h>
#endif
#ifndef INCLUDED_openfl_filters_BlurFilter
#include <openfl/filters/BlurFilter.h>
#endif
#ifndef INCLUDED_openfl_filters_ShaderFilter
#include <openfl/filters/ShaderFilter.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_b3f58d72d382e2a6_61_new,"OptionsMenuState","new",0x9551a7c6,"OptionsMenuState.new","OptionsMenuState.hx",61,0x18c6f26a)
HX_LOCAL_STACK_FRAME(_hx_pos_b3f58d72d382e2a6_111_create,"OptionsMenuState","create",0xc37db356,"OptionsMenuState.create","OptionsMenuState.hx",111,0x18c6f26a)
HX_LOCAL_STACK_FRAME(_hx_pos_b3f58d72d382e2a6_127_create,"OptionsMenuState","create",0xc37db356,"OptionsMenuState.create","OptionsMenuState.hx",127,0x18c6f26a)
HX_LOCAL_STACK_FRAME(_hx_pos_b3f58d72d382e2a6_143_create,"OptionsMenuState","create",0xc37db356,"OptionsMenuState.create","OptionsMenuState.hx",143,0x18c6f26a)
HX_LOCAL_STACK_FRAME(_hx_pos_b3f58d72d382e2a6_164_create,"OptionsMenuState","create",0xc37db356,"OptionsMenuState.create","OptionsMenuState.hx",164,0x18c6f26a)
HX_LOCAL_STACK_FRAME(_hx_pos_b3f58d72d382e2a6_185_create,"OptionsMenuState","create",0xc37db356,"OptionsMenuState.create","OptionsMenuState.hx",185,0x18c6f26a)
HX_LOCAL_STACK_FRAME(_hx_pos_b3f58d72d382e2a6_202_create,"OptionsMenuState","create",0xc37db356,"OptionsMenuState.create","OptionsMenuState.hx",202,0x18c6f26a)
HX_LOCAL_STACK_FRAME(_hx_pos_b3f58d72d382e2a6_219_create,"OptionsMenuState","create",0xc37db356,"OptionsMenuState.create","OptionsMenuState.hx",219,0x18c6f26a)
HX_LOCAL_STACK_FRAME(_hx_pos_b3f58d72d382e2a6_236_create,"OptionsMenuState","create",0xc37db356,"OptionsMenuState.create","OptionsMenuState.hx",236,0x18c6f26a)
HX_LOCAL_STACK_FRAME(_hx_pos_b3f58d72d382e2a6_253_create,"OptionsMenuState","create",0xc37db356,"OptionsMenuState.create","OptionsMenuState.hx",253,0x18c6f26a)
HX_LOCAL_STACK_FRAME(_hx_pos_b3f58d72d382e2a6_270_create,"OptionsMenuState","create",0xc37db356,"OptionsMenuState.create","OptionsMenuState.hx",270,0x18c6f26a)
HX_LOCAL_STACK_FRAME(_hx_pos_b3f58d72d382e2a6_287_create,"OptionsMenuState","create",0xc37db356,"OptionsMenuState.create","OptionsMenuState.hx",287,0x18c6f26a)
HX_LOCAL_STACK_FRAME(_hx_pos_b3f58d72d382e2a6_304_create,"OptionsMenuState","create",0xc37db356,"OptionsMenuState.create","OptionsMenuState.hx",304,0x18c6f26a)
HX_LOCAL_STACK_FRAME(_hx_pos_b3f58d72d382e2a6_311_create,"OptionsMenuState","create",0xc37db356,"OptionsMenuState.create","OptionsMenuState.hx",311,0x18c6f26a)
HX_LOCAL_STACK_FRAME(_hx_pos_b3f58d72d382e2a6_328_create,"OptionsMenuState","create",0xc37db356,"OptionsMenuState.create","OptionsMenuState.hx",328,0x18c6f26a)
HX_LOCAL_STACK_FRAME(_hx_pos_b3f58d72d382e2a6_345_create,"OptionsMenuState","create",0xc37db356,"OptionsMenuState.create","OptionsMenuState.hx",345,0x18c6f26a)
HX_LOCAL_STACK_FRAME(_hx_pos_b3f58d72d382e2a6_362_create,"OptionsMenuState","create",0xc37db356,"OptionsMenuState.create","OptionsMenuState.hx",362,0x18c6f26a)
HX_LOCAL_STACK_FRAME(_hx_pos_b3f58d72d382e2a6_379_create,"OptionsMenuState","create",0xc37db356,"OptionsMenuState.create","OptionsMenuState.hx",379,0x18c6f26a)
HX_LOCAL_STACK_FRAME(_hx_pos_b3f58d72d382e2a6_396_create,"OptionsMenuState","create",0xc37db356,"OptionsMenuState.create","OptionsMenuState.hx",396,0x18c6f26a)
HX_LOCAL_STACK_FRAME(_hx_pos_b3f58d72d382e2a6_413_create,"OptionsMenuState","create",0xc37db356,"OptionsMenuState.create","OptionsMenuState.hx",413,0x18c6f26a)
HX_LOCAL_STACK_FRAME(_hx_pos_b3f58d72d382e2a6_430_create,"OptionsMenuState","create",0xc37db356,"OptionsMenuState.create","OptionsMenuState.hx",430,0x18c6f26a)
HX_LOCAL_STACK_FRAME(_hx_pos_b3f58d72d382e2a6_85_create,"OptionsMenuState","create",0xc37db356,"OptionsMenuState.create","OptionsMenuState.hx",85,0x18c6f26a)
HX_LOCAL_STACK_FRAME(_hx_pos_b3f58d72d382e2a6_500_setControls,"OptionsMenuState","setControls",0x8d79fd9e,"OptionsMenuState.setControls","OptionsMenuState.hx",500,0x18c6f26a)
HX_LOCAL_STACK_FRAME(_hx_pos_b3f58d72d382e2a6_533_changeSelection,"OptionsMenuState","changeSelection",0x594bf122,"OptionsMenuState.changeSelection","OptionsMenuState.hx",533,0x18c6f26a)
HX_LOCAL_STACK_FRAME(_hx_pos_b3f58d72d382e2a6_520_changeSelection,"OptionsMenuState","changeSelection",0x594bf122,"OptionsMenuState.changeSelection","OptionsMenuState.hx",520,0x18c6f26a)
HX_LOCAL_STACK_FRAME(_hx_pos_b3f58d72d382e2a6_558_setting,"OptionsMenuState","setting",0x60bc63f6,"OptionsMenuState.setting","OptionsMenuState.hx",558,0x18c6f26a)
HX_LOCAL_STACK_FRAME(_hx_pos_b3f58d72d382e2a6_570_setCat,"OptionsMenuState","setCat",0xb6d14dee,"OptionsMenuState.setCat","OptionsMenuState.hx",570,0x18c6f26a)
HX_LOCAL_STACK_FRAME(_hx_pos_b3f58d72d382e2a6_583_openSubStateBlur,"OptionsMenuState","openSubStateBlur",0x5ed39f7c,"OptionsMenuState.openSubStateBlur","OptionsMenuState.hx",583,0x18c6f26a)
HX_LOCAL_STACK_FRAME(_hx_pos_b3f58d72d382e2a6_580_openSubStateBlur,"OptionsMenuState","openSubStateBlur",0x5ed39f7c,"OptionsMenuState.openSubStateBlur","OptionsMenuState.hx",580,0x18c6f26a)
HX_LOCAL_STACK_FRAME(_hx_pos_b3f58d72d382e2a6_589_closeSubState,"OptionsMenuState","closeSubState",0xbc216b2f,"OptionsMenuState.closeSubState","OptionsMenuState.hx",589,0x18c6f26a)
HX_LOCAL_STACK_FRAME(_hx_pos_b3f58d72d382e2a6_596_update,"OptionsMenuState","update",0xce73d263,"OptionsMenuState.update","OptionsMenuState.hx",596,0x18c6f26a)
HX_LOCAL_STACK_FRAME(_hx_pos_b3f58d72d382e2a6_632_update,"OptionsMenuState","update",0xce73d263,"OptionsMenuState.update","OptionsMenuState.hx",632,0x18c6f26a)

void OptionsMenuState_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_b3f58d72d382e2a6_61_new)
HXLINE(  83)		this->settingTxt = HX_("",00,00,00,00);
HXLINE(  81)		this->changeBlur = false;
HXLINE(  79)		this->isChangingOption = false;
HXLINE(  78)		this->shouldPress = false;
HXLINE(  76)		this->curSelected = 0;
HXLINE(  75)		this->curCatalog = 0;
HXLINE(  62)		this->imNotSure = 10;
HXLINE(  61)		super::__construct();
            	}

Dynamic OptionsMenuState_obj::__CreateEmpty() { return new OptionsMenuState_obj; }

void *OptionsMenuState_obj::_hx_vtable = 0;

Dynamic OptionsMenuState_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< OptionsMenuState_obj > _hx_result = new OptionsMenuState_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool OptionsMenuState_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x3f706236) {
		if (inClassId<=(int)0x29d19794) {
			if (inClassId<=(int)0x23a57bae) {
				return inClassId==(int)0x00000001 || inClassId==(int)0x23a57bae;
			} else {
				return inClassId==(int)0x29d19794;
			}
		} else {
			return inClassId==(int)0x2f064378 || inClassId==(int)0x3f706236;
		}
	} else {
		if (inClassId<=(int)0x7c795c9f) {
			if (inClassId<=(int)0x62817b24) {
				return inClassId==(int)0x520ebf94 || inClassId==(int)0x62817b24;
			} else {
				return inClassId==(int)0x7c795c9f;
			}
		} else {
			return inClassId==(int)0x7ccf8994;
		}
	}
}

void OptionsMenuState_obj::create(){
            		HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_0, ::OptionsMenuState,_gthis) HXARGC(2)
            		void _hx_run( ::Options option,bool pressed){
            			HX_GC_STACKFRAME(&_hx_pos_b3f58d72d382e2a6_111_create)
HXLINE( 112)			option->ID = 0;
HXLINE( 114)			if ((option->optionIcon->animation->_curAnim->name != HX_("other",d0,66,76,36))) {
HXLINE( 115)				option->optionIcon->animation->play(HX_("other",d0,66,76,36),null(),null(),null());
            			}
HXLINE( 117)			if (pressed) {
HXLINE( 118)				option->optionSubState = ( ( ::OptionsSubState)(::flixel::util::FlxDestroyUtil_obj::destroy(option->optionSubState)) );
HXLINE( 119)				option->optionSubState = ::OptionsSubState_obj::newSubState(::SaveType_obj::CUSTOM_KEYBINDS_dyn());
HXLINE( 120)				option->optionSubState->set_cameras(::Array_obj< ::Dynamic>::__new(1)->init(0,_gthis->camSubState));
HXLINE( 122)				_gthis->openSubStateBlur(option->optionSubState);
            			}
HXLINE( 125)			_gthis->setting(option,HX_("",00,00,00,00),option->ID);
            		}
            		HX_END_LOCAL_FUNC2((void))

            		HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_1, ::OptionsMenuState,_gthis) HXARGC(2)
            		void _hx_run( ::Options option,bool pressed){
            			HX_GC_STACKFRAME(&_hx_pos_b3f58d72d382e2a6_127_create)
HXLINE( 128)			option->ID = 1;
HXLINE( 130)			if ((option->optionIcon->animation->_curAnim->name != HX_("other",d0,66,76,36))) {
HXLINE( 131)				option->optionIcon->animation->play(HX_("other",d0,66,76,36),null(),null(),null());
            			}
HXLINE( 133)			if (pressed) {
HXLINE( 134)				 ::Dynamic fh = ::flixel::FlxG_obj::save->data;
HXDLIN( 134)				fh->__SetField(HX_("dfjk",c3,18,67,42),(fh->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) + 1),::hx::paccDynamic);
HXLINE( 135)				_gthis->setControls(option,option->ID);
            			}
            			else {
HXLINE( 137)				_gthis->setControls(option,option->ID);
            			}
HXLINE( 140)			if (pressed) {
HXLINE( 141)				_gthis->isChangingOption = false;
            			}
            		}
            		HX_END_LOCAL_FUNC2((void))

            		HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_2, ::OptionsMenuState,_gthis) HXARGC(2)
            		void _hx_run( ::Options option,bool pressed){
            			HX_GC_STACKFRAME(&_hx_pos_b3f58d72d382e2a6_143_create)
HXLINE( 144)			option->ID = 2;
HXLINE( 146)			if ((option->optionIcon->animation->_curAnim->name != HX_("other",d0,66,76,36))) {
HXLINE( 147)				option->optionIcon->animation->play(HX_("other",d0,66,76,36),null(),null(),null());
            			}
HXLINE( 149)			if (pressed) {
HXLINE( 150)				 ::Dynamic fh = ::flixel::FlxG_obj::save->data;
HXDLIN( 150)				fh->__SetField(HX_("lowFps",b5,3f,e3,66),(fh->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) + 10),::hx::paccDynamic);
HXLINE( 152)				if (::hx::IsGreater( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic),100 )) {
HXLINE( 153)					::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            				}
HXLINE( 155)				 ::openfl::display::Stage _hx_tmp = ::openfl::Lib_obj::get_current()->stage;
HXDLIN( 155)				 ::Dynamic _hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
HXDLIN( 155)				 ::Dynamic _hx_tmp2;
HXDLIN( 155)				switch((int)(::SaveType_obj::FPS_MULTIPLIER_dyn()->_hx_getIndex())){
            					case (int)1: {
HXLINE( 155)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 155)							::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            						}
HXDLIN( 155)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            					}
            					break;
            					case (int)2: {
HXLINE( 155)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 155)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            						else {
HXLINE( 155)							if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 155)								::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            							}
            						}
HXDLIN( 155)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            					}
            					break;
            					case (int)3: {
HXLINE( 155)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 155)							::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            						}
HXDLIN( 155)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            					}
            					break;
            					case (int)4: {
HXLINE( 155)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 155)							::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            						}
HXDLIN( 155)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            					}
            					break;
            					case (int)5: {
HXLINE( 155)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 155)							::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            						}
HXDLIN( 155)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            					}
            					break;
            					case (int)6: {
HXLINE( 155)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 155)							::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            						}
HXDLIN( 155)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            					}
            					break;
            					case (int)7: {
HXLINE( 155)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 155)							::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            						}
HXDLIN( 155)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            					}
            					break;
            					case (int)8: {
HXLINE( 155)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 155)							::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            						}
HXDLIN( 155)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            					}
            					break;
            					case (int)9: {
HXLINE( 155)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 155)							::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            						}
HXDLIN( 155)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            					}
            					break;
            					case (int)10: {
HXLINE( 155)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 155)							::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            						}
HXDLIN( 155)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            					}
            					break;
            					case (int)11: {
HXLINE( 155)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 155)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            						else {
HXLINE( 155)							if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 155)								::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            							}
            						}
HXDLIN( 155)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            					}
            					break;
            					case (int)12: {
HXLINE( 155)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 155)							::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            						}
HXDLIN( 155)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            					}
            					break;
            					case (int)13: {
HXLINE( 155)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 155)							::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            						}
HXDLIN( 155)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            					}
            					break;
            					case (int)14: {
HXLINE( 155)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 155)							::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            						}
HXDLIN( 155)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            					}
            					break;
            					case (int)15: {
HXLINE( 155)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 155)							::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            						}
HXDLIN( 155)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            					}
            					break;
            					case (int)16: {
HXLINE( 155)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 155)							::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            						}
HXDLIN( 155)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            					}
            					break;
            					case (int)17: {
HXLINE( 155)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 155)							::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            						}
HXDLIN( 155)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            					}
            					break;
            					case (int)18: {
HXLINE( 155)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 155)							::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            						}
HXDLIN( 155)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            					}
            					break;
            					case (int)19: {
HXLINE( 155)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 155)							::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            						}
HXDLIN( 155)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            					}
            					break;
            					case (int)20: {
HXLINE( 155)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 155)							::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            						}
HXDLIN( 155)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            					}
            					break;
            					case (int)21: {
HXLINE( 155)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 155)							::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            						}
HXDLIN( 155)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            					}
            					break;
            					default:{
HXLINE( 155)						_hx_tmp2 = null();
            					}
            				}
HXDLIN( 155)				_hx_tmp->set_frameRate((( (Float)(_hx_tmp1) ) * ( (Float)(_hx_tmp2) )));
HXLINE( 156)				::Main_obj::framerate = ( (int)(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)) );
            			}
HXLINE( 159)			 ::OptionsMenuState _gthis1 = _gthis;
HXDLIN( 159)			::String _hx_tmp = ::Std_obj::string( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)));
HXDLIN( 159)			_gthis1->setting(option,_hx_tmp,option->ID);
HXLINE( 161)			if (pressed) {
HXLINE( 162)				_gthis->isChangingOption = false;
            			}
            		}
            		HX_END_LOCAL_FUNC2((void))

            		HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_3, ::OptionsMenuState,_gthis) HXARGC(2)
            		void _hx_run( ::Options option,bool pressed){
            			HX_GC_STACKFRAME(&_hx_pos_b3f58d72d382e2a6_164_create)
HXLINE( 165)			option->ID = 3;
HXLINE( 167)			if ((option->optionIcon->animation->_curAnim->name != HX_("other",d0,66,76,36))) {
HXLINE( 168)				option->optionIcon->animation->play(HX_("other",d0,66,76,36),null(),null(),null());
            			}
HXLINE( 170)			if (pressed) {
HXLINE( 171)				 ::Dynamic fh = ::flixel::FlxG_obj::save->data;
HXDLIN( 171)				fh->__SetField(HX_("fpsMulti",d0,e5,0a,9a),(fh->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) + 1),::hx::paccDynamic);
HXLINE( 173)				if (::hx::IsGreater( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic),9 )) {
HXLINE( 174)					::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            				}
HXLINE( 176)				 ::openfl::display::Stage _hx_tmp = ::openfl::Lib_obj::get_current()->stage;
HXDLIN( 176)				 ::Dynamic _hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
HXDLIN( 176)				 ::Dynamic _hx_tmp2;
HXDLIN( 176)				switch((int)(::SaveType_obj::FPS_MULTIPLIER_dyn()->_hx_getIndex())){
            					case (int)1: {
HXLINE( 176)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 176)							::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            						}
HXDLIN( 176)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            					}
            					break;
            					case (int)2: {
HXLINE( 176)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 176)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            						else {
HXLINE( 176)							if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 176)								::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            							}
            						}
HXDLIN( 176)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            					}
            					break;
            					case (int)3: {
HXLINE( 176)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 176)							::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            						}
HXDLIN( 176)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            					}
            					break;
            					case (int)4: {
HXLINE( 176)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 176)							::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            						}
HXDLIN( 176)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            					}
            					break;
            					case (int)5: {
HXLINE( 176)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 176)							::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            						}
HXDLIN( 176)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            					}
            					break;
            					case (int)6: {
HXLINE( 176)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 176)							::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            						}
HXDLIN( 176)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            					}
            					break;
            					case (int)7: {
HXLINE( 176)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 176)							::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            						}
HXDLIN( 176)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            					}
            					break;
            					case (int)8: {
HXLINE( 176)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 176)							::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            						}
HXDLIN( 176)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            					}
            					break;
            					case (int)9: {
HXLINE( 176)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 176)							::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            						}
HXDLIN( 176)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            					}
            					break;
            					case (int)10: {
HXLINE( 176)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 176)							::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            						}
HXDLIN( 176)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            					}
            					break;
            					case (int)11: {
HXLINE( 176)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 176)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            						else {
HXLINE( 176)							if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 176)								::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            							}
            						}
HXDLIN( 176)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            					}
            					break;
            					case (int)12: {
HXLINE( 176)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 176)							::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            						}
HXDLIN( 176)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            					}
            					break;
            					case (int)13: {
HXLINE( 176)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 176)							::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            						}
HXDLIN( 176)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            					}
            					break;
            					case (int)14: {
HXLINE( 176)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 176)							::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            						}
HXDLIN( 176)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            					}
            					break;
            					case (int)15: {
HXLINE( 176)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 176)							::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            						}
HXDLIN( 176)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            					}
            					break;
            					case (int)16: {
HXLINE( 176)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 176)							::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            						}
HXDLIN( 176)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            					}
            					break;
            					case (int)17: {
HXLINE( 176)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 176)							::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            						}
HXDLIN( 176)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            					}
            					break;
            					case (int)18: {
HXLINE( 176)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 176)							::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            						}
HXDLIN( 176)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            					}
            					break;
            					case (int)19: {
HXLINE( 176)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 176)							::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            						}
HXDLIN( 176)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            					}
            					break;
            					case (int)20: {
HXLINE( 176)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 176)							::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            						}
HXDLIN( 176)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            					}
            					break;
            					case (int)21: {
HXLINE( 176)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 176)							::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            						}
HXDLIN( 176)						_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            					}
            					break;
            					default:{
HXLINE( 176)						_hx_tmp2 = null();
            					}
            				}
HXDLIN( 176)				_hx_tmp->set_frameRate((( (Float)(_hx_tmp1) ) * ( (Float)(_hx_tmp2) )));
HXLINE( 177)				::Main_obj::framerate = ( (int)(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)) );
            			}
HXLINE( 180)			 ::OptionsMenuState _gthis1 = _gthis;
HXDLIN( 180)			::String _hx_tmp = ::Std_obj::string( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic)));
HXDLIN( 180)			_gthis1->setting(option,_hx_tmp,option->ID);
HXLINE( 182)			if (pressed) {
HXLINE( 183)				_gthis->isChangingOption = false;
            			}
            		}
            		HX_END_LOCAL_FUNC2((void))

            		HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_4, ::OptionsMenuState,_gthis) HXARGC(2)
            		void _hx_run( ::Options option,bool pressed){
            			HX_GC_STACKFRAME(&_hx_pos_b3f58d72d382e2a6_185_create)
HXLINE( 186)			option->ID = 4;
HXLINE( 188)			if (pressed) {
HXLINE( 189)				::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),!(( (bool)(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic)) )),::hx::paccDynamic);
            			}
HXLINE( 191)			 ::Dynamic _hx_tmp;
HXDLIN( 191)			switch((int)(::SaveType_obj::PRESET_INPUTS_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE( 191)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 191)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN( 191)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE( 191)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 191)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE( 191)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 191)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN( 191)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE( 191)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 191)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN( 191)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE( 191)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 191)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN( 191)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE( 191)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 191)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN( 191)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE( 191)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 191)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN( 191)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE( 191)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 191)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN( 191)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE( 191)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 191)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN( 191)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE( 191)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 191)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN( 191)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE( 191)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 191)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN( 191)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE( 191)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 191)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE( 191)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 191)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN( 191)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE( 191)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 191)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN( 191)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE( 191)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 191)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN( 191)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE( 191)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 191)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN( 191)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE( 191)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 191)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN( 191)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE( 191)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 191)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN( 191)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE( 191)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 191)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN( 191)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE( 191)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 191)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN( 191)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE( 191)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 191)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN( 191)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE( 191)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 191)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN( 191)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE( 191)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 191)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN( 191)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE( 191)					_hx_tmp = null();
            				}
            			}
HXDLIN( 191)			if (!(( (bool)(_hx_tmp) ))) {
HXLINE( 192)				_gthis->setting(option,HX_("Off",4f,4b,3c,00),option->ID);
HXLINE( 193)				option->optionIcon->animation->play(HX_("off",6f,93,54,00),null(),null(),null());
            			}
            			else {
HXLINE( 195)				_gthis->setting(option,HX_("On",3f,45,00,00),option->ID);
HXLINE( 196)				option->optionIcon->animation->play(HX_("on",1f,61,00,00),null(),null(),null());
            			}
HXLINE( 199)			if (pressed) {
HXLINE( 200)				_gthis->isChangingOption = false;
            			}
            		}
            		HX_END_LOCAL_FUNC2((void))

            		HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_5, ::OptionsMenuState,_gthis) HXARGC(2)
            		void _hx_run( ::Options option,bool pressed){
            			HX_GC_STACKFRAME(&_hx_pos_b3f58d72d382e2a6_202_create)
HXLINE( 203)			option->ID = 5;
HXLINE( 205)			if (pressed) {
HXLINE( 206)				::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),!(( (bool)(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic)) )),::hx::paccDynamic);
            			}
HXLINE( 208)			 ::Dynamic _hx_tmp;
HXDLIN( 208)			switch((int)(::SaveType_obj::DOWNSCROLL_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE( 208)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 208)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN( 208)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE( 208)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 208)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE( 208)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 208)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN( 208)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE( 208)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 208)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN( 208)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE( 208)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 208)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN( 208)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE( 208)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 208)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN( 208)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE( 208)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 208)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN( 208)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE( 208)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 208)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN( 208)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE( 208)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 208)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN( 208)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE( 208)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 208)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN( 208)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE( 208)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 208)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN( 208)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE( 208)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 208)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE( 208)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 208)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN( 208)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE( 208)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 208)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN( 208)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE( 208)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 208)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN( 208)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE( 208)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 208)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN( 208)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE( 208)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 208)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN( 208)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE( 208)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 208)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN( 208)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE( 208)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 208)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN( 208)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE( 208)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 208)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN( 208)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE( 208)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 208)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN( 208)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE( 208)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 208)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN( 208)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE( 208)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 208)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN( 208)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE( 208)					_hx_tmp = null();
            				}
            			}
HXDLIN( 208)			if (!(( (bool)(_hx_tmp) ))) {
HXLINE( 209)				_gthis->setting(option,HX_("Off",4f,4b,3c,00),option->ID);
HXLINE( 210)				option->optionIcon->animation->play(HX_("off",6f,93,54,00),null(),null(),null());
            			}
            			else {
HXLINE( 212)				_gthis->setting(option,HX_("On",3f,45,00,00),option->ID);
HXLINE( 213)				option->optionIcon->animation->play(HX_("on",1f,61,00,00),null(),null(),null());
            			}
HXLINE( 216)			if (pressed) {
HXLINE( 217)				_gthis->isChangingOption = false;
            			}
            		}
            		HX_END_LOCAL_FUNC2((void))

            		HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_6, ::OptionsMenuState,_gthis) HXARGC(2)
            		void _hx_run( ::Options option,bool pressed){
            			HX_GC_STACKFRAME(&_hx_pos_b3f58d72d382e2a6_219_create)
HXLINE( 220)			option->ID = 6;
HXLINE( 222)			if (pressed) {
HXLINE( 223)				::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),!(( (bool)(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic)) )),::hx::paccDynamic);
            			}
HXLINE( 225)			 ::Dynamic _hx_tmp;
HXDLIN( 225)			switch((int)(::SaveType_obj::SHOW_NOTE_SPLASH_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE( 225)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 225)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN( 225)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE( 225)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 225)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE( 225)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 225)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN( 225)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE( 225)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 225)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN( 225)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE( 225)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 225)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN( 225)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE( 225)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 225)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN( 225)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE( 225)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 225)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN( 225)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE( 225)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 225)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN( 225)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE( 225)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 225)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN( 225)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE( 225)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 225)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN( 225)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE( 225)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 225)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN( 225)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE( 225)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 225)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE( 225)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 225)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN( 225)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE( 225)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 225)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN( 225)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE( 225)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 225)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN( 225)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE( 225)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 225)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN( 225)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE( 225)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 225)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN( 225)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE( 225)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 225)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN( 225)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE( 225)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 225)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN( 225)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE( 225)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 225)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN( 225)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE( 225)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 225)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN( 225)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE( 225)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 225)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN( 225)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE( 225)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 225)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN( 225)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE( 225)					_hx_tmp = null();
            				}
            			}
HXDLIN( 225)			if (!(( (bool)(_hx_tmp) ))) {
HXLINE( 226)				_gthis->setting(option,HX_("Off",4f,4b,3c,00),option->ID);
HXLINE( 227)				option->optionIcon->animation->play(HX_("off",6f,93,54,00),null(),null(),null());
            			}
            			else {
HXLINE( 229)				_gthis->setting(option,HX_("On",3f,45,00,00),option->ID);
HXLINE( 230)				option->optionIcon->animation->play(HX_("on",1f,61,00,00),null(),null(),null());
            			}
HXLINE( 233)			if (pressed) {
HXLINE( 234)				_gthis->isChangingOption = false;
            			}
            		}
            		HX_END_LOCAL_FUNC2((void))

            		HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_7, ::OptionsMenuState,_gthis) HXARGC(2)
            		void _hx_run( ::Options option,bool pressed){
            			HX_GC_STACKFRAME(&_hx_pos_b3f58d72d382e2a6_236_create)
HXLINE( 237)			option->ID = 7;
HXLINE( 239)			if (pressed) {
HXLINE( 240)				::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),!(( (bool)(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic)) )),::hx::paccDynamic);
            			}
HXLINE( 242)			 ::Dynamic _hx_tmp;
HXDLIN( 242)			switch((int)(::SaveType_obj::SHOW_BOTTOM_BAR_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE( 242)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 242)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN( 242)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE( 242)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 242)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE( 242)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 242)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN( 242)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE( 242)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 242)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN( 242)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE( 242)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 242)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN( 242)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE( 242)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 242)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN( 242)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE( 242)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 242)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN( 242)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE( 242)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 242)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN( 242)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE( 242)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 242)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN( 242)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE( 242)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 242)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN( 242)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE( 242)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 242)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN( 242)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE( 242)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 242)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE( 242)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 242)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN( 242)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE( 242)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 242)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN( 242)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE( 242)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 242)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN( 242)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE( 242)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 242)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN( 242)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE( 242)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 242)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN( 242)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE( 242)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 242)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN( 242)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE( 242)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 242)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN( 242)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE( 242)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 242)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN( 242)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE( 242)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 242)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN( 242)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE( 242)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 242)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN( 242)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE( 242)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 242)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN( 242)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE( 242)					_hx_tmp = null();
            				}
            			}
HXDLIN( 242)			if (!(( (bool)(_hx_tmp) ))) {
HXLINE( 243)				_gthis->setting(option,HX_("Off",4f,4b,3c,00),option->ID);
HXLINE( 244)				option->optionIcon->animation->play(HX_("off",6f,93,54,00),null(),null(),null());
            			}
            			else {
HXLINE( 246)				_gthis->setting(option,HX_("On",3f,45,00,00),option->ID);
HXLINE( 247)				option->optionIcon->animation->play(HX_("on",1f,61,00,00),null(),null(),null());
            			}
HXLINE( 250)			if (pressed) {
HXLINE( 251)				_gthis->isChangingOption = false;
            			}
            		}
            		HX_END_LOCAL_FUNC2((void))

            		HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_8, ::OptionsMenuState,_gthis) HXARGC(2)
            		void _hx_run( ::Options option,bool pressed){
            			HX_GC_STACKFRAME(&_hx_pos_b3f58d72d382e2a6_253_create)
HXLINE( 254)			option->ID = 8;
HXLINE( 256)			if (pressed) {
HXLINE( 257)				::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),!(( (bool)(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic)) )),::hx::paccDynamic);
            			}
HXLINE( 259)			 ::Dynamic _hx_tmp;
HXDLIN( 259)			switch((int)(::SaveType_obj::GRAPHICS_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE( 259)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 259)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN( 259)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE( 259)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 259)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE( 259)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 259)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN( 259)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE( 259)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 259)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN( 259)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE( 259)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 259)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN( 259)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE( 259)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 259)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN( 259)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE( 259)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 259)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN( 259)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE( 259)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 259)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN( 259)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE( 259)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 259)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN( 259)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE( 259)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 259)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN( 259)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE( 259)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 259)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN( 259)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE( 259)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 259)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE( 259)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 259)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN( 259)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE( 259)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 259)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN( 259)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE( 259)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 259)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN( 259)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE( 259)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 259)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN( 259)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE( 259)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 259)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN( 259)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE( 259)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 259)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN( 259)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE( 259)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 259)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN( 259)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE( 259)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 259)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN( 259)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE( 259)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 259)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN( 259)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE( 259)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 259)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN( 259)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE( 259)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 259)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN( 259)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE( 259)					_hx_tmp = null();
            				}
            			}
HXDLIN( 259)			if (!(( (bool)(_hx_tmp) ))) {
HXLINE( 260)				_gthis->setting(option,HX_("Off",4f,4b,3c,00),option->ID);
HXLINE( 261)				option->optionIcon->animation->play(HX_("off",6f,93,54,00),null(),null(),null());
            			}
            			else {
HXLINE( 263)				_gthis->setting(option,HX_("On",3f,45,00,00),option->ID);
HXLINE( 264)				option->optionIcon->animation->play(HX_("on",1f,61,00,00),null(),null(),null());
            			}
HXLINE( 267)			if (pressed) {
HXLINE( 268)				_gthis->isChangingOption = false;
            			}
            		}
            		HX_END_LOCAL_FUNC2((void))

            		HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_9, ::OptionsMenuState,_gthis) HXARGC(2)
            		void _hx_run( ::Options option,bool pressed){
            			HX_GC_STACKFRAME(&_hx_pos_b3f58d72d382e2a6_270_create)
HXLINE( 271)			option->ID = 9;
HXLINE( 273)			if (pressed) {
HXLINE( 274)				::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),!(( (bool)(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic)) )),::hx::paccDynamic);
            			}
HXLINE( 276)			 ::Dynamic _hx_tmp;
HXDLIN( 276)			switch((int)(::SaveType_obj::CACHE_ASSETS_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE( 276)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 276)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN( 276)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE( 276)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 276)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE( 276)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 276)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN( 276)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE( 276)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 276)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN( 276)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE( 276)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 276)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN( 276)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE( 276)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 276)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN( 276)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE( 276)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 276)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN( 276)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE( 276)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 276)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN( 276)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE( 276)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 276)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN( 276)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE( 276)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 276)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN( 276)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE( 276)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 276)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN( 276)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE( 276)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 276)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE( 276)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 276)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN( 276)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE( 276)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 276)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN( 276)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE( 276)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 276)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN( 276)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE( 276)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 276)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN( 276)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE( 276)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 276)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN( 276)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE( 276)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 276)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN( 276)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE( 276)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 276)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN( 276)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE( 276)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 276)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN( 276)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE( 276)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 276)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN( 276)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE( 276)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 276)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN( 276)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE( 276)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 276)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN( 276)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE( 276)					_hx_tmp = null();
            				}
            			}
HXDLIN( 276)			if (!(( (bool)(_hx_tmp) ))) {
HXLINE( 277)				_gthis->setting(option,HX_("Off",4f,4b,3c,00),option->ID);
HXLINE( 278)				option->optionIcon->animation->play(HX_("off",6f,93,54,00),null(),null(),null());
            			}
            			else {
HXLINE( 280)				_gthis->setting(option,HX_("On",3f,45,00,00),option->ID);
HXLINE( 281)				option->optionIcon->animation->play(HX_("on",1f,61,00,00),null(),null(),null());
            			}
HXLINE( 284)			if (pressed) {
HXLINE( 285)				_gthis->isChangingOption = false;
            			}
            		}
            		HX_END_LOCAL_FUNC2((void))

            		HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_10, ::OptionsMenuState,_gthis) HXARGC(2)
            		void _hx_run( ::Options option,bool pressed){
            			HX_GC_STACKFRAME(&_hx_pos_b3f58d72d382e2a6_287_create)
HXLINE( 288)			option->ID = 10;
HXLINE( 290)			if (pressed) {
HXLINE( 291)				::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),!(( (bool)(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic)) )),::hx::paccDynamic);
            			}
HXLINE( 293)			 ::Dynamic _hx_tmp;
HXDLIN( 293)			switch((int)(::SaveType_obj::GHOST_TAPPING_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE( 293)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 293)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN( 293)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE( 293)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 293)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE( 293)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 293)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN( 293)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE( 293)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 293)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN( 293)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE( 293)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 293)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN( 293)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE( 293)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 293)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN( 293)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE( 293)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 293)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN( 293)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE( 293)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 293)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN( 293)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE( 293)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 293)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN( 293)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE( 293)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 293)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN( 293)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE( 293)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 293)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN( 293)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE( 293)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 293)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE( 293)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 293)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN( 293)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE( 293)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 293)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN( 293)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE( 293)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 293)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN( 293)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE( 293)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 293)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN( 293)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE( 293)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 293)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN( 293)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE( 293)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 293)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN( 293)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE( 293)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 293)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN( 293)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE( 293)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 293)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN( 293)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE( 293)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 293)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN( 293)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE( 293)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 293)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN( 293)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE( 293)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 293)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN( 293)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE( 293)					_hx_tmp = null();
            				}
            			}
HXDLIN( 293)			if (!(( (bool)(_hx_tmp) ))) {
HXLINE( 294)				_gthis->setting(option,HX_("Off",4f,4b,3c,00),option->ID);
HXLINE( 295)				option->optionIcon->animation->play(HX_("off",6f,93,54,00),null(),null(),null());
            			}
            			else {
HXLINE( 297)				_gthis->setting(option,HX_("On",3f,45,00,00),option->ID);
HXLINE( 298)				option->optionIcon->animation->play(HX_("on",1f,61,00,00),null(),null(),null());
            			}
HXLINE( 301)			if (pressed) {
HXLINE( 302)				_gthis->isChangingOption = false;
            			}
            		}
            		HX_END_LOCAL_FUNC2((void))

            		HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_11, ::OptionsMenuState,_gthis) HXARGC(2)
            		void _hx_run( ::Options option,bool pressed){
            			HX_GC_STACKFRAME(&_hx_pos_b3f58d72d382e2a6_304_create)
HXLINE( 305)			option->ID = (_gthis->imNotSure + 1);
HXLINE( 307)			option->optionIcon->kill();
HXLINE( 308)			option->set_optionTitle(true);
HXLINE( 309)			_gthis->setting(option,HX_("",00,00,00,00),option->ID);
            		}
            		HX_END_LOCAL_FUNC2((void))

            		HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_12, ::OptionsMenuState,_gthis) HXARGC(2)
            		void _hx_run( ::Options option,bool pressed){
            			HX_GC_STACKFRAME(&_hx_pos_b3f58d72d382e2a6_311_create)
HXLINE( 312)			option->ID = (_gthis->imNotSure + 2);
HXLINE( 314)			if (pressed) {
HXLINE( 315)				::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),!(( (bool)(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic)) )),::hx::paccDynamic);
            			}
HXLINE( 317)			 ::Dynamic _hx_tmp;
HXDLIN( 317)			switch((int)(::SaveType_obj::FLIP_CHART_MOD_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE( 317)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 317)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN( 317)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE( 317)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 317)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE( 317)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 317)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN( 317)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE( 317)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 317)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN( 317)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE( 317)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 317)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN( 317)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE( 317)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 317)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN( 317)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE( 317)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 317)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN( 317)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE( 317)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 317)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN( 317)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE( 317)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 317)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN( 317)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE( 317)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 317)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN( 317)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE( 317)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 317)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN( 317)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE( 317)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 317)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE( 317)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 317)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN( 317)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE( 317)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 317)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN( 317)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE( 317)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 317)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN( 317)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE( 317)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 317)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN( 317)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE( 317)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 317)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN( 317)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE( 317)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 317)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN( 317)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE( 317)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 317)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN( 317)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE( 317)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 317)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN( 317)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE( 317)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 317)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN( 317)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE( 317)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 317)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN( 317)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE( 317)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 317)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN( 317)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE( 317)					_hx_tmp = null();
            				}
            			}
HXDLIN( 317)			if (!(( (bool)(_hx_tmp) ))) {
HXLINE( 318)				_gthis->setting(option,HX_("Off",4f,4b,3c,00),option->ID);
HXLINE( 319)				option->optionIcon->animation->play(HX_("off",6f,93,54,00),null(),null(),null());
            			}
            			else {
HXLINE( 321)				_gthis->setting(option,HX_("On",3f,45,00,00),option->ID);
HXLINE( 322)				option->optionIcon->animation->play(HX_("modifier",57,db,c7,16),null(),null(),null());
            			}
HXLINE( 325)			if (pressed) {
HXLINE( 326)				_gthis->isChangingOption = false;
            			}
            		}
            		HX_END_LOCAL_FUNC2((void))

            		HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_13, ::OptionsMenuState,_gthis) HXARGC(2)
            		void _hx_run( ::Options option,bool pressed){
            			HX_GC_STACKFRAME(&_hx_pos_b3f58d72d382e2a6_328_create)
HXLINE( 329)			option->ID = (_gthis->imNotSure + 3);
HXLINE( 331)			if (pressed) {
HXLINE( 332)				::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),!(( (bool)(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic)) )),::hx::paccDynamic);
            			}
HXLINE( 334)			 ::Dynamic _hx_tmp;
HXDLIN( 334)			switch((int)(::SaveType_obj::CUSTOM_HELL_MOD_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE( 334)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 334)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN( 334)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE( 334)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 334)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE( 334)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 334)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN( 334)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE( 334)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 334)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN( 334)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE( 334)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 334)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN( 334)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE( 334)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 334)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN( 334)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE( 334)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 334)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN( 334)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE( 334)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 334)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN( 334)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE( 334)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 334)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN( 334)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE( 334)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 334)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN( 334)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE( 334)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 334)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN( 334)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE( 334)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 334)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE( 334)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 334)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN( 334)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE( 334)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 334)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN( 334)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE( 334)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 334)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN( 334)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE( 334)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 334)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN( 334)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE( 334)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 334)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN( 334)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE( 334)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 334)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN( 334)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE( 334)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 334)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN( 334)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE( 334)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 334)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN( 334)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE( 334)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 334)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN( 334)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE( 334)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 334)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN( 334)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE( 334)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 334)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN( 334)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE( 334)					_hx_tmp = null();
            				}
            			}
HXDLIN( 334)			if (!(( (bool)(_hx_tmp) ))) {
HXLINE( 335)				_gthis->setting(option,HX_("Off",4f,4b,3c,00),option->ID);
HXLINE( 336)				option->optionIcon->animation->play(HX_("off",6f,93,54,00),null(),null(),null());
            			}
            			else {
HXLINE( 338)				_gthis->setting(option,HX_("On",3f,45,00,00),option->ID);
HXLINE( 339)				option->optionIcon->animation->play(HX_("modifier",57,db,c7,16),null(),null(),null());
            			}
HXLINE( 342)			if (pressed) {
HXLINE( 343)				_gthis->isChangingOption = false;
            			}
            		}
            		HX_END_LOCAL_FUNC2((void))

            		HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_14, ::OptionsMenuState,_gthis) HXARGC(2)
            		void _hx_run( ::Options option,bool pressed){
            			HX_GC_STACKFRAME(&_hx_pos_b3f58d72d382e2a6_345_create)
HXLINE( 346)			option->ID = (_gthis->imNotSure + 4);
HXLINE( 348)			if (pressed) {
HXLINE( 349)				::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),!(( (bool)(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic)) )),::hx::paccDynamic);
            			}
HXLINE( 351)			 ::Dynamic _hx_tmp;
HXDLIN( 351)			switch((int)(::SaveType_obj::PERFECT_MODE_MOD_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE( 351)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 351)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN( 351)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE( 351)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 351)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE( 351)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 351)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN( 351)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE( 351)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 351)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN( 351)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE( 351)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 351)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN( 351)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE( 351)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 351)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN( 351)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE( 351)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 351)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN( 351)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE( 351)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 351)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN( 351)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE( 351)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 351)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN( 351)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE( 351)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 351)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN( 351)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE( 351)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 351)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN( 351)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE( 351)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 351)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE( 351)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 351)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN( 351)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE( 351)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 351)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN( 351)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE( 351)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 351)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN( 351)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE( 351)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 351)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN( 351)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE( 351)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 351)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN( 351)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE( 351)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 351)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN( 351)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE( 351)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 351)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN( 351)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE( 351)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 351)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN( 351)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE( 351)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 351)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN( 351)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE( 351)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 351)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN( 351)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE( 351)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 351)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN( 351)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE( 351)					_hx_tmp = null();
            				}
            			}
HXDLIN( 351)			if (!(( (bool)(_hx_tmp) ))) {
HXLINE( 352)				_gthis->setting(option,HX_("Off",4f,4b,3c,00),option->ID);
HXLINE( 353)				option->optionIcon->animation->play(HX_("off",6f,93,54,00),null(),null(),null());
            			}
            			else {
HXLINE( 355)				_gthis->setting(option,HX_("On",3f,45,00,00),option->ID);
HXLINE( 356)				option->optionIcon->animation->play(HX_("modifier",57,db,c7,16),null(),null(),null());
            			}
HXLINE( 359)			if (pressed) {
HXLINE( 360)				_gthis->isChangingOption = false;
            			}
            		}
            		HX_END_LOCAL_FUNC2((void))

            		HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_15, ::OptionsMenuState,_gthis) HXARGC(2)
            		void _hx_run( ::Options option,bool pressed){
            			HX_GC_STACKFRAME(&_hx_pos_b3f58d72d382e2a6_362_create)
HXLINE( 363)			option->ID = (_gthis->imNotSure + 5);
HXLINE( 365)			if (pressed) {
HXLINE( 366)				::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),!(( (bool)(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic)) )),::hx::paccDynamic);
            			}
HXLINE( 368)			 ::Dynamic _hx_tmp;
HXDLIN( 368)			switch((int)(::SaveType_obj::FAIR_BATTLE_MOD_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE( 368)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 368)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN( 368)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE( 368)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 368)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE( 368)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 368)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN( 368)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE( 368)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 368)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN( 368)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE( 368)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 368)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN( 368)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE( 368)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 368)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN( 368)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE( 368)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 368)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN( 368)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE( 368)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 368)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN( 368)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE( 368)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 368)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN( 368)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE( 368)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 368)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN( 368)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE( 368)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 368)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN( 368)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE( 368)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 368)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE( 368)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 368)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN( 368)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE( 368)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 368)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN( 368)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE( 368)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 368)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN( 368)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE( 368)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 368)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN( 368)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE( 368)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 368)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN( 368)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE( 368)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 368)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN( 368)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE( 368)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 368)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN( 368)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE( 368)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 368)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN( 368)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE( 368)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 368)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN( 368)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE( 368)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 368)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN( 368)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE( 368)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 368)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN( 368)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE( 368)					_hx_tmp = null();
            				}
            			}
HXDLIN( 368)			if (!(( (bool)(_hx_tmp) ))) {
HXLINE( 369)				_gthis->setting(option,HX_("Off",4f,4b,3c,00),option->ID);
HXLINE( 370)				option->optionIcon->animation->play(HX_("off",6f,93,54,00),null(),null(),null());
            			}
            			else {
HXLINE( 372)				_gthis->setting(option,HX_("On",3f,45,00,00),option->ID);
HXLINE( 373)				option->optionIcon->animation->play(HX_("modifier",57,db,c7,16),null(),null(),null());
            			}
HXLINE( 376)			if (pressed) {
HXLINE( 377)				_gthis->isChangingOption = false;
            			}
            		}
            		HX_END_LOCAL_FUNC2((void))

            		HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_16, ::OptionsMenuState,_gthis) HXARGC(2)
            		void _hx_run( ::Options option,bool pressed){
            			HX_GC_STACKFRAME(&_hx_pos_b3f58d72d382e2a6_379_create)
HXLINE( 380)			option->ID = (_gthis->imNotSure + 6);
HXLINE( 382)			if (pressed) {
HXLINE( 383)				::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),!(( (bool)(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic)) )),::hx::paccDynamic);
            			}
HXLINE( 385)			 ::Dynamic _hx_tmp;
HXDLIN( 385)			switch((int)(::SaveType_obj::FADE_BATTLE_MOD_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE( 385)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 385)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN( 385)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE( 385)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 385)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE( 385)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 385)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN( 385)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE( 385)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 385)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN( 385)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE( 385)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 385)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN( 385)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE( 385)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 385)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN( 385)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE( 385)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 385)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN( 385)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE( 385)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 385)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN( 385)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE( 385)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 385)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN( 385)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE( 385)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 385)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN( 385)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE( 385)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 385)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN( 385)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE( 385)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 385)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE( 385)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 385)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN( 385)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE( 385)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 385)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN( 385)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE( 385)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 385)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN( 385)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE( 385)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 385)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN( 385)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE( 385)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 385)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN( 385)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE( 385)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 385)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN( 385)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE( 385)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 385)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN( 385)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE( 385)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 385)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN( 385)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE( 385)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 385)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN( 385)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE( 385)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 385)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN( 385)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE( 385)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 385)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN( 385)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE( 385)					_hx_tmp = null();
            				}
            			}
HXDLIN( 385)			if (!(( (bool)(_hx_tmp) ))) {
HXLINE( 386)				_gthis->setting(option,HX_("Off",4f,4b,3c,00),option->ID);
HXLINE( 387)				option->optionIcon->animation->play(HX_("off",6f,93,54,00),null(),null(),null());
            			}
            			else {
HXLINE( 389)				_gthis->setting(option,HX_("On",3f,45,00,00),option->ID);
HXLINE( 390)				option->optionIcon->animation->play(HX_("modifier",57,db,c7,16),null(),null(),null());
            			}
HXLINE( 393)			if (pressed) {
HXLINE( 394)				_gthis->isChangingOption = false;
            			}
            		}
            		HX_END_LOCAL_FUNC2((void))

            		HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_17, ::OptionsMenuState,_gthis) HXARGC(2)
            		void _hx_run( ::Options option,bool pressed){
            			HX_GC_STACKFRAME(&_hx_pos_b3f58d72d382e2a6_396_create)
HXLINE( 397)			option->ID = (_gthis->imNotSure + 7);
HXLINE( 399)			if (pressed) {
HXLINE( 400)				::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),!(( (bool)(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic)) )),::hx::paccDynamic);
            			}
HXLINE( 402)			 ::Dynamic _hx_tmp;
HXDLIN( 402)			switch((int)(::SaveType_obj::NO_BLUE_BALLS_MOD_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE( 402)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 402)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN( 402)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE( 402)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 402)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE( 402)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 402)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN( 402)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE( 402)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 402)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN( 402)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE( 402)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 402)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN( 402)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE( 402)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 402)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN( 402)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE( 402)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 402)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN( 402)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE( 402)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 402)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN( 402)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE( 402)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 402)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN( 402)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE( 402)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 402)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN( 402)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE( 402)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 402)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN( 402)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE( 402)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 402)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE( 402)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 402)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN( 402)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE( 402)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 402)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN( 402)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE( 402)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 402)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN( 402)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE( 402)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 402)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN( 402)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE( 402)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 402)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN( 402)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE( 402)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 402)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN( 402)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE( 402)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 402)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN( 402)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE( 402)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 402)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN( 402)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE( 402)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 402)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN( 402)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE( 402)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 402)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN( 402)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE( 402)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 402)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN( 402)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE( 402)					_hx_tmp = null();
            				}
            			}
HXDLIN( 402)			if (!(( (bool)(_hx_tmp) ))) {
HXLINE( 403)				_gthis->setting(option,HX_("Off",4f,4b,3c,00),option->ID);
HXLINE( 404)				option->optionIcon->animation->play(HX_("off",6f,93,54,00),null(),null(),null());
            			}
            			else {
HXLINE( 406)				_gthis->setting(option,HX_("On",3f,45,00,00),option->ID);
HXLINE( 407)				option->optionIcon->animation->play(HX_("modifier",57,db,c7,16),null(),null(),null());
            			}
HXLINE( 410)			if (pressed) {
HXLINE( 411)				_gthis->isChangingOption = false;
            			}
            		}
            		HX_END_LOCAL_FUNC2((void))

            		HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_18, ::OptionsMenuState,_gthis) HXARGC(2)
            		void _hx_run( ::Options option,bool pressed){
            			HX_GC_STACKFRAME(&_hx_pos_b3f58d72d382e2a6_413_create)
HXLINE( 414)			option->ID = (_gthis->imNotSure + 8);
HXLINE( 416)			if (pressed) {
HXLINE( 417)				::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),!(( (bool)(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic)) )),::hx::paccDynamic);
            			}
HXLINE( 419)			 ::Dynamic _hx_tmp;
HXDLIN( 419)			switch((int)(::SaveType_obj::BLIND_MOD_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE( 419)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 419)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN( 419)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE( 419)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 419)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE( 419)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 419)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN( 419)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE( 419)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 419)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN( 419)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE( 419)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 419)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN( 419)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE( 419)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 419)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN( 419)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE( 419)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 419)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN( 419)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE( 419)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 419)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN( 419)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE( 419)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 419)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN( 419)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE( 419)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 419)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN( 419)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE( 419)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 419)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN( 419)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE( 419)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 419)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE( 419)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 419)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN( 419)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE( 419)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 419)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN( 419)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE( 419)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 419)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN( 419)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE( 419)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 419)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN( 419)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE( 419)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 419)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN( 419)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE( 419)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 419)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN( 419)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE( 419)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 419)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN( 419)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE( 419)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 419)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN( 419)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE( 419)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 419)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN( 419)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE( 419)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 419)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN( 419)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE( 419)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 419)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN( 419)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE( 419)					_hx_tmp = null();
            				}
            			}
HXDLIN( 419)			if (!(( (bool)(_hx_tmp) ))) {
HXLINE( 420)				_gthis->setting(option,HX_("Off",4f,4b,3c,00),option->ID);
HXLINE( 421)				option->optionIcon->animation->play(HX_("off",6f,93,54,00),null(),null(),null());
            			}
            			else {
HXLINE( 423)				_gthis->setting(option,HX_("On",3f,45,00,00),option->ID);
HXLINE( 424)				option->optionIcon->animation->play(HX_("modifier",57,db,c7,16),null(),null(),null());
            			}
HXLINE( 427)			if (pressed) {
HXLINE( 428)				_gthis->isChangingOption = false;
            			}
            		}
            		HX_END_LOCAL_FUNC2((void))

            		HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_19, ::OptionsMenuState,_gthis) HXARGC(2)
            		void _hx_run( ::Options option,bool pressed){
            			HX_GC_STACKFRAME(&_hx_pos_b3f58d72d382e2a6_430_create)
HXLINE( 431)			option->ID = (_gthis->imNotSure + 9);
HXLINE( 433)			if (pressed) {
HXLINE( 434)				::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),!(( (bool)(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic)) )),::hx::paccDynamic);
            			}
HXLINE( 436)			 ::Dynamic _hx_tmp;
HXDLIN( 436)			switch((int)(::SaveType_obj::X_WOBBLE_MOD_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE( 436)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 436)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN( 436)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE( 436)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 436)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE( 436)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 436)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN( 436)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE( 436)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 436)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN( 436)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE( 436)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 436)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN( 436)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE( 436)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 436)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN( 436)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE( 436)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 436)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN( 436)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE( 436)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 436)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN( 436)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE( 436)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 436)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN( 436)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE( 436)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 436)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN( 436)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE( 436)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 436)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN( 436)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE( 436)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 436)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE( 436)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 436)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN( 436)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE( 436)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 436)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN( 436)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE( 436)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 436)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN( 436)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE( 436)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 436)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN( 436)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE( 436)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 436)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN( 436)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE( 436)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 436)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN( 436)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE( 436)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 436)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN( 436)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE( 436)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 436)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN( 436)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE( 436)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 436)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN( 436)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE( 436)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 436)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN( 436)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE( 436)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 436)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN( 436)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE( 436)					_hx_tmp = null();
            				}
            			}
HXDLIN( 436)			if (!(( (bool)(_hx_tmp) ))) {
HXLINE( 437)				_gthis->setting(option,HX_("Off",4f,4b,3c,00),option->ID);
HXLINE( 438)				option->optionIcon->animation->play(HX_("off",6f,93,54,00),null(),null(),null());
            			}
            			else {
HXLINE( 440)				_gthis->setting(option,HX_("On",3f,45,00,00),option->ID);
HXLINE( 441)				option->optionIcon->animation->play(HX_("modifier",57,db,c7,16),null(),null(),null());
            			}
HXLINE( 444)			if (pressed) {
HXLINE( 445)				_gthis->isChangingOption = false;
            			}
            		}
            		HX_END_LOCAL_FUNC2((void))

            	HX_GC_STACKFRAME(&_hx_pos_b3f58d72d382e2a6_85_create)
HXDLIN(  85)		 ::OptionsMenuState _gthis = ::hx::ObjectPtr<OBJ_>(this);
HXLINE(  86)		::flixel::FlxG_obj::mouse->set_visible(true);
HXLINE(  88)		{
HXLINE(  88)			 ::Dynamic _hx_tmp;
HXDLIN(  88)			switch((int)(::SaveType_obj::DOWNSCROLL_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE(  88)					_hx_tmp = null();
            				}
            			}
HXDLIN(  88)			::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),_hx_tmp,::hx::paccDynamic);
HXDLIN(  88)			 ::Dynamic _hx_tmp1;
HXDLIN(  88)			switch((int)(::SaveType_obj::PRESET_KEYBINDS_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE(  88)					_hx_tmp1 = null();
            				}
            			}
HXDLIN(  88)			::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),_hx_tmp1,::hx::paccDynamic);
HXDLIN(  88)			 ::Dynamic _hx_tmp2;
HXDLIN(  88)			switch((int)(::SaveType_obj::PERFECT_MODE_MOD_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE(  88)					_hx_tmp2 = null();
            				}
            			}
HXDLIN(  88)			::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),_hx_tmp2,::hx::paccDynamic);
HXDLIN(  88)			 ::Dynamic _hx_tmp3;
HXDLIN(  88)			switch((int)(::SaveType_obj::FLIP_CHART_MOD_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE(  88)					_hx_tmp3 = null();
            				}
            			}
HXDLIN(  88)			::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),_hx_tmp3,::hx::paccDynamic);
HXDLIN(  88)			 ::Dynamic _hx_tmp4;
HXDLIN(  88)			switch((int)(::SaveType_obj::CUSTOM_HELL_MOD_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE(  88)					_hx_tmp4 = null();
            				}
            			}
HXDLIN(  88)			::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),_hx_tmp4,::hx::paccDynamic);
HXDLIN(  88)			 ::Dynamic _hx_tmp5;
HXDLIN(  88)			switch((int)(::SaveType_obj::FAIR_BATTLE_MOD_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE(  88)					_hx_tmp5 = null();
            				}
            			}
HXDLIN(  88)			::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),_hx_tmp5,::hx::paccDynamic);
HXDLIN(  88)			 ::Dynamic _hx_tmp6;
HXDLIN(  88)			switch((int)(::SaveType_obj::FADE_BATTLE_MOD_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE(  88)					_hx_tmp6 = null();
            				}
            			}
HXDLIN(  88)			::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),_hx_tmp6,::hx::paccDynamic);
HXDLIN(  88)			 ::Dynamic _hx_tmp7;
HXDLIN(  88)			switch((int)(::SaveType_obj::SHOW_BOTTOM_BAR_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE(  88)					_hx_tmp7 = null();
            				}
            			}
HXDLIN(  88)			::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),_hx_tmp7,::hx::paccDynamic);
HXDLIN(  88)			 ::Dynamic _hx_tmp8;
HXDLIN(  88)			switch((int)(::SaveType_obj::SHOW_NOTE_SPLASH_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE(  88)					_hx_tmp8 = null();
            				}
            			}
HXDLIN(  88)			::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),_hx_tmp8,::hx::paccDynamic);
HXDLIN(  88)			 ::Dynamic _hx_tmp9;
HXDLIN(  88)			switch((int)(::SaveType_obj::GRAPHICS_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE(  88)					_hx_tmp9 = null();
            				}
            			}
HXDLIN(  88)			::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),_hx_tmp9,::hx::paccDynamic);
HXDLIN(  88)			 ::Dynamic _hx_tmp10;
HXDLIN(  88)			switch((int)(::SaveType_obj::SET_FPS_DEFAULT_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE(  88)					_hx_tmp10 = null();
            				}
            			}
HXDLIN(  88)			::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),_hx_tmp10,::hx::paccDynamic);
HXDLIN(  88)			 ::Dynamic _hx_tmp11;
HXDLIN(  88)			switch((int)(::SaveType_obj::FPS_MULTIPLIER_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE(  88)					_hx_tmp11 = null();
            				}
            			}
HXDLIN(  88)			::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),_hx_tmp11,::hx::paccDynamic);
HXDLIN(  88)			 ::Dynamic _hx_tmp12;
HXDLIN(  88)			switch((int)(::SaveType_obj::NO_BLUE_BALLS_MOD_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE(  88)					_hx_tmp12 = null();
            				}
            			}
HXDLIN(  88)			::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),_hx_tmp12,::hx::paccDynamic);
HXDLIN(  88)			 ::Dynamic _hx_tmp13;
HXDLIN(  88)			switch((int)(::SaveType_obj::BLIND_MOD_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE(  88)					_hx_tmp13 = null();
            				}
            			}
HXDLIN(  88)			::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),_hx_tmp13,::hx::paccDynamic);
HXDLIN(  88)			 ::Dynamic _hx_tmp14;
HXDLIN(  88)			switch((int)(::SaveType_obj::X_WOBBLE_MOD_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE(  88)					_hx_tmp14 = null();
            				}
            			}
HXDLIN(  88)			::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),_hx_tmp14,::hx::paccDynamic);
HXDLIN(  88)			 ::Dynamic _hx_tmp15;
HXDLIN(  88)			switch((int)(::SaveType_obj::PRESET_INPUTS_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE(  88)					_hx_tmp15 = null();
            				}
            			}
HXDLIN(  88)			::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),_hx_tmp15,::hx::paccDynamic);
HXDLIN(  88)			 ::Dynamic _hx_tmp16;
HXDLIN(  88)			switch((int)(::SaveType_obj::CACHE_ASSETS_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE(  88)					_hx_tmp16 = null();
            				}
            			}
HXDLIN(  88)			::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),_hx_tmp16,::hx::paccDynamic);
HXDLIN(  88)			 ::Dynamic _hx_tmp17;
HXDLIN(  88)			switch((int)(::SaveType_obj::CUSTOM_KEYBINDS_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE(  88)					_hx_tmp17 = null();
            				}
            			}
HXDLIN(  88)			::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),_hx_tmp17,::hx::paccDynamic);
HXDLIN(  88)			 ::Dynamic _hx_tmp18;
HXDLIN(  88)			switch((int)(::SaveType_obj::CAMERA_MOVEMENT_MOD_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE(  88)					_hx_tmp18 = null();
            				}
            			}
HXDLIN(  88)			::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),_hx_tmp18,::hx::paccDynamic);
HXDLIN(  88)			 ::Dynamic _hx_tmp19;
HXDLIN(  88)			switch((int)(::SaveType_obj::GHOST_TAPPING_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE(  88)					_hx_tmp19 = null();
            				}
            			}
HXDLIN(  88)			::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),_hx_tmp19,::hx::paccDynamic);
HXDLIN(  88)			 ::Dynamic _hx_tmp20;
HXDLIN(  88)			switch((int)(::SaveType_obj::CUSTOM_MENU_BINDS_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE(  88)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  88)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN(  88)					_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE(  88)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  88)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN(  88)					_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE(  88)					_hx_tmp20 = null();
            				}
            			}
HXDLIN(  88)			::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),_hx_tmp20,::hx::paccDynamic);
HXDLIN(  88)			::flixel::FlxG_obj::save->flush(null(),null());
            		}
HXLINE(  90)		this->camBackground =  ::betterShit::BetterCams_obj::__alloc( HX_CTX );
HXLINE(  91)		this->camNoBlur =  ::betterShit::BetterCams_obj::__alloc( HX_CTX );
HXLINE(  92)		this->camSubState =  ::betterShit::BetterCams_obj::__alloc( HX_CTX );
HXLINE(  93)		{
HXLINE(  93)			 ::betterShit::BetterCams _hx_tmp21 = this->camBackground;
HXDLIN(  93)			_hx_tmp21->bgColor = (_hx_tmp21->bgColor & 16777215);
HXDLIN(  93)			 ::betterShit::BetterCams _hx_tmp22 = this->camBackground;
HXDLIN(  93)			_hx_tmp22->bgColor = (_hx_tmp22->bgColor | 0);
            		}
HXLINE(  94)		{
HXLINE(  94)			 ::betterShit::BetterCams _hx_tmp23 = this->camNoBlur;
HXDLIN(  94)			_hx_tmp23->bgColor = (_hx_tmp23->bgColor & 16777215);
HXDLIN(  94)			 ::betterShit::BetterCams _hx_tmp24 = this->camNoBlur;
HXDLIN(  94)			_hx_tmp24->bgColor = (_hx_tmp24->bgColor | 0);
            		}
HXLINE(  95)		{
HXLINE(  95)			 ::betterShit::BetterCams _hx_tmp25 = this->camSubState;
HXDLIN(  95)			_hx_tmp25->bgColor = (_hx_tmp25->bgColor & 16777215);
HXDLIN(  95)			 ::betterShit::BetterCams _hx_tmp26 = this->camSubState;
HXDLIN(  95)			_hx_tmp26->bgColor = (_hx_tmp26->bgColor | 0);
            		}
HXLINE(  97)		::flixel::FlxG_obj::cameras->reset(this->camBackground);
HXLINE(  98)		::flixel::FlxG_obj::cameras->add(this->camNoBlur,null()).StaticCast<  ::betterShit::BetterCams >();
HXLINE(  99)		::flixel::FlxG_obj::cameras->add(this->camSubState,null()).StaticCast<  ::betterShit::BetterCams >();
HXLINE( 101)		this->camNoBlur->set_zoom(((Float)0.9));
HXLINE( 103)		::flixel::FlxCamera_obj::_defaultCameras = ::Array_obj< ::Dynamic>::__new(1)->init(0,this->camBackground);
HXLINE( 105)		this->curOptionSection =  ::flixel::group::FlxTypedSpriteGroup_obj::__alloc( HX_CTX ,null(),null(),null());
HXLINE( 111)		 ::Options _hx_tmp27 =  ::Options_obj::__alloc( HX_CTX ,( (Float)(0) ),( (Float)(10) ),HX_("Custom Keybinds",66,a4,88,73),::SaveType_obj::CUSTOM_KEYBINDS_dyn(), ::Dynamic(new _hx_Closure_0(_gthis)));
HXLINE( 127)		 ::Options _hx_tmp28 =  ::Options_obj::__alloc( HX_CTX ,( (Float)(0) ),( (Float)(20) ),HX_("Preset Keybinds",f8,92,5a,e3),::SaveType_obj::PRESET_KEYBINDS_dyn(), ::Dynamic(new _hx_Closure_1(_gthis)));
HXLINE( 143)		 ::Options _hx_tmp29 =  ::Options_obj::__alloc( HX_CTX ,( (Float)(0) ),( (Float)(30) ),HX_("Minimal FPS Cap",3c,45,19,b3),::SaveType_obj::SET_FPS_DEFAULT_dyn(), ::Dynamic(new _hx_Closure_2(_gthis)));
HXLINE( 164)		 ::Options _hx_tmp30 =  ::Options_obj::__alloc( HX_CTX ,( (Float)(0) ),( (Float)(40) ),HX_("Multiply FPS",ed,47,81,f7),::SaveType_obj::FPS_MULTIPLIER_dyn(), ::Dynamic(new _hx_Closure_3(_gthis)));
HXLINE( 185)		 ::Options _hx_tmp31 =  ::Options_obj::__alloc( HX_CTX ,( (Float)(0) ),( (Float)(50) ),HX_("Complex Inputs",59,65,23,bd),::SaveType_obj::PRESET_INPUTS_dyn(), ::Dynamic(new _hx_Closure_4(_gthis)));
HXLINE( 202)		 ::Options _hx_tmp32 =  ::Options_obj::__alloc( HX_CTX ,( (Float)(0) ),( (Float)(60) ),HX_("Downscroll",0f,4a,85,46),::SaveType_obj::DOWNSCROLL_dyn(), ::Dynamic(new _hx_Closure_5(_gthis)));
HXLINE( 219)		 ::Options _hx_tmp33 =  ::Options_obj::__alloc( HX_CTX ,( (Float)(0) ),( (Float)(70) ),HX_("Note Splash",d5,0f,35,f1),::SaveType_obj::SHOW_NOTE_SPLASH_dyn(), ::Dynamic(new _hx_Closure_6(_gthis)));
HXLINE( 236)		 ::Options _hx_tmp34 =  ::Options_obj::__alloc( HX_CTX ,( (Float)(0) ),( (Float)(80) ),HX_("Show Accuracy",bc,55,df,cd),::SaveType_obj::SHOW_BOTTOM_BAR_dyn(), ::Dynamic(new _hx_Closure_7(_gthis)));
HXLINE( 253)		 ::Options _hx_tmp35 =  ::Options_obj::__alloc( HX_CTX ,( (Float)(0) ),( (Float)(90) ),HX_("High Graphics",49,f1,ab,d7),::SaveType_obj::GRAPHICS_dyn(), ::Dynamic(new _hx_Closure_8(_gthis)));
HXLINE( 270)		 ::Options _hx_tmp36 =  ::Options_obj::__alloc( HX_CTX ,( (Float)(0) ),( (Float)(100) ),HX_("Cache Assets",e1,f2,6c,5c),::SaveType_obj::CACHE_ASSETS_dyn(), ::Dynamic(new _hx_Closure_9(_gthis)));
HXLINE( 287)		 ::GhostTapping _hx_tmp37 =  ::GhostTapping_obj::__alloc( HX_CTX ,( (Float)(0) ),( (Float)(110) ),HX_("Ghost Tapping",44,6c,9f,40),::SaveType_obj::GHOST_TAPPING_dyn(), ::Dynamic(new _hx_Closure_10(_gthis)));
HXLINE( 304)		 ::Options _hx_tmp38 =  ::Options_obj::__alloc( HX_CTX ,( (Float)(0) ),( (Float)((((this->imNotSure + 1) * 10) + 60)) ),HX_("Modifiers",1c,f1,ea,79),::SaveType_obj::NONE_dyn(), ::Dynamic(new _hx_Closure_11(_gthis)));
HXLINE( 311)		 ::Options _hx_tmp39 =  ::Options_obj::__alloc( HX_CTX ,( (Float)(0) ),( (Float)((((this->imNotSure + 1) * 10) + 120)) ),HX_("Opposite Chart",e5,2c,7c,19),::SaveType_obj::FLIP_CHART_MOD_dyn(), ::Dynamic(new _hx_Closure_12(_gthis)));
HXLINE( 328)		 ::Options _hx_tmp40 =  ::Options_obj::__alloc( HX_CTX ,( (Float)(0) ),( (Float)((((this->imNotSure + 2) * 10) + 120)) ),HX_("Custom Hell",8c,7d,f8,82),::SaveType_obj::CUSTOM_HELL_MOD_dyn(), ::Dynamic(new _hx_Closure_13(_gthis)));
HXLINE( 345)		 ::Options _hx_tmp41 =  ::Options_obj::__alloc( HX_CTX ,( (Float)(0) ),( (Float)((((this->imNotSure + 3) * 10) + 120)) ),HX_("Get Good Scrub",f6,14,99,17),::SaveType_obj::PERFECT_MODE_MOD_dyn(), ::Dynamic(new _hx_Closure_14(_gthis)));
HXLINE( 362)		 ::Options _hx_tmp42 =  ::Options_obj::__alloc( HX_CTX ,( (Float)(0) ),( (Float)((((this->imNotSure + 4) * 10) + 120)) ),HX_("Both Health Gain",84,bc,c1,eb),::SaveType_obj::FAIR_BATTLE_MOD_dyn(), ::Dynamic(new _hx_Closure_15(_gthis)));
HXLINE( 379)		 ::Options _hx_tmp43 =  ::Options_obj::__alloc( HX_CTX ,( (Float)(0) ),( (Float)((((this->imNotSure + 5) * 10) + 120)) ),HX_("Fade In Notes",ca,94,9a,ba),::SaveType_obj::FADE_BATTLE_MOD_dyn(), ::Dynamic(new _hx_Closure_16(_gthis)));
HXLINE( 396)		 ::Options _hx_tmp44 =  ::Options_obj::__alloc( HX_CTX ,( (Float)(0) ),( (Float)((((this->imNotSure + 6) * 10) + 120)) ),HX_("No Blue Balls",ed,3c,d3,07),::SaveType_obj::NO_BLUE_BALLS_MOD_dyn(), ::Dynamic(new _hx_Closure_17(_gthis)));
HXLINE( 413)		 ::Options _hx_tmp45 =  ::Options_obj::__alloc( HX_CTX ,( (Float)(0) ),( (Float)((((this->imNotSure + 7) * 10) + 120)) ),HX_("Simon Says",92,fe,ac,de),::SaveType_obj::BLIND_MOD_dyn(), ::Dynamic(new _hx_Closure_18(_gthis)));
HXLINE( 107)		this->optionList = ::Array_obj< ::Dynamic>::__new(1)->init(0, ::Dynamic(::hx::Anon_obj::Create(2)
            			->setFixed(0,HX_("options",5e,33,fe,df),::Array_obj< ::Dynamic>::__new(20)->init(0,_hx_tmp27)->init(1,_hx_tmp28)->init(2,_hx_tmp29)->init(3,_hx_tmp30)->init(4,_hx_tmp31)->init(5,_hx_tmp32)->init(6,_hx_tmp33)->init(7,_hx_tmp34)->init(8,_hx_tmp35)->init(9,_hx_tmp36)->init(10,_hx_tmp37)->init(11,_hx_tmp38)->init(12,_hx_tmp39)->init(13,_hx_tmp40)->init(14,_hx_tmp41)->init(15,_hx_tmp42)->init(16,_hx_tmp43)->init(17,_hx_tmp44)->init(18,_hx_tmp45)->init(19, ::Options_obj::__alloc( HX_CTX ,( (Float)(0) ),( (Float)((((this->imNotSure + 8) * 10) + 120)) ),HX_("Wobbly Notes",46,f6,bb,5c),::SaveType_obj::X_WOBBLE_MOD_dyn(), ::Dynamic(new _hx_Closure_19(_gthis)))))
            			->setFixed(1,HX_("catagory",fa,d8,d1,5f),HX_("Everything",93,ce,86,95))));
HXLINE( 451)		this->setCat(this->curCatalog);
HXLINE( 453)		 ::betterShit::BetterCams _hx_tmp46 = this->camBackground;
HXDLIN( 453)		 ::openfl::filters::BlurFilter _hx_tmp47 =  ::openfl::filters::BlurFilter_obj::__alloc( HX_CTX ,15,15,1);
HXDLIN( 453)		_hx_tmp46->setFilters(::Array_obj< ::Dynamic>::__new(2)->init(0,_hx_tmp47)->init(1, ::openfl::filters::ShaderFilter_obj::__alloc( HX_CTX , ::_OptionsMenuState::StupidVibeShader_obj::__alloc( HX_CTX ,((Float)1.5)))));
HXLINE( 455)		this->add(this->curOptionSection);
HXLINE( 457)		this->blurEffect =  ::feshixl::filters::GuassianBlur_obj::__alloc( HX_CTX ,0,null());
HXLINE( 458)		 ::betterShit::BetterCams _hx_tmp48 = this->camNoBlur;
HXDLIN( 458)		_hx_tmp48->setFilters(::Array_obj< ::Dynamic>::__new(1)->init(0, ::openfl::filters::ShaderFilter_obj::__alloc( HX_CTX ,this->blurEffect)));
HXLINE( 460)		if (::hx::IsNotEq(  ::Dynamic(::Paths_obj::get_modJSON()->__Field(HX_("main_menu",a5,ba,e0,81),::hx::paccDynamic))->__Field(HX_("background_image",0a,a1,52,4f),::hx::paccDynamic),HX_("",00,00,00,00) )) {
HXLINE( 461)			 ::flixel::FlxSprite bg =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,null(),null(),null());
HXDLIN( 461)			 ::flixel::FlxSprite bg1 = bg->loadGraphic(::Paths_obj::image(( (::String)( ::Dynamic(::Paths_obj::get_modJSON()->__Field(HX_("main_menu",a5,ba,e0,81),::hx::paccDynamic))->__Field(HX_("background_image",0a,a1,52,4f),::hx::paccDynamic)) ),null()),null(),null(),null(),null(),null());
HXLINE( 462)			bg1->setGraphicSize(1280,720);
HXLINE( 463)			bg1->updateHitbox();
HXLINE( 464)			{
HXLINE( 464)				 ::flixel::util::FlxAxes axes = ::flixel::util::FlxAxes_obj::XY_dyn();
HXDLIN( 464)				bool _hx_tmp;
HXDLIN( 464)				switch((int)(axes->_hx_getIndex())){
            					case (int)0: case (int)2: {
HXLINE( 464)						_hx_tmp = true;
            					}
            					break;
            					default:{
HXLINE( 464)						_hx_tmp = false;
            					}
            				}
HXDLIN( 464)				if (_hx_tmp) {
HXLINE( 464)					int _hx_tmp = ::flixel::FlxG_obj::width;
HXDLIN( 464)					bg1->set_x(((( (Float)(_hx_tmp) ) - bg1->get_width()) / ( (Float)(2) )));
            				}
HXDLIN( 464)				bool _hx_tmp1;
HXDLIN( 464)				switch((int)(axes->_hx_getIndex())){
            					case (int)1: case (int)2: {
HXLINE( 464)						_hx_tmp1 = true;
            					}
            					break;
            					default:{
HXLINE( 464)						_hx_tmp1 = false;
            					}
            				}
HXDLIN( 464)				if (_hx_tmp1) {
HXLINE( 464)					int _hx_tmp = ::flixel::FlxG_obj::height;
HXDLIN( 464)					bg1->set_y(((( (Float)(_hx_tmp) ) - bg1->get_height()) / ( (Float)(2) )));
            				}
            			}
HXLINE( 465)			bg1->scrollFactor->set(((Float)0.1),null());
HXLINE( 466)			this->add(bg1);
            		}
            		else {
HXLINE( 468)			 ::flixel::FlxSprite bg =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,-100,-15,null());
HXDLIN( 468)			 ::flixel::FlxSprite bg1 = bg->loadGraphic(::Paths_obj::image(HX_("menu/sky2",e1,61,d5,63),null()),null(),null(),null(),null(),null());
HXLINE( 469)			bg1->scrollFactor->set(null(),null());
HXLINE( 470)			this->add(bg1);
HXLINE( 472)			 ::flixel::FlxSprite city =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,-10,-15,null());
HXDLIN( 472)			 ::flixel::FlxSprite city1 = city->loadGraphic(::Paths_obj::image(HX_("menu/city",5b,6f,40,59),null()),null(),null(),null(),null(),null());
HXLINE( 473)			city1->scrollFactor->set(((Float)0.1),null());
HXLINE( 474)			city1->updateHitbox();
HXLINE( 475)			{
HXLINE( 475)				 ::flixel::util::FlxAxes axes = ::flixel::util::FlxAxes_obj::XY_dyn();
HXDLIN( 475)				bool _hx_tmp;
HXDLIN( 475)				switch((int)(axes->_hx_getIndex())){
            					case (int)0: case (int)2: {
HXLINE( 475)						_hx_tmp = true;
            					}
            					break;
            					default:{
HXLINE( 475)						_hx_tmp = false;
            					}
            				}
HXDLIN( 475)				if (_hx_tmp) {
HXLINE( 475)					int _hx_tmp = ::flixel::FlxG_obj::width;
HXDLIN( 475)					city1->set_x(((( (Float)(_hx_tmp) ) - city1->get_width()) / ( (Float)(2) )));
            				}
HXDLIN( 475)				bool _hx_tmp1;
HXDLIN( 475)				switch((int)(axes->_hx_getIndex())){
            					case (int)1: case (int)2: {
HXLINE( 475)						_hx_tmp1 = true;
            					}
            					break;
            					default:{
HXLINE( 475)						_hx_tmp1 = false;
            					}
            				}
HXDLIN( 475)				if (_hx_tmp1) {
HXLINE( 475)					int _hx_tmp = ::flixel::FlxG_obj::height;
HXDLIN( 475)					city1->set_y(((( (Float)(_hx_tmp) ) - city1->get_height()) / ( (Float)(2) )));
            				}
            			}
HXLINE( 476)			this->add(city1);
HXLINE( 478)			 ::flixel::FlxSprite light =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,city1->x,city1->y,null());
HXDLIN( 478)			 ::flixel::FlxSprite light1 = light->loadGraphic(::Paths_obj::image(HX_("menu/win2",46,ae,78,66),null()),null(),null(),null(),null(),null());
HXLINE( 479)			light1->scrollFactor->set(((Float)0.1),null());
HXLINE( 480)			light1->updateHitbox();
HXLINE( 481)			{
HXLINE( 481)				 ::flixel::util::FlxAxes axes1 = ::flixel::util::FlxAxes_obj::XY_dyn();
HXDLIN( 481)				bool _hx_tmp2;
HXDLIN( 481)				switch((int)(axes1->_hx_getIndex())){
            					case (int)0: case (int)2: {
HXLINE( 481)						_hx_tmp2 = true;
            					}
            					break;
            					default:{
HXLINE( 481)						_hx_tmp2 = false;
            					}
            				}
HXDLIN( 481)				if (_hx_tmp2) {
HXLINE( 481)					int _hx_tmp = ::flixel::FlxG_obj::width;
HXDLIN( 481)					light1->set_x(((( (Float)(_hx_tmp) ) - light1->get_width()) / ( (Float)(2) )));
            				}
HXDLIN( 481)				bool _hx_tmp3;
HXDLIN( 481)				switch((int)(axes1->_hx_getIndex())){
            					case (int)1: case (int)2: {
HXLINE( 481)						_hx_tmp3 = true;
            					}
            					break;
            					default:{
HXLINE( 481)						_hx_tmp3 = false;
            					}
            				}
HXDLIN( 481)				if (_hx_tmp3) {
HXLINE( 481)					int _hx_tmp = ::flixel::FlxG_obj::height;
HXDLIN( 481)					light1->set_y(((( (Float)(_hx_tmp) ) - light1->get_height()) / ( (Float)(2) )));
            				}
            			}
HXLINE( 482)			this->add(light1);
HXLINE( 484)			 ::flixel::FlxSprite streetBehind =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,-40,-50,null());
HXDLIN( 484)			 ::flixel::FlxSprite streetBehind1 = streetBehind->loadGraphic(::Paths_obj::image(HX_("menu/behindTrain",fe,c8,df,0d),null()),null(),null(),null(),null(),null());
HXLINE( 485)			streetBehind1->scrollFactor->set(null(),null());
HXLINE( 486)			this->add(streetBehind1);
HXLINE( 488)			 ::flixel::FlxSprite street =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,-40,streetBehind1->y,null());
HXDLIN( 488)			 ::flixel::FlxSprite street1 = street->loadGraphic(::Paths_obj::image(HX_("menu/street",b3,21,7c,37),null()),null(),null(),null(),null(),null());
HXLINE( 489)			street1->scrollFactor->set(((Float)0.1),null());
HXLINE( 490)			this->add(street1);
            		}
HXLINE( 493)		this->curOptionSection->set_cameras(::Array_obj< ::Dynamic>::__new(1)->init(0,this->camNoBlur));
HXLINE( 495)		this->shouldPress = true;
HXLINE( 497)		this->super::create();
            	}


void OptionsMenuState_obj::setControls( ::Options option,int id){
            	HX_STACKFRAME(&_hx_pos_b3f58d72d382e2a6_500_setControls)
HXLINE( 501)		if (::hx::IsGreater( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic),3 )) {
HXLINE( 502)			::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            		}
HXLINE( 504)		{
HXLINE( 504)			 ::Dynamic _g;
HXDLIN( 504)			switch((int)(::SaveType_obj::PRESET_KEYBINDS_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE( 504)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 504)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN( 504)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE( 504)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 504)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE( 504)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 504)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN( 504)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE( 504)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 504)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN( 504)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE( 504)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 504)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN( 504)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE( 504)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 504)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN( 504)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE( 504)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 504)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN( 504)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE( 504)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 504)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN( 504)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE( 504)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 504)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN( 504)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE( 504)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 504)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN( 504)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE( 504)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 504)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN( 504)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE( 504)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 504)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE( 504)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 504)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN( 504)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE( 504)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 504)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN( 504)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE( 504)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 504)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN( 504)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE( 504)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 504)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN( 504)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE( 504)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 504)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN( 504)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE( 504)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 504)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN( 504)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE( 504)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 504)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN( 504)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE( 504)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 504)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN( 504)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE( 504)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 504)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN( 504)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE( 504)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 504)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN( 504)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE( 504)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 504)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN( 504)					_g =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE( 504)					_g = null();
            				}
            			}
HXDLIN( 504)			 ::Dynamic _hx_switch_0 = _g;
            			if (  (_hx_switch_0==0) ){
HXLINE( 506)				::PlayerSettings_obj::player1->controls->setKeyboardScheme(::KeyboardScheme_obj::Duo(true),true);
HXLINE( 507)				this->setting(option,HX_("W A S D",4f,87,a8,6f),id);
HXLINE( 505)				goto _hx_goto_22;
            			}
            			if (  (_hx_switch_0==1) ){
HXLINE( 509)				::PlayerSettings_obj::player1->controls->setKeyboardScheme(::KeyboardScheme_obj::Solo_dyn(),true);
HXLINE( 510)				this->setting(option,HX_("D F J K",3f,c9,8a,3a),id);
HXLINE( 508)				goto _hx_goto_22;
            			}
            			if (  (_hx_switch_0==2) ){
HXLINE( 512)				::PlayerSettings_obj::player1->controls->setKeyboardScheme(::KeyboardScheme_obj::Duo(false),true);
HXLINE( 513)				this->setting(option,HX_("Z X 1 2",75,76,86,2a),id);
HXLINE( 511)				goto _hx_goto_22;
            			}
            			if (  (_hx_switch_0==3) ){
HXLINE( 515)				::PlayerSettings_obj::player1->controls->setKeyboardScheme(::KeyboardScheme_obj::Custom_dyn(),true);
HXLINE( 516)				this->setting(option,HX_("CUSTOM",b1,33,15,f2),id);
HXLINE( 514)				goto _hx_goto_22;
            			}
            			_hx_goto_22:;
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC2(OptionsMenuState_obj,setControls,(void))

void OptionsMenuState_obj::changeSelection(::hx::Null< int >  __o_change){
            		HX_BEGIN_LOCAL_FUNC_S2(::hx::LocalFunc,_hx_Closure_0, ::OptionsMenuState,_gthis,int,change) HXARGC(1)
            		void _hx_run( ::Options option){
            			HX_STACKFRAME(&_hx_pos_b3f58d72d382e2a6_533_changeSelection)
HXLINE( 533)			bool _hx_tmp;
HXDLIN( 533)			if (option->optionTitle) {
HXLINE( 533)				_hx_tmp = (option->ID == _gthis->curSelected);
            			}
            			else {
HXLINE( 533)				_hx_tmp = false;
            			}
HXDLIN( 533)			if (_hx_tmp) {
HXLINE( 534)				 ::OptionsMenuState _gthis1 = _gthis;
HXDLIN( 534)				_gthis1->curSelected = (_gthis1->curSelected + change);
HXLINE( 536)				if ((_gthis->curSelected < 0)) {
HXLINE( 537)					_gthis->curSelected = (( (::Array< ::Dynamic>)(_gthis->optionList->__get(_gthis->curCatalog)->__Field(HX_("options",5e,33,fe,df),::hx::paccDynamic)) )->length - 1);
            				}
HXLINE( 538)				if ((_gthis->curSelected >= ( (::Array< ::Dynamic>)(_gthis->optionList->__get(_gthis->curCatalog)->__Field(HX_("options",5e,33,fe,df),::hx::paccDynamic)) )->length)) {
HXLINE( 539)					_gthis->curSelected = 0;
            				}
HXLINE( 541)				return;
            			}
            		}
            		HX_END_LOCAL_FUNC1((void))

            		int change = __o_change.Default(0);
            	HX_STACKFRAME(&_hx_pos_b3f58d72d382e2a6_520_changeSelection)
HXDLIN( 520)		 ::OptionsMenuState _gthis = ::hx::ObjectPtr<OBJ_>(this);
HXLINE( 521)		 ::flixel::_hx_system::frontEnds::SoundFrontEnd _hx_tmp = ::flixel::FlxG_obj::sound;
HXDLIN( 521)		::String library = null();
HXDLIN( 521)		::String _hx_tmp1;
HXDLIN( 521)		if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("sounds/",eb,02,a5,b6) + HX_("scrollMenu",4c,d4,18,06)) + HX_(".",2e,00,00,00)) + HX_("ogg",4f,94,54,00)),HX_("SOUND",af,c4,ba,fe),library),null())) {
HXLINE( 521)			_hx_tmp1 = ::Paths_obj::getPath((((HX_("sounds/",eb,02,a5,b6) + HX_("scrollMenu",4c,d4,18,06)) + HX_(".",2e,00,00,00)) + HX_("ogg",4f,94,54,00)),HX_("SOUND",af,c4,ba,fe),library);
            		}
            		else {
HXLINE( 521)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate sound - ",98,e2,ed,38) + HX_("scrollMenu",4c,d4,18,06))));
            		}
HXDLIN( 521)		_hx_tmp->play(_hx_tmp1,((Float)0.4),null(),null(),null(),null());
HXLINE( 523)		 ::OptionsMenuState _hx_tmp2 = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN( 523)		_hx_tmp2->curSelected = (_hx_tmp2->curSelected + change);
HXLINE( 525)		if ((this->curSelected < 0)) {
HXLINE( 526)			this->curSelected = (( (::Array< ::Dynamic>)(this->optionList->__get(this->curCatalog)->__Field(HX_("options",5e,33,fe,df),::hx::paccDynamic)) )->length - 1);
            		}
HXLINE( 527)		if ((this->curSelected >= ( (::Array< ::Dynamic>)(this->optionList->__get(this->curCatalog)->__Field(HX_("options",5e,33,fe,df),::hx::paccDynamic)) )->length)) {
HXLINE( 528)			this->curSelected = 0;
            		}
HXLINE( 530)		int bullShit = 0;
HXLINE( 532)		this->curOptionSection->group->forEach( ::Dynamic(new _hx_Closure_0(_gthis,change)),false);
HXLINE( 545)		{
HXLINE( 545)			int _g = 0;
HXDLIN( 545)			int _g1 = this->curOptionSection->group->length;
HXDLIN( 545)			while((_g < _g1)){
HXLINE( 545)				_g = (_g + 1);
HXDLIN( 545)				int i = (_g - 1);
HXLINE( 546)				 ::Options item = Dynamic( this->curOptionSection->group->members->__get(i)).StaticCast<  ::Options >();
HXLINE( 548)				item->targetY = (bullShit - this->curSelected);
HXLINE( 549)				bullShit = (bullShit + 1);
HXLINE( 551)				item->set_alpha(((Float)0.6));
HXLINE( 553)				bool _hx_tmp;
HXDLIN( 553)				if ((item->targetY != 0)) {
HXLINE( 553)					_hx_tmp = item->optionTitle;
            				}
            				else {
HXLINE( 553)					_hx_tmp = true;
            				}
HXDLIN( 553)				if (_hx_tmp) {
HXLINE( 554)					item->set_alpha(( (Float)(1) ));
            				}
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(OptionsMenuState_obj,changeSelection,(void))

void OptionsMenuState_obj::setting( ::Options option,::String display,int id){
            	HX_GC_STACKFRAME(&_hx_pos_b3f58d72d382e2a6_558_setting)
HXLINE( 559)		if (::hx::IsNull( this->optionSetting )) {
HXLINE( 560)			this->optionSetting =  ::flixel::group::FlxTypedGroup_obj::__alloc( HX_CTX ,null());
HXLINE( 561)			this->add(this->optionSetting);
            		}
HXLINE( 564)		 ::Alphabet optionS =  ::Alphabet_obj::__alloc( HX_CTX ,( (Float)(0) ),( (Float)(0) ),display,false,false,840);
HXLINE( 565)		optionS->ID = id;
HXLINE( 566)		optionS->set_cameras(::Array_obj< ::Dynamic>::__new(1)->init(0,this->camNoBlur));
HXLINE( 567)		this->optionSetting->add(optionS).StaticCast<  ::Alphabet >();
            	}


HX_DEFINE_DYNAMIC_FUNC3(OptionsMenuState_obj,setting,(void))

void OptionsMenuState_obj::setCat(int catagory){
            	HX_STACKFRAME(&_hx_pos_b3f58d72d382e2a6_570_setCat)
HXLINE( 571)		this->curOptionSection->group->clear();
HXLINE( 573)		{
HXLINE( 573)			int _g = 0;
HXDLIN( 573)			int _g1 = ( (::Array< ::Dynamic>)(this->optionList->__get(catagory)->__Field(HX_("options",5e,33,fe,df),::hx::paccDynamic)) )->length;
HXDLIN( 573)			while((_g < _g1)){
HXLINE( 573)				_g = (_g + 1);
HXDLIN( 573)				int i = (_g - 1);
HXLINE( 574)				if ((i != 0)) {
HXLINE( 574)					Dynamic(  ::Dynamic(this->optionList->__get(catagory)->__Field(HX_("options",5e,33,fe,df),::hx::paccDynamic))->__GetItem(i)).StaticCast<  ::Options >()->set_alpha(((Float)0.6));
            				}
HXLINE( 575)				Dynamic(  ::Dynamic(this->optionList->__get(catagory)->__Field(HX_("options",5e,33,fe,df),::hx::paccDynamic))->__GetItem(i)).StaticCast<  ::Options >()->targetY = i;
HXLINE( 576)				this->curOptionSection->add(Dynamic(  ::Dynamic(this->optionList->__get(catagory)->__Field(HX_("options",5e,33,fe,df),::hx::paccDynamic))->__GetItem(i)).StaticCast<  ::Options >()).StaticCast<  ::Options >();
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(OptionsMenuState_obj,setCat,(void))

void OptionsMenuState_obj::openSubStateBlur( ::flixel::FlxSubState SubState){
            		HX_BEGIN_LOCAL_FUNC_S2(::hx::LocalFunc,_hx_Closure_0, ::OptionsMenuState,_gthis, ::flixel::FlxSubState,SubState) HXARGC(1)
            		void _hx_run( ::flixel::tweens::FlxTween twn){
            			HX_STACKFRAME(&_hx_pos_b3f58d72d382e2a6_583_openSubStateBlur)
HXLINE( 584)			_gthis->openSubState(SubState);
HXLINE( 585)			_gthis->changeBlur = false;
            		}
            		HX_END_LOCAL_FUNC1((void))

            	HX_STACKFRAME(&_hx_pos_b3f58d72d382e2a6_580_openSubStateBlur)
HXDLIN( 580)		 ::OptionsMenuState _gthis = ::hx::ObjectPtr<OBJ_>(this);
HXLINE( 581)		this->changeBlur = true;
HXLINE( 583)		::flixel::tweens::FlxTween_obj::tween(this->blurEffect, ::Dynamic(::hx::Anon_obj::Create(1)
            			->setFixed(0,HX_("size",c1,a0,53,4c),20)),((Float)0.75), ::Dynamic(::hx::Anon_obj::Create(2)
            			->setFixed(0,HX_("ease",ee,8b,0c,43),::flixel::tweens::FlxEase_obj::quadOut_dyn())
            			->setFixed(1,HX_("onComplete",f8,d4,7e,5d), ::Dynamic(new _hx_Closure_0(_gthis,SubState)))));
            	}


HX_DEFINE_DYNAMIC_FUNC1(OptionsMenuState_obj,openSubStateBlur,(void))

void OptionsMenuState_obj::closeSubState(){
            	HX_STACKFRAME(&_hx_pos_b3f58d72d382e2a6_589_closeSubState)
HXLINE( 590)		this->isChangingOption = false;
HXLINE( 591)		::flixel::tweens::FlxTween_obj::tween(this->blurEffect, ::Dynamic(::hx::Anon_obj::Create(1)
            			->setFixed(0,HX_("size",c1,a0,53,4c),0)),((Float)0.75), ::Dynamic(::hx::Anon_obj::Create(1)
            			->setFixed(0,HX_("ease",ee,8b,0c,43),::flixel::tweens::FlxEase_obj::quadOut_dyn())));
HXLINE( 593)		this->super::closeSubState();
            	}


void OptionsMenuState_obj::update(Float elapsed){
            	HX_GC_STACKFRAME(&_hx_pos_b3f58d72d382e2a6_596_update)
HXDLIN( 596)		 ::OptionsMenuState _gthis = ::hx::ObjectPtr<OBJ_>(this);
HXLINE( 597)		this->super::update(elapsed);
HXLINE( 599)		bool upP = ::PlayerSettings_obj::player1->controls->_upP->check();
HXLINE( 600)		bool downP = ::PlayerSettings_obj::player1->controls->_downP->check();
HXLINE( 601)		bool accepted = ::PlayerSettings_obj::player1->controls->_accept->check();
HXLINE( 602)		bool escaped = ::PlayerSettings_obj::player1->controls->_back->check();
HXLINE( 604)		bool _hx_tmp;
HXDLIN( 604)		bool _hx_tmp1;
HXDLIN( 604)		if (!(upP)) {
HXLINE( 604)			_hx_tmp1 = (::flixel::FlxG_obj::mouse->wheel > ((Float)0.1));
            		}
            		else {
HXLINE( 604)			_hx_tmp1 = true;
            		}
HXDLIN( 604)		if (_hx_tmp1) {
HXLINE( 604)			_hx_tmp = !(this->isChangingOption);
            		}
            		else {
HXLINE( 604)			_hx_tmp = false;
            		}
HXDLIN( 604)		if (_hx_tmp) {
HXLINE( 605)			this->changeSelection(-1);
            		}
HXLINE( 606)		bool _hx_tmp2;
HXDLIN( 606)		bool _hx_tmp3;
HXDLIN( 606)		if (!(downP)) {
HXLINE( 606)			_hx_tmp3 = (::flixel::FlxG_obj::mouse->wheel < ((Float)-0.1));
            		}
            		else {
HXLINE( 606)			_hx_tmp3 = true;
            		}
HXDLIN( 606)		if (_hx_tmp3) {
HXLINE( 606)			_hx_tmp2 = !(this->isChangingOption);
            		}
            		else {
HXLINE( 606)			_hx_tmp2 = false;
            		}
HXDLIN( 606)		if (_hx_tmp2) {
HXLINE( 607)			this->changeSelection(1);
            		}
HXLINE( 609)		bool _hx_tmp4;
HXDLIN( 609)		if (accepted) {
HXLINE( 609)			_hx_tmp4 = !(this->isChangingOption);
            		}
            		else {
HXLINE( 609)			_hx_tmp4 = false;
            		}
HXDLIN( 609)		if (_hx_tmp4) {
HXLINE( 610)			this->isChangingOption = true;
HXLINE( 612)			this->settingTxt = HX_("",00,00,00,00);
HXLINE( 614)			this->remove(this->optionSetting,null());
HXLINE( 615)			this->optionSetting = ( ( ::flixel::group::FlxTypedGroup)(::flixel::util::FlxDestroyUtil_obj::destroy(this->optionSetting)) );
HXLINE( 617)			{
HXLINE( 617)				int _g = 0;
HXDLIN( 617)				int _g1 = ( (::Array< ::Dynamic>)(this->optionList->__get(this->curCatalog)->__Field(HX_("options",5e,33,fe,df),::hx::paccDynamic)) )->length;
HXDLIN( 617)				while((_g < _g1)){
HXLINE( 617)					_g = (_g + 1);
HXDLIN( 617)					int i = (_g - 1);
HXLINE( 618)					 ::Options item = Dynamic(  ::Dynamic(this->optionList->__get(this->curCatalog)->__Field(HX_("options",5e,33,fe,df),::hx::paccDynamic))->__GetItem(i)).StaticCast<  ::Options >();
HXLINE( 620)					if ((item->targetY == 0)) {
HXLINE( 621)						item->callback(item,true);
            					}
            					else {
HXLINE( 623)						item->callback(item,false);
            					}
            				}
            			}
            		}
HXLINE( 627)		bool _hx_tmp5;
HXDLIN( 627)		if (escaped) {
HXLINE( 627)			_hx_tmp5 = !(this->isChangingOption);
            		}
            		else {
HXLINE( 627)			_hx_tmp5 = false;
            		}
HXDLIN( 627)		if (_hx_tmp5) {
HXLINE( 628)			 ::flixel::FlxState nextState =  ::MainMenuState_obj::__alloc( HX_CTX ,null());
HXDLIN( 628)			if (::flixel::FlxG_obj::game->_state->switchTo(nextState)) {
HXLINE( 628)				::flixel::FlxG_obj::game->_requestedState = nextState;
            			}
            		}
HXLINE( 631)		if (::hx::IsNotNull( this->optionSetting )) {
            			HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_0, ::OptionsMenuState,_gthis) HXARGC(1)
            			void _hx_run( ::Options option){
            				HX_GC_STACKFRAME(&_hx_pos_b3f58d72d382e2a6_632_update)
HXLINE( 633)				Dynamic( _gthis->optionSetting->members->__get(option->ID)).StaticCast<  ::Alphabet >()->set_x(option->x);
HXLINE( 634)				 ::Alphabet _gthis1 = Dynamic( _gthis->optionSetting->members->__get(option->ID)).StaticCast<  ::Alphabet >();
HXDLIN( 634)				Float option1 = option->optionIcon->y;
HXDLIN( 634)				_gthis1->set_y(((option1 - (Dynamic( _gthis->optionSetting->members->__get(option->ID)).StaticCast<  ::Alphabet >()->get_height() / ( (Float)(2) ))) + 5));
            			}
            			HX_END_LOCAL_FUNC1((void))

HXLINE( 632)			this->curOptionSection->group->forEach( ::Dynamic(new _hx_Closure_0(_gthis)),false);
            		}
            	}



::hx::ObjectPtr< OptionsMenuState_obj > OptionsMenuState_obj::__new() {
	::hx::ObjectPtr< OptionsMenuState_obj > __this = new OptionsMenuState_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< OptionsMenuState_obj > OptionsMenuState_obj::__alloc(::hx::Ctx *_hx_ctx) {
	OptionsMenuState_obj *__this = (OptionsMenuState_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(OptionsMenuState_obj), true, "OptionsMenuState"));
	*(void **)__this = OptionsMenuState_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

OptionsMenuState_obj::OptionsMenuState_obj()
{
}

void OptionsMenuState_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(OptionsMenuState);
	HX_MARK_MEMBER_NAME(imNotSure,"imNotSure");
	HX_MARK_MEMBER_NAME(camBackground,"camBackground");
	HX_MARK_MEMBER_NAME(camNoBlur,"camNoBlur");
	HX_MARK_MEMBER_NAME(camSubState,"camSubState");
	HX_MARK_MEMBER_NAME(blurEffect,"blurEffect");
	HX_MARK_MEMBER_NAME(optionList,"optionList");
	HX_MARK_MEMBER_NAME(curOptionSection,"curOptionSection");
	HX_MARK_MEMBER_NAME(optionSetting,"optionSetting");
	HX_MARK_MEMBER_NAME(curCatalog,"curCatalog");
	HX_MARK_MEMBER_NAME(curSelected,"curSelected");
	HX_MARK_MEMBER_NAME(shouldPress,"shouldPress");
	HX_MARK_MEMBER_NAME(isChangingOption,"isChangingOption");
	HX_MARK_MEMBER_NAME(changeBlur,"changeBlur");
	HX_MARK_MEMBER_NAME(settingTxt,"settingTxt");
	 ::HelperStates_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void OptionsMenuState_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(imNotSure,"imNotSure");
	HX_VISIT_MEMBER_NAME(camBackground,"camBackground");
	HX_VISIT_MEMBER_NAME(camNoBlur,"camNoBlur");
	HX_VISIT_MEMBER_NAME(camSubState,"camSubState");
	HX_VISIT_MEMBER_NAME(blurEffect,"blurEffect");
	HX_VISIT_MEMBER_NAME(optionList,"optionList");
	HX_VISIT_MEMBER_NAME(curOptionSection,"curOptionSection");
	HX_VISIT_MEMBER_NAME(optionSetting,"optionSetting");
	HX_VISIT_MEMBER_NAME(curCatalog,"curCatalog");
	HX_VISIT_MEMBER_NAME(curSelected,"curSelected");
	HX_VISIT_MEMBER_NAME(shouldPress,"shouldPress");
	HX_VISIT_MEMBER_NAME(isChangingOption,"isChangingOption");
	HX_VISIT_MEMBER_NAME(changeBlur,"changeBlur");
	HX_VISIT_MEMBER_NAME(settingTxt,"settingTxt");
	 ::HelperStates_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val OptionsMenuState_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return ::hx::Val( create_dyn() ); }
		if (HX_FIELD_EQ(inName,"setCat") ) { return ::hx::Val( setCat_dyn() ); }
		if (HX_FIELD_EQ(inName,"update") ) { return ::hx::Val( update_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"setting") ) { return ::hx::Val( setting_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"imNotSure") ) { return ::hx::Val( imNotSure ); }
		if (HX_FIELD_EQ(inName,"camNoBlur") ) { return ::hx::Val( camNoBlur ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"blurEffect") ) { return ::hx::Val( blurEffect ); }
		if (HX_FIELD_EQ(inName,"optionList") ) { return ::hx::Val( optionList ); }
		if (HX_FIELD_EQ(inName,"curCatalog") ) { return ::hx::Val( curCatalog ); }
		if (HX_FIELD_EQ(inName,"changeBlur") ) { return ::hx::Val( changeBlur ); }
		if (HX_FIELD_EQ(inName,"settingTxt") ) { return ::hx::Val( settingTxt ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"camSubState") ) { return ::hx::Val( camSubState ); }
		if (HX_FIELD_EQ(inName,"curSelected") ) { return ::hx::Val( curSelected ); }
		if (HX_FIELD_EQ(inName,"shouldPress") ) { return ::hx::Val( shouldPress ); }
		if (HX_FIELD_EQ(inName,"setControls") ) { return ::hx::Val( setControls_dyn() ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"camBackground") ) { return ::hx::Val( camBackground ); }
		if (HX_FIELD_EQ(inName,"optionSetting") ) { return ::hx::Val( optionSetting ); }
		if (HX_FIELD_EQ(inName,"closeSubState") ) { return ::hx::Val( closeSubState_dyn() ); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"changeSelection") ) { return ::hx::Val( changeSelection_dyn() ); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"curOptionSection") ) { return ::hx::Val( curOptionSection ); }
		if (HX_FIELD_EQ(inName,"isChangingOption") ) { return ::hx::Val( isChangingOption ); }
		if (HX_FIELD_EQ(inName,"openSubStateBlur") ) { return ::hx::Val( openSubStateBlur_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val OptionsMenuState_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"imNotSure") ) { imNotSure=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"camNoBlur") ) { camNoBlur=inValue.Cast<  ::betterShit::BetterCams >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"blurEffect") ) { blurEffect=inValue.Cast<  ::feshixl::filters::GuassianBlur >(); return inValue; }
		if (HX_FIELD_EQ(inName,"optionList") ) { optionList=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
		if (HX_FIELD_EQ(inName,"curCatalog") ) { curCatalog=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"changeBlur") ) { changeBlur=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"settingTxt") ) { settingTxt=inValue.Cast< ::String >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"camSubState") ) { camSubState=inValue.Cast<  ::betterShit::BetterCams >(); return inValue; }
		if (HX_FIELD_EQ(inName,"curSelected") ) { curSelected=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"shouldPress") ) { shouldPress=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"camBackground") ) { camBackground=inValue.Cast<  ::betterShit::BetterCams >(); return inValue; }
		if (HX_FIELD_EQ(inName,"optionSetting") ) { optionSetting=inValue.Cast<  ::flixel::group::FlxTypedGroup >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"curOptionSection") ) { curOptionSection=inValue.Cast<  ::flixel::group::FlxTypedSpriteGroup >(); return inValue; }
		if (HX_FIELD_EQ(inName,"isChangingOption") ) { isChangingOption=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void OptionsMenuState_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("imNotSure",04,10,57,ee));
	outFields->push(HX_("camBackground",dd,54,7b,de));
	outFields->push(HX_("camNoBlur",f7,60,5f,39));
	outFields->push(HX_("camSubState",a0,23,e1,55));
	outFields->push(HX_("blurEffect",98,08,2f,d8));
	outFields->push(HX_("optionList",73,7a,4e,8d));
	outFields->push(HX_("curOptionSection",50,3d,cc,92));
	outFields->push(HX_("optionSetting",9b,be,dc,44));
	outFields->push(HX_("curCatalog",39,90,3f,f3));
	outFields->push(HX_("curSelected",fb,eb,ab,32));
	outFields->push(HX_("shouldPress",50,82,59,7f));
	outFields->push(HX_("isChangingOption",8c,73,4d,c4));
	outFields->push(HX_("changeBlur",37,78,62,1b));
	outFields->push(HX_("settingTxt",c0,9e,29,f3));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo OptionsMenuState_obj_sMemberStorageInfo[] = {
	{::hx::fsInt,(int)offsetof(OptionsMenuState_obj,imNotSure),HX_("imNotSure",04,10,57,ee)},
	{::hx::fsObject /*  ::betterShit::BetterCams */ ,(int)offsetof(OptionsMenuState_obj,camBackground),HX_("camBackground",dd,54,7b,de)},
	{::hx::fsObject /*  ::betterShit::BetterCams */ ,(int)offsetof(OptionsMenuState_obj,camNoBlur),HX_("camNoBlur",f7,60,5f,39)},
	{::hx::fsObject /*  ::betterShit::BetterCams */ ,(int)offsetof(OptionsMenuState_obj,camSubState),HX_("camSubState",a0,23,e1,55)},
	{::hx::fsObject /*  ::feshixl::filters::GuassianBlur */ ,(int)offsetof(OptionsMenuState_obj,blurEffect),HX_("blurEffect",98,08,2f,d8)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(OptionsMenuState_obj,optionList),HX_("optionList",73,7a,4e,8d)},
	{::hx::fsObject /*  ::flixel::group::FlxTypedSpriteGroup */ ,(int)offsetof(OptionsMenuState_obj,curOptionSection),HX_("curOptionSection",50,3d,cc,92)},
	{::hx::fsObject /*  ::flixel::group::FlxTypedGroup */ ,(int)offsetof(OptionsMenuState_obj,optionSetting),HX_("optionSetting",9b,be,dc,44)},
	{::hx::fsInt,(int)offsetof(OptionsMenuState_obj,curCatalog),HX_("curCatalog",39,90,3f,f3)},
	{::hx::fsInt,(int)offsetof(OptionsMenuState_obj,curSelected),HX_("curSelected",fb,eb,ab,32)},
	{::hx::fsBool,(int)offsetof(OptionsMenuState_obj,shouldPress),HX_("shouldPress",50,82,59,7f)},
	{::hx::fsBool,(int)offsetof(OptionsMenuState_obj,isChangingOption),HX_("isChangingOption",8c,73,4d,c4)},
	{::hx::fsBool,(int)offsetof(OptionsMenuState_obj,changeBlur),HX_("changeBlur",37,78,62,1b)},
	{::hx::fsString,(int)offsetof(OptionsMenuState_obj,settingTxt),HX_("settingTxt",c0,9e,29,f3)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *OptionsMenuState_obj_sStaticStorageInfo = 0;
#endif

static ::String OptionsMenuState_obj_sMemberFields[] = {
	HX_("imNotSure",04,10,57,ee),
	HX_("camBackground",dd,54,7b,de),
	HX_("camNoBlur",f7,60,5f,39),
	HX_("camSubState",a0,23,e1,55),
	HX_("blurEffect",98,08,2f,d8),
	HX_("optionList",73,7a,4e,8d),
	HX_("curOptionSection",50,3d,cc,92),
	HX_("optionSetting",9b,be,dc,44),
	HX_("curCatalog",39,90,3f,f3),
	HX_("curSelected",fb,eb,ab,32),
	HX_("shouldPress",50,82,59,7f),
	HX_("isChangingOption",8c,73,4d,c4),
	HX_("changeBlur",37,78,62,1b),
	HX_("settingTxt",c0,9e,29,f3),
	HX_("create",fc,66,0f,7c),
	HX_("setControls",38,50,1d,68),
	HX_("changeSelection",bc,98,b5,48),
	HX_("setting",90,e1,a7,27),
	HX_("setCat",94,01,63,6f),
	HX_("openSubStateBlur",a2,9e,dc,eb),
	HX_("closeSubState",49,18,32,04),
	HX_("update",09,86,05,87),
	::String(null()) };

::hx::Class OptionsMenuState_obj::__mClass;

void OptionsMenuState_obj::__register()
{
	OptionsMenuState_obj _hx_dummy;
	OptionsMenuState_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("OptionsMenuState",d4,0c,2d,7c);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(OptionsMenuState_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< OptionsMenuState_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = OptionsMenuState_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = OptionsMenuState_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

