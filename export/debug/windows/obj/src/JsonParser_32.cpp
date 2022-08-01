#include <hxcpp.h>

#ifndef INCLUDED_JsonParser_32
#include <JsonParser_32.h>
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

HX_DEFINE_STACK_FRAME(_hx_pos_c4324b57e9095362_961_new,"JsonParser_32","new",0x7c04fc49,"JsonParser_32.new","json2object/reader/DataBuilder.hx",961,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_c4324b57e9095362_966_onIncorrectType,"JsonParser_32","onIncorrectType",0x941fe549,"JsonParser_32.onIncorrectType","json2object/reader/DataBuilder.hx",966,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_c4324b57e9095362_123_loadJsonNumber,"JsonParser_32","loadJsonNumber",0xa7b3cf8e,"JsonParser_32.loadJsonNumber","json2object/reader/DataBuilder.hx",123,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_c4324b57e9095362_995_getAuto,"JsonParser_32","getAuto",0x1e79638e,"JsonParser_32.getAuto","json2object/reader/DataBuilder.hx",995,0x0533cd73)

void JsonParser_32_obj::__construct(::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType){
            		 ::Dynamic errorType = __o_errorType;
            		if (::hx::IsNull(__o_errorType)) errorType = 0;
            	HX_STACKFRAME(&_hx_pos_c4324b57e9095362_961_new)
HXLINE( 962)		super::__construct(errors,putils,errorType);
HXLINE( 948)		this->value = 0;
            	}

Dynamic JsonParser_32_obj::__CreateEmpty() { return new JsonParser_32_obj; }

void *JsonParser_32_obj::_hx_vtable = 0;

Dynamic JsonParser_32_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< JsonParser_32_obj > _hx_result = new JsonParser_32_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return _hx_result;
}

bool JsonParser_32_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x0f6d5b90) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x0f6d5b90;
	} else {
		return inClassId==(int)0x686c4933;
	}
}

void JsonParser_32_obj::onIncorrectType( ::Dynamic pos,::String variable){
            	HX_STACKFRAME(&_hx_pos_c4324b57e9095362_966_onIncorrectType)
HXLINE( 967)		this->errors->push(::json2object::Error_obj::IncorrectType(variable,HX_("Float",7c,35,c4,95),pos));
HXLINE( 968)		this->super::onIncorrectType(pos,variable);
            	}


void JsonParser_32_obj::loadJsonNumber(::String f, ::Dynamic pos,::String variable){
            	HX_STACKFRAME(&_hx_pos_c4324b57e9095362_123_loadJsonNumber)
HXDLIN( 123)		this->value = this->loadJsonFloat(f,pos,variable,( (Float)(this->value) ));
            	}


Float JsonParser_32_obj::getAuto(){
            	HX_GC_STACKFRAME(&_hx_pos_c4324b57e9095362_995_getAuto)
HXDLIN( 995)		 ::JsonParser_32 _hx_tmp =  ::JsonParser_32_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXDLIN( 995)		return ( (Float)(_hx_tmp->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null())) );
            	}


HX_DEFINE_DYNAMIC_FUNC0(JsonParser_32_obj,getAuto,return )


::hx::ObjectPtr< JsonParser_32_obj > JsonParser_32_obj::__new(::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType) {
	::hx::ObjectPtr< JsonParser_32_obj > __this = new JsonParser_32_obj();
	__this->__construct(errors,putils,__o_errorType);
	return __this;
}

::hx::ObjectPtr< JsonParser_32_obj > JsonParser_32_obj::__alloc(::hx::Ctx *_hx_ctx,::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType) {
	JsonParser_32_obj *__this = (JsonParser_32_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(JsonParser_32_obj), true, "JsonParser_32"));
	*(void **)__this = JsonParser_32_obj::_hx_vtable;
	__this->__construct(errors,putils,__o_errorType);
	return __this;
}

JsonParser_32_obj::JsonParser_32_obj()
{
}

::hx::Val JsonParser_32_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"getAuto") ) { return ::hx::Val( getAuto_dyn() ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"loadJsonNumber") ) { return ::hx::Val( loadJsonNumber_dyn() ); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"onIncorrectType") ) { return ::hx::Val( onIncorrectType_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *JsonParser_32_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *JsonParser_32_obj_sStaticStorageInfo = 0;
#endif

static ::String JsonParser_32_obj_sMemberFields[] = {
	HX_("onIncorrectType",e0,ff,a7,01),
	HX_("loadJsonNumber",d7,54,20,79),
	HX_("getAuto",25,8f,f9,12),
	::String(null()) };

::hx::Class JsonParser_32_obj::__mClass;

void JsonParser_32_obj::__register()
{
	JsonParser_32_obj _hx_dummy;
	JsonParser_32_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("JsonParser_32",d7,23,55,bd);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(JsonParser_32_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< JsonParser_32_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = JsonParser_32_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = JsonParser_32_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

