#include <hxcpp.h>

#ifndef INCLUDED_polymod_PolymodConfig
#include <polymod/PolymodConfig.h>
#endif
#ifndef INCLUDED_polymod_util__SemanticVersion_SemanticVersionScore_Impl_
#include <polymod/util/_SemanticVersion/SemanticVersionScore_Impl_.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_cae42745e4bfdcf9_24_get_debug,"polymod.PolymodConfig","get_debug",0x074ffd7c,"polymod.PolymodConfig.get_debug","polymod/PolymodConfig.hx",24,0x8e4837ff)
HX_LOCAL_STACK_FRAME(_hx_pos_cae42745e4bfdcf9_42_get_rootPath,"polymod.PolymodConfig","get_rootPath",0x11eead5e,"polymod.PolymodConfig.get_rootPath","polymod/PolymodConfig.hx",42,0x8e4837ff)
HX_LOCAL_STACK_FRAME(_hx_pos_cae42745e4bfdcf9_62_get_useNamespaceInPaths,"polymod.PolymodConfig","get_useNamespaceInPaths",0xef313efe,"polymod.PolymodConfig.get_useNamespaceInPaths","polymod/PolymodConfig.hx",62,0x8e4837ff)
HX_LOCAL_STACK_FRAME(_hx_pos_cae42745e4bfdcf9_80_get_scriptExt,"polymod.PolymodConfig","get_scriptExt",0x538e82ff,"polymod.PolymodConfig.get_scriptExt","polymod/PolymodConfig.hx",80,0x8e4837ff)
HX_LOCAL_STACK_FRAME(_hx_pos_cae42745e4bfdcf9_98_get_scriptClassExt,"polymod.PolymodConfig","get_scriptClassExt",0xe8b9f42b,"polymod.PolymodConfig.get_scriptClassExt","polymod/PolymodConfig.hx",98,0x8e4837ff)
HX_LOCAL_STACK_FRAME(_hx_pos_cae42745e4bfdcf9_117_get_scriptLibrary,"polymod.PolymodConfig","get_scriptLibrary",0x2f4f2459,"polymod.PolymodConfig.get_scriptLibrary","polymod/PolymodConfig.hx",117,0x8e4837ff)
HX_LOCAL_STACK_FRAME(_hx_pos_cae42745e4bfdcf9_135_get_appendFolder,"polymod.PolymodConfig","get_appendFolder",0xb5fda81f,"polymod.PolymodConfig.get_appendFolder","polymod/PolymodConfig.hx",135,0x8e4837ff)
HX_LOCAL_STACK_FRAME(_hx_pos_cae42745e4bfdcf9_159_get_apiVersionMatch,"polymod.PolymodConfig","get_apiVersionMatch",0x1d4f7b30,"polymod.PolymodConfig.get_apiVersionMatch","polymod/PolymodConfig.hx",159,0x8e4837ff)
HX_LOCAL_STACK_FRAME(_hx_pos_cae42745e4bfdcf9_177_get_mergeFolder,"polymod.PolymodConfig","get_mergeFolder",0x3871576f,"polymod.PolymodConfig.get_mergeFolder","polymod/PolymodConfig.hx",177,0x8e4837ff)
HX_LOCAL_STACK_FRAME(_hx_pos_cae42745e4bfdcf9_196_get_modPackFile,"polymod.PolymodConfig","get_modPackFile",0x99ed06c0,"polymod.PolymodConfig.get_modPackFile","polymod/PolymodConfig.hx",196,0x8e4837ff)
HX_LOCAL_STACK_FRAME(_hx_pos_cae42745e4bfdcf9_214_get_modMetadataFile,"polymod.PolymodConfig","get_modMetadataFile",0xc9a9dbd6,"polymod.PolymodConfig.get_modMetadataFile","polymod/PolymodConfig.hx",214,0x8e4837ff)
HX_LOCAL_STACK_FRAME(_hx_pos_cae42745e4bfdcf9_232_get_modIconFile,"polymod.PolymodConfig","get_modIconFile",0xe332e760,"polymod.PolymodConfig.get_modIconFile","polymod/PolymodConfig.hx",232,0x8e4837ff)
HX_LOCAL_STACK_FRAME(_hx_pos_cae42745e4bfdcf9_251_get_modIgnoreFiles,"polymod.PolymodConfig","get_modIgnoreFiles",0xad36f01a,"polymod.PolymodConfig.get_modIgnoreFiles","polymod/PolymodConfig.hx",251,0x8e4837ff)
static const ::String _hx_array_data_a82454c0_13[] = {
	HX_("LICENSE.txt",e3,aa,9a,6b),HX_("ASSET_LICENSE.txt",b4,72,9f,4f),HX_("CODE_LICENSE.txt",91,61,d1,6f),
};
HX_LOCAL_STACK_FRAME(_hx_pos_cae42745e4bfdcf9_156_boot,"polymod.PolymodConfig","boot",0xd1baa6a0,"polymod.PolymodConfig.boot","polymod/PolymodConfig.hx",156,0x8e4837ff)
namespace polymod{

void PolymodConfig_obj::__construct() { }

Dynamic PolymodConfig_obj::__CreateEmpty() { return new PolymodConfig_obj; }

void *PolymodConfig_obj::_hx_vtable = 0;

Dynamic PolymodConfig_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< PolymodConfig_obj > _hx_result = new PolymodConfig_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool PolymodConfig_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x48534066;
}

 ::Dynamic PolymodConfig_obj::debug;

 ::Dynamic PolymodConfig_obj::get_debug(){
            	HX_STACKFRAME(&_hx_pos_cae42745e4bfdcf9_24_get_debug)
HXLINE(  26)		if (::hx::IsNull( ::polymod::PolymodConfig_obj::debug )) {
HXLINE(  27)			::polymod::PolymodConfig_obj::debug = false;
            		}
HXLINE(  28)		return ::polymod::PolymodConfig_obj::debug;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(PolymodConfig_obj,get_debug,return )

::String PolymodConfig_obj::rootPath;

::String PolymodConfig_obj::get_rootPath(){
            	HX_STACKFRAME(&_hx_pos_cae42745e4bfdcf9_42_get_rootPath)
HXLINE(  44)		if (::hx::IsNull( ::polymod::PolymodConfig_obj::rootPath )) {
HXLINE(  45)			::polymod::PolymodConfig_obj::rootPath = HX_("data/",c5,0e,88,d4);
            		}
HXLINE(  46)		return ::polymod::PolymodConfig_obj::rootPath;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(PolymodConfig_obj,get_rootPath,return )

 ::Dynamic PolymodConfig_obj::useNamespaceInPaths;

 ::Dynamic PolymodConfig_obj::get_useNamespaceInPaths(){
            	HX_STACKFRAME(&_hx_pos_cae42745e4bfdcf9_62_get_useNamespaceInPaths)
HXLINE(  64)		if (::hx::IsNull( ::polymod::PolymodConfig_obj::useNamespaceInPaths )) {
HXLINE(  65)			::polymod::PolymodConfig_obj::useNamespaceInPaths = false;
            		}
HXLINE(  66)		return ::polymod::PolymodConfig_obj::useNamespaceInPaths;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(PolymodConfig_obj,get_useNamespaceInPaths,return )

::String PolymodConfig_obj::scriptExt;

::String PolymodConfig_obj::get_scriptExt(){
            	HX_STACKFRAME(&_hx_pos_cae42745e4bfdcf9_80_get_scriptExt)
HXLINE(  82)		if (::hx::IsNull( ::polymod::PolymodConfig_obj::scriptExt )) {
HXLINE(  83)			::polymod::PolymodConfig_obj::scriptExt = HX_(".txt",02,3f,c0,1e);
            		}
HXLINE(  84)		return ::polymod::PolymodConfig_obj::scriptExt;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(PolymodConfig_obj,get_scriptExt,return )

::String PolymodConfig_obj::scriptClassExt;

::String PolymodConfig_obj::get_scriptClassExt(){
            	HX_STACKFRAME(&_hx_pos_cae42745e4bfdcf9_98_get_scriptClassExt)
HXLINE( 100)		if (::hx::IsNull( ::polymod::PolymodConfig_obj::scriptClassExt )) {
HXLINE( 101)			::polymod::PolymodConfig_obj::scriptClassExt = HX_(".hxc",e5,23,b7,1e);
            		}
HXLINE( 102)		return ::polymod::PolymodConfig_obj::scriptClassExt;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(PolymodConfig_obj,get_scriptClassExt,return )

::String PolymodConfig_obj::scriptLibrary;

::String PolymodConfig_obj::get_scriptLibrary(){
            	HX_STACKFRAME(&_hx_pos_cae42745e4bfdcf9_117_get_scriptLibrary)
HXLINE( 119)		if (::hx::IsNull( ::polymod::PolymodConfig_obj::scriptLibrary )) {
HXLINE( 120)			::polymod::PolymodConfig_obj::scriptLibrary = HX_("default",c1,d8,c3,9b);
            		}
HXLINE( 121)		return ::polymod::PolymodConfig_obj::scriptLibrary;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(PolymodConfig_obj,get_scriptLibrary,return )

::String PolymodConfig_obj::appendFolder;

::String PolymodConfig_obj::get_appendFolder(){
            	HX_STACKFRAME(&_hx_pos_cae42745e4bfdcf9_135_get_appendFolder)
HXLINE( 137)		if (::hx::IsNull( ::polymod::PolymodConfig_obj::appendFolder )) {
HXLINE( 138)			::polymod::PolymodConfig_obj::appendFolder = HX_("_append",79,f3,4a,fe);
            		}
HXLINE( 139)		return ::polymod::PolymodConfig_obj::appendFolder;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(PolymodConfig_obj,get_appendFolder,return )

 ::Dynamic PolymodConfig_obj::apiVersionMatch;

 ::Dynamic PolymodConfig_obj::get_apiVersionMatch(){
            	HX_STACKFRAME(&_hx_pos_cae42745e4bfdcf9_159_get_apiVersionMatch)
HXLINE( 161)		if (::hx::IsNull( ::polymod::PolymodConfig_obj::apiVersionMatch )) {
HXLINE( 162)			::polymod::PolymodConfig_obj::apiVersionMatch = ::polymod::util::_SemanticVersion::SemanticVersionScore_Impl__obj::fromString(HX_("MATCH_PATCH",ce,f0,6e,ae));
            		}
HXLINE( 163)		return ::polymod::PolymodConfig_obj::apiVersionMatch;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(PolymodConfig_obj,get_apiVersionMatch,return )

::String PolymodConfig_obj::mergeFolder;

::String PolymodConfig_obj::get_mergeFolder(){
            	HX_STACKFRAME(&_hx_pos_cae42745e4bfdcf9_177_get_mergeFolder)
HXLINE( 179)		if (::hx::IsNull( ::polymod::PolymodConfig_obj::mergeFolder )) {
HXLINE( 180)			::polymod::PolymodConfig_obj::mergeFolder = HX_("_merge",f9,e9,ad,01);
            		}
HXLINE( 181)		return ::polymod::PolymodConfig_obj::mergeFolder;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(PolymodConfig_obj,get_mergeFolder,return )

::String PolymodConfig_obj::modPackFile;

::String PolymodConfig_obj::get_modPackFile(){
            	HX_STACKFRAME(&_hx_pos_cae42745e4bfdcf9_196_get_modPackFile)
HXLINE( 198)		if (::hx::IsNull( ::polymod::PolymodConfig_obj::modPackFile )) {
HXLINE( 199)			::polymod::PolymodConfig_obj::modPackFile = HX_("_polymod_pack.txt",63,9d,09,cb);
            		}
HXLINE( 200)		return ::polymod::PolymodConfig_obj::modPackFile;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(PolymodConfig_obj,get_modPackFile,return )

::String PolymodConfig_obj::modMetadataFile;

::String PolymodConfig_obj::get_modMetadataFile(){
            	HX_STACKFRAME(&_hx_pos_cae42745e4bfdcf9_214_get_modMetadataFile)
HXLINE( 216)		if (::hx::IsNull( ::polymod::PolymodConfig_obj::modMetadataFile )) {
HXLINE( 217)			::polymod::PolymodConfig_obj::modMetadataFile = HX_("_polymod_meta.json",69,fc,10,06);
            		}
HXLINE( 218)		return ::polymod::PolymodConfig_obj::modMetadataFile;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(PolymodConfig_obj,get_modMetadataFile,return )

::String PolymodConfig_obj::modIconFile;

::String PolymodConfig_obj::get_modIconFile(){
            	HX_STACKFRAME(&_hx_pos_cae42745e4bfdcf9_232_get_modIconFile)
HXLINE( 234)		if (::hx::IsNull( ::polymod::PolymodConfig_obj::modIconFile )) {
HXLINE( 235)			::polymod::PolymodConfig_obj::modIconFile = HX_("_polymod_icon.png",3c,6c,4c,14);
            		}
HXLINE( 236)		return ::polymod::PolymodConfig_obj::modIconFile;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(PolymodConfig_obj,get_modIconFile,return )

::Array< ::String > PolymodConfig_obj::modIgnoreFiles;

::Array< ::String > PolymodConfig_obj::get_modIgnoreFiles(){
            	HX_STACKFRAME(&_hx_pos_cae42745e4bfdcf9_251_get_modIgnoreFiles)
HXLINE( 253)		if (::hx::IsNull( ::polymod::PolymodConfig_obj::modIgnoreFiles )) {
HXLINE( 254)			::polymod::PolymodConfig_obj::modIgnoreFiles = ::Array_obj< ::String >::fromData( _hx_array_data_a82454c0_13,3);
            		}
HXLINE( 255)		return ::polymod::PolymodConfig_obj::modIgnoreFiles;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(PolymodConfig_obj,get_modIgnoreFiles,return )


PolymodConfig_obj::PolymodConfig_obj()
{
}

bool PolymodConfig_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"debug") ) { outValue = ( inCallProp == ::hx::paccAlways ? get_debug() : debug ); return true; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"rootPath") ) { outValue = ( inCallProp == ::hx::paccAlways ? get_rootPath() : rootPath ); return true; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_debug") ) { outValue = get_debug_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"scriptExt") ) { outValue = ( inCallProp == ::hx::paccAlways ? get_scriptExt() : scriptExt ); return true; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"mergeFolder") ) { outValue = ( inCallProp == ::hx::paccAlways ? get_mergeFolder() : mergeFolder ); return true; }
		if (HX_FIELD_EQ(inName,"modPackFile") ) { outValue = ( inCallProp == ::hx::paccAlways ? get_modPackFile() : modPackFile ); return true; }
		if (HX_FIELD_EQ(inName,"modIconFile") ) { outValue = ( inCallProp == ::hx::paccAlways ? get_modIconFile() : modIconFile ); return true; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_rootPath") ) { outValue = get_rootPath_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"appendFolder") ) { outValue = ( inCallProp == ::hx::paccAlways ? get_appendFolder() : appendFolder ); return true; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"get_scriptExt") ) { outValue = get_scriptExt_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"scriptLibrary") ) { outValue = ( inCallProp == ::hx::paccAlways ? get_scriptLibrary() : scriptLibrary ); return true; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"scriptClassExt") ) { outValue = ( inCallProp == ::hx::paccAlways ? get_scriptClassExt() : scriptClassExt ); return true; }
		if (HX_FIELD_EQ(inName,"modIgnoreFiles") ) { outValue = ( inCallProp == ::hx::paccAlways ? get_modIgnoreFiles() : modIgnoreFiles ); return true; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"apiVersionMatch") ) { outValue = ( inCallProp == ::hx::paccAlways ? get_apiVersionMatch() : apiVersionMatch ); return true; }
		if (HX_FIELD_EQ(inName,"get_mergeFolder") ) { outValue = get_mergeFolder_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"get_modPackFile") ) { outValue = get_modPackFile_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"modMetadataFile") ) { outValue = ( inCallProp == ::hx::paccAlways ? get_modMetadataFile() : modMetadataFile ); return true; }
		if (HX_FIELD_EQ(inName,"get_modIconFile") ) { outValue = get_modIconFile_dyn(); return true; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"get_appendFolder") ) { outValue = get_appendFolder_dyn(); return true; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"get_scriptLibrary") ) { outValue = get_scriptLibrary_dyn(); return true; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"get_scriptClassExt") ) { outValue = get_scriptClassExt_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"get_modIgnoreFiles") ) { outValue = get_modIgnoreFiles_dyn(); return true; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"useNamespaceInPaths") ) { outValue = ( inCallProp == ::hx::paccAlways ? get_useNamespaceInPaths() : useNamespaceInPaths ); return true; }
		if (HX_FIELD_EQ(inName,"get_apiVersionMatch") ) { outValue = get_apiVersionMatch_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"get_modMetadataFile") ) { outValue = get_modMetadataFile_dyn(); return true; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"get_useNamespaceInPaths") ) { outValue = get_useNamespaceInPaths_dyn(); return true; }
	}
	return false;
}

