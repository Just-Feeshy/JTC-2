#include <hxcpp.h>

#ifndef INCLUDED_95f339a1d026d52c
#define INCLUDED_95f339a1d026d52c
#include "hxMath.h"
#endif
#ifndef INCLUDED_AlphaCharacter
#include <AlphaCharacter.h>
#endif
#ifndef INCLUDED_Alphabet
#include <Alphabet.h>
#endif
#ifndef INCLUDED_CustomKeys
#include <CustomKeys.h>
#endif
#ifndef INCLUDED_MusicBeatSubstate
#include <MusicBeatSubstate.h>
#endif
#ifndef INCLUDED_OptionsSubState
#include <OptionsSubState.h>
#endif
#ifndef INCLUDED_SaveType
#include <SaveType.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_FlxObject
#include <flixel/FlxObject.h>
#endif
#ifndef INCLUDED_flixel_FlxSprite
#include <flixel/FlxSprite.h>
#endif
#ifndef INCLUDED_flixel_FlxState
#include <flixel/FlxState.h>
#endif
#ifndef INCLUDED_flixel_FlxSubState
#include <flixel/FlxSubState.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedSpriteGroup
#include <flixel/group/FlxTypedSpriteGroup.h>
#endif
#ifndef INCLUDED_flixel_input_FlxBaseKeyList
#include <flixel/input/FlxBaseKeyList.h>
#endif
#ifndef INCLUDED_flixel_input_FlxKeyManager
#include <flixel/input/FlxKeyManager.h>
#endif
#ifndef INCLUDED_flixel_input_IFlxInputManager
#include <flixel/input/IFlxInputManager.h>
#endif
#ifndef INCLUDED_flixel_input_keyboard_FlxKeyList
#include <flixel/input/keyboard/FlxKeyList.h>
#endif
#ifndef INCLUDED_flixel_input_keyboard_FlxKeyboard
#include <flixel/input/keyboard/FlxKeyboard.h>
#endif
#ifndef INCLUDED_flixel_input_keyboard__FlxKey_FlxKey_Impl_
#include <flixel/input/keyboard/_FlxKey/FlxKey_Impl_.h>
#endif
#ifndef INCLUDED_flixel_text_FlxText
#include <flixel/text/FlxText.h>
#endif
#ifndef INCLUDED_flixel_text_FlxTextBorderStyle
#include <flixel/text/FlxTextBorderStyle.h>
#endif
#ifndef INCLUDED_flixel_tweens_FlxEase
#include <flixel/tweens/FlxEase.h>
#endif
#ifndef INCLUDED_flixel_tweens_FlxTween
#include <flixel/tweens/FlxTween.h>
#endif
#ifndef INCLUDED_flixel_tweens_misc_VarTween
#include <flixel/tweens/misc/VarTween.h>
#endif
#ifndef INCLUDED_flixel_util_FlxAxes
#include <flixel/util/FlxAxes.h>
#endif
#ifndef INCLUDED_flixel_util_FlxSave
#include <flixel/util/FlxSave.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxDestroyable
#include <flixel/util/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_util__FlxColor_FlxColor_Impl_
#include <flixel/util/_FlxColor/FlxColor_Impl_.h>
#endif
#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_IntMap
#include <haxe/ds/IntMap.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_bd0f5e58e0203c61_56_new,"CustomKeys","new",0xd3eefdd7,"CustomKeys.new","OptionsSubState.hx",56,0xe308bc4f)
HX_DEFINE_STACK_FRAME(_hx_pos_bd0f5e58e0203c61_31_new,"CustomKeys","new",0xd3eefdd7,"CustomKeys.new","OptionsSubState.hx",31,0xe308bc4f)
HX_LOCAL_STACK_FRAME(_hx_pos_bd0f5e58e0203c61_70_update,"CustomKeys","update",0xb38cdcf2,"CustomKeys.update","OptionsSubState.hx",70,0xe308bc4f)
HX_LOCAL_STACK_FRAME(_hx_pos_bd0f5e58e0203c61_152_reloadKeys,"CustomKeys","reloadKeys",0xac560156,"CustomKeys.reloadKeys","OptionsSubState.hx",152,0xe308bc4f)

void CustomKeys_obj::__construct(){
            		HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_0, ::CustomKeys,_gthis) HXARGC(1)
            		void _hx_run( ::flixel::tweens::FlxTween twn){
            			HX_GC_STACKFRAME(&_hx_pos_bd0f5e58e0203c61_56_new)
HXLINE(  57)			_gthis->keys =  ::Alphabet_obj::__alloc( HX_CTX ,( (Float)(0) ),( (Float)(0) ),( (::String)(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic)) ),true,false,null());
HXLINE(  58)			{
HXLINE(  58)				 ::Alphabet _this = _gthis->keys;
HXDLIN(  58)				 ::flixel::util::FlxAxes axes = ::flixel::util::FlxAxes_obj::XY_dyn();
HXDLIN(  58)				bool _hx_tmp;
HXDLIN(  58)				switch((int)(axes->_hx_getIndex())){
            					case (int)0: case (int)2: {
HXLINE(  58)						_hx_tmp = true;
            					}
            					break;
            					default:{
HXLINE(  58)						_hx_tmp = false;
            					}
            				}
HXDLIN(  58)				if (_hx_tmp) {
HXLINE(  58)					int _hx_tmp = ::flixel::FlxG_obj::width;
HXDLIN(  58)					_this->set_x(((( (Float)(_hx_tmp) ) - _this->get_width()) / ( (Float)(2) )));
            				}
HXDLIN(  58)				bool _hx_tmp1;
HXDLIN(  58)				switch((int)(axes->_hx_getIndex())){
            					case (int)1: case (int)2: {
HXLINE(  58)						_hx_tmp1 = true;
            					}
            					break;
            					default:{
HXLINE(  58)						_hx_tmp1 = false;
            					}
            				}
HXDLIN(  58)				if (_hx_tmp1) {
HXLINE(  58)					int _hx_tmp = ::flixel::FlxG_obj::height;
HXDLIN(  58)					_this->set_y(((( (Float)(_hx_tmp) ) - _this->get_height()) / ( (Float)(2) )));
            				}
            			}
HXLINE(  59)			_gthis->add(_gthis->keys).StaticCast<  ::flixel::FlxBasic >();
HXLINE(  61)			_gthis->howManyKey =  ::flixel::text::FlxText_obj::__alloc( HX_CTX ,0,0,::flixel::FlxG_obj::width,HX_("Standard Four Keybinds",8e,09,2f,5f),32,null());
HXLINE(  62)			_gthis->howManyKey->setFormat(HX_("VCR OSD Mono",be,44,e4,b8),32,-1,HX_("center",d5,25,db,05),::flixel::text::FlxTextBorderStyle_obj::OUTLINE_dyn(),-16777216,null());
HXLINE(  63)			_gthis->howManyKey->set_borderSize(( (Float)(2) ));
HXLINE(  64)			{
HXLINE(  64)				 ::flixel::text::FlxText _this1 = _gthis->howManyKey;
HXDLIN(  64)				 ::flixel::util::FlxAxes axes1 = ::flixel::util::FlxAxes_obj::X_dyn();
HXDLIN(  64)				if (::hx::IsNull( axes1 )) {
HXLINE(  64)					axes1 = ::flixel::util::FlxAxes_obj::XY_dyn();
            				}
HXDLIN(  64)				bool _hx_tmp2;
HXDLIN(  64)				switch((int)(axes1->_hx_getIndex())){
            					case (int)0: case (int)2: {
HXLINE(  64)						_hx_tmp2 = true;
            					}
            					break;
            					default:{
HXLINE(  64)						_hx_tmp2 = false;
            					}
            				}
HXDLIN(  64)				if (_hx_tmp2) {
HXLINE(  64)					int _hx_tmp = ::flixel::FlxG_obj::width;
HXDLIN(  64)					_this1->set_x(((( (Float)(_hx_tmp) ) - _this1->get_width()) / ( (Float)(2) )));
            				}
HXDLIN(  64)				bool _hx_tmp3;
HXDLIN(  64)				switch((int)(axes1->_hx_getIndex())){
            					case (int)1: case (int)2: {
HXLINE(  64)						_hx_tmp3 = true;
            					}
            					break;
            					default:{
HXLINE(  64)						_hx_tmp3 = false;
            					}
            				}
HXDLIN(  64)				if (_hx_tmp3) {
HXLINE(  64)					int _hx_tmp = ::flixel::FlxG_obj::height;
HXDLIN(  64)					_this1->set_y(((( (Float)(_hx_tmp) ) - _this1->get_height()) / ( (Float)(2) )));
            				}
            			}
HXLINE(  65)			 ::flixel::text::FlxText _gthis1 = _gthis->howManyKey;
HXDLIN(  65)			Float _hx_tmp4 = _gthis->howManyKey->getScreenCenter(::flixel::util::FlxAxes_obj::Y_dyn());
HXDLIN(  65)			_gthis1->set_y((_hx_tmp4 + (_gthis->keys->get_height() * ((Float)1.5))));
HXLINE(  66)			_gthis->add(_gthis->howManyKey).StaticCast<  ::flixel::FlxBasic >();
            		}
            		HX_END_LOCAL_FUNC1((void))

            	HX_GC_STACKFRAME(&_hx_pos_bd0f5e58e0203c61_31_new)
HXLINE(  44)		this->changedOnSteam = 0;
HXLINE(  43)		this->saveryMapArray = false;
HXLINE(  41)		this->changingKeys = false;
HXLINE(  39)		this->colorSway = ((Float)0);
HXLINE(  37)		this->section = 0;
HXLINE(  46)		 ::CustomKeys _gthis = ::hx::ObjectPtr<OBJ_>(this);
HXLINE(  47)		super::__construct();
HXLINE(  49)		if (::hx::IsLess(  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic))->__Field(HX_("split",da,ea,6e,81),::hx::paccDynamic)(HX_(" ",20,00,00,00))->__Field(HX_("length",e6,94,07,9f),::hx::paccDynamic),4 )) {
HXLINE(  50)			::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("A S W D",cf,cc,09,3a),::hx::paccDynamic);
            		}
