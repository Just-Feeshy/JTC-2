#include <hxcpp.h>

#ifndef INCLUDED_JsonParser_20
#include <JsonParser_20.h>
#endif
#ifndef INCLUDED_JsonParser_25
#include <JsonParser_25.h>
#endif
#ifndef INCLUDED_JsonParser_3
#include <JsonParser_3.h>
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

HX_DEFINE_STACK_FRAME(_hx_pos_672342416efd83f7_938_new,"JsonParser_20","new",0xeedc76e8,"JsonParser_20.new","json2object/reader/DataBuilder.hx",938,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_672342416efd83f7_942_onIncorrectType,"JsonParser_20","onIncorrectType",0x7bd45268,"JsonParser_20.onIncorrectType","json2object/reader/DataBuilder.hx",942,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_672342416efd83f7_523_loadJsonNull,"JsonParser_20","loadJsonNull",0x73cb758d,"JsonParser_20.loadJsonNull","json2object/reader/DataBuilder.hx",523,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_672342416efd83f7_515_loadJsonObject,"JsonParser_20","loadJsonObject",0x0a24a345,"JsonParser_20.loadJsonObject","json2object/reader/DataBuilder.hx",515,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_672342416efd83f7_971_getAuto,"JsonParser_20","getAuto",0xb84c19ad,"JsonParser_20.getAuto","json2object/reader/DataBuilder.hx",971,0x0533cd73)

void JsonParser_20_obj::__construct(::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType){
            		 ::Dynamic errorType = __o_errorType;
            		if (::hx::IsNull(__o_errorType)) errorType = 0;
            	HX_STACKFRAME(&_hx_pos_672342416efd83f7_938_new)
HXDLIN( 938)		super::__construct(errors,putils,errorType);
            	}

Dynamic JsonParser_20_obj::__CreateEmpty() { return new JsonParser_20_obj; }

void *JsonParser_20_obj::_hx_vtable = 0;

Dynamic JsonParser_20_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< JsonParser_20_obj > _hx_result = new JsonParser_20_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return _hx_result;
}

bool JsonParser_20_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x0f6d5b90) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x0f6d5b90;
	} else {
		return inClassId==(int)0x686c4852;
	}
}

void JsonParser_20_obj::onIncorrectType( ::Dynamic pos,::String variable){
            	HX_STACKFRAME(&_hx_pos_672342416efd83f7_942_onIncorrectType)
HXLINE( 943)		this->errors->push(::json2object::Error_obj::IncorrectType(variable,HX_("haxe.ds.Map<String, AnimationInfo>",68,4f,33,d6),pos));
HXLINE( 944)		this->super::onIncorrectType(pos,variable);
            	}


void JsonParser_20_obj::loadJsonNull( ::Dynamic pos,::String variable){
            	HX_STACKFRAME(&_hx_pos_672342416efd83f7_523_loadJsonNull)
HXDLIN( 523)		this->value = null();
            	}


