#include <hxcpp.h>

#ifndef INCLUDED_cc9afe4755847ade
#define INCLUDED_cc9afe4755847ade
#include "linc_lua.h"
#endif
#ifndef INCLUDED_Conductor
#include <Conductor.h>
#endif
#ifndef INCLUDED_HelperStates
#include <HelperStates.h>
#endif
#ifndef INCLUDED_ModLua
#include <ModLua.h>
#endif
#ifndef INCLUDED_Paths
#include <Paths.h>
#endif
#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Register
#include <Register.h>
#endif
#ifndef INCLUDED_SaveType
#include <SaveType.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
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
#ifndef INCLUDED_flixel_math_FlxPoint
#include <flixel/math/FlxPoint.h>
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
#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_lime_utils_Assets
#include <lime/utils/Assets.h>
#endif
#ifndef INCLUDED_llua_Convert
#include <llua/Convert.h>
#endif
#ifndef INCLUDED_llua_Lua_helper
#include <llua/Lua_helper.h>
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
#ifndef INCLUDED_sys_FileSystem
#include <sys/FileSystem.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_cf04762c5f4ddd2d_20_new,"ModLua","new",0xbd818828,"ModLua.new","ModLua.hx",20,0x7f20b448)
HX_LOCAL_STACK_FRAME(_hx_pos_cf04762c5f4ddd2d_36_execute,"ModLua","execute",0xa00645fd,"ModLua.execute","ModLua.hx",36,0x7f20b448)
HX_LOCAL_STACK_FRAME(_hx_pos_cf04762c5f4ddd2d_67_execute,"ModLua","execute",0xa00645fd,"ModLua.execute","ModLua.hx",67,0x7f20b448)
HX_LOCAL_STACK_FRAME(_hx_pos_cf04762c5f4ddd2d_81_execute,"ModLua","execute",0xa00645fd,"ModLua.execute","ModLua.hx",81,0x7f20b448)
HX_LOCAL_STACK_FRAME(_hx_pos_cf04762c5f4ddd2d_88_execute,"ModLua","execute",0xa00645fd,"ModLua.execute","ModLua.hx",88,0x7f20b448)
HX_LOCAL_STACK_FRAME(_hx_pos_cf04762c5f4ddd2d_103_execute,"ModLua","execute",0xa00645fd,"ModLua.execute","ModLua.hx",103,0x7f20b448)
HX_LOCAL_STACK_FRAME(_hx_pos_cf04762c5f4ddd2d_122_execute,"ModLua","execute",0xa00645fd,"ModLua.execute","ModLua.hx",122,0x7f20b448)
HX_LOCAL_STACK_FRAME(_hx_pos_cf04762c5f4ddd2d_132_execute,"ModLua","execute",0xa00645fd,"ModLua.execute","ModLua.hx",132,0x7f20b448)
HX_LOCAL_STACK_FRAME(_hx_pos_cf04762c5f4ddd2d_142_execute,"ModLua","execute",0xa00645fd,"ModLua.execute","ModLua.hx",142,0x7f20b448)
HX_LOCAL_STACK_FRAME(_hx_pos_cf04762c5f4ddd2d_152_execute,"ModLua","execute",0xa00645fd,"ModLua.execute","ModLua.hx",152,0x7f20b448)
HX_LOCAL_STACK_FRAME(_hx_pos_cf04762c5f4ddd2d_162_execute,"ModLua","execute",0xa00645fd,"ModLua.execute","ModLua.hx",162,0x7f20b448)
HX_LOCAL_STACK_FRAME(_hx_pos_cf04762c5f4ddd2d_173_execute,"ModLua","execute",0xa00645fd,"ModLua.execute","ModLua.hx",173,0x7f20b448)
HX_LOCAL_STACK_FRAME(_hx_pos_cf04762c5f4ddd2d_184_execute,"ModLua","execute",0xa00645fd,"ModLua.execute","ModLua.hx",184,0x7f20b448)
HX_LOCAL_STACK_FRAME(_hx_pos_cf04762c5f4ddd2d_194_execute,"ModLua","execute",0xa00645fd,"ModLua.execute","ModLua.hx",194,0x7f20b448)
HX_LOCAL_STACK_FRAME(_hx_pos_cf04762c5f4ddd2d_205_execute,"ModLua","execute",0xa00645fd,"ModLua.execute","ModLua.hx",205,0x7f20b448)
HX_LOCAL_STACK_FRAME(_hx_pos_cf04762c5f4ddd2d_209_execute,"ModLua","execute",0xa00645fd,"ModLua.execute","ModLua.hx",209,0x7f20b448)
HX_LOCAL_STACK_FRAME(_hx_pos_cf04762c5f4ddd2d_216_execute,"ModLua","execute",0xa00645fd,"ModLua.execute","ModLua.hx",216,0x7f20b448)
HX_LOCAL_STACK_FRAME(_hx_pos_cf04762c5f4ddd2d_226_addCallback,"ModLua","addCallback",0x413990ce,"ModLua.addCallback","ModLua.hx",226,0x7f20b448)
HX_LOCAL_STACK_FRAME(_hx_pos_cf04762c5f4ddd2d_230_set,"ModLua","set",0xbd85536a,"ModLua.set","ModLua.hx",230,0x7f20b448)
HX_LOCAL_STACK_FRAME(_hx_pos_cf04762c5f4ddd2d_241_call,"ModLua","call",0x0c8d2fd6,"ModLua.call","ModLua.hx",241,0x7f20b448)
HX_LOCAL_STACK_FRAME(_hx_pos_cf04762c5f4ddd2d_272_getSprite,"ModLua","getSprite",0xf1822303,"ModLua.getSprite","ModLua.hx",272,0x7f20b448)
HX_LOCAL_STACK_FRAME(_hx_pos_cf04762c5f4ddd2d_285_close,"ModLua","close",0xf6445180,"ModLua.close","ModLua.hx",285,0x7f20b448)
HX_LOCAL_STACK_FRAME(_hx_pos_cf04762c5f4ddd2d_310_convertToLua,"ModLua","convertToLua",0x71ec1b42,"ModLua.convertToLua","ModLua.hx",310,0x7f20b448)

void ModLua_obj::__construct(::String luaScript){
            	HX_GC_STACKFRAME(&_hx_pos_cf04762c5f4ddd2d_20_new)
HXLINE(  30)		this->luaTweens =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
HXLINE(  28)		this->luaCameras =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
HXLINE(  27)		this->luaSprites =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
HXLINE(  22)		this->lua = null();
HXLINE(  33)		this->luaScript = luaScript;
            	}

Dynamic ModLua_obj::__CreateEmpty() { return new ModLua_obj; }

void *ModLua_obj::_hx_vtable = 0;

Dynamic ModLua_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< ModLua_obj > _hx_result = new ModLua_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool ModLua_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x569356f6;
}

void ModLua_obj::execute(){
            	HX_STACKFRAME(&_hx_pos_cf04762c5f4ddd2d_36_execute)
HXDLIN(  36)		 ::ModLua _gthis = ::hx::ObjectPtr<OBJ_>(this);
HXLINE(  38)		this->lua = luaL_newstate();
HXLINE(  39)		luaL_openlibs(this->lua);
HXLINE(  40)		{
HXLINE(  40)			 cpp::Reference<lua_State> l = this->lua;
HXDLIN(  40)			linc::callbacks::set_callbacks_function(::cpp::Function< int ( cpp::Reference<lua_State>,::String)>(::hx::AnyCast(&::llua::Lua_helper_obj::callback_handler )));
            		}
HXLINE(  42)		 ::Dynamic resultFile = luaL_dofile(this->lua,this->luaScript);
HXLINE(  43)		::String luaResults = linc::lua::tostring(this->lua,( (int)(resultFile) ));
HXLINE(  45)		bool _hx_tmp;
HXDLIN(  45)		if (::hx::IsNotNull( luaResults )) {
HXLINE(  45)			_hx_tmp = ::hx::IsNotEq( resultFile,0 );
            		}
            		else {
HXLINE(  45)			_hx_tmp = false;
            		}
HXDLIN(  45)		if (_hx_tmp) {
HXLINE(  46)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((((HX_("Error loading lua script: \"",0d,36,81,a7) + this->luaScript) + HX_("\"\n",a8,1d,00,00)) + luaResults)));
            		}
