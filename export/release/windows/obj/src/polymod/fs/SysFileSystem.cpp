#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_polymod_ModMetadata
#include <polymod/ModMetadata.h>
#endif
#ifndef INCLUDED_polymod_Polymod
#include <polymod/Polymod.h>
#endif
#ifndef INCLUDED_polymod_PolymodConfig
#include <polymod/PolymodConfig.h>
#endif
#ifndef INCLUDED_polymod_fs_IFileSystem
#include <polymod/fs/IFileSystem.h>
#endif
#ifndef INCLUDED_polymod_fs_SysFileSystem
#include <polymod/fs/SysFileSystem.h>
#endif
#ifndef INCLUDED_polymod_util_Util
#include <polymod/util/Util.h>
#endif
#ifndef INCLUDED_sys_FileSystem
#include <sys/FileSystem.h>
#endif
#ifndef INCLUDED_sys_io_File
#include <sys/io/File.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_bf2ba162cbc492b7_18_new,"polymod.fs.SysFileSystem","new",0x6e978ee1,"polymod.fs.SysFileSystem.new","polymod/fs/SysFileSystem.hx",18,0xf6781e4f)
HX_LOCAL_STACK_FRAME(_hx_pos_bf2ba162cbc492b7_23_exists,"polymod.fs.SysFileSystem","exists",0x494ba5fb,"polymod.fs.SysFileSystem.exists","polymod/fs/SysFileSystem.hx",23,0xf6781e4f)
HX_LOCAL_STACK_FRAME(_hx_pos_bf2ba162cbc492b7_27_isDirectory,"polymod.fs.SysFileSystem","isDirectory",0x4f9d50a4,"polymod.fs.SysFileSystem.isDirectory","polymod/fs/SysFileSystem.hx",27,0xf6781e4f)
HX_LOCAL_STACK_FRAME(_hx_pos_bf2ba162cbc492b7_30_readDirectory,"polymod.fs.SysFileSystem","readDirectory",0xa764b5f8,"polymod.fs.SysFileSystem.readDirectory","polymod/fs/SysFileSystem.hx",30,0xf6781e4f)
HX_LOCAL_STACK_FRAME(_hx_pos_bf2ba162cbc492b7_33_getFileContent,"polymod.fs.SysFileSystem","getFileContent",0x6bbf8046,"polymod.fs.SysFileSystem.getFileContent","polymod/fs/SysFileSystem.hx",33,0xf6781e4f)
HX_LOCAL_STACK_FRAME(_hx_pos_bf2ba162cbc492b7_40_getFileBytes,"polymod.fs.SysFileSystem","getFileBytes",0x2af12e38,"polymod.fs.SysFileSystem.getFileBytes","polymod/fs/SysFileSystem.hx",40,0xf6781e4f)
HX_LOCAL_STACK_FRAME(_hx_pos_bf2ba162cbc492b7_47_scanMods,"polymod.fs.SysFileSystem","scanMods",0x79d70d6d,"polymod.fs.SysFileSystem.scanMods","polymod/fs/SysFileSystem.hx",47,0xf6781e4f)
HX_LOCAL_STACK_FRAME(_hx_pos_bf2ba162cbc492b7_64_getMetadata,"polymod.fs.SysFileSystem","getMetadata",0xc6e551a6,"polymod.fs.SysFileSystem.getMetadata","polymod/fs/SysFileSystem.hx",64,0xf6781e4f)
HX_LOCAL_STACK_FRAME(_hx_pos_bf2ba162cbc492b7_104_readDirectoryRecursive,"polymod.fs.SysFileSystem","readDirectoryRecursive",0x29cb565a,"polymod.fs.SysFileSystem.readDirectoryRecursive","polymod/fs/SysFileSystem.hx",104,0xf6781e4f)
HX_LOCAL_STACK_FRAME(_hx_pos_bf2ba162cbc492b7_120__readDirectoryRecursive,"polymod.fs.SysFileSystem","_readDirectoryRecursive",0x895744db,"polymod.fs.SysFileSystem._readDirectoryRecursive","polymod/fs/SysFileSystem.hx",120,0xf6781e4f)
namespace polymod{
namespace fs{

void SysFileSystem_obj::__construct( ::Dynamic params){
            	HX_STACKFRAME(&_hx_pos_bf2ba162cbc492b7_18_new)
HXDLIN(  18)		this->modRoot = ( (::String)(params->__Field(HX_("modRoot",04,ba,da,e0),::hx::paccDynamic)) );
            	}

Dynamic SysFileSystem_obj::__CreateEmpty() { return new SysFileSystem_obj; }

void *SysFileSystem_obj::_hx_vtable = 0;

Dynamic SysFileSystem_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< SysFileSystem_obj > _hx_result = new SysFileSystem_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool SysFileSystem_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x744a2635;
}

static ::polymod::fs::IFileSystem_obj _hx_polymod_fs_SysFileSystem__hx_polymod_fs_IFileSystem= {
	( bool (::hx::Object::*)(::String))&::polymod::fs::SysFileSystem_obj::exists,
	( bool (::hx::Object::*)(::String))&::polymod::fs::SysFileSystem_obj::isDirectory,
	( ::Array< ::String > (::hx::Object::*)(::String))&::polymod::fs::SysFileSystem_obj::readDirectory,
	( ::Array< ::String > (::hx::Object::*)(::String))&::polymod::fs::SysFileSystem_obj::readDirectoryRecursive,
	( ::String (::hx::Object::*)(::String))&::polymod::fs::SysFileSystem_obj::getFileContent,
	(  ::haxe::io::Bytes (::hx::Object::*)(::String))&::polymod::fs::SysFileSystem_obj::getFileBytes,
	( ::Array< ::String > (::hx::Object::*)())&::polymod::fs::SysFileSystem_obj::scanMods,
	(  ::polymod::ModMetadata (::hx::Object::*)(::String))&::polymod::fs::SysFileSystem_obj::getMetadata,
};

void *SysFileSystem_obj::_hx_getInterface(int inHash) {
	switch(inHash) {
		case (int)0x0d05d891: return &_hx_polymod_fs_SysFileSystem__hx_polymod_fs_IFileSystem;
	}
	#ifdef HXCPP_SCRIPTABLE
	return super::_hx_getInterface(inHash);
	#else
	return 0;
	#endif
}

bool SysFileSystem_obj::exists(::String path){
            	HX_STACKFRAME(&_hx_pos_bf2ba162cbc492b7_23_exists)
HXDLIN(  23)		return ::sys::FileSystem_obj::exists(path);
            	}


HX_DEFINE_DYNAMIC_FUNC1(SysFileSystem_obj,exists,return )

bool SysFileSystem_obj::isDirectory(::String path){
            	HX_STACKFRAME(&_hx_pos_bf2ba162cbc492b7_27_isDirectory)
HXDLIN(  27)		return ::sys::FileSystem_obj::isDirectory(path);
            	}


HX_DEFINE_DYNAMIC_FUNC1(SysFileSystem_obj,isDirectory,return )

::Array< ::String > SysFileSystem_obj::readDirectory(::String path){
            	HX_STACKFRAME(&_hx_pos_bf2ba162cbc492b7_30_readDirectory)
HXDLIN(  30)		return ::sys::FileSystem_obj::readDirectory(path);
            	}


HX_DEFINE_DYNAMIC_FUNC1(SysFileSystem_obj,readDirectory,return )

::String SysFileSystem_obj::getFileContent(::String path){
            	HX_STACKFRAME(&_hx_pos_bf2ba162cbc492b7_33_getFileContent)
HXLINE(  34)		if (!(::sys::FileSystem_obj::exists(path))) {
HXLINE(  35)			return null();
            		}
HXLINE(  36)		return ::sys::io::File_obj::getContent(path);
            	}


HX_DEFINE_DYNAMIC_FUNC1(SysFileSystem_obj,getFileContent,return )

