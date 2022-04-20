#include <hxcpp.h>

#ifndef INCLUDED_Control
#include <Control.h>
#endif
#ifndef INCLUDED_Controls
#include <Controls.h>
#endif
#ifndef INCLUDED_Device
#include <Device.h>
#endif
#ifndef INCLUDED_KeyboardScheme
#include <KeyboardScheme.h>
#endif
#ifndef INCLUDED_SaveType
#include <SaveType.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_input_IFlxInputManager
#include <flixel/input/IFlxInputManager.h>
#endif
#ifndef INCLUDED_flixel_input_actions_FlxAction
#include <flixel/input/actions/FlxAction.h>
#endif
#ifndef INCLUDED_flixel_input_actions_FlxActionAnalog
#include <flixel/input/actions/FlxActionAnalog.h>
#endif
#ifndef INCLUDED_flixel_input_actions_FlxActionDigital
#include <flixel/input/actions/FlxActionDigital.h>
#endif
#ifndef INCLUDED_flixel_input_actions_FlxActionInput
#include <flixel/input/actions/FlxActionInput.h>
#endif
#ifndef INCLUDED_flixel_input_actions_FlxActionInputDigital
#include <flixel/input/actions/FlxActionInputDigital.h>
#endif
#ifndef INCLUDED_flixel_input_actions_FlxActionManager
#include <flixel/input/actions/FlxActionManager.h>
#endif
#ifndef INCLUDED_flixel_input_actions_FlxActionSet
#include <flixel/input/actions/FlxActionSet.h>
#endif
#ifndef INCLUDED_flixel_input_actions_FlxInputDevice
#include <flixel/input/actions/FlxInputDevice.h>
#endif
#ifndef INCLUDED_flixel_input_gamepad__FlxGamepadInputID_FlxGamepadInputID_Impl_
#include <flixel/input/gamepad/_FlxGamepadInputID/FlxGamepadInputID_Impl_.h>
#endif
#ifndef INCLUDED_flixel_input_keyboard__FlxKey_FlxKey_Impl_
#include <flixel/input/keyboard/_FlxKey/FlxKey_Impl_.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_InputFrontEnd
#include <flixel/system/frontEnds/InputFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_util_FlxSave
#include <flixel/util/FlxSave.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxDestroyable
#include <flixel/util/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_haxe_Exception
#include <haxe/Exception.h>
#endif
#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_BalancedTree
#include <haxe/ds/BalancedTree.h>
#endif
#ifndef INCLUDED_haxe_ds_EnumValueMap
#include <haxe/ds/EnumValueMap.h>
#endif
#ifndef INCLUDED_haxe_ds_IntMap
#include <haxe/ds/IntMap.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_948b5caa279cd923_102_new,"Controls","new",0x4f8de688,"Controls.new","Controls.hx",102,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_137_get_UP,"Controls","get_UP",0xb958147c,"Controls.get_UP","Controls.hx",137,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_142_get_LEFT,"Controls","get_LEFT",0xc8e82468,"Controls.get_LEFT","Controls.hx",142,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_147_get_RIGHT,"Controls","get_RIGHT",0x7944c43b,"Controls.get_RIGHT","Controls.hx",147,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_152_get_DOWN,"Controls","get_DOWN",0xc3a614c3,"Controls.get_DOWN","Controls.hx",152,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_157_get_SPACE,"Controls","get_SPACE",0x11474525,"Controls.get_SPACE","Controls.hx",157,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_162_get_SPACE_P,"Controls","get_SPACE_P",0x657eeb76,"Controls.get_SPACE_P","Controls.hx",162,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_167_get_UP_P,"Controls","get_UP_P",0xcee37e8d,"Controls.get_UP_P","Controls.hx",167,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_172_get_LEFT_P,"Controls","get_LEFT_P",0xee886179,"Controls.get_LEFT_P","Controls.hx",172,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_177_get_RIGHT_P,"Controls","get_RIGHT_P",0xe72adc0c,"Controls.get_RIGHT_P","Controls.hx",177,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_182_get_DOWN_P,"Controls","get_DOWN_P",0x88e75e94,"Controls.get_DOWN_P","Controls.hx",182,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_187_get_UP_R,"Controls","get_UP_R",0xcee37e8f,"Controls.get_UP_R","Controls.hx",187,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_192_get_LEFT_R,"Controls","get_LEFT_R",0xee88617b,"Controls.get_LEFT_R","Controls.hx",192,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_197_get_RIGHT_R,"Controls","get_RIGHT_R",0xe72adc0e,"Controls.get_RIGHT_R","Controls.hx",197,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_202_get_DOWN_R,"Controls","get_DOWN_R",0x88e75e96,"Controls.get_DOWN_R","Controls.hx",202,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_207_get_SPACE_R,"Controls","get_SPACE_R",0x657eeb78,"Controls.get_SPACE_R","Controls.hx",207,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_212_get_ACCEPT,"Controls","get_ACCEPT",0x5fc72da9,"Controls.get_ACCEPT","Controls.hx",212,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_217_get_BACK,"Controls","get_BACK",0xc248f688,"Controls.get_BACK","Controls.hx",217,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_222_get_PAUSE,"Controls","get_PAUSE",0x4d388f55,"Controls.get_PAUSE","Controls.hx",222,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_227_get_RESET,"Controls","get_RESET",0x76a9022e,"Controls.get_RESET","Controls.hx",227,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_232_get_CHEAT,"Controls","get_CHEAT",0xd5974f72,"Controls.get_CHEAT","Controls.hx",232,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_302_update,"Controls","update",0x9d2db8e1,"Controls.update","Controls.hx",302,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_312_checkByName,"Controls","checkByName",0xbe587cd2,"Controls.checkByName","Controls.hx",312,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_316_getDialogueName,"Controls","getDialogueName",0xe1263f61,"Controls.getDialogueName","Controls.hx",316,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_328_getDialogueNameFromToken,"Controls","getDialogueNameFromToken",0x6458998e,"Controls.getDialogueNameFromToken","Controls.hx",328,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_333_getActionFromControl,"Controls","getActionFromControl",0xa2e9ae5f,"Controls.getActionFromControl","Controls.hx",333,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_362_forEachBound,"Controls","forEachBound",0x9a98930c,"Controls.forEachBound","Controls.hx",362,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_398_replaceBinding,"Controls","replaceBinding",0x45096449,"Controls.replaceBinding","Controls.hx",398,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_419_copyFrom,"Controls","copyFrom",0xdf1da497,"Controls.copyFrom","Controls.hx",419,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_466_copyTo,"Controls","copyTo",0xdf5b4f68,"Controls.copyTo","Controls.hx",466,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_471_mergeKeyboardScheme,"Controls","mergeKeyboardScheme",0x61e2372c,"Controls.mergeKeyboardScheme","Controls.hx",471,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_490_bindKeys,"Controls","bindKeys",0xcb8dbf29,"Controls.bindKeys","Controls.hx",490,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_503_unbindKeys,"Controls","unbindKeys",0xec4b8c82,"Controls.unbindKeys","Controls.hx",503,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_527_setKeyboardScheme,"Controls","setKeyboardScheme",0x039bdb96,"Controls.setKeyboardScheme","Controls.hx",527,0x0ab041e8)
static const int _hx_array_data_116e4296_758[] = {
	(int)74,(int)38,
};
static const int _hx_array_data_116e4296_759[] = {
	(int)70,(int)40,
};
static const int _hx_array_data_116e4296_760[] = {
	(int)68,(int)37,
};
static const int _hx_array_data_116e4296_761[] = {
	(int)75,(int)39,
};
static const int _hx_array_data_116e4296_762[] = {
	(int)71,(int)90,(int)32,(int)13,
};
static const int _hx_array_data_116e4296_763[] = {
	(int)27,(int)8,
};
static const int _hx_array_data_116e4296_764[] = {
	(int)80,(int)13,(int)27,
};
static const int _hx_array_data_116e4296_765[] = {
	(int)82,
};
static const int _hx_array_data_116e4296_766[] = {
	(int)87,(int)38,
};
static const int _hx_array_data_116e4296_767[] = {
	(int)83,(int)40,
};
static const int _hx_array_data_116e4296_768[] = {
	(int)65,(int)37,
};
static const int _hx_array_data_116e4296_769[] = {
	(int)68,(int)39,
};
static const int _hx_array_data_116e4296_770[] = {
	(int)71,(int)90,(int)32,(int)13,
};
static const int _hx_array_data_116e4296_771[] = {
	(int)27,(int)8,
};
static const int _hx_array_data_116e4296_772[] = {
	(int)82,
};
static const int _hx_array_data_116e4296_773[] = {
	(int)49,(int)97,(int)38,
};
static const int _hx_array_data_116e4296_774[] = {
	(int)88,(int)40,
};
static const int _hx_array_data_116e4296_775[] = {
	(int)90,(int)37,
};
static const int _hx_array_data_116e4296_776[] = {
	(int)50,(int)98,(int)39,
};
static const int _hx_array_data_116e4296_777[] = {
	(int)71,(int)79,(int)32,(int)13,
};
static const int _hx_array_data_116e4296_778[] = {
	(int)27,(int)8,(int)80,
};
static const int _hx_array_data_116e4296_779[] = {
	(int)82,
};
static const int _hx_array_data_116e4296_780[] = {
	(int)71,(int)90,(int)32,(int)13,
};
static const int _hx_array_data_116e4296_781[] = {
	(int)27,(int)8,
};
static const int _hx_array_data_116e4296_782[] = {
	(int)80,(int)13,(int)27,
};
static const int _hx_array_data_116e4296_783[] = {
	(int)82,
};
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_586_removeKeyboard,"Controls","removeKeyboard",0xd2dac3e3,"Controls.removeKeyboard","Controls.hx",586,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_599_addGamepad,"Controls","addGamepad",0xa2c68b58,"Controls.addGamepad","Controls.hx",599,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_612_addGamepadLiteral,"Controls","addGamepadLiteral",0x50b4e0f7,"Controls.addGamepadLiteral","Controls.hx",612,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_625_removeGamepad,"Controls","removeGamepad",0xfdf294e5,"Controls.removeGamepad","Controls.hx",625,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_643_addDefaultGamepad,"Controls","addDefaultGamepad",0xaa5e6409,"Controls.addDefaultGamepad","Controls.hx",643,0x0ab041e8)
static const int _hx_array_data_116e4296_856[] = {
	(int)0,
};
static const int _hx_array_data_116e4296_857[] = {
	(int)1,
};
static const int _hx_array_data_116e4296_858[] = {
	(int)11,(int)34,
};
static const int _hx_array_data_116e4296_859[] = {
	(int)12,(int)36,
};
static const int _hx_array_data_116e4296_860[] = {
	(int)13,(int)37,
};
static const int _hx_array_data_116e4296_861[] = {
	(int)14,(int)35,
};
static const int _hx_array_data_116e4296_862[] = {
	(int)7,
};
static const int _hx_array_data_116e4296_863[] = {
	(int)3,
};
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_677_bindButtons,"Controls","bindButtons",0x94dee42c,"Controls.bindButtons","Controls.hx",677,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_690_unbindButtons,"Controls","unbindButtons",0x83d33473,"Controls.unbindButtons","Controls.hx",690,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_714_getInputsFor,"Controls","getInputsFor",0xa3571ac2,"Controls.getInputsFor","Controls.hx",714,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_738_removeDevice,"Controls","removeDevice",0x4c1b5cd2,"Controls.removeDevice","Controls.hx",738,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_349_init,"Controls","init",0x495487e8,"Controls.init","Controls.hx",349,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_511_addKeys,"Controls","addKeys",0xd0486edd,"Controls.addKeys","Controls.hx",511,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_516_removeKeys,"Controls","removeKeys",0x75dc9b30,"Controls.removeKeys","Controls.hx",516,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_698_addButtons,"Controls","addButtons",0xe3b5fcf8,"Controls.addButtons","Controls.hx",698,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_703_removeButtons,"Controls","removeButtons",0x3ee20685,"Controls.removeButtons","Controls.hx",703,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_749_isDevice,"Controls","isDevice",0xe09e10f8,"Controls.isDevice","Controls.hx",749,0x0ab041e8)
HX_LOCAL_STACK_FRAME(_hx_pos_948b5caa279cd923_758_isGamepad,"Controls","isGamepad",0x5bcd81ff,"Controls.isGamepad","Controls.hx",758,0x0ab041e8)

void Controls_obj::__construct(::String name, ::KeyboardScheme __o_scheme){
            		 ::KeyboardScheme scheme = __o_scheme;
            		if (::hx::IsNull(__o_scheme)) scheme = ::KeyboardScheme_obj::None_dyn();
            	HX_GC_STACKFRAME(&_hx_pos_948b5caa279cd923_102_new)
HXLINE( 132)		this->keyboardScheme = ::KeyboardScheme_obj::None_dyn();
HXLINE( 131)		this->gamepadsAdded = ::Array_obj< int >::__new(0);
HXLINE( 126)		this->byName =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
HXLINE( 123)		this->_cheat =  ::flixel::input::actions::FlxActionDigital_obj::__alloc( HX_CTX ,HX_("cheat",13,97,b6,45),null());
HXLINE( 122)		this->_reset =  ::flixel::input::actions::FlxActionDigital_obj::__alloc( HX_CTX ,HX_("reset",cf,49,c8,e6),null());
HXLINE( 121)		this->_pause =  ::flixel::input::actions::FlxActionDigital_obj::__alloc( HX_CTX ,HX_("pause",f6,d6,57,bd),null());
HXLINE( 120)		this->_back =  ::flixel::input::actions::FlxActionDigital_obj::__alloc( HX_CTX ,HX_("back",27,da,10,41),null());
HXLINE( 119)		this->_accept =  ::flixel::input::actions::FlxActionDigital_obj::__alloc( HX_CTX ,HX_("accept",08,93,06,0b),null());
HXLINE( 118)		this->_spaceR =  ::flixel::input::actions::FlxActionDigital_obj::__alloc( HX_CTX ,HX_("space-release",00,58,55,ea),null());
HXLINE( 117)		this->_downR =  ::flixel::input::actions::FlxActionDigital_obj::__alloc( HX_CTX ,HX_("down-release",9c,bf,5b,fc),null());
HXLINE( 116)		this->_rightR =  ::flixel::input::actions::FlxActionDigital_obj::__alloc( HX_CTX ,HX_("right-release",16,dd,28,fb),null());
HXLINE( 115)		this->_leftR =  ::flixel::input::actions::FlxActionDigital_obj::__alloc( HX_CTX ,HX_("left-release",41,7c,5d,2e),null());
HXLINE( 114)		this->_upR =  ::flixel::input::actions::FlxActionDigital_obj::__alloc( HX_CTX ,HX_("up-release",95,4e,72,92),null());
HXLINE( 113)		this->_spaceP =  ::flixel::input::actions::FlxActionDigital_obj::__alloc( HX_CTX ,HX_("space-press",7c,f5,08,3f),null());
HXLINE( 112)		this->_downP =  ::flixel::input::actions::FlxActionDigital_obj::__alloc( HX_CTX ,HX_("down-press",18,fe,06,cf),null());
HXLINE( 111)		this->_rightP =  ::flixel::input::actions::FlxActionDigital_obj::__alloc( HX_CTX ,HX_("right-press",12,e9,87,fb),null());
HXLINE( 110)		this->_leftP =  ::flixel::input::actions::FlxActionDigital_obj::__alloc( HX_CTX ,HX_("left-press",7d,d7,13,c1),null());
HXLINE( 109)		this->_upP =  ::flixel::input::actions::FlxActionDigital_obj::__alloc( HX_CTX ,HX_("up-press",d1,ac,09,1c),null());
HXLINE( 108)		this->_space =  ::flixel::input::actions::FlxActionDigital_obj::__alloc( HX_CTX ,HX_("space",c6,8c,66,81),null());
HXLINE( 107)		this->_down =  ::flixel::input::actions::FlxActionDigital_obj::__alloc( HX_CTX ,HX_("down",62,f8,6d,42),null());
HXLINE( 106)		this->_right =  ::flixel::input::actions::FlxActionDigital_obj::__alloc( HX_CTX ,HX_("right",dc,0b,64,e9),null());
HXLINE( 105)		this->_left =  ::flixel::input::actions::FlxActionDigital_obj::__alloc( HX_CTX ,HX_("left",07,08,b0,47),null());
HXLINE( 104)		this->_up =  ::flixel::input::actions::FlxActionDigital_obj::__alloc( HX_CTX ,HX_("up",5b,66,00,00),null());
HXLINE( 237)		super::__construct(name,null(),null());
HXLINE( 239)		this->add(this->_up);
HXLINE( 240)		this->add(this->_left);
HXLINE( 241)		this->add(this->_right);
HXLINE( 242)		this->add(this->_down);
HXLINE( 243)		this->add(this->_space);
HXLINE( 244)		this->add(this->_upP);
HXLINE( 245)		this->add(this->_leftP);
HXLINE( 246)		this->add(this->_rightP);
HXLINE( 247)		this->add(this->_downP);
HXLINE( 248)		this->add(this->_spaceP);
HXLINE( 249)		this->add(this->_upR);
HXLINE( 250)		this->add(this->_leftR);
HXLINE( 251)		this->add(this->_rightR);
HXLINE( 252)		this->add(this->_downR);
HXLINE( 253)		this->add(this->_spaceR);
HXLINE( 254)		this->add(this->_accept);
HXLINE( 255)		this->add(this->_back);
HXLINE( 256)		this->add(this->_pause);
HXLINE( 257)		this->add(this->_reset);
HXLINE( 258)		this->add(this->_cheat);
HXLINE( 260)		{
HXLINE( 260)			int _g = 0;
HXDLIN( 260)			::Array< ::Dynamic> _g1 = this->digitalActions;
HXDLIN( 260)			while((_g < _g1->length)){
HXLINE( 260)				 ::flixel::input::actions::FlxActionDigital action = _g1->__get(_g).StaticCast<  ::flixel::input::actions::FlxActionDigital >();
HXDLIN( 260)				_g = (_g + 1);
HXLINE( 261)				this->byName->set(action->name,action);
            			}
            		}
HXLINE( 263)		this->setKeyboardScheme(scheme,false);
            	}

Dynamic Controls_obj::__CreateEmpty() { return new Controls_obj; }

void *Controls_obj::_hx_vtable = 0;

Dynamic Controls_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Controls_obj > _hx_result = new Controls_obj();
	_hx_result->__construct(inArgs[0],inArgs[1]);
	return _hx_result;
}

bool Controls_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x315ddd0d) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x315ddd0d;
	} else {
		return inClassId==(int)0x6cff3556;
	}
}

bool Controls_obj::get_UP(){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_137_get_UP)
HXDLIN( 137)		return this->_up->check();
            	}


HX_DEFINE_DYNAMIC_FUNC0(Controls_obj,get_UP,return )

bool Controls_obj::get_LEFT(){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_142_get_LEFT)
HXDLIN( 142)		return this->_left->check();
            	}


HX_DEFINE_DYNAMIC_FUNC0(Controls_obj,get_LEFT,return )

bool Controls_obj::get_RIGHT(){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_147_get_RIGHT)
HXDLIN( 147)		return this->_right->check();
            	}


HX_DEFINE_DYNAMIC_FUNC0(Controls_obj,get_RIGHT,return )

bool Controls_obj::get_DOWN(){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_152_get_DOWN)
HXDLIN( 152)		return this->_down->check();
            	}


HX_DEFINE_DYNAMIC_FUNC0(Controls_obj,get_DOWN,return )

bool Controls_obj::get_SPACE(){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_157_get_SPACE)
HXDLIN( 157)		return this->_space->check();
            	}


HX_DEFINE_DYNAMIC_FUNC0(Controls_obj,get_SPACE,return )

bool Controls_obj::get_SPACE_P(){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_162_get_SPACE_P)
HXDLIN( 162)		return this->_spaceP->check();
            	}


HX_DEFINE_DYNAMIC_FUNC0(Controls_obj,get_SPACE_P,return )

bool Controls_obj::get_UP_P(){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_167_get_UP_P)
HXDLIN( 167)		return this->_upP->check();
            	}


HX_DEFINE_DYNAMIC_FUNC0(Controls_obj,get_UP_P,return )

bool Controls_obj::get_LEFT_P(){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_172_get_LEFT_P)
HXDLIN( 172)		return this->_leftP->check();
            	}


HX_DEFINE_DYNAMIC_FUNC0(Controls_obj,get_LEFT_P,return )

bool Controls_obj::get_RIGHT_P(){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_177_get_RIGHT_P)
HXDLIN( 177)		return this->_rightP->check();
            	}


HX_DEFINE_DYNAMIC_FUNC0(Controls_obj,get_RIGHT_P,return )

bool Controls_obj::get_DOWN_P(){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_182_get_DOWN_P)
HXDLIN( 182)		return this->_downP->check();
            	}


HX_DEFINE_DYNAMIC_FUNC0(Controls_obj,get_DOWN_P,return )

bool Controls_obj::get_UP_R(){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_187_get_UP_R)
HXDLIN( 187)		return this->_upR->check();
            	}


HX_DEFINE_DYNAMIC_FUNC0(Controls_obj,get_UP_R,return )

bool Controls_obj::get_LEFT_R(){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_192_get_LEFT_R)
HXDLIN( 192)		return this->_leftR->check();
            	}


HX_DEFINE_DYNAMIC_FUNC0(Controls_obj,get_LEFT_R,return )

bool Controls_obj::get_RIGHT_R(){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_197_get_RIGHT_R)
HXDLIN( 197)		return this->_rightR->check();
            	}


HX_DEFINE_DYNAMIC_FUNC0(Controls_obj,get_RIGHT_R,return )

bool Controls_obj::get_DOWN_R(){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_202_get_DOWN_R)
HXDLIN( 202)		return this->_downR->check();
            	}


HX_DEFINE_DYNAMIC_FUNC0(Controls_obj,get_DOWN_R,return )

bool Controls_obj::get_SPACE_R(){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_207_get_SPACE_R)
HXDLIN( 207)		return this->_spaceR->check();
            	}


HX_DEFINE_DYNAMIC_FUNC0(Controls_obj,get_SPACE_R,return )

bool Controls_obj::get_ACCEPT(){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_212_get_ACCEPT)
HXDLIN( 212)		return this->_accept->check();
            	}


HX_DEFINE_DYNAMIC_FUNC0(Controls_obj,get_ACCEPT,return )

bool Controls_obj::get_BACK(){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_217_get_BACK)
HXDLIN( 217)		return this->_back->check();
            	}


HX_DEFINE_DYNAMIC_FUNC0(Controls_obj,get_BACK,return )

bool Controls_obj::get_PAUSE(){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_222_get_PAUSE)
HXDLIN( 222)		return this->_pause->check();
            	}


HX_DEFINE_DYNAMIC_FUNC0(Controls_obj,get_PAUSE,return )

bool Controls_obj::get_RESET(){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_227_get_RESET)
HXDLIN( 227)		return this->_reset->check();
            	}


HX_DEFINE_DYNAMIC_FUNC0(Controls_obj,get_RESET,return )

bool Controls_obj::get_CHEAT(){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_232_get_CHEAT)
HXDLIN( 232)		return this->_cheat->check();
            	}


HX_DEFINE_DYNAMIC_FUNC0(Controls_obj,get_CHEAT,return )

void Controls_obj::update(){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_302_update)
HXDLIN( 302)		this->super::update();
            	}


bool Controls_obj::checkByName(::String name){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_312_checkByName)
HXDLIN( 312)		return ( ( ::flixel::input::actions::FlxActionDigital)(this->byName->get(name)) )->check();
            	}


HX_DEFINE_DYNAMIC_FUNC1(Controls_obj,checkByName,return )

::String Controls_obj::getDialogueName( ::flixel::input::actions::FlxActionDigital action){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_316_getDialogueName)
HXLINE( 317)		 ::flixel::input::actions::FlxActionInput input = action->inputs->__get(0).StaticCast<  ::flixel::input::actions::FlxActionInput >();
HXLINE( 318)		 ::flixel::input::actions::FlxInputDevice _g = input->device;
HXDLIN( 318)		switch((int)(_g->_hx_getIndex())){
            			case (int)3: {
HXLINE( 320)				return ((HX_("[",5b,00,00,00) + ::flixel::input::keyboard::_FlxKey::FlxKey_Impl__obj::toStringMap->get(input->inputID)) + HX_("]",5d,00,00,00));
            			}
            			break;
            			case (int)4: {
HXLINE( 321)				return ((HX_("(",28,00,00,00) + ::flixel::input::gamepad::_FlxGamepadInputID::FlxGamepadInputID_Impl__obj::toStringMap->get(input->inputID)) + HX_(")",29,00,00,00));
            			}
            			break;
            			default:{
HXLINE( 322)				 ::flixel::input::actions::FlxInputDevice device = _g;
HXDLIN( 322)				HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("unhandled device: ",f9,e1,62,a5) + ::Std_obj::string(device))));
            			}
            		}
HXLINE( 318)		return null();
            	}


HX_DEFINE_DYNAMIC_FUNC1(Controls_obj,getDialogueName,return )

::String Controls_obj::getDialogueNameFromToken(::String token){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_328_getDialogueNameFromToken)
HXDLIN( 328)		::cpp::VirtualArray params = null();
HXDLIN( 328)		return this->getDialogueName(this->getActionFromControl(::Type_obj::createEnum(::hx::ClassOf< ::Control >(),token.toUpperCase(),params)));
            	}


HX_DEFINE_DYNAMIC_FUNC1(Controls_obj,getDialogueNameFromToken,return )

 ::flixel::input::actions::FlxActionDigital Controls_obj::getActionFromControl( ::Control control){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_333_getActionFromControl)
HXDLIN( 333)		switch((int)(control->_hx_getIndex())){
            			case (int)0: {
HXLINE( 335)				return this->_up;
            			}
            			break;
            			case (int)1: {
HXLINE( 337)				return this->_left;
            			}
            			break;
            			case (int)2: {
HXLINE( 338)				return this->_right;
            			}
            			break;
            			case (int)3: {
HXLINE( 336)				return this->_down;
            			}
            			break;
            			case (int)4: {
HXLINE( 344)				return this->_space;
            			}
            			break;
            			case (int)5: {
HXLINE( 342)				return this->_reset;
            			}
            			break;
            			case (int)6: {
HXLINE( 339)				return this->_accept;
            			}
            			break;
            			case (int)7: {
HXLINE( 340)				return this->_back;
            			}
            			break;
            			case (int)8: {
HXLINE( 341)				return this->_pause;
            			}
            			break;
            			case (int)9: {
HXLINE( 343)				return this->_cheat;
            			}
            			break;
            		}
HXLINE( 333)		return null();
            	}


HX_DEFINE_DYNAMIC_FUNC1(Controls_obj,getActionFromControl,return )

void Controls_obj::forEachBound( ::Control control, ::Dynamic func){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_362_forEachBound)
HXDLIN( 362)		switch((int)(control->_hx_getIndex())){
            			case (int)0: {
HXLINE( 365)				func(this->_up,1);
HXLINE( 366)				func(this->_upP,2);
HXLINE( 367)				func(this->_upR,-1);
            			}
            			break;
            			case (int)1: {
HXLINE( 369)				func(this->_left,1);
HXLINE( 370)				func(this->_leftP,2);
HXLINE( 371)				func(this->_leftR,-1);
            			}
            			break;
            			case (int)2: {
HXLINE( 373)				func(this->_right,1);
HXLINE( 374)				func(this->_rightP,2);
HXLINE( 375)				func(this->_rightR,-1);
            			}
            			break;
            			case (int)3: {
HXLINE( 377)				func(this->_down,1);
HXLINE( 378)				func(this->_downP,2);
HXLINE( 379)				func(this->_downR,-1);
            			}
            			break;
            			case (int)4: {
HXLINE( 391)				func(this->_space,1);
HXLINE( 392)				func(this->_spaceP,2);
HXLINE( 393)				func(this->_spaceR,-1);
            			}
            			break;
            			case (int)5: {
HXLINE( 387)				func(this->_reset,2);
            			}
            			break;
            			case (int)6: {
HXLINE( 381)				func(this->_accept,2);
            			}
            			break;
            			case (int)7: {
HXLINE( 383)				func(this->_back,2);
            			}
            			break;
            			case (int)8: {
HXLINE( 385)				func(this->_pause,2);
            			}
            			break;
            			case (int)9: {
HXLINE( 389)				func(this->_cheat,2);
            			}
            			break;
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC2(Controls_obj,forEachBound,(void))

void Controls_obj::replaceBinding( ::Control control, ::Device device, ::Dynamic toAdd, ::Dynamic toRemove){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_398_replaceBinding)
HXLINE( 399)		if (::hx::IsEq( toAdd,toRemove )) {
HXLINE( 400)			return;
            		}
HXLINE( 402)		switch((int)(device->_hx_getIndex())){
            			case (int)0: {
HXLINE( 405)				if (::hx::IsNotNull( toRemove )) {
HXLINE( 406)					this->unbindKeys(control,::Array_obj< int >::__new(1)->init(0,toRemove));
            				}
HXLINE( 407)				if (::hx::IsNotNull( toAdd )) {
HXLINE( 408)					this->bindKeys(control,::Array_obj< int >::__new(1)->init(0,toAdd));
            				}
            			}
            			break;
            			case (int)1: {
HXLINE( 410)				int id = device->_hx_getInt(0);
HXDLIN( 410)				{
HXLINE( 411)					if (::hx::IsNotNull( toRemove )) {
HXLINE( 412)						this->unbindButtons(control,id,::Array_obj< int >::__new(1)->init(0,toRemove));
            					}
HXLINE( 413)					if (::hx::IsNotNull( toAdd )) {
HXLINE( 414)						this->bindButtons(control,id,::Array_obj< int >::__new(1)->init(0,toAdd));
            					}
            				}
            			}
            			break;
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC4(Controls_obj,replaceBinding,(void))

void Controls_obj::copyFrom( ::Controls controls, ::Device device){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_419_copyFrom)
HXLINE( 421)		{
HXLINE( 421)			::Dynamic map = controls->byName;
HXDLIN( 421)			::Dynamic _g_map = map;
HXDLIN( 421)			 ::Dynamic _g_keys = ::haxe::IMap_obj::keys(map);
HXDLIN( 421)			while(( (bool)(_g_keys->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE( 421)				::String key = ( (::String)(_g_keys->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXDLIN( 421)				 ::flixel::input::actions::FlxActionDigital _g1_value = ( ( ::flixel::input::actions::FlxActionDigital)(::haxe::IMap_obj::get(_g_map,key)) );
HXDLIN( 421)				::String _g1_key = key;
HXDLIN( 421)				::String name = _g1_key;
HXDLIN( 421)				 ::flixel::input::actions::FlxActionDigital action = _g1_value;
HXLINE( 423)				{
HXLINE( 423)					int _g = 0;
HXDLIN( 423)					::Array< ::Dynamic> _g1 = action->inputs;
HXDLIN( 423)					while((_g < _g1->length)){
HXLINE( 423)						 ::flixel::input::actions::FlxActionInput input = _g1->__get(_g).StaticCast<  ::flixel::input::actions::FlxActionInput >();
HXDLIN( 423)						_g = (_g + 1);
HXLINE( 425)						bool _hx_tmp;
HXDLIN( 425)						if (::hx::IsNotNull( device )) {
HXLINE( 425)							_hx_tmp = ::Controls_obj::isDevice(input,device);
            						}
            						else {
HXLINE( 425)							_hx_tmp = true;
            						}
HXDLIN( 425)						if (_hx_tmp) {
HXLINE( 426)							( ( ::flixel::input::actions::FlxActionDigital)(this->byName->get(name)) )->add(( ( ::flixel::input::actions::FlxActionInputDigital)(input) ));
            						}
            					}
            				}
            			}
            		}
HXLINE( 441)		if (::hx::IsNull( device )) {
HXLINE( 446)			{
HXLINE( 446)				int _g = 0;
HXDLIN( 446)				::Array< int > _g1 = controls->gamepadsAdded;
HXDLIN( 446)				while((_g < _g1->length)){
HXLINE( 446)					int gamepad = _g1->__get(_g);
HXDLIN( 446)					_g = (_g + 1);
HXLINE( 447)					if (!(this->gamepadsAdded->contains(gamepad))) {
HXLINE( 448)						this->gamepadsAdded->push(gamepad);
            					}
            				}
            			}
HXLINE( 455)			this->mergeKeyboardScheme(controls->keyboardScheme);
            		}
            		else {
HXLINE( 441)			switch((int)(device->_hx_getIndex())){
            				case (int)0: {
HXLINE( 460)					this->mergeKeyboardScheme(controls->keyboardScheme);
            				}
            				break;
            				case (int)1: {
HXLINE( 457)					int id = device->_hx_getInt(0);
HXLINE( 458)					this->gamepadsAdded->push(id);
            				}
            				break;
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC2(Controls_obj,copyFrom,(void))

void Controls_obj::copyTo( ::Controls controls, ::Device device){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_466_copyTo)
HXDLIN( 466)		controls->copyFrom(::hx::ObjectPtr<OBJ_>(this),device);
            	}


HX_DEFINE_DYNAMIC_FUNC2(Controls_obj,copyTo,(void))

void Controls_obj::mergeKeyboardScheme( ::KeyboardScheme scheme){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_471_mergeKeyboardScheme)
HXDLIN( 471)		if (::hx::IsPointerNotEq( scheme,::KeyboardScheme_obj::None_dyn() )) {
HXLINE( 473)			if ((this->keyboardScheme->_hx_getIndex() == 2)) {
HXLINE( 476)				this->keyboardScheme = scheme;
            			}
            			else {
HXLINE( 478)				this->keyboardScheme = ::KeyboardScheme_obj::Custom_dyn();
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(Controls_obj,mergeKeyboardScheme,(void))

void Controls_obj::bindKeys( ::Control control,::Array< int > keys){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_490_bindKeys)
HXDLIN( 490)		switch((int)(control->_hx_getIndex())){
            			case (int)0: {
HXDLIN( 490)				{
HXDLIN( 490)					 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 490)					int state = 1;
HXDLIN( 490)					int _g = 0;
HXDLIN( 490)					while((_g < keys->length)){
HXDLIN( 490)						int key = keys->__get(_g);
HXDLIN( 490)						_g = (_g + 1);
HXDLIN( 490)						action->addKey(key,state);
            					}
            				}
HXDLIN( 490)				{
HXDLIN( 490)					 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 490)					int state1 = 2;
HXDLIN( 490)					int _g1 = 0;
HXDLIN( 490)					while((_g1 < keys->length)){
HXDLIN( 490)						int key = keys->__get(_g1);
HXDLIN( 490)						_g1 = (_g1 + 1);
HXDLIN( 490)						action1->addKey(key,state1);
            					}
            				}
HXDLIN( 490)				{
HXDLIN( 490)					 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 490)					int state2 = -1;
HXDLIN( 490)					int _g2 = 0;
HXDLIN( 490)					while((_g2 < keys->length)){
HXDLIN( 490)						int key = keys->__get(_g2);
HXDLIN( 490)						_g2 = (_g2 + 1);
HXDLIN( 490)						action2->addKey(key,state2);
            					}
            				}
            			}
            			break;
            			case (int)1: {
HXDLIN( 490)				{
HXDLIN( 490)					 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 490)					int state = 1;
HXDLIN( 490)					int _g = 0;
HXDLIN( 490)					while((_g < keys->length)){
HXDLIN( 490)						int key = keys->__get(_g);
HXDLIN( 490)						_g = (_g + 1);
HXDLIN( 490)						action->addKey(key,state);
            					}
            				}
HXDLIN( 490)				{
HXDLIN( 490)					 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 490)					int state1 = 2;
HXDLIN( 490)					int _g1 = 0;
HXDLIN( 490)					while((_g1 < keys->length)){
HXDLIN( 490)						int key = keys->__get(_g1);
HXDLIN( 490)						_g1 = (_g1 + 1);
HXDLIN( 490)						action1->addKey(key,state1);
            					}
            				}
HXDLIN( 490)				{
HXDLIN( 490)					 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 490)					int state2 = -1;
HXDLIN( 490)					int _g2 = 0;
HXDLIN( 490)					while((_g2 < keys->length)){
HXDLIN( 490)						int key = keys->__get(_g2);
HXDLIN( 490)						_g2 = (_g2 + 1);
HXDLIN( 490)						action2->addKey(key,state2);
            					}
            				}
            			}
            			break;
            			case (int)2: {
HXDLIN( 490)				{
HXDLIN( 490)					 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 490)					int state = 1;
HXDLIN( 490)					int _g = 0;
HXDLIN( 490)					while((_g < keys->length)){
HXDLIN( 490)						int key = keys->__get(_g);
HXDLIN( 490)						_g = (_g + 1);
HXDLIN( 490)						action->addKey(key,state);
            					}
            				}
HXDLIN( 490)				{
HXDLIN( 490)					 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 490)					int state1 = 2;
HXDLIN( 490)					int _g1 = 0;
HXDLIN( 490)					while((_g1 < keys->length)){
HXDLIN( 490)						int key = keys->__get(_g1);
HXDLIN( 490)						_g1 = (_g1 + 1);
HXDLIN( 490)						action1->addKey(key,state1);
            					}
            				}
HXDLIN( 490)				{
HXDLIN( 490)					 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 490)					int state2 = -1;
HXDLIN( 490)					int _g2 = 0;
HXDLIN( 490)					while((_g2 < keys->length)){
HXDLIN( 490)						int key = keys->__get(_g2);
HXDLIN( 490)						_g2 = (_g2 + 1);
HXDLIN( 490)						action2->addKey(key,state2);
            					}
            				}
            			}
            			break;
            			case (int)3: {
HXDLIN( 490)				{
HXDLIN( 490)					 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 490)					int state = 1;
HXDLIN( 490)					int _g = 0;
HXDLIN( 490)					while((_g < keys->length)){
HXDLIN( 490)						int key = keys->__get(_g);
HXDLIN( 490)						_g = (_g + 1);
HXDLIN( 490)						action->addKey(key,state);
            					}
            				}
HXDLIN( 490)				{
HXDLIN( 490)					 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 490)					int state1 = 2;
HXDLIN( 490)					int _g1 = 0;
HXDLIN( 490)					while((_g1 < keys->length)){
HXDLIN( 490)						int key = keys->__get(_g1);
HXDLIN( 490)						_g1 = (_g1 + 1);
HXDLIN( 490)						action1->addKey(key,state1);
            					}
            				}
HXDLIN( 490)				{
HXDLIN( 490)					 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 490)					int state2 = -1;
HXDLIN( 490)					int _g2 = 0;
HXDLIN( 490)					while((_g2 < keys->length)){
HXDLIN( 490)						int key = keys->__get(_g2);
HXDLIN( 490)						_g2 = (_g2 + 1);
HXDLIN( 490)						action2->addKey(key,state2);
            					}
            				}
            			}
            			break;
            			case (int)4: {
HXDLIN( 490)				{
HXDLIN( 490)					 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 490)					int state = 1;
HXDLIN( 490)					int _g = 0;
HXDLIN( 490)					while((_g < keys->length)){
HXDLIN( 490)						int key = keys->__get(_g);
HXDLIN( 490)						_g = (_g + 1);
HXDLIN( 490)						action->addKey(key,state);
            					}
            				}
HXDLIN( 490)				{
HXDLIN( 490)					 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 490)					int state1 = 2;
HXDLIN( 490)					int _g1 = 0;
HXDLIN( 490)					while((_g1 < keys->length)){
HXDLIN( 490)						int key = keys->__get(_g1);
HXDLIN( 490)						_g1 = (_g1 + 1);
HXDLIN( 490)						action1->addKey(key,state1);
            					}
            				}
HXDLIN( 490)				{
HXDLIN( 490)					 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 490)					int state2 = -1;
HXDLIN( 490)					int _g2 = 0;
HXDLIN( 490)					while((_g2 < keys->length)){
HXDLIN( 490)						int key = keys->__get(_g2);
HXDLIN( 490)						_g2 = (_g2 + 1);
HXDLIN( 490)						action2->addKey(key,state2);
            					}
            				}
            			}
            			break;
            			case (int)5: {
HXDLIN( 490)				 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 490)				int state = 2;
HXDLIN( 490)				int _g = 0;
HXDLIN( 490)				while((_g < keys->length)){
HXDLIN( 490)					int key = keys->__get(_g);
HXDLIN( 490)					_g = (_g + 1);
HXDLIN( 490)					action->addKey(key,state);
            				}
            			}
            			break;
            			case (int)6: {
HXDLIN( 490)				 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 490)				int state = 2;
HXDLIN( 490)				int _g = 0;
HXDLIN( 490)				while((_g < keys->length)){
HXDLIN( 490)					int key = keys->__get(_g);
HXDLIN( 490)					_g = (_g + 1);
HXDLIN( 490)					action->addKey(key,state);
            				}
            			}
            			break;
            			case (int)7: {
HXDLIN( 490)				 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 490)				int state = 2;
HXDLIN( 490)				int _g = 0;
HXDLIN( 490)				while((_g < keys->length)){
HXDLIN( 490)					int key = keys->__get(_g);
HXDLIN( 490)					_g = (_g + 1);
HXDLIN( 490)					action->addKey(key,state);
            				}
            			}
            			break;
            			case (int)8: {
HXDLIN( 490)				 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 490)				int state = 2;
HXDLIN( 490)				int _g = 0;
HXDLIN( 490)				while((_g < keys->length)){
HXDLIN( 490)					int key = keys->__get(_g);
HXDLIN( 490)					_g = (_g + 1);
HXDLIN( 490)					action->addKey(key,state);
            				}
            			}
            			break;
            			case (int)9: {
HXDLIN( 490)				 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 490)				int state = 2;
HXDLIN( 490)				int _g = 0;
HXDLIN( 490)				while((_g < keys->length)){
HXDLIN( 490)					int key = keys->__get(_g);
HXDLIN( 490)					_g = (_g + 1);
HXDLIN( 490)					action->addKey(key,state);
            				}
            			}
            			break;
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC2(Controls_obj,bindKeys,(void))

void Controls_obj::unbindKeys( ::Control control,::Array< int > keys){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_503_unbindKeys)
HXDLIN( 503)		switch((int)(control->_hx_getIndex())){
            			case (int)0: {
HXDLIN( 503)				::Controls_obj::removeKeys(this->_up,keys);
HXDLIN( 503)				::Controls_obj::removeKeys(this->_upP,keys);
HXDLIN( 503)				::Controls_obj::removeKeys(this->_upR,keys);
            			}
            			break;
            			case (int)1: {
HXDLIN( 503)				::Controls_obj::removeKeys(this->_left,keys);
HXDLIN( 503)				::Controls_obj::removeKeys(this->_leftP,keys);
HXDLIN( 503)				::Controls_obj::removeKeys(this->_leftR,keys);
            			}
            			break;
            			case (int)2: {
HXDLIN( 503)				::Controls_obj::removeKeys(this->_right,keys);
HXDLIN( 503)				::Controls_obj::removeKeys(this->_rightP,keys);
HXDLIN( 503)				::Controls_obj::removeKeys(this->_rightR,keys);
            			}
            			break;
            			case (int)3: {
HXDLIN( 503)				::Controls_obj::removeKeys(this->_down,keys);
HXDLIN( 503)				::Controls_obj::removeKeys(this->_downP,keys);
HXDLIN( 503)				::Controls_obj::removeKeys(this->_downR,keys);
            			}
            			break;
            			case (int)4: {
HXDLIN( 503)				::Controls_obj::removeKeys(this->_space,keys);
HXDLIN( 503)				::Controls_obj::removeKeys(this->_spaceP,keys);
HXDLIN( 503)				::Controls_obj::removeKeys(this->_spaceR,keys);
            			}
            			break;
            			case (int)5: {
HXDLIN( 503)				::Controls_obj::removeKeys(this->_reset,keys);
            			}
            			break;
            			case (int)6: {
HXDLIN( 503)				::Controls_obj::removeKeys(this->_accept,keys);
            			}
            			break;
            			case (int)7: {
HXDLIN( 503)				::Controls_obj::removeKeys(this->_back,keys);
            			}
            			break;
            			case (int)8: {
HXDLIN( 503)				::Controls_obj::removeKeys(this->_pause,keys);
            			}
            			break;
            			case (int)9: {
HXDLIN( 503)				::Controls_obj::removeKeys(this->_cheat,keys);
            			}
            			break;
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC2(Controls_obj,unbindKeys,(void))

void Controls_obj::setKeyboardScheme( ::KeyboardScheme scheme,::hx::Null< bool >  __o_reset){
            		bool reset = __o_reset.Default(true);
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_527_setKeyboardScheme)
HXLINE( 528)		if (reset) {
HXLINE( 529)			this->removeKeyboard();
            		}
HXLINE( 531)		this->keyboardScheme = scheme;
HXLINE( 536)		switch((int)(scheme->_hx_getIndex())){
            			case (int)0: {
HXLINE( 539)				{
HXLINE( 539)					::Array< int > keys = ::Array_obj< int >::fromData( _hx_array_data_116e4296_758,2);
HXDLIN( 539)					switch((int)(::Control_obj::UP_dyn()->_hx_getIndex())){
            						case (int)0: {
HXLINE( 539)							{
HXLINE( 539)								 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 539)								int state = 1;
HXDLIN( 539)								int _g = 0;
HXDLIN( 539)								while((_g < keys->length)){
HXLINE( 539)									int key = keys->__get(_g);
HXDLIN( 539)									_g = (_g + 1);
HXDLIN( 539)									action->addKey(key,state);
            								}
            							}
HXDLIN( 539)							{
HXLINE( 539)								 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 539)								int state1 = 2;
HXDLIN( 539)								int _g1 = 0;
HXDLIN( 539)								while((_g1 < keys->length)){
HXLINE( 539)									int key = keys->__get(_g1);
HXDLIN( 539)									_g1 = (_g1 + 1);
HXDLIN( 539)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 539)							{
HXLINE( 539)								 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 539)								int state2 = -1;
HXDLIN( 539)								int _g2 = 0;
HXDLIN( 539)								while((_g2 < keys->length)){
HXLINE( 539)									int key = keys->__get(_g2);
HXDLIN( 539)									_g2 = (_g2 + 1);
HXDLIN( 539)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)1: {
HXLINE( 539)							{
HXLINE( 539)								 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 539)								int state = 1;
HXDLIN( 539)								int _g = 0;
HXDLIN( 539)								while((_g < keys->length)){
HXLINE( 539)									int key = keys->__get(_g);
HXDLIN( 539)									_g = (_g + 1);
HXDLIN( 539)									action->addKey(key,state);
            								}
            							}
HXDLIN( 539)							{
HXLINE( 539)								 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 539)								int state1 = 2;
HXDLIN( 539)								int _g1 = 0;
HXDLIN( 539)								while((_g1 < keys->length)){
HXLINE( 539)									int key = keys->__get(_g1);
HXDLIN( 539)									_g1 = (_g1 + 1);
HXDLIN( 539)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 539)							{
HXLINE( 539)								 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 539)								int state2 = -1;
HXDLIN( 539)								int _g2 = 0;
HXDLIN( 539)								while((_g2 < keys->length)){
HXLINE( 539)									int key = keys->__get(_g2);
HXDLIN( 539)									_g2 = (_g2 + 1);
HXDLIN( 539)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)2: {
HXLINE( 539)							{
HXLINE( 539)								 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 539)								int state = 1;
HXDLIN( 539)								int _g = 0;
HXDLIN( 539)								while((_g < keys->length)){
HXLINE( 539)									int key = keys->__get(_g);
HXDLIN( 539)									_g = (_g + 1);
HXDLIN( 539)									action->addKey(key,state);
            								}
            							}
HXDLIN( 539)							{
HXLINE( 539)								 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 539)								int state1 = 2;
HXDLIN( 539)								int _g1 = 0;
HXDLIN( 539)								while((_g1 < keys->length)){
HXLINE( 539)									int key = keys->__get(_g1);
HXDLIN( 539)									_g1 = (_g1 + 1);
HXDLIN( 539)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 539)							{
HXLINE( 539)								 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 539)								int state2 = -1;
HXDLIN( 539)								int _g2 = 0;
HXDLIN( 539)								while((_g2 < keys->length)){
HXLINE( 539)									int key = keys->__get(_g2);
HXDLIN( 539)									_g2 = (_g2 + 1);
HXDLIN( 539)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)3: {
HXLINE( 539)							{
HXLINE( 539)								 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 539)								int state = 1;
HXDLIN( 539)								int _g = 0;
HXDLIN( 539)								while((_g < keys->length)){
HXLINE( 539)									int key = keys->__get(_g);
HXDLIN( 539)									_g = (_g + 1);
HXDLIN( 539)									action->addKey(key,state);
            								}
            							}
HXDLIN( 539)							{
HXLINE( 539)								 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 539)								int state1 = 2;
HXDLIN( 539)								int _g1 = 0;
HXDLIN( 539)								while((_g1 < keys->length)){
HXLINE( 539)									int key = keys->__get(_g1);
HXDLIN( 539)									_g1 = (_g1 + 1);
HXDLIN( 539)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 539)							{
HXLINE( 539)								 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 539)								int state2 = -1;
HXDLIN( 539)								int _g2 = 0;
HXDLIN( 539)								while((_g2 < keys->length)){
HXLINE( 539)									int key = keys->__get(_g2);
HXDLIN( 539)									_g2 = (_g2 + 1);
HXDLIN( 539)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)4: {
HXLINE( 539)							{
HXLINE( 539)								 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 539)								int state = 1;
HXDLIN( 539)								int _g = 0;
HXDLIN( 539)								while((_g < keys->length)){
HXLINE( 539)									int key = keys->__get(_g);
HXDLIN( 539)									_g = (_g + 1);
HXDLIN( 539)									action->addKey(key,state);
            								}
            							}
HXDLIN( 539)							{
HXLINE( 539)								 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 539)								int state1 = 2;
HXDLIN( 539)								int _g1 = 0;
HXDLIN( 539)								while((_g1 < keys->length)){
HXLINE( 539)									int key = keys->__get(_g1);
HXDLIN( 539)									_g1 = (_g1 + 1);
HXDLIN( 539)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 539)							{
HXLINE( 539)								 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 539)								int state2 = -1;
HXDLIN( 539)								int _g2 = 0;
HXDLIN( 539)								while((_g2 < keys->length)){
HXLINE( 539)									int key = keys->__get(_g2);
HXDLIN( 539)									_g2 = (_g2 + 1);
HXDLIN( 539)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)5: {
HXLINE( 539)							 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 539)							int state = 2;
HXDLIN( 539)							int _g = 0;
HXDLIN( 539)							while((_g < keys->length)){
HXLINE( 539)								int key = keys->__get(_g);
HXDLIN( 539)								_g = (_g + 1);
HXDLIN( 539)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)6: {
HXLINE( 539)							 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 539)							int state = 2;
HXDLIN( 539)							int _g = 0;
HXDLIN( 539)							while((_g < keys->length)){
HXLINE( 539)								int key = keys->__get(_g);
HXDLIN( 539)								_g = (_g + 1);
HXDLIN( 539)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)7: {
HXLINE( 539)							 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 539)							int state = 2;
HXDLIN( 539)							int _g = 0;
HXDLIN( 539)							while((_g < keys->length)){
HXLINE( 539)								int key = keys->__get(_g);
HXDLIN( 539)								_g = (_g + 1);
HXDLIN( 539)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)8: {
HXLINE( 539)							 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 539)							int state = 2;
HXDLIN( 539)							int _g = 0;
HXDLIN( 539)							while((_g < keys->length)){
HXLINE( 539)								int key = keys->__get(_g);
HXDLIN( 539)								_g = (_g + 1);
HXDLIN( 539)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)9: {
HXLINE( 539)							 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 539)							int state = 2;
HXDLIN( 539)							int _g = 0;
HXDLIN( 539)							while((_g < keys->length)){
HXLINE( 539)								int key = keys->__get(_g);
HXDLIN( 539)								_g = (_g + 1);
HXDLIN( 539)								action->addKey(key,state);
            							}
            						}
            						break;
            					}
            				}
HXLINE( 540)				{
HXLINE( 540)					::Array< int > keys1 = ::Array_obj< int >::fromData( _hx_array_data_116e4296_759,2);
HXDLIN( 540)					switch((int)(::Control_obj::DOWN_dyn()->_hx_getIndex())){
            						case (int)0: {
HXLINE( 540)							{
HXLINE( 540)								 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 540)								int state = 1;
HXDLIN( 540)								int _g = 0;
HXDLIN( 540)								while((_g < keys1->length)){
HXLINE( 540)									int key = keys1->__get(_g);
HXDLIN( 540)									_g = (_g + 1);
HXDLIN( 540)									action->addKey(key,state);
            								}
            							}
HXDLIN( 540)							{
HXLINE( 540)								 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 540)								int state1 = 2;
HXDLIN( 540)								int _g1 = 0;
HXDLIN( 540)								while((_g1 < keys1->length)){
HXLINE( 540)									int key = keys1->__get(_g1);
HXDLIN( 540)									_g1 = (_g1 + 1);
HXDLIN( 540)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 540)							{
HXLINE( 540)								 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 540)								int state2 = -1;
HXDLIN( 540)								int _g2 = 0;
HXDLIN( 540)								while((_g2 < keys1->length)){
HXLINE( 540)									int key = keys1->__get(_g2);
HXDLIN( 540)									_g2 = (_g2 + 1);
HXDLIN( 540)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)1: {
HXLINE( 540)							{
HXLINE( 540)								 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 540)								int state = 1;
HXDLIN( 540)								int _g = 0;
HXDLIN( 540)								while((_g < keys1->length)){
HXLINE( 540)									int key = keys1->__get(_g);
HXDLIN( 540)									_g = (_g + 1);
HXDLIN( 540)									action->addKey(key,state);
            								}
            							}
HXDLIN( 540)							{
HXLINE( 540)								 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 540)								int state1 = 2;
HXDLIN( 540)								int _g1 = 0;
HXDLIN( 540)								while((_g1 < keys1->length)){
HXLINE( 540)									int key = keys1->__get(_g1);
HXDLIN( 540)									_g1 = (_g1 + 1);
HXDLIN( 540)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 540)							{
HXLINE( 540)								 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 540)								int state2 = -1;
HXDLIN( 540)								int _g2 = 0;
HXDLIN( 540)								while((_g2 < keys1->length)){
HXLINE( 540)									int key = keys1->__get(_g2);
HXDLIN( 540)									_g2 = (_g2 + 1);
HXDLIN( 540)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)2: {
HXLINE( 540)							{
HXLINE( 540)								 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 540)								int state = 1;
HXDLIN( 540)								int _g = 0;
HXDLIN( 540)								while((_g < keys1->length)){
HXLINE( 540)									int key = keys1->__get(_g);
HXDLIN( 540)									_g = (_g + 1);
HXDLIN( 540)									action->addKey(key,state);
            								}
            							}
HXDLIN( 540)							{
HXLINE( 540)								 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 540)								int state1 = 2;
HXDLIN( 540)								int _g1 = 0;
HXDLIN( 540)								while((_g1 < keys1->length)){
HXLINE( 540)									int key = keys1->__get(_g1);
HXDLIN( 540)									_g1 = (_g1 + 1);
HXDLIN( 540)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 540)							{
HXLINE( 540)								 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 540)								int state2 = -1;
HXDLIN( 540)								int _g2 = 0;
HXDLIN( 540)								while((_g2 < keys1->length)){
HXLINE( 540)									int key = keys1->__get(_g2);
HXDLIN( 540)									_g2 = (_g2 + 1);
HXDLIN( 540)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)3: {
HXLINE( 540)							{
HXLINE( 540)								 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 540)								int state = 1;
HXDLIN( 540)								int _g = 0;
HXDLIN( 540)								while((_g < keys1->length)){
HXLINE( 540)									int key = keys1->__get(_g);
HXDLIN( 540)									_g = (_g + 1);
HXDLIN( 540)									action->addKey(key,state);
            								}
            							}
HXDLIN( 540)							{
HXLINE( 540)								 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 540)								int state1 = 2;
HXDLIN( 540)								int _g1 = 0;
HXDLIN( 540)								while((_g1 < keys1->length)){
HXLINE( 540)									int key = keys1->__get(_g1);
HXDLIN( 540)									_g1 = (_g1 + 1);
HXDLIN( 540)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 540)							{
HXLINE( 540)								 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 540)								int state2 = -1;
HXDLIN( 540)								int _g2 = 0;
HXDLIN( 540)								while((_g2 < keys1->length)){
HXLINE( 540)									int key = keys1->__get(_g2);
HXDLIN( 540)									_g2 = (_g2 + 1);
HXDLIN( 540)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)4: {
HXLINE( 540)							{
HXLINE( 540)								 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 540)								int state = 1;
HXDLIN( 540)								int _g = 0;
HXDLIN( 540)								while((_g < keys1->length)){
HXLINE( 540)									int key = keys1->__get(_g);
HXDLIN( 540)									_g = (_g + 1);
HXDLIN( 540)									action->addKey(key,state);
            								}
            							}
HXDLIN( 540)							{
HXLINE( 540)								 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 540)								int state1 = 2;
HXDLIN( 540)								int _g1 = 0;
HXDLIN( 540)								while((_g1 < keys1->length)){
HXLINE( 540)									int key = keys1->__get(_g1);
HXDLIN( 540)									_g1 = (_g1 + 1);
HXDLIN( 540)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 540)							{
HXLINE( 540)								 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 540)								int state2 = -1;
HXDLIN( 540)								int _g2 = 0;
HXDLIN( 540)								while((_g2 < keys1->length)){
HXLINE( 540)									int key = keys1->__get(_g2);
HXDLIN( 540)									_g2 = (_g2 + 1);
HXDLIN( 540)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)5: {
HXLINE( 540)							 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 540)							int state = 2;
HXDLIN( 540)							int _g = 0;
HXDLIN( 540)							while((_g < keys1->length)){
HXLINE( 540)								int key = keys1->__get(_g);
HXDLIN( 540)								_g = (_g + 1);
HXDLIN( 540)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)6: {
HXLINE( 540)							 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 540)							int state = 2;
HXDLIN( 540)							int _g = 0;
HXDLIN( 540)							while((_g < keys1->length)){
HXLINE( 540)								int key = keys1->__get(_g);
HXDLIN( 540)								_g = (_g + 1);
HXDLIN( 540)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)7: {
HXLINE( 540)							 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 540)							int state = 2;
HXDLIN( 540)							int _g = 0;
HXDLIN( 540)							while((_g < keys1->length)){
HXLINE( 540)								int key = keys1->__get(_g);
HXDLIN( 540)								_g = (_g + 1);
HXDLIN( 540)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)8: {
HXLINE( 540)							 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 540)							int state = 2;
HXDLIN( 540)							int _g = 0;
HXDLIN( 540)							while((_g < keys1->length)){
HXLINE( 540)								int key = keys1->__get(_g);
HXDLIN( 540)								_g = (_g + 1);
HXDLIN( 540)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)9: {
HXLINE( 540)							 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 540)							int state = 2;
HXDLIN( 540)							int _g = 0;
HXDLIN( 540)							while((_g < keys1->length)){
HXLINE( 540)								int key = keys1->__get(_g);
HXDLIN( 540)								_g = (_g + 1);
HXDLIN( 540)								action->addKey(key,state);
            							}
            						}
            						break;
            					}
            				}
HXLINE( 541)				{
HXLINE( 541)					::Array< int > keys2 = ::Array_obj< int >::fromData( _hx_array_data_116e4296_760,2);
HXDLIN( 541)					switch((int)(::Control_obj::LEFT_dyn()->_hx_getIndex())){
            						case (int)0: {
HXLINE( 541)							{
HXLINE( 541)								 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 541)								int state = 1;
HXDLIN( 541)								int _g = 0;
HXDLIN( 541)								while((_g < keys2->length)){
HXLINE( 541)									int key = keys2->__get(_g);
HXDLIN( 541)									_g = (_g + 1);
HXDLIN( 541)									action->addKey(key,state);
            								}
            							}
HXDLIN( 541)							{
HXLINE( 541)								 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 541)								int state1 = 2;
HXDLIN( 541)								int _g1 = 0;
HXDLIN( 541)								while((_g1 < keys2->length)){
HXLINE( 541)									int key = keys2->__get(_g1);
HXDLIN( 541)									_g1 = (_g1 + 1);
HXDLIN( 541)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 541)							{
HXLINE( 541)								 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 541)								int state2 = -1;
HXDLIN( 541)								int _g2 = 0;
HXDLIN( 541)								while((_g2 < keys2->length)){
HXLINE( 541)									int key = keys2->__get(_g2);
HXDLIN( 541)									_g2 = (_g2 + 1);
HXDLIN( 541)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)1: {
HXLINE( 541)							{
HXLINE( 541)								 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 541)								int state = 1;
HXDLIN( 541)								int _g = 0;
HXDLIN( 541)								while((_g < keys2->length)){
HXLINE( 541)									int key = keys2->__get(_g);
HXDLIN( 541)									_g = (_g + 1);
HXDLIN( 541)									action->addKey(key,state);
            								}
            							}
HXDLIN( 541)							{
HXLINE( 541)								 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 541)								int state1 = 2;
HXDLIN( 541)								int _g1 = 0;
HXDLIN( 541)								while((_g1 < keys2->length)){
HXLINE( 541)									int key = keys2->__get(_g1);
HXDLIN( 541)									_g1 = (_g1 + 1);
HXDLIN( 541)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 541)							{
HXLINE( 541)								 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 541)								int state2 = -1;
HXDLIN( 541)								int _g2 = 0;
HXDLIN( 541)								while((_g2 < keys2->length)){
HXLINE( 541)									int key = keys2->__get(_g2);
HXDLIN( 541)									_g2 = (_g2 + 1);
HXDLIN( 541)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)2: {
HXLINE( 541)							{
HXLINE( 541)								 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 541)								int state = 1;
HXDLIN( 541)								int _g = 0;
HXDLIN( 541)								while((_g < keys2->length)){
HXLINE( 541)									int key = keys2->__get(_g);
HXDLIN( 541)									_g = (_g + 1);
HXDLIN( 541)									action->addKey(key,state);
            								}
            							}
HXDLIN( 541)							{
HXLINE( 541)								 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 541)								int state1 = 2;
HXDLIN( 541)								int _g1 = 0;
HXDLIN( 541)								while((_g1 < keys2->length)){
HXLINE( 541)									int key = keys2->__get(_g1);
HXDLIN( 541)									_g1 = (_g1 + 1);
HXDLIN( 541)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 541)							{
HXLINE( 541)								 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 541)								int state2 = -1;
HXDLIN( 541)								int _g2 = 0;
HXDLIN( 541)								while((_g2 < keys2->length)){
HXLINE( 541)									int key = keys2->__get(_g2);
HXDLIN( 541)									_g2 = (_g2 + 1);
HXDLIN( 541)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)3: {
HXLINE( 541)							{
HXLINE( 541)								 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 541)								int state = 1;
HXDLIN( 541)								int _g = 0;
HXDLIN( 541)								while((_g < keys2->length)){
HXLINE( 541)									int key = keys2->__get(_g);
HXDLIN( 541)									_g = (_g + 1);
HXDLIN( 541)									action->addKey(key,state);
            								}
            							}
HXDLIN( 541)							{
HXLINE( 541)								 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 541)								int state1 = 2;
HXDLIN( 541)								int _g1 = 0;
HXDLIN( 541)								while((_g1 < keys2->length)){
HXLINE( 541)									int key = keys2->__get(_g1);
HXDLIN( 541)									_g1 = (_g1 + 1);
HXDLIN( 541)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 541)							{
HXLINE( 541)								 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 541)								int state2 = -1;
HXDLIN( 541)								int _g2 = 0;
HXDLIN( 541)								while((_g2 < keys2->length)){
HXLINE( 541)									int key = keys2->__get(_g2);
HXDLIN( 541)									_g2 = (_g2 + 1);
HXDLIN( 541)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)4: {
HXLINE( 541)							{
HXLINE( 541)								 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 541)								int state = 1;
HXDLIN( 541)								int _g = 0;
HXDLIN( 541)								while((_g < keys2->length)){
HXLINE( 541)									int key = keys2->__get(_g);
HXDLIN( 541)									_g = (_g + 1);
HXDLIN( 541)									action->addKey(key,state);
            								}
            							}
HXDLIN( 541)							{
HXLINE( 541)								 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 541)								int state1 = 2;
HXDLIN( 541)								int _g1 = 0;
HXDLIN( 541)								while((_g1 < keys2->length)){
HXLINE( 541)									int key = keys2->__get(_g1);
HXDLIN( 541)									_g1 = (_g1 + 1);
HXDLIN( 541)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 541)							{
HXLINE( 541)								 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 541)								int state2 = -1;
HXDLIN( 541)								int _g2 = 0;
HXDLIN( 541)								while((_g2 < keys2->length)){
HXLINE( 541)									int key = keys2->__get(_g2);
HXDLIN( 541)									_g2 = (_g2 + 1);
HXDLIN( 541)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)5: {
HXLINE( 541)							 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 541)							int state = 2;
HXDLIN( 541)							int _g = 0;
HXDLIN( 541)							while((_g < keys2->length)){
HXLINE( 541)								int key = keys2->__get(_g);
HXDLIN( 541)								_g = (_g + 1);
HXDLIN( 541)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)6: {
HXLINE( 541)							 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 541)							int state = 2;
HXDLIN( 541)							int _g = 0;
HXDLIN( 541)							while((_g < keys2->length)){
HXLINE( 541)								int key = keys2->__get(_g);
HXDLIN( 541)								_g = (_g + 1);
HXDLIN( 541)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)7: {
HXLINE( 541)							 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 541)							int state = 2;
HXDLIN( 541)							int _g = 0;
HXDLIN( 541)							while((_g < keys2->length)){
HXLINE( 541)								int key = keys2->__get(_g);
HXDLIN( 541)								_g = (_g + 1);
HXDLIN( 541)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)8: {
HXLINE( 541)							 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 541)							int state = 2;
HXDLIN( 541)							int _g = 0;
HXDLIN( 541)							while((_g < keys2->length)){
HXLINE( 541)								int key = keys2->__get(_g);
HXDLIN( 541)								_g = (_g + 1);
HXDLIN( 541)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)9: {
HXLINE( 541)							 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 541)							int state = 2;
HXDLIN( 541)							int _g = 0;
HXDLIN( 541)							while((_g < keys2->length)){
HXLINE( 541)								int key = keys2->__get(_g);
HXDLIN( 541)								_g = (_g + 1);
HXDLIN( 541)								action->addKey(key,state);
            							}
            						}
            						break;
            					}
            				}
HXLINE( 542)				{
HXLINE( 542)					::Array< int > keys3 = ::Array_obj< int >::fromData( _hx_array_data_116e4296_761,2);
HXDLIN( 542)					switch((int)(::Control_obj::RIGHT_dyn()->_hx_getIndex())){
            						case (int)0: {
HXLINE( 542)							{
HXLINE( 542)								 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 542)								int state = 1;
HXDLIN( 542)								int _g = 0;
HXDLIN( 542)								while((_g < keys3->length)){
HXLINE( 542)									int key = keys3->__get(_g);
HXDLIN( 542)									_g = (_g + 1);
HXDLIN( 542)									action->addKey(key,state);
            								}
            							}
HXDLIN( 542)							{
HXLINE( 542)								 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 542)								int state1 = 2;
HXDLIN( 542)								int _g1 = 0;
HXDLIN( 542)								while((_g1 < keys3->length)){
HXLINE( 542)									int key = keys3->__get(_g1);
HXDLIN( 542)									_g1 = (_g1 + 1);
HXDLIN( 542)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 542)							{
HXLINE( 542)								 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 542)								int state2 = -1;
HXDLIN( 542)								int _g2 = 0;
HXDLIN( 542)								while((_g2 < keys3->length)){
HXLINE( 542)									int key = keys3->__get(_g2);
HXDLIN( 542)									_g2 = (_g2 + 1);
HXDLIN( 542)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)1: {
HXLINE( 542)							{
HXLINE( 542)								 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 542)								int state = 1;
HXDLIN( 542)								int _g = 0;
HXDLIN( 542)								while((_g < keys3->length)){
HXLINE( 542)									int key = keys3->__get(_g);
HXDLIN( 542)									_g = (_g + 1);
HXDLIN( 542)									action->addKey(key,state);
            								}
            							}
HXDLIN( 542)							{
HXLINE( 542)								 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 542)								int state1 = 2;
HXDLIN( 542)								int _g1 = 0;
HXDLIN( 542)								while((_g1 < keys3->length)){
HXLINE( 542)									int key = keys3->__get(_g1);
HXDLIN( 542)									_g1 = (_g1 + 1);
HXDLIN( 542)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 542)							{
HXLINE( 542)								 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 542)								int state2 = -1;
HXDLIN( 542)								int _g2 = 0;
HXDLIN( 542)								while((_g2 < keys3->length)){
HXLINE( 542)									int key = keys3->__get(_g2);
HXDLIN( 542)									_g2 = (_g2 + 1);
HXDLIN( 542)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)2: {
HXLINE( 542)							{
HXLINE( 542)								 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 542)								int state = 1;
HXDLIN( 542)								int _g = 0;
HXDLIN( 542)								while((_g < keys3->length)){
HXLINE( 542)									int key = keys3->__get(_g);
HXDLIN( 542)									_g = (_g + 1);
HXDLIN( 542)									action->addKey(key,state);
            								}
            							}
HXDLIN( 542)							{
HXLINE( 542)								 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 542)								int state1 = 2;
HXDLIN( 542)								int _g1 = 0;
HXDLIN( 542)								while((_g1 < keys3->length)){
HXLINE( 542)									int key = keys3->__get(_g1);
HXDLIN( 542)									_g1 = (_g1 + 1);
HXDLIN( 542)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 542)							{
HXLINE( 542)								 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 542)								int state2 = -1;
HXDLIN( 542)								int _g2 = 0;
HXDLIN( 542)								while((_g2 < keys3->length)){
HXLINE( 542)									int key = keys3->__get(_g2);
HXDLIN( 542)									_g2 = (_g2 + 1);
HXDLIN( 542)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)3: {
HXLINE( 542)							{
HXLINE( 542)								 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 542)								int state = 1;
HXDLIN( 542)								int _g = 0;
HXDLIN( 542)								while((_g < keys3->length)){
HXLINE( 542)									int key = keys3->__get(_g);
HXDLIN( 542)									_g = (_g + 1);
HXDLIN( 542)									action->addKey(key,state);
            								}
            							}
HXDLIN( 542)							{
HXLINE( 542)								 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 542)								int state1 = 2;
HXDLIN( 542)								int _g1 = 0;
HXDLIN( 542)								while((_g1 < keys3->length)){
HXLINE( 542)									int key = keys3->__get(_g1);
HXDLIN( 542)									_g1 = (_g1 + 1);
HXDLIN( 542)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 542)							{
HXLINE( 542)								 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 542)								int state2 = -1;
HXDLIN( 542)								int _g2 = 0;
HXDLIN( 542)								while((_g2 < keys3->length)){
HXLINE( 542)									int key = keys3->__get(_g2);
HXDLIN( 542)									_g2 = (_g2 + 1);
HXDLIN( 542)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)4: {
HXLINE( 542)							{
HXLINE( 542)								 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 542)								int state = 1;
HXDLIN( 542)								int _g = 0;
HXDLIN( 542)								while((_g < keys3->length)){
HXLINE( 542)									int key = keys3->__get(_g);
HXDLIN( 542)									_g = (_g + 1);
HXDLIN( 542)									action->addKey(key,state);
            								}
            							}
HXDLIN( 542)							{
HXLINE( 542)								 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 542)								int state1 = 2;
HXDLIN( 542)								int _g1 = 0;
HXDLIN( 542)								while((_g1 < keys3->length)){
HXLINE( 542)									int key = keys3->__get(_g1);
HXDLIN( 542)									_g1 = (_g1 + 1);
HXDLIN( 542)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 542)							{
HXLINE( 542)								 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 542)								int state2 = -1;
HXDLIN( 542)								int _g2 = 0;
HXDLIN( 542)								while((_g2 < keys3->length)){
HXLINE( 542)									int key = keys3->__get(_g2);
HXDLIN( 542)									_g2 = (_g2 + 1);
HXDLIN( 542)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)5: {
HXLINE( 542)							 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 542)							int state = 2;
HXDLIN( 542)							int _g = 0;
HXDLIN( 542)							while((_g < keys3->length)){
HXLINE( 542)								int key = keys3->__get(_g);
HXDLIN( 542)								_g = (_g + 1);
HXDLIN( 542)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)6: {
HXLINE( 542)							 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 542)							int state = 2;
HXDLIN( 542)							int _g = 0;
HXDLIN( 542)							while((_g < keys3->length)){
HXLINE( 542)								int key = keys3->__get(_g);
HXDLIN( 542)								_g = (_g + 1);
HXDLIN( 542)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)7: {
HXLINE( 542)							 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 542)							int state = 2;
HXDLIN( 542)							int _g = 0;
HXDLIN( 542)							while((_g < keys3->length)){
HXLINE( 542)								int key = keys3->__get(_g);
HXDLIN( 542)								_g = (_g + 1);
HXDLIN( 542)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)8: {
HXLINE( 542)							 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 542)							int state = 2;
HXDLIN( 542)							int _g = 0;
HXDLIN( 542)							while((_g < keys3->length)){
HXLINE( 542)								int key = keys3->__get(_g);
HXDLIN( 542)								_g = (_g + 1);
HXDLIN( 542)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)9: {
HXLINE( 542)							 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 542)							int state = 2;
HXDLIN( 542)							int _g = 0;
HXDLIN( 542)							while((_g < keys3->length)){
HXLINE( 542)								int key = keys3->__get(_g);
HXDLIN( 542)								_g = (_g + 1);
HXDLIN( 542)								action->addKey(key,state);
            							}
            						}
            						break;
            					}
            				}
HXLINE( 543)				{
HXLINE( 543)					::Array< int > keys4 = ::Array_obj< int >::fromData( _hx_array_data_116e4296_762,4);
HXDLIN( 543)					switch((int)(::Control_obj::ACCEPT_dyn()->_hx_getIndex())){
            						case (int)0: {
HXLINE( 543)							{
HXLINE( 543)								 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 543)								int state = 1;
HXDLIN( 543)								int _g = 0;
HXDLIN( 543)								while((_g < keys4->length)){
HXLINE( 543)									int key = keys4->__get(_g);
HXDLIN( 543)									_g = (_g + 1);
HXDLIN( 543)									action->addKey(key,state);
            								}
            							}
HXDLIN( 543)							{
HXLINE( 543)								 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 543)								int state1 = 2;
HXDLIN( 543)								int _g1 = 0;
HXDLIN( 543)								while((_g1 < keys4->length)){
HXLINE( 543)									int key = keys4->__get(_g1);
HXDLIN( 543)									_g1 = (_g1 + 1);
HXDLIN( 543)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 543)							{
HXLINE( 543)								 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 543)								int state2 = -1;
HXDLIN( 543)								int _g2 = 0;
HXDLIN( 543)								while((_g2 < keys4->length)){
HXLINE( 543)									int key = keys4->__get(_g2);
HXDLIN( 543)									_g2 = (_g2 + 1);
HXDLIN( 543)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)1: {
HXLINE( 543)							{
HXLINE( 543)								 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 543)								int state = 1;
HXDLIN( 543)								int _g = 0;
HXDLIN( 543)								while((_g < keys4->length)){
HXLINE( 543)									int key = keys4->__get(_g);
HXDLIN( 543)									_g = (_g + 1);
HXDLIN( 543)									action->addKey(key,state);
            								}
            							}
HXDLIN( 543)							{
HXLINE( 543)								 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 543)								int state1 = 2;
HXDLIN( 543)								int _g1 = 0;
HXDLIN( 543)								while((_g1 < keys4->length)){
HXLINE( 543)									int key = keys4->__get(_g1);
HXDLIN( 543)									_g1 = (_g1 + 1);
HXDLIN( 543)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 543)							{
HXLINE( 543)								 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 543)								int state2 = -1;
HXDLIN( 543)								int _g2 = 0;
HXDLIN( 543)								while((_g2 < keys4->length)){
HXLINE( 543)									int key = keys4->__get(_g2);
HXDLIN( 543)									_g2 = (_g2 + 1);
HXDLIN( 543)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)2: {
HXLINE( 543)							{
HXLINE( 543)								 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 543)								int state = 1;
HXDLIN( 543)								int _g = 0;
HXDLIN( 543)								while((_g < keys4->length)){
HXLINE( 543)									int key = keys4->__get(_g);
HXDLIN( 543)									_g = (_g + 1);
HXDLIN( 543)									action->addKey(key,state);
            								}
            							}
HXDLIN( 543)							{
HXLINE( 543)								 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 543)								int state1 = 2;
HXDLIN( 543)								int _g1 = 0;
HXDLIN( 543)								while((_g1 < keys4->length)){
HXLINE( 543)									int key = keys4->__get(_g1);
HXDLIN( 543)									_g1 = (_g1 + 1);
HXDLIN( 543)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 543)							{
HXLINE( 543)								 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 543)								int state2 = -1;
HXDLIN( 543)								int _g2 = 0;
HXDLIN( 543)								while((_g2 < keys4->length)){
HXLINE( 543)									int key = keys4->__get(_g2);
HXDLIN( 543)									_g2 = (_g2 + 1);
HXDLIN( 543)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)3: {
HXLINE( 543)							{
HXLINE( 543)								 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 543)								int state = 1;
HXDLIN( 543)								int _g = 0;
HXDLIN( 543)								while((_g < keys4->length)){
HXLINE( 543)									int key = keys4->__get(_g);
HXDLIN( 543)									_g = (_g + 1);
HXDLIN( 543)									action->addKey(key,state);
            								}
            							}
HXDLIN( 543)							{
HXLINE( 543)								 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 543)								int state1 = 2;
HXDLIN( 543)								int _g1 = 0;
HXDLIN( 543)								while((_g1 < keys4->length)){
HXLINE( 543)									int key = keys4->__get(_g1);
HXDLIN( 543)									_g1 = (_g1 + 1);
HXDLIN( 543)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 543)							{
HXLINE( 543)								 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 543)								int state2 = -1;
HXDLIN( 543)								int _g2 = 0;
HXDLIN( 543)								while((_g2 < keys4->length)){
HXLINE( 543)									int key = keys4->__get(_g2);
HXDLIN( 543)									_g2 = (_g2 + 1);
HXDLIN( 543)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)4: {
HXLINE( 543)							{
HXLINE( 543)								 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 543)								int state = 1;
HXDLIN( 543)								int _g = 0;
HXDLIN( 543)								while((_g < keys4->length)){
HXLINE( 543)									int key = keys4->__get(_g);
HXDLIN( 543)									_g = (_g + 1);
HXDLIN( 543)									action->addKey(key,state);
            								}
            							}
HXDLIN( 543)							{
HXLINE( 543)								 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 543)								int state1 = 2;
HXDLIN( 543)								int _g1 = 0;
HXDLIN( 543)								while((_g1 < keys4->length)){
HXLINE( 543)									int key = keys4->__get(_g1);
HXDLIN( 543)									_g1 = (_g1 + 1);
HXDLIN( 543)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 543)							{
HXLINE( 543)								 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 543)								int state2 = -1;
HXDLIN( 543)								int _g2 = 0;
HXDLIN( 543)								while((_g2 < keys4->length)){
HXLINE( 543)									int key = keys4->__get(_g2);
HXDLIN( 543)									_g2 = (_g2 + 1);
HXDLIN( 543)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)5: {
HXLINE( 543)							 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 543)							int state = 2;
HXDLIN( 543)							int _g = 0;
HXDLIN( 543)							while((_g < keys4->length)){
HXLINE( 543)								int key = keys4->__get(_g);
HXDLIN( 543)								_g = (_g + 1);
HXDLIN( 543)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)6: {
HXLINE( 543)							 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 543)							int state = 2;
HXDLIN( 543)							int _g = 0;
HXDLIN( 543)							while((_g < keys4->length)){
HXLINE( 543)								int key = keys4->__get(_g);
HXDLIN( 543)								_g = (_g + 1);
HXDLIN( 543)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)7: {
HXLINE( 543)							 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 543)							int state = 2;
HXDLIN( 543)							int _g = 0;
HXDLIN( 543)							while((_g < keys4->length)){
HXLINE( 543)								int key = keys4->__get(_g);
HXDLIN( 543)								_g = (_g + 1);
HXDLIN( 543)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)8: {
HXLINE( 543)							 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 543)							int state = 2;
HXDLIN( 543)							int _g = 0;
HXDLIN( 543)							while((_g < keys4->length)){
HXLINE( 543)								int key = keys4->__get(_g);
HXDLIN( 543)								_g = (_g + 1);
HXDLIN( 543)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)9: {
HXLINE( 543)							 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 543)							int state = 2;
HXDLIN( 543)							int _g = 0;
HXDLIN( 543)							while((_g < keys4->length)){
HXLINE( 543)								int key = keys4->__get(_g);
HXDLIN( 543)								_g = (_g + 1);
HXDLIN( 543)								action->addKey(key,state);
            							}
            						}
            						break;
            					}
            				}
HXLINE( 544)				{
HXLINE( 544)					::Array< int > keys5 = ::Array_obj< int >::fromData( _hx_array_data_116e4296_763,2);
HXDLIN( 544)					switch((int)(::Control_obj::BACK_dyn()->_hx_getIndex())){
            						case (int)0: {
HXLINE( 544)							{
HXLINE( 544)								 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 544)								int state = 1;
HXDLIN( 544)								int _g = 0;
HXDLIN( 544)								while((_g < keys5->length)){
HXLINE( 544)									int key = keys5->__get(_g);
HXDLIN( 544)									_g = (_g + 1);
HXDLIN( 544)									action->addKey(key,state);
            								}
            							}
HXDLIN( 544)							{
HXLINE( 544)								 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 544)								int state1 = 2;
HXDLIN( 544)								int _g1 = 0;
HXDLIN( 544)								while((_g1 < keys5->length)){
HXLINE( 544)									int key = keys5->__get(_g1);
HXDLIN( 544)									_g1 = (_g1 + 1);
HXDLIN( 544)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 544)							{
HXLINE( 544)								 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 544)								int state2 = -1;
HXDLIN( 544)								int _g2 = 0;
HXDLIN( 544)								while((_g2 < keys5->length)){
HXLINE( 544)									int key = keys5->__get(_g2);
HXDLIN( 544)									_g2 = (_g2 + 1);
HXDLIN( 544)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)1: {
HXLINE( 544)							{
HXLINE( 544)								 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 544)								int state = 1;
HXDLIN( 544)								int _g = 0;
HXDLIN( 544)								while((_g < keys5->length)){
HXLINE( 544)									int key = keys5->__get(_g);
HXDLIN( 544)									_g = (_g + 1);
HXDLIN( 544)									action->addKey(key,state);
            								}
            							}
HXDLIN( 544)							{
HXLINE( 544)								 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 544)								int state1 = 2;
HXDLIN( 544)								int _g1 = 0;
HXDLIN( 544)								while((_g1 < keys5->length)){
HXLINE( 544)									int key = keys5->__get(_g1);
HXDLIN( 544)									_g1 = (_g1 + 1);
HXDLIN( 544)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 544)							{
HXLINE( 544)								 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 544)								int state2 = -1;
HXDLIN( 544)								int _g2 = 0;
HXDLIN( 544)								while((_g2 < keys5->length)){
HXLINE( 544)									int key = keys5->__get(_g2);
HXDLIN( 544)									_g2 = (_g2 + 1);
HXDLIN( 544)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)2: {
HXLINE( 544)							{
HXLINE( 544)								 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 544)								int state = 1;
HXDLIN( 544)								int _g = 0;
HXDLIN( 544)								while((_g < keys5->length)){
HXLINE( 544)									int key = keys5->__get(_g);
HXDLIN( 544)									_g = (_g + 1);
HXDLIN( 544)									action->addKey(key,state);
            								}
            							}
HXDLIN( 544)							{
HXLINE( 544)								 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 544)								int state1 = 2;
HXDLIN( 544)								int _g1 = 0;
HXDLIN( 544)								while((_g1 < keys5->length)){
HXLINE( 544)									int key = keys5->__get(_g1);
HXDLIN( 544)									_g1 = (_g1 + 1);
HXDLIN( 544)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 544)							{
HXLINE( 544)								 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 544)								int state2 = -1;
HXDLIN( 544)								int _g2 = 0;
HXDLIN( 544)								while((_g2 < keys5->length)){
HXLINE( 544)									int key = keys5->__get(_g2);
HXDLIN( 544)									_g2 = (_g2 + 1);
HXDLIN( 544)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)3: {
HXLINE( 544)							{
HXLINE( 544)								 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 544)								int state = 1;
HXDLIN( 544)								int _g = 0;
HXDLIN( 544)								while((_g < keys5->length)){
HXLINE( 544)									int key = keys5->__get(_g);
HXDLIN( 544)									_g = (_g + 1);
HXDLIN( 544)									action->addKey(key,state);
            								}
            							}
HXDLIN( 544)							{
HXLINE( 544)								 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 544)								int state1 = 2;
HXDLIN( 544)								int _g1 = 0;
HXDLIN( 544)								while((_g1 < keys5->length)){
HXLINE( 544)									int key = keys5->__get(_g1);
HXDLIN( 544)									_g1 = (_g1 + 1);
HXDLIN( 544)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 544)							{
HXLINE( 544)								 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 544)								int state2 = -1;
HXDLIN( 544)								int _g2 = 0;
HXDLIN( 544)								while((_g2 < keys5->length)){
HXLINE( 544)									int key = keys5->__get(_g2);
HXDLIN( 544)									_g2 = (_g2 + 1);
HXDLIN( 544)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)4: {
HXLINE( 544)							{
HXLINE( 544)								 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 544)								int state = 1;
HXDLIN( 544)								int _g = 0;
HXDLIN( 544)								while((_g < keys5->length)){
HXLINE( 544)									int key = keys5->__get(_g);
HXDLIN( 544)									_g = (_g + 1);
HXDLIN( 544)									action->addKey(key,state);
            								}
            							}
HXDLIN( 544)							{
HXLINE( 544)								 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 544)								int state1 = 2;
HXDLIN( 544)								int _g1 = 0;
HXDLIN( 544)								while((_g1 < keys5->length)){
HXLINE( 544)									int key = keys5->__get(_g1);
HXDLIN( 544)									_g1 = (_g1 + 1);
HXDLIN( 544)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 544)							{
HXLINE( 544)								 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 544)								int state2 = -1;
HXDLIN( 544)								int _g2 = 0;
HXDLIN( 544)								while((_g2 < keys5->length)){
HXLINE( 544)									int key = keys5->__get(_g2);
HXDLIN( 544)									_g2 = (_g2 + 1);
HXDLIN( 544)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)5: {
HXLINE( 544)							 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 544)							int state = 2;
HXDLIN( 544)							int _g = 0;
HXDLIN( 544)							while((_g < keys5->length)){
HXLINE( 544)								int key = keys5->__get(_g);
HXDLIN( 544)								_g = (_g + 1);
HXDLIN( 544)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)6: {
HXLINE( 544)							 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 544)							int state = 2;
HXDLIN( 544)							int _g = 0;
HXDLIN( 544)							while((_g < keys5->length)){
HXLINE( 544)								int key = keys5->__get(_g);
HXDLIN( 544)								_g = (_g + 1);
HXDLIN( 544)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)7: {
HXLINE( 544)							 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 544)							int state = 2;
HXDLIN( 544)							int _g = 0;
HXDLIN( 544)							while((_g < keys5->length)){
HXLINE( 544)								int key = keys5->__get(_g);
HXDLIN( 544)								_g = (_g + 1);
HXDLIN( 544)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)8: {
HXLINE( 544)							 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 544)							int state = 2;
HXDLIN( 544)							int _g = 0;
HXDLIN( 544)							while((_g < keys5->length)){
HXLINE( 544)								int key = keys5->__get(_g);
HXDLIN( 544)								_g = (_g + 1);
HXDLIN( 544)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)9: {
HXLINE( 544)							 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 544)							int state = 2;
HXDLIN( 544)							int _g = 0;
HXDLIN( 544)							while((_g < keys5->length)){
HXLINE( 544)								int key = keys5->__get(_g);
HXDLIN( 544)								_g = (_g + 1);
HXDLIN( 544)								action->addKey(key,state);
            							}
            						}
            						break;
            					}
            				}
HXLINE( 545)				{
HXLINE( 545)					::Array< int > keys6 = ::Array_obj< int >::fromData( _hx_array_data_116e4296_764,3);
HXDLIN( 545)					switch((int)(::Control_obj::PAUSE_dyn()->_hx_getIndex())){
            						case (int)0: {
HXLINE( 545)							{
HXLINE( 545)								 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 545)								int state = 1;
HXDLIN( 545)								int _g = 0;
HXDLIN( 545)								while((_g < keys6->length)){
HXLINE( 545)									int key = keys6->__get(_g);
HXDLIN( 545)									_g = (_g + 1);
HXDLIN( 545)									action->addKey(key,state);
            								}
            							}
HXDLIN( 545)							{
HXLINE( 545)								 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 545)								int state1 = 2;
HXDLIN( 545)								int _g1 = 0;
HXDLIN( 545)								while((_g1 < keys6->length)){
HXLINE( 545)									int key = keys6->__get(_g1);
HXDLIN( 545)									_g1 = (_g1 + 1);
HXDLIN( 545)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 545)							{
HXLINE( 545)								 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 545)								int state2 = -1;
HXDLIN( 545)								int _g2 = 0;
HXDLIN( 545)								while((_g2 < keys6->length)){
HXLINE( 545)									int key = keys6->__get(_g2);
HXDLIN( 545)									_g2 = (_g2 + 1);
HXDLIN( 545)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)1: {
HXLINE( 545)							{
HXLINE( 545)								 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 545)								int state = 1;
HXDLIN( 545)								int _g = 0;
HXDLIN( 545)								while((_g < keys6->length)){
HXLINE( 545)									int key = keys6->__get(_g);
HXDLIN( 545)									_g = (_g + 1);
HXDLIN( 545)									action->addKey(key,state);
            								}
            							}
HXDLIN( 545)							{
HXLINE( 545)								 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 545)								int state1 = 2;
HXDLIN( 545)								int _g1 = 0;
HXDLIN( 545)								while((_g1 < keys6->length)){
HXLINE( 545)									int key = keys6->__get(_g1);
HXDLIN( 545)									_g1 = (_g1 + 1);
HXDLIN( 545)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 545)							{
HXLINE( 545)								 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 545)								int state2 = -1;
HXDLIN( 545)								int _g2 = 0;
HXDLIN( 545)								while((_g2 < keys6->length)){
HXLINE( 545)									int key = keys6->__get(_g2);
HXDLIN( 545)									_g2 = (_g2 + 1);
HXDLIN( 545)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)2: {
HXLINE( 545)							{
HXLINE( 545)								 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 545)								int state = 1;
HXDLIN( 545)								int _g = 0;
HXDLIN( 545)								while((_g < keys6->length)){
HXLINE( 545)									int key = keys6->__get(_g);
HXDLIN( 545)									_g = (_g + 1);
HXDLIN( 545)									action->addKey(key,state);
            								}
            							}
HXDLIN( 545)							{
HXLINE( 545)								 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 545)								int state1 = 2;
HXDLIN( 545)								int _g1 = 0;
HXDLIN( 545)								while((_g1 < keys6->length)){
HXLINE( 545)									int key = keys6->__get(_g1);
HXDLIN( 545)									_g1 = (_g1 + 1);
HXDLIN( 545)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 545)							{
HXLINE( 545)								 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 545)								int state2 = -1;
HXDLIN( 545)								int _g2 = 0;
HXDLIN( 545)								while((_g2 < keys6->length)){
HXLINE( 545)									int key = keys6->__get(_g2);
HXDLIN( 545)									_g2 = (_g2 + 1);
HXDLIN( 545)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)3: {
HXLINE( 545)							{
HXLINE( 545)								 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 545)								int state = 1;
HXDLIN( 545)								int _g = 0;
HXDLIN( 545)								while((_g < keys6->length)){
HXLINE( 545)									int key = keys6->__get(_g);
HXDLIN( 545)									_g = (_g + 1);
HXDLIN( 545)									action->addKey(key,state);
            								}
            							}
HXDLIN( 545)							{
HXLINE( 545)								 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 545)								int state1 = 2;
HXDLIN( 545)								int _g1 = 0;
HXDLIN( 545)								while((_g1 < keys6->length)){
HXLINE( 545)									int key = keys6->__get(_g1);
HXDLIN( 545)									_g1 = (_g1 + 1);
HXDLIN( 545)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 545)							{
HXLINE( 545)								 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 545)								int state2 = -1;
HXDLIN( 545)								int _g2 = 0;
HXDLIN( 545)								while((_g2 < keys6->length)){
HXLINE( 545)									int key = keys6->__get(_g2);
HXDLIN( 545)									_g2 = (_g2 + 1);
HXDLIN( 545)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)4: {
HXLINE( 545)							{
HXLINE( 545)								 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 545)								int state = 1;
HXDLIN( 545)								int _g = 0;
HXDLIN( 545)								while((_g < keys6->length)){
HXLINE( 545)									int key = keys6->__get(_g);
HXDLIN( 545)									_g = (_g + 1);
HXDLIN( 545)									action->addKey(key,state);
            								}
            							}
HXDLIN( 545)							{
HXLINE( 545)								 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 545)								int state1 = 2;
HXDLIN( 545)								int _g1 = 0;
HXDLIN( 545)								while((_g1 < keys6->length)){
HXLINE( 545)									int key = keys6->__get(_g1);
HXDLIN( 545)									_g1 = (_g1 + 1);
HXDLIN( 545)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 545)							{
HXLINE( 545)								 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 545)								int state2 = -1;
HXDLIN( 545)								int _g2 = 0;
HXDLIN( 545)								while((_g2 < keys6->length)){
HXLINE( 545)									int key = keys6->__get(_g2);
HXDLIN( 545)									_g2 = (_g2 + 1);
HXDLIN( 545)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)5: {
HXLINE( 545)							 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 545)							int state = 2;
HXDLIN( 545)							int _g = 0;
HXDLIN( 545)							while((_g < keys6->length)){
HXLINE( 545)								int key = keys6->__get(_g);
HXDLIN( 545)								_g = (_g + 1);
HXDLIN( 545)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)6: {
HXLINE( 545)							 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 545)							int state = 2;
HXDLIN( 545)							int _g = 0;
HXDLIN( 545)							while((_g < keys6->length)){
HXLINE( 545)								int key = keys6->__get(_g);
HXDLIN( 545)								_g = (_g + 1);
HXDLIN( 545)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)7: {
HXLINE( 545)							 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 545)							int state = 2;
HXDLIN( 545)							int _g = 0;
HXDLIN( 545)							while((_g < keys6->length)){
HXLINE( 545)								int key = keys6->__get(_g);
HXDLIN( 545)								_g = (_g + 1);
HXDLIN( 545)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)8: {
HXLINE( 545)							 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 545)							int state = 2;
HXDLIN( 545)							int _g = 0;
HXDLIN( 545)							while((_g < keys6->length)){
HXLINE( 545)								int key = keys6->__get(_g);
HXDLIN( 545)								_g = (_g + 1);
HXDLIN( 545)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)9: {
HXLINE( 545)							 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 545)							int state = 2;
HXDLIN( 545)							int _g = 0;
HXDLIN( 545)							while((_g < keys6->length)){
HXLINE( 545)								int key = keys6->__get(_g);
HXDLIN( 545)								_g = (_g + 1);
HXDLIN( 545)								action->addKey(key,state);
            							}
            						}
            						break;
            					}
            				}
HXLINE( 546)				{
HXLINE( 546)					::Array< int > keys7 = ::Array_obj< int >::fromData( _hx_array_data_116e4296_765,1);
HXDLIN( 546)					switch((int)(::Control_obj::RESET_dyn()->_hx_getIndex())){
            						case (int)0: {
HXLINE( 546)							{
HXLINE( 546)								 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 546)								int state = 1;
HXDLIN( 546)								int _g = 0;
HXDLIN( 546)								while((_g < keys7->length)){
HXLINE( 546)									int key = keys7->__get(_g);
HXDLIN( 546)									_g = (_g + 1);
HXDLIN( 546)									action->addKey(key,state);
            								}
            							}
HXDLIN( 546)							{
HXLINE( 546)								 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 546)								int state1 = 2;
HXDLIN( 546)								int _g1 = 0;
HXDLIN( 546)								while((_g1 < keys7->length)){
HXLINE( 546)									int key = keys7->__get(_g1);
HXDLIN( 546)									_g1 = (_g1 + 1);
HXDLIN( 546)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 546)							{
HXLINE( 546)								 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 546)								int state2 = -1;
HXDLIN( 546)								int _g2 = 0;
HXDLIN( 546)								while((_g2 < keys7->length)){
HXLINE( 546)									int key = keys7->__get(_g2);
HXDLIN( 546)									_g2 = (_g2 + 1);
HXDLIN( 546)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)1: {
HXLINE( 546)							{
HXLINE( 546)								 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 546)								int state = 1;
HXDLIN( 546)								int _g = 0;
HXDLIN( 546)								while((_g < keys7->length)){
HXLINE( 546)									int key = keys7->__get(_g);
HXDLIN( 546)									_g = (_g + 1);
HXDLIN( 546)									action->addKey(key,state);
            								}
            							}
HXDLIN( 546)							{
HXLINE( 546)								 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 546)								int state1 = 2;
HXDLIN( 546)								int _g1 = 0;
HXDLIN( 546)								while((_g1 < keys7->length)){
HXLINE( 546)									int key = keys7->__get(_g1);
HXDLIN( 546)									_g1 = (_g1 + 1);
HXDLIN( 546)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 546)							{
HXLINE( 546)								 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 546)								int state2 = -1;
HXDLIN( 546)								int _g2 = 0;
HXDLIN( 546)								while((_g2 < keys7->length)){
HXLINE( 546)									int key = keys7->__get(_g2);
HXDLIN( 546)									_g2 = (_g2 + 1);
HXDLIN( 546)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)2: {
HXLINE( 546)							{
HXLINE( 546)								 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 546)								int state = 1;
HXDLIN( 546)								int _g = 0;
HXDLIN( 546)								while((_g < keys7->length)){
HXLINE( 546)									int key = keys7->__get(_g);
HXDLIN( 546)									_g = (_g + 1);
HXDLIN( 546)									action->addKey(key,state);
            								}
            							}
HXDLIN( 546)							{
HXLINE( 546)								 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 546)								int state1 = 2;
HXDLIN( 546)								int _g1 = 0;
HXDLIN( 546)								while((_g1 < keys7->length)){
HXLINE( 546)									int key = keys7->__get(_g1);
HXDLIN( 546)									_g1 = (_g1 + 1);
HXDLIN( 546)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 546)							{
HXLINE( 546)								 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 546)								int state2 = -1;
HXDLIN( 546)								int _g2 = 0;
HXDLIN( 546)								while((_g2 < keys7->length)){
HXLINE( 546)									int key = keys7->__get(_g2);
HXDLIN( 546)									_g2 = (_g2 + 1);
HXDLIN( 546)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)3: {
HXLINE( 546)							{
HXLINE( 546)								 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 546)								int state = 1;
HXDLIN( 546)								int _g = 0;
HXDLIN( 546)								while((_g < keys7->length)){
HXLINE( 546)									int key = keys7->__get(_g);
HXDLIN( 546)									_g = (_g + 1);
HXDLIN( 546)									action->addKey(key,state);
            								}
            							}
HXDLIN( 546)							{
HXLINE( 546)								 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 546)								int state1 = 2;
HXDLIN( 546)								int _g1 = 0;
HXDLIN( 546)								while((_g1 < keys7->length)){
HXLINE( 546)									int key = keys7->__get(_g1);
HXDLIN( 546)									_g1 = (_g1 + 1);
HXDLIN( 546)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 546)							{
HXLINE( 546)								 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 546)								int state2 = -1;
HXDLIN( 546)								int _g2 = 0;
HXDLIN( 546)								while((_g2 < keys7->length)){
HXLINE( 546)									int key = keys7->__get(_g2);
HXDLIN( 546)									_g2 = (_g2 + 1);
HXDLIN( 546)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)4: {
HXLINE( 546)							{
HXLINE( 546)								 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 546)								int state = 1;
HXDLIN( 546)								int _g = 0;
HXDLIN( 546)								while((_g < keys7->length)){
HXLINE( 546)									int key = keys7->__get(_g);
HXDLIN( 546)									_g = (_g + 1);
HXDLIN( 546)									action->addKey(key,state);
            								}
            							}
HXDLIN( 546)							{
HXLINE( 546)								 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 546)								int state1 = 2;
HXDLIN( 546)								int _g1 = 0;
HXDLIN( 546)								while((_g1 < keys7->length)){
HXLINE( 546)									int key = keys7->__get(_g1);
HXDLIN( 546)									_g1 = (_g1 + 1);
HXDLIN( 546)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 546)							{
HXLINE( 546)								 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 546)								int state2 = -1;
HXDLIN( 546)								int _g2 = 0;
HXDLIN( 546)								while((_g2 < keys7->length)){
HXLINE( 546)									int key = keys7->__get(_g2);
HXDLIN( 546)									_g2 = (_g2 + 1);
HXDLIN( 546)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)5: {
HXLINE( 546)							 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 546)							int state = 2;
HXDLIN( 546)							int _g = 0;
HXDLIN( 546)							while((_g < keys7->length)){
HXLINE( 546)								int key = keys7->__get(_g);
HXDLIN( 546)								_g = (_g + 1);
HXDLIN( 546)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)6: {
HXLINE( 546)							 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 546)							int state = 2;
HXDLIN( 546)							int _g = 0;
HXDLIN( 546)							while((_g < keys7->length)){
HXLINE( 546)								int key = keys7->__get(_g);
HXDLIN( 546)								_g = (_g + 1);
HXDLIN( 546)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)7: {
HXLINE( 546)							 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 546)							int state = 2;
HXDLIN( 546)							int _g = 0;
HXDLIN( 546)							while((_g < keys7->length)){
HXLINE( 546)								int key = keys7->__get(_g);
HXDLIN( 546)								_g = (_g + 1);
HXDLIN( 546)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)8: {
HXLINE( 546)							 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 546)							int state = 2;
HXDLIN( 546)							int _g = 0;
HXDLIN( 546)							while((_g < keys7->length)){
HXLINE( 546)								int key = keys7->__get(_g);
HXDLIN( 546)								_g = (_g + 1);
HXDLIN( 546)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)9: {
HXLINE( 546)							 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 546)							int state = 2;
HXDLIN( 546)							int _g = 0;
HXDLIN( 546)							while((_g < keys7->length)){
HXLINE( 546)								int key = keys7->__get(_g);
HXDLIN( 546)								_g = (_g + 1);
HXDLIN( 546)								action->addKey(key,state);
            							}
            						}
            						break;
            					}
            				}
HXLINE( 547)				{
HXLINE( 547)					::Array< int > keys8 = ::Array_obj< int >::__new(0);
HXDLIN( 547)					switch((int)(::Control_obj::CHEAT_dyn()->_hx_getIndex())){
            						case (int)0: {
HXLINE( 547)							{
HXLINE( 547)								 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 547)								int state = 1;
HXDLIN( 547)								int _g = 0;
HXDLIN( 547)								while((_g < keys8->length)){
HXLINE( 547)									int key = keys8->__get(_g);
HXDLIN( 547)									_g = (_g + 1);
HXDLIN( 547)									action->addKey(key,state);
            								}
            							}
HXDLIN( 547)							{
HXLINE( 547)								 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 547)								int state1 = 2;
HXDLIN( 547)								int _g1 = 0;
HXDLIN( 547)								while((_g1 < keys8->length)){
HXLINE( 547)									int key = keys8->__get(_g1);
HXDLIN( 547)									_g1 = (_g1 + 1);
HXDLIN( 547)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 547)							{
HXLINE( 547)								 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 547)								int state2 = -1;
HXDLIN( 547)								int _g2 = 0;
HXDLIN( 547)								while((_g2 < keys8->length)){
HXLINE( 547)									int key = keys8->__get(_g2);
HXDLIN( 547)									_g2 = (_g2 + 1);
HXDLIN( 547)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)1: {
HXLINE( 547)							{
HXLINE( 547)								 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 547)								int state = 1;
HXDLIN( 547)								int _g = 0;
HXDLIN( 547)								while((_g < keys8->length)){
HXLINE( 547)									int key = keys8->__get(_g);
HXDLIN( 547)									_g = (_g + 1);
HXDLIN( 547)									action->addKey(key,state);
            								}
            							}
HXDLIN( 547)							{
HXLINE( 547)								 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 547)								int state1 = 2;
HXDLIN( 547)								int _g1 = 0;
HXDLIN( 547)								while((_g1 < keys8->length)){
HXLINE( 547)									int key = keys8->__get(_g1);
HXDLIN( 547)									_g1 = (_g1 + 1);
HXDLIN( 547)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 547)							{
HXLINE( 547)								 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 547)								int state2 = -1;
HXDLIN( 547)								int _g2 = 0;
HXDLIN( 547)								while((_g2 < keys8->length)){
HXLINE( 547)									int key = keys8->__get(_g2);
HXDLIN( 547)									_g2 = (_g2 + 1);
HXDLIN( 547)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)2: {
HXLINE( 547)							{
HXLINE( 547)								 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 547)								int state = 1;
HXDLIN( 547)								int _g = 0;
HXDLIN( 547)								while((_g < keys8->length)){
HXLINE( 547)									int key = keys8->__get(_g);
HXDLIN( 547)									_g = (_g + 1);
HXDLIN( 547)									action->addKey(key,state);
            								}
            							}
HXDLIN( 547)							{
HXLINE( 547)								 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 547)								int state1 = 2;
HXDLIN( 547)								int _g1 = 0;
HXDLIN( 547)								while((_g1 < keys8->length)){
HXLINE( 547)									int key = keys8->__get(_g1);
HXDLIN( 547)									_g1 = (_g1 + 1);
HXDLIN( 547)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 547)							{
HXLINE( 547)								 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 547)								int state2 = -1;
HXDLIN( 547)								int _g2 = 0;
HXDLIN( 547)								while((_g2 < keys8->length)){
HXLINE( 547)									int key = keys8->__get(_g2);
HXDLIN( 547)									_g2 = (_g2 + 1);
HXDLIN( 547)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)3: {
HXLINE( 547)							{
HXLINE( 547)								 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 547)								int state = 1;
HXDLIN( 547)								int _g = 0;
HXDLIN( 547)								while((_g < keys8->length)){
HXLINE( 547)									int key = keys8->__get(_g);
HXDLIN( 547)									_g = (_g + 1);
HXDLIN( 547)									action->addKey(key,state);
            								}
            							}
HXDLIN( 547)							{
HXLINE( 547)								 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 547)								int state1 = 2;
HXDLIN( 547)								int _g1 = 0;
HXDLIN( 547)								while((_g1 < keys8->length)){
HXLINE( 547)									int key = keys8->__get(_g1);
HXDLIN( 547)									_g1 = (_g1 + 1);
HXDLIN( 547)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 547)							{
HXLINE( 547)								 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 547)								int state2 = -1;
HXDLIN( 547)								int _g2 = 0;
HXDLIN( 547)								while((_g2 < keys8->length)){
HXLINE( 547)									int key = keys8->__get(_g2);
HXDLIN( 547)									_g2 = (_g2 + 1);
HXDLIN( 547)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)4: {
HXLINE( 547)							{
HXLINE( 547)								 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 547)								int state = 1;
HXDLIN( 547)								int _g = 0;
HXDLIN( 547)								while((_g < keys8->length)){
HXLINE( 547)									int key = keys8->__get(_g);
HXDLIN( 547)									_g = (_g + 1);
HXDLIN( 547)									action->addKey(key,state);
            								}
            							}
HXDLIN( 547)							{
HXLINE( 547)								 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 547)								int state1 = 2;
HXDLIN( 547)								int _g1 = 0;
HXDLIN( 547)								while((_g1 < keys8->length)){
HXLINE( 547)									int key = keys8->__get(_g1);
HXDLIN( 547)									_g1 = (_g1 + 1);
HXDLIN( 547)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 547)							{
HXLINE( 547)								 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 547)								int state2 = -1;
HXDLIN( 547)								int _g2 = 0;
HXDLIN( 547)								while((_g2 < keys8->length)){
HXLINE( 547)									int key = keys8->__get(_g2);
HXDLIN( 547)									_g2 = (_g2 + 1);
HXDLIN( 547)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)5: {
HXLINE( 547)							 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 547)							int state = 2;
HXDLIN( 547)							int _g = 0;
HXDLIN( 547)							while((_g < keys8->length)){
HXLINE( 547)								int key = keys8->__get(_g);
HXDLIN( 547)								_g = (_g + 1);
HXDLIN( 547)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)6: {
HXLINE( 547)							 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 547)							int state = 2;
HXDLIN( 547)							int _g = 0;
HXDLIN( 547)							while((_g < keys8->length)){
HXLINE( 547)								int key = keys8->__get(_g);
HXDLIN( 547)								_g = (_g + 1);
HXDLIN( 547)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)7: {
HXLINE( 547)							 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 547)							int state = 2;
HXDLIN( 547)							int _g = 0;
HXDLIN( 547)							while((_g < keys8->length)){
HXLINE( 547)								int key = keys8->__get(_g);
HXDLIN( 547)								_g = (_g + 1);
HXDLIN( 547)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)8: {
HXLINE( 547)							 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 547)							int state = 2;
HXDLIN( 547)							int _g = 0;
HXDLIN( 547)							while((_g < keys8->length)){
HXLINE( 547)								int key = keys8->__get(_g);
HXDLIN( 547)								_g = (_g + 1);
HXDLIN( 547)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)9: {
HXLINE( 547)							 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 547)							int state = 2;
HXDLIN( 547)							int _g = 0;
HXDLIN( 547)							while((_g < keys8->length)){
HXLINE( 547)								int key = keys8->__get(_g);
HXDLIN( 547)								_g = (_g + 1);
HXDLIN( 547)								action->addKey(key,state);
            							}
            						}
            						break;
            					}
            				}
            			}
            			break;
            			case (int)1: {
HXLINE( 557)				if (scheme->_hx_getBool(0)) {
HXLINE( 549)					{
HXLINE( 549)						::Array< int > keys = ::Array_obj< int >::fromData( _hx_array_data_116e4296_766,2);
HXDLIN( 549)						switch((int)(::Control_obj::UP_dyn()->_hx_getIndex())){
            							case (int)0: {
HXLINE( 549)								{
HXLINE( 549)									 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 549)									int state = 1;
HXDLIN( 549)									int _g = 0;
HXDLIN( 549)									while((_g < keys->length)){
HXLINE( 549)										int key = keys->__get(_g);
HXDLIN( 549)										_g = (_g + 1);
HXDLIN( 549)										action->addKey(key,state);
            									}
            								}
HXDLIN( 549)								{
HXLINE( 549)									 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 549)									int state1 = 2;
HXDLIN( 549)									int _g1 = 0;
HXDLIN( 549)									while((_g1 < keys->length)){
HXLINE( 549)										int key = keys->__get(_g1);
HXDLIN( 549)										_g1 = (_g1 + 1);
HXDLIN( 549)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 549)								{
HXLINE( 549)									 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 549)									int state2 = -1;
HXDLIN( 549)									int _g2 = 0;
HXDLIN( 549)									while((_g2 < keys->length)){
HXLINE( 549)										int key = keys->__get(_g2);
HXDLIN( 549)										_g2 = (_g2 + 1);
HXDLIN( 549)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)1: {
HXLINE( 549)								{
HXLINE( 549)									 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 549)									int state = 1;
HXDLIN( 549)									int _g = 0;
HXDLIN( 549)									while((_g < keys->length)){
HXLINE( 549)										int key = keys->__get(_g);
HXDLIN( 549)										_g = (_g + 1);
HXDLIN( 549)										action->addKey(key,state);
            									}
            								}
HXDLIN( 549)								{
HXLINE( 549)									 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 549)									int state1 = 2;
HXDLIN( 549)									int _g1 = 0;
HXDLIN( 549)									while((_g1 < keys->length)){
HXLINE( 549)										int key = keys->__get(_g1);
HXDLIN( 549)										_g1 = (_g1 + 1);
HXDLIN( 549)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 549)								{
HXLINE( 549)									 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 549)									int state2 = -1;
HXDLIN( 549)									int _g2 = 0;
HXDLIN( 549)									while((_g2 < keys->length)){
HXLINE( 549)										int key = keys->__get(_g2);
HXDLIN( 549)										_g2 = (_g2 + 1);
HXDLIN( 549)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)2: {
HXLINE( 549)								{
HXLINE( 549)									 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 549)									int state = 1;
HXDLIN( 549)									int _g = 0;
HXDLIN( 549)									while((_g < keys->length)){
HXLINE( 549)										int key = keys->__get(_g);
HXDLIN( 549)										_g = (_g + 1);
HXDLIN( 549)										action->addKey(key,state);
            									}
            								}
HXDLIN( 549)								{
HXLINE( 549)									 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 549)									int state1 = 2;
HXDLIN( 549)									int _g1 = 0;
HXDLIN( 549)									while((_g1 < keys->length)){
HXLINE( 549)										int key = keys->__get(_g1);
HXDLIN( 549)										_g1 = (_g1 + 1);
HXDLIN( 549)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 549)								{
HXLINE( 549)									 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 549)									int state2 = -1;
HXDLIN( 549)									int _g2 = 0;
HXDLIN( 549)									while((_g2 < keys->length)){
HXLINE( 549)										int key = keys->__get(_g2);
HXDLIN( 549)										_g2 = (_g2 + 1);
HXDLIN( 549)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)3: {
HXLINE( 549)								{
HXLINE( 549)									 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 549)									int state = 1;
HXDLIN( 549)									int _g = 0;
HXDLIN( 549)									while((_g < keys->length)){
HXLINE( 549)										int key = keys->__get(_g);
HXDLIN( 549)										_g = (_g + 1);
HXDLIN( 549)										action->addKey(key,state);
            									}
            								}
HXDLIN( 549)								{
HXLINE( 549)									 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 549)									int state1 = 2;
HXDLIN( 549)									int _g1 = 0;
HXDLIN( 549)									while((_g1 < keys->length)){
HXLINE( 549)										int key = keys->__get(_g1);
HXDLIN( 549)										_g1 = (_g1 + 1);
HXDLIN( 549)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 549)								{
HXLINE( 549)									 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 549)									int state2 = -1;
HXDLIN( 549)									int _g2 = 0;
HXDLIN( 549)									while((_g2 < keys->length)){
HXLINE( 549)										int key = keys->__get(_g2);
HXDLIN( 549)										_g2 = (_g2 + 1);
HXDLIN( 549)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)4: {
HXLINE( 549)								{
HXLINE( 549)									 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 549)									int state = 1;
HXDLIN( 549)									int _g = 0;
HXDLIN( 549)									while((_g < keys->length)){
HXLINE( 549)										int key = keys->__get(_g);
HXDLIN( 549)										_g = (_g + 1);
HXDLIN( 549)										action->addKey(key,state);
            									}
            								}
HXDLIN( 549)								{
HXLINE( 549)									 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 549)									int state1 = 2;
HXDLIN( 549)									int _g1 = 0;
HXDLIN( 549)									while((_g1 < keys->length)){
HXLINE( 549)										int key = keys->__get(_g1);
HXDLIN( 549)										_g1 = (_g1 + 1);
HXDLIN( 549)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 549)								{
HXLINE( 549)									 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 549)									int state2 = -1;
HXDLIN( 549)									int _g2 = 0;
HXDLIN( 549)									while((_g2 < keys->length)){
HXLINE( 549)										int key = keys->__get(_g2);
HXDLIN( 549)										_g2 = (_g2 + 1);
HXDLIN( 549)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)5: {
HXLINE( 549)								 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 549)								int state = 2;
HXDLIN( 549)								int _g = 0;
HXDLIN( 549)								while((_g < keys->length)){
HXLINE( 549)									int key = keys->__get(_g);
HXDLIN( 549)									_g = (_g + 1);
HXDLIN( 549)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)6: {
HXLINE( 549)								 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 549)								int state = 2;
HXDLIN( 549)								int _g = 0;
HXDLIN( 549)								while((_g < keys->length)){
HXLINE( 549)									int key = keys->__get(_g);
HXDLIN( 549)									_g = (_g + 1);
HXDLIN( 549)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)7: {
HXLINE( 549)								 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 549)								int state = 2;
HXDLIN( 549)								int _g = 0;
HXDLIN( 549)								while((_g < keys->length)){
HXLINE( 549)									int key = keys->__get(_g);
HXDLIN( 549)									_g = (_g + 1);
HXDLIN( 549)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)8: {
HXLINE( 549)								 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 549)								int state = 2;
HXDLIN( 549)								int _g = 0;
HXDLIN( 549)								while((_g < keys->length)){
HXLINE( 549)									int key = keys->__get(_g);
HXDLIN( 549)									_g = (_g + 1);
HXDLIN( 549)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)9: {
HXLINE( 549)								 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 549)								int state = 2;
HXDLIN( 549)								int _g = 0;
HXDLIN( 549)								while((_g < keys->length)){
HXLINE( 549)									int key = keys->__get(_g);
HXDLIN( 549)									_g = (_g + 1);
HXDLIN( 549)									action->addKey(key,state);
            								}
            							}
            							break;
            						}
            					}
HXLINE( 550)					{
HXLINE( 550)						::Array< int > keys1 = ::Array_obj< int >::fromData( _hx_array_data_116e4296_767,2);
HXDLIN( 550)						switch((int)(::Control_obj::DOWN_dyn()->_hx_getIndex())){
            							case (int)0: {
HXLINE( 550)								{
HXLINE( 550)									 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 550)									int state = 1;
HXDLIN( 550)									int _g = 0;
HXDLIN( 550)									while((_g < keys1->length)){
HXLINE( 550)										int key = keys1->__get(_g);
HXDLIN( 550)										_g = (_g + 1);
HXDLIN( 550)										action->addKey(key,state);
            									}
            								}
HXDLIN( 550)								{
HXLINE( 550)									 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 550)									int state1 = 2;
HXDLIN( 550)									int _g1 = 0;
HXDLIN( 550)									while((_g1 < keys1->length)){
HXLINE( 550)										int key = keys1->__get(_g1);
HXDLIN( 550)										_g1 = (_g1 + 1);
HXDLIN( 550)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 550)								{
HXLINE( 550)									 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 550)									int state2 = -1;
HXDLIN( 550)									int _g2 = 0;
HXDLIN( 550)									while((_g2 < keys1->length)){
HXLINE( 550)										int key = keys1->__get(_g2);
HXDLIN( 550)										_g2 = (_g2 + 1);
HXDLIN( 550)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)1: {
HXLINE( 550)								{
HXLINE( 550)									 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 550)									int state = 1;
HXDLIN( 550)									int _g = 0;
HXDLIN( 550)									while((_g < keys1->length)){
HXLINE( 550)										int key = keys1->__get(_g);
HXDLIN( 550)										_g = (_g + 1);
HXDLIN( 550)										action->addKey(key,state);
            									}
            								}
HXDLIN( 550)								{
HXLINE( 550)									 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 550)									int state1 = 2;
HXDLIN( 550)									int _g1 = 0;
HXDLIN( 550)									while((_g1 < keys1->length)){
HXLINE( 550)										int key = keys1->__get(_g1);
HXDLIN( 550)										_g1 = (_g1 + 1);
HXDLIN( 550)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 550)								{
HXLINE( 550)									 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 550)									int state2 = -1;
HXDLIN( 550)									int _g2 = 0;
HXDLIN( 550)									while((_g2 < keys1->length)){
HXLINE( 550)										int key = keys1->__get(_g2);
HXDLIN( 550)										_g2 = (_g2 + 1);
HXDLIN( 550)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)2: {
HXLINE( 550)								{
HXLINE( 550)									 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 550)									int state = 1;
HXDLIN( 550)									int _g = 0;
HXDLIN( 550)									while((_g < keys1->length)){
HXLINE( 550)										int key = keys1->__get(_g);
HXDLIN( 550)										_g = (_g + 1);
HXDLIN( 550)										action->addKey(key,state);
            									}
            								}
HXDLIN( 550)								{
HXLINE( 550)									 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 550)									int state1 = 2;
HXDLIN( 550)									int _g1 = 0;
HXDLIN( 550)									while((_g1 < keys1->length)){
HXLINE( 550)										int key = keys1->__get(_g1);
HXDLIN( 550)										_g1 = (_g1 + 1);
HXDLIN( 550)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 550)								{
HXLINE( 550)									 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 550)									int state2 = -1;
HXDLIN( 550)									int _g2 = 0;
HXDLIN( 550)									while((_g2 < keys1->length)){
HXLINE( 550)										int key = keys1->__get(_g2);
HXDLIN( 550)										_g2 = (_g2 + 1);
HXDLIN( 550)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)3: {
HXLINE( 550)								{
HXLINE( 550)									 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 550)									int state = 1;
HXDLIN( 550)									int _g = 0;
HXDLIN( 550)									while((_g < keys1->length)){
HXLINE( 550)										int key = keys1->__get(_g);
HXDLIN( 550)										_g = (_g + 1);
HXDLIN( 550)										action->addKey(key,state);
            									}
            								}
HXDLIN( 550)								{
HXLINE( 550)									 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 550)									int state1 = 2;
HXDLIN( 550)									int _g1 = 0;
HXDLIN( 550)									while((_g1 < keys1->length)){
HXLINE( 550)										int key = keys1->__get(_g1);
HXDLIN( 550)										_g1 = (_g1 + 1);
HXDLIN( 550)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 550)								{
HXLINE( 550)									 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 550)									int state2 = -1;
HXDLIN( 550)									int _g2 = 0;
HXDLIN( 550)									while((_g2 < keys1->length)){
HXLINE( 550)										int key = keys1->__get(_g2);
HXDLIN( 550)										_g2 = (_g2 + 1);
HXDLIN( 550)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)4: {
HXLINE( 550)								{
HXLINE( 550)									 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 550)									int state = 1;
HXDLIN( 550)									int _g = 0;
HXDLIN( 550)									while((_g < keys1->length)){
HXLINE( 550)										int key = keys1->__get(_g);
HXDLIN( 550)										_g = (_g + 1);
HXDLIN( 550)										action->addKey(key,state);
            									}
            								}
HXDLIN( 550)								{
HXLINE( 550)									 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 550)									int state1 = 2;
HXDLIN( 550)									int _g1 = 0;
HXDLIN( 550)									while((_g1 < keys1->length)){
HXLINE( 550)										int key = keys1->__get(_g1);
HXDLIN( 550)										_g1 = (_g1 + 1);
HXDLIN( 550)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 550)								{
HXLINE( 550)									 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 550)									int state2 = -1;
HXDLIN( 550)									int _g2 = 0;
HXDLIN( 550)									while((_g2 < keys1->length)){
HXLINE( 550)										int key = keys1->__get(_g2);
HXDLIN( 550)										_g2 = (_g2 + 1);
HXDLIN( 550)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)5: {
HXLINE( 550)								 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 550)								int state = 2;
HXDLIN( 550)								int _g = 0;
HXDLIN( 550)								while((_g < keys1->length)){
HXLINE( 550)									int key = keys1->__get(_g);
HXDLIN( 550)									_g = (_g + 1);
HXDLIN( 550)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)6: {
HXLINE( 550)								 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 550)								int state = 2;
HXDLIN( 550)								int _g = 0;
HXDLIN( 550)								while((_g < keys1->length)){
HXLINE( 550)									int key = keys1->__get(_g);
HXDLIN( 550)									_g = (_g + 1);
HXDLIN( 550)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)7: {
HXLINE( 550)								 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 550)								int state = 2;
HXDLIN( 550)								int _g = 0;
HXDLIN( 550)								while((_g < keys1->length)){
HXLINE( 550)									int key = keys1->__get(_g);
HXDLIN( 550)									_g = (_g + 1);
HXDLIN( 550)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)8: {
HXLINE( 550)								 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 550)								int state = 2;
HXDLIN( 550)								int _g = 0;
HXDLIN( 550)								while((_g < keys1->length)){
HXLINE( 550)									int key = keys1->__get(_g);
HXDLIN( 550)									_g = (_g + 1);
HXDLIN( 550)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)9: {
HXLINE( 550)								 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 550)								int state = 2;
HXDLIN( 550)								int _g = 0;
HXDLIN( 550)								while((_g < keys1->length)){
HXLINE( 550)									int key = keys1->__get(_g);
HXDLIN( 550)									_g = (_g + 1);
HXDLIN( 550)									action->addKey(key,state);
            								}
            							}
            							break;
            						}
            					}
HXLINE( 551)					{
HXLINE( 551)						::Array< int > keys2 = ::Array_obj< int >::fromData( _hx_array_data_116e4296_768,2);
HXDLIN( 551)						switch((int)(::Control_obj::LEFT_dyn()->_hx_getIndex())){
            							case (int)0: {
HXLINE( 551)								{
HXLINE( 551)									 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 551)									int state = 1;
HXDLIN( 551)									int _g = 0;
HXDLIN( 551)									while((_g < keys2->length)){
HXLINE( 551)										int key = keys2->__get(_g);
HXDLIN( 551)										_g = (_g + 1);
HXDLIN( 551)										action->addKey(key,state);
            									}
            								}
HXDLIN( 551)								{
HXLINE( 551)									 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 551)									int state1 = 2;
HXDLIN( 551)									int _g1 = 0;
HXDLIN( 551)									while((_g1 < keys2->length)){
HXLINE( 551)										int key = keys2->__get(_g1);
HXDLIN( 551)										_g1 = (_g1 + 1);
HXDLIN( 551)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 551)								{
HXLINE( 551)									 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 551)									int state2 = -1;
HXDLIN( 551)									int _g2 = 0;
HXDLIN( 551)									while((_g2 < keys2->length)){
HXLINE( 551)										int key = keys2->__get(_g2);
HXDLIN( 551)										_g2 = (_g2 + 1);
HXDLIN( 551)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)1: {
HXLINE( 551)								{
HXLINE( 551)									 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 551)									int state = 1;
HXDLIN( 551)									int _g = 0;
HXDLIN( 551)									while((_g < keys2->length)){
HXLINE( 551)										int key = keys2->__get(_g);
HXDLIN( 551)										_g = (_g + 1);
HXDLIN( 551)										action->addKey(key,state);
            									}
            								}
HXDLIN( 551)								{
HXLINE( 551)									 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 551)									int state1 = 2;
HXDLIN( 551)									int _g1 = 0;
HXDLIN( 551)									while((_g1 < keys2->length)){
HXLINE( 551)										int key = keys2->__get(_g1);
HXDLIN( 551)										_g1 = (_g1 + 1);
HXDLIN( 551)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 551)								{
HXLINE( 551)									 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 551)									int state2 = -1;
HXDLIN( 551)									int _g2 = 0;
HXDLIN( 551)									while((_g2 < keys2->length)){
HXLINE( 551)										int key = keys2->__get(_g2);
HXDLIN( 551)										_g2 = (_g2 + 1);
HXDLIN( 551)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)2: {
HXLINE( 551)								{
HXLINE( 551)									 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 551)									int state = 1;
HXDLIN( 551)									int _g = 0;
HXDLIN( 551)									while((_g < keys2->length)){
HXLINE( 551)										int key = keys2->__get(_g);
HXDLIN( 551)										_g = (_g + 1);
HXDLIN( 551)										action->addKey(key,state);
            									}
            								}
HXDLIN( 551)								{
HXLINE( 551)									 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 551)									int state1 = 2;
HXDLIN( 551)									int _g1 = 0;
HXDLIN( 551)									while((_g1 < keys2->length)){
HXLINE( 551)										int key = keys2->__get(_g1);
HXDLIN( 551)										_g1 = (_g1 + 1);
HXDLIN( 551)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 551)								{
HXLINE( 551)									 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 551)									int state2 = -1;
HXDLIN( 551)									int _g2 = 0;
HXDLIN( 551)									while((_g2 < keys2->length)){
HXLINE( 551)										int key = keys2->__get(_g2);
HXDLIN( 551)										_g2 = (_g2 + 1);
HXDLIN( 551)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)3: {
HXLINE( 551)								{
HXLINE( 551)									 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 551)									int state = 1;
HXDLIN( 551)									int _g = 0;
HXDLIN( 551)									while((_g < keys2->length)){
HXLINE( 551)										int key = keys2->__get(_g);
HXDLIN( 551)										_g = (_g + 1);
HXDLIN( 551)										action->addKey(key,state);
            									}
            								}
HXDLIN( 551)								{
HXLINE( 551)									 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 551)									int state1 = 2;
HXDLIN( 551)									int _g1 = 0;
HXDLIN( 551)									while((_g1 < keys2->length)){
HXLINE( 551)										int key = keys2->__get(_g1);
HXDLIN( 551)										_g1 = (_g1 + 1);
HXDLIN( 551)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 551)								{
HXLINE( 551)									 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 551)									int state2 = -1;
HXDLIN( 551)									int _g2 = 0;
HXDLIN( 551)									while((_g2 < keys2->length)){
HXLINE( 551)										int key = keys2->__get(_g2);
HXDLIN( 551)										_g2 = (_g2 + 1);
HXDLIN( 551)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)4: {
HXLINE( 551)								{
HXLINE( 551)									 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 551)									int state = 1;
HXDLIN( 551)									int _g = 0;
HXDLIN( 551)									while((_g < keys2->length)){
HXLINE( 551)										int key = keys2->__get(_g);
HXDLIN( 551)										_g = (_g + 1);
HXDLIN( 551)										action->addKey(key,state);
            									}
            								}
HXDLIN( 551)								{
HXLINE( 551)									 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 551)									int state1 = 2;
HXDLIN( 551)									int _g1 = 0;
HXDLIN( 551)									while((_g1 < keys2->length)){
HXLINE( 551)										int key = keys2->__get(_g1);
HXDLIN( 551)										_g1 = (_g1 + 1);
HXDLIN( 551)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 551)								{
HXLINE( 551)									 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 551)									int state2 = -1;
HXDLIN( 551)									int _g2 = 0;
HXDLIN( 551)									while((_g2 < keys2->length)){
HXLINE( 551)										int key = keys2->__get(_g2);
HXDLIN( 551)										_g2 = (_g2 + 1);
HXDLIN( 551)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)5: {
HXLINE( 551)								 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 551)								int state = 2;
HXDLIN( 551)								int _g = 0;
HXDLIN( 551)								while((_g < keys2->length)){
HXLINE( 551)									int key = keys2->__get(_g);
HXDLIN( 551)									_g = (_g + 1);
HXDLIN( 551)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)6: {
HXLINE( 551)								 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 551)								int state = 2;
HXDLIN( 551)								int _g = 0;
HXDLIN( 551)								while((_g < keys2->length)){
HXLINE( 551)									int key = keys2->__get(_g);
HXDLIN( 551)									_g = (_g + 1);
HXDLIN( 551)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)7: {
HXLINE( 551)								 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 551)								int state = 2;
HXDLIN( 551)								int _g = 0;
HXDLIN( 551)								while((_g < keys2->length)){
HXLINE( 551)									int key = keys2->__get(_g);
HXDLIN( 551)									_g = (_g + 1);
HXDLIN( 551)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)8: {
HXLINE( 551)								 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 551)								int state = 2;
HXDLIN( 551)								int _g = 0;
HXDLIN( 551)								while((_g < keys2->length)){
HXLINE( 551)									int key = keys2->__get(_g);
HXDLIN( 551)									_g = (_g + 1);
HXDLIN( 551)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)9: {
HXLINE( 551)								 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 551)								int state = 2;
HXDLIN( 551)								int _g = 0;
HXDLIN( 551)								while((_g < keys2->length)){
HXLINE( 551)									int key = keys2->__get(_g);
HXDLIN( 551)									_g = (_g + 1);
HXDLIN( 551)									action->addKey(key,state);
            								}
            							}
            							break;
            						}
            					}
HXLINE( 552)					{
HXLINE( 552)						::Array< int > keys3 = ::Array_obj< int >::fromData( _hx_array_data_116e4296_769,2);
HXDLIN( 552)						switch((int)(::Control_obj::RIGHT_dyn()->_hx_getIndex())){
            							case (int)0: {
HXLINE( 552)								{
HXLINE( 552)									 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 552)									int state = 1;
HXDLIN( 552)									int _g = 0;
HXDLIN( 552)									while((_g < keys3->length)){
HXLINE( 552)										int key = keys3->__get(_g);
HXDLIN( 552)										_g = (_g + 1);
HXDLIN( 552)										action->addKey(key,state);
            									}
            								}
HXDLIN( 552)								{
HXLINE( 552)									 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 552)									int state1 = 2;
HXDLIN( 552)									int _g1 = 0;
HXDLIN( 552)									while((_g1 < keys3->length)){
HXLINE( 552)										int key = keys3->__get(_g1);
HXDLIN( 552)										_g1 = (_g1 + 1);
HXDLIN( 552)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 552)								{
HXLINE( 552)									 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 552)									int state2 = -1;
HXDLIN( 552)									int _g2 = 0;
HXDLIN( 552)									while((_g2 < keys3->length)){
HXLINE( 552)										int key = keys3->__get(_g2);
HXDLIN( 552)										_g2 = (_g2 + 1);
HXDLIN( 552)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)1: {
HXLINE( 552)								{
HXLINE( 552)									 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 552)									int state = 1;
HXDLIN( 552)									int _g = 0;
HXDLIN( 552)									while((_g < keys3->length)){
HXLINE( 552)										int key = keys3->__get(_g);
HXDLIN( 552)										_g = (_g + 1);
HXDLIN( 552)										action->addKey(key,state);
            									}
            								}
HXDLIN( 552)								{
HXLINE( 552)									 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 552)									int state1 = 2;
HXDLIN( 552)									int _g1 = 0;
HXDLIN( 552)									while((_g1 < keys3->length)){
HXLINE( 552)										int key = keys3->__get(_g1);
HXDLIN( 552)										_g1 = (_g1 + 1);
HXDLIN( 552)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 552)								{
HXLINE( 552)									 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 552)									int state2 = -1;
HXDLIN( 552)									int _g2 = 0;
HXDLIN( 552)									while((_g2 < keys3->length)){
HXLINE( 552)										int key = keys3->__get(_g2);
HXDLIN( 552)										_g2 = (_g2 + 1);
HXDLIN( 552)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)2: {
HXLINE( 552)								{
HXLINE( 552)									 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 552)									int state = 1;
HXDLIN( 552)									int _g = 0;
HXDLIN( 552)									while((_g < keys3->length)){
HXLINE( 552)										int key = keys3->__get(_g);
HXDLIN( 552)										_g = (_g + 1);
HXDLIN( 552)										action->addKey(key,state);
            									}
            								}
HXDLIN( 552)								{
HXLINE( 552)									 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 552)									int state1 = 2;
HXDLIN( 552)									int _g1 = 0;
HXDLIN( 552)									while((_g1 < keys3->length)){
HXLINE( 552)										int key = keys3->__get(_g1);
HXDLIN( 552)										_g1 = (_g1 + 1);
HXDLIN( 552)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 552)								{
HXLINE( 552)									 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 552)									int state2 = -1;
HXDLIN( 552)									int _g2 = 0;
HXDLIN( 552)									while((_g2 < keys3->length)){
HXLINE( 552)										int key = keys3->__get(_g2);
HXDLIN( 552)										_g2 = (_g2 + 1);
HXDLIN( 552)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)3: {
HXLINE( 552)								{
HXLINE( 552)									 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 552)									int state = 1;
HXDLIN( 552)									int _g = 0;
HXDLIN( 552)									while((_g < keys3->length)){
HXLINE( 552)										int key = keys3->__get(_g);
HXDLIN( 552)										_g = (_g + 1);
HXDLIN( 552)										action->addKey(key,state);
            									}
            								}
HXDLIN( 552)								{
HXLINE( 552)									 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 552)									int state1 = 2;
HXDLIN( 552)									int _g1 = 0;
HXDLIN( 552)									while((_g1 < keys3->length)){
HXLINE( 552)										int key = keys3->__get(_g1);
HXDLIN( 552)										_g1 = (_g1 + 1);
HXDLIN( 552)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 552)								{
HXLINE( 552)									 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 552)									int state2 = -1;
HXDLIN( 552)									int _g2 = 0;
HXDLIN( 552)									while((_g2 < keys3->length)){
HXLINE( 552)										int key = keys3->__get(_g2);
HXDLIN( 552)										_g2 = (_g2 + 1);
HXDLIN( 552)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)4: {
HXLINE( 552)								{
HXLINE( 552)									 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 552)									int state = 1;
HXDLIN( 552)									int _g = 0;
HXDLIN( 552)									while((_g < keys3->length)){
HXLINE( 552)										int key = keys3->__get(_g);
HXDLIN( 552)										_g = (_g + 1);
HXDLIN( 552)										action->addKey(key,state);
            									}
            								}
HXDLIN( 552)								{
HXLINE( 552)									 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 552)									int state1 = 2;
HXDLIN( 552)									int _g1 = 0;
HXDLIN( 552)									while((_g1 < keys3->length)){
HXLINE( 552)										int key = keys3->__get(_g1);
HXDLIN( 552)										_g1 = (_g1 + 1);
HXDLIN( 552)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 552)								{
HXLINE( 552)									 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 552)									int state2 = -1;
HXDLIN( 552)									int _g2 = 0;
HXDLIN( 552)									while((_g2 < keys3->length)){
HXLINE( 552)										int key = keys3->__get(_g2);
HXDLIN( 552)										_g2 = (_g2 + 1);
HXDLIN( 552)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)5: {
HXLINE( 552)								 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 552)								int state = 2;
HXDLIN( 552)								int _g = 0;
HXDLIN( 552)								while((_g < keys3->length)){
HXLINE( 552)									int key = keys3->__get(_g);
HXDLIN( 552)									_g = (_g + 1);
HXDLIN( 552)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)6: {
HXLINE( 552)								 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 552)								int state = 2;
HXDLIN( 552)								int _g = 0;
HXDLIN( 552)								while((_g < keys3->length)){
HXLINE( 552)									int key = keys3->__get(_g);
HXDLIN( 552)									_g = (_g + 1);
HXDLIN( 552)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)7: {
HXLINE( 552)								 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 552)								int state = 2;
HXDLIN( 552)								int _g = 0;
HXDLIN( 552)								while((_g < keys3->length)){
HXLINE( 552)									int key = keys3->__get(_g);
HXDLIN( 552)									_g = (_g + 1);
HXDLIN( 552)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)8: {
HXLINE( 552)								 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 552)								int state = 2;
HXDLIN( 552)								int _g = 0;
HXDLIN( 552)								while((_g < keys3->length)){
HXLINE( 552)									int key = keys3->__get(_g);
HXDLIN( 552)									_g = (_g + 1);
HXDLIN( 552)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)9: {
HXLINE( 552)								 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 552)								int state = 2;
HXDLIN( 552)								int _g = 0;
HXDLIN( 552)								while((_g < keys3->length)){
HXLINE( 552)									int key = keys3->__get(_g);
HXDLIN( 552)									_g = (_g + 1);
HXDLIN( 552)									action->addKey(key,state);
            								}
            							}
            							break;
            						}
            					}
HXLINE( 553)					{
HXLINE( 553)						::Array< int > keys4 = ::Array_obj< int >::fromData( _hx_array_data_116e4296_770,4);
HXDLIN( 553)						switch((int)(::Control_obj::ACCEPT_dyn()->_hx_getIndex())){
            							case (int)0: {
HXLINE( 553)								{
HXLINE( 553)									 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 553)									int state = 1;
HXDLIN( 553)									int _g = 0;
HXDLIN( 553)									while((_g < keys4->length)){
HXLINE( 553)										int key = keys4->__get(_g);
HXDLIN( 553)										_g = (_g + 1);
HXDLIN( 553)										action->addKey(key,state);
            									}
            								}
HXDLIN( 553)								{
HXLINE( 553)									 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 553)									int state1 = 2;
HXDLIN( 553)									int _g1 = 0;
HXDLIN( 553)									while((_g1 < keys4->length)){
HXLINE( 553)										int key = keys4->__get(_g1);
HXDLIN( 553)										_g1 = (_g1 + 1);
HXDLIN( 553)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 553)								{
HXLINE( 553)									 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 553)									int state2 = -1;
HXDLIN( 553)									int _g2 = 0;
HXDLIN( 553)									while((_g2 < keys4->length)){
HXLINE( 553)										int key = keys4->__get(_g2);
HXDLIN( 553)										_g2 = (_g2 + 1);
HXDLIN( 553)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)1: {
HXLINE( 553)								{
HXLINE( 553)									 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 553)									int state = 1;
HXDLIN( 553)									int _g = 0;
HXDLIN( 553)									while((_g < keys4->length)){
HXLINE( 553)										int key = keys4->__get(_g);
HXDLIN( 553)										_g = (_g + 1);
HXDLIN( 553)										action->addKey(key,state);
            									}
            								}
HXDLIN( 553)								{
HXLINE( 553)									 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 553)									int state1 = 2;
HXDLIN( 553)									int _g1 = 0;
HXDLIN( 553)									while((_g1 < keys4->length)){
HXLINE( 553)										int key = keys4->__get(_g1);
HXDLIN( 553)										_g1 = (_g1 + 1);
HXDLIN( 553)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 553)								{
HXLINE( 553)									 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 553)									int state2 = -1;
HXDLIN( 553)									int _g2 = 0;
HXDLIN( 553)									while((_g2 < keys4->length)){
HXLINE( 553)										int key = keys4->__get(_g2);
HXDLIN( 553)										_g2 = (_g2 + 1);
HXDLIN( 553)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)2: {
HXLINE( 553)								{
HXLINE( 553)									 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 553)									int state = 1;
HXDLIN( 553)									int _g = 0;
HXDLIN( 553)									while((_g < keys4->length)){
HXLINE( 553)										int key = keys4->__get(_g);
HXDLIN( 553)										_g = (_g + 1);
HXDLIN( 553)										action->addKey(key,state);
            									}
            								}
HXDLIN( 553)								{
HXLINE( 553)									 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 553)									int state1 = 2;
HXDLIN( 553)									int _g1 = 0;
HXDLIN( 553)									while((_g1 < keys4->length)){
HXLINE( 553)										int key = keys4->__get(_g1);
HXDLIN( 553)										_g1 = (_g1 + 1);
HXDLIN( 553)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 553)								{
HXLINE( 553)									 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 553)									int state2 = -1;
HXDLIN( 553)									int _g2 = 0;
HXDLIN( 553)									while((_g2 < keys4->length)){
HXLINE( 553)										int key = keys4->__get(_g2);
HXDLIN( 553)										_g2 = (_g2 + 1);
HXDLIN( 553)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)3: {
HXLINE( 553)								{
HXLINE( 553)									 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 553)									int state = 1;
HXDLIN( 553)									int _g = 0;
HXDLIN( 553)									while((_g < keys4->length)){
HXLINE( 553)										int key = keys4->__get(_g);
HXDLIN( 553)										_g = (_g + 1);
HXDLIN( 553)										action->addKey(key,state);
            									}
            								}
HXDLIN( 553)								{
HXLINE( 553)									 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 553)									int state1 = 2;
HXDLIN( 553)									int _g1 = 0;
HXDLIN( 553)									while((_g1 < keys4->length)){
HXLINE( 553)										int key = keys4->__get(_g1);
HXDLIN( 553)										_g1 = (_g1 + 1);
HXDLIN( 553)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 553)								{
HXLINE( 553)									 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 553)									int state2 = -1;
HXDLIN( 553)									int _g2 = 0;
HXDLIN( 553)									while((_g2 < keys4->length)){
HXLINE( 553)										int key = keys4->__get(_g2);
HXDLIN( 553)										_g2 = (_g2 + 1);
HXDLIN( 553)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)4: {
HXLINE( 553)								{
HXLINE( 553)									 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 553)									int state = 1;
HXDLIN( 553)									int _g = 0;
HXDLIN( 553)									while((_g < keys4->length)){
HXLINE( 553)										int key = keys4->__get(_g);
HXDLIN( 553)										_g = (_g + 1);
HXDLIN( 553)										action->addKey(key,state);
            									}
            								}
HXDLIN( 553)								{
HXLINE( 553)									 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 553)									int state1 = 2;
HXDLIN( 553)									int _g1 = 0;
HXDLIN( 553)									while((_g1 < keys4->length)){
HXLINE( 553)										int key = keys4->__get(_g1);
HXDLIN( 553)										_g1 = (_g1 + 1);
HXDLIN( 553)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 553)								{
HXLINE( 553)									 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 553)									int state2 = -1;
HXDLIN( 553)									int _g2 = 0;
HXDLIN( 553)									while((_g2 < keys4->length)){
HXLINE( 553)										int key = keys4->__get(_g2);
HXDLIN( 553)										_g2 = (_g2 + 1);
HXDLIN( 553)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)5: {
HXLINE( 553)								 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 553)								int state = 2;
HXDLIN( 553)								int _g = 0;
HXDLIN( 553)								while((_g < keys4->length)){
HXLINE( 553)									int key = keys4->__get(_g);
HXDLIN( 553)									_g = (_g + 1);
HXDLIN( 553)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)6: {
HXLINE( 553)								 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 553)								int state = 2;
HXDLIN( 553)								int _g = 0;
HXDLIN( 553)								while((_g < keys4->length)){
HXLINE( 553)									int key = keys4->__get(_g);
HXDLIN( 553)									_g = (_g + 1);
HXDLIN( 553)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)7: {
HXLINE( 553)								 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 553)								int state = 2;
HXDLIN( 553)								int _g = 0;
HXDLIN( 553)								while((_g < keys4->length)){
HXLINE( 553)									int key = keys4->__get(_g);
HXDLIN( 553)									_g = (_g + 1);
HXDLIN( 553)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)8: {
HXLINE( 553)								 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 553)								int state = 2;
HXDLIN( 553)								int _g = 0;
HXDLIN( 553)								while((_g < keys4->length)){
HXLINE( 553)									int key = keys4->__get(_g);
HXDLIN( 553)									_g = (_g + 1);
HXDLIN( 553)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)9: {
HXLINE( 553)								 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 553)								int state = 2;
HXDLIN( 553)								int _g = 0;
HXDLIN( 553)								while((_g < keys4->length)){
HXLINE( 553)									int key = keys4->__get(_g);
HXDLIN( 553)									_g = (_g + 1);
HXDLIN( 553)									action->addKey(key,state);
            								}
            							}
            							break;
            						}
            					}
HXLINE( 554)					{
HXLINE( 554)						::Array< int > keys5 = ::Array_obj< int >::fromData( _hx_array_data_116e4296_771,2);
HXDLIN( 554)						switch((int)(::Control_obj::BACK_dyn()->_hx_getIndex())){
            							case (int)0: {
HXLINE( 554)								{
HXLINE( 554)									 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 554)									int state = 1;
HXDLIN( 554)									int _g = 0;
HXDLIN( 554)									while((_g < keys5->length)){
HXLINE( 554)										int key = keys5->__get(_g);
HXDLIN( 554)										_g = (_g + 1);
HXDLIN( 554)										action->addKey(key,state);
            									}
            								}
HXDLIN( 554)								{
HXLINE( 554)									 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 554)									int state1 = 2;
HXDLIN( 554)									int _g1 = 0;
HXDLIN( 554)									while((_g1 < keys5->length)){
HXLINE( 554)										int key = keys5->__get(_g1);
HXDLIN( 554)										_g1 = (_g1 + 1);
HXDLIN( 554)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 554)								{
HXLINE( 554)									 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 554)									int state2 = -1;
HXDLIN( 554)									int _g2 = 0;
HXDLIN( 554)									while((_g2 < keys5->length)){
HXLINE( 554)										int key = keys5->__get(_g2);
HXDLIN( 554)										_g2 = (_g2 + 1);
HXDLIN( 554)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)1: {
HXLINE( 554)								{
HXLINE( 554)									 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 554)									int state = 1;
HXDLIN( 554)									int _g = 0;
HXDLIN( 554)									while((_g < keys5->length)){
HXLINE( 554)										int key = keys5->__get(_g);
HXDLIN( 554)										_g = (_g + 1);
HXDLIN( 554)										action->addKey(key,state);
            									}
            								}
HXDLIN( 554)								{
HXLINE( 554)									 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 554)									int state1 = 2;
HXDLIN( 554)									int _g1 = 0;
HXDLIN( 554)									while((_g1 < keys5->length)){
HXLINE( 554)										int key = keys5->__get(_g1);
HXDLIN( 554)										_g1 = (_g1 + 1);
HXDLIN( 554)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 554)								{
HXLINE( 554)									 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 554)									int state2 = -1;
HXDLIN( 554)									int _g2 = 0;
HXDLIN( 554)									while((_g2 < keys5->length)){
HXLINE( 554)										int key = keys5->__get(_g2);
HXDLIN( 554)										_g2 = (_g2 + 1);
HXDLIN( 554)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)2: {
HXLINE( 554)								{
HXLINE( 554)									 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 554)									int state = 1;
HXDLIN( 554)									int _g = 0;
HXDLIN( 554)									while((_g < keys5->length)){
HXLINE( 554)										int key = keys5->__get(_g);
HXDLIN( 554)										_g = (_g + 1);
HXDLIN( 554)										action->addKey(key,state);
            									}
            								}
HXDLIN( 554)								{
HXLINE( 554)									 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 554)									int state1 = 2;
HXDLIN( 554)									int _g1 = 0;
HXDLIN( 554)									while((_g1 < keys5->length)){
HXLINE( 554)										int key = keys5->__get(_g1);
HXDLIN( 554)										_g1 = (_g1 + 1);
HXDLIN( 554)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 554)								{
HXLINE( 554)									 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 554)									int state2 = -1;
HXDLIN( 554)									int _g2 = 0;
HXDLIN( 554)									while((_g2 < keys5->length)){
HXLINE( 554)										int key = keys5->__get(_g2);
HXDLIN( 554)										_g2 = (_g2 + 1);
HXDLIN( 554)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)3: {
HXLINE( 554)								{
HXLINE( 554)									 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 554)									int state = 1;
HXDLIN( 554)									int _g = 0;
HXDLIN( 554)									while((_g < keys5->length)){
HXLINE( 554)										int key = keys5->__get(_g);
HXDLIN( 554)										_g = (_g + 1);
HXDLIN( 554)										action->addKey(key,state);
            									}
            								}
HXDLIN( 554)								{
HXLINE( 554)									 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 554)									int state1 = 2;
HXDLIN( 554)									int _g1 = 0;
HXDLIN( 554)									while((_g1 < keys5->length)){
HXLINE( 554)										int key = keys5->__get(_g1);
HXDLIN( 554)										_g1 = (_g1 + 1);
HXDLIN( 554)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 554)								{
HXLINE( 554)									 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 554)									int state2 = -1;
HXDLIN( 554)									int _g2 = 0;
HXDLIN( 554)									while((_g2 < keys5->length)){
HXLINE( 554)										int key = keys5->__get(_g2);
HXDLIN( 554)										_g2 = (_g2 + 1);
HXDLIN( 554)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)4: {
HXLINE( 554)								{
HXLINE( 554)									 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 554)									int state = 1;
HXDLIN( 554)									int _g = 0;
HXDLIN( 554)									while((_g < keys5->length)){
HXLINE( 554)										int key = keys5->__get(_g);
HXDLIN( 554)										_g = (_g + 1);
HXDLIN( 554)										action->addKey(key,state);
            									}
            								}
HXDLIN( 554)								{
HXLINE( 554)									 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 554)									int state1 = 2;
HXDLIN( 554)									int _g1 = 0;
HXDLIN( 554)									while((_g1 < keys5->length)){
HXLINE( 554)										int key = keys5->__get(_g1);
HXDLIN( 554)										_g1 = (_g1 + 1);
HXDLIN( 554)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 554)								{
HXLINE( 554)									 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 554)									int state2 = -1;
HXDLIN( 554)									int _g2 = 0;
HXDLIN( 554)									while((_g2 < keys5->length)){
HXLINE( 554)										int key = keys5->__get(_g2);
HXDLIN( 554)										_g2 = (_g2 + 1);
HXDLIN( 554)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)5: {
HXLINE( 554)								 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 554)								int state = 2;
HXDLIN( 554)								int _g = 0;
HXDLIN( 554)								while((_g < keys5->length)){
HXLINE( 554)									int key = keys5->__get(_g);
HXDLIN( 554)									_g = (_g + 1);
HXDLIN( 554)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)6: {
HXLINE( 554)								 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 554)								int state = 2;
HXDLIN( 554)								int _g = 0;
HXDLIN( 554)								while((_g < keys5->length)){
HXLINE( 554)									int key = keys5->__get(_g);
HXDLIN( 554)									_g = (_g + 1);
HXDLIN( 554)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)7: {
HXLINE( 554)								 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 554)								int state = 2;
HXDLIN( 554)								int _g = 0;
HXDLIN( 554)								while((_g < keys5->length)){
HXLINE( 554)									int key = keys5->__get(_g);
HXDLIN( 554)									_g = (_g + 1);
HXDLIN( 554)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)8: {
HXLINE( 554)								 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 554)								int state = 2;
HXDLIN( 554)								int _g = 0;
HXDLIN( 554)								while((_g < keys5->length)){
HXLINE( 554)									int key = keys5->__get(_g);
HXDLIN( 554)									_g = (_g + 1);
HXDLIN( 554)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)9: {
HXLINE( 554)								 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 554)								int state = 2;
HXDLIN( 554)								int _g = 0;
HXDLIN( 554)								while((_g < keys5->length)){
HXLINE( 554)									int key = keys5->__get(_g);
HXDLIN( 554)									_g = (_g + 1);
HXDLIN( 554)									action->addKey(key,state);
            								}
            							}
            							break;
            						}
            					}
HXLINE( 555)					{
HXLINE( 555)						::Array< int > keys6 = ::Array_obj< int >::fromData( _hx_array_data_116e4296_772,1);
HXDLIN( 555)						switch((int)(::Control_obj::RESET_dyn()->_hx_getIndex())){
            							case (int)0: {
HXLINE( 555)								{
HXLINE( 555)									 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 555)									int state = 1;
HXDLIN( 555)									int _g = 0;
HXDLIN( 555)									while((_g < keys6->length)){
HXLINE( 555)										int key = keys6->__get(_g);
HXDLIN( 555)										_g = (_g + 1);
HXDLIN( 555)										action->addKey(key,state);
            									}
            								}
HXDLIN( 555)								{
HXLINE( 555)									 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 555)									int state1 = 2;
HXDLIN( 555)									int _g1 = 0;
HXDLIN( 555)									while((_g1 < keys6->length)){
HXLINE( 555)										int key = keys6->__get(_g1);
HXDLIN( 555)										_g1 = (_g1 + 1);
HXDLIN( 555)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 555)								{
HXLINE( 555)									 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 555)									int state2 = -1;
HXDLIN( 555)									int _g2 = 0;
HXDLIN( 555)									while((_g2 < keys6->length)){
HXLINE( 555)										int key = keys6->__get(_g2);
HXDLIN( 555)										_g2 = (_g2 + 1);
HXDLIN( 555)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)1: {
HXLINE( 555)								{
HXLINE( 555)									 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 555)									int state = 1;
HXDLIN( 555)									int _g = 0;
HXDLIN( 555)									while((_g < keys6->length)){
HXLINE( 555)										int key = keys6->__get(_g);
HXDLIN( 555)										_g = (_g + 1);
HXDLIN( 555)										action->addKey(key,state);
            									}
            								}
HXDLIN( 555)								{
HXLINE( 555)									 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 555)									int state1 = 2;
HXDLIN( 555)									int _g1 = 0;
HXDLIN( 555)									while((_g1 < keys6->length)){
HXLINE( 555)										int key = keys6->__get(_g1);
HXDLIN( 555)										_g1 = (_g1 + 1);
HXDLIN( 555)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 555)								{
HXLINE( 555)									 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 555)									int state2 = -1;
HXDLIN( 555)									int _g2 = 0;
HXDLIN( 555)									while((_g2 < keys6->length)){
HXLINE( 555)										int key = keys6->__get(_g2);
HXDLIN( 555)										_g2 = (_g2 + 1);
HXDLIN( 555)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)2: {
HXLINE( 555)								{
HXLINE( 555)									 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 555)									int state = 1;
HXDLIN( 555)									int _g = 0;
HXDLIN( 555)									while((_g < keys6->length)){
HXLINE( 555)										int key = keys6->__get(_g);
HXDLIN( 555)										_g = (_g + 1);
HXDLIN( 555)										action->addKey(key,state);
            									}
            								}
HXDLIN( 555)								{
HXLINE( 555)									 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 555)									int state1 = 2;
HXDLIN( 555)									int _g1 = 0;
HXDLIN( 555)									while((_g1 < keys6->length)){
HXLINE( 555)										int key = keys6->__get(_g1);
HXDLIN( 555)										_g1 = (_g1 + 1);
HXDLIN( 555)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 555)								{
HXLINE( 555)									 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 555)									int state2 = -1;
HXDLIN( 555)									int _g2 = 0;
HXDLIN( 555)									while((_g2 < keys6->length)){
HXLINE( 555)										int key = keys6->__get(_g2);
HXDLIN( 555)										_g2 = (_g2 + 1);
HXDLIN( 555)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)3: {
HXLINE( 555)								{
HXLINE( 555)									 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 555)									int state = 1;
HXDLIN( 555)									int _g = 0;
HXDLIN( 555)									while((_g < keys6->length)){
HXLINE( 555)										int key = keys6->__get(_g);
HXDLIN( 555)										_g = (_g + 1);
HXDLIN( 555)										action->addKey(key,state);
            									}
            								}
HXDLIN( 555)								{
HXLINE( 555)									 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 555)									int state1 = 2;
HXDLIN( 555)									int _g1 = 0;
HXDLIN( 555)									while((_g1 < keys6->length)){
HXLINE( 555)										int key = keys6->__get(_g1);
HXDLIN( 555)										_g1 = (_g1 + 1);
HXDLIN( 555)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 555)								{
HXLINE( 555)									 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 555)									int state2 = -1;
HXDLIN( 555)									int _g2 = 0;
HXDLIN( 555)									while((_g2 < keys6->length)){
HXLINE( 555)										int key = keys6->__get(_g2);
HXDLIN( 555)										_g2 = (_g2 + 1);
HXDLIN( 555)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)4: {
HXLINE( 555)								{
HXLINE( 555)									 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 555)									int state = 1;
HXDLIN( 555)									int _g = 0;
HXDLIN( 555)									while((_g < keys6->length)){
HXLINE( 555)										int key = keys6->__get(_g);
HXDLIN( 555)										_g = (_g + 1);
HXDLIN( 555)										action->addKey(key,state);
            									}
            								}
HXDLIN( 555)								{
HXLINE( 555)									 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 555)									int state1 = 2;
HXDLIN( 555)									int _g1 = 0;
HXDLIN( 555)									while((_g1 < keys6->length)){
HXLINE( 555)										int key = keys6->__get(_g1);
HXDLIN( 555)										_g1 = (_g1 + 1);
HXDLIN( 555)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 555)								{
HXLINE( 555)									 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 555)									int state2 = -1;
HXDLIN( 555)									int _g2 = 0;
HXDLIN( 555)									while((_g2 < keys6->length)){
HXLINE( 555)										int key = keys6->__get(_g2);
HXDLIN( 555)										_g2 = (_g2 + 1);
HXDLIN( 555)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)5: {
HXLINE( 555)								 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 555)								int state = 2;
HXDLIN( 555)								int _g = 0;
HXDLIN( 555)								while((_g < keys6->length)){
HXLINE( 555)									int key = keys6->__get(_g);
HXDLIN( 555)									_g = (_g + 1);
HXDLIN( 555)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)6: {
HXLINE( 555)								 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 555)								int state = 2;
HXDLIN( 555)								int _g = 0;
HXDLIN( 555)								while((_g < keys6->length)){
HXLINE( 555)									int key = keys6->__get(_g);
HXDLIN( 555)									_g = (_g + 1);
HXDLIN( 555)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)7: {
HXLINE( 555)								 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 555)								int state = 2;
HXDLIN( 555)								int _g = 0;
HXDLIN( 555)								while((_g < keys6->length)){
HXLINE( 555)									int key = keys6->__get(_g);
HXDLIN( 555)									_g = (_g + 1);
HXDLIN( 555)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)8: {
HXLINE( 555)								 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 555)								int state = 2;
HXDLIN( 555)								int _g = 0;
HXDLIN( 555)								while((_g < keys6->length)){
HXLINE( 555)									int key = keys6->__get(_g);
HXDLIN( 555)									_g = (_g + 1);
HXDLIN( 555)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)9: {
HXLINE( 555)								 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 555)								int state = 2;
HXDLIN( 555)								int _g = 0;
HXDLIN( 555)								while((_g < keys6->length)){
HXLINE( 555)									int key = keys6->__get(_g);
HXDLIN( 555)									_g = (_g + 1);
HXDLIN( 555)									action->addKey(key,state);
            								}
            							}
            							break;
            						}
            					}
HXLINE( 556)					{
HXLINE( 556)						::Array< int > keys7 = ::Array_obj< int >::__new(0);
HXDLIN( 556)						switch((int)(::Control_obj::CHEAT_dyn()->_hx_getIndex())){
            							case (int)0: {
HXLINE( 556)								{
HXLINE( 556)									 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 556)									int state = 1;
HXDLIN( 556)									int _g = 0;
HXDLIN( 556)									while((_g < keys7->length)){
HXLINE( 556)										int key = keys7->__get(_g);
HXDLIN( 556)										_g = (_g + 1);
HXDLIN( 556)										action->addKey(key,state);
            									}
            								}
HXDLIN( 556)								{
HXLINE( 556)									 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 556)									int state1 = 2;
HXDLIN( 556)									int _g1 = 0;
HXDLIN( 556)									while((_g1 < keys7->length)){
HXLINE( 556)										int key = keys7->__get(_g1);
HXDLIN( 556)										_g1 = (_g1 + 1);
HXDLIN( 556)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 556)								{
HXLINE( 556)									 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 556)									int state2 = -1;
HXDLIN( 556)									int _g2 = 0;
HXDLIN( 556)									while((_g2 < keys7->length)){
HXLINE( 556)										int key = keys7->__get(_g2);
HXDLIN( 556)										_g2 = (_g2 + 1);
HXDLIN( 556)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)1: {
HXLINE( 556)								{
HXLINE( 556)									 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 556)									int state = 1;
HXDLIN( 556)									int _g = 0;
HXDLIN( 556)									while((_g < keys7->length)){
HXLINE( 556)										int key = keys7->__get(_g);
HXDLIN( 556)										_g = (_g + 1);
HXDLIN( 556)										action->addKey(key,state);
            									}
            								}
HXDLIN( 556)								{
HXLINE( 556)									 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 556)									int state1 = 2;
HXDLIN( 556)									int _g1 = 0;
HXDLIN( 556)									while((_g1 < keys7->length)){
HXLINE( 556)										int key = keys7->__get(_g1);
HXDLIN( 556)										_g1 = (_g1 + 1);
HXDLIN( 556)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 556)								{
HXLINE( 556)									 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 556)									int state2 = -1;
HXDLIN( 556)									int _g2 = 0;
HXDLIN( 556)									while((_g2 < keys7->length)){
HXLINE( 556)										int key = keys7->__get(_g2);
HXDLIN( 556)										_g2 = (_g2 + 1);
HXDLIN( 556)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)2: {
HXLINE( 556)								{
HXLINE( 556)									 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 556)									int state = 1;
HXDLIN( 556)									int _g = 0;
HXDLIN( 556)									while((_g < keys7->length)){
HXLINE( 556)										int key = keys7->__get(_g);
HXDLIN( 556)										_g = (_g + 1);
HXDLIN( 556)										action->addKey(key,state);
            									}
            								}
HXDLIN( 556)								{
HXLINE( 556)									 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 556)									int state1 = 2;
HXDLIN( 556)									int _g1 = 0;
HXDLIN( 556)									while((_g1 < keys7->length)){
HXLINE( 556)										int key = keys7->__get(_g1);
HXDLIN( 556)										_g1 = (_g1 + 1);
HXDLIN( 556)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 556)								{
HXLINE( 556)									 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 556)									int state2 = -1;
HXDLIN( 556)									int _g2 = 0;
HXDLIN( 556)									while((_g2 < keys7->length)){
HXLINE( 556)										int key = keys7->__get(_g2);
HXDLIN( 556)										_g2 = (_g2 + 1);
HXDLIN( 556)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)3: {
HXLINE( 556)								{
HXLINE( 556)									 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 556)									int state = 1;
HXDLIN( 556)									int _g = 0;
HXDLIN( 556)									while((_g < keys7->length)){
HXLINE( 556)										int key = keys7->__get(_g);
HXDLIN( 556)										_g = (_g + 1);
HXDLIN( 556)										action->addKey(key,state);
            									}
            								}
HXDLIN( 556)								{
HXLINE( 556)									 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 556)									int state1 = 2;
HXDLIN( 556)									int _g1 = 0;
HXDLIN( 556)									while((_g1 < keys7->length)){
HXLINE( 556)										int key = keys7->__get(_g1);
HXDLIN( 556)										_g1 = (_g1 + 1);
HXDLIN( 556)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 556)								{
HXLINE( 556)									 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 556)									int state2 = -1;
HXDLIN( 556)									int _g2 = 0;
HXDLIN( 556)									while((_g2 < keys7->length)){
HXLINE( 556)										int key = keys7->__get(_g2);
HXDLIN( 556)										_g2 = (_g2 + 1);
HXDLIN( 556)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)4: {
HXLINE( 556)								{
HXLINE( 556)									 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 556)									int state = 1;
HXDLIN( 556)									int _g = 0;
HXDLIN( 556)									while((_g < keys7->length)){
HXLINE( 556)										int key = keys7->__get(_g);
HXDLIN( 556)										_g = (_g + 1);
HXDLIN( 556)										action->addKey(key,state);
            									}
            								}
HXDLIN( 556)								{
HXLINE( 556)									 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 556)									int state1 = 2;
HXDLIN( 556)									int _g1 = 0;
HXDLIN( 556)									while((_g1 < keys7->length)){
HXLINE( 556)										int key = keys7->__get(_g1);
HXDLIN( 556)										_g1 = (_g1 + 1);
HXDLIN( 556)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 556)								{
HXLINE( 556)									 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 556)									int state2 = -1;
HXDLIN( 556)									int _g2 = 0;
HXDLIN( 556)									while((_g2 < keys7->length)){
HXLINE( 556)										int key = keys7->__get(_g2);
HXDLIN( 556)										_g2 = (_g2 + 1);
HXDLIN( 556)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)5: {
HXLINE( 556)								 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 556)								int state = 2;
HXDLIN( 556)								int _g = 0;
HXDLIN( 556)								while((_g < keys7->length)){
HXLINE( 556)									int key = keys7->__get(_g);
HXDLIN( 556)									_g = (_g + 1);
HXDLIN( 556)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)6: {
HXLINE( 556)								 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 556)								int state = 2;
HXDLIN( 556)								int _g = 0;
HXDLIN( 556)								while((_g < keys7->length)){
HXLINE( 556)									int key = keys7->__get(_g);
HXDLIN( 556)									_g = (_g + 1);
HXDLIN( 556)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)7: {
HXLINE( 556)								 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 556)								int state = 2;
HXDLIN( 556)								int _g = 0;
HXDLIN( 556)								while((_g < keys7->length)){
HXLINE( 556)									int key = keys7->__get(_g);
HXDLIN( 556)									_g = (_g + 1);
HXDLIN( 556)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)8: {
HXLINE( 556)								 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 556)								int state = 2;
HXDLIN( 556)								int _g = 0;
HXDLIN( 556)								while((_g < keys7->length)){
HXLINE( 556)									int key = keys7->__get(_g);
HXDLIN( 556)									_g = (_g + 1);
HXDLIN( 556)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)9: {
HXLINE( 556)								 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 556)								int state = 2;
HXDLIN( 556)								int _g = 0;
HXDLIN( 556)								while((_g < keys7->length)){
HXLINE( 556)									int key = keys7->__get(_g);
HXDLIN( 556)									_g = (_g + 1);
HXDLIN( 556)									action->addKey(key,state);
            								}
            							}
            							break;
            						}
            					}
            				}
            				else {
HXLINE( 558)					{
HXLINE( 558)						::Array< int > keys = ::Array_obj< int >::fromData( _hx_array_data_116e4296_773,3);
HXDLIN( 558)						switch((int)(::Control_obj::UP_dyn()->_hx_getIndex())){
            							case (int)0: {
HXLINE( 558)								{
HXLINE( 558)									 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 558)									int state = 1;
HXDLIN( 558)									int _g = 0;
HXDLIN( 558)									while((_g < keys->length)){
HXLINE( 558)										int key = keys->__get(_g);
HXDLIN( 558)										_g = (_g + 1);
HXDLIN( 558)										action->addKey(key,state);
            									}
            								}
HXDLIN( 558)								{
HXLINE( 558)									 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 558)									int state1 = 2;
HXDLIN( 558)									int _g1 = 0;
HXDLIN( 558)									while((_g1 < keys->length)){
HXLINE( 558)										int key = keys->__get(_g1);
HXDLIN( 558)										_g1 = (_g1 + 1);
HXDLIN( 558)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 558)								{
HXLINE( 558)									 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 558)									int state2 = -1;
HXDLIN( 558)									int _g2 = 0;
HXDLIN( 558)									while((_g2 < keys->length)){
HXLINE( 558)										int key = keys->__get(_g2);
HXDLIN( 558)										_g2 = (_g2 + 1);
HXDLIN( 558)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)1: {
HXLINE( 558)								{
HXLINE( 558)									 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 558)									int state = 1;
HXDLIN( 558)									int _g = 0;
HXDLIN( 558)									while((_g < keys->length)){
HXLINE( 558)										int key = keys->__get(_g);
HXDLIN( 558)										_g = (_g + 1);
HXDLIN( 558)										action->addKey(key,state);
            									}
            								}
HXDLIN( 558)								{
HXLINE( 558)									 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 558)									int state1 = 2;
HXDLIN( 558)									int _g1 = 0;
HXDLIN( 558)									while((_g1 < keys->length)){
HXLINE( 558)										int key = keys->__get(_g1);
HXDLIN( 558)										_g1 = (_g1 + 1);
HXDLIN( 558)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 558)								{
HXLINE( 558)									 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 558)									int state2 = -1;
HXDLIN( 558)									int _g2 = 0;
HXDLIN( 558)									while((_g2 < keys->length)){
HXLINE( 558)										int key = keys->__get(_g2);
HXDLIN( 558)										_g2 = (_g2 + 1);
HXDLIN( 558)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)2: {
HXLINE( 558)								{
HXLINE( 558)									 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 558)									int state = 1;
HXDLIN( 558)									int _g = 0;
HXDLIN( 558)									while((_g < keys->length)){
HXLINE( 558)										int key = keys->__get(_g);
HXDLIN( 558)										_g = (_g + 1);
HXDLIN( 558)										action->addKey(key,state);
            									}
            								}
HXDLIN( 558)								{
HXLINE( 558)									 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 558)									int state1 = 2;
HXDLIN( 558)									int _g1 = 0;
HXDLIN( 558)									while((_g1 < keys->length)){
HXLINE( 558)										int key = keys->__get(_g1);
HXDLIN( 558)										_g1 = (_g1 + 1);
HXDLIN( 558)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 558)								{
HXLINE( 558)									 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 558)									int state2 = -1;
HXDLIN( 558)									int _g2 = 0;
HXDLIN( 558)									while((_g2 < keys->length)){
HXLINE( 558)										int key = keys->__get(_g2);
HXDLIN( 558)										_g2 = (_g2 + 1);
HXDLIN( 558)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)3: {
HXLINE( 558)								{
HXLINE( 558)									 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 558)									int state = 1;
HXDLIN( 558)									int _g = 0;
HXDLIN( 558)									while((_g < keys->length)){
HXLINE( 558)										int key = keys->__get(_g);
HXDLIN( 558)										_g = (_g + 1);
HXDLIN( 558)										action->addKey(key,state);
            									}
            								}
HXDLIN( 558)								{
HXLINE( 558)									 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 558)									int state1 = 2;
HXDLIN( 558)									int _g1 = 0;
HXDLIN( 558)									while((_g1 < keys->length)){
HXLINE( 558)										int key = keys->__get(_g1);
HXDLIN( 558)										_g1 = (_g1 + 1);
HXDLIN( 558)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 558)								{
HXLINE( 558)									 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 558)									int state2 = -1;
HXDLIN( 558)									int _g2 = 0;
HXDLIN( 558)									while((_g2 < keys->length)){
HXLINE( 558)										int key = keys->__get(_g2);
HXDLIN( 558)										_g2 = (_g2 + 1);
HXDLIN( 558)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)4: {
HXLINE( 558)								{
HXLINE( 558)									 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 558)									int state = 1;
HXDLIN( 558)									int _g = 0;
HXDLIN( 558)									while((_g < keys->length)){
HXLINE( 558)										int key = keys->__get(_g);
HXDLIN( 558)										_g = (_g + 1);
HXDLIN( 558)										action->addKey(key,state);
            									}
            								}
HXDLIN( 558)								{
HXLINE( 558)									 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 558)									int state1 = 2;
HXDLIN( 558)									int _g1 = 0;
HXDLIN( 558)									while((_g1 < keys->length)){
HXLINE( 558)										int key = keys->__get(_g1);
HXDLIN( 558)										_g1 = (_g1 + 1);
HXDLIN( 558)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 558)								{
HXLINE( 558)									 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 558)									int state2 = -1;
HXDLIN( 558)									int _g2 = 0;
HXDLIN( 558)									while((_g2 < keys->length)){
HXLINE( 558)										int key = keys->__get(_g2);
HXDLIN( 558)										_g2 = (_g2 + 1);
HXDLIN( 558)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)5: {
HXLINE( 558)								 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 558)								int state = 2;
HXDLIN( 558)								int _g = 0;
HXDLIN( 558)								while((_g < keys->length)){
HXLINE( 558)									int key = keys->__get(_g);
HXDLIN( 558)									_g = (_g + 1);
HXDLIN( 558)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)6: {
HXLINE( 558)								 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 558)								int state = 2;
HXDLIN( 558)								int _g = 0;
HXDLIN( 558)								while((_g < keys->length)){
HXLINE( 558)									int key = keys->__get(_g);
HXDLIN( 558)									_g = (_g + 1);
HXDLIN( 558)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)7: {
HXLINE( 558)								 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 558)								int state = 2;
HXDLIN( 558)								int _g = 0;
HXDLIN( 558)								while((_g < keys->length)){
HXLINE( 558)									int key = keys->__get(_g);
HXDLIN( 558)									_g = (_g + 1);
HXDLIN( 558)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)8: {
HXLINE( 558)								 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 558)								int state = 2;
HXDLIN( 558)								int _g = 0;
HXDLIN( 558)								while((_g < keys->length)){
HXLINE( 558)									int key = keys->__get(_g);
HXDLIN( 558)									_g = (_g + 1);
HXDLIN( 558)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)9: {
HXLINE( 558)								 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 558)								int state = 2;
HXDLIN( 558)								int _g = 0;
HXDLIN( 558)								while((_g < keys->length)){
HXLINE( 558)									int key = keys->__get(_g);
HXDLIN( 558)									_g = (_g + 1);
HXDLIN( 558)									action->addKey(key,state);
            								}
            							}
            							break;
            						}
            					}
HXLINE( 559)					{
HXLINE( 559)						::Array< int > keys1 = ::Array_obj< int >::fromData( _hx_array_data_116e4296_774,2);
HXDLIN( 559)						switch((int)(::Control_obj::DOWN_dyn()->_hx_getIndex())){
            							case (int)0: {
HXLINE( 559)								{
HXLINE( 559)									 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 559)									int state = 1;
HXDLIN( 559)									int _g = 0;
HXDLIN( 559)									while((_g < keys1->length)){
HXLINE( 559)										int key = keys1->__get(_g);
HXDLIN( 559)										_g = (_g + 1);
HXDLIN( 559)										action->addKey(key,state);
            									}
            								}
HXDLIN( 559)								{
HXLINE( 559)									 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 559)									int state1 = 2;
HXDLIN( 559)									int _g1 = 0;
HXDLIN( 559)									while((_g1 < keys1->length)){
HXLINE( 559)										int key = keys1->__get(_g1);
HXDLIN( 559)										_g1 = (_g1 + 1);
HXDLIN( 559)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 559)								{
HXLINE( 559)									 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 559)									int state2 = -1;
HXDLIN( 559)									int _g2 = 0;
HXDLIN( 559)									while((_g2 < keys1->length)){
HXLINE( 559)										int key = keys1->__get(_g2);
HXDLIN( 559)										_g2 = (_g2 + 1);
HXDLIN( 559)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)1: {
HXLINE( 559)								{
HXLINE( 559)									 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 559)									int state = 1;
HXDLIN( 559)									int _g = 0;
HXDLIN( 559)									while((_g < keys1->length)){
HXLINE( 559)										int key = keys1->__get(_g);
HXDLIN( 559)										_g = (_g + 1);
HXDLIN( 559)										action->addKey(key,state);
            									}
            								}
HXDLIN( 559)								{
HXLINE( 559)									 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 559)									int state1 = 2;
HXDLIN( 559)									int _g1 = 0;
HXDLIN( 559)									while((_g1 < keys1->length)){
HXLINE( 559)										int key = keys1->__get(_g1);
HXDLIN( 559)										_g1 = (_g1 + 1);
HXDLIN( 559)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 559)								{
HXLINE( 559)									 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 559)									int state2 = -1;
HXDLIN( 559)									int _g2 = 0;
HXDLIN( 559)									while((_g2 < keys1->length)){
HXLINE( 559)										int key = keys1->__get(_g2);
HXDLIN( 559)										_g2 = (_g2 + 1);
HXDLIN( 559)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)2: {
HXLINE( 559)								{
HXLINE( 559)									 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 559)									int state = 1;
HXDLIN( 559)									int _g = 0;
HXDLIN( 559)									while((_g < keys1->length)){
HXLINE( 559)										int key = keys1->__get(_g);
HXDLIN( 559)										_g = (_g + 1);
HXDLIN( 559)										action->addKey(key,state);
            									}
            								}
HXDLIN( 559)								{
HXLINE( 559)									 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 559)									int state1 = 2;
HXDLIN( 559)									int _g1 = 0;
HXDLIN( 559)									while((_g1 < keys1->length)){
HXLINE( 559)										int key = keys1->__get(_g1);
HXDLIN( 559)										_g1 = (_g1 + 1);
HXDLIN( 559)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 559)								{
HXLINE( 559)									 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 559)									int state2 = -1;
HXDLIN( 559)									int _g2 = 0;
HXDLIN( 559)									while((_g2 < keys1->length)){
HXLINE( 559)										int key = keys1->__get(_g2);
HXDLIN( 559)										_g2 = (_g2 + 1);
HXDLIN( 559)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)3: {
HXLINE( 559)								{
HXLINE( 559)									 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 559)									int state = 1;
HXDLIN( 559)									int _g = 0;
HXDLIN( 559)									while((_g < keys1->length)){
HXLINE( 559)										int key = keys1->__get(_g);
HXDLIN( 559)										_g = (_g + 1);
HXDLIN( 559)										action->addKey(key,state);
            									}
            								}
HXDLIN( 559)								{
HXLINE( 559)									 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 559)									int state1 = 2;
HXDLIN( 559)									int _g1 = 0;
HXDLIN( 559)									while((_g1 < keys1->length)){
HXLINE( 559)										int key = keys1->__get(_g1);
HXDLIN( 559)										_g1 = (_g1 + 1);
HXDLIN( 559)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 559)								{
HXLINE( 559)									 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 559)									int state2 = -1;
HXDLIN( 559)									int _g2 = 0;
HXDLIN( 559)									while((_g2 < keys1->length)){
HXLINE( 559)										int key = keys1->__get(_g2);
HXDLIN( 559)										_g2 = (_g2 + 1);
HXDLIN( 559)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)4: {
HXLINE( 559)								{
HXLINE( 559)									 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 559)									int state = 1;
HXDLIN( 559)									int _g = 0;
HXDLIN( 559)									while((_g < keys1->length)){
HXLINE( 559)										int key = keys1->__get(_g);
HXDLIN( 559)										_g = (_g + 1);
HXDLIN( 559)										action->addKey(key,state);
            									}
            								}
HXDLIN( 559)								{
HXLINE( 559)									 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 559)									int state1 = 2;
HXDLIN( 559)									int _g1 = 0;
HXDLIN( 559)									while((_g1 < keys1->length)){
HXLINE( 559)										int key = keys1->__get(_g1);
HXDLIN( 559)										_g1 = (_g1 + 1);
HXDLIN( 559)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 559)								{
HXLINE( 559)									 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 559)									int state2 = -1;
HXDLIN( 559)									int _g2 = 0;
HXDLIN( 559)									while((_g2 < keys1->length)){
HXLINE( 559)										int key = keys1->__get(_g2);
HXDLIN( 559)										_g2 = (_g2 + 1);
HXDLIN( 559)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)5: {
HXLINE( 559)								 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 559)								int state = 2;
HXDLIN( 559)								int _g = 0;
HXDLIN( 559)								while((_g < keys1->length)){
HXLINE( 559)									int key = keys1->__get(_g);
HXDLIN( 559)									_g = (_g + 1);
HXDLIN( 559)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)6: {
HXLINE( 559)								 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 559)								int state = 2;
HXDLIN( 559)								int _g = 0;
HXDLIN( 559)								while((_g < keys1->length)){
HXLINE( 559)									int key = keys1->__get(_g);
HXDLIN( 559)									_g = (_g + 1);
HXDLIN( 559)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)7: {
HXLINE( 559)								 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 559)								int state = 2;
HXDLIN( 559)								int _g = 0;
HXDLIN( 559)								while((_g < keys1->length)){
HXLINE( 559)									int key = keys1->__get(_g);
HXDLIN( 559)									_g = (_g + 1);
HXDLIN( 559)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)8: {
HXLINE( 559)								 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 559)								int state = 2;
HXDLIN( 559)								int _g = 0;
HXDLIN( 559)								while((_g < keys1->length)){
HXLINE( 559)									int key = keys1->__get(_g);
HXDLIN( 559)									_g = (_g + 1);
HXDLIN( 559)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)9: {
HXLINE( 559)								 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 559)								int state = 2;
HXDLIN( 559)								int _g = 0;
HXDLIN( 559)								while((_g < keys1->length)){
HXLINE( 559)									int key = keys1->__get(_g);
HXDLIN( 559)									_g = (_g + 1);
HXDLIN( 559)									action->addKey(key,state);
            								}
            							}
            							break;
            						}
            					}
HXLINE( 560)					{
HXLINE( 560)						::Array< int > keys2 = ::Array_obj< int >::fromData( _hx_array_data_116e4296_775,2);
HXDLIN( 560)						switch((int)(::Control_obj::LEFT_dyn()->_hx_getIndex())){
            							case (int)0: {
HXLINE( 560)								{
HXLINE( 560)									 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 560)									int state = 1;
HXDLIN( 560)									int _g = 0;
HXDLIN( 560)									while((_g < keys2->length)){
HXLINE( 560)										int key = keys2->__get(_g);
HXDLIN( 560)										_g = (_g + 1);
HXDLIN( 560)										action->addKey(key,state);
            									}
            								}
HXDLIN( 560)								{
HXLINE( 560)									 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 560)									int state1 = 2;
HXDLIN( 560)									int _g1 = 0;
HXDLIN( 560)									while((_g1 < keys2->length)){
HXLINE( 560)										int key = keys2->__get(_g1);
HXDLIN( 560)										_g1 = (_g1 + 1);
HXDLIN( 560)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 560)								{
HXLINE( 560)									 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 560)									int state2 = -1;
HXDLIN( 560)									int _g2 = 0;
HXDLIN( 560)									while((_g2 < keys2->length)){
HXLINE( 560)										int key = keys2->__get(_g2);
HXDLIN( 560)										_g2 = (_g2 + 1);
HXDLIN( 560)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)1: {
HXLINE( 560)								{
HXLINE( 560)									 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 560)									int state = 1;
HXDLIN( 560)									int _g = 0;
HXDLIN( 560)									while((_g < keys2->length)){
HXLINE( 560)										int key = keys2->__get(_g);
HXDLIN( 560)										_g = (_g + 1);
HXDLIN( 560)										action->addKey(key,state);
            									}
            								}
HXDLIN( 560)								{
HXLINE( 560)									 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 560)									int state1 = 2;
HXDLIN( 560)									int _g1 = 0;
HXDLIN( 560)									while((_g1 < keys2->length)){
HXLINE( 560)										int key = keys2->__get(_g1);
HXDLIN( 560)										_g1 = (_g1 + 1);
HXDLIN( 560)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 560)								{
HXLINE( 560)									 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 560)									int state2 = -1;
HXDLIN( 560)									int _g2 = 0;
HXDLIN( 560)									while((_g2 < keys2->length)){
HXLINE( 560)										int key = keys2->__get(_g2);
HXDLIN( 560)										_g2 = (_g2 + 1);
HXDLIN( 560)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)2: {
HXLINE( 560)								{
HXLINE( 560)									 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 560)									int state = 1;
HXDLIN( 560)									int _g = 0;
HXDLIN( 560)									while((_g < keys2->length)){
HXLINE( 560)										int key = keys2->__get(_g);
HXDLIN( 560)										_g = (_g + 1);
HXDLIN( 560)										action->addKey(key,state);
            									}
            								}
HXDLIN( 560)								{
HXLINE( 560)									 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 560)									int state1 = 2;
HXDLIN( 560)									int _g1 = 0;
HXDLIN( 560)									while((_g1 < keys2->length)){
HXLINE( 560)										int key = keys2->__get(_g1);
HXDLIN( 560)										_g1 = (_g1 + 1);
HXDLIN( 560)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 560)								{
HXLINE( 560)									 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 560)									int state2 = -1;
HXDLIN( 560)									int _g2 = 0;
HXDLIN( 560)									while((_g2 < keys2->length)){
HXLINE( 560)										int key = keys2->__get(_g2);
HXDLIN( 560)										_g2 = (_g2 + 1);
HXDLIN( 560)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)3: {
HXLINE( 560)								{
HXLINE( 560)									 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 560)									int state = 1;
HXDLIN( 560)									int _g = 0;
HXDLIN( 560)									while((_g < keys2->length)){
HXLINE( 560)										int key = keys2->__get(_g);
HXDLIN( 560)										_g = (_g + 1);
HXDLIN( 560)										action->addKey(key,state);
            									}
            								}
HXDLIN( 560)								{
HXLINE( 560)									 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 560)									int state1 = 2;
HXDLIN( 560)									int _g1 = 0;
HXDLIN( 560)									while((_g1 < keys2->length)){
HXLINE( 560)										int key = keys2->__get(_g1);
HXDLIN( 560)										_g1 = (_g1 + 1);
HXDLIN( 560)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 560)								{
HXLINE( 560)									 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 560)									int state2 = -1;
HXDLIN( 560)									int _g2 = 0;
HXDLIN( 560)									while((_g2 < keys2->length)){
HXLINE( 560)										int key = keys2->__get(_g2);
HXDLIN( 560)										_g2 = (_g2 + 1);
HXDLIN( 560)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)4: {
HXLINE( 560)								{
HXLINE( 560)									 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 560)									int state = 1;
HXDLIN( 560)									int _g = 0;
HXDLIN( 560)									while((_g < keys2->length)){
HXLINE( 560)										int key = keys2->__get(_g);
HXDLIN( 560)										_g = (_g + 1);
HXDLIN( 560)										action->addKey(key,state);
            									}
            								}
HXDLIN( 560)								{
HXLINE( 560)									 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 560)									int state1 = 2;
HXDLIN( 560)									int _g1 = 0;
HXDLIN( 560)									while((_g1 < keys2->length)){
HXLINE( 560)										int key = keys2->__get(_g1);
HXDLIN( 560)										_g1 = (_g1 + 1);
HXDLIN( 560)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 560)								{
HXLINE( 560)									 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 560)									int state2 = -1;
HXDLIN( 560)									int _g2 = 0;
HXDLIN( 560)									while((_g2 < keys2->length)){
HXLINE( 560)										int key = keys2->__get(_g2);
HXDLIN( 560)										_g2 = (_g2 + 1);
HXDLIN( 560)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)5: {
HXLINE( 560)								 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 560)								int state = 2;
HXDLIN( 560)								int _g = 0;
HXDLIN( 560)								while((_g < keys2->length)){
HXLINE( 560)									int key = keys2->__get(_g);
HXDLIN( 560)									_g = (_g + 1);
HXDLIN( 560)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)6: {
HXLINE( 560)								 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 560)								int state = 2;
HXDLIN( 560)								int _g = 0;
HXDLIN( 560)								while((_g < keys2->length)){
HXLINE( 560)									int key = keys2->__get(_g);
HXDLIN( 560)									_g = (_g + 1);
HXDLIN( 560)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)7: {
HXLINE( 560)								 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 560)								int state = 2;
HXDLIN( 560)								int _g = 0;
HXDLIN( 560)								while((_g < keys2->length)){
HXLINE( 560)									int key = keys2->__get(_g);
HXDLIN( 560)									_g = (_g + 1);
HXDLIN( 560)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)8: {
HXLINE( 560)								 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 560)								int state = 2;
HXDLIN( 560)								int _g = 0;
HXDLIN( 560)								while((_g < keys2->length)){
HXLINE( 560)									int key = keys2->__get(_g);
HXDLIN( 560)									_g = (_g + 1);
HXDLIN( 560)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)9: {
HXLINE( 560)								 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 560)								int state = 2;
HXDLIN( 560)								int _g = 0;
HXDLIN( 560)								while((_g < keys2->length)){
HXLINE( 560)									int key = keys2->__get(_g);
HXDLIN( 560)									_g = (_g + 1);
HXDLIN( 560)									action->addKey(key,state);
            								}
            							}
            							break;
            						}
            					}
HXLINE( 561)					{
HXLINE( 561)						::Array< int > keys3 = ::Array_obj< int >::fromData( _hx_array_data_116e4296_776,3);
HXDLIN( 561)						switch((int)(::Control_obj::RIGHT_dyn()->_hx_getIndex())){
            							case (int)0: {
HXLINE( 561)								{
HXLINE( 561)									 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 561)									int state = 1;
HXDLIN( 561)									int _g = 0;
HXDLIN( 561)									while((_g < keys3->length)){
HXLINE( 561)										int key = keys3->__get(_g);
HXDLIN( 561)										_g = (_g + 1);
HXDLIN( 561)										action->addKey(key,state);
            									}
            								}
HXDLIN( 561)								{
HXLINE( 561)									 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 561)									int state1 = 2;
HXDLIN( 561)									int _g1 = 0;
HXDLIN( 561)									while((_g1 < keys3->length)){
HXLINE( 561)										int key = keys3->__get(_g1);
HXDLIN( 561)										_g1 = (_g1 + 1);
HXDLIN( 561)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 561)								{
HXLINE( 561)									 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 561)									int state2 = -1;
HXDLIN( 561)									int _g2 = 0;
HXDLIN( 561)									while((_g2 < keys3->length)){
HXLINE( 561)										int key = keys3->__get(_g2);
HXDLIN( 561)										_g2 = (_g2 + 1);
HXDLIN( 561)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)1: {
HXLINE( 561)								{
HXLINE( 561)									 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 561)									int state = 1;
HXDLIN( 561)									int _g = 0;
HXDLIN( 561)									while((_g < keys3->length)){
HXLINE( 561)										int key = keys3->__get(_g);
HXDLIN( 561)										_g = (_g + 1);
HXDLIN( 561)										action->addKey(key,state);
            									}
            								}
HXDLIN( 561)								{
HXLINE( 561)									 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 561)									int state1 = 2;
HXDLIN( 561)									int _g1 = 0;
HXDLIN( 561)									while((_g1 < keys3->length)){
HXLINE( 561)										int key = keys3->__get(_g1);
HXDLIN( 561)										_g1 = (_g1 + 1);
HXDLIN( 561)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 561)								{
HXLINE( 561)									 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 561)									int state2 = -1;
HXDLIN( 561)									int _g2 = 0;
HXDLIN( 561)									while((_g2 < keys3->length)){
HXLINE( 561)										int key = keys3->__get(_g2);
HXDLIN( 561)										_g2 = (_g2 + 1);
HXDLIN( 561)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)2: {
HXLINE( 561)								{
HXLINE( 561)									 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 561)									int state = 1;
HXDLIN( 561)									int _g = 0;
HXDLIN( 561)									while((_g < keys3->length)){
HXLINE( 561)										int key = keys3->__get(_g);
HXDLIN( 561)										_g = (_g + 1);
HXDLIN( 561)										action->addKey(key,state);
            									}
            								}
HXDLIN( 561)								{
HXLINE( 561)									 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 561)									int state1 = 2;
HXDLIN( 561)									int _g1 = 0;
HXDLIN( 561)									while((_g1 < keys3->length)){
HXLINE( 561)										int key = keys3->__get(_g1);
HXDLIN( 561)										_g1 = (_g1 + 1);
HXDLIN( 561)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 561)								{
HXLINE( 561)									 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 561)									int state2 = -1;
HXDLIN( 561)									int _g2 = 0;
HXDLIN( 561)									while((_g2 < keys3->length)){
HXLINE( 561)										int key = keys3->__get(_g2);
HXDLIN( 561)										_g2 = (_g2 + 1);
HXDLIN( 561)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)3: {
HXLINE( 561)								{
HXLINE( 561)									 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 561)									int state = 1;
HXDLIN( 561)									int _g = 0;
HXDLIN( 561)									while((_g < keys3->length)){
HXLINE( 561)										int key = keys3->__get(_g);
HXDLIN( 561)										_g = (_g + 1);
HXDLIN( 561)										action->addKey(key,state);
            									}
            								}
HXDLIN( 561)								{
HXLINE( 561)									 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 561)									int state1 = 2;
HXDLIN( 561)									int _g1 = 0;
HXDLIN( 561)									while((_g1 < keys3->length)){
HXLINE( 561)										int key = keys3->__get(_g1);
HXDLIN( 561)										_g1 = (_g1 + 1);
HXDLIN( 561)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 561)								{
HXLINE( 561)									 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 561)									int state2 = -1;
HXDLIN( 561)									int _g2 = 0;
HXDLIN( 561)									while((_g2 < keys3->length)){
HXLINE( 561)										int key = keys3->__get(_g2);
HXDLIN( 561)										_g2 = (_g2 + 1);
HXDLIN( 561)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)4: {
HXLINE( 561)								{
HXLINE( 561)									 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 561)									int state = 1;
HXDLIN( 561)									int _g = 0;
HXDLIN( 561)									while((_g < keys3->length)){
HXLINE( 561)										int key = keys3->__get(_g);
HXDLIN( 561)										_g = (_g + 1);
HXDLIN( 561)										action->addKey(key,state);
            									}
            								}
HXDLIN( 561)								{
HXLINE( 561)									 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 561)									int state1 = 2;
HXDLIN( 561)									int _g1 = 0;
HXDLIN( 561)									while((_g1 < keys3->length)){
HXLINE( 561)										int key = keys3->__get(_g1);
HXDLIN( 561)										_g1 = (_g1 + 1);
HXDLIN( 561)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 561)								{
HXLINE( 561)									 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 561)									int state2 = -1;
HXDLIN( 561)									int _g2 = 0;
HXDLIN( 561)									while((_g2 < keys3->length)){
HXLINE( 561)										int key = keys3->__get(_g2);
HXDLIN( 561)										_g2 = (_g2 + 1);
HXDLIN( 561)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)5: {
HXLINE( 561)								 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 561)								int state = 2;
HXDLIN( 561)								int _g = 0;
HXDLIN( 561)								while((_g < keys3->length)){
HXLINE( 561)									int key = keys3->__get(_g);
HXDLIN( 561)									_g = (_g + 1);
HXDLIN( 561)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)6: {
HXLINE( 561)								 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 561)								int state = 2;
HXDLIN( 561)								int _g = 0;
HXDLIN( 561)								while((_g < keys3->length)){
HXLINE( 561)									int key = keys3->__get(_g);
HXDLIN( 561)									_g = (_g + 1);
HXDLIN( 561)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)7: {
HXLINE( 561)								 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 561)								int state = 2;
HXDLIN( 561)								int _g = 0;
HXDLIN( 561)								while((_g < keys3->length)){
HXLINE( 561)									int key = keys3->__get(_g);
HXDLIN( 561)									_g = (_g + 1);
HXDLIN( 561)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)8: {
HXLINE( 561)								 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 561)								int state = 2;
HXDLIN( 561)								int _g = 0;
HXDLIN( 561)								while((_g < keys3->length)){
HXLINE( 561)									int key = keys3->__get(_g);
HXDLIN( 561)									_g = (_g + 1);
HXDLIN( 561)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)9: {
HXLINE( 561)								 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 561)								int state = 2;
HXDLIN( 561)								int _g = 0;
HXDLIN( 561)								while((_g < keys3->length)){
HXLINE( 561)									int key = keys3->__get(_g);
HXDLIN( 561)									_g = (_g + 1);
HXDLIN( 561)									action->addKey(key,state);
            								}
            							}
            							break;
            						}
            					}
HXLINE( 562)					{
HXLINE( 562)						::Array< int > keys4 = ::Array_obj< int >::fromData( _hx_array_data_116e4296_777,4);
HXDLIN( 562)						switch((int)(::Control_obj::ACCEPT_dyn()->_hx_getIndex())){
            							case (int)0: {
HXLINE( 562)								{
HXLINE( 562)									 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 562)									int state = 1;
HXDLIN( 562)									int _g = 0;
HXDLIN( 562)									while((_g < keys4->length)){
HXLINE( 562)										int key = keys4->__get(_g);
HXDLIN( 562)										_g = (_g + 1);
HXDLIN( 562)										action->addKey(key,state);
            									}
            								}
HXDLIN( 562)								{
HXLINE( 562)									 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 562)									int state1 = 2;
HXDLIN( 562)									int _g1 = 0;
HXDLIN( 562)									while((_g1 < keys4->length)){
HXLINE( 562)										int key = keys4->__get(_g1);
HXDLIN( 562)										_g1 = (_g1 + 1);
HXDLIN( 562)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 562)								{
HXLINE( 562)									 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 562)									int state2 = -1;
HXDLIN( 562)									int _g2 = 0;
HXDLIN( 562)									while((_g2 < keys4->length)){
HXLINE( 562)										int key = keys4->__get(_g2);
HXDLIN( 562)										_g2 = (_g2 + 1);
HXDLIN( 562)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)1: {
HXLINE( 562)								{
HXLINE( 562)									 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 562)									int state = 1;
HXDLIN( 562)									int _g = 0;
HXDLIN( 562)									while((_g < keys4->length)){
HXLINE( 562)										int key = keys4->__get(_g);
HXDLIN( 562)										_g = (_g + 1);
HXDLIN( 562)										action->addKey(key,state);
            									}
            								}
HXDLIN( 562)								{
HXLINE( 562)									 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 562)									int state1 = 2;
HXDLIN( 562)									int _g1 = 0;
HXDLIN( 562)									while((_g1 < keys4->length)){
HXLINE( 562)										int key = keys4->__get(_g1);
HXDLIN( 562)										_g1 = (_g1 + 1);
HXDLIN( 562)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 562)								{
HXLINE( 562)									 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 562)									int state2 = -1;
HXDLIN( 562)									int _g2 = 0;
HXDLIN( 562)									while((_g2 < keys4->length)){
HXLINE( 562)										int key = keys4->__get(_g2);
HXDLIN( 562)										_g2 = (_g2 + 1);
HXDLIN( 562)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)2: {
HXLINE( 562)								{
HXLINE( 562)									 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 562)									int state = 1;
HXDLIN( 562)									int _g = 0;
HXDLIN( 562)									while((_g < keys4->length)){
HXLINE( 562)										int key = keys4->__get(_g);
HXDLIN( 562)										_g = (_g + 1);
HXDLIN( 562)										action->addKey(key,state);
            									}
            								}
HXDLIN( 562)								{
HXLINE( 562)									 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 562)									int state1 = 2;
HXDLIN( 562)									int _g1 = 0;
HXDLIN( 562)									while((_g1 < keys4->length)){
HXLINE( 562)										int key = keys4->__get(_g1);
HXDLIN( 562)										_g1 = (_g1 + 1);
HXDLIN( 562)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 562)								{
HXLINE( 562)									 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 562)									int state2 = -1;
HXDLIN( 562)									int _g2 = 0;
HXDLIN( 562)									while((_g2 < keys4->length)){
HXLINE( 562)										int key = keys4->__get(_g2);
HXDLIN( 562)										_g2 = (_g2 + 1);
HXDLIN( 562)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)3: {
HXLINE( 562)								{
HXLINE( 562)									 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 562)									int state = 1;
HXDLIN( 562)									int _g = 0;
HXDLIN( 562)									while((_g < keys4->length)){
HXLINE( 562)										int key = keys4->__get(_g);
HXDLIN( 562)										_g = (_g + 1);
HXDLIN( 562)										action->addKey(key,state);
            									}
            								}
HXDLIN( 562)								{
HXLINE( 562)									 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 562)									int state1 = 2;
HXDLIN( 562)									int _g1 = 0;
HXDLIN( 562)									while((_g1 < keys4->length)){
HXLINE( 562)										int key = keys4->__get(_g1);
HXDLIN( 562)										_g1 = (_g1 + 1);
HXDLIN( 562)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 562)								{
HXLINE( 562)									 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 562)									int state2 = -1;
HXDLIN( 562)									int _g2 = 0;
HXDLIN( 562)									while((_g2 < keys4->length)){
HXLINE( 562)										int key = keys4->__get(_g2);
HXDLIN( 562)										_g2 = (_g2 + 1);
HXDLIN( 562)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)4: {
HXLINE( 562)								{
HXLINE( 562)									 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 562)									int state = 1;
HXDLIN( 562)									int _g = 0;
HXDLIN( 562)									while((_g < keys4->length)){
HXLINE( 562)										int key = keys4->__get(_g);
HXDLIN( 562)										_g = (_g + 1);
HXDLIN( 562)										action->addKey(key,state);
            									}
            								}
HXDLIN( 562)								{
HXLINE( 562)									 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 562)									int state1 = 2;
HXDLIN( 562)									int _g1 = 0;
HXDLIN( 562)									while((_g1 < keys4->length)){
HXLINE( 562)										int key = keys4->__get(_g1);
HXDLIN( 562)										_g1 = (_g1 + 1);
HXDLIN( 562)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 562)								{
HXLINE( 562)									 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 562)									int state2 = -1;
HXDLIN( 562)									int _g2 = 0;
HXDLIN( 562)									while((_g2 < keys4->length)){
HXLINE( 562)										int key = keys4->__get(_g2);
HXDLIN( 562)										_g2 = (_g2 + 1);
HXDLIN( 562)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)5: {
HXLINE( 562)								 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 562)								int state = 2;
HXDLIN( 562)								int _g = 0;
HXDLIN( 562)								while((_g < keys4->length)){
HXLINE( 562)									int key = keys4->__get(_g);
HXDLIN( 562)									_g = (_g + 1);
HXDLIN( 562)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)6: {
HXLINE( 562)								 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 562)								int state = 2;
HXDLIN( 562)								int _g = 0;
HXDLIN( 562)								while((_g < keys4->length)){
HXLINE( 562)									int key = keys4->__get(_g);
HXDLIN( 562)									_g = (_g + 1);
HXDLIN( 562)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)7: {
HXLINE( 562)								 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 562)								int state = 2;
HXDLIN( 562)								int _g = 0;
HXDLIN( 562)								while((_g < keys4->length)){
HXLINE( 562)									int key = keys4->__get(_g);
HXDLIN( 562)									_g = (_g + 1);
HXDLIN( 562)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)8: {
HXLINE( 562)								 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 562)								int state = 2;
HXDLIN( 562)								int _g = 0;
HXDLIN( 562)								while((_g < keys4->length)){
HXLINE( 562)									int key = keys4->__get(_g);
HXDLIN( 562)									_g = (_g + 1);
HXDLIN( 562)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)9: {
HXLINE( 562)								 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 562)								int state = 2;
HXDLIN( 562)								int _g = 0;
HXDLIN( 562)								while((_g < keys4->length)){
HXLINE( 562)									int key = keys4->__get(_g);
HXDLIN( 562)									_g = (_g + 1);
HXDLIN( 562)									action->addKey(key,state);
            								}
            							}
            							break;
            						}
            					}
HXLINE( 563)					{
HXLINE( 563)						::Array< int > keys5 = ::Array_obj< int >::fromData( _hx_array_data_116e4296_778,3);
HXDLIN( 563)						switch((int)(::Control_obj::BACK_dyn()->_hx_getIndex())){
            							case (int)0: {
HXLINE( 563)								{
HXLINE( 563)									 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 563)									int state = 1;
HXDLIN( 563)									int _g = 0;
HXDLIN( 563)									while((_g < keys5->length)){
HXLINE( 563)										int key = keys5->__get(_g);
HXDLIN( 563)										_g = (_g + 1);
HXDLIN( 563)										action->addKey(key,state);
            									}
            								}
HXDLIN( 563)								{
HXLINE( 563)									 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 563)									int state1 = 2;
HXDLIN( 563)									int _g1 = 0;
HXDLIN( 563)									while((_g1 < keys5->length)){
HXLINE( 563)										int key = keys5->__get(_g1);
HXDLIN( 563)										_g1 = (_g1 + 1);
HXDLIN( 563)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 563)								{
HXLINE( 563)									 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 563)									int state2 = -1;
HXDLIN( 563)									int _g2 = 0;
HXDLIN( 563)									while((_g2 < keys5->length)){
HXLINE( 563)										int key = keys5->__get(_g2);
HXDLIN( 563)										_g2 = (_g2 + 1);
HXDLIN( 563)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)1: {
HXLINE( 563)								{
HXLINE( 563)									 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 563)									int state = 1;
HXDLIN( 563)									int _g = 0;
HXDLIN( 563)									while((_g < keys5->length)){
HXLINE( 563)										int key = keys5->__get(_g);
HXDLIN( 563)										_g = (_g + 1);
HXDLIN( 563)										action->addKey(key,state);
            									}
            								}
HXDLIN( 563)								{
HXLINE( 563)									 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 563)									int state1 = 2;
HXDLIN( 563)									int _g1 = 0;
HXDLIN( 563)									while((_g1 < keys5->length)){
HXLINE( 563)										int key = keys5->__get(_g1);
HXDLIN( 563)										_g1 = (_g1 + 1);
HXDLIN( 563)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 563)								{
HXLINE( 563)									 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 563)									int state2 = -1;
HXDLIN( 563)									int _g2 = 0;
HXDLIN( 563)									while((_g2 < keys5->length)){
HXLINE( 563)										int key = keys5->__get(_g2);
HXDLIN( 563)										_g2 = (_g2 + 1);
HXDLIN( 563)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)2: {
HXLINE( 563)								{
HXLINE( 563)									 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 563)									int state = 1;
HXDLIN( 563)									int _g = 0;
HXDLIN( 563)									while((_g < keys5->length)){
HXLINE( 563)										int key = keys5->__get(_g);
HXDLIN( 563)										_g = (_g + 1);
HXDLIN( 563)										action->addKey(key,state);
            									}
            								}
HXDLIN( 563)								{
HXLINE( 563)									 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 563)									int state1 = 2;
HXDLIN( 563)									int _g1 = 0;
HXDLIN( 563)									while((_g1 < keys5->length)){
HXLINE( 563)										int key = keys5->__get(_g1);
HXDLIN( 563)										_g1 = (_g1 + 1);
HXDLIN( 563)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 563)								{
HXLINE( 563)									 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 563)									int state2 = -1;
HXDLIN( 563)									int _g2 = 0;
HXDLIN( 563)									while((_g2 < keys5->length)){
HXLINE( 563)										int key = keys5->__get(_g2);
HXDLIN( 563)										_g2 = (_g2 + 1);
HXDLIN( 563)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)3: {
HXLINE( 563)								{
HXLINE( 563)									 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 563)									int state = 1;
HXDLIN( 563)									int _g = 0;
HXDLIN( 563)									while((_g < keys5->length)){
HXLINE( 563)										int key = keys5->__get(_g);
HXDLIN( 563)										_g = (_g + 1);
HXDLIN( 563)										action->addKey(key,state);
            									}
            								}
HXDLIN( 563)								{
HXLINE( 563)									 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 563)									int state1 = 2;
HXDLIN( 563)									int _g1 = 0;
HXDLIN( 563)									while((_g1 < keys5->length)){
HXLINE( 563)										int key = keys5->__get(_g1);
HXDLIN( 563)										_g1 = (_g1 + 1);
HXDLIN( 563)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 563)								{
HXLINE( 563)									 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 563)									int state2 = -1;
HXDLIN( 563)									int _g2 = 0;
HXDLIN( 563)									while((_g2 < keys5->length)){
HXLINE( 563)										int key = keys5->__get(_g2);
HXDLIN( 563)										_g2 = (_g2 + 1);
HXDLIN( 563)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)4: {
HXLINE( 563)								{
HXLINE( 563)									 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 563)									int state = 1;
HXDLIN( 563)									int _g = 0;
HXDLIN( 563)									while((_g < keys5->length)){
HXLINE( 563)										int key = keys5->__get(_g);
HXDLIN( 563)										_g = (_g + 1);
HXDLIN( 563)										action->addKey(key,state);
            									}
            								}
HXDLIN( 563)								{
HXLINE( 563)									 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 563)									int state1 = 2;
HXDLIN( 563)									int _g1 = 0;
HXDLIN( 563)									while((_g1 < keys5->length)){
HXLINE( 563)										int key = keys5->__get(_g1);
HXDLIN( 563)										_g1 = (_g1 + 1);
HXDLIN( 563)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 563)								{
HXLINE( 563)									 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 563)									int state2 = -1;
HXDLIN( 563)									int _g2 = 0;
HXDLIN( 563)									while((_g2 < keys5->length)){
HXLINE( 563)										int key = keys5->__get(_g2);
HXDLIN( 563)										_g2 = (_g2 + 1);
HXDLIN( 563)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)5: {
HXLINE( 563)								 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 563)								int state = 2;
HXDLIN( 563)								int _g = 0;
HXDLIN( 563)								while((_g < keys5->length)){
HXLINE( 563)									int key = keys5->__get(_g);
HXDLIN( 563)									_g = (_g + 1);
HXDLIN( 563)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)6: {
HXLINE( 563)								 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 563)								int state = 2;
HXDLIN( 563)								int _g = 0;
HXDLIN( 563)								while((_g < keys5->length)){
HXLINE( 563)									int key = keys5->__get(_g);
HXDLIN( 563)									_g = (_g + 1);
HXDLIN( 563)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)7: {
HXLINE( 563)								 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 563)								int state = 2;
HXDLIN( 563)								int _g = 0;
HXDLIN( 563)								while((_g < keys5->length)){
HXLINE( 563)									int key = keys5->__get(_g);
HXDLIN( 563)									_g = (_g + 1);
HXDLIN( 563)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)8: {
HXLINE( 563)								 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 563)								int state = 2;
HXDLIN( 563)								int _g = 0;
HXDLIN( 563)								while((_g < keys5->length)){
HXLINE( 563)									int key = keys5->__get(_g);
HXDLIN( 563)									_g = (_g + 1);
HXDLIN( 563)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)9: {
HXLINE( 563)								 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 563)								int state = 2;
HXDLIN( 563)								int _g = 0;
HXDLIN( 563)								while((_g < keys5->length)){
HXLINE( 563)									int key = keys5->__get(_g);
HXDLIN( 563)									_g = (_g + 1);
HXDLIN( 563)									action->addKey(key,state);
            								}
            							}
            							break;
            						}
            					}
HXLINE( 564)					{
HXLINE( 564)						::Array< int > keys6 = ::Array_obj< int >::fromData( _hx_array_data_116e4296_779,1);
HXDLIN( 564)						switch((int)(::Control_obj::RESET_dyn()->_hx_getIndex())){
            							case (int)0: {
HXLINE( 564)								{
HXLINE( 564)									 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 564)									int state = 1;
HXDLIN( 564)									int _g = 0;
HXDLIN( 564)									while((_g < keys6->length)){
HXLINE( 564)										int key = keys6->__get(_g);
HXDLIN( 564)										_g = (_g + 1);
HXDLIN( 564)										action->addKey(key,state);
            									}
            								}
HXDLIN( 564)								{
HXLINE( 564)									 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 564)									int state1 = 2;
HXDLIN( 564)									int _g1 = 0;
HXDLIN( 564)									while((_g1 < keys6->length)){
HXLINE( 564)										int key = keys6->__get(_g1);
HXDLIN( 564)										_g1 = (_g1 + 1);
HXDLIN( 564)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 564)								{
HXLINE( 564)									 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 564)									int state2 = -1;
HXDLIN( 564)									int _g2 = 0;
HXDLIN( 564)									while((_g2 < keys6->length)){
HXLINE( 564)										int key = keys6->__get(_g2);
HXDLIN( 564)										_g2 = (_g2 + 1);
HXDLIN( 564)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)1: {
HXLINE( 564)								{
HXLINE( 564)									 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 564)									int state = 1;
HXDLIN( 564)									int _g = 0;
HXDLIN( 564)									while((_g < keys6->length)){
HXLINE( 564)										int key = keys6->__get(_g);
HXDLIN( 564)										_g = (_g + 1);
HXDLIN( 564)										action->addKey(key,state);
            									}
            								}
HXDLIN( 564)								{
HXLINE( 564)									 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 564)									int state1 = 2;
HXDLIN( 564)									int _g1 = 0;
HXDLIN( 564)									while((_g1 < keys6->length)){
HXLINE( 564)										int key = keys6->__get(_g1);
HXDLIN( 564)										_g1 = (_g1 + 1);
HXDLIN( 564)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 564)								{
HXLINE( 564)									 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 564)									int state2 = -1;
HXDLIN( 564)									int _g2 = 0;
HXDLIN( 564)									while((_g2 < keys6->length)){
HXLINE( 564)										int key = keys6->__get(_g2);
HXDLIN( 564)										_g2 = (_g2 + 1);
HXDLIN( 564)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)2: {
HXLINE( 564)								{
HXLINE( 564)									 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 564)									int state = 1;
HXDLIN( 564)									int _g = 0;
HXDLIN( 564)									while((_g < keys6->length)){
HXLINE( 564)										int key = keys6->__get(_g);
HXDLIN( 564)										_g = (_g + 1);
HXDLIN( 564)										action->addKey(key,state);
            									}
            								}
HXDLIN( 564)								{
HXLINE( 564)									 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 564)									int state1 = 2;
HXDLIN( 564)									int _g1 = 0;
HXDLIN( 564)									while((_g1 < keys6->length)){
HXLINE( 564)										int key = keys6->__get(_g1);
HXDLIN( 564)										_g1 = (_g1 + 1);
HXDLIN( 564)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 564)								{
HXLINE( 564)									 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 564)									int state2 = -1;
HXDLIN( 564)									int _g2 = 0;
HXDLIN( 564)									while((_g2 < keys6->length)){
HXLINE( 564)										int key = keys6->__get(_g2);
HXDLIN( 564)										_g2 = (_g2 + 1);
HXDLIN( 564)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)3: {
HXLINE( 564)								{
HXLINE( 564)									 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 564)									int state = 1;
HXDLIN( 564)									int _g = 0;
HXDLIN( 564)									while((_g < keys6->length)){
HXLINE( 564)										int key = keys6->__get(_g);
HXDLIN( 564)										_g = (_g + 1);
HXDLIN( 564)										action->addKey(key,state);
            									}
            								}
HXDLIN( 564)								{
HXLINE( 564)									 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 564)									int state1 = 2;
HXDLIN( 564)									int _g1 = 0;
HXDLIN( 564)									while((_g1 < keys6->length)){
HXLINE( 564)										int key = keys6->__get(_g1);
HXDLIN( 564)										_g1 = (_g1 + 1);
HXDLIN( 564)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 564)								{
HXLINE( 564)									 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 564)									int state2 = -1;
HXDLIN( 564)									int _g2 = 0;
HXDLIN( 564)									while((_g2 < keys6->length)){
HXLINE( 564)										int key = keys6->__get(_g2);
HXDLIN( 564)										_g2 = (_g2 + 1);
HXDLIN( 564)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)4: {
HXLINE( 564)								{
HXLINE( 564)									 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 564)									int state = 1;
HXDLIN( 564)									int _g = 0;
HXDLIN( 564)									while((_g < keys6->length)){
HXLINE( 564)										int key = keys6->__get(_g);
HXDLIN( 564)										_g = (_g + 1);
HXDLIN( 564)										action->addKey(key,state);
            									}
            								}
HXDLIN( 564)								{
HXLINE( 564)									 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 564)									int state1 = 2;
HXDLIN( 564)									int _g1 = 0;
HXDLIN( 564)									while((_g1 < keys6->length)){
HXLINE( 564)										int key = keys6->__get(_g1);
HXDLIN( 564)										_g1 = (_g1 + 1);
HXDLIN( 564)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 564)								{
HXLINE( 564)									 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 564)									int state2 = -1;
HXDLIN( 564)									int _g2 = 0;
HXDLIN( 564)									while((_g2 < keys6->length)){
HXLINE( 564)										int key = keys6->__get(_g2);
HXDLIN( 564)										_g2 = (_g2 + 1);
HXDLIN( 564)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)5: {
HXLINE( 564)								 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 564)								int state = 2;
HXDLIN( 564)								int _g = 0;
HXDLIN( 564)								while((_g < keys6->length)){
HXLINE( 564)									int key = keys6->__get(_g);
HXDLIN( 564)									_g = (_g + 1);
HXDLIN( 564)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)6: {
HXLINE( 564)								 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 564)								int state = 2;
HXDLIN( 564)								int _g = 0;
HXDLIN( 564)								while((_g < keys6->length)){
HXLINE( 564)									int key = keys6->__get(_g);
HXDLIN( 564)									_g = (_g + 1);
HXDLIN( 564)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)7: {
HXLINE( 564)								 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 564)								int state = 2;
HXDLIN( 564)								int _g = 0;
HXDLIN( 564)								while((_g < keys6->length)){
HXLINE( 564)									int key = keys6->__get(_g);
HXDLIN( 564)									_g = (_g + 1);
HXDLIN( 564)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)8: {
HXLINE( 564)								 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 564)								int state = 2;
HXDLIN( 564)								int _g = 0;
HXDLIN( 564)								while((_g < keys6->length)){
HXLINE( 564)									int key = keys6->__get(_g);
HXDLIN( 564)									_g = (_g + 1);
HXDLIN( 564)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)9: {
HXLINE( 564)								 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 564)								int state = 2;
HXDLIN( 564)								int _g = 0;
HXDLIN( 564)								while((_g < keys6->length)){
HXLINE( 564)									int key = keys6->__get(_g);
HXDLIN( 564)									_g = (_g + 1);
HXDLIN( 564)									action->addKey(key,state);
            								}
            							}
            							break;
            						}
            					}
HXLINE( 565)					{
HXLINE( 565)						::Array< int > keys7 = ::Array_obj< int >::__new(0);
HXDLIN( 565)						switch((int)(::Control_obj::CHEAT_dyn()->_hx_getIndex())){
            							case (int)0: {
HXLINE( 565)								{
HXLINE( 565)									 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 565)									int state = 1;
HXDLIN( 565)									int _g = 0;
HXDLIN( 565)									while((_g < keys7->length)){
HXLINE( 565)										int key = keys7->__get(_g);
HXDLIN( 565)										_g = (_g + 1);
HXDLIN( 565)										action->addKey(key,state);
            									}
            								}
HXDLIN( 565)								{
HXLINE( 565)									 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 565)									int state1 = 2;
HXDLIN( 565)									int _g1 = 0;
HXDLIN( 565)									while((_g1 < keys7->length)){
HXLINE( 565)										int key = keys7->__get(_g1);
HXDLIN( 565)										_g1 = (_g1 + 1);
HXDLIN( 565)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 565)								{
HXLINE( 565)									 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 565)									int state2 = -1;
HXDLIN( 565)									int _g2 = 0;
HXDLIN( 565)									while((_g2 < keys7->length)){
HXLINE( 565)										int key = keys7->__get(_g2);
HXDLIN( 565)										_g2 = (_g2 + 1);
HXDLIN( 565)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)1: {
HXLINE( 565)								{
HXLINE( 565)									 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 565)									int state = 1;
HXDLIN( 565)									int _g = 0;
HXDLIN( 565)									while((_g < keys7->length)){
HXLINE( 565)										int key = keys7->__get(_g);
HXDLIN( 565)										_g = (_g + 1);
HXDLIN( 565)										action->addKey(key,state);
            									}
            								}
HXDLIN( 565)								{
HXLINE( 565)									 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 565)									int state1 = 2;
HXDLIN( 565)									int _g1 = 0;
HXDLIN( 565)									while((_g1 < keys7->length)){
HXLINE( 565)										int key = keys7->__get(_g1);
HXDLIN( 565)										_g1 = (_g1 + 1);
HXDLIN( 565)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 565)								{
HXLINE( 565)									 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 565)									int state2 = -1;
HXDLIN( 565)									int _g2 = 0;
HXDLIN( 565)									while((_g2 < keys7->length)){
HXLINE( 565)										int key = keys7->__get(_g2);
HXDLIN( 565)										_g2 = (_g2 + 1);
HXDLIN( 565)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)2: {
HXLINE( 565)								{
HXLINE( 565)									 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 565)									int state = 1;
HXDLIN( 565)									int _g = 0;
HXDLIN( 565)									while((_g < keys7->length)){
HXLINE( 565)										int key = keys7->__get(_g);
HXDLIN( 565)										_g = (_g + 1);
HXDLIN( 565)										action->addKey(key,state);
            									}
            								}
HXDLIN( 565)								{
HXLINE( 565)									 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 565)									int state1 = 2;
HXDLIN( 565)									int _g1 = 0;
HXDLIN( 565)									while((_g1 < keys7->length)){
HXLINE( 565)										int key = keys7->__get(_g1);
HXDLIN( 565)										_g1 = (_g1 + 1);
HXDLIN( 565)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 565)								{
HXLINE( 565)									 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 565)									int state2 = -1;
HXDLIN( 565)									int _g2 = 0;
HXDLIN( 565)									while((_g2 < keys7->length)){
HXLINE( 565)										int key = keys7->__get(_g2);
HXDLIN( 565)										_g2 = (_g2 + 1);
HXDLIN( 565)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)3: {
HXLINE( 565)								{
HXLINE( 565)									 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 565)									int state = 1;
HXDLIN( 565)									int _g = 0;
HXDLIN( 565)									while((_g < keys7->length)){
HXLINE( 565)										int key = keys7->__get(_g);
HXDLIN( 565)										_g = (_g + 1);
HXDLIN( 565)										action->addKey(key,state);
            									}
            								}
HXDLIN( 565)								{
HXLINE( 565)									 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 565)									int state1 = 2;
HXDLIN( 565)									int _g1 = 0;
HXDLIN( 565)									while((_g1 < keys7->length)){
HXLINE( 565)										int key = keys7->__get(_g1);
HXDLIN( 565)										_g1 = (_g1 + 1);
HXDLIN( 565)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 565)								{
HXLINE( 565)									 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 565)									int state2 = -1;
HXDLIN( 565)									int _g2 = 0;
HXDLIN( 565)									while((_g2 < keys7->length)){
HXLINE( 565)										int key = keys7->__get(_g2);
HXDLIN( 565)										_g2 = (_g2 + 1);
HXDLIN( 565)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)4: {
HXLINE( 565)								{
HXLINE( 565)									 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 565)									int state = 1;
HXDLIN( 565)									int _g = 0;
HXDLIN( 565)									while((_g < keys7->length)){
HXLINE( 565)										int key = keys7->__get(_g);
HXDLIN( 565)										_g = (_g + 1);
HXDLIN( 565)										action->addKey(key,state);
            									}
            								}
HXDLIN( 565)								{
HXLINE( 565)									 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 565)									int state1 = 2;
HXDLIN( 565)									int _g1 = 0;
HXDLIN( 565)									while((_g1 < keys7->length)){
HXLINE( 565)										int key = keys7->__get(_g1);
HXDLIN( 565)										_g1 = (_g1 + 1);
HXDLIN( 565)										action1->addKey(key,state1);
            									}
            								}
HXDLIN( 565)								{
HXLINE( 565)									 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 565)									int state2 = -1;
HXDLIN( 565)									int _g2 = 0;
HXDLIN( 565)									while((_g2 < keys7->length)){
HXLINE( 565)										int key = keys7->__get(_g2);
HXDLIN( 565)										_g2 = (_g2 + 1);
HXDLIN( 565)										action2->addKey(key,state2);
            									}
            								}
            							}
            							break;
            							case (int)5: {
HXLINE( 565)								 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 565)								int state = 2;
HXDLIN( 565)								int _g = 0;
HXDLIN( 565)								while((_g < keys7->length)){
HXLINE( 565)									int key = keys7->__get(_g);
HXDLIN( 565)									_g = (_g + 1);
HXDLIN( 565)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)6: {
HXLINE( 565)								 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 565)								int state = 2;
HXDLIN( 565)								int _g = 0;
HXDLIN( 565)								while((_g < keys7->length)){
HXLINE( 565)									int key = keys7->__get(_g);
HXDLIN( 565)									_g = (_g + 1);
HXDLIN( 565)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)7: {
HXLINE( 565)								 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 565)								int state = 2;
HXDLIN( 565)								int _g = 0;
HXDLIN( 565)								while((_g < keys7->length)){
HXLINE( 565)									int key = keys7->__get(_g);
HXDLIN( 565)									_g = (_g + 1);
HXDLIN( 565)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)8: {
HXLINE( 565)								 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 565)								int state = 2;
HXDLIN( 565)								int _g = 0;
HXDLIN( 565)								while((_g < keys7->length)){
HXLINE( 565)									int key = keys7->__get(_g);
HXDLIN( 565)									_g = (_g + 1);
HXDLIN( 565)									action->addKey(key,state);
            								}
            							}
            							break;
            							case (int)9: {
HXLINE( 565)								 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 565)								int state = 2;
HXDLIN( 565)								int _g = 0;
HXDLIN( 565)								while((_g < keys7->length)){
HXLINE( 565)									int key = keys7->__get(_g);
HXDLIN( 565)									_g = (_g + 1);
HXDLIN( 565)									action->addKey(key,state);
            								}
            							}
            							break;
            						}
            					}
            				}
            			}
            			break;
            			case (int)2: {
            			}
            			break;
            			case (int)3: {
HXLINE( 568)				{
HXLINE( 568)					::Dynamic this1 = ::flixel::input::keyboard::_FlxKey::FlxKey_Impl__obj::fromStringMap;
HXDLIN( 568)					 ::Dynamic key;
HXDLIN( 568)					switch((int)(::SaveType_obj::CUSTOM_KEYBINDS_dyn()->_hx_getIndex())){
            						case (int)1: {
HXLINE( 568)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 568)								::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            							}
HXDLIN( 568)							key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            						}
            						break;
            						case (int)2: {
HXLINE( 568)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 568)								::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            							}
            							else {
HXLINE( 568)								if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 568)									::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            								}
            							}
HXDLIN( 568)							key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            						}
            						break;
            						case (int)3: {
HXLINE( 568)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 568)								::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            							}
HXDLIN( 568)							key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            						}
            						break;
            						case (int)4: {
HXLINE( 568)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 568)								::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            							}
HXDLIN( 568)							key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            						}
            						break;
            						case (int)5: {
HXLINE( 568)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 568)								::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            							}
HXDLIN( 568)							key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            						}
            						break;
            						case (int)6: {
HXLINE( 568)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 568)								::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            							}
HXDLIN( 568)							key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            						}
            						break;
            						case (int)7: {
HXLINE( 568)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 568)								::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            							}
HXDLIN( 568)							key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            						}
            						break;
            						case (int)8: {
HXLINE( 568)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 568)								::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            							}
HXDLIN( 568)							key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            						}
            						break;
            						case (int)9: {
HXLINE( 568)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 568)								::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            							}
HXDLIN( 568)							key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            						}
            						break;
            						case (int)10: {
HXLINE( 568)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 568)								::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            							}
HXDLIN( 568)							key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            						}
            						break;
            						case (int)11: {
HXLINE( 568)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 568)								::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            							}
            							else {
HXLINE( 568)								if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 568)									::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            								}
            							}
HXDLIN( 568)							key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            						}
            						break;
            						case (int)12: {
HXLINE( 568)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 568)								::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            							}
HXDLIN( 568)							key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            						}
            						break;
            						case (int)13: {
HXLINE( 568)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 568)								::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            							}
HXDLIN( 568)							key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            						}
            						break;
            						case (int)14: {
HXLINE( 568)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 568)								::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            							}
HXDLIN( 568)							key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            						}
            						break;
            						case (int)15: {
HXLINE( 568)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 568)								::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            							}
HXDLIN( 568)							key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            						}
            						break;
            						case (int)16: {
HXLINE( 568)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 568)								::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            							}
HXDLIN( 568)							key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            						}
            						break;
            						case (int)17: {
HXLINE( 568)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 568)								::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            							}
HXDLIN( 568)							key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            						}
            						break;
            						case (int)18: {
HXLINE( 568)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 568)								::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            							}
HXDLIN( 568)							key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            						}
            						break;
            						case (int)19: {
HXLINE( 568)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 568)								::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            							}
HXDLIN( 568)							key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            						}
            						break;
            						case (int)20: {
HXLINE( 568)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 568)								::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            							}
HXDLIN( 568)							key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            						}
            						break;
            						case (int)21: {
HXLINE( 568)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 568)								::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            							}
HXDLIN( 568)							key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            						}
            						break;
            						default:{
HXLINE( 568)							key = null();
            						}
            					}
HXDLIN( 568)					::Array< int > keys = ::Array_obj< int >::__new(2)->init(0,( ( ::haxe::ds::StringMap)(this1) )->get(key->__Field(HX_("split",da,ea,6e,81),::hx::paccDynamic)(HX_(" ",20,00,00,00))->__GetItem(2)))->init(1,38);
HXDLIN( 568)					switch((int)(::Control_obj::UP_dyn()->_hx_getIndex())){
            						case (int)0: {
HXLINE( 568)							{
HXLINE( 568)								 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 568)								int state = 1;
HXDLIN( 568)								int _g = 0;
HXDLIN( 568)								while((_g < keys->length)){
HXLINE( 568)									int key = keys->__get(_g);
HXDLIN( 568)									_g = (_g + 1);
HXDLIN( 568)									action->addKey(key,state);
            								}
            							}
HXDLIN( 568)							{
HXLINE( 568)								 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 568)								int state1 = 2;
HXDLIN( 568)								int _g1 = 0;
HXDLIN( 568)								while((_g1 < keys->length)){
HXLINE( 568)									int key = keys->__get(_g1);
HXDLIN( 568)									_g1 = (_g1 + 1);
HXDLIN( 568)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 568)							{
HXLINE( 568)								 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 568)								int state2 = -1;
HXDLIN( 568)								int _g2 = 0;
HXDLIN( 568)								while((_g2 < keys->length)){
HXLINE( 568)									int key = keys->__get(_g2);
HXDLIN( 568)									_g2 = (_g2 + 1);
HXDLIN( 568)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)1: {
HXLINE( 568)							{
HXLINE( 568)								 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 568)								int state = 1;
HXDLIN( 568)								int _g = 0;
HXDLIN( 568)								while((_g < keys->length)){
HXLINE( 568)									int key = keys->__get(_g);
HXDLIN( 568)									_g = (_g + 1);
HXDLIN( 568)									action->addKey(key,state);
            								}
            							}
HXDLIN( 568)							{
HXLINE( 568)								 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 568)								int state1 = 2;
HXDLIN( 568)								int _g1 = 0;
HXDLIN( 568)								while((_g1 < keys->length)){
HXLINE( 568)									int key = keys->__get(_g1);
HXDLIN( 568)									_g1 = (_g1 + 1);
HXDLIN( 568)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 568)							{
HXLINE( 568)								 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 568)								int state2 = -1;
HXDLIN( 568)								int _g2 = 0;
HXDLIN( 568)								while((_g2 < keys->length)){
HXLINE( 568)									int key = keys->__get(_g2);
HXDLIN( 568)									_g2 = (_g2 + 1);
HXDLIN( 568)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)2: {
HXLINE( 568)							{
HXLINE( 568)								 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 568)								int state = 1;
HXDLIN( 568)								int _g = 0;
HXDLIN( 568)								while((_g < keys->length)){
HXLINE( 568)									int key = keys->__get(_g);
HXDLIN( 568)									_g = (_g + 1);
HXDLIN( 568)									action->addKey(key,state);
            								}
            							}
HXDLIN( 568)							{
HXLINE( 568)								 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 568)								int state1 = 2;
HXDLIN( 568)								int _g1 = 0;
HXDLIN( 568)								while((_g1 < keys->length)){
HXLINE( 568)									int key = keys->__get(_g1);
HXDLIN( 568)									_g1 = (_g1 + 1);
HXDLIN( 568)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 568)							{
HXLINE( 568)								 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 568)								int state2 = -1;
HXDLIN( 568)								int _g2 = 0;
HXDLIN( 568)								while((_g2 < keys->length)){
HXLINE( 568)									int key = keys->__get(_g2);
HXDLIN( 568)									_g2 = (_g2 + 1);
HXDLIN( 568)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)3: {
HXLINE( 568)							{
HXLINE( 568)								 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 568)								int state = 1;
HXDLIN( 568)								int _g = 0;
HXDLIN( 568)								while((_g < keys->length)){
HXLINE( 568)									int key = keys->__get(_g);
HXDLIN( 568)									_g = (_g + 1);
HXDLIN( 568)									action->addKey(key,state);
            								}
            							}
HXDLIN( 568)							{
HXLINE( 568)								 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 568)								int state1 = 2;
HXDLIN( 568)								int _g1 = 0;
HXDLIN( 568)								while((_g1 < keys->length)){
HXLINE( 568)									int key = keys->__get(_g1);
HXDLIN( 568)									_g1 = (_g1 + 1);
HXDLIN( 568)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 568)							{
HXLINE( 568)								 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 568)								int state2 = -1;
HXDLIN( 568)								int _g2 = 0;
HXDLIN( 568)								while((_g2 < keys->length)){
HXLINE( 568)									int key = keys->__get(_g2);
HXDLIN( 568)									_g2 = (_g2 + 1);
HXDLIN( 568)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)4: {
HXLINE( 568)							{
HXLINE( 568)								 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 568)								int state = 1;
HXDLIN( 568)								int _g = 0;
HXDLIN( 568)								while((_g < keys->length)){
HXLINE( 568)									int key = keys->__get(_g);
HXDLIN( 568)									_g = (_g + 1);
HXDLIN( 568)									action->addKey(key,state);
            								}
            							}
HXDLIN( 568)							{
HXLINE( 568)								 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 568)								int state1 = 2;
HXDLIN( 568)								int _g1 = 0;
HXDLIN( 568)								while((_g1 < keys->length)){
HXLINE( 568)									int key = keys->__get(_g1);
HXDLIN( 568)									_g1 = (_g1 + 1);
HXDLIN( 568)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 568)							{
HXLINE( 568)								 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 568)								int state2 = -1;
HXDLIN( 568)								int _g2 = 0;
HXDLIN( 568)								while((_g2 < keys->length)){
HXLINE( 568)									int key = keys->__get(_g2);
HXDLIN( 568)									_g2 = (_g2 + 1);
HXDLIN( 568)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)5: {
HXLINE( 568)							 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 568)							int state = 2;
HXDLIN( 568)							int _g = 0;
HXDLIN( 568)							while((_g < keys->length)){
HXLINE( 568)								int key = keys->__get(_g);
HXDLIN( 568)								_g = (_g + 1);
HXDLIN( 568)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)6: {
HXLINE( 568)							 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 568)							int state = 2;
HXDLIN( 568)							int _g = 0;
HXDLIN( 568)							while((_g < keys->length)){
HXLINE( 568)								int key = keys->__get(_g);
HXDLIN( 568)								_g = (_g + 1);
HXDLIN( 568)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)7: {
HXLINE( 568)							 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 568)							int state = 2;
HXDLIN( 568)							int _g = 0;
HXDLIN( 568)							while((_g < keys->length)){
HXLINE( 568)								int key = keys->__get(_g);
HXDLIN( 568)								_g = (_g + 1);
HXDLIN( 568)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)8: {
HXLINE( 568)							 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 568)							int state = 2;
HXDLIN( 568)							int _g = 0;
HXDLIN( 568)							while((_g < keys->length)){
HXLINE( 568)								int key = keys->__get(_g);
HXDLIN( 568)								_g = (_g + 1);
HXDLIN( 568)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)9: {
HXLINE( 568)							 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 568)							int state = 2;
HXDLIN( 568)							int _g = 0;
HXDLIN( 568)							while((_g < keys->length)){
HXLINE( 568)								int key = keys->__get(_g);
HXDLIN( 568)								_g = (_g + 1);
HXDLIN( 568)								action->addKey(key,state);
            							}
            						}
            						break;
            					}
            				}
HXLINE( 569)				{
HXLINE( 569)					::Dynamic this2 = ::flixel::input::keyboard::_FlxKey::FlxKey_Impl__obj::fromStringMap;
HXDLIN( 569)					 ::Dynamic key1;
HXDLIN( 569)					switch((int)(::SaveType_obj::CUSTOM_KEYBINDS_dyn()->_hx_getIndex())){
            						case (int)1: {
HXLINE( 569)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 569)								::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            							}
HXDLIN( 569)							key1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            						}
            						break;
            						case (int)2: {
HXLINE( 569)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 569)								::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            							}
            							else {
HXLINE( 569)								if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 569)									::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            								}
            							}
HXDLIN( 569)							key1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            						}
            						break;
            						case (int)3: {
HXLINE( 569)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 569)								::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            							}
HXDLIN( 569)							key1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            						}
            						break;
            						case (int)4: {
HXLINE( 569)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 569)								::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            							}
HXDLIN( 569)							key1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            						}
            						break;
            						case (int)5: {
HXLINE( 569)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 569)								::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            							}
HXDLIN( 569)							key1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            						}
            						break;
            						case (int)6: {
HXLINE( 569)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 569)								::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            							}
HXDLIN( 569)							key1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            						}
            						break;
            						case (int)7: {
HXLINE( 569)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 569)								::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            							}
HXDLIN( 569)							key1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            						}
            						break;
            						case (int)8: {
HXLINE( 569)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 569)								::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            							}
HXDLIN( 569)							key1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            						}
            						break;
            						case (int)9: {
HXLINE( 569)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 569)								::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            							}
HXDLIN( 569)							key1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            						}
            						break;
            						case (int)10: {
HXLINE( 569)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 569)								::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            							}
HXDLIN( 569)							key1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            						}
            						break;
            						case (int)11: {
HXLINE( 569)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 569)								::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            							}
            							else {
HXLINE( 569)								if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 569)									::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            								}
            							}
HXDLIN( 569)							key1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            						}
            						break;
            						case (int)12: {
HXLINE( 569)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 569)								::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            							}
HXDLIN( 569)							key1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            						}
            						break;
            						case (int)13: {
HXLINE( 569)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 569)								::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            							}
HXDLIN( 569)							key1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            						}
            						break;
            						case (int)14: {
HXLINE( 569)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 569)								::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            							}
HXDLIN( 569)							key1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            						}
            						break;
            						case (int)15: {
HXLINE( 569)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 569)								::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            							}
HXDLIN( 569)							key1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            						}
            						break;
            						case (int)16: {
HXLINE( 569)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 569)								::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            							}
HXDLIN( 569)							key1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            						}
            						break;
            						case (int)17: {
HXLINE( 569)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 569)								::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            							}
HXDLIN( 569)							key1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            						}
            						break;
            						case (int)18: {
HXLINE( 569)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 569)								::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            							}
HXDLIN( 569)							key1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            						}
            						break;
            						case (int)19: {
HXLINE( 569)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 569)								::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            							}
HXDLIN( 569)							key1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            						}
            						break;
            						case (int)20: {
HXLINE( 569)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 569)								::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            							}
HXDLIN( 569)							key1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            						}
            						break;
            						case (int)21: {
HXLINE( 569)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 569)								::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            							}
HXDLIN( 569)							key1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            						}
            						break;
            						default:{
HXLINE( 569)							key1 = null();
            						}
            					}
HXDLIN( 569)					::Array< int > keys1 = ::Array_obj< int >::__new(2)->init(0,( ( ::haxe::ds::StringMap)(this2) )->get(key1->__Field(HX_("split",da,ea,6e,81),::hx::paccDynamic)(HX_(" ",20,00,00,00))->__GetItem(1)))->init(1,40);
HXDLIN( 569)					switch((int)(::Control_obj::DOWN_dyn()->_hx_getIndex())){
            						case (int)0: {
HXLINE( 569)							{
HXLINE( 569)								 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 569)								int state = 1;
HXDLIN( 569)								int _g = 0;
HXDLIN( 569)								while((_g < keys1->length)){
HXLINE( 569)									int key = keys1->__get(_g);
HXDLIN( 569)									_g = (_g + 1);
HXDLIN( 569)									action->addKey(key,state);
            								}
            							}
HXDLIN( 569)							{
HXLINE( 569)								 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 569)								int state1 = 2;
HXDLIN( 569)								int _g1 = 0;
HXDLIN( 569)								while((_g1 < keys1->length)){
HXLINE( 569)									int key = keys1->__get(_g1);
HXDLIN( 569)									_g1 = (_g1 + 1);
HXDLIN( 569)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 569)							{
HXLINE( 569)								 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 569)								int state2 = -1;
HXDLIN( 569)								int _g2 = 0;
HXDLIN( 569)								while((_g2 < keys1->length)){
HXLINE( 569)									int key = keys1->__get(_g2);
HXDLIN( 569)									_g2 = (_g2 + 1);
HXDLIN( 569)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)1: {
HXLINE( 569)							{
HXLINE( 569)								 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 569)								int state = 1;
HXDLIN( 569)								int _g = 0;
HXDLIN( 569)								while((_g < keys1->length)){
HXLINE( 569)									int key = keys1->__get(_g);
HXDLIN( 569)									_g = (_g + 1);
HXDLIN( 569)									action->addKey(key,state);
            								}
            							}
HXDLIN( 569)							{
HXLINE( 569)								 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 569)								int state1 = 2;
HXDLIN( 569)								int _g1 = 0;
HXDLIN( 569)								while((_g1 < keys1->length)){
HXLINE( 569)									int key = keys1->__get(_g1);
HXDLIN( 569)									_g1 = (_g1 + 1);
HXDLIN( 569)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 569)							{
HXLINE( 569)								 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 569)								int state2 = -1;
HXDLIN( 569)								int _g2 = 0;
HXDLIN( 569)								while((_g2 < keys1->length)){
HXLINE( 569)									int key = keys1->__get(_g2);
HXDLIN( 569)									_g2 = (_g2 + 1);
HXDLIN( 569)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)2: {
HXLINE( 569)							{
HXLINE( 569)								 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 569)								int state = 1;
HXDLIN( 569)								int _g = 0;
HXDLIN( 569)								while((_g < keys1->length)){
HXLINE( 569)									int key = keys1->__get(_g);
HXDLIN( 569)									_g = (_g + 1);
HXDLIN( 569)									action->addKey(key,state);
            								}
            							}
HXDLIN( 569)							{
HXLINE( 569)								 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 569)								int state1 = 2;
HXDLIN( 569)								int _g1 = 0;
HXDLIN( 569)								while((_g1 < keys1->length)){
HXLINE( 569)									int key = keys1->__get(_g1);
HXDLIN( 569)									_g1 = (_g1 + 1);
HXDLIN( 569)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 569)							{
HXLINE( 569)								 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 569)								int state2 = -1;
HXDLIN( 569)								int _g2 = 0;
HXDLIN( 569)								while((_g2 < keys1->length)){
HXLINE( 569)									int key = keys1->__get(_g2);
HXDLIN( 569)									_g2 = (_g2 + 1);
HXDLIN( 569)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)3: {
HXLINE( 569)							{
HXLINE( 569)								 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 569)								int state = 1;
HXDLIN( 569)								int _g = 0;
HXDLIN( 569)								while((_g < keys1->length)){
HXLINE( 569)									int key = keys1->__get(_g);
HXDLIN( 569)									_g = (_g + 1);
HXDLIN( 569)									action->addKey(key,state);
            								}
            							}
HXDLIN( 569)							{
HXLINE( 569)								 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 569)								int state1 = 2;
HXDLIN( 569)								int _g1 = 0;
HXDLIN( 569)								while((_g1 < keys1->length)){
HXLINE( 569)									int key = keys1->__get(_g1);
HXDLIN( 569)									_g1 = (_g1 + 1);
HXDLIN( 569)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 569)							{
HXLINE( 569)								 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 569)								int state2 = -1;
HXDLIN( 569)								int _g2 = 0;
HXDLIN( 569)								while((_g2 < keys1->length)){
HXLINE( 569)									int key = keys1->__get(_g2);
HXDLIN( 569)									_g2 = (_g2 + 1);
HXDLIN( 569)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)4: {
HXLINE( 569)							{
HXLINE( 569)								 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 569)								int state = 1;
HXDLIN( 569)								int _g = 0;
HXDLIN( 569)								while((_g < keys1->length)){
HXLINE( 569)									int key = keys1->__get(_g);
HXDLIN( 569)									_g = (_g + 1);
HXDLIN( 569)									action->addKey(key,state);
            								}
            							}
HXDLIN( 569)							{
HXLINE( 569)								 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 569)								int state1 = 2;
HXDLIN( 569)								int _g1 = 0;
HXDLIN( 569)								while((_g1 < keys1->length)){
HXLINE( 569)									int key = keys1->__get(_g1);
HXDLIN( 569)									_g1 = (_g1 + 1);
HXDLIN( 569)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 569)							{
HXLINE( 569)								 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 569)								int state2 = -1;
HXDLIN( 569)								int _g2 = 0;
HXDLIN( 569)								while((_g2 < keys1->length)){
HXLINE( 569)									int key = keys1->__get(_g2);
HXDLIN( 569)									_g2 = (_g2 + 1);
HXDLIN( 569)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)5: {
HXLINE( 569)							 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 569)							int state = 2;
HXDLIN( 569)							int _g = 0;
HXDLIN( 569)							while((_g < keys1->length)){
HXLINE( 569)								int key = keys1->__get(_g);
HXDLIN( 569)								_g = (_g + 1);
HXDLIN( 569)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)6: {
HXLINE( 569)							 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 569)							int state = 2;
HXDLIN( 569)							int _g = 0;
HXDLIN( 569)							while((_g < keys1->length)){
HXLINE( 569)								int key = keys1->__get(_g);
HXDLIN( 569)								_g = (_g + 1);
HXDLIN( 569)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)7: {
HXLINE( 569)							 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 569)							int state = 2;
HXDLIN( 569)							int _g = 0;
HXDLIN( 569)							while((_g < keys1->length)){
HXLINE( 569)								int key = keys1->__get(_g);
HXDLIN( 569)								_g = (_g + 1);
HXDLIN( 569)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)8: {
HXLINE( 569)							 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 569)							int state = 2;
HXDLIN( 569)							int _g = 0;
HXDLIN( 569)							while((_g < keys1->length)){
HXLINE( 569)								int key = keys1->__get(_g);
HXDLIN( 569)								_g = (_g + 1);
HXDLIN( 569)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)9: {
HXLINE( 569)							 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 569)							int state = 2;
HXDLIN( 569)							int _g = 0;
HXDLIN( 569)							while((_g < keys1->length)){
HXLINE( 569)								int key = keys1->__get(_g);
HXDLIN( 569)								_g = (_g + 1);
HXDLIN( 569)								action->addKey(key,state);
            							}
            						}
            						break;
            					}
            				}
HXLINE( 570)				{
HXLINE( 570)					::Dynamic this3 = ::flixel::input::keyboard::_FlxKey::FlxKey_Impl__obj::fromStringMap;
HXDLIN( 570)					 ::Dynamic key2;
HXDLIN( 570)					switch((int)(::SaveType_obj::CUSTOM_KEYBINDS_dyn()->_hx_getIndex())){
            						case (int)1: {
HXLINE( 570)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 570)								::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            							}
HXDLIN( 570)							key2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            						}
            						break;
            						case (int)2: {
HXLINE( 570)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 570)								::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            							}
            							else {
HXLINE( 570)								if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 570)									::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            								}
            							}
HXDLIN( 570)							key2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            						}
            						break;
            						case (int)3: {
HXLINE( 570)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 570)								::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            							}
HXDLIN( 570)							key2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            						}
            						break;
            						case (int)4: {
HXLINE( 570)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 570)								::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            							}
HXDLIN( 570)							key2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            						}
            						break;
            						case (int)5: {
HXLINE( 570)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 570)								::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            							}
HXDLIN( 570)							key2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            						}
            						break;
            						case (int)6: {
HXLINE( 570)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 570)								::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            							}
HXDLIN( 570)							key2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            						}
            						break;
            						case (int)7: {
HXLINE( 570)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 570)								::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            							}
HXDLIN( 570)							key2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            						}
            						break;
            						case (int)8: {
HXLINE( 570)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 570)								::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            							}
HXDLIN( 570)							key2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            						}
            						break;
            						case (int)9: {
HXLINE( 570)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 570)								::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            							}
HXDLIN( 570)							key2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            						}
            						break;
            						case (int)10: {
HXLINE( 570)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 570)								::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            							}
HXDLIN( 570)							key2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            						}
            						break;
            						case (int)11: {
HXLINE( 570)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 570)								::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            							}
            							else {
HXLINE( 570)								if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 570)									::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            								}
            							}
HXDLIN( 570)							key2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            						}
            						break;
            						case (int)12: {
HXLINE( 570)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 570)								::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            							}
HXDLIN( 570)							key2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            						}
            						break;
            						case (int)13: {
HXLINE( 570)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 570)								::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            							}
HXDLIN( 570)							key2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            						}
            						break;
            						case (int)14: {
HXLINE( 570)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 570)								::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            							}
HXDLIN( 570)							key2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            						}
            						break;
            						case (int)15: {
HXLINE( 570)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 570)								::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            							}
HXDLIN( 570)							key2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            						}
            						break;
            						case (int)16: {
HXLINE( 570)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 570)								::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            							}
HXDLIN( 570)							key2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            						}
            						break;
            						case (int)17: {
HXLINE( 570)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 570)								::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            							}
HXDLIN( 570)							key2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            						}
            						break;
            						case (int)18: {
HXLINE( 570)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 570)								::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            							}
HXDLIN( 570)							key2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            						}
            						break;
            						case (int)19: {
HXLINE( 570)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 570)								::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            							}
HXDLIN( 570)							key2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            						}
            						break;
            						case (int)20: {
HXLINE( 570)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 570)								::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            							}
HXDLIN( 570)							key2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            						}
            						break;
            						case (int)21: {
HXLINE( 570)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 570)								::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            							}
HXDLIN( 570)							key2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            						}
            						break;
            						default:{
HXLINE( 570)							key2 = null();
            						}
            					}
HXDLIN( 570)					::Array< int > keys2 = ::Array_obj< int >::__new(2)->init(0,( ( ::haxe::ds::StringMap)(this3) )->get(key2->__Field(HX_("split",da,ea,6e,81),::hx::paccDynamic)(HX_(" ",20,00,00,00))->__GetItem(0)))->init(1,37);
HXDLIN( 570)					switch((int)(::Control_obj::LEFT_dyn()->_hx_getIndex())){
            						case (int)0: {
HXLINE( 570)							{
HXLINE( 570)								 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 570)								int state = 1;
HXDLIN( 570)								int _g = 0;
HXDLIN( 570)								while((_g < keys2->length)){
HXLINE( 570)									int key = keys2->__get(_g);
HXDLIN( 570)									_g = (_g + 1);
HXDLIN( 570)									action->addKey(key,state);
            								}
            							}
HXDLIN( 570)							{
HXLINE( 570)								 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 570)								int state1 = 2;
HXDLIN( 570)								int _g1 = 0;
HXDLIN( 570)								while((_g1 < keys2->length)){
HXLINE( 570)									int key = keys2->__get(_g1);
HXDLIN( 570)									_g1 = (_g1 + 1);
HXDLIN( 570)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 570)							{
HXLINE( 570)								 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 570)								int state2 = -1;
HXDLIN( 570)								int _g2 = 0;
HXDLIN( 570)								while((_g2 < keys2->length)){
HXLINE( 570)									int key = keys2->__get(_g2);
HXDLIN( 570)									_g2 = (_g2 + 1);
HXDLIN( 570)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)1: {
HXLINE( 570)							{
HXLINE( 570)								 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 570)								int state = 1;
HXDLIN( 570)								int _g = 0;
HXDLIN( 570)								while((_g < keys2->length)){
HXLINE( 570)									int key = keys2->__get(_g);
HXDLIN( 570)									_g = (_g + 1);
HXDLIN( 570)									action->addKey(key,state);
            								}
            							}
HXDLIN( 570)							{
HXLINE( 570)								 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 570)								int state1 = 2;
HXDLIN( 570)								int _g1 = 0;
HXDLIN( 570)								while((_g1 < keys2->length)){
HXLINE( 570)									int key = keys2->__get(_g1);
HXDLIN( 570)									_g1 = (_g1 + 1);
HXDLIN( 570)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 570)							{
HXLINE( 570)								 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 570)								int state2 = -1;
HXDLIN( 570)								int _g2 = 0;
HXDLIN( 570)								while((_g2 < keys2->length)){
HXLINE( 570)									int key = keys2->__get(_g2);
HXDLIN( 570)									_g2 = (_g2 + 1);
HXDLIN( 570)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)2: {
HXLINE( 570)							{
HXLINE( 570)								 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 570)								int state = 1;
HXDLIN( 570)								int _g = 0;
HXDLIN( 570)								while((_g < keys2->length)){
HXLINE( 570)									int key = keys2->__get(_g);
HXDLIN( 570)									_g = (_g + 1);
HXDLIN( 570)									action->addKey(key,state);
            								}
            							}
HXDLIN( 570)							{
HXLINE( 570)								 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 570)								int state1 = 2;
HXDLIN( 570)								int _g1 = 0;
HXDLIN( 570)								while((_g1 < keys2->length)){
HXLINE( 570)									int key = keys2->__get(_g1);
HXDLIN( 570)									_g1 = (_g1 + 1);
HXDLIN( 570)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 570)							{
HXLINE( 570)								 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 570)								int state2 = -1;
HXDLIN( 570)								int _g2 = 0;
HXDLIN( 570)								while((_g2 < keys2->length)){
HXLINE( 570)									int key = keys2->__get(_g2);
HXDLIN( 570)									_g2 = (_g2 + 1);
HXDLIN( 570)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)3: {
HXLINE( 570)							{
HXLINE( 570)								 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 570)								int state = 1;
HXDLIN( 570)								int _g = 0;
HXDLIN( 570)								while((_g < keys2->length)){
HXLINE( 570)									int key = keys2->__get(_g);
HXDLIN( 570)									_g = (_g + 1);
HXDLIN( 570)									action->addKey(key,state);
            								}
            							}
HXDLIN( 570)							{
HXLINE( 570)								 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 570)								int state1 = 2;
HXDLIN( 570)								int _g1 = 0;
HXDLIN( 570)								while((_g1 < keys2->length)){
HXLINE( 570)									int key = keys2->__get(_g1);
HXDLIN( 570)									_g1 = (_g1 + 1);
HXDLIN( 570)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 570)							{
HXLINE( 570)								 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 570)								int state2 = -1;
HXDLIN( 570)								int _g2 = 0;
HXDLIN( 570)								while((_g2 < keys2->length)){
HXLINE( 570)									int key = keys2->__get(_g2);
HXDLIN( 570)									_g2 = (_g2 + 1);
HXDLIN( 570)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)4: {
HXLINE( 570)							{
HXLINE( 570)								 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 570)								int state = 1;
HXDLIN( 570)								int _g = 0;
HXDLIN( 570)								while((_g < keys2->length)){
HXLINE( 570)									int key = keys2->__get(_g);
HXDLIN( 570)									_g = (_g + 1);
HXDLIN( 570)									action->addKey(key,state);
            								}
            							}
HXDLIN( 570)							{
HXLINE( 570)								 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 570)								int state1 = 2;
HXDLIN( 570)								int _g1 = 0;
HXDLIN( 570)								while((_g1 < keys2->length)){
HXLINE( 570)									int key = keys2->__get(_g1);
HXDLIN( 570)									_g1 = (_g1 + 1);
HXDLIN( 570)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 570)							{
HXLINE( 570)								 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 570)								int state2 = -1;
HXDLIN( 570)								int _g2 = 0;
HXDLIN( 570)								while((_g2 < keys2->length)){
HXLINE( 570)									int key = keys2->__get(_g2);
HXDLIN( 570)									_g2 = (_g2 + 1);
HXDLIN( 570)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)5: {
HXLINE( 570)							 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 570)							int state = 2;
HXDLIN( 570)							int _g = 0;
HXDLIN( 570)							while((_g < keys2->length)){
HXLINE( 570)								int key = keys2->__get(_g);
HXDLIN( 570)								_g = (_g + 1);
HXDLIN( 570)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)6: {
HXLINE( 570)							 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 570)							int state = 2;
HXDLIN( 570)							int _g = 0;
HXDLIN( 570)							while((_g < keys2->length)){
HXLINE( 570)								int key = keys2->__get(_g);
HXDLIN( 570)								_g = (_g + 1);
HXDLIN( 570)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)7: {
HXLINE( 570)							 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 570)							int state = 2;
HXDLIN( 570)							int _g = 0;
HXDLIN( 570)							while((_g < keys2->length)){
HXLINE( 570)								int key = keys2->__get(_g);
HXDLIN( 570)								_g = (_g + 1);
HXDLIN( 570)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)8: {
HXLINE( 570)							 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 570)							int state = 2;
HXDLIN( 570)							int _g = 0;
HXDLIN( 570)							while((_g < keys2->length)){
HXLINE( 570)								int key = keys2->__get(_g);
HXDLIN( 570)								_g = (_g + 1);
HXDLIN( 570)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)9: {
HXLINE( 570)							 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 570)							int state = 2;
HXDLIN( 570)							int _g = 0;
HXDLIN( 570)							while((_g < keys2->length)){
HXLINE( 570)								int key = keys2->__get(_g);
HXDLIN( 570)								_g = (_g + 1);
HXDLIN( 570)								action->addKey(key,state);
            							}
            						}
            						break;
            					}
            				}
HXLINE( 571)				{
HXLINE( 571)					::Dynamic this4 = ::flixel::input::keyboard::_FlxKey::FlxKey_Impl__obj::fromStringMap;
HXDLIN( 571)					 ::Dynamic key3;
HXDLIN( 571)					switch((int)(::SaveType_obj::CUSTOM_KEYBINDS_dyn()->_hx_getIndex())){
            						case (int)1: {
HXLINE( 571)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 571)								::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            							}
HXDLIN( 571)							key3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            						}
            						break;
            						case (int)2: {
HXLINE( 571)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 571)								::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            							}
            							else {
HXLINE( 571)								if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 571)									::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            								}
            							}
HXDLIN( 571)							key3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            						}
            						break;
            						case (int)3: {
HXLINE( 571)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 571)								::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            							}
HXDLIN( 571)							key3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            						}
            						break;
            						case (int)4: {
HXLINE( 571)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 571)								::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            							}
HXDLIN( 571)							key3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            						}
            						break;
            						case (int)5: {
HXLINE( 571)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 571)								::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            							}
HXDLIN( 571)							key3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            						}
            						break;
            						case (int)6: {
HXLINE( 571)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 571)								::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            							}
HXDLIN( 571)							key3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            						}
            						break;
            						case (int)7: {
HXLINE( 571)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 571)								::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            							}
HXDLIN( 571)							key3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            						}
            						break;
            						case (int)8: {
HXLINE( 571)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 571)								::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            							}
HXDLIN( 571)							key3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            						}
            						break;
            						case (int)9: {
HXLINE( 571)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 571)								::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            							}
HXDLIN( 571)							key3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            						}
            						break;
            						case (int)10: {
HXLINE( 571)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 571)								::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            							}
HXDLIN( 571)							key3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            						}
            						break;
            						case (int)11: {
HXLINE( 571)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 571)								::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            							}
            							else {
HXLINE( 571)								if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 571)									::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            								}
            							}
HXDLIN( 571)							key3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            						}
            						break;
            						case (int)12: {
HXLINE( 571)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 571)								::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            							}
HXDLIN( 571)							key3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            						}
            						break;
            						case (int)13: {
HXLINE( 571)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 571)								::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            							}
HXDLIN( 571)							key3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            						}
            						break;
            						case (int)14: {
HXLINE( 571)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 571)								::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            							}
HXDLIN( 571)							key3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            						}
            						break;
            						case (int)15: {
HXLINE( 571)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 571)								::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            							}
HXDLIN( 571)							key3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            						}
            						break;
            						case (int)16: {
HXLINE( 571)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 571)								::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            							}
HXDLIN( 571)							key3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            						}
            						break;
            						case (int)17: {
HXLINE( 571)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 571)								::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            							}
HXDLIN( 571)							key3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            						}
            						break;
            						case (int)18: {
HXLINE( 571)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 571)								::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            							}
HXDLIN( 571)							key3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            						}
            						break;
            						case (int)19: {
HXLINE( 571)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 571)								::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            							}
HXDLIN( 571)							key3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            						}
            						break;
            						case (int)20: {
HXLINE( 571)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 571)								::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            							}
HXDLIN( 571)							key3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            						}
            						break;
            						case (int)21: {
HXLINE( 571)							if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 571)								::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            							}
HXDLIN( 571)							key3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            						}
            						break;
            						default:{
HXLINE( 571)							key3 = null();
            						}
            					}
HXDLIN( 571)					::Array< int > keys3 = ::Array_obj< int >::__new(2)->init(0,( ( ::haxe::ds::StringMap)(this4) )->get(key3->__Field(HX_("split",da,ea,6e,81),::hx::paccDynamic)(HX_(" ",20,00,00,00))->__GetItem(3)))->init(1,39);
HXDLIN( 571)					switch((int)(::Control_obj::RIGHT_dyn()->_hx_getIndex())){
            						case (int)0: {
HXLINE( 571)							{
HXLINE( 571)								 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 571)								int state = 1;
HXDLIN( 571)								int _g = 0;
HXDLIN( 571)								while((_g < keys3->length)){
HXLINE( 571)									int key = keys3->__get(_g);
HXDLIN( 571)									_g = (_g + 1);
HXDLIN( 571)									action->addKey(key,state);
            								}
            							}
HXDLIN( 571)							{
HXLINE( 571)								 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 571)								int state1 = 2;
HXDLIN( 571)								int _g1 = 0;
HXDLIN( 571)								while((_g1 < keys3->length)){
HXLINE( 571)									int key = keys3->__get(_g1);
HXDLIN( 571)									_g1 = (_g1 + 1);
HXDLIN( 571)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 571)							{
HXLINE( 571)								 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 571)								int state2 = -1;
HXDLIN( 571)								int _g2 = 0;
HXDLIN( 571)								while((_g2 < keys3->length)){
HXLINE( 571)									int key = keys3->__get(_g2);
HXDLIN( 571)									_g2 = (_g2 + 1);
HXDLIN( 571)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)1: {
HXLINE( 571)							{
HXLINE( 571)								 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 571)								int state = 1;
HXDLIN( 571)								int _g = 0;
HXDLIN( 571)								while((_g < keys3->length)){
HXLINE( 571)									int key = keys3->__get(_g);
HXDLIN( 571)									_g = (_g + 1);
HXDLIN( 571)									action->addKey(key,state);
            								}
            							}
HXDLIN( 571)							{
HXLINE( 571)								 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 571)								int state1 = 2;
HXDLIN( 571)								int _g1 = 0;
HXDLIN( 571)								while((_g1 < keys3->length)){
HXLINE( 571)									int key = keys3->__get(_g1);
HXDLIN( 571)									_g1 = (_g1 + 1);
HXDLIN( 571)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 571)							{
HXLINE( 571)								 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 571)								int state2 = -1;
HXDLIN( 571)								int _g2 = 0;
HXDLIN( 571)								while((_g2 < keys3->length)){
HXLINE( 571)									int key = keys3->__get(_g2);
HXDLIN( 571)									_g2 = (_g2 + 1);
HXDLIN( 571)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)2: {
HXLINE( 571)							{
HXLINE( 571)								 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 571)								int state = 1;
HXDLIN( 571)								int _g = 0;
HXDLIN( 571)								while((_g < keys3->length)){
HXLINE( 571)									int key = keys3->__get(_g);
HXDLIN( 571)									_g = (_g + 1);
HXDLIN( 571)									action->addKey(key,state);
            								}
            							}
HXDLIN( 571)							{
HXLINE( 571)								 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 571)								int state1 = 2;
HXDLIN( 571)								int _g1 = 0;
HXDLIN( 571)								while((_g1 < keys3->length)){
HXLINE( 571)									int key = keys3->__get(_g1);
HXDLIN( 571)									_g1 = (_g1 + 1);
HXDLIN( 571)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 571)							{
HXLINE( 571)								 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 571)								int state2 = -1;
HXDLIN( 571)								int _g2 = 0;
HXDLIN( 571)								while((_g2 < keys3->length)){
HXLINE( 571)									int key = keys3->__get(_g2);
HXDLIN( 571)									_g2 = (_g2 + 1);
HXDLIN( 571)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)3: {
HXLINE( 571)							{
HXLINE( 571)								 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 571)								int state = 1;
HXDLIN( 571)								int _g = 0;
HXDLIN( 571)								while((_g < keys3->length)){
HXLINE( 571)									int key = keys3->__get(_g);
HXDLIN( 571)									_g = (_g + 1);
HXDLIN( 571)									action->addKey(key,state);
            								}
            							}
HXDLIN( 571)							{
HXLINE( 571)								 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 571)								int state1 = 2;
HXDLIN( 571)								int _g1 = 0;
HXDLIN( 571)								while((_g1 < keys3->length)){
HXLINE( 571)									int key = keys3->__get(_g1);
HXDLIN( 571)									_g1 = (_g1 + 1);
HXDLIN( 571)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 571)							{
HXLINE( 571)								 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 571)								int state2 = -1;
HXDLIN( 571)								int _g2 = 0;
HXDLIN( 571)								while((_g2 < keys3->length)){
HXLINE( 571)									int key = keys3->__get(_g2);
HXDLIN( 571)									_g2 = (_g2 + 1);
HXDLIN( 571)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)4: {
HXLINE( 571)							{
HXLINE( 571)								 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 571)								int state = 1;
HXDLIN( 571)								int _g = 0;
HXDLIN( 571)								while((_g < keys3->length)){
HXLINE( 571)									int key = keys3->__get(_g);
HXDLIN( 571)									_g = (_g + 1);
HXDLIN( 571)									action->addKey(key,state);
            								}
            							}
HXDLIN( 571)							{
HXLINE( 571)								 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 571)								int state1 = 2;
HXDLIN( 571)								int _g1 = 0;
HXDLIN( 571)								while((_g1 < keys3->length)){
HXLINE( 571)									int key = keys3->__get(_g1);
HXDLIN( 571)									_g1 = (_g1 + 1);
HXDLIN( 571)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 571)							{
HXLINE( 571)								 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 571)								int state2 = -1;
HXDLIN( 571)								int _g2 = 0;
HXDLIN( 571)								while((_g2 < keys3->length)){
HXLINE( 571)									int key = keys3->__get(_g2);
HXDLIN( 571)									_g2 = (_g2 + 1);
HXDLIN( 571)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)5: {
HXLINE( 571)							 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 571)							int state = 2;
HXDLIN( 571)							int _g = 0;
HXDLIN( 571)							while((_g < keys3->length)){
HXLINE( 571)								int key = keys3->__get(_g);
HXDLIN( 571)								_g = (_g + 1);
HXDLIN( 571)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)6: {
HXLINE( 571)							 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 571)							int state = 2;
HXDLIN( 571)							int _g = 0;
HXDLIN( 571)							while((_g < keys3->length)){
HXLINE( 571)								int key = keys3->__get(_g);
HXDLIN( 571)								_g = (_g + 1);
HXDLIN( 571)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)7: {
HXLINE( 571)							 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 571)							int state = 2;
HXDLIN( 571)							int _g = 0;
HXDLIN( 571)							while((_g < keys3->length)){
HXLINE( 571)								int key = keys3->__get(_g);
HXDLIN( 571)								_g = (_g + 1);
HXDLIN( 571)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)8: {
HXLINE( 571)							 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 571)							int state = 2;
HXDLIN( 571)							int _g = 0;
HXDLIN( 571)							while((_g < keys3->length)){
HXLINE( 571)								int key = keys3->__get(_g);
HXDLIN( 571)								_g = (_g + 1);
HXDLIN( 571)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)9: {
HXLINE( 571)							 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 571)							int state = 2;
HXDLIN( 571)							int _g = 0;
HXDLIN( 571)							while((_g < keys3->length)){
HXLINE( 571)								int key = keys3->__get(_g);
HXDLIN( 571)								_g = (_g + 1);
HXDLIN( 571)								action->addKey(key,state);
            							}
            						}
            						break;
            					}
            				}
HXLINE( 572)				{
HXLINE( 572)					::Array< int > keys4 = ::Array_obj< int >::fromData( _hx_array_data_116e4296_780,4);
HXDLIN( 572)					switch((int)(::Control_obj::ACCEPT_dyn()->_hx_getIndex())){
            						case (int)0: {
HXLINE( 572)							{
HXLINE( 572)								 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 572)								int state = 1;
HXDLIN( 572)								int _g = 0;
HXDLIN( 572)								while((_g < keys4->length)){
HXLINE( 572)									int key = keys4->__get(_g);
HXDLIN( 572)									_g = (_g + 1);
HXDLIN( 572)									action->addKey(key,state);
            								}
            							}
HXDLIN( 572)							{
HXLINE( 572)								 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 572)								int state1 = 2;
HXDLIN( 572)								int _g1 = 0;
HXDLIN( 572)								while((_g1 < keys4->length)){
HXLINE( 572)									int key = keys4->__get(_g1);
HXDLIN( 572)									_g1 = (_g1 + 1);
HXDLIN( 572)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 572)							{
HXLINE( 572)								 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 572)								int state2 = -1;
HXDLIN( 572)								int _g2 = 0;
HXDLIN( 572)								while((_g2 < keys4->length)){
HXLINE( 572)									int key = keys4->__get(_g2);
HXDLIN( 572)									_g2 = (_g2 + 1);
HXDLIN( 572)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)1: {
HXLINE( 572)							{
HXLINE( 572)								 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 572)								int state = 1;
HXDLIN( 572)								int _g = 0;
HXDLIN( 572)								while((_g < keys4->length)){
HXLINE( 572)									int key = keys4->__get(_g);
HXDLIN( 572)									_g = (_g + 1);
HXDLIN( 572)									action->addKey(key,state);
            								}
            							}
HXDLIN( 572)							{
HXLINE( 572)								 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 572)								int state1 = 2;
HXDLIN( 572)								int _g1 = 0;
HXDLIN( 572)								while((_g1 < keys4->length)){
HXLINE( 572)									int key = keys4->__get(_g1);
HXDLIN( 572)									_g1 = (_g1 + 1);
HXDLIN( 572)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 572)							{
HXLINE( 572)								 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 572)								int state2 = -1;
HXDLIN( 572)								int _g2 = 0;
HXDLIN( 572)								while((_g2 < keys4->length)){
HXLINE( 572)									int key = keys4->__get(_g2);
HXDLIN( 572)									_g2 = (_g2 + 1);
HXDLIN( 572)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)2: {
HXLINE( 572)							{
HXLINE( 572)								 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 572)								int state = 1;
HXDLIN( 572)								int _g = 0;
HXDLIN( 572)								while((_g < keys4->length)){
HXLINE( 572)									int key = keys4->__get(_g);
HXDLIN( 572)									_g = (_g + 1);
HXDLIN( 572)									action->addKey(key,state);
            								}
            							}
HXDLIN( 572)							{
HXLINE( 572)								 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 572)								int state1 = 2;
HXDLIN( 572)								int _g1 = 0;
HXDLIN( 572)								while((_g1 < keys4->length)){
HXLINE( 572)									int key = keys4->__get(_g1);
HXDLIN( 572)									_g1 = (_g1 + 1);
HXDLIN( 572)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 572)							{
HXLINE( 572)								 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 572)								int state2 = -1;
HXDLIN( 572)								int _g2 = 0;
HXDLIN( 572)								while((_g2 < keys4->length)){
HXLINE( 572)									int key = keys4->__get(_g2);
HXDLIN( 572)									_g2 = (_g2 + 1);
HXDLIN( 572)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)3: {
HXLINE( 572)							{
HXLINE( 572)								 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 572)								int state = 1;
HXDLIN( 572)								int _g = 0;
HXDLIN( 572)								while((_g < keys4->length)){
HXLINE( 572)									int key = keys4->__get(_g);
HXDLIN( 572)									_g = (_g + 1);
HXDLIN( 572)									action->addKey(key,state);
            								}
            							}
HXDLIN( 572)							{
HXLINE( 572)								 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 572)								int state1 = 2;
HXDLIN( 572)								int _g1 = 0;
HXDLIN( 572)								while((_g1 < keys4->length)){
HXLINE( 572)									int key = keys4->__get(_g1);
HXDLIN( 572)									_g1 = (_g1 + 1);
HXDLIN( 572)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 572)							{
HXLINE( 572)								 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 572)								int state2 = -1;
HXDLIN( 572)								int _g2 = 0;
HXDLIN( 572)								while((_g2 < keys4->length)){
HXLINE( 572)									int key = keys4->__get(_g2);
HXDLIN( 572)									_g2 = (_g2 + 1);
HXDLIN( 572)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)4: {
HXLINE( 572)							{
HXLINE( 572)								 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 572)								int state = 1;
HXDLIN( 572)								int _g = 0;
HXDLIN( 572)								while((_g < keys4->length)){
HXLINE( 572)									int key = keys4->__get(_g);
HXDLIN( 572)									_g = (_g + 1);
HXDLIN( 572)									action->addKey(key,state);
            								}
            							}
HXDLIN( 572)							{
HXLINE( 572)								 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 572)								int state1 = 2;
HXDLIN( 572)								int _g1 = 0;
HXDLIN( 572)								while((_g1 < keys4->length)){
HXLINE( 572)									int key = keys4->__get(_g1);
HXDLIN( 572)									_g1 = (_g1 + 1);
HXDLIN( 572)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 572)							{
HXLINE( 572)								 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 572)								int state2 = -1;
HXDLIN( 572)								int _g2 = 0;
HXDLIN( 572)								while((_g2 < keys4->length)){
HXLINE( 572)									int key = keys4->__get(_g2);
HXDLIN( 572)									_g2 = (_g2 + 1);
HXDLIN( 572)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)5: {
HXLINE( 572)							 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 572)							int state = 2;
HXDLIN( 572)							int _g = 0;
HXDLIN( 572)							while((_g < keys4->length)){
HXLINE( 572)								int key = keys4->__get(_g);
HXDLIN( 572)								_g = (_g + 1);
HXDLIN( 572)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)6: {
HXLINE( 572)							 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 572)							int state = 2;
HXDLIN( 572)							int _g = 0;
HXDLIN( 572)							while((_g < keys4->length)){
HXLINE( 572)								int key = keys4->__get(_g);
HXDLIN( 572)								_g = (_g + 1);
HXDLIN( 572)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)7: {
HXLINE( 572)							 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 572)							int state = 2;
HXDLIN( 572)							int _g = 0;
HXDLIN( 572)							while((_g < keys4->length)){
HXLINE( 572)								int key = keys4->__get(_g);
HXDLIN( 572)								_g = (_g + 1);
HXDLIN( 572)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)8: {
HXLINE( 572)							 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 572)							int state = 2;
HXDLIN( 572)							int _g = 0;
HXDLIN( 572)							while((_g < keys4->length)){
HXLINE( 572)								int key = keys4->__get(_g);
HXDLIN( 572)								_g = (_g + 1);
HXDLIN( 572)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)9: {
HXLINE( 572)							 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 572)							int state = 2;
HXDLIN( 572)							int _g = 0;
HXDLIN( 572)							while((_g < keys4->length)){
HXLINE( 572)								int key = keys4->__get(_g);
HXDLIN( 572)								_g = (_g + 1);
HXDLIN( 572)								action->addKey(key,state);
            							}
            						}
            						break;
            					}
            				}
HXLINE( 573)				{
HXLINE( 573)					::Array< int > keys5 = ::Array_obj< int >::fromData( _hx_array_data_116e4296_781,2);
HXDLIN( 573)					switch((int)(::Control_obj::BACK_dyn()->_hx_getIndex())){
            						case (int)0: {
HXLINE( 573)							{
HXLINE( 573)								 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 573)								int state = 1;
HXDLIN( 573)								int _g = 0;
HXDLIN( 573)								while((_g < keys5->length)){
HXLINE( 573)									int key = keys5->__get(_g);
HXDLIN( 573)									_g = (_g + 1);
HXDLIN( 573)									action->addKey(key,state);
            								}
            							}
HXDLIN( 573)							{
HXLINE( 573)								 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 573)								int state1 = 2;
HXDLIN( 573)								int _g1 = 0;
HXDLIN( 573)								while((_g1 < keys5->length)){
HXLINE( 573)									int key = keys5->__get(_g1);
HXDLIN( 573)									_g1 = (_g1 + 1);
HXDLIN( 573)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 573)							{
HXLINE( 573)								 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 573)								int state2 = -1;
HXDLIN( 573)								int _g2 = 0;
HXDLIN( 573)								while((_g2 < keys5->length)){
HXLINE( 573)									int key = keys5->__get(_g2);
HXDLIN( 573)									_g2 = (_g2 + 1);
HXDLIN( 573)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)1: {
HXLINE( 573)							{
HXLINE( 573)								 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 573)								int state = 1;
HXDLIN( 573)								int _g = 0;
HXDLIN( 573)								while((_g < keys5->length)){
HXLINE( 573)									int key = keys5->__get(_g);
HXDLIN( 573)									_g = (_g + 1);
HXDLIN( 573)									action->addKey(key,state);
            								}
            							}
HXDLIN( 573)							{
HXLINE( 573)								 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 573)								int state1 = 2;
HXDLIN( 573)								int _g1 = 0;
HXDLIN( 573)								while((_g1 < keys5->length)){
HXLINE( 573)									int key = keys5->__get(_g1);
HXDLIN( 573)									_g1 = (_g1 + 1);
HXDLIN( 573)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 573)							{
HXLINE( 573)								 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 573)								int state2 = -1;
HXDLIN( 573)								int _g2 = 0;
HXDLIN( 573)								while((_g2 < keys5->length)){
HXLINE( 573)									int key = keys5->__get(_g2);
HXDLIN( 573)									_g2 = (_g2 + 1);
HXDLIN( 573)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)2: {
HXLINE( 573)							{
HXLINE( 573)								 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 573)								int state = 1;
HXDLIN( 573)								int _g = 0;
HXDLIN( 573)								while((_g < keys5->length)){
HXLINE( 573)									int key = keys5->__get(_g);
HXDLIN( 573)									_g = (_g + 1);
HXDLIN( 573)									action->addKey(key,state);
            								}
            							}
HXDLIN( 573)							{
HXLINE( 573)								 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 573)								int state1 = 2;
HXDLIN( 573)								int _g1 = 0;
HXDLIN( 573)								while((_g1 < keys5->length)){
HXLINE( 573)									int key = keys5->__get(_g1);
HXDLIN( 573)									_g1 = (_g1 + 1);
HXDLIN( 573)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 573)							{
HXLINE( 573)								 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 573)								int state2 = -1;
HXDLIN( 573)								int _g2 = 0;
HXDLIN( 573)								while((_g2 < keys5->length)){
HXLINE( 573)									int key = keys5->__get(_g2);
HXDLIN( 573)									_g2 = (_g2 + 1);
HXDLIN( 573)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)3: {
HXLINE( 573)							{
HXLINE( 573)								 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 573)								int state = 1;
HXDLIN( 573)								int _g = 0;
HXDLIN( 573)								while((_g < keys5->length)){
HXLINE( 573)									int key = keys5->__get(_g);
HXDLIN( 573)									_g = (_g + 1);
HXDLIN( 573)									action->addKey(key,state);
            								}
            							}
HXDLIN( 573)							{
HXLINE( 573)								 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 573)								int state1 = 2;
HXDLIN( 573)								int _g1 = 0;
HXDLIN( 573)								while((_g1 < keys5->length)){
HXLINE( 573)									int key = keys5->__get(_g1);
HXDLIN( 573)									_g1 = (_g1 + 1);
HXDLIN( 573)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 573)							{
HXLINE( 573)								 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 573)								int state2 = -1;
HXDLIN( 573)								int _g2 = 0;
HXDLIN( 573)								while((_g2 < keys5->length)){
HXLINE( 573)									int key = keys5->__get(_g2);
HXDLIN( 573)									_g2 = (_g2 + 1);
HXDLIN( 573)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)4: {
HXLINE( 573)							{
HXLINE( 573)								 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 573)								int state = 1;
HXDLIN( 573)								int _g = 0;
HXDLIN( 573)								while((_g < keys5->length)){
HXLINE( 573)									int key = keys5->__get(_g);
HXDLIN( 573)									_g = (_g + 1);
HXDLIN( 573)									action->addKey(key,state);
            								}
            							}
HXDLIN( 573)							{
HXLINE( 573)								 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 573)								int state1 = 2;
HXDLIN( 573)								int _g1 = 0;
HXDLIN( 573)								while((_g1 < keys5->length)){
HXLINE( 573)									int key = keys5->__get(_g1);
HXDLIN( 573)									_g1 = (_g1 + 1);
HXDLIN( 573)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 573)							{
HXLINE( 573)								 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 573)								int state2 = -1;
HXDLIN( 573)								int _g2 = 0;
HXDLIN( 573)								while((_g2 < keys5->length)){
HXLINE( 573)									int key = keys5->__get(_g2);
HXDLIN( 573)									_g2 = (_g2 + 1);
HXDLIN( 573)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)5: {
HXLINE( 573)							 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 573)							int state = 2;
HXDLIN( 573)							int _g = 0;
HXDLIN( 573)							while((_g < keys5->length)){
HXLINE( 573)								int key = keys5->__get(_g);
HXDLIN( 573)								_g = (_g + 1);
HXDLIN( 573)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)6: {
HXLINE( 573)							 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 573)							int state = 2;
HXDLIN( 573)							int _g = 0;
HXDLIN( 573)							while((_g < keys5->length)){
HXLINE( 573)								int key = keys5->__get(_g);
HXDLIN( 573)								_g = (_g + 1);
HXDLIN( 573)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)7: {
HXLINE( 573)							 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 573)							int state = 2;
HXDLIN( 573)							int _g = 0;
HXDLIN( 573)							while((_g < keys5->length)){
HXLINE( 573)								int key = keys5->__get(_g);
HXDLIN( 573)								_g = (_g + 1);
HXDLIN( 573)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)8: {
HXLINE( 573)							 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 573)							int state = 2;
HXDLIN( 573)							int _g = 0;
HXDLIN( 573)							while((_g < keys5->length)){
HXLINE( 573)								int key = keys5->__get(_g);
HXDLIN( 573)								_g = (_g + 1);
HXDLIN( 573)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)9: {
HXLINE( 573)							 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 573)							int state = 2;
HXDLIN( 573)							int _g = 0;
HXDLIN( 573)							while((_g < keys5->length)){
HXLINE( 573)								int key = keys5->__get(_g);
HXDLIN( 573)								_g = (_g + 1);
HXDLIN( 573)								action->addKey(key,state);
            							}
            						}
            						break;
            					}
            				}
HXLINE( 574)				{
HXLINE( 574)					::Array< int > keys6 = ::Array_obj< int >::fromData( _hx_array_data_116e4296_782,3);
HXDLIN( 574)					switch((int)(::Control_obj::PAUSE_dyn()->_hx_getIndex())){
            						case (int)0: {
HXLINE( 574)							{
HXLINE( 574)								 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 574)								int state = 1;
HXDLIN( 574)								int _g = 0;
HXDLIN( 574)								while((_g < keys6->length)){
HXLINE( 574)									int key = keys6->__get(_g);
HXDLIN( 574)									_g = (_g + 1);
HXDLIN( 574)									action->addKey(key,state);
            								}
            							}
HXDLIN( 574)							{
HXLINE( 574)								 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 574)								int state1 = 2;
HXDLIN( 574)								int _g1 = 0;
HXDLIN( 574)								while((_g1 < keys6->length)){
HXLINE( 574)									int key = keys6->__get(_g1);
HXDLIN( 574)									_g1 = (_g1 + 1);
HXDLIN( 574)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 574)							{
HXLINE( 574)								 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 574)								int state2 = -1;
HXDLIN( 574)								int _g2 = 0;
HXDLIN( 574)								while((_g2 < keys6->length)){
HXLINE( 574)									int key = keys6->__get(_g2);
HXDLIN( 574)									_g2 = (_g2 + 1);
HXDLIN( 574)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)1: {
HXLINE( 574)							{
HXLINE( 574)								 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 574)								int state = 1;
HXDLIN( 574)								int _g = 0;
HXDLIN( 574)								while((_g < keys6->length)){
HXLINE( 574)									int key = keys6->__get(_g);
HXDLIN( 574)									_g = (_g + 1);
HXDLIN( 574)									action->addKey(key,state);
            								}
            							}
HXDLIN( 574)							{
HXLINE( 574)								 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 574)								int state1 = 2;
HXDLIN( 574)								int _g1 = 0;
HXDLIN( 574)								while((_g1 < keys6->length)){
HXLINE( 574)									int key = keys6->__get(_g1);
HXDLIN( 574)									_g1 = (_g1 + 1);
HXDLIN( 574)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 574)							{
HXLINE( 574)								 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 574)								int state2 = -1;
HXDLIN( 574)								int _g2 = 0;
HXDLIN( 574)								while((_g2 < keys6->length)){
HXLINE( 574)									int key = keys6->__get(_g2);
HXDLIN( 574)									_g2 = (_g2 + 1);
HXDLIN( 574)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)2: {
HXLINE( 574)							{
HXLINE( 574)								 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 574)								int state = 1;
HXDLIN( 574)								int _g = 0;
HXDLIN( 574)								while((_g < keys6->length)){
HXLINE( 574)									int key = keys6->__get(_g);
HXDLIN( 574)									_g = (_g + 1);
HXDLIN( 574)									action->addKey(key,state);
            								}
            							}
HXDLIN( 574)							{
HXLINE( 574)								 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 574)								int state1 = 2;
HXDLIN( 574)								int _g1 = 0;
HXDLIN( 574)								while((_g1 < keys6->length)){
HXLINE( 574)									int key = keys6->__get(_g1);
HXDLIN( 574)									_g1 = (_g1 + 1);
HXDLIN( 574)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 574)							{
HXLINE( 574)								 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 574)								int state2 = -1;
HXDLIN( 574)								int _g2 = 0;
HXDLIN( 574)								while((_g2 < keys6->length)){
HXLINE( 574)									int key = keys6->__get(_g2);
HXDLIN( 574)									_g2 = (_g2 + 1);
HXDLIN( 574)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)3: {
HXLINE( 574)							{
HXLINE( 574)								 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 574)								int state = 1;
HXDLIN( 574)								int _g = 0;
HXDLIN( 574)								while((_g < keys6->length)){
HXLINE( 574)									int key = keys6->__get(_g);
HXDLIN( 574)									_g = (_g + 1);
HXDLIN( 574)									action->addKey(key,state);
            								}
            							}
HXDLIN( 574)							{
HXLINE( 574)								 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 574)								int state1 = 2;
HXDLIN( 574)								int _g1 = 0;
HXDLIN( 574)								while((_g1 < keys6->length)){
HXLINE( 574)									int key = keys6->__get(_g1);
HXDLIN( 574)									_g1 = (_g1 + 1);
HXDLIN( 574)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 574)							{
HXLINE( 574)								 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 574)								int state2 = -1;
HXDLIN( 574)								int _g2 = 0;
HXDLIN( 574)								while((_g2 < keys6->length)){
HXLINE( 574)									int key = keys6->__get(_g2);
HXDLIN( 574)									_g2 = (_g2 + 1);
HXDLIN( 574)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)4: {
HXLINE( 574)							{
HXLINE( 574)								 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 574)								int state = 1;
HXDLIN( 574)								int _g = 0;
HXDLIN( 574)								while((_g < keys6->length)){
HXLINE( 574)									int key = keys6->__get(_g);
HXDLIN( 574)									_g = (_g + 1);
HXDLIN( 574)									action->addKey(key,state);
            								}
            							}
HXDLIN( 574)							{
HXLINE( 574)								 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 574)								int state1 = 2;
HXDLIN( 574)								int _g1 = 0;
HXDLIN( 574)								while((_g1 < keys6->length)){
HXLINE( 574)									int key = keys6->__get(_g1);
HXDLIN( 574)									_g1 = (_g1 + 1);
HXDLIN( 574)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 574)							{
HXLINE( 574)								 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 574)								int state2 = -1;
HXDLIN( 574)								int _g2 = 0;
HXDLIN( 574)								while((_g2 < keys6->length)){
HXLINE( 574)									int key = keys6->__get(_g2);
HXDLIN( 574)									_g2 = (_g2 + 1);
HXDLIN( 574)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)5: {
HXLINE( 574)							 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 574)							int state = 2;
HXDLIN( 574)							int _g = 0;
HXDLIN( 574)							while((_g < keys6->length)){
HXLINE( 574)								int key = keys6->__get(_g);
HXDLIN( 574)								_g = (_g + 1);
HXDLIN( 574)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)6: {
HXLINE( 574)							 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 574)							int state = 2;
HXDLIN( 574)							int _g = 0;
HXDLIN( 574)							while((_g < keys6->length)){
HXLINE( 574)								int key = keys6->__get(_g);
HXDLIN( 574)								_g = (_g + 1);
HXDLIN( 574)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)7: {
HXLINE( 574)							 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 574)							int state = 2;
HXDLIN( 574)							int _g = 0;
HXDLIN( 574)							while((_g < keys6->length)){
HXLINE( 574)								int key = keys6->__get(_g);
HXDLIN( 574)								_g = (_g + 1);
HXDLIN( 574)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)8: {
HXLINE( 574)							 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 574)							int state = 2;
HXDLIN( 574)							int _g = 0;
HXDLIN( 574)							while((_g < keys6->length)){
HXLINE( 574)								int key = keys6->__get(_g);
HXDLIN( 574)								_g = (_g + 1);
HXDLIN( 574)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)9: {
HXLINE( 574)							 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 574)							int state = 2;
HXDLIN( 574)							int _g = 0;
HXDLIN( 574)							while((_g < keys6->length)){
HXLINE( 574)								int key = keys6->__get(_g);
HXDLIN( 574)								_g = (_g + 1);
HXDLIN( 574)								action->addKey(key,state);
            							}
            						}
            						break;
            					}
            				}
HXLINE( 575)				{
HXLINE( 575)					::Array< int > keys7 = ::Array_obj< int >::fromData( _hx_array_data_116e4296_783,1);
HXDLIN( 575)					switch((int)(::Control_obj::RESET_dyn()->_hx_getIndex())){
            						case (int)0: {
HXLINE( 575)							{
HXLINE( 575)								 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 575)								int state = 1;
HXDLIN( 575)								int _g = 0;
HXDLIN( 575)								while((_g < keys7->length)){
HXLINE( 575)									int key = keys7->__get(_g);
HXDLIN( 575)									_g = (_g + 1);
HXDLIN( 575)									action->addKey(key,state);
            								}
            							}
HXDLIN( 575)							{
HXLINE( 575)								 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 575)								int state1 = 2;
HXDLIN( 575)								int _g1 = 0;
HXDLIN( 575)								while((_g1 < keys7->length)){
HXLINE( 575)									int key = keys7->__get(_g1);
HXDLIN( 575)									_g1 = (_g1 + 1);
HXDLIN( 575)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 575)							{
HXLINE( 575)								 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 575)								int state2 = -1;
HXDLIN( 575)								int _g2 = 0;
HXDLIN( 575)								while((_g2 < keys7->length)){
HXLINE( 575)									int key = keys7->__get(_g2);
HXDLIN( 575)									_g2 = (_g2 + 1);
HXDLIN( 575)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)1: {
HXLINE( 575)							{
HXLINE( 575)								 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 575)								int state = 1;
HXDLIN( 575)								int _g = 0;
HXDLIN( 575)								while((_g < keys7->length)){
HXLINE( 575)									int key = keys7->__get(_g);
HXDLIN( 575)									_g = (_g + 1);
HXDLIN( 575)									action->addKey(key,state);
            								}
            							}
HXDLIN( 575)							{
HXLINE( 575)								 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 575)								int state1 = 2;
HXDLIN( 575)								int _g1 = 0;
HXDLIN( 575)								while((_g1 < keys7->length)){
HXLINE( 575)									int key = keys7->__get(_g1);
HXDLIN( 575)									_g1 = (_g1 + 1);
HXDLIN( 575)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 575)							{
HXLINE( 575)								 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 575)								int state2 = -1;
HXDLIN( 575)								int _g2 = 0;
HXDLIN( 575)								while((_g2 < keys7->length)){
HXLINE( 575)									int key = keys7->__get(_g2);
HXDLIN( 575)									_g2 = (_g2 + 1);
HXDLIN( 575)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)2: {
HXLINE( 575)							{
HXLINE( 575)								 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 575)								int state = 1;
HXDLIN( 575)								int _g = 0;
HXDLIN( 575)								while((_g < keys7->length)){
HXLINE( 575)									int key = keys7->__get(_g);
HXDLIN( 575)									_g = (_g + 1);
HXDLIN( 575)									action->addKey(key,state);
            								}
            							}
HXDLIN( 575)							{
HXLINE( 575)								 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 575)								int state1 = 2;
HXDLIN( 575)								int _g1 = 0;
HXDLIN( 575)								while((_g1 < keys7->length)){
HXLINE( 575)									int key = keys7->__get(_g1);
HXDLIN( 575)									_g1 = (_g1 + 1);
HXDLIN( 575)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 575)							{
HXLINE( 575)								 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 575)								int state2 = -1;
HXDLIN( 575)								int _g2 = 0;
HXDLIN( 575)								while((_g2 < keys7->length)){
HXLINE( 575)									int key = keys7->__get(_g2);
HXDLIN( 575)									_g2 = (_g2 + 1);
HXDLIN( 575)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)3: {
HXLINE( 575)							{
HXLINE( 575)								 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 575)								int state = 1;
HXDLIN( 575)								int _g = 0;
HXDLIN( 575)								while((_g < keys7->length)){
HXLINE( 575)									int key = keys7->__get(_g);
HXDLIN( 575)									_g = (_g + 1);
HXDLIN( 575)									action->addKey(key,state);
            								}
            							}
HXDLIN( 575)							{
HXLINE( 575)								 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 575)								int state1 = 2;
HXDLIN( 575)								int _g1 = 0;
HXDLIN( 575)								while((_g1 < keys7->length)){
HXLINE( 575)									int key = keys7->__get(_g1);
HXDLIN( 575)									_g1 = (_g1 + 1);
HXDLIN( 575)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 575)							{
HXLINE( 575)								 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 575)								int state2 = -1;
HXDLIN( 575)								int _g2 = 0;
HXDLIN( 575)								while((_g2 < keys7->length)){
HXLINE( 575)									int key = keys7->__get(_g2);
HXDLIN( 575)									_g2 = (_g2 + 1);
HXDLIN( 575)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)4: {
HXLINE( 575)							{
HXLINE( 575)								 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 575)								int state = 1;
HXDLIN( 575)								int _g = 0;
HXDLIN( 575)								while((_g < keys7->length)){
HXLINE( 575)									int key = keys7->__get(_g);
HXDLIN( 575)									_g = (_g + 1);
HXDLIN( 575)									action->addKey(key,state);
            								}
            							}
HXDLIN( 575)							{
HXLINE( 575)								 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 575)								int state1 = 2;
HXDLIN( 575)								int _g1 = 0;
HXDLIN( 575)								while((_g1 < keys7->length)){
HXLINE( 575)									int key = keys7->__get(_g1);
HXDLIN( 575)									_g1 = (_g1 + 1);
HXDLIN( 575)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 575)							{
HXLINE( 575)								 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 575)								int state2 = -1;
HXDLIN( 575)								int _g2 = 0;
HXDLIN( 575)								while((_g2 < keys7->length)){
HXLINE( 575)									int key = keys7->__get(_g2);
HXDLIN( 575)									_g2 = (_g2 + 1);
HXDLIN( 575)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)5: {
HXLINE( 575)							 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 575)							int state = 2;
HXDLIN( 575)							int _g = 0;
HXDLIN( 575)							while((_g < keys7->length)){
HXLINE( 575)								int key = keys7->__get(_g);
HXDLIN( 575)								_g = (_g + 1);
HXDLIN( 575)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)6: {
HXLINE( 575)							 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 575)							int state = 2;
HXDLIN( 575)							int _g = 0;
HXDLIN( 575)							while((_g < keys7->length)){
HXLINE( 575)								int key = keys7->__get(_g);
HXDLIN( 575)								_g = (_g + 1);
HXDLIN( 575)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)7: {
HXLINE( 575)							 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 575)							int state = 2;
HXDLIN( 575)							int _g = 0;
HXDLIN( 575)							while((_g < keys7->length)){
HXLINE( 575)								int key = keys7->__get(_g);
HXDLIN( 575)								_g = (_g + 1);
HXDLIN( 575)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)8: {
HXLINE( 575)							 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 575)							int state = 2;
HXDLIN( 575)							int _g = 0;
HXDLIN( 575)							while((_g < keys7->length)){
HXLINE( 575)								int key = keys7->__get(_g);
HXDLIN( 575)								_g = (_g + 1);
HXDLIN( 575)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)9: {
HXLINE( 575)							 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 575)							int state = 2;
HXDLIN( 575)							int _g = 0;
HXDLIN( 575)							while((_g < keys7->length)){
HXLINE( 575)								int key = keys7->__get(_g);
HXDLIN( 575)								_g = (_g + 1);
HXDLIN( 575)								action->addKey(key,state);
            							}
            						}
            						break;
            					}
            				}
HXLINE( 576)				{
HXLINE( 576)					::Array< int > keys8 = ::Array_obj< int >::__new(0);
HXDLIN( 576)					switch((int)(::Control_obj::CHEAT_dyn()->_hx_getIndex())){
            						case (int)0: {
HXLINE( 576)							{
HXLINE( 576)								 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 576)								int state = 1;
HXDLIN( 576)								int _g = 0;
HXDLIN( 576)								while((_g < keys8->length)){
HXLINE( 576)									int key = keys8->__get(_g);
HXDLIN( 576)									_g = (_g + 1);
HXDLIN( 576)									action->addKey(key,state);
            								}
            							}
HXDLIN( 576)							{
HXLINE( 576)								 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 576)								int state1 = 2;
HXDLIN( 576)								int _g1 = 0;
HXDLIN( 576)								while((_g1 < keys8->length)){
HXLINE( 576)									int key = keys8->__get(_g1);
HXDLIN( 576)									_g1 = (_g1 + 1);
HXDLIN( 576)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 576)							{
HXLINE( 576)								 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 576)								int state2 = -1;
HXDLIN( 576)								int _g2 = 0;
HXDLIN( 576)								while((_g2 < keys8->length)){
HXLINE( 576)									int key = keys8->__get(_g2);
HXDLIN( 576)									_g2 = (_g2 + 1);
HXDLIN( 576)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)1: {
HXLINE( 576)							{
HXLINE( 576)								 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 576)								int state = 1;
HXDLIN( 576)								int _g = 0;
HXDLIN( 576)								while((_g < keys8->length)){
HXLINE( 576)									int key = keys8->__get(_g);
HXDLIN( 576)									_g = (_g + 1);
HXDLIN( 576)									action->addKey(key,state);
            								}
            							}
HXDLIN( 576)							{
HXLINE( 576)								 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 576)								int state1 = 2;
HXDLIN( 576)								int _g1 = 0;
HXDLIN( 576)								while((_g1 < keys8->length)){
HXLINE( 576)									int key = keys8->__get(_g1);
HXDLIN( 576)									_g1 = (_g1 + 1);
HXDLIN( 576)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 576)							{
HXLINE( 576)								 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 576)								int state2 = -1;
HXDLIN( 576)								int _g2 = 0;
HXDLIN( 576)								while((_g2 < keys8->length)){
HXLINE( 576)									int key = keys8->__get(_g2);
HXDLIN( 576)									_g2 = (_g2 + 1);
HXDLIN( 576)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)2: {
HXLINE( 576)							{
HXLINE( 576)								 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 576)								int state = 1;
HXDLIN( 576)								int _g = 0;
HXDLIN( 576)								while((_g < keys8->length)){
HXLINE( 576)									int key = keys8->__get(_g);
HXDLIN( 576)									_g = (_g + 1);
HXDLIN( 576)									action->addKey(key,state);
            								}
            							}
HXDLIN( 576)							{
HXLINE( 576)								 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 576)								int state1 = 2;
HXDLIN( 576)								int _g1 = 0;
HXDLIN( 576)								while((_g1 < keys8->length)){
HXLINE( 576)									int key = keys8->__get(_g1);
HXDLIN( 576)									_g1 = (_g1 + 1);
HXDLIN( 576)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 576)							{
HXLINE( 576)								 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 576)								int state2 = -1;
HXDLIN( 576)								int _g2 = 0;
HXDLIN( 576)								while((_g2 < keys8->length)){
HXLINE( 576)									int key = keys8->__get(_g2);
HXDLIN( 576)									_g2 = (_g2 + 1);
HXDLIN( 576)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)3: {
HXLINE( 576)							{
HXLINE( 576)								 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 576)								int state = 1;
HXDLIN( 576)								int _g = 0;
HXDLIN( 576)								while((_g < keys8->length)){
HXLINE( 576)									int key = keys8->__get(_g);
HXDLIN( 576)									_g = (_g + 1);
HXDLIN( 576)									action->addKey(key,state);
            								}
            							}
HXDLIN( 576)							{
HXLINE( 576)								 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 576)								int state1 = 2;
HXDLIN( 576)								int _g1 = 0;
HXDLIN( 576)								while((_g1 < keys8->length)){
HXLINE( 576)									int key = keys8->__get(_g1);
HXDLIN( 576)									_g1 = (_g1 + 1);
HXDLIN( 576)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 576)							{
HXLINE( 576)								 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 576)								int state2 = -1;
HXDLIN( 576)								int _g2 = 0;
HXDLIN( 576)								while((_g2 < keys8->length)){
HXLINE( 576)									int key = keys8->__get(_g2);
HXDLIN( 576)									_g2 = (_g2 + 1);
HXDLIN( 576)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)4: {
HXLINE( 576)							{
HXLINE( 576)								 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 576)								int state = 1;
HXDLIN( 576)								int _g = 0;
HXDLIN( 576)								while((_g < keys8->length)){
HXLINE( 576)									int key = keys8->__get(_g);
HXDLIN( 576)									_g = (_g + 1);
HXDLIN( 576)									action->addKey(key,state);
            								}
            							}
HXDLIN( 576)							{
HXLINE( 576)								 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 576)								int state1 = 2;
HXDLIN( 576)								int _g1 = 0;
HXDLIN( 576)								while((_g1 < keys8->length)){
HXLINE( 576)									int key = keys8->__get(_g1);
HXDLIN( 576)									_g1 = (_g1 + 1);
HXDLIN( 576)									action1->addKey(key,state1);
            								}
            							}
HXDLIN( 576)							{
HXLINE( 576)								 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 576)								int state2 = -1;
HXDLIN( 576)								int _g2 = 0;
HXDLIN( 576)								while((_g2 < keys8->length)){
HXLINE( 576)									int key = keys8->__get(_g2);
HXDLIN( 576)									_g2 = (_g2 + 1);
HXDLIN( 576)									action2->addKey(key,state2);
            								}
            							}
            						}
            						break;
            						case (int)5: {
HXLINE( 576)							 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 576)							int state = 2;
HXDLIN( 576)							int _g = 0;
HXDLIN( 576)							while((_g < keys8->length)){
HXLINE( 576)								int key = keys8->__get(_g);
HXDLIN( 576)								_g = (_g + 1);
HXDLIN( 576)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)6: {
HXLINE( 576)							 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 576)							int state = 2;
HXDLIN( 576)							int _g = 0;
HXDLIN( 576)							while((_g < keys8->length)){
HXLINE( 576)								int key = keys8->__get(_g);
HXDLIN( 576)								_g = (_g + 1);
HXDLIN( 576)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)7: {
HXLINE( 576)							 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 576)							int state = 2;
HXDLIN( 576)							int _g = 0;
HXDLIN( 576)							while((_g < keys8->length)){
HXLINE( 576)								int key = keys8->__get(_g);
HXDLIN( 576)								_g = (_g + 1);
HXDLIN( 576)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)8: {
HXLINE( 576)							 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 576)							int state = 2;
HXDLIN( 576)							int _g = 0;
HXDLIN( 576)							while((_g < keys8->length)){
HXLINE( 576)								int key = keys8->__get(_g);
HXDLIN( 576)								_g = (_g + 1);
HXDLIN( 576)								action->addKey(key,state);
            							}
            						}
            						break;
            						case (int)9: {
HXLINE( 576)							 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 576)							int state = 2;
HXDLIN( 576)							int _g = 0;
HXDLIN( 576)							while((_g < keys8->length)){
HXLINE( 576)								int key = keys8->__get(_g);
HXDLIN( 576)								_g = (_g + 1);
HXDLIN( 576)								action->addKey(key,state);
            							}
            						}
            						break;
            					}
            				}
            			}
            			break;
            		}
HXLINE( 579)		{
HXLINE( 579)			::Dynamic this1 = ::flixel::input::keyboard::_FlxKey::FlxKey_Impl__obj::fromStringMap;
HXDLIN( 579)			 ::Dynamic key;
HXDLIN( 579)			switch((int)(::SaveType_obj::CUSTOM_MENU_BINDS_dyn()->_hx_getIndex())){
            				case (int)1: {
HXLINE( 579)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 579)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            					}
HXDLIN( 579)					key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            				}
            				break;
            				case (int)2: {
HXLINE( 579)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 579)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            					else {
HXLINE( 579)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 579)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            						}
            					}
HXDLIN( 579)					key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)3: {
HXLINE( 579)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 579)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            					}
HXDLIN( 579)					key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            				}
            				break;
            				case (int)4: {
HXLINE( 579)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 579)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            					}
HXDLIN( 579)					key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)5: {
HXLINE( 579)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 579)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            					}
HXDLIN( 579)					key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            				}
            				break;
            				case (int)6: {
HXLINE( 579)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 579)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN( 579)					key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)7: {
HXLINE( 579)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 579)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            					}
HXDLIN( 579)					key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            				}
            				break;
            				case (int)8: {
HXLINE( 579)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 579)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            					}
HXDLIN( 579)					key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            				}
            				break;
            				case (int)9: {
HXLINE( 579)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 579)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            					}
HXDLIN( 579)					key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            				}
            				break;
            				case (int)10: {
HXLINE( 579)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 579)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            					}
HXDLIN( 579)					key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            				}
            				break;
            				case (int)11: {
HXLINE( 579)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 579)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            					else {
HXLINE( 579)						if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 579)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            						}
            					}
HXDLIN( 579)					key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            				}
            				break;
            				case (int)12: {
HXLINE( 579)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 579)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            					}
HXDLIN( 579)					key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            				}
            				break;
            				case (int)13: {
HXLINE( 579)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 579)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            					}
HXDLIN( 579)					key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            				}
            				break;
            				case (int)14: {
HXLINE( 579)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 579)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            					}
HXDLIN( 579)					key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            				}
            				break;
            				case (int)15: {
HXLINE( 579)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 579)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            					}
HXDLIN( 579)					key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            				}
            				break;
            				case (int)16: {
HXLINE( 579)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 579)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            					}
HXDLIN( 579)					key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            				}
            				break;
            				case (int)17: {
HXLINE( 579)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 579)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            					}
HXDLIN( 579)					key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            				}
            				break;
            				case (int)18: {
HXLINE( 579)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 579)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            					}
HXDLIN( 579)					key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            				}
            				break;
            				case (int)19: {
HXLINE( 579)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 579)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            					}
HXDLIN( 579)					key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            				}
            				break;
            				case (int)20: {
HXLINE( 579)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 579)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            					}
HXDLIN( 579)					key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            				}
            				break;
            				case (int)21: {
HXLINE( 579)					if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 579)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            					}
HXDLIN( 579)					key =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            				}
            				break;
            				default:{
HXLINE( 579)					key = null();
            				}
            			}
HXDLIN( 579)			::Array< int > keys = ::Array_obj< int >::__new(1)->init(0,( ( ::haxe::ds::StringMap)(this1) )->get(key->__GetItem(0)->__Field(HX_("split",da,ea,6e,81),::hx::paccDynamic)(HX_(" ",20,00,00,00))->__GetItem(0)));
HXDLIN( 579)			switch((int)(::Control_obj::SPACE_dyn()->_hx_getIndex())){
            				case (int)0: {
HXLINE( 579)					{
HXLINE( 579)						 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 579)						int state = 1;
HXDLIN( 579)						int _g = 0;
HXDLIN( 579)						while((_g < keys->length)){
HXLINE( 579)							int key = keys->__get(_g);
HXDLIN( 579)							_g = (_g + 1);
HXDLIN( 579)							action->addKey(key,state);
            						}
            					}
HXDLIN( 579)					{
HXLINE( 579)						 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 579)						int state1 = 2;
HXDLIN( 579)						int _g1 = 0;
HXDLIN( 579)						while((_g1 < keys->length)){
HXLINE( 579)							int key = keys->__get(_g1);
HXDLIN( 579)							_g1 = (_g1 + 1);
HXDLIN( 579)							action1->addKey(key,state1);
            						}
            					}
HXDLIN( 579)					{
HXLINE( 579)						 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 579)						int state2 = -1;
HXDLIN( 579)						int _g2 = 0;
HXDLIN( 579)						while((_g2 < keys->length)){
HXLINE( 579)							int key = keys->__get(_g2);
HXDLIN( 579)							_g2 = (_g2 + 1);
HXDLIN( 579)							action2->addKey(key,state2);
            						}
            					}
            				}
            				break;
            				case (int)1: {
HXLINE( 579)					{
HXLINE( 579)						 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 579)						int state = 1;
HXDLIN( 579)						int _g = 0;
HXDLIN( 579)						while((_g < keys->length)){
HXLINE( 579)							int key = keys->__get(_g);
HXDLIN( 579)							_g = (_g + 1);
HXDLIN( 579)							action->addKey(key,state);
            						}
            					}
HXDLIN( 579)					{
HXLINE( 579)						 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 579)						int state1 = 2;
HXDLIN( 579)						int _g1 = 0;
HXDLIN( 579)						while((_g1 < keys->length)){
HXLINE( 579)							int key = keys->__get(_g1);
HXDLIN( 579)							_g1 = (_g1 + 1);
HXDLIN( 579)							action1->addKey(key,state1);
            						}
            					}
HXDLIN( 579)					{
HXLINE( 579)						 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 579)						int state2 = -1;
HXDLIN( 579)						int _g2 = 0;
HXDLIN( 579)						while((_g2 < keys->length)){
HXLINE( 579)							int key = keys->__get(_g2);
HXDLIN( 579)							_g2 = (_g2 + 1);
HXDLIN( 579)							action2->addKey(key,state2);
            						}
            					}
            				}
            				break;
            				case (int)2: {
HXLINE( 579)					{
HXLINE( 579)						 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 579)						int state = 1;
HXDLIN( 579)						int _g = 0;
HXDLIN( 579)						while((_g < keys->length)){
HXLINE( 579)							int key = keys->__get(_g);
HXDLIN( 579)							_g = (_g + 1);
HXDLIN( 579)							action->addKey(key,state);
            						}
            					}
HXDLIN( 579)					{
HXLINE( 579)						 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 579)						int state1 = 2;
HXDLIN( 579)						int _g1 = 0;
HXDLIN( 579)						while((_g1 < keys->length)){
HXLINE( 579)							int key = keys->__get(_g1);
HXDLIN( 579)							_g1 = (_g1 + 1);
HXDLIN( 579)							action1->addKey(key,state1);
            						}
            					}
HXDLIN( 579)					{
HXLINE( 579)						 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 579)						int state2 = -1;
HXDLIN( 579)						int _g2 = 0;
HXDLIN( 579)						while((_g2 < keys->length)){
HXLINE( 579)							int key = keys->__get(_g2);
HXDLIN( 579)							_g2 = (_g2 + 1);
HXDLIN( 579)							action2->addKey(key,state2);
            						}
            					}
            				}
            				break;
            				case (int)3: {
HXLINE( 579)					{
HXLINE( 579)						 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 579)						int state = 1;
HXDLIN( 579)						int _g = 0;
HXDLIN( 579)						while((_g < keys->length)){
HXLINE( 579)							int key = keys->__get(_g);
HXDLIN( 579)							_g = (_g + 1);
HXDLIN( 579)							action->addKey(key,state);
            						}
            					}
HXDLIN( 579)					{
HXLINE( 579)						 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 579)						int state1 = 2;
HXDLIN( 579)						int _g1 = 0;
HXDLIN( 579)						while((_g1 < keys->length)){
HXLINE( 579)							int key = keys->__get(_g1);
HXDLIN( 579)							_g1 = (_g1 + 1);
HXDLIN( 579)							action1->addKey(key,state1);
            						}
            					}
HXDLIN( 579)					{
HXLINE( 579)						 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 579)						int state2 = -1;
HXDLIN( 579)						int _g2 = 0;
HXDLIN( 579)						while((_g2 < keys->length)){
HXLINE( 579)							int key = keys->__get(_g2);
HXDLIN( 579)							_g2 = (_g2 + 1);
HXDLIN( 579)							action2->addKey(key,state2);
            						}
            					}
            				}
            				break;
            				case (int)4: {
HXLINE( 579)					{
HXLINE( 579)						 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 579)						int state = 1;
HXDLIN( 579)						int _g = 0;
HXDLIN( 579)						while((_g < keys->length)){
HXLINE( 579)							int key = keys->__get(_g);
HXDLIN( 579)							_g = (_g + 1);
HXDLIN( 579)							action->addKey(key,state);
            						}
            					}
HXDLIN( 579)					{
HXLINE( 579)						 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 579)						int state1 = 2;
HXDLIN( 579)						int _g1 = 0;
HXDLIN( 579)						while((_g1 < keys->length)){
HXLINE( 579)							int key = keys->__get(_g1);
HXDLIN( 579)							_g1 = (_g1 + 1);
HXDLIN( 579)							action1->addKey(key,state1);
            						}
            					}
HXDLIN( 579)					{
HXLINE( 579)						 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 579)						int state2 = -1;
HXDLIN( 579)						int _g2 = 0;
HXDLIN( 579)						while((_g2 < keys->length)){
HXLINE( 579)							int key = keys->__get(_g2);
HXDLIN( 579)							_g2 = (_g2 + 1);
HXDLIN( 579)							action2->addKey(key,state2);
            						}
            					}
            				}
            				break;
            				case (int)5: {
HXLINE( 579)					 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 579)					int state = 2;
HXDLIN( 579)					int _g = 0;
HXDLIN( 579)					while((_g < keys->length)){
HXLINE( 579)						int key = keys->__get(_g);
HXDLIN( 579)						_g = (_g + 1);
HXDLIN( 579)						action->addKey(key,state);
            					}
            				}
            				break;
            				case (int)6: {
HXLINE( 579)					 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 579)					int state = 2;
HXDLIN( 579)					int _g = 0;
HXDLIN( 579)					while((_g < keys->length)){
HXLINE( 579)						int key = keys->__get(_g);
HXDLIN( 579)						_g = (_g + 1);
HXDLIN( 579)						action->addKey(key,state);
            					}
            				}
            				break;
            				case (int)7: {
HXLINE( 579)					 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 579)					int state = 2;
HXDLIN( 579)					int _g = 0;
HXDLIN( 579)					while((_g < keys->length)){
HXLINE( 579)						int key = keys->__get(_g);
HXDLIN( 579)						_g = (_g + 1);
HXDLIN( 579)						action->addKey(key,state);
            					}
            				}
            				break;
            				case (int)8: {
HXLINE( 579)					 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 579)					int state = 2;
HXDLIN( 579)					int _g = 0;
HXDLIN( 579)					while((_g < keys->length)){
HXLINE( 579)						int key = keys->__get(_g);
HXDLIN( 579)						_g = (_g + 1);
HXDLIN( 579)						action->addKey(key,state);
            					}
            				}
            				break;
            				case (int)9: {
HXLINE( 579)					 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 579)					int state = 2;
HXDLIN( 579)					int _g = 0;
HXDLIN( 579)					while((_g < keys->length)){
HXLINE( 579)						int key = keys->__get(_g);
HXDLIN( 579)						_g = (_g + 1);
HXDLIN( 579)						action->addKey(key,state);
            					}
            				}
            				break;
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC2(Controls_obj,setKeyboardScheme,(void))

void Controls_obj::removeKeyboard(){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_586_removeKeyboard)
HXDLIN( 586)		int _g = 0;
HXDLIN( 586)		::Array< ::Dynamic> _g1 = this->digitalActions;
HXDLIN( 586)		while((_g < _g1->length)){
HXDLIN( 586)			 ::flixel::input::actions::FlxActionDigital action = _g1->__get(_g).StaticCast<  ::flixel::input::actions::FlxActionDigital >();
HXDLIN( 586)			_g = (_g + 1);
HXLINE( 588)			int i = action->inputs->length;
HXLINE( 589)			while(true){
HXLINE( 589)				i = (i - 1);
HXDLIN( 589)				if (!(((i + 1) > 0))) {
HXLINE( 589)					goto _hx_goto_785;
            				}
HXLINE( 591)				 ::flixel::input::actions::FlxActionInput input = action->inputs->__get(i).StaticCast<  ::flixel::input::actions::FlxActionInput >();
HXLINE( 592)				if (::hx::IsPointerEq( input->device,::flixel::input::actions::FlxInputDevice_obj::KEYBOARD_dyn() )) {
HXLINE( 593)					action->remove(input,null());
            				}
            			}
            			_hx_goto_785:;
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC0(Controls_obj,removeKeyboard,(void))

void Controls_obj::addGamepad(int id, ::haxe::ds::EnumValueMap buttonMap){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_599_addGamepad)
HXLINE( 600)		this->gamepadsAdded->push(id);
HXLINE( 603)		{
HXLINE( 603)			::Dynamic map = buttonMap;
HXDLIN( 603)			::Dynamic _g_map = map;
HXDLIN( 603)			 ::Dynamic _g_keys = ::haxe::IMap_obj::keys(map);
HXDLIN( 603)			while(( (bool)(_g_keys->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE( 603)				 ::Control key = _g_keys->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)();
HXDLIN( 603)				::Array< int > _g1_value = ( (::Array< int >)(::haxe::IMap_obj::get(_g_map,key)) );
HXDLIN( 603)				 ::Control _g1_key = key;
HXDLIN( 603)				 ::Control control = _g1_key;
HXDLIN( 603)				::Array< int > buttons = _g1_value;
HXLINE( 604)				{
HXLINE( 604)					int id1 = id;
HXDLIN( 604)					::Array< int > buttons1 = buttons;
HXDLIN( 604)					switch((int)(control->_hx_getIndex())){
            						case (int)0: {
HXLINE( 604)							{
HXLINE( 604)								 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 604)								int state = 1;
HXDLIN( 604)								int _g = 0;
HXDLIN( 604)								while((_g < buttons1->length)){
HXLINE( 604)									int button = buttons1->__get(_g);
HXDLIN( 604)									_g = (_g + 1);
HXDLIN( 604)									action->addGamepad(button,state,id1);
            								}
            							}
HXDLIN( 604)							{
HXLINE( 604)								 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 604)								int state1 = 2;
HXDLIN( 604)								int _g1 = 0;
HXDLIN( 604)								while((_g1 < buttons1->length)){
HXLINE( 604)									int button = buttons1->__get(_g1);
HXDLIN( 604)									_g1 = (_g1 + 1);
HXDLIN( 604)									action1->addGamepad(button,state1,id1);
            								}
            							}
HXDLIN( 604)							{
HXLINE( 604)								 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 604)								int state2 = -1;
HXDLIN( 604)								int _g2 = 0;
HXDLIN( 604)								while((_g2 < buttons1->length)){
HXLINE( 604)									int button = buttons1->__get(_g2);
HXDLIN( 604)									_g2 = (_g2 + 1);
HXDLIN( 604)									action2->addGamepad(button,state2,id1);
            								}
            							}
            						}
            						break;
            						case (int)1: {
HXLINE( 604)							{
HXLINE( 604)								 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 604)								int state = 1;
HXDLIN( 604)								int _g = 0;
HXDLIN( 604)								while((_g < buttons1->length)){
HXLINE( 604)									int button = buttons1->__get(_g);
HXDLIN( 604)									_g = (_g + 1);
HXDLIN( 604)									action->addGamepad(button,state,id1);
            								}
            							}
HXDLIN( 604)							{
HXLINE( 604)								 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 604)								int state1 = 2;
HXDLIN( 604)								int _g1 = 0;
HXDLIN( 604)								while((_g1 < buttons1->length)){
HXLINE( 604)									int button = buttons1->__get(_g1);
HXDLIN( 604)									_g1 = (_g1 + 1);
HXDLIN( 604)									action1->addGamepad(button,state1,id1);
            								}
            							}
HXDLIN( 604)							{
HXLINE( 604)								 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 604)								int state2 = -1;
HXDLIN( 604)								int _g2 = 0;
HXDLIN( 604)								while((_g2 < buttons1->length)){
HXLINE( 604)									int button = buttons1->__get(_g2);
HXDLIN( 604)									_g2 = (_g2 + 1);
HXDLIN( 604)									action2->addGamepad(button,state2,id1);
            								}
            							}
            						}
            						break;
            						case (int)2: {
HXLINE( 604)							{
HXLINE( 604)								 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 604)								int state = 1;
HXDLIN( 604)								int _g = 0;
HXDLIN( 604)								while((_g < buttons1->length)){
HXLINE( 604)									int button = buttons1->__get(_g);
HXDLIN( 604)									_g = (_g + 1);
HXDLIN( 604)									action->addGamepad(button,state,id1);
            								}
            							}
HXDLIN( 604)							{
HXLINE( 604)								 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 604)								int state1 = 2;
HXDLIN( 604)								int _g1 = 0;
HXDLIN( 604)								while((_g1 < buttons1->length)){
HXLINE( 604)									int button = buttons1->__get(_g1);
HXDLIN( 604)									_g1 = (_g1 + 1);
HXDLIN( 604)									action1->addGamepad(button,state1,id1);
            								}
            							}
HXDLIN( 604)							{
HXLINE( 604)								 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 604)								int state2 = -1;
HXDLIN( 604)								int _g2 = 0;
HXDLIN( 604)								while((_g2 < buttons1->length)){
HXLINE( 604)									int button = buttons1->__get(_g2);
HXDLIN( 604)									_g2 = (_g2 + 1);
HXDLIN( 604)									action2->addGamepad(button,state2,id1);
            								}
            							}
            						}
            						break;
            						case (int)3: {
HXLINE( 604)							{
HXLINE( 604)								 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 604)								int state = 1;
HXDLIN( 604)								int _g = 0;
HXDLIN( 604)								while((_g < buttons1->length)){
HXLINE( 604)									int button = buttons1->__get(_g);
HXDLIN( 604)									_g = (_g + 1);
HXDLIN( 604)									action->addGamepad(button,state,id1);
            								}
            							}
HXDLIN( 604)							{
HXLINE( 604)								 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 604)								int state1 = 2;
HXDLIN( 604)								int _g1 = 0;
HXDLIN( 604)								while((_g1 < buttons1->length)){
HXLINE( 604)									int button = buttons1->__get(_g1);
HXDLIN( 604)									_g1 = (_g1 + 1);
HXDLIN( 604)									action1->addGamepad(button,state1,id1);
            								}
            							}
HXDLIN( 604)							{
HXLINE( 604)								 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 604)								int state2 = -1;
HXDLIN( 604)								int _g2 = 0;
HXDLIN( 604)								while((_g2 < buttons1->length)){
HXLINE( 604)									int button = buttons1->__get(_g2);
HXDLIN( 604)									_g2 = (_g2 + 1);
HXDLIN( 604)									action2->addGamepad(button,state2,id1);
            								}
            							}
            						}
            						break;
            						case (int)4: {
HXLINE( 604)							{
HXLINE( 604)								 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 604)								int state = 1;
HXDLIN( 604)								int _g = 0;
HXDLIN( 604)								while((_g < buttons1->length)){
HXLINE( 604)									int button = buttons1->__get(_g);
HXDLIN( 604)									_g = (_g + 1);
HXDLIN( 604)									action->addGamepad(button,state,id1);
            								}
            							}
HXDLIN( 604)							{
HXLINE( 604)								 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 604)								int state1 = 2;
HXDLIN( 604)								int _g1 = 0;
HXDLIN( 604)								while((_g1 < buttons1->length)){
HXLINE( 604)									int button = buttons1->__get(_g1);
HXDLIN( 604)									_g1 = (_g1 + 1);
HXDLIN( 604)									action1->addGamepad(button,state1,id1);
            								}
            							}
HXDLIN( 604)							{
HXLINE( 604)								 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 604)								int state2 = -1;
HXDLIN( 604)								int _g2 = 0;
HXDLIN( 604)								while((_g2 < buttons1->length)){
HXLINE( 604)									int button = buttons1->__get(_g2);
HXDLIN( 604)									_g2 = (_g2 + 1);
HXDLIN( 604)									action2->addGamepad(button,state2,id1);
            								}
            							}
            						}
            						break;
            						case (int)5: {
HXLINE( 604)							 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 604)							int state = 2;
HXDLIN( 604)							int _g = 0;
HXDLIN( 604)							while((_g < buttons1->length)){
HXLINE( 604)								int button = buttons1->__get(_g);
HXDLIN( 604)								_g = (_g + 1);
HXDLIN( 604)								action->addGamepad(button,state,id1);
            							}
            						}
            						break;
            						case (int)6: {
HXLINE( 604)							 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 604)							int state = 2;
HXDLIN( 604)							int _g = 0;
HXDLIN( 604)							while((_g < buttons1->length)){
HXLINE( 604)								int button = buttons1->__get(_g);
HXDLIN( 604)								_g = (_g + 1);
HXDLIN( 604)								action->addGamepad(button,state,id1);
            							}
            						}
            						break;
            						case (int)7: {
HXLINE( 604)							 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 604)							int state = 2;
HXDLIN( 604)							int _g = 0;
HXDLIN( 604)							while((_g < buttons1->length)){
HXLINE( 604)								int button = buttons1->__get(_g);
HXDLIN( 604)								_g = (_g + 1);
HXDLIN( 604)								action->addGamepad(button,state,id1);
            							}
            						}
            						break;
            						case (int)8: {
HXLINE( 604)							 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 604)							int state = 2;
HXDLIN( 604)							int _g = 0;
HXDLIN( 604)							while((_g < buttons1->length)){
HXLINE( 604)								int button = buttons1->__get(_g);
HXDLIN( 604)								_g = (_g + 1);
HXDLIN( 604)								action->addGamepad(button,state,id1);
            							}
            						}
            						break;
            						case (int)9: {
HXLINE( 604)							 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 604)							int state = 2;
HXDLIN( 604)							int _g = 0;
HXDLIN( 604)							while((_g < buttons1->length)){
HXLINE( 604)								int button = buttons1->__get(_g);
HXDLIN( 604)								_g = (_g + 1);
HXDLIN( 604)								action->addGamepad(button,state,id1);
            							}
            						}
            						break;
            					}
            				}
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC2(Controls_obj,addGamepad,(void))

void Controls_obj::addGamepadLiteral(int id, ::haxe::ds::EnumValueMap buttonMap){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_612_addGamepadLiteral)
HXLINE( 613)		this->gamepadsAdded->push(id);
HXLINE( 616)		{
HXLINE( 616)			::Dynamic map = buttonMap;
HXDLIN( 616)			::Dynamic _g_map = map;
HXDLIN( 616)			 ::Dynamic _g_keys = ::haxe::IMap_obj::keys(map);
HXDLIN( 616)			while(( (bool)(_g_keys->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE( 616)				 ::Control key = _g_keys->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)();
HXDLIN( 616)				::Array< int > _g1_value = ( (::Array< int >)(::haxe::IMap_obj::get(_g_map,key)) );
HXDLIN( 616)				 ::Control _g1_key = key;
HXDLIN( 616)				 ::Control control = _g1_key;
HXDLIN( 616)				::Array< int > buttons = _g1_value;
HXLINE( 617)				{
HXLINE( 617)					int id1 = id;
HXDLIN( 617)					::Array< int > buttons1 = buttons;
HXDLIN( 617)					switch((int)(control->_hx_getIndex())){
            						case (int)0: {
HXLINE( 617)							{
HXLINE( 617)								 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 617)								int state = 1;
HXDLIN( 617)								int _g = 0;
HXDLIN( 617)								while((_g < buttons1->length)){
HXLINE( 617)									int button = buttons1->__get(_g);
HXDLIN( 617)									_g = (_g + 1);
HXDLIN( 617)									action->addGamepad(button,state,id1);
            								}
            							}
HXDLIN( 617)							{
HXLINE( 617)								 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 617)								int state1 = 2;
HXDLIN( 617)								int _g1 = 0;
HXDLIN( 617)								while((_g1 < buttons1->length)){
HXLINE( 617)									int button = buttons1->__get(_g1);
HXDLIN( 617)									_g1 = (_g1 + 1);
HXDLIN( 617)									action1->addGamepad(button,state1,id1);
            								}
            							}
HXDLIN( 617)							{
HXLINE( 617)								 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 617)								int state2 = -1;
HXDLIN( 617)								int _g2 = 0;
HXDLIN( 617)								while((_g2 < buttons1->length)){
HXLINE( 617)									int button = buttons1->__get(_g2);
HXDLIN( 617)									_g2 = (_g2 + 1);
HXDLIN( 617)									action2->addGamepad(button,state2,id1);
            								}
            							}
            						}
            						break;
            						case (int)1: {
HXLINE( 617)							{
HXLINE( 617)								 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 617)								int state = 1;
HXDLIN( 617)								int _g = 0;
HXDLIN( 617)								while((_g < buttons1->length)){
HXLINE( 617)									int button = buttons1->__get(_g);
HXDLIN( 617)									_g = (_g + 1);
HXDLIN( 617)									action->addGamepad(button,state,id1);
            								}
            							}
HXDLIN( 617)							{
HXLINE( 617)								 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 617)								int state1 = 2;
HXDLIN( 617)								int _g1 = 0;
HXDLIN( 617)								while((_g1 < buttons1->length)){
HXLINE( 617)									int button = buttons1->__get(_g1);
HXDLIN( 617)									_g1 = (_g1 + 1);
HXDLIN( 617)									action1->addGamepad(button,state1,id1);
            								}
            							}
HXDLIN( 617)							{
HXLINE( 617)								 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 617)								int state2 = -1;
HXDLIN( 617)								int _g2 = 0;
HXDLIN( 617)								while((_g2 < buttons1->length)){
HXLINE( 617)									int button = buttons1->__get(_g2);
HXDLIN( 617)									_g2 = (_g2 + 1);
HXDLIN( 617)									action2->addGamepad(button,state2,id1);
            								}
            							}
            						}
            						break;
            						case (int)2: {
HXLINE( 617)							{
HXLINE( 617)								 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 617)								int state = 1;
HXDLIN( 617)								int _g = 0;
HXDLIN( 617)								while((_g < buttons1->length)){
HXLINE( 617)									int button = buttons1->__get(_g);
HXDLIN( 617)									_g = (_g + 1);
HXDLIN( 617)									action->addGamepad(button,state,id1);
            								}
            							}
HXDLIN( 617)							{
HXLINE( 617)								 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 617)								int state1 = 2;
HXDLIN( 617)								int _g1 = 0;
HXDLIN( 617)								while((_g1 < buttons1->length)){
HXLINE( 617)									int button = buttons1->__get(_g1);
HXDLIN( 617)									_g1 = (_g1 + 1);
HXDLIN( 617)									action1->addGamepad(button,state1,id1);
            								}
            							}
HXDLIN( 617)							{
HXLINE( 617)								 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 617)								int state2 = -1;
HXDLIN( 617)								int _g2 = 0;
HXDLIN( 617)								while((_g2 < buttons1->length)){
HXLINE( 617)									int button = buttons1->__get(_g2);
HXDLIN( 617)									_g2 = (_g2 + 1);
HXDLIN( 617)									action2->addGamepad(button,state2,id1);
            								}
            							}
            						}
            						break;
            						case (int)3: {
HXLINE( 617)							{
HXLINE( 617)								 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 617)								int state = 1;
HXDLIN( 617)								int _g = 0;
HXDLIN( 617)								while((_g < buttons1->length)){
HXLINE( 617)									int button = buttons1->__get(_g);
HXDLIN( 617)									_g = (_g + 1);
HXDLIN( 617)									action->addGamepad(button,state,id1);
            								}
            							}
HXDLIN( 617)							{
HXLINE( 617)								 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 617)								int state1 = 2;
HXDLIN( 617)								int _g1 = 0;
HXDLIN( 617)								while((_g1 < buttons1->length)){
HXLINE( 617)									int button = buttons1->__get(_g1);
HXDLIN( 617)									_g1 = (_g1 + 1);
HXDLIN( 617)									action1->addGamepad(button,state1,id1);
            								}
            							}
HXDLIN( 617)							{
HXLINE( 617)								 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 617)								int state2 = -1;
HXDLIN( 617)								int _g2 = 0;
HXDLIN( 617)								while((_g2 < buttons1->length)){
HXLINE( 617)									int button = buttons1->__get(_g2);
HXDLIN( 617)									_g2 = (_g2 + 1);
HXDLIN( 617)									action2->addGamepad(button,state2,id1);
            								}
            							}
            						}
            						break;
            						case (int)4: {
HXLINE( 617)							{
HXLINE( 617)								 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 617)								int state = 1;
HXDLIN( 617)								int _g = 0;
HXDLIN( 617)								while((_g < buttons1->length)){
HXLINE( 617)									int button = buttons1->__get(_g);
HXDLIN( 617)									_g = (_g + 1);
HXDLIN( 617)									action->addGamepad(button,state,id1);
            								}
            							}
HXDLIN( 617)							{
HXLINE( 617)								 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 617)								int state1 = 2;
HXDLIN( 617)								int _g1 = 0;
HXDLIN( 617)								while((_g1 < buttons1->length)){
HXLINE( 617)									int button = buttons1->__get(_g1);
HXDLIN( 617)									_g1 = (_g1 + 1);
HXDLIN( 617)									action1->addGamepad(button,state1,id1);
            								}
            							}
HXDLIN( 617)							{
HXLINE( 617)								 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 617)								int state2 = -1;
HXDLIN( 617)								int _g2 = 0;
HXDLIN( 617)								while((_g2 < buttons1->length)){
HXLINE( 617)									int button = buttons1->__get(_g2);
HXDLIN( 617)									_g2 = (_g2 + 1);
HXDLIN( 617)									action2->addGamepad(button,state2,id1);
            								}
            							}
            						}
            						break;
            						case (int)5: {
HXLINE( 617)							 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 617)							int state = 2;
HXDLIN( 617)							int _g = 0;
HXDLIN( 617)							while((_g < buttons1->length)){
HXLINE( 617)								int button = buttons1->__get(_g);
HXDLIN( 617)								_g = (_g + 1);
HXDLIN( 617)								action->addGamepad(button,state,id1);
            							}
            						}
            						break;
            						case (int)6: {
HXLINE( 617)							 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 617)							int state = 2;
HXDLIN( 617)							int _g = 0;
HXDLIN( 617)							while((_g < buttons1->length)){
HXLINE( 617)								int button = buttons1->__get(_g);
HXDLIN( 617)								_g = (_g + 1);
HXDLIN( 617)								action->addGamepad(button,state,id1);
            							}
            						}
            						break;
            						case (int)7: {
HXLINE( 617)							 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 617)							int state = 2;
HXDLIN( 617)							int _g = 0;
HXDLIN( 617)							while((_g < buttons1->length)){
HXLINE( 617)								int button = buttons1->__get(_g);
HXDLIN( 617)								_g = (_g + 1);
HXDLIN( 617)								action->addGamepad(button,state,id1);
            							}
            						}
            						break;
            						case (int)8: {
HXLINE( 617)							 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 617)							int state = 2;
HXDLIN( 617)							int _g = 0;
HXDLIN( 617)							while((_g < buttons1->length)){
HXLINE( 617)								int button = buttons1->__get(_g);
HXDLIN( 617)								_g = (_g + 1);
HXDLIN( 617)								action->addGamepad(button,state,id1);
            							}
            						}
            						break;
            						case (int)9: {
HXLINE( 617)							 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 617)							int state = 2;
HXDLIN( 617)							int _g = 0;
HXDLIN( 617)							while((_g < buttons1->length)){
HXLINE( 617)								int button = buttons1->__get(_g);
HXDLIN( 617)								_g = (_g + 1);
HXDLIN( 617)								action->addGamepad(button,state,id1);
            							}
            						}
            						break;
            					}
            				}
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC2(Controls_obj,addGamepadLiteral,(void))

void Controls_obj::removeGamepad(::hx::Null< int >  __o_deviceID){
            		int deviceID = __o_deviceID.Default(-1);
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_625_removeGamepad)
HXLINE( 626)		{
HXLINE( 626)			int _g = 0;
HXDLIN( 626)			::Array< ::Dynamic> _g1 = this->digitalActions;
HXDLIN( 626)			while((_g < _g1->length)){
HXLINE( 626)				 ::flixel::input::actions::FlxActionDigital action = _g1->__get(_g).StaticCast<  ::flixel::input::actions::FlxActionDigital >();
HXDLIN( 626)				_g = (_g + 1);
HXLINE( 628)				int i = action->inputs->length;
HXLINE( 629)				while(true){
HXLINE( 629)					i = (i - 1);
HXDLIN( 629)					if (!(((i + 1) > 0))) {
HXLINE( 629)						goto _hx_goto_832;
            					}
HXLINE( 631)					 ::flixel::input::actions::FlxActionInput input = action->inputs->__get(i).StaticCast<  ::flixel::input::actions::FlxActionInput >();
HXLINE( 632)					bool _hx_tmp;
HXDLIN( 632)					if (::hx::IsPointerEq( input->device,::flixel::input::actions::FlxInputDevice_obj::GAMEPAD_dyn() )) {
HXLINE( 632)						if ((deviceID != -1)) {
HXLINE( 632)							_hx_tmp = (input->deviceID == deviceID);
            						}
            						else {
HXLINE( 632)							_hx_tmp = true;
            						}
            					}
            					else {
HXLINE( 632)						_hx_tmp = false;
            					}
HXDLIN( 632)					if (_hx_tmp) {
HXLINE( 633)						action->remove(input,null());
            					}
            				}
            				_hx_goto_832:;
            			}
            		}
HXLINE( 637)		this->gamepadsAdded->remove(deviceID);
            	}


HX_DEFINE_DYNAMIC_FUNC1(Controls_obj,removeGamepad,(void))

void Controls_obj::addDefaultGamepad(int id){
            	HX_GC_STACKFRAME(&_hx_pos_948b5caa279cd923_643_addDefaultGamepad)
HXDLIN( 643)		 ::haxe::ds::EnumValueMap _g =  ::haxe::ds::EnumValueMap_obj::__alloc( HX_CTX );
HXDLIN( 643)		_g->set(::Control_obj::ACCEPT_dyn(),::Array_obj< int >::fromData( _hx_array_data_116e4296_856,1));
HXDLIN( 643)		_g->set(::Control_obj::BACK_dyn(),::Array_obj< int >::fromData( _hx_array_data_116e4296_857,1));
HXDLIN( 643)		_g->set(::Control_obj::UP_dyn(),::Array_obj< int >::fromData( _hx_array_data_116e4296_858,2));
HXDLIN( 643)		_g->set(::Control_obj::DOWN_dyn(),::Array_obj< int >::fromData( _hx_array_data_116e4296_859,2));
HXDLIN( 643)		_g->set(::Control_obj::LEFT_dyn(),::Array_obj< int >::fromData( _hx_array_data_116e4296_860,2));
HXDLIN( 643)		_g->set(::Control_obj::RIGHT_dyn(),::Array_obj< int >::fromData( _hx_array_data_116e4296_861,2));
HXDLIN( 643)		_g->set(::Control_obj::PAUSE_dyn(),::Array_obj< int >::fromData( _hx_array_data_116e4296_862,1));
HXDLIN( 643)		_g->set(::Control_obj::RESET_dyn(),::Array_obj< int >::fromData( _hx_array_data_116e4296_863,1));
HXDLIN( 643)		this->gamepadsAdded->push(id);
HXDLIN( 643)		{
HXDLIN( 643)			::Dynamic map = _g;
HXDLIN( 643)			::Dynamic _g_map = map;
HXDLIN( 643)			 ::Dynamic _g_keys = ::haxe::IMap_obj::keys(map);
HXDLIN( 643)			while(( (bool)(_g_keys->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXDLIN( 643)				 ::Control key = _g_keys->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)();
HXDLIN( 643)				::Array< int > _g1_value = ( (::Array< int >)(::haxe::IMap_obj::get(_g_map,key)) );
HXDLIN( 643)				 ::Control _g1_key = key;
HXDLIN( 643)				 ::Control control = _g1_key;
HXDLIN( 643)				::Array< int > buttons = _g1_value;
HXDLIN( 643)				{
HXDLIN( 643)					int id1 = id;
HXDLIN( 643)					::Array< int > buttons1 = buttons;
HXDLIN( 643)					switch((int)(control->_hx_getIndex())){
            						case (int)0: {
HXDLIN( 643)							{
HXDLIN( 643)								 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 643)								int state = 1;
HXDLIN( 643)								int _g = 0;
HXDLIN( 643)								while((_g < buttons1->length)){
HXDLIN( 643)									int button = buttons1->__get(_g);
HXDLIN( 643)									_g = (_g + 1);
HXDLIN( 643)									action->addGamepad(button,state,id1);
            								}
            							}
HXDLIN( 643)							{
HXDLIN( 643)								 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 643)								int state1 = 2;
HXDLIN( 643)								int _g1 = 0;
HXDLIN( 643)								while((_g1 < buttons1->length)){
HXDLIN( 643)									int button = buttons1->__get(_g1);
HXDLIN( 643)									_g1 = (_g1 + 1);
HXDLIN( 643)									action1->addGamepad(button,state1,id1);
            								}
            							}
HXDLIN( 643)							{
HXDLIN( 643)								 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 643)								int state2 = -1;
HXDLIN( 643)								int _g2 = 0;
HXDLIN( 643)								while((_g2 < buttons1->length)){
HXDLIN( 643)									int button = buttons1->__get(_g2);
HXDLIN( 643)									_g2 = (_g2 + 1);
HXDLIN( 643)									action2->addGamepad(button,state2,id1);
            								}
            							}
            						}
            						break;
            						case (int)1: {
HXDLIN( 643)							{
HXDLIN( 643)								 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 643)								int state = 1;
HXDLIN( 643)								int _g = 0;
HXDLIN( 643)								while((_g < buttons1->length)){
HXDLIN( 643)									int button = buttons1->__get(_g);
HXDLIN( 643)									_g = (_g + 1);
HXDLIN( 643)									action->addGamepad(button,state,id1);
            								}
            							}
HXDLIN( 643)							{
HXDLIN( 643)								 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 643)								int state1 = 2;
HXDLIN( 643)								int _g1 = 0;
HXDLIN( 643)								while((_g1 < buttons1->length)){
HXDLIN( 643)									int button = buttons1->__get(_g1);
HXDLIN( 643)									_g1 = (_g1 + 1);
HXDLIN( 643)									action1->addGamepad(button,state1,id1);
            								}
            							}
HXDLIN( 643)							{
HXDLIN( 643)								 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 643)								int state2 = -1;
HXDLIN( 643)								int _g2 = 0;
HXDLIN( 643)								while((_g2 < buttons1->length)){
HXDLIN( 643)									int button = buttons1->__get(_g2);
HXDLIN( 643)									_g2 = (_g2 + 1);
HXDLIN( 643)									action2->addGamepad(button,state2,id1);
            								}
            							}
            						}
            						break;
            						case (int)2: {
HXDLIN( 643)							{
HXDLIN( 643)								 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 643)								int state = 1;
HXDLIN( 643)								int _g = 0;
HXDLIN( 643)								while((_g < buttons1->length)){
HXDLIN( 643)									int button = buttons1->__get(_g);
HXDLIN( 643)									_g = (_g + 1);
HXDLIN( 643)									action->addGamepad(button,state,id1);
            								}
            							}
HXDLIN( 643)							{
HXDLIN( 643)								 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 643)								int state1 = 2;
HXDLIN( 643)								int _g1 = 0;
HXDLIN( 643)								while((_g1 < buttons1->length)){
HXDLIN( 643)									int button = buttons1->__get(_g1);
HXDLIN( 643)									_g1 = (_g1 + 1);
HXDLIN( 643)									action1->addGamepad(button,state1,id1);
            								}
            							}
HXDLIN( 643)							{
HXDLIN( 643)								 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 643)								int state2 = -1;
HXDLIN( 643)								int _g2 = 0;
HXDLIN( 643)								while((_g2 < buttons1->length)){
HXDLIN( 643)									int button = buttons1->__get(_g2);
HXDLIN( 643)									_g2 = (_g2 + 1);
HXDLIN( 643)									action2->addGamepad(button,state2,id1);
            								}
            							}
            						}
            						break;
            						case (int)3: {
HXDLIN( 643)							{
HXDLIN( 643)								 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 643)								int state = 1;
HXDLIN( 643)								int _g = 0;
HXDLIN( 643)								while((_g < buttons1->length)){
HXDLIN( 643)									int button = buttons1->__get(_g);
HXDLIN( 643)									_g = (_g + 1);
HXDLIN( 643)									action->addGamepad(button,state,id1);
            								}
            							}
HXDLIN( 643)							{
HXDLIN( 643)								 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 643)								int state1 = 2;
HXDLIN( 643)								int _g1 = 0;
HXDLIN( 643)								while((_g1 < buttons1->length)){
HXDLIN( 643)									int button = buttons1->__get(_g1);
HXDLIN( 643)									_g1 = (_g1 + 1);
HXDLIN( 643)									action1->addGamepad(button,state1,id1);
            								}
            							}
HXDLIN( 643)							{
HXDLIN( 643)								 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 643)								int state2 = -1;
HXDLIN( 643)								int _g2 = 0;
HXDLIN( 643)								while((_g2 < buttons1->length)){
HXDLIN( 643)									int button = buttons1->__get(_g2);
HXDLIN( 643)									_g2 = (_g2 + 1);
HXDLIN( 643)									action2->addGamepad(button,state2,id1);
            								}
            							}
            						}
            						break;
            						case (int)4: {
HXDLIN( 643)							{
HXDLIN( 643)								 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 643)								int state = 1;
HXDLIN( 643)								int _g = 0;
HXDLIN( 643)								while((_g < buttons1->length)){
HXDLIN( 643)									int button = buttons1->__get(_g);
HXDLIN( 643)									_g = (_g + 1);
HXDLIN( 643)									action->addGamepad(button,state,id1);
            								}
            							}
HXDLIN( 643)							{
HXDLIN( 643)								 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 643)								int state1 = 2;
HXDLIN( 643)								int _g1 = 0;
HXDLIN( 643)								while((_g1 < buttons1->length)){
HXDLIN( 643)									int button = buttons1->__get(_g1);
HXDLIN( 643)									_g1 = (_g1 + 1);
HXDLIN( 643)									action1->addGamepad(button,state1,id1);
            								}
            							}
HXDLIN( 643)							{
HXDLIN( 643)								 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 643)								int state2 = -1;
HXDLIN( 643)								int _g2 = 0;
HXDLIN( 643)								while((_g2 < buttons1->length)){
HXDLIN( 643)									int button = buttons1->__get(_g2);
HXDLIN( 643)									_g2 = (_g2 + 1);
HXDLIN( 643)									action2->addGamepad(button,state2,id1);
            								}
            							}
            						}
            						break;
            						case (int)5: {
HXDLIN( 643)							 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 643)							int state = 2;
HXDLIN( 643)							int _g = 0;
HXDLIN( 643)							while((_g < buttons1->length)){
HXDLIN( 643)								int button = buttons1->__get(_g);
HXDLIN( 643)								_g = (_g + 1);
HXDLIN( 643)								action->addGamepad(button,state,id1);
            							}
            						}
            						break;
            						case (int)6: {
HXDLIN( 643)							 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 643)							int state = 2;
HXDLIN( 643)							int _g = 0;
HXDLIN( 643)							while((_g < buttons1->length)){
HXDLIN( 643)								int button = buttons1->__get(_g);
HXDLIN( 643)								_g = (_g + 1);
HXDLIN( 643)								action->addGamepad(button,state,id1);
            							}
            						}
            						break;
            						case (int)7: {
HXDLIN( 643)							 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 643)							int state = 2;
HXDLIN( 643)							int _g = 0;
HXDLIN( 643)							while((_g < buttons1->length)){
HXDLIN( 643)								int button = buttons1->__get(_g);
HXDLIN( 643)								_g = (_g + 1);
HXDLIN( 643)								action->addGamepad(button,state,id1);
            							}
            						}
            						break;
            						case (int)8: {
HXDLIN( 643)							 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 643)							int state = 2;
HXDLIN( 643)							int _g = 0;
HXDLIN( 643)							while((_g < buttons1->length)){
HXDLIN( 643)								int button = buttons1->__get(_g);
HXDLIN( 643)								_g = (_g + 1);
HXDLIN( 643)								action->addGamepad(button,state,id1);
            							}
            						}
            						break;
            						case (int)9: {
HXDLIN( 643)							 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 643)							int state = 2;
HXDLIN( 643)							int _g = 0;
HXDLIN( 643)							while((_g < buttons1->length)){
HXDLIN( 643)								int button = buttons1->__get(_g);
HXDLIN( 643)								_g = (_g + 1);
HXDLIN( 643)								action->addGamepad(button,state,id1);
            							}
            						}
            						break;
            					}
            				}
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(Controls_obj,addDefaultGamepad,(void))

void Controls_obj::bindButtons( ::Control control,int id,::Array< int > buttons){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_677_bindButtons)
HXDLIN( 677)		switch((int)(control->_hx_getIndex())){
            			case (int)0: {
HXDLIN( 677)				{
HXDLIN( 677)					 ::flixel::input::actions::FlxActionDigital action = this->_up;
HXDLIN( 677)					int state = 1;
HXDLIN( 677)					int _g = 0;
HXDLIN( 677)					while((_g < buttons->length)){
HXDLIN( 677)						int button = buttons->__get(_g);
HXDLIN( 677)						_g = (_g + 1);
HXDLIN( 677)						action->addGamepad(button,state,id);
            					}
            				}
HXDLIN( 677)				{
HXDLIN( 677)					 ::flixel::input::actions::FlxActionDigital action1 = this->_upP;
HXDLIN( 677)					int state1 = 2;
HXDLIN( 677)					int _g1 = 0;
HXDLIN( 677)					while((_g1 < buttons->length)){
HXDLIN( 677)						int button = buttons->__get(_g1);
HXDLIN( 677)						_g1 = (_g1 + 1);
HXDLIN( 677)						action1->addGamepad(button,state1,id);
            					}
            				}
HXDLIN( 677)				{
HXDLIN( 677)					 ::flixel::input::actions::FlxActionDigital action2 = this->_upR;
HXDLIN( 677)					int state2 = -1;
HXDLIN( 677)					int _g2 = 0;
HXDLIN( 677)					while((_g2 < buttons->length)){
HXDLIN( 677)						int button = buttons->__get(_g2);
HXDLIN( 677)						_g2 = (_g2 + 1);
HXDLIN( 677)						action2->addGamepad(button,state2,id);
            					}
            				}
            			}
            			break;
            			case (int)1: {
HXDLIN( 677)				{
HXDLIN( 677)					 ::flixel::input::actions::FlxActionDigital action = this->_left;
HXDLIN( 677)					int state = 1;
HXDLIN( 677)					int _g = 0;
HXDLIN( 677)					while((_g < buttons->length)){
HXDLIN( 677)						int button = buttons->__get(_g);
HXDLIN( 677)						_g = (_g + 1);
HXDLIN( 677)						action->addGamepad(button,state,id);
            					}
            				}
HXDLIN( 677)				{
HXDLIN( 677)					 ::flixel::input::actions::FlxActionDigital action1 = this->_leftP;
HXDLIN( 677)					int state1 = 2;
HXDLIN( 677)					int _g1 = 0;
HXDLIN( 677)					while((_g1 < buttons->length)){
HXDLIN( 677)						int button = buttons->__get(_g1);
HXDLIN( 677)						_g1 = (_g1 + 1);
HXDLIN( 677)						action1->addGamepad(button,state1,id);
            					}
            				}
HXDLIN( 677)				{
HXDLIN( 677)					 ::flixel::input::actions::FlxActionDigital action2 = this->_leftR;
HXDLIN( 677)					int state2 = -1;
HXDLIN( 677)					int _g2 = 0;
HXDLIN( 677)					while((_g2 < buttons->length)){
HXDLIN( 677)						int button = buttons->__get(_g2);
HXDLIN( 677)						_g2 = (_g2 + 1);
HXDLIN( 677)						action2->addGamepad(button,state2,id);
            					}
            				}
            			}
            			break;
            			case (int)2: {
HXDLIN( 677)				{
HXDLIN( 677)					 ::flixel::input::actions::FlxActionDigital action = this->_right;
HXDLIN( 677)					int state = 1;
HXDLIN( 677)					int _g = 0;
HXDLIN( 677)					while((_g < buttons->length)){
HXDLIN( 677)						int button = buttons->__get(_g);
HXDLIN( 677)						_g = (_g + 1);
HXDLIN( 677)						action->addGamepad(button,state,id);
            					}
            				}
HXDLIN( 677)				{
HXDLIN( 677)					 ::flixel::input::actions::FlxActionDigital action1 = this->_rightP;
HXDLIN( 677)					int state1 = 2;
HXDLIN( 677)					int _g1 = 0;
HXDLIN( 677)					while((_g1 < buttons->length)){
HXDLIN( 677)						int button = buttons->__get(_g1);
HXDLIN( 677)						_g1 = (_g1 + 1);
HXDLIN( 677)						action1->addGamepad(button,state1,id);
            					}
            				}
HXDLIN( 677)				{
HXDLIN( 677)					 ::flixel::input::actions::FlxActionDigital action2 = this->_rightR;
HXDLIN( 677)					int state2 = -1;
HXDLIN( 677)					int _g2 = 0;
HXDLIN( 677)					while((_g2 < buttons->length)){
HXDLIN( 677)						int button = buttons->__get(_g2);
HXDLIN( 677)						_g2 = (_g2 + 1);
HXDLIN( 677)						action2->addGamepad(button,state2,id);
            					}
            				}
            			}
            			break;
            			case (int)3: {
HXDLIN( 677)				{
HXDLIN( 677)					 ::flixel::input::actions::FlxActionDigital action = this->_down;
HXDLIN( 677)					int state = 1;
HXDLIN( 677)					int _g = 0;
HXDLIN( 677)					while((_g < buttons->length)){
HXDLIN( 677)						int button = buttons->__get(_g);
HXDLIN( 677)						_g = (_g + 1);
HXDLIN( 677)						action->addGamepad(button,state,id);
            					}
            				}
HXDLIN( 677)				{
HXDLIN( 677)					 ::flixel::input::actions::FlxActionDigital action1 = this->_downP;
HXDLIN( 677)					int state1 = 2;
HXDLIN( 677)					int _g1 = 0;
HXDLIN( 677)					while((_g1 < buttons->length)){
HXDLIN( 677)						int button = buttons->__get(_g1);
HXDLIN( 677)						_g1 = (_g1 + 1);
HXDLIN( 677)						action1->addGamepad(button,state1,id);
            					}
            				}
HXDLIN( 677)				{
HXDLIN( 677)					 ::flixel::input::actions::FlxActionDigital action2 = this->_downR;
HXDLIN( 677)					int state2 = -1;
HXDLIN( 677)					int _g2 = 0;
HXDLIN( 677)					while((_g2 < buttons->length)){
HXDLIN( 677)						int button = buttons->__get(_g2);
HXDLIN( 677)						_g2 = (_g2 + 1);
HXDLIN( 677)						action2->addGamepad(button,state2,id);
            					}
            				}
            			}
            			break;
            			case (int)4: {
HXDLIN( 677)				{
HXDLIN( 677)					 ::flixel::input::actions::FlxActionDigital action = this->_space;
HXDLIN( 677)					int state = 1;
HXDLIN( 677)					int _g = 0;
HXDLIN( 677)					while((_g < buttons->length)){
HXDLIN( 677)						int button = buttons->__get(_g);
HXDLIN( 677)						_g = (_g + 1);
HXDLIN( 677)						action->addGamepad(button,state,id);
            					}
            				}
HXDLIN( 677)				{
HXDLIN( 677)					 ::flixel::input::actions::FlxActionDigital action1 = this->_spaceP;
HXDLIN( 677)					int state1 = 2;
HXDLIN( 677)					int _g1 = 0;
HXDLIN( 677)					while((_g1 < buttons->length)){
HXDLIN( 677)						int button = buttons->__get(_g1);
HXDLIN( 677)						_g1 = (_g1 + 1);
HXDLIN( 677)						action1->addGamepad(button,state1,id);
            					}
            				}
HXDLIN( 677)				{
HXDLIN( 677)					 ::flixel::input::actions::FlxActionDigital action2 = this->_spaceR;
HXDLIN( 677)					int state2 = -1;
HXDLIN( 677)					int _g2 = 0;
HXDLIN( 677)					while((_g2 < buttons->length)){
HXDLIN( 677)						int button = buttons->__get(_g2);
HXDLIN( 677)						_g2 = (_g2 + 1);
HXDLIN( 677)						action2->addGamepad(button,state2,id);
            					}
            				}
            			}
            			break;
            			case (int)5: {
HXDLIN( 677)				 ::flixel::input::actions::FlxActionDigital action = this->_reset;
HXDLIN( 677)				int state = 2;
HXDLIN( 677)				int _g = 0;
HXDLIN( 677)				while((_g < buttons->length)){
HXDLIN( 677)					int button = buttons->__get(_g);
HXDLIN( 677)					_g = (_g + 1);
HXDLIN( 677)					action->addGamepad(button,state,id);
            				}
            			}
            			break;
            			case (int)6: {
HXDLIN( 677)				 ::flixel::input::actions::FlxActionDigital action = this->_accept;
HXDLIN( 677)				int state = 2;
HXDLIN( 677)				int _g = 0;
HXDLIN( 677)				while((_g < buttons->length)){
HXDLIN( 677)					int button = buttons->__get(_g);
HXDLIN( 677)					_g = (_g + 1);
HXDLIN( 677)					action->addGamepad(button,state,id);
            				}
            			}
            			break;
            			case (int)7: {
HXDLIN( 677)				 ::flixel::input::actions::FlxActionDigital action = this->_back;
HXDLIN( 677)				int state = 2;
HXDLIN( 677)				int _g = 0;
HXDLIN( 677)				while((_g < buttons->length)){
HXDLIN( 677)					int button = buttons->__get(_g);
HXDLIN( 677)					_g = (_g + 1);
HXDLIN( 677)					action->addGamepad(button,state,id);
            				}
            			}
            			break;
            			case (int)8: {
HXDLIN( 677)				 ::flixel::input::actions::FlxActionDigital action = this->_pause;
HXDLIN( 677)				int state = 2;
HXDLIN( 677)				int _g = 0;
HXDLIN( 677)				while((_g < buttons->length)){
HXDLIN( 677)					int button = buttons->__get(_g);
HXDLIN( 677)					_g = (_g + 1);
HXDLIN( 677)					action->addGamepad(button,state,id);
            				}
            			}
            			break;
            			case (int)9: {
HXDLIN( 677)				 ::flixel::input::actions::FlxActionDigital action = this->_cheat;
HXDLIN( 677)				int state = 2;
HXDLIN( 677)				int _g = 0;
HXDLIN( 677)				while((_g < buttons->length)){
HXDLIN( 677)					int button = buttons->__get(_g);
HXDLIN( 677)					_g = (_g + 1);
HXDLIN( 677)					action->addGamepad(button,state,id);
            				}
            			}
            			break;
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC3(Controls_obj,bindButtons,(void))

void Controls_obj::unbindButtons( ::Control control,int gamepadID,::Array< int > buttons){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_690_unbindButtons)
HXDLIN( 690)		switch((int)(control->_hx_getIndex())){
            			case (int)0: {
HXDLIN( 690)				::Controls_obj::removeButtons(this->_up,gamepadID,buttons);
HXDLIN( 690)				::Controls_obj::removeButtons(this->_upP,gamepadID,buttons);
HXDLIN( 690)				::Controls_obj::removeButtons(this->_upR,gamepadID,buttons);
            			}
            			break;
            			case (int)1: {
HXDLIN( 690)				::Controls_obj::removeButtons(this->_left,gamepadID,buttons);
HXDLIN( 690)				::Controls_obj::removeButtons(this->_leftP,gamepadID,buttons);
HXDLIN( 690)				::Controls_obj::removeButtons(this->_leftR,gamepadID,buttons);
            			}
            			break;
            			case (int)2: {
HXDLIN( 690)				::Controls_obj::removeButtons(this->_right,gamepadID,buttons);
HXDLIN( 690)				::Controls_obj::removeButtons(this->_rightP,gamepadID,buttons);
HXDLIN( 690)				::Controls_obj::removeButtons(this->_rightR,gamepadID,buttons);
            			}
            			break;
            			case (int)3: {
HXDLIN( 690)				::Controls_obj::removeButtons(this->_down,gamepadID,buttons);
HXDLIN( 690)				::Controls_obj::removeButtons(this->_downP,gamepadID,buttons);
HXDLIN( 690)				::Controls_obj::removeButtons(this->_downR,gamepadID,buttons);
            			}
            			break;
            			case (int)4: {
HXDLIN( 690)				::Controls_obj::removeButtons(this->_space,gamepadID,buttons);
HXDLIN( 690)				::Controls_obj::removeButtons(this->_spaceP,gamepadID,buttons);
HXDLIN( 690)				::Controls_obj::removeButtons(this->_spaceR,gamepadID,buttons);
            			}
            			break;
            			case (int)5: {
HXDLIN( 690)				::Controls_obj::removeButtons(this->_reset,gamepadID,buttons);
            			}
            			break;
            			case (int)6: {
HXDLIN( 690)				::Controls_obj::removeButtons(this->_accept,gamepadID,buttons);
            			}
            			break;
            			case (int)7: {
HXDLIN( 690)				::Controls_obj::removeButtons(this->_back,gamepadID,buttons);
            			}
            			break;
            			case (int)8: {
HXDLIN( 690)				::Controls_obj::removeButtons(this->_pause,gamepadID,buttons);
            			}
            			break;
            			case (int)9: {
HXDLIN( 690)				::Controls_obj::removeButtons(this->_cheat,gamepadID,buttons);
            			}
            			break;
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC3(Controls_obj,unbindButtons,(void))

::Array< int > Controls_obj::getInputsFor( ::Control control, ::Device device,::Array< int > list){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_714_getInputsFor)
HXLINE( 715)		if (::hx::IsNull( list )) {
HXLINE( 716)			list = ::Array_obj< int >::__new(0);
            		}
HXLINE( 718)		switch((int)(device->_hx_getIndex())){
            			case (int)0: {
HXLINE( 721)				int _g = 0;
HXDLIN( 721)				::Array< ::Dynamic> _g1 = this->getActionFromControl(control)->inputs;
HXDLIN( 721)				while((_g < _g1->length)){
HXLINE( 721)					 ::flixel::input::actions::FlxActionInput input = _g1->__get(_g).StaticCast<  ::flixel::input::actions::FlxActionInput >();
HXDLIN( 721)					_g = (_g + 1);
HXLINE( 723)					if (::hx::IsPointerEq( input->device,::flixel::input::actions::FlxInputDevice_obj::KEYBOARD_dyn() )) {
HXLINE( 724)						list->push(input->inputID);
            					}
            				}
            			}
            			break;
            			case (int)1: {
HXLINE( 726)				int id = device->_hx_getInt(0);
HXLINE( 727)				{
HXLINE( 727)					int _g = 0;
HXDLIN( 727)					::Array< ::Dynamic> _g1 = this->getActionFromControl(control)->inputs;
HXDLIN( 727)					while((_g < _g1->length)){
HXLINE( 727)						 ::flixel::input::actions::FlxActionInput input = _g1->__get(_g).StaticCast<  ::flixel::input::actions::FlxActionInput >();
HXDLIN( 727)						_g = (_g + 1);
HXLINE( 729)						if ((input->deviceID == id)) {
HXLINE( 730)							list->push(input->inputID);
            						}
            					}
            				}
            			}
            			break;
            		}
HXLINE( 733)		return list;
            	}


HX_DEFINE_DYNAMIC_FUNC3(Controls_obj,getInputsFor,return )

void Controls_obj::removeDevice( ::Device device){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_738_removeDevice)
HXDLIN( 738)		switch((int)(device->_hx_getIndex())){
            			case (int)0: {
HXLINE( 741)				this->setKeyboardScheme(::KeyboardScheme_obj::None_dyn(),null());
            			}
            			break;
            			case (int)1: {
HXLINE( 742)				int id = device->_hx_getInt(0);
HXLINE( 743)				this->removeGamepad(id);
            			}
            			break;
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(Controls_obj,removeDevice,(void))

void Controls_obj::init(){
            	HX_GC_STACKFRAME(&_hx_pos_948b5caa279cd923_349_init)
HXLINE( 350)		 ::flixel::input::actions::FlxActionManager actions =  ::flixel::input::actions::FlxActionManager_obj::__alloc( HX_CTX );
HXLINE( 351)		::flixel::FlxG_obj::inputs->add_flixel_input_actions_FlxActionManager(actions);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Controls_obj,init,(void))

void Controls_obj::addKeys( ::flixel::input::actions::FlxActionDigital action,::Array< int > keys,int state){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_511_addKeys)
HXDLIN( 511)		int _g = 0;
HXDLIN( 511)		while((_g < keys->length)){
HXDLIN( 511)			int key = keys->__get(_g);
HXDLIN( 511)			_g = (_g + 1);
HXLINE( 512)			action->addKey(key,state);
            		}
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Controls_obj,addKeys,(void))

void Controls_obj::removeKeys( ::flixel::input::actions::FlxActionDigital action,::Array< int > keys){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_516_removeKeys)
HXLINE( 517)		int i = action->inputs->length;
HXLINE( 518)		while(true){
HXLINE( 518)			i = (i - 1);
HXDLIN( 518)			if (!(((i + 1) > 0))) {
HXLINE( 518)				goto _hx_goto_893;
            			}
HXLINE( 520)			 ::flixel::input::actions::FlxActionInput input = action->inputs->__get(i).StaticCast<  ::flixel::input::actions::FlxActionInput >();
HXLINE( 521)			bool _hx_tmp;
HXDLIN( 521)			if (::hx::IsPointerEq( input->device,::flixel::input::actions::FlxInputDevice_obj::KEYBOARD_dyn() )) {
HXLINE( 521)				_hx_tmp = (keys->indexOf(input->inputID,null()) != -1);
            			}
            			else {
HXLINE( 521)				_hx_tmp = false;
            			}
HXDLIN( 521)			if (_hx_tmp) {
HXLINE( 522)				action->remove(input,null());
            			}
            		}
            		_hx_goto_893:;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Controls_obj,removeKeys,(void))

void Controls_obj::addButtons( ::flixel::input::actions::FlxActionDigital action,::Array< int > buttons,int state,int id){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_698_addButtons)
HXDLIN( 698)		int _g = 0;
HXDLIN( 698)		while((_g < buttons->length)){
HXDLIN( 698)			int button = buttons->__get(_g);
HXDLIN( 698)			_g = (_g + 1);
HXLINE( 699)			action->addGamepad(button,state,id);
            		}
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Controls_obj,addButtons,(void))

void Controls_obj::removeButtons( ::flixel::input::actions::FlxActionDigital action,int gamepadID,::Array< int > buttons){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_703_removeButtons)
HXLINE( 704)		int i = action->inputs->length;
HXLINE( 705)		while(true){
HXLINE( 705)			i = (i - 1);
HXDLIN( 705)			if (!(((i + 1) > 0))) {
HXLINE( 705)				goto _hx_goto_897;
            			}
HXLINE( 707)			 ::flixel::input::actions::FlxActionInput input = action->inputs->__get(i).StaticCast<  ::flixel::input::actions::FlxActionInput >();
HXLINE( 708)			bool _hx_tmp;
HXDLIN( 708)			bool _hx_tmp1;
HXDLIN( 708)			if (::hx::IsPointerEq( input->device,::flixel::input::actions::FlxInputDevice_obj::GAMEPAD_dyn() )) {
HXLINE( 708)				if ((gamepadID != -1)) {
HXLINE( 708)					_hx_tmp1 = (input->deviceID == gamepadID);
            				}
            				else {
HXLINE( 708)					_hx_tmp1 = true;
            				}
            			}
            			else {
HXLINE( 708)				_hx_tmp1 = false;
            			}
HXDLIN( 708)			if (_hx_tmp1) {
HXLINE( 708)				_hx_tmp = (buttons->indexOf(input->inputID,null()) != -1);
            			}
            			else {
HXLINE( 708)				_hx_tmp = false;
            			}
HXDLIN( 708)			if (_hx_tmp) {
HXLINE( 709)				action->remove(input,null());
            			}
            		}
            		_hx_goto_897:;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Controls_obj,removeButtons,(void))

bool Controls_obj::isDevice( ::flixel::input::actions::FlxActionInput input, ::Device device){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_749_isDevice)
HXDLIN( 749)		switch((int)(device->_hx_getIndex())){
            			case (int)0: {
HXLINE( 751)				return ::hx::IsPointerEq( input->device,::flixel::input::actions::FlxInputDevice_obj::KEYBOARD_dyn() );
            			}
            			break;
            			case (int)1: {
HXLINE( 752)				int id = device->_hx_getInt(0);
HXDLIN( 752)				if (::hx::IsPointerEq( input->device,::flixel::input::actions::FlxInputDevice_obj::GAMEPAD_dyn() )) {
HXLINE( 752)					if ((id != -1)) {
HXLINE( 752)						return (input->deviceID == id);
            					}
            					else {
HXLINE( 752)						return true;
            					}
            				}
            				else {
HXLINE( 752)					return false;
            				}
            			}
            			break;
            		}
HXLINE( 749)		return false;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Controls_obj,isDevice,return )

bool Controls_obj::isGamepad( ::flixel::input::actions::FlxActionInput input,int deviceID){
            	HX_STACKFRAME(&_hx_pos_948b5caa279cd923_758_isGamepad)
HXDLIN( 758)		if (::hx::IsPointerEq( input->device,::flixel::input::actions::FlxInputDevice_obj::GAMEPAD_dyn() )) {
HXDLIN( 758)			if ((deviceID != -1)) {
HXDLIN( 758)				return (input->deviceID == deviceID);
            			}
            			else {
HXDLIN( 758)				return true;
            			}
            		}
            		else {
HXDLIN( 758)			return false;
            		}
HXDLIN( 758)		return false;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Controls_obj,isGamepad,return )


::hx::ObjectPtr< Controls_obj > Controls_obj::__new(::String name, ::KeyboardScheme __o_scheme) {
	::hx::ObjectPtr< Controls_obj > __this = new Controls_obj();
	__this->__construct(name,__o_scheme);
	return __this;
}

::hx::ObjectPtr< Controls_obj > Controls_obj::__alloc(::hx::Ctx *_hx_ctx,::String name, ::KeyboardScheme __o_scheme) {
	Controls_obj *__this = (Controls_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Controls_obj), true, "Controls"));
	*(void **)__this = Controls_obj::_hx_vtable;
	__this->__construct(name,__o_scheme);
	return __this;
}

Controls_obj::Controls_obj()
{
}

void Controls_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Controls);
	HX_MARK_MEMBER_NAME(_up,"_up");
	HX_MARK_MEMBER_NAME(_left,"_left");
	HX_MARK_MEMBER_NAME(_right,"_right");
	HX_MARK_MEMBER_NAME(_down,"_down");
	HX_MARK_MEMBER_NAME(_space,"_space");
	HX_MARK_MEMBER_NAME(_upP,"_upP");
	HX_MARK_MEMBER_NAME(_leftP,"_leftP");
	HX_MARK_MEMBER_NAME(_rightP,"_rightP");
	HX_MARK_MEMBER_NAME(_downP,"_downP");
	HX_MARK_MEMBER_NAME(_spaceP,"_spaceP");
	HX_MARK_MEMBER_NAME(_upR,"_upR");
	HX_MARK_MEMBER_NAME(_leftR,"_leftR");
	HX_MARK_MEMBER_NAME(_rightR,"_rightR");
	HX_MARK_MEMBER_NAME(_downR,"_downR");
	HX_MARK_MEMBER_NAME(_spaceR,"_spaceR");
	HX_MARK_MEMBER_NAME(_accept,"_accept");
	HX_MARK_MEMBER_NAME(_back,"_back");
	HX_MARK_MEMBER_NAME(_pause,"_pause");
	HX_MARK_MEMBER_NAME(_reset,"_reset");
	HX_MARK_MEMBER_NAME(_cheat,"_cheat");
	HX_MARK_MEMBER_NAME(byName,"byName");
	HX_MARK_MEMBER_NAME(gamepadsAdded,"gamepadsAdded");
	HX_MARK_MEMBER_NAME(keyboardScheme,"keyboardScheme");
	 ::flixel::input::actions::FlxActionSet_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Controls_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_up,"_up");
	HX_VISIT_MEMBER_NAME(_left,"_left");
	HX_VISIT_MEMBER_NAME(_right,"_right");
	HX_VISIT_MEMBER_NAME(_down,"_down");
	HX_VISIT_MEMBER_NAME(_space,"_space");
	HX_VISIT_MEMBER_NAME(_upP,"_upP");
	HX_VISIT_MEMBER_NAME(_leftP,"_leftP");
	HX_VISIT_MEMBER_NAME(_rightP,"_rightP");
	HX_VISIT_MEMBER_NAME(_downP,"_downP");
	HX_VISIT_MEMBER_NAME(_spaceP,"_spaceP");
	HX_VISIT_MEMBER_NAME(_upR,"_upR");
	HX_VISIT_MEMBER_NAME(_leftR,"_leftR");
	HX_VISIT_MEMBER_NAME(_rightR,"_rightR");
	HX_VISIT_MEMBER_NAME(_downR,"_downR");
	HX_VISIT_MEMBER_NAME(_spaceR,"_spaceR");
	HX_VISIT_MEMBER_NAME(_accept,"_accept");
	HX_VISIT_MEMBER_NAME(_back,"_back");
	HX_VISIT_MEMBER_NAME(_pause,"_pause");
	HX_VISIT_MEMBER_NAME(_reset,"_reset");
	HX_VISIT_MEMBER_NAME(_cheat,"_cheat");
	HX_VISIT_MEMBER_NAME(byName,"byName");
	HX_VISIT_MEMBER_NAME(gamepadsAdded,"gamepadsAdded");
	HX_VISIT_MEMBER_NAME(keyboardScheme,"keyboardScheme");
	 ::flixel::input::actions::FlxActionSet_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val Controls_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"UP") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_UP() ); }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"_up") ) { return ::hx::Val( _up ); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_upP") ) { return ::hx::Val( _upP ); }
		if (HX_FIELD_EQ(inName,"_upR") ) { return ::hx::Val( _upR ); }
		if (HX_FIELD_EQ(inName,"LEFT") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_LEFT() ); }
		if (HX_FIELD_EQ(inName,"DOWN") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_DOWN() ); }
		if (HX_FIELD_EQ(inName,"UP_P") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_UP_P() ); }
		if (HX_FIELD_EQ(inName,"UP_R") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_UP_R() ); }
		if (HX_FIELD_EQ(inName,"BACK") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_BACK() ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_left") ) { return ::hx::Val( _left ); }
		if (HX_FIELD_EQ(inName,"_down") ) { return ::hx::Val( _down ); }
		if (HX_FIELD_EQ(inName,"_back") ) { return ::hx::Val( _back ); }
		if (HX_FIELD_EQ(inName,"RIGHT") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_RIGHT() ); }
		if (HX_FIELD_EQ(inName,"SPACE") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_SPACE() ); }
		if (HX_FIELD_EQ(inName,"PAUSE") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_PAUSE() ); }
		if (HX_FIELD_EQ(inName,"RESET") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_RESET() ); }
		if (HX_FIELD_EQ(inName,"CHEAT") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_CHEAT() ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_right") ) { return ::hx::Val( _right ); }
		if (HX_FIELD_EQ(inName,"_space") ) { return ::hx::Val( _space ); }
		if (HX_FIELD_EQ(inName,"_leftP") ) { return ::hx::Val( _leftP ); }
		if (HX_FIELD_EQ(inName,"_downP") ) { return ::hx::Val( _downP ); }
		if (HX_FIELD_EQ(inName,"_leftR") ) { return ::hx::Val( _leftR ); }
		if (HX_FIELD_EQ(inName,"_downR") ) { return ::hx::Val( _downR ); }
		if (HX_FIELD_EQ(inName,"_pause") ) { return ::hx::Val( _pause ); }
		if (HX_FIELD_EQ(inName,"_reset") ) { return ::hx::Val( _reset ); }
		if (HX_FIELD_EQ(inName,"_cheat") ) { return ::hx::Val( _cheat ); }
		if (HX_FIELD_EQ(inName,"byName") ) { return ::hx::Val( byName ); }
		if (HX_FIELD_EQ(inName,"get_UP") ) { return ::hx::Val( get_UP_dyn() ); }
		if (HX_FIELD_EQ(inName,"LEFT_P") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_LEFT_P() ); }
		if (HX_FIELD_EQ(inName,"DOWN_P") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_DOWN_P() ); }
		if (HX_FIELD_EQ(inName,"LEFT_R") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_LEFT_R() ); }
		if (HX_FIELD_EQ(inName,"DOWN_R") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_DOWN_R() ); }
		if (HX_FIELD_EQ(inName,"ACCEPT") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_ACCEPT() ); }
		if (HX_FIELD_EQ(inName,"update") ) { return ::hx::Val( update_dyn() ); }
		if (HX_FIELD_EQ(inName,"copyTo") ) { return ::hx::Val( copyTo_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_rightP") ) { return ::hx::Val( _rightP ); }
		if (HX_FIELD_EQ(inName,"_spaceP") ) { return ::hx::Val( _spaceP ); }
		if (HX_FIELD_EQ(inName,"_rightR") ) { return ::hx::Val( _rightR ); }
		if (HX_FIELD_EQ(inName,"_spaceR") ) { return ::hx::Val( _spaceR ); }
		if (HX_FIELD_EQ(inName,"_accept") ) { return ::hx::Val( _accept ); }
		if (HX_FIELD_EQ(inName,"SPACE_P") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_SPACE_P() ); }
		if (HX_FIELD_EQ(inName,"RIGHT_P") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_RIGHT_P() ); }
		if (HX_FIELD_EQ(inName,"RIGHT_R") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_RIGHT_R() ); }
		if (HX_FIELD_EQ(inName,"SPACE_R") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_SPACE_R() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_LEFT") ) { return ::hx::Val( get_LEFT_dyn() ); }
		if (HX_FIELD_EQ(inName,"get_DOWN") ) { return ::hx::Val( get_DOWN_dyn() ); }
		if (HX_FIELD_EQ(inName,"get_UP_P") ) { return ::hx::Val( get_UP_P_dyn() ); }
		if (HX_FIELD_EQ(inName,"get_UP_R") ) { return ::hx::Val( get_UP_R_dyn() ); }
		if (HX_FIELD_EQ(inName,"get_BACK") ) { return ::hx::Val( get_BACK_dyn() ); }
		if (HX_FIELD_EQ(inName,"copyFrom") ) { return ::hx::Val( copyFrom_dyn() ); }
		if (HX_FIELD_EQ(inName,"bindKeys") ) { return ::hx::Val( bindKeys_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_RIGHT") ) { return ::hx::Val( get_RIGHT_dyn() ); }
		if (HX_FIELD_EQ(inName,"get_SPACE") ) { return ::hx::Val( get_SPACE_dyn() ); }
		if (HX_FIELD_EQ(inName,"get_PAUSE") ) { return ::hx::Val( get_PAUSE_dyn() ); }
		if (HX_FIELD_EQ(inName,"get_RESET") ) { return ::hx::Val( get_RESET_dyn() ); }
		if (HX_FIELD_EQ(inName,"get_CHEAT") ) { return ::hx::Val( get_CHEAT_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_LEFT_P") ) { return ::hx::Val( get_LEFT_P_dyn() ); }
		if (HX_FIELD_EQ(inName,"get_DOWN_P") ) { return ::hx::Val( get_DOWN_P_dyn() ); }
		if (HX_FIELD_EQ(inName,"get_LEFT_R") ) { return ::hx::Val( get_LEFT_R_dyn() ); }
		if (HX_FIELD_EQ(inName,"get_DOWN_R") ) { return ::hx::Val( get_DOWN_R_dyn() ); }
		if (HX_FIELD_EQ(inName,"get_ACCEPT") ) { return ::hx::Val( get_ACCEPT_dyn() ); }
		if (HX_FIELD_EQ(inName,"unbindKeys") ) { return ::hx::Val( unbindKeys_dyn() ); }
		if (HX_FIELD_EQ(inName,"addGamepad") ) { return ::hx::Val( addGamepad_dyn() ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_SPACE_P") ) { return ::hx::Val( get_SPACE_P_dyn() ); }
		if (HX_FIELD_EQ(inName,"get_RIGHT_P") ) { return ::hx::Val( get_RIGHT_P_dyn() ); }
		if (HX_FIELD_EQ(inName,"get_RIGHT_R") ) { return ::hx::Val( get_RIGHT_R_dyn() ); }
		if (HX_FIELD_EQ(inName,"get_SPACE_R") ) { return ::hx::Val( get_SPACE_R_dyn() ); }
		if (HX_FIELD_EQ(inName,"checkByName") ) { return ::hx::Val( checkByName_dyn() ); }
		if (HX_FIELD_EQ(inName,"bindButtons") ) { return ::hx::Val( bindButtons_dyn() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"forEachBound") ) { return ::hx::Val( forEachBound_dyn() ); }
		if (HX_FIELD_EQ(inName,"getInputsFor") ) { return ::hx::Val( getInputsFor_dyn() ); }
		if (HX_FIELD_EQ(inName,"removeDevice") ) { return ::hx::Val( removeDevice_dyn() ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"gamepadsAdded") ) { return ::hx::Val( gamepadsAdded ); }
		if (HX_FIELD_EQ(inName,"removeGamepad") ) { return ::hx::Val( removeGamepad_dyn() ); }
		if (HX_FIELD_EQ(inName,"unbindButtons") ) { return ::hx::Val( unbindButtons_dyn() ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"keyboardScheme") ) { return ::hx::Val( keyboardScheme ); }
		if (HX_FIELD_EQ(inName,"replaceBinding") ) { return ::hx::Val( replaceBinding_dyn() ); }
		if (HX_FIELD_EQ(inName,"removeKeyboard") ) { return ::hx::Val( removeKeyboard_dyn() ); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"getDialogueName") ) { return ::hx::Val( getDialogueName_dyn() ); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"setKeyboardScheme") ) { return ::hx::Val( setKeyboardScheme_dyn() ); }
		if (HX_FIELD_EQ(inName,"addGamepadLiteral") ) { return ::hx::Val( addGamepadLiteral_dyn() ); }
		if (HX_FIELD_EQ(inName,"addDefaultGamepad") ) { return ::hx::Val( addDefaultGamepad_dyn() ); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"mergeKeyboardScheme") ) { return ::hx::Val( mergeKeyboardScheme_dyn() ); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"getActionFromControl") ) { return ::hx::Val( getActionFromControl_dyn() ); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"getDialogueNameFromToken") ) { return ::hx::Val( getDialogueNameFromToken_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

bool Controls_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { outValue = init_dyn(); return true; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"addKeys") ) { outValue = addKeys_dyn(); return true; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"isDevice") ) { outValue = isDevice_dyn(); return true; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"isGamepad") ) { outValue = isGamepad_dyn(); return true; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"removeKeys") ) { outValue = removeKeys_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"addButtons") ) { outValue = addButtons_dyn(); return true; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"removeButtons") ) { outValue = removeButtons_dyn(); return true; }
	}
	return false;
}

::hx::Val Controls_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_up") ) { _up=inValue.Cast<  ::flixel::input::actions::FlxActionDigital >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_upP") ) { _upP=inValue.Cast<  ::flixel::input::actions::FlxActionDigital >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_upR") ) { _upR=inValue.Cast<  ::flixel::input::actions::FlxActionDigital >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_left") ) { _left=inValue.Cast<  ::flixel::input::actions::FlxActionDigital >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_down") ) { _down=inValue.Cast<  ::flixel::input::actions::FlxActionDigital >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_back") ) { _back=inValue.Cast<  ::flixel::input::actions::FlxActionDigital >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_right") ) { _right=inValue.Cast<  ::flixel::input::actions::FlxActionDigital >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_space") ) { _space=inValue.Cast<  ::flixel::input::actions::FlxActionDigital >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_leftP") ) { _leftP=inValue.Cast<  ::flixel::input::actions::FlxActionDigital >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_downP") ) { _downP=inValue.Cast<  ::flixel::input::actions::FlxActionDigital >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_leftR") ) { _leftR=inValue.Cast<  ::flixel::input::actions::FlxActionDigital >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_downR") ) { _downR=inValue.Cast<  ::flixel::input::actions::FlxActionDigital >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_pause") ) { _pause=inValue.Cast<  ::flixel::input::actions::FlxActionDigital >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_reset") ) { _reset=inValue.Cast<  ::flixel::input::actions::FlxActionDigital >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_cheat") ) { _cheat=inValue.Cast<  ::flixel::input::actions::FlxActionDigital >(); return inValue; }
		if (HX_FIELD_EQ(inName,"byName") ) { byName=inValue.Cast<  ::haxe::ds::StringMap >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_rightP") ) { _rightP=inValue.Cast<  ::flixel::input::actions::FlxActionDigital >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_spaceP") ) { _spaceP=inValue.Cast<  ::flixel::input::actions::FlxActionDigital >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_rightR") ) { _rightR=inValue.Cast<  ::flixel::input::actions::FlxActionDigital >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_spaceR") ) { _spaceR=inValue.Cast<  ::flixel::input::actions::FlxActionDigital >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_accept") ) { _accept=inValue.Cast<  ::flixel::input::actions::FlxActionDigital >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"gamepadsAdded") ) { gamepadsAdded=inValue.Cast< ::Array< int > >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"keyboardScheme") ) { keyboardScheme=inValue.Cast<  ::KeyboardScheme >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Controls_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("_up",7a,7c,48,00));
	outFields->push(HX_("_left",e6,23,c1,fa));
	outFields->push(HX_("_right",1d,53,4b,e5));
	outFields->push(HX_("_down",41,14,7f,f5));
	outFields->push(HX_("_space",07,d4,4d,7d));
	outFields->push(HX_("_upP",96,6e,24,3f));
	outFields->push(HX_("_leftP",aa,45,3e,6e));
	outFields->push(HX_("_rightP",93,66,9d,bc));
	outFields->push(HX_("_downP",ef,a4,b2,d9));
	outFields->push(HX_("_spaceP",69,b2,cb,26));
	outFields->push(HX_("_upR",98,6e,24,3f));
	outFields->push(HX_("_leftR",ac,45,3e,6e));
	outFields->push(HX_("_rightR",95,66,9d,bc));
	outFields->push(HX_("_downR",f1,a4,b2,d9));
	outFields->push(HX_("_spaceR",6b,b2,cb,26));
	outFields->push(HX_("_accept",a7,a4,7d,79));
	outFields->push(HX_("_back",06,f6,21,f4));
	outFields->push(HX_("_pause",37,1e,3f,b9));
	outFields->push(HX_("_reset",10,91,af,e2));
	outFields->push(HX_("_cheat",54,de,9d,41));
	outFields->push(HX_("byName",c2,2b,4e,0e));
	outFields->push(HX_("gamepadsAdded",ae,52,a9,94));
	outFields->push(HX_("keyboardScheme",2c,c8,f4,c5));
	outFields->push(HX_("UP",5b,4a,00,00));
	outFields->push(HX_("LEFT",07,d0,70,32));
	outFields->push(HX_("RIGHT",bc,43,52,67));
	outFields->push(HX_("DOWN",62,c0,2e,2d));
	outFields->push(HX_("SPACE",a6,c4,54,ff));
	outFields->push(HX_("SPACE_P",37,0d,8c,11));
	outFields->push(HX_("UP_P",2c,2a,6c,38));
	outFields->push(HX_("LEFT_P",d8,72,4a,4c));
	outFields->push(HX_("RIGHT_P",cd,fd,37,93));
	outFields->push(HX_("DOWN_P",f3,6f,a9,e6));
	outFields->push(HX_("UP_R",2e,2a,6c,38));
	outFields->push(HX_("LEFT_R",da,72,4a,4c));
	outFields->push(HX_("RIGHT_R",cf,fd,37,93));
	outFields->push(HX_("DOWN_R",f5,6f,a9,e6));
	outFields->push(HX_("SPACE_R",39,0d,8c,11));
	outFields->push(HX_("ACCEPT",08,3f,89,bd));
	outFields->push(HX_("BACK",27,a2,d1,2b));
	outFields->push(HX_("PAUSE",d6,0e,46,3b));
	outFields->push(HX_("RESET",af,81,b6,64));
	outFields->push(HX_("CHEAT",f3,ce,a4,c3));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Controls_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::flixel::input::actions::FlxActionDigital */ ,(int)offsetof(Controls_obj,_up),HX_("_up",7a,7c,48,00)},
	{::hx::fsObject /*  ::flixel::input::actions::FlxActionDigital */ ,(int)offsetof(Controls_obj,_left),HX_("_left",e6,23,c1,fa)},
	{::hx::fsObject /*  ::flixel::input::actions::FlxActionDigital */ ,(int)offsetof(Controls_obj,_right),HX_("_right",1d,53,4b,e5)},
	{::hx::fsObject /*  ::flixel::input::actions::FlxActionDigital */ ,(int)offsetof(Controls_obj,_down),HX_("_down",41,14,7f,f5)},
	{::hx::fsObject /*  ::flixel::input::actions::FlxActionDigital */ ,(int)offsetof(Controls_obj,_space),HX_("_space",07,d4,4d,7d)},
	{::hx::fsObject /*  ::flixel::input::actions::FlxActionDigital */ ,(int)offsetof(Controls_obj,_upP),HX_("_upP",96,6e,24,3f)},
	{::hx::fsObject /*  ::flixel::input::actions::FlxActionDigital */ ,(int)offsetof(Controls_obj,_leftP),HX_("_leftP",aa,45,3e,6e)},
	{::hx::fsObject /*  ::flixel::input::actions::FlxActionDigital */ ,(int)offsetof(Controls_obj,_rightP),HX_("_rightP",93,66,9d,bc)},
	{::hx::fsObject /*  ::flixel::input::actions::FlxActionDigital */ ,(int)offsetof(Controls_obj,_downP),HX_("_downP",ef,a4,b2,d9)},
	{::hx::fsObject /*  ::flixel::input::actions::FlxActionDigital */ ,(int)offsetof(Controls_obj,_spaceP),HX_("_spaceP",69,b2,cb,26)},
	{::hx::fsObject /*  ::flixel::input::actions::FlxActionDigital */ ,(int)offsetof(Controls_obj,_upR),HX_("_upR",98,6e,24,3f)},
	{::hx::fsObject /*  ::flixel::input::actions::FlxActionDigital */ ,(int)offsetof(Controls_obj,_leftR),HX_("_leftR",ac,45,3e,6e)},
	{::hx::fsObject /*  ::flixel::input::actions::FlxActionDigital */ ,(int)offsetof(Controls_obj,_rightR),HX_("_rightR",95,66,9d,bc)},
	{::hx::fsObject /*  ::flixel::input::actions::FlxActionDigital */ ,(int)offsetof(Controls_obj,_downR),HX_("_downR",f1,a4,b2,d9)},
	{::hx::fsObject /*  ::flixel::input::actions::FlxActionDigital */ ,(int)offsetof(Controls_obj,_spaceR),HX_("_spaceR",6b,b2,cb,26)},
	{::hx::fsObject /*  ::flixel::input::actions::FlxActionDigital */ ,(int)offsetof(Controls_obj,_accept),HX_("_accept",a7,a4,7d,79)},
	{::hx::fsObject /*  ::flixel::input::actions::FlxActionDigital */ ,(int)offsetof(Controls_obj,_back),HX_("_back",06,f6,21,f4)},
	{::hx::fsObject /*  ::flixel::input::actions::FlxActionDigital */ ,(int)offsetof(Controls_obj,_pause),HX_("_pause",37,1e,3f,b9)},
	{::hx::fsObject /*  ::flixel::input::actions::FlxActionDigital */ ,(int)offsetof(Controls_obj,_reset),HX_("_reset",10,91,af,e2)},
	{::hx::fsObject /*  ::flixel::input::actions::FlxActionDigital */ ,(int)offsetof(Controls_obj,_cheat),HX_("_cheat",54,de,9d,41)},
	{::hx::fsObject /*  ::haxe::ds::StringMap */ ,(int)offsetof(Controls_obj,byName),HX_("byName",c2,2b,4e,0e)},
	{::hx::fsObject /* ::Array< int > */ ,(int)offsetof(Controls_obj,gamepadsAdded),HX_("gamepadsAdded",ae,52,a9,94)},
	{::hx::fsObject /*  ::KeyboardScheme */ ,(int)offsetof(Controls_obj,keyboardScheme),HX_("keyboardScheme",2c,c8,f4,c5)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *Controls_obj_sStaticStorageInfo = 0;
#endif

static ::String Controls_obj_sMemberFields[] = {
	HX_("_up",7a,7c,48,00),
	HX_("_left",e6,23,c1,fa),
	HX_("_right",1d,53,4b,e5),
	HX_("_down",41,14,7f,f5),
	HX_("_space",07,d4,4d,7d),
	HX_("_upP",96,6e,24,3f),
	HX_("_leftP",aa,45,3e,6e),
	HX_("_rightP",93,66,9d,bc),
	HX_("_downP",ef,a4,b2,d9),
	HX_("_spaceP",69,b2,cb,26),
	HX_("_upR",98,6e,24,3f),
	HX_("_leftR",ac,45,3e,6e),
	HX_("_rightR",95,66,9d,bc),
	HX_("_downR",f1,a4,b2,d9),
	HX_("_spaceR",6b,b2,cb,26),
	HX_("_accept",a7,a4,7d,79),
	HX_("_back",06,f6,21,f4),
	HX_("_pause",37,1e,3f,b9),
	HX_("_reset",10,91,af,e2),
	HX_("_cheat",54,de,9d,41),
	HX_("byName",c2,2b,4e,0e),
	HX_("gamepadsAdded",ae,52,a9,94),
	HX_("keyboardScheme",2c,c8,f4,c5),
	HX_("get_UP",a4,e1,2f,a3),
	HX_("get_LEFT",90,8b,2b,b2),
	HX_("get_RIGHT",13,a0,fb,aa),
	HX_("get_DOWN",eb,7b,e9,ac),
	HX_("get_SPACE",fd,20,fe,42),
	HX_("get_SPACE_P",4e,6d,86,97),
	HX_("get_UP_P",b5,e5,26,b8),
	HX_("get_LEFT_P",a1,e2,d1,3c),
	HX_("get_RIGHT_P",e4,5d,32,19),
	HX_("get_DOWN_P",bc,df,30,d7),
	HX_("get_UP_R",b7,e5,26,b8),
	HX_("get_LEFT_R",a3,e2,d1,3c),
	HX_("get_RIGHT_R",e6,5d,32,19),
	HX_("get_DOWN_R",be,df,30,d7),
	HX_("get_SPACE_R",50,6d,86,97),
	HX_("get_ACCEPT",d1,ae,10,ae),
	HX_("get_BACK",b0,5d,8c,ab),
	HX_("get_PAUSE",2d,6b,ef,7e),
	HX_("get_RESET",06,de,5f,a8),
	HX_("get_CHEAT",4a,2b,4e,07),
	HX_("update",09,86,05,87),
	HX_("checkByName",aa,fe,5f,f0),
	HX_("getDialogueName",39,8d,0f,32),
	HX_("getDialogueNameFromToken",b6,d0,32,d3),
	HX_("getActionFromControl",87,31,3f,3d),
	HX_("forEachBound",34,ae,22,2f),
	HX_("replaceBinding",71,99,ae,a4),
	HX_("copyFrom",bf,0b,61,c8),
	HX_("copyTo",90,1c,33,c9),
	HX_("mergeKeyboardScheme",04,51,83,14),
	HX_("bindKeys",51,26,d1,b4),
	HX_("unbindKeys",aa,0d,95,3a),
	HX_("setKeyboardScheme",6e,4f,d6,5b),
	HX_("removeKeyboard",0b,f9,7f,32),
	HX_("addGamepad",80,0c,10,f1),
	HX_("addGamepadLiteral",cf,54,ef,a8),
	HX_("removeGamepad",bd,3c,40,62),
	HX_("addDefaultGamepad",e1,d7,98,02),
	HX_("bindButtons",04,66,e6,c6),
	HX_("unbindButtons",4b,dc,20,e8),
	HX_("getInputsFor",ea,35,e1,37),
	HX_("removeDevice",fa,77,a5,e0),
	::String(null()) };

::hx::Class Controls_obj::__mClass;

static ::String Controls_obj_sStaticFields[] = {
	HX_("init",10,3b,bb,45),
	HX_("addKeys",b5,24,44,83),
	HX_("removeKeys",58,1c,26,c4),
	HX_("addButtons",20,7e,ff,31),
	HX_("removeButtons",5d,ae,2f,a3),
	HX_("isDevice",20,78,e1,c9),
	HX_("isGamepad",d7,5d,84,8d),
	::String(null())
};

void Controls_obj::__register()
{
	Controls_obj _hx_dummy;
	Controls_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("Controls",96,42,6e,11);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Controls_obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(Controls_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Controls_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Controls_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Controls_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Controls_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

