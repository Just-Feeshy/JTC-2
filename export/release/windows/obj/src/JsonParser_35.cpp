#include <hxcpp.h>

#ifndef INCLUDED_JsonParser_16
#include <JsonParser_16.h>
#endif
#ifndef INCLUDED_JsonParser_26
#include <JsonParser_26.h>
#endif
#ifndef INCLUDED_JsonParser_3
#include <JsonParser_3.h>
#endif
#ifndef INCLUDED_JsonParser_31
#include <JsonParser_31.h>
#endif
#ifndef INCLUDED_JsonParser_35
#include <JsonParser_35.h>
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

HX_DEFINE_STACK_FRAME(_hx_pos_44e202270e837bd2_962_new,"JsonParser_35","new",0x3638b9cc,"JsonParser_35.new","json2object/reader/DataBuilder.hx",962,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_44e202270e837bd2_966_onIncorrectType,"JsonParser_35","onIncorrectType",0x1cfb5b4c,"JsonParser_35.onIncorrectType","json2object/reader/DataBuilder.hx",966,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_44e202270e837bd2_483_loadJsonNull,"JsonParser_35","loadJsonNull",0xd629b629,"JsonParser_35.loadJsonNull","json2object/reader/DataBuilder.hx",483,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_44e202270e837bd2_470_loadJsonObject,"JsonParser_35","loadJsonObject",0x710942e1,"JsonParser_35.loadJsonObject","json2object/reader/DataBuilder.hx",470,0x0533cd73)
static const ::String _hx_array_data_bd5523da_6[] = {
	HX_("framerate",8d,e5,4b,4e),HX_("looped",c3,5f,b9,61),HX_("name",4b,72,ff,48),HX_("offset",93,97,3f,60),HX_("prefix",92,d9,b6,ae),
};
static const bool _hx_array_data_bd5523da_7[] = {
	0,0,0,0,0,
};
HX_LOCAL_STACK_FRAME(_hx_pos_44e202270e837bd2_442_getAuto,"JsonParser_35","getAuto",0x974d9e91,"JsonParser_35.getAuto","json2object/reader/DataBuilder.hx",442,0x0533cd73)

void JsonParser_35_obj::__construct(::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType){
            		 ::Dynamic errorType = __o_errorType;
            		if (::hx::IsNull(__o_errorType)) errorType = 0;
            	HX_STACKFRAME(&_hx_pos_44e202270e837bd2_962_new)
HXDLIN( 962)		super::__construct(errors,putils,errorType);
            	}

Dynamic JsonParser_35_obj::__CreateEmpty() { return new JsonParser_35_obj; }

void *JsonParser_35_obj::_hx_vtable = 0;

Dynamic JsonParser_35_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< JsonParser_35_obj > _hx_result = new JsonParser_35_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return _hx_result;
}

bool JsonParser_35_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x0f6d5b90) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x0f6d5b90;
	} else {
		return inClassId==(int)0x686c4936;
	}
}

void JsonParser_35_obj::onIncorrectType( ::Dynamic pos,::String variable){
            	HX_STACKFRAME(&_hx_pos_44e202270e837bd2_966_onIncorrectType)
HXLINE( 967)		this->errors->push(::json2object::Error_obj::IncorrectType(variable,HX_("{ prefix : String, offset : Array<Int>, name : String, looped : Bool, framerate : Int }",8d,35,ee,bd),pos));
HXLINE( 968)		this->super::onIncorrectType(pos,variable);
            	}


void JsonParser_35_obj::loadJsonNull( ::Dynamic pos,::String variable){
            	HX_STACKFRAME(&_hx_pos_44e202270e837bd2_483_loadJsonNull)
HXDLIN( 483)		this->value = null();
            	}


