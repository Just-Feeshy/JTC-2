#include <hxcpp.h>

#ifndef INCLUDED_APIStuff
#include <APIStuff.h>
#endif
#ifndef INCLUDED_Alphabet
#include <Alphabet.h>
#endif
#ifndef INCLUDED_Conductor
#include <Conductor.h>
#endif
#ifndef INCLUDED_Date
#include <Date.h>
#endif
#ifndef INCLUDED_DiscordClient
#include <DiscordClient.h>
#endif
#ifndef INCLUDED_HelperStates
#include <HelperStates.h>
#endif
#ifndef INCLUDED_Highscore
#include <Highscore.h>
#endif
#ifndef INCLUDED_MainMenuState
#include <MainMenuState.h>
#endif
#ifndef INCLUDED_MusicBeatState
#include <MusicBeatState.h>
#endif
#ifndef INCLUDED_NGio
#include <NGio.h>
#endif
#ifndef INCLUDED_Paths
#include <Paths.h>
#endif
#ifndef INCLUDED_PlayerSettings
#include <PlayerSettings.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_TitleState
#include <TitleState.h>
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
#ifndef INCLUDED_flixel_addons_transition_FlxTransitionableState
#include <flixel/addons/transition/FlxTransitionableState.h>
#endif
#ifndef INCLUDED_flixel_addons_transition_GraphicTransTileDiamond
#include <flixel/addons/transition/GraphicTransTileDiamond.h>
#endif
#ifndef INCLUDED_flixel_addons_transition_TransitionData
#include <flixel/addons/transition/TransitionData.h>
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
#ifndef INCLUDED_flixel_animation_FlxAnimationController
#include <flixel/animation/FlxAnimationController.h>
#endif
#ifndef INCLUDED_flixel_graphics_FlxGraphic
#include <flixel/graphics/FlxGraphic.h>
#endif
#ifndef INCLUDED_flixel_graphics_frames_FlxAtlasFrames
#include <flixel/graphics/frames/FlxAtlasFrames.h>
#endif
#ifndef INCLUDED_flixel_graphics_frames_FlxFramesCollection
#include <flixel/graphics/frames/FlxFramesCollection.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedSpriteGroup
#include <flixel/group/FlxTypedSpriteGroup.h>
#endif
#ifndef INCLUDED_flixel_input_FlxBaseKeyList
#include <flixel/input/FlxBaseKeyList.h>
#endif
#ifndef INCLUDED_flixel_input_FlxInput
#include <flixel/input/FlxInput.h>
#endif
#ifndef INCLUDED_flixel_input_FlxKeyManager
#include <flixel/input/FlxKeyManager.h>
#endif
#ifndef INCLUDED_flixel_input_FlxPointer
#include <flixel/input/FlxPointer.h>
#endif
#ifndef INCLUDED_flixel_input_IFlxInput
#include <flixel/input/IFlxInput.h>
#endif
#ifndef INCLUDED_flixel_input_IFlxInputManager
#include <flixel/input/IFlxInputManager.h>
#endif
#ifndef INCLUDED_flixel_input_gamepad_FlxGamepad
#include <flixel/input/gamepad/FlxGamepad.h>
#endif
#ifndef INCLUDED_flixel_input_gamepad_FlxGamepadButton
#include <flixel/input/gamepad/FlxGamepadButton.h>
#endif
#ifndef INCLUDED_flixel_input_gamepad_FlxGamepadManager
#include <flixel/input/gamepad/FlxGamepadManager.h>
#endif
#ifndef INCLUDED_flixel_input_gamepad_lists_FlxBaseGamepadList
#include <flixel/input/gamepad/lists/FlxBaseGamepadList.h>
#endif
#ifndef INCLUDED_flixel_input_gamepad_lists_FlxGamepadButtonList
#include <flixel/input/gamepad/lists/FlxGamepadButtonList.h>
#endif
#ifndef INCLUDED_flixel_input_gamepad_mappings_FlxGamepadMapping
#include <flixel/input/gamepad/mappings/FlxGamepadMapping.h>
#endif
#ifndef INCLUDED_flixel_input_keyboard_FlxKeyList
#include <flixel/input/keyboard/FlxKeyList.h>
#endif
#ifndef INCLUDED_flixel_input_keyboard_FlxKeyboard
#include <flixel/input/keyboard/FlxKeyboard.h>
#endif
#ifndef INCLUDED_flixel_input_mouse_FlxMouse
#include <flixel/input/mouse/FlxMouse.h>
#endif
#ifndef INCLUDED_flixel_math_FlxPoint
#include <flixel/math/FlxPoint.h>
#endif
#ifndef INCLUDED_flixel_math_FlxRandom
#include <flixel/math/FlxRandom.h>
#endif
#ifndef INCLUDED_flixel_math_FlxRect
#include <flixel/math/FlxRect.h>
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
#ifndef INCLUDED_flixel_tweens_FlxEase
#include <flixel/tweens/FlxEase.h>
#endif
#ifndef INCLUDED_flixel_tweens_FlxTween
#include <flixel/tweens/FlxTween.h>
#endif
#ifndef INCLUDED_flixel_tweens_misc_NumTween
#include <flixel/tweens/misc/NumTween.h>
#endif
#ifndef INCLUDED_flixel_tweens_misc_VarTween
#include <flixel/tweens/misc/VarTween.h>
#endif
#ifndef INCLUDED_flixel_util_FlxAxes
#include <flixel/util/FlxAxes.h>
#endif
#ifndef INCLUDED_flixel_util_FlxSave
#include <flixel/util/FlxSave.h>
#endif
#ifndef INCLUDED_flixel_util_FlxTimer
#include <flixel/util/FlxTimer.h>
#endif
#ifndef INCLUDED_flixel_util_FlxTimerManager
#include <flixel/util/FlxTimerManager.h>
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
#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_IntMap
#include <haxe/ds/IntMap.h>
#endif
#ifndef INCLUDED_io_newgrounds_NG
#include <io/newgrounds/NG.h>
#endif
#ifndef INCLUDED_io_newgrounds_NGLite
#include <io/newgrounds/NGLite.h>
#endif
#ifndef INCLUDED_io_newgrounds_objects_Medal
#include <io/newgrounds/objects/Medal.h>
#endif
#ifndef INCLUDED_io_newgrounds_objects_Object
#include <io/newgrounds/objects/Object.h>
#endif
#ifndef INCLUDED_lime_app_Application
#include <lime/app/Application.h>
#endif
#ifndef INCLUDED_lime_app_IModule
#include <lime/app/IModule.h>
#endif
#ifndef INCLUDED_lime_app_Module
#include <lime/app/Module.h>
#endif
#ifndef INCLUDED_lime_app__Event_Int_Void
#include <lime/app/_Event_Int_Void.h>
#endif
#ifndef INCLUDED_lime_utils_Assets
#include <lime/utils/Assets.h>
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
#ifndef INCLUDED_openfl_media_SoundChannel
#include <openfl/media/SoundChannel.h>
#endif
#ifndef INCLUDED_openfl_utils_Assets
#include <openfl/utils/Assets.h>
#endif
#ifndef INCLUDED_sys_FileSystem
#include <sys/FileSystem.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_a55214e0452daa02_36_new,"TitleState","new",0x3b23deeb,"TitleState.new","TitleState.hx",36,0xd132a6e5)
HX_LOCAL_STACK_FRAME(_hx_pos_a55214e0452daa02_86_create,"TitleState","create",0x801cc151,"TitleState.create","TitleState.hx",86,0xd132a6e5)
HX_LOCAL_STACK_FRAME(_hx_pos_a55214e0452daa02_94_create,"TitleState","create",0x801cc151,"TitleState.create","TitleState.hx",94,0xd132a6e5)
HX_LOCAL_STACK_FRAME(_hx_pos_a55214e0452daa02_52_create,"TitleState","create",0x801cc151,"TitleState.create","TitleState.hx",52,0xd132a6e5)
HX_LOCAL_STACK_FRAME(_hx_pos_a55214e0452daa02_107_startIntro,"TitleState","startIntro",0x6a094b7f,"TitleState.startIntro","TitleState.hx",107,0xd132a6e5)
static const int _hx_array_data_8ca18d79_5[] = {
	(int)30,(int)0,(int)1,(int)2,(int)3,(int)4,(int)5,(int)6,(int)7,(int)8,(int)9,(int)10,(int)11,(int)12,(int)13,(int)14,
};
static const int _hx_array_data_8ca18d79_6[] = {
	(int)15,(int)16,(int)17,(int)18,(int)19,(int)20,(int)21,(int)22,(int)23,(int)24,(int)25,(int)26,(int)27,(int)28,(int)29,
};
HX_LOCAL_STACK_FRAME(_hx_pos_a55214e0452daa02_212_getIntroTextShit,"TitleState","getIntroTextShit",0x5dcf15b8,"TitleState.getIntroTextShit","TitleState.hx",212,0xd132a6e5)
HX_LOCAL_STACK_FRAME(_hx_pos_a55214e0452daa02_231_update,"TitleState","update",0x8b12e05e,"TitleState.update","TitleState.hx",231,0xd132a6e5)
HX_LOCAL_STACK_FRAME(_hx_pos_a55214e0452daa02_287_update,"TitleState","update",0x8b12e05e,"TitleState.update","TitleState.hx",287,0xd132a6e5)
HX_LOCAL_STACK_FRAME(_hx_pos_a55214e0452daa02_302_createCoolText,"TitleState","createCoolText",0x83610287,"TitleState.createCoolText","TitleState.hx",302,0xd132a6e5)
HX_LOCAL_STACK_FRAME(_hx_pos_a55214e0452daa02_313_addMoreText,"TitleState","addMoreText",0xcf420fae,"TitleState.addMoreText","TitleState.hx",313,0xd132a6e5)
HX_LOCAL_STACK_FRAME(_hx_pos_a55214e0452daa02_347_deleteCoolText,"TitleState","deleteCoolText",0x8afda2b6,"TitleState.deleteCoolText","TitleState.hx",347,0xd132a6e5)
HX_LOCAL_STACK_FRAME(_hx_pos_a55214e0452daa02_362_beatHit,"TitleState","beatHit",0xfba69a88,"TitleState.beatHit","TitleState.hx",362,0xd132a6e5)
static const ::String _hx_array_data_8ca18d79_19[] = {
	HX_("ninjamuffin99",f7,4c,e5,00),HX_("phantomArcade",bd,dd,c2,a7),HX_("kawaisprite",0e,de,66,45),HX_("evilsk8er",f9,15,51,51),
};
static const ::String _hx_array_data_8ca18d79_20[] = {
	HX_("FeeshX and Feeshmora",20,73,b7,64),
};
static const ::String _hx_array_data_8ca18d79_21[] = {
	HX_("Feeshy",de,03,8e,67),
};
HX_LOCAL_STACK_FRAME(_hx_pos_a55214e0452daa02_428_skipIntro,"TitleState","skipIntro",0xc9924038,"TitleState.skipIntro","TitleState.hx",428,0xd132a6e5)
HX_LOCAL_STACK_FRAME(_hx_pos_a55214e0452daa02_446_sortByShit,"TitleState","sortByShit",0xfe58a80a,"TitleState.sortByShit","TitleState.hx",446,0xd132a6e5)
HX_LOCAL_STACK_FRAME(_hx_pos_a55214e0452daa02_38_boot,"TitleState","boot",0x7c582f47,"TitleState.boot","TitleState.hx",38,0xd132a6e5)