HXLINE(  52)		this->bgBlack =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,null(),null(),null())->makeGraphic(::flixel::FlxG_obj::width,::flixel::FlxG_obj::height,-16777216,null(),null());
HXLINE(  53)		this->bgBlack->set_alpha(( (Float)(0) ));
HXLINE(  54)		this->add(this->bgBlack);
HXLINE(  56)		::flixel::tweens::FlxTween_obj::tween(this->bgBlack, ::Dynamic(::hx::Anon_obj::Create(1)
            			->setFixed(0,HX_("alpha",5e,a7,96,21),((Float)0.5))),1, ::Dynamic(::hx::Anon_obj::Create(2)
            			->setFixed(0,HX_("ease",ee,8b,0c,43),::flixel::tweens::FlxEase_obj::quadOut_dyn())
            			->setFixed(1,HX_("onComplete",f8,d4,7e,5d), ::Dynamic(new _hx_Closure_0(_gthis)))));
            	}

Dynamic CustomKeys_obj::__CreateEmpty() { return new CustomKeys_obj; }

void *CustomKeys_obj::_hx_vtable = 0;

Dynamic CustomKeys_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< CustomKeys_obj > _hx_result = new CustomKeys_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool CustomKeys_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x62817b24) {
		if (inClassId<=(int)0x3184f5ed) {
			if (inClassId<=(int)0x27392463) {
				return inClassId==(int)0x00000001 || inClassId==(int)0x27392463;
			} else {
				return inClassId==(int)0x3184f5ed;
			}
		} else {
			return inClassId==(int)0x5661ffbf || inClassId==(int)0x62817b24;
		}
	} else {
		if (inClassId<=(int)0x7ccf8994) {
			return inClassId==(int)0x7c795c9f || inClassId==(int)0x7ccf8994;
		} else {
			return inClassId==(int)0x7fce3ab0;
		}
	}
}

void CustomKeys_obj::update(Float elapsed){
            	HX_STACKFRAME(&_hx_pos_bd0f5e58e0203c61_70_update)
HXLINE(  71)		if (::hx::IsNotNull( this->keys )) {
HXLINE(  72)			 ::CustomKeys _hx_tmp = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN(  72)			_hx_tmp->colorSway = (_hx_tmp->colorSway + elapsed);
HXLINE(  74)			{
HXLINE(  74)				int _g = 0;
HXDLIN(  74)				int _g1 = this->keys->letters->length;
HXDLIN(  74)				while((_g < _g1)){
HXLINE(  74)					_g = (_g + 1);
HXDLIN(  74)					int i = (_g - 1);
HXLINE(  75)					if ((this->keys->letters->__get(i).StaticCast<  ::AlphaCharacter >()->spaceLocation == this->section)) {
HXLINE(  76)						 ::AlphaCharacter _hx_tmp = this->keys->letters->__get(i).StaticCast<  ::AlphaCharacter >();
HXDLIN(  76)						Float Red = (((Float)0.6) + (::Math_obj::sin((this->colorSway * ::Math_obj::PI)) * ((Float)0.4)));
HXDLIN(  76)						Float Green = (((Float)0.6) + (::Math_obj::sin((this->colorSway * ::Math_obj::PI)) * ((Float)0.4)));
HXDLIN(  76)						Float Blue = (((Float)0.6) + (::Math_obj::sin((this->colorSway * ::Math_obj::PI)) * ((Float)0.4)));
HXDLIN(  76)						Float Alpha = ( (Float)(1) );
HXDLIN(  76)						int color = ::flixel::util::_FlxColor::FlxColor_Impl__obj::_new(null());
HXDLIN(  76)						{
HXLINE(  76)							int Value = ::Math_obj::round((Red * ( (Float)(255) )));
HXDLIN(  76)							color = (color & -16711681);
HXDLIN(  76)							int color1;
HXDLIN(  76)							if ((Value > 255)) {
HXLINE(  76)								color1 = 255;
            							}
            							else {
HXLINE(  76)								if ((Value < 0)) {
HXLINE(  76)									color1 = 0;
            								}
            								else {
HXLINE(  76)									color1 = Value;
            								}
            							}
HXDLIN(  76)							color = (color | (color1 << 16));
            						}
HXDLIN(  76)						{
HXLINE(  76)							int Value1 = ::Math_obj::round((Green * ( (Float)(255) )));
HXDLIN(  76)							color = (color & -65281);
HXDLIN(  76)							int color2;
HXDLIN(  76)							if ((Value1 > 255)) {
HXLINE(  76)								color2 = 255;
            							}
            							else {
HXLINE(  76)								if ((Value1 < 0)) {
HXLINE(  76)									color2 = 0;
            								}
            								else {
HXLINE(  76)									color2 = Value1;
            								}
            							}
HXDLIN(  76)							color = (color | (color2 << 8));
            						}
HXDLIN(  76)						{
HXLINE(  76)							int Value2 = ::Math_obj::round((Blue * ( (Float)(255) )));
HXDLIN(  76)							color = (color & -256);
HXDLIN(  76)							int color3;
HXDLIN(  76)							if ((Value2 > 255)) {
HXLINE(  76)								color3 = 255;
            							}
            							else {
HXLINE(  76)								if ((Value2 < 0)) {
HXLINE(  76)									color3 = 0;
            								}
            								else {
HXLINE(  76)									color3 = Value2;
            								}
            							}
HXDLIN(  76)							color = (color | color3);
            						}
HXDLIN(  76)						{
HXLINE(  76)							int Value3 = ::Math_obj::round((Alpha * ( (Float)(255) )));
HXDLIN(  76)							color = (color & 16777215);
HXDLIN(  76)							int color4;
HXDLIN(  76)							if ((Value3 > 255)) {
HXLINE(  76)								color4 = 255;
            							}
            							else {
HXLINE(  76)								if ((Value3 < 0)) {
HXLINE(  76)									color4 = 0;
            								}
            								else {
HXLINE(  76)									color4 = Value3;
            								}
            							}
HXDLIN(  76)							color = (color | (color4 << 24));
            						}
HXDLIN(  76)						_hx_tmp->set_color(color);
            					}
            				}
            			}
            		}
HXLINE(  83)		bool _hx_tmp;
HXDLIN(  83)		if (( ( ::flixel::input::FlxBaseKeyList)(::flixel::FlxG_obj::keys->justPressed) )->get_ANY()) {
HXLINE(  83)			_hx_tmp = !(this->changingKeys);
            		}
            		else {
HXLINE(  83)			_hx_tmp = false;
            		}
HXDLIN(  83)		if (_hx_tmp) {
HXLINE(  84)			if (!(this->saveryMapArray)) {
HXLINE(  85)				this->changingKeys = true;
HXLINE(  87)				::Array< ::String > containKeys = ( (::Array< ::String >)( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic))->__Field(HX_("split",da,ea,6e,81),::hx::paccDynamic)(HX_(" ",20,00,00,00))) );
HXLINE(  88)				::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
HXLINE(  90)				{
HXLINE(  90)					int _g = 0;
HXDLIN(  90)					int _g1 = containKeys->length;
HXDLIN(  90)					while((_g < _g1)){
HXLINE(  90)						_g = (_g + 1);
HXDLIN(  90)						int i = (_g - 1);
HXLINE(  91)						if ((this->section == i)) {
HXLINE(  92)							 ::Dynamic fh = ::flixel::FlxG_obj::save->data;
HXDLIN(  92)							::String _hx_tmp = ::Std_obj::string( ::Dynamic(fh->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic)));
HXDLIN(  92)							::Dynamic this1 = ::flixel::input::keyboard::_FlxKey::FlxKey_Impl__obj::toStringMap;
HXDLIN(  92)							fh->__SetField(HX_("customKeys",45,c2,ae,a4),(_hx_tmp + (( ( ::haxe::ds::IntMap)(this1) )->get(::flixel::FlxG_obj::keys->firstJustPressed()) + HX_(" ",20,00,00,00))),::hx::paccDynamic);
            						}
            						else {
HXLINE(  94)							 ::Dynamic fh = ::flixel::FlxG_obj::save->data;
HXDLIN(  94)							::String _hx_tmp = ::Std_obj::string( ::Dynamic(fh->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic)));
HXDLIN(  94)							fh->__SetField(HX_("customKeys",45,c2,ae,a4),(_hx_tmp + (containKeys->__get(i) + HX_(" ",20,00,00,00))),::hx::paccDynamic);
            						}
            					}
            				}
HXLINE(  98)				::String trimmed = ( (::String)(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic)) );
HXLINE(  99)				::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),::StringTools_obj::rtrim(trimmed),::hx::paccDynamic);
HXLINE( 101)				 ::CustomKeys _hx_tmp = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN( 101)				_hx_tmp->section = (_hx_tmp->section + 1);
HXLINE( 102)				this->reloadKeys(( (::String)(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic)) ));
HXLINE( 104)				if ((this->section >= containKeys->length)) {
HXLINE( 105)					this->section = 0;
HXLINE( 106)					{
HXLINE( 106)						 ::Dynamic _hx_tmp;
HXDLIN( 106)						switch((int)(::SaveType_obj::DOWNSCROLL_dyn()->_hx_getIndex())){
            							case (int)1: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            							}
            							break;
            							case (int)2: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)3: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            							}
            							break;
            							case (int)4: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)5: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            							}
            							break;
            							case (int)6: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)7: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)8: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            							}
            							break;
            							case (int)9: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            							}
            							break;
            							case (int)10: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            							}
            							break;
            							case (int)11: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            							}
            							break;
            							case (int)12: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            							}
            							break;
            							case (int)13: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            							}
            							break;
            							case (int)14: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            							}
            							break;
            							case (int)15: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            							}
            							break;
            							case (int)16: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)17: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            							}
            							break;
            							case (int)18: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            							}
            							break;
            							case (int)19: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            							}
            							break;
            							case (int)20: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            							}
            							break;
            							case (int)21: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            							}
            							break;
            							default:{
HXLINE( 106)								_hx_tmp = null();
            							}
            						}
