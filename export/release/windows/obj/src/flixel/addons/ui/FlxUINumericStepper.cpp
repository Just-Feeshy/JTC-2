#include <hxcpp.h>

#ifndef INCLUDED_95f339a1d026d52c
#define INCLUDED_95f339a1d026d52c
#include "hxMath.h"
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxObject
#include <flixel/FlxObject.h>
#endif
#ifndef INCLUDED_flixel_FlxSprite
#include <flixel/FlxSprite.h>
#endif
#ifndef INCLUDED_flixel_IFlxBasic
#include <flixel/IFlxBasic.h>
#endif
#ifndef INCLUDED_flixel_IFlxSprite
#include <flixel/IFlxSprite.h>
#endif
#ifndef INCLUDED_flixel_addons_ui_FlxInputText
#include <flixel/addons/ui/FlxInputText.h>
#endif
#ifndef INCLUDED_flixel_addons_ui_FlxUI
#include <flixel/addons/ui/FlxUI.h>
#endif
#ifndef INCLUDED_flixel_addons_ui_FlxUIGroup
#include <flixel/addons/ui/FlxUIGroup.h>
#endif
#ifndef INCLUDED_flixel_addons_ui_FlxUIInputText
#include <flixel/addons/ui/FlxUIInputText.h>
#endif
#ifndef INCLUDED_flixel_addons_ui_FlxUINumericStepper
#include <flixel/addons/ui/FlxUINumericStepper.h>
#endif
#ifndef INCLUDED_flixel_addons_ui_FlxUITypedButton
#include <flixel/addons/ui/FlxUITypedButton.h>
#endif
#ifndef INCLUDED_flixel_addons_ui_interfaces_ICursorPointable
#include <flixel/addons/ui/interfaces/ICursorPointable.h>
#endif
#ifndef INCLUDED_flixel_addons_ui_interfaces_IEventGetter
#include <flixel/addons/ui/interfaces/IEventGetter.h>
#endif
#ifndef INCLUDED_flixel_addons_ui_interfaces_IFlxUIButton
#include <flixel/addons/ui/interfaces/IFlxUIButton.h>
#endif
#ifndef INCLUDED_flixel_addons_ui_interfaces_IFlxUIClickable
#include <flixel/addons/ui/interfaces/IFlxUIClickable.h>
#endif
#ifndef INCLUDED_flixel_addons_ui_interfaces_IFlxUIWidget
#include <flixel/addons/ui/interfaces/IFlxUIWidget.h>
#endif
#ifndef INCLUDED_flixel_addons_ui_interfaces_IHasParams
#include <flixel/addons/ui/interfaces/IHasParams.h>
#endif
#ifndef INCLUDED_flixel_addons_ui_interfaces_IResizable
#include <flixel/addons/ui/interfaces/IResizable.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedSpriteGroup
#include <flixel/group/FlxTypedSpriteGroup.h>
#endif
#ifndef INCLUDED_flixel_input_IFlxInput
#include <flixel/input/IFlxInput.h>
#endif
#ifndef INCLUDED_flixel_text_FlxText
#include <flixel/text/FlxText.h>
#endif
#ifndef INCLUDED_flixel_ui_FlxTypedButton
#include <flixel/ui/FlxTypedButton.h>
#endif
#ifndef INCLUDED_flixel_ui__FlxButton_FlxButtonEvent
#include <flixel/ui/_FlxButton/FlxButtonEvent.h>
#endif
#ifndef INCLUDED_flixel_util_FlxStringUtil
#include <flixel/util/FlxStringUtil.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxDestroyable
#include <flixel/util/IFlxDestroyable.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_b3434b006136ea9e_13_new,"flixel.addons.ui.FlxUINumericStepper","new",0xdb22a66b,"flixel.addons.ui.FlxUINumericStepper.new","flixel/addons/ui/FlxUINumericStepper.hx",13,0xbef22206)
HX_LOCAL_STACK_FRAME(_hx_pos_b3434b006136ea9e_37_set_params,"flixel.addons.ui.FlxUINumericStepper","set_params",0xbd02dad8,"flixel.addons.ui.FlxUINumericStepper.set_params","flixel/addons/ui/FlxUINumericStepper.hx",37,0xbef22206)
HX_LOCAL_STACK_FRAME(_hx_pos_b3434b006136ea9e_45_set_skipButtonUpdate,"flixel.addons.ui.FlxUINumericStepper","set_skipButtonUpdate",0x707fcccc,"flixel.addons.ui.FlxUINumericStepper.set_skipButtonUpdate","flixel/addons/ui/FlxUINumericStepper.hx",45,0xbef22206)
HX_LOCAL_STACK_FRAME(_hx_pos_b3434b006136ea9e_54_set_color,"flixel.addons.ui.FlxUINumericStepper","set_color",0x15562a11,"flixel.addons.ui.FlxUINumericStepper.set_color","flixel/addons/ui/FlxUINumericStepper.hx",54,0xbef22206)
HX_LOCAL_STACK_FRAME(_hx_pos_b3434b006136ea9e_71_set_min,"flixel.addons.ui.FlxUINumericStepper","set_min",0x8923a2c0,"flixel.addons.ui.FlxUINumericStepper.set_min","flixel/addons/ui/FlxUINumericStepper.hx",71,0xbef22206)
HX_LOCAL_STACK_FRAME(_hx_pos_b3434b006136ea9e_81_set_max,"flixel.addons.ui.FlxUINumericStepper","set_max",0x89239bd2,"flixel.addons.ui.FlxUINumericStepper.set_max","flixel/addons/ui/FlxUINumericStepper.hx",81,0xbef22206)
HX_LOCAL_STACK_FRAME(_hx_pos_b3434b006136ea9e_91_set_value,"flixel.addons.ui.FlxUINumericStepper","set_value",0xfcb2381f,"flixel.addons.ui.FlxUINumericStepper.set_value","flixel/addons/ui/FlxUINumericStepper.hx",91,0xbef22206)
HX_LOCAL_STACK_FRAME(_hx_pos_b3434b006136ea9e_123_set_decimals,"flixel.addons.ui.FlxUINumericStepper","set_decimals",0xbb56b2d4,"flixel.addons.ui.FlxUINumericStepper.set_decimals","flixel/addons/ui/FlxUINumericStepper.hx",123,0xbef22206)
HX_LOCAL_STACK_FRAME(_hx_pos_b3434b006136ea9e_134_set_isPercent,"flixel.addons.ui.FlxUINumericStepper","set_isPercent",0xa2c7cfa9,"flixel.addons.ui.FlxUINumericStepper.set_isPercent","flixel/addons/ui/FlxUINumericStepper.hx",134,0xbef22206)
HX_LOCAL_STACK_FRAME(_hx_pos_b3434b006136ea9e_141_set_stack,"flixel.addons.ui.FlxUINumericStepper","set_stack",0x4f051ff6,"flixel.addons.ui.FlxUINumericStepper.set_stack","flixel/addons/ui/FlxUINumericStepper.hx",141,0xbef22206)
HX_LOCAL_STACK_FRAME(_hx_pos_b3434b006136ea9e_186_decimalize,"flixel.addons.ui.FlxUINumericStepper","decimalize",0x151fa4b8,"flixel.addons.ui.FlxUINumericStepper.decimalize","flixel/addons/ui/FlxUINumericStepper.hx",186,0xbef22206)
HX_LOCAL_STACK_FRAME(_hx_pos_b3434b006136ea9e_271__onInputTextEvent,"flixel.addons.ui.FlxUINumericStepper","_onInputTextEvent",0x97f1d1ec,"flixel.addons.ui.FlxUINumericStepper._onInputTextEvent","flixel/addons/ui/FlxUINumericStepper.hx",271,0xbef22206)
HX_LOCAL_STACK_FRAME(_hx_pos_b3434b006136ea9e_299__onPlus,"flixel.addons.ui.FlxUINumericStepper","_onPlus",0xcab59143,"flixel.addons.ui.FlxUINumericStepper._onPlus","flixel/addons/ui/FlxUINumericStepper.hx",299,0xbef22206)
HX_LOCAL_STACK_FRAME(_hx_pos_b3434b006136ea9e_306__onMinus,"flixel.addons.ui.FlxUINumericStepper","_onMinus",0xd7f4da67,"flixel.addons.ui.FlxUINumericStepper._onMinus","flixel/addons/ui/FlxUINumericStepper.hx",306,0xbef22206)
HX_LOCAL_STACK_FRAME(_hx_pos_b3434b006136ea9e_314__doCallback,"flixel.addons.ui.FlxUINumericStepper","_doCallback",0xf5f9d69a,"flixel.addons.ui.FlxUINumericStepper._doCallback","flixel/addons/ui/FlxUINumericStepper.hx",314,0xbef22206)
HX_LOCAL_STACK_FRAME(_hx_pos_b3434b006136ea9e_27_boot,"flixel.addons.ui.FlxUINumericStepper","boot",0xdb47f7c7,"flixel.addons.ui.FlxUINumericStepper.boot","flixel/addons/ui/FlxUINumericStepper.hx",27,0xbef22206)
HX_LOCAL_STACK_FRAME(_hx_pos_b3434b006136ea9e_28_boot,"flixel.addons.ui.FlxUINumericStepper","boot",0xdb47f7c7,"flixel.addons.ui.FlxUINumericStepper.boot","flixel/addons/ui/FlxUINumericStepper.hx",28,0xbef22206)
HX_LOCAL_STACK_FRAME(_hx_pos_b3434b006136ea9e_30_boot,"flixel.addons.ui.FlxUINumericStepper","boot",0xdb47f7c7,"flixel.addons.ui.FlxUINumericStepper.boot","flixel/addons/ui/FlxUINumericStepper.hx",30,0xbef22206)
HX_LOCAL_STACK_FRAME(_hx_pos_b3434b006136ea9e_31_boot,"flixel.addons.ui.FlxUINumericStepper","boot",0xdb47f7c7,"flixel.addons.ui.FlxUINumericStepper.boot","flixel/addons/ui/FlxUINumericStepper.hx",31,0xbef22206)
HX_LOCAL_STACK_FRAME(_hx_pos_b3434b006136ea9e_32_boot,"flixel.addons.ui.FlxUINumericStepper","boot",0xdb47f7c7,"flixel.addons.ui.FlxUINumericStepper.boot","flixel/addons/ui/FlxUINumericStepper.hx",32,0xbef22206)
namespace flixel{
namespace addons{
namespace ui{

void FlxUINumericStepper_obj::__construct(::hx::Null< Float >  __o_X,::hx::Null< Float >  __o_Y,::hx::Null< Float >  __o_StepSize,::hx::Null< Float >  __o_DefaultValue,::hx::Null< Float >  __o_Min,::hx::Null< Float >  __o_Max,::hx::Null< int >  __o_Decimals,::hx::Null< int >  __o_Stack, ::flixel::text::FlxText TextField, ::flixel::addons::ui::FlxUITypedButton ButtonPlus, ::flixel::addons::ui::FlxUITypedButton ButtonMinus,::hx::Null< bool >  __o_IsPercent){
            		Float X = __o_X.Default(0);
            		Float Y = __o_Y.Default(0);
            		Float StepSize = __o_StepSize.Default(1);
            		Float DefaultValue = __o_DefaultValue.Default(0);
            		Float Min = __o_Min.Default(-999);
            		Float Max = __o_Max.Default(999);
            		int Decimals = __o_Decimals.Default(0);
            		int Stack = __o_Stack.Default(1);
            		bool IsPercent = __o_IsPercent.Default(false);
            	HX_GC_STACKFRAME(&_hx_pos_b3434b006136ea9e_13_new)
HXLINE(  25)		this->isPercent = false;
HXLINE(  24)		this->stack = 1;
HXLINE(  23)		this->value = ((Float)0);
HXLINE(  22)		this->max = ((Float)10);
HXLINE(  21)		this->min = ((Float)0);
HXLINE(  20)		this->decimals = 0;
HXLINE(  19)		this->stepSize = ((Float)0);
HXLINE( 211)		super::__construct(X,Y);
HXLINE( 213)		if (::hx::IsNull( TextField )) {
HXLINE( 215)			TextField =  ::flixel::addons::ui::FlxUIInputText_obj::__alloc( HX_CTX ,0,0,25,null(),null(),null(),null(),null());
            		}
HXLINE( 217)		TextField->set_x(( (Float)(0) ));
HXLINE( 218)		TextField->set_y(( (Float)(0) ));
HXLINE( 219)		this->text_field = TextField;
HXLINE( 220)		 ::flixel::text::FlxText _hx_tmp = this->text_field;
HXDLIN( 220)		_hx_tmp->set_text(::Std_obj::string(DefaultValue));
HXLINE( 222)		if (::Std_obj::isOfType(this->text_field,::hx::ClassOf< ::flixel::addons::ui::FlxUIInputText >())) {
HXLINE( 224)			 ::flixel::addons::ui::FlxUIInputText fuit = ( ( ::flixel::addons::ui::FlxUIInputText)(this->text_field) );
HXLINE( 225)			fuit->set_lines(1);
HXLINE( 226)			fuit->callback = this->_onInputTextEvent_dyn();
HXLINE( 227)			fuit->broadcastToFlxUI = false;
            		}
HXLINE( 230)		this->stepSize = StepSize;
HXLINE( 231)		this->set_decimals(Decimals);
HXLINE( 232)		this->set_min(Min);
HXLINE( 233)		this->set_max(Max);
HXLINE( 234)		this->set_value(DefaultValue);
HXLINE( 235)		this->set_isPercent(IsPercent);
HXLINE( 237)		int btnSize = (1 + ( (int)(TextField->get_height()) ));
HXLINE( 239)		if (::hx::IsNull( ButtonPlus )) {
HXLINE( 241)			ButtonPlus =  ::flixel::addons::ui::FlxUITypedButton_obj::__alloc( HX_CTX ,0,0,null());
HXLINE( 242)			ButtonPlus->loadGraphicSlice9(::cpp::VirtualArray_obj::__new(1)->init(0,HX_("flixel/flixel-ui/img/button_thin.png",58,62,55,9f)),btnSize,btnSize,::Array_obj< ::Dynamic>::__new(1)->init(0,::flixel::util::FlxStringUtil_obj::toIntArray(HX_("2,2,15,15",38,7b,83,18))),0,-1,false,18,18,null());
HXLINE( 244)			ButtonPlus->set_label( ::flixel::FlxSprite_obj::__alloc( HX_CTX ,0,0,HX_("flixel/flixel-ui/img/plus_mark.png",e4,f7,7a,be))).StaticCast<  ::flixel::FlxSprite >();
            		}
HXLINE( 246)		if (::hx::IsNull( ButtonMinus )) {
HXLINE( 248)			ButtonMinus =  ::flixel::addons::ui::FlxUITypedButton_obj::__alloc( HX_CTX ,0,0,null());
HXLINE( 249)			ButtonMinus->loadGraphicSlice9(::cpp::VirtualArray_obj::__new(1)->init(0,HX_("flixel/flixel-ui/img/button_thin.png",58,62,55,9f)),btnSize,btnSize,::Array_obj< ::Dynamic>::__new(1)->init(0,::flixel::util::FlxStringUtil_obj::toIntArray(HX_("2,2,15,15",38,7b,83,18))),0,-1,false,18,18,null());
HXLINE( 251)			ButtonMinus->set_label( ::flixel::FlxSprite_obj::__alloc( HX_CTX ,0,0,HX_("flixel/flixel-ui/img/minus_mark.png",80,c9,b5,31))).StaticCast<  ::flixel::FlxSprite >();
            		}
HXLINE( 254)		this->button_plus = ButtonPlus;
HXLINE( 255)		this->button_minus = ButtonMinus;
HXLINE( 257)		this->add(this->text_field);
HXLINE( 258)		this->add(this->button_plus);
HXLINE( 259)		this->add(this->button_minus);
HXLINE( 261)		this->button_plus->onUp->callback = this->_onPlus_dyn();
HXLINE( 262)		this->button_plus->broadcastToFlxUI = false;
HXLINE( 264)		this->button_minus->onUp->callback = this->_onMinus_dyn();
HXLINE( 265)		this->button_minus->broadcastToFlxUI = false;
HXLINE( 267)		this->set_stack(Stack);
            	}

Dynamic FlxUINumericStepper_obj::__CreateEmpty() { return new FlxUINumericStepper_obj; }

void *FlxUINumericStepper_obj::_hx_vtable = 0;

Dynamic FlxUINumericStepper_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< FlxUINumericStepper_obj > _hx_result = new FlxUINumericStepper_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6],inArgs[7],inArgs[8],inArgs[9],inArgs[10],inArgs[11]);
	return _hx_result;
}