HXLINE(  49)		::haxe::Log_obj::trace((HX_("Successfully loaded script: ",53,42,15,a9) + this->luaScript),::hx::SourceInfo(HX_("build/ModLua.hx",e7,96,ee,7d),49,HX_("ModLua",36,94,48,f5),HX_("execute",35,0a,0d,cc)));
HXLINE(  51)		this->set(HX_("windowWidth",f6,4b,35,bb),::flixel::FlxG_obj::width);
HXLINE(  52)		this->set(HX_("windowHeight",f7,a3,bc,c9),::flixel::FlxG_obj::height);
HXLINE(  54)		this->set(HX_("inRapBattle",54,8d,7f,74),false);
HXLINE(  56)		this->set(HX_("curBpm",3f,61,c3,3e),::Conductor_obj::bpm);
HXLINE(  64)		this->set(HX_("onSwitch",73,40,26,a5),false);
HXLINE(  67)		{
            			HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_0, ::ModLua,_gthis) HXARGC(1)
            			void _hx_run(::String name){
            				HX_GC_STACKFRAME(&_hx_pos_cf04762c5f4ddd2d_67_execute)
HXLINE(  68)				if (_gthis->luaSprites->exists(name)) {
HXLINE(  69)					return;
            				}
HXLINE(  72)				name = ::StringTools_obj::replace(name,HX_(".",2e,00,00,00),HX_("",00,00,00,00));
HXLINE(  74)				 ::flixel::FlxSprite sprite =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,null(),null(),null());
HXLINE(  75)				 ::Dynamic _hx_tmp;
HXDLIN(  75)				switch((int)(::SaveType_obj::GRAPHICS_dyn()->_hx_getIndex())){
            					case (int)1: {
HXLINE(  75)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  75)							::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            						}
HXDLIN(  75)						_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            					}
            					break;
            					case (int)2: {
HXLINE(  75)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  75)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            						else {
HXLINE(  75)							if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  75)								::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            							}
            						}
HXDLIN(  75)						_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            					}
            					break;
            					case (int)3: {
HXLINE(  75)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  75)							::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            						}
HXDLIN(  75)						_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            					}
            					break;
            					case (int)4: {
HXLINE(  75)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  75)							::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            						}
HXDLIN(  75)						_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            					}
            					break;
            					case (int)5: {
HXLINE(  75)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  75)							::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            						}
HXDLIN(  75)						_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            					}
            					break;
            					case (int)6: {
HXLINE(  75)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  75)							::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            						}
HXDLIN(  75)						_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            					}
            					break;
            					case (int)7: {
HXLINE(  75)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  75)							::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            						}
HXDLIN(  75)						_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            					}
            					break;
            					case (int)8: {
HXLINE(  75)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  75)							::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            						}
HXDLIN(  75)						_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            					}
            					break;
            					case (int)9: {
HXLINE(  75)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  75)							::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            						}
HXDLIN(  75)						_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            					}
            					break;
            					case (int)10: {
HXLINE(  75)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  75)							::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            						}
HXDLIN(  75)						_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            					}
            					break;
            					case (int)11: {
HXLINE(  75)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  75)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            						else {
HXLINE(  75)							if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  75)								::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            							}
            						}
HXDLIN(  75)						_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            					}
            					break;
            					case (int)12: {
HXLINE(  75)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  75)							::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            						}
HXDLIN(  75)						_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            					}
            					break;
            					case (int)13: {
HXLINE(  75)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  75)							::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            						}
HXDLIN(  75)						_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            					}
            					break;
            					case (int)14: {
HXLINE(  75)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  75)							::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            						}
HXDLIN(  75)						_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            					}
            					break;
            					case (int)15: {
HXLINE(  75)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  75)							::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            						}
HXDLIN(  75)						_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            					}
            					break;
            					case (int)16: {
HXLINE(  75)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  75)							::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            						}
HXDLIN(  75)						_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            					}
            					break;
            					case (int)17: {
HXLINE(  75)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  75)							::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            						}
HXDLIN(  75)						_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            					}
            					break;
            					case (int)18: {
HXLINE(  75)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  75)							::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            						}
HXDLIN(  75)						_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            					}
            					break;
            					case (int)19: {
HXLINE(  75)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  75)							::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            						}
HXDLIN(  75)						_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            					}
            					break;
            					case (int)20: {
HXLINE(  75)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  75)							::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            						}
HXDLIN(  75)						_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            					}
            					break;
            					case (int)21: {
HXLINE(  75)						if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  75)							::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            						}
HXDLIN(  75)						_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            					}
            					break;
            					default:{
HXLINE(  75)						_hx_tmp = null();
            					}
            				}
HXDLIN(  75)				sprite->set_antialiasing(( (bool)(_hx_tmp) ));
HXLINE(  76)				sprite->set_active(true);
HXLINE(  78)				_gthis->luaSprites->set(name,sprite);
            			}
            			HX_END_LOCAL_FUNC1((void))

HXLINE(  67)			 cpp::Reference<lua_State> l1 = this->lua;
HXDLIN(  67)			::llua::Lua_helper_obj::callbacks->set(HX_("createSprite",21,1c,eb,e5), ::Dynamic(new _hx_Closure_0(_gthis)));
HXDLIN(  67)			linc::callbacks::add_callback_function(l1,HX_("createSprite",21,1c,eb,e5));
            		}
HXLINE(  81)		{
            			HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_1, ::ModLua,_gthis) HXARGC(1)
            			bool _hx_run(::String name){
            				HX_STACKFRAME(&_hx_pos_cf04762c5f4ddd2d_81_execute)
HXLINE(  82)				if (::hx::IsNull( _gthis->getSprite(name) )) {
HXLINE(  83)					return false;
            				}
HXLINE(  85)				return true;
            			}
            			HX_END_LOCAL_FUNC1(return)

HXLINE(  81)			 cpp::Reference<lua_State> l2 = this->lua;
HXDLIN(  81)			::llua::Lua_helper_obj::callbacks->set(HX_("spriteExist",72,24,bd,ad), ::Dynamic(new _hx_Closure_1(_gthis)));
HXDLIN(  81)			linc::callbacks::add_callback_function(l2,HX_("spriteExist",72,24,bd,ad));
            		}
HXLINE(  88)		{
            			HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_2, ::ModLua,_gthis) HXARGC(3)
            			void _hx_run(::String name,::String spritesheet,::String type){
            				HX_STACKFRAME(&_hx_pos_cf04762c5f4ddd2d_88_execute)
HXLINE(  89)				 ::flixel::FlxSprite spr = _gthis->getSprite(name);
HXLINE(  91)				if (::hx::IsNull( spr )) {
HXLINE(  92)					return;
            				}
HXLINE(  95)				::String _hx_switch_0 = ::StringTools_obj::trim(type.toLowerCase());
            				if (  (_hx_switch_0==HX_("pac",52,51,55,00)) ||  (_hx_switch_0==HX_("packer",86,57,98,e3)) ||  (_hx_switch_0==HX_("packeratlas",05,f0,7b,dc)) ){
HXLINE(  97)					::String library = null();
HXDLIN(  97)					 ::Dynamic cache = null();
HXDLIN(  97)					::String cacheFile = HX_("",00,00,00,00);
HXDLIN(  97)					if (( (bool)(cache) )) {
HXLINE(  97)						cacheFile = HX_("cache/",ad,5f,f2,b0);
            					}
HXDLIN(  97)					if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + spritesheet))) {
HXLINE(  97)						cacheFile = HX_("",00,00,00,00);
            					}
