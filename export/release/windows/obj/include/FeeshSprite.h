#ifndef INCLUDED_FeeshSprite
#define INCLUDED_FeeshSprite

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_flixel_FlxSprite
#include <flixel/FlxSprite.h>
#endif
HX_DECLARE_CLASS0(FeeshSprite)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS2(flixel,util,IFlxDestroyable)



class HXCPP_CLASS_ATTRIBUTES FeeshSprite_obj : public  ::flixel::FlxSprite_obj
{
	public:
		typedef  ::flixel::FlxSprite_obj super;
		typedef FeeshSprite_obj OBJ_;
		FeeshSprite_obj();

	public:
		enum { _hx_ClassId = 0x0a05cef8 };

		void __construct(Float x,Float y,::String __o_ab, ::Dynamic __o_secondSprite);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="FeeshSprite")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"FeeshSprite"); }
		static ::hx::ObjectPtr< FeeshSprite_obj > __new(Float x,Float y,::String __o_ab, ::Dynamic __o_secondSprite);
		static ::hx::ObjectPtr< FeeshSprite_obj > __alloc(::hx::Ctx *_hx_ctx,Float x,Float y,::String __o_ab, ::Dynamic __o_secondSprite);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~FeeshSprite_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("FeeshSprite",a0,de,fc,e1); }

		::String curAbstract;
		void update(Float elapsed);

};


#endif /* INCLUDED_FeeshSprite */ 