bool PolymodConfig_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"debug") ) { debug=ioValue.Cast<  ::Dynamic >(); return true; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"rootPath") ) { rootPath=ioValue.Cast< ::String >(); return true; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"scriptExt") ) { scriptExt=ioValue.Cast< ::String >(); return true; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"mergeFolder") ) { mergeFolder=ioValue.Cast< ::String >(); return true; }
		if (HX_FIELD_EQ(inName,"modPackFile") ) { modPackFile=ioValue.Cast< ::String >(); return true; }
		if (HX_FIELD_EQ(inName,"modIconFile") ) { modIconFile=ioValue.Cast< ::String >(); return true; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"appendFolder") ) { appendFolder=ioValue.Cast< ::String >(); return true; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"scriptLibrary") ) { scriptLibrary=ioValue.Cast< ::String >(); return true; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"scriptClassExt") ) { scriptClassExt=ioValue.Cast< ::String >(); return true; }
		if (HX_FIELD_EQ(inName,"modIgnoreFiles") ) { modIgnoreFiles=ioValue.Cast< ::Array< ::String > >(); return true; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"apiVersionMatch") ) { apiVersionMatch=ioValue.Cast<  ::Dynamic >(); return true; }
		if (HX_FIELD_EQ(inName,"modMetadataFile") ) { modMetadataFile=ioValue.Cast< ::String >(); return true; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"useNamespaceInPaths") ) { useNamespaceInPaths=ioValue.Cast<  ::Dynamic >(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *PolymodConfig_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo PolymodConfig_obj_sStaticStorageInfo[] = {
	{::hx::fsObject /*  ::Dynamic */ ,(void *) &PolymodConfig_obj::debug,HX_("debug",53,52,1f,d7)},
	{::hx::fsString,(void *) &PolymodConfig_obj::rootPath,HX_("rootPath",e7,b8,88,e1)},
	{::hx::fsObject /*  ::Dynamic */ ,(void *) &PolymodConfig_obj::useNamespaceInPaths,HX_("useNamespaceInPaths",15,be,fe,da)},
	{::hx::fsString,(void *) &PolymodConfig_obj::scriptExt,HX_("scriptExt",56,8f,be,2a)},
	{::hx::fsString,(void *) &PolymodConfig_obj::scriptClassExt,HX_("scriptClassExt",74,cc,ea,14)},
	{::hx::fsString,(void *) &PolymodConfig_obj::scriptLibrary,HX_("scriptLibrary",30,a8,51,45)},
	{::hx::fsString,(void *) &PolymodConfig_obj::appendFolder,HX_("appendFolder",28,ac,de,a4)},
	{::hx::fsObject /*  ::Dynamic */ ,(void *) &PolymodConfig_obj::apiVersionMatch,HX_("apiVersionMatch",c7,e2,db,9b)},
	{::hx::fsString,(void *) &PolymodConfig_obj::mergeFolder,HX_("mergeFolder",86,67,fe,44)},
	{::hx::fsString,(void *) &PolymodConfig_obj::modPackFile,HX_("modPackFile",d7,16,7a,a6)},
	{::hx::fsString,(void *) &PolymodConfig_obj::modMetadataFile,HX_("modMetadataFile",6d,43,36,48)},
	{::hx::fsString,(void *) &PolymodConfig_obj::modIconFile,HX_("modIconFile",77,f7,bf,ef)},
	{::hx::fsObject /* ::Array< ::String > */ ,(void *) &PolymodConfig_obj::modIgnoreFiles,HX_("modIgnoreFiles",63,c8,67,d9)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static void PolymodConfig_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PolymodConfig_obj::debug,"debug");
	HX_MARK_MEMBER_NAME(PolymodConfig_obj::rootPath,"rootPath");
	HX_MARK_MEMBER_NAME(PolymodConfig_obj::useNamespaceInPaths,"useNamespaceInPaths");
	HX_MARK_MEMBER_NAME(PolymodConfig_obj::scriptExt,"scriptExt");
	HX_MARK_MEMBER_NAME(PolymodConfig_obj::scriptClassExt,"scriptClassExt");
	HX_MARK_MEMBER_NAME(PolymodConfig_obj::scriptLibrary,"scriptLibrary");
	HX_MARK_MEMBER_NAME(PolymodConfig_obj::appendFolder,"appendFolder");
	HX_MARK_MEMBER_NAME(PolymodConfig_obj::apiVersionMatch,"apiVersionMatch");
	HX_MARK_MEMBER_NAME(PolymodConfig_obj::mergeFolder,"mergeFolder");
	HX_MARK_MEMBER_NAME(PolymodConfig_obj::modPackFile,"modPackFile");
	HX_MARK_MEMBER_NAME(PolymodConfig_obj::modMetadataFile,"modMetadataFile");
	HX_MARK_MEMBER_NAME(PolymodConfig_obj::modIconFile,"modIconFile");
	HX_MARK_MEMBER_NAME(PolymodConfig_obj::modIgnoreFiles,"modIgnoreFiles");
};

#ifdef HXCPP_VISIT_ALLOCS
static void PolymodConfig_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PolymodConfig_obj::debug,"debug");
	HX_VISIT_MEMBER_NAME(PolymodConfig_obj::rootPath,"rootPath");
	HX_VISIT_MEMBER_NAME(PolymodConfig_obj::useNamespaceInPaths,"useNamespaceInPaths");
	HX_VISIT_MEMBER_NAME(PolymodConfig_obj::scriptExt,"scriptExt");
	HX_VISIT_MEMBER_NAME(PolymodConfig_obj::scriptClassExt,"scriptClassExt");
	HX_VISIT_MEMBER_NAME(PolymodConfig_obj::scriptLibrary,"scriptLibrary");
	HX_VISIT_MEMBER_NAME(PolymodConfig_obj::appendFolder,"appendFolder");
	HX_VISIT_MEMBER_NAME(PolymodConfig_obj::apiVersionMatch,"apiVersionMatch");
	HX_VISIT_MEMBER_NAME(PolymodConfig_obj::mergeFolder,"mergeFolder");
	HX_VISIT_MEMBER_NAME(PolymodConfig_obj::modPackFile,"modPackFile");
	HX_VISIT_MEMBER_NAME(PolymodConfig_obj::modMetadataFile,"modMetadataFile");
	HX_VISIT_MEMBER_NAME(PolymodConfig_obj::modIconFile,"modIconFile");
	HX_VISIT_MEMBER_NAME(PolymodConfig_obj::modIgnoreFiles,"modIgnoreFiles");
};

