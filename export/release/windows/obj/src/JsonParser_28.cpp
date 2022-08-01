#include <hxcpp.h>

#ifndef INCLUDED_JsonParser_16
#include <JsonParser_16.h>
#endif
#ifndef INCLUDED_JsonParser_28
#include <JsonParser_28.h>
#endif
#ifndef INCLUDED_JsonParser_3
#include <JsonParser_3.h>
#endif
#ifndef INCLUDED_JsonParser_30
#include <JsonParser_30.h>
#endif
#ifndef INCLUDED_JsonParser_31
#include <JsonParser_31.h>
#endif
#ifndef INCLUDED_JsonParser_33
#include <JsonParser_33.h>
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

HX_DEFINE_STACK_FRAME(_hx_pos_a4949f0f39413048_962_new,"JsonParser_28","new",0x8a111af0,"JsonParser_28.new","json2object/reader/DataBuilder.hx",962,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_a4949f0f39413048_966_onIncorrectType,"JsonParser_28","onIncorrectType",0x9372e270,"JsonParser_28.onIncorrectType","json2object/reader/DataBuilder.hx",966,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_a4949f0f39413048_483_loadJsonNull,"JsonParser_28","loadJsonNull",0x89361085,"JsonParser_28.loadJsonNull","json2object/reader/DataBuilder.hx",483,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_a4949f0f39413048_470_loadJsonObject,"JsonParser_28","loadJsonObject",0x43a5ec3d,"JsonParser_28.loadJsonObject","json2object/reader/DataBuilder.hx",470,0x0533cd73)
static const ::String _hx_array_data_bd5522fe_6[] = {
	HX_("animations",ef,34,1c,83),HX_("file",7c,ce,bb,43),HX_("icon",79,e7,b2,45),HX_("isPlayer",eb,86,22,90),HX_("pixel",86,c6,a3,c2),HX_("playAnim",25,ea,84,30),HX_("position",a9,a0,fa,ca),
};
static const bool _hx_array_data_bd5522fe_7[] = {
	0,0,0,0,0,0,0,
};
HX_LOCAL_STACK_FRAME(_hx_pos_a4949f0f39413048_442_getAuto,"JsonParser_28","getAuto",0x4fd761b5,"JsonParser_28.getAuto","json2object/reader/DataBuilder.hx",442,0x0533cd73)

void JsonParser_28_obj::__construct(::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType){
            		 ::Dynamic errorType = __o_errorType;
            		if (::hx::IsNull(__o_errorType)) errorType = 0;
            	HX_STACKFRAME(&_hx_pos_a4949f0f39413048_962_new)
HXDLIN( 962)		super::__construct(errors,putils,errorType);
            	}

Dynamic JsonParser_28_obj::__CreateEmpty() { return new JsonParser_28_obj; }

void *JsonParser_28_obj::_hx_vtable = 0;

Dynamic JsonParser_28_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< JsonParser_28_obj > _hx_result = new JsonParser_28_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return _hx_result;
}

bool JsonParser_28_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x0f6d5b90) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x0f6d5b90;
	} else {
		return inClassId==(int)0x686c485a;
	}
}

void JsonParser_28_obj::onIncorrectType( ::Dynamic pos,::String variable){
            	HX_STACKFRAME(&_hx_pos_a4949f0f39413048_966_onIncorrectType)
HXLINE( 967)		this->errors->push(::json2object::Error_obj::IncorrectType(variable,HX_("{ position : Map<String, Int>, playAnim : String, pixel : Bool, isPlayer : Bool, icon : Array<Int>, file : String, animations : Map<String, AnimationInfo> }",d4,44,61,a9),pos));
HXLINE( 968)		this->super::onIncorrectType(pos,variable);
            	}


void JsonParser_28_obj::loadJsonNull( ::Dynamic pos,::String variable){
            	HX_STACKFRAME(&_hx_pos_a4949f0f39413048_483_loadJsonNull)
HXDLIN( 483)		this->value = null();
            	}


