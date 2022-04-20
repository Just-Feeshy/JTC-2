#ifndef INCLUDED_polymod_hscript_Param
#define INCLUDED_polymod_hscript_Param

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(polymod,hscript,Param)
namespace polymod{
namespace hscript{


class Param_obj : public ::hx::EnumBase_obj
{
	typedef ::hx::EnumBase_obj super;
		typedef Param_obj OBJ_;

	public:
		Param_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		static bool __GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		::String GetEnumName( ) const { return HX_("polymod.hscript.Param",ba,bb,9d,ae); }
		::String __ToString() const { return HX_("Param.",21,6f,0f,22) + _hx_tag; }

		static ::polymod::hscript::Param Unused;
		static inline ::polymod::hscript::Param Unused_dyn() { return Unused; }
};

} // end namespace polymod
} // end namespace hscript

#endif /* INCLUDED_polymod_hscript_Param */ 
