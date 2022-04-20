#ifndef INCLUDED_betterShit_BetterCams
#define INCLUDED_betterShit_BetterCams

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_flixel_FlxCamera
#include <flixel/FlxCamera.h>
#endif
HX_DECLARE_CLASS1(betterShit,BetterCams)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxCamera)
HX_DECLARE_CLASS2(flixel,util,IFlxDestroyable)
HX_DECLARE_CLASS2(openfl,filters,BitmapFilter)

namespace betterShit{


class HXCPP_CLASS_ATTRIBUTES BetterCams_obj : public  ::flixel::FlxCamera_obj
{
	public:
		typedef  ::flixel::FlxCamera_obj super;
		typedef BetterCams_obj OBJ_;
		BetterCams_obj();

	public:
		enum { _hx_ClassId = 0x79a9d584 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="betterShit.BetterCams")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"betterShit.BetterCams"); }
		static ::hx::ObjectPtr< BetterCams_obj > __new();
		static ::hx::ObjectPtr< BetterCams_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~BetterCams_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("BetterCams",f4,b2,53,c1); }

		::Array< ::Dynamic> lockedFilters;
		bool betterFiltersEnabled;
		Float engineX;
		Float engineY;
		Float engineAngle;
		void lockFilter( ::openfl::filters::BitmapFilter filters);
		::Dynamic lockFilter_dyn();

		void eraseFilters();
		::Dynamic eraseFilters_dyn();

		::Array< ::Dynamic> get_getFilters();
		::Dynamic get_getFilters_dyn();

		Float set_engineX(Float x);
		::Dynamic set_engineX_dyn();

		Float set_engineY(Float y);
		::Dynamic set_engineY_dyn();

		Float set_engineAngle(Float Angle);
		::Dynamic set_engineAngle_dyn();

		Float set_angle(Float Angle);

		virtual void update(Float elapsed);

		virtual void destroy();

		void updateFlashSpritePosition();

};

} // end namespace betterShit

#endif /* INCLUDED_betterShit_BetterCams */ 