bool FlxUINumericStepper_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x398eb8dc) {
		if (inClassId<=(int)0x2c01639b) {
			if (inClassId<=(int)0x288ce903) {
				return inClassId==(int)0x00000001 || inClassId==(int)0x288ce903;
			} else {
				return inClassId==(int)0x2c01639b;
			}
		} else {
			return inClassId==(int)0x398eb8dc;
		}
	} else {
		if (inClassId<=(int)0x7ccf8994) {
			return inClassId==(int)0x6a478fa3 || inClassId==(int)0x7ccf8994;
		} else {
			return inClassId==(int)0x7dab0655;
		}
	}
}

static ::flixel::IFlxSprite_obj _hx_flixel_addons_ui_FlxUINumericStepper__hx_flixel_IFlxSprite= {
	( bool (::hx::Object::*)(bool))&::flixel::addons::ui::FlxUINumericStepper_obj::set_active,
	( bool (::hx::Object::*)(bool))&::flixel::addons::ui::FlxUINumericStepper_obj::set_visible,
	( bool (::hx::Object::*)(bool))&::flixel::addons::ui::FlxUINumericStepper_obj::set_alive,
	( bool (::hx::Object::*)(bool))&::flixel::addons::ui::FlxUINumericStepper_obj::set_exists,
	( void (::hx::Object::*)())&::flixel::addons::ui::FlxUINumericStepper_obj::draw,
	( void (::hx::Object::*)(Float))&::flixel::addons::ui::FlxUINumericStepper_obj::update,
	( void (::hx::Object::*)())&::flixel::addons::ui::FlxUINumericStepper_obj::destroy,
	( void (::hx::Object::*)())&::flixel::addons::ui::FlxUINumericStepper_obj::kill,
	( void (::hx::Object::*)())&::flixel::addons::ui::FlxUINumericStepper_obj::revive,
	( ::String (::hx::Object::*)())&::flixel::addons::ui::FlxUINumericStepper_obj::toString,
	( Float (::hx::Object::*)(Float))&::flixel::addons::ui::FlxUINumericStepper_obj::set_x,
	( Float (::hx::Object::*)(Float))&::flixel::addons::ui::FlxUINumericStepper_obj::set_y,
	( Float (::hx::Object::*)(Float))&::flixel::addons::ui::FlxUINumericStepper_obj::set_alpha,
	( Float (::hx::Object::*)(Float))&::flixel::addons::ui::FlxUINumericStepper_obj::set_angle,
	( int (::hx::Object::*)(int))&::flixel::addons::ui::FlxUINumericStepper_obj::set_facing,
	( bool (::hx::Object::*)(bool))&::flixel::addons::ui::FlxUINumericStepper_obj::set_moves,
	( bool (::hx::Object::*)(bool))&::flixel::addons::ui::FlxUINumericStepper_obj::set_immovable,
	( void (::hx::Object::*)(Float,Float))&::flixel::addons::ui::FlxUINumericStepper_obj::reset,
	( void (::hx::Object::*)(::hx::Null< Float > ,::hx::Null< Float > ))&::flixel::addons::ui::FlxUINumericStepper_obj::setPosition,
};

