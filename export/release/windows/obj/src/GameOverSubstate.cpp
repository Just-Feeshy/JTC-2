#include <hxcpp.h>

#ifndef INCLUDED_Boyfriend
#include <Boyfriend.h>
#endif
#ifndef INCLUDED_Character
#include <Character.h>
#endif
#ifndef INCLUDED_Conductor
#include <Conductor.h>
#endif
#ifndef INCLUDED_Controls
#include <Controls.h>
#endif
#ifndef INCLUDED_FreeplayState
#include <FreeplayState.h>
#endif
#ifndef INCLUDED_GameOverSubstate
#include <GameOverSubstate.h>
#endif
#ifndef INCLUDED_HelperStates
#include <HelperStates.h>
#endif
#ifndef INCLUDED_LoadingState
#include <LoadingState.h>
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
#ifndef INCLUDED_PlayState
#include <PlayState.h>
#endif
#ifndef INCLUDED_PlayerSettings
#include <PlayerSettings.h>
#endif
#ifndef INCLUDED_StoryMenuState
#include <StoryMenuState.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxCamera
#include <flixel/FlxCamera.h>
#endif
#ifndef INCLUDED_flixel_FlxCameraFollowStyle
#include <flixel/FlxCameraFollowStyle.h>
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
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
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
#ifndef INCLUDED_flixel_system_FlxSound
#include <flixel/system/FlxSound.h>
#endif
#ifndef INCLUDED_flixel_system_FlxSoundGroup
#include <flixel/system/FlxSoundGroup.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_SoundFrontEnd
#include <flixel/system/frontEnds/SoundFrontEnd.h>
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
#ifndef INCLUDED_openfl_media_SoundChannel
#include <openfl/media/SoundChannel.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_b2ae8d30512793fc_10_new,"GameOverSubstate","new",0xba5265a9,"GameOverSubstate.new","GameOverSubstate.hx",10,0x01fbc1e7)
HX_LOCAL_STACK_FRAME(_hx_pos_b2ae8d30512793fc_55_update,"GameOverSubstate","update",0x4cd2a460,"GameOverSubstate.update","GameOverSubstate.hx",55,0x01fbc1e7)
HX_LOCAL_STACK_FRAME(_hx_pos_b2ae8d30512793fc_91_beatHit,"GameOverSubstate","beatHit",0xc1b25846,"GameOverSubstate.beatHit","GameOverSubstate.hx",91,0x01fbc1e7)
HX_LOCAL_STACK_FRAME(_hx_pos_b2ae8d30512793fc_100_endBullshit,"GameOverSubstate","endBullshit",0xd9747d97,"GameOverSubstate.endBullshit","GameOverSubstate.hx",100,0x01fbc1e7)
HX_LOCAL_STACK_FRAME(_hx_pos_b2ae8d30512793fc_110_endBullshit,"GameOverSubstate","endBullshit",0xd9747d97,"GameOverSubstate.endBullshit","GameOverSubstate.hx",110,0x01fbc1e7)
HX_LOCAL_STACK_FRAME(_hx_pos_b2ae8d30512793fc_108_endBullshit,"GameOverSubstate","endBullshit",0xd9747d97,"GameOverSubstate.endBullshit","GameOverSubstate.hx",108,0x01fbc1e7)

