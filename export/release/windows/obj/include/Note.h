#ifndef INCLUDED_Note
#define INCLUDED_Note

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_flixel_FlxSprite
#include <flixel/FlxSprite.h>
#endif
HX_DECLARE_CLASS0(Boyfriend)
HX_DECLARE_CLASS0(Character)
HX_DECLARE_CLASS0(Note)
HX_DECLARE_CLASS0(SplashSprite)
HX_DECLARE_CLASS0(Strum)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS2(flixel,util,FlxAxes)
HX_DECLARE_CLASS2(flixel,util,IFlxDestroyable)
HX_DECLARE_CLASS1(_hx_template,CustomNote)



class HXCPP_CLASS_ATTRIBUTES Note_obj : public  ::flixel::FlxSprite_obj
{
	public:
		typedef  ::flixel::FlxSprite_obj super;
		typedef Note_obj OBJ_;
		Note_obj();

	public:
		enum { _hx_ClassId = 0x08363a36 };

		void __construct(Float strumTime,int noteData, ::Note prevNote, ::Dynamic __o_sustainNote,::String __o_noteType, ::Dynamic ifcircle, ::Dynamic ifPlayState);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="Note")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"Note"); }
		static ::hx::ObjectPtr< Note_obj > __new(Float strumTime,int noteData, ::Note prevNote, ::Dynamic __o_sustainNote,::String __o_noteType, ::Dynamic ifcircle, ::Dynamic ifPlayState);
		static ::hx::ObjectPtr< Note_obj > __alloc(::hx::Ctx *_hx_ctx,Float strumTime,int noteData, ::Note prevNote, ::Dynamic __o_sustainNote,::String __o_noteType, ::Dynamic ifcircle, ::Dynamic ifPlayState);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Note_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Note",12,44,e3,33); }

		static void __boot();
		static Float swagWidth;
		static int PURP_NOTE;
		static int GREEN_NOTE;
		static int BLUE_NOTE;
		static int RED_NOTE;
		static Float AFFECTED_SCROLLSPEED;
		static Float AFFECTED_STRUMTIME;
		 ::Note prevNote;
		bool downscrollNote;
		Float howSpeed;
		Float setupPosition;
		Float strumTime;
		Float swayTime;
		bool mustPress;
		int noteData;
		bool canBeHit;
		bool tooLate;
		bool wasGoodHit;
		Float caculatePos;
		 ::flixel::util::FlxAxes distanceAxis;
		Float sustainLength;
		bool isSustainNote;
		bool wasSustainNote;
		bool ignore;
		Float noteScore;
		::String rating;
		::String noteAbstract;
		 ::flixel::group::FlxTypedGroup trail;
		 ::_hx_template::CustomNote hasCustomAddon;
		bool ifPlayState;
		Float tickDivider;
		bool reverseDebounce;
		void refresh(bool fifth, ::Dynamic findSus);
		::Dynamic refresh_dyn();

		void pressedByPlayer( ::Boyfriend boyfriend, ::Character dad, ::Character girlfriend);
		::Dynamic pressedByPlayer_dyn();

		Float getInverseAxis( ::flixel::util::FlxAxes ax);
		::Dynamic getInverseAxis_dyn();

		void setInverseAxis( ::flixel::util::FlxAxes ax,Float value);
		::Dynamic setInverseAxis_dyn();

		void setNoteAxis( ::flixel::util::FlxAxes ax);
		::Dynamic setNoteAxis_dyn();

		void setNoteAlpha(Float value);
		::Dynamic setNoteAlpha_dyn();

		void setNoteAngle(Float value);
		::Dynamic setNoteAngle_dyn();

		Float getNoteStrumPosition(int offset);
		::Dynamic getNoteStrumPosition_dyn();

		void setVisibility(bool visibility);
		::Dynamic setVisibility_dyn();

		void setXaxis(Float alreadyX);
		::Dynamic setXaxis_dyn();

		void splash( ::SplashSprite splashThing, ::Strum strumNote,::String rating);
		::Dynamic splash_dyn();

		void setupPrefixes();
		::Dynamic setupPrefixes_dyn();

		 ::_hx_template::CustomNote getAddon();
		::Dynamic getAddon_dyn();

		void update(Float elapsed);

		void destroy();

};


#endif /* INCLUDED_Note */ 