 ::haxe::io::Bytes SysFileSystem_obj::getFileBytes(::String path){
            	HX_STACKFRAME(&_hx_pos_bf2ba162cbc492b7_40_getFileBytes)
HXLINE(  41)		if (!(::sys::FileSystem_obj::exists(path))) {
HXLINE(  42)			return null();
            		}
HXLINE(  43)		return ::sys::io::File_obj::getBytes(path);
            	}


HX_DEFINE_DYNAMIC_FUNC1(SysFileSystem_obj,getFileBytes,return )

::Array< ::String > SysFileSystem_obj::scanMods(){
            	HX_STACKFRAME(&_hx_pos_bf2ba162cbc492b7_47_scanMods)
HXLINE(  48)		::Array< ::String > dirs = ::sys::FileSystem_obj::readDirectory(this->modRoot);
HXLINE(  49)		int l = dirs->length;
HXLINE(  50)		{
HXLINE(  50)			int _g = 0;
HXDLIN(  50)			int _g1 = l;
HXDLIN(  50)			while((_g < _g1)){
HXLINE(  50)				_g = (_g + 1);
HXDLIN(  50)				int i = (_g - 1);
HXLINE(  52)				int j = ((l - i) - 1);
HXLINE(  53)				::String dir = dirs->__get(j);
HXLINE(  54)				::String testDir = (((HX_("",00,00,00,00) + this->modRoot) + HX_("/",2f,00,00,00)) + dir);
HXLINE(  55)				bool _hx_tmp;
HXDLIN(  55)				if (::sys::FileSystem_obj::isDirectory(testDir)) {
HXLINE(  55)					_hx_tmp = !(::sys::FileSystem_obj::exists(testDir));
            				}
            				else {
HXLINE(  55)					_hx_tmp = true;
            				}
HXDLIN(  55)				if (_hx_tmp) {
HXLINE(  57)					dirs->removeRange(j,1);
            				}
            			}
            		}
HXLINE(  60)		return dirs;
            	}


HX_DEFINE_DYNAMIC_FUNC0(SysFileSystem_obj,scanMods,return )

