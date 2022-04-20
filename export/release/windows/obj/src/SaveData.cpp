#include <hxcpp.h>

#ifndef INCLUDED_SaveData
#include <SaveData.h>
#endif
#ifndef INCLUDED_SaveType
#include <SaveType.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_util_FlxSave
#include <flixel/util/FlxSave.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxDestroyable
#include <flixel/util/IFlxDestroyable.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_dc01e484f6679c8f_38_saveClient,"SaveData","saveClient",0xe3c3224f,"SaveData.saveClient","SaveData.hx",38,0x4f8f68f7)
HX_LOCAL_STACK_FRAME(_hx_pos_dc01e484f6679c8f_65_getData,"SaveData","getData",0xff183299,"SaveData.getData","SaveData.hx",65,0x4f8f68f7)

void SaveData_obj::__construct() { }

Dynamic SaveData_obj::__CreateEmpty() { return new SaveData_obj; }

void *SaveData_obj::_hx_vtable = 0;

Dynamic SaveData_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< SaveData_obj > _hx_result = new SaveData_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool SaveData_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x2b5f9ee7;
}

void SaveData_obj::saveClient(){
            	HX_STACKFRAME(&_hx_pos_dc01e484f6679c8f_38_saveClient)
HXLINE(  39)		 ::Dynamic _hx_tmp;
HXDLIN(  39)		switch((int)(::SaveType_obj::DOWNSCROLL_dyn()->_hx_getIndex())){
            			case (int)1: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            				}
HXDLIN(  39)				_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            			}
            			break;
            			case (int)2: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            				}
            				else {
HXLINE(  39)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  39)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            				}
HXDLIN(  39)				_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)3: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            				}
HXDLIN(  39)				_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            			}
            			break;
            			case (int)4: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            				}
HXDLIN(  39)				_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)5: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            				}
HXDLIN(  39)				_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            			}
            			break;
            			case (int)6: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  39)				_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)7: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  39)				_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)8: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            				}
HXDLIN(  39)				_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            			}
            			break;
            			case (int)9: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            				}
HXDLIN(  39)				_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            			}
            			break;
            			case (int)10: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            				}
HXDLIN(  39)				_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            			}
            			break;
            			case (int)11: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            				}
            				else {
HXLINE(  39)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  39)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            				}
HXDLIN(  39)				_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            			}
            			break;
            			case (int)12: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            				}
HXDLIN(  39)				_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            			}
            			break;
            			case (int)13: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            				}
HXDLIN(  39)				_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            			}
            			break;
            			case (int)14: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            				}
HXDLIN(  39)				_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            			}
            			break;
            			case (int)15: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            				}
HXDLIN(  39)				_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            			}
            			break;
            			case (int)16: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            				}
HXDLIN(  39)				_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)17: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            				}
HXDLIN(  39)				_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            			}
            			break;
            			case (int)18: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            				}
HXDLIN(  39)				_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            			}
            			break;
            			case (int)19: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            				}
HXDLIN(  39)				_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            			}
            			break;
            			case (int)20: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            				}
HXDLIN(  39)				_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            			}
            			break;
            			case (int)21: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            				}
HXDLIN(  39)				_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            			}
            			break;
            			default:{
HXLINE(  39)				_hx_tmp = null();
            			}
            		}
HXDLIN(  39)		::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),_hx_tmp,::hx::paccDynamic);
HXLINE(  40)		 ::Dynamic _hx_tmp1;
HXDLIN(  40)		switch((int)(::SaveType_obj::PRESET_KEYBINDS_dyn()->_hx_getIndex())){
            			case (int)1: {
HXLINE(  40)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  40)					::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            				}
HXDLIN(  40)				_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            			}
            			break;
            			case (int)2: {
HXLINE(  40)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  40)					::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            				}
            				else {
HXLINE(  40)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  40)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            				}
HXDLIN(  40)				_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)3: {
HXLINE(  40)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  40)					::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            				}
HXDLIN(  40)				_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            			}
            			break;
            			case (int)4: {
HXLINE(  40)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  40)					::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            				}
HXDLIN(  40)				_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)5: {
HXLINE(  40)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  40)					::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            				}
HXDLIN(  40)				_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            			}
            			break;
            			case (int)6: {
HXLINE(  40)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  40)					::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  40)				_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)7: {
HXLINE(  40)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  40)					::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  40)				_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)8: {
HXLINE(  40)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  40)					::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            				}
HXDLIN(  40)				_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            			}
            			break;
            			case (int)9: {
HXLINE(  40)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  40)					::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            				}
HXDLIN(  40)				_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            			}
            			break;
            			case (int)10: {
HXLINE(  40)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  40)					::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            				}
HXDLIN(  40)				_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            			}
            			break;
            			case (int)11: {
HXLINE(  40)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  40)					::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            				}
            				else {
HXLINE(  40)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  40)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            				}
HXDLIN(  40)				_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            			}
            			break;
            			case (int)12: {
HXLINE(  40)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  40)					::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            				}
HXDLIN(  40)				_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            			}
            			break;
            			case (int)13: {
HXLINE(  40)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  40)					::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            				}
HXDLIN(  40)				_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            			}
            			break;
            			case (int)14: {
HXLINE(  40)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  40)					::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            				}
HXDLIN(  40)				_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            			}
            			break;
            			case (int)15: {
HXLINE(  40)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  40)					::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            				}
HXDLIN(  40)				_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            			}
            			break;
            			case (int)16: {
HXLINE(  40)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  40)					::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            				}
HXDLIN(  40)				_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)17: {
HXLINE(  40)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  40)					::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            				}
HXDLIN(  40)				_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            			}
            			break;
            			case (int)18: {
HXLINE(  40)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  40)					::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            				}
HXDLIN(  40)				_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            			}
            			break;
            			case (int)19: {
HXLINE(  40)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  40)					::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            				}
HXDLIN(  40)				_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            			}
            			break;
            			case (int)20: {
HXLINE(  40)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  40)					::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            				}
HXDLIN(  40)				_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            			}
            			break;
            			case (int)21: {
HXLINE(  40)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  40)					::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            				}
HXDLIN(  40)				_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            			}
            			break;
            			default:{
HXLINE(  40)				_hx_tmp1 = null();
            			}
            		}
HXDLIN(  40)		::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),_hx_tmp1,::hx::paccDynamic);
HXLINE(  41)		 ::Dynamic _hx_tmp2;
HXDLIN(  41)		switch((int)(::SaveType_obj::PERFECT_MODE_MOD_dyn()->_hx_getIndex())){
            			case (int)1: {
HXLINE(  41)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  41)					::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            				}
HXDLIN(  41)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            			}
            			break;
            			case (int)2: {
HXLINE(  41)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  41)					::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            				}
            				else {
HXLINE(  41)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  41)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            				}
HXDLIN(  41)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)3: {
HXLINE(  41)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  41)					::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            				}
HXDLIN(  41)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            			}
            			break;
            			case (int)4: {
HXLINE(  41)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  41)					::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            				}
HXDLIN(  41)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)5: {
HXLINE(  41)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  41)					::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            				}
HXDLIN(  41)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            			}
            			break;
            			case (int)6: {
HXLINE(  41)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  41)					::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  41)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)7: {
HXLINE(  41)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  41)					::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  41)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)8: {
HXLINE(  41)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  41)					::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            				}
HXDLIN(  41)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            			}
            			break;
            			case (int)9: {
HXLINE(  41)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  41)					::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            				}
HXDLIN(  41)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            			}
            			break;
            			case (int)10: {
HXLINE(  41)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  41)					::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            				}
HXDLIN(  41)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            			}
            			break;
            			case (int)11: {
HXLINE(  41)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  41)					::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            				}
            				else {
HXLINE(  41)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  41)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            				}
HXDLIN(  41)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            			}
            			break;
            			case (int)12: {
HXLINE(  41)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  41)					::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            				}
HXDLIN(  41)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            			}
            			break;
            			case (int)13: {
HXLINE(  41)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  41)					::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            				}
HXDLIN(  41)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            			}
            			break;
            			case (int)14: {
HXLINE(  41)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  41)					::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            				}
HXDLIN(  41)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            			}
            			break;
            			case (int)15: {
HXLINE(  41)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  41)					::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            				}
HXDLIN(  41)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            			}
            			break;
            			case (int)16: {
HXLINE(  41)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  41)					::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            				}
HXDLIN(  41)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)17: {
HXLINE(  41)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  41)					::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            				}
HXDLIN(  41)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            			}
            			break;
            			case (int)18: {
HXLINE(  41)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  41)					::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            				}
HXDLIN(  41)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            			}
            			break;
            			case (int)19: {
HXLINE(  41)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  41)					::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            				}
HXDLIN(  41)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            			}
            			break;
            			case (int)20: {
HXLINE(  41)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  41)					::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            				}
HXDLIN(  41)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            			}
            			break;
            			case (int)21: {
HXLINE(  41)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  41)					::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            				}
HXDLIN(  41)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            			}
            			break;
            			default:{
HXLINE(  41)				_hx_tmp2 = null();
            			}
            		}