static ::flixel::IFlxBasic_obj _hx_flixel_addons_ui_FlxUINumericStepper__hx_flixel_IFlxBasic= {
	( bool (::hx::Object::*)(bool))&::flixel::addons::ui::FlxUINumericStepper_obj::set_active,
	( bool (::hx::Object::*)(bool))&::flixel::addons::ui::FlxUINumericStepper_obj::set_visible,
	( bool (::hx::Object::*)(bool))&::flixel::addons::ui::FlxUINumericStepper_obj::set_alive,
	( bool (::hx::Object::*)(bool))&::flixel::addons::ui::FlxUINumericStepper_obj::set_exists,
	( void (::hx::Object::*)())&::flixel::addons::ui::FlxUINumericStepper_obj::draw,
	( void (::hx::Object::*)(Float))&::flixel::addons::ui::FlxUINumericStepper_obj::update,
	( void (::hx::Object::*)())&::flixel::addons::ui::FlxUINumericStepper_obj::destroy,
	( void (::hx::Object::*)())&::flixel::addons::ui::FlxUINumericStepper_obj::kill,
	( void (::hx::Object::*)())&::flixel::addons::ui::FlxUINumericStepper_obj::revive,
	( ::String (::hx::Object::*)())&::flixel::addons::ui::FlxUINumericStepper_obj::toString,
};