HXDLIN(  97)					 ::flixel::graphics::frames::FlxAtlasFrames _hx_tmp;
HXDLIN(  97)					if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + spritesheet) + HX_(".txt",02,3f,c0,1e)),HX_("TEXT",ad,94,ba,37),library),null())) {
HXLINE(  97)						if (::hx::IsNotNull( ::Paths_obj::ifImageCached((cacheFile + spritesheet)) )) {
HXLINE(  97)							 ::flixel::graphics::FlxGraphic _hx_tmp1 = ::Paths_obj::ifImageCached((cacheFile + spritesheet));
HXDLIN(  97)							_hx_tmp = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSpriteSheetPacker(_hx_tmp1,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + spritesheet) + HX_(".txt",02,3f,c0,1e)),HX_("TEXT",ad,94,ba,37),library));
            						}
            						else {
HXLINE(  97)							::String _hx_tmp1 = ::Paths_obj::image((cacheFile + spritesheet),library);
HXDLIN(  97)							_hx_tmp = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSpriteSheetPacker(_hx_tmp1,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + spritesheet) + HX_(".txt",02,3f,c0,1e)),HX_("TEXT",ad,94,ba,37),library));
            						}
            					}
            					else {
HXLINE(  97)						HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate asset - ",17,30,f9,e8) + ::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + spritesheet) + HX_(".txt",02,3f,c0,1e)),HX_("TEXT",ad,94,ba,37),library))));
            					}
HXDLIN(  97)					spr->set_frames(_hx_tmp);
HXDLIN(  97)					goto _hx_goto_1;
            				}
            				/* default */{
HXLINE(  99)					::String library = null();
HXDLIN(  99)					 ::Dynamic cache = null();
HXDLIN(  99)					::String cacheFile = HX_("",00,00,00,00);
HXDLIN(  99)					if (( (bool)(cache) )) {
HXLINE(  99)						cacheFile = HX_("cache/",ad,5f,f2,b0);
            					}
HXDLIN(  99)					if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + spritesheet))) {
HXLINE(  99)						cacheFile = HX_("",00,00,00,00);
            					}
HXDLIN(  99)					 ::flixel::graphics::frames::FlxAtlasFrames _hx_tmp;
HXDLIN(  99)					::String cacheFile1 = HX_("",00,00,00,00);
HXDLIN(  99)					if (( (bool)(cache) )) {
HXLINE(  99)						cacheFile1 = HX_("cache/",ad,5f,f2,b0);
            					}
HXDLIN(  99)					if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + spritesheet))) {
HXLINE(  99)						cacheFile1 = HX_("",00,00,00,00);
            					}
HXDLIN(  99)					if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile1) + spritesheet) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library),null())) {
HXLINE(  99)						if (::hx::IsNotNull( ::Paths_obj::ifImageCached((cacheFile + spritesheet)) )) {
HXLINE(  99)							 ::flixel::graphics::FlxGraphic _hx_tmp1 = ::Paths_obj::ifImageCached((cacheFile + spritesheet));
HXDLIN(  99)							_hx_tmp = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSparrow(_hx_tmp1,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + spritesheet) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library));
            						}
            						else {
HXLINE(  99)							::String _hx_tmp1 = ::Paths_obj::image((cacheFile + spritesheet),library);
HXDLIN(  99)							_hx_tmp = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSparrow(_hx_tmp1,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + spritesheet) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library));
            						}
            					}
            					else {
HXLINE(  99)						HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate asset - ",17,30,f9,e8) + ::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + spritesheet) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library))));
            					}
HXDLIN(  99)					spr->set_frames(_hx_tmp);
            				}
            				_hx_goto_1:;
            			}
            			HX_END_LOCAL_FUNC3((void))

HXLINE(  88)			 cpp::Reference<lua_State> l3 = this->lua;
HXDLIN(  88)			::llua::Lua_helper_obj::callbacks->set(HX_("compileSpriteSheet",a7,95,bc,af), ::Dynamic(new _hx_Closure_2(_gthis)));
HXDLIN(  88)			linc::callbacks::add_callback_function(l3,HX_("compileSpriteSheet",a7,95,bc,af));
            		}
HXLINE( 103)		{
            			HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_3, ::ModLua,_gthis) HXARGC(5)
            			void _hx_run(::String name,::String animation,::String prefix, ::Dynamic __o_framerate, ::Dynamic __o_loop){
            		int framerate = __o_framerate.Default(24);
            		bool loop = __o_loop.Default(true);
            				HX_STACKFRAME(&_hx_pos_cf04762c5f4ddd2d_103_execute)
HXLINE( 104)				 ::flixel::FlxSprite spr = _gthis->getSprite(name);
HXLINE( 106)				if (::hx::IsNull( spr )) {
HXLINE( 107)					return;
            				}
HXLINE( 114)				if (spr->animation->_animations->exists(animation)) {
HXLINE( 115)					spr->animation->remove(animation);
            				}
HXLINE( 118)				spr->animation->addByPrefix(animation,prefix,framerate,loop,null(),null());
HXLINE( 119)				spr->animation->play(animation,null(),null(),null());
            			}
            			HX_END_LOCAL_FUNC5((void))

HXLINE( 103)			 cpp::Reference<lua_State> l4 = this->lua;
HXDLIN( 103)			::llua::Lua_helper_obj::callbacks->set(HX_("playAnimationByPrefix",59,0d,1c,c0), ::Dynamic(new _hx_Closure_3(_gthis)));
HXDLIN( 103)			linc::callbacks::add_callback_function(l4,HX_("playAnimationByPrefix",59,0d,1c,c0));
            		}
HXLINE( 122)		{
            			HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_4, ::ModLua,_gthis) HXARGC(3)
            			void _hx_run(::String name,::String prop, ::Dynamic value){
            				HX_STACKFRAME(&_hx_pos_cf04762c5f4ddd2d_122_execute)
HXLINE( 123)				 ::flixel::FlxSprite spr = _gthis->getSprite(name);
HXLINE( 125)				if (::hx::IsNull( spr )) {
HXLINE( 126)					return;
            				}
HXLINE( 129)				::Reflect_obj::setField(spr,prop,value);
            			}
            			HX_END_LOCAL_FUNC3((void))

HXLINE( 122)			 cpp::Reference<lua_State> l5 = this->lua;
HXDLIN( 122)			::llua::Lua_helper_obj::callbacks->set(HX_("setCustomPropertyToSprite",68,94,cb,23), ::Dynamic(new _hx_Closure_4(_gthis)));
HXDLIN( 122)			linc::callbacks::add_callback_function(l5,HX_("setCustomPropertyToSprite",68,94,cb,23));
            		}
HXLINE( 132)		{
            			HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_5, ::ModLua,_gthis) HXARGC(3)
            			void _hx_run(::String name,Float x,Float y){
            				HX_STACKFRAME(&_hx_pos_cf04762c5f4ddd2d_132_execute)
HXLINE( 133)				 ::flixel::FlxSprite spr = _gthis->getSprite(name);
HXLINE( 135)				if (::hx::IsNull( spr )) {
HXLINE( 136)					return;
            				}
HXLINE( 139)				spr->setPosition(x,y);
            			}
            			HX_END_LOCAL_FUNC3((void))

HXLINE( 132)			 cpp::Reference<lua_State> l6 = this->lua;
HXDLIN( 132)			::llua::Lua_helper_obj::callbacks->set(HX_("setSpritePosition",10,cd,16,b0), ::Dynamic(new _hx_Closure_5(_gthis)));
HXDLIN( 132)			linc::callbacks::add_callback_function(l6,HX_("setSpritePosition",10,cd,16,b0));
            		}
HXLINE( 142)		{
            			HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_6, ::ModLua,_gthis) HXARGC(2)
            			void _hx_run(::String name,Float angle){
            				HX_STACKFRAME(&_hx_pos_cf04762c5f4ddd2d_142_execute)
HXLINE( 143)				 ::flixel::FlxSprite spr = _gthis->getSprite(name);
HXLINE( 145)				if (::hx::IsNull( spr )) {
HXLINE( 146)					return;
            				}
HXLINE( 149)				spr->set_angle(angle);
            			}
            			HX_END_LOCAL_FUNC2((void))

HXLINE( 142)			 cpp::Reference<lua_State> l7 = this->lua;
HXDLIN( 142)			::llua::Lua_helper_obj::callbacks->set(HX_("setSpriteAngle",0c,61,43,01), ::Dynamic(new _hx_Closure_6(_gthis)));
HXDLIN( 142)			linc::callbacks::add_callback_function(l7,HX_("setSpriteAngle",0c,61,43,01));
            		}
