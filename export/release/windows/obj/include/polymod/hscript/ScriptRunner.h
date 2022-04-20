#ifndef INCLUDED_polymod_hscript_ScriptRunner
#define INCLUDED_polymod_hscript_ScriptRunner

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(haxe,IMap)
HX_DECLARE_CLASS2(haxe,ds,StringMap)
HX_DECLARE_CLASS2(polymod,hscript,Script)
HX_DECLARE_CLASS2(polymod,hscript,ScriptRunner)

namespace polymod{
namespace hscript{


class HXCPP_CLASS_ATTRIBUTES ScriptRunner_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef ScriptRunner_obj OBJ_;
		ScriptRunner_obj();

	public:
		enum { _hx_ClassId = 0x540eac1c };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="polymod.hscript.ScriptRunner")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"polymod.hscript.ScriptRunner"); }
		static ::hx::ObjectPtr< ScriptRunner_obj > __new();
		static ::hx::ObjectPtr< ScriptRunner_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~ScriptRunner_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("ScriptRunner",7b,f2,3b,9b); }

		static void __boot();
		static  ::haxe::ds::StringMap scripts;
		static void clearScripts();
		static ::Dynamic clearScripts_dyn();

		static ::String scriptPath(::String pathName);
		static ::Dynamic scriptPath_dyn();

		 ::polymod::hscript::Script load(::String name, ::Dynamic assetHandler);
		::Dynamic load_dyn();

		 ::polymod::hscript::Script get(::String name, ::Dynamic assetHandler);
		::Dynamic get_dyn();

		 ::Dynamic execute(::String name, ::Dynamic assetHandler);
		::Dynamic execute_dyn();

};

} // end namespace polymod
} // end namespace hscript

#endif /* INCLUDED_polymod_hscript_ScriptRunner */ 
