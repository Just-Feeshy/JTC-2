#ifndef INCLUDED_hscript_Printer
#define INCLUDED_hscript_Printer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(StringBuf)
HX_DECLARE_CLASS1(hscript,CType)
HX_DECLARE_CLASS1(hscript,Error)
HX_DECLARE_CLASS1(hscript,Expr)
HX_DECLARE_CLASS1(hscript,Printer)

namespace hscript{


class HXCPP_CLASS_ATTRIBUTES Printer_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef Printer_obj OBJ_;
		Printer_obj();

	public:
		enum { _hx_ClassId = 0x7ec3df13 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="hscript.Printer")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"hscript.Printer"); }
		static ::hx::ObjectPtr< Printer_obj > __new();
		static ::hx::ObjectPtr< Printer_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Printer_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Printer",ba,fd,84,51); }

		static ::String toString( ::hscript::Expr e);
		static ::Dynamic toString_dyn();

		static ::String errorToString( ::hscript::Error e);
		static ::Dynamic errorToString_dyn();

		 ::StringBuf buf;
		::String tabs;
		::String exprToString( ::hscript::Expr e);
		::Dynamic exprToString_dyn();

		::String typeToString( ::hscript::CType t);
		::Dynamic typeToString_dyn();

		void add( ::Dynamic s);
		::Dynamic add_dyn();

		void type( ::hscript::CType t);
		::Dynamic type_dyn();

		void addType( ::hscript::CType t);
		::Dynamic addType_dyn();

		void expr( ::hscript::Expr e);
		::Dynamic expr_dyn();

};

} // end namespace hscript

#endif /* INCLUDED_hscript_Printer */ 