HXLINE( 152)		{
            			HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_7, ::ModLua,_gthis) HXARGC(3)
            			void _hx_run(::String name,int x,int y){
            				HX_STACKFRAME(&_hx_pos_cf04762c5f4ddd2d_152_execute)
HXLINE( 153)				 ::flixel::FlxSprite spr = _gthis->getSprite(name);
HXLINE( 155)				if (::hx::IsNull( spr )) {
HXLINE( 156)					return;
            				}
HXLINE( 159)				spr->scrollFactor->set(x,y);
            			}
            			HX_END_LOCAL_FUNC3((void))

HXLINE( 152)			 cpp::Reference<lua_State> l8 = this->lua;
HXDLIN( 152)			::llua::Lua_helper_obj::callbacks->set(HX_("setScrollFactorToSprite",7e,ad,34,9c), ::Dynamic(new _hx_Closure_7(_gthis)));
HXDLIN( 152)			linc::callbacks::add_callback_function(l8,HX_("setScrollFactorToSprite",7e,ad,34,9c));
            		}
HXLINE( 162)		{
            			HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_8, ::ModLua,_gthis) HXARGC(3)
            			void _hx_run(::String name,int width,int height){
            				HX_STACKFRAME(&_hx_pos_cf04762c5f4ddd2d_162_execute)
HXLINE( 163)				 ::flixel::FlxSprite spr = _gthis->getSprite(name);
HXLINE( 165)				if (::hx::IsNull( spr )) {
HXLINE( 166)					return;
            				}
HXLINE( 169)				spr->setGraphicSize(width,height);
HXLINE( 170)				spr->updateHitbox();
            			}
            			HX_END_LOCAL_FUNC3((void))

HXLINE( 162)			 cpp::Reference<lua_State> l9 = this->lua;
HXDLIN( 162)			::llua::Lua_helper_obj::callbacks->set(HX_("setSpriteSize",a8,cd,59,93), ::Dynamic(new _hx_Closure_8(_gthis)));
HXDLIN( 162)			linc::callbacks::add_callback_function(l9,HX_("setSpriteSize",a8,cd,59,93));
            		}
HXLINE( 173)		{
            			HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_9, ::ModLua,_gthis) HXARGC(3)
            			void _hx_run(::String name,Float width,Float height){
            				HX_STACKFRAME(&_hx_pos_cf04762c5f4ddd2d_173_execute)
HXLINE( 174)				 ::flixel::FlxSprite spr = _gthis->getSprite(name);
HXLINE( 176)				if (::hx::IsNull( spr )) {
HXLINE( 177)					return;
            				}
HXLINE( 180)				int _hx_tmp = ::Std_obj::_hx_int((spr->get_width() / width));
HXDLIN( 180)				spr->setGraphicSize(_hx_tmp,::Std_obj::_hx_int((spr->get_height() / height)));
HXLINE( 181)				spr->updateHitbox();
            			}
            			HX_END_LOCAL_FUNC3((void))

HXLINE( 173)			 cpp::Reference<lua_State> l10 = this->lua;
HXDLIN( 173)			::llua::Lua_helper_obj::callbacks->set(HX_("decreaseSpriteSizeBy",5b,24,db,8d), ::Dynamic(new _hx_Closure_9(_gthis)));
HXDLIN( 173)			linc::callbacks::add_callback_function(l10,HX_("decreaseSpriteSizeBy",5b,24,db,8d));
            		}
HXLINE( 184)		{
            			HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_10, ::ModLua,_gthis) HXARGC(1)
            			void _hx_run(::String name){
            				HX_STACKFRAME(&_hx_pos_cf04762c5f4ddd2d_184_execute)
HXLINE( 185)				 ::flixel::FlxSprite spr = _gthis->getSprite(name);
HXLINE( 187)				if (::hx::IsNull( spr )) {
HXLINE( 188)					return;
            				}
HXLINE( 191)				::flixel::FlxG_obj::game->_state->add(spr).StaticCast<  ::flixel::FlxBasic >();
            			}
            			HX_END_LOCAL_FUNC1((void))

HXLINE( 184)			 cpp::Reference<lua_State> l11 = this->lua;
HXDLIN( 184)			::llua::Lua_helper_obj::callbacks->set(HX_("addSpriteToState",30,a6,29,9e), ::Dynamic(new _hx_Closure_10(_gthis)));
HXDLIN( 184)			linc::callbacks::add_callback_function(l11,HX_("addSpriteToState",30,a6,29,9e));
            		}
HXLINE( 194)		{
            			HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_11, ::ModLua,_gthis) HXARGC(2)
            			void _hx_run(::String name,int zoom){
            				HX_STACKFRAME(&_hx_pos_cf04762c5f4ddd2d_194_execute)
HXLINE( 195)				 ::flixel::FlxCamera cam = ( ( ::flixel::FlxCamera)(_gthis->luaCameras->get(name)) );
HXLINE( 197)				if (::hx::IsNull( cam )) {
HXLINE( 198)					return;
            				}
HXLINE( 201)				cam->set_zoom(( (Float)(zoom) ));
            			}
            			HX_END_LOCAL_FUNC2((void))

HXLINE( 194)			 cpp::Reference<lua_State> l12 = this->lua;
HXDLIN( 194)			::llua::Lua_helper_obj::callbacks->set(HX_("setCameraZoom",9a,0a,8f,58), ::Dynamic(new _hx_Closure_11(_gthis)));
HXDLIN( 194)			linc::callbacks::add_callback_function(l12,HX_("setCameraZoom",9a,0a,8f,58));
            		}
HXLINE( 204)		{
            			HX_BEGIN_LOCAL_FUNC_S0(::hx::LocalFunc,_hx_Closure_12) HXARGC(1)
            			void _hx_run(::String state){
            				HX_STACKFRAME(&_hx_pos_cf04762c5f4ddd2d_205_execute)
HXLINE( 205)				 ::flixel::FlxState nextState = ( ( ::flixel::FlxState)(::Register_obj::forNameClass(state,::cpp::VirtualArray_obj::__new(0))) );
HXDLIN( 205)				if (::flixel::FlxG_obj::game->_state->switchTo(nextState)) {
HXLINE( 205)					::flixel::FlxG_obj::game->_requestedState = nextState;
            				}
            			}
            			HX_END_LOCAL_FUNC1((void))

HXLINE( 204)			 cpp::Reference<lua_State> l13 = this->lua;
HXDLIN( 204)			::llua::Lua_helper_obj::callbacks->set(HX_("switchState",7d,07,8b,77), ::Dynamic(new _hx_Closure_12()));
HXDLIN( 204)			linc::callbacks::add_callback_function(l13,HX_("switchState",7d,07,8b,77));
            		}
HXLINE( 209)		{
            			HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_14, ::ModLua,_gthis) HXARGC(4)
            			void _hx_run(::String name,Float value,Float duration,::String easing){
            				HX_STACKFRAME(&_hx_pos_cf04762c5f4ddd2d_209_execute)
HXLINE( 210)				 ::flixel::FlxCamera cam = ( ( ::flixel::FlxCamera)(_gthis->luaCameras->get(name)) );
HXLINE( 212)				if (::hx::IsNull( cam )) {
HXLINE( 213)					return;
            				}
HXLINE( 216)				{
            					HX_BEGIN_LOCAL_FUNC_S2(::hx::LocalFunc,_hx_Closure_13,::String,name, ::ModLua,_gthis) HXARGC(1)
            					void _hx_run( ::flixel::tweens::FlxTween twn){
            						HX_STACKFRAME(&_hx_pos_cf04762c5f4ddd2d_216_execute)
HXLINE( 217)						_gthis->call(HX_("onTweenComplete",a5,b1,0f,65),::cpp::VirtualArray_obj::__new(1)->init(0,name),null());
HXLINE( 218)						_gthis->luaTweens->remove(name);
            					}
            					HX_END_LOCAL_FUNC1((void))

HXLINE( 216)					::Dynamic this1 = _gthis->luaTweens;
HXDLIN( 216)					 ::flixel::tweens::FlxTween value1 = ::flixel::tweens::FlxTween_obj::tween(cam, ::Dynamic(::hx::Anon_obj::Create(1)
            						->setFixed(0,HX_("zoom",13,a3,f8,50),value)),duration, ::Dynamic(::hx::Anon_obj::Create(2)
            						->setFixed(0,HX_("ease",ee,8b,0c,43),::Register_obj::getFlxEaseByString(easing))
            						->setFixed(1,HX_("onComplete",f8,d4,7e,5d), ::Dynamic(new _hx_Closure_13(name,_gthis)))));
HXDLIN( 216)					( ( ::haxe::ds::StringMap)(this1) )->set(name,value1);
            				}
            			}
            			HX_END_LOCAL_FUNC4((void))

