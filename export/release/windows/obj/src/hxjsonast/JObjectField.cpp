#include <hxcpp.h>

#ifndef INCLUDED_hxjsonast_JObjectField
#include <hxjsonast/JObjectField.h>
#endif
#ifndef INCLUDED_hxjsonast_Json
#include <hxjsonast/Json.h>
#endif
#ifndef INCLUDED_hxjsonast_Position
#include <hxjsonast/Position.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_c7b5b1e149dfec1f_86_new,"hxjsonast.JObjectField","new",0x3910daa7,"hxjsonast.JObjectField.new","hxjsonast/Json.hx",86,0xb257ac31)
namespace hxjsonast{

void JObjectField_obj::__construct(::String name, ::hxjsonast::Position namePos, ::hxjsonast::Json value){
            	HX_STACKFRAME(&_hx_pos_c7b5b1e149dfec1f_86_new)
HXLINE(  87)		this->name = name;
HXLINE(  88)		this->namePos = namePos;
HXLINE(  89)		this->value = value;
            	}

Dynamic JObjectField_obj::__CreateEmpty() { return new JObjectField_obj; }

void *JObjectField_obj::_hx_vtable = 0;

Dynamic JObjectField_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< JObjectField_obj > _hx_result = new JObjectField_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return _hx_result;
}

bool JObjectField_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x1d9ae6f7;
}


::hx::ObjectPtr< JObjectField_obj > JObjectField_obj::__new(::String name, ::hxjsonast::Position namePos, ::hxjsonast::Json value) {
	::hx::ObjectPtr< JObjectField_obj > __this = new JObjectField_obj();
	__this->__construct(name,namePos,value);
	return __this;
}

::hx::ObjectPtr< JObjectField_obj > JObjectField_obj::__alloc(::hx::Ctx *_hx_ctx,::String name, ::hxjsonast::Position namePos, ::hxjsonast::Json value) {
	JObjectField_obj *__this = (JObjectField_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(JObjectField_obj), true, "hxjsonast.JObjectField"));
	*(void **)__this = JObjectField_obj::_hx_vtable;
	__this->__construct(name,namePos,value);
	return __this;
}

JObjectField_obj::JObjectField_obj()
{
}

void JObjectField_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(JObjectField);
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(namePos,"namePos");
	HX_MARK_MEMBER_NAME(value,"value");
	HX_MARK_END_CLASS();
}

void JObjectField_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(name,"name");
	HX_VISIT_MEMBER_NAME(namePos,"namePos");
	HX_VISIT_MEMBER_NAME(value,"value");
}

::hx::Val JObjectField_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return ::hx::Val( name ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { return ::hx::Val( value ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"namePos") ) { return ::hx::Val( namePos ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val JObjectField_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { value=inValue.Cast<  ::hxjsonast::Json >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"namePos") ) { namePos=inValue.Cast<  ::hxjsonast::Position >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void JObjectField_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("name",4b,72,ff,48));
	outFields->push(HX_("namePos",09,e4,83,ac));
	outFields->push(HX_("value",71,7f,b8,31));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo JObjectField_obj_sMemberStorageInfo[] = {
	{::hx::fsString,(int)offsetof(JObjectField_obj,name),HX_("name",4b,72,ff,48)},
	{::hx::fsObject /*  ::hxjsonast::Position */ ,(int)offsetof(JObjectField_obj,namePos),HX_("namePos",09,e4,83,ac)},
	{::hx::fsObject /*  ::hxjsonast::Json */ ,(int)offsetof(JObjectField_obj,value),HX_("value",71,7f,b8,31)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *JObjectField_obj_sStaticStorageInfo = 0;
#endif

static ::String JObjectField_obj_sMemberFields[] = {
	HX_("name",4b,72,ff,48),
	HX_("namePos",09,e4,83,ac),
	HX_("value",71,7f,b8,31),
	::String(null()) };

::hx::Class JObjectField_obj::__mClass;

void JObjectField_obj::__register()
{
	JObjectField_obj _hx_dummy;
	JObjectField_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("hxjsonast.JObjectField",35,fb,7e,6b);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(JObjectField_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< JObjectField_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = JObjectField_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = JObjectField_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace hxjsonast
