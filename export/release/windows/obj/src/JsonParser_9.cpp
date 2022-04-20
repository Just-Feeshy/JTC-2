#include <hxcpp.h>

#ifndef INCLUDED_JsonParser_14
#include <JsonParser_14.h>
#endif
#ifndef INCLUDED_JsonParser_15
#include <JsonParser_15.h>
#endif
#ifndef INCLUDED_JsonParser_2
#include <JsonParser_2.h>
#endif
#ifndef INCLUDED_JsonParser_9
#include <JsonParser_9.h>
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

HX_DEFINE_STACK_FRAME(_hx_pos_af4cbf4fd1ed7b1a_938_new,"JsonParser_9","new",0xa8760d73,"JsonParser_9.new","json2object/reader/DataBuilder.hx",938,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_af4cbf4fd1ed7b1a_942_onIncorrectType,"JsonParser_9","onIncorrectType",0x5ffb0d73,"JsonParser_9.onIncorrectType","json2object/reader/DataBuilder.hx",942,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_af4cbf4fd1ed7b1a_459_loadJsonNull,"JsonParser_9","loadJsonNull",0x49be35a2,"JsonParser_9.loadJsonNull","json2object/reader/DataBuilder.hx",459,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_af4cbf4fd1ed7b1a_446_loadJsonObject,"JsonParser_9","loadJsonObject",0x5257529a,"JsonParser_9.loadJsonObject","json2object/reader/DataBuilder.hx",446,0x0533cd73)
static const ::String _hx_array_data_9987d801_6[] = {
	HX_("credit_engine_creator",75,3e,38,77),HX_("mod_creators",a4,10,9b,6f),HX_("random_waky",34,2b,6b,d9),HX_("waky",38,5c,f2,4e),
};
static const bool _hx_array_data_9987d801_7[] = {
	0,0,0,0,
};
HX_LOCAL_STACK_FRAME(_hx_pos_af4cbf4fd1ed7b1a_418_getAuto,"JsonParser_9","getAuto",0xd61b51b8,"JsonParser_9.getAuto","json2object/reader/DataBuilder.hx",418,0x0533cd73)

void JsonParser_9_obj::__construct(::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType){
            		 ::Dynamic errorType = __o_errorType;
            		if (::hx::IsNull(__o_errorType)) errorType = 0;
            	HX_STACKFRAME(&_hx_pos_af4cbf4fd1ed7b1a_938_new)
HXDLIN( 938)		super::__construct(errors,putils,errorType);
            	}

Dynamic JsonParser_9_obj::__CreateEmpty() { return new JsonParser_9_obj; }

void *JsonParser_9_obj::_hx_vtable = 0;

Dynamic JsonParser_9_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< JsonParser_9_obj > _hx_result = new JsonParser_9_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return _hx_result;
}

bool JsonParser_9_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x0f6d5b90) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x0f6d5b90;
	} else {
		return inClassId==(int)0x194860ed;
	}
}

void JsonParser_9_obj::onIncorrectType( ::Dynamic pos,::String variable){
            	HX_STACKFRAME(&_hx_pos_af4cbf4fd1ed7b1a_942_onIncorrectType)
HXLINE( 943)		this->errors->push(::json2object::Error_obj::IncorrectType(variable,HX_("{ waky : Array<String>, random_waky : Array<Array<String>>, mod_creators : Array<String>, credit_engine_creator : Bool }",26,f5,a0,16),pos));
HXLINE( 944)		this->super::onIncorrectType(pos,variable);
            	}


void JsonParser_9_obj::loadJsonNull( ::Dynamic pos,::String variable){
            	HX_STACKFRAME(&_hx_pos_af4cbf4fd1ed7b1a_459_loadJsonNull)
HXDLIN( 459)		this->value = null();
            	}


