#ifndef INCLUDED_polymod_hscript_PolymodParserEx
#define INCLUDED_polymod_hscript_PolymodParserEx

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_hscript_Parser
#include <hscript/Parser.h>
#endif
HX_DECLARE_CLASS1(hscript,ModuleDecl)
HX_DECLARE_CLASS1(hscript,Parser)
HX_DECLARE_CLASS2(polymod,hscript,PolymodParserEx)

namespace polymod{
namespace hscript{


class HXCPP_CLASS_ATTRIBUTES PolymodParserEx_obj : public  ::hscript::Parser_obj
{
	public:
		typedef  ::hscript::Parser_obj super;
		typedef PolymodParserEx_obj OBJ_;
		PolymodParserEx_obj();

	public:
		enum { _hx_ClassId = 0x5b61440b };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="polymod.hscript.PolymodParserEx")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"polymod.hscript.PolymodParserEx"); }
		static ::hx::ObjectPtr< PolymodParserEx_obj > __new();
		static ::hx::ObjectPtr< PolymodParserEx_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~PolymodParserEx_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("PolymodParserEx",28,49,06,ce); }

		::Array< ::Dynamic> parseModule(::String content,::String origin);

};

} // end namespace polymod
} // end namespace hscript

#endif /* INCLUDED_polymod_hscript_PolymodParserEx */ 
