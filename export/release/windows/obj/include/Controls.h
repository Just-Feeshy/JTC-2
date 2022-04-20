#ifndef INCLUDED_Controls
#define INCLUDED_Controls

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_flixel_input_actions_FlxActionSet
#include <flixel/input/actions/FlxActionSet.h>
#endif
HX_DECLARE_CLASS0(Control)
HX_DECLARE_CLASS0(Controls)
HX_DECLARE_CLASS0(Device)
HX_DECLARE_CLASS0(KeyboardScheme)
HX_DECLARE_CLASS3(flixel,input,actions,FlxAction)
HX_DECLARE_CLASS3(flixel,input,actions,FlxActionDigital)
HX_DECLARE_CLASS3(flixel,input,actions,FlxActionInput)
HX_DECLARE_CLASS3(flixel,input,actions,FlxActionSet)
HX_DECLARE_CLASS2(flixel,util,IFlxDestroyable)
HX_DECLARE_CLASS1(haxe,IMap)
HX_DECLARE_CLASS2(haxe,ds,BalancedTree)
HX_DECLARE_CLASS2(haxe,ds,EnumValueMap)
HX_DECLARE_CLASS2(haxe,ds,StringMap)



class HXCPP_CLASS_ATTRIBUTES Controls_obj : public  ::flixel::input::actions::FlxActionSet_obj
{
	public:
		typedef  ::flixel::input::actions::FlxActionSet_obj super;
		typedef Controls_obj OBJ_;
		Controls_obj();

	public:
		enum { _hx_ClassId = 0x6cff3556 };

