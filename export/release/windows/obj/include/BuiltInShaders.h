#ifndef INCLUDED_BuiltInShaders
#define INCLUDED_BuiltInShaders

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_flixel_graphics_tile_FlxGraphicsShader
#include <flixel/graphics/tile/FlxGraphicsShader.h>
#endif
HX_DECLARE_CLASS0(BuiltInShaders)
HX_DECLARE_CLASS0(ShaderType)
HX_DECLARE_CLASS3(flixel,graphics,tile,FlxGraphicsShader)
HX_DECLARE_CLASS2(openfl,display,BitmapData)
HX_DECLARE_CLASS2(openfl,display,GraphicsShader)
HX_DECLARE_CLASS2(openfl,display,IBitmapDrawable)
HX_DECLARE_CLASS2(openfl,display,Shader)
HX_DECLARE_CLASS2(openfl,display,ShaderInput_openfl_display_BitmapData)
HX_DECLARE_CLASS2(openfl,display,ShaderParameter_Bool)
HX_DECLARE_CLASS2(openfl,display,ShaderParameter_Float)
HX_DECLARE_CLASS2(openfl,display,ShaderParameter_Int)



class HXCPP_CLASS_ATTRIBUTES BuiltInShaders_obj : public  ::flixel::graphics::tile::FlxGraphicsShader_obj
{
	public:
		typedef  ::flixel::graphics::tile::FlxGraphicsShader_obj super;
		typedef BuiltInShaders_obj OBJ_;
		BuiltInShaders_obj();

	public:
		enum { _hx_ClassId = 0x5207880b };

		void __construct( ::openfl::display::BitmapData spriteBit);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="BuiltInShaders")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"BuiltInShaders"); }
		static ::hx::ObjectPtr< BuiltInShaders_obj > __new( ::openfl::display::BitmapData spriteBit);
		static ::hx::ObjectPtr< BuiltInShaders_obj > __alloc(::hx::Ctx *_hx_ctx, ::openfl::display::BitmapData spriteBit);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~BuiltInShaders_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("BuiltInShaders",4b,05,1c,70); }

		 ::ShaderType shader;
		Float position;
		 ::ShaderType set_shader( ::ShaderType v);
		::Dynamic set_shader_dyn();

		Float set_position(Float v);
		::Dynamic set_position_dyn();

		 ::openfl::display::BitmapData updateBitmap( ::openfl::display::BitmapData v);
		::Dynamic updateBitmap_dyn();

		 ::openfl::display::ShaderInput_openfl_display_BitmapData bit;
		 ::openfl::display::ShaderParameter_Float shaderValue;
		 ::openfl::display::ShaderParameter_Bool useExternalBit;
		 ::openfl::display::ShaderParameter_Int shad;
};


#endif /* INCLUDED_BuiltInShaders */ 
