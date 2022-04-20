#ifndef INCLUDED_template_CustomNote
#define INCLUDED_template_CustomNote

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Character)
HX_DECLARE_CLASS0(Note)
HX_DECLARE_CLASS0(SplashSprite)
HX_DECLARE_CLASS0(Strum)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS2(flixel,util,IFlxDestroyable)
HX_DECLARE_CLASS1(_hx_template,CustomNote)

namespace _hx_template{


class HXCPP_CLASS_ATTRIBUTES CustomNote_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef CustomNote_obj OBJ_;
		CustomNote_obj();

	public:
		enum { _hx_ClassId = 0x29d8891d };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="template.CustomNote")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"template.CustomNote"); }
		static ::hx::ObjectPtr< CustomNote_obj > __new();
		static ::hx::ObjectPtr< CustomNote_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~CustomNote_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("CustomNote",63,fc,62,9d); }

		int ID;
		void pressedByPlayer( ::Note note, ::Character player, ::Character opponent, ::Character girlfriend);
		::Dynamic pressedByPlayer_dyn();

		bool useCustomPrefix( ::Note note);
		::Dynamic useCustomPrefix_dyn();

		bool shouldBeIgnored();
		::Dynamic shouldBeIgnored_dyn();

		void createSplashSprite( ::SplashSprite splash, ::Strum strumNote,::String rating);
		::Dynamic createSplashSprite_dyn();

		void whenIsSpawned( ::Note note);
		::Dynamic whenIsSpawned_dyn();

		void whenTiggerSceneActived();
		::Dynamic whenTiggerSceneActived_dyn();

		void trailUpdate( ::Note note);
		::Dynamic trailUpdate_dyn();

		void noteUpdate( ::Note note);
		::Dynamic noteUpdate_dyn();

		bool allowRatingUssage();
		::Dynamic allowRatingUssage_dyn();

		Float setNoteAlpha(Float alpha);
		::Dynamic setNoteAlpha_dyn();

		Float setNoteAngle(Float angle);
		::Dynamic setNoteAngle_dyn();

		Float setXPosition(Float x);
		::Dynamic setXPosition_dyn();

		bool setVisibility(bool staticArrowVisible);
		::Dynamic setVisibility_dyn();

		 ::flixel::group::FlxTypedGroup getTrailGroup();
		::Dynamic getTrailGroup_dyn();

		bool hasOppositeScroll();
		::Dynamic hasOppositeScroll_dyn();

		bool cantHaveHold();
		::Dynamic cantHaveHold_dyn();

		Float getIndividualSpeed();
		::Dynamic getIndividualSpeed_dyn();

		bool playerShouldntHit();
		::Dynamic playerShouldntHit_dyn();

		bool noDefaultSplash();
		::Dynamic noDefaultSplash_dyn();

		Float giveHealth();
		::Dynamic giveHealth_dyn();

		int getWobblePower();
		::Dynamic getWobblePower_dyn();

		int set_ID(int compileID);
		::Dynamic set_ID_dyn();

};

} // end namespace template

#endif /* INCLUDED_template_CustomNote */ 
