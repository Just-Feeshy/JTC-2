#ifndef INCLUDED_CameraNote
#define INCLUDED_CameraNote

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_betterShit_BetterCams
#include <betterShit/BetterCams.h>
#endif
HX_DECLARE_CLASS0(CameraNote)
HX_DECLARE_CLASS0(WiggleEffect)
HX_DECLARE_CLASS1(betterShit,BetterCams)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxCamera)
HX_DECLARE_CLASS2(flixel,util,IFlxDestroyable)
HX_DECLARE_CLASS2(openfl,filters,BitmapFilter)



class HXCPP_CLASS_ATTRIBUTES CameraNote_obj : public  ::betterShit::BetterCams_obj
{
	public:
		typedef  ::betterShit::BetterCams_obj super;
		typedef CameraNote_obj OBJ_;
		CameraNote_obj();

	public:
		enum { _hx_ClassId = 0x3bfe74df };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="CameraNote")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"CameraNote"); }
		static ::hx::ObjectPtr< CameraNote_obj > __new();
		static ::hx::ObjectPtr< CameraNote_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~CameraNote_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("CameraNote",57,45,d9,a5); }

		 ::flixel::FlxCamera camNoteWOBBLE;
		 ::WiggleEffect noteWiggleFLAG;
		void createNoteCam(::String note);
		::Dynamic createNoteCam_dyn();

		void setFilters(::Array< ::Dynamic> filters);

		void update(Float elapsed);

		void destroy();

};


#endif /* INCLUDED_CameraNote */ 
