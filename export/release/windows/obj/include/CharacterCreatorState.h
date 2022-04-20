#ifndef INCLUDED_CharacterCreatorState
#define INCLUDED_CharacterCreatorState

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_MusicBeatState
#include <MusicBeatState.h>
#endif
HX_DECLARE_CLASS0(Character)
HX_DECLARE_CLASS0(CharacterCreatorState)
HX_DECLARE_CLASS0(FileType)
HX_DECLARE_CLASS0(HealthIcon)
HX_DECLARE_CLASS0(HelperStates)
HX_DECLARE_CLASS0(JsonParser_28)
HX_DECLARE_CLASS0(MusicBeatState)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxCamera)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS1(flixel,FlxState)
HX_DECLARE_CLASS1(flixel,IFlxBasic)
HX_DECLARE_CLASS1(flixel,IFlxSprite)
HX_DECLARE_CLASS3(flixel,addons,transition,FlxTransitionableState)
HX_DECLARE_CLASS3(flixel,addons,ui,FlxInputText)
HX_DECLARE_CLASS3(flixel,addons,ui,FlxUI)
HX_DECLARE_CLASS3(flixel,addons,ui,FlxUICheckBox)
HX_DECLARE_CLASS3(flixel,addons,ui,FlxUIDropDownMenu)
HX_DECLARE_CLASS3(flixel,addons,ui,FlxUIGroup)
HX_DECLARE_CLASS3(flixel,addons,ui,FlxUIInputText)
HX_DECLARE_CLASS3(flixel,addons,ui,FlxUINumericStepper)
HX_DECLARE_CLASS3(flixel,addons,ui,FlxUIState)
HX_DECLARE_CLASS3(flixel,addons,ui,FlxUITabMenu)
HX_DECLARE_CLASS4(flixel,addons,ui,interfaces,ICursorPointable)
HX_DECLARE_CLASS4(flixel,addons,ui,interfaces,IEventGetter)
HX_DECLARE_CLASS4(flixel,addons,ui,interfaces,IFlxUIClickable)
HX_DECLARE_CLASS4(flixel,addons,ui,interfaces,IFlxUIState)
HX_DECLARE_CLASS4(flixel,addons,ui,interfaces,IFlxUIWidget)
HX_DECLARE_CLASS4(flixel,addons,ui,interfaces,IHasParams)
HX_DECLARE_CLASS4(flixel,addons,ui,interfaces,ILabeled)
HX_DECLARE_CLASS4(flixel,addons,ui,interfaces,IResizable)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS2(flixel,group,FlxTypedSpriteGroup)
HX_DECLARE_CLASS2(flixel,math,FlxPoint)
HX_DECLARE_CLASS2(flixel,text,FlxText)
HX_DECLARE_CLASS2(flixel,ui,FlxBar)
HX_DECLARE_CLASS2(flixel,util,FlxTimer)
HX_DECLARE_CLASS2(flixel,util,IFlxDestroyable)
HX_DECLARE_CLASS2(flixel,util,IFlxPooled)
HX_DECLARE_CLASS1(haxe,IMap)
HX_DECLARE_CLASS2(haxe,ds,StringMap)
HX_DECLARE_CLASS2(json2object,reader,BaseParser)
HX_DECLARE_CLASS2(openfl,events,ErrorEvent)
HX_DECLARE_CLASS2(openfl,events,Event)
HX_DECLARE_CLASS2(openfl,events,EventDispatcher)
HX_DECLARE_CLASS2(openfl,events,IEventDispatcher)
HX_DECLARE_CLASS2(openfl,events,IOErrorEvent)
HX_DECLARE_CLASS2(openfl,events,TextEvent)
HX_DECLARE_CLASS2(openfl,net,FileReference)



class HXCPP_CLASS_ATTRIBUTES CharacterCreatorState_obj : public  ::MusicBeatState_obj
{
	public:
		typedef  ::MusicBeatState_obj super;
		typedef CharacterCreatorState_obj OBJ_;
		CharacterCreatorState_obj();