 ::polymod::ModMetadata SysFileSystem_obj::getMetadata(::String modId){
            	HX_STACKFRAME(&_hx_pos_bf2ba162cbc492b7_64_getMetadata)
HXLINE(  65)		if (::sys::FileSystem_obj::exists(modId)) {
HXLINE(  67)			 ::polymod::ModMetadata meta = null();
HXLINE(  69)			::String metaFile = ::polymod::util::Util_obj::pathJoin(modId,::polymod::PolymodConfig_obj::get_modMetadataFile());
HXLINE(  70)			::String iconFile = ::polymod::util::Util_obj::pathJoin(modId,::polymod::PolymodConfig_obj::get_modIconFile());
HXLINE(  72)			if (!(::sys::FileSystem_obj::exists(metaFile))) {
HXLINE(  74)				::polymod::Polymod_obj::warning(HX_("missing_meta",7e,15,b8,7b),(HX_("Could not find mod metadata file: ",3a,e3,e3,94) + metaFile),null());
HXLINE(  75)				return null();
            			}
            			else {
HXLINE(  79)				::String metaText;
HXDLIN(  79)				if (!(::sys::FileSystem_obj::exists(metaFile))) {
HXLINE(  79)					metaText = null();
            				}
            				else {
HXLINE(  79)					metaText = ::sys::io::File_obj::getContent(metaFile);
            				}
HXDLIN(  79)				::String metaText1 = metaText;
HXLINE(  80)				meta = ::polymod::ModMetadata_obj::fromJsonStr(metaText1);
HXLINE(  81)				if (::hx::IsNull( meta )) {
HXLINE(  82)					return null();
            				}
            			}
HXLINE(  85)			if (!(::sys::FileSystem_obj::exists(iconFile))) {
HXLINE(  87)				::polymod::Polymod_obj::warning(HX_("missing_icon",32,b2,11,79),(HX_("Could not find mod icon file: ",f0,c8,b1,6d) + iconFile),null());
            			}
            			else {
HXLINE(  91)				 ::haxe::io::Bytes iconBytes;
HXDLIN(  91)				if (!(::sys::FileSystem_obj::exists(iconFile))) {
HXLINE(  91)					iconBytes = null();
            				}
            				else {
HXLINE(  91)					iconBytes = ::sys::io::File_obj::getBytes(iconFile);
            				}
HXDLIN(  91)				 ::haxe::io::Bytes iconBytes1 = iconBytes;
HXLINE(  92)				meta->icon = iconBytes1;
            			}
HXLINE(  94)			return meta;
            		}
            		else {
HXLINE(  98)			::polymod::Polymod_obj::error(HX_("missing_mod",29,c6,4d,c8),(HX_("Could not find mod directory: ",5a,c9,b1,d4) + modId),null());
            		}
HXLINE( 100)		return null();
            	}


HX_DEFINE_DYNAMIC_FUNC1(SysFileSystem_obj,getMetadata,return )

::Array< ::String > SysFileSystem_obj::readDirectoryRecursive(::String path){
            	HX_STACKFRAME(&_hx_pos_bf2ba162cbc492b7_104_readDirectoryRecursive)
HXLINE( 105)		::Array< ::String > all = this->_readDirectoryRecursive(path);
HXLINE( 106)		{
HXLINE( 106)			int _g = 0;
HXDLIN( 106)			int _g1 = all->length;
HXDLIN( 106)			while((_g < _g1)){
HXLINE( 106)				_g = (_g + 1);
HXDLIN( 106)				int i = (_g - 1);
HXLINE( 108)				::String f = all->__get(i);
HXLINE( 109)				int stri = ::polymod::util::Util_obj::uIndexOf(f,(path + HX_("/",2f,00,00,00)),null());
HXLINE( 110)				if ((stri == 0)) {
HXLINE( 112)					int f1 = ::polymod::util::Util_obj::uLength((path + HX_("/",2f,00,00,00)));
HXDLIN( 112)					f = ::polymod::util::Util_obj::uSubstr(f,f1,::polymod::util::Util_obj::uLength(f));
HXLINE( 113)					all[i] = f;
            				}
            			}
            		}
HXLINE( 116)		return all;
            	}


HX_DEFINE_DYNAMIC_FUNC1(SysFileSystem_obj,readDirectoryRecursive,return )

::Array< ::String > SysFileSystem_obj::_readDirectoryRecursive(::String str){
            	HX_STACKFRAME(&_hx_pos_bf2ba162cbc492b7_120__readDirectoryRecursive)
HXLINE( 121)		bool _hx_tmp;
HXDLIN( 121)		if (::sys::FileSystem_obj::exists(str)) {
HXLINE( 121)			_hx_tmp = ::sys::FileSystem_obj::isDirectory(str);
            		}
            		else {
HXLINE( 121)			_hx_tmp = false;
            		}
HXDLIN( 121)		if (_hx_tmp) {
HXLINE( 123)			::Array< ::String > all = ::sys::FileSystem_obj::readDirectory(str);
HXLINE( 124)			if (::hx::IsNull( all )) {
HXLINE( 125)				return ::Array_obj< ::String >::__new(0);
            			}
HXLINE( 126)			::Array< ::String > results = ::Array_obj< ::String >::__new(0);
HXLINE( 127)			{
HXLINE( 127)				int _g = 0;
HXDLIN( 127)				while((_g < all->length)){
HXLINE( 127)					::String thing = all->__get(_g);
HXDLIN( 127)					_g = (_g + 1);
HXLINE( 129)					if (::hx::IsNull( thing )) {
HXLINE( 130)						continue;
            					}
HXLINE( 131)					::String pathToThing = ::polymod::util::Util_obj::pathJoin(str,thing);
HXLINE( 132)					if (::sys::FileSystem_obj::isDirectory(pathToThing)) {
HXLINE( 134)						::Array< ::String > subs = this->_readDirectoryRecursive(pathToThing);
HXLINE( 135)						if (::hx::IsNotNull( subs )) {
HXLINE( 137)							results = results->concat(subs);
            						}
            					}
            					else {
HXLINE( 142)						results->push(pathToThing);
            					}
            				}
            			}
HXLINE( 145)			return results;
            		}
HXLINE( 147)		return ::Array_obj< ::String >::__new(0);
            	}


HX_DEFINE_DYNAMIC_FUNC1(SysFileSystem_obj,_readDirectoryRecursive,return )


::hx::ObjectPtr< SysFileSystem_obj > SysFileSystem_obj::__new( ::Dynamic params) {
	::hx::ObjectPtr< SysFileSystem_obj > __this = new SysFileSystem_obj();
	__this->__construct(params);
	return __this;
}

::hx::ObjectPtr< SysFileSystem_obj > SysFileSystem_obj::__alloc(::hx::Ctx *_hx_ctx, ::Dynamic params) {
	SysFileSystem_obj *__this = (SysFileSystem_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(SysFileSystem_obj), true, "polymod.fs.SysFileSystem"));
	*(void **)__this = SysFileSystem_obj::_hx_vtable;
	__this->__construct(params);
	return __this;
}

