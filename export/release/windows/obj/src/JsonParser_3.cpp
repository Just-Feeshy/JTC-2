#include <hxcpp.h>

#ifndef INCLUDED_JsonParser_3
#include <JsonParser_3.h>
#endif
#ifndef INCLUDED_hxjsonast_Json
#include <hxjsonast/Json.h>
#endif
#ifndef INCLUDED_hxjsonast_JsonValue
#include <hxjsonast/JsonValue.h>
#endif
#ifndef INCLUDED_hxjsonast_Position
#include <hxjsonast/Position.h>
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

HX_DEFINE_STACK_FRAME(_hx_pos_b72bc31f430e25a5_938_new,"JsonParser_3","new",0x340e926d,"JsonParser_3.new","json2object/reader/DataBuilder.hx",938,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_b72bc31f430e25a5_942_onIncorrectType,"JsonParser_3","onIncorrectType",0x4e44216d,"JsonParser_3.onIncorrectType","json2object/reader/DataBuilder.hx",942,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_b72bc31f430e25a5_98_loadJsonNull,"JsonParser_3","loadJsonNull",0xb9ae4168,"JsonParser_3.loadJsonNull","json2object/reader/DataBuilder.hx",98,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_b72bc31f430e25a5_97_loadJsonString,"JsonParser_3","loadJsonString",0xa32705f2,"JsonParser_3.loadJsonString","json2object/reader/DataBuilder.hx",97,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_b72bc31f430e25a5_971_getAuto,"JsonParser_3","getAuto",0xe472dbb2,"JsonParser_3.getAuto","json2object/reader/DataBuilder.hx",971,0x0533cd73)

void JsonParser_3_obj::__construct(::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType){
            		 ::Dynamic errorType = __o_errorType;
            		if (::hx::IsNull(__o_errorType)) errorType = 0;
            	HX_STACKFRAME(&_hx_pos_b72bc31f430e25a5_938_new)
HXDLIN( 938)		super::__construct(errors,putils,errorType);
            	}

Dynamic JsonParser_3_obj::__CreateEmpty() { return new JsonParser_3_obj; }

void *JsonParser_3_obj::_hx_vtable = 0;

Dynamic JsonParser_3_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< JsonParser_3_obj > _hx_result = new JsonParser_3_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return _hx_result;
}

bool JsonParser_3_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x0f6d5b90) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x0f6d5b90;
	} else {
		return inClassId==(int)0x194860e7;
	}
}

void JsonParser_3_obj::onIncorrectType( ::Dynamic pos,::String variable){
            	HX_STACKFRAME(&_hx_pos_b72bc31f430e25a5_942_onIncorrectType)
HXLINE( 943)		this->errors->push(::json2object::Error_obj::IncorrectType(variable,HX_("String",f1,9c,c4,45),pos));
HXLINE( 944)		this->super::onIncorrectType(pos,variable);
            	}


void JsonParser_3_obj::loadJsonNull( ::Dynamic pos,::String variable){
            	HX_STACKFRAME(&_hx_pos_b72bc31f430e25a5_98_loadJsonNull)
HXDLIN(  98)		this->value = null();
            	}


void JsonParser_3_obj::loadJsonString(::String s, ::Dynamic pos,::String variable){
            	HX_STACKFRAME(&_hx_pos_b72bc31f430e25a5_97_loadJsonString)
HXDLIN(  97)		this->value = s;
            	}


::String JsonParser_3_obj::getAuto(){
            	HX_GC_STACKFRAME(&_hx_pos_b72bc31f430e25a5_971_getAuto)
HXDLIN( 971)		 ::JsonParser_3 _hx_tmp =  ::JsonParser_3_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXDLIN( 971)		return ( (::String)(_hx_tmp->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null())) );
            	}


HX_DEFINE_DYNAMIC_FUNC0(JsonParser_3_obj,getAuto,return )


::hx::ObjectPtr< JsonParser_3_obj > JsonParser_3_obj::__new(::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType) {
	::hx::ObjectPtr< JsonParser_3_obj > __this = new JsonParser_3_obj();
	__this->__construct(errors,putils,__o_errorType);
	return __this;
}

::hx::ObjectPtr< JsonParser_3_obj > JsonParser_3_obj::__alloc(::hx::Ctx *_hx_ctx,::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType) {
	JsonParser_3_obj *__this = (JsonParser_3_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(JsonParser_3_obj), true, "JsonParser_3"));
	*(void **)__this = JsonParser_3_obj::_hx_vtable;
	__this->__construct(errors,putils,__o_errorType);
	return __this;
}

JsonParser_3_obj::JsonParser_3_obj()
{
}

::hx::Val JsonParser_3_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"getAuto") ) { return ::hx::Val( getAuto_dyn() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"loadJsonNull") ) { return ::hx::Val( loadJsonNull_dyn() ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"loadJsonString") ) { return ::hx::Val( loadJsonString_dyn() ); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"onIncorrectType") ) { return ::hx::Val( onIncorrectType_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *JsonParser_3_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *JsonParser_3_obj_sStaticStorageInfo = 0;
#endif

static ::String JsonParser_3_obj_sMemberFields[] = {
	HX_("onIncorrectType",e0,ff,a7,01),
	HX_("loadJsonNull",15,2d,09,02),
	HX_("loadJsonString",df,f6,d5,e8),
	HX_("getAuto",25,8f,f9,12),
	::String(null()) };

::hx::Class JsonParser_3_obj::__mClass;

void JsonParser_3_obj::__register()
{
	JsonParser_3_obj _hx_dummy;
	JsonParser_3_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("JsonParser_3",fb,d7,87,99);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(JsonParser_3_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< JsonParser_3_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = JsonParser_3_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = JsonParser_3_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