	public:
		enum { _hx_ClassId = 0x40247e2e };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="CharacterCreatorState")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"CharacterCreatorState"); }
		static ::hx::ObjectPtr< CharacterCreatorState_obj > __new();
		static ::hx::ObjectPtr< CharacterCreatorState_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~CharacterCreatorState_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("CharacterCreatorState",ee,28,e6,ba); }

		bool isIn;
		 ::flixel::addons::ui::FlxUITabMenu UI_thingy;
		 ::flixel::util::FlxTimer startTimer;
		bool keyPress;
		 ::Character shadowEntity;
		 ::Character character;
		 ::flixel::group::FlxTypedGroup characterStorage;
		 ::haxe::ds::StringMap characterAutosave;
		 ::haxe::ds::StringMap mapEditor;
		::Array< ::String > characterJSONs;
		 ::JsonParser_28 parser;
		 ::flixel::ui::FlxBar healthBar;
		 ::flixel::text::FlxText instrucTxt;
		 ::HealthIcon iconP1;
		 ::HealthIcon iconP2;
		Float health;
		int chooseSkin;
		Float colorSway;
		 ::Dynamic _character;
		 ::flixel::FlxCamera camHUD;
		 ::flixel::FlxCamera camGame;
		 ::flixel::FlxObject camFollow;
		 ::flixel::math::FlxPoint camPos;
		bool changeCharacter;
		 ::openfl::net::FileReference _file;
		::Array< ::String > avaiableColors;
		void create();

		void createDisplay();
		::Dynamic createDisplay_dyn();

		 ::flixel::addons::ui::FlxUI tab_group_display;
		 ::flixel::addons::ui::FlxUINumericStepper redMulti;
		 ::flixel::addons::ui::FlxUINumericStepper greenMulti;
		 ::flixel::addons::ui::FlxUINumericStepper blueMulti;
		 ::flixel::addons::ui::FlxUINumericStepper alphaMulti;
		 ::flixel::addons::ui::FlxUINumericStepper redOffset;
		 ::flixel::addons::ui::FlxUINumericStepper greenOffset;
		 ::flixel::addons::ui::FlxUINumericStepper blueOffset;
		 ::flixel::addons::ui::FlxUINumericStepper alphaOffset;
		 ::flixel::addons::ui::FlxUINumericStepper damageColor;
		 ::flixel::addons::ui::FlxUINumericStepper healthColor;
		 ::flixel::addons::ui::FlxUINumericStepper xInput;
		 ::flixel::addons::ui::FlxUINumericStepper yInput;
		 ::flixel::addons::ui::FlxUINumericStepper xCamInput;
		 ::flixel::addons::ui::FlxUINumericStepper yCamInput;
		 ::flixel::addons::ui::FlxUINumericStepper normalIxon;
		 ::flixel::addons::ui::FlxUINumericStepper dedIxon;
		 ::flixel::addons::ui::FlxUINumericStepper hapeyIxon;
		 ::flixel::addons::ui::FlxUIDropDownMenu characterSelector;
		void addDisplayUI();
		::Dynamic addDisplayUI_dyn();

		 ::flixel::addons::ui::FlxUIInputText fileInput;
		 ::flixel::addons::ui::FlxUIDropDownMenu animationDrop;
		 ::flixel::addons::ui::FlxUICheckBox lockAnimCheck;
		 ::flixel::addons::ui::FlxUIInputText prefixInput;
		 ::flixel::addons::ui::FlxUINumericStepper framerateChange;
		 ::flixel::addons::ui::FlxUICheckBox loopAnim;
		 ::flixel::addons::ui::FlxUINumericStepper offsetXInput;
		 ::flixel::addons::ui::FlxUINumericStepper offsetYInput;
		 ::flixel::addons::ui::FlxUICheckBox checkPlayable;
		 ::flixel::addons::ui::FlxUICheckBox canBePixel;
		 ::flixel::text::FlxText warningIndex;
		bool playCustomAnim;
		void addAnimationsUI();
		::Dynamic addAnimationsUI_dyn();

		void addExportUI();
		::Dynamic addExportUI_dyn();

		void updateStuff();
		::Dynamic updateStuff_dyn();

		void getEvent(::String id, ::Dynamic sender, ::Dynamic data,::cpp::VirtualArray params);

		void update(Float elapsed);

		void saveFile( ::FileType fileType);
		::Dynamic saveFile_dyn();

		void exploreFile();
		::Dynamic exploreFile_dyn();

		void onSaveComplete( ::openfl::events::Event _);
		::Dynamic onSaveComplete_dyn();

		void onCancel( ::openfl::events::Event _);
		::Dynamic onCancel_dyn();

		void onSaveError( ::openfl::events::IOErrorEvent _);
		::Dynamic onSaveError_dyn();

		void onSelect( ::openfl::events::Event E);
		::Dynamic onSelect_dyn();

};


#endif /* INCLUDED_CharacterCreatorState */ 
