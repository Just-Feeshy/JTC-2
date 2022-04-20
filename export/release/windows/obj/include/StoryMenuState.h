#ifndef INCLUDED_StoryMenuState
#define INCLUDED_StoryMenuState

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_MusicBeatState
#include <MusicBeatState.h>
#endif
HX_DECLARE_CLASS0(HelperStates)
HX_DECLARE_CLASS0(MenuBackground)
HX_DECLARE_CLASS0(MusicBeatState)
HX_DECLARE_CLASS0(StoryMenuState)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS1(flixel,FlxState)
HX_DECLARE_CLASS3(flixel,addons,display,FlxBackdrop)
HX_DECLARE_CLASS3(flixel,addons,transition,FlxTransitionableState)
HX_DECLARE_CLASS3(flixel,addons,ui,FlxUIState)
HX_DECLARE_CLASS4(flixel,addons,ui,interfaces,IEventGetter)
HX_DECLARE_CLASS4(flixel,addons,ui,interfaces,IFlxUIState)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS2(flixel,group,FlxTypedSpriteGroup)
HX_DECLARE_CLASS2(flixel,text,FlxText)
HX_DECLARE_CLASS2(flixel,util,IFlxDestroyable)



class HXCPP_CLASS_ATTRIBUTES StoryMenuState_obj : public  ::MusicBeatState_obj
{
	public:
		typedef  ::MusicBeatState_obj super;
		typedef StoryMenuState_obj OBJ_;
		StoryMenuState_obj();

	public:
		enum { _hx_ClassId = 0x244c1c1d };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="StoryMenuState")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"StoryMenuState"); }
		static ::hx::ObjectPtr< StoryMenuState_obj > __new();
		static ::hx::ObjectPtr< StoryMenuState_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~StoryMenuState_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("StoryMenuState",5d,99,60,42); }

		 ::flixel::text::FlxText scoreText;
		int curDifficulty;
		bool chooseDifficulty;
		 ::flixel::text::FlxText txtWeekTitle;
		int curWeek;
		 ::flixel::text::FlxText txtTracklist;
		 ::flixel::group::FlxTypedGroup grpWeekText;
		 ::flixel::group::FlxTypedGroup grpLocks;
		 ::MenuBackground menuBG;
		 ::flixel::addons::display::FlxBackdrop extraStuff;
		 ::flixel::group::FlxTypedGroup difficultySelectors;
		 ::flixel::FlxSprite sprDifficulty;
		 ::flixel::FlxSprite leftArrow;
		 ::flixel::FlxSprite rightArrow;
		void create();

		bool movedBack;
		bool selectedWeek;
		bool stopspamming;
		void update(Float elapsed);

		void selectWeek();
		::Dynamic selectWeek_dyn();

		void changeDifficulty(::hx::Null< int >  change);
		::Dynamic changeDifficulty_dyn();

		int lerpScore;
		int intendedScore;
		Float weekAlpha;
		void changeWeek(::hx::Null< int >  change);
		::Dynamic changeWeek_dyn();

		void updateText();
		::Dynamic updateText_dyn();

};


#endif /* INCLUDED_StoryMenuState */ 