void JsonParser_35_obj::loadJsonObject(::Array< ::Dynamic> o, ::Dynamic pos,::String variable){
            	HX_GC_STACKFRAME(&_hx_pos_44e202270e837bd2_470_loadJsonObject)
HXLINE( 471)		 ::haxe::ds::StringMap assigned =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
HXLINE( 472)		this->objectSetupAssign(assigned,::Array_obj< ::String >::fromData( _hx_array_data_bd5523da_6,5),::Array_obj< bool >::fromData( _hx_array_data_bd5523da_7,5));
HXLINE( 473)		this->value = this->getAuto();
HXLINE( 475)		{
HXLINE( 475)			int _g = 0;
HXDLIN( 475)			while((_g < o->length)){
HXLINE( 475)				 ::hxjsonast::JObjectField field = o->__get(_g).StaticCast<  ::hxjsonast::JObjectField >();
HXDLIN( 475)				_g = (_g + 1);
HXLINE( 438)				::String _hx_switch_0 = field->name;
            				if (  (_hx_switch_0==HX_("framerate",8d,e5,4b,4e)) ){
HXLINE( 375)					this->value->__SetField(HX_("framerate",8d,e5,4b,4e),( (int)(this->loadObjectField( ::JsonParser_26_obj::__alloc( HX_CTX ,this->errors,this->putils,1)->loadJson_dyn(),field,HX_("framerate",8d,e5,4b,4e),assigned, ::Dynamic(this->value->__Field(HX_("framerate",8d,e5,4b,4e),::hx::paccDynamic)),pos)) ),::hx::paccDynamic);
HXDLIN( 375)					goto _hx_goto_4;
            				}
            				if (  (_hx_switch_0==HX_("looped",c3,5f,b9,61)) ){
HXLINE( 375)					this->value->__SetField(HX_("looped",c3,5f,b9,61),( (bool)(this->loadObjectField( ::JsonParser_16_obj::__alloc( HX_CTX ,this->errors,this->putils,1)->loadJson_dyn(),field,HX_("looped",c3,5f,b9,61),assigned, ::Dynamic(this->value->__Field(HX_("looped",c3,5f,b9,61),::hx::paccDynamic)),pos)) ),::hx::paccDynamic);
HXDLIN( 375)					goto _hx_goto_4;
            				}
            				if (  (_hx_switch_0==HX_("name",4b,72,ff,48)) ){
HXLINE( 366)					 ::Dynamic v = this->loadObjectField( ::JsonParser_3_obj::__alloc( HX_CTX ,this->errors,this->putils,1)->loadJson_dyn(),field,HX_("name",4b,72,ff,48),assigned, ::Dynamic(this->value->__Field(HX_("name",4b,72,ff,48),::hx::paccDynamic)),pos);
HXLINE( 367)					if (::hx::IsNotNull( v )) {
HXLINE( 368)						this->value->__SetField(HX_("name",4b,72,ff,48),( (::String)(v) ),::hx::paccDynamic);
            					}
            					else {
HXLINE( 370)						this->value->__SetField(HX_("name",4b,72,ff,48),null(),::hx::paccDynamic);
            					}
HXLINE( 365)					goto _hx_goto_4;
            				}
            				if (  (_hx_switch_0==HX_("offset",93,97,3f,60)) ){
HXLINE( 366)					 ::Dynamic v = this->loadObjectField( ::JsonParser_31_obj::__alloc( HX_CTX ,this->errors,this->putils,1)->loadJson_dyn(),field,HX_("offset",93,97,3f,60),assigned, ::Dynamic(this->value->__Field(HX_("offset",93,97,3f,60),::hx::paccDynamic)),pos);
HXLINE( 367)					if (::hx::IsNotNull( v )) {
HXLINE( 368)						this->value->__SetField(HX_("offset",93,97,3f,60),( (::Array< int >)(v) ),::hx::paccDynamic);
            					}
            					else {
HXLINE( 370)						this->value->__SetField(HX_("offset",93,97,3f,60),null(),::hx::paccDynamic);
            					}
HXLINE( 365)					goto _hx_goto_4;
            				}
            				if (  (_hx_switch_0==HX_("prefix",92,d9,b6,ae)) ){
HXLINE( 366)					 ::Dynamic v = this->loadObjectField( ::JsonParser_3_obj::__alloc( HX_CTX ,this->errors,this->putils,1)->loadJson_dyn(),field,HX_("prefix",92,d9,b6,ae),assigned, ::Dynamic(this->value->__Field(HX_("prefix",92,d9,b6,ae),::hx::paccDynamic)),pos);
HXLINE( 367)					if (::hx::IsNotNull( v )) {
HXLINE( 368)						this->value->__SetField(HX_("prefix",92,d9,b6,ae),( (::String)(v) ),::hx::paccDynamic);
            					}
            					else {
HXLINE( 370)						this->value->__SetField(HX_("prefix",92,d9,b6,ae),null(),::hx::paccDynamic);
            					}
HXLINE( 365)					goto _hx_goto_4;
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


 ::Dynamic JsonParser_35_obj::getAuto(){
            	HX_GC_STACKFRAME(&_hx_pos_44e202270e837bd2_442_getAuto)
HXLINE( 421)		 ::JsonParser_26 _hx_tmp =  ::JsonParser_26_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXDLIN( 421)		int _hx_tmp1 = ( (int)(_hx_tmp->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null())) );
HXDLIN( 421)		 ::JsonParser_16 _hx_tmp2 =  ::JsonParser_16_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXDLIN( 421)		bool _hx_tmp3 = ( (bool)(_hx_tmp2->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null())) );
HXDLIN( 421)		 ::JsonParser_3 _hx_tmp4 =  ::JsonParser_3_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXDLIN( 421)		::String _hx_tmp5 = ( (::String)(_hx_tmp4->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null())) );
HXDLIN( 421)		 ::JsonParser_31 _hx_tmp6 =  ::JsonParser_31_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXDLIN( 421)		::Array< int > _hx_tmp7 = ( (::Array< int >)(_hx_tmp6->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null())) );
HXDLIN( 421)		 ::JsonParser_3 _hx_tmp8 =  ::JsonParser_3_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXLINE( 442)		return  ::Dynamic(::hx::Anon_obj::Create(5)
            			->setFixed(0,HX_("prefix",92,d9,b6,ae),_hx_tmp8->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null()))
            			->setFixed(1,HX_("name",4b,72,ff,48),_hx_tmp5)
            			->setFixed(2,HX_("framerate",8d,e5,4b,4e),_hx_tmp1)
            			->setFixed(3,HX_("offset",93,97,3f,60),_hx_tmp7)
            			->setFixed(4,HX_("looped",c3,5f,b9,61),_hx_tmp3));
            	}