HXLINE( 209)			 cpp::Reference<lua_State> l14 = this->lua;
HXDLIN( 209)			::llua::Lua_helper_obj::callbacks->set(HX_("setCameraZoomTween",71,61,40,12), ::Dynamic(new _hx_Closure_14(_gthis)));
HXDLIN( 209)			linc::callbacks::add_callback_function(l14,HX_("setCameraZoomTween",71,61,40,12));
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC0(ModLua_obj,execute,(void))

void ModLua_obj::addCallback(::String name, ::Dynamic method){
            	HX_STACKFRAME(&_hx_pos_cf04762c5f4ddd2d_226_addCallback)
HXDLIN( 226)		 cpp::Reference<lua_State> l = this->lua;
HXDLIN( 226)		::llua::Lua_helper_obj::callbacks->set(name,method);
HXDLIN( 226)		linc::callbacks::add_callback_function(l,name);
            	}


HX_DEFINE_DYNAMIC_FUNC2(ModLua_obj,addCallback,(void))

void ModLua_obj::set(::String variable, ::Dynamic data){
            	HX_STACKFRAME(&_hx_pos_cf04762c5f4ddd2d_230_set)
HXLINE( 232)		if (::hx::IsNull( this->lua )) {
HXLINE( 233)			return;
            		}
HXLINE( 236)		::llua::Convert_obj::toLua(this->lua,data);
HXLINE( 237)		lua_setglobal(this->lua,variable);
            	}