void TitleState_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_a55214e0452daa02_36_new)
HXLINE( 424)		this->skippedIntro = false;
HXLINE( 228)		this->transitioning = false;
HXLINE( 103)		this->danceLeft = false;
HXLINE(  49)		this->credits = ( (::Array< ::String >)( ::Dynamic(::Paths_obj::get_modJSON()->__Field(HX_("title_menu",e6,04,22,7a),::hx::paccDynamic))->__Field(HX_("mod_creators",a4,10,9b,6f),::hx::paccDynamic)) );
HXLINE(  36)		super::__construct();
            	}

Dynamic TitleState_obj::__CreateEmpty() { return new TitleState_obj; }

void *TitleState_obj::_hx_vtable = 0;

Dynamic TitleState_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< TitleState_obj > _hx_result = new TitleState_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool TitleState_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x2f064378) {
		if (inClassId<=(int)0x23a57bae) {
			if (inClassId<=(int)0x22c6bd01) {
				return inClassId==(int)0x00000001 || inClassId==(int)0x22c6bd01;
			} else {
				return inClassId==(int)0x23a57bae;
			}
		} else {
			return inClassId==(int)0x29d19794 || inClassId==(int)0x2f064378;
		}
	} else {
		if (inClassId<=(int)0x7c795c9f) {
			if (inClassId<=(int)0x62817b24) {
				return inClassId==(int)0x3f706236 || inClassId==(int)0x62817b24;
			} else {
				return inClassId==(int)0x7c795c9f;
			}
		} else {
			return inClassId==(int)0x7ccf8994;
		}
	}
}

void TitleState_obj::create(){
            		HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_0, ::TitleState,_gthis) HXARGC(1)
            		void _hx_run( ::flixel::util::FlxTimer tmr){
            			HX_GC_STACKFRAME(&_hx_pos_a55214e0452daa02_86_create)
HXLINE(  86)			_gthis->startIntro();
            		}
            		HX_END_LOCAL_FUNC1((void))

            		HX_BEGIN_LOCAL_FUNC_S0(::hx::LocalFunc,_hx_Closure_1) HXARGC(1)
            		void _hx_run(int exitCode){
            			HX_GC_STACKFRAME(&_hx_pos_a55214e0452daa02_94_create)
HXLINE(  94)			::DiscordClient_obj::shutdown();
            		}
            		HX_END_LOCAL_FUNC1((void))

            	HX_GC_STACKFRAME(&_hx_pos_a55214e0452daa02_52_create)
HXDLIN(  52)		 ::TitleState _gthis = ::hx::ObjectPtr<OBJ_>(this);
HXLINE(  53)		::flixel::FlxG_obj::save->bind(HX_("funkin",31,b2,4f,6f),HX_("ninjamuffin99",f7,4c,e5,00));
HXLINE(  55)		this->credits->sort(this->sortByShit_dyn());
HXLINE(  63)		::PlayerSettings_obj::init();
HXLINE(  67)		this->userIcon =  ::flixel::group::FlxTypedSpriteGroup_obj::__alloc( HX_CTX ,null(),null(),null());
HXLINE(  68)		this->userName =  ::flixel::group::FlxTypedGroup_obj::__alloc( HX_CTX ,null());
HXLINE(  70)		::NGio_obj::noLogin(::APIStuff_obj::API);
HXLINE(  77)		::Highscore_obj::load();
HXLINE(  84)		 ::flixel::util::FlxTimer_obj::__alloc( HX_CTX ,null())->start(1, ::Dynamic(new _hx_Closure_0(_gthis)),null());
HXLINE(  91)		::DiscordClient_obj::initialize();
HXLINE(  93)		::lime::app::Application_obj::current->onExit->add( ::Dynamic(new _hx_Closure_1()),null(),null());
HXLINE(  98)		this->super::create();
            	}


void TitleState_obj::startIntro(){
            	HX_GC_STACKFRAME(&_hx_pos_a55214e0452daa02_107_startIntro)
HXLINE( 108)		if (!(::TitleState_obj::initialized)) {
HXLINE( 110)			 ::flixel::graphics::FlxGraphic diamond = ::flixel::graphics::FlxGraphic_obj::fromClass(::hx::ClassOf< ::flixel::addons::transition::GraphicTransTileDiamond >(),null(),null(),null());
HXLINE( 111)			diamond->persist = true;
HXLINE( 112)			diamond->set_destroyOnNoUse(false);
HXLINE( 114)			 ::flixel::math::FlxPoint _hx_tmp =  ::flixel::math::FlxPoint_obj::__alloc( HX_CTX ,0,-1);
HXDLIN( 114)			::flixel::addons::transition::FlxTransitionableState_obj::defaultTransIn =  ::flixel::addons::transition::TransitionData_obj::__alloc( HX_CTX ,HX_("fade",7c,b5,b5,43),-16777216,((Float)0.7),_hx_tmp, ::Dynamic(::hx::Anon_obj::Create(3)
            				->setFixed(0,HX_("width",06,b6,62,ca),32)
            				->setFixed(1,HX_("height",e7,07,4c,02),32)
            				->setFixed(2,HX_("asset",f0,69,39,26),diamond)), ::flixel::math::FlxRect_obj::__alloc( HX_CTX ,-200,-200,(( (Float)(::flixel::FlxG_obj::width) ) * ((Float)1.4)),(( (Float)(::flixel::FlxG_obj::height) ) * ((Float)1.4))));
HXLINE( 116)			 ::flixel::math::FlxPoint _hx_tmp1 =  ::flixel::math::FlxPoint_obj::__alloc( HX_CTX ,0,1);
HXDLIN( 116)			::flixel::addons::transition::FlxTransitionableState_obj::defaultTransOut =  ::flixel::addons::transition::TransitionData_obj::__alloc( HX_CTX ,HX_("tiles",85,fd,34,10),-16777216,((Float)0.7),_hx_tmp1, ::Dynamic(::hx::Anon_obj::Create(3)
            				->setFixed(0,HX_("width",06,b6,62,ca),32)
            				->setFixed(1,HX_("height",e7,07,4c,02),32)
            				->setFixed(2,HX_("asset",f0,69,39,26),diamond)), ::flixel::math::FlxRect_obj::__alloc( HX_CTX ,-200,-200,(( (Float)(::flixel::FlxG_obj::width) ) * ((Float)1.4)),(( (Float)(::flixel::FlxG_obj::height) ) * ((Float)1.4))));
HXLINE( 119)			this->transIn = ::flixel::addons::transition::FlxTransitionableState_obj::defaultTransIn;
HXLINE( 120)			this->transOut = ::flixel::addons::transition::FlxTransitionableState_obj::defaultTransOut;
HXLINE( 130)			 ::flixel::_hx_system::frontEnds::SoundFrontEnd _hx_tmp2 = ::flixel::FlxG_obj::sound;
HXDLIN( 130)			::String library = null();
HXDLIN( 130)			::String _hx_tmp3;
HXDLIN( 130)			if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("music/",ea,bf,1b,3f) + HX_("freakyMenu",15,c9,93,86)) + HX_(".",2e,00,00,00)) + HX_("ogg",4f,94,54,00)),HX_("MUSIC",85,08,49,8e),library),null())) {
HXLINE( 130)				_hx_tmp3 = ::Paths_obj::getPath((((HX_("music/",ea,bf,1b,3f) + HX_("freakyMenu",15,c9,93,86)) + HX_(".",2e,00,00,00)) + HX_("ogg",4f,94,54,00)),HX_("MUSIC",85,08,49,8e),library);
            			}
            			else {
HXLINE( 130)				HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate music - ",82,28,df,2c) + HX_("freakyMenu",15,c9,93,86))));
            			}
HXDLIN( 130)			_hx_tmp2->playMusic(_hx_tmp3,0,null(),null());
HXLINE( 132)			{
HXLINE( 132)				 ::flixel::_hx_system::FlxSound _this = ::flixel::FlxG_obj::sound->music;
HXDLIN( 132)				 ::Dynamic onComplete = null();
HXDLIN( 132)				if (::hx::IsNull( _this->_channel )) {
HXLINE( 132)					_this->play(null(),null(),null());
            				}
HXDLIN( 132)				if (::hx::IsNotNull( _this->fadeTween )) {
HXLINE( 132)					_this->fadeTween->cancel();
            				}
HXDLIN( 132)				_this->fadeTween = ::flixel::tweens::FlxTween_obj::num(( (Float)(0) ),((Float)0.7),4, ::Dynamic(::hx::Anon_obj::Create(1)
            					->setFixed(0,HX_("onComplete",f8,d4,7e,5d),onComplete)),_this->volumeTween_dyn());
            			}
            		}