HX_DEFINE_DYNAMIC_FUNC0(JsonParser_35_obj,getAuto,return )


::hx::ObjectPtr< JsonParser_35_obj > JsonParser_35_obj::__new(::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType) {
	::hx::ObjectPtr< JsonParser_35_obj > __this = new JsonParser_35_obj();
	__this->__construct(errors,putils,__o_errorType);
	return __this;
}

::hx::ObjectPtr< JsonParser_35_obj > JsonParser_35_obj::__alloc(::hx::Ctx *_hx_ctx,::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType) {
	JsonParser_35_obj *__this = (JsonParser_35_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(JsonParser_35_obj), true, "JsonParser_35"));
	*(void **)__this = JsonParser_35_obj::_hx_vtable;
	__this->__construct(errors,putils,__o_errorType);
	return __this;
}

JsonParser_35_obj::JsonParser_35_obj()
{
}

::hx::Val JsonParser_35_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
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
static ::hx::StorageInfo *JsonParser_35_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *JsonParser_35_obj_sStaticStorageInfo = 0;
#endif

static ::String JsonParser_35_obj_sMemberFields[] = {
	HX_("onIncorrectType",e0,ff,a7,01),
	HX_("loadJsonNull",15,2d,09,02),
	HX_("loadJsonObject",cd,4c,e5,ec),
	HX_("getAuto",25,8f,f9,12),
	::String(null()) };

::hx::Class JsonParser_35_obj::__mClass;

void JsonParser_35_obj::__register()
{
	JsonParser_35_obj _hx_dummy;
	JsonParser_35_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("JsonParser_35",da,23,55,bd);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(JsonParser_35_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< JsonParser_35_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = JsonParser_35_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = JsonParser_35_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

