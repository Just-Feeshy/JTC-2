#ifndef INCLUDED__FreeplayState_StupidVibeShader
#define INCLUDED__FreeplayState_StupidVibeShader

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_flixel_graphics_tile_FlxGraphicsShader
#include <flixel/graphics/tile/FlxGraphicsShader.h>
#endif
HX_DECLARE_CLASS1(_FreeplayState,StupidVibeShader)
HX_DECLARE_CLASS3(flixel,graphics,tile,FlxGraphicsShader)
HX_DECLARE_CLASS2(openfl,display,GraphicsShader)
HX_DECLARE_CLASS2(openfl,display,Shader)
HX_DECLARE_CLASS2(openfl,display,ShaderParameter_Float)

namespace _FreeplayState{


class HXCPP_CLASS_ATTRIBUTES StupidVibeShader_obj : public  ::flixel::graphics::tile::FlxGraphicsShader_obj
{
	public:
		typedef  ::flixel::graphics::tile::FlxGraphicsShader_obj super;
		typedef StupidVibeShader_obj OBJ_;
		StupidVibeShader_obj();

	public:
		enum { _hx_ClassId = 0x031b1768 };

		void __construct(Float vibeMeter);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="_FreeplayState.StupidVibeShader")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"_FreeplayState.StupidVibeShader"); }
		static ::hx::ObjectPtr< StupidVibeShader_obj > __new(Float vibeMeter);
		static ::hx::ObjectPtr< StupidVibeShader_obj > __alloc(::hx::Ctx *_hx_ctx,Float vibeMeter);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~StupidVibeShader_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("StupidVibeShader",92,aa,7a,9f); }

		 ::openfl::display::ShaderParameter_Float vibe;
};

} // end namespace _FreeplayState

#endif /* INCLUDED__FreeplayState_StupidVibeShader */ 
