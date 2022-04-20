#ifndef INCLUDED_NGio
#define INCLUDED_NGio

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(NGio)
HX_DECLARE_CLASS2(flixel,util,IFlxDestroyable)
HX_DECLARE_CLASS2(flixel,util,IFlxSignal)
HX_DECLARE_CLASS3(flixel,util,_FlxSignal,FlxBaseSignal)
HX_DECLARE_CLASS3(flixel,util,_FlxSignal,FlxSignal0)



class HXCPP_CLASS_ATTRIBUTES NGio_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef NGio_obj OBJ_;
		NGio_obj();

	public:
		enum { _hx_ClassId = 0x0817d683 };

		void __construct(::String api,::String encKey,::String sessionId);
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="NGio")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"NGio"); }
		static ::hx::ObjectPtr< NGio_obj > __new(::String api,::String encKey,::String sessionId);
		static ::hx::ObjectPtr< NGio_obj > __alloc(::hx::Ctx *_hx_ctx,::String api,::String encKey,::String sessionId);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~NGio_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("NGio",5f,e0,c4,33); }

		static void __boot();
		static bool isLoggedIn;
		static bool scoreboardsLoaded;
		static ::Array< ::Dynamic> scoreboardArray;
		static  ::flixel::util::_FlxSignal::FlxSignal0 ngDataLoaded;
		static  ::flixel::util::_FlxSignal::FlxSignal0 ngScoresLoaded;
		static ::String GAME_VER;
		static ::String GAME_VER_NUMS;
		static bool gotOnlineVer;
		static void noLogin(::String api);
		static ::Dynamic noLogin_dyn();

		static void postScore(::hx::Null< int >  score,::String song);
		static ::Dynamic postScore_dyn();

		static void logEvent(::String event);
		static ::Dynamic logEvent_dyn();

		static void unlockMedal(int id);
		static ::Dynamic unlockMedal_dyn();

		void onNGLogin();
		::Dynamic onNGLogin_dyn();

		void onNGMedalFetch();
		::Dynamic onNGMedalFetch_dyn();

		void onNGBoardsFetch();
		::Dynamic onNGBoardsFetch_dyn();

		void onNGScoresFetch();
		::Dynamic onNGScoresFetch_dyn();

};


#endif /* INCLUDED_NGio */ 
