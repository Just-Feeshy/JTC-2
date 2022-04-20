#include <hxcpp.h>

#ifndef INCLUDED_JsonParser_14
#include <JsonParser_14.h>
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

HX_DEFINE_STACK_FRAME(_hx_pos_a6e54c1b586483d8_937_new,"JsonParser_14","new",0xd61b6c8d,"JsonParser_14.new","json2object/reader/DataBuilder.hx",937,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_a6e54c1b586483d8_942_onIncorrectType,"JsonParser_14","onIncorrectType",0x753fab8d,"JsonParser_14.onIncorrectType","json2object/reader/DataBuilder.hx",942,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_a6e54c1b586483d8_132_loadJsonBool,"JsonParser_14","loadJsonBool",0xe19208eb,"JsonParser_14.loadJsonBool","json2object/reader/DataBuilder.hx",132,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_a6e54c1b586483d8_971_getAuto,"JsonParser_14","getAuto",0x43c745d2,"JsonParser_14.getAuto","json2object/reader/DataBuilder.hx",971,0x0533cd73)

void JsonParser_14_obj::__construct(::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType){
            		 ::Dynamic errorType = __o_errorType;
            		if (::hx::IsNull(__o_errorType)) errorType = 0;
            	HX_STACKFRAME(&_hx_pos_a6e54c1b586483d8_937_new)
HXLINE( 938)		super::__construct(errors,putils,errorType);
HXLINE( 928)		this->value = false;
            	}

Dynamic JsonParser_14_obj::__CreateEmpty() { return new JsonParser_14_obj; }

void *JsonParser_14_obj::_hx_vtable = 0;

Dynamic JsonParser_14_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< JsonParser_14_obj > _hx_result = new JsonParser_14_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return _hx_result;
}

bool JsonParser_14_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x0f6d5b90) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x0f6d5b90;
	} else {
		return inClassId==(int)0x686c4777;
	}
}

void JsonParser_14_obj::onIncorrectType( ::Dynamic pos,::String variable){
            	HX_STACKFRAME(&_hx_pos_a6e54c1b586483d8_942_onIncorrectType)
HXLINE( 943)		this->errors->push(::json2object::Error_obj::IncorrectType(variable,HX_("Bool",4a,b0,f4,2b),pos));
HXLINE( 944)		this->super::onIncorrectType(pos,variable);
            	}


void JsonParser_14_obj::loadJsonBool(bool b, ::Dynamic pos,::String variable){
            	HX_STACKFRAME(&_hx_pos_a6e54c1b586483d8_132_loadJsonBool)
HXDLIN( 132)		this->value = b;
            	}


bool JsonParser_14_obj::getAuto(){
            	HX_GC_STACKFRAME(&_hx_pos_a6e54c1b586483d8_971_getAuto)
HXDLIN( 971)		 ::JsonParser_14 _hx_tmp =  ::JsonParser_14_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXDLIN( 971)		return ( (bool)(_hx_tmp->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null())) );
            	}


HX_DEFINE_DYNAMIC_FUNC0(JsonParser_14_obj,getAuto,return )


::hx::ObjectPtr< JsonParser_14_obj > JsonParser_14_obj::__new(::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType) {
	::hx::ObjectPtr< JsonParser_14_obj > __this = new JsonParser_14_obj();
	__this->__construct(errors,putils,__o_errorType);
	return __this;
}

::hx::ObjectPtr< JsonParser_14_obj > JsonParser_14_obj::__alloc(::hx::Ctx *_hx_ctx,::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType) {
	JsonParser_14_obj *__this = (JsonParser_14_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(JsonParser_14_obj), true, "JsonParser_14"));
	*(void **)__this = JsonParser_14_obj::_hx_vtable;
	__this->__construct(errors,putils,__o_errorType);
	return __this;
}

JsonParser_14_obj::JsonParser_14_obj()
{
}

::hx::Val JsonParser_14_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"getAuto") ) { return ::hx::Val( getAuto_dyn() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"loadJsonBool") ) { return ::hx::Val( loadJsonBool_dyn() ); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"onIncorrectType") ) { return ::hx::Val( onIncorrectType_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *JsonParser_14_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *JsonParser_14_obj_sStaticStorageInfo = 0;
#endif

static ::String JsonParser_14_obj_sMemberFields[] = {
	HX_("onIncorrectType",e0,ff,a7,01),
	HX_("loadJsonBool",b8,12,16,fa),
	HX_("getAuto",25,8f,f9,12),
	::String(null()) };

::hx::Class JsonParser_14_obj::__mClass;

void JsonParser_14_obj::__register()
{
	JsonParser_14_obj _hx_dummy;
	JsonParser_14_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("JsonParser_14",1b,22,55,bd);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(JsonParser_14_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< JsonParser_14_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = JsonParser_14_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = JsonParser_14_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

