#include <hxcpp.h>

#ifndef INCLUDED_JsonParser_26
#include <JsonParser_26.h>
#endif
#ifndef INCLUDED_JsonParser_40
#include <JsonParser_40.h>
#endif
#ifndef INCLUDED_JsonParser_41
#include <JsonParser_41.h>
#endif
#ifndef INCLUDED_JsonParser_42
#include <JsonParser_42.h>
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

HX_DEFINE_STACK_FRAME(_hx_pos_eb2c421d22fabf2c_962_new,"JsonParser_40","new",0xbb932fa6,"JsonParser_40.new","json2object/reader/DataBuilder.hx",962,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_eb2c421d22fabf2c_966_onIncorrectType,"JsonParser_40","onIncorrectType",0xa09c3026,"JsonParser_40.onIncorrectType","json2object/reader/DataBuilder.hx",966,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_eb2c421d22fabf2c_483_loadJsonNull,"JsonParser_40","loadJsonNull",0x9dc2b50f,"JsonParser_40.loadJsonNull","json2object/reader/DataBuilder.hx",483,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_eb2c421d22fabf2c_470_loadJsonObject,"JsonParser_40","loadJsonObject",0x100c4747,"JsonParser_40.loadJsonObject","json2object/reader/DataBuilder.hx",470,0x0533cd73)
static const ::String _hx_array_data_bd5524b4_6[] = {
	HX_("animations",ef,34,1c,83),HX_("assetID",cb,05,dc,36),HX_("size",c1,a0,53,4c),HX_("x",78,00,00,00),HX_("y",79,00,00,00),
};
static const bool _hx_array_data_bd5524b4_7[] = {
	0,0,0,0,0,
};
HX_LOCAL_STACK_FRAME(_hx_pos_eb2c421d22fabf2c_442_getAuto,"JsonParser_40","getAuto",0x38e1096b,"JsonParser_40.getAuto","json2object/reader/DataBuilder.hx",442,0x0533cd73)

void JsonParser_40_obj::__construct(::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType){
            		 ::Dynamic errorType = __o_errorType;
            		if (::hx::IsNull(__o_errorType)) errorType = 0;
            	HX_STACKFRAME(&_hx_pos_eb2c421d22fabf2c_962_new)
HXDLIN( 962)		super::__construct(errors,putils,errorType);
            	}

Dynamic JsonParser_40_obj::__CreateEmpty() { return new JsonParser_40_obj; }

void *JsonParser_40_obj::_hx_vtable = 0;

Dynamic JsonParser_40_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< JsonParser_40_obj > _hx_result = new JsonParser_40_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return _hx_result;
}

bool JsonParser_40_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x0f6d5b90) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x0f6d5b90;
	} else {
		return inClassId==(int)0x686c4a10;
	}
}

void JsonParser_40_obj::onIncorrectType( ::Dynamic pos,::String variable){
            	HX_STACKFRAME(&_hx_pos_eb2c421d22fabf2c_966_onIncorrectType)
HXLINE( 967)		this->errors->push(::json2object::Error_obj::IncorrectType(variable,HX_("{ y : Float, x : Float, size : Float, assetID : Int, animations : Array<AnimationInfo> }",0a,33,d1,71),pos));
HXLINE( 968)		this->super::onIncorrectType(pos,variable);
            	}


void JsonParser_40_obj::loadJsonNull( ::Dynamic pos,::String variable){
            	HX_STACKFRAME(&_hx_pos_eb2c421d22fabf2c_483_loadJsonNull)
HXDLIN( 483)		this->value = null();
            	}


