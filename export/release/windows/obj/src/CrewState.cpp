#include <hxcpp.h>

#ifndef INCLUDED_95f339a1d026d52c
#define INCLUDED_95f339a1d026d52c
#include "hxMath.h"
#endif
#ifndef INCLUDED_CrewState
#include <CrewState.h>
#endif
#ifndef INCLUDED_HelperStates
#include <HelperStates.h>
#endif
#ifndef INCLUDED_MusicBeatState
#include <MusicBeatState.h>
#endif
#ifndef INCLUDED_Paths
#include <Paths.h>
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
#ifndef INCLUDED_flixel_addons_transition_FlxTransitionableState
#include <flixel/addons/transition/FlxTransitionableState.h>
#endif
#ifndef INCLUDED_flixel_addons_ui_FlxUIState
#include <flixel/addons/ui/FlxUIState.h>
#endif
#ifndef INCLUDED_flixel_addons_ui_interfaces_IEventGetter
#include <flixel/addons/ui/interfaces/IEventGetter.h>
#endif
#ifndef INCLUDED_flixel_addons_ui_interfaces_IFlxUIState
#include <flixel/addons/ui/interfaces/IFlxUIState.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_util_FlxAxes
#include <flixel/util/FlxAxes.h>
#endif
#ifndef INCLUDED_flixel_util_FlxGradient
#include <flixel/util/FlxGradient.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxDestroyable
#include <flixel/util/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_util__FlxColor_FlxColor_Impl_
#include <flixel/util/_FlxColor/FlxColor_Impl_.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_7b9e470b77c42d12_11_new,"CrewState","new",0x7b5a8642,"CrewState.new","CrewState.hx",11,0xbcd2776e)
HX_LOCAL_STACK_FRAME(_hx_pos_7b9e470b77c42d12_22_create,"CrewState","create",0x61ca0a5a,"CrewState.create","CrewState.hx",22,0xbcd2776e)
HX_LOCAL_STACK_FRAME(_hx_pos_7b9e470b77c42d12_43_update,"CrewState","update",0x6cc02967,"CrewState.update","CrewState.hx",43,0xbcd2776e)
HX_LOCAL_STACK_FRAME(_hx_pos_7b9e470b77c42d12_57_changeDev,"CrewState","changeDev",0x046931a7,"CrewState.changeDev","CrewState.hx",57,0xbcd2776e)
HX_LOCAL_STACK_FRAME(_hx_pos_7b9e470b77c42d12_48_changeDev,"CrewState","changeDev",0x046931a7,"CrewState.changeDev","CrewState.hx",48,0xbcd2776e)
HX_LOCAL_STACK_FRAME(_hx_pos_7b9e470b77c42d12_72_makeCoolPeople,"CrewState","makeCoolPeople",0x8e8a5ae4,"CrewState.makeCoolPeople","CrewState.hx",72,0xbcd2776e)

void CrewState_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_7b9e470b77c42d12_11_new)
HXLINE(  16)		this->globalOffset = ((Float)1);
HXLINE(  14)		this->curSelected = 0;
HXLINE(  19)		super::__construct();
            	}

Dynamic CrewState_obj::__CreateEmpty() { return new CrewState_obj; }

void *CrewState_obj::_hx_vtable = 0;

Dynamic CrewState_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< CrewState_obj > _hx_result = new CrewState_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool CrewState_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x335844ac) {
		if (inClassId<=(int)0x29d19794) {
			if (inClassId<=(int)0x23a57bae) {
				return inClassId==(int)0x00000001 || inClassId==(int)0x23a57bae;
			} else {
				return inClassId==(int)0x29d19794;
			}
		} else {
			return inClassId==(int)0x2f064378 || inClassId==(int)0x335844ac;
		}
	} else {
		if (inClassId<=(int)0x7c795c9f) {
			if (inClassId<=(int)0x62817b24) {
				return inClassId==(int)0x3f706236 || inClassId==(int)0x62817b24;
			} else {
				return inClassId==(int)0x7c795c9f;
			}
		} else {
			return inClassId==(int)0x7ccf8994;
		}
	}
}

