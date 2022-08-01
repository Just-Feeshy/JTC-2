#ifndef INCLUDED_JsonParser_41
#define INCLUDED_JsonParser_41

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_json2object_reader_BaseParser
#include <json2object/reader/BaseParser.h>
#endif
HX_DECLARE_CLASS0(JsonParser_41)
HX_DECLARE_CLASS1(json2object,Error)
HX_DECLARE_CLASS1(json2object,PositionUtils)
HX_DECLARE_CLASS2(json2object,reader,BaseParser)



class HXCPP_CLASS_ATTRIBUTES JsonParser_41_obj : public  ::json2object::reader::BaseParser_obj
{
	public:
		typedef  ::json2object::reader::BaseParser_obj super;
		typedef JsonParser_41_obj OBJ_;
		JsonParser_41_obj();

	public:
		enum { _hx_ClassId = 0x686c4a11 };

		void __construct(::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="JsonParser_41")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"JsonParser_41"); }
		static ::hx::ObjectPtr< JsonParser_41_obj > __new(::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType);
		static ::hx::ObjectPtr< JsonParser_41_obj > __alloc(::hx::Ctx *_hx_ctx,::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~JsonParser_41_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("JsonParser_41",b5,24,55,bd); }

		void onIncorrectType( ::Dynamic pos,::String variable);

		void loadJsonNumber(::String f, ::Dynamic pos,::String variable);

		Float getAuto();
		::Dynamic getAuto_dyn();

};


#endif /* INCLUDED_JsonParser_41 */ 
