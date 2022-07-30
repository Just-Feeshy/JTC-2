#ifndef INCLUDED_JsonParser_32
#define INCLUDED_JsonParser_32

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_json2object_reader_BaseParser
#include <json2object/reader/BaseParser.h>
#endif
HX_DECLARE_CLASS0(JsonParser_32)
HX_DECLARE_CLASS1(json2object,Error)
HX_DECLARE_CLASS1(json2object,PositionUtils)
HX_DECLARE_CLASS2(json2object,reader,BaseParser)



class HXCPP_CLASS_ATTRIBUTES JsonParser_32_obj : public  ::json2object::reader::BaseParser_obj
{
	public:
		typedef  ::json2object::reader::BaseParser_obj super;
		typedef JsonParser_32_obj OBJ_;
		JsonParser_32_obj();

	public:
		enum { _hx_ClassId = 0x686c4933 };

		void __construct(::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="JsonParser_32")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"JsonParser_32"); }
		static ::hx::ObjectPtr< JsonParser_32_obj > __new(::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType);
		static ::hx::ObjectPtr< JsonParser_32_obj > __alloc(::hx::Ctx *_hx_ctx,::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~JsonParser_32_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("JsonParser_32",d7,23,55,bd); }

		void onIncorrectType( ::Dynamic pos,::String variable);

		void loadJsonNumber(::String f, ::Dynamic pos,::String variable);

		Float getAuto();
		::Dynamic getAuto_dyn();

};


#endif /* INCLUDED_JsonParser_32 */ 