HXDLIN( 106)						::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),_hx_tmp,::hx::paccDynamic);
HXDLIN( 106)						 ::Dynamic _hx_tmp1;
HXDLIN( 106)						switch((int)(::SaveType_obj::PRESET_KEYBINDS_dyn()->_hx_getIndex())){
            							case (int)1: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            							}
            							break;
            							case (int)2: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)3: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            							}
            							break;
            							case (int)4: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)5: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            							}
            							break;
            							case (int)6: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)7: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)8: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            							}
            							break;
            							case (int)9: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            							}
            							break;
            							case (int)10: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            							}
            							break;
            							case (int)11: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            							}
            							break;
            							case (int)12: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            							}
            							break;
            							case (int)13: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            							}
            							break;
            							case (int)14: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            							}
            							break;
            							case (int)15: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            							}
            							break;
            							case (int)16: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)17: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            							}
            							break;
            							case (int)18: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            							}
            							break;
            							case (int)19: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            							}
            							break;
            							case (int)20: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            							}
            							break;
            							case (int)21: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            							}
            							break;
            							default:{
HXLINE( 106)								_hx_tmp1 = null();
            							}
            						}
HXDLIN( 106)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),_hx_tmp1,::hx::paccDynamic);
HXDLIN( 106)						 ::Dynamic _hx_tmp2;
HXDLIN( 106)						switch((int)(::SaveType_obj::PERFECT_MODE_MOD_dyn()->_hx_getIndex())){
            							case (int)1: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            							}
            							break;
            							case (int)2: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)3: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            							}
            							break;
            							case (int)4: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)5: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            							}
            							break;
            							case (int)6: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)7: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)8: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            							}
            							break;
            							case (int)9: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            							}
            							break;
            							case (int)10: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            							}
            							break;
            							case (int)11: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            							}
            							break;
            							case (int)12: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            							}
            							break;
            							case (int)13: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            							}
            							break;
            							case (int)14: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            							}
            							break;
            							case (int)15: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            							}
            							break;
            							case (int)16: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)17: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            							}
            							break;
            							case (int)18: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            							}
            							break;
            							case (int)19: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            							}
            							break;
            							case (int)20: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            							}
            							break;
            							case (int)21: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            							}
            							break;
            							default:{
HXLINE( 106)								_hx_tmp2 = null();
            							}
            						}
HXDLIN( 106)						::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),_hx_tmp2,::hx::paccDynamic);
HXDLIN( 106)						 ::Dynamic _hx_tmp3;
HXDLIN( 106)						switch((int)(::SaveType_obj::FLIP_CHART_MOD_dyn()->_hx_getIndex())){
            							case (int)1: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            							}
            							break;
            							case (int)2: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)3: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            							}
            							break;
            							case (int)4: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)5: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            							}
            							break;
            							case (int)6: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)7: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)8: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            							}
            							break;
            							case (int)9: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            							}
            							break;
            							case (int)10: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            							}
            							break;
            							case (int)11: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            							}
            							break;
            							case (int)12: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            							}
            							break;
            							case (int)13: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            							}
            							break;
            							case (int)14: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            							}
            							break;
            							case (int)15: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            							}
            							break;
            							case (int)16: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)17: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            							}
            							break;
            							case (int)18: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            							}
            							break;
            							case (int)19: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            							}
            							break;
            							case (int)20: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            							}
            							break;
            							case (int)21: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            							}
            							break;
            							default:{
HXLINE( 106)								_hx_tmp3 = null();
            							}
            						}
HXDLIN( 106)						::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),_hx_tmp3,::hx::paccDynamic);
HXDLIN( 106)						 ::Dynamic _hx_tmp4;
HXDLIN( 106)						switch((int)(::SaveType_obj::CUSTOM_HELL_MOD_dyn()->_hx_getIndex())){
            							case (int)1: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            							}
            							break;
            							case (int)2: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)3: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            							}
            							break;
            							case (int)4: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)5: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            							}
            							break;
            							case (int)6: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)7: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)8: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            							}
            							break;
            							case (int)9: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            							}
            							break;
            							case (int)10: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            							}
            							break;
            							case (int)11: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            							}
            							break;
            							case (int)12: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            							}
            							break;
            							case (int)13: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            							}
            							break;
            							case (int)14: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            							}
            							break;
            							case (int)15: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            							}
            							break;
            							case (int)16: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)17: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            							}
            							break;
            							case (int)18: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            							}
            							break;
            							case (int)19: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            							}
            							break;
            							case (int)20: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            							}
            							break;
            							case (int)21: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            							}
            							break;
            							default:{
HXLINE( 106)								_hx_tmp4 = null();
            							}
            						}
HXDLIN( 106)						::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),_hx_tmp4,::hx::paccDynamic);
HXDLIN( 106)						 ::Dynamic _hx_tmp5;
HXDLIN( 106)						switch((int)(::SaveType_obj::FAIR_BATTLE_MOD_dyn()->_hx_getIndex())){
            							case (int)1: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            							}
            							break;
            							case (int)2: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)3: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            							}
            							break;
            							case (int)4: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)5: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            							}
            							break;
            							case (int)6: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)7: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)8: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            							}
            							break;
            							case (int)9: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            							}
            							break;
            							case (int)10: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            							}
            							break;
            							case (int)11: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            							}
            							break;
            							case (int)12: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            							}
            							break;
            							case (int)13: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            							}
            							break;
            							case (int)14: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            							}
            							break;
            							case (int)15: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            							}
            							break;
            							case (int)16: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)17: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            							}
            							break;
            							case (int)18: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            							}
            							break;
            							case (int)19: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            							}
            							break;
            							case (int)20: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            							}
            							break;
            							case (int)21: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            							}
            							break;
            							default:{
HXLINE( 106)								_hx_tmp5 = null();
            							}
            						}
HXDLIN( 106)						::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),_hx_tmp5,::hx::paccDynamic);
HXDLIN( 106)						 ::Dynamic _hx_tmp6;
HXDLIN( 106)						switch((int)(::SaveType_obj::FADE_BATTLE_MOD_dyn()->_hx_getIndex())){
            							case (int)1: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            							}
            							break;
            							case (int)2: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)3: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            							}
            							break;
            							case (int)4: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)5: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            							}
            							break;
            							case (int)6: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)7: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)8: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            							}
            							break;
            							case (int)9: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            							}
            							break;
            							case (int)10: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            							}
            							break;
            							case (int)11: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            							}
            							break;
            							case (int)12: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            							}
            							break;
            							case (int)13: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            							}
            							break;
            							case (int)14: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            							}
            							break;
            							case (int)15: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            							}
            							break;
            							case (int)16: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)17: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            							}
            							break;
            							case (int)18: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            							}
            							break;
            							case (int)19: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            							}
            							break;
            							case (int)20: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            							}
            							break;
            							case (int)21: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            							}
            							break;
            							default:{
HXLINE( 106)								_hx_tmp6 = null();
            							}
            						}
HXDLIN( 106)						::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),_hx_tmp6,::hx::paccDynamic);
HXDLIN( 106)						 ::Dynamic _hx_tmp7;
HXDLIN( 106)						switch((int)(::SaveType_obj::SHOW_BOTTOM_BAR_dyn()->_hx_getIndex())){
            							case (int)1: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            							}
            							break;
            							case (int)2: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)3: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            							}
            							break;
            							case (int)4: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)5: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            							}
            							break;
            							case (int)6: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)7: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)8: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            							}
            							break;
            							case (int)9: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            							}
            							break;
            							case (int)10: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            							}
            							break;
            							case (int)11: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            							}
            							break;
            							case (int)12: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            							}
            							break;
            							case (int)13: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            							}
            							break;
            							case (int)14: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            							}
            							break;
            							case (int)15: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            							}
            							break;
            							case (int)16: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)17: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            							}
            							break;
            							case (int)18: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            							}
            							break;
            							case (int)19: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            							}
            							break;
            							case (int)20: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            							}
            							break;
            							case (int)21: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            							}
            							break;
            							default:{
HXLINE( 106)								_hx_tmp7 = null();
            							}
            						}
HXDLIN( 106)						::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),_hx_tmp7,::hx::paccDynamic);
HXDLIN( 106)						 ::Dynamic _hx_tmp8;
HXDLIN( 106)						switch((int)(::SaveType_obj::SHOW_NOTE_SPLASH_dyn()->_hx_getIndex())){
            							case (int)1: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            							}
            							break;
            							case (int)2: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)3: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            							}
            							break;
            							case (int)4: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)5: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            							}
            							break;
            							case (int)6: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)7: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)8: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            							}
            							break;
            							case (int)9: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            							}
            							break;
            							case (int)10: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            							}
            							break;
            							case (int)11: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            							}
            							break;
            							case (int)12: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            							}
            							break;
            							case (int)13: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            							}
            							break;
            							case (int)14: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            							}
            							break;
            							case (int)15: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            							}
            							break;
            							case (int)16: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)17: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            							}
            							break;
            							case (int)18: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            							}
            							break;
            							case (int)19: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            							}
            							break;
            							case (int)20: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            							}
            							break;
            							case (int)21: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            							}
            							break;
            							default:{
HXLINE( 106)								_hx_tmp8 = null();
            							}
            						}
