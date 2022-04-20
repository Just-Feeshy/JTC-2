#include <hxcpp.h>

#ifndef INCLUDED_ModInitialize
#include <ModInitialize.h>
#endif



::hx::Class ModInitialize_obj::__mClass;

void ModInitialize_obj::__register()
{
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("ModInitialize",92,62,34,b7);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TIsInterface< (int)0xb7346292 >;
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