void JsonParser_9_obj::loadJsonObject(::Array< ::Dynamic> o, ::Dynamic pos,::String variable){
            	HX_GC_STACKFRAME(&_hx_pos_af4cbf4fd1ed7b1a_446_loadJsonObject)
HXLINE( 447)		 ::haxe::ds::StringMap assigned =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
HXLINE( 448)		this->objectSetupAssign(assigned,::Array_obj< ::String >::fromData( _hx_array_data_9987d801_6,4),::Array_obj< bool >::fromData( _hx_array_data_9987d801_7,4));
HXLINE( 449)		this->value = this->getAuto();
HXLINE( 451)		{
HXLINE( 451)			int _g = 0;
HXDLIN( 451)			while((_g < o->length)){
HXLINE( 451)				 ::hxjsonast::JObjectField field = o->__get(_g).StaticCast<  ::hxjsonast::JObjectField >();
HXDLIN( 451)				_g = (_g + 1);
HXLINE( 414)				::String _hx_switch_0 = field->name;
            				if (  (_hx_switch_0==HX_("credit_engine_creator",75,3e,38,77)) ){
HXLINE( 351)					this->value->__SetField(HX_("credit_engine_creator",75,3e,38,77),( (bool)(this->loadObjectField( ::JsonParser_14_obj::__alloc( HX_CTX ,this->errors,this->putils,1)->loadJson_dyn(),field,HX_("credit_engine_creator",75,3e,38,77),assigned, ::Dynamic(this->value->__Field(HX_("credit_engine_creator",75,3e,38,77),::hx::paccDynamic)),pos)) ),::hx::paccDynamic);
HXDLIN( 351)					goto _hx_goto_4;
            				}
            				if (  (_hx_switch_0==HX_("mod_creators",a4,10,9b,6f)) ){
HXLINE( 342)					 ::Dynamic v = this->loadObjectField( ::JsonParser_2_obj::__alloc( HX_CTX ,this->errors,this->putils,1)->loadJson_dyn(),field,HX_("mod_creators",a4,10,9b,6f),assigned, ::Dynamic(this->value->__Field(HX_("mod_creators",a4,10,9b,6f),::hx::paccDynamic)),pos);
HXLINE( 343)					if (::hx::IsNotNull( v )) {
HXLINE( 344)						this->value->__SetField(HX_("mod_creators",a4,10,9b,6f),( (::Array< ::String >)(v) ),::hx::paccDynamic);
            					}
            					else {
HXLINE( 346)						this->value->__SetField(HX_("mod_creators",a4,10,9b,6f),null(),::hx::paccDynamic);
            					}
HXLINE( 341)					goto _hx_goto_4;
            				}
            				if (  (_hx_switch_0==HX_("random_waky",34,2b,6b,d9)) ){
HXLINE( 342)					 ::Dynamic v = this->loadObjectField( ::JsonParser_15_obj::__alloc( HX_CTX ,this->errors,this->putils,1)->loadJson_dyn(),field,HX_("random_waky",34,2b,6b,d9),assigned, ::Dynamic(this->value->__Field(HX_("random_waky",34,2b,6b,d9),::hx::paccDynamic)),pos);
HXLINE( 343)					if (::hx::IsNotNull( v )) {
HXLINE( 344)						this->value->__SetField(HX_("random_waky",34,2b,6b,d9),( (::Array< ::Dynamic>)(v) ),::hx::paccDynamic);
            					}
            					else {
HXLINE( 346)						this->value->__SetField(HX_("random_waky",34,2b,6b,d9),null(),::hx::paccDynamic);
            					}
HXLINE( 341)					goto _hx_goto_4;
            				}
            				if (  (_hx_switch_0==HX_("waky",38,5c,f2,4e)) ){
HXLINE( 342)					 ::Dynamic v = this->loadObjectField( ::JsonParser_2_obj::__alloc( HX_CTX ,this->errors,this->putils,1)->loadJson_dyn(),field,HX_("waky",38,5c,f2,4e),assigned, ::Dynamic(this->value->__Field(HX_("waky",38,5c,f2,4e),::hx::paccDynamic)),pos);
HXLINE( 343)					if (::hx::IsNotNull( v )) {
HXLINE( 344)						this->value->__SetField(HX_("waky",38,5c,f2,4e),( (::Array< ::String >)(v) ),::hx::paccDynamic);
            					}
            					else {
HXLINE( 346)						this->value->__SetField(HX_("waky",38,5c,f2,4e),null(),::hx::paccDynamic);
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


 ::Dynamic JsonParser_9_obj::getAuto(){
            	HX_GC_STACKFRAME(&_hx_pos_af4cbf4fd1ed7b1a_418_getAuto)
HXLINE( 397)		 ::JsonParser_14 _hx_tmp =  ::JsonParser_14_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXDLIN( 397)		bool _hx_tmp1 = ( (bool)(_hx_tmp->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null())) );
HXDLIN( 397)		 ::JsonParser_2 _hx_tmp2 =  ::JsonParser_2_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXDLIN( 397)		::Array< ::String > _hx_tmp3 = ( (::Array< ::String >)(_hx_tmp2->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null())) );
HXDLIN( 397)		 ::JsonParser_15 _hx_tmp4 =  ::JsonParser_15_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXDLIN( 397)		::Array< ::Dynamic> _hx_tmp5 = ( (::Array< ::Dynamic>)(_hx_tmp4->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null())) );
HXDLIN( 397)		 ::JsonParser_2 _hx_tmp6 =  ::JsonParser_2_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXLINE( 418)		return  ::Dynamic(::hx::Anon_obj::Create(4)
            			->setFixed(0,HX_("random_waky",34,2b,6b,d9),_hx_tmp5)
            			->setFixed(1,HX_("waky",38,5c,f2,4e),_hx_tmp6->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null()))
            			->setFixed(2,HX_("mod_creators",a4,10,9b,6f),_hx_tmp3)
            			->setFixed(3,HX_("credit_engine_creator",75,3e,38,77),_hx_tmp1));
            	}


HX_DEFINE_DYNAMIC_FUNC0(JsonParser_9_obj,getAuto,return )


::hx::ObjectPtr< JsonParser_9_obj > JsonParser_9_obj::__new(::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType) {
	::hx::ObjectPtr< JsonParser_9_obj > __this = new JsonParser_9_obj();
	__this->__construct(errors,putils,__o_errorType);
	return __this;
}

::hx::ObjectPtr< JsonParser_9_obj > JsonParser_9_obj::__alloc(::hx::Ctx *_hx_ctx,::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType) {
	JsonParser_9_obj *__this = (JsonParser_9_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(JsonParser_9_obj), true, "JsonParser_9"));
	*(void **)__this = JsonParser_9_obj::_hx_vtable;
	__this->__construct(errors,putils,__o_errorType);
	return __this;
}

JsonParser_9_obj::JsonParser_9_obj()
{
}

::hx::Val JsonParser_9_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
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
static ::hx::StorageInfo *JsonParser_9_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *JsonParser_9_obj_sStaticStorageInfo = 0;
#endif

static ::String JsonParser_9_obj_sMemberFields[] = {
	HX_("onIncorrectType",e0,ff,a7,01),
	HX_("loadJsonNull",15,2d,09,02),
	HX_("loadJsonObject",cd,4c,e5,ec),
	HX_("getAuto",25,8f,f9,12),
	::String(null()) };

::hx::Class JsonParser_9_obj::__mClass;

void JsonParser_9_obj::__register()
{
	JsonParser_9_obj _hx_dummy;
	JsonParser_9_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("JsonParser_9",01,d8,87,99);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(JsonParser_9_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< JsonParser_9_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = JsonParser_9_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = JsonParser_9_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

