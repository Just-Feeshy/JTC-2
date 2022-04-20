#ifndef INCLUDED_hxjsonast_Parser
#define INCLUDED_hxjsonast_Parser

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(hxjsonast,Json)
HX_DECLARE_CLASS1(hxjsonast,JsonValue)
HX_DECLARE_CLASS1(hxjsonast,Parser)
HX_DECLARE_CLASS1(hxjsonast,Position)

namespace hxjsonast{


class HXCPP_CLASS_ATTRIBUTES Parser_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef Parser_obj OBJ_;
		Parser_obj();

	public:
		enum { _hx_ClassId = 0x7f7a3b45 };

		void __construct(::String source,::String filename);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="hxjsonast.Parser")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"hxjsonast.Parser"); }
		static ::hx::ObjectPtr< Parser_obj > __new(::String source,::String filename);
		static ::hx::ObjectPtr< Parser_obj > __alloc(::hx::Ctx *_hx_ctx,::String source,::String filename);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Parser_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Parser",ff,10,1d,22); }

		static  ::hxjsonast::Json parse(::String source,::String filename);
		static ::Dynamic parse_dyn();

		::String source;
		::String filename;
		int pos;
		 ::hxjsonast::Json parseRec();
		::Dynamic parseRec_dyn();

		::String parseString();
		::Dynamic parseString_dyn();

		 ::hxjsonast::Json parseNumber(int c);
		::Dynamic parseNumber_dyn();

		int nextChar();
		::Dynamic nextChar_dyn();

		 ::hxjsonast::Json mk( ::hxjsonast::Position pos, ::hxjsonast::JsonValue value);
		::Dynamic mk_dyn();

		 ::hxjsonast::Position mkPos(int min,int max);
		::Dynamic mkPos_dyn();

		void invalidChar();
		::Dynamic invalidChar_dyn();

		void invalidNumber(int start);
		::Dynamic invalidNumber_dyn();

};

} // end namespace hxjsonast

#endif /* INCLUDED_hxjsonast_Parser */ 
