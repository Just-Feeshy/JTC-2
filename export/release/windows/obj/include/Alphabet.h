#ifndef INCLUDED_Alphabet
#define INCLUDED_Alphabet

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_flixel_group_FlxTypedSpriteGroup
#include <flixel/group/FlxTypedSpriteGroup.h>
#endif
HX_DECLARE_CLASS0(AlphaCharacter)
HX_DECLARE_CLASS0(Alphabet)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS2(flixel,group,FlxTypedSpriteGroup)
HX_DECLARE_CLASS2(flixel,util,IFlxDestroyable)



class HXCPP_CLASS_ATTRIBUTES Alphabet_obj : public  ::flixel::group::FlxTypedSpriteGroup_obj
{
	public:
		typedef  ::flixel::group::FlxTypedSpriteGroup_obj super;
		typedef Alphabet_obj OBJ_;
		Alphabet_obj();

	public:
		enum { _hx_ClassId = 0x567b2b93 };

		void __construct(Float x,Float y,::String __o_text, ::Dynamic __o_bold,::hx::Null< bool >  __o_typed, ::Dynamic __o_startX);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="Alphabet")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"Alphabet"); }
		static ::hx::ObjectPtr< Alphabet_obj > __new(Float x,Float y,::String __o_text, ::Dynamic __o_bold,::hx::Null< bool >  __o_typed, ::Dynamic __o_startX);
		static ::hx::ObjectPtr< Alphabet_obj > __alloc(::hx::Ctx *_hx_ctx,Float x,Float y,::String __o_text, ::Dynamic __o_bold,::hx::Null< bool >  __o_typed, ::Dynamic __o_startX);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Alphabet_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Alphabet",d3,38,ea,fa); }

		int yMultiplier;
		Float delay;
		bool paused;
		int targetY;
		bool isMenuItem;
		bool isOptionItem;
		Float prevX;
		::String text;
		::String _finalText;
		::String _curText;
		Float widthOfWords;
		Float yMulti;
		int totalSpaces;
		::Array< ::Dynamic> letters;
		 ::AlphaCharacter lastSprite;
		bool xPosResetted;
		bool lastWasSpace;
		::Array< ::String > splitWords;
		bool isBold;
		void addText(Float startX);
		::Dynamic addText_dyn();

		void doSplitWords();
		::Dynamic doSplitWords_dyn();

		::String personTalking;
		void startTypedText(Float startX);
		::Dynamic startTypedText_dyn();

		virtual void update(Float elapsed);

};


#endif /* INCLUDED_Alphabet */ 
