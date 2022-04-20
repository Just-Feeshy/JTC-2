#ifndef INCLUDED_GhostTapping
#define INCLUDED_GhostTapping

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_Options
#include <Options.h>
#endif
HX_DECLARE_CLASS0(Alphabet)
HX_DECLARE_CLASS0(GhostTapping)
HX_DECLARE_CLASS0(Options)
HX_DECLARE_CLASS0(SaveType)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS2(flixel,group,FlxTypedSpriteGroup)
HX_DECLARE_CLASS2(flixel,util,IFlxDestroyable)



class HXCPP_CLASS_ATTRIBUTES GhostTapping_obj : public  ::Options_obj
{
	public:
		typedef  ::Options_obj super;
		typedef GhostTapping_obj OBJ_;
		GhostTapping_obj();

	public:
		enum { _hx_ClassId = 0x2662d86e };

		void __construct(Float x,Float y,::String __o_text, ::SaveType saveType, ::Dynamic Callback);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="GhostTapping")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"GhostTapping"); }
		static ::hx::ObjectPtr< GhostTapping_obj > __new(Float x,Float y,::String __o_text, ::SaveType saveType, ::Dynamic Callback);
		static ::hx::ObjectPtr< GhostTapping_obj > __alloc(::hx::Ctx *_hx_ctx,Float x,Float y,::String __o_text, ::SaveType saveType, ::Dynamic Callback);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~GhostTapping_obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("GhostTapping",e6,b6,ec,d8); }

		static Float get_consequence();
		static ::Dynamic get_consequence_dyn();

		static bool get_ghostTap();
		static ::Dynamic get_ghostTap_dyn();

};


#endif /* INCLUDED_GhostTapping */ 
