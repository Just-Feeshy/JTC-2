#ifndef INCLUDED_Compile
#define INCLUDED_Compile

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Compile)



class HXCPP_CLASS_ATTRIBUTES Compile_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef Compile_obj OBJ_;
		Compile_obj();

	public:
		enum { _hx_ClassId = 0x10dff293 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="Compile")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"Compile"); }

		inline static ::hx::ObjectPtr< Compile_obj > __new() {
			::hx::ObjectPtr< Compile_obj > __this = new Compile_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< Compile_obj > __alloc(::hx::Ctx *_hx_ctx) {
			Compile_obj *__this = (Compile_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Compile_obj), false, "Compile"));
			*(void **)__this = Compile_obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Compile_obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Compile",53,4d,c0,50); }

		static void __boot();
		static Float strumOffset;
		static int sizeTimer;
		static Float shakeCamTimer;
		static Float shakeCamTimerHUD;
		static Float timeFreeze;
		static ::Array< Float > strumOffsetEvent;
		static ::Array< ::Dynamic> strumOffsetArray;
		static ::Array< Float > camAngle;
		static ::Array< Float > camPos;
		static ::Array< ::String > tempNoteAbstracts;
		static bool preloadAddon;
		static ::Array< ::Dynamic> strumSize;
		static bool jitStrumSize;
		static Float getNoteTime(Float strumTime);
		static ::Dynamic getNoteTime_dyn();

		static ::Array< ::String > getcharacterJSON();
		static ::Dynamic getcharacterJSON_dyn();

		static Float compilePosition(Float strum);
		static ::Dynamic compilePosition_dyn();

		static void spawn();
		static ::Dynamic spawn_dyn();

		static void kill();
		static ::Dynamic kill_dyn();

		static void update();
		static ::Dynamic update_dyn();

		static void eventHandler();
		static ::Dynamic eventHandler_dyn();

		static Float caculateShake(int divider,Float shaker);
		static ::Dynamic caculateShake_dyn();

};


#endif /* INCLUDED_Compile */ 
