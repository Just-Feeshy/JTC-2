#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_polymod_ModMetadata
#include <polymod/ModMetadata.h>
#endif
#ifndef INCLUDED_polymod_fs_IFileSystem
#include <polymod/fs/IFileSystem.h>
#endif
#ifndef INCLUDED_polymod_fs_StubFileSystem
#include <polymod/fs/StubFileSystem.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_0133b8a666cd821f_14_new,"polymod.fs.StubFileSystem","new",0x945ac6f4,"polymod.fs.StubFileSystem.new","polymod/fs/StubFileSystem.hx",14,0x6bc1a85c)
HX_LOCAL_STACK_FRAME(_hx_pos_0133b8a666cd821f_18_exists,"polymod.fs.StubFileSystem","exists",0xefea7bc8,"polymod.fs.StubFileSystem.exists","polymod/fs/StubFileSystem.hx",18,0x6bc1a85c)
HX_LOCAL_STACK_FRAME(_hx_pos_0133b8a666cd821f_21_isDirectory,"polymod.fs.StubFileSystem","isDirectory",0xe74353b7,"polymod.fs.StubFileSystem.isDirectory","polymod/fs/StubFileSystem.hx",21,0x6bc1a85c)
HX_LOCAL_STACK_FRAME(_hx_pos_0133b8a666cd821f_24_readDirectory,"polymod.fs.StubFileSystem","readDirectory",0xf6dfe3cb,"polymod.fs.StubFileSystem.readDirectory","polymod/fs/StubFileSystem.hx",24,0x6bc1a85c)
HX_LOCAL_STACK_FRAME(_hx_pos_0133b8a666cd821f_27_getFileContent,"polymod.fs.StubFileSystem","getFileContent",0xa80c6b13,"polymod.fs.StubFileSystem.getFileContent","polymod/fs/StubFileSystem.hx",27,0x6bc1a85c)
HX_LOCAL_STACK_FRAME(_hx_pos_0133b8a666cd821f_30_getFileBytes,"polymod.fs.StubFileSystem","getFileBytes",0x448ddbc5,"polymod.fs.StubFileSystem.getFileBytes","polymod/fs/StubFileSystem.hx",30,0x6bc1a85c)
HX_LOCAL_STACK_FRAME(_hx_pos_0133b8a666cd821f_33_readDirectoryRecursive,"polymod.fs.StubFileSystem","readDirectoryRecursive",0x27635627,"polymod.fs.StubFileSystem.readDirectoryRecursive","polymod/fs/StubFileSystem.hx",33,0x6bc1a85c)
HX_LOCAL_STACK_FRAME(_hx_pos_0133b8a666cd821f_36_scanMods,"polymod.fs.StubFileSystem","scanMods",0x2630b07a,"polymod.fs.StubFileSystem.scanMods","polymod/fs/StubFileSystem.hx",36,0x6bc1a85c)
HX_LOCAL_STACK_FRAME(_hx_pos_0133b8a666cd821f_39_getMetadata,"polymod.fs.StubFileSystem","getMetadata",0x5e8b54b9,"polymod.fs.StubFileSystem.getMetadata","polymod/fs/StubFileSystem.hx",39,0x6bc1a85c)
namespace polymod{
namespace fs{

void StubFileSystem_obj::__construct( ::Dynamic params){
            	HX_STACKFRAME(&_hx_pos_0133b8a666cd821f_14_new)
            	}

Dynamic StubFileSystem_obj::__CreateEmpty() { return new StubFileSystem_obj; }

void *StubFileSystem_obj::_hx_vtable = 0;

Dynamic StubFileSystem_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< StubFileSystem_obj > _hx_result = new StubFileSystem_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool StubFileSystem_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x090852ec;
}

static ::polymod::fs::IFileSystem_obj _hx_polymod_fs_StubFileSystem__hx_polymod_fs_IFileSystem= {
	( bool (::hx::Object::*)(::String))&::polymod::fs::StubFileSystem_obj::exists,
	( bool (::hx::Object::*)(::String))&::polymod::fs::StubFileSystem_obj::isDirectory,
	( ::Array< ::String > (::hx::Object::*)(::String))&::polymod::fs::StubFileSystem_obj::readDirectory,
	( ::Array< ::String > (::hx::Object::*)(::String))&::polymod::fs::StubFileSystem_obj::readDirectoryRecursive,
	( ::String (::hx::Object::*)(::String))&::polymod::fs::StubFileSystem_obj::getFileContent,
	(  ::haxe::io::Bytes (::hx::Object::*)(::String))&::polymod::fs::StubFileSystem_obj::getFileBytes,
	( ::Array< ::String > (::hx::Object::*)())&::polymod::fs::StubFileSystem_obj::scanMods,
	(  ::polymod::ModMetadata (::hx::Object::*)(::String))&::polymod::fs::StubFileSystem_obj::getMetadata,
};

void *StubFileSystem_obj::_hx_getInterface(int inHash) {
	switch(inHash) {
		case (int)0x0d05d891: return &_hx_polymod_fs_StubFileSystem__hx_polymod_fs_IFileSystem;
	}
	#ifdef HXCPP_SCRIPTABLE
	return super::_hx_getInterface(inHash);
	#else
	return 0;
	#endif
}

bool StubFileSystem_obj::exists(::String path){
            	HX_STACKFRAME(&_hx_pos_0133b8a666cd821f_18_exists)
HXDLIN(  18)		return false;
            	}


HX_DEFINE_DYNAMIC_FUNC1(StubFileSystem_obj,exists,return )

bool StubFileSystem_obj::isDirectory(::String path){
            	HX_STACKFRAME(&_hx_pos_0133b8a666cd821f_21_isDirectory)
HXDLIN(  21)		return false;
            	}


HX_DEFINE_DYNAMIC_FUNC1(StubFileSystem_obj,isDirectory,return )

::Array< ::String > StubFileSystem_obj::readDirectory(::String path){
            	HX_STACKFRAME(&_hx_pos_0133b8a666cd821f_24_readDirectory)
HXDLIN(  24)		return ::Array_obj< ::String >::__new(0);
            	}


HX_DEFINE_DYNAMIC_FUNC1(StubFileSystem_obj,readDirectory,return )

::String StubFileSystem_obj::getFileContent(::String path){
            	HX_STACKFRAME(&_hx_pos_0133b8a666cd821f_27_getFileContent)
HXDLIN(  27)		return null();
            	}


HX_DEFINE_DYNAMIC_FUNC1(StubFileSystem_obj,getFileContent,return )