HXDLIN(  41)		::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),_hx_tmp2,::hx::paccDynamic);
HXLINE(  42)		 ::Dynamic _hx_tmp3;
HXDLIN(  42)		switch((int)(::SaveType_obj::FLIP_CHART_MOD_dyn()->_hx_getIndex())){
            			case (int)1: {
HXLINE(  42)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  42)					::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            				}
HXDLIN(  42)				_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            			}
            			break;
            			case (int)2: {
HXLINE(  42)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  42)					::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            				}
            				else {
HXLINE(  42)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  42)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            				}
HXDLIN(  42)				_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)3: {
HXLINE(  42)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  42)					::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            				}
HXDLIN(  42)				_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            			}
            			break;
            			case (int)4: {
HXLINE(  42)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  42)					::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            				}
HXDLIN(  42)				_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)5: {
HXLINE(  42)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  42)					::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            				}
HXDLIN(  42)				_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            			}
            			break;
            			case (int)6: {
HXLINE(  42)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  42)					::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  42)				_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)7: {
HXLINE(  42)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  42)					::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  42)				_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)8: {
HXLINE(  42)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  42)					::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            				}
HXDLIN(  42)				_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            			}
            			break;
            			case (int)9: {
HXLINE(  42)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  42)					::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            				}
HXDLIN(  42)				_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            			}
            			break;
            			case (int)10: {
HXLINE(  42)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  42)					::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            				}
HXDLIN(  42)				_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            			}
            			break;
            			case (int)11: {
HXLINE(  42)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  42)					::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            				}
            				else {
HXLINE(  42)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  42)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            				}
HXDLIN(  42)				_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            			}
            			break;
            			case (int)12: {
HXLINE(  42)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  42)					::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            				}
HXDLIN(  42)				_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            			}
            			break;
            			case (int)13: {
HXLINE(  42)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  42)					::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            				}
HXDLIN(  42)				_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            			}
            			break;
            			case (int)14: {
HXLINE(  42)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  42)					::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            				}
HXDLIN(  42)				_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            			}
            			break;
            			case (int)15: {
HXLINE(  42)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  42)					::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            				}
HXDLIN(  42)				_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            			}
            			break;
            			case (int)16: {
HXLINE(  42)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  42)					::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            				}
HXDLIN(  42)				_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)17: {
HXLINE(  42)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  42)					::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            				}
HXDLIN(  42)				_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            			}
            			break;
            			case (int)18: {
HXLINE(  42)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  42)					::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            				}
HXDLIN(  42)				_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            			}
            			break;
            			case (int)19: {
HXLINE(  42)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  42)					::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            				}
HXDLIN(  42)				_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            			}
            			break;
            			case (int)20: {
HXLINE(  42)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  42)					::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            				}
HXDLIN(  42)				_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            			}
            			break;
            			case (int)21: {
HXLINE(  42)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  42)					::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            				}
HXDLIN(  42)				_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            			}
            			break;
            			default:{
HXLINE(  42)				_hx_tmp3 = null();
            			}
            		}
HXDLIN(  42)		::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),_hx_tmp3,::hx::paccDynamic);
HXLINE(  43)		 ::Dynamic _hx_tmp4;
HXDLIN(  43)		switch((int)(::SaveType_obj::CUSTOM_HELL_MOD_dyn()->_hx_getIndex())){
            			case (int)1: {
HXLINE(  43)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  43)					::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            				}
HXDLIN(  43)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            			}
            			break;
            			case (int)2: {
HXLINE(  43)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  43)					::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            				}
            				else {
HXLINE(  43)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  43)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            				}
HXDLIN(  43)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)3: {
HXLINE(  43)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  43)					::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            				}
HXDLIN(  43)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            			}
            			break;
            			case (int)4: {
HXLINE(  43)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  43)					::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            				}
HXDLIN(  43)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)5: {
HXLINE(  43)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  43)					::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            				}
HXDLIN(  43)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            			}
            			break;
            			case (int)6: {
HXLINE(  43)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  43)					::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  43)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)7: {
HXLINE(  43)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  43)					::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  43)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)8: {
HXLINE(  43)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  43)					::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            				}
HXDLIN(  43)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            			}
            			break;
            			case (int)9: {
HXLINE(  43)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  43)					::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            				}
HXDLIN(  43)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            			}
            			break;
            			case (int)10: {
HXLINE(  43)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  43)					::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            				}
HXDLIN(  43)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            			}
            			break;
            			case (int)11: {
HXLINE(  43)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  43)					::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            				}
            				else {
HXLINE(  43)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  43)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            				}
HXDLIN(  43)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            			}
            			break;
            			case (int)12: {
HXLINE(  43)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  43)					::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            				}
HXDLIN(  43)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            			}
            			break;
            			case (int)13: {
HXLINE(  43)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  43)					::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            				}
HXDLIN(  43)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            			}
            			break;
            			case (int)14: {
HXLINE(  43)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  43)					::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            				}
HXDLIN(  43)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            			}
            			break;
            			case (int)15: {
HXLINE(  43)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  43)					::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            				}
HXDLIN(  43)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            			}
            			break;
            			case (int)16: {
HXLINE(  43)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  43)					::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            				}
HXDLIN(  43)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)17: {
HXLINE(  43)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  43)					::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            				}
HXDLIN(  43)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            			}
            			break;
            			case (int)18: {
HXLINE(  43)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  43)					::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            				}
HXDLIN(  43)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            			}
            			break;
            			case (int)19: {
HXLINE(  43)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  43)					::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            				}
HXDLIN(  43)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            			}
            			break;
            			case (int)20: {
HXLINE(  43)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  43)					::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            				}
HXDLIN(  43)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            			}
            			break;
            			case (int)21: {
HXLINE(  43)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  43)					::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            				}
HXDLIN(  43)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            			}
            			break;
            			default:{
HXLINE(  43)				_hx_tmp4 = null();
            			}
            		}
