#include <hxcpp.h>

#ifndef INCLUDED_JsonParser_1
#include <JsonParser_1.h>
#endif
#ifndef INCLUDED_JsonParser_11
#include <JsonParser_11.h>
#endif
#ifndef INCLUDED_JsonParser_2
#include <JsonParser_2.h>
#endif
#ifndef INCLUDED_JsonParser_3
#include <JsonParser_3.h>
#endif
#ifndef INCLUDED_JsonParser_5
#include <JsonParser_5.h>
#endif
#ifndef INCLUDED_JsonParser_7
#include <JsonParser_7.h>
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

HX_DEFINE_STACK_FRAME(_hx_pos_e4a5a0bf8b45eb1d_938_new,"JsonParser_1","new",0x0d41696b,"JsonParser_1.new","json2object/reader/DataBuilder.hx",938,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_e4a5a0bf8b45eb1d_942_onIncorrectType,"JsonParser_1","onIncorrectType",0x485c7d6b,"JsonParser_1.onIncorrectType","json2object/reader/DataBuilder.hx",942,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_e4a5a0bf8b45eb1d_459_loadJsonNull,"JsonParser_1","loadJsonNull",0x34539aaa,"JsonParser_1.loadJsonNull","json2object/reader/DataBuilder.hx",459,0x0533cd73)
HX_LOCAL_STACK_FRAME(_hx_pos_e4a5a0bf8b45eb1d_446_loadJsonObject,"JsonParser_1","loadJsonObject",0x18d609a2,"JsonParser_1.loadJsonObject","json2object/reader/DataBuilder.hx",446,0x0533cd73)
static const ::String _hx_array_data_9987d7f9_6[] = {
	HX_("custom_notes",f3,05,bb,66),HX_("main",39,38,56,48),HX_("main_menu",a5,ba,e0,81),HX_("mod",c2,16,53,00),HX_("title_menu",e6,04,22,7a),HX_("weeks",ff,95,be,c7),
};
static const bool _hx_array_data_9987d7f9_7[] = {
	0,0,0,0,0,0,
};
HX_LOCAL_STACK_FRAME(_hx_pos_e4a5a0bf8b45eb1d_418_getAuto,"JsonParser_1","getAuto",0x3e9009b0,"JsonParser_1.getAuto","json2object/reader/DataBuilder.hx",418,0x0533cd73)

void JsonParser_1_obj::__construct(::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType){
            		 ::Dynamic errorType = __o_errorType;
            		if (::hx::IsNull(__o_errorType)) errorType = 0;
            	HX_STACKFRAME(&_hx_pos_e4a5a0bf8b45eb1d_938_new)
HXDLIN( 938)		super::__construct(errors,putils,errorType);
            	}

Dynamic JsonParser_1_obj::__CreateEmpty() { return new JsonParser_1_obj; }

void *JsonParser_1_obj::_hx_vtable = 0;

Dynamic JsonParser_1_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< JsonParser_1_obj > _hx_result = new JsonParser_1_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return _hx_result;
}

bool JsonParser_1_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x0f6d5b90) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x0f6d5b90;
	} else {
		return inClassId==(int)0x194860e5;
	}
}

void JsonParser_1_obj::onIncorrectType( ::Dynamic pos,::String variable){
            	HX_STACKFRAME(&_hx_pos_e4a5a0bf8b45eb1d_942_onIncorrectType)
HXLINE( 943)		this->errors->push(::json2object::Error_obj::IncorrectType(variable,HX_("{ weeks : Map<String, WeekInfo>, title_menu : Title_Menu, mod : Mod_Info, main_menu : Main_Menu, main : String, custom_notes : Array<String> }",cc,45,f8,5d),pos));
HXLINE( 944)		this->super::onIncorrectType(pos,variable);
            	}


void JsonParser_1_obj::loadJsonNull( ::Dynamic pos,::String variable){
            	HX_STACKFRAME(&_hx_pos_e4a5a0bf8b45eb1d_459_loadJsonNull)
HXDLIN( 459)		this->value = null();
            	}