SysFileSystem_obj::SysFileSystem_obj()
{
}

void SysFileSystem_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SysFileSystem);
	HX_MARK_MEMBER_NAME(modRoot,"modRoot");
	HX_MARK_END_CLASS();
}

void SysFileSystem_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(modRoot,"modRoot");
}

::hx::Val SysFileSystem_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"exists") ) { return ::hx::Val( exists_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"modRoot") ) { return ::hx::Val( modRoot ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"scanMods") ) { return ::hx::Val( scanMods_dyn() ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"isDirectory") ) { return ::hx::Val( isDirectory_dyn() ); }
		if (HX_FIELD_EQ(inName,"getMetadata") ) { return ::hx::Val( getMetadata_dyn() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"getFileBytes") ) { return ::hx::Val( getFileBytes_dyn() ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"readDirectory") ) { return ::hx::Val( readDirectory_dyn() ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getFileContent") ) { return ::hx::Val( getFileContent_dyn() ); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"readDirectoryRecursive") ) { return ::hx::Val( readDirectoryRecursive_dyn() ); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"_readDirectoryRecursive") ) { return ::hx::Val( _readDirectoryRecursive_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val SysFileSystem_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"modRoot") ) { modRoot=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SysFileSystem_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("modRoot",04,ba,da,e0));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo SysFileSystem_obj_sMemberStorageInfo[] = {
	{::hx::fsString,(int)offsetof(SysFileSystem_obj,modRoot),HX_("modRoot",04,ba,da,e0)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *SysFileSystem_obj_sStaticStorageInfo = 0;
#endif

static ::String SysFileSystem_obj_sMemberFields[] = {
	HX_("modRoot",04,ba,da,e0),
	HX_("exists",dc,1d,e0,bf),
	HX_("isDirectory",23,a9,c5,ee),
	HX_("readDirectory",37,6c,b3,a3),
	HX_("getFileContent",27,41,50,34),
	HX_("getFileBytes",d9,44,16,cf),
	HX_("scanMods",8e,ff,61,18),
	HX_("getMetadata",25,aa,0d,66),
	HX_("readDirectoryRecursive",3b,60,49,77),
	HX_("_readDirectoryRecursive",da,df,21,0a),
	::String(null()) };

::hx::Class SysFileSystem_obj::__mClass;

void SysFileSystem_obj::__register()
{
	SysFileSystem_obj _hx_dummy;
	SysFileSystem_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("polymod.fs.SysFileSystem",6f,8a,54,60);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(SysFileSystem_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< SysFileSystem_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = SysFileSystem_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = SysFileSystem_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace polymod
} // end namespace fs