void CrewState_obj::create(){
            	HX_GC_STACKFRAME(&_hx_pos_7b9e470b77c42d12_22_create)
HXLINE(  23)		int background = ::flixel::FlxG_obj::width;
HXDLIN(  23)		int background1 = ::flixel::FlxG_obj::height;
HXLINE(  24)		int Alpha = 255;
HXDLIN(  24)		int color = ::flixel::util::_FlxColor::FlxColor_Impl__obj::_new(null());
HXDLIN(  24)		{
HXLINE(  24)			color = (color & -16711681);
HXDLIN(  24)			color = (color | 5570560);
            		}
HXDLIN(  24)		{
HXLINE(  24)			color = (color & -65281);
HXDLIN(  24)			color = (color | 0);
            		}
HXDLIN(  24)		{
HXLINE(  24)			color = (color & -256);
HXDLIN(  24)			color = (color | 150);
            		}
HXDLIN(  24)		{
HXLINE(  24)			color = (color & 16777215);
HXDLIN(  24)			int color1;
HXDLIN(  24)			if ((Alpha > 255)) {
HXLINE(  24)				color1 = 255;
            			}
            			else {
HXLINE(  24)				if ((Alpha < 0)) {
HXLINE(  24)					color1 = 0;
            				}
            				else {
HXLINE(  24)					color1 = Alpha;
            				}
            			}
HXDLIN(  24)			color = (color | (color1 << 24));
            		}
HXDLIN(  24)		int color2 = ::flixel::util::_FlxColor::FlxColor_Impl__obj::_new(null());
HXDLIN(  24)		{
HXLINE(  24)			color2 = (color2 & -16711681);
HXDLIN(  24)			color2 = (color2 | 2818048);
            		}
HXDLIN(  24)		{
HXLINE(  24)			color2 = (color2 & -65281);
HXDLIN(  24)			color2 = (color2 | 2048);
            		}
HXDLIN(  24)		{
HXLINE(  24)			color2 = (color2 & -256);
HXDLIN(  24)			color2 = (color2 | 180);
            		}
HXDLIN(  24)		{
HXLINE(  24)			color2 = (color2 & 16777215);
HXDLIN(  24)			color2 = (color2 | (int)1258291200);
            		}
HXDLIN(  24)		int color3 = ::flixel::util::_FlxColor::FlxColor_Impl__obj::_new(null());
HXDLIN(  24)		{
HXLINE(  24)			color3 = (color3 & -16711681);
HXDLIN(  24)			color3 = (color3 | 2818048);
            		}
HXDLIN(  24)		{
HXLINE(  24)			color3 = (color3 & -65281);
HXDLIN(  24)			color3 = (color3 | 2048);
            		}
HXDLIN(  24)		{
HXLINE(  24)			color3 = (color3 & -256);
HXDLIN(  24)			color3 = (color3 | 180);
            		}
HXDLIN(  24)		{
HXLINE(  24)			color3 = (color3 & 16777215);
HXDLIN(  24)			color3 = (color3 | (int)1258291200);
            		}
HXDLIN(  24)		int color4 = ::flixel::util::_FlxColor::FlxColor_Impl__obj::_new(null());
HXDLIN(  24)		{
HXLINE(  24)			color4 = (color4 & -16711681);
HXDLIN(  24)			color4 = (color4 | 2818048);
            		}
HXDLIN(  24)		{
HXLINE(  24)			color4 = (color4 & -65281);
HXDLIN(  24)			color4 = (color4 | 2048);
            		}
HXDLIN(  24)		{
HXLINE(  24)			color4 = (color4 & -256);
HXDLIN(  24)			color4 = (color4 | 180);
            		}
HXDLIN(  24)		{
HXLINE(  24)			color4 = (color4 & 16777215);
HXDLIN(  24)			color4 = (color4 | (int)1258291200);
            		}
HXDLIN(  24)		int Alpha1 = 255;
HXDLIN(  24)		int color5 = ::flixel::util::_FlxColor::FlxColor_Impl__obj::_new(null());
HXDLIN(  24)		{
HXLINE(  24)			color5 = (color5 & -16711681);
HXDLIN(  24)			color5 = (color5 | 5570560);
            		}
HXDLIN(  24)		{
HXLINE(  24)			color5 = (color5 & -65281);
HXDLIN(  24)			color5 = (color5 | 0);
            		}
HXDLIN(  24)		{
HXLINE(  24)			color5 = (color5 & -256);
HXDLIN(  24)			color5 = (color5 | 150);
            		}
HXDLIN(  24)		{
HXLINE(  24)			color5 = (color5 & 16777215);
HXDLIN(  24)			int color6;
HXDLIN(  24)			if ((Alpha1 > 255)) {
HXLINE(  24)				color6 = 255;
            			}
            			else {
HXLINE(  24)				if ((Alpha1 < 0)) {
HXLINE(  24)					color6 = 0;
            				}
            				else {
HXLINE(  24)					color6 = Alpha1;
            				}
            			}
HXDLIN(  24)			color5 = (color5 | (color6 << 24));
            		}
HXLINE(  23)		 ::flixel::FlxSprite background2 = ::flixel::util::FlxGradient_obj::createGradientFlxSprite(background,background1,::Array_obj< int >::__new(5)->init(0,color)->init(1,color2)->init(2,color3)->init(3,color4)->init(4,color5),1,null(),null());
HXLINE(  26)		{
HXLINE(  26)			 ::flixel::util::FlxAxes axes = ::flixel::util::FlxAxes_obj::XY_dyn();
HXDLIN(  26)			bool _hx_tmp;
HXDLIN(  26)			switch((int)(axes->_hx_getIndex())){
            				case (int)0: case (int)2: {
HXLINE(  26)					_hx_tmp = true;
            				}
            				break;
            				default:{
HXLINE(  26)					_hx_tmp = false;
            				}
            			}
HXDLIN(  26)			if (_hx_tmp) {
HXLINE(  26)				int _hx_tmp = ::flixel::FlxG_obj::width;
HXDLIN(  26)				background2->set_x(((( (Float)(_hx_tmp) ) - background2->get_width()) / ( (Float)(2) )));
            			}
HXDLIN(  26)			bool _hx_tmp1;
HXDLIN(  26)			switch((int)(axes->_hx_getIndex())){
            				case (int)1: case (int)2: {
HXLINE(  26)					_hx_tmp1 = true;
            				}
            				break;
            				default:{
HXLINE(  26)					_hx_tmp1 = false;
            				}
            			}
HXDLIN(  26)			if (_hx_tmp1) {
HXLINE(  26)				int _hx_tmp = ::flixel::FlxG_obj::height;
HXDLIN(  26)				background2->set_y(((( (Float)(_hx_tmp) ) - background2->get_height()) / ( (Float)(2) )));
            			}
            		}
HXLINE(  27)		this->add(background2);
HXLINE(  29)		this->officalDevTeam =  ::flixel::group::FlxTypedGroup_obj::__alloc( HX_CTX ,null());
HXLINE(  30)		this->add(this->officalDevTeam);
HXLINE(  32)		this->makeCoolPeople();
HXLINE(  34)		 ::flixel::FlxSprite devTeamLogo =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,null(),null(),null());
HXDLIN(  34)		 ::flixel::FlxSprite devTeamLogo1 = devTeamLogo->loadGraphic(::Paths_obj::image(HX_("devTeamLogo",9d,e9,ea,59),null()),null(),null(),null(),null(),null());
HXLINE(  35)		this->add(devTeamLogo1);
HXLINE(  37)		this->changeDev(null());
HXLINE(  39)		this->super::create();
            	}