HXDLIN(  43)		::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),_hx_tmp4,::hx::paccDynamic);
HXLINE(  44)		 ::Dynamic _hx_tmp5;
HXDLIN(  44)		switch((int)(::SaveType_obj::FAIR_BATTLE_MOD_dyn()->_hx_getIndex())){
            			case (int)1: {
HXLINE(  44)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  44)					::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            				}
HXDLIN(  44)				_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            			}
            			break;
            			case (int)2: {
HXLINE(  44)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  44)					::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            				}
            				else {
HXLINE(  44)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  44)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            				}
HXDLIN(  44)				_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)3: {
HXLINE(  44)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  44)					::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            				}
HXDLIN(  44)				_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            			}
            			break;
            			case (int)4: {
HXLINE(  44)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  44)					::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            				}
HXDLIN(  44)				_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)5: {
HXLINE(  44)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  44)					::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            				}
HXDLIN(  44)				_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            			}
            			break;
            			case (int)6: {
HXLINE(  44)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  44)					::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  44)				_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)7: {
HXLINE(  44)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  44)					::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  44)				_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)8: {
HXLINE(  44)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  44)					::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            				}
HXDLIN(  44)				_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            			}
            			break;
            			case (int)9: {
HXLINE(  44)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  44)					::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            				}
HXDLIN(  44)				_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            			}
            			break;
            			case (int)10: {
HXLINE(  44)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  44)					::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            				}
HXDLIN(  44)				_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            			}
            			break;
            			case (int)11: {
HXLINE(  44)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  44)					::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            				}
            				else {
HXLINE(  44)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  44)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            				}
HXDLIN(  44)				_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            			}
            			break;
            			case (int)12: {
HXLINE(  44)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  44)					::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            				}
HXDLIN(  44)				_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            			}
            			break;
            			case (int)13: {
HXLINE(  44)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  44)					::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            				}
HXDLIN(  44)				_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            			}
            			break;
            			case (int)14: {
HXLINE(  44)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  44)					::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            				}
HXDLIN(  44)				_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            			}
            			break;
            			case (int)15: {
HXLINE(  44)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  44)					::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            				}
HXDLIN(  44)				_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            			}
            			break;
            			case (int)16: {
HXLINE(  44)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  44)					::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            				}
HXDLIN(  44)				_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)17: {
HXLINE(  44)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  44)					::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            				}
HXDLIN(  44)				_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            			}
            			break;
            			case (int)18: {
HXLINE(  44)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  44)					::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            				}
HXDLIN(  44)				_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            			}
            			break;
            			case (int)19: {
HXLINE(  44)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  44)					::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            				}
HXDLIN(  44)				_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            			}
            			break;
            			case (int)20: {
HXLINE(  44)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  44)					::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            				}
HXDLIN(  44)				_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            			}
            			break;
            			case (int)21: {
HXLINE(  44)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  44)					::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            				}
HXDLIN(  44)				_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            			}
            			break;
            			default:{
HXLINE(  44)				_hx_tmp5 = null();
            			}
            		}
HXDLIN(  44)		::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),_hx_tmp5,::hx::paccDynamic);
HXLINE(  45)		 ::Dynamic _hx_tmp6;
HXDLIN(  45)		switch((int)(::SaveType_obj::FADE_BATTLE_MOD_dyn()->_hx_getIndex())){
            			case (int)1: {
HXLINE(  45)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  45)					::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            				}
HXDLIN(  45)				_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            			}
            			break;
            			case (int)2: {
HXLINE(  45)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  45)					::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            				}
            				else {
HXLINE(  45)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  45)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            				}
HXDLIN(  45)				_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)3: {
HXLINE(  45)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  45)					::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            				}
HXDLIN(  45)				_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            			}
            			break;
            			case (int)4: {
HXLINE(  45)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  45)					::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            				}
HXDLIN(  45)				_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)5: {
HXLINE(  45)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  45)					::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            				}
HXDLIN(  45)				_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            			}
            			break;
            			case (int)6: {
HXLINE(  45)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  45)					::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  45)				_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)7: {
HXLINE(  45)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  45)					::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  45)				_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)8: {
HXLINE(  45)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  45)					::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            				}
HXDLIN(  45)				_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            			}
            			break;
            			case (int)9: {
HXLINE(  45)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  45)					::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            				}
HXDLIN(  45)				_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            			}
            			break;
            			case (int)10: {
HXLINE(  45)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  45)					::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            				}
HXDLIN(  45)				_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            			}
            			break;
            			case (int)11: {
HXLINE(  45)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  45)					::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            				}
            				else {
HXLINE(  45)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  45)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            				}
HXDLIN(  45)				_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            			}
            			break;
            			case (int)12: {
HXLINE(  45)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  45)					::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            				}
HXDLIN(  45)				_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            			}
            			break;
            			case (int)13: {
HXLINE(  45)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  45)					::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            				}
HXDLIN(  45)				_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            			}
            			break;
            			case (int)14: {
HXLINE(  45)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  45)					::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            				}
HXDLIN(  45)				_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            			}
            			break;
            			case (int)15: {
HXLINE(  45)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  45)					::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            				}
HXDLIN(  45)				_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            			}
            			break;
            			case (int)16: {
HXLINE(  45)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  45)					::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            				}
HXDLIN(  45)				_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)17: {
HXLINE(  45)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  45)					::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            				}
HXDLIN(  45)				_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            			}
            			break;
            			case (int)18: {
HXLINE(  45)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  45)					::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            				}
HXDLIN(  45)				_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            			}
            			break;
            			case (int)19: {
HXLINE(  45)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  45)					::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            				}
HXDLIN(  45)				_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            			}
            			break;
            			case (int)20: {
HXLINE(  45)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  45)					::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            				}
HXDLIN(  45)				_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            			}
            			break;
            			case (int)21: {
HXLINE(  45)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  45)					::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            				}
HXDLIN(  45)				_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            			}
            			break;
            			default:{
HXLINE(  45)				_hx_tmp6 = null();
            			}
            		}
HXDLIN(  45)		::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),_hx_tmp6,::hx::paccDynamic);
HXLINE(  46)		 ::Dynamic _hx_tmp7;
HXDLIN(  46)		switch((int)(::SaveType_obj::SHOW_BOTTOM_BAR_dyn()->_hx_getIndex())){
            			case (int)1: {
HXLINE(  46)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  46)					::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            				}
HXDLIN(  46)				_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            			}
            			break;
            			case (int)2: {
HXLINE(  46)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  46)					::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            				}
            				else {
HXLINE(  46)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  46)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            				}
HXDLIN(  46)				_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)3: {
HXLINE(  46)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  46)					::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            				}
HXDLIN(  46)				_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            			}
            			break;
            			case (int)4: {
HXLINE(  46)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  46)					::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            				}
HXDLIN(  46)				_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)5: {
HXLINE(  46)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  46)					::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            				}
HXDLIN(  46)				_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            			}
            			break;
            			case (int)6: {
HXLINE(  46)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  46)					::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  46)				_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)7: {
HXLINE(  46)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  46)					::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  46)				_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)8: {
HXLINE(  46)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  46)					::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            				}
HXDLIN(  46)				_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            			}
            			break;
            			case (int)9: {
HXLINE(  46)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  46)					::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            				}
HXDLIN(  46)				_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            			}
            			break;
            			case (int)10: {
HXLINE(  46)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  46)					::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            				}
HXDLIN(  46)				_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            			}
            			break;
            			case (int)11: {
HXLINE(  46)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  46)					::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            				}
            				else {
HXLINE(  46)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  46)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            				}
HXDLIN(  46)				_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            			}
            			break;
            			case (int)12: {
HXLINE(  46)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  46)					::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            				}
HXDLIN(  46)				_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            			}
            			break;
            			case (int)13: {
HXLINE(  46)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  46)					::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            				}
HXDLIN(  46)				_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            			}
            			break;
            			case (int)14: {
HXLINE(  46)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  46)					::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            				}
HXDLIN(  46)				_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            			}
            			break;
            			case (int)15: {
HXLINE(  46)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  46)					::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            				}
HXDLIN(  46)				_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            			}
            			break;
            			case (int)16: {
HXLINE(  46)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  46)					::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            				}
HXDLIN(  46)				_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)17: {
HXLINE(  46)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  46)					::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            				}
HXDLIN(  46)				_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            			}
            			break;
            			case (int)18: {
HXLINE(  46)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  46)					::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            				}
HXDLIN(  46)				_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            			}
            			break;
            			case (int)19: {
HXLINE(  46)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  46)					::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            				}
HXDLIN(  46)				_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            			}
            			break;
            			case (int)20: {
HXLINE(  46)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  46)					::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            				}
HXDLIN(  46)				_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            			}
            			break;
            			case (int)21: {
HXLINE(  46)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  46)					::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            				}
HXDLIN(  46)				_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            			}
            			break;
            			default:{
HXLINE(  46)				_hx_tmp7 = null();
            			}
            		}
HXDLIN(  46)		::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),_hx_tmp7,::hx::paccDynamic);
HXLINE(  47)		 ::Dynamic _hx_tmp8;
HXDLIN(  47)		switch((int)(::SaveType_obj::SHOW_NOTE_SPLASH_dyn()->_hx_getIndex())){
            			case (int)1: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            				}
HXDLIN(  47)				_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            			}
            			break;
            			case (int)2: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            				}
            				else {
HXLINE(  47)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  47)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            				}
HXDLIN(  47)				_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)3: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            				}
HXDLIN(  47)				_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            			}
            			break;
            			case (int)4: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            				}
HXDLIN(  47)				_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)5: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            				}
HXDLIN(  47)				_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            			}
            			break;
            			case (int)6: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  47)				_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)7: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  47)				_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)8: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            				}
