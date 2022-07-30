#include <hxcpp.h>

#ifndef INCLUDED_JsonParser_26
#include <JsonParser_26.h>
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

HX_DEFINE_STACK_FRAME(_hx_pos_4e2fae9a465a7b95_961_new,"JsonParser_26","new",0x6343f1ee,"JsonParser_26.new","json2object/reader/DataBuilder.hx",961,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_4e2fae9a465a7b95_966_onIncorrectType,"JsonParser_26","onIncorrectType",0x8d8b3e6e,"JsonParser_26.onIncorrectType","json2object/reader/DataBuilder.hx",966,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_4e2fae9a465a7b95_103_loadJsonNumber,"JsonParser_26","loadJsonNumber",0x4180a209,"JsonParser_26.loadJsonNumber","json2object/reader/DataBuilder.hx",103,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_4e2fae9a465a7b95_995_getAuto,"JsonParser_26","getAuto",0xa9f48fb3,"JsonParser_26.getAuto","json2object/reader/DataBuilder.hx",995,0x0533cd73)

void JsonParser_26_obj::__construct(::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType){
            		 ::Dynamic errorType = __o_errorType;
            		if (::hx::IsNull(__o_errorType)) errorType = 0;
            	HX_STACKFRAME(&_hx_pos_4e2fae9a465a7b95_961_new)
HXLINE( 962)		super::__construct(errors,putils,errorType);
HXLINE( 948)		this->value = 0;
            	}

Dynamic JsonParser_26_obj::__CreateEmpty() { return new JsonParser_26_obj; }

void *JsonParser_26_obj::_hx_vtable = 0;

Dynamic JsonParser_26_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< JsonParser_26_obj > _hx_result = new JsonParser_26_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return _hx_result;
}

bool JsonParser_26_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x0f6d5b90) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x0f6d5b90;
	} else {
		return inClassId==(int)0x686c4858;
	}
}

void JsonParser_26_obj::onIncorrectType( ::Dynamic pos,::String variable){
            	HX_STACKFRAME(&_hx_pos_4e2fae9a465a7b95_966_onIncorrectType)
HXLINE( 967)		this->errors->push(::json2object::Error_obj::IncorrectType(variable,HX_("Int",cf,c4,37,00),pos));
HXLINE( 968)		this->super::onIncorrectType(pos,variable);
            	}


void JsonParser_26_obj::loadJsonNumber(::String f, ::Dynamic pos,::String variable){
            	HX_STACKFRAME(&_hx_pos_4e2fae9a465a7b95_103_loadJsonNumber)
HXDLIN( 103)		this->value = this->loadJsonInt(f,pos,variable,( (int)(this->value) ));
            	}


int JsonParser_26_obj::getAuto(){
            	HX_GC_STACKFRAME(&_hx_pos_4e2fae9a465a7b95_995_getAuto)
HXDLIN( 995)		 ::JsonParser_26 _hx_tmp =  ::JsonParser_26_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXDLIN( 995)		return ( (int)(_hx_tmp->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null())) );
            	}


HX_DEFINE_DYNAMIC_FUNC0(JsonParser_26_obj,getAuto,return )


::hx::ObjectPtr< JsonParser_26_obj > JsonParser_26_obj::__new(::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType) {
	::hx::ObjectPtr< JsonParser_26_obj > __this = new JsonParser_26_obj();
	__this->__construct(errors,putils,__o_errorType);
	return __this;
}

::hx::ObjectPtr< JsonParser_26_obj > JsonParser_26_obj::__alloc(::hx::Ctx *_hx_ctx,::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType) {
	JsonParser_26_obj *__this = (JsonParser_26_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(JsonParser_26_obj), true, "JsonParser_26"));
	*(void **)__this = JsonParser_26_obj::_hx_vtable;
	__this->__construct(errors,putils,__o_errorType);
	return __this;
}

JsonParser_26_obj::JsonParser_26_obj()
{
}

::hx::Val JsonParser_26_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
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
static ::hx::StorageInfo *JsonParser_26_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *JsonParser_26_obj_sStaticStorageInfo = 0;
#endif

static ::String JsonParser_26_obj_sMemberFields[] = {
	HX_("onIncorrectType",e0,ff,a7,01),
	HX_("loadJsonNumber",d7,54,20,79),
	HX_("getAuto",25,8f,f9,12),
	::String(null()) };

::hx::Class JsonParser_26_obj::__mClass;

void JsonParser_26_obj::__register()
{
	JsonParser_26_obj _hx_dummy;
	JsonParser_26_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("JsonParser_26",fc,22,55,bd);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(JsonParser_26_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< JsonParser_26_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = JsonParser_26_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = JsonParser_26_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