void GameOverSubstate_obj::__construct(Float x,Float y){
            	HX_GC_STACKFRAME(&_hx_pos_b2ae8d30512793fc_10_new)
HXLINE(  96)		this->isEnding = false;
HXLINE(  15)		this->stageSuffix = HX_("",00,00,00,00);
HXLINE(  19)		::String daStage = ::PlayState_obj::curStage;
HXLINE(  20)		::String daBf = HX_("",00,00,00,00);
HXLINE(  21)		::String _hx_switch_0 = daStage;
            		if (  (_hx_switch_0==HX_("school",74,b8,c8,40)) ){
HXLINE(  24)			this->stageSuffix = HX_("-pixel",39,03,b3,c0);
HXLINE(  25)			daBf = HX_("bf-pixel-dead",34,d0,3d,c4);
HXLINE(  23)			goto _hx_goto_0;
            		}
            		if (  (_hx_switch_0==HX_("schoolEvil",28,a1,f5,f7)) ){
HXLINE(  27)			this->stageSuffix = HX_("-pixel",39,03,b3,c0);
HXLINE(  28)			daBf = HX_("bf-pixel-dead",34,d0,3d,c4);
HXLINE(  26)			goto _hx_goto_0;
            		}
            		/* default */{
HXLINE(  30)			daBf = HX_("bf",c4,55,00,00);
            		}
            		_hx_goto_0:;
HXLINE(  33)		super::__construct();
HXLINE(  35)		::Conductor_obj::songPosition = ( (Float)(0) );
HXLINE(  37)		this->bf =  ::Boyfriend_obj::__alloc( HX_CTX ,x,y,daBf);
HXLINE(  38)		this->add(this->bf);
HXLINE(  40)		Float _hx_tmp = this->bf->getGraphicMidpoint(null())->x;
HXDLIN(  40)		this->camFollow =  ::flixel::FlxObject_obj::__alloc( HX_CTX ,_hx_tmp,this->bf->getGraphicMidpoint(null())->y,1,1);
HXLINE(  41)		this->add(this->camFollow);
HXLINE(  43)		 ::flixel::_hx_system::frontEnds::SoundFrontEnd _hx_tmp1 = ::flixel::FlxG_obj::sound;
HXDLIN(  43)		::String key = (HX_("fnf_loss_sfx",6a,36,72,11) + this->stageSuffix);
HXDLIN(  43)		::String library = null();
HXDLIN(  43)		::String _hx_tmp2;
HXDLIN(  43)		if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("sounds/",eb,02,a5,b6) + key) + HX_(".",2e,00,00,00)) + HX_("ogg",4f,94,54,00)),HX_("SOUND",af,c4,ba,fe),library),null())) {
HXLINE(  43)			_hx_tmp2 = ::Paths_obj::getPath((((HX_("sounds/",eb,02,a5,b6) + key) + HX_(".",2e,00,00,00)) + HX_("ogg",4f,94,54,00)),HX_("SOUND",af,c4,ba,fe),library);
            		}
            		else {
HXLINE(  43)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate sound - ",98,e2,ed,38) + key)));
            		}
HXDLIN(  43)		_hx_tmp1->play(_hx_tmp2,null(),null(),null(),null(),null());
HXLINE(  44)		::Conductor_obj::changeBPM(100);
HXLINE(  48)		::flixel::FlxG_obj::camera->scroll->set(null(),null());
HXLINE(  49)		::flixel::FlxG_obj::camera->target = null();
HXLINE(  51)		this->bf->playAnim(HX_("firstDeath",e4,d8,fc,14),null(),null(),null());
            	}

Dynamic GameOverSubstate_obj::__CreateEmpty() { return new GameOverSubstate_obj; }

void *GameOverSubstate_obj::_hx_vtable = 0;

Dynamic GameOverSubstate_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< GameOverSubstate_obj > _hx_result = new GameOverSubstate_obj();
	_hx_result->__construct(inArgs[0],inArgs[1]);
	return _hx_result;
}

bool GameOverSubstate_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x7c795c9f) {
		if (inClassId<=(int)0x62817b24) {
			if (inClassId<=(int)0x5661ffbf) {
				return inClassId==(int)0x00000001 || inClassId==(int)0x5661ffbf;
			} else {
				return inClassId==(int)0x62817b24;
			}
		} else {
			return inClassId==(int)0x7c795c9f;
		}
	} else {
		if (inClassId<=(int)0x7d3f71b3) {
			return inClassId==(int)0x7ccf8994 || inClassId==(int)0x7d3f71b3;
		} else {
			return inClassId==(int)0x7fce3ab0;
		}
	}
}