HXDLIN( 106)						::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),_hx_tmp8,::hx::paccDynamic);
HXDLIN( 106)						 ::Dynamic _hx_tmp9;
HXDLIN( 106)						switch((int)(::SaveType_obj::GRAPHICS_dyn()->_hx_getIndex())){
            							case (int)1: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            							}
            							break;
            							case (int)2: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)3: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            							}
            							break;
            							case (int)4: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)5: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            							}
            							break;
            							case (int)6: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)7: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)8: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            							}
            							break;
            							case (int)9: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            							}
            							break;
            							case (int)10: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            							}
            							break;
            							case (int)11: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            							}
            							break;
            							case (int)12: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            							}
            							break;
            							case (int)13: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            							}
            							break;
            							case (int)14: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            							}
            							break;
            							case (int)15: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            							}
            							break;
            							case (int)16: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)17: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            							}
            							break;
            							case (int)18: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            							}
            							break;
            							case (int)19: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            							}
            							break;
            							case (int)20: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            							}
            							break;
            							case (int)21: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            							}
            							break;
            							default:{
HXLINE( 106)								_hx_tmp9 = null();
            							}
            						}
HXDLIN( 106)						::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),_hx_tmp9,::hx::paccDynamic);
HXDLIN( 106)						 ::Dynamic _hx_tmp10;
HXDLIN( 106)						switch((int)(::SaveType_obj::SET_FPS_DEFAULT_dyn()->_hx_getIndex())){
            							case (int)1: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            							}
            							break;
            							case (int)2: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)3: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            							}
            							break;
            							case (int)4: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)5: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            							}
            							break;
            							case (int)6: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)7: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)8: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            							}
            							break;
            							case (int)9: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            							}
            							break;
            							case (int)10: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            							}
            							break;
            							case (int)11: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            							}
            							break;
            							case (int)12: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            							}
            							break;
            							case (int)13: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            							}
            							break;
            							case (int)14: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            							}
            							break;
            							case (int)15: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            							}
            							break;
            							case (int)16: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)17: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            							}
            							break;
            							case (int)18: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            							}
            							break;
            							case (int)19: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            							}
            							break;
            							case (int)20: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            							}
            							break;
            							case (int)21: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            							}
            							break;
            							default:{
HXLINE( 106)								_hx_tmp10 = null();
            							}
            						}
HXDLIN( 106)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),_hx_tmp10,::hx::paccDynamic);
HXDLIN( 106)						 ::Dynamic _hx_tmp11;
HXDLIN( 106)						switch((int)(::SaveType_obj::FPS_MULTIPLIER_dyn()->_hx_getIndex())){
            							case (int)1: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            							}
            							break;
            							case (int)2: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)3: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            							}
            							break;
            							case (int)4: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)5: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            							}
            							break;
            							case (int)6: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)7: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)8: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            							}
            							break;
            							case (int)9: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            							}
            							break;
            							case (int)10: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            							}
            							break;
            							case (int)11: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            							}
            							break;
            							case (int)12: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            							}
            							break;
            							case (int)13: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            							}
            							break;
            							case (int)14: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            							}
            							break;
            							case (int)15: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            							}
            							break;
            							case (int)16: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)17: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            							}
            							break;
            							case (int)18: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            							}
            							break;
            							case (int)19: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            							}
            							break;
            							case (int)20: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            							}
            							break;
            							case (int)21: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            							}
            							break;
            							default:{
HXLINE( 106)								_hx_tmp11 = null();
            							}
            						}
HXDLIN( 106)						::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),_hx_tmp11,::hx::paccDynamic);
HXDLIN( 106)						 ::Dynamic _hx_tmp12;
HXDLIN( 106)						switch((int)(::SaveType_obj::NO_BLUE_BALLS_MOD_dyn()->_hx_getIndex())){
            							case (int)1: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            							}
            							break;
            							case (int)2: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)3: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            							}
            							break;
            							case (int)4: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)5: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            							}
            							break;
            							case (int)6: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)7: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)8: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            							}
            							break;
            							case (int)9: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            							}
            							break;
            							case (int)10: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            							}
            							break;
            							case (int)11: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            							}
            							break;
            							case (int)12: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            							}
            							break;
            							case (int)13: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            							}
            							break;
            							case (int)14: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            							}
            							break;
            							case (int)15: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            							}
            							break;
            							case (int)16: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)17: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            							}
            							break;
            							case (int)18: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            							}
            							break;
            							case (int)19: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            							}
            							break;
            							case (int)20: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            							}
            							break;
            							case (int)21: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            							}
            							break;
            							default:{
HXLINE( 106)								_hx_tmp12 = null();
            							}
            						}
HXDLIN( 106)						::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),_hx_tmp12,::hx::paccDynamic);
HXDLIN( 106)						 ::Dynamic _hx_tmp13;
HXDLIN( 106)						switch((int)(::SaveType_obj::BLIND_MOD_dyn()->_hx_getIndex())){
            							case (int)1: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            							}
            							break;
            							case (int)2: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)3: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            							}
            							break;
            							case (int)4: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)5: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            							}
            							break;
            							case (int)6: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)7: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)8: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            							}
            							break;
            							case (int)9: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            							}
            							break;
            							case (int)10: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            							}
            							break;
            							case (int)11: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            							}
            							break;
            							case (int)12: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            							}
            							break;
            							case (int)13: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            							}
            							break;
            							case (int)14: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            							}
            							break;
            							case (int)15: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            							}
            							break;
            							case (int)16: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)17: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            							}
            							break;
            							case (int)18: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            							}
            							break;
            							case (int)19: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            							}
            							break;
            							case (int)20: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            							}
            							break;
            							case (int)21: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            							}
            							break;
            							default:{
HXLINE( 106)								_hx_tmp13 = null();
            							}
            						}
HXDLIN( 106)						::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),_hx_tmp13,::hx::paccDynamic);
HXDLIN( 106)						 ::Dynamic _hx_tmp14;
HXDLIN( 106)						switch((int)(::SaveType_obj::X_WOBBLE_MOD_dyn()->_hx_getIndex())){
            							case (int)1: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            							}
            							break;
            							case (int)2: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)3: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            							}
            							break;
            							case (int)4: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)5: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            							}
            							break;
            							case (int)6: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)7: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)8: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            							}
            							break;
            							case (int)9: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            							}
            							break;
            							case (int)10: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            							}
            							break;
            							case (int)11: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            							}
            							break;
            							case (int)12: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            							}
            							break;
            							case (int)13: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            							}
            							break;
            							case (int)14: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            							}
            							break;
            							case (int)15: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            							}
            							break;
            							case (int)16: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)17: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            							}
            							break;
            							case (int)18: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            							}
            							break;
            							case (int)19: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            							}
            							break;
            							case (int)20: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            							}
            							break;
            							case (int)21: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            							}
            							break;
            							default:{
HXLINE( 106)								_hx_tmp14 = null();
            							}
            						}
HXDLIN( 106)						::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),_hx_tmp14,::hx::paccDynamic);
HXDLIN( 106)						 ::Dynamic _hx_tmp15;
HXDLIN( 106)						switch((int)(::SaveType_obj::PRESET_INPUTS_dyn()->_hx_getIndex())){
            							case (int)1: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            							}
            							break;
            							case (int)2: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)3: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            							}
            							break;
            							case (int)4: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)5: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            							}
            							break;
            							case (int)6: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)7: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)8: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            							}
            							break;
            							case (int)9: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            							}
            							break;
            							case (int)10: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            							}
            							break;
            							case (int)11: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            							}
            							break;
            							case (int)12: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            							}
            							break;
            							case (int)13: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            							}
            							break;
            							case (int)14: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            							}
            							break;
            							case (int)15: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            							}
            							break;
            							case (int)16: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)17: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            							}
            							break;
            							case (int)18: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            							}
            							break;
            							case (int)19: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            							}
            							break;
            							case (int)20: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            							}
            							break;
            							case (int)21: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            							}
            							break;
            							default:{
HXLINE( 106)								_hx_tmp15 = null();
            							}
            						}
HXDLIN( 106)						::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),_hx_tmp15,::hx::paccDynamic);
HXDLIN( 106)						 ::Dynamic _hx_tmp16;
HXDLIN( 106)						switch((int)(::SaveType_obj::CACHE_ASSETS_dyn()->_hx_getIndex())){
            							case (int)1: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            							}
            							break;
            							case (int)2: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)3: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            							}
            							break;
            							case (int)4: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)5: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            							}
            							break;
            							case (int)6: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)7: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)8: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            							}
            							break;
            							case (int)9: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            							}
            							break;
            							case (int)10: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            							}
            							break;
            							case (int)11: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            							}
            							break;
            							case (int)12: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            							}
            							break;
            							case (int)13: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            							}
            							break;
            							case (int)14: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            							}
            							break;
            							case (int)15: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            							}
            							break;
            							case (int)16: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)17: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            							}
            							break;
            							case (int)18: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            							}
            							break;
            							case (int)19: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            							}
            							break;
            							case (int)20: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            							}
            							break;
            							case (int)21: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            							}
            							break;
            							default:{
HXLINE( 106)								_hx_tmp16 = null();
            							}
            						}
HXDLIN( 106)						::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),_hx_tmp16,::hx::paccDynamic);
HXDLIN( 106)						 ::Dynamic _hx_tmp17;
HXDLIN( 106)						switch((int)(::SaveType_obj::CUSTOM_KEYBINDS_dyn()->_hx_getIndex())){
            							case (int)1: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            							}
            							break;
            							case (int)2: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)3: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            							}
            							break;
            							case (int)4: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)5: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            							}
            							break;
            							case (int)6: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)7: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)8: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            							}
            							break;
            							case (int)9: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            							}
            							break;
            							case (int)10: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            							}
            							break;
            							case (int)11: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            							}
            							break;
            							case (int)12: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            							}
            							break;
            							case (int)13: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            							}
            							break;
            							case (int)14: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            							}
            							break;
            							case (int)15: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            							}
            							break;
            							case (int)16: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)17: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            							}
            							break;
            							case (int)18: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            							}
            							break;
            							case (int)19: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            							}
            							break;
            							case (int)20: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            							}
            							break;
            							case (int)21: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            							}
            							break;
            							default:{
HXLINE( 106)								_hx_tmp17 = null();
            							}
            						}
