#include <hxcpp.h>

#ifndef INCLUDED_hxjsonast_Json
#include <hxjsonast/Json.h>
#endif
#ifndef INCLUDED_hxjsonast_JsonValue
#include <hxjsonast/JsonValue.h>
#endif
#ifndef INCLUDED_hxjsonast_Position
#include <hxjsonast/Position.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_98b94370c3ba5bc7_18_new,"hxjsonast.Json","new",0x8772131e,"hxjsonast.Json.new","hxjsonast/Json.hx",18,0xb257ac31)
namespace hxjsonast{

void Json_obj::__construct( ::hxjsonast::JsonValue value, ::hxjsonast::Position pos){
            	HX_STACKFRAME(&_hx_pos_98b94370c3ba5bc7_18_new)
HXLINE(  19)		this->value = value;
HXLINE(  20)		this->pos = pos;
            	}

Dynamic Json_obj::__CreateEmpty() { return new Json_obj; }

void *Json_obj::_hx_vtable = 0;

Dynamic Json_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Json_obj > _hx_result = new Json_obj();
	_hx_result->__construct(inArgs[0],inArgs[1]);
	return _hx_result;
}

bool Json_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x1ae1950a;
}


::hx::ObjectPtr< Json_obj > Json_obj::__new( ::hxjsonast::JsonValue value, ::hxjsonast::Position pos) {
	::hx::ObjectPtr< Json_obj > __this = new Json_obj();
	__this->__construct(value,pos);
	return __this;
}

::hx::ObjectPtr< Json_obj > Json_obj::__alloc(::hx::Ctx *_hx_ctx, ::hxjsonast::JsonValue value, ::hxjsonast::Position pos) {
	Json_obj *__this = (Json_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Json_obj), true, "hxjsonast.Json"));
	*(void **)__this = Json_obj::_hx_vtable;
	__this->__construct(value,pos);
	return __this;
}

Json_obj::Json_obj()
{
}

void Json_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Json);
	HX_MARK_MEMBER_NAME(value,"value");
	HX_MARK_MEMBER_NAME(pos,"pos");
	HX_MARK_END_CLASS();
}

void Json_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(value,"value");
	HX_VISIT_MEMBER_NAME(pos,"pos");
}

::hx::Val Json_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"pos") ) { return ::hx::Val( pos ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { return ::hx::Val( value ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val Json_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"pos") ) { pos=inValue.Cast<  ::hxjsonast::Position >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { value=inValue.Cast<  ::hxjsonast::JsonValue >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Json_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("value",71,7f,b8,31));
	outFields->push(HX_("pos",94,5d,55,00));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Json_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::hxjsonast::JsonValue */ ,(int)offsetof(Json_obj,value),HX_("value",71,7f,b8,31)},
	{::hx::fsObject /*  ::hxjsonast::Position */ ,(int)offsetof(Json_obj,pos),HX_("pos",94,5d,55,00)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *Json_obj_sStaticStorageInfo = 0;
#endif

static ::String Json_obj_sMemberFields[] = {
	HX_("value",71,7f,b8,31),
	HX_("pos",94,5d,55,00),
	::String(null()) };

::hx::Class Json_obj::__mClass;

void Json_obj::__register()
{
	Json_obj _hx_dummy;
	Json_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("hxjsonast.Json",2c,ec,2e,53);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Json_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Json_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Json_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Json_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace hxjsonast