void CrewState_obj::update(Float elapsed){
            	HX_STACKFRAME(&_hx_pos_7b9e470b77c42d12_43_update)
HXDLIN(  43)		this->super::update(elapsed);
            	}


void CrewState_obj::changeDev(::hx::Null< int >  __o_change){
            		HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_0, ::CrewState,_gthis) HXARGC(1)
            		void _hx_run( ::flixel::FlxSprite dev){
            			HX_STACKFRAME(&_hx_pos_7b9e470b77c42d12_57_changeDev)
HXLINE(  57)			if ((dev->ID == _gthis->curSelected)) {
HXLINE(  58)				if (((( (Float)(((dev->color >> 16) & 255)) ) / ( (Float)(255) )) != ((Float)0.1))) {
HXLINE(  61)					_gthis->globalOffset = ((Float)1.1);
HXLINE(  64)					Float Alpha = ( (Float)(1) );
HXDLIN(  64)					int color = ::flixel::util::_FlxColor::FlxColor_Impl__obj::_new(null());
HXDLIN(  64)					{
HXLINE(  64)						int Value = ::Math_obj::round(( (Float)(255) ));
HXDLIN(  64)						color = (color & -16711681);
HXDLIN(  64)						int color1;
HXDLIN(  64)						if ((Value > 255)) {
HXLINE(  64)							color1 = 255;
            						}
            						else {
HXLINE(  64)							if ((Value < 0)) {
HXLINE(  64)								color1 = 0;
            							}
            							else {
HXLINE(  64)								color1 = Value;
            							}
            						}
HXDLIN(  64)						color = (color | (color1 << 16));
            					}
HXDLIN(  64)					{
HXLINE(  64)						int Value1 = ::Math_obj::round(( (Float)(255) ));
HXDLIN(  64)						color = (color & -65281);
HXDLIN(  64)						int color2;
HXDLIN(  64)						if ((Value1 > 255)) {
HXLINE(  64)							color2 = 255;
            						}
            						else {
HXLINE(  64)							if ((Value1 < 0)) {
HXLINE(  64)								color2 = 0;
            							}
            							else {
HXLINE(  64)								color2 = Value1;
            							}
            						}
HXDLIN(  64)						color = (color | (color2 << 8));
            					}
HXDLIN(  64)					{
HXLINE(  64)						int Value2 = ::Math_obj::round(( (Float)(255) ));
HXDLIN(  64)						color = (color & -256);
HXDLIN(  64)						int color3;
HXDLIN(  64)						if ((Value2 > 255)) {
HXLINE(  64)							color3 = 255;
            						}
            						else {
HXLINE(  64)							if ((Value2 < 0)) {
HXLINE(  64)								color3 = 0;
            							}
            							else {
HXLINE(  64)								color3 = Value2;
            							}
            						}
HXDLIN(  64)						color = (color | color3);
            					}
HXDLIN(  64)					{
HXLINE(  64)						int Value3 = ::Math_obj::round((Alpha * ( (Float)(255) )));
HXDLIN(  64)						color = (color & 16777215);
HXDLIN(  64)						int color4;
HXDLIN(  64)						if ((Value3 > 255)) {
HXLINE(  64)							color4 = 255;
            						}
            						else {
HXLINE(  64)							if ((Value3 < 0)) {
HXLINE(  64)								color4 = 0;
            							}
            							else {
HXLINE(  64)								color4 = Value3;
            							}
            						}
HXDLIN(  64)						color = (color | (color4 << 24));
            					}
HXDLIN(  64)					dev->set_color(color);
            				}
            			}
            			else {
HXLINE(  67)				Float Alpha = ( (Float)(1) );
HXDLIN(  67)				int color = ::flixel::util::_FlxColor::FlxColor_Impl__obj::_new(null());
HXDLIN(  67)				{
HXLINE(  67)					int Value = ::Math_obj::round(((Float)25.5));
HXDLIN(  67)					color = (color & -16711681);
HXDLIN(  67)					int color1;
HXDLIN(  67)					if ((Value > 255)) {
HXLINE(  67)						color1 = 255;
            					}
            					else {
HXLINE(  67)						if ((Value < 0)) {
HXLINE(  67)							color1 = 0;
            						}
            						else {
HXLINE(  67)							color1 = Value;
            						}
            					}
HXDLIN(  67)					color = (color | (color1 << 16));
            				}
HXDLIN(  67)				{
HXLINE(  67)					int Value1 = ::Math_obj::round(((Float)25.5));
HXDLIN(  67)					color = (color & -65281);
HXDLIN(  67)					int color2;
HXDLIN(  67)					if ((Value1 > 255)) {
HXLINE(  67)						color2 = 255;
            					}
            					else {
HXLINE(  67)						if ((Value1 < 0)) {
HXLINE(  67)							color2 = 0;
            						}
            						else {
HXLINE(  67)							color2 = Value1;
            						}
            					}
HXDLIN(  67)					color = (color | (color2 << 8));
            				}
HXDLIN(  67)				{
HXLINE(  67)					int Value2 = ::Math_obj::round(((Float)25.5));
HXDLIN(  67)					color = (color & -256);
HXDLIN(  67)					int color3;
HXDLIN(  67)					if ((Value2 > 255)) {
HXLINE(  67)						color3 = 255;
            					}
            					else {
HXLINE(  67)						if ((Value2 < 0)) {
HXLINE(  67)							color3 = 0;
            						}
            						else {
HXLINE(  67)							color3 = Value2;
            						}
            					}
HXDLIN(  67)					color = (color | color3);
            				}
HXDLIN(  67)				{
HXLINE(  67)					int Value3 = ::Math_obj::round((Alpha * ( (Float)(255) )));
HXDLIN(  67)					color = (color & 16777215);
HXDLIN(  67)					int color4;
HXDLIN(  67)					if ((Value3 > 255)) {
HXLINE(  67)						color4 = 255;
            					}
            					else {
HXLINE(  67)						if ((Value3 < 0)) {
HXLINE(  67)							color4 = 0;
            						}
            						else {
HXLINE(  67)							color4 = Value3;
            						}
            					}
HXDLIN(  67)					color = (color | (color4 << 24));
            				}
HXDLIN(  67)				dev->set_color(color);
            			}
            		}
            		HX_END_LOCAL_FUNC1((void))

            		int change = __o_change.Default(0);
            	HX_STACKFRAME(&_hx_pos_7b9e470b77c42d12_48_changeDev)