HXLINE( 135)		::Conductor_obj::changeBPM(102);
HXLINE( 136)		this->persistentUpdate = true;
HXLINE( 138)		 ::flixel::FlxSprite bg =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,null(),null(),null())->makeGraphic(::flixel::FlxG_obj::width,::flixel::FlxG_obj::height,-16777216,null(),null());
HXLINE( 142)		this->add(bg);
HXLINE( 144)		this->logoBl =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,-150,-100,null());
HXLINE( 145)		 ::flixel::FlxSprite _hx_tmp = this->logoBl;
HXDLIN( 145)		::String library = null();
HXDLIN( 145)		 ::Dynamic cache = null();
HXDLIN( 145)		::String cacheFile = HX_("",00,00,00,00);
HXDLIN( 145)		if (( (bool)(cache) )) {
HXLINE( 145)			cacheFile = HX_("cache/",ad,5f,f2,b0);
            		}
HXDLIN( 145)		if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + HX_("logoBumpin",26,cb,02,ab)))) {
HXLINE( 145)			cacheFile = HX_("",00,00,00,00);
            		}
HXDLIN( 145)		 ::flixel::graphics::frames::FlxAtlasFrames _hx_tmp1;
HXDLIN( 145)		::String cacheFile1 = HX_("",00,00,00,00);
HXDLIN( 145)		if (( (bool)(cache) )) {
HXLINE( 145)			cacheFile1 = HX_("cache/",ad,5f,f2,b0);
            		}
HXDLIN( 145)		if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + HX_("logoBumpin",26,cb,02,ab)))) {
HXLINE( 145)			cacheFile1 = HX_("",00,00,00,00);
            		}
HXDLIN( 145)		if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile1) + HX_("logoBumpin",26,cb,02,ab)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library),null())) {
HXLINE( 145)			if (::hx::IsNotNull( ::Paths_obj::ifImageCached((cacheFile + HX_("logoBumpin",26,cb,02,ab))) )) {
HXLINE( 145)				 ::flixel::graphics::FlxGraphic _hx_tmp = ::Paths_obj::ifImageCached((cacheFile + HX_("logoBumpin",26,cb,02,ab)));
HXDLIN( 145)				_hx_tmp1 = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSparrow(_hx_tmp,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + HX_("logoBumpin",26,cb,02,ab)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library));
            			}
            			else {
HXLINE( 145)				::String _hx_tmp = ::Paths_obj::image((cacheFile + HX_("logoBumpin",26,cb,02,ab)),library);
HXDLIN( 145)				_hx_tmp1 = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSparrow(_hx_tmp,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + HX_("logoBumpin",26,cb,02,ab)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library));
            			}
            		}
            		else {
HXLINE( 145)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate asset - ",17,30,f9,e8) + ::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + HX_("logoBumpin",26,cb,02,ab)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library))));
            		}
HXDLIN( 145)		_hx_tmp->set_frames(_hx_tmp1);
HXLINE( 146)		this->logoBl->set_antialiasing(true);
HXLINE( 147)		this->logoBl->animation->addByPrefix(HX_("bump",f6,0f,20,41),HX_("logo bumpin",70,a1,0b,72),24,null(),null(),null());
HXLINE( 148)		this->logoBl->animation->play(HX_("bump",f6,0f,20,41),null(),null(),null());
HXLINE( 149)		this->logoBl->updateHitbox();
HXLINE( 153)		this->gfDance =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,(( (Float)(::flixel::FlxG_obj::width) ) * ((Float)0.4)),(( (Float)(::flixel::FlxG_obj::height) ) * ((Float)0.07)),null());
HXLINE( 154)		 ::flixel::FlxSprite _hx_tmp2 = this->gfDance;
HXDLIN( 154)		::String library1 = null();
HXDLIN( 154)		 ::Dynamic cache1 = null();
HXDLIN( 154)		::String cacheFile2 = HX_("",00,00,00,00);
HXDLIN( 154)		if (( (bool)(cache1) )) {
HXLINE( 154)			cacheFile2 = HX_("cache/",ad,5f,f2,b0);
            		}
HXDLIN( 154)		if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + HX_("gfDanceTitle",64,64,d2,7b)))) {
HXLINE( 154)			cacheFile2 = HX_("",00,00,00,00);
            		}
HXDLIN( 154)		 ::flixel::graphics::frames::FlxAtlasFrames _hx_tmp3;
HXDLIN( 154)		::String cacheFile3 = HX_("",00,00,00,00);
HXDLIN( 154)		if (( (bool)(cache1) )) {
HXLINE( 154)			cacheFile3 = HX_("cache/",ad,5f,f2,b0);
            		}
HXDLIN( 154)		if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + HX_("gfDanceTitle",64,64,d2,7b)))) {
HXLINE( 154)			cacheFile3 = HX_("",00,00,00,00);
            		}
HXDLIN( 154)		if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile3) + HX_("gfDanceTitle",64,64,d2,7b)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library1),null())) {
HXLINE( 154)			if (::hx::IsNotNull( ::Paths_obj::ifImageCached((cacheFile2 + HX_("gfDanceTitle",64,64,d2,7b))) )) {
HXLINE( 154)				 ::flixel::graphics::FlxGraphic _hx_tmp = ::Paths_obj::ifImageCached((cacheFile2 + HX_("gfDanceTitle",64,64,d2,7b)));
HXDLIN( 154)				_hx_tmp3 = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSparrow(_hx_tmp,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile2) + HX_("gfDanceTitle",64,64,d2,7b)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library1));
            			}
            			else {
HXLINE( 154)				::String _hx_tmp = ::Paths_obj::image((cacheFile2 + HX_("gfDanceTitle",64,64,d2,7b)),library1);
HXDLIN( 154)				_hx_tmp3 = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSparrow(_hx_tmp,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile2) + HX_("gfDanceTitle",64,64,d2,7b)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library1));
            			}
            		}
            		else {
HXLINE( 154)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate asset - ",17,30,f9,e8) + ::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile2) + HX_("gfDanceTitle",64,64,d2,7b)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library1))));
            		}
HXDLIN( 154)		_hx_tmp2->set_frames(_hx_tmp3);
HXLINE( 155)		this->gfDance->animation->addByIndices(HX_("danceLeft",da,cc,f9,df),HX_("gfDance",94,88,3a,eb),::Array_obj< int >::fromData( _hx_array_data_8ca18d79_5,16),HX_("",00,00,00,00),24,false,null(),null());
HXLINE( 156)		this->gfDance->animation->addByIndices(HX_("danceRight",a9,7f,a6,91),HX_("gfDance",94,88,3a,eb),::Array_obj< int >::fromData( _hx_array_data_8ca18d79_6,15),HX_("",00,00,00,00),24,false,null(),null());
HXLINE( 157)		this->gfDance->set_antialiasing(true);
HXLINE( 158)		this->add(this->gfDance);
HXLINE( 159)		this->add(this->logoBl);
HXLINE( 161)		this->titleText =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,100,(( (Float)(::flixel::FlxG_obj::height) ) * ((Float)0.8)),null());
HXLINE( 162)		 ::flixel::FlxSprite _hx_tmp4 = this->titleText;
HXDLIN( 162)		::String library2 = null();
HXDLIN( 162)		 ::Dynamic cache2 = null();
HXDLIN( 162)		::String cacheFile4 = HX_("",00,00,00,00);
HXDLIN( 162)		if (( (bool)(cache2) )) {
HXLINE( 162)			cacheFile4 = HX_("cache/",ad,5f,f2,b0);
            		}
HXDLIN( 162)		if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + HX_("titleEnter",60,80,6b,82)))) {
HXLINE( 162)			cacheFile4 = HX_("",00,00,00,00);
            		}
HXDLIN( 162)		 ::flixel::graphics::frames::FlxAtlasFrames _hx_tmp5;
HXDLIN( 162)		::String cacheFile5 = HX_("",00,00,00,00);
HXDLIN( 162)		if (( (bool)(cache2) )) {
HXLINE( 162)			cacheFile5 = HX_("cache/",ad,5f,f2,b0);
            		}
HXDLIN( 162)		if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + HX_("titleEnter",60,80,6b,82)))) {
HXLINE( 162)			cacheFile5 = HX_("",00,00,00,00);
            		}
HXDLIN( 162)		if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile5) + HX_("titleEnter",60,80,6b,82)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library2),null())) {
HXLINE( 162)			if (::hx::IsNotNull( ::Paths_obj::ifImageCached((cacheFile4 + HX_("titleEnter",60,80,6b,82))) )) {
HXLINE( 162)				 ::flixel::graphics::FlxGraphic _hx_tmp = ::Paths_obj::ifImageCached((cacheFile4 + HX_("titleEnter",60,80,6b,82)));
HXDLIN( 162)				_hx_tmp5 = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSparrow(_hx_tmp,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile4) + HX_("titleEnter",60,80,6b,82)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library2));
            			}
            			else {
HXLINE( 162)				::String _hx_tmp = ::Paths_obj::image((cacheFile4 + HX_("titleEnter",60,80,6b,82)),library2);
HXDLIN( 162)				_hx_tmp5 = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSparrow(_hx_tmp,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile4) + HX_("titleEnter",60,80,6b,82)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library2));
            			}
            		}
            		else {
HXLINE( 162)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate asset - ",17,30,f9,e8) + ::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile4) + HX_("titleEnter",60,80,6b,82)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library2))));
            		}
