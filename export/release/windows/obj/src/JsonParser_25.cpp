#include <hxcpp.h>

#ifndef INCLUDED_JsonParser_14
#include <JsonParser_14.h>
#endif
#ifndef INCLUDED_JsonParser_16
#include <JsonParser_16.h>
#endif
#ifndef INCLUDED_JsonParser_21
#include <JsonParser_21.h>
#endif
#ifndef INCLUDED_JsonParser_25
#include <JsonParser_25.h>
#endif
#ifndef INCLUDED_JsonParser_3
#include <JsonParser_3.h>
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

HX_DEFINE_STACK_FRAME(_hx_pos_723f50ff7160efa0_938_new,"JsonParser_25","new",0xcfdd5d6d,"JsonParser_25.new","json2object/reader/DataBuilder.hx",938,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_723f50ff7160efa0_942_onIncorrectType,"JsonParser_25","onIncorrectType",0x0a976c6d,"JsonParser_25.onIncorrectType","json2object/reader/DataBuilder.hx",942,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_723f50ff7160efa0_459_loadJsonNull,"JsonParser_25","loadJsonNull",0x412e1668,"JsonParser_25.loadJsonNull","json2object/reader/DataBuilder.hx",459,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_723f50ff7160efa0_446_loadJsonObject,"JsonParser_25","loadJsonObject",0xee1570e0,"JsonParser_25.loadJsonObject","json2object/reader/DataBuilder.hx",446,0x0533cd73)
static const ::String _hx_array_data_bd5522fb_6[] = {
	HX_("framerate",8d,e5,4b,4e),HX_("looped",c3,5f,b9,61),HX_("offset",93,97,3f,60),HX_("prefix",92,d9,b6,ae),
};
static const bool _hx_array_data_bd5522fb_7[] = {
	0,0,0,0,
};
HX_LOCAL_STACK_FRAME(_hx_pos_723f50ff7160efa0_418_getAuto,"JsonParser_25","getAuto",0xd70326b2,"JsonParser_25.getAuto","json2object/reader/DataBuilder.hx",418,0x0533cd73)

void JsonParser_25_obj::__construct(::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType){
            		 ::Dynamic errorType = __o_errorType;
            		if (::hx::IsNull(__o_errorType)) errorType = 0;
            	HX_STACKFRAME(&_hx_pos_723f50ff7160efa0_938_new)
HXDLIN( 938)		super::__construct(errors,putils,errorType);
            	}

Dynamic JsonParser_25_obj::__CreateEmpty() { return new JsonParser_25_obj; }

void *JsonParser_25_obj::_hx_vtable = 0;

Dynamic JsonParser_25_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< JsonParser_25_obj > _hx_result = new JsonParser_25_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return _hx_result;
}

bool JsonParser_25_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x0f6d5b90) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x0f6d5b90;
	} else {
		return inClassId==(int)0x686c4857;
	}
}

void JsonParser_25_obj::onIncorrectType( ::Dynamic pos,::String variable){
            	HX_STACKFRAME(&_hx_pos_723f50ff7160efa0_942_onIncorrectType)
HXLINE( 943)		this->errors->push(::json2object::Error_obj::IncorrectType(variable,HX_("{ prefix : String, offset : Array<Int>, looped : Bool, framerate : Int }",f7,14,8f,1c),pos));
HXLINE( 944)		this->super::onIncorrectType(pos,variable);
            	}


void JsonParser_25_obj::loadJsonNull( ::Dynamic pos,::String variable){
            	HX_STACKFRAME(&_hx_pos_723f50ff7160efa0_459_loadJsonNull)
HXDLIN( 459)		this->value = null();
            	}


