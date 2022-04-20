#ifndef INCLUDED_FileType
#define INCLUDED_FileType

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(FileType)


class FileType_obj : public ::hx::EnumBase_obj
{
	typedef ::hx::EnumBase_obj super;
		typedef FileType_obj OBJ_;

	public:
		FileType_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		static bool __GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		::String GetEnumName( ) const { return HX_("FileType",76,97,fe,3f); }
		::String __ToString() const { return HX_("FileType.",f8,ef,c5,be) + _hx_tag; }

		static ::FileType CHARACTER;
		static inline ::FileType CHARACTER_dyn() { return CHARACTER; }
		static ::FileType COLOR_MAPPING;
		static inline ::FileType COLOR_MAPPING_dyn() { return COLOR_MAPPING; }
};


#endif /* INCLUDED_FileType */ 
