#include <hxcpp.h>

#ifndef INCLUDED_polymod_Polymod
#include <polymod/Polymod.h>
#endif
#ifndef INCLUDED_polymod_backends_IBackend
#include <polymod/backends/IBackend.h>
#endif
#ifndef INCLUDED_polymod_backends_KhaBackend
#include <polymod/backends/KhaBackend.h>
#endif
#ifndef INCLUDED_polymod_backends_StubBackend
#include <polymod/backends/StubBackend.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_28feed735110b4ea_7_new,"polymod.backends.KhaBackend","new",0x459d5a99,"polymod.backends.KhaBackend.new","polymod/backends/KhaBackend.hx",7,0x4eaad717)
namespace polymod{
namespace backends{

void KhaBackend_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_28feed735110b4ea_7_new)
HXLINE(   8)		super::__construct();
HXLINE(   9)		::polymod::Polymod_obj::error(HX_("functionality_not_implemented",e2,d8,5e,2f),HX_("KhaBackend requires the kha library, did you forget to install it?",b9,85,7c,24),null());
            	}

Dynamic KhaBackend_obj::__CreateEmpty() { return new KhaBackend_obj; }

void *KhaBackend_obj::_hx_vtable = 0;

Dynamic KhaBackend_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< KhaBackend_obj > _hx_result = new KhaBackend_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool KhaBackend_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x10401405) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x10401405;
	} else {
		return inClassId==(int)0x66589f31;
	}
}


::hx::ObjectPtr< KhaBackend_obj > KhaBackend_obj::__new() {
	::hx::ObjectPtr< KhaBackend_obj > __this = new KhaBackend_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< KhaBackend_obj > KhaBackend_obj::__alloc(::hx::Ctx *_hx_ctx) {
	KhaBackend_obj *__this = (KhaBackend_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(KhaBackend_obj), true, "polymod.backends.KhaBackend"));
	*(void **)__this = KhaBackend_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

KhaBackend_obj::KhaBackend_obj()
{
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *KhaBackend_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *KhaBackend_obj_sStaticStorageInfo = 0;
#endif

::hx::Class KhaBackend_obj::__mClass;

void KhaBackend_obj::__register()
{
	KhaBackend_obj _hx_dummy;
	KhaBackend_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("polymod.backends.KhaBackend",27,1a,2c,41);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< KhaBackend_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = KhaBackend_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = KhaBackend_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace polymod
} // end namespace backends