#endif

::hx::Class PolymodConfig_obj::__mClass;

static ::String PolymodConfig_obj_sStaticFields[] = {
	HX_("debug",53,52,1f,d7),
	HX_("get_debug",aa,ae,c8,1a),
	HX_("rootPath",e7,b8,88,e1),
	HX_("get_rootPath",f0,6c,a2,96),
	HX_("useNamespaceInPaths",15,be,fe,da),
	HX_("get_useNamespaceInPaths",ac,64,54,e3),
	HX_("scriptExt",56,8f,be,2a),
	HX_("get_scriptExt",2d,63,22,ec),
	HX_("scriptClassExt",74,cc,ea,14),
	HX_("get_scriptClassExt",3d,ad,84,b0),
	HX_("scriptLibrary",30,a8,51,45),
	HX_("get_scriptLibrary",87,b3,c1,4b),
	HX_("appendFolder",28,ac,de,a4),
	HX_("get_appendFolder",b1,98,7d,a9),
	HX_("apiVersionMatch",c7,e2,db,9b),
	HX_("get_apiVersionMatch",de,b1,e6,26),
	HX_("mergeFolder",86,67,fe,44),
	HX_("get_mergeFolder",1d,1f,e0,05),
	HX_("modPackFile",d7,16,7a,a6),
	HX_("get_modPackFile",6e,ce,5b,67),
	HX_("modMetadataFile",6d,43,36,48),
	HX_("get_modMetadataFile",84,12,41,d3),
	HX_("modIconFile",77,f7,bf,ef),
	HX_("get_modIconFile",0e,af,a1,b0),
	HX_("modIgnoreFiles",63,c8,67,d9),
	HX_("get_modIgnoreFiles",2c,a9,01,75),
	::String(null())
};

void PolymodConfig_obj::__register()
{
	PolymodConfig_obj _hx_dummy;
	PolymodConfig_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("polymod.PolymodConfig",c0,54,24,a8);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &PolymodConfig_obj::__GetStatic;
	__mClass->mSetStaticField = &PolymodConfig_obj::__SetStatic;
	__mClass->mMarkFunc = PolymodConfig_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(PolymodConfig_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< PolymodConfig_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = PolymodConfig_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = PolymodConfig_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = PolymodConfig_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void PolymodConfig_obj::__boot()
{
{
            	HX_STACKFRAME(&_hx_pos_cae42745e4bfdcf9_156_boot)
HXDLIN( 156)		apiVersionMatch = null();
            	}
}

} // end namespace polymod
