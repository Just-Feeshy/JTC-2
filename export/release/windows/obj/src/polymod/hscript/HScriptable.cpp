#include <hxcpp.h>

#ifndef INCLUDED_polymod_hscript_HScriptable
#include <polymod/hscript/HScriptable.h>
#endif

namespace polymod{
namespace hscript{


::hx::Class HScriptable_obj::__mClass;

void HScriptable_obj::__register()
{
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("polymod.hscript.HScriptable",9a,0e,69,78);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TIsInterface< (int)0x4cdec3b0 >;
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace polymod
} // end namespace hscript
