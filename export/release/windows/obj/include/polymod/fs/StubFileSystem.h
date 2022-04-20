#ifndef INCLUDED_polymod_fs_StubFileSystem
#define INCLUDED_polymod_fs_StubFileSystem

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_polymod_fs_IFileSystem
#include <polymod/fs/IFileSystem.h>
#endif
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS1(polymod,ModMetadata)
HX_DECLARE_CLASS2(polymod,fs,IFileSystem)
HX_DECLARE_CLASS2(polymod,fs,StubFileSystem)

namespace polymod{
namespace fs{


class HXCPP_CLASS_ATTRIBUTES StubFileSystem_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef StubFileSystem_obj OBJ_;
		StubFileSystem_obj();

	public:
		enum { _hx_ClassId = 0x090852ec };

		void __construct( ::Dynamic params);
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="polymod.fs.StubFileSystem")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"polymod.fs.StubFileSystem"); }
		static ::hx::ObjectPtr< StubFileSystem_obj > __new( ::Dynamic params);
		static ::hx::ObjectPtr< StubFileSystem_obj > __alloc(::hx::Ctx *_hx_ctx, ::Dynamic params);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~StubFileSystem_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		void *_hx_getInterface(int inHash);
		::String __ToString() const { return HX_("StubFileSystem",79,f1,24,e5); }

		bool exists(::String path);
		::Dynamic exists_dyn();

		bool isDirectory(::String path);
		::Dynamic isDirectory_dyn();

		::Array< ::String > readDirectory(::String path);
		::Dynamic readDirectory_dyn();

		::String getFileContent(::String path);
		::Dynamic getFileContent_dyn();

		 ::haxe::io::Bytes getFileBytes(::String path);
		::Dynamic getFileBytes_dyn();

		::Array< ::String > readDirectoryRecursive(::String path);
		::Dynamic readDirectoryRecursive_dyn();

		::Array< ::String > scanMods();
		::Dynamic scanMods_dyn();

		 ::polymod::ModMetadata getMetadata(::String modId);
		::Dynamic getMetadata_dyn();

};

} // end namespace polymod
} // end namespace fs

#endif /* INCLUDED_polymod_fs_StubFileSystem */ 