HX_DEFINE_DYNAMIC_FUNC2(ModLua_obj,set,(void))

 ::Dynamic ModLua_obj::call(::String event,::cpp::VirtualArray args,::hx::Null< int >  __o_index){
            		int index = __o_index.Default(0);
            	HX_STACKFRAME(&_hx_pos_cf04762c5f4ddd2d_241_call)
HXLINE( 243)		if (::hx::IsNull( this->lua )) {
HXLINE( 244)			::haxe::Log_obj::trace(HX_("Error: Something went wrong with lua.",25,61,ae,bd),::hx::SourceInfo(HX_("build/ModLua.hx",e7,96,ee,7d),244,HX_("ModLua",36,94,48,f5),HX_("call",9e,18,ba,41)));
HXLINE( 245)			return 0;
            		}
HXLINE( 248)		lua_getglobal(this->lua,event);
HXLINE( 250)		if ((this->convertToLua(args,index) == 1)) {
HXLINE( 251)			 ::Dynamic luaResults = lua_pcall(this->lua,args->get_length(),1,0);
HXLINE( 253)			if (::hx::IsNotNull( luaResults )) {
HXLINE( 254)				if ((lua_type(this->lua,-1) == 4)) {
HXLINE( 255)					::String error = linc::lua::tostring(this->lua,-1);
HXLINE( 256)					lua_pop(this->lua,1);
HXLINE( 258)					if ((error == HX_("attempt to call a nil value",93,04,85,54))) {
HXLINE( 259)						return null();
            					}
            				}
            			}
HXLINE( 264)			 cpp::Reference<lua_State> l = this->lua;
HXDLIN( 264)			int v = ( (int)(luaResults) );
HXDLIN( 264)			 ::Dynamic ret = null();
HXDLIN( 264)			switch((int)(lua_type(l,v))){
            				case (int)0: {
HXLINE( 264)					ret = null();
            				}
            				break;
            				case (int)1: {
HXLINE( 264)					ret = (lua_toboolean(l,v) != 0);
            				}
            				break;
            				case (int)3: {
HXLINE( 264)					ret = lua_tonumber(l,v);
            				}
            				break;
            				case (int)4: {
HXLINE( 264)					ret = linc::lua::tostring(l,v);
            				}
            				break;
            				case (int)5: {
HXLINE( 264)					bool array = true;
HXDLIN( 264)					 ::Dynamic ret1 = null();
HXDLIN( 264)					lua_pushnil(l);
HXDLIN( 264)					while((lua_next(l,-2) != 0)){
HXLINE( 264)						if ((lua_type(l,-2) != 3)) {
HXLINE( 264)							array = false;
HXDLIN( 264)							lua_pop(l,2);
HXDLIN( 264)							goto _hx_goto_20;
            						}
HXDLIN( 264)						Float n = lua_tonumber(l,-2);
HXDLIN( 264)						if ((n != ::Std_obj::_hx_int(n))) {
HXLINE( 264)							array = false;
HXDLIN( 264)							lua_pop(l,2);
HXDLIN( 264)							goto _hx_goto_20;
            						}
HXDLIN( 264)						lua_pop(l,1);
            					}
            					_hx_goto_20:;
HXDLIN( 264)					if (array) {
HXLINE( 264)						::cpp::VirtualArray arr = ::cpp::VirtualArray_obj::__new(0);
HXDLIN( 264)						lua_pushnil(l);
HXDLIN( 264)						while((lua_next(l,-2) != 0)){
HXLINE( 264)							int index = (lua_tointeger(l,-2) - 1);
HXDLIN( 264)							 ::Dynamic ret = null();
HXDLIN( 264)							switch((int)(lua_type(l,-1))){
            								case (int)0: {
HXLINE( 264)									ret = null();
            								}
            								break;
            								case (int)1: {
HXLINE( 264)									ret = (lua_toboolean(l,-1) != 0);
            								}
            								break;
            								case (int)3: {
HXLINE( 264)									ret = lua_tonumber(l,-1);
            								}
            								break;
            								case (int)4: {
HXLINE( 264)									ret = linc::lua::tostring(l,-1);
            								}
            								break;
            								case (int)5: {
HXLINE( 264)									bool array = true;
HXDLIN( 264)									 ::Dynamic ret1 = null();
HXDLIN( 264)									lua_pushnil(l);
HXDLIN( 264)									while((lua_next(l,-2) != 0)){
HXLINE( 264)										if ((lua_type(l,-2) != 3)) {
HXLINE( 264)											array = false;
HXDLIN( 264)											lua_pop(l,2);
HXDLIN( 264)											goto _hx_goto_22;
            										}
HXDLIN( 264)										Float n = lua_tonumber(l,-2);
HXDLIN( 264)										if ((n != ::Std_obj::_hx_int(n))) {
HXLINE( 264)											array = false;
HXDLIN( 264)											lua_pop(l,2);
HXDLIN( 264)											goto _hx_goto_22;
            										}
HXDLIN( 264)										lua_pop(l,1);
            									}
            									_hx_goto_22:;
HXDLIN( 264)									if (array) {
HXLINE( 264)										::cpp::VirtualArray arr = ::cpp::VirtualArray_obj::__new(0);
HXDLIN( 264)										lua_pushnil(l);
HXDLIN( 264)										while((lua_next(l,-2) != 0)){
HXLINE( 264)											int index = (lua_tointeger(l,-2) - 1);
HXDLIN( 264)											arr->set(index,::llua::Convert_obj::fromLua(l,-1));
HXDLIN( 264)											lua_pop(l,1);
            										}
HXDLIN( 264)										ret1 = arr;
            									}
            									else {
HXLINE( 264)										 hx::Anon obj = hx::Anon_obj::Create();
HXDLIN( 264)										lua_pushnil(l);
HXDLIN( 264)										while((lua_next(l,-2) != 0)){
HXLINE( 264)											::String ret = ::Std_obj::string(::llua::Convert_obj::fromLua(l,-2));
HXDLIN( 264)											obj->hx::Anon_obj::Add(ret,::llua::Convert_obj::fromLua(l,-1));
HXDLIN( 264)											lua_pop(l,1);
            										}
HXDLIN( 264)										ret1 = obj;
            									}
HXDLIN( 264)									ret = ret1;
            								}
            								break;
            								default:{
HXLINE( 264)									ret = null();
HXDLIN( 264)									::haxe::Log_obj::trace(HX_("return value not supported\n",48,41,fb,c8),::hx::SourceInfo(HX_("llua/Convert.hx",6e,6a,e3,49),96,HX_("llua.Convert",31,b8,44,19),HX_("fromLua",6e,2a,fd,57)));
            								}
            							}
HXDLIN( 264)							arr->set(index,ret);
HXDLIN( 264)							lua_pop(l,1);
            						}
HXDLIN( 264)						ret1 = arr;
            					}
            					else {
HXLINE( 264)						 hx::Anon obj = hx::Anon_obj::Create();
HXDLIN( 264)						lua_pushnil(l);
HXDLIN( 264)						while((lua_next(l,-2) != 0)){
HXLINE( 264)							 ::Dynamic ret = null();
HXDLIN( 264)							switch((int)(lua_type(l,-2))){
            								case (int)0: {
HXLINE( 264)									ret = null();
            								}
            								break;
            								case (int)1: {
HXLINE( 264)									ret = (lua_toboolean(l,-2) != 0);
            								}
            								break;
            								case (int)3: {
HXLINE( 264)									ret = lua_tonumber(l,-2);
            								}
            								break;
            								case (int)4: {
HXLINE( 264)									ret = linc::lua::tostring(l,-2);
            								}
            								break;
            								case (int)5: {
HXLINE( 264)									bool array = true;
HXDLIN( 264)									 ::Dynamic ret1 = null();
HXDLIN( 264)									lua_pushnil(l);
HXDLIN( 264)									while((lua_next(l,-2) != 0)){
HXLINE( 264)										if ((lua_type(l,-2) != 3)) {
HXLINE( 264)											array = false;
HXDLIN( 264)											lua_pop(l,2);
HXDLIN( 264)											goto _hx_goto_26;
            										}
HXDLIN( 264)										Float n = lua_tonumber(l,-2);
HXDLIN( 264)										if ((n != ::Std_obj::_hx_int(n))) {
HXLINE( 264)											array = false;
HXDLIN( 264)											lua_pop(l,2);
HXDLIN( 264)											goto _hx_goto_26;
            										}
HXDLIN( 264)										lua_pop(l,1);
            									}
            									_hx_goto_26:;
HXDLIN( 264)									if (array) {
HXLINE( 264)										::cpp::VirtualArray arr = ::cpp::VirtualArray_obj::__new(0);
HXDLIN( 264)										lua_pushnil(l);
HXDLIN( 264)										while((lua_next(l,-2) != 0)){
HXLINE( 264)											int index = (lua_tointeger(l,-2) - 1);
HXDLIN( 264)											 ::Dynamic ret = null();
HXDLIN( 264)											switch((int)(lua_type(l,-1))){
            												case (int)0: {
HXLINE( 264)													ret = null();
            												}
            												break;
            												case (int)1: {
HXLINE( 264)													ret = (lua_toboolean(l,-1) != 0);
            												}
            												break;
            												case (int)3: {
HXLINE( 264)													ret = lua_tonumber(l,-1);
            												}
            												break;
            												case (int)4: {
HXLINE( 264)													ret = linc::lua::tostring(l,-1);
            												}
            												break;
            												case (int)5: {
HXLINE( 264)													bool array = true;
HXDLIN( 264)													 ::Dynamic ret1 = null();
HXDLIN( 264)													lua_pushnil(l);
HXDLIN( 264)													while((lua_next(l,-2) != 0)){
HXLINE( 264)														if ((lua_type(l,-2) != 3)) {
HXLINE( 264)															array = false;
HXDLIN( 264)															lua_pop(l,2);
HXDLIN( 264)															goto _hx_goto_28;
            														}
HXDLIN( 264)														Float n = lua_tonumber(l,-2);
HXDLIN( 264)														if ((n != ::Std_obj::_hx_int(n))) {
HXLINE( 264)															array = false;
HXDLIN( 264)															lua_pop(l,2);
HXDLIN( 264)															goto _hx_goto_28;
            														}
HXDLIN( 264)														lua_pop(l,1);
            													}
            													_hx_goto_28:;
HXDLIN( 264)													if (array) {
HXLINE( 264)														::cpp::VirtualArray arr = ::cpp::VirtualArray_obj::__new(0);
HXDLIN( 264)														lua_pushnil(l);
HXDLIN( 264)														while((lua_next(l,-2) != 0)){
HXLINE( 264)															int index = (lua_tointeger(l,-2) - 1);
HXDLIN( 264)															arr->set(index,::llua::Convert_obj::fromLua(l,-1));
HXDLIN( 264)															lua_pop(l,1);
            														}
HXDLIN( 264)														ret1 = arr;
            													}
            													else {
HXLINE( 264)														 hx::Anon obj = hx::Anon_obj::Create();
HXDLIN( 264)														lua_pushnil(l);
HXDLIN( 264)														while((lua_next(l,-2) != 0)){
HXLINE( 264)															::String ret = ::Std_obj::string(::llua::Convert_obj::fromLua(l,-2));
HXDLIN( 264)															obj->hx::Anon_obj::Add(ret,::llua::Convert_obj::fromLua(l,-1));
HXDLIN( 264)															lua_pop(l,1);
            														}
HXDLIN( 264)														ret1 = obj;
            													}
HXDLIN( 264)													ret = ret1;
            												}
            												break;
            												default:{
HXLINE( 264)													ret = null();
HXDLIN( 264)													::haxe::Log_obj::trace(HX_("return value not supported\n",48,41,fb,c8),::hx::SourceInfo(HX_("llua/Convert.hx",6e,6a,e3,49),96,HX_("llua.Convert",31,b8,44,19),HX_("fromLua",6e,2a,fd,57)));
            												}
            											}
HXDLIN( 264)											arr->set(index,ret);
HXDLIN( 264)											lua_pop(l,1);
            										}
HXDLIN( 264)										ret1 = arr;
            									}
            									else {
HXLINE( 264)										 hx::Anon obj = hx::Anon_obj::Create();
HXDLIN( 264)										lua_pushnil(l);
HXDLIN( 264)										while((lua_next(l,-2) != 0)){
HXLINE( 264)											 ::Dynamic ret = null();
HXDLIN( 264)											switch((int)(lua_type(l,-2))){
            												case (int)0: {
HXLINE( 264)													ret = null();
            												}
            												break;
            												case (int)1: {
HXLINE( 264)													ret = (lua_toboolean(l,-2) != 0);
            												}
            												break;
            												case (int)3: {
HXLINE( 264)													ret = lua_tonumber(l,-2);
            												}
            												break;
            												case (int)4: {
HXLINE( 264)													ret = linc::lua::tostring(l,-2);
            												}
            												break;
            												case (int)5: {
HXLINE( 264)													bool array = true;
HXDLIN( 264)													 ::Dynamic ret1 = null();
HXDLIN( 264)													lua_pushnil(l);
HXDLIN( 264)													while((lua_next(l,-2) != 0)){
HXLINE( 264)														if ((lua_type(l,-2) != 3)) {
HXLINE( 264)															array = false;
HXDLIN( 264)															lua_pop(l,2);
HXDLIN( 264)															goto _hx_goto_32;
            														}
HXDLIN( 264)														Float n = lua_tonumber(l,-2);
HXDLIN( 264)														if ((n != ::Std_obj::_hx_int(n))) {
HXLINE( 264)															array = false;
HXDLIN( 264)															lua_pop(l,2);
HXDLIN( 264)															goto _hx_goto_32;
            														}
HXDLIN( 264)														lua_pop(l,1);
            													}
            													_hx_goto_32:;
HXDLIN( 264)													if (array) {
HXLINE( 264)														::cpp::VirtualArray arr = ::cpp::VirtualArray_obj::__new(0);
HXDLIN( 264)														lua_pushnil(l);
HXDLIN( 264)														while((lua_next(l,-2) != 0)){
HXLINE( 264)															int index = (lua_tointeger(l,-2) - 1);
HXDLIN( 264)															arr->set(index,::llua::Convert_obj::fromLua(l,-1));
HXDLIN( 264)															lua_pop(l,1);
            														}
HXDLIN( 264)														ret1 = arr;
            													}
            													else {
HXLINE( 264)														 hx::Anon obj = hx::Anon_obj::Create();
HXDLIN( 264)														lua_pushnil(l);
HXDLIN( 264)														while((lua_next(l,-2) != 0)){
HXLINE( 264)															::String ret = ::Std_obj::string(::llua::Convert_obj::fromLua(l,-2));
HXDLIN( 264)															obj->hx::Anon_obj::Add(ret,::llua::Convert_obj::fromLua(l,-1));
HXDLIN( 264)															lua_pop(l,1);
            														}
HXDLIN( 264)														ret1 = obj;
            													}
HXDLIN( 264)													ret = ret1;
            												}
            												break;
            												default:{
HXLINE( 264)													ret = null();
HXDLIN( 264)													::haxe::Log_obj::trace(HX_("return value not supported\n",48,41,fb,c8),::hx::SourceInfo(HX_("llua/Convert.hx",6e,6a,e3,49),96,HX_("llua.Convert",31,b8,44,19),HX_("fromLua",6e,2a,fd,57)));
            												}
            											}
HXDLIN( 264)											::String ret1 = ::Std_obj::string(ret);
HXDLIN( 264)											 ::Dynamic ret2 = null();
HXDLIN( 264)											switch((int)(lua_type(l,-1))){
            												case (int)0: {
HXLINE( 264)													ret2 = null();
            												}
            												break;
            												case (int)1: {
HXLINE( 264)													ret2 = (lua_toboolean(l,-1) != 0);
            												}
            												break;
            												case (int)3: {
HXLINE( 264)													ret2 = lua_tonumber(l,-1);
            												}
            												break;
            												case (int)4: {
HXLINE( 264)													ret2 = linc::lua::tostring(l,-1);
            												}
            												break;
            												case (int)5: {
HXLINE( 264)													bool array = true;
HXDLIN( 264)													 ::Dynamic ret = null();
HXDLIN( 264)													lua_pushnil(l);
HXDLIN( 264)													while((lua_next(l,-2) != 0)){
HXLINE( 264)														if ((lua_type(l,-2) != 3)) {
HXLINE( 264)															array = false;
HXDLIN( 264)															lua_pop(l,2);
HXDLIN( 264)															goto _hx_goto_35;
            														}
HXDLIN( 264)														Float n = lua_tonumber(l,-2);
HXDLIN( 264)														if ((n != ::Std_obj::_hx_int(n))) {
HXLINE( 264)															array = false;
HXDLIN( 264)															lua_pop(l,2);
HXDLIN( 264)															goto _hx_goto_35;
            														}
HXDLIN( 264)														lua_pop(l,1);
            													}
            													_hx_goto_35:;
HXDLIN( 264)													if (array) {
HXLINE( 264)														::cpp::VirtualArray arr = ::cpp::VirtualArray_obj::__new(0);
HXDLIN( 264)														lua_pushnil(l);
HXDLIN( 264)														while((lua_next(l,-2) != 0)){
HXLINE( 264)															int index = (lua_tointeger(l,-2) - 1);
HXDLIN( 264)															arr->set(index,::llua::Convert_obj::fromLua(l,-1));
HXDLIN( 264)															lua_pop(l,1);
            														}
HXDLIN( 264)														ret = arr;
            													}
            													else {
HXLINE( 264)														 hx::Anon obj = hx::Anon_obj::Create();
HXDLIN( 264)														lua_pushnil(l);
HXDLIN( 264)														while((lua_next(l,-2) != 0)){
HXLINE( 264)															::String ret = ::Std_obj::string(::llua::Convert_obj::fromLua(l,-2));
HXDLIN( 264)															obj->hx::Anon_obj::Add(ret,::llua::Convert_obj::fromLua(l,-1));
HXDLIN( 264)															lua_pop(l,1);
            														}
HXDLIN( 264)														ret = obj;
            													}
HXDLIN( 264)													ret2 = ret;
            												}
            												break;
            												default:{
HXLINE( 264)													ret2 = null();
HXDLIN( 264)													::haxe::Log_obj::trace(HX_("return value not supported\n",48,41,fb,c8),::hx::SourceInfo(HX_("llua/Convert.hx",6e,6a,e3,49),96,HX_("llua.Convert",31,b8,44,19),HX_("fromLua",6e,2a,fd,57)));
            												}
            											}
HXDLIN( 264)											obj->hx::Anon_obj::Add(ret1,ret2);
HXDLIN( 264)											lua_pop(l,1);
            										}
HXDLIN( 264)										ret1 = obj;
            									}
HXDLIN( 264)									ret = ret1;
            								}
            								break;
            								default:{
HXLINE( 264)									ret = null();
HXDLIN( 264)									::haxe::Log_obj::trace(HX_("return value not supported\n",48,41,fb,c8),::hx::SourceInfo(HX_("llua/Convert.hx",6e,6a,e3,49),96,HX_("llua.Convert",31,b8,44,19),HX_("fromLua",6e,2a,fd,57)));
            								}
            							}
HXDLIN( 264)							::String ret1 = ::Std_obj::string(ret);
HXDLIN( 264)							 ::Dynamic ret2 = null();
HXDLIN( 264)							switch((int)(lua_type(l,-1))){
            								case (int)0: {
HXLINE( 264)									ret2 = null();
            								}
            								break;
            								case (int)1: {
HXLINE( 264)									ret2 = (lua_toboolean(l,-1) != 0);
            								}
            								break;
            								case (int)3: {
HXLINE( 264)									ret2 = lua_tonumber(l,-1);
            								}
            								break;
            								case (int)4: {
HXLINE( 264)									ret2 = linc::lua::tostring(l,-1);
            								}
            								break;
            								case (int)5: {
HXLINE( 264)									bool array = true;
HXDLIN( 264)									 ::Dynamic ret = null();
HXDLIN( 264)									lua_pushnil(l);
HXDLIN( 264)									while((lua_next(l,-2) != 0)){
HXLINE( 264)										if ((lua_type(l,-2) != 3)) {
HXLINE( 264)											array = false;
HXDLIN( 264)											lua_pop(l,2);
HXDLIN( 264)											goto _hx_goto_38;
            										}
HXDLIN( 264)										Float n = lua_tonumber(l,-2);
HXDLIN( 264)										if ((n != ::Std_obj::_hx_int(n))) {
HXLINE( 264)											array = false;
HXDLIN( 264)											lua_pop(l,2);
HXDLIN( 264)											goto _hx_goto_38;
            										}
HXDLIN( 264)										lua_pop(l,1);
            									}
            									_hx_goto_38:;
HXDLIN( 264)									if (array) {
HXLINE( 264)										::cpp::VirtualArray arr = ::cpp::VirtualArray_obj::__new(0);
HXDLIN( 264)										lua_pushnil(l);
HXDLIN( 264)										while((lua_next(l,-2) != 0)){
HXLINE( 264)											int index = (lua_tointeger(l,-2) - 1);
HXDLIN( 264)											arr->set(index,::llua::Convert_obj::fromLua(l,-1));
HXDLIN( 264)											lua_pop(l,1);
            										}
HXDLIN( 264)										ret = arr;
            									}
            									else {
HXLINE( 264)										 hx::Anon obj = hx::Anon_obj::Create();
HXDLIN( 264)										lua_pushnil(l);
HXDLIN( 264)										while((lua_next(l,-2) != 0)){
HXLINE( 264)											::String ret = ::Std_obj::string(::llua::Convert_obj::fromLua(l,-2));
HXDLIN( 264)											obj->hx::Anon_obj::Add(ret,::llua::Convert_obj::fromLua(l,-1));
HXDLIN( 264)											lua_pop(l,1);
            										}
HXDLIN( 264)										ret = obj;
            									}
HXDLIN( 264)									ret2 = ret;
            								}
            								break;
            								default:{
HXLINE( 264)									ret2 = null();
HXDLIN( 264)									::haxe::Log_obj::trace(HX_("return value not supported\n",48,41,fb,c8),::hx::SourceInfo(HX_("llua/Convert.hx",6e,6a,e3,49),96,HX_("llua.Convert",31,b8,44,19),HX_("fromLua",6e,2a,fd,57)));
            								}
            							}
HXDLIN( 264)							obj->hx::Anon_obj::Add(ret1,ret2);
HXDLIN( 264)							lua_pop(l,1);
            						}
HXDLIN( 264)						ret1 = obj;
            					}
HXDLIN( 264)					ret = ret1;
            				}
            				break;
            				default:{
HXLINE( 264)					ret = null();
HXDLIN( 264)					::haxe::Log_obj::trace(HX_("return value not supported\n",48,41,fb,c8),::hx::SourceInfo(HX_("llua/Convert.hx",6e,6a,e3,49),96,HX_("llua.Convert",31,b8,44,19),HX_("fromLua",6e,2a,fd,57)));
            				}
            			}
HXDLIN( 264)			 ::Dynamic output = ret;
HXLINE( 265)			return output;
            		}
HXLINE( 269)		return null();
            	}