void JsonParser_20_obj::loadJsonObject(::Array< ::Dynamic> o, ::Dynamic pos,::String variable){
            	HX_GC_STACKFRAME(&_hx_pos_672342416efd83f7_515_loadJsonObject)
HXLINE( 516)		this->value =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
HXLINE( 517)		{
HXLINE( 517)			int _g = 0;
HXDLIN( 517)			while((_g < o->length)){
HXLINE( 517)				 ::hxjsonast::JObjectField field = o->__get(_g).StaticCast<  ::hxjsonast::JObjectField >();
HXDLIN( 517)				_g = (_g + 1);
HXLINE( 518)				{
HXLINE( 518)					::Dynamic this1 = this->value;
HXDLIN( 518)					::String key;
HXLINE( 468)					try {
            						HX_STACK_CATCHABLE( ::Dynamic, 0);
HXLINE( 469)						 ::JsonParser_3 key1 =  ::JsonParser_3_obj::__alloc( HX_CTX ,this->errors,this->putils,2);
HXDLIN( 469)						 ::hxjsonast::JsonValue _g = ::hxjsonast::JsonValue_obj::JString(field->name);
HXDLIN( 469)						 ::json2object::PositionUtils _this = this->putils;
HXLINE( 518)						key = ( (::String)(key1->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,_g, ::hxjsonast::Position_obj::__alloc( HX_CTX ,( (::String)(pos->__Field(HX_("file",7c,ce,bb,43),::hx::paccDynamic)) ),(( (int)(pos->__Field(HX_("min",92,11,53,00),::hx::paccDynamic)) ) - 1),(( (int)(pos->__Field(HX_("max",a4,0a,53,00),::hx::paccDynamic)) ) - 1))),variable)) );
            					} catch( ::Dynamic _hx_e) {
            						if (_hx_e.IsClass<  ::Dynamic >() ){
            							HX_STACK_BEGIN_CATCH
            							 ::Dynamic _g = _hx_e;
HXLINE(   1)							{
HXLINE(   1)								null();
            							}
HXDLIN(   1)							 ::Dynamic _g1 = ::haxe::Exception_obj::caught(_g)->unwrap();
HXLINE( 468)							if (::Std_obj::isOfType(_g1,::hx::ClassOf< ::json2object::InternalError >())) {
HXLINE(   1)								 ::json2object::InternalError e = _g1;
HXLINE( 471)								if (::hx::IsPointerNotEq( e,::json2object::InternalError_obj::ParsingThrow_dyn() )) {
HXLINE( 472)									HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(e));
            								}
HXLINE( 475)								continue;
            							}
            							else {
HXLINE( 468)								HX_STACK_DO_THROW(_g);
            							}
            						}
            						else {
            							HX_STACK_DO_THROW(_hx_e);
            						}
            					}
HXLINE( 518)					 ::Dynamic value;
HXLINE( 501)					try {
            						HX_STACK_CATCHABLE( ::Dynamic, 0);
HXLINE( 518)						value =  ::JsonParser_25_obj::__alloc( HX_CTX ,this->errors,this->putils,2)->loadJson(field->value,field->name);
            					} catch( ::Dynamic _hx_e) {
            						if (_hx_e.IsClass<  ::Dynamic >() ){
            							HX_STACK_BEGIN_CATCH
            							 ::Dynamic _g = _hx_e;
HXLINE(   1)							{
HXLINE(   1)								null();
            							}
HXDLIN(   1)							 ::Dynamic _g1 = ::haxe::Exception_obj::caught(_g)->unwrap();
HXLINE( 501)							if (::Std_obj::isOfType(_g1,::hx::ClassOf< ::json2object::InternalError >())) {
HXLINE(   1)								 ::json2object::InternalError e = _g1;
HXLINE( 505)								if (::hx::IsPointerNotEq( e,::json2object::InternalError_obj::ParsingThrow_dyn() )) {
HXLINE( 506)									HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(e));
            								}
HXLINE( 509)								continue;
            							}
            							else {
HXLINE( 501)								HX_STACK_DO_THROW(_g);
            							}
            						}
            						else {
            							HX_STACK_DO_THROW(_hx_e);
            						}
            					}
HXLINE( 518)					( ( ::haxe::ds::StringMap)(this1) )->set(key,value);
            				}
            			}
            		}
            	}


 ::haxe::ds::StringMap JsonParser_20_obj::getAuto(){
            	HX_GC_STACKFRAME(&_hx_pos_672342416efd83f7_971_getAuto)
HXDLIN( 971)		 ::JsonParser_20 _hx_tmp =  ::JsonParser_20_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXDLIN( 971)		return _hx_tmp->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null()).StaticCast<  ::haxe::ds::StringMap >();
            	}


HX_DEFINE_DYNAMIC_FUNC0(JsonParser_20_obj,getAuto,return )


::hx::ObjectPtr< JsonParser_20_obj > JsonParser_20_obj::__new(::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType) {
	::hx::ObjectPtr< JsonParser_20_obj > __this = new JsonParser_20_obj();
	__this->__construct(errors,putils,__o_errorType);
	return __this;
}

::hx::ObjectPtr< JsonParser_20_obj > JsonParser_20_obj::__alloc(::hx::Ctx *_hx_ctx,::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType) {
	JsonParser_20_obj *__this = (JsonParser_20_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(JsonParser_20_obj), true, "JsonParser_20"));
	*(void **)__this = JsonParser_20_obj::_hx_vtable;
	__this->__construct(errors,putils,__o_errorType);
	return __this;
}

JsonParser_20_obj::JsonParser_20_obj()
{
}

::hx::Val JsonParser_20_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
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
static ::hx::StorageInfo *JsonParser_20_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *JsonParser_20_obj_sStaticStorageInfo = 0;
#endif

static ::String JsonParser_20_obj_sMemberFields[] = {
	HX_("onIncorrectType",e0,ff,a7,01),
	HX_("loadJsonNull",15,2d,09,02),
	HX_("loadJsonObject",cd,4c,e5,ec),
	HX_("getAuto",25,8f,f9,12),
	::String(null()) };

::hx::Class JsonParser_20_obj::__mClass;

void JsonParser_20_obj::__register()
{
	JsonParser_20_obj _hx_dummy;
	JsonParser_20_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("JsonParser_20",f6,22,55,bd);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(JsonParser_20_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< JsonParser_20_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = JsonParser_20_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = JsonParser_20_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