void GameOverSubstate_obj::update(Float elapsed){
            	HX_GC_STACKFRAME(&_hx_pos_b2ae8d30512793fc_55_update)
HXLINE(  56)		this->super::update(elapsed);
HXLINE(  58)		if (::PlayerSettings_obj::player1->controls->_accept->check()) {
HXLINE(  60)			this->endBullshit();
            		}
HXLINE(  63)		if (::PlayerSettings_obj::player1->controls->_back->check()) {
HXLINE(  65)			{
HXLINE(  65)				 ::flixel::_hx_system::FlxSound _this = ::flixel::FlxG_obj::sound->music;
HXDLIN(  65)				_this->cleanup(_this->autoDestroy,true);
            			}
HXLINE(  67)			if (::PlayState_obj::isStoryMode) {
HXLINE(  68)				 ::flixel::FlxState nextState =  ::StoryMenuState_obj::__alloc( HX_CTX );
HXDLIN(  68)				if (::flixel::FlxG_obj::game->_state->switchTo(nextState)) {
HXLINE(  68)					::flixel::FlxG_obj::game->_requestedState = nextState;
            				}
            			}
            			else {
HXLINE(  70)				 ::flixel::FlxState nextState =  ::FreeplayState_obj::__alloc( HX_CTX );
HXDLIN(  70)				if (::flixel::FlxG_obj::game->_state->switchTo(nextState)) {
HXLINE(  70)					::flixel::FlxG_obj::game->_requestedState = nextState;
            				}
            			}
            		}
HXLINE(  73)		bool _hx_tmp;
HXDLIN(  73)		if ((this->bf->animation->_curAnim->name == HX_("firstDeath",e4,d8,fc,14))) {
HXLINE(  73)			_hx_tmp = (this->bf->animation->_curAnim->curFrame == 12);
            		}
            		else {
HXLINE(  73)			_hx_tmp = false;
            		}
HXDLIN(  73)		if (_hx_tmp) {
HXLINE(  75)			::flixel::FlxG_obj::camera->follow(this->camFollow,::flixel::FlxCameraFollowStyle_obj::LOCKON_dyn(),((Float)0.01));
            		}
HXLINE(  78)		bool _hx_tmp1;
HXDLIN(  78)		if ((this->bf->animation->_curAnim->name == HX_("firstDeath",e4,d8,fc,14))) {
HXLINE(  78)			_hx_tmp1 = this->bf->animation->_curAnim->finished;
            		}
            		else {
HXLINE(  78)			_hx_tmp1 = false;
            		}
HXDLIN(  78)		if (_hx_tmp1) {
HXLINE(  80)			 ::flixel::_hx_system::frontEnds::SoundFrontEnd _hx_tmp = ::flixel::FlxG_obj::sound;
HXDLIN(  80)			::String key = (HX_("gameOver",66,92,de,b5) + this->stageSuffix);
HXDLIN(  80)			::String library = null();
HXDLIN(  80)			::String _hx_tmp1;
HXDLIN(  80)			if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("music/",ea,bf,1b,3f) + key) + HX_(".",2e,00,00,00)) + HX_("ogg",4f,94,54,00)),HX_("MUSIC",85,08,49,8e),library),null())) {
HXLINE(  80)				_hx_tmp1 = ::Paths_obj::getPath((((HX_("music/",ea,bf,1b,3f) + key) + HX_(".",2e,00,00,00)) + HX_("ogg",4f,94,54,00)),HX_("MUSIC",85,08,49,8e),library);
            			}
            			else {
HXLINE(  80)				HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate music - ",82,28,df,2c) + key)));
            			}
HXDLIN(  80)			_hx_tmp->playMusic(_hx_tmp1,null(),null(),null());
            		}