static ::flixel::addons::ui::interfaces::IFlxUIWidget_obj _hx_flixel_addons_ui_FlxUINumericStepper__hx_flixel_addons_ui_interfaces_IFlxUIWidget= {
	( bool (::hx::Object::*)(bool))&::flixel::addons::ui::FlxUINumericStepper_obj::set_active,
	( bool (::hx::Object::*)(bool))&::flixel::addons::ui::FlxUINumericStepper_obj::set_visible,
	( bool (::hx::Object::*)(bool))&::flixel::addons::ui::FlxUINumericStepper_obj::set_alive,
	( bool (::hx::Object::*)(bool))&::flixel::addons::ui::FlxUINumericStepper_obj::set_exists,
	( void (::hx::Object::*)())&::flixel::addons::ui::FlxUINumericStepper_obj::draw,
	( void (::hx::Object::*)(Float))&::flixel::addons::ui::FlxUINumericStepper_obj::update,
	( void (::hx::Object::*)())&::flixel::addons::ui::FlxUINumericStepper_obj::destroy,
	( void (::hx::Object::*)())&::flixel::addons::ui::FlxUINumericStepper_obj::kill,
	( void (::hx::Object::*)())&::flixel::addons::ui::FlxUINumericStepper_obj::revive,
	( ::String (::hx::Object::*)())&::flixel::addons::ui::FlxUINumericStepper_obj::toString,
	( Float (::hx::Object::*)(Float))&::flixel::addons::ui::FlxUINumericStepper_obj::set_x,
	( Float (::hx::Object::*)(Float))&::flixel::addons::ui::FlxUINumericStepper_obj::set_y,
	( Float (::hx::Object::*)(Float))&::flixel::addons::ui::FlxUINumericStepper_obj::set_alpha,
	( Float (::hx::Object::*)(Float))&::flixel::addons::ui::FlxUINumericStepper_obj::set_angle,
	( int (::hx::Object::*)(int))&::flixel::addons::ui::FlxUINumericStepper_obj::set_facing,
	( bool (::hx::Object::*)(bool))&::flixel::addons::ui::FlxUINumericStepper_obj::set_moves,
	( bool (::hx::Object::*)(bool))&::flixel::addons::ui::FlxUINumericStepper_obj::set_immovable,
	( void (::hx::Object::*)(Float,Float))&::flixel::addons::ui::FlxUINumericStepper_obj::reset,
	( void (::hx::Object::*)(::hx::Null< Float > ,::hx::Null< Float > ))&::flixel::addons::ui::FlxUINumericStepper_obj::setPosition,
	( Float (::hx::Object::*)())&::flixel::addons::ui::FlxUINumericStepper_obj::get_width,
	( Float (::hx::Object::*)(Float))&::flixel::addons::ui::FlxUINumericStepper_obj::set_width,
	( Float (::hx::Object::*)())&::flixel::addons::ui::FlxUINumericStepper_obj::get_height,
	( Float (::hx::Object::*)(Float))&::flixel::addons::ui::FlxUINumericStepper_obj::set_height,
};

static ::flixel::addons::ui::interfaces::IHasParams_obj _hx_flixel_addons_ui_FlxUINumericStepper__hx_flixel_addons_ui_interfaces_IHasParams= {
	( ::cpp::VirtualArray (::hx::Object::*)(::cpp::VirtualArray))&::flixel::addons::ui::FlxUINumericStepper_obj::set_params,
};

static ::flixel::addons::ui::interfaces::IFlxUIClickable_obj _hx_flixel_addons_ui_FlxUINumericStepper__hx_flixel_addons_ui_interfaces_IFlxUIClickable= {
	( bool (::hx::Object::*)(bool))&::flixel::addons::ui::FlxUINumericStepper_obj::set_skipButtonUpdate,
};

void *FlxUINumericStepper_obj::_hx_getInterface(int inHash) {
	switch(inHash) {
		case (int)0x897c83aa: return &_hx_flixel_addons_ui_FlxUINumericStepper__hx_flixel_IFlxSprite;
		case (int)0x284cfea9: return &_hx_flixel_addons_ui_FlxUINumericStepper__hx_flixel_IFlxBasic;
		case (int)0x998525de: return &_hx_flixel_addons_ui_FlxUINumericStepper__hx_flixel_addons_ui_interfaces_IFlxUIWidget;
		case (int)0x9e5db374: return &_hx_flixel_addons_ui_FlxUINumericStepper__hx_flixel_addons_ui_interfaces_IHasParams;
		case (int)0x3e998408: return &_hx_flixel_addons_ui_FlxUINumericStepper__hx_flixel_addons_ui_interfaces_IFlxUIClickable;
	}
	return super::_hx_getInterface(inHash);
}

::cpp::VirtualArray FlxUINumericStepper_obj::set_params(::cpp::VirtualArray p){
            	HX_STACKFRAME(&_hx_pos_b3434b006136ea9e_37_set_params)
HXLINE(  38)		this->params = p;
HXLINE(  39)		return this->params;
            	}


HX_DEFINE_DYNAMIC_FUNC1(FlxUINumericStepper_obj,set_params,return )

bool FlxUINumericStepper_obj::set_skipButtonUpdate(bool b){
            	HX_STACKFRAME(&_hx_pos_b3434b006136ea9e_45_set_skipButtonUpdate)
HXLINE(  46)		this->skipButtonUpdate = b;
HXLINE(  47)		this->button_plus->set_skipButtonUpdate(b);
HXLINE(  48)		this->button_minus->set_skipButtonUpdate(b);
HXLINE(  50)		return b;
            	}


HX_DEFINE_DYNAMIC_FUNC1(FlxUINumericStepper_obj,set_skipButtonUpdate,return )

int FlxUINumericStepper_obj::set_color(int _tmp_Value){
            	HX_STACKFRAME(&_hx_pos_b3434b006136ea9e_54_set_color)
HXLINE(  55)		int Value = _tmp_Value;
HXDLIN(  55)		this->color = Value;
HXLINE(  56)		this->button_plus->set_color(Value);
HXLINE(  57)		this->button_minus->set_color(Value);
HXLINE(  58)		if (::Std_obj::isOfType(this->text_field,::hx::ClassOf< ::flixel::addons::ui::FlxInputText >())) {
HXLINE(  60)			 ::flixel::addons::ui::FlxInputText fit = ( ( ::flixel::addons::ui::FlxInputText)(this->text_field) );
HXLINE(  61)			fit->set_backgroundColor(Value);
            		}
            		else {
HXLINE(  65)			this->text_field->set_color(Value);
            		}
HXLINE(  67)		return Value;
            	}


Float FlxUINumericStepper_obj::set_min(Float f){
            	HX_STACKFRAME(&_hx_pos_b3434b006136ea9e_71_set_min)
HXLINE(  72)		this->min = f;
HXLINE(  73)		if (::hx::IsLess( this->value,this->min )) {
HXLINE(  75)			this->set_value(this->min);
            		}
HXLINE(  77)		return this->min;
            	}


