#ifndef INCLUDED_OptionsSubState
#define INCLUDED_OptionsSubState

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_MusicBeatSubstate
#include <MusicBeatSubstate.h>
#endif
HX_DECLARE_CLASS0(MusicBeatSubstate)
HX_DECLARE_CLASS0(OptionsSubState)
HX_DECLARE_CLASS0(SaveType)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxState)
HX_DECLARE_CLASS1(flixel,FlxSubState)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS2(flixel,util,IFlxDestroyable)



class HXCPP_CLASS_ATTRIBUTES OptionsSubState_obj : public  ::MusicBeatSubstate_obj
{
	public:
		typedef  ::MusicBeatSubstate_obj super;
		typedef OptionsSubState_obj OBJ_;
		OptionsSubState_obj();

	public:
		enum { _hx_ClassId = 0x27392463 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="OptionsSubState")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"OptionsSubState"); }
		static ::hx::ObjectPtr< OptionsSubState_obj > __new();
		static ::hx::ObjectPtr< OptionsSubState_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~OptionsSubState_obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("OptionsSubState",cf,51,f6,cd); }

		static  ::OptionsSubState newSubState( ::SaveType type);
		static ::Dynamic newSubState_dyn();

};


#endif /* INCLUDED_OptionsSubState */ 
