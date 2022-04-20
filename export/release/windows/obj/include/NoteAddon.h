#ifndef INCLUDED_NoteAddon
#define INCLUDED_NoteAddon

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Character)
HX_DECLARE_CLASS0(Note)
HX_DECLARE_CLASS0(NoteAddon)
HX_DECLARE_CLASS0(SplashSprite)
HX_DECLARE_CLASS0(Strum)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS2(flixel,util,IFlxDestroyable)



class HXCPP_CLASS_ATTRIBUTES NoteAddon_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef NoteAddon_obj OBJ_;
		NoteAddon_obj();

	public:
		enum { _hx_ClassId = 0x6dae4f6a };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="NoteAddon")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"NoteAddon"); }
		static ::hx::ObjectPtr< NoteAddon_obj > __new();
		static ::hx::ObjectPtr< NoteAddon_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~NoteAddon_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("NoteAddon",0e,08,a4,fb); }

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

		::String getCustomNote();
		::Dynamic getCustomNote_dyn();

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


#endif /* INCLUDED_NoteAddon */ 