HXLINE(  83)		if (::hx::IsNotNull( ::flixel::FlxG_obj::sound->music->_channel )) {
HXLINE(  85)			::Conductor_obj::songPosition = ::flixel::FlxG_obj::sound->music->_time;
            		}
            	}


void GameOverSubstate_obj::beatHit(){
            	HX_STACKFRAME(&_hx_pos_b2ae8d30512793fc_91_beatHit)
HXDLIN(  91)		this->super::beatHit();
            	}


void GameOverSubstate_obj::endBullshit(){
            	HX_GC_STACKFRAME(&_hx_pos_b2ae8d30512793fc_100_endBullshit)
HXDLIN( 100)		if (!(this->isEnding)) {
            			HX_BEGIN_LOCAL_FUNC_S0(::hx::LocalFunc,_hx_Closure_1) HXARGC(1)
            			void _hx_run( ::flixel::util::FlxTimer tmr){
            				HX_BEGIN_LOCAL_FUNC_S0(::hx::LocalFunc,_hx_Closure_0) HXARGC(0)
            				void _hx_run(){
            					HX_GC_STACKFRAME(&_hx_pos_b2ae8d30512793fc_110_endBullshit)
HXLINE( 110)					 ::flixel::FlxState nextState = ::LoadingState_obj::getNextState(( ( ::flixel::FlxState)( ::PlayState_obj::__alloc( HX_CTX ,null())) ),false);
HXDLIN( 110)					if (::flixel::FlxG_obj::game->_state->switchTo(nextState)) {
HXLINE( 110)						::flixel::FlxG_obj::game->_requestedState = nextState;
            					}
            				}
            				HX_END_LOCAL_FUNC0((void))

            				HX_GC_STACKFRAME(&_hx_pos_b2ae8d30512793fc_108_endBullshit)
HXLINE( 108)				::flixel::FlxG_obj::camera->fade(-16777216,2,false, ::Dynamic(new _hx_Closure_0()),null());
            			}
            			HX_END_LOCAL_FUNC1((void))

HXLINE( 102)			this->isEnding = true;
HXLINE( 103)			this->bf->playAnim(HX_("deathConfirm",2c,44,2b,12),true,null(),null());
HXLINE( 104)			{
HXLINE( 104)				 ::flixel::_hx_system::FlxSound _this = ::flixel::FlxG_obj::sound->music;
HXDLIN( 104)				_this->cleanup(_this->autoDestroy,true);
            			}
HXLINE( 105)			 ::flixel::_hx_system::frontEnds::SoundFrontEnd _hx_tmp = ::flixel::FlxG_obj::sound;
HXDLIN( 105)			::String key = (HX_("gameOverEnd",15,2d,a9,8d) + this->stageSuffix);
HXDLIN( 105)			::String library = null();
HXDLIN( 105)			::String _hx_tmp1;
HXDLIN( 105)			if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("music/",ea,bf,1b,3f) + key) + HX_(".",2e,00,00,00)) + HX_("ogg",4f,94,54,00)),HX_("MUSIC",85,08,49,8e),library),null())) {
HXLINE( 105)				_hx_tmp1 = ::Paths_obj::getPath((((HX_("music/",ea,bf,1b,3f) + key) + HX_(".",2e,00,00,00)) + HX_("ogg",4f,94,54,00)),HX_("MUSIC",85,08,49,8e),library);
            			}
            			else {
HXLINE( 105)				HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate music - ",82,28,df,2c) + key)));
            			}
HXDLIN( 105)			_hx_tmp->play(_hx_tmp1,null(),null(),null(),null(),null());
HXLINE( 106)			 ::flixel::util::FlxTimer_obj::__alloc( HX_CTX ,null())->start(((Float)0.7), ::Dynamic(new _hx_Closure_1()),null());
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC0(GameOverSubstate_obj,endBullshit,(void))


::hx::ObjectPtr< GameOverSubstate_obj > GameOverSubstate_obj::__new(Float x,Float y) {
	::hx::ObjectPtr< GameOverSubstate_obj > __this = new GameOverSubstate_obj();
	__this->__construct(x,y);
	return __this;
}

