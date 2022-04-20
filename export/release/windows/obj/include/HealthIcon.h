#ifndef INCLUDED_HealthIcon
#define INCLUDED_HealthIcon

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_flixel_FlxSprite
#include <flixel/FlxSprite.h>
#endif
HX_DECLARE_CLASS0(HealthIcon)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS2(flixel,util,IFlxDestroyable)



class HXCPP_CLASS_ATTRIBUTES HealthIcon_obj : public  ::flixel::FlxSprite_obj
{
	public:
		typedef  ::flixel::FlxSprite_obj super;
		typedef HealthIcon_obj OBJ_;
		HealthIcon_obj();

	public:
		enum { _hx_ClassId = 0x10bce115 };

		void __construct(::String __o__hx_char,::hx::Null< bool >  __o_isPlayer, ::Dynamic __o_storyBPM, ::Dynamic __o_loadAnims);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="HealthIcon")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"HealthIcon"); }
		static ::hx::ObjectPtr< HealthIcon_obj > __new(::String __o__hx_char,::hx::Null< bool >  __o_isPlayer, ::Dynamic __o_storyBPM, ::Dynamic __o_loadAnims);
		static ::hx::ObjectPtr< HealthIcon_obj > __alloc(::hx::Ctx *_hx_ctx,::String __o__hx_char,::hx::Null< bool >  __o_isPlayer, ::Dynamic __o_storyBPM, ::Dynamic __o_loadAnims);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~HealthIcon_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("HealthIcon",55,be,f9,f8); }

		 ::flixel::FlxSprite sprTracker;
		Float iconSway;
		int BPM;
		::Array< ::String > iconCharacters;
		Float updatePref;
		void loadAllAnims(bool isPlayer);
		::Dynamic loadAllAnims_dyn();

		void createAnim(::String character,::Array< int > iconAnimInfo,::hx::Null< bool >  isPlayer);
		::Dynamic createAnim_dyn();

		 ::Dynamic loadJSON(::String character);
		::Dynamic loadJSON_dyn();

		void update(Float elapsed);

};


#endif /* INCLUDED_HealthIcon */ 
