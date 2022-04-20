#ifndef INCLUDED_flixel_graphics_frames_FlxFilterFrames
#define INCLUDED_flixel_graphics_frames_FlxFilterFrames

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_flixel_graphics_frames_FlxFramesCollection
#include <flixel/graphics/frames/FlxFramesCollection.h>
#endif
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS3(flixel,graphics,frames,FlxFilterFrames)
HX_DECLARE_CLASS3(flixel,graphics,frames,FlxFramesCollection)
HX_DECLARE_CLASS2(flixel,util,IFlxDestroyable)
HX_DECLARE_CLASS2(openfl,filters,BitmapFilter)
HX_DECLARE_CLASS2(openfl,geom,Point)
HX_DECLARE_CLASS2(openfl,geom,Rectangle)

namespace flixel{
namespace graphics{
namespace frames{


class HXCPP_CLASS_ATTRIBUTES FlxFilterFrames_obj : public  ::flixel::graphics::frames::FlxFramesCollection_obj
{
	public:
		typedef  ::flixel::graphics::frames::FlxFramesCollection_obj super;
		typedef FlxFilterFrames_obj OBJ_;
		FlxFilterFrames_obj();

	public:
		enum { _hx_ClassId = 0x214f249f };

		void __construct( ::flixel::graphics::frames::FlxFramesCollection sourceFrames,::hx::Null< int >  __o_widthInc,::hx::Null< int >  __o_heightInc,::Array< ::Dynamic> filters);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="flixel.graphics.frames.FlxFilterFrames")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"flixel.graphics.frames.FlxFilterFrames"); }
		static ::hx::ObjectPtr< FlxFilterFrames_obj > __new( ::flixel::graphics::frames::FlxFramesCollection sourceFrames,::hx::Null< int >  __o_widthInc,::hx::Null< int >  __o_heightInc,::Array< ::Dynamic> filters);
		static ::hx::ObjectPtr< FlxFilterFrames_obj > __alloc(::hx::Ctx *_hx_ctx, ::flixel::graphics::frames::FlxFramesCollection sourceFrames,::hx::Null< int >  __o_widthInc,::hx::Null< int >  __o_heightInc,::Array< ::Dynamic> filters);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~FlxFilterFrames_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("FlxFilterFrames",f0,d8,17,11); }

		static void __boot();
		static  ::openfl::geom::Point point;
		static  ::openfl::geom::Rectangle rect;
		static  ::flixel::graphics::frames::FlxFilterFrames fromFrames( ::flixel::graphics::frames::FlxFramesCollection frames,::hx::Null< int >  widthInc,::hx::Null< int >  heightInc,::Array< ::Dynamic> filters);
		static ::Dynamic fromFrames_dyn();

		 ::flixel::graphics::frames::FlxFramesCollection sourceFrames;
		int widthInc;
		int heightInc;
		::Array< ::Dynamic> filters;
		void applyToSprite( ::flixel::FlxSprite spr,::hx::Null< bool >  saveAnimations,::hx::Null< bool >  updateFrames);
		::Dynamic applyToSprite_dyn();

		void genFrames();
		::Dynamic genFrames_dyn();

		void addFilter( ::openfl::filters::BitmapFilter filter);
		::Dynamic addFilter_dyn();

		void removeFilter( ::openfl::filters::BitmapFilter filter);
		::Dynamic removeFilter_dyn();

		void clearFilters();
		::Dynamic clearFilters_dyn();

		void regenAndApplyFilters();
		::Dynamic regenAndApplyFilters_dyn();

		void regenBitmaps(::hx::Null< bool >  fill);
		::Dynamic regenBitmaps_dyn();

		void applyFilter( ::openfl::filters::BitmapFilter filter);
		::Dynamic applyFilter_dyn();

		void applyFilters();
		::Dynamic applyFilters_dyn();

		void destroy();

		::Array< ::Dynamic> set_filters(::Array< ::Dynamic> value);
		::Dynamic set_filters_dyn();

};

} // end namespace flixel
} // end namespace graphics
} // end namespace frames

#endif /* INCLUDED_flixel_graphics_frames_FlxFilterFrames */ 
