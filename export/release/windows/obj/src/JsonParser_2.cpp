#include <hxcpp.h>

#ifndef INCLUDED_JsonParser_2
#include <JsonParser_2.h>
#endif
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

HX_DEFINE_STACK_FRAME(_hx_pos_1ab4cad8f7073b4b_938_new,"JsonParser_2","new",0xa0a7fdec,"JsonParser_2.new","json2object/reader/DataBuilder.hx",938,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_1ab4cad8f7073b4b_942_onIncorrectType,"JsonParser_2","onIncorrectType",0xcb504f6c,"JsonParser_2.onIncorrectType","json2object/reader/DataBuilder.hx",942,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_1ab4cad8f7073b4b_162_loadJsonNull,"JsonParser_2","loadJsonNull",0xf700ee09,"JsonParser_2.loadJsonNull","json2object/reader/DataBuilder.hx",162,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_1ab4cad8f7073b4b_158_loadJsonArray,"JsonParser_2","loadJsonArray",0xaba2afd7,"JsonParser_2.loadJsonArray","json2object/reader/DataBuilder.hx",158,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_1ab4cad8f7073b4b_971_getAuto,"JsonParser_2","getAuto",0x118172b1,"JsonParser_2.getAuto","json2object/reader/DataBuilder.hx",971,0x0533cd73)

void JsonParser_2_obj::__construct(::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType){
            		 ::Dynamic errorType = __o_errorType;
            		if (::hx::IsNull(__o_errorType)) errorType = 0;
            	HX_STACKFRAME(&_hx_pos_1ab4cad8f7073b4b_938_new)
HXDLIN( 938)		super::__construct(errors,putils,errorType);
            	}

Dynamic JsonParser_2_obj::__CreateEmpty() { return new JsonParser_2_obj; }

void *JsonParser_2_obj::_hx_vtable = 0;

Dynamic JsonParser_2_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< JsonParser_2_obj > _hx_result = new JsonParser_2_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return _hx_result;
}

bool JsonParser_2_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x0f6d5b90) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x0f6d5b90;
	} else {
		return inClassId==(int)0x194860e6;
	}
}

void JsonParser_2_obj::onIncorrectType( ::Dynamic pos,::String variable){
            	HX_STACKFRAME(&_hx_pos_1ab4cad8f7073b4b_942_onIncorrectType)
HXLINE( 943)		this->errors->push(::json2object::Error_obj::IncorrectType(variable,HX_("Array<String>",ea,f3,93,1e),pos));
HXLINE( 944)		this->super::onIncorrectType(pos,variable);
            	}


void JsonParser_2_obj::loadJsonNull( ::Dynamic pos,::String variable){
            	HX_STACKFRAME(&_hx_pos_1ab4cad8f7073b4b_162_loadJsonNull)
HXDLIN( 162)		this->value = null();
            	}


void JsonParser_2_obj::loadJsonArray(::Array< ::Dynamic> a, ::Dynamic pos,::String variable){
            	HX_GC_STACKFRAME(&_hx_pos_1ab4cad8f7073b4b_158_loadJsonArray)
HXDLIN( 158)		this->value = this->loadJsonArrayValue(a, ::JsonParser_3_obj::__alloc( HX_CTX ,this->errors,this->putils,2)->loadJson_dyn(),variable);
            	}


::Array< ::String > JsonParser_2_obj::getAuto(){
            	HX_GC_STACKFRAME(&_hx_pos_1ab4cad8f7073b4b_971_getAuto)
HXDLIN( 971)		 ::JsonParser_2 _hx_tmp =  ::JsonParser_2_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXDLIN( 971)		return ( (::Array< ::String >)(_hx_tmp->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null())) );
            	}


HX_DEFINE_DYNAMIC_FUNC0(JsonParser_2_obj,getAuto,return )


::hx::ObjectPtr< JsonParser_2_obj > JsonParser_2_obj::__new(::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType) {
	::hx::ObjectPtr< JsonParser_2_obj > __this = new JsonParser_2_obj();
	__this->__construct(errors,putils,__o_errorType);
	return __this;
}

::hx::ObjectPtr< JsonParser_2_obj > JsonParser_2_obj::__alloc(::hx::Ctx *_hx_ctx,::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType) {
	JsonParser_2_obj *__this = (JsonParser_2_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(JsonParser_2_obj), true, "JsonParser_2"));
	*(void **)__this = JsonParser_2_obj::_hx_vtable;
	__this->__construct(errors,putils,__o_errorType);
	return __this;
}

JsonParser_2_obj::JsonParser_2_obj()
{
}

::hx::Val JsonParser_2_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"getAuto") ) { return ::hx::Val( getAuto_dyn() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"loadJsonNull") ) { return ::hx::Val( loadJsonNull_dyn() ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"loadJsonArray") ) { return ::hx::Val( loadJsonArray_dyn() ); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"onIncorrectType") ) { return ::hx::Val( onIncorrectType_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *JsonParser_2_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *JsonParser_2_obj_sStaticStorageInfo = 0;
#endif

static ::String JsonParser_2_obj_sMemberFields[] = {
	HX_("onIncorrectType",e0,ff,a7,01),
	HX_("loadJsonNull",15,2d,09,02),
	HX_("loadJsonArray",4b,9b,d1,47),
	HX_("getAuto",25,8f,f9,12),
	::String(null()) };

::hx::Class JsonParser_2_obj::__mClass;

void JsonParser_2_obj::__register()
{
	JsonParser_2_obj _hx_dummy;
	JsonParser_2_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("JsonParser_2",fa,d7,87,99);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(JsonParser_2_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< JsonParser_2_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = JsonParser_2_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = JsonParser_2_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

