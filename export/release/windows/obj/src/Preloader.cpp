#include <hxcpp.h>

#ifndef INCLUDED_HelperStates
#include <HelperStates.h>
#endif
#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_Mod
#include <Mod.h>
#endif
#ifndef INCLUDED_MusicBeatState
#include <MusicBeatState.h>
#endif
#ifndef INCLUDED_Paths
#include <Paths.h>
#endif
#ifndef INCLUDED_Preloader
#include <Preloader.h>
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
#ifndef INCLUDED_TitleState
#include <TitleState.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_FlxGame
#include <flixel/FlxGame.h>
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
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_input_FlxPointer
#include <flixel/input/FlxPointer.h>
#endif
#ifndef INCLUDED_flixel_input_IFlxInputManager
#include <flixel/input/IFlxInputManager.h>
#endif
#ifndef INCLUDED_flixel_input_mouse_FlxMouse
#include <flixel/input/mouse/FlxMouse.h>
#endif
#ifndef INCLUDED_flixel_util_FlxSave
#include <flixel/util/FlxSave.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxDestroyable
#include <flixel/util/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_haxe_Exception
#include <haxe/Exception.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_format_JsonPrinter
#include <haxe/format/JsonPrinter.h>
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
#ifndef INCLUDED_openfl_display_DisplayObject
#include <openfl/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObjectContainer
#include <openfl/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_openfl_display_FPS
#include <openfl/display/FPS.h>
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
#ifndef INCLUDED_openfl_text_TextField
#include <openfl/text/TextField.h>
#endif
#ifndef INCLUDED_sys_io_File
#include <sys/io/File.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_312e3f7dfa8ca2c7_14_new,"Preloader","new",0x90324848,"Preloader.new","Preloader.hx",14,0xc73f5828)
HX_LOCAL_STACK_FRAME(_hx_pos_312e3f7dfa8ca2c7_15_create,"Preloader","create",0xecaed014,"Preloader.create","Preloader.hx",15,0xc73f5828)
HX_LOCAL_STACK_FRAME(_hx_pos_312e3f7dfa8ca2c7_55_update,"Preloader","update",0xf7a4ef21,"Preloader.update","Preloader.hx",55,0xc73f5828)

void Preloader_obj::__construct( ::Dynamic MaxSize){
            	HX_STACKFRAME(&_hx_pos_312e3f7dfa8ca2c7_14_new)
HXDLIN(  14)		super::__construct(MaxSize);
            	}

Dynamic Preloader_obj::__CreateEmpty() { return new Preloader_obj; }

void *Preloader_obj::_hx_vtable = 0;

Dynamic Preloader_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Preloader_obj > _hx_result = new Preloader_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool Preloader_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x62817b24) {
		if (inClassId<=(int)0x451fddce) {
			return inClassId==(int)0x00000001 || inClassId==(int)0x451fddce;
		} else {
			return inClassId==(int)0x62817b24;
		}
	} else {
		return inClassId==(int)0x7c795c9f || inClassId==(int)0x7ccf8994;
	}
}

