#ifndef INCLUDED_polymod_hscript_PolymodScriptClass
#define INCLUDED_polymod_hscript_PolymodScriptClass

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(haxe,IMap)
HX_DECLARE_CLASS2(haxe,ds,StringMap)
HX_DECLARE_CLASS1(hscript,Interp)
HX_DECLARE_CLASS2(polymod,hscript,PolymodInterpEx)
HX_DECLARE_CLASS2(polymod,hscript,PolymodScriptClass)

namespace polymod{
namespace hscript{


class HXCPP_CLASS_ATTRIBUTES PolymodScriptClass_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef PolymodScriptClass_obj OBJ_;
		PolymodScriptClass_obj();

	public:
		enum { _hx_ClassId = 0x5fef6af4 };

		void __construct( ::Dynamic c,::cpp::VirtualArray args);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="polymod.hscript.PolymodScriptClass")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"polymod.hscript.PolymodScriptClass"); }
		static ::hx::ObjectPtr< PolymodScriptClass_obj > __new( ::Dynamic c,::cpp::VirtualArray args);
		static ::hx::ObjectPtr< PolymodScriptClass_obj > __alloc(::hx::Ctx *_hx_ctx, ::Dynamic c,::cpp::VirtualArray args);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~PolymodScriptClass_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("PolymodScriptClass",f7,b5,a6,c3); }

		static void __boot();
		static  ::polymod::hscript::PolymodInterpEx scriptInterp;
		static  ::haxe::ds::StringMap scriptClassOverrides;
		static void registerScriptClassByString(::String body);
		static ::Dynamic registerScriptClassByString_dyn();

		static void registerScriptClassByPath(::String path);
		static ::Dynamic registerScriptClassByPath_dyn();

		static void registerAllScriptClasses();
		static ::Dynamic registerAllScriptClasses_dyn();

		static void clearScriptClasses();
		static ::Dynamic clearScriptClasses_dyn();

		static ::Array< ::String > listScriptClasses();
		static ::Dynamic listScriptClasses_dyn();

		static ::Array< ::String > listScriptClassesExtending(::String clsPath);
		static ::Dynamic listScriptClassesExtending_dyn();

		static ::Array< ::String > listScriptClassesExtendingClass(::hx::Class cls);
		static ::Dynamic listScriptClassesExtendingClass_dyn();

		static ::Array< ::String > getSuperClasses( ::Dynamic classDecl);
		static ::Dynamic getSuperClasses_dyn();

		static  ::polymod::hscript::PolymodScriptClass createScriptClassInstance(::String name,::cpp::VirtualArray args);
		static ::Dynamic createScriptClassInstance_dyn();

		void createSuperClass(::cpp::VirtualArray args);
		::Dynamic createSuperClass_dyn();

		 ::Dynamic callFunction(::String name,::cpp::VirtualArray args);
		::Dynamic callFunction_dyn();

		 ::Dynamic _c;
		 ::polymod::hscript::PolymodInterpEx _interp;
		 ::Dynamic superClass;
		::String className;
		::String get_className();
		::Dynamic get_className_dyn();

		void superConstructor( ::Dynamic arg0, ::Dynamic arg1, ::Dynamic arg2, ::Dynamic arg3);
		::Dynamic superConstructor_dyn();

		 ::Dynamic callFunction0(::String name);
		::Dynamic callFunction0_dyn();

		 ::Dynamic callFunction1(::String name, ::Dynamic arg0);
		::Dynamic callFunction1_dyn();

		 ::Dynamic callFunction2(::String name, ::Dynamic arg0, ::Dynamic arg1);
		::Dynamic callFunction2_dyn();

		 ::Dynamic callFunction3(::String name, ::Dynamic arg0, ::Dynamic arg1, ::Dynamic arg2);
		::Dynamic callFunction3_dyn();

		 ::Dynamic callFunction4(::String name, ::Dynamic arg0, ::Dynamic arg1, ::Dynamic arg2, ::Dynamic arg3);
		::Dynamic callFunction4_dyn();

		 ::Dynamic findFunction(::String name);
		::Dynamic findFunction_dyn();

		 ::Dynamic findVar(::String name);
		::Dynamic findVar_dyn();

		 ::Dynamic findField(::String name);
		::Dynamic findField_dyn();

		 ::haxe::ds::StringMap listFunctions();
		::Dynamic listFunctions_dyn();

		 ::haxe::ds::StringMap _cachedFieldDecls;
		 ::haxe::ds::StringMap _cachedFunctionDecls;
		 ::haxe::ds::StringMap _cachedVarDecls;
		void buildCaches();
		::Dynamic buildCaches_dyn();

};

} // end namespace polymod
} // end namespace hscript

#endif /* INCLUDED_polymod_hscript_PolymodScriptClass */ 