void JsonParser_28_obj::loadJsonObject(::Array< ::Dynamic> o, ::Dynamic pos,::String variable){
            	HX_GC_STACKFRAME(&_hx_pos_a4949f0f39413048_470_loadJsonObject)
HXLINE( 471)		 ::haxe::ds::StringMap assigned =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
HXLINE( 472)		this->objectSetupAssign(assigned,::Array_obj< ::String >::fromData( _hx_array_data_bd5522fe_6,7),::Array_obj< bool >::fromData( _hx_array_data_bd5522fe_7,7));
HXLINE( 473)		this->value = this->getAuto();
HXLINE( 475)		{
HXLINE( 475)			int _g = 0;
HXDLIN( 475)			while((_g < o->length)){
HXLINE( 475)				 ::hxjsonast::JObjectField field = o->__get(_g).StaticCast<  ::hxjsonast::JObjectField >();
HXDLIN( 475)				_g = (_g + 1);
HXLINE( 438)				::String _hx_switch_0 = field->name;
            				if (  (_hx_switch_0==HX_("animations",ef,34,1c,83)) ){
HXLINE( 366)					 ::Dynamic v = this->loadObjectField( ::JsonParser_30_obj::__alloc( HX_CTX ,this->errors,this->putils,1)->loadJson_dyn(),field,HX_("animations",ef,34,1c,83),assigned, ::Dynamic(this->value->__Field(HX_("animations",ef,34,1c,83),::hx::paccDynamic)),pos);
HXLINE( 367)					if (::hx::IsNotNull( v )) {
HXLINE( 368)						this->value->__SetField(HX_("animations",ef,34,1c,83),( ( ::haxe::ds::StringMap)(v) ),::hx::paccDynamic);
            					}
            					else {
HXLINE( 370)						this->value->__SetField(HX_("animations",ef,34,1c,83),null(),::hx::paccDynamic);
            					}
HXLINE( 365)					goto _hx_goto_4;
            				}
            				if (  (_hx_switch_0==HX_("file",7c,ce,bb,43)) ){
HXLINE( 366)					 ::Dynamic v = this->loadObjectField( ::JsonParser_3_obj::__alloc( HX_CTX ,this->errors,this->putils,1)->loadJson_dyn(),field,HX_("file",7c,ce,bb,43),assigned, ::Dynamic(this->value->__Field(HX_("file",7c,ce,bb,43),::hx::paccDynamic)),pos);
HXLINE( 367)					if (::hx::IsNotNull( v )) {
HXLINE( 368)						this->value->__SetField(HX_("file",7c,ce,bb,43),( (::String)(v) ),::hx::paccDynamic);
            					}
            					else {
HXLINE( 370)						this->value->__SetField(HX_("file",7c,ce,bb,43),null(),::hx::paccDynamic);
            					}
HXLINE( 365)					goto _hx_goto_4;
            				}
            				if (  (_hx_switch_0==HX_("icon",79,e7,b2,45)) ){
HXLINE( 366)					 ::Dynamic v = this->loadObjectField( ::JsonParser_31_obj::__alloc( HX_CTX ,this->errors,this->putils,1)->loadJson_dyn(),field,HX_("icon",79,e7,b2,45),assigned, ::Dynamic(this->value->__Field(HX_("icon",79,e7,b2,45),::hx::paccDynamic)),pos);
HXLINE( 367)					if (::hx::IsNotNull( v )) {
HXLINE( 368)						this->value->__SetField(HX_("icon",79,e7,b2,45),( (::Array< int >)(v) ),::hx::paccDynamic);
            					}
            					else {
HXLINE( 370)						this->value->__SetField(HX_("icon",79,e7,b2,45),null(),::hx::paccDynamic);
            					}
HXLINE( 365)					goto _hx_goto_4;
            				}
            				if (  (_hx_switch_0==HX_("isPlayer",eb,86,22,90)) ){
HXLINE( 375)					this->value->__SetField(HX_("isPlayer",eb,86,22,90),( (bool)(this->loadObjectField( ::JsonParser_16_obj::__alloc( HX_CTX ,this->errors,this->putils,1)->loadJson_dyn(),field,HX_("isPlayer",eb,86,22,90),assigned, ::Dynamic(this->value->__Field(HX_("isPlayer",eb,86,22,90),::hx::paccDynamic)),pos)) ),::hx::paccDynamic);
HXDLIN( 375)					goto _hx_goto_4;
            				}
            				if (  (_hx_switch_0==HX_("pixel",86,c6,a3,c2)) ){
HXLINE( 375)					this->value->__SetField(HX_("pixel",86,c6,a3,c2),( (bool)(this->loadObjectField( ::JsonParser_16_obj::__alloc( HX_CTX ,this->errors,this->putils,1)->loadJson_dyn(),field,HX_("pixel",86,c6,a3,c2),assigned, ::Dynamic(this->value->__Field(HX_("pixel",86,c6,a3,c2),::hx::paccDynamic)),pos)) ),::hx::paccDynamic);
HXDLIN( 375)					goto _hx_goto_4;
            				}
            				if (  (_hx_switch_0==HX_("playAnim",25,ea,84,30)) ){
HXLINE( 366)					 ::Dynamic v = this->loadObjectField( ::JsonParser_3_obj::__alloc( HX_CTX ,this->errors,this->putils,1)->loadJson_dyn(),field,HX_("playAnim",25,ea,84,30),assigned, ::Dynamic(this->value->__Field(HX_("playAnim",25,ea,84,30),::hx::paccDynamic)),pos);
HXLINE( 367)					if (::hx::IsNotNull( v )) {
HXLINE( 368)						this->value->__SetField(HX_("playAnim",25,ea,84,30),( (::String)(v) ),::hx::paccDynamic);
            					}
            					else {
HXLINE( 370)						this->value->__SetField(HX_("playAnim",25,ea,84,30),null(),::hx::paccDynamic);
            					}
HXLINE( 365)					goto _hx_goto_4;
            				}
            				if (  (_hx_switch_0==HX_("position",a9,a0,fa,ca)) ){
HXLINE( 366)					 ::Dynamic v = this->loadObjectField( ::JsonParser_33_obj::__alloc( HX_CTX ,this->errors,this->putils,1)->loadJson_dyn(),field,HX_("position",a9,a0,fa,ca),assigned, ::Dynamic(this->value->__Field(HX_("position",a9,a0,fa,ca),::hx::paccDynamic)),pos);
HXLINE( 367)					if (::hx::IsNotNull( v )) {
HXLINE( 368)						this->value->__SetField(HX_("position",a9,a0,fa,ca),( ( ::haxe::ds::StringMap)(v) ),::hx::paccDynamic);
            					}
            					else {
HXLINE( 370)						this->value->__SetField(HX_("position",a9,a0,fa,ca),null(),::hx::paccDynamic);
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


 ::Dynamic JsonParser_28_obj::getAuto(){
            	HX_GC_STACKFRAME(&_hx_pos_a4949f0f39413048_442_getAuto)
HXLINE( 421)		 ::JsonParser_30 _hx_tmp =  ::JsonParser_30_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXDLIN( 421)		 ::haxe::ds::StringMap _hx_tmp1 = _hx_tmp->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null()).StaticCast<  ::haxe::ds::StringMap >();
HXDLIN( 421)		 ::JsonParser_3 _hx_tmp2 =  ::JsonParser_3_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXDLIN( 421)		::String _hx_tmp3 = ( (::String)(_hx_tmp2->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null())) );
HXDLIN( 421)		 ::JsonParser_31 _hx_tmp4 =  ::JsonParser_31_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXDLIN( 421)		::Array< int > _hx_tmp5 = ( (::Array< int >)(_hx_tmp4->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null())) );
HXDLIN( 421)		 ::JsonParser_16 _hx_tmp6 =  ::JsonParser_16_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXDLIN( 421)		bool _hx_tmp7 = ( (bool)(_hx_tmp6->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null())) );
HXDLIN( 421)		 ::JsonParser_16 _hx_tmp8 =  ::JsonParser_16_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXDLIN( 421)		bool _hx_tmp9 = ( (bool)(_hx_tmp8->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null())) );
HXDLIN( 421)		 ::JsonParser_3 _hx_tmp10 =  ::JsonParser_3_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXDLIN( 421)		::String _hx_tmp11 = ( (::String)(_hx_tmp10->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null())) );
HXDLIN( 421)		 ::JsonParser_33 _hx_tmp12 =  ::JsonParser_33_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXLINE( 442)		return  ::Dynamic(::hx::Anon_obj::Create(7)
            			->setFixed(0,HX_("animations",ef,34,1c,83),_hx_tmp1)
            			->setFixed(1,HX_("isPlayer",eb,86,22,90),_hx_tmp7)
            			->setFixed(2,HX_("pixel",86,c6,a3,c2),_hx_tmp9)
            			->setFixed(3,HX_("position",a9,a0,fa,ca),_hx_tmp12->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null()).StaticCast<  ::haxe::ds::StringMap >())
            			->setFixed(4,HX_("playAnim",25,ea,84,30),_hx_tmp11)
            			->setFixed(5,HX_("file",7c,ce,bb,43),_hx_tmp3)
            			->setFixed(6,HX_("icon",79,e7,b2,45),_hx_tmp5));
            	}


