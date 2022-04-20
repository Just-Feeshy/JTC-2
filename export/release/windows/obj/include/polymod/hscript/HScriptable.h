#ifndef INCLUDED_polymod_hscript_HScriptable
#define INCLUDED_polymod_hscript_HScriptable

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(polymod,hscript,HScriptable)

namespace polymod{
namespace hscript{


class HXCPP_CLASS_ATTRIBUTES HScriptable_obj {
	public:
		typedef ::hx::Object super;
		HX_DO_INTERFACE_RTTI;

};

} // end namespace polymod
} // end namespace hscript

#endif /* INCLUDED_polymod_hscript_HScriptable */ 