HXDLIN( 162)		_hx_tmp4->set_frames(_hx_tmp5);
HXLINE( 163)		this->titleText->animation->addByPrefix(HX_("idle",14,a7,b3,45),HX_("Press Enter to Begin",e9,79,2c,83),24,null(),null(),null());
HXLINE( 164)		this->titleText->animation->addByPrefix(HX_("press",83,53,88,c8),HX_("ENTER PRESSED",5a,47,9f,63),24,null(),null(),null());
HXLINE( 165)		this->titleText->set_antialiasing(true);
HXLINE( 166)		this->titleText->animation->play(HX_("idle",14,a7,b3,45),null(),null(),null());
HXLINE( 167)		this->titleText->updateHitbox();
HXLINE( 169)		this->add(this->titleText);
HXLINE( 171)		 ::flixel::FlxSprite logo =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,null(),null(),null());
HXDLIN( 171)		 ::flixel::FlxSprite logo1 = logo->loadGraphic(::Paths_obj::image(HX_("logo",6b,9f,b7,47),null()),null(),null(),null(),null(),null());
HXLINE( 172)		{
HXLINE( 172)			 ::flixel::util::FlxAxes axes = ::flixel::util::FlxAxes_obj::XY_dyn();
HXDLIN( 172)			bool _hx_tmp6;
HXDLIN( 172)			switch((int)(axes->_hx_getIndex())){
            				case (int)0: case (int)2: {
HXLINE( 172)					_hx_tmp6 = true;
            				}
            				break;
            				default:{
HXLINE( 172)					_hx_tmp6 = false;
            				}
            			}
HXDLIN( 172)			if (_hx_tmp6) {
HXLINE( 172)				int _hx_tmp = ::flixel::FlxG_obj::width;
HXDLIN( 172)				logo1->set_x(((( (Float)(_hx_tmp) ) - logo1->get_width()) / ( (Float)(2) )));
            			}
HXDLIN( 172)			bool _hx_tmp7;
HXDLIN( 172)			switch((int)(axes->_hx_getIndex())){
            				case (int)1: case (int)2: {
HXLINE( 172)					_hx_tmp7 = true;
            				}
            				break;
            				default:{
HXLINE( 172)					_hx_tmp7 = false;
            				}
            			}
HXDLIN( 172)			if (_hx_tmp7) {
HXLINE( 172)				int _hx_tmp = ::flixel::FlxG_obj::height;
HXDLIN( 172)				logo1->set_y(((( (Float)(_hx_tmp) ) - logo1->get_height()) / ( (Float)(2) )));
            			}
            		}
HXLINE( 173)		logo1->set_antialiasing(true);
HXLINE( 179)		this->credGroup =  ::flixel::group::FlxTypedGroup_obj::__alloc( HX_CTX ,null());
HXLINE( 180)		this->add(this->credGroup);
HXLINE( 181)		this->textGroup =  ::flixel::group::FlxTypedGroup_obj::__alloc( HX_CTX ,null());
HXLINE( 183)		this->blackScreen =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,null(),null(),null())->makeGraphic(::flixel::FlxG_obj::width,::flixel::FlxG_obj::height,-16777216,null(),null());
HXLINE( 184)		this->credGroup->add(this->blackScreen).StaticCast<  ::flixel::FlxBasic >();
HXLINE( 186)		this->credTextShit =  ::Alphabet_obj::__alloc( HX_CTX ,( (Float)(0) ),( (Float)(0) ),HX_("ninjamuffin99\nPhantomArcade\nkawaisprite\nevilsk8er",fd,7d,e3,3b),true,null(),null());
HXLINE( 187)		{
HXLINE( 187)			 ::Alphabet _this = this->credTextShit;
HXDLIN( 187)			 ::flixel::util::FlxAxes axes1 = ::flixel::util::FlxAxes_obj::XY_dyn();
HXDLIN( 187)			bool _hx_tmp8;
HXDLIN( 187)			switch((int)(axes1->_hx_getIndex())){
            				case (int)0: case (int)2: {
HXLINE( 187)					_hx_tmp8 = true;
            				}
            				break;
            				default:{
HXLINE( 187)					_hx_tmp8 = false;
            				}
            			}
HXDLIN( 187)			if (_hx_tmp8) {
HXLINE( 187)				int _hx_tmp = ::flixel::FlxG_obj::width;
HXDLIN( 187)				_this->set_x(((( (Float)(_hx_tmp) ) - _this->get_width()) / ( (Float)(2) )));
            			}
HXDLIN( 187)			bool _hx_tmp9;
HXDLIN( 187)			switch((int)(axes1->_hx_getIndex())){
            				case (int)1: case (int)2: {
HXLINE( 187)					_hx_tmp9 = true;
            				}
            				break;
            				default:{
HXLINE( 187)					_hx_tmp9 = false;
            				}
            			}
HXDLIN( 187)			if (_hx_tmp9) {
HXLINE( 187)				int _hx_tmp = ::flixel::FlxG_obj::height;
HXDLIN( 187)				_this->set_y(((( (Float)(_hx_tmp) ) - _this->get_height()) / ( (Float)(2) )));
            			}
            		}
HXLINE( 191)		this->credTextShit->set_visible(false);
HXLINE( 193)		 ::flixel::FlxSprite _hx_tmp10 =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,0,(( (Float)(::flixel::FlxG_obj::height) ) * ((Float)0.52)),null());
HXDLIN( 193)		this->ngSpr = _hx_tmp10->loadGraphic(::Paths_obj::image(HX_("newgrounds_logo",1e,5c,8d,a6),null()),null(),null(),null(),null(),null());
HXLINE( 194)		this->add(this->ngSpr);
HXLINE( 195)		this->ngSpr->set_visible(false);
HXLINE( 196)		 ::flixel::FlxSprite _hx_tmp11 = this->ngSpr;
HXDLIN( 196)		_hx_tmp11->setGraphicSize(::Std_obj::_hx_int((this->ngSpr->get_width() * ((Float)0.8))),null());
HXLINE( 197)		this->ngSpr->updateHitbox();
HXLINE( 198)		{
HXLINE( 198)			 ::flixel::FlxSprite _this1 = this->ngSpr;
HXDLIN( 198)			 ::flixel::util::FlxAxes axes2 = ::flixel::util::FlxAxes_obj::X_dyn();
HXDLIN( 198)			if (::hx::IsNull( axes2 )) {
HXLINE( 198)				axes2 = ::flixel::util::FlxAxes_obj::XY_dyn();
            			}
HXDLIN( 198)			bool _hx_tmp12;
HXDLIN( 198)			switch((int)(axes2->_hx_getIndex())){
            				case (int)0: case (int)2: {
HXLINE( 198)					_hx_tmp12 = true;
            				}
            				break;
            				default:{
HXLINE( 198)					_hx_tmp12 = false;
            				}
            			}
HXDLIN( 198)			if (_hx_tmp12) {
HXLINE( 198)				int _hx_tmp = ::flixel::FlxG_obj::width;
HXDLIN( 198)				_this1->set_x(((( (Float)(_hx_tmp) ) - _this1->get_width()) / ( (Float)(2) )));
            			}
HXDLIN( 198)			bool _hx_tmp13;
HXDLIN( 198)			switch((int)(axes2->_hx_getIndex())){
            				case (int)1: case (int)2: {
HXLINE( 198)					_hx_tmp13 = true;
            				}
            				break;
            				default:{
HXLINE( 198)					_hx_tmp13 = false;
            				}
            			}
HXDLIN( 198)			if (_hx_tmp13) {
HXLINE( 198)				int _hx_tmp = ::flixel::FlxG_obj::height;
HXDLIN( 198)				_this1->set_y(((( (Float)(_hx_tmp) ) - _this1->get_height()) / ( (Float)(2) )));
            			}
            		}
HXLINE( 199)		this->ngSpr->set_antialiasing(true);
HXLINE( 201)		::flixel::tweens::FlxTween_obj::tween(this->credTextShit, ::Dynamic(::hx::Anon_obj::Create(1)
            			->setFixed(0,HX_("y",79,00,00,00),(this->credTextShit->y + 20))),((Float)2.9), ::Dynamic(::hx::Anon_obj::Create(2)
            			->setFixed(0,HX_("ease",ee,8b,0c,43),::flixel::tweens::FlxEase_obj::quadInOut_dyn())
            			->setFixed(1,HX_("type",ba,f2,08,4d),4)));
HXLINE( 203)		::flixel::FlxG_obj::mouse->set_visible(false);
HXLINE( 205)		if (::TitleState_obj::initialized) {
HXLINE( 206)			this->skipIntro();
            		}
            		else {
HXLINE( 208)			::TitleState_obj::initialized = true;
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC0(TitleState_obj,startIntro,(void))

::Array< ::Dynamic> TitleState_obj::getIntroTextShit(){
            	HX_STACKFRAME(&_hx_pos_a55214e0452daa02_212_getIntroTextShit)
HXLINE( 213)		::String library = null();
HXDLIN( 213)		::String fullText;
HXDLIN( 213)		if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath(((HX_("data/",c5,0e,88,d4) + HX_("introText",39,69,67,a6)) + HX_(".txt",02,3f,c0,1e)),HX_("TEXT",ad,94,ba,37),library),null())) {
HXLINE( 213)			fullText = ::Paths_obj::getPath(((HX_("data/",c5,0e,88,d4) + HX_("introText",39,69,67,a6)) + HX_(".txt",02,3f,c0,1e)),HX_("TEXT",ad,94,ba,37),library);
            		}
            		else {
HXLINE( 213)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Warning: could not locate text file - ",84,62,2b,42) + HX_("introText",39,69,67,a6))));
            		}
HXDLIN( 213)		::String fullText1 = ::openfl::utils::Assets_obj::getText(fullText);
HXLINE( 215)		::Array< ::String > firstArray = fullText1.split(HX_("\n",0a,00,00,00));
HXLINE( 216)		::Array< ::Dynamic> swagGoodArray = ::Array_obj< ::Dynamic>::__new(0);
HXLINE( 218)		{
HXLINE( 218)			int _g = 0;
HXDLIN( 218)			while((_g < firstArray->length)){
HXLINE( 218)				::String i = firstArray->__get(_g);
HXDLIN( 218)				_g = (_g + 1);
HXLINE( 220)				swagGoodArray->push(i.split(HX_("--",60,27,00,00)));
            			}
            		}