HX_DEFINE_DYNAMIC_FUNC1(FlxUINumericStepper_obj,set_min,return )

Float FlxUINumericStepper_obj::set_max(Float f){
            	HX_STACKFRAME(&_hx_pos_b3434b006136ea9e_81_set_max)
HXLINE(  82)		this->max = f;
HXLINE(  83)		if (::hx::IsGreater( this->value,this->max )) {
HXLINE(  85)			this->set_value(this->max);
            		}
HXLINE(  87)		return this->max;
            	}


HX_DEFINE_DYNAMIC_FUNC1(FlxUINumericStepper_obj,set_max,return )

 ::Dynamic FlxUINumericStepper_obj::set_value( ::Dynamic f){
            	HX_STACKFRAME(&_hx_pos_b3434b006136ea9e_91_set_value)
HXLINE(  92)		this->value = f;
HXLINE(  94)		if (::hx::IsNull( this->value )) {
HXLINE(  96)			this->value = 0;
            		}
HXLINE(  98)		if (::hx::IsLess( this->value,this->min )) {
HXLINE( 100)			this->value = this->min;
            		}
HXLINE( 102)		if (::hx::IsGreater( this->value,this->max )) {
HXLINE( 104)			this->value = this->max;
            		}
HXLINE( 106)		if (::hx::IsNotNull( this->text_field )) {
HXLINE( 108)			Float displayValue = ( (Float)(this->value) );
HXLINE( 109)			if (this->isPercent) {
HXLINE( 111)				displayValue = (displayValue * ( (Float)(100) ));
HXLINE( 112)				 ::flixel::text::FlxText _hx_tmp = this->text_field;
HXDLIN( 112)				Float tens = ::Math_obj::pow(( (Float)(10) ),( (Float)(this->decimals) ));
HXDLIN( 112)				_hx_tmp->set_text((::Std_obj::string(::Std_obj::string((( (Float)(::Math_obj::round((displayValue * tens))) ) / tens))) + HX_("%",25,00,00,00)));
            			}
            			else {
HXLINE( 116)				 ::flixel::text::FlxText _hx_tmp = this->text_field;
HXDLIN( 116)				Float tens = ::Math_obj::pow(( (Float)(10) ),( (Float)(this->decimals) ));
HXDLIN( 116)				_hx_tmp->set_text(::Std_obj::string((( (Float)(::Math_obj::round((displayValue * tens))) ) / tens)));
            			}
            		}
HXLINE( 119)		return this->value;
            	}


HX_DEFINE_DYNAMIC_FUNC1(FlxUINumericStepper_obj,set_value,return )

int FlxUINumericStepper_obj::set_decimals(int i){
            	HX_STACKFRAME(&_hx_pos_b3434b006136ea9e_123_set_decimals)
HXLINE( 124)		this->decimals = i;
HXLINE( 125)		if ((i < 0)) {
HXLINE( 127)			this->decimals = 0;
            		}
HXLINE( 129)		this->set_value(this->value);
HXLINE( 130)		return this->decimals;
            	}


HX_DEFINE_DYNAMIC_FUNC1(FlxUINumericStepper_obj,set_decimals,return )

bool FlxUINumericStepper_obj::set_isPercent(bool b){
            	HX_STACKFRAME(&_hx_pos_b3434b006136ea9e_134_set_isPercent)
HXLINE( 135)		this->isPercent = b;
HXLINE( 136)		this->set_value(this->value);
HXLINE( 137)		return this->isPercent;
            	}


HX_DEFINE_DYNAMIC_FUNC1(FlxUINumericStepper_obj,set_isPercent,return )

int FlxUINumericStepper_obj::set_stack(int s){
            	HX_STACKFRAME(&_hx_pos_b3434b006136ea9e_141_set_stack)
HXLINE( 142)		this->stack = s;
HXLINE( 143)		int btnSize = 10;
HXLINE( 144)		int offsetX = 0;
HXLINE( 145)		int offsetY = 0;
HXLINE( 146)		if (::Std_obj::isOfType(this->text_field,::hx::ClassOf< ::flixel::addons::ui::FlxUIInputText >())) {
HXLINE( 148)			offsetX = 1;
HXLINE( 149)			offsetY = 1;
            		}
HXLINE( 151)		switch((int)(this->stack)){
            			case (int)0: {
HXLINE( 168)				btnSize = (1 + ( (int)((this->text_field->get_height() / ( (Float)(2) ))) ));
HXLINE( 169)				if ((this->button_plus->get_height() != btnSize)) {
HXLINE( 171)					this->button_plus->resize(( (Float)(btnSize) ),( (Float)(btnSize) ));
            				}
HXLINE( 173)				if ((this->button_minus->get_height() != btnSize)) {
HXLINE( 175)					this->button_minus->resize(( (Float)(btnSize) ),( (Float)(btnSize) ));
            				}
HXLINE( 177)				 ::flixel::addons::ui::FlxUITypedButton _hx_tmp = this->button_plus;
HXDLIN( 177)				Float _hx_tmp1 = (offsetX + this->text_field->x);
HXDLIN( 177)				_hx_tmp->set_x((_hx_tmp1 + this->text_field->get_width()));
HXLINE( 178)				this->button_plus->set_y((-(offsetY) + this->text_field->y));
HXLINE( 179)				 ::flixel::addons::ui::FlxUITypedButton _hx_tmp2 = this->button_minus;
HXDLIN( 179)				Float _hx_tmp3 = (offsetX + this->text_field->x);
HXDLIN( 179)				_hx_tmp2->set_x((_hx_tmp3 + this->text_field->get_width()));
HXLINE( 180)				 ::flixel::addons::ui::FlxUITypedButton _hx_tmp4 = this->button_minus;
HXDLIN( 180)				Float _hx_tmp5 = (offsetY + this->text_field->y);
HXDLIN( 180)				Float _hx_tmp6 = this->text_field->get_height();
HXDLIN( 180)				_hx_tmp4->set_y((_hx_tmp5 + (_hx_tmp6 - this->button_minus->get_height())));
            			}
            			break;
            			case (int)1: {
HXLINE( 154)				btnSize = (2 + ( (int)(this->text_field->get_height()) ));
HXLINE( 155)				if ((this->button_plus->get_height() != btnSize)) {
HXLINE( 157)					this->button_plus->resize(( (Float)(btnSize) ),( (Float)(btnSize) ));
            				}
HXLINE( 159)				if ((this->button_minus->get_height() != btnSize)) {
HXLINE( 161)					this->button_minus->resize(( (Float)(btnSize) ),( (Float)(btnSize) ));
            				}
HXLINE( 163)				 ::flixel::addons::ui::FlxUITypedButton _hx_tmp = this->button_plus;
HXDLIN( 163)				Float _hx_tmp1 = (offsetX + this->text_field->x);
HXDLIN( 163)				_hx_tmp->set_x((_hx_tmp1 + this->text_field->get_width()));
HXLINE( 164)				this->button_plus->set_y((-(offsetY) + this->text_field->y));
HXLINE( 165)				 ::flixel::addons::ui::FlxUITypedButton _hx_tmp2 = this->button_minus;
HXDLIN( 165)				Float _hx_tmp3 = this->button_plus->x;
HXDLIN( 165)				_hx_tmp2->set_x((_hx_tmp3 + this->button_plus->get_width()));
HXLINE( 166)				this->button_minus->set_y(this->button_plus->y);
            			}
            			break;
            		}
HXLINE( 182)		return this->stack;
            	}