void JsonParser_40_obj::loadJsonObject(::Array< ::Dynamic> o, ::Dynamic pos,::String variable){
            	HX_GC_STACKFRAME(&_hx_pos_eb2c421d22fabf2c_470_loadJsonObject)
HXLINE( 471)		 ::haxe::ds::StringMap assigned =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
HXLINE( 472)		this->objectSetupAssign(assigned,::Array_obj< ::String >::fromData( _hx_array_data_bd5524b4_6,5),::Array_obj< bool >::fromData( _hx_array_data_bd5524b4_7,5));
HXLINE( 473)		this->value = this->getAuto();
HXLINE( 475)		{
HXLINE( 475)			int _g = 0;
HXDLIN( 475)			while((_g < o->length)){
HXLINE( 475)				 ::hxjsonast::JObjectField field = o->__get(_g).StaticCast<  ::hxjsonast::JObjectField >();
HXDLIN( 475)				_g = (_g + 1);
HXLINE( 438)				::String _hx_switch_0 = field->name;
            				if (  (_hx_switch_0==HX_("animations",ef,34,1c,83)) ){
HXLINE( 366)					 ::Dynamic v = this->loadObjectField( ::JsonParser_42_obj::__alloc( HX_CTX ,this->errors,this->putils,1)->loadJson_dyn(),field,HX_("animations",ef,34,1c,83),assigned, ::Dynamic(this->value->__Field(HX_("animations",ef,34,1c,83),::hx::paccDynamic)),pos);
HXLINE( 367)					if (::hx::IsNotNull( v )) {
HXLINE( 368)						this->value->__SetField(HX_("animations",ef,34,1c,83),( (::Array< ::Dynamic>)(v) ),::hx::paccDynamic);
            					}
            					else {
HXLINE( 370)						this->value->__SetField(HX_("animations",ef,34,1c,83),null(),::hx::paccDynamic);
            					}
HXLINE( 365)					goto _hx_goto_4;
            				}
            				if (  (_hx_switch_0==HX_("assetID",cb,05,dc,36)) ){
HXLINE( 375)					this->value->__SetField(HX_("assetID",cb,05,dc,36),( (int)(this->loadObjectField( ::JsonParser_26_obj::__alloc( HX_CTX ,this->errors,this->putils,1)->loadJson_dyn(),field,HX_("assetID",cb,05,dc,36),assigned, ::Dynamic(this->value->__Field(HX_("assetID",cb,05,dc,36),::hx::paccDynamic)),pos)) ),::hx::paccDynamic);
HXDLIN( 375)					goto _hx_goto_4;
            				}
            				if (  (_hx_switch_0==HX_("size",c1,a0,53,4c)) ){
HXLINE( 375)					this->value->__SetField(HX_("size",c1,a0,53,4c),( (Float)(this->loadObjectField( ::JsonParser_41_obj::__alloc( HX_CTX ,this->errors,this->putils,1)->loadJson_dyn(),field,HX_("size",c1,a0,53,4c),assigned, ::Dynamic(this->value->__Field(HX_("size",c1,a0,53,4c),::hx::paccDynamic)),pos)) ),::hx::paccDynamic);
HXDLIN( 375)					goto _hx_goto_4;
            				}
            				if (  (_hx_switch_0==HX_("x",78,00,00,00)) ){
HXLINE( 375)					this->value->__SetField(HX_("x",78,00,00,00),( (Float)(this->loadObjectField( ::JsonParser_41_obj::__alloc( HX_CTX ,this->errors,this->putils,1)->loadJson_dyn(),field,HX_("x",78,00,00,00),assigned, ::Dynamic(this->value->__Field(HX_("x",78,00,00,00),::hx::paccDynamic)),pos)) ),::hx::paccDynamic);
HXDLIN( 375)					goto _hx_goto_4;
            				}
            				if (  (_hx_switch_0==HX_("y",79,00,00,00)) ){
HXLINE( 375)					this->value->__SetField(HX_("y",79,00,00,00),( (Float)(this->loadObjectField( ::JsonParser_41_obj::__alloc( HX_CTX ,this->errors,this->putils,1)->loadJson_dyn(),field,HX_("y",79,00,00,00),assigned, ::Dynamic(this->value->__Field(HX_("y",79,00,00,00),::hx::paccDynamic)),pos)) ),::hx::paccDynamic);
HXDLIN( 375)					goto _hx_goto_4;
            				}
            				/* default */{
HXLINE( 437)					::Array< ::Dynamic> _hx_tmp = this->errors;
HXDLIN( 437)					::String field1 = field->name;
HXDLIN( 437)					_hx_tmp->push(::json2object::Error_obj::UnknownVariable(field1,this->putils->convertPosition(field->namePos)));
            				}
            				_hx_goto_4:;
            			}
            		}
HXLINE( 479)		this->objectErrors(assigned,pos);
            	}


 ::Dynamic JsonParser_40_obj::getAuto(){
            	HX_GC_STACKFRAME(&_hx_pos_eb2c421d22fabf2c_442_getAuto)
HXLINE( 421)		 ::JsonParser_42 _hx_tmp =  ::JsonParser_42_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXDLIN( 421)		::Array< ::Dynamic> _hx_tmp1 = ( (::Array< ::Dynamic>)(_hx_tmp->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null())) );
HXDLIN( 421)		 ::JsonParser_26 _hx_tmp2 =  ::JsonParser_26_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXDLIN( 421)		int _hx_tmp3 = ( (int)(_hx_tmp2->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null())) );
HXDLIN( 421)		 ::JsonParser_41 _hx_tmp4 =  ::JsonParser_41_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXDLIN( 421)		Float _hx_tmp5 = ( (Float)(_hx_tmp4->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null())) );
HXDLIN( 421)		 ::JsonParser_41 _hx_tmp6 =  ::JsonParser_41_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXDLIN( 421)		Float _hx_tmp7 = ( (Float)(_hx_tmp6->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null())) );
HXDLIN( 421)		 ::JsonParser_41 _hx_tmp8 =  ::JsonParser_41_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXLINE( 442)		return  ::Dynamic(::hx::Anon_obj::Create(5)
            			->setFixed(0,HX_("animations",ef,34,1c,83),_hx_tmp1)
            			->setFixed(1,HX_("x",78,00,00,00),_hx_tmp7)
            			->setFixed(2,HX_("y",79,00,00,00),_hx_tmp8->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null()))
            			->setFixed(3,HX_("assetID",cb,05,dc,36),_hx_tmp3)
            			->setFixed(4,HX_("size",c1,a0,53,4c),_hx_tmp5));
            	}


