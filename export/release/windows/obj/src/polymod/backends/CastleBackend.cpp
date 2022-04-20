#include <hxcpp.h>

#ifndef INCLUDED_polymod_Polymod
#include <polymod/Polymod.h>
#endif
#ifndef INCLUDED_polymod_backends_CastleBackend
#include <polymod/backends/CastleBackend.h>
#endif
#ifndef INCLUDED_polymod_backends_IBackend
#include <polymod/backends/IBackend.h>
#endif
#ifndef INCLUDED_polymod_backends_StubBackend
#include <polymod/backends/StubBackend.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_699b620ae42a9617_6_new,"polymod.backends.CastleBackend","new",0xbc3a59f7,"polymod.backends.CastleBackend.new","polymod/backends/CastleBackend.hx",6,0xb7318939)
namespace polymod{
namespace backends{

void CastleBackend_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_699b620ae42a9617_6_new)
HXLINE(   7)		super::__construct();
HXLINE(   8)		::polymod::Polymod_obj::error(HX_("functionality_not_implemented",e2,d8,5e,2f),HX_("CastleDB support in Polymod has not been implemented yet",53,79,f7,31),null());
            	}

Dynamic CastleBackend_obj::__CreateEmpty() { return new CastleBackend_obj; }

void *CastleBackend_obj::_hx_vtable = 0;

Dynamic CastleBackend_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< CastleBackend_obj > _hx_result = new CastleBackend_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool CastleBackend_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x66589f31) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x66589f31;
	} else {
		return inClassId==(int)0x672d9767;
	}
}


::hx::ObjectPtr< CastleBackend_obj > CastleBackend_obj::__new() {
	::hx::ObjectPtr< CastleBackend_obj > __this = new CastleBackend_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< CastleBackend_obj > CastleBackend_obj::__alloc(::hx::Ctx *_hx_ctx) {
	CastleBackend_obj *__this = (CastleBackend_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(CastleBackend_obj), true, "polymod.backends.CastleBackend"));
	*(void **)__this = CastleBackend_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

CastleBackend_obj::CastleBackend_obj()
{
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *CastleBackend_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *CastleBackend_obj_sStaticStorageInfo = 0;
#endif

::hx::Class CastleBackend_obj::__mClass;

void CastleBackend_obj::__register()
{
	CastleBackend_obj _hx_dummy;
	CastleBackend_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("polymod.backends.CastleBackend",85,92,82,9f);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< CastleBackend_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = CastleBackend_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = CastleBackend_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace polymod
} // end namespace backends
