#ifndef INCLUDED_SplashSprite
#define INCLUDED_SplashSprite

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_flixel_FlxSprite
#include <flixel/FlxSprite.h>
#endif
HX_DECLARE_CLASS0(SplashSprite)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS2(flixel,util,IFlxDestroyable)



class HXCPP_CLASS_ATTRIBUTES SplashSprite_obj : public  ::flixel::FlxSprite_obj
{
	public:
		typedef  ::flixel::FlxSprite_obj super;
		typedef SplashSprite_obj OBJ_;
		SplashSprite_obj();

	public:
		enum { _hx_ClassId = 0x36aff7ac };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="SplashSprite")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"SplashSprite"); }
		static ::hx::ObjectPtr< SplashSprite_obj > __new();
		static ::hx::ObjectPtr< SplashSprite_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~SplashSprite_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("SplashSprite",ec,a4,ce,4d); }

		::String texture;
		 ::Dynamic buildAnim;
		Dynamic buildAnim_dyn() { return buildAnim;}
		::String prevTexture;
		void loadAnims(::String txtr);
		::Dynamic loadAnims_dyn();

		void defaultStrumAnim();
		::Dynamic defaultStrumAnim_dyn();

		::String set_texture(::String value);
		::Dynamic set_texture_dyn();

};


#endif /* INCLUDED_SplashSprite */ 