HXLINE( 223)		return swagGoodArray;
            	}


HX_DEFINE_DYNAMIC_FUNC0(TitleState_obj,getIntroTextShit,return )

void TitleState_obj::update(Float elapsed){
            	HX_GC_STACKFRAME(&_hx_pos_a55214e0452daa02_231_update)
HXLINE( 232)		if (::hx::IsNotNull( ::flixel::FlxG_obj::sound->music )) {
HXLINE( 233)			::Conductor_obj::songPosition = ::flixel::FlxG_obj::sound->music->_time;
            		}
HXLINE( 236)		 ::flixel::input::keyboard::FlxKeyList _this = ( ( ::flixel::input::keyboard::FlxKeyList)(::flixel::FlxG_obj::keys->justPressed) );
HXDLIN( 236)		if (_this->keyManager->checkStatusUnsafe(70,_this->status)) {
HXLINE( 238)			::flixel::FlxG_obj::set_fullscreen(!(::flixel::FlxG_obj::get_fullscreen()));
            		}
HXLINE( 241)		if ((this->curBeat >= 2)) {
HXLINE( 242)			 ::flixel::input::keyboard::FlxKeyList _this = ( ( ::flixel::input::keyboard::FlxKeyList)(::flixel::FlxG_obj::keys->justPressed) );
HXDLIN( 242)			this->pressedEnter = _this->keyManager->checkStatusUnsafe(13,_this->status);
            		}
HXLINE( 254)		 ::flixel::input::gamepad::FlxGamepad gamepad = ::flixel::FlxG_obj::gamepads->lastActive;
HXLINE( 256)		if (::hx::IsNotNull( gamepad )) {
HXLINE( 258)			 ::flixel::input::gamepad::lists::FlxGamepadButtonList _this = gamepad->justPressed;
HXDLIN( 258)			int id = 7;
HXDLIN( 258)			 ::flixel::input::gamepad::FlxGamepad _this1 = _this->gamepad;
HXDLIN( 258)			int Status = _this->status;
HXDLIN( 258)			bool _hx_tmp;
HXDLIN( 258)			switch((int)(id)){
            				case (int)-2: {
HXLINE( 258)					_hx_tmp = _this1->anyButton(Status);
            				}
            				break;
            				case (int)-1: {
HXLINE( 258)					_hx_tmp = !(_this1->anyButton(Status));
            				}
            				break;
            				default:{
HXLINE( 258)					int RawID = _this1->mapping->getRawID(id);
HXDLIN( 258)					 ::flixel::input::gamepad::FlxGamepadButton button = _this1->buttons->__get(RawID).StaticCast<  ::flixel::input::gamepad::FlxGamepadButton >();
HXDLIN( 258)					if (::hx::IsNotNull( button )) {
HXLINE( 258)						_hx_tmp = button->hasState(Status);
            					}
            					else {
HXLINE( 258)						_hx_tmp = false;
            					}
            				}
            			}
HXDLIN( 258)			if (_hx_tmp) {
HXLINE( 259)				this->pressedEnter = true;
            			}
            		}
HXLINE( 267)		bool _hx_tmp;
HXDLIN( 267)		bool _hx_tmp1;
HXDLIN( 267)		if (this->pressedEnter) {
HXLINE( 267)			_hx_tmp1 = !(this->transitioning);
            		}
            		else {
HXLINE( 267)			_hx_tmp1 = false;
            		}
HXDLIN( 267)		if (_hx_tmp1) {
HXLINE( 267)			_hx_tmp = this->skippedIntro;
            		}
            		else {
HXLINE( 267)			_hx_tmp = false;
            		}
HXDLIN( 267)		if (_hx_tmp) {
            			HX_BEGIN_LOCAL_FUNC_S0(::hx::LocalFunc,_hx_Closure_0) HXARGC(1)
            			void _hx_run( ::flixel::util::FlxTimer tmr){
            				HX_GC_STACKFRAME(&_hx_pos_a55214e0452daa02_287_update)
HXLINE( 287)				 ::flixel::FlxState nextState =  ::MainMenuState_obj::__alloc( HX_CTX ,true);
HXDLIN( 287)				if (::flixel::FlxG_obj::game->_state->switchTo(nextState)) {
HXLINE( 287)					::flixel::FlxG_obj::game->_requestedState = nextState;
            				}
            			}
            			HX_END_LOCAL_FUNC1((void))

HXLINE( 270)			if (::NGio_obj::isLoggedIn) {
HXLINE( 270)				 ::io::newgrounds::objects::Medal medal = ( ( ::io::newgrounds::objects::Medal)(::io::newgrounds::NG_obj::core->medals->get(60960)) );
HXDLIN( 270)				if (!(( (bool)(medal->_data->__Field(HX_("unlocked",23,34,0e,5c),::hx::paccDynamic)) ))) {
HXLINE( 270)					medal->sendUnlock();
            				}
            			}
HXLINE( 273)			if ((::Date_obj::now()->getDay() == 5)) {
HXLINE( 274)				if (::NGio_obj::isLoggedIn) {
HXLINE( 274)					 ::io::newgrounds::objects::Medal medal = ( ( ::io::newgrounds::objects::Medal)(::io::newgrounds::NG_obj::core->medals->get(61034)) );
HXDLIN( 274)					if (!(( (bool)(medal->_data->__Field(HX_("unlocked",23,34,0e,5c),::hx::paccDynamic)) ))) {
HXLINE( 274)						medal->sendUnlock();
            					}
            				}
            			}
HXLINE( 277)			this->titleText->animation->play(HX_("press",83,53,88,c8),null(),null(),null());
HXLINE( 279)			::flixel::FlxG_obj::camera->flash(-1,1,null(),null());
HXLINE( 280)			 ::flixel::_hx_system::frontEnds::SoundFrontEnd _hx_tmp = ::flixel::FlxG_obj::sound;
HXDLIN( 280)			::String library = null();
HXDLIN( 280)			::String _hx_tmp1;
HXDLIN( 280)			if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("sounds/",eb,02,a5,b6) + HX_("confirmMenu",bf,8e,fe,3c)) + HX_(".",2e,00,00,00)) + HX_("ogg",4f,94,54,00)),HX_("SOUND",af,c4,ba,fe),library),null())) {
HXLINE( 280)				_hx_tmp1 = ::Paths_obj::getPath((((HX_("sounds/",eb,02,a5,b6) + HX_("confirmMenu",bf,8e,fe,3c)) + HX_(".",2e,00,00,00)) + HX_("ogg",4f,94,54,00)),HX_("SOUND",af,c4,ba,fe),library);
            			}
            			else {
HXLINE( 280)				HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate sound - ",98,e2,ed,38) + HX_("confirmMenu",bf,8e,fe,3c))));
            			}
HXDLIN( 280)			_hx_tmp->play(_hx_tmp1,((Float)0.7),null(),null(),null(),null());
HXLINE( 282)			this->transitioning = true;
HXLINE( 285)			 ::flixel::util::FlxTimer_obj::__alloc( HX_CTX ,null())->start(2, ::Dynamic(new _hx_Closure_0()),null());
            		}
HXLINE( 292)		bool _hx_tmp2;
HXDLIN( 292)		if (this->pressedEnter) {
HXLINE( 292)			_hx_tmp2 = !(this->skippedIntro);
            		}
            		else {
HXLINE( 292)			_hx_tmp2 = false;
            		}
HXDLIN( 292)		if (_hx_tmp2) {
HXLINE( 294)			this->skipIntro();
            		}
HXLINE( 297)		this->super::update(elapsed);
            	}


