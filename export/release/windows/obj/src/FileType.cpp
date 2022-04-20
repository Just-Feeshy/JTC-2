#include <hxcpp.h>

#ifndef INCLUDED_FileType
#include <FileType.h>
#endif

::FileType FileType_obj::CHARACTER;

::FileType FileType_obj::COLOR_MAPPING;

bool FileType_obj::__GetStatic(const ::String &inName, ::Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	if (inName==HX_("CHARACTER",89,4b,2a,3d)) { outValue = FileType_obj::CHARACTER; return true; }
	if (inName==HX_("COLOR_MAPPING",b2,cc,d0,b3)) { outValue = FileType_obj::COLOR_MAPPING; return true; }
	return super::__GetStatic(inName, outValue, inCallProp);
}

HX_DEFINE_CREATE_ENUM(FileType_obj)

int FileType_obj::__FindIndex(::String inName)
{
	if (inName==HX_("CHARACTER",89,4b,2a,3d)) return 0;
	if (inName==HX_("COLOR_MAPPING",b2,cc,d0,b3)) return 1;
	return super::__FindIndex(inName);
}

int FileType_obj::__FindArgCount(::String inName)
{
	if (inName==HX_("CHARACTER",89,4b,2a,3d)) return 0;
	if (inName==HX_("COLOR_MAPPING",b2,cc,d0,b3)) return 0;
	return super::__FindArgCount(inName);
}

::hx::Val FileType_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	if (inName==HX_("CHARACTER",89,4b,2a,3d)) return CHARACTER;
	if (inName==HX_("COLOR_MAPPING",b2,cc,d0,b3)) return COLOR_MAPPING;
	return super::__Field(inName,inCallProp);
}

static ::String FileType_obj_sStaticFields[] = {
	HX_("CHARACTER",89,4b,2a,3d),
	HX_("COLOR_MAPPING",b2,cc,d0,b3),
	::String(null())
};

::hx::Class FileType_obj::__mClass;

Dynamic __Create_FileType_obj() { return new FileType_obj; }

void FileType_obj::__register()
{

::hx::Static(__mClass) = ::hx::_hx_RegisterClass(HX_("FileType",76,97,fe,3f), ::hx::TCanCast< FileType_obj >,FileType_obj_sStaticFields,0,
	&__Create_FileType_obj, &__Create,
	&super::__SGetClass(), &CreateFileType_obj, 0
#ifdef HXCPP_VISIT_ALLOCS
    , 0
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
	__mClass->mGetStaticField = &FileType_obj::__GetStatic;
}

void FileType_obj::__boot()
{
CHARACTER = ::hx::CreateConstEnum< FileType_obj >(HX_("CHARACTER",89,4b,2a,3d),0);
COLOR_MAPPING = ::hx::CreateConstEnum< FileType_obj >(HX_("COLOR_MAPPING",b2,cc,d0,b3),1);
}


