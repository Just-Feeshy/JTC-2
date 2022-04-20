#ifndef INCLUDED_CustomKeys
#define INCLUDED_CustomKeys

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_OptionsSubState
#include <OptionsSubState.h>
#endif
HX_DECLARE_CLASS0(Alphabet)
HX_DECLARE_CLASS0(CustomKeys)
HX_DECLARE_CLASS0(MusicBeatSubstate)
HX_DECLARE_CLASS0(OptionsSubState)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS1(flixel,FlxState)
HX_DECLARE_CLASS1(flixel,FlxSubState)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS2(flixel,group,FlxTypedSpriteGroup)
HX_DECLARE_CLASS2(flixel,text,FlxText)
HX_DECLARE_CLASS2(flixel,util,IFlxDestroyable)



class HXCPP_CLASS_ATTRIBUTES CustomKeys_obj : public  ::OptionsSubState_obj
{
	public:
		typedef  ::OptionsSubState_obj super;
		typedef CustomKeys_obj OBJ_;
		CustomKeys_obj();

	public:
		enum { _hx_ClassId = 0x3184f5ed };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="CustomKeys")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"CustomKeys"); }
		static ::hx::ObjectPtr< CustomKeys_obj > __new();
		static ::hx::ObjectPtr< CustomKeys_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~CustomKeys_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("CustomKeys",65,c6,5f,9b); }

		 ::flixel::FlxSprite bgBlack;
		 ::Alphabet keys;
		 ::flixel::text::FlxText howManyKey;
		int section;
		Float colorSway;
		bool changingKeys;
		bool saveryMapArray;
		int changedOnSteam;
		void update(Float elapsed);

		void reloadKeys(::String text);
		::Dynamic reloadKeys_dyn();

};


#endif /* INCLUDED_CustomKeys */ 
