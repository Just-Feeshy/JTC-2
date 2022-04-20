#ifndef INCLUDED_json2object_reader_BaseParser
#define INCLUDED_json2object_reader_BaseParser

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(haxe,IMap)
HX_DECLARE_CLASS2(haxe,ds,StringMap)
HX_DECLARE_CLASS1(hxjsonast,JObjectField)
HX_DECLARE_CLASS1(hxjsonast,Json)
HX_DECLARE_CLASS1(json2object,Error)
HX_DECLARE_CLASS1(json2object,PositionUtils)
HX_DECLARE_CLASS2(json2object,reader,BaseParser)

namespace json2object{
namespace reader{


class HXCPP_CLASS_ATTRIBUTES BaseParser_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef BaseParser_obj OBJ_;
		BaseParser_obj();

	public:
		enum { _hx_ClassId = 0x0f6d5b90 };

		void __construct(::Array< ::Dynamic> errors, ::json2object::PositionUtils putils,int errorType);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="json2object.reader.BaseParser")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"json2object.reader.BaseParser"); }
		static ::hx::ObjectPtr< BaseParser_obj > __new(::Array< ::Dynamic> errors, ::json2object::PositionUtils putils,int errorType);
		static ::hx::ObjectPtr< BaseParser_obj > __alloc(::hx::Ctx *_hx_ctx,::Array< ::Dynamic> errors, ::json2object::PositionUtils putils,int errorType);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~BaseParser_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("BaseParser",f0,df,69,bc); }

		 ::Dynamic value;
		::Array< ::Dynamic> errors;
		int errorType;
		 ::json2object::PositionUtils putils;
		 ::Dynamic fromJson(::String jsonString,::String filename);
		::Dynamic fromJson_dyn();

		 ::Dynamic loadJson( ::hxjsonast::Json json,::String variable);
		::Dynamic loadJson_dyn();

		virtual void loadJsonNull( ::Dynamic pos,::String variable);
		::Dynamic loadJsonNull_dyn();

		virtual void loadJsonString(::String s, ::Dynamic pos,::String variable);
		::Dynamic loadJsonString_dyn();

		::String loadString(::String s, ::Dynamic pos,::String variable,::Array< ::String > validValues,::String defaultValue);
		::Dynamic loadString_dyn();

		virtual void loadJsonNumber(::String f, ::Dynamic pos,::String variable);
		::Dynamic loadJsonNumber_dyn();

		int loadJsonUInt(::String f, ::Dynamic pos,::String variable,int value);
		::Dynamic loadJsonUInt_dyn();

		int loadJsonInt(::String f, ::Dynamic pos,::String variable,int value);
		::Dynamic loadJsonInt_dyn();

		Float loadJsonFloat(::String f, ::Dynamic pos,::String variable,Float value);
		::Dynamic loadJsonFloat_dyn();

		virtual void loadJsonBool(bool b, ::Dynamic pos,::String variable);
		::Dynamic loadJsonBool_dyn();

		virtual void loadJsonArray(::Array< ::Dynamic> a, ::Dynamic pos,::String variable);
		::Dynamic loadJsonArray_dyn();

		::cpp::VirtualArray loadJsonArrayValue(::Array< ::Dynamic> a, ::Dynamic loadJsonFn,::String variable);
		::Dynamic loadJsonArrayValue_dyn();

		virtual void loadJsonObject(::Array< ::Dynamic> o, ::Dynamic pos,::String variable);
		::Dynamic loadJsonObject_dyn();

		 ::Dynamic loadObjectField( ::Dynamic loadJsonFn, ::hxjsonast::JObjectField field,::String name, ::haxe::ds::StringMap assigned, ::Dynamic defaultValue, ::Dynamic pos);
		::Dynamic loadObjectField_dyn();

		void loadObjectFieldReflect( ::Dynamic loadJsonFn, ::hxjsonast::JObjectField field,::String name, ::haxe::ds::StringMap assigned, ::Dynamic pos);
		::Dynamic loadObjectFieldReflect_dyn();

		void objectSetupAssign( ::haxe::ds::StringMap assigned,::Array< ::String > keys,::Array< bool > values);
		::Dynamic objectSetupAssign_dyn();

		void objectErrors( ::haxe::ds::StringMap assigned, ::Dynamic pos);
		::Dynamic objectErrors_dyn();

		virtual void onIncorrectType( ::Dynamic pos,::String variable);
		::Dynamic onIncorrectType_dyn();

		void parsingThrow();
		::Dynamic parsingThrow_dyn();

		void objectThrow( ::Dynamic pos,::String variable);
		::Dynamic objectThrow_dyn();

		void mapSet( ::haxe::ds::StringMap map,::String key,bool value);
		::Dynamic mapSet_dyn();

};

} // end namespace json2object
} // end namespace reader

#endif /* INCLUDED_json2object_reader_BaseParser */ 