HXDLIN(  47)				_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            			}
            			break;
            			case (int)9: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            				}
HXDLIN(  47)				_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            			}
            			break;
            			case (int)10: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            				}
HXDLIN(  47)				_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            			}
            			break;
            			case (int)11: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            				}
            				else {
HXLINE(  47)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  47)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            				}
HXDLIN(  47)				_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            			}
            			break;
            			case (int)12: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            				}
HXDLIN(  47)				_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            			}
            			break;
            			case (int)13: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            				}
HXDLIN(  47)				_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            			}
            			break;
            			case (int)14: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            				}
HXDLIN(  47)				_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            			}
            			break;
            			case (int)15: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            				}
HXDLIN(  47)				_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            			}
            			break;
            			case (int)16: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            				}
HXDLIN(  47)				_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)17: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            				}
HXDLIN(  47)				_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            			}
            			break;
            			case (int)18: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            				}
HXDLIN(  47)				_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            			}
            			break;
            			case (int)19: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            				}
HXDLIN(  47)				_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            			}
            			break;
            			case (int)20: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            				}
HXDLIN(  47)				_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            			}
            			break;
            			case (int)21: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            				}
HXDLIN(  47)				_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            			}
            			break;
            			default:{
HXLINE(  47)				_hx_tmp8 = null();
            			}
            		}
HXDLIN(  47)		::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),_hx_tmp8,::hx::paccDynamic);
HXLINE(  48)		 ::Dynamic _hx_tmp9;
HXDLIN(  48)		switch((int)(::SaveType_obj::GRAPHICS_dyn()->_hx_getIndex())){
            			case (int)1: {
HXLINE(  48)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  48)					::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            				}
HXDLIN(  48)				_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            			}
            			break;
            			case (int)2: {
HXLINE(  48)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  48)					::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            				}
            				else {
HXLINE(  48)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  48)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            				}
HXDLIN(  48)				_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)3: {
HXLINE(  48)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  48)					::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            				}
HXDLIN(  48)				_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            			}
            			break;
            			case (int)4: {
HXLINE(  48)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  48)					::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            				}
HXDLIN(  48)				_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)5: {
HXLINE(  48)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  48)					::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            				}
HXDLIN(  48)				_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            			}
            			break;
            			case (int)6: {
HXLINE(  48)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  48)					::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  48)				_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)7: {
HXLINE(  48)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  48)					::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  48)				_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)8: {
HXLINE(  48)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  48)					::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            				}
HXDLIN(  48)				_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            			}
            			break;
            			case (int)9: {
HXLINE(  48)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  48)					::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            				}
HXDLIN(  48)				_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            			}
            			break;
            			case (int)10: {
HXLINE(  48)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  48)					::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            				}
HXDLIN(  48)				_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            			}
            			break;
            			case (int)11: {
HXLINE(  48)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  48)					::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            				}
            				else {
HXLINE(  48)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  48)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            				}
HXDLIN(  48)				_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            			}
            			break;
            			case (int)12: {
HXLINE(  48)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  48)					::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            				}
HXDLIN(  48)				_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            			}
            			break;
            			case (int)13: {
HXLINE(  48)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  48)					::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            				}
HXDLIN(  48)				_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            			}
            			break;
            			case (int)14: {
HXLINE(  48)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  48)					::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            				}
HXDLIN(  48)				_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            			}
            			break;
            			case (int)15: {
HXLINE(  48)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  48)					::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            				}
HXDLIN(  48)				_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            			}
            			break;
            			case (int)16: {
HXLINE(  48)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  48)					::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            				}
HXDLIN(  48)				_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)17: {
HXLINE(  48)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  48)					::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            				}
HXDLIN(  48)				_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            			}
            			break;
            			case (int)18: {
HXLINE(  48)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  48)					::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            				}
HXDLIN(  48)				_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            			}
            			break;
            			case (int)19: {
HXLINE(  48)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  48)					::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            				}
HXDLIN(  48)				_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            			}
            			break;
            			case (int)20: {
HXLINE(  48)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  48)					::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            				}
HXDLIN(  48)				_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            			}
            			break;
            			case (int)21: {
HXLINE(  48)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  48)					::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            				}
HXDLIN(  48)				_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            			}
            			break;
            			default:{
HXLINE(  48)				_hx_tmp9 = null();
            			}
            		}
HXDLIN(  48)		::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),_hx_tmp9,::hx::paccDynamic);
HXLINE(  49)		 ::Dynamic _hx_tmp10;
HXDLIN(  49)		switch((int)(::SaveType_obj::SET_FPS_DEFAULT_dyn()->_hx_getIndex())){
            			case (int)1: {
HXLINE(  49)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  49)					::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            				}
HXDLIN(  49)				_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            			}
            			break;
            			case (int)2: {
HXLINE(  49)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  49)					::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            				}
            				else {
HXLINE(  49)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  49)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            				}
HXDLIN(  49)				_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)3: {
HXLINE(  49)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  49)					::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            				}
HXDLIN(  49)				_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            			}
            			break;
            			case (int)4: {
HXLINE(  49)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  49)					::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            				}
HXDLIN(  49)				_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)5: {
HXLINE(  49)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  49)					::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            				}
HXDLIN(  49)				_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            			}
            			break;
            			case (int)6: {
HXLINE(  49)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  49)					::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  49)				_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)7: {
HXLINE(  49)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  49)					::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  49)				_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)8: {
HXLINE(  49)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  49)					::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            				}
HXDLIN(  49)				_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            			}
            			break;
            			case (int)9: {
HXLINE(  49)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  49)					::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            				}
HXDLIN(  49)				_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            			}
            			break;
            			case (int)10: {
HXLINE(  49)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  49)					::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            				}
HXDLIN(  49)				_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            			}
            			break;
            			case (int)11: {
HXLINE(  49)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  49)					::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            				}
            				else {
HXLINE(  49)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  49)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            				}
HXDLIN(  49)				_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            			}
            			break;
            			case (int)12: {
HXLINE(  49)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  49)					::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            				}
HXDLIN(  49)				_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            			}
            			break;
            			case (int)13: {
HXLINE(  49)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  49)					::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            				}
HXDLIN(  49)				_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            			}
            			break;
            			case (int)14: {
HXLINE(  49)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  49)					::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            				}
HXDLIN(  49)				_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            			}
            			break;
            			case (int)15: {
HXLINE(  49)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  49)					::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            				}
HXDLIN(  49)				_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            			}
            			break;
            			case (int)16: {
HXLINE(  49)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  49)					::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            				}
HXDLIN(  49)				_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)17: {
HXLINE(  49)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  49)					::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            				}
HXDLIN(  49)				_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            			}
            			break;
            			case (int)18: {
HXLINE(  49)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  49)					::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            				}
HXDLIN(  49)				_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            			}
            			break;
            			case (int)19: {
HXLINE(  49)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  49)					::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            				}
HXDLIN(  49)				_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            			}
            			break;
            			case (int)20: {
HXLINE(  49)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  49)					::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            				}
HXDLIN(  49)				_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            			}
            			break;
            			case (int)21: {
HXLINE(  49)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  49)					::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            				}
HXDLIN(  49)				_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            			}
            			break;
            			default:{
HXLINE(  49)				_hx_tmp10 = null();
            			}
            		}