HXDLIN( 106)						::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),_hx_tmp17,::hx::paccDynamic);
HXDLIN( 106)						 ::Dynamic _hx_tmp18;
HXDLIN( 106)						switch((int)(::SaveType_obj::CAMERA_MOVEMENT_MOD_dyn()->_hx_getIndex())){
            							case (int)1: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            							}
            							break;
            							case (int)2: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)3: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            							}
            							break;
            							case (int)4: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)5: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            							}
            							break;
            							case (int)6: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)7: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)8: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            							}
            							break;
            							case (int)9: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            							}
            							break;
            							case (int)10: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            							}
            							break;
            							case (int)11: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            							}
            							break;
            							case (int)12: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            							}
            							break;
            							case (int)13: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            							}
            							break;
            							case (int)14: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            							}
            							break;
            							case (int)15: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            							}
            							break;
            							case (int)16: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)17: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            							}
            							break;
            							case (int)18: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            							}
            							break;
            							case (int)19: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            							}
            							break;
            							case (int)20: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            							}
            							break;
            							case (int)21: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            							}
            							break;
            							default:{
HXLINE( 106)								_hx_tmp18 = null();
            							}
            						}
HXDLIN( 106)						::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),_hx_tmp18,::hx::paccDynamic);
HXDLIN( 106)						 ::Dynamic _hx_tmp19;
HXDLIN( 106)						switch((int)(::SaveType_obj::GHOST_TAPPING_dyn()->_hx_getIndex())){
            							case (int)1: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            							}
            							break;
            							case (int)2: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)3: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            							}
            							break;
            							case (int)4: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)5: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            							}
            							break;
            							case (int)6: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)7: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)8: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            							}
            							break;
            							case (int)9: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            							}
            							break;
            							case (int)10: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            							}
            							break;
            							case (int)11: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            							}
            							break;
            							case (int)12: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            							}
            							break;
            							case (int)13: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            							}
            							break;
            							case (int)14: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            							}
            							break;
            							case (int)15: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            							}
            							break;
            							case (int)16: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)17: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            							}
            							break;
            							case (int)18: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            							}
            							break;
            							case (int)19: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            							}
            							break;
            							case (int)20: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            							}
            							break;
            							case (int)21: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            							}
            							break;
            							default:{
HXLINE( 106)								_hx_tmp19 = null();
            							}
            						}
HXDLIN( 106)						::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),_hx_tmp19,::hx::paccDynamic);
HXDLIN( 106)						 ::Dynamic _hx_tmp20;
HXDLIN( 106)						switch((int)(::SaveType_obj::CUSTOM_MENU_BINDS_dyn()->_hx_getIndex())){
            							case (int)1: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            							}
            							break;
            							case (int)2: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)3: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            							}
            							break;
            							case (int)4: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)5: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            							}
            							break;
            							case (int)6: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)7: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            							}
            							break;
            							case (int)8: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            							}
            							break;
            							case (int)9: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            							}
            							break;
            							case (int)10: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            							}
            							break;
            							case (int)11: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            								}
            								else {
HXLINE( 106)									if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 106)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            								}
HXDLIN( 106)								_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            							}
            							break;
            							case (int)12: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            							}
            							break;
            							case (int)13: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            							}
            							break;
            							case (int)14: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            							}
            							break;
            							case (int)15: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            							}
            							break;
            							case (int)16: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            							}
            							break;
            							case (int)17: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            							}
            							break;
            							case (int)18: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            							}
            							break;
            							case (int)19: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            							}
            							break;
            							case (int)20: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            							}
            							break;
            							case (int)21: {
HXLINE( 106)								if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 106)									::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            								}
HXDLIN( 106)								_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            							}
            							break;
            							default:{
HXLINE( 106)								_hx_tmp20 = null();
            							}
            						}
HXDLIN( 106)						::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),_hx_tmp20,::hx::paccDynamic);
HXDLIN( 106)						::flixel::FlxG_obj::save->flush(null(),null());
            					}
HXLINE( 107)					this->saveryMapArray = true;
HXLINE( 109)					this->reloadKeys(( (::String)( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic))->__GetItem(this->changedOnSteam)) ));
HXLINE( 111)					if ((this->changedOnSteam == 0)) {
HXLINE( 112)						this->howManyKey->set_text(HX_("Middle Keybind For Five Keys",5c,1c,37,cb));
            					}
            				}
HXLINE( 115)				this->changingKeys = false;
            			}
            			else {
HXLINE( 116)				if (this->saveryMapArray) {
HXLINE( 117)					this->changingKeys = true;
HXLINE( 119)					::Array< ::String > containKeys = ( (::Array< ::String >)( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic))->__GetItem(this->changedOnSteam)->__Field(HX_("split",da,ea,6e,81),::hx::paccDynamic)(HX_(" ",20,00,00,00))) );
HXLINE( 121)					 ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic))->__SetItem(this->changedOnSteam,HX_("",00,00,00,00));
HXLINE( 123)					{
HXLINE( 123)						int _g = 0;
HXDLIN( 123)						int _g1 = containKeys->length;
HXDLIN( 123)						while((_g < _g1)){
HXLINE( 123)							_g = (_g + 1);
HXDLIN( 123)							int i = (_g - 1);
HXLINE( 124)							if ((this->section == i)) {
HXLINE( 125)								 ::Dynamic base =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
HXDLIN( 125)								int index = this->changedOnSteam;
HXDLIN( 125)								::String base1 = ( (::String)(base->__GetItem(index)) );
HXDLIN( 125)								::Dynamic this1 = ::flixel::input::keyboard::_FlxKey::FlxKey_Impl__obj::toStringMap;
HXDLIN( 125)								base->__SetItem(index,(base1 + (( ( ::haxe::ds::IntMap)(this1) )->get(::flixel::FlxG_obj::keys->firstJustPressed()) + HX_(" ",20,00,00,00))));
            							}
            							else {
HXLINE( 127)								 ::Dynamic base =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
HXDLIN( 127)								int index = this->changedOnSteam;
HXDLIN( 127)								base->__SetItem(index,(base->__GetItem(index) + (containKeys->__get(i) + HX_(" ",20,00,00,00))));
            							}
            						}
            					}
HXLINE( 131)					::String trimmed = ( (::String)( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic))->__GetItem(this->changedOnSteam)) );
HXLINE( 132)					 ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic))->__SetItem(this->changedOnSteam,::StringTools_obj::rtrim(trimmed));
HXLINE( 134)					 ::CustomKeys _hx_tmp = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN( 134)					_hx_tmp->section = (_hx_tmp->section + 1);
HXLINE( 135)					this->reloadKeys(( (::String)( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic))->__GetItem(this->changedOnSteam)) ));
HXLINE( 137)					if ((this->section >= containKeys->length)) {
HXLINE( 138)						this->section = 0;
HXLINE( 139)						{
HXLINE( 139)							 ::Dynamic _hx_tmp;
HXDLIN( 139)							switch((int)(::SaveType_obj::DOWNSCROLL_dyn()->_hx_getIndex())){
            								case (int)1: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            								}
            								break;
            								case (int)2: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)3: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            								}
            								break;
            								case (int)4: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)5: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            								}
            								break;
            								case (int)6: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)7: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)8: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            								}
            								break;
            								case (int)9: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            								}
            								break;
            								case (int)10: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            								}
            								break;
            								case (int)11: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            								}
            								break;
            								case (int)12: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            								}
            								break;
            								case (int)13: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            								}
            								break;
            								case (int)14: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            								}
            								break;
            								case (int)15: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            								}
            								break;
            								case (int)16: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)17: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            								}
            								break;
            								case (int)18: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            								}
            								break;
            								case (int)19: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            								}
            								break;
            								case (int)20: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            								}
            								break;
            								case (int)21: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            								}
            								break;
            								default:{
HXLINE( 139)									_hx_tmp = null();
            								}
            							}
HXDLIN( 139)							::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),_hx_tmp,::hx::paccDynamic);
HXDLIN( 139)							 ::Dynamic _hx_tmp1;
HXDLIN( 139)							switch((int)(::SaveType_obj::PRESET_KEYBINDS_dyn()->_hx_getIndex())){
            								case (int)1: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            								}
            								break;
            								case (int)2: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)3: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            								}
            								break;
            								case (int)4: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)5: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            								}
            								break;
            								case (int)6: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)7: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)8: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            								}
            								break;
            								case (int)9: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            								}
            								break;
            								case (int)10: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            								}
            								break;
            								case (int)11: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            								}
            								break;
            								case (int)12: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            								}
            								break;
            								case (int)13: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            								}
            								break;
            								case (int)14: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            								}
            								break;
            								case (int)15: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            								}
            								break;
            								case (int)16: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)17: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            								}
            								break;
            								case (int)18: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            								}
            								break;
            								case (int)19: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            								}
            								break;
            								case (int)20: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            								}
            								break;
            								case (int)21: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp1 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            								}
            								break;
            								default:{
HXLINE( 139)									_hx_tmp1 = null();
            								}
            							}
HXDLIN( 139)							::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),_hx_tmp1,::hx::paccDynamic);
HXDLIN( 139)							 ::Dynamic _hx_tmp2;
HXDLIN( 139)							switch((int)(::SaveType_obj::PERFECT_MODE_MOD_dyn()->_hx_getIndex())){
            								case (int)1: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            								}
            								break;
            								case (int)2: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)3: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            								}
            								break;
            								case (int)4: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)5: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            								}
            								break;
            								case (int)6: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)7: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)8: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            								}
            								break;
            								case (int)9: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            								}
            								break;
            								case (int)10: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            								}
            								break;
            								case (int)11: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            								}
            								break;
            								case (int)12: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            								}
            								break;
            								case (int)13: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            								}
            								break;
            								case (int)14: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            								}
            								break;
            								case (int)15: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            								}
            								break;
            								case (int)16: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)17: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            								}
            								break;
            								case (int)18: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            								}
            								break;
            								case (int)19: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            								}
            								break;
            								case (int)20: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            								}
            								break;
            								case (int)21: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            								}
            								break;
            								default:{
HXLINE( 139)									_hx_tmp2 = null();
            								}
            							}