HX_DEFINE_DYNAMIC_FUNC3(ModLua_obj,call,return )

 ::flixel::FlxSprite ModLua_obj::getSprite(::String name){
            	HX_STACKFRAME(&_hx_pos_cf04762c5f4ddd2d_272_getSprite)
HXLINE( 273)		 ::flixel::FlxSprite spr = ( ( ::flixel::FlxSprite)(this->luaSprites->get(name)) );
HXLINE( 275)		if (::hx::IsNull( spr )) {
HXLINE( 276)			 ::HelperStates curState = ::hx::TCast<  ::HelperStates >::cast(::flixel::FlxG_obj::game->_state);
HXLINE( 278)			if (curState->modifiableSprites->exists(name)) {
HXLINE( 279)				spr = ( ( ::flixel::FlxSprite)(curState->modifiableSprites->get(name)) );
            			}
            		}
HXLINE( 282)		return spr;
            	}


HX_DEFINE_DYNAMIC_FUNC1(ModLua_obj,getSprite,return )

void ModLua_obj::close(){
            	HX_STACKFRAME(&_hx_pos_cf04762c5f4ddd2d_285_close)
HXLINE( 287)		if (::hx::IsNull( this->lua )) {
HXLINE( 288)			return;
            		}
HXLINE( 291)		if (::hx::IsNotNull( this->luaSprites )) {
HXLINE( 292)			this->luaSprites->clear();
HXLINE( 293)			this->luaSprites = null();
            		}
HXLINE( 296)		if (::hx::IsNotNull( this->luaCameras )) {
HXLINE( 297)			this->luaCameras->clear();
HXLINE( 298)			this->luaCameras = null();
            		}
HXLINE( 301)		lua_close(this->lua);
HXLINE( 302)		this->lua = null();
            	}