HX_DEFINE_DYNAMIC_FUNC1(FlxUINumericStepper_obj,set_stack,return )

::String FlxUINumericStepper_obj::decimalize(Float f,int digits){
            	HX_STACKFRAME(&_hx_pos_b3434b006136ea9e_186_decimalize)
HXLINE( 187)		Float tens = ::Math_obj::pow(( (Float)(10) ),( (Float)(digits) ));
HXLINE( 188)		return ::Std_obj::string((( (Float)(::Math_obj::round((f * tens))) ) / tens));
            	}


HX_DEFINE_DYNAMIC_FUNC2(FlxUINumericStepper_obj,decimalize,return )

void FlxUINumericStepper_obj::_onInputTextEvent(::String text,::String action){
            	HX_STACKFRAME(&_hx_pos_b3434b006136ea9e_271__onInputTextEvent)
HXLINE( 272)		if ((text == HX_("",00,00,00,00))) {
HXLINE( 274)			text = ::Std_obj::string(this->min);
            		}
HXLINE( 277)		int numDecimals = 0;
HXLINE( 278)		{
HXLINE( 278)			int _g = 0;
HXDLIN( 278)			int _g1 = text.length;
HXDLIN( 278)			while((_g < _g1)){
HXLINE( 278)				_g = (_g + 1);
HXDLIN( 278)				int i = (_g - 1);
HXLINE( 280)				::String _hx_char = text.charAt(i);
HXLINE( 281)				if ((_hx_char == HX_(".",2e,00,00,00))) {
HXLINE( 283)					numDecimals = (numDecimals + 1);
            				}
            			}
            		}
HXLINE( 287)		bool justAddedDecimal;
HXDLIN( 287)		if ((numDecimals == 1)) {
HXLINE( 287)			int justAddedDecimal1 = text.indexOf(HX_(".",2e,00,00,00),null());
HXDLIN( 287)			justAddedDecimal = (justAddedDecimal1 == (text.length - 1));
            		}
            		else {
HXLINE( 287)			justAddedDecimal = false;
            		}
HXLINE( 290)		if (!(justAddedDecimal)) {
HXLINE( 292)			this->set_value(::Std_obj::parseFloat(text));
HXLINE( 293)			this->_doCallback(HX_("edit_numeric_stepper",ea,96,04,5c));
HXLINE( 294)			this->_doCallback(HX_("change_numeric_stepper",50,0a,cc,bb));
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC2(FlxUINumericStepper_obj,_onInputTextEvent,(void))

void FlxUINumericStepper_obj::_onPlus(){
            	HX_STACKFRAME(&_hx_pos_b3434b006136ea9e_299__onPlus)
HXLINE( 300)		this->set_value((this->value + this->stepSize));
HXLINE( 301)		this->_doCallback(HX_("click_numeric_stepper",28,25,65,6e));
HXLINE( 302)		this->_doCallback(HX_("change_numeric_stepper",50,0a,cc,bb));
            	}


HX_DEFINE_DYNAMIC_FUNC0(FlxUINumericStepper_obj,_onPlus,(void))

void FlxUINumericStepper_obj::_onMinus(){
            	HX_STACKFRAME(&_hx_pos_b3434b006136ea9e_306__onMinus)
HXLINE( 307)		this->set_value((( (Float)(this->value) ) - this->stepSize));
HXLINE( 308)		this->_doCallback(HX_("click_numeric_stepper",28,25,65,6e));
HXLINE( 309)		this->_doCallback(HX_("change_numeric_stepper",50,0a,cc,bb));
            	}


HX_DEFINE_DYNAMIC_FUNC0(FlxUINumericStepper_obj,_onMinus,(void))

void FlxUINumericStepper_obj::_doCallback(::String event_name){
            	HX_STACKFRAME(&_hx_pos_b3434b006136ea9e_314__doCallback)
HXDLIN( 314)		if (this->broadcastToFlxUI) {
HXLINE( 316)			::flixel::addons::ui::FlxUI_obj::event(event_name,::hx::ObjectPtr<OBJ_>(this),this->value,this->params);
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(FlxUINumericStepper_obj,_doCallback,(void))

int FlxUINumericStepper_obj::STACK_VERTICAL;

int FlxUINumericStepper_obj::STACK_HORIZONTAL;

::String FlxUINumericStepper_obj::CLICK_EVENT;

::String FlxUINumericStepper_obj::EDIT_EVENT;

::String FlxUINumericStepper_obj::CHANGE_EVENT;


::hx::ObjectPtr< FlxUINumericStepper_obj > FlxUINumericStepper_obj::__new(::hx::Null< Float >  __o_X,::hx::Null< Float >  __o_Y,::hx::Null< Float >  __o_StepSize,::hx::Null< Float >  __o_DefaultValue,::hx::Null< Float >  __o_Min,::hx::Null< Float >  __o_Max,::hx::Null< int >  __o_Decimals,::hx::Null< int >  __o_Stack, ::flixel::text::FlxText TextField, ::flixel::addons::ui::FlxUITypedButton ButtonPlus, ::flixel::addons::ui::FlxUITypedButton ButtonMinus,::hx::Null< bool >  __o_IsPercent) {
	::hx::ObjectPtr< FlxUINumericStepper_obj > __this = new FlxUINumericStepper_obj();
	__this->__construct(__o_X,__o_Y,__o_StepSize,__o_DefaultValue,__o_Min,__o_Max,__o_Decimals,__o_Stack,TextField,ButtonPlus,ButtonMinus,__o_IsPercent);
	return __this;
}

::hx::ObjectPtr< FlxUINumericStepper_obj > FlxUINumericStepper_obj::__alloc(::hx::Ctx *_hx_ctx,::hx::Null< Float >  __o_X,::hx::Null< Float >  __o_Y,::hx::Null< Float >  __o_StepSize,::hx::Null< Float >  __o_DefaultValue,::hx::Null< Float >  __o_Min,::hx::Null< Float >  __o_Max,::hx::Null< int >  __o_Decimals,::hx::Null< int >  __o_Stack, ::flixel::text::FlxText TextField, ::flixel::addons::ui::FlxUITypedButton ButtonPlus, ::flixel::addons::ui::FlxUITypedButton ButtonMinus,::hx::Null< bool >  __o_IsPercent) {
	FlxUINumericStepper_obj *__this = (FlxUINumericStepper_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(FlxUINumericStepper_obj), true, "flixel.addons.ui.FlxUINumericStepper"));
	*(void **)__this = FlxUINumericStepper_obj::_hx_vtable;
	__this->__construct(__o_X,__o_Y,__o_StepSize,__o_DefaultValue,__o_Min,__o_Max,__o_Decimals,__o_Stack,TextField,ButtonPlus,ButtonMinus,__o_IsPercent);
	return __this;
}

FlxUINumericStepper_obj::FlxUINumericStepper_obj()
{
}

void FlxUINumericStepper_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxUINumericStepper);
	HX_MARK_MEMBER_NAME(button_plus,"button_plus");
	HX_MARK_MEMBER_NAME(button_minus,"button_minus");
	HX_MARK_MEMBER_NAME(text_field,"text_field");
	HX_MARK_MEMBER_NAME(stepSize,"stepSize");
	HX_MARK_MEMBER_NAME(decimals,"decimals");
	HX_MARK_MEMBER_NAME(min,"min");
	HX_MARK_MEMBER_NAME(max,"max");
	HX_MARK_MEMBER_NAME(value,"value");
	HX_MARK_MEMBER_NAME(stack,"stack");
	HX_MARK_MEMBER_NAME(isPercent,"isPercent");
	HX_MARK_MEMBER_NAME(params,"params");
	HX_MARK_MEMBER_NAME(skipButtonUpdate,"skipButtonUpdate");
	 ::flixel::addons::ui::FlxUIGroup_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FlxUINumericStepper_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(button_plus,"button_plus");
	HX_VISIT_MEMBER_NAME(button_minus,"button_minus");
	HX_VISIT_MEMBER_NAME(text_field,"text_field");
	HX_VISIT_MEMBER_NAME(stepSize,"stepSize");
	HX_VISIT_MEMBER_NAME(decimals,"decimals");
	HX_VISIT_MEMBER_NAME(min,"min");
	HX_VISIT_MEMBER_NAME(max,"max");
	HX_VISIT_MEMBER_NAME(value,"value");
	HX_VISIT_MEMBER_NAME(stack,"stack");
	HX_VISIT_MEMBER_NAME(isPercent,"isPercent");
	HX_VISIT_MEMBER_NAME(params,"params");
	HX_VISIT_MEMBER_NAME(skipButtonUpdate,"skipButtonUpdate");
	 ::flixel::addons::ui::FlxUIGroup_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val FlxUINumericStepper_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"min") ) { return ::hx::Val( min ); }
		if (HX_FIELD_EQ(inName,"max") ) { return ::hx::Val( max ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { return ::hx::Val( value ); }
		if (HX_FIELD_EQ(inName,"stack") ) { return ::hx::Val( stack ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"params") ) { return ::hx::Val( params ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"set_min") ) { return ::hx::Val( set_min_dyn() ); }
		if (HX_FIELD_EQ(inName,"set_max") ) { return ::hx::Val( set_max_dyn() ); }
		if (HX_FIELD_EQ(inName,"_onPlus") ) { return ::hx::Val( _onPlus_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"stepSize") ) { return ::hx::Val( stepSize ); }
		if (HX_FIELD_EQ(inName,"decimals") ) { return ::hx::Val( decimals ); }
		if (HX_FIELD_EQ(inName,"_onMinus") ) { return ::hx::Val( _onMinus_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"isPercent") ) { return ::hx::Val( isPercent ); }
		if (HX_FIELD_EQ(inName,"set_color") ) { return ::hx::Val( set_color_dyn() ); }
		if (HX_FIELD_EQ(inName,"set_value") ) { return ::hx::Val( set_value_dyn() ); }
		if (HX_FIELD_EQ(inName,"set_stack") ) { return ::hx::Val( set_stack_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"text_field") ) { return ::hx::Val( text_field ); }
		if (HX_FIELD_EQ(inName,"set_params") ) { return ::hx::Val( set_params_dyn() ); }
		if (HX_FIELD_EQ(inName,"decimalize") ) { return ::hx::Val( decimalize_dyn() ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"button_plus") ) { return ::hx::Val( button_plus ); }
		if (HX_FIELD_EQ(inName,"_doCallback") ) { return ::hx::Val( _doCallback_dyn() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"button_minus") ) { return ::hx::Val( button_minus ); }
		if (HX_FIELD_EQ(inName,"set_decimals") ) { return ::hx::Val( set_decimals_dyn() ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"set_isPercent") ) { return ::hx::Val( set_isPercent_dyn() ); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"skipButtonUpdate") ) { return ::hx::Val( skipButtonUpdate ); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_onInputTextEvent") ) { return ::hx::Val( _onInputTextEvent_dyn() ); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"set_skipButtonUpdate") ) { return ::hx::Val( set_skipButtonUpdate_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val FlxUINumericStepper_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"min") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_min(inValue.Cast< Float >()) );min=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"max") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_max(inValue.Cast< Float >()) );max=inValue.Cast< Float >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_value(inValue.Cast<  ::Dynamic >()) );value=inValue.Cast<  ::Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"stack") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_stack(inValue.Cast< int >()) );stack=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"params") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_params(inValue.Cast< ::cpp::VirtualArray >()) );params=inValue.Cast< ::cpp::VirtualArray >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"stepSize") ) { stepSize=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"decimals") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_decimals(inValue.Cast< int >()) );decimals=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"isPercent") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_isPercent(inValue.Cast< bool >()) );isPercent=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"text_field") ) { text_field=inValue.Cast<  ::flixel::text::FlxText >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"button_plus") ) { button_plus=inValue.Cast<  ::flixel::addons::ui::FlxUITypedButton >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"button_minus") ) { button_minus=inValue.Cast<  ::flixel::addons::ui::FlxUITypedButton >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"skipButtonUpdate") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_skipButtonUpdate(inValue.Cast< bool >()) );skipButtonUpdate=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxUINumericStepper_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("button_plus",07,ac,e8,b7));
	outFields->push(HX_("button_minus",23,2b,79,77));
	outFields->push(HX_("text_field",68,e8,d6,fe));
	outFields->push(HX_("stepSize",2d,4a,7c,9f));
	outFields->push(HX_("decimals",c2,4a,6a,12));
	outFields->push(HX_("min",92,11,53,00));
	outFields->push(HX_("max",a4,0a,53,00));
	outFields->push(HX_("value",71,7f,b8,31));
	outFields->push(HX_("stack",48,67,0b,84));
	outFields->push(HX_("isPercent",fb,27,d9,7c));
	outFields->push(HX_("params",46,fb,7a,ed));
	outFields->push(HX_("skipButtonUpdate",ba,02,f2,13));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo FlxUINumericStepper_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::flixel::addons::ui::FlxUITypedButton */ ,(int)offsetof(FlxUINumericStepper_obj,button_plus),HX_("button_plus",07,ac,e8,b7)},
	{::hx::fsObject /*  ::flixel::addons::ui::FlxUITypedButton */ ,(int)offsetof(FlxUINumericStepper_obj,button_minus),HX_("button_minus",23,2b,79,77)},
	{::hx::fsObject /*  ::flixel::text::FlxText */ ,(int)offsetof(FlxUINumericStepper_obj,text_field),HX_("text_field",68,e8,d6,fe)},
	{::hx::fsFloat,(int)offsetof(FlxUINumericStepper_obj,stepSize),HX_("stepSize",2d,4a,7c,9f)},
	{::hx::fsInt,(int)offsetof(FlxUINumericStepper_obj,decimals),HX_("decimals",c2,4a,6a,12)},
	{::hx::fsFloat,(int)offsetof(FlxUINumericStepper_obj,min),HX_("min",92,11,53,00)},
	{::hx::fsFloat,(int)offsetof(FlxUINumericStepper_obj,max),HX_("max",a4,0a,53,00)},
	{::hx::fsObject /*  ::Dynamic */ ,(int)offsetof(FlxUINumericStepper_obj,value),HX_("value",71,7f,b8,31)},
	{::hx::fsInt,(int)offsetof(FlxUINumericStepper_obj,stack),HX_("stack",48,67,0b,84)},
	{::hx::fsBool,(int)offsetof(FlxUINumericStepper_obj,isPercent),HX_("isPercent",fb,27,d9,7c)},
	{::hx::fsObject /* ::cpp::VirtualArray */ ,(int)offsetof(FlxUINumericStepper_obj,params),HX_("params",46,fb,7a,ed)},
	{::hx::fsBool,(int)offsetof(FlxUINumericStepper_obj,skipButtonUpdate),HX_("skipButtonUpdate",ba,02,f2,13)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo FlxUINumericStepper_obj_sStaticStorageInfo[] = {
	{::hx::fsInt,(void *) &FlxUINumericStepper_obj::STACK_VERTICAL,HX_("STACK_VERTICAL",ad,7f,2e,ce)},
	{::hx::fsInt,(void *) &FlxUINumericStepper_obj::STACK_HORIZONTAL,HX_("STACK_HORIZONTAL",db,1f,fd,43)},
	{::hx::fsString,(void *) &FlxUINumericStepper_obj::CLICK_EVENT,HX_("CLICK_EVENT",63,89,c0,0d)},
	{::hx::fsString,(void *) &FlxUINumericStepper_obj::EDIT_EVENT,HX_("EDIT_EVENT",c5,fc,39,c0)},
	{::hx::fsString,(void *) &FlxUINumericStepper_obj::CHANGE_EVENT,HX_("CHANGE_EVENT",ab,38,ff,8d)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static ::String FlxUINumericStepper_obj_sMemberFields[] = {
	HX_("button_plus",07,ac,e8,b7),
	HX_("button_minus",23,2b,79,77),
	HX_("text_field",68,e8,d6,fe),
	HX_("stepSize",2d,4a,7c,9f),
	HX_("decimals",c2,4a,6a,12),
	HX_("min",92,11,53,00),
	HX_("max",a4,0a,53,00),
	HX_("value",71,7f,b8,31),
	HX_("stack",48,67,0b,84),
	HX_("isPercent",fb,27,d9,7c),
	HX_("params",46,fb,7a,ed),
	HX_("set_params",83,09,80,e1),
	HX_("skipButtonUpdate",ba,02,f2,13),
	HX_("set_skipButtonUpdate",37,1f,14,ff),
	HX_("set_color",c6,b9,56,71),
	HX_("set_min",35,6b,c9,19),
	HX_("set_max",47,64,c9,19),
	HX_("set_value",d4,c7,b2,58),
	HX_("set_decimals",3f,22,7d,dc),
	HX_("set_isPercent",de,dd,42,83),
	HX_("set_stack",ab,af,05,ab),
	HX_("decimalize",63,d3,9c,39),
	HX_("_onInputTextEvent",a1,9e,48,f2),
	HX_("_onPlus",b8,59,5b,5b),
	HX_("_onMinus",52,78,5e,d8),
	HX_("_doCallback",8f,7d,05,bf),
	::String(null()) };

static void FlxUINumericStepper_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxUINumericStepper_obj::STACK_VERTICAL,"STACK_VERTICAL");
	HX_MARK_MEMBER_NAME(FlxUINumericStepper_obj::STACK_HORIZONTAL,"STACK_HORIZONTAL");
	HX_MARK_MEMBER_NAME(FlxUINumericStepper_obj::CLICK_EVENT,"CLICK_EVENT");
	HX_MARK_MEMBER_NAME(FlxUINumericStepper_obj::EDIT_EVENT,"EDIT_EVENT");
	HX_MARK_MEMBER_NAME(FlxUINumericStepper_obj::CHANGE_EVENT,"CHANGE_EVENT");
};

#ifdef HXCPP_VISIT_ALLOCS
static void FlxUINumericStepper_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxUINumericStepper_obj::STACK_VERTICAL,"STACK_VERTICAL");
	HX_VISIT_MEMBER_NAME(FlxUINumericStepper_obj::STACK_HORIZONTAL,"STACK_HORIZONTAL");
	HX_VISIT_MEMBER_NAME(FlxUINumericStepper_obj::CLICK_EVENT,"CLICK_EVENT");
	HX_VISIT_MEMBER_NAME(FlxUINumericStepper_obj::EDIT_EVENT,"EDIT_EVENT");
	HX_VISIT_MEMBER_NAME(FlxUINumericStepper_obj::CHANGE_EVENT,"CHANGE_EVENT");
};

