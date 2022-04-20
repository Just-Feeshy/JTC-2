#ifndef INCLUDED_Register
#define INCLUDED_Register

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(ClassType)
HX_DECLARE_CLASS0(ModLua)
HX_DECLARE_CLASS0(Register)
HX_DECLARE_CLASS2(feshixl,group,FeshEventGroup)
HX_DECLARE_CLASS2(feshixl,group,IFeshEvent)
HX_DECLARE_CLASS2(flixel,util,IFlxDestroyable)



class HXCPP_CLASS_ATTRIBUTES Register_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef Register_obj OBJ_;
		Register_obj();

	public:
		enum { _hx_ClassId = 0x05e25543 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="Register")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"Register"); }

		inline static ::hx::ObjectPtr< Register_obj > __new() {
			::hx::ObjectPtr< Register_obj > __this = new Register_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< Register_obj > __alloc(::hx::Ctx *_hx_ctx) {
			Register_obj *__this = (Register_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Register_obj), false, "Register"));
			*(void **)__this = Register_obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Register_obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Register",83,62,51,aa); }

		static void __boot();
		static ::String get_regJSON();
		static ::Dynamic get_regJSON_dyn();

		static  ::feshixl::group::FeshEventGroup events;
		static void setup();
		static ::Dynamic setup_dyn();

		static void attachLuaToState(::hx::Class state, ::ModLua luaClass);
		static ::Dynamic attachLuaToState_dyn();

		static void add( ::ClassType addonType, ::Dynamic addonClass);
		static ::Dynamic add_dyn();

		static int getWeekFromSong(::String song);
		static ::Dynamic getWeekFromSong_dyn();

		static  ::Dynamic forNameClass(::String type,::cpp::VirtualArray args);
		static ::Dynamic forNameClass_dyn();

		static  ::Dynamic getFlxEaseByString(::String ease);
		static ::Dynamic getFlxEaseByString_dyn();

};


#endif /* INCLUDED_Register */ 