 ::haxe::io::Bytes StubFileSystem_obj::getFileBytes(::String path){
            	HX_STACKFRAME(&_hx_pos_0133b8a666cd821f_30_getFileBytes)
HXDLIN(  30)		return null();
            	}


HX_DEFINE_DYNAMIC_FUNC1(StubFileSystem_obj,getFileBytes,return )

::Array< ::String > StubFileSystem_obj::readDirectoryRecursive(::String path){
            	HX_STACKFRAME(&_hx_pos_0133b8a666cd821f_33_readDirectoryRecursive)
HXDLIN(  33)		return ::Array_obj< ::String >::__new(0);
            	}


HX_DEFINE_DYNAMIC_FUNC1(StubFileSystem_obj,readDirectoryRecursive,return )

::Array< ::String > StubFileSystem_obj::scanMods(){
            	HX_STACKFRAME(&_hx_pos_0133b8a666cd821f_36_scanMods)
HXDLIN(  36)		return ::Array_obj< ::String >::__new(0);
            	}


HX_DEFINE_DYNAMIC_FUNC0(StubFileSystem_obj,scanMods,return )

 ::polymod::ModMetadata StubFileSystem_obj::getMetadata(::String modId){
            	HX_STACKFRAME(&_hx_pos_0133b8a666cd821f_39_getMetadata)
HXDLIN(  39)		return null();
            	}


HX_DEFINE_DYNAMIC_FUNC1(StubFileSystem_obj,getMetadata,return )


::hx::ObjectPtr< StubFileSystem_obj > StubFileSystem_obj::__new( ::Dynamic params) {
	::hx::ObjectPtr< StubFileSystem_obj > __this = new StubFileSystem_obj();
	__this->__construct(params);
	return __this;
}

::hx::ObjectPtr< StubFileSystem_obj > StubFileSystem_obj::__alloc(::hx::Ctx *_hx_ctx, ::Dynamic params) {
	StubFileSystem_obj *__this = (StubFileSystem_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(StubFileSystem_obj), false, "polymod.fs.StubFileSystem"));
	*(void **)__this = StubFileSystem_obj::_hx_vtable;
	__this->__construct(params);
	return __this;
}

StubFileSystem_obj::StubFileSystem_obj()
{
}

::hx::Val StubFileSystem_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"exists") ) { return ::hx::Val( exists_dyn() ); }
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
	}
	return super::__Field(inName,inCallProp);
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *StubFileSystem_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *StubFileSystem_obj_sStaticStorageInfo = 0;
#endif

static ::String StubFileSystem_obj_sMemberFields[] = {
	HX_("exists",dc,1d,e0,bf),
	HX_("isDirectory",23,a9,c5,ee),
	HX_("readDirectory",37,6c,b3,a3),
	HX_("getFileContent",27,41,50,34),
	HX_("getFileBytes",d9,44,16,cf),
	HX_("readDirectoryRecursive",3b,60,49,77),
	HX_("scanMods",8e,ff,61,18),
	HX_("getMetadata",25,aa,0d,66),
	::String(null()) };

::hx::Class StubFileSystem_obj::__mClass;

void StubFileSystem_obj::__register()
{
	StubFileSystem_obj _hx_dummy;
	StubFileSystem_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("polymod.fs.StubFileSystem",02,7d,cf,24);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(StubFileSystem_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< StubFileSystem_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = StubFileSystem_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = StubFileSystem_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace polymod
} // end namespace fs