HXDLIN(  49)		::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),_hx_tmp10,::hx::paccDynamic);
HXLINE(  50)		 ::Dynamic _hx_tmp11;
HXDLIN(  50)		switch((int)(::SaveType_obj::FPS_MULTIPLIER_dyn()->_hx_getIndex())){
            			case (int)1: {
HXLINE(  50)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  50)					::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            				}
HXDLIN(  50)				_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            			}
            			break;
            			case (int)2: {
HXLINE(  50)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  50)					::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            				}
            				else {
HXLINE(  50)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  50)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            				}
HXDLIN(  50)				_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)3: {
HXLINE(  50)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  50)					::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            				}
HXDLIN(  50)				_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            			}
            			break;
            			case (int)4: {
HXLINE(  50)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  50)					::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            				}
HXDLIN(  50)				_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)5: {
HXLINE(  50)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  50)					::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            				}
HXDLIN(  50)				_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            			}
            			break;
            			case (int)6: {
HXLINE(  50)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  50)					::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  50)				_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)7: {
HXLINE(  50)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  50)					::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  50)				_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)8: {
HXLINE(  50)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  50)					::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            				}
HXDLIN(  50)				_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            			}
            			break;
            			case (int)9: {
HXLINE(  50)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  50)					::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            				}
HXDLIN(  50)				_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            			}
            			break;
            			case (int)10: {
HXLINE(  50)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  50)					::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            				}
HXDLIN(  50)				_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            			}
            			break;
            			case (int)11: {
HXLINE(  50)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  50)					::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            				}
            				else {
HXLINE(  50)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  50)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            				}
HXDLIN(  50)				_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            			}
            			break;
            			case (int)12: {
HXLINE(  50)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  50)					::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            				}
HXDLIN(  50)				_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            			}
            			break;
            			case (int)13: {
HXLINE(  50)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  50)					::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            				}
HXDLIN(  50)				_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            			}
            			break;
            			case (int)14: {
HXLINE(  50)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  50)					::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            				}
HXDLIN(  50)				_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            			}
            			break;
            			case (int)15: {
HXLINE(  50)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  50)					::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            				}
HXDLIN(  50)				_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            			}
            			break;
            			case (int)16: {
HXLINE(  50)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  50)					::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            				}
HXDLIN(  50)				_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)17: {
HXLINE(  50)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  50)					::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            				}
HXDLIN(  50)				_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            			}
            			break;
            			case (int)18: {
HXLINE(  50)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  50)					::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            				}
HXDLIN(  50)				_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            			}
            			break;
            			case (int)19: {
HXLINE(  50)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  50)					::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            				}
HXDLIN(  50)				_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            			}
            			break;
            			case (int)20: {
HXLINE(  50)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  50)					::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            				}
HXDLIN(  50)				_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            			}
            			break;
            			case (int)21: {
HXLINE(  50)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  50)					::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            				}
HXDLIN(  50)				_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            			}
            			break;
            			default:{
HXLINE(  50)				_hx_tmp11 = null();
            			}
            		}
HXDLIN(  50)		::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),_hx_tmp11,::hx::paccDynamic);
HXLINE(  51)		 ::Dynamic _hx_tmp12;
HXDLIN(  51)		switch((int)(::SaveType_obj::NO_BLUE_BALLS_MOD_dyn()->_hx_getIndex())){
            			case (int)1: {
HXLINE(  51)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  51)					::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            				}
HXDLIN(  51)				_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            			}
            			break;
            			case (int)2: {
HXLINE(  51)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  51)					::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            				}
            				else {
HXLINE(  51)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  51)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            				}
HXDLIN(  51)				_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)3: {
HXLINE(  51)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  51)					::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            				}
HXDLIN(  51)				_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            			}
            			break;
            			case (int)4: {
HXLINE(  51)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  51)					::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            				}
HXDLIN(  51)				_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)5: {
HXLINE(  51)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  51)					::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            				}
HXDLIN(  51)				_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            			}
            			break;
            			case (int)6: {
HXLINE(  51)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  51)					::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  51)				_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)7: {
HXLINE(  51)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  51)					::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  51)				_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)8: {
HXLINE(  51)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  51)					::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            				}
HXDLIN(  51)				_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            			}
            			break;
            			case (int)9: {
HXLINE(  51)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  51)					::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            				}
HXDLIN(  51)				_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            			}
            			break;
            			case (int)10: {
HXLINE(  51)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  51)					::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            				}
HXDLIN(  51)				_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            			}
            			break;
            			case (int)11: {
HXLINE(  51)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  51)					::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            				}
            				else {
HXLINE(  51)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  51)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            				}
HXDLIN(  51)				_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            			}
            			break;
            			case (int)12: {
HXLINE(  51)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  51)					::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            				}
HXDLIN(  51)				_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            			}
            			break;
            			case (int)13: {
HXLINE(  51)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  51)					::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            				}
HXDLIN(  51)				_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            			}
            			break;
            			case (int)14: {
HXLINE(  51)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  51)					::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            				}
HXDLIN(  51)				_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            			}
            			break;
            			case (int)15: {
HXLINE(  51)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  51)					::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            				}
HXDLIN(  51)				_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            			}
            			break;
            			case (int)16: {
HXLINE(  51)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  51)					::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            				}
HXDLIN(  51)				_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)17: {
HXLINE(  51)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  51)					::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            				}
HXDLIN(  51)				_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            			}
            			break;
            			case (int)18: {
HXLINE(  51)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  51)					::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            				}
HXDLIN(  51)				_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            			}
            			break;
            			case (int)19: {
HXLINE(  51)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  51)					::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            				}
HXDLIN(  51)				_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            			}
            			break;
            			case (int)20: {
HXLINE(  51)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  51)					::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            				}
HXDLIN(  51)				_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            			}
            			break;
            			case (int)21: {
HXLINE(  51)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  51)					::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            				}
HXDLIN(  51)				_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            			}
            			break;
            			default:{
HXLINE(  51)				_hx_tmp12 = null();
            			}
            		}
HXDLIN(  51)		::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),_hx_tmp12,::hx::paccDynamic);
HXLINE(  52)		 ::Dynamic _hx_tmp13;
HXDLIN(  52)		switch((int)(::SaveType_obj::BLIND_MOD_dyn()->_hx_getIndex())){
            			case (int)1: {
HXLINE(  52)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  52)					::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            				}
HXDLIN(  52)				_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            			}
            			break;
            			case (int)2: {
HXLINE(  52)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  52)					::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            				}
            				else {
HXLINE(  52)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  52)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            				}
HXDLIN(  52)				_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)3: {
HXLINE(  52)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  52)					::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            				}
HXDLIN(  52)				_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            			}
            			break;
            			case (int)4: {
HXLINE(  52)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  52)					::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            				}
HXDLIN(  52)				_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)5: {
HXLINE(  52)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  52)					::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            				}
HXDLIN(  52)				_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            			}
            			break;
            			case (int)6: {
HXLINE(  52)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  52)					::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  52)				_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)7: {
HXLINE(  52)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  52)					::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  52)				_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)8: {
HXLINE(  52)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  52)					::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            				}
HXDLIN(  52)				_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            			}
            			break;
            			case (int)9: {
HXLINE(  52)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  52)					::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            				}
HXDLIN(  52)				_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            			}
            			break;
            			case (int)10: {
HXLINE(  52)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  52)					::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            				}
HXDLIN(  52)				_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            			}
            			break;
            			case (int)11: {
HXLINE(  52)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  52)					::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            				}
            				else {
HXLINE(  52)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  52)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            				}
HXDLIN(  52)				_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            			}
            			break;
            			case (int)12: {
HXLINE(  52)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  52)					::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            				}
HXDLIN(  52)				_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            			}
            			break;
            			case (int)13: {
HXLINE(  52)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  52)					::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            				}
HXDLIN(  52)				_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            			}
            			break;
            			case (int)14: {
HXLINE(  52)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  52)					::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            				}
HXDLIN(  52)				_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            			}
            			break;
            			case (int)15: {
HXLINE(  52)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  52)					::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            				}
HXDLIN(  52)				_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            			}
            			break;
            			case (int)16: {
HXLINE(  52)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  52)					::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            				}
HXDLIN(  52)				_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)17: {
HXLINE(  52)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  52)					::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            				}
HXDLIN(  52)				_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            			}
            			break;
            			case (int)18: {
HXLINE(  52)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  52)					::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            				}
HXDLIN(  52)				_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            			}
            			break;
            			case (int)19: {
HXLINE(  52)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  52)					::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            				}
HXDLIN(  52)				_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            			}
            			break;
            			case (int)20: {
HXLINE(  52)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  52)					::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            				}
HXDLIN(  52)				_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            			}
            			break;
            			case (int)21: {
HXLINE(  52)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  52)					::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            				}
HXDLIN(  52)				_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            			}
            			break;
            			default:{
HXLINE(  52)				_hx_tmp13 = null();
            			}
            		}