void TitleState_obj::createCoolText(::Array< ::String > textArray){
            	HX_GC_STACKFRAME(&_hx_pos_a55214e0452daa02_302_createCoolText)
HXDLIN( 302)		int _g = 0;
HXDLIN( 302)		int _g1 = textArray->length;
HXDLIN( 302)		while((_g < _g1)){
HXDLIN( 302)			_g = (_g + 1);
HXDLIN( 302)			int i = (_g - 1);
HXLINE( 304)			 ::Alphabet money =  ::Alphabet_obj::__alloc( HX_CTX ,( (Float)(0) ),( (Float)(0) ),textArray->__get(i),true,false,null());
HXLINE( 305)			{
HXLINE( 305)				 ::flixel::util::FlxAxes axes = ::flixel::util::FlxAxes_obj::X_dyn();
HXDLIN( 305)				if (::hx::IsNull( axes )) {
HXLINE( 305)					axes = ::flixel::util::FlxAxes_obj::XY_dyn();
            				}
HXDLIN( 305)				bool _hx_tmp;
HXDLIN( 305)				switch((int)(axes->_hx_getIndex())){
            					case (int)0: case (int)2: {
HXLINE( 305)						_hx_tmp = true;
            					}
            					break;
            					default:{
HXLINE( 305)						_hx_tmp = false;
            					}
            				}
HXDLIN( 305)				if (_hx_tmp) {
HXLINE( 305)					int _hx_tmp = ::flixel::FlxG_obj::width;
HXDLIN( 305)					money->set_x(((( (Float)(_hx_tmp) ) - money->get_width()) / ( (Float)(2) )));
            				}
HXDLIN( 305)				bool _hx_tmp1;
HXDLIN( 305)				switch((int)(axes->_hx_getIndex())){
            					case (int)1: case (int)2: {
HXLINE( 305)						_hx_tmp1 = true;
            					}
            					break;
            					default:{
HXLINE( 305)						_hx_tmp1 = false;
            					}
            				}
HXDLIN( 305)				if (_hx_tmp1) {
HXLINE( 305)					int _hx_tmp = ::flixel::FlxG_obj::height;
HXDLIN( 305)					money->set_y(((( (Float)(_hx_tmp) ) - money->get_height()) / ( (Float)(2) )));
            				}
            			}
HXLINE( 306)			money->set_y((money->y + ((i * 60) + 200)));
HXLINE( 307)			this->credGroup->add(money).StaticCast<  ::flixel::FlxBasic >();
HXLINE( 308)			this->textGroup->add(money).StaticCast<  ::flixel::FlxBasic >();
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(TitleState_obj,createCoolText,(void))

void TitleState_obj::addMoreText(::String text,::Array< ::String > image){
            	HX_GC_STACKFRAME(&_hx_pos_a55214e0452daa02_313_addMoreText)
HXLINE( 314)		 ::Alphabet coolText =  ::Alphabet_obj::__alloc( HX_CTX ,( (Float)(0) ),( (Float)(0) ),text,true,false,null());
HXLINE( 315)		{
HXLINE( 315)			 ::flixel::util::FlxAxes axes = ::flixel::util::FlxAxes_obj::X_dyn();
HXDLIN( 315)			if (::hx::IsNull( axes )) {
HXLINE( 315)				axes = ::flixel::util::FlxAxes_obj::XY_dyn();
            			}
HXDLIN( 315)			bool _hx_tmp;
HXDLIN( 315)			switch((int)(axes->_hx_getIndex())){
            				case (int)0: case (int)2: {
HXLINE( 315)					_hx_tmp = true;
            				}
            				break;
            				default:{
HXLINE( 315)					_hx_tmp = false;
            				}
            			}
HXDLIN( 315)			if (_hx_tmp) {
HXLINE( 315)				int _hx_tmp = ::flixel::FlxG_obj::width;
HXDLIN( 315)				coolText->set_x(((( (Float)(_hx_tmp) ) - coolText->get_width()) / ( (Float)(2) )));
            			}
HXDLIN( 315)			bool _hx_tmp1;
HXDLIN( 315)			switch((int)(axes->_hx_getIndex())){
            				case (int)1: case (int)2: {
HXLINE( 315)					_hx_tmp1 = true;
            				}
            				break;
            				default:{
HXLINE( 315)					_hx_tmp1 = false;
            				}
            			}
HXDLIN( 315)			if (_hx_tmp1) {
HXLINE( 315)				int _hx_tmp = ::flixel::FlxG_obj::height;
HXDLIN( 315)				coolText->set_y(((( (Float)(_hx_tmp) ) - coolText->get_height()) / ( (Float)(2) )));
            			}
            		}
HXLINE( 316)		coolText->set_y((coolText->y + ((this->textGroup->length * 60) + 200)));
HXLINE( 317)		this->credGroup->add(coolText).StaticCast<  ::flixel::FlxBasic >();
HXLINE( 318)		this->textGroup->add(coolText).StaticCast<  ::flixel::FlxBasic >();
HXLINE( 320)		bool _hx_tmp2;
HXDLIN( 320)		if (::hx::IsNotNull( image )) {
HXLINE( 320)			_hx_tmp2 = !(this->skippedIntro);
            		}
            		else {
HXLINE( 320)			_hx_tmp2 = false;
            		}
HXDLIN( 320)		if (_hx_tmp2) {
HXLINE( 321)			{
HXLINE( 321)				int _g = 0;
HXDLIN( 321)				int _g1 = image->length;
HXDLIN( 321)				while((_g < _g1)){
HXLINE( 321)					_g = (_g + 1);
HXDLIN( 321)					int i = (_g - 1);
HXLINE( 322)					 ::flixel::FlxSprite profile =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,0,350,null());
HXDLIN( 322)					 ::flixel::FlxSprite profile1 = profile->loadGraphic(::Paths_obj::image((HX_("credits/",d5,48,ee,de) + image->__get(i)),null()),null(),null(),null(),null(),null());
HXLINE( 323)					profile1->setGraphicSize(200,null());
HXLINE( 324)					profile1->updateHitbox();
HXLINE( 325)					profile1->set_antialiasing(true);
HXLINE( 327)					if ((i >= 1)) {
HXLINE( 328)						profile1->set_x(((Dynamic( this->userIcon->group->members->__get((i - 1))).StaticCast<  ::flixel::FlxSprite >()->get_width() + 30) * ( (Float)(i) )));
            					}
HXLINE( 331)					this->userIcon->add(profile1).StaticCast<  ::flixel::FlxSprite >();
            				}
            			}
HXLINE( 334)			{
HXLINE( 334)				 ::flixel::group::FlxTypedSpriteGroup _this = this->userIcon;
HXDLIN( 334)				 ::flixel::util::FlxAxes axes = ::flixel::util::FlxAxes_obj::X_dyn();
HXDLIN( 334)				if (::hx::IsNull( axes )) {
HXLINE( 334)					axes = ::flixel::util::FlxAxes_obj::XY_dyn();
            				}
HXDLIN( 334)				bool _hx_tmp;
HXDLIN( 334)				switch((int)(axes->_hx_getIndex())){
            					case (int)0: case (int)2: {
HXLINE( 334)						_hx_tmp = true;
            					}
            					break;
            					default:{
HXLINE( 334)						_hx_tmp = false;
            					}
            				}
HXDLIN( 334)				if (_hx_tmp) {
HXLINE( 334)					int _hx_tmp = ::flixel::FlxG_obj::width;
HXDLIN( 334)					_this->set_x(((( (Float)(_hx_tmp) ) - _this->get_width()) / ( (Float)(2) )));
            				}
HXDLIN( 334)				bool _hx_tmp1;
HXDLIN( 334)				switch((int)(axes->_hx_getIndex())){
            					case (int)1: case (int)2: {
HXLINE( 334)						_hx_tmp1 = true;
            					}
            					break;
            					default:{
HXLINE( 334)						_hx_tmp1 = false;
            					}
            				}
HXDLIN( 334)				if (_hx_tmp1) {
HXLINE( 334)					int _hx_tmp = ::flixel::FlxG_obj::height;
HXDLIN( 334)					_this->set_y(((( (Float)(_hx_tmp) ) - _this->get_height()) / ( (Float)(2) )));
            				}
            			}
HXLINE( 335)			this->add(this->userIcon);
HXLINE( 337)			{
HXLINE( 337)				int _g2 = 0;
HXDLIN( 337)				int _g3 = image->length;
HXDLIN( 337)				while((_g2 < _g3)){
HXLINE( 337)					_g2 = (_g2 + 1);
HXDLIN( 337)					int i = (_g2 - 1);
HXLINE( 338)					Float name = Dynamic( this->userIcon->group->members->__get(i)).StaticCast<  ::flixel::FlxSprite >()->x;
HXDLIN( 338)					Float name1 = Dynamic( this->userIcon->group->members->__get(i)).StaticCast<  ::flixel::FlxSprite >()->get_width();
HXDLIN( 338)					Float name2 = (name + (name1 / ( (Float)(image->__get(i).length) )));
HXDLIN( 338)					Float name3 = Dynamic( this->userIcon->group->members->__get(i)).StaticCast<  ::flixel::FlxSprite >()->y;
HXDLIN( 338)					Float name4 = (name3 + (Dynamic( this->userIcon->group->members->__get(i)).StaticCast<  ::flixel::FlxSprite >()->get_width() + 20));
HXDLIN( 338)					 ::flixel::text::FlxText name5 =  ::flixel::text::FlxText_obj::__alloc( HX_CTX ,name2,name4,0,image->__get(i),24,null());
HXLINE( 339)					this->userName->add(name5).StaticCast<  ::flixel::text::FlxText >();
            				}
            			}
HXLINE( 342)			this->add(this->userName);
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC2(TitleState_obj,addMoreText,(void))

void TitleState_obj::deleteCoolText(){
            	HX_STACKFRAME(&_hx_pos_a55214e0452daa02_347_deleteCoolText)
HXLINE( 348)		while((this->textGroup->members->get_length() > 0)){
HXLINE( 350)			this->credGroup->remove(Dynamic( this->textGroup->members->__get(0)).StaticCast<  ::flixel::FlxBasic >(),true).StaticCast<  ::flixel::FlxBasic >();
HXLINE( 351)			this->textGroup->remove(Dynamic( this->textGroup->members->__get(0)).StaticCast<  ::flixel::FlxBasic >(),true).StaticCast<  ::flixel::FlxBasic >();
            		}
HXLINE( 354)		if (::hx::IsNotNull( Dynamic( this->userIcon->group->members->__get(0)).StaticCast<  ::flixel::FlxSprite >() )) {
HXLINE( 355)			this->userIcon->group->clear();
HXLINE( 356)			this->userName->clear();
HXLINE( 357)			this->remove(this->userName,null());
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC0(TitleState_obj,deleteCoolText,(void))

void TitleState_obj::beatHit(){
            	HX_STACKFRAME(&_hx_pos_a55214e0452daa02_362_beatHit)
HXLINE( 363)		this->super::beatHit();
HXLINE( 365)		this->logoBl->animation->play(HX_("bump",f6,0f,20,41),null(),null(),null());
HXLINE( 366)		this->danceLeft = !(this->danceLeft);
HXLINE( 368)		if (this->danceLeft) {
HXLINE( 369)			this->gfDance->animation->play(HX_("danceRight",a9,7f,a6,91),null(),null(),null());
            		}
            		else {
HXLINE( 371)			this->gfDance->animation->play(HX_("danceLeft",da,cc,f9,df),null(),null(),null());
            		}
HXLINE( 375)		switch((int)(this->curBeat)){
            			case (int)1: {
HXLINE( 378)				this->createCoolText(::Array_obj< ::String >::fromData( _hx_array_data_8ca18d79_19,4));
            			}
            			break;
            			case (int)3: {
HXLINE( 381)				this->addMoreText(HX_("present",fb,3a,dc,39),null());
            			}
            			break;
            			case (int)4: {
HXLINE( 385)				this->deleteCoolText();
            			}
            			break;
            			case (int)5: {
HXLINE( 387)				if (( (bool)( ::Dynamic(::Paths_obj::get_modJSON()->__Field(HX_("title_menu",e6,04,22,7a),::hx::paccDynamic))->__Field(HX_("credit_engine_creator",75,3e,38,77),::hx::paccDynamic)) )) {
HXLINE( 388)					this->createCoolText(::Array_obj< ::String >::fromData( _hx_array_data_8ca18d79_20,1));
            				}
            				else {
HXLINE( 390)					this->createCoolText(::Array_obj< ::String >::__new(1)->init(0, ::Dynamic( ::Dynamic(::Paths_obj::get_modJSON()->__Field(HX_("title_menu",e6,04,22,7a),::hx::paccDynamic))->__Field(HX_("waky",38,5c,f2,4e),::hx::paccDynamic))->__GetItem(0)));
            				}
            			}
            			break;
            			case (int)7: {
HXLINE( 392)				if (( (bool)( ::Dynamic(::Paths_obj::get_modJSON()->__Field(HX_("title_menu",e6,04,22,7a),::hx::paccDynamic))->__Field(HX_("credit_engine_creator",75,3e,38,77),::hx::paccDynamic)) )) {
HXLINE( 393)					this->addMoreText(HX_("Made By",42,c9,7f,21),::Array_obj< ::String >::fromData( _hx_array_data_8ca18d79_21,1));
            				}
            				else {
HXLINE( 395)					this->addMoreText(( (::String)( ::Dynamic( ::Dynamic(::Paths_obj::get_modJSON()->__Field(HX_("title_menu",e6,04,22,7a),::hx::paccDynamic))->__Field(HX_("waky",38,5c,f2,4e),::hx::paccDynamic))->__GetItem(1)) ),null());
            				}
            			}
            			break;
            			case (int)8: {
HXLINE( 397)				this->deleteCoolText();
            			}
            			break;
            			case (int)9: {
HXLINE( 399)				if ((this->credits->__get((this->credits->length - 1)).length > 0)) {
HXLINE( 400)					this->deleteCoolText();
HXLINE( 401)					this->addMoreText(HX_("Mod Created By",0d,2a,c4,f7),this->credits);
            				}
            				else {
HXLINE( 403)					this->deleteCoolText();
HXLINE( 404)					this->addMoreText(( (::String)( ::Dynamic( ::Dynamic(::Paths_obj::get_modJSON()->__Field(HX_("title_menu",e6,04,22,7a),::hx::paccDynamic))->__Field(HX_("waky",38,5c,f2,4e),::hx::paccDynamic))->__GetItem(2)) ),null());
            				}
            			}
            			break;
            			case (int)11: {
HXLINE( 408)				this->deleteCoolText();
HXLINE( 409)				::Array< ::Dynamic> _hx_tmp = ( (::Array< ::Dynamic>)( ::Dynamic(::Paths_obj::get_modJSON()->__Field(HX_("title_menu",e6,04,22,7a),::hx::paccDynamic))->__Field(HX_("random_waky",34,2b,6b,d9),::hx::paccDynamic)) );
HXDLIN( 409)				 ::flixel::math::FlxRandom _hx_tmp1 = ::flixel::FlxG_obj::random;
HXDLIN( 409)				this->createCoolText(_hx_tmp->__get(_hx_tmp1->_hx_int(0,(( (::Array< ::Dynamic>)( ::Dynamic(::Paths_obj::get_modJSON()->__Field(HX_("title_menu",e6,04,22,7a),::hx::paccDynamic))->__Field(HX_("random_waky",34,2b,6b,d9),::hx::paccDynamic)) )->length - 1),null())).StaticCast< ::Array< ::String > >());
            			}
            			break;
            			case (int)12: {
HXLINE( 411)				this->deleteCoolText();
HXLINE( 412)				::Array< ::Dynamic> _hx_tmp = ( (::Array< ::Dynamic>)( ::Dynamic(::Paths_obj::get_modJSON()->__Field(HX_("title_menu",e6,04,22,7a),::hx::paccDynamic))->__Field(HX_("random_waky",34,2b,6b,d9),::hx::paccDynamic)) );
HXDLIN( 412)				 ::flixel::math::FlxRandom _hx_tmp1 = ::flixel::FlxG_obj::random;
HXDLIN( 412)				this->createCoolText(_hx_tmp->__get(_hx_tmp1->_hx_int(0,(( (::Array< ::Dynamic>)( ::Dynamic(::Paths_obj::get_modJSON()->__Field(HX_("title_menu",e6,04,22,7a),::hx::paccDynamic))->__Field(HX_("random_waky",34,2b,6b,d9),::hx::paccDynamic)) )->length - 1),null())).StaticCast< ::Array< ::String > >());
            			}
            			break;
            			case (int)13: {
HXLINE( 414)				this->deleteCoolText();
            			}
            			break;
            			case (int)14: {
HXLINE( 417)				::Array< ::Dynamic> _hx_tmp = ( (::Array< ::Dynamic>)( ::Dynamic(::Paths_obj::get_modJSON()->__Field(HX_("title_menu",e6,04,22,7a),::hx::paccDynamic))->__Field(HX_("random_waky",34,2b,6b,d9),::hx::paccDynamic)) );
HXDLIN( 417)				 ::flixel::math::FlxRandom _hx_tmp1 = ::flixel::FlxG_obj::random;
HXDLIN( 417)				this->createCoolText(_hx_tmp->__get(_hx_tmp1->_hx_int(0,(( (::Array< ::Dynamic>)( ::Dynamic(::Paths_obj::get_modJSON()->__Field(HX_("title_menu",e6,04,22,7a),::hx::paccDynamic))->__Field(HX_("random_waky",34,2b,6b,d9),::hx::paccDynamic)) )->length - 1),null())).StaticCast< ::Array< ::String > >());
            			}
            			break;
            			case (int)15: {
HXLINE( 420)				this->skipIntro();
            			}
            			break;
            		}
            	}


void TitleState_obj::skipIntro(){
            	HX_STACKFRAME(&_hx_pos_a55214e0452daa02_428_skipIntro)
HXDLIN( 428)		if (!(this->skippedIntro)) {
HXLINE( 430)			this->remove(this->ngSpr,null());
HXLINE( 432)			::flixel::FlxG_obj::camera->flash(-1,4,null(),null());
HXLINE( 433)			this->remove(this->credGroup,null());
HXLINE( 434)			this->skippedIntro = true;
HXLINE( 436)			if (::hx::IsNotNull( Dynamic( this->userIcon->group->members->__get(0)).StaticCast<  ::flixel::FlxSprite >() )) {
HXLINE( 437)				this->userIcon->group->clear();
HXLINE( 438)				this->userName->clear();
HXLINE( 439)				this->remove(this->userName,null());
HXLINE( 440)				this->remove(this->userIcon,null());
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC0(TitleState_obj,skipIntro,(void))

int TitleState_obj::sortByShit(::String str1,::String str2){
            	HX_STACKFRAME(&_hx_pos_a55214e0452daa02_446_sortByShit)
HXDLIN( 446)		Float Value1 = ( (Float)(str1.length) );
HXDLIN( 446)		Float Value2 = ( (Float)(str2.length) );
HXDLIN( 446)		int result = 0;
HXDLIN( 446)		if ((Value1 < Value2)) {
HXDLIN( 446)			result = -1;
            		}
            		else {
HXDLIN( 446)			if ((Value1 > Value2)) {
HXDLIN( 446)				result = 1;
            			}
            		}
HXDLIN( 446)		return result;
            	}


HX_DEFINE_DYNAMIC_FUNC2(TitleState_obj,sortByShit,return )

bool TitleState_obj::initialized;


::hx::ObjectPtr< TitleState_obj > TitleState_obj::__new() {
	::hx::ObjectPtr< TitleState_obj > __this = new TitleState_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< TitleState_obj > TitleState_obj::__alloc(::hx::Ctx *_hx_ctx) {
	TitleState_obj *__this = (TitleState_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(TitleState_obj), true, "TitleState"));
	*(void **)__this = TitleState_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

TitleState_obj::TitleState_obj()
{
}

void TitleState_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TitleState);
	HX_MARK_MEMBER_NAME(blackScreen,"blackScreen");
	HX_MARK_MEMBER_NAME(credGroup,"credGroup");
	HX_MARK_MEMBER_NAME(credTextShit,"credTextShit");
	HX_MARK_MEMBER_NAME(textGroup,"textGroup");
	HX_MARK_MEMBER_NAME(ngSpr,"ngSpr");
	HX_MARK_MEMBER_NAME(userIcon,"userIcon");
	HX_MARK_MEMBER_NAME(userName,"userName");
	HX_MARK_MEMBER_NAME(credits,"credits");
	HX_MARK_MEMBER_NAME(logoBl,"logoBl");
	HX_MARK_MEMBER_NAME(gfDance,"gfDance");
	HX_MARK_MEMBER_NAME(danceLeft,"danceLeft");
	HX_MARK_MEMBER_NAME(titleText,"titleText");
	HX_MARK_MEMBER_NAME(pressedEnter,"pressedEnter");
	HX_MARK_MEMBER_NAME(transitioning,"transitioning");
	HX_MARK_MEMBER_NAME(skippedIntro,"skippedIntro");
	 ::HelperStates_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void TitleState_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(blackScreen,"blackScreen");
	HX_VISIT_MEMBER_NAME(credGroup,"credGroup");
	HX_VISIT_MEMBER_NAME(credTextShit,"credTextShit");
	HX_VISIT_MEMBER_NAME(textGroup,"textGroup");
	HX_VISIT_MEMBER_NAME(ngSpr,"ngSpr");
	HX_VISIT_MEMBER_NAME(userIcon,"userIcon");
	HX_VISIT_MEMBER_NAME(userName,"userName");
	HX_VISIT_MEMBER_NAME(credits,"credits");
	HX_VISIT_MEMBER_NAME(logoBl,"logoBl");
	HX_VISIT_MEMBER_NAME(gfDance,"gfDance");
	HX_VISIT_MEMBER_NAME(danceLeft,"danceLeft");
	HX_VISIT_MEMBER_NAME(titleText,"titleText");
	HX_VISIT_MEMBER_NAME(pressedEnter,"pressedEnter");
	HX_VISIT_MEMBER_NAME(transitioning,"transitioning");
	HX_VISIT_MEMBER_NAME(skippedIntro,"skippedIntro");
	 ::HelperStates_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val TitleState_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"ngSpr") ) { return ::hx::Val( ngSpr ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return ::hx::Val( create_dyn() ); }
		if (HX_FIELD_EQ(inName,"logoBl") ) { return ::hx::Val( logoBl ); }
		if (HX_FIELD_EQ(inName,"update") ) { return ::hx::Val( update_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"credits") ) { return ::hx::Val( credits ); }
		if (HX_FIELD_EQ(inName,"gfDance") ) { return ::hx::Val( gfDance ); }
		if (HX_FIELD_EQ(inName,"beatHit") ) { return ::hx::Val( beatHit_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"userIcon") ) { return ::hx::Val( userIcon ); }
		if (HX_FIELD_EQ(inName,"userName") ) { return ::hx::Val( userName ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"credGroup") ) { return ::hx::Val( credGroup ); }
		if (HX_FIELD_EQ(inName,"textGroup") ) { return ::hx::Val( textGroup ); }
		if (HX_FIELD_EQ(inName,"danceLeft") ) { return ::hx::Val( danceLeft ); }
		if (HX_FIELD_EQ(inName,"titleText") ) { return ::hx::Val( titleText ); }
		if (HX_FIELD_EQ(inName,"skipIntro") ) { return ::hx::Val( skipIntro_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"startIntro") ) { return ::hx::Val( startIntro_dyn() ); }
		if (HX_FIELD_EQ(inName,"sortByShit") ) { return ::hx::Val( sortByShit_dyn() ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"blackScreen") ) { return ::hx::Val( blackScreen ); }
		if (HX_FIELD_EQ(inName,"addMoreText") ) { return ::hx::Val( addMoreText_dyn() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"credTextShit") ) { return ::hx::Val( credTextShit ); }
		if (HX_FIELD_EQ(inName,"pressedEnter") ) { return ::hx::Val( pressedEnter ); }
		if (HX_FIELD_EQ(inName,"skippedIntro") ) { return ::hx::Val( skippedIntro ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"transitioning") ) { return ::hx::Val( transitioning ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"createCoolText") ) { return ::hx::Val( createCoolText_dyn() ); }
		if (HX_FIELD_EQ(inName,"deleteCoolText") ) { return ::hx::Val( deleteCoolText_dyn() ); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getIntroTextShit") ) { return ::hx::Val( getIntroTextShit_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

bool TitleState_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"initialized") ) { outValue = ( initialized ); return true; }
	}
	return false;
}

::hx::Val TitleState_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"ngSpr") ) { ngSpr=inValue.Cast<  ::flixel::FlxSprite >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"logoBl") ) { logoBl=inValue.Cast<  ::flixel::FlxSprite >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"credits") ) { credits=inValue.Cast< ::Array< ::String > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gfDance") ) { gfDance=inValue.Cast<  ::flixel::FlxSprite >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"userIcon") ) { userIcon=inValue.Cast<  ::flixel::group::FlxTypedSpriteGroup >(); return inValue; }
		if (HX_FIELD_EQ(inName,"userName") ) { userName=inValue.Cast<  ::flixel::group::FlxTypedGroup >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"credGroup") ) { credGroup=inValue.Cast<  ::flixel::group::FlxTypedGroup >(); return inValue; }
		if (HX_FIELD_EQ(inName,"textGroup") ) { textGroup=inValue.Cast<  ::flixel::group::FlxTypedGroup >(); return inValue; }
		if (HX_FIELD_EQ(inName,"danceLeft") ) { danceLeft=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"titleText") ) { titleText=inValue.Cast<  ::flixel::FlxSprite >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"blackScreen") ) { blackScreen=inValue.Cast<  ::flixel::FlxSprite >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"credTextShit") ) { credTextShit=inValue.Cast<  ::Alphabet >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pressedEnter") ) { pressedEnter=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"skippedIntro") ) { skippedIntro=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"transitioning") ) { transitioning=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool TitleState_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"initialized") ) { initialized=ioValue.Cast< bool >(); return true; }
	}
	return false;
}

