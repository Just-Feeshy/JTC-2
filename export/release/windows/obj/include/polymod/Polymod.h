#ifndef INCLUDED_polymod_Polymod
#define INCLUDED_polymod_Polymod

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(polymod,ModMetadata)
HX_DECLARE_CLASS1(polymod,Polymod)
HX_DECLARE_CLASS1(polymod,PolymodError)
HX_DECLARE_CLASS2(polymod,backends,PolymodAssetLibrary)
HX_DECLARE_CLASS2(polymod,fs,IFileSystem)

namespace polymod{


class HXCPP_CLASS_ATTRIBUTES Polymod_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef Polymod_obj OBJ_;
		Polymod_obj();

	public:
		enum { _hx_ClassId = 0x4937d120 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="polymod.Polymod")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"polymod.Polymod"); }

		inline static ::hx::ObjectPtr< Polymod_obj > __new() {
			::hx::ObjectPtr< Polymod_obj > __this = new Polymod_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< Polymod_obj > __alloc(::hx::Ctx *_hx_ctx) {
			Polymod_obj *__this = (Polymod_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Polymod_obj), false, "polymod.Polymod"));
			*(void **)__this = Polymod_obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Polymod_obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Polymod",d6,b7,e6,df); }

		static void __boot();
		static  ::Dynamic onError;
		static Dynamic onError_dyn() { return onError;}
		static  ::polymod::backends::PolymodAssetLibrary assetLibrary;
		static  ::Dynamic prevParams;
		static ::Array< ::Dynamic> init( ::Dynamic params);
		static ::Dynamic init_dyn();

		static ::Dynamic getFileSystem();
		static ::Dynamic getFileSystem_dyn();

		static void loadMod(::String modId);
		static ::Dynamic loadMod_dyn();

		static void loadMods(::Array< ::String > modIds);
		static ::Dynamic loadMods_dyn();

		static void unloadMod(::String modId);
		static ::Dynamic unloadMod_dyn();

		static void unloadMods(::Array< ::String > modIds);
		static ::Dynamic unloadMods_dyn();

		static void unloadAllMods();
		static ::Dynamic unloadAllMods_dyn();

		static void disable();
		static ::Dynamic disable_dyn();

		static ::Array< ::String > getDefaultIgnoreList();
		static ::Dynamic getDefaultIgnoreList_dyn();

		static ::Array< ::Dynamic> scan(::String modRoot,::String apiVersionStr, ::Dynamic errorCallback,::Dynamic fileSystem);
		static ::Dynamic scan_dyn();

		static void clearCache();
		static ::Dynamic clearCache_dyn();

		static void error(::String code,::String message,::String origin);
		static ::Dynamic error_dyn();

		static void warning(::String code,::String message,::String origin);
		static ::Dynamic warning_dyn();

		static void notice(::String code,::String message,::String origin);
		static ::Dynamic notice_dyn();

		static void debug(::String message, ::Dynamic posInfo);
		static ::Dynamic debug_dyn();

		static ::Array< ::String > listModFiles(::String type);
		static ::Dynamic listModFiles_dyn();

};

} // end namespace polymod

#endif /* INCLUDED_polymod_Polymod */ 