::hx::ObjectPtr< GameOverSubstate_obj > GameOverSubstate_obj::__alloc(::hx::Ctx *_hx_ctx,Float x,Float y) {
	GameOverSubstate_obj *__this = (GameOverSubstate_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(GameOverSubstate_obj), true, "GameOverSubstate"));
	*(void **)__this = GameOverSubstate_obj::_hx_vtable;
	__this->__construct(x,y);
	return __this;
}

GameOverSubstate_obj::GameOverSubstate_obj()
{
}

void GameOverSubstate_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GameOverSubstate);
	HX_MARK_MEMBER_NAME(bf,"bf");
	HX_MARK_MEMBER_NAME(camFollow,"camFollow");
	HX_MARK_MEMBER_NAME(stageSuffix,"stageSuffix");
	HX_MARK_MEMBER_NAME(isEnding,"isEnding");
	 ::flixel::FlxSubState_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void GameOverSubstate_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(bf,"bf");
	HX_VISIT_MEMBER_NAME(camFollow,"camFollow");
	HX_VISIT_MEMBER_NAME(stageSuffix,"stageSuffix");
	HX_VISIT_MEMBER_NAME(isEnding,"isEnding");
	 ::flixel::FlxSubState_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val GameOverSubstate_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"bf") ) { return ::hx::Val( bf ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return ::hx::Val( update_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"beatHit") ) { return ::hx::Val( beatHit_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"isEnding") ) { return ::hx::Val( isEnding ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"camFollow") ) { return ::hx::Val( camFollow ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"stageSuffix") ) { return ::hx::Val( stageSuffix ); }
		if (HX_FIELD_EQ(inName,"endBullshit") ) { return ::hx::Val( endBullshit_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val GameOverSubstate_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"bf") ) { bf=inValue.Cast<  ::Boyfriend >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"isEnding") ) { isEnding=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"camFollow") ) { camFollow=inValue.Cast<  ::flixel::FlxObject >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"stageSuffix") ) { stageSuffix=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void GameOverSubstate_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("bf",c4,55,00,00));
	outFields->push(HX_("camFollow",e0,6e,47,22));
	outFields->push(HX_("stageSuffix",2f,64,9f,2f));
	outFields->push(HX_("isEnding",71,3f,f2,52));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo GameOverSubstate_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::Boyfriend */ ,(int)offsetof(GameOverSubstate_obj,bf),HX_("bf",c4,55,00,00)},
	{::hx::fsObject /*  ::flixel::FlxObject */ ,(int)offsetof(GameOverSubstate_obj,camFollow),HX_("camFollow",e0,6e,47,22)},
	{::hx::fsString,(int)offsetof(GameOverSubstate_obj,stageSuffix),HX_("stageSuffix",2f,64,9f,2f)},
	{::hx::fsBool,(int)offsetof(GameOverSubstate_obj,isEnding),HX_("isEnding",71,3f,f2,52)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *GameOverSubstate_obj_sStaticStorageInfo = 0;
#endif

static ::String GameOverSubstate_obj_sMemberFields[] = {
	HX_("bf",c4,55,00,00),
	HX_("camFollow",e0,6e,47,22),
	HX_("stageSuffix",2f,64,9f,2f),
	HX_("update",09,86,05,87),
	HX_("beatHit",7d,ea,04,74),
	HX_("isEnding",71,3f,f2,52),
	HX_("endBullshit",4e,f7,81,48),
	::String(null()) };

::hx::Class GameOverSubstate_obj::__mClass;

void GameOverSubstate_obj::__register()
{
	GameOverSubstate_obj _hx_dummy;
	GameOverSubstate_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("GameOverSubstate",37,5d,9a,d7);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(GameOverSubstate_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< GameOverSubstate_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = GameOverSubstate_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = GameOverSubstate_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

