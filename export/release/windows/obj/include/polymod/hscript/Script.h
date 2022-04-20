#ifndef INCLUDED_polymod_hscript_Script
#define INCLUDED_polymod_hscript_Script

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(hscript,Expr)
HX_DECLARE_CLASS1(hscript,Interp)
HX_DECLARE_CLASS1(hscript,Parser)
HX_DECLARE_CLASS2(polymod,hscript,Script)

namespace polymod{
namespace hscript{


class HXCPP_CLASS_ATTRIBUTES Script_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef Script_obj OBJ_;
		Script_obj();

	public:
		enum { _hx_ClassId = 0x038a9d0c };

		void __construct(::String script);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="polymod.hscript.Script")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"polymod.hscript.Script"); }
		static ::hx::ObjectPtr< Script_obj > __new(::String script);
		static ::hx::ObjectPtr< Script_obj > __alloc(::hx::Ctx *_hx_ctx,::String script);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Script_obj();

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
		::String __ToString() const { return HX_("Script",2b,c2,f4,7b); }

		static  ::hscript::Parser parser;
		static  ::hscript::Parser buildParser();
		static ::Dynamic buildParser_dyn();

		static  ::hscript::Interp buildInterp();
		static ::Dynamic buildInterp_dyn();

		 ::hscript::Expr program;
		 ::hscript::Interp interp;
		void set(::String key, ::Dynamic value);
		::Dynamic set_dyn();

		 ::Dynamic execute();
		::Dynamic execute_dyn();

};

} // end namespace polymod
} // end namespace hscript

#endif /* INCLUDED_polymod_hscript_Script */ 