HXDLIN(  48)		 ::CrewState _gthis = ::hx::ObjectPtr<OBJ_>(this);
HXLINE(  49)		 ::CrewState _hx_tmp = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN(  49)		_hx_tmp->curSelected = _hx_tmp->curSelected;
HXLINE(  51)		if ((this->curSelected < 0)) {
HXLINE(  52)			this->curSelected = (this->officalDevTeam->length - 1);
            		}
HXLINE(  53)		if ((this->curSelected > (this->officalDevTeam->length - 1))) {
HXLINE(  54)			this->curSelected = 0;
            		}
HXLINE(  56)		this->officalDevTeam->forEachAlive( ::Dynamic(new _hx_Closure_0(_gthis)),null());
            	}


HX_DEFINE_DYNAMIC_FUNC1(CrewState_obj,changeDev,(void))

void CrewState_obj::makeCoolPeople(){
            	HX_GC_STACKFRAME(&_hx_pos_7b9e470b77c42d12_72_makeCoolPeople)
HXLINE(  73)		 ::flixel::FlxSprite suki =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,null(),null(),null());
HXDLIN(  73)		 ::flixel::FlxSprite suki1 = suki->loadGraphic(::Paths_obj::image(HX_("ThiccSuki",95,87,38,4f),null()),null(),null(),null(),null(),null());
HXLINE(  74)		suki1->ID = 0;
HXLINE(  76)		 ::flixel::FlxSprite frogtreat =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,null(),null(),null());
HXDLIN(  76)		 ::flixel::FlxSprite frogtreat1 = frogtreat->loadGraphic(::Paths_obj::image(HX_("TreatOfDaFrog",d2,77,a0,e4),null()),null(),null(),null(),null(),null());
HXLINE(  77)		frogtreat1->ID = 1;
HXLINE(  78)		this->officalDevTeam->add(frogtreat1).StaticCast<  ::flixel::FlxSprite >();
HXLINE(  80)		 ::flixel::FlxSprite difi =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,null(),null(),null());
HXDLIN(  80)		 ::flixel::FlxSprite difi1 = difi->loadGraphic(::Paths_obj::image(HX_("SussyDifi",ff,c3,40,0a),null()),null(),null(),null(),null(),null());
HXLINE(  81)		difi1->ID = 2;
HXLINE(  82)		this->officalDevTeam->add(difi1).StaticCast<  ::flixel::FlxSprite >();
HXLINE(  84)		 ::flixel::FlxSprite feeshy =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,null(),null(),null());
HXDLIN(  84)		 ::flixel::FlxSprite feeshy1 = feeshy->loadGraphic(::Paths_obj::image(HX_("FeshyFeeshy",e3,4b,56,28),null()),null(),null(),null(),null(),null());
HXLINE(  85)		feeshy1->ID = 3;
HXLINE(  86)		this->officalDevTeam->add(feeshy1).StaticCast<  ::flixel::FlxSprite >();
HXLINE(  88)		 ::flixel::FlxSprite varsavi =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,null(),null(),null());
HXDLIN(  88)		 ::flixel::FlxSprite varsavi1 = varsavi->loadGraphic(::Paths_obj::image(HX_("VarVar",60,36,2b,88),null()),null(),null(),null(),null(),null());
HXLINE(  89)		varsavi1->ID = 4;
HXLINE(  90)		this->officalDevTeam->add(varsavi1).StaticCast<  ::flixel::FlxSprite >();
HXLINE(  92)		 ::flixel::FlxSprite jdst =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,null(),null(),null());
HXDLIN(  92)		 ::flixel::FlxSprite jdst1 = jdst->loadGraphic(::Paths_obj::image(HX_("MusicManJDST",70,3d,f9,82),null()),null(),null(),null(),null(),null());
HXLINE(  93)		jdst1->ID = 5;
HXLINE(  94)		this->officalDevTeam->add(jdst1).StaticCast<  ::flixel::FlxSprite >();
HXLINE(  96)		this->officalDevTeam->add(suki1).StaticCast<  ::flixel::FlxSprite >();
            	}