HXDLIN(  52)		::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),_hx_tmp13,::hx::paccDynamic);
HXLINE(  53)		 ::Dynamic _hx_tmp14;
HXDLIN(  53)		switch((int)(::SaveType_obj::X_WOBBLE_MOD_dyn()->_hx_getIndex())){
            			case (int)1: {
HXLINE(  53)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  53)					::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            				}
HXDLIN(  53)				_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            			}
            			break;
            			case (int)2: {
HXLINE(  53)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  53)					::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            				}
            				else {
HXLINE(  53)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  53)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            				}
HXDLIN(  53)				_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)3: {
HXLINE(  53)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  53)					::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            				}
HXDLIN(  53)				_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            			}
            			break;
            			case (int)4: {
HXLINE(  53)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  53)					::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            				}
HXDLIN(  53)				_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)5: {
HXLINE(  53)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  53)					::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            				}
HXDLIN(  53)				_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            			}
            			break;
            			case (int)6: {
HXLINE(  53)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  53)					::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  53)				_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)7: {
HXLINE(  53)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  53)					::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  53)				_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)8: {
HXLINE(  53)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  53)					::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            				}
HXDLIN(  53)				_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            			}
            			break;
            			case (int)9: {
HXLINE(  53)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  53)					::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            				}
HXDLIN(  53)				_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            			}
            			break;
            			case (int)10: {
HXLINE(  53)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  53)					::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            				}
HXDLIN(  53)				_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            			}
            			break;
            			case (int)11: {
HXLINE(  53)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  53)					::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            				}
            				else {
HXLINE(  53)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  53)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            				}
HXDLIN(  53)				_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            			}
            			break;
            			case (int)12: {
HXLINE(  53)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  53)					::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            				}
HXDLIN(  53)				_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            			}
            			break;
            			case (int)13: {
HXLINE(  53)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  53)					::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            				}
HXDLIN(  53)				_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            			}
            			break;
            			case (int)14: {
HXLINE(  53)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  53)					::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            				}
HXDLIN(  53)				_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            			}
            			break;
            			case (int)15: {
HXLINE(  53)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  53)					::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            				}
HXDLIN(  53)				_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            			}
            			break;
            			case (int)16: {
HXLINE(  53)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  53)					::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            				}
HXDLIN(  53)				_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)17: {
HXLINE(  53)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  53)					::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            				}
HXDLIN(  53)				_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            			}
            			break;
            			case (int)18: {
HXLINE(  53)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  53)					::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            				}
HXDLIN(  53)				_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            			}
            			break;
            			case (int)19: {
HXLINE(  53)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  53)					::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            				}
HXDLIN(  53)				_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            			}
            			break;
            			case (int)20: {
HXLINE(  53)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  53)					::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            				}
HXDLIN(  53)				_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            			}
            			break;
            			case (int)21: {
HXLINE(  53)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  53)					::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            				}
HXDLIN(  53)				_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            			}
            			break;
            			default:{
HXLINE(  53)				_hx_tmp14 = null();
            			}
            		}
HXDLIN(  53)		::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),_hx_tmp14,::hx::paccDynamic);
HXLINE(  54)		 ::Dynamic _hx_tmp15;
HXDLIN(  54)		switch((int)(::SaveType_obj::PRESET_INPUTS_dyn()->_hx_getIndex())){
            			case (int)1: {
HXLINE(  54)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  54)					::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            				}
HXDLIN(  54)				_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            			}
            			break;
            			case (int)2: {
HXLINE(  54)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  54)					::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            				}
            				else {
HXLINE(  54)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  54)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            				}
HXDLIN(  54)				_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)3: {
HXLINE(  54)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  54)					::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            				}
HXDLIN(  54)				_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            			}
            			break;
            			case (int)4: {
HXLINE(  54)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  54)					::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            				}
HXDLIN(  54)				_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)5: {
HXLINE(  54)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  54)					::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            				}
HXDLIN(  54)				_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            			}
            			break;
            			case (int)6: {
HXLINE(  54)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  54)					::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  54)				_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)7: {
HXLINE(  54)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  54)					::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  54)				_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)8: {
HXLINE(  54)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  54)					::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            				}
HXDLIN(  54)				_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            			}
            			break;
            			case (int)9: {
HXLINE(  54)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  54)					::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            				}
HXDLIN(  54)				_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            			}
            			break;
            			case (int)10: {
HXLINE(  54)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  54)					::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            				}
HXDLIN(  54)				_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            			}
            			break;
            			case (int)11: {
HXLINE(  54)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  54)					::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            				}
            				else {
HXLINE(  54)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  54)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            				}
HXDLIN(  54)				_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            			}
            			break;
            			case (int)12: {
HXLINE(  54)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  54)					::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            				}
HXDLIN(  54)				_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            			}
            			break;
            			case (int)13: {
HXLINE(  54)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  54)					::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            				}
HXDLIN(  54)				_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            			}
            			break;
            			case (int)14: {
HXLINE(  54)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  54)					::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            				}
HXDLIN(  54)				_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            			}
            			break;
            			case (int)15: {
HXLINE(  54)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  54)					::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            				}
HXDLIN(  54)				_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            			}
            			break;
            			case (int)16: {
HXLINE(  54)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  54)					::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            				}
HXDLIN(  54)				_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)17: {
HXLINE(  54)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  54)					::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            				}
HXDLIN(  54)				_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            			}
            			break;
            			case (int)18: {
HXLINE(  54)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  54)					::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            				}
HXDLIN(  54)				_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            			}
            			break;
            			case (int)19: {
HXLINE(  54)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  54)					::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            				}
HXDLIN(  54)				_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            			}
            			break;
            			case (int)20: {
HXLINE(  54)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  54)					::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            				}
HXDLIN(  54)				_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            			}
            			break;
            			case (int)21: {
HXLINE(  54)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  54)					::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            				}
HXDLIN(  54)				_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            			}
            			break;
            			default:{
HXLINE(  54)				_hx_tmp15 = null();
            			}
            		}
HXDLIN(  54)		::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),_hx_tmp15,::hx::paccDynamic);
HXLINE(  55)		 ::Dynamic _hx_tmp16;
HXDLIN(  55)		switch((int)(::SaveType_obj::CACHE_ASSETS_dyn()->_hx_getIndex())){
            			case (int)1: {
HXLINE(  55)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  55)					::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            				}
HXDLIN(  55)				_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            			}
            			break;
            			case (int)2: {
HXLINE(  55)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  55)					::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            				}
            				else {
HXLINE(  55)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  55)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            				}
HXDLIN(  55)				_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)3: {
HXLINE(  55)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  55)					::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            				}
HXDLIN(  55)				_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            			}
            			break;
            			case (int)4: {
HXLINE(  55)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  55)					::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            				}
HXDLIN(  55)				_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)5: {
HXLINE(  55)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  55)					::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            				}
HXDLIN(  55)				_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            			}
            			break;
            			case (int)6: {
HXLINE(  55)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  55)					::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  55)				_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)7: {
HXLINE(  55)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  55)					::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  55)				_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)8: {
HXLINE(  55)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  55)					::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            				}
HXDLIN(  55)				_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            			}
            			break;
            			case (int)9: {
HXLINE(  55)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  55)					::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            				}
HXDLIN(  55)				_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            			}
            			break;
            			case (int)10: {
HXLINE(  55)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  55)					::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            				}
HXDLIN(  55)				_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            			}
            			break;
            			case (int)11: {
HXLINE(  55)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  55)					::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            				}
            				else {
HXLINE(  55)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  55)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            				}
HXDLIN(  55)				_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            			}
            			break;
            			case (int)12: {
HXLINE(  55)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  55)					::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            				}
HXDLIN(  55)				_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            			}
            			break;
            			case (int)13: {
HXLINE(  55)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  55)					::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            				}
HXDLIN(  55)				_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            			}
            			break;
            			case (int)14: {
HXLINE(  55)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  55)					::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            				}
HXDLIN(  55)				_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            			}
            			break;
            			case (int)15: {
HXLINE(  55)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  55)					::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            				}
HXDLIN(  55)				_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            			}
            			break;
            			case (int)16: {
HXLINE(  55)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  55)					::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            				}
HXDLIN(  55)				_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)17: {
HXLINE(  55)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  55)					::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            				}
HXDLIN(  55)				_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            			}
            			break;
            			case (int)18: {
HXLINE(  55)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  55)					::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            				}
HXDLIN(  55)				_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            			}
            			break;
            			case (int)19: {
HXLINE(  55)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  55)					::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            				}
HXDLIN(  55)				_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            			}
            			break;
            			case (int)20: {
HXLINE(  55)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  55)					::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            				}
HXDLIN(  55)				_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            			}
            			break;
            			case (int)21: {
HXLINE(  55)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  55)					::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            				}
HXDLIN(  55)				_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            			}
            			break;
            			default:{
HXLINE(  55)				_hx_tmp16 = null();
            			}
            		}
