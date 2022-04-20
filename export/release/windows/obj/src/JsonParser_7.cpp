#include <hxcpp.h>

#ifndef INCLUDED_JsonParser_2
#include <JsonParser_2.h>
#endif
#ifndef INCLUDED_JsonParser_3
#include <JsonParser_3.h>
#endif
#ifndef INCLUDED_JsonParser_7
#include <JsonParser_7.h>
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
#ifndef INCLUDED_json2object_PositionUtils
#include <json2object/PositionUtils.h>
#endif
#ifndef INCLUDED_json2object_reader_BaseParser
#include <json2object/reader/BaseParser.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_f6450e2cd97b40bd_938_new,"JsonParser_7","new",0x81a8e471,"JsonParser_7.new","json2object/reader/DataBuilder.hx",938,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_f6450e2cd97b40bd_942_onIncorrectType,"JsonParser_7","onIncorrectType",0x5a136971,"JsonParser_7.onIncorrectType","json2object/reader/DataBuilder.hx",942,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_f6450e2cd97b40bd_459_loadJsonNull,"JsonParser_7","loadJsonNull",0xc4638ee4,"JsonParser_7.loadJsonNull","json2object/reader/DataBuilder.hx",459,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_f6450e2cd97b40bd_446_loadJsonObject,"JsonParser_7","loadJsonObject",0xc3f7005c,"JsonParser_7.loadJsonObject","json2object/reader/DataBuilder.hx",446,0x0533cd73)
static const ::String _hx_array_data_9987d7ff_6[] = {
	HX_("name",4b,72,ff,48),HX_("stages",f5,fb,f1,05),HX_("version",18,e7,f1,7c),
};
static const bool _hx_array_data_9987d7ff_7[] = {
	0,0,0,
};
HX_LOCAL_STACK_FRAME(_hx_pos_f6450e2cd97b40bd_418_getAuto,"JsonParser_7","getAuto",0x30387fb6,"JsonParser_7.getAuto","json2object/reader/DataBuilder.hx",418,0x0533cd73)

void JsonParser_7_obj::__construct(::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType){
            		 ::Dynamic errorType = __o_errorType;
            		if (::hx::IsNull(__o_errorType)) errorType = 0;
            	HX_STACKFRAME(&_hx_pos_f6450e2cd97b40bd_938_new)
HXDLIN( 938)		super::__construct(errors,putils,errorType);
            	}

Dynamic JsonParser_7_obj::__CreateEmpty() { return new JsonParser_7_obj; }

void *JsonParser_7_obj::_hx_vtable = 0;

Dynamic JsonParser_7_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< JsonParser_7_obj > _hx_result = new JsonParser_7_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return _hx_result;
}

bool JsonParser_7_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x0f6d5b90) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x0f6d5b90;
	} else {
		return inClassId==(int)0x194860eb;
	}
}

void JsonParser_7_obj::onIncorrectType( ::Dynamic pos,::String variable){
            	HX_STACKFRAME(&_hx_pos_f6450e2cd97b40bd_942_onIncorrectType)
HXLINE( 943)		this->errors->push(::json2object::Error_obj::IncorrectType(variable,HX_("{ version : String, stages : Array<String>, name : String }",a4,e8,9e,3f),pos));
HXLINE( 944)		this->super::onIncorrectType(pos,variable);
            	}


void JsonParser_7_obj::loadJsonNull( ::Dynamic pos,::String variable){
            	HX_STACKFRAME(&_hx_pos_f6450e2cd97b40bd_459_loadJsonNull)
HXDLIN( 459)		this->value = null();
            	}


