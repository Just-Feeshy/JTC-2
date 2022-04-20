#include <hxcpp.h>

#ifndef INCLUDED_ChooseFeeshmora
#include <ChooseFeeshmora.h>
#endif
#ifndef INCLUDED_JsonParser_28
#include <JsonParser_28.h>
#endif
#ifndef INCLUDED_Paths
#include <Paths.h>
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
#ifndef INCLUDED_json2object_Error
#include <json2object/Error.h>
#endif
#ifndef INCLUDED_json2object_PositionUtils
#include <json2object/PositionUtils.h>
#endif
#ifndef INCLUDED_json2object_reader_BaseParser
#include <json2object/reader/BaseParser.h>
#endif
#ifndef INCLUDED_lime_utils_Assets
#include <lime/utils/Assets.h>
#endif
#ifndef INCLUDED_sys_io_File
#include <sys/io/File.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_909c6d5cf55c10ea_72_changeMapArray,"ChooseFeeshmora","changeMapArray",0x422d97c6,"ChooseFeeshmora.changeMapArray","Feeshmora.hx",72,0xa899d0f2)
HX_LOCAL_STACK_FRAME(_hx_pos_909c6d5cf55c10ea_75_getMapSize,"ChooseFeeshmora","getMapSize",0x9a89b7e0,"ChooseFeeshmora.getMapSize","Feeshmora.hx",75,0xa899d0f2)
HX_LOCAL_STACK_FRAME(_hx_pos_909c6d5cf55c10ea_46_boot,"ChooseFeeshmora","boot",0x380427cb,"ChooseFeeshmora.boot","Feeshmora.hx",46,0xa899d0f2)
HX_LOCAL_STACK_FRAME(_hx_pos_909c6d5cf55c10ea_48_boot,"ChooseFeeshmora","boot",0x380427cb,"ChooseFeeshmora.boot","Feeshmora.hx",48,0xa899d0f2)
static const ::String _hx_array_data_62006375_4[] = {
	HX_("red",51,d9,56,00),HX_("transparent",52,2b,ba,22),HX_("lime",15,17,b3,47),HX_("blue",9a,42,19,41),HX_("black",bf,d5,f1,b4),HX_("cyan",23,45,cc,41),HX_("brown",76,ce,f3,b8),HX_("gray",e3,cf,6b,44),HX_("green",c3,0e,ed,99),HX_("magenta",29,ba,9d,0e),HX_("orange",ee,b2,bc,45),HX_("pink",76,f2,57,4a),HX_("purple",3c,f6,89,71),HX_("white",a9,4a,bd,c9),HX_("yellow",74,9f,5c,d0),
};
HX_LOCAL_STACK_FRAME(_hx_pos_909c6d5cf55c10ea_66_boot,"ChooseFeeshmora","boot",0x380427cb,"ChooseFeeshmora.boot","Feeshmora.hx",66,0xa899d0f2)

void ChooseFeeshmora_obj::__construct() { }

Dynamic ChooseFeeshmora_obj::__CreateEmpty() { return new ChooseFeeshmora_obj; }

void *ChooseFeeshmora_obj::_hx_vtable = 0;

Dynamic ChooseFeeshmora_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< ChooseFeeshmora_obj > _hx_result = new ChooseFeeshmora_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool ChooseFeeshmora_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x2e2748b5;
}

 ::JsonParser_28 ChooseFeeshmora_obj::parser;

::Array< ::String > ChooseFeeshmora_obj::avaiableColors;

 ::haxe::ds::StringMap ChooseFeeshmora_obj::chooseSkin;

void ChooseFeeshmora_obj::changeMapArray(::String switcher,int daGet){
            	HX_STACKFRAME(&_hx_pos_909c6d5cf55c10ea_72_changeMapArray)
HXDLIN(  72)		 ::JsonParser_28 this1 = ::ChooseFeeshmora_obj::parser;
HXDLIN(  72)		::String library = null();
HXDLIN(  72)		::String this2;
HXDLIN(  72)		if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("feeshdata/",8a,24,9b,7f) + HX_("skins",56,97,1e,7e)) + HX_(".",2e,00,00,00)) + HX_("json",28,42,68,46)),HX_("TEXT",ad,94,ba,37),library),null())) {
HXDLIN(  72)			this2 = ::Paths_obj::getPath((((HX_("feeshdata/",8a,24,9b,7f) + HX_("skins",56,97,1e,7e)) + HX_(".",2e,00,00,00)) + HX_("json",28,42,68,46)),HX_("TEXT",ad,94,ba,37),library);
            		}
            		else {
HXDLIN(  72)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate file - ",63,30,27,df) + ((HX_("skins",56,97,1e,7e) + HX_(".",2e,00,00,00)) + HX_("json",28,42,68,46)))));
            		}
