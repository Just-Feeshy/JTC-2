#ifndef INCLUDED_ShaderType
#define INCLUDED_ShaderType

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(ShaderType)


class ShaderType_obj : public ::hx::EnumBase_obj
{
	typedef ::hx::EnumBase_obj super;
		typedef ShaderType_obj OBJ_;

	public:
		ShaderType_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		static bool __GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		::String GetEnumName( ) const { return HX_("ShaderType",9f,d8,52,32); }
		::String __ToString() const { return HX_("ShaderType.",af,b2,2a,d6) + _hx_tag; }

		static ::ShaderType GAUSSIAN_BLUR;
		static inline ::ShaderType GAUSSIAN_BLUR_dyn() { return GAUSSIAN_BLUR; }
		static ::ShaderType GLIM_SELECTION;
		static inline ::ShaderType GLIM_SELECTION_dyn() { return GLIM_SELECTION; }
		static ::ShaderType MINING_SIM_LOADING;
		static inline ::ShaderType MINING_SIM_LOADING_dyn() { return MINING_SIM_LOADING; }
};


#endif /* INCLUDED_ShaderType */ 