void JsonParser_25_obj::loadJsonObject(::Array< ::Dynamic> o, ::Dynamic pos,::String variable){
            	HX_GC_STACKFRAME(&_hx_pos_723f50ff7160efa0_446_loadJsonObject)
HXLINE( 447)		 ::haxe::ds::StringMap assigned =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
HXLINE( 448)		this->objectSetupAssign(assigned,::Array_obj< ::String >::fromData( _hx_array_data_bd5522fb_6,4),::Array_obj< bool >::fromData( _hx_array_data_bd5522fb_7,4));
HXLINE( 449)		this->value = this->getAuto();
HXLINE( 451)		{
HXLINE( 451)			int _g = 0;
HXDLIN( 451)			while((_g < o->length)){
HXLINE( 451)				 ::hxjsonast::JObjectField field = o->__get(_g).StaticCast<  ::hxjsonast::JObjectField >();
HXDLIN( 451)				_g = (_g + 1);
HXLINE( 414)				::String _hx_switch_0 = field->name;
            				if (  (_hx_switch_0==HX_("framerate",8d,e5,4b,4e)) ){
HXLINE( 351)					this->value->__SetField(HX_("framerate",8d,e5,4b,4e),( (int)(this->loadObjectField( ::JsonParser_16_obj::__alloc( HX_CTX ,this->errors,this->putils,1)->loadJson_dyn(),field,HX_("framerate",8d,e5,4b,4e),assigned, ::Dynamic(this->value->__Field(HX_("framerate",8d,e5,4b,4e),::hx::paccDynamic)),pos)) ),::hx::paccDynamic);
HXDLIN( 351)					goto _hx_goto_4;
            				}
            				if (  (_hx_switch_0==HX_("looped",c3,5f,b9,61)) ){
HXLINE( 351)					this->value->__SetField(HX_("looped",c3,5f,b9,61),( (bool)(this->loadObjectField( ::JsonParser_14_obj::__alloc( HX_CTX ,this->errors,this->putils,1)->loadJson_dyn(),field,HX_("looped",c3,5f,b9,61),assigned, ::Dynamic(this->value->__Field(HX_("looped",c3,5f,b9,61),::hx::paccDynamic)),pos)) ),::hx::paccDynamic);
HXDLIN( 351)					goto _hx_goto_4;
            				}
            				if (  (_hx_switch_0==HX_("offset",93,97,3f,60)) ){
HXLINE( 342)					 ::Dynamic v = this->loadObjectField( ::JsonParser_21_obj::__alloc( HX_CTX ,this->errors,this->putils,1)->loadJson_dyn(),field,HX_("offset",93,97,3f,60),assigned, ::Dynamic(this->value->__Field(HX_("offset",93,97,3f,60),::hx::paccDynamic)),pos);
HXLINE( 343)					if (::hx::IsNotNull( v )) {
HXLINE( 344)						this->value->__SetField(HX_("offset",93,97,3f,60),( (::Array< int >)(v) ),::hx::paccDynamic);
            					}
            					else {
HXLINE( 346)						this->value->__SetField(HX_("offset",93,97,3f,60),null(),::hx::paccDynamic);
            					}
HXLINE( 341)					goto _hx_goto_4;
            				}
            				if (  (_hx_switch_0==HX_("prefix",92,d9,b6,ae)) ){
HXLINE( 342)					 ::Dynamic v = this->loadObjectField( ::JsonParser_3_obj::__alloc( HX_CTX ,this->errors,this->putils,1)->loadJson_dyn(),field,HX_("prefix",92,d9,b6,ae),assigned, ::Dynamic(this->value->__Field(HX_("prefix",92,d9,b6,ae),::hx::paccDynamic)),pos);
HXLINE( 343)					if (::hx::IsNotNull( v )) {
HXLINE( 344)						this->value->__SetField(HX_("prefix",92,d9,b6,ae),( (::String)(v) ),::hx::paccDynamic);
            					}
            					else {
HXLINE( 346)						this->value->__SetField(HX_("prefix",92,d9,b6,ae),null(),::hx::paccDynamic);
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


 ::Dynamic JsonParser_25_obj::getAuto(){
            	HX_GC_STACKFRAME(&_hx_pos_723f50ff7160efa0_418_getAuto)
HXLINE( 397)		 ::JsonParser_16 _hx_tmp =  ::JsonParser_16_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXDLIN( 397)		int _hx_tmp1 = ( (int)(_hx_tmp->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null())) );
HXDLIN( 397)		 ::JsonParser_14 _hx_tmp2 =  ::JsonParser_14_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXDLIN( 397)		bool _hx_tmp3 = ( (bool)(_hx_tmp2->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null())) );
HXDLIN( 397)		 ::JsonParser_21 _hx_tmp4 =  ::JsonParser_21_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXDLIN( 397)		::Array< int > _hx_tmp5 = ( (::Array< int >)(_hx_tmp4->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null())) );
HXDLIN( 397)		 ::JsonParser_3 _hx_tmp6 =  ::JsonParser_3_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXLINE( 418)		return  ::Dynamic(::hx::Anon_obj::Create(4)
            			->setFixed(0,HX_("prefix",92,d9,b6,ae),_hx_tmp6->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null()))
            			->setFixed(1,HX_("framerate",8d,e5,4b,4e),_hx_tmp1)
            			->setFixed(2,HX_("offset",93,97,3f,60),_hx_tmp5)
            			->setFixed(3,HX_("looped",c3,5f,b9,61),_hx_tmp3));
            	}


HX_DEFINE_DYNAMIC_FUNC0(JsonParser_25_obj,getAuto,return )


::hx::ObjectPtr< JsonParser_25_obj > JsonParser_25_obj::__new(::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType) {
	::hx::ObjectPtr< JsonParser_25_obj > __this = new JsonParser_25_obj();
	__this->__construct(errors,putils,__o_errorType);
	return __this;
}

::hx::ObjectPtr< JsonParser_25_obj > JsonParser_25_obj::__alloc(::hx::Ctx *_hx_ctx,::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType) {
	JsonParser_25_obj *__this = (JsonParser_25_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(JsonParser_25_obj), true, "JsonParser_25"));
	*(void **)__this = JsonParser_25_obj::_hx_vtable;
	__this->__construct(errors,putils,__o_errorType);
	return __this;
}

JsonParser_25_obj::JsonParser_25_obj()
{
}

::hx::Val JsonParser_25_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
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
static ::hx::StorageInfo *JsonParser_25_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *JsonParser_25_obj_sStaticStorageInfo = 0;
#endif

static ::String JsonParser_25_obj_sMemberFields[] = {
	HX_("onIncorrectType",e0,ff,a7,01),
	HX_("loadJsonNull",15,2d,09,02),
	HX_("loadJsonObject",cd,4c,e5,ec),
	HX_("getAuto",25,8f,f9,12),
	::String(null()) };

::hx::Class JsonParser_25_obj::__mClass;

void JsonParser_25_obj::__register()
{
	JsonParser_25_obj _hx_dummy;
	JsonParser_25_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("JsonParser_25",fb,22,55,bd);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(JsonParser_25_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< JsonParser_25_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = JsonParser_25_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = JsonParser_25_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