#endif

::hx::Class FlxUINumericStepper_obj::__mClass;

static ::String FlxUINumericStepper_obj_sStaticFields[] = {
	HX_("STACK_VERTICAL",ad,7f,2e,ce),
	HX_("STACK_HORIZONTAL",db,1f,fd,43),
	HX_("CLICK_EVENT",63,89,c0,0d),
	HX_("EDIT_EVENT",c5,fc,39,c0),
	HX_("CHANGE_EVENT",ab,38,ff,8d),
	::String(null())
};

void FlxUINumericStepper_obj::__register()
{
	FlxUINumericStepper_obj _hx_dummy;
	FlxUINumericStepper_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("flixel.addons.ui.FlxUINumericStepper",f9,94,c6,34);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mMarkFunc = FlxUINumericStepper_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(FlxUINumericStepper_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(FlxUINumericStepper_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< FlxUINumericStepper_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = FlxUINumericStepper_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = FlxUINumericStepper_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = FlxUINumericStepper_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void FlxUINumericStepper_obj::__boot()
{
{
            	HX_STACKFRAME(&_hx_pos_b3434b006136ea9e_27_boot)
HXDLIN(  27)		STACK_VERTICAL = 0;
            	}
{
            	HX_STACKFRAME(&_hx_pos_b3434b006136ea9e_28_boot)
HXDLIN(  28)		STACK_HORIZONTAL = 1;
            	}
{
            	HX_STACKFRAME(&_hx_pos_b3434b006136ea9e_30_boot)
HXDLIN(  30)		CLICK_EVENT = HX_("click_numeric_stepper",28,25,65,6e);
            	}
{
            	HX_STACKFRAME(&_hx_pos_b3434b006136ea9e_31_boot)
HXDLIN(  31)		EDIT_EVENT = HX_("edit_numeric_stepper",ea,96,04,5c);
            	}
{
            	HX_STACKFRAME(&_hx_pos_b3434b006136ea9e_32_boot)
HXDLIN(  32)		CHANGE_EVENT = HX_("change_numeric_stepper",50,0a,cc,bb);
            	}
}

} // end namespace flixel
} // end namespace addons
} // end namespace ui