HXDLIN(  55)		::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),_hx_tmp16,::hx::paccDynamic);
HXLINE(  56)		 ::Dynamic _hx_tmp17;
HXDLIN(  56)		switch((int)(::SaveType_obj::CUSTOM_KEYBINDS_dyn()->_hx_getIndex())){
            			case (int)1: {
HXLINE(  56)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  56)					::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            				}
HXDLIN(  56)				_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            			}
            			break;
            			case (int)2: {
HXLINE(  56)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  56)					::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            				}
            				else {
HXLINE(  56)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  56)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            				}
HXDLIN(  56)				_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)3: {
HXLINE(  56)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  56)					::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            				}
HXDLIN(  56)				_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            			}
            			break;
            			case (int)4: {
HXLINE(  56)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  56)					::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            				}
HXDLIN(  56)				_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)5: {
HXLINE(  56)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  56)					::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            				}
HXDLIN(  56)				_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            			}
            			break;
            			case (int)6: {
HXLINE(  56)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  56)					::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  56)				_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)7: {
HXLINE(  56)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  56)					::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  56)				_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)8: {
HXLINE(  56)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  56)					::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            				}
HXDLIN(  56)				_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            			}
            			break;
            			case (int)9: {
HXLINE(  56)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  56)					::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            				}
HXDLIN(  56)				_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            			}
            			break;
            			case (int)10: {
HXLINE(  56)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  56)					::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            				}
HXDLIN(  56)				_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            			}
            			break;
            			case (int)11: {
HXLINE(  56)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  56)					::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            				}
            				else {
HXLINE(  56)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  56)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            				}
HXDLIN(  56)				_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            			}
            			break;
            			case (int)12: {
HXLINE(  56)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  56)					::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            				}
HXDLIN(  56)				_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            			}
            			break;
            			case (int)13: {
HXLINE(  56)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  56)					::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            				}
HXDLIN(  56)				_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            			}
            			break;
            			case (int)14: {
HXLINE(  56)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  56)					::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            				}
HXDLIN(  56)				_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            			}
            			break;
            			case (int)15: {
HXLINE(  56)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  56)					::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            				}
HXDLIN(  56)				_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            			}
            			break;
            			case (int)16: {
HXLINE(  56)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  56)					::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            				}
HXDLIN(  56)				_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)17: {
HXLINE(  56)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  56)					::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            				}
HXDLIN(  56)				_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            			}
            			break;
            			case (int)18: {
HXLINE(  56)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  56)					::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            				}
HXDLIN(  56)				_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            			}
            			break;
            			case (int)19: {
HXLINE(  56)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  56)					::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            				}
HXDLIN(  56)				_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            			}
            			break;
            			case (int)20: {
HXLINE(  56)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  56)					::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            				}
HXDLIN(  56)				_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            			}
            			break;
            			case (int)21: {
HXLINE(  56)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  56)					::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            				}
HXDLIN(  56)				_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            			}
            			break;
            			default:{
HXLINE(  56)				_hx_tmp17 = null();
            			}
            		}
HXDLIN(  56)		::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),_hx_tmp17,::hx::paccDynamic);
HXLINE(  57)		 ::Dynamic _hx_tmp18;
HXDLIN(  57)		switch((int)(::SaveType_obj::CAMERA_MOVEMENT_MOD_dyn()->_hx_getIndex())){
            			case (int)1: {
HXLINE(  57)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  57)					::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            				}
HXDLIN(  57)				_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            			}
            			break;
            			case (int)2: {
HXLINE(  57)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  57)					::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            				}
            				else {
HXLINE(  57)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  57)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            				}
HXDLIN(  57)				_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)3: {
HXLINE(  57)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  57)					::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            				}
HXDLIN(  57)				_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            			}
            			break;
            			case (int)4: {
HXLINE(  57)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  57)					::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            				}
HXDLIN(  57)				_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)5: {
HXLINE(  57)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  57)					::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            				}
HXDLIN(  57)				_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            			}
            			break;
            			case (int)6: {
HXLINE(  57)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  57)					::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  57)				_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)7: {
HXLINE(  57)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  57)					::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  57)				_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)8: {
HXLINE(  57)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  57)					::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            				}
HXDLIN(  57)				_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            			}
            			break;
            			case (int)9: {
HXLINE(  57)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  57)					::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            				}
HXDLIN(  57)				_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            			}
            			break;
            			case (int)10: {
HXLINE(  57)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  57)					::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            				}
HXDLIN(  57)				_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            			}
            			break;
            			case (int)11: {
HXLINE(  57)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  57)					::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            				}
            				else {
HXLINE(  57)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  57)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            				}
HXDLIN(  57)				_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            			}
            			break;
            			case (int)12: {
HXLINE(  57)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  57)					::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            				}
HXDLIN(  57)				_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            			}
            			break;
            			case (int)13: {
HXLINE(  57)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  57)					::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            				}
HXDLIN(  57)				_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            			}
            			break;
            			case (int)14: {
HXLINE(  57)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  57)					::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            				}
HXDLIN(  57)				_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            			}
            			break;
            			case (int)15: {
HXLINE(  57)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  57)					::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            				}
HXDLIN(  57)				_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            			}
            			break;
            			case (int)16: {
HXLINE(  57)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  57)					::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            				}
HXDLIN(  57)				_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)17: {
HXLINE(  57)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  57)					::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            				}
HXDLIN(  57)				_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            			}
            			break;
            			case (int)18: {
HXLINE(  57)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  57)					::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            				}
HXDLIN(  57)				_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            			}
            			break;
            			case (int)19: {
HXLINE(  57)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  57)					::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            				}
HXDLIN(  57)				_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            			}
            			break;
            			case (int)20: {
HXLINE(  57)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  57)					::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            				}
HXDLIN(  57)				_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            			}
            			break;
            			case (int)21: {
HXLINE(  57)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  57)					::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            				}
HXDLIN(  57)				_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            			}
            			break;
            			default:{
HXLINE(  57)				_hx_tmp18 = null();
            			}
            		}
HXDLIN(  57)		::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),_hx_tmp18,::hx::paccDynamic);
HXLINE(  58)		 ::Dynamic _hx_tmp19;
HXDLIN(  58)		switch((int)(::SaveType_obj::GHOST_TAPPING_dyn()->_hx_getIndex())){
            			case (int)1: {
HXLINE(  58)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  58)					::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            				}
HXDLIN(  58)				_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            			}
            			break;
            			case (int)2: {
HXLINE(  58)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  58)					::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            				}
            				else {
HXLINE(  58)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  58)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            				}
HXDLIN(  58)				_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)3: {
HXLINE(  58)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  58)					::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            				}
HXDLIN(  58)				_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            			}
            			break;
            			case (int)4: {
HXLINE(  58)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  58)					::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            				}
HXDLIN(  58)				_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)5: {
HXLINE(  58)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  58)					::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            				}
HXDLIN(  58)				_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            			}
            			break;
            			case (int)6: {
HXLINE(  58)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  58)					::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  58)				_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)7: {
HXLINE(  58)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  58)					::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  58)				_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)8: {
HXLINE(  58)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  58)					::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            				}
HXDLIN(  58)				_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            			}
            			break;
            			case (int)9: {
HXLINE(  58)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  58)					::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            				}
HXDLIN(  58)				_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            			}
            			break;
            			case (int)10: {
HXLINE(  58)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  58)					::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            				}
HXDLIN(  58)				_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            			}
            			break;
            			case (int)11: {
HXLINE(  58)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  58)					::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            				}
            				else {
HXLINE(  58)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  58)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            				}
HXDLIN(  58)				_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            			}
            			break;
            			case (int)12: {
HXLINE(  58)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  58)					::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            				}
HXDLIN(  58)				_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            			}
            			break;
            			case (int)13: {
HXLINE(  58)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  58)					::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            				}
HXDLIN(  58)				_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            			}
            			break;
            			case (int)14: {
HXLINE(  58)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  58)					::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            				}
HXDLIN(  58)				_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            			}
            			break;
            			case (int)15: {
HXLINE(  58)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  58)					::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            				}
HXDLIN(  58)				_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            			}
            			break;
            			case (int)16: {
HXLINE(  58)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  58)					::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            				}
HXDLIN(  58)				_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)17: {
HXLINE(  58)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  58)					::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            				}
HXDLIN(  58)				_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            			}
            			break;
            			case (int)18: {
HXLINE(  58)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  58)					::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            				}
HXDLIN(  58)				_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            			}
            			break;
            			case (int)19: {
HXLINE(  58)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  58)					::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            				}
HXDLIN(  58)				_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            			}
            			break;
            			case (int)20: {
HXLINE(  58)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  58)					::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            				}
HXDLIN(  58)				_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            			}
            			break;
            			case (int)21: {
HXLINE(  58)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  58)					::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            				}
HXDLIN(  58)				_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            			}
            			break;
            			default:{
HXLINE(  58)				_hx_tmp19 = null();
            			}
            		}