		void __construct(::String name, ::KeyboardScheme __o_scheme);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="Controls")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"Controls"); }
		static ::hx::ObjectPtr< Controls_obj > __new(::String name, ::KeyboardScheme __o_scheme);
		static ::hx::ObjectPtr< Controls_obj > __alloc(::hx::Ctx *_hx_ctx,::String name, ::KeyboardScheme __o_scheme);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Controls_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Controls",96,42,6e,11); }

		static void init();
		static ::Dynamic init_dyn();

		static void addKeys( ::flixel::input::actions::FlxActionDigital action,::Array< int > keys,int state);
		static ::Dynamic addKeys_dyn();

		static void removeKeys( ::flixel::input::actions::FlxActionDigital action,::Array< int > keys);
		static ::Dynamic removeKeys_dyn();

		static void addButtons( ::flixel::input::actions::FlxActionDigital action,::Array< int > buttons,int state,int id);
		static ::Dynamic addButtons_dyn();

		static void removeButtons( ::flixel::input::actions::FlxActionDigital action,int gamepadID,::Array< int > buttons);
		static ::Dynamic removeButtons_dyn();

		static bool isDevice( ::flixel::input::actions::FlxActionInput input, ::Device device);
		static ::Dynamic isDevice_dyn();

		static bool isGamepad( ::flixel::input::actions::FlxActionInput input,int deviceID);
		static ::Dynamic isGamepad_dyn();

		 ::flixel::input::actions::FlxActionDigital _up;
		 ::flixel::input::actions::FlxActionDigital _left;
		 ::flixel::input::actions::FlxActionDigital _right;
		 ::flixel::input::actions::FlxActionDigital _down;
		 ::flixel::input::actions::FlxActionDigital _space;
		 ::flixel::input::actions::FlxActionDigital _upP;
		 ::flixel::input::actions::FlxActionDigital _leftP;
		 ::flixel::input::actions::FlxActionDigital _rightP;
		 ::flixel::input::actions::FlxActionDigital _downP;
		 ::flixel::input::actions::FlxActionDigital _spaceP;
		 ::flixel::input::actions::FlxActionDigital _upR;
		 ::flixel::input::actions::FlxActionDigital _leftR;
		 ::flixel::input::actions::FlxActionDigital _rightR;
		 ::flixel::input::actions::FlxActionDigital _downR;
		 ::flixel::input::actions::FlxActionDigital _spaceR;
		 ::flixel::input::actions::FlxActionDigital _accept;
		 ::flixel::input::actions::FlxActionDigital _back;
		 ::flixel::input::actions::FlxActionDigital _pause;
		 ::flixel::input::actions::FlxActionDigital _reset;
		 ::flixel::input::actions::FlxActionDigital _cheat;
		 ::haxe::ds::StringMap byName;
		::Array< int > gamepadsAdded;
		 ::KeyboardScheme keyboardScheme;
		bool get_UP();
		::Dynamic get_UP_dyn();

		bool get_LEFT();
		::Dynamic get_LEFT_dyn();

		bool get_RIGHT();
		::Dynamic get_RIGHT_dyn();

		bool get_DOWN();
		::Dynamic get_DOWN_dyn();

		bool get_SPACE();
		::Dynamic get_SPACE_dyn();

		bool get_SPACE_P();
		::Dynamic get_SPACE_P_dyn();

		bool get_UP_P();
		::Dynamic get_UP_P_dyn();

		bool get_LEFT_P();
		::Dynamic get_LEFT_P_dyn();

		bool get_RIGHT_P();
		::Dynamic get_RIGHT_P_dyn();

		bool get_DOWN_P();
		::Dynamic get_DOWN_P_dyn();

		bool get_UP_R();
		::Dynamic get_UP_R_dyn();

		bool get_LEFT_R();
		::Dynamic get_LEFT_R_dyn();

		bool get_RIGHT_R();
		::Dynamic get_RIGHT_R_dyn();

		bool get_DOWN_R();
		::Dynamic get_DOWN_R_dyn();

		bool get_SPACE_R();
		::Dynamic get_SPACE_R_dyn();

		bool get_ACCEPT();
		::Dynamic get_ACCEPT_dyn();

		bool get_BACK();
		::Dynamic get_BACK_dyn();

		bool get_PAUSE();
		::Dynamic get_PAUSE_dyn();

		bool get_RESET();
		::Dynamic get_RESET_dyn();

		bool get_CHEAT();
		::Dynamic get_CHEAT_dyn();

		void update();

		bool checkByName(::String name);
		::Dynamic checkByName_dyn();

		::String getDialogueName( ::flixel::input::actions::FlxActionDigital action);
		::Dynamic getDialogueName_dyn();

		::String getDialogueNameFromToken(::String token);
		::Dynamic getDialogueNameFromToken_dyn();

		 ::flixel::input::actions::FlxActionDigital getActionFromControl( ::Control control);
		::Dynamic getActionFromControl_dyn();

		void forEachBound( ::Control control, ::Dynamic func);
		::Dynamic forEachBound_dyn();

		void replaceBinding( ::Control control, ::Device device, ::Dynamic toAdd, ::Dynamic toRemove);
		::Dynamic replaceBinding_dyn();

		void copyFrom( ::Controls controls, ::Device device);
		::Dynamic copyFrom_dyn();

		void copyTo( ::Controls controls, ::Device device);
		::Dynamic copyTo_dyn();

		void mergeKeyboardScheme( ::KeyboardScheme scheme);
		::Dynamic mergeKeyboardScheme_dyn();

		void bindKeys( ::Control control,::Array< int > keys);
		::Dynamic bindKeys_dyn();

		void unbindKeys( ::Control control,::Array< int > keys);
		::Dynamic unbindKeys_dyn();

		void setKeyboardScheme( ::KeyboardScheme scheme,::hx::Null< bool >  reset);
		::Dynamic setKeyboardScheme_dyn();

		void removeKeyboard();
		::Dynamic removeKeyboard_dyn();

		void addGamepad(int id, ::haxe::ds::EnumValueMap buttonMap);
		::Dynamic addGamepad_dyn();

		void addGamepadLiteral(int id, ::haxe::ds::EnumValueMap buttonMap);
		::Dynamic addGamepadLiteral_dyn();

		void removeGamepad(::hx::Null< int >  deviceID);
		::Dynamic removeGamepad_dyn();

		void addDefaultGamepad(int id);
		::Dynamic addDefaultGamepad_dyn();

		void bindButtons( ::Control control,int id,::Array< int > buttons);
		::Dynamic bindButtons_dyn();

		void unbindButtons( ::Control control,int gamepadID,::Array< int > buttons);
		::Dynamic unbindButtons_dyn();

		::Array< int > getInputsFor( ::Control control, ::Device device,::Array< int > list);
		::Dynamic getInputsFor_dyn();

		void removeDevice( ::Device device);
		::Dynamic removeDevice_dyn();

};


#endif /* INCLUDED_Controls */ 