HXDLIN(  72)		this1->fromJson(::sys::io::File_obj::getContent(this2),HX_("skins.json",40,02,26,9e)).StaticCast<  ::haxe::ds::StringMap >()->get_bool(switcher);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ChooseFeeshmora_obj,changeMapArray,(void))

int ChooseFeeshmora_obj::getMapSize(::String switcher){
            	HX_STACKFRAME(&_hx_pos_909c6d5cf55c10ea_75_getMapSize)
HXLINE(  76)		::String library = null();
HXDLIN(  76)		::String _hx_tmp;
HXDLIN(  76)		if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("feeshdata/",8a,24,9b,7f) + HX_("skins",56,97,1e,7e)) + HX_(".",2e,00,00,00)) + HX_("json",28,42,68,46)),HX_("TEXT",ad,94,ba,37),library),null())) {
HXLINE(  76)			_hx_tmp = ::Paths_obj::getPath((((HX_("feeshdata/",8a,24,9b,7f) + HX_("skins",56,97,1e,7e)) + HX_(".",2e,00,00,00)) + HX_("json",28,42,68,46)),HX_("TEXT",ad,94,ba,37),library);
            		}
            		else {
HXLINE(  76)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate file - ",63,30,27,df) + ((HX_("skins",56,97,1e,7e) + HX_(".",2e,00,00,00)) + HX_("json",28,42,68,46)))));
            		}
HXDLIN(  76)		if ((::sys::io::File_obj::getContent(_hx_tmp).length < 48)) {
HXLINE(  77)			return 0;
            		}
HXLINE(  79)		 ::Dynamic _hx_tmp1 = ::haxe::Log_obj::trace;
HXDLIN(  79)		 ::JsonParser_28 this1 = ::ChooseFeeshmora_obj::parser;
HXDLIN(  79)		::String library1 = null();
HXDLIN(  79)		::String this2;
HXDLIN(  79)		if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("feeshdata/",8a,24,9b,7f) + HX_("skins",56,97,1e,7e)) + HX_(".",2e,00,00,00)) + HX_("json",28,42,68,46)),HX_("TEXT",ad,94,ba,37),library1),null())) {
HXLINE(  79)			this2 = ::Paths_obj::getPath((((HX_("feeshdata/",8a,24,9b,7f) + HX_("skins",56,97,1e,7e)) + HX_(".",2e,00,00,00)) + HX_("json",28,42,68,46)),HX_("TEXT",ad,94,ba,37),library1);
            		}
            		else {
HXLINE(  79)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate file - ",63,30,27,df) + ((HX_("skins",56,97,1e,7e) + HX_(".",2e,00,00,00)) + HX_("json",28,42,68,46)))));
            		}
HXDLIN(  79)		::Array< ::Dynamic> _hx_tmp2 = ( (::Array< ::Dynamic>)(this1->fromJson(::sys::io::File_obj::getContent(this2),HX_("skins.json",40,02,26,9e)).StaticCast<  ::haxe::ds::StringMap >()->get(switcher)) );
HXDLIN(  79)		_hx_tmp1(_hx_tmp2->length,::hx::SourceInfo(HX_("build/Feeshmora.hx",b3,1b,3e,f3),79,HX_("ChooseFeeshmora",75,63,00,62),HX_("getMapSize",87,db,b0,80)));
HXLINE(  81)		 ::JsonParser_28 this3 = ::ChooseFeeshmora_obj::parser;
HXDLIN(  81)		::String library2 = null();
HXDLIN(  81)		::String this4;
HXDLIN(  81)		if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("feeshdata/",8a,24,9b,7f) + HX_("skins",56,97,1e,7e)) + HX_(".",2e,00,00,00)) + HX_("json",28,42,68,46)),HX_("TEXT",ad,94,ba,37),library2),null())) {
HXLINE(  81)			this4 = ::Paths_obj::getPath((((HX_("feeshdata/",8a,24,9b,7f) + HX_("skins",56,97,1e,7e)) + HX_(".",2e,00,00,00)) + HX_("json",28,42,68,46)),HX_("TEXT",ad,94,ba,37),library2);
            		}
            		else {
HXLINE(  81)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate file - ",63,30,27,df) + ((HX_("skins",56,97,1e,7e) + HX_(".",2e,00,00,00)) + HX_("json",28,42,68,46)))));
            		}
HXDLIN(  81)		return ( (::Array< ::Dynamic>)(this3->fromJson(::sys::io::File_obj::getContent(this4),HX_("skins.json",40,02,26,9e)).StaticCast<  ::haxe::ds::StringMap >()->get(switcher)) )->length;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ChooseFeeshmora_obj,getMapSize,return )


ChooseFeeshmora_obj::ChooseFeeshmora_obj()
{
}