HXDLIN(  58)		::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),_hx_tmp19,::hx::paccDynamic);
HXLINE(  59)		 ::Dynamic _hx_tmp20;
HXDLIN(  59)		switch((int)(::SaveType_obj::CUSTOM_MENU_BINDS_dyn()->_hx_getIndex())){
            			case (int)1: {
HXLINE(  59)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  59)					::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            				}
HXDLIN(  59)				_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            			}
            			break;
            			case (int)2: {
HXLINE(  59)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  59)					::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            				}
            				else {
HXLINE(  59)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  59)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            				}
HXDLIN(  59)				_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)3: {
HXLINE(  59)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  59)					::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            				}
HXDLIN(  59)				_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            			}
            			break;
            			case (int)4: {
HXLINE(  59)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  59)					::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            				}
HXDLIN(  59)				_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)5: {
HXLINE(  59)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  59)					::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            				}
HXDLIN(  59)				_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            			}
            			break;
            			case (int)6: {
HXLINE(  59)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  59)					::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  59)				_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)7: {
HXLINE(  59)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  59)					::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  59)				_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)8: {
HXLINE(  59)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  59)					::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            				}
HXDLIN(  59)				_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            			}
            			break;
            			case (int)9: {
HXLINE(  59)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  59)					::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            				}
HXDLIN(  59)				_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            			}
            			break;
            			case (int)10: {
HXLINE(  59)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  59)					::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            				}
HXDLIN(  59)				_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            			}
            			break;
            			case (int)11: {
HXLINE(  59)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  59)					::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            				}
            				else {
HXLINE(  59)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  59)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            				}
HXDLIN(  59)				_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            			}
            			break;
            			case (int)12: {
HXLINE(  59)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  59)					::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            				}
HXDLIN(  59)				_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            			}
            			break;
            			case (int)13: {
HXLINE(  59)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  59)					::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            				}
HXDLIN(  59)				_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            			}
            			break;
            			case (int)14: {
HXLINE(  59)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  59)					::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            				}
HXDLIN(  59)				_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            			}
            			break;
            			case (int)15: {
HXLINE(  59)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  59)					::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            				}
HXDLIN(  59)				_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            			}
            			break;
            			case (int)16: {
HXLINE(  59)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  59)					::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            				}
HXDLIN(  59)				_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)17: {
HXLINE(  59)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  59)					::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            				}
HXDLIN(  59)				_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            			}
            			break;
            			case (int)18: {
HXLINE(  59)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  59)					::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            				}
HXDLIN(  59)				_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            			}
            			break;
            			case (int)19: {
HXLINE(  59)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  59)					::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            				}
HXDLIN(  59)				_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            			}
            			break;
            			case (int)20: {
HXLINE(  59)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  59)					::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            				}
HXDLIN(  59)				_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            			}
            			break;
            			case (int)21: {
HXLINE(  59)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  59)					::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            				}
HXDLIN(  59)				_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            			}
            			break;
            			default:{
HXLINE(  59)				_hx_tmp20 = null();
            			}
            		}
HXDLIN(  59)		::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),_hx_tmp20,::hx::paccDynamic);
HXLINE(  61)		::flixel::FlxG_obj::save->flush(null(),null());
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(SaveData_obj,saveClient,(void))

 ::Dynamic SaveData_obj::getData( ::SaveType data){
            	HX_STACKFRAME(&_hx_pos_dc01e484f6679c8f_65_getData)
HXDLIN(  65)		switch((int)(data->_hx_getIndex())){
            			case (int)1: {
HXLINE(  67)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  68)					::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            				}
HXLINE(  70)				return  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            			}
            			break;
            			case (int)2: {
HXLINE(  73)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  74)					::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            				}
            				else {
HXLINE(  75)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  76)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            				}
HXLINE(  84)				return  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)3: {
HXLINE(  86)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  87)					::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            				}
HXLINE(  89)				return  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            			}
            			break;
            			case (int)4: {
HXLINE(  91)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  92)					::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            				}
HXLINE(  94)				return  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)5: {
HXLINE(  96)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  97)					::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            				}
HXLINE(  99)				return  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            			}
            			break;
            			case (int)6: {
HXLINE( 101)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 102)					::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            				}
HXLINE( 104)				return  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)7: {
HXLINE( 106)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 107)					::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            				}
HXLINE( 109)				return  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)8: {
HXLINE( 111)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 112)					::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            				}
HXLINE( 114)				return  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            			}
            			break;
            			case (int)9: {
HXLINE( 116)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 117)					::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            				}
HXLINE( 119)				return  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            			}
            			break;
            			case (int)10: {
HXLINE( 121)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 122)					::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            				}
HXLINE( 124)				return  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            			}
            			break;
            			case (int)11: {
HXLINE( 127)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 128)					::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            				}
            				else {
HXLINE( 129)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 130)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            				}
HXLINE( 138)				return  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            			}
            			break;
            			case (int)12: {
HXLINE( 185)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 186)					::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            				}
HXLINE( 188)				return  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            			}
            			break;
            			case (int)13: {
HXLINE( 140)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 141)					::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            				}
HXLINE( 143)				return  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            			}
            			break;
            			case (int)14: {
HXLINE( 145)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 146)					::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            				}
HXLINE( 148)				return  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            			}
            			break;
            			case (int)15: {
HXLINE( 150)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 151)					::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            				}
HXLINE( 153)				return  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            			}
            			break;
            			case (int)16: {
HXLINE( 155)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 156)					::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            				}
HXLINE( 158)				return  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)17: {
HXLINE( 160)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 161)					::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            				}
HXLINE( 163)				return  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            			}
            			break;
            			case (int)18: {
HXLINE( 165)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 166)					::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            				}
HXLINE( 168)				return  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            			}
            			break;
            			case (int)19: {
HXLINE( 170)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 171)					::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            				}
HXLINE( 173)				return  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            			}
            			break;
            			case (int)20: {
HXLINE( 175)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 176)					::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            				}
HXLINE( 178)				return  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            			}
            			break;
            			case (int)21: {
HXLINE( 180)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 181)					::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            				}
HXLINE( 183)				return  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            			}
            			break;
            			default:{
HXLINE( 190)				return null();
            			}
            		}
HXLINE(  65)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(SaveData_obj,getData,return )


SaveData_obj::SaveData_obj()
{
}

bool SaveData_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"getData") ) { outValue = getData_dyn(); return true; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"saveClient") ) { outValue = saveClient_dyn(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *SaveData_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *SaveData_obj_sStaticStorageInfo = 0;
#endif

::hx::Class SaveData_obj::__mClass;

static ::String SaveData_obj_sStaticFields[] = {
	HX_("saveClient",68,55,09,53),
	HX_("getData",e0,05,e6,14),
	::String(null())
};

void SaveData_obj::__register()
{
	SaveData_obj _hx_dummy;
	SaveData_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("SaveData",27,ac,ce,cf);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &SaveData_obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(SaveData_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< SaveData_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = SaveData_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = SaveData_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