HX_DEFINE_DYNAMIC_FUNC0(JsonParser_40_obj,getAuto,return )


::hx::ObjectPtr< JsonParser_40_obj > JsonParser_40_obj::__new(::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType) {
	::hx::ObjectPtr< JsonParser_40_obj > __this = new JsonParser_40_obj();
	__this->__construct(errors,putils,__o_errorType);
	return __this;
}

::hx::ObjectPtr< JsonParser_40_obj > JsonParser_40_obj::__alloc(::hx::Ctx *_hx_ctx,::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType) {
	JsonParser_40_obj *__this = (JsonParser_40_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(JsonParser_40_obj), true, "JsonParser_40"));
	*(void **)__this = JsonParser_40_obj::_hx_vtable;
	__this->__construct(errors,putils,__o_errorType);
	return __this;
}

JsonParser_40_obj::JsonParser_40_obj()
{
}

::hx::Val JsonParser_40_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
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
static ::hx::StorageInfo *JsonParser_40_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *JsonParser_40_obj_sStaticStorageInfo = 0;
#endif

static ::String JsonParser_40_obj_sMemberFields[] = {
	HX_("onIncorrectType",e0,ff,a7,01),
	HX_("loadJsonNull",15,2d,09,02),
	HX_("loadJsonObject",cd,4c,e5,ec),
	HX_("getAuto",25,8f,f9,12),
	::String(null()) };

::hx::Class JsonParser_40_obj::__mClass;

void JsonParser_40_obj::__register()
{
	JsonParser_40_obj _hx_dummy;
	JsonParser_40_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("JsonParser_40",b4,24,55,bd);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(JsonParser_40_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< JsonParser_40_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = JsonParser_40_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = JsonParser_40_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