void Preloader_obj::create(){
            	HX_GC_STACKFRAME(&_hx_pos_312e3f7dfa8ca2c7_15_create)
HXLINE(  16)		int fpsMulti;
HXDLIN(  16)		switch((int)(::SaveType_obj::FPS_MULTIPLIER_dyn()->_hx_getIndex())){
            			case (int)1: {
HXLINE(  16)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  16)					::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            				}
HXDLIN(  16)				fpsMulti = ( (int)(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic)) );
            			}
            			break;
            			case (int)2: {
HXLINE(  16)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  16)					::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            				}
            				else {
HXLINE(  16)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  16)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            				}
HXDLIN(  16)				fpsMulti = ( (int)(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)) );
            			}
            			break;
            			case (int)3: {
HXLINE(  16)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  16)					::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            				}
HXDLIN(  16)				fpsMulti = ( (int)(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic)) );
            			}
            			break;
            			case (int)4: {
HXLINE(  16)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  16)					::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            				}
HXDLIN(  16)				fpsMulti = ( (int)(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic)) );
            			}
            			break;
            			case (int)5: {
HXLINE(  16)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  16)					::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            				}
HXDLIN(  16)				fpsMulti = ( (int)(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic)) );
            			}
            			break;
            			case (int)6: {
HXLINE(  16)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  16)					::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  16)				fpsMulti = ( (int)(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic)) );
            			}
            			break;
            			case (int)7: {
HXLINE(  16)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  16)					::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  16)				fpsMulti = ( (int)(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic)) );
            			}
            			break;
            			case (int)8: {
HXLINE(  16)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  16)					::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            				}
HXDLIN(  16)				fpsMulti = ( (int)(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic)) );
            			}
            			break;
            			case (int)9: {
HXLINE(  16)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  16)					::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            				}
HXDLIN(  16)				fpsMulti = ( (int)(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic)) );
            			}
            			break;
            			case (int)10: {
HXLINE(  16)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  16)					::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            				}
HXDLIN(  16)				fpsMulti = ( (int)(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic)) );
            			}
            			break;
            			case (int)11: {
HXLINE(  16)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  16)					::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            				}
            				else {
HXLINE(  16)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  16)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            				}
HXDLIN(  16)				fpsMulti = ( (int)(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)) );
            			}
            			break;
            			case (int)12: {
HXLINE(  16)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  16)					::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            				}
HXDLIN(  16)				fpsMulti = ( (int)(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic)) );
            			}
            			break;
            			case (int)13: {
HXLINE(  16)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  16)					::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            				}
HXDLIN(  16)				fpsMulti = ( (int)(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic)) );
            			}
            			break;
            			case (int)14: {
HXLINE(  16)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  16)					::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            				}
HXDLIN(  16)				fpsMulti = ( (int)(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic)) );
            			}
            			break;
            			case (int)15: {
HXLINE(  16)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  16)					::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            				}
HXDLIN(  16)				fpsMulti = ( (int)(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic)) );
            			}
            			break;
            			case (int)16: {
HXLINE(  16)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  16)					::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            				}
HXDLIN(  16)				fpsMulti = ( (int)(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic)) );
            			}
            			break;
            			case (int)17: {
HXLINE(  16)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  16)					::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            				}
HXDLIN(  16)				fpsMulti = ( (int)(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic)) );
            			}
            			break;
            			case (int)18: {
HXLINE(  16)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  16)					::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            				}
HXDLIN(  16)				fpsMulti = ( (int)(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic)) );
            			}
            			break;
            			case (int)19: {
HXLINE(  16)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  16)					::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            				}
HXDLIN(  16)				fpsMulti = ( (int)(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic)) );
            			}
            			break;
            			case (int)20: {
HXLINE(  16)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  16)					::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            				}
HXDLIN(  16)				fpsMulti = ( (int)(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic)) );
            			}
            			break;
            			case (int)21: {
HXLINE(  16)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  16)					::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            				}
HXDLIN(  16)				fpsMulti = ( (int)(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic)) );
            			}
            			break;
            			default:{
HXLINE(  16)				fpsMulti = null();
            			}
            		}
HXLINE(  26)		 ::openfl::display::MovieClip _hx_tmp = ::openfl::Lib_obj::get_current();
HXDLIN(  26)		_hx_tmp->addChild( ::openfl::display::FPS_obj::__alloc( HX_CTX ,10,3,16777215));
HXLINE(  29)		::String library = null();
HXDLIN(  29)		::String _hx_tmp1;
HXDLIN(  29)		if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("feeshdata/",8a,24,9b,7f) + HX_("shaders",ae,81,86,5f)) + HX_(".",2e,00,00,00)) + HX_("json",28,42,68,46)),HX_("TEXT",ad,94,ba,37),library),null())) {
HXLINE(  29)			_hx_tmp1 = ::Paths_obj::getPath((((HX_("feeshdata/",8a,24,9b,7f) + HX_("shaders",ae,81,86,5f)) + HX_(".",2e,00,00,00)) + HX_("json",28,42,68,46)),HX_("TEXT",ad,94,ba,37),library);
            		}
            		else {
HXLINE(  29)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate file - ",63,30,27,df) + ((HX_("shaders",ae,81,86,5f) + HX_(".",2e,00,00,00)) + HX_("json",28,42,68,46)))));
            		}