HXDLIN( 139)							::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),_hx_tmp2,::hx::paccDynamic);
HXDLIN( 139)							 ::Dynamic _hx_tmp3;
HXDLIN( 139)							switch((int)(::SaveType_obj::FLIP_CHART_MOD_dyn()->_hx_getIndex())){
            								case (int)1: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            								}
            								break;
            								case (int)2: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)3: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            								}
            								break;
            								case (int)4: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)5: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            								}
            								break;
            								case (int)6: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)7: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)8: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            								}
            								break;
            								case (int)9: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            								}
            								break;
            								case (int)10: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            								}
            								break;
            								case (int)11: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            								}
            								break;
            								case (int)12: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            								}
            								break;
            								case (int)13: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            								}
            								break;
            								case (int)14: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            								}
            								break;
            								case (int)15: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            								}
            								break;
            								case (int)16: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)17: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            								}
            								break;
            								case (int)18: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            								}
            								break;
            								case (int)19: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            								}
            								break;
            								case (int)20: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            								}
            								break;
            								case (int)21: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp3 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            								}
            								break;
            								default:{
HXLINE( 139)									_hx_tmp3 = null();
            								}
            							}
HXDLIN( 139)							::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),_hx_tmp3,::hx::paccDynamic);
HXDLIN( 139)							 ::Dynamic _hx_tmp4;
HXDLIN( 139)							switch((int)(::SaveType_obj::CUSTOM_HELL_MOD_dyn()->_hx_getIndex())){
            								case (int)1: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            								}
            								break;
            								case (int)2: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)3: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            								}
            								break;
            								case (int)4: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)5: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            								}
            								break;
            								case (int)6: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)7: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)8: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            								}
            								break;
            								case (int)9: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            								}
            								break;
            								case (int)10: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            								}
            								break;
            								case (int)11: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            								}
            								break;
            								case (int)12: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            								}
            								break;
            								case (int)13: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            								}
            								break;
            								case (int)14: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            								}
            								break;
            								case (int)15: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            								}
            								break;
            								case (int)16: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)17: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            								}
            								break;
            								case (int)18: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            								}
            								break;
            								case (int)19: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            								}
            								break;
            								case (int)20: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            								}
            								break;
            								case (int)21: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            								}
            								break;
            								default:{
HXLINE( 139)									_hx_tmp4 = null();
            								}
            							}
HXDLIN( 139)							::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),_hx_tmp4,::hx::paccDynamic);
HXDLIN( 139)							 ::Dynamic _hx_tmp5;
HXDLIN( 139)							switch((int)(::SaveType_obj::FAIR_BATTLE_MOD_dyn()->_hx_getIndex())){
            								case (int)1: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            								}
            								break;
            								case (int)2: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)3: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            								}
            								break;
            								case (int)4: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)5: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            								}
            								break;
            								case (int)6: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)7: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)8: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            								}
            								break;
            								case (int)9: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            								}
            								break;
            								case (int)10: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            								}
            								break;
            								case (int)11: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            								}
            								break;
            								case (int)12: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            								}
            								break;
            								case (int)13: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            								}
            								break;
            								case (int)14: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            								}
            								break;
            								case (int)15: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            								}
            								break;
            								case (int)16: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)17: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            								}
            								break;
            								case (int)18: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            								}
            								break;
            								case (int)19: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            								}
            								break;
            								case (int)20: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            								}
            								break;
            								case (int)21: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp5 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            								}
            								break;
            								default:{
HXLINE( 139)									_hx_tmp5 = null();
            								}
            							}
HXDLIN( 139)							::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),_hx_tmp5,::hx::paccDynamic);
HXDLIN( 139)							 ::Dynamic _hx_tmp6;
HXDLIN( 139)							switch((int)(::SaveType_obj::FADE_BATTLE_MOD_dyn()->_hx_getIndex())){
            								case (int)1: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            								}
            								break;
            								case (int)2: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)3: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            								}
            								break;
            								case (int)4: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)5: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            								}
            								break;
            								case (int)6: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)7: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)8: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            								}
            								break;
            								case (int)9: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            								}
            								break;
            								case (int)10: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            								}
            								break;
            								case (int)11: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            								}
            								break;
            								case (int)12: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            								}
            								break;
            								case (int)13: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            								}
            								break;
            								case (int)14: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            								}
            								break;
            								case (int)15: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            								}
            								break;
            								case (int)16: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)17: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            								}
            								break;
            								case (int)18: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            								}
            								break;
            								case (int)19: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            								}
            								break;
            								case (int)20: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            								}
            								break;
            								case (int)21: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp6 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            								}
            								break;
            								default:{
HXLINE( 139)									_hx_tmp6 = null();
            								}
            							}
HXDLIN( 139)							::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),_hx_tmp6,::hx::paccDynamic);
HXDLIN( 139)							 ::Dynamic _hx_tmp7;
HXDLIN( 139)							switch((int)(::SaveType_obj::SHOW_BOTTOM_BAR_dyn()->_hx_getIndex())){
            								case (int)1: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            								}
            								break;
            								case (int)2: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)3: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            								}
            								break;
            								case (int)4: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)5: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            								}
            								break;
            								case (int)6: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)7: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)8: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            								}
            								break;
            								case (int)9: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            								}
            								break;
            								case (int)10: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            								}
            								break;
            								case (int)11: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            								}
            								break;
            								case (int)12: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            								}
            								break;
            								case (int)13: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            								}
            								break;
            								case (int)14: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            								}
            								break;
            								case (int)15: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            								}
            								break;
            								case (int)16: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)17: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            								}
            								break;
            								case (int)18: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            								}
            								break;
            								case (int)19: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            								}
            								break;
            								case (int)20: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            								}
            								break;
            								case (int)21: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp7 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            								}
            								break;
            								default:{
HXLINE( 139)									_hx_tmp7 = null();
            								}
            							}
HXDLIN( 139)							::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),_hx_tmp7,::hx::paccDynamic);
HXDLIN( 139)							 ::Dynamic _hx_tmp8;
HXDLIN( 139)							switch((int)(::SaveType_obj::SHOW_NOTE_SPLASH_dyn()->_hx_getIndex())){
            								case (int)1: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            								}
            								break;
            								case (int)2: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)3: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            								}
            								break;
            								case (int)4: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)5: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            								}
            								break;
            								case (int)6: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)7: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)8: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            								}
            								break;
            								case (int)9: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            								}
            								break;
            								case (int)10: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            								}
            								break;
            								case (int)11: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            								}
            								break;
            								case (int)12: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            								}
            								break;
            								case (int)13: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            								}
            								break;
            								case (int)14: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            								}
            								break;
            								case (int)15: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            								}
            								break;
            								case (int)16: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)17: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            								}
            								break;
            								case (int)18: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            								}
            								break;
            								case (int)19: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            								}
            								break;
            								case (int)20: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            								}
            								break;
            								case (int)21: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp8 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            								}
            								break;
            								default:{
HXLINE( 139)									_hx_tmp8 = null();
            								}
            							}
HXDLIN( 139)							::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),_hx_tmp8,::hx::paccDynamic);
HXDLIN( 139)							 ::Dynamic _hx_tmp9;
HXDLIN( 139)							switch((int)(::SaveType_obj::GRAPHICS_dyn()->_hx_getIndex())){
            								case (int)1: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            								}
            								break;
            								case (int)2: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)3: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            								}
            								break;
            								case (int)4: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)5: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            								}
            								break;
            								case (int)6: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)7: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)8: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            								}
            								break;
            								case (int)9: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            								}
            								break;
            								case (int)10: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            								}
            								break;
            								case (int)11: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            								}
            								break;
            								case (int)12: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            								}
            								break;
            								case (int)13: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            								}
            								break;
            								case (int)14: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            								}
            								break;
            								case (int)15: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            								}
            								break;
            								case (int)16: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)17: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            								}
            								break;
            								case (int)18: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            								}
            								break;
            								case (int)19: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            								}
            								break;
            								case (int)20: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            								}
            								break;
            								case (int)21: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp9 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            								}
            								break;
            								default:{
HXLINE( 139)									_hx_tmp9 = null();
            								}
            							}
HXDLIN( 139)							::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),_hx_tmp9,::hx::paccDynamic);
HXDLIN( 139)							 ::Dynamic _hx_tmp10;
HXDLIN( 139)							switch((int)(::SaveType_obj::SET_FPS_DEFAULT_dyn()->_hx_getIndex())){
            								case (int)1: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            								}
            								break;
            								case (int)2: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)3: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            								}
            								break;
            								case (int)4: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)5: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            								}
            								break;
            								case (int)6: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)7: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)8: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            								}
            								break;
            								case (int)9: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            								}
            								break;
            								case (int)10: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            								}
            								break;
            								case (int)11: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            								}
            								break;
            								case (int)12: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            								}
            								break;
            								case (int)13: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            								}
            								break;
            								case (int)14: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            								}
            								break;
            								case (int)15: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            								}
            								break;
            								case (int)16: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)17: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            								}
            								break;
            								case (int)18: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            								}
            								break;
            								case (int)19: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            								}
            								break;
            								case (int)20: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            								}
            								break;
            								case (int)21: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp10 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            								}
            								break;
            								default:{
HXLINE( 139)									_hx_tmp10 = null();
            								}
            							}