void JsonParser_1_obj::loadJsonObject(::Array< ::Dynamic> o, ::Dynamic pos,::String variable){
            	HX_GC_STACKFRAME(&_hx_pos_e4a5a0bf8b45eb1d_446_loadJsonObject)
HXLINE( 447)		 ::haxe::ds::StringMap assigned =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
HXLINE( 448)		this->objectSetupAssign(assigned,::Array_obj< ::String >::fromData( _hx_array_data_9987d7f9_6,6),::Array_obj< bool >::fromData( _hx_array_data_9987d7f9_7,6));
HXLINE( 449)		this->value = this->getAuto();
HXLINE( 451)		{
HXLINE( 451)			int _g = 0;
HXDLIN( 451)			while((_g < o->length)){
HXLINE( 451)				 ::hxjsonast::JObjectField field = o->__get(_g).StaticCast<  ::hxjsonast::JObjectField >();
HXDLIN( 451)				_g = (_g + 1);
HXLINE( 414)				::String _hx_switch_0 = field->name;
            				if (  (_hx_switch_0==HX_("custom_notes",f3,05,bb,66)) ){
HXLINE( 342)					 ::Dynamic v = this->loadObjectField( ::JsonParser_2_obj::__alloc( HX_CTX ,this->errors,this->putils,1)->loadJson_dyn(),field,HX_("custom_notes",f3,05,bb,66),assigned, ::Dynamic(this->value->__Field(HX_("custom_notes",f3,05,bb,66),::hx::paccDynamic)),pos);
HXLINE( 343)					if (::hx::IsNotNull( v )) {
HXLINE( 344)						this->value->__SetField(HX_("custom_notes",f3,05,bb,66),( (::Array< ::String >)(v) ),::hx::paccDynamic);
            					}
            					else {
HXLINE( 346)						this->value->__SetField(HX_("custom_notes",f3,05,bb,66),null(),::hx::paccDynamic);
            					}
HXLINE( 341)					goto _hx_goto_4;
            				}
            				if (  (_hx_switch_0==HX_("main",39,38,56,48)) ){
HXLINE( 342)					 ::Dynamic v = this->loadObjectField( ::JsonParser_3_obj::__alloc( HX_CTX ,this->errors,this->putils,1)->loadJson_dyn(),field,HX_("main",39,38,56,48),assigned, ::Dynamic(this->value->__Field(HX_("main",39,38,56,48),::hx::paccDynamic)),pos);
HXLINE( 343)					if (::hx::IsNotNull( v )) {
HXLINE( 344)						this->value->__SetField(HX_("main",39,38,56,48),( (::String)(v) ),::hx::paccDynamic);
            					}
            					else {
HXLINE( 346)						this->value->__SetField(HX_("main",39,38,56,48),null(),::hx::paccDynamic);
            					}
HXLINE( 341)					goto _hx_goto_4;
            				}
            				if (  (_hx_switch_0==HX_("main_menu",a5,ba,e0,81)) ){
HXLINE( 342)					 ::Dynamic v = this->loadObjectField( ::JsonParser_5_obj::__alloc( HX_CTX ,this->errors,this->putils,1)->loadJson_dyn(),field,HX_("main_menu",a5,ba,e0,81),assigned, ::Dynamic(this->value->__Field(HX_("main_menu",a5,ba,e0,81),::hx::paccDynamic)),pos);
HXLINE( 343)					if (::hx::IsNotNull( v )) {
HXLINE( 344)						this->value->__SetField(HX_("main_menu",a5,ba,e0,81),v,::hx::paccDynamic);
            					}
            					else {
HXLINE( 346)						this->value->__SetField(HX_("main_menu",a5,ba,e0,81),null(),::hx::paccDynamic);
            					}
HXLINE( 341)					goto _hx_goto_4;
            				}
            				if (  (_hx_switch_0==HX_("mod",c2,16,53,00)) ){
HXLINE( 342)					 ::Dynamic v = this->loadObjectField( ::JsonParser_7_obj::__alloc( HX_CTX ,this->errors,this->putils,1)->loadJson_dyn(),field,HX_("mod",c2,16,53,00),assigned, ::Dynamic(this->value->__Field(HX_("mod",c2,16,53,00),::hx::paccDynamic)),pos);
HXLINE( 343)					if (::hx::IsNotNull( v )) {
HXLINE( 344)						this->value->__SetField(HX_("mod",c2,16,53,00),v,::hx::paccDynamic);
            					}
            					else {
HXLINE( 346)						this->value->__SetField(HX_("mod",c2,16,53,00),null(),::hx::paccDynamic);
            					}
HXLINE( 341)					goto _hx_goto_4;
            				}
            				if (  (_hx_switch_0==HX_("title_menu",e6,04,22,7a)) ){
HXLINE( 342)					 ::Dynamic v = this->loadObjectField( ::JsonParser_9_obj::__alloc( HX_CTX ,this->errors,this->putils,1)->loadJson_dyn(),field,HX_("title_menu",e6,04,22,7a),assigned, ::Dynamic(this->value->__Field(HX_("title_menu",e6,04,22,7a),::hx::paccDynamic)),pos);
HXLINE( 343)					if (::hx::IsNotNull( v )) {
HXLINE( 344)						this->value->__SetField(HX_("title_menu",e6,04,22,7a),v,::hx::paccDynamic);
            					}
            					else {
HXLINE( 346)						this->value->__SetField(HX_("title_menu",e6,04,22,7a),null(),::hx::paccDynamic);
            					}
HXLINE( 341)					goto _hx_goto_4;
            				}
            				if (  (_hx_switch_0==HX_("weeks",ff,95,be,c7)) ){
HXLINE( 342)					 ::Dynamic v = this->loadObjectField( ::JsonParser_11_obj::__alloc( HX_CTX ,this->errors,this->putils,1)->loadJson_dyn(),field,HX_("weeks",ff,95,be,c7),assigned, ::Dynamic(this->value->__Field(HX_("weeks",ff,95,be,c7),::hx::paccDynamic)),pos);
HXLINE( 343)					if (::hx::IsNotNull( v )) {
HXLINE( 344)						this->value->__SetField(HX_("weeks",ff,95,be,c7),( ( ::haxe::ds::StringMap)(v) ),::hx::paccDynamic);
            					}
            					else {
HXLINE( 346)						this->value->__SetField(HX_("weeks",ff,95,be,c7),null(),::hx::paccDynamic);
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


 ::Dynamic JsonParser_1_obj::getAuto(){
            	HX_GC_STACKFRAME(&_hx_pos_e4a5a0bf8b45eb1d_418_getAuto)
HXLINE( 397)		 ::JsonParser_2 _hx_tmp =  ::JsonParser_2_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXDLIN( 397)		::Array< ::String > _hx_tmp1 = ( (::Array< ::String >)(_hx_tmp->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null())) );
HXDLIN( 397)		 ::JsonParser_3 _hx_tmp2 =  ::JsonParser_3_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXDLIN( 397)		::String _hx_tmp3 = ( (::String)(_hx_tmp2->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null())) );
HXDLIN( 397)		 ::JsonParser_5 _hx_tmp4 =  ::JsonParser_5_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXDLIN( 397)		 ::Dynamic _hx_tmp5 = _hx_tmp4->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null());
HXDLIN( 397)		 ::JsonParser_7 _hx_tmp6 =  ::JsonParser_7_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXDLIN( 397)		 ::Dynamic _hx_tmp7 = _hx_tmp6->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null());
HXDLIN( 397)		 ::JsonParser_9 _hx_tmp8 =  ::JsonParser_9_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXDLIN( 397)		 ::Dynamic _hx_tmp9 = _hx_tmp8->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null());
HXDLIN( 397)		 ::JsonParser_11 _hx_tmp10 =  ::JsonParser_11_obj::__alloc( HX_CTX ,::Array_obj< ::Dynamic>::__new(0),this->putils,0);
HXLINE( 418)		return  ::Dynamic(::hx::Anon_obj::Create(6)
            			->setFixed(0,HX_("main_menu",a5,ba,e0,81),_hx_tmp5)
            			->setFixed(1,HX_("weeks",ff,95,be,c7),_hx_tmp10->loadJson( ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,HX_("",00,00,00,00),0,1)),null()).StaticCast<  ::haxe::ds::StringMap >())
            			->setFixed(2,HX_("mod",c2,16,53,00),_hx_tmp7)
            			->setFixed(3,HX_("main",39,38,56,48),_hx_tmp3)
            			->setFixed(4,HX_("custom_notes",f3,05,bb,66),_hx_tmp1)
            			->setFixed(5,HX_("title_menu",e6,04,22,7a),_hx_tmp9));
            	}