void TitleState_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("blackScreen",8b,de,f4,5d));
	outFields->push(HX_("credGroup",91,7f,9c,9c));
	outFields->push(HX_("credTextShit",fb,55,c1,3c));
	outFields->push(HX_("textGroup",52,43,e2,32));
	outFields->push(HX_("ngSpr",7c,26,68,9a));
	outFields->push(HX_("userIcon",64,27,78,08));
	outFields->push(HX_("userName",36,b2,c4,0b));
	outFields->push(HX_("credits",1a,0e,5e,13));
	outFields->push(HX_("logoBl",15,ca,6e,5c));
	outFields->push(HX_("gfDance",94,88,3a,eb));
	outFields->push(HX_("danceLeft",da,cc,f9,df));
	outFields->push(HX_("titleText",65,ba,a4,70));
	outFields->push(HX_("pressedEnter",16,3f,a4,df));
	outFields->push(HX_("transitioning",6d,6a,93,94));
	outFields->push(HX_("skippedIntro",9c,44,26,49));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo TitleState_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::flixel::FlxSprite */ ,(int)offsetof(TitleState_obj,blackScreen),HX_("blackScreen",8b,de,f4,5d)},
	{::hx::fsObject /*  ::flixel::group::FlxTypedGroup */ ,(int)offsetof(TitleState_obj,credGroup),HX_("credGroup",91,7f,9c,9c)},
	{::hx::fsObject /*  ::Alphabet */ ,(int)offsetof(TitleState_obj,credTextShit),HX_("credTextShit",fb,55,c1,3c)},
	{::hx::fsObject /*  ::flixel::group::FlxTypedGroup */ ,(int)offsetof(TitleState_obj,textGroup),HX_("textGroup",52,43,e2,32)},
	{::hx::fsObject /*  ::flixel::FlxSprite */ ,(int)offsetof(TitleState_obj,ngSpr),HX_("ngSpr",7c,26,68,9a)},
	{::hx::fsObject /*  ::flixel::group::FlxTypedSpriteGroup */ ,(int)offsetof(TitleState_obj,userIcon),HX_("userIcon",64,27,78,08)},
	{::hx::fsObject /*  ::flixel::group::FlxTypedGroup */ ,(int)offsetof(TitleState_obj,userName),HX_("userName",36,b2,c4,0b)},
	{::hx::fsObject /* ::Array< ::String > */ ,(int)offsetof(TitleState_obj,credits),HX_("credits",1a,0e,5e,13)},
	{::hx::fsObject /*  ::flixel::FlxSprite */ ,(int)offsetof(TitleState_obj,logoBl),HX_("logoBl",15,ca,6e,5c)},
	{::hx::fsObject /*  ::flixel::FlxSprite */ ,(int)offsetof(TitleState_obj,gfDance),HX_("gfDance",94,88,3a,eb)},
	{::hx::fsBool,(int)offsetof(TitleState_obj,danceLeft),HX_("danceLeft",da,cc,f9,df)},
	{::hx::fsObject /*  ::flixel::FlxSprite */ ,(int)offsetof(TitleState_obj,titleText),HX_("titleText",65,ba,a4,70)},
	{::hx::fsBool,(int)offsetof(TitleState_obj,pressedEnter),HX_("pressedEnter",16,3f,a4,df)},
	{::hx::fsBool,(int)offsetof(TitleState_obj,transitioning),HX_("transitioning",6d,6a,93,94)},
	{::hx::fsBool,(int)offsetof(TitleState_obj,skippedIntro),HX_("skippedIntro",9c,44,26,49)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo TitleState_obj_sStaticStorageInfo[] = {
	{::hx::fsBool,(void *) &TitleState_obj::initialized,HX_("initialized",14,f5,0f,37)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static ::String TitleState_obj_sMemberFields[] = {
	HX_("blackScreen",8b,de,f4,5d),
	HX_("credGroup",91,7f,9c,9c),
	HX_("credTextShit",fb,55,c1,3c),
	HX_("textGroup",52,43,e2,32),
	HX_("ngSpr",7c,26,68,9a),
	HX_("userIcon",64,27,78,08),
	HX_("userName",36,b2,c4,0b),
	HX_("credits",1a,0e,5e,13),
	HX_("create",fc,66,0f,7c),
	HX_("logoBl",15,ca,6e,5c),
	HX_("gfDance",94,88,3a,eb),
	HX_("danceLeft",da,cc,f9,df),
	HX_("titleText",65,ba,a4,70),
	HX_("startIntro",aa,a2,37,da),
	HX_("getIntroTextShit",23,9f,f3,eb),
	HX_("pressedEnter",16,3f,a4,df),
	HX_("transitioning",6d,6a,93,94),
	HX_("update",09,86,05,87),
	HX_("createCoolText",32,cb,41,41),
	HX_("addMoreText",23,fe,9f,87),
	HX_("deleteCoolText",61,6b,de,48),
	HX_("beatHit",7d,ea,04,74),
	HX_("skippedIntro",9c,44,26,49),
	HX_("skipIntro",6d,37,1c,d2),
	HX_("sortByShit",35,ff,86,6e),
	::String(null()) };

static void TitleState_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TitleState_obj::initialized,"initialized");
};

#ifdef HXCPP_VISIT_ALLOCS
static void TitleState_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TitleState_obj::initialized,"initialized");
};

#endif

::hx::Class TitleState_obj::__mClass;

static ::String TitleState_obj_sStaticFields[] = {
	HX_("initialized",14,f5,0f,37),
	::String(null())
};

void TitleState_obj::__register()
{
	TitleState_obj _hx_dummy;
	TitleState_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("TitleState",79,8d,a1,8c);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &TitleState_obj::__GetStatic;
	__mClass->mSetStaticField = &TitleState_obj::__SetStatic;
	__mClass->mMarkFunc = TitleState_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(TitleState_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(TitleState_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< TitleState_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = TitleState_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = TitleState_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = TitleState_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void TitleState_obj::__boot()
{
{
            	HX_STACKFRAME(&_hx_pos_a55214e0452daa02_38_boot)
HXDLIN(  38)		initialized = false;
            	}
}

