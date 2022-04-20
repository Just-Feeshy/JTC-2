#ifndef INCLUDED_json2object_PositionUtils
#define INCLUDED_json2object_PositionUtils

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(hxjsonast,Position)
HX_DECLARE_CLASS1(json2object,PositionUtils)

namespace json2object{


class HXCPP_CLASS_ATTRIBUTES PositionUtils_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef PositionUtils_obj OBJ_;
		PositionUtils_obj();

	public:
		enum { _hx_ClassId = 0x44803047 };

		void __construct(::String content);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="json2object.PositionUtils")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"json2object.PositionUtils"); }
		static ::hx::ObjectPtr< PositionUtils_obj > __new(::String content);
		static ::hx::ObjectPtr< PositionUtils_obj > __alloc(::hx::Ctx *_hx_ctx,::String content);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~PositionUtils_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("PositionUtils",a8,c4,cd,5c); }

		::Array< ::Dynamic> linesInfo;
		 ::Dynamic convertPosition( ::hxjsonast::Position position);
		::Dynamic convertPosition_dyn();

		 ::hxjsonast::Position revert( ::Dynamic position);
		::Dynamic revert_dyn();

};

} // end namespace json2object

#endif /* INCLUDED_json2object_PositionUtils */ 
