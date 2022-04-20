#ifndef INCLUDED_ClassType
#define INCLUDED_ClassType

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(ClassType)


class ClassType_obj : public ::hx::EnumBase_obj
{
	typedef ::hx::EnumBase_obj super;
		typedef ClassType_obj OBJ_;

	public:
		ClassType_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		static bool __GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		::String GetEnumName( ) const { return HX_("ClassType",f2,f2,19,82); }
		::String __ToString() const { return HX_("ClassType.",fc,a0,9a,54) + _hx_tag; }

		static ::ClassType EVENT;
		static inline ::ClassType EVENT_dyn() { return EVENT; }
		static ::ClassType STAGE;
		static inline ::ClassType STAGE_dyn() { return STAGE; }
};


#endif /* INCLUDED_ClassType */ 
