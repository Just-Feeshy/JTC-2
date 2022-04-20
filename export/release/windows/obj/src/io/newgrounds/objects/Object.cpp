#include <hxcpp.h>

#ifndef INCLUDED_io_newgrounds_NGLite
#include <io/newgrounds/NGLite.h>
#endif
#ifndef INCLUDED_io_newgrounds_objects_Object
#include <io/newgrounds/objects/Object.h>
#endif
#ifndef INCLUDED_io_newgrounds_utils_Dispatcher
#include <io/newgrounds/utils/Dispatcher.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_138ebb87b01b65f0_13_new,"io.newgrounds.objects.Object","new",0xad4eb1a5,"io.newgrounds.objects.Object.new","io/newgrounds/objects/Object.hx",13,0xd3d3bfaa)
HX_LOCAL_STACK_FRAME(_hx_pos_138ebb87b01b65f0_24_parse,"io.newgrounds.objects.Object","parse",0xc7bf0cb8,"io.newgrounds.objects.Object.parse","io/newgrounds/objects/Object.hx",24,0xd3d3bfaa)
HX_LOCAL_STACK_FRAME(_hx_pos_138ebb87b01b65f0_33_destroy,"io.newgrounds.objects.Object","destroy",0xb9ab94bf,"io.newgrounds.objects.Object.destroy","io/newgrounds/objects/Object.hx",33,0xd3d3bfaa)
namespace io{
namespace newgrounds{
namespace objects{

void Object_obj::__construct( ::io::newgrounds::NGLite core, ::Dynamic data){
            	HX_GC_STACKFRAME(&_hx_pos_138ebb87b01b65f0_13_new)
HXLINE(  15)		this->_core = core;
HXLINE(  17)		this->onUpdate =  ::io::newgrounds::utils::Dispatcher_obj::__alloc( HX_CTX );
HXLINE(  19)		if (::hx::IsNotNull( data )) {
HXLINE(  20)			this->parse(data);
            		}
            	}

Dynamic Object_obj::__CreateEmpty() { return new Object_obj; }

void *Object_obj::_hx_vtable = 0;

Dynamic Object_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Object_obj > _hx_result = new Object_obj();
	_hx_result->__construct(inArgs[0],inArgs[1]);
	return _hx_result;
}

bool Object_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x596f3161;
}

void Object_obj::parse( ::Dynamic data){
            	HX_STACKFRAME(&_hx_pos_138ebb87b01b65f0_24_parse)
HXLINE(  26)		this->_data = data;
HXLINE(  27)		this->onUpdate->dispatch();
            	}


HX_DEFINE_DYNAMIC_FUNC1(Object_obj,parse,(void))

void Object_obj::destroy(){
            	HX_STACKFRAME(&_hx_pos_138ebb87b01b65f0_33_destroy)
HXDLIN(  33)		this->_core = null();
            	}


HX_DEFINE_DYNAMIC_FUNC0(Object_obj,destroy,(void))


::hx::ObjectPtr< Object_obj > Object_obj::__new( ::io::newgrounds::NGLite core, ::Dynamic data) {
	::hx::ObjectPtr< Object_obj > __this = new Object_obj();
	__this->__construct(core,data);
	return __this;
}

::hx::ObjectPtr< Object_obj > Object_obj::__alloc(::hx::Ctx *_hx_ctx, ::io::newgrounds::NGLite core, ::Dynamic data) {
	Object_obj *__this = (Object_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Object_obj), true, "io.newgrounds.objects.Object"));
	*(void **)__this = Object_obj::_hx_vtable;
	__this->__construct(core,data);
	return __this;
}

Object_obj::Object_obj()
{
}

void Object_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Object);
	HX_MARK_MEMBER_NAME(_core,"_core");
	HX_MARK_MEMBER_NAME(_data,"_data");
	HX_MARK_MEMBER_NAME(onUpdate,"onUpdate");
	HX_MARK_END_CLASS();
}

void Object_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_core,"_core");
	HX_VISIT_MEMBER_NAME(_data,"_data");
	HX_VISIT_MEMBER_NAME(onUpdate,"onUpdate");
}

::hx::Val Object_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_core") ) { return ::hx::Val( _core ); }
		if (HX_FIELD_EQ(inName,"_data") ) { return ::hx::Val( _data ); }
		if (HX_FIELD_EQ(inName,"parse") ) { return ::hx::Val( parse_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return ::hx::Val( destroy_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"onUpdate") ) { return ::hx::Val( onUpdate ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val Object_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_core") ) { _core=inValue.Cast<  ::io::newgrounds::NGLite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_data") ) { _data=inValue.Cast<  ::Dynamic >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"onUpdate") ) { onUpdate=inValue.Cast<  ::io::newgrounds::utils::Dispatcher >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Object_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("_core",3e,d9,d5,f4));
	outFields->push(HX_("_data",09,72,74,f5));
	outFields->push(HX_("onUpdate",88,7c,b2,66));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Object_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::io::newgrounds::NGLite */ ,(int)offsetof(Object_obj,_core),HX_("_core",3e,d9,d5,f4)},
	{::hx::fsObject /*  ::Dynamic */ ,(int)offsetof(Object_obj,_data),HX_("_data",09,72,74,f5)},
	{::hx::fsObject /*  ::io::newgrounds::utils::Dispatcher */ ,(int)offsetof(Object_obj,onUpdate),HX_("onUpdate",88,7c,b2,66)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *Object_obj_sStaticStorageInfo = 0;
#endif

static ::String Object_obj_sMemberFields[] = {
	HX_("_core",3e,d9,d5,f4),
	HX_("_data",09,72,74,f5),
	HX_("onUpdate",88,7c,b2,66),
	HX_("parse",33,90,55,bd),
	HX_("destroy",fa,2c,86,24),
	::String(null()) };

::hx::Class Object_obj::__mClass;

void Object_obj::__register()
{
	Object_obj _hx_dummy;
	Object_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("io.newgrounds.objects.Object",33,fb,09,e5);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Object_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Object_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Object_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Object_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace io
} // end namespace newgrounds
} // end namespace objects