HX_DEFINE_DYNAMIC_FUNC0(JsonParser_28_obj,getAuto,return )


::hx::ObjectPtr< JsonParser_28_obj > JsonParser_28_obj::__new(::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType) {
	::hx::ObjectPtr< JsonParser_28_obj > __this = new JsonParser_28_obj();
	__this->__construct(errors,putils,__o_errorType);
	return __this;
}

::hx::ObjectPtr< JsonParser_28_obj > JsonParser_28_obj::__alloc(::hx::Ctx *_hx_ctx,::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType) {
	JsonParser_28_obj *__this = (JsonParser_28_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(JsonParser_28_obj), true, "JsonParser_28"));
	*(void **)__this = JsonParser_28_obj::_hx_vtable;
	__this->__construct(errors,putils,__o_errorType);
	return __this;
}

JsonParser_28_obj::JsonParser_28_obj()
{
}

::hx::Val JsonParser_28_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
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
static ::hx::StorageInfo *JsonParser_28_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *JsonParser_28_obj_sStaticStorageInfo = 0;
#endif

static ::String JsonParser_28_obj_sMemberFields[] = {
	HX_("onIncorrectType",e0,ff,a7,01),
	HX_("loadJsonNull",15,2d,09,02),
	HX_("loadJsonObject",cd,4c,e5,ec),
	HX_("getAuto",25,8f,f9,12),
	::String(null()) };

::hx::Class JsonParser_28_obj::__mClass;

void JsonParser_28_obj::__register()
{
	JsonParser_28_obj _hx_dummy;
	JsonParser_28_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("JsonParser_28",fe,22,55,bd);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(JsonParser_28_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< JsonParser_28_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = JsonParser_28_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = JsonParser_28_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