HXDLIN(  29)		if ((::sys::io::File_obj::getContent(_hx_tmp1).length < 11)) {
HXLINE(  30)			::String library = null();
HXDLIN(  30)			::String _hx_tmp;
HXDLIN(  30)			if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("feeshdata/",8a,24,9b,7f) + HX_("shaders",ae,81,86,5f)) + HX_(".",2e,00,00,00)) + HX_("json",28,42,68,46)),HX_("TEXT",ad,94,ba,37),library),null())) {
HXLINE(  30)				_hx_tmp = ::Paths_obj::getPath((((HX_("feeshdata/",8a,24,9b,7f) + HX_("shaders",ae,81,86,5f)) + HX_(".",2e,00,00,00)) + HX_("json",28,42,68,46)),HX_("TEXT",ad,94,ba,37),library);
            			}
            			else {
HXLINE(  30)				HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate file - ",63,30,27,df) + ((HX_("shaders",ae,81,86,5f) + HX_(".",2e,00,00,00)) + HX_("json",28,42,68,46)))));
            			}
HXDLIN(  30)			 ::Dynamic replacer = null();
HXDLIN(  30)			::String space = null();
HXDLIN(  30)			::sys::io::File_obj::saveContent(_hx_tmp,::haxe::format::JsonPrinter_obj::print(::cpp::VirtualArray_obj::__new(5)->init(0,0)->init(1,0)->init(2,0)->init(3,0)->init(4,0),replacer,space));
            		}
HXLINE(  32)		::flixel::FlxG_obj::mouse->set_visible(false);
HXLINE(  34)		if ((fpsMulti < 1)) {
HXLINE(  35)			fpsMulti = 1;
            		}
HXLINE(  37)		::Main_obj::trueFramerate = ( (int)(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)) );
HXLINE(  38)		 ::openfl::display::Stage _hx_tmp2 = ::openfl::Lib_obj::get_current()->stage;
HXDLIN(  38)		_hx_tmp2->set_frameRate(( (Float)((::Main_obj::trueFramerate * fpsMulti)) ));
HXLINE(  40)		 ::Dynamic _hx_tmp3 = ::haxe::Log_obj::trace;
HXDLIN(  40)		::String _hx_tmp4 = (HX_("FPS: ",af,da,2c,83) + ::openfl::Lib_obj::get_current()->stage->get_frameRate());
HXDLIN(  40)		_hx_tmp3(_hx_tmp4,::hx::SourceInfo(HX_("build/Preloader.hx",e9,a2,e3,11),40,HX_("Preloader",56,c4,4e,24),HX_("create",fc,66,0f,7c)));
HXLINE(  42)		::flixel::FlxG_obj::autoPause = false;
HXLINE(  44)		this->super::create();
HXLINE(  46)		::Register_obj::setup();
HXLINE(  48)		{
HXLINE(  48)			 ::flixel::FlxState nextState =  ::TitleState_obj::__alloc( HX_CTX );
HXDLIN(  48)			if (::flixel::FlxG_obj::game->_state->switchTo(nextState)) {
HXLINE(  48)				::flixel::FlxG_obj::game->_requestedState = nextState;
            			}
            		}
HXLINE(  51)		::Mod_obj::onInit();
            	}


void Preloader_obj::update(Float elapsed){
            	HX_STACKFRAME(&_hx_pos_312e3f7dfa8ca2c7_55_update)
HXDLIN(  55)		this->super::update((elapsed / ( (Float)(2) )));
            	}



::hx::ObjectPtr< Preloader_obj > Preloader_obj::__new( ::Dynamic MaxSize) {
	::hx::ObjectPtr< Preloader_obj > __this = new Preloader_obj();
	__this->__construct(MaxSize);
	return __this;
}

::hx::ObjectPtr< Preloader_obj > Preloader_obj::__alloc(::hx::Ctx *_hx_ctx, ::Dynamic MaxSize) {
	Preloader_obj *__this = (Preloader_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Preloader_obj), true, "Preloader"));
	*(void **)__this = Preloader_obj::_hx_vtable;
	__this->__construct(MaxSize);
	return __this;
}

Preloader_obj::Preloader_obj()
{
}

::hx::Val Preloader_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return ::hx::Val( create_dyn() ); }
		if (HX_FIELD_EQ(inName,"update") ) { return ::hx::Val( update_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *Preloader_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *Preloader_obj_sStaticStorageInfo = 0;
#endif

static ::String Preloader_obj_sMemberFields[] = {
	HX_("create",fc,66,0f,7c),
	HX_("update",09,86,05,87),
	::String(null()) };

::hx::Class Preloader_obj::__mClass;

void Preloader_obj::__register()
{
	Preloader_obj _hx_dummy;
	Preloader_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("Preloader",56,c4,4e,24);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Preloader_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Preloader_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Preloader_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Preloader_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