bool ChooseFeeshmora_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"parser") ) { outValue = ( parser ); return true; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"chooseSkin") ) { outValue = ( chooseSkin ); return true; }
		if (HX_FIELD_EQ(inName,"getMapSize") ) { outValue = getMapSize_dyn(); return true; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"avaiableColors") ) { outValue = ( avaiableColors ); return true; }
		if (HX_FIELD_EQ(inName,"changeMapArray") ) { outValue = changeMapArray_dyn(); return true; }
	}
	return false;
}

bool ChooseFeeshmora_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"parser") ) { parser=ioValue.Cast<  ::JsonParser_28 >(); return true; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"chooseSkin") ) { chooseSkin=ioValue.Cast<  ::haxe::ds::StringMap >(); return true; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"avaiableColors") ) { avaiableColors=ioValue.Cast< ::Array< ::String > >(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *ChooseFeeshmora_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo ChooseFeeshmora_obj_sStaticStorageInfo[] = {
	{::hx::fsObject /*  ::JsonParser_28 */ ,(void *) &ChooseFeeshmora_obj::parser,HX_("parser",df,9c,88,ed)},
	{::hx::fsObject /* ::Array< ::String > */ ,(void *) &ChooseFeeshmora_obj::avaiableColors,HX_("avaiableColors",47,ce,25,d0)},
	{::hx::fsObject /*  ::haxe::ds::StringMap */ ,(void *) &ChooseFeeshmora_obj::chooseSkin,HX_("chooseSkin",f4,54,3e,3d)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static void ChooseFeeshmora_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ChooseFeeshmora_obj::parser,"parser");
	HX_MARK_MEMBER_NAME(ChooseFeeshmora_obj::avaiableColors,"avaiableColors");
	HX_MARK_MEMBER_NAME(ChooseFeeshmora_obj::chooseSkin,"chooseSkin");
};

#ifdef HXCPP_VISIT_ALLOCS
static void ChooseFeeshmora_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ChooseFeeshmora_obj::parser,"parser");
	HX_VISIT_MEMBER_NAME(ChooseFeeshmora_obj::avaiableColors,"avaiableColors");
	HX_VISIT_MEMBER_NAME(ChooseFeeshmora_obj::chooseSkin,"chooseSkin");
};

#endif

::hx::Class ChooseFeeshmora_obj::__mClass;

static ::String ChooseFeeshmora_obj_sStaticFields[] = {
	HX_("parser",df,9c,88,ed),
	HX_("avaiableColors",47,ce,25,d0),
	HX_("chooseSkin",f4,54,3e,3d),
	HX_("changeMapArray",ed,1a,0d,f6),
	HX_("getMapSize",87,db,b0,80),
	::String(null())
};

void ChooseFeeshmora_obj::__register()
{
	ChooseFeeshmora_obj _hx_dummy;
	ChooseFeeshmora_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("ChooseFeeshmora",75,63,00,62);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &ChooseFeeshmora_obj::__GetStatic;
	__mClass->mSetStaticField = &ChooseFeeshmora_obj::__SetStatic;
	__mClass->mMarkFunc = ChooseFeeshmora_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(ChooseFeeshmora_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< ChooseFeeshmora_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = ChooseFeeshmora_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = ChooseFeeshmora_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = ChooseFeeshmora_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void ChooseFeeshmora_obj::__boot()
{
{
            	HX_GC_STACKFRAME(&_hx_pos_909c6d5cf55c10ea_46_boot)
HXDLIN(  46)		parser =  ::JsonParser_28_obj::__alloc( HX_CTX ,null(),null(),null());
            	}
{
            	HX_STACKFRAME(&_hx_pos_909c6d5cf55c10ea_48_boot)
HXDLIN(  48)		avaiableColors = ::Array_obj< ::String >::fromData( _hx_array_data_62006375_4,15);
            	}
{
            		HX_BEGIN_LOCAL_FUNC_S0(::hx::LocalFunc,_hx_Closure_0) HXARGC(0)
            		 ::haxe::ds::StringMap _hx_run(){
            			HX_GC_STACKFRAME(&_hx_pos_909c6d5cf55c10ea_66_boot)
HXDLIN(  66)			 ::haxe::ds::StringMap _g =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
HXDLIN(  66)			_g->set(HX_("boyfriend",6a,29,b8,e6),::Array_obj< Float >::__new());
HXDLIN(  66)			_g->set(HX_("health",9c,28,06,fd),::Array_obj< Float >::__new());
HXDLIN(  66)			return _g;
            		}
            		HX_END_LOCAL_FUNC0(return)

            	HX_STACKFRAME(&_hx_pos_909c6d5cf55c10ea_66_boot)
HXDLIN(  66)		chooseSkin = ( ( ::haxe::ds::StringMap)( ::Dynamic(new _hx_Closure_0())()) );
            	}
}

