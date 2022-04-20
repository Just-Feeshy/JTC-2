#ifndef INCLUDED_polymod_hscript_PolymodInterpEx
#define INCLUDED_polymod_hscript_PolymodInterpEx

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_hscript_Interp
#include <hscript/Interp.h>
#endif
HX_DECLARE_CLASS1(haxe,IMap)
HX_DECLARE_CLASS2(haxe,ds,StringMap)
HX_DECLARE_CLASS1(hscript,Expr)
HX_DECLARE_CLASS1(hscript,Interp)
HX_DECLARE_CLASS1(hscript,ModuleDecl)
HX_DECLARE_CLASS2(polymod,hscript,PolymodInterpEx)
HX_DECLARE_CLASS2(polymod,hscript,PolymodScriptClass)

namespace polymod{
namespace hscript{


class HXCPP_CLASS_ATTRIBUTES PolymodInterpEx_obj : public  ::hscript::Interp_obj
{
	public:
		typedef  ::hscript::Interp_obj super;
		typedef PolymodInterpEx_obj OBJ_;
		PolymodInterpEx_obj();

	public:
		enum { _hx_ClassId = 0x25369478 };

		void __construct(::hx::Class targetCls, ::polymod::hscript::PolymodScriptClass proxy);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="polymod.hscript.PolymodInterpEx")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"polymod.hscript.PolymodInterpEx"); }
		static ::hx::ObjectPtr< PolymodInterpEx_obj > __new(::hx::Class targetCls, ::polymod::hscript::PolymodScriptClass proxy);
		static ::hx::ObjectPtr< PolymodInterpEx_obj > __alloc(::hx::Ctx *_hx_ctx,::hx::Class targetCls, ::polymod::hscript::PolymodScriptClass proxy);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~PolymodInterpEx_obj();

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
		::String __ToString() const { return HX_("PolymodInterpEx",5d,0d,ed,1f); }

		static void __boot();
		static  ::haxe::ds::StringMap _scriptClassDescriptors;
		static  ::haxe::ds::StringMap _scriptClassOverrides;
		static void registerScriptClass( ::Dynamic c);
		static ::Dynamic registerScriptClass_dyn();

		static  ::Dynamic findScriptClassDescriptor(::String name);
		static ::Dynamic findScriptClassDescriptor_dyn();

		::hx::Class targetCls;
		 ::Dynamic cnew(::String cl,::cpp::VirtualArray args);

		 ::Dynamic fcall( ::Dynamic o,::String f,::cpp::VirtualArray args);

		 ::polymod::hscript::PolymodScriptClass _proxy;
		 ::Dynamic assign( ::hscript::Expr e1, ::hscript::Expr e2);

		 ::Dynamic call( ::Dynamic o, ::Dynamic f,::cpp::VirtualArray args);

		 ::Dynamic get( ::Dynamic o,::String f);

		 ::Dynamic set( ::Dynamic o,::String f, ::Dynamic v);

		 ::Dynamic _nextCallObject;
		 ::Dynamic resolve(::String id);

		void addModule(::String moduleContents);
		::Dynamic addModule_dyn();

		 ::polymod::hscript::PolymodScriptClass createScriptClassInstance(::String className,::cpp::VirtualArray args);
		::Dynamic createScriptClassInstance_dyn();

		void registerModule(::Array< ::Dynamic> module);
		::Dynamic registerModule_dyn();

};

} // end namespace polymod
} // end namespace hscript

#endif /* INCLUDED_polymod_hscript_PolymodInterpEx */ 