HX_DEFINE_DYNAMIC_FUNC0(ModLua_obj,close,(void))

int ModLua_obj::convertToLua(::cpp::VirtualArray args,::hx::Null< int >  __o_index){
            		int index = __o_index.Default(0);
            	HX_STACKFRAME(&_hx_pos_cf04762c5f4ddd2d_310_convertToLua)
HXLINE( 311)		if ((index < args->get_length())) {
HXLINE( 312)			::llua::Convert_obj::toLua(this->lua,args->__get(index));
HXLINE( 313)			return this->convertToLua(args,(index + 1));
            		}
HXLINE( 316)		return 1;
            	}


HX_DEFINE_DYNAMIC_FUNC2(ModLua_obj,convertToLua,return )


::hx::ObjectPtr< ModLua_obj > ModLua_obj::__new(::String luaScript) {
	::hx::ObjectPtr< ModLua_obj > __this = new ModLua_obj();
	__this->__construct(luaScript);
	return __this;
}

::hx::ObjectPtr< ModLua_obj > ModLua_obj::__alloc(::hx::Ctx *_hx_ctx,::String luaScript) {
	ModLua_obj *__this = (ModLua_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(ModLua_obj), true, "ModLua"));
	*(void **)__this = ModLua_obj::_hx_vtable;
	__this->__construct(luaScript);
	return __this;
}

ModLua_obj::ModLua_obj()
{
}

void ModLua_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ModLua);
	HX_MARK_MEMBER_NAME(lua,"lua");
	HX_MARK_MEMBER_NAME(luaScript,"luaScript");
	HX_MARK_MEMBER_NAME(luaSprites,"luaSprites");
	HX_MARK_MEMBER_NAME(luaCameras,"luaCameras");
	HX_MARK_MEMBER_NAME(luaTweens,"luaTweens");
	HX_MARK_END_CLASS();
}

void ModLua_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(lua,"lua");
	HX_VISIT_MEMBER_NAME(luaScript,"luaScript");
	HX_VISIT_MEMBER_NAME(luaSprites,"luaSprites");
	HX_VISIT_MEMBER_NAME(luaCameras,"luaCameras");
	HX_VISIT_MEMBER_NAME(luaTweens,"luaTweens");
}

::hx::Val ModLua_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"lua") ) { return ::hx::Val( lua ); }
		if (HX_FIELD_EQ(inName,"set") ) { return ::hx::Val( set_dyn() ); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"call") ) { return ::hx::Val( call_dyn() ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"close") ) { return ::hx::Val( close_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"execute") ) { return ::hx::Val( execute_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"luaScript") ) { return ::hx::Val( luaScript ); }
		if (HX_FIELD_EQ(inName,"luaTweens") ) { return ::hx::Val( luaTweens ); }
		if (HX_FIELD_EQ(inName,"getSprite") ) { return ::hx::Val( getSprite_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"luaSprites") ) { return ::hx::Val( luaSprites ); }
		if (HX_FIELD_EQ(inName,"luaCameras") ) { return ::hx::Val( luaCameras ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"addCallback") ) { return ::hx::Val( addCallback_dyn() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"convertToLua") ) { return ::hx::Val( convertToLua_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val ModLua_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"lua") ) { lua=inValue.Cast<  cpp::Reference<lua_State> >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"luaScript") ) { luaScript=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"luaTweens") ) { luaTweens=inValue.Cast<  ::haxe::ds::StringMap >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"luaSprites") ) { luaSprites=inValue.Cast<  ::haxe::ds::StringMap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"luaCameras") ) { luaCameras=inValue.Cast<  ::haxe::ds::StringMap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ModLua_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("lua",b8,59,52,00));
	outFields->push(HX_("luaScript",e3,35,7d,5f));
	outFields->push(HX_("luaSprites",f6,9d,b8,60));
	outFields->push(HX_("luaCameras",56,7f,5f,e4));
	outFields->push(HX_("luaTweens",80,5b,41,41));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo ModLua_obj_sMemberStorageInfo[] = {
	{::hx::fsUnknown /*  cpp::Reference<lua_State> */ ,(int)offsetof(ModLua_obj,lua),HX_("lua",b8,59,52,00)},
	{::hx::fsString,(int)offsetof(ModLua_obj,luaScript),HX_("luaScript",e3,35,7d,5f)},
	{::hx::fsObject /*  ::haxe::ds::StringMap */ ,(int)offsetof(ModLua_obj,luaSprites),HX_("luaSprites",f6,9d,b8,60)},
	{::hx::fsObject /*  ::haxe::ds::StringMap */ ,(int)offsetof(ModLua_obj,luaCameras),HX_("luaCameras",56,7f,5f,e4)},
	{::hx::fsObject /*  ::haxe::ds::StringMap */ ,(int)offsetof(ModLua_obj,luaTweens),HX_("luaTweens",80,5b,41,41)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *ModLua_obj_sStaticStorageInfo = 0;
#endif

static ::String ModLua_obj_sMemberFields[] = {
	HX_("lua",b8,59,52,00),
	HX_("luaScript",e3,35,7d,5f),
	HX_("luaSprites",f6,9d,b8,60),
	HX_("luaCameras",56,7f,5f,e4),
	HX_("luaTweens",80,5b,41,41),
	HX_("execute",35,0a,0d,cc),
	HX_("addCallback",06,d1,62,b0),
	HX_("set",a2,9b,57,00),
	HX_("call",9e,18,ba,41),
	HX_("getSprite",3b,65,ec,3f),
	HX_("close",b8,17,63,48),
	HX_("convertToLua",0a,0c,db,46),
	::String(null()) };

::hx::Class ModLua_obj::__mClass;

void ModLua_obj::__register()
{
	ModLua_obj _hx_dummy;
	ModLua_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("ModLua",36,94,48,f5);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(ModLua_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< ModLua_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = ModLua_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = ModLua_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

