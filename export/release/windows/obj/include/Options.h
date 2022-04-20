#ifndef INCLUDED_Options
#define INCLUDED_Options

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_Alphabet
#include <Alphabet.h>
#endif
HX_DECLARE_CLASS0(Alphabet)
HX_DECLARE_CLASS0(MusicBeatSubstate)
HX_DECLARE_CLASS0(Options)
HX_DECLARE_CLASS0(OptionsSubState)
HX_DECLARE_CLASS0(SaveType)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS1(flixel,FlxState)
HX_DECLARE_CLASS1(flixel,FlxSubState)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS2(flixel,group,FlxTypedSpriteGroup)
HX_DECLARE_CLASS2(flixel,util,IFlxDestroyable)



class HXCPP_CLASS_ATTRIBUTES Options_obj : public  ::Alphabet_obj
{
	public:
		typedef  ::Alphabet_obj super;
		typedef Options_obj OBJ_;
		Options_obj();

	public:
		enum { _hx_ClassId = 0x6d6f007e };

		void __construct(Float x,Float y,::String __o_text, ::SaveType saveType, ::Dynamic Callback);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="Options")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"Options"); }
		static ::hx::ObjectPtr< Options_obj > __new(Float x,Float y,::String __o_text, ::SaveType saveType, ::Dynamic Callback);
		static ::hx::ObjectPtr< Options_obj > __alloc(::hx::Ctx *_hx_ctx,Float x,Float y,::String __o_text, ::SaveType saveType, ::Dynamic Callback);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Options_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Options",3e,5b,4f,ad); }

		 ::flixel::FlxSprite optionIcon;
		bool optionTitle;
		 ::OptionsSubState optionSubState;
		 ::SaveType saveType;
		 ::Dynamic callback;
		Dynamic callback_dyn() { return callback;}
		bool set_optionTitle(bool value);
		::Dynamic set_optionTitle_dyn();

		void update(Float elapsed);

		void destroy();

};


#endif /* INCLUDED_Options */ 
