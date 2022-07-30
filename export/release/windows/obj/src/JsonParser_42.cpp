#include <hxcpp.h>

#ifndef INCLUDED_JsonParser_26
#include <JsonParser_26.h>
#endif
#ifndef INCLUDED_JsonParser_3
#include <JsonParser_3.h>
#endif
#ifndef INCLUDED_JsonParser_42
#include <JsonParser_42.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_Exception
#include <haxe/Exception.h>
#endif
#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_hxjsonast_JObjectField
#include <hxjsonast/JObjectField.h>
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
#ifndef INCLUDED_json2object_InternalError
#include <json2object/InternalError.h>
#endif
#ifndef INCLUDED_json2object_PositionUtils
#include <json2object/PositionUtils.h>
#endif
#ifndef INCLUDED_json2object_reader_BaseParser
#include <json2object/reader/BaseParser.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_b280ff41b0f9b96f_962_new,"JsonParser_42","new",0xe26058a8,"JsonParser_42.new","json2object/reader/DataBuilder.hx",962,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_b280ff41b0f9b96f_966_onIncorrectType,"JsonParser_42","onIncorrectType",0xa683d428,"JsonParser_42.onIncorrectType","json2object/reader/DataBuilder.hx",966,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_b280ff41b0f9b96f_547_loadJsonNull,"JsonParser_42","loadJsonNull",0x231d5bcd,"JsonParser_42.loadJsonNull","json2object/reader/DataBuilder.hx",547,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_b280ff41b0f9b96f_539_loadJsonObject,"JsonParser_42","loadJsonObject",0x9e6c9985,"JsonParser_42.loadJsonObject","json2object/reader/DataBuilder.hx",539,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_b280ff41b0f9b96f_995_getAuto,"JsonParser_42","getAuto",0xdec3db6d,"JsonParser_42.getAuto","json2object/reader/DataBuilder.hx",995,0x0533cd73)

void JsonParser_42_obj::__construct(::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType){
            		 ::Dynamic errorType = __o_errorType;
            		if (::hx::IsNull(__o_errorType)) errorType = 0;
            	HX_STACKFRAME(&_hx_pos_b280ff41b0f9b96f_962_new)
HXDLIN( 962)		super::__construct(errors,putils,errorType);
            	}

Dynamic JsonParser_42_obj::__CreateEmpty() { return new JsonParser_42_obj; }

void *JsonParser_42_obj::_hx_vtable = 0;

Dynamic JsonParser_42_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< JsonParser_42_obj > _hx_result = new JsonParser_42_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return _hx_result;
}

bool JsonParser_42_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x0f6d5b90) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x0f6d5b90;
	} else {
		return inClassId==(int)0x686c4a12;
	}
}

void JsonParser_42_obj::onIncorrectType( ::Dynamic pos,::String variable){
            	HX_STACKFRAME(&_hx_pos_b280ff41b0f9b96f_966_onIncorrectType)
HXLINE( 967)		this->errors->push(::json2object::Error_obj::IncorrectType(variable,HX_("haxe.ds.Map<String, Int>",6b,06,e8,94),pos));
HXLINE( 968)		this->super::onIncorrectType(pos,variable);
            	}


void JsonParser_42_obj::loadJsonNull( ::Dynamic pos,::String variable){
            	HX_STACKFRAME(&_hx_pos_b280ff41b0f9b96f_547_loadJsonNull)
HXDLIN( 547)		this->value = null();
            	}


