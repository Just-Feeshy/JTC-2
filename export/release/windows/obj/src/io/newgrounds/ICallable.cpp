#include <hxcpp.h>

#ifndef INCLUDED_io_newgrounds_ICallable
#include <io/newgrounds/ICallable.h>
#endif

namespace io{
namespace newgrounds{


static ::String ICallable_obj_sMemberFields[] = {
	HX_("component",bd,f0,53,0f),
	HX_("send",48,8d,50,4c),
	HX_("queue",91,8d,ea,5d),
	HX_("destroy",fa,2c,86,24),
	::String(null()) };

::hx::Class ICallable_obj::__mClass;

void ICallable_obj::__register()
{
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("io.newgrounds.ICallable",e7,44,fb,36);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(ICallable_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TIsInterface< (int)0xda87fdcf >;
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace io
} // end namespace newgrounds
