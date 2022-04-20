#ifndef INCLUDED_Strum
#define INCLUDED_Strum

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_flixel_FlxSprite
#include <flixel/FlxSprite.h>
#endif
HX_DECLARE_CLASS0(Strum)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS2(flixel,util,FlxAxes)
HX_DECLARE_CLASS2(flixel,util,IFlxDestroyable)



class HXCPP_CLASS_ATTRIBUTES Strum_obj : public  ::flixel::FlxSprite_obj
{
	public:
		typedef  ::flixel::FlxSprite_obj super;
		typedef Strum_obj OBJ_;
		Strum_obj();

	public:
		enum { _hx_ClassId = 0x0b8a3685 };

		void __construct(Float x,Float y);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="Strum")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"Strum"); }
		static ::hx::ObjectPtr< Strum_obj > __new(Float x,Float y);
		static ::hx::ObjectPtr< Strum_obj > __alloc(::hx::Ctx *_hx_ctx,Float x,Float y);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Strum_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Strum",29,cd,45,17); }

		::String ifCustom;
		bool ifOpponent;
		Float onlyFans;
		bool xAxis;
		bool prevVisible;
		bool onlyVisible;
		bool setVisibility(bool visibility);
		::Dynamic setVisibility_dyn();

		Float getInverseAxis( ::flixel::util::FlxAxes ax);
		::Dynamic getInverseAxis_dyn();

		Float getRegularAxis( ::flixel::util::FlxAxes ax);
		::Dynamic getRegularAxis_dyn();

		void update(Float elapsed);

};


#endif /* INCLUDED_Strum */ 