void JsonParser_42_obj::loadJsonObject(::Array< ::Dynamic> o, ::Dynamic pos,::String variable){
            	HX_GC_STACKFRAME(&_hx_pos_b280ff41b0f9b96f_539_loadJsonObject)
HXLINE( 540)		this->value =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
HXLINE( 541)		{
HXLINE( 541)			int _g = 0;
HXDLIN( 541)			while((_g < o->length)){
HXLINE( 541)				 ::hxjsonast::JObjectField field = o->__get(_g).StaticCast<  ::hxjsonast::JObjectField >();
HXDLIN( 541)				_g = (_g + 1);
HXLINE( 542)				{
HXLINE( 542)					::Dynamic this1 = this->value;
HXDLIN( 542)					::String key;
HXLINE( 492)					try {
            						HX_STACK_CATCHABLE( ::Dynamic, 0);
HXLINE( 493)						 ::JsonParser_3 key1 =  ::JsonParser_3_obj::__alloc( HX_CTX ,this->errors,this->putils,2);
HXDLIN( 493)						 ::hxjsonast::JsonValue _g = ::hxjsonast::JsonValue_obj::JString(field->name);
HXDLIN( 493)						 ::json2object::PositionUtils _this = this->putils;
HXLINE( 542)						key = ( (::String)(key1->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,_g, ::hxjsonast::Position_obj::__alloc( HX_CTX ,( (::String)(pos->__Field(HX_("file",7c,ce,bb,43),::hx::paccDynamic)) ),(( (int)(pos->__Field(HX_("min",92,11,53,00),::hx::paccDynamic)) ) - 1),(( (int)(pos->__Field(HX_("max",a4,0a,53,00),::hx::paccDynamic)) ) - 1))),variable)) );
            					} catch( ::Dynamic _hx_e) {
            						if (_hx_e.IsClass<  ::Dynamic >() ){
            							HX_STACK_BEGIN_CATCH
            							 ::Dynamic _g = _hx_e;
HXLINE(   1)							{
HXLINE(   1)								null();
            							}
HXDLIN(   1)							 ::Dynamic _g1 = ::haxe::Exception_obj::caught(_g)->unwrap();
HXLINE( 492)							if (::Std_obj::isOfType(_g1,::hx::ClassOf< ::json2object::InternalError >())) {
HXLINE(   1)								 ::json2object::InternalError e = _g1;
HXLINE( 495)								if (::hx::IsPointerNotEq( e,::json2object::InternalError_obj::ParsingThrow_dyn() )) {
HXLINE( 496)									HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(e));
            								}
HXLINE( 499)								continue;
            							}
            							else {
HXLINE( 492)								HX_STACK_DO_THROW(_g);
            							}
            						}
            						else {
            							HX_STACK_DO_THROW(_hx_e);
            						}
            					}
HXLINE( 542)					int value;
HXLINE( 525)					try {
            						HX_STACK_CATCHABLE( ::Dynamic, 0);
HXLINE( 542)						value = ( (int)( ::JsonParser_26_obj::__alloc( HX_CTX ,this->errors,this->putils,2)->loadJson(field->value,field->name)) );
            					} catch( ::Dynamic _hx_e) {
            						if (_hx_e.IsClass<  ::Dynamic >() ){
            							HX_STACK_BEGIN_CATCH
            							 ::Dynamic _g = _hx_e;
HXLINE(   1)							{
HXLINE(   1)								null();
            							}
HXDLIN(   1)							 ::Dynamic _g1 = ::haxe::Exception_obj::caught(_g)->unwrap();
HXLINE( 525)							if (::Std_obj::isOfType(_g1,::hx::ClassOf< ::json2object::InternalError >())) {
HXLINE(   1)								 ::json2object::InternalError e = _g1;
HXLINE( 529)								if (::hx::IsPointerNotEq( e,::json2object::InternalError_obj::ParsingThrow_dyn() )) {
HXLINE( 530)									HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(e));
            								}
HXLINE( 533)								continue;
            							}
            							else {
HXLINE( 525)								HX_STACK_DO_THROW(_g);
            							}
            						}
            						else {
            							HX_STACK_DO_THROW(_hx_e);
            						}
            					}
HXLINE( 542)					( ( ::haxe::ds::StringMap)(this1) )->set(key,value);
            				}
            			}
            		}
            	}


 ::haxe::ds::StringMap JsonParser_42_obj::getAuto(){
            	HX_GC_STACKFRAME(&_hx_pos_b280ff41b0f9b96f_995_getAuto)
HXDLIN( 995)		 ::JsonParser_42 _hx_tmp =  ::JsonParser_42_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXDLIN( 995)		return _hx_tmp->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null()).StaticCast<  ::haxe::ds::StringMap >();
            	}


HX_DEFINE_DYNAMIC_FUNC0(JsonParser_42_obj,getAuto,return )


::hx::ObjectPtr< JsonParser_42_obj > JsonParser_42_obj::__new(::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType) {
	::hx::ObjectPtr< JsonParser_42_obj > __this = new JsonParser_42_obj();
	__this->__construct(errors,putils,__o_errorType);
	return __this;
}

::hx::ObjectPtr< JsonParser_42_obj > JsonParser_42_obj::__alloc(::hx::Ctx *_hx_ctx,::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType) {
	JsonParser_42_obj *__this = (JsonParser_42_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(JsonParser_42_obj), true, "JsonParser_42"));
	*(void **)__this = JsonParser_42_obj::_hx_vtable;
	__this->__construct(errors,putils,__o_errorType);
	return __this;
}

JsonParser_42_obj::JsonParser_42_obj()
{
}

::hx::Val JsonParser_42_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"getAuto") ) { return ::hx::Val( getAuto_dyn() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"loadJsonNull") ) { return ::hx::Val( loadJsonNull_dyn() ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"loadJsonObject") ) { return ::hx::Val( loadJsonObject_dyn() ); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"onIncorrectType") ) { return ::hx::Val( onIncorrectType_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *JsonParser_42_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *JsonParser_42_obj_sStaticStorageInfo = 0;
#endif

static ::String JsonParser_42_obj_sMemberFields[] = {
	HX_("onIncorrectType",e0,ff,a7,01),
	HX_("loadJsonNull",15,2d,09,02),
	HX_("loadJsonObject",cd,4c,e5,ec),
	HX_("getAuto",25,8f,f9,12),
	::String(null()) };

::hx::Class JsonParser_42_obj::__mClass;

void JsonParser_42_obj::__register()
{
	JsonParser_42_obj _hx_dummy;
	JsonParser_42_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("JsonParser_42",b6,24,55,bd);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(JsonParser_42_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< JsonParser_42_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = JsonParser_42_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = JsonParser_42_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

