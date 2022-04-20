#ifndef INCLUDED_WarningSubGroup
#define INCLUDED_WarningSubGroup

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_flixel_group_FlxTypedSpriteGroup
#include <flixel/group/FlxTypedSpriteGroup.h>
#endif
HX_DECLARE_CLASS0(Controls)
HX_DECLARE_CLASS0(WarningSubGroup)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS2(flixel,group,FlxTypedSpriteGroup)
HX_DECLARE_CLASS3(flixel,input,actions,FlxActionSet)
HX_DECLARE_CLASS2(flixel,text,FlxText)
HX_DECLARE_CLASS2(flixel,util,IFlxDestroyable)



class HXCPP_CLASS_ATTRIBUTES WarningSubGroup_obj : public  ::flixel::group::FlxTypedSpriteGroup_obj
{
	public:
		typedef  ::flixel::group::FlxTypedSpriteGroup_obj super;
		typedef WarningSubGroup_obj OBJ_;
		WarningSubGroup_obj();

	public:
		enum { _hx_ClassId = 0x2282e773 };

		void __construct(::Array< ::String > warn);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="WarningSubGroup")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"WarningSubGroup"); }
		static ::hx::ObjectPtr< WarningSubGroup_obj > __new(::Array< ::String > warn);
		static ::hx::ObjectPtr< WarningSubGroup_obj > __alloc(::hx::Ctx *_hx_ctx,::Array< ::String > warn);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~WarningSubGroup_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("WarningSubGroup",fb,63,49,f8); }

		bool acceptedTermsOfService;
		Float sway;
		Float txtY;
		bool pressedSwitch;
		 ::flixel::text::FlxText warningTxt;
		 ::Controls get_controls();
		::Dynamic get_controls_dyn();

		void update(Float elapsed);

		::String getWarning(::Array< ::String > wrns);
		::Dynamic getWarning_dyn();

};


#endif /* INCLUDED_WarningSubGroup */ 