HXDLIN( 139)							::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),_hx_tmp10,::hx::paccDynamic);
HXDLIN( 139)							 ::Dynamic _hx_tmp11;
HXDLIN( 139)							switch((int)(::SaveType_obj::FPS_MULTIPLIER_dyn()->_hx_getIndex())){
            								case (int)1: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            								}
            								break;
            								case (int)2: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)3: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            								}
            								break;
            								case (int)4: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)5: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            								}
            								break;
            								case (int)6: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)7: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)8: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            								}
            								break;
            								case (int)9: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            								}
            								break;
            								case (int)10: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            								}
            								break;
            								case (int)11: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            								}
            								break;
            								case (int)12: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            								}
            								break;
            								case (int)13: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            								}
            								break;
            								case (int)14: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            								}
            								break;
            								case (int)15: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            								}
            								break;
            								case (int)16: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)17: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            								}
            								break;
            								case (int)18: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            								}
            								break;
            								case (int)19: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            								}
            								break;
            								case (int)20: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            								}
            								break;
            								case (int)21: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp11 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            								}
            								break;
            								default:{
HXLINE( 139)									_hx_tmp11 = null();
            								}
            							}
HXDLIN( 139)							::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),_hx_tmp11,::hx::paccDynamic);
HXDLIN( 139)							 ::Dynamic _hx_tmp12;
HXDLIN( 139)							switch((int)(::SaveType_obj::NO_BLUE_BALLS_MOD_dyn()->_hx_getIndex())){
            								case (int)1: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            								}
            								break;
            								case (int)2: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)3: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            								}
            								break;
            								case (int)4: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)5: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            								}
            								break;
            								case (int)6: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)7: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)8: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            								}
            								break;
            								case (int)9: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            								}
            								break;
            								case (int)10: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            								}
            								break;
            								case (int)11: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            								}
            								break;
            								case (int)12: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            								}
            								break;
            								case (int)13: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            								}
            								break;
            								case (int)14: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            								}
            								break;
            								case (int)15: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            								}
            								break;
            								case (int)16: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)17: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            								}
            								break;
            								case (int)18: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            								}
            								break;
            								case (int)19: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            								}
            								break;
            								case (int)20: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            								}
            								break;
            								case (int)21: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp12 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            								}
            								break;
            								default:{
HXLINE( 139)									_hx_tmp12 = null();
            								}
            							}
HXDLIN( 139)							::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),_hx_tmp12,::hx::paccDynamic);
HXDLIN( 139)							 ::Dynamic _hx_tmp13;
HXDLIN( 139)							switch((int)(::SaveType_obj::BLIND_MOD_dyn()->_hx_getIndex())){
            								case (int)1: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            								}
            								break;
            								case (int)2: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)3: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            								}
            								break;
            								case (int)4: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)5: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            								}
            								break;
            								case (int)6: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)7: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)8: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            								}
            								break;
            								case (int)9: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            								}
            								break;
            								case (int)10: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            								}
            								break;
            								case (int)11: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            								}
            								break;
            								case (int)12: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            								}
            								break;
            								case (int)13: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            								}
            								break;
            								case (int)14: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            								}
            								break;
            								case (int)15: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            								}
            								break;
            								case (int)16: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)17: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            								}
            								break;
            								case (int)18: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            								}
            								break;
            								case (int)19: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            								}
            								break;
            								case (int)20: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            								}
            								break;
            								case (int)21: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp13 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            								}
            								break;
            								default:{
HXLINE( 139)									_hx_tmp13 = null();
            								}
            							}
HXDLIN( 139)							::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),_hx_tmp13,::hx::paccDynamic);
HXDLIN( 139)							 ::Dynamic _hx_tmp14;
HXDLIN( 139)							switch((int)(::SaveType_obj::X_WOBBLE_MOD_dyn()->_hx_getIndex())){
            								case (int)1: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            								}
            								break;
            								case (int)2: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)3: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            								}
            								break;
            								case (int)4: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)5: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            								}
            								break;
            								case (int)6: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)7: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)8: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            								}
            								break;
            								case (int)9: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            								}
            								break;
            								case (int)10: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            								}
            								break;
            								case (int)11: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            								}
            								break;
            								case (int)12: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            								}
            								break;
            								case (int)13: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            								}
            								break;
            								case (int)14: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            								}
            								break;
            								case (int)15: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            								}
            								break;
            								case (int)16: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)17: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            								}
            								break;
            								case (int)18: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            								}
            								break;
            								case (int)19: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            								}
            								break;
            								case (int)20: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            								}
            								break;
            								case (int)21: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp14 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            								}
            								break;
            								default:{
HXLINE( 139)									_hx_tmp14 = null();
            								}
            							}
HXDLIN( 139)							::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),_hx_tmp14,::hx::paccDynamic);
HXDLIN( 139)							 ::Dynamic _hx_tmp15;
HXDLIN( 139)							switch((int)(::SaveType_obj::PRESET_INPUTS_dyn()->_hx_getIndex())){
            								case (int)1: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            								}
            								break;
            								case (int)2: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)3: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            								}
            								break;
            								case (int)4: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)5: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            								}
            								break;
            								case (int)6: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)7: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)8: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            								}
            								break;
            								case (int)9: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            								}
            								break;
            								case (int)10: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            								}
            								break;
            								case (int)11: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            								}
            								break;
            								case (int)12: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            								}
            								break;
            								case (int)13: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            								}
            								break;
            								case (int)14: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            								}
            								break;
            								case (int)15: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            								}
            								break;
            								case (int)16: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)17: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            								}
            								break;
            								case (int)18: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            								}
            								break;
            								case (int)19: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            								}
            								break;
            								case (int)20: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            								}
            								break;
            								case (int)21: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp15 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            								}
            								break;
            								default:{
HXLINE( 139)									_hx_tmp15 = null();
            								}
            							}
HXDLIN( 139)							::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),_hx_tmp15,::hx::paccDynamic);
HXDLIN( 139)							 ::Dynamic _hx_tmp16;
HXDLIN( 139)							switch((int)(::SaveType_obj::CACHE_ASSETS_dyn()->_hx_getIndex())){
            								case (int)1: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            								}
            								break;
            								case (int)2: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)3: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            								}
            								break;
            								case (int)4: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)5: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            								}
            								break;
            								case (int)6: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)7: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)8: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            								}
            								break;
            								case (int)9: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            								}
            								break;
            								case (int)10: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            								}
            								break;
            								case (int)11: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            								}
            								break;
            								case (int)12: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            								}
            								break;
            								case (int)13: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            								}
            								break;
            								case (int)14: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            								}
            								break;
            								case (int)15: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            								}
            								break;
            								case (int)16: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)17: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            								}
            								break;
            								case (int)18: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            								}
            								break;
            								case (int)19: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            								}
            								break;
            								case (int)20: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            								}
            								break;
            								case (int)21: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp16 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            								}
            								break;
            								default:{
HXLINE( 139)									_hx_tmp16 = null();
            								}
            							}
HXDLIN( 139)							::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),_hx_tmp16,::hx::paccDynamic);
HXDLIN( 139)							 ::Dynamic _hx_tmp17;
HXDLIN( 139)							switch((int)(::SaveType_obj::CUSTOM_KEYBINDS_dyn()->_hx_getIndex())){
            								case (int)1: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            								}
            								break;
            								case (int)2: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)3: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            								}
            								break;
            								case (int)4: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)5: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            								}
            								break;
            								case (int)6: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)7: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)8: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            								}
            								break;
            								case (int)9: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            								}
            								break;
            								case (int)10: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            								}
            								break;
            								case (int)11: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            								}
            								break;
            								case (int)12: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            								}
            								break;
            								case (int)13: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            								}
            								break;
            								case (int)14: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            								}
            								break;
            								case (int)15: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            								}
            								break;
            								case (int)16: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)17: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            								}
            								break;
            								case (int)18: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            								}
            								break;
            								case (int)19: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            								}
            								break;
            								case (int)20: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            								}
            								break;
            								case (int)21: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp17 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            								}
            								break;
            								default:{
HXLINE( 139)									_hx_tmp17 = null();
            								}
            							}
HXDLIN( 139)							::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),_hx_tmp17,::hx::paccDynamic);
HXDLIN( 139)							 ::Dynamic _hx_tmp18;
HXDLIN( 139)							switch((int)(::SaveType_obj::CAMERA_MOVEMENT_MOD_dyn()->_hx_getIndex())){
            								case (int)1: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            								}
            								break;
            								case (int)2: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)3: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            								}
            								break;
            								case (int)4: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)5: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            								}
            								break;
            								case (int)6: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)7: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)8: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            								}
            								break;
            								case (int)9: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            								}
            								break;
            								case (int)10: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            								}
            								break;
            								case (int)11: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            								}
            								break;
            								case (int)12: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            								}
            								break;
            								case (int)13: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            								}
            								break;
            								case (int)14: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            								}
            								break;
            								case (int)15: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            								}
            								break;
            								case (int)16: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)17: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            								}
            								break;
            								case (int)18: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            								}
            								break;
            								case (int)19: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            								}
            								break;
            								case (int)20: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            								}
            								break;
            								case (int)21: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp18 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            								}
            								break;
            								default:{
HXLINE( 139)									_hx_tmp18 = null();
            								}
            							}
HXDLIN( 139)							::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),_hx_tmp18,::hx::paccDynamic);
HXDLIN( 139)							 ::Dynamic _hx_tmp19;
HXDLIN( 139)							switch((int)(::SaveType_obj::GHOST_TAPPING_dyn()->_hx_getIndex())){
            								case (int)1: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            								}
            								break;
            								case (int)2: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)3: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            								}
            								break;
            								case (int)4: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)5: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            								}
            								break;
            								case (int)6: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)7: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)8: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            								}
            								break;
            								case (int)9: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            								}
            								break;
            								case (int)10: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            								}
            								break;
            								case (int)11: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            								}
            								break;
            								case (int)12: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            								}
            								break;
            								case (int)13: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            								}
            								break;
            								case (int)14: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            								}
            								break;
            								case (int)15: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            								}
            								break;
            								case (int)16: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)17: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            								}
            								break;
            								case (int)18: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            								}
            								break;
            								case (int)19: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            								}
            								break;
            								case (int)20: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            								}
            								break;
            								case (int)21: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp19 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            								}
            								break;
            								default:{
HXLINE( 139)									_hx_tmp19 = null();
            								}
            							}
