#ifndef INCLUDED_feshixl_filters_GuassianBlur
#define INCLUDED_feshixl_filters_GuassianBlur

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_flixel_graphics_tile_FlxGraphicsShader
#include <flixel/graphics/tile/FlxGraphicsShader.h>
#endif
HX_DECLARE_CLASS2(feshixl,filters,GuassianBlur)
HX_DECLARE_CLASS3(flixel,graphics,tile,FlxGraphicsShader)
HX_DECLARE_CLASS2(openfl,display,BitmapData)
HX_DECLARE_CLASS2(openfl,display,GraphicsShader)
HX_DECLARE_CLASS2(openfl,display,IBitmapDrawable)
HX_DECLARE_CLASS2(openfl,display,Shader)
HX_DECLARE_CLASS2(openfl,display,ShaderInput_openfl_display_BitmapData)
HX_DECLARE_CLASS2(openfl,display,ShaderParameter_Bool)
HX_DECLARE_CLASS2(openfl,display,ShaderParameter_Float)

namespace feshixl{
namespace filters{


class HXCPP_CLASS_ATTRIBUTES GuassianBlur_obj : public  ::flixel::graphics::tile::FlxGraphicsShader_obj
{
	public:
		typedef  ::flixel::graphics::tile::FlxGraphicsShader_obj super;
		typedef GuassianBlur_obj OBJ_;
		GuassianBlur_obj();

	public:
		enum { _hx_ClassId = 0x51501b88 };

		void __construct(::hx::Null< Float >  __o_sizeValue, ::openfl::display::BitmapData spriteBit);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="feshixl.filters.GuassianBlur")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"feshixl.filters.GuassianBlur"); }
		static ::hx::ObjectPtr< GuassianBlur_obj > __new(::hx::Null< Float >  __o_sizeValue, ::openfl::display::BitmapData spriteBit);
		static ::hx::ObjectPtr< GuassianBlur_obj > __alloc(::hx::Ctx *_hx_ctx,::hx::Null< Float >  __o_sizeValue, ::openfl::display::BitmapData spriteBit);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~GuassianBlur_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("GuassianBlur",0a,3a,03,cb); }

		static void __boot();
		static  ::Dynamic __meta__;
		void setSpriteBitmap( ::openfl::display::BitmapData spriteBit);
		::Dynamic setSpriteBitmap_dyn();

		Float set_size(Float Value);
		::Dynamic set_size_dyn();

		Float get_size();
		::Dynamic get_size_dyn();

		 ::openfl::display::ShaderInput_openfl_display_BitmapData bit;
		 ::openfl::display::ShaderParameter_Float _size;
		 ::openfl::display::ShaderParameter_Bool useExternalBit;
};

} // end namespace feshixl
} // end namespace filters

#endif /* INCLUDED_feshixl_filters_GuassianBlur */ 