void JsonParser_7_obj::loadJsonObject(::Array< ::Dynamic> o, ::Dynamic pos,::String variable){
            	HX_GC_STACKFRAME(&_hx_pos_f6450e2cd97b40bd_446_loadJsonObject)
HXLINE( 447)		 ::haxe::ds::StringMap assigned =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
HXLINE( 448)		this->objectSetupAssign(assigned,::Array_obj< ::String >::fromData( _hx_array_data_9987d7ff_6,3),::Array_obj< bool >::fromData( _hx_array_data_9987d7ff_7,3));
HXLINE( 449)		this->value = this->getAuto();
HXLINE( 451)		{
HXLINE( 451)			int _g = 0;
HXDLIN( 451)			while((_g < o->length)){
HXLINE( 451)				 ::hxjsonast::JObjectField field = o->__get(_g).StaticCast<  ::hxjsonast::JObjectField >();
HXDLIN( 451)				_g = (_g + 1);
HXLINE( 414)				::String _hx_switch_0 = field->name;
            				if (  (_hx_switch_0==HX_("name",4b,72,ff,48)) ){
HXLINE( 342)					 ::Dynamic v = this->loadObjectField( ::JsonParser_3_obj::__alloc( HX_CTX ,this->errors,this->putils,1)->loadJson_dyn(),field,HX_("name",4b,72,ff,48),assigned, ::Dynamic(this->value->__Field(HX_("name",4b,72,ff,48),::hx::paccDynamic)),pos);
HXLINE( 343)					if (::hx::IsNotNull( v )) {
HXLINE( 344)						this->value->__SetField(HX_("name",4b,72,ff,48),( (::String)(v) ),::hx::paccDynamic);
            					}
            					else {
HXLINE( 346)						this->value->__SetField(HX_("name",4b,72,ff,48),null(),::hx::paccDynamic);
            					}
HXLINE( 341)					goto _hx_goto_4;
            				}
            				if (  (_hx_switch_0==HX_("stages",f5,fb,f1,05)) ){
HXLINE( 342)					 ::Dynamic v = this->loadObjectField( ::JsonParser_2_obj::__alloc( HX_CTX ,this->errors,this->putils,1)->loadJson_dyn(),field,HX_("stages",f5,fb,f1,05),assigned, ::Dynamic(this->value->__Field(HX_("stages",f5,fb,f1,05),::hx::paccDynamic)),pos);
HXLINE( 343)					if (::hx::IsNotNull( v )) {
HXLINE( 344)						this->value->__SetField(HX_("stages",f5,fb,f1,05),( (::Array< ::String >)(v) ),::hx::paccDynamic);
            					}
            					else {
HXLINE( 346)						this->value->__SetField(HX_("stages",f5,fb,f1,05),null(),::hx::paccDynamic);
            					}
HXLINE( 341)					goto _hx_goto_4;
            				}
            				if (  (_hx_switch_0==HX_("version",18,e7,f1,7c)) ){
HXLINE( 342)					 ::Dynamic v = this->loadObjectField( ::JsonParser_3_obj::__alloc( HX_CTX ,this->errors,this->putils,1)->loadJson_dyn(),field,HX_("version",18,e7,f1,7c),assigned, ::Dynamic(this->value->__Field(HX_("version",18,e7,f1,7c),::hx::paccDynamic)),pos);
HXLINE( 343)					if (::hx::IsNotNull( v )) {
HXLINE( 344)						this->value->__SetField(HX_("version",18,e7,f1,7c),( (::String)(v) ),::hx::paccDynamic);
            					}
            					else {
HXLINE( 346)						this->value->__SetField(HX_("version",18,e7,f1,7c),null(),::hx::paccDynamic);
            					}
HXLINE( 341)					goto _hx_goto_4;
            				}
            				/* default */{
HXLINE( 413)					::Array< ::Dynamic> _hx_tmp = this->errors;
HXDLIN( 413)					::String field1 = field->name;
HXDLIN( 413)					_hx_tmp->push(::json2object::Error_obj::UnknownVariable(field1,this->putils->convertPosition(field->namePos)));
            				}
            				_hx_goto_4:;
            			}
            		}
HXLINE( 455)		this->objectErrors(assigned,pos);
            	}


 ::Dynamic JsonParser_7_obj::getAuto(){
            	HX_GC_STACKFRAME(&_hx_pos_f6450e2cd97b40bd_418_getAuto)
HXLINE( 397)		 ::JsonParser_3 _hx_tmp =  ::JsonParser_3_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXDLIN( 397)		::String _hx_tmp1 = ( (::String)(_hx_tmp->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null())) );
HXDLIN( 397)		 ::JsonParser_2 _hx_tmp2 =  ::JsonParser_2_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXDLIN( 397)		::Array< ::String > _hx_tmp3 = ( (::Array< ::String >)(_hx_tmp2->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null())) );
HXDLIN( 397)		 ::JsonParser_3 _hx_tmp4 =  ::JsonParser_3_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXLINE( 418)		return  ::Dynamic(::hx::Anon_obj::Create(3)
            			->setFixed(0,HX_("stages",f5,fb,f1,05),_hx_tmp3)
            			->setFixed(1,HX_("name",4b,72,ff,48),_hx_tmp1)
            			->setFixed(2,HX_("version",18,e7,f1,7c),_hx_tmp4->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null())));
            	}


HX_DEFINE_DYNAMIC_FUNC0(JsonParser_7_obj,getAuto,return )


::hx::ObjectPtr< JsonParser_7_obj > JsonParser_7_obj::__new(::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType) {
	::hx::ObjectPtr< JsonParser_7_obj > __this = new JsonParser_7_obj();
	__this->__construct(errors,putils,__o_errorType);
	return __this;
}

::hx::ObjectPtr< JsonParser_7_obj > JsonParser_7_obj::__alloc(::hx::Ctx *_hx_ctx,::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType) {
	JsonParser_7_obj *__this = (JsonParser_7_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(JsonParser_7_obj), true, "JsonParser_7"));
	*(void **)__this = JsonParser_7_obj::_hx_vtable;
	__this->__construct(errors,putils,__o_errorType);
	return __this;
}

JsonParser_7_obj::JsonParser_7_obj()
{
}

::hx::Val JsonParser_7_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
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
static ::hx::StorageInfo *JsonParser_7_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *JsonParser_7_obj_sStaticStorageInfo = 0;
#endif

static ::String JsonParser_7_obj_sMemberFields[] = {
	HX_("onIncorrectType",e0,ff,a7,01),
	HX_("loadJsonNull",15,2d,09,02),
	HX_("loadJsonObject",cd,4c,e5,ec),
	HX_("getAuto",25,8f,f9,12),
	::String(null()) };

::hx::Class JsonParser_7_obj::__mClass;

void JsonParser_7_obj::__register()
{
	JsonParser_7_obj _hx_dummy;
	JsonParser_7_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("JsonParser_7",ff,d7,87,99);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(JsonParser_7_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< JsonParser_7_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = JsonParser_7_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = JsonParser_7_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

