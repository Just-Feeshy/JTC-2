#include <hxcpp.h>

#ifndef INCLUDED_95f339a1d026d52c
#define INCLUDED_95f339a1d026d52c
#include "hxMath.h"
#endif
#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_polymod_format_JsonHelp
#include <polymod/format/JsonHelp.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_9c18bffd7895cc1b_6_bool,"polymod.format.JsonHelp","bool",0x50ccdd90,"polymod.format.JsonHelp.bool","polymod/format/JsonHelp.hx",6,0x7164f0d6)
HX_LOCAL_STACK_FRAME(_hx_pos_9c18bffd7895cc1b_19_int,"polymod.format.JsonHelp","int",0x1ac96249,"polymod.format.JsonHelp.int","polymod/format/JsonHelp.hx",19,0x7164f0d6)
HX_LOCAL_STACK_FRAME(_hx_pos_9c18bffd7895cc1b_32_float,"polymod.format.JsonHelp","float",0xae13a576,"polymod.format.JsonHelp.float","polymod/format/JsonHelp.hx",32,0x7164f0d6)
HX_LOCAL_STACK_FRAME(_hx_pos_9c18bffd7895cc1b_53_mapStr,"polymod.format.JsonHelp","mapStr",0x1ad2de5b,"polymod.format.JsonHelp.mapStr","polymod/format/JsonHelp.hx",53,0x7164f0d6)
HX_LOCAL_STACK_FRAME(_hx_pos_9c18bffd7895cc1b_72_str,"polymod.format.JsonHelp","str",0x1ad0fe0b,"polymod.format.JsonHelp.str","polymod/format/JsonHelp.hx",72,0x7164f0d6)
HX_LOCAL_STACK_FRAME(_hx_pos_9c18bffd7895cc1b_82_type,"polymod.format.JsonHelp","type",0x5cba4c20,"polymod.format.JsonHelp.type","polymod/format/JsonHelp.hx",82,0x7164f0d6)
HX_LOCAL_STACK_FRAME(_hx_pos_9c18bffd7895cc1b_92_arrType,"polymod.format.JsonHelp","arrType",0x5e396c15,"polymod.format.JsonHelp.arrType","polymod/format/JsonHelp.hx",92,0x7164f0d6)
HX_LOCAL_STACK_FRAME(_hx_pos_9c18bffd7895cc1b_104_arrStr,"polymod.format.JsonHelp","arrStr",0x19acd3b6,"polymod.format.JsonHelp.arrStr","polymod/format/JsonHelp.hx",104,0x7164f0d6)
namespace polymod{
namespace format{

void JsonHelp_obj::__construct() { }

Dynamic JsonHelp_obj::__CreateEmpty() { return new JsonHelp_obj; }

void *JsonHelp_obj::_hx_vtable = 0;

Dynamic JsonHelp_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< JsonHelp_obj > _hx_result = new JsonHelp_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool JsonHelp_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x626a4b56;
}

bool JsonHelp_obj::_hx_bool( ::Dynamic json,::String field,::hx::Null< bool >  __o_defaultValue){
            		bool defaultValue = __o_defaultValue.Default(false);
            	HX_STACKFRAME(&_hx_pos_9c18bffd7895cc1b_6_bool)
HXLINE(   7)		::String str = HX_("",00,00,00,00);
HXLINE(   8)		if (::Reflect_obj::hasField(json,field)) {
HXLINE(   9)			str = ( (::String)(::Reflect_obj::field(json,field)) );
            		}
HXLINE(  10)		bool _hx_tmp;
HXDLIN(  10)		if (::hx::IsNotNull( str )) {
HXLINE(  10)			_hx_tmp = (str == HX_("",00,00,00,00));
            		}
            		else {
HXLINE(  10)			_hx_tmp = true;
            		}
HXDLIN(  10)		if (_hx_tmp) {
HXLINE(  11)			return defaultValue;
            		}
HXLINE(  12)		str = str.toLowerCase();
HXLINE(  13)		if ((str == HX_("true",4e,a7,03,4d))) {
HXLINE(  14)			return true;
            		}
HXLINE(  15)		return false;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(JsonHelp_obj,_hx_bool,return )

int JsonHelp_obj::_hx_int( ::Dynamic json,::String field,::hx::Null< int >  __o_defaultValue){
            		int defaultValue = __o_defaultValue.Default(0);
            	HX_STACKFRAME(&_hx_pos_9c18bffd7895cc1b_19_int)
HXLINE(  20)		::String str = HX_("",00,00,00,00);
HXLINE(  21)		if (::Reflect_obj::hasField(json,field)) {
HXLINE(  22)			str = ( (::String)(::Reflect_obj::field(json,field)) );
            		}
HXLINE(  23)		bool _hx_tmp;
HXDLIN(  23)		if (::hx::IsNotNull( str )) {
HXLINE(  23)			_hx_tmp = (str == HX_("",00,00,00,00));
            		}
            		else {
HXLINE(  23)			_hx_tmp = true;
            		}
HXDLIN(  23)		if (_hx_tmp) {
HXLINE(  24)			return defaultValue;
            		}
HXLINE(  25)		 ::Dynamic i = ::Std_obj::parseInt(str);
HXLINE(  26)		if (::hx::IsNull( i )) {
HXLINE(  27)			return defaultValue;
            		}
HXLINE(  28)		return ( (int)(i) );
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(JsonHelp_obj,_hx_int,return )

Float JsonHelp_obj::_hx_float( ::Dynamic json,::String field,::hx::Null< Float >  __o_defaultValue){
            		Float defaultValue = __o_defaultValue.Default(0);
            	HX_STACKFRAME(&_hx_pos_9c18bffd7895cc1b_32_float)
HXLINE(  33)		::String str = HX_("",00,00,00,00);
HXLINE(  34)		if (::Reflect_obj::hasField(json,field)) {
HXLINE(  35)			str = ( (::String)(::Reflect_obj::field(json,field)) );
            		}
HXLINE(  36)		bool _hx_tmp;
HXDLIN(  36)		if (::hx::IsNotNull( str )) {
HXLINE(  36)			_hx_tmp = (str == HX_("",00,00,00,00));
            		}
            		else {
HXLINE(  36)			_hx_tmp = true;
            		}
HXDLIN(  36)		if (_hx_tmp) {
HXLINE(  37)			return defaultValue;
            		}
HXLINE(  38)		Float f = ::Math_obj::NaN;
HXLINE(  39)		try {
            			HX_STACK_CATCHABLE( ::Dynamic, 0);
HXLINE(  41)			f = ::Std_obj::parseFloat(str);
            		} catch( ::Dynamic _hx_e) {
            			if (_hx_e.IsClass<  ::Dynamic >() ){
            				HX_STACK_BEGIN_CATCH
            				 ::Dynamic _g = _hx_e;
HXLINE(  43)				{
HXLINE(  43)					null();
            				}
HXLINE(  45)				f = ::Math_obj::NaN;
            			}
            			else {
            				HX_STACK_DO_THROW(_hx_e);
            			}
            		}
HXLINE(  47)		if (::Math_obj::isNaN(f)) {
HXLINE(  48)			return defaultValue;
            		}
HXLINE(  49)		return f;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(JsonHelp_obj,_hx_float,return )

 ::haxe::ds::StringMap JsonHelp_obj::mapStr( ::Dynamic json,::String field){
            	HX_GC_STACKFRAME(&_hx_pos_9c18bffd7895cc1b_53_mapStr)
HXLINE(  54)		 ::haxe::ds::StringMap map =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
HXLINE(  55)		bool _hx_tmp;
HXDLIN(  55)		bool _hx_tmp1;
HXDLIN(  55)		if (::hx::IsNotNull( json )) {
HXLINE(  55)			_hx_tmp1 = (field == HX_("",00,00,00,00));
            		}
            		else {
HXLINE(  55)			_hx_tmp1 = true;
            		}
HXDLIN(  55)		if (!(_hx_tmp1)) {
HXLINE(  55)			_hx_tmp = ::hx::IsNull( field );
            		}
            		else {
HXLINE(  55)			_hx_tmp = true;
            		}
HXDLIN(  55)		if (_hx_tmp) {
HXLINE(  56)			return map;
            		}
HXLINE(  57)		 ::Dynamic val = null();
HXLINE(  58)		if (::Reflect_obj::hasField(json,field)) {
HXLINE(  59)			val = ::Reflect_obj::field(json,field);
            		}
HXLINE(  60)		if (::hx::IsNotNull( val )) {
HXLINE(  62)			int _g = 0;
HXDLIN(  62)			::Array< ::String > _g1 = ::Reflect_obj::fields(val);
HXDLIN(  62)			while((_g < _g1->length)){
HXLINE(  62)				::String field = _g1->__get(_g);
HXDLIN(  62)				_g = (_g + 1);
HXLINE(  64)				 ::Dynamic fieldVal = ::Reflect_obj::field(val,field);
HXLINE(  65)				map->set(field,::Std_obj::string(fieldVal));
            			}
            		}
HXLINE(  68)		return map;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(JsonHelp_obj,mapStr,return )

::String JsonHelp_obj::str( ::Dynamic json,::String field,::String __o_defaultValue){
            		::String defaultValue = __o_defaultValue;
            		if (::hx::IsNull(__o_defaultValue)) defaultValue = HX_("",00,00,00,00);
            	HX_STACKFRAME(&_hx_pos_9c18bffd7895cc1b_72_str)
HXLINE(  73)		::String str = HX_("",00,00,00,00);
HXLINE(  74)		if (::Reflect_obj::hasField(json,field)) {
HXLINE(  75)			str = ( (::String)(::Reflect_obj::field(json,field)) );
            		}
HXLINE(  76)		bool _hx_tmp;
HXDLIN(  76)		if (::hx::IsNotNull( str )) {
HXLINE(  76)			_hx_tmp = (str == HX_("",00,00,00,00));
            		}
            		else {
HXLINE(  76)			_hx_tmp = true;
            		}
HXDLIN(  76)		if (_hx_tmp) {
HXLINE(  77)			return defaultValue;
            		}
HXLINE(  78)		return str;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(JsonHelp_obj,str,return )

 ::Dynamic JsonHelp_obj::type( ::Dynamic json,::String field, ::Dynamic defaultValue){
            	HX_STACKFRAME(&_hx_pos_9c18bffd7895cc1b_82_type)
HXLINE(  83)		 ::Dynamic value = null();
HXLINE(  84)		if (::Reflect_obj::hasField(json,field)) {
HXLINE(  85)			value = ::Reflect_obj::field(json,field);
            		}
HXLINE(  86)		if (::hx::IsNull( value )) {
HXLINE(  87)			return defaultValue;
            		}
HXLINE(  88)		return value;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(JsonHelp_obj,type,return )

::cpp::VirtualArray JsonHelp_obj::arrType( ::Dynamic json,::String field,::cpp::VirtualArray defaultValue){
            	HX_STACKFRAME(&_hx_pos_9c18bffd7895cc1b_92_arrType)
HXLINE(  93)		::cpp::VirtualArray val = null();
HXLINE(  94)		if (::Reflect_obj::hasField(json,field)) {
HXLINE(  95)			val = ( (::cpp::VirtualArray)(::Reflect_obj::field(json,field)) );
            		}
HXLINE(  96)		bool _hx_tmp;
HXDLIN(  96)		if (::hx::IsNotNull( val )) {
HXLINE(  96)			_hx_tmp = ::Std_obj::isOfType(val,::hx::ArrayBase::__mClass);
            		}
            		else {
HXLINE(  96)			_hx_tmp = false;
            		}
HXDLIN(  96)		if (_hx_tmp) {
HXLINE(  98)			return val;
            		}
HXLINE( 100)		return defaultValue;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(JsonHelp_obj,arrType,return )

::Array< ::String > JsonHelp_obj::arrStr( ::Dynamic json,::String field,::Array< ::String > defaultValue){
            	HX_STACKFRAME(&_hx_pos_9c18bffd7895cc1b_104_arrStr)
HXLINE( 105)		 ::Dynamic val = null();
HXLINE( 106)		if (::Reflect_obj::hasField(json,field)) {
HXLINE( 107)			val = ::Reflect_obj::field(json,field);
            		}
HXLINE( 108)		bool _hx_tmp;
HXDLIN( 108)		if (::hx::IsNotNull( val )) {
HXLINE( 108)			_hx_tmp = ::Std_obj::isOfType(val,::hx::ArrayBase::__mClass);
            		}
            		else {
HXLINE( 108)			_hx_tmp = false;
            		}
HXDLIN( 108)		if (_hx_tmp) {
HXLINE( 110)			return ( (::Array< ::String >)(val) );
            		}
HXLINE( 112)		return defaultValue;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(JsonHelp_obj,arrStr,return )


JsonHelp_obj::JsonHelp_obj()
{
}

bool JsonHelp_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"int") ) { outValue = _hx_int_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"str") ) { outValue = str_dyn(); return true; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"bool") ) { outValue = _hx_bool_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"type") ) { outValue = type_dyn(); return true; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"float") ) { outValue = _hx_float_dyn(); return true; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"mapStr") ) { outValue = mapStr_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"arrStr") ) { outValue = arrStr_dyn(); return true; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"arrType") ) { outValue = arrType_dyn(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *JsonHelp_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *JsonHelp_obj_sStaticStorageInfo = 0;
#endif

::hx::Class JsonHelp_obj::__mClass;

static ::String JsonHelp_obj_sStaticFields[] = {
	HX_("bool",2a,84,1b,41),
	HX_("int",ef,0c,50,00),
	HX_("float",9c,c5,96,02),
	HX_("mapStr",75,df,0b,b9),
	HX_("str",b1,a8,57,00),
	HX_("type",ba,f2,08,4d),
	HX_("arrType",bb,61,e1,31),
	HX_("arrStr",d0,d4,e5,b7),
	::String(null())
};

void JsonHelp_obj::__register()
{
	JsonHelp_obj _hx_dummy;
	JsonHelp_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("polymod.format.JsonHelp",c8,80,2d,ef);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &JsonHelp_obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(JsonHelp_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< JsonHelp_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = JsonHelp_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = JsonHelp_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace polymod
} // end namespace format