HX_DEFINE_DYNAMIC_FUNC0(JsonParser_1_obj,getAuto,return )


::hx::ObjectPtr< JsonParser_1_obj > JsonParser_1_obj::__new(::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType) {
	::hx::ObjectPtr< JsonParser_1_obj > __this = new JsonParser_1_obj();
	__this->__construct(errors,putils,__o_errorType);
	return __this;
}

::hx::ObjectPtr< JsonParser_1_obj > JsonParser_1_obj::__alloc(::hx::Ctx *_hx_ctx,::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType) {
	JsonParser_1_obj *__this = (JsonParser_1_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(JsonParser_1_obj), true, "JsonParser_1"));
	*(void **)__this = JsonParser_1_obj::_hx_vtable;
	__this->__construct(errors,putils,__o_errorType);
	return __this;
}

JsonParser_1_obj::JsonParser_1_obj()
{
}

::hx::Val JsonParser_1_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
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
static ::hx::StorageInfo *JsonParser_1_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *JsonParser_1_obj_sStaticStorageInfo = 0;
#endif

static ::String JsonParser_1_obj_sMemberFields[] = {
	HX_("onIncorrectType",e0,ff,a7,01),
	HX_("loadJsonNull",15,2d,09,02),
	HX_("loadJsonObject",cd,4c,e5,ec),
	HX_("getAuto",25,8f,f9,12),
	::String(null()) };

::hx::Class JsonParser_1_obj::__mClass;

void JsonParser_1_obj::__register()
{
	JsonParser_1_obj _hx_dummy;
	JsonParser_1_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("JsonParser_1",f9,d7,87,99);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(JsonParser_1_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< JsonParser_1_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = JsonParser_1_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = JsonParser_1_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

