#ifndef INCLUDED_JsonParser_7
#define INCLUDED_JsonParser_7

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_json2object_reader_BaseParser
#include <json2object/reader/BaseParser.h>
#endif
HX_DECLARE_CLASS0(JsonParser_7)
HX_DECLARE_CLASS1(hxjsonast,JObjectField)
HX_DECLARE_CLASS1(json2object,Error)
HX_DECLARE_CLASS1(json2object,PositionUtils)
HX_DECLARE_CLASS2(json2object,reader,BaseParser)



class HXCPP_CLASS_ATTRIBUTES JsonParser_7_obj : public  ::json2object::reader::BaseParser_obj
{
	public:
		typedef  ::json2object::reader::BaseParser_obj super;
		typedef JsonParser_7_obj OBJ_;
		JsonParser_7_obj();

	public:
		enum { _hx_ClassId = 0x194860eb };

		void __construct(::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="JsonParser_7")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"JsonParser_7"); }
		static ::hx::ObjectPtr< JsonParser_7_obj > __new(::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType);
		static ::hx::ObjectPtr< JsonParser_7_obj > __alloc(::hx::Ctx *_hx_ctx,::Array< ::Dynamic> errors, ::json2object::PositionUtils putils, ::Dynamic __o_errorType);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~JsonParser_7_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("JsonParser_7",ff,d7,87,99); }

		void onIncorrectType( ::Dynamic pos,::String variable);

		void loadJsonNull( ::Dynamic pos,::String variable);

		void loadJsonObject(::Array< ::Dynamic> o, ::Dynamic pos,::String variable);

		 ::Dynamic getAuto();
		::Dynamic getAuto_dyn();

};


#endif /* INCLUDED_JsonParser_7 */ 