HXDLIN( 139)							::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),_hx_tmp19,::hx::paccDynamic);
HXDLIN( 139)							 ::Dynamic _hx_tmp20;
HXDLIN( 139)							switch((int)(::SaveType_obj::CUSTOM_MENU_BINDS_dyn()->_hx_getIndex())){
            								case (int)1: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            								}
            								break;
            								case (int)2: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)3: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            								}
            								break;
            								case (int)4: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)5: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            								}
            								break;
            								case (int)6: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)7: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            								}
            								break;
            								case (int)8: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            								}
            								break;
            								case (int)9: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            								}
            								break;
            								case (int)10: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            								}
            								break;
            								case (int)11: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            									}
            									else {
HXLINE( 139)										if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE( 139)											::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            										}
            									}
HXDLIN( 139)									_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            								}
            								break;
            								case (int)12: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            								}
            								break;
            								case (int)13: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            								}
            								break;
            								case (int)14: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            								}
            								break;
            								case (int)15: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            								}
            								break;
            								case (int)16: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            								}
            								break;
            								case (int)17: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            								}
            								break;
            								case (int)18: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            								}
            								break;
            								case (int)19: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            								}
            								break;
            								case (int)20: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            								}
            								break;
            								case (int)21: {
HXLINE( 139)									if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE( 139)										::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            									}
HXDLIN( 139)									_hx_tmp20 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            								}
            								break;
            								default:{
HXLINE( 139)									_hx_tmp20 = null();
            								}
            							}
HXDLIN( 139)							::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),_hx_tmp20,::hx::paccDynamic);
HXDLIN( 139)							::flixel::FlxG_obj::save->flush(null(),null());
            						}
HXLINE( 140)						this->saveryMapArray = true;
HXLINE( 142)						this->close();
            					}
HXLINE( 145)					this->changingKeys = false;
            				}
            			}
            		}
HXLINE( 149)		this->super::update(elapsed);
            	}


void CustomKeys_obj::reloadKeys(::String text){
            	HX_GC_STACKFRAME(&_hx_pos_bd0f5e58e0203c61_152_reloadKeys)
HXLINE( 153)		this->remove(this->keys,null());
HXLINE( 154)		this->keys->destroy();
HXLINE( 155)		this->keys =  ::Alphabet_obj::__alloc( HX_CTX ,( (Float)(0) ),( (Float)(0) ),text,true,false,null());
HXLINE( 156)		{
HXLINE( 156)			 ::Alphabet _this = this->keys;
HXDLIN( 156)			 ::flixel::util::FlxAxes axes = ::flixel::util::FlxAxes_obj::XY_dyn();
HXDLIN( 156)			bool _hx_tmp;
HXDLIN( 156)			switch((int)(axes->_hx_getIndex())){
            				case (int)0: case (int)2: {
HXLINE( 156)					_hx_tmp = true;
            				}
            				break;
            				default:{
HXLINE( 156)					_hx_tmp = false;
            				}
            			}
HXDLIN( 156)			if (_hx_tmp) {
HXLINE( 156)				int _hx_tmp = ::flixel::FlxG_obj::width;
HXDLIN( 156)				_this->set_x(((( (Float)(_hx_tmp) ) - _this->get_width()) / ( (Float)(2) )));
            			}
HXDLIN( 156)			bool _hx_tmp1;
HXDLIN( 156)			switch((int)(axes->_hx_getIndex())){
            				case (int)1: case (int)2: {
HXLINE( 156)					_hx_tmp1 = true;
            				}
            				break;
            				default:{
HXLINE( 156)					_hx_tmp1 = false;
            				}
            			}
HXDLIN( 156)			if (_hx_tmp1) {
HXLINE( 156)				int _hx_tmp = ::flixel::FlxG_obj::height;
HXDLIN( 156)				_this->set_y(((( (Float)(_hx_tmp) ) - _this->get_height()) / ( (Float)(2) )));
            			}
            		}
HXLINE( 157)		this->add(this->keys);
            	}


HX_DEFINE_DYNAMIC_FUNC1(CustomKeys_obj,reloadKeys,(void))


::hx::ObjectPtr< CustomKeys_obj > CustomKeys_obj::__new() {
	::hx::ObjectPtr< CustomKeys_obj > __this = new CustomKeys_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< CustomKeys_obj > CustomKeys_obj::__alloc(::hx::Ctx *_hx_ctx) {
	CustomKeys_obj *__this = (CustomKeys_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(CustomKeys_obj), true, "CustomKeys"));
	*(void **)__this = CustomKeys_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

CustomKeys_obj::CustomKeys_obj()
{
}

void CustomKeys_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CustomKeys);
	HX_MARK_MEMBER_NAME(bgBlack,"bgBlack");
	HX_MARK_MEMBER_NAME(keys,"keys");
	HX_MARK_MEMBER_NAME(howManyKey,"howManyKey");
	HX_MARK_MEMBER_NAME(section,"section");
	HX_MARK_MEMBER_NAME(colorSway,"colorSway");
	HX_MARK_MEMBER_NAME(changingKeys,"changingKeys");
	HX_MARK_MEMBER_NAME(saveryMapArray,"saveryMapArray");
	HX_MARK_MEMBER_NAME(changedOnSteam,"changedOnSteam");
	 ::flixel::FlxSubState_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void CustomKeys_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(bgBlack,"bgBlack");
	HX_VISIT_MEMBER_NAME(keys,"keys");
	HX_VISIT_MEMBER_NAME(howManyKey,"howManyKey");
	HX_VISIT_MEMBER_NAME(section,"section");
	HX_VISIT_MEMBER_NAME(colorSway,"colorSway");
	HX_VISIT_MEMBER_NAME(changingKeys,"changingKeys");
	HX_VISIT_MEMBER_NAME(saveryMapArray,"saveryMapArray");
	HX_VISIT_MEMBER_NAME(changedOnSteam,"changedOnSteam");
	 ::flixel::FlxSubState_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val CustomKeys_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"keys") ) { return ::hx::Val( keys ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return ::hx::Val( update_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"bgBlack") ) { return ::hx::Val( bgBlack ); }
		if (HX_FIELD_EQ(inName,"section") ) { return ::hx::Val( section ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"colorSway") ) { return ::hx::Val( colorSway ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"howManyKey") ) { return ::hx::Val( howManyKey ); }
		if (HX_FIELD_EQ(inName,"reloadKeys") ) { return ::hx::Val( reloadKeys_dyn() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"changingKeys") ) { return ::hx::Val( changingKeys ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"saveryMapArray") ) { return ::hx::Val( saveryMapArray ); }
		if (HX_FIELD_EQ(inName,"changedOnSteam") ) { return ::hx::Val( changedOnSteam ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val CustomKeys_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"keys") ) { keys=inValue.Cast<  ::Alphabet >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"bgBlack") ) { bgBlack=inValue.Cast<  ::flixel::FlxSprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"section") ) { section=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"colorSway") ) { colorSway=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"howManyKey") ) { howManyKey=inValue.Cast<  ::flixel::text::FlxText >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"changingKeys") ) { changingKeys=inValue.Cast< bool >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"saveryMapArray") ) { saveryMapArray=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"changedOnSteam") ) { changedOnSteam=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CustomKeys_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("bgBlack",ba,e5,18,62));
	outFields->push(HX_("keys",f4,e1,06,47));
	outFields->push(HX_("howManyKey",90,e0,3a,1c));
	outFields->push(HX_("section",e5,05,d8,5d));
	outFields->push(HX_("colorSway",9f,b5,cb,27));
	outFields->push(HX_("changingKeys",41,9f,56,d4));
	outFields->push(HX_("saveryMapArray",c1,75,90,d3));
	outFields->push(HX_("changedOnSteam",5d,4a,db,be));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo CustomKeys_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::flixel::FlxSprite */ ,(int)offsetof(CustomKeys_obj,bgBlack),HX_("bgBlack",ba,e5,18,62)},
	{::hx::fsObject /*  ::Alphabet */ ,(int)offsetof(CustomKeys_obj,keys),HX_("keys",f4,e1,06,47)},
	{::hx::fsObject /*  ::flixel::text::FlxText */ ,(int)offsetof(CustomKeys_obj,howManyKey),HX_("howManyKey",90,e0,3a,1c)},
	{::hx::fsInt,(int)offsetof(CustomKeys_obj,section),HX_("section",e5,05,d8,5d)},
	{::hx::fsFloat,(int)offsetof(CustomKeys_obj,colorSway),HX_("colorSway",9f,b5,cb,27)},
	{::hx::fsBool,(int)offsetof(CustomKeys_obj,changingKeys),HX_("changingKeys",41,9f,56,d4)},
	{::hx::fsBool,(int)offsetof(CustomKeys_obj,saveryMapArray),HX_("saveryMapArray",c1,75,90,d3)},
	{::hx::fsInt,(int)offsetof(CustomKeys_obj,changedOnSteam),HX_("changedOnSteam",5d,4a,db,be)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *CustomKeys_obj_sStaticStorageInfo = 0;
#endif

static ::String CustomKeys_obj_sMemberFields[] = {
	HX_("bgBlack",ba,e5,18,62),
	HX_("keys",f4,e1,06,47),
	HX_("howManyKey",90,e0,3a,1c),
	HX_("section",e5,05,d8,5d),
	HX_("colorSway",9f,b5,cb,27),
	HX_("changingKeys",41,9f,56,d4),
	HX_("saveryMapArray",c1,75,90,d3),
	HX_("changedOnSteam",5d,4a,db,be),
	HX_("update",09,86,05,87),
	HX_("reloadKeys",ed,81,0e,92),
	::String(null()) };

::hx::Class CustomKeys_obj::__mClass;

void CustomKeys_obj::__register()
{
	CustomKeys_obj _hx_dummy;
	CustomKeys_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("CustomKeys",65,c6,5f,9b);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(CustomKeys_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< CustomKeys_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = CustomKeys_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = CustomKeys_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