HX_DEFINE_DYNAMIC_FUNC0(CrewState_obj,makeCoolPeople,(void))


::hx::ObjectPtr< CrewState_obj > CrewState_obj::__new() {
	::hx::ObjectPtr< CrewState_obj > __this = new CrewState_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< CrewState_obj > CrewState_obj::__alloc(::hx::Ctx *_hx_ctx) {
	CrewState_obj *__this = (CrewState_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(CrewState_obj), true, "CrewState"));
	*(void **)__this = CrewState_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

CrewState_obj::CrewState_obj()
{
}

void CrewState_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CrewState);
	HX_MARK_MEMBER_NAME(officalDevTeam,"officalDevTeam");
	HX_MARK_MEMBER_NAME(curSelected,"curSelected");
	HX_MARK_MEMBER_NAME(globalOffset,"globalOffset");
	 ::HelperStates_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void CrewState_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(officalDevTeam,"officalDevTeam");
	HX_VISIT_MEMBER_NAME(curSelected,"curSelected");
	HX_VISIT_MEMBER_NAME(globalOffset,"globalOffset");
	 ::HelperStates_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val CrewState_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return ::hx::Val( create_dyn() ); }
		if (HX_FIELD_EQ(inName,"update") ) { return ::hx::Val( update_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"changeDev") ) { return ::hx::Val( changeDev_dyn() ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"curSelected") ) { return ::hx::Val( curSelected ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"globalOffset") ) { return ::hx::Val( globalOffset ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"officalDevTeam") ) { return ::hx::Val( officalDevTeam ); }
		if (HX_FIELD_EQ(inName,"makeCoolPeople") ) { return ::hx::Val( makeCoolPeople_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val CrewState_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"curSelected") ) { curSelected=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"globalOffset") ) { globalOffset=inValue.Cast< Float >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"officalDevTeam") ) { officalDevTeam=inValue.Cast<  ::flixel::group::FlxTypedGroup >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CrewState_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("officalDevTeam",3e,71,c0,43));
	outFields->push(HX_("curSelected",fb,eb,ab,32));
	outFields->push(HX_("globalOffset",56,e9,8d,be));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo CrewState_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::flixel::group::FlxTypedGroup */ ,(int)offsetof(CrewState_obj,officalDevTeam),HX_("officalDevTeam",3e,71,c0,43)},
	{::hx::fsInt,(int)offsetof(CrewState_obj,curSelected),HX_("curSelected",fb,eb,ab,32)},
	{::hx::fsFloat,(int)offsetof(CrewState_obj,globalOffset),HX_("globalOffset",56,e9,8d,be)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *CrewState_obj_sStaticStorageInfo = 0;
#endif

static ::String CrewState_obj_sMemberFields[] = {
	HX_("officalDevTeam",3e,71,c0,43),
	HX_("curSelected",fb,eb,ab,32),
	HX_("globalOffset",56,e9,8d,be),
	HX_("create",fc,66,0f,7c),
	HX_("update",09,86,05,87),
	HX_("changeDev",45,e6,f9,1d),
	HX_("makeCoolPeople",86,29,50,34),
	::String(null()) };

::hx::Class CrewState_obj::__mClass;

void CrewState_obj::__register()
{
	CrewState_obj _hx_dummy;
	CrewState_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("CrewState",50,fd,4d,c1);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(CrewState_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< CrewState_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = CrewState_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = CrewState_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

