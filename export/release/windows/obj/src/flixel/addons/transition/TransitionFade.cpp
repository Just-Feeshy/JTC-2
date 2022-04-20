#include <hxcpp.h>

#ifndef INCLUDED_95f339a1d026d52c
#define INCLUDED_95f339a1d026d52c
#include "hxMath.h"
#endif
#ifndef INCLUDED_Reflect
#include <Reflect.h>
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
#ifndef INCLUDED_flixel_addons_transition_TransitionData
#include <flixel/addons/transition/TransitionData.h>
#endif
#ifndef INCLUDED_flixel_addons_transition_TransitionEffect
#include <flixel/addons/transition/TransitionEffect.h>
#endif
#ifndef INCLUDED_flixel_addons_transition_TransitionFade
#include <flixel/addons/transition/TransitionFade.h>
#endif
#ifndef INCLUDED_flixel_addons_transition__TransitionFade_GraphicDiagonalGradient
#include <flixel/addons/transition/_TransitionFade/GraphicDiagonalGradient.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedSpriteGroup
#include <flixel/group/FlxTypedSpriteGroup.h>
#endif
#ifndef INCLUDED_flixel_math_FlxPoint
#include <flixel/math/FlxPoint.h>
#endif
#ifndef INCLUDED_flixel_tweens_FlxTween
#include <flixel/tweens/FlxTween.h>
#endif
#ifndef INCLUDED_flixel_tweens_misc_VarTween
#include <flixel/tweens/misc/VarTween.h>
#endif
#ifndef INCLUDED_flixel_util_FlxGradient
#include <flixel/util/FlxGradient.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxDestroyable
#include <flixel/util/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxPooled
#include <flixel/util/IFlxPooled.h>
#endif
#ifndef INCLUDED_openfl_display_BitmapData
#include <openfl/display/BitmapData.h>
#endif
#ifndef INCLUDED_openfl_display_IBitmapDrawable
#include <openfl/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl_geom_ColorTransform
#include <openfl/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_openfl_geom_Matrix
#include <openfl/geom/Matrix.h>
#endif
#ifndef INCLUDED_openfl_geom_Point
#include <openfl/geom/Point.h>
#endif
#ifndef INCLUDED_openfl_geom_Rectangle
#include <openfl/geom/Rectangle.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_85f0573c4a29b283_22_new,"flixel.addons.transition.TransitionFade","new",0x4927e913,"flixel.addons.transition.TransitionFade.new","flixel/addons/transition/TransitionFade.hx",22,0x307a6abc)
HX_LOCAL_STACK_FRAME(_hx_pos_85f0573c4a29b283_42_destroy,"flixel.addons.transition.TransitionFade","destroy",0x16001b2d,"flixel.addons.transition.TransitionFade.destroy","flixel/addons/transition/TransitionFade.hx",42,0x307a6abc)
HX_LOCAL_STACK_FRAME(_hx_pos_85f0573c4a29b283_48_start,"flixel.addons.transition.TransitionFade","start",0xbc9d5fd5,"flixel.addons.transition.TransitionFade.start","flixel/addons/transition/TransitionFade.hx",48,0x307a6abc)
HX_LOCAL_STACK_FRAME(_hx_pos_85f0573c4a29b283_84_setTweenValues,"flixel.addons.transition.TransitionFade","setTweenValues",0x069b0e58,"flixel.addons.transition.TransitionFade.setTweenValues","flixel/addons/transition/TransitionFade.hx",84,0x307a6abc)
HX_LOCAL_STACK_FRAME(_hx_pos_85f0573c4a29b283_150_makeSprite,"flixel.addons.transition.TransitionFade","makeSprite",0x080a6440,"flixel.addons.transition.TransitionFade.makeSprite","flixel/addons/transition/TransitionFade.hx",150,0x307a6abc)
HX_LOCAL_STACK_FRAME(_hx_pos_85f0573c4a29b283_199_getGradient,"flixel.addons.transition.TransitionFade","getGradient",0xadab8059,"flixel.addons.transition.TransitionFade.getGradient","flixel/addons/transition/TransitionFade.hx",199,0x307a6abc)
HX_LOCAL_STACK_FRAME(_hx_pos_85f0573c4a29b283_218_finishTween,"flixel.addons.transition.TransitionFade","finishTween",0x9dee50cb,"flixel.addons.transition.TransitionFade.finishTween","flixel/addons/transition/TransitionFade.hx",218,0x307a6abc)
namespace flixel{
namespace addons{
namespace transition{

void TransitionFade_obj::__construct( ::flixel::addons::transition::TransitionData data){
            	HX_STACKFRAME(&_hx_pos_85f0573c4a29b283_22_new)
HXLINE(  30)		this->tweenValEnd2 = ((Float)0);
HXLINE(  29)		this->tweenValEnd = ((Float)0);
HXLINE(  28)		this->tweenValStart2 = ((Float)0);
HXLINE(  27)		this->tweenValStart = ((Float)0);
HXLINE(  26)		this->tweenStr2 = HX_("",00,00,00,00);
HXLINE(  25)		this->tweenStr = HX_("",00,00,00,00);
HXLINE(  34)		super::__construct(data);
HXLINE(  36)		this->back = this->makeSprite(data->direction->x,data->direction->y);
HXLINE(  37)		this->back->scrollFactor->set(0,0);
HXLINE(  38)		this->add(this->back);
            	}

Dynamic TransitionFade_obj::__CreateEmpty() { return new TransitionFade_obj; }

void *TransitionFade_obj::_hx_vtable = 0;

Dynamic TransitionFade_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< TransitionFade_obj > _hx_result = new TransitionFade_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool TransitionFade_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x5b6c5e35) {
		if (inClassId<=(int)0x2c01639b) {
			if (inClassId<=(int)0x288ce903) {
				return inClassId==(int)0x00000001 || inClassId==(int)0x288ce903;
			} else {
				return inClassId==(int)0x2c01639b;
			}
		} else {
			return inClassId==(int)0x5b6c5e35;
		}
	} else {
		if (inClassId<=(int)0x7dab0655) {
			return inClassId==(int)0x7ccf8994 || inClassId==(int)0x7dab0655;
		} else {
			return inClassId==(int)0x7fcf2fe2;
		}
	}
}

void TransitionFade_obj::destroy(){
            	HX_STACKFRAME(&_hx_pos_85f0573c4a29b283_42_destroy)
HXLINE(  43)		this->super::destroy();
HXLINE(  44)		this->back = null();
            	}


void TransitionFade_obj::start(int NewStatus){
            	HX_STACKFRAME(&_hx_pos_85f0573c4a29b283_48_start)
HXLINE(  49)		this->super::start(NewStatus);
HXLINE(  51)		this->setTweenValues(NewStatus,this->_data->direction->x,this->_data->direction->y);
HXLINE(  53)		::String _hx_switch_0 = this->tweenStr;
            		if (  (_hx_switch_0==HX_("alpha",5e,a7,96,21)) ){
HXLINE(  56)			this->back->set_alpha(this->tweenValStart);
HXDLIN(  56)			goto _hx_goto_2;
            		}
            		if (  (_hx_switch_0==HX_("x",78,00,00,00)) ){
HXLINE(  58)			this->back->set_x(this->tweenValStart);
HXDLIN(  58)			goto _hx_goto_2;
            		}
            		if (  (_hx_switch_0==HX_("y",79,00,00,00)) ){
HXLINE(  60)			this->back->set_y(this->tweenValStart);
HXDLIN(  60)			goto _hx_goto_2;
            		}
            		_hx_goto_2:;
HXLINE(  62)		::String _hx_switch_1 = this->tweenStr2;
            		if (  (_hx_switch_1==HX_("alpha",5e,a7,96,21)) ){
HXLINE(  65)			this->back->set_alpha(this->tweenValStart2);
HXDLIN(  65)			goto _hx_goto_3;
            		}
            		if (  (_hx_switch_1==HX_("x",78,00,00,00)) ){
HXLINE(  67)			this->back->set_x(this->tweenValStart2);
HXDLIN(  67)			goto _hx_goto_3;
            		}
            		if (  (_hx_switch_1==HX_("y",79,00,00,00)) ){
HXLINE(  69)			this->back->set_y(this->tweenValStart2);
HXDLIN(  69)			goto _hx_goto_3;
            		}
            		_hx_goto_3:;
HXLINE(  72)		 ::Dynamic Values =  ::Dynamic(::hx::Anon_obj::Create(0));
HXLINE(  73)		::Reflect_obj::setField(Values,this->tweenStr,this->tweenValEnd);
HXLINE(  74)		if ((this->tweenStr2 != HX_("",00,00,00,00))) {
HXLINE(  76)			::Reflect_obj::setField(Values,this->tweenStr2,this->tweenValEnd2);
            		}
HXLINE(  78)		this->_data->tweenOptions->__SetField(HX_("onComplete",f8,d4,7e,5d),this->finishTween_dyn(),::hx::paccDynamic);
HXLINE(  79)		::flixel::tweens::FlxTween_obj::tween(this->back,Values,this->_data->duration,this->_data->tweenOptions);
            	}


void TransitionFade_obj::setTweenValues(int NewStatus,Float DirX,Float DirY){
            	HX_STACKFRAME(&_hx_pos_85f0573c4a29b283_84_setTweenValues)
HXDLIN(  84)		bool _hx_tmp;
HXDLIN(  84)		if ((DirX == 0)) {
HXDLIN(  84)			_hx_tmp = (DirY == 0);
            		}
            		else {
HXDLIN(  84)			_hx_tmp = false;
            		}
HXDLIN(  84)		if (_hx_tmp) {
HXLINE(  87)			this->tweenStr = HX_("alpha",5e,a7,96,21);
HXLINE(  88)			Float _hx_tmp;
HXDLIN(  88)			if ((NewStatus == 0)) {
HXLINE(  88)				_hx_tmp = ((Float)0.0);
            			}
            			else {
HXLINE(  88)				_hx_tmp = ((Float)1.0);
            			}
HXDLIN(  88)			this->tweenValStart = _hx_tmp;
HXLINE(  89)			Float _hx_tmp1;
HXDLIN(  89)			if ((NewStatus == 0)) {
HXLINE(  89)				_hx_tmp1 = ((Float)1.0);
            			}
            			else {
HXLINE(  89)				_hx_tmp1 = ((Float)0.0);
            			}
HXDLIN(  89)			this->tweenValEnd = _hx_tmp1;
            		}
            		else {
HXLINE(  91)			bool _hx_tmp;
HXDLIN(  91)			if ((::Math_obj::abs(DirX) > 0)) {
HXLINE(  91)				_hx_tmp = (DirY == 0);
            			}
            			else {
HXLINE(  91)				_hx_tmp = false;
            			}
HXDLIN(  91)			if (_hx_tmp) {
HXLINE(  94)				this->tweenStr = HX_("x",78,00,00,00);
HXLINE(  95)				if ((DirX > 0)) {
HXLINE(  97)					Float _hx_tmp;
HXDLIN(  97)					if ((NewStatus == 0)) {
HXLINE(  97)						_hx_tmp = -(this->back->get_width());
            					}
            					else {
HXLINE(  97)						_hx_tmp = ( (Float)(0) );
            					}
HXDLIN(  97)					this->tweenValStart = _hx_tmp;
HXLINE(  98)					Float _hx_tmp1;
HXDLIN(  98)					if ((NewStatus == 0)) {
HXLINE(  98)						_hx_tmp1 = ( (Float)(0) );
            					}
            					else {
HXLINE(  98)						_hx_tmp1 = -(this->back->get_width());
            					}
HXDLIN(  98)					this->tweenValEnd = _hx_tmp1;
            				}
            				else {
HXLINE( 102)					Float _hx_tmp;
HXDLIN( 102)					if ((NewStatus == 0)) {
HXLINE( 102)						_hx_tmp = ( (Float)(::flixel::FlxG_obj::width) );
            					}
            					else {
HXLINE( 102)						_hx_tmp = (-(this->back->get_width()) / ( (Float)(2) ));
            					}
HXDLIN( 102)					this->tweenValStart = _hx_tmp;
HXLINE( 103)					Float _hx_tmp1;
HXDLIN( 103)					if ((NewStatus == 0)) {
HXLINE( 103)						_hx_tmp1 = (-(this->back->get_width()) / ( (Float)(2) ));
            					}
            					else {
HXLINE( 103)						_hx_tmp1 = ( (Float)(::flixel::FlxG_obj::width) );
            					}
HXDLIN( 103)					this->tweenValEnd = _hx_tmp1;
            				}
            			}
            			else {
HXLINE( 106)				bool _hx_tmp;
HXDLIN( 106)				if ((DirX == 0)) {
HXLINE( 106)					_hx_tmp = (::Math_obj::abs(DirY) > 0);
            				}
            				else {
HXLINE( 106)					_hx_tmp = false;
            				}
HXDLIN( 106)				if (_hx_tmp) {
HXLINE( 109)					this->tweenStr = HX_("y",79,00,00,00);
HXLINE( 110)					if ((DirY > 0)) {
HXLINE( 112)						Float _hx_tmp;
HXDLIN( 112)						if ((NewStatus == 0)) {
HXLINE( 112)							_hx_tmp = -(this->back->get_height());
            						}
            						else {
HXLINE( 112)							_hx_tmp = ( (Float)(0) );
            						}
HXDLIN( 112)						this->tweenValStart = _hx_tmp;
HXLINE( 113)						Float _hx_tmp1;
HXDLIN( 113)						if ((NewStatus == 0)) {
HXLINE( 113)							_hx_tmp1 = ( (Float)(0) );
            						}
            						else {
HXLINE( 113)							_hx_tmp1 = -(this->back->get_height());
            						}
HXDLIN( 113)						this->tweenValEnd = _hx_tmp1;
            					}
            					else {
HXLINE( 117)						Float _hx_tmp;
HXDLIN( 117)						if ((NewStatus == 0)) {
HXLINE( 117)							_hx_tmp = ( (Float)(::flixel::FlxG_obj::height) );
            						}
            						else {
HXLINE( 117)							_hx_tmp = (-(this->back->get_height()) / ( (Float)(2) ));
            						}
HXDLIN( 117)						this->tweenValStart = _hx_tmp;
HXLINE( 118)						Float _hx_tmp1;
HXDLIN( 118)						if ((NewStatus == 0)) {
HXLINE( 118)							_hx_tmp1 = (-(this->back->get_height()) / ( (Float)(2) ));
            						}
            						else {
HXLINE( 118)							_hx_tmp1 = ( (Float)(::flixel::FlxG_obj::height) );
            						}
HXDLIN( 118)						this->tweenValEnd = _hx_tmp1;
            					}
            				}
            				else {
HXLINE( 121)					bool _hx_tmp;
HXDLIN( 121)					if ((::Math_obj::abs(DirX) > 0)) {
HXLINE( 121)						_hx_tmp = (::Math_obj::abs(DirY) > 0);
            					}
            					else {
HXLINE( 121)						_hx_tmp = false;
            					}
HXDLIN( 121)					if (_hx_tmp) {
HXLINE( 124)						this->tweenStr = HX_("x",78,00,00,00);
HXLINE( 125)						this->tweenStr2 = HX_("y",79,00,00,00);
HXLINE( 126)						if ((DirX > 0)) {
HXLINE( 128)							Float _hx_tmp;
HXDLIN( 128)							if ((NewStatus == 0)) {
HXLINE( 128)								_hx_tmp = -(this->back->get_width());
            							}
            							else {
HXLINE( 128)								_hx_tmp = ( (Float)(0) );
            							}
HXDLIN( 128)							this->tweenValStart = _hx_tmp;
HXLINE( 129)							Float _hx_tmp1;
HXDLIN( 129)							if ((NewStatus == 0)) {
HXLINE( 129)								_hx_tmp1 = ( (Float)(0) );
            							}
            							else {
HXLINE( 129)								_hx_tmp1 = -(this->back->get_width());
            							}
HXDLIN( 129)							this->tweenValEnd = _hx_tmp1;
            						}
            						else {
HXLINE( 133)							Float _hx_tmp;
HXDLIN( 133)							if ((NewStatus == 0)) {
HXLINE( 133)								_hx_tmp = ( (Float)(::flixel::FlxG_obj::width) );
            							}
            							else {
HXLINE( 133)								_hx_tmp = (-(this->back->get_width()) * ((Float)0.66666666666666663));
            							}
HXDLIN( 133)							this->tweenValStart = _hx_tmp;
HXLINE( 134)							Float _hx_tmp1;
HXDLIN( 134)							if ((NewStatus == 0)) {
HXLINE( 134)								_hx_tmp1 = (-(this->back->get_width()) * ((Float)0.66666666666666663));
            							}
            							else {
HXLINE( 134)								_hx_tmp1 = ( (Float)(::flixel::FlxG_obj::width) );
            							}
HXDLIN( 134)							this->tweenValEnd = _hx_tmp1;
            						}
HXLINE( 136)						if ((DirY > 0)) {
HXLINE( 138)							Float _hx_tmp;
HXDLIN( 138)							if ((NewStatus == 0)) {
HXLINE( 138)								_hx_tmp = -(this->back->get_height());
            							}
            							else {
HXLINE( 138)								_hx_tmp = ( (Float)(0) );
            							}
HXDLIN( 138)							this->tweenValStart2 = _hx_tmp;
HXLINE( 139)							Float _hx_tmp1;
HXDLIN( 139)							if ((NewStatus == 0)) {
HXLINE( 139)								_hx_tmp1 = ( (Float)(0) );
            							}
            							else {
HXLINE( 139)								_hx_tmp1 = -(this->back->get_height());
            							}
HXDLIN( 139)							this->tweenValEnd2 = _hx_tmp1;
            						}
            						else {
HXLINE( 143)							Float _hx_tmp;
HXDLIN( 143)							if ((NewStatus == 0)) {
HXLINE( 143)								_hx_tmp = ( (Float)(::flixel::FlxG_obj::height) );
            							}
            							else {
HXLINE( 143)								_hx_tmp = (-(this->back->get_height()) * ((Float)0.66666666666666663));
            							}
HXDLIN( 143)							this->tweenValStart2 = _hx_tmp;
HXLINE( 144)							Float _hx_tmp1;
HXDLIN( 144)							if ((NewStatus == 0)) {
HXLINE( 144)								_hx_tmp1 = (-(this->back->get_height()) * ((Float)0.66666666666666663));
            							}
            							else {
HXLINE( 144)								_hx_tmp1 = ( (Float)(::flixel::FlxG_obj::height) );
            							}
HXDLIN( 144)							this->tweenValEnd2 = _hx_tmp1;
            						}
            					}
            				}
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC3(TransitionFade_obj,setTweenValues,(void))

 ::flixel::FlxSprite TransitionFade_obj::makeSprite(Float DirX,Float DirY){
            	HX_GC_STACKFRAME(&_hx_pos_85f0573c4a29b283_150_makeSprite)
HXLINE( 151)		 ::flixel::FlxSprite s =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,0,0,null());
HXLINE( 152)		Float locX = ( (Float)(0) );
HXLINE( 153)		Float locY = ( (Float)(0) );
HXLINE( 154)		int angle = 0;
HXLINE( 155)		 ::openfl::display::BitmapData pixels = null();
HXLINE( 156)		bool _hx_tmp;
HXDLIN( 156)		if ((DirX == 0)) {
HXLINE( 156)			_hx_tmp = (DirY == 0);
            		}
            		else {
HXLINE( 156)			_hx_tmp = false;
            		}
HXDLIN( 156)		if (_hx_tmp) {
HXLINE( 159)			s->makeGraphic(::flixel::FlxG_obj::width,::flixel::FlxG_obj::height,this->_data->color,null(),null());
            		}
            		else {
HXLINE( 161)			bool _hx_tmp;
HXDLIN( 161)			if ((DirX == 0)) {
HXLINE( 161)				_hx_tmp = (::Math_obj::abs(DirY) > 0);
            			}
            			else {
HXLINE( 161)				_hx_tmp = false;
            			}
HXDLIN( 161)			if (_hx_tmp) {
HXLINE( 164)				if ((DirY > 0)) {
HXLINE( 164)					locY = ( (Float)(::flixel::FlxG_obj::height) );
            				}
            				else {
HXLINE( 164)					locY = ( (Float)(0) );
            				}
HXLINE( 165)				if ((DirY > 0)) {
HXLINE( 165)					angle = 90;
            				}
            				else {
HXLINE( 165)					angle = 270;
            				}
HXLINE( 166)				s->makeGraphic(1,(::flixel::FlxG_obj::height * 2),this->_data->color,null(),null());
HXLINE( 167)				pixels = s->get_pixels();
HXLINE( 168)				 ::openfl::display::BitmapData gvert = ::flixel::util::FlxGradient_obj::createGradientBitmapData(1,::flixel::FlxG_obj::height,::Array_obj< int >::__new(2)->init(0,this->_data->color)->init(1,0),1,angle,null());
HXLINE( 169)				 ::openfl::geom::Rectangle gvert1 = gvert->rect;
HXDLIN( 169)				pixels->copyPixels(gvert,gvert1, ::openfl::geom::Point_obj::__alloc( HX_CTX ,0,locY),null(),null(),null());
HXLINE( 170)				s->set_pixels(pixels);
HXLINE( 171)				s->scale->set(::flixel::FlxG_obj::width,((Float)1.0));
HXLINE( 172)				s->updateHitbox();
            			}
            			else {
HXLINE( 174)				bool _hx_tmp;
HXDLIN( 174)				if ((::Math_obj::abs(DirX) > 0)) {
HXLINE( 174)					_hx_tmp = (DirY == 0);
            				}
            				else {
HXLINE( 174)					_hx_tmp = false;
            				}
HXDLIN( 174)				if (_hx_tmp) {
HXLINE( 177)					if ((DirX > 0)) {
HXLINE( 177)						locX = ( (Float)(::flixel::FlxG_obj::width) );
            					}
            					else {
HXLINE( 177)						locX = ( (Float)(0) );
            					}
HXLINE( 178)					if ((DirX > 0)) {
HXLINE( 178)						angle = 0;
            					}
            					else {
HXLINE( 178)						angle = 180;
            					}
HXLINE( 179)					s->makeGraphic((::flixel::FlxG_obj::width * 2),1,this->_data->color,null(),null());
HXLINE( 180)					pixels = s->get_pixels();
HXLINE( 181)					 ::openfl::display::BitmapData ghorz = ::flixel::util::FlxGradient_obj::createGradientBitmapData(::flixel::FlxG_obj::width,1,::Array_obj< int >::__new(2)->init(0,this->_data->color)->init(1,0),1,angle,null());
HXLINE( 182)					 ::openfl::geom::Rectangle ghorz1 = ghorz->rect;
HXDLIN( 182)					pixels->copyPixels(ghorz,ghorz1, ::openfl::geom::Point_obj::__alloc( HX_CTX ,locX,0),null(),null(),null());
HXLINE( 183)					s->set_pixels(pixels);
HXLINE( 184)					s->scale->set(((Float)1.0),::flixel::FlxG_obj::height);
HXLINE( 185)					s->updateHitbox();
            				}
            				else {
HXLINE( 187)					bool _hx_tmp;
HXDLIN( 187)					if ((::Math_obj::abs(DirX) > 0)) {
HXLINE( 187)						_hx_tmp = (::Math_obj::abs(DirY) > 0);
            					}
            					else {
HXLINE( 187)						_hx_tmp = false;
            					}
HXDLIN( 187)					if (_hx_tmp) {
HXLINE( 190)						if ((DirY > 0)) {
HXLINE( 190)							locY = ( (Float)(::flixel::FlxG_obj::height) );
            						}
            						else {
HXLINE( 190)							locY = ( (Float)(0) );
            						}
HXLINE( 191)						s->loadGraphic(this->getGradient(),null(),null(),null(),null(),null());
HXLINE( 192)						s->set_flipX((DirX < 0));
HXLINE( 193)						s->set_flipY((DirY < 0));
            					}
            				}
            			}
            		}
HXLINE( 195)		return s;
            	}


HX_DEFINE_DYNAMIC_FUNC2(TransitionFade_obj,makeSprite,return )

 ::openfl::display::BitmapData TransitionFade_obj::getGradient(){
            	HX_GC_STACKFRAME(&_hx_pos_85f0573c4a29b283_199_getGradient)
HXLINE( 201)		 ::flixel::addons::transition::_TransitionFade::GraphicDiagonalGradient rawBmp =  ::flixel::addons::transition::_TransitionFade::GraphicDiagonalGradient_obj::__alloc( HX_CTX ,0,0,null(),null());
HXLINE( 202)		 ::openfl::display::BitmapData gdiag = ( ( ::openfl::display::BitmapData)(rawBmp) );
HXLINE( 203)		 ::openfl::display::BitmapData gdiag_scaled =  ::openfl::display::BitmapData_obj::__alloc( HX_CTX ,(::flixel::FlxG_obj::width * 2),(::flixel::FlxG_obj::height * 2),true,null());
HXLINE( 204)		 ::openfl::geom::Matrix m =  ::openfl::geom::Matrix_obj::__alloc( HX_CTX ,null(),null(),null(),null(),null(),null());
HXLINE( 205)		m->scale((( (Float)(gdiag_scaled->width) ) / ( (Float)(gdiag->width) )),(( (Float)(gdiag_scaled->height) ) / ( (Float)(gdiag->height) )));
HXLINE( 206)		gdiag_scaled->draw(gdiag,m,null(),null(),null(),true);
HXLINE( 207)		int theColor = this->_data->color;
HXLINE( 208)		 ::openfl::display::BitmapData final_pixels =  ::openfl::display::BitmapData_obj::__alloc( HX_CTX ,(::flixel::FlxG_obj::width * 3),(::flixel::FlxG_obj::height * 3),true,theColor);
HXLINE( 209)		 ::openfl::geom::Rectangle gdiag_scaled1 = gdiag_scaled->rect;
HXDLIN( 209)		final_pixels->copyChannel(gdiag_scaled,gdiag_scaled1, ::openfl::geom::Point_obj::__alloc( HX_CTX ,(final_pixels->width - gdiag_scaled->width),(final_pixels->height - gdiag_scaled->height)),1,8);
HXLINE( 211)		gdiag->dispose();
HXLINE( 212)		gdiag_scaled->dispose();
HXLINE( 213)		return final_pixels;
            	}


HX_DEFINE_DYNAMIC_FUNC0(TransitionFade_obj,getGradient,return )

void TransitionFade_obj::finishTween( ::flixel::tweens::FlxTween f){
            	HX_STACKFRAME(&_hx_pos_85f0573c4a29b283_218_finishTween)
HXDLIN( 218)		this->delayThenFinish();
            	}


HX_DEFINE_DYNAMIC_FUNC1(TransitionFade_obj,finishTween,(void))


::hx::ObjectPtr< TransitionFade_obj > TransitionFade_obj::__new( ::flixel::addons::transition::TransitionData data) {
	::hx::ObjectPtr< TransitionFade_obj > __this = new TransitionFade_obj();
	__this->__construct(data);
	return __this;
}

::hx::ObjectPtr< TransitionFade_obj > TransitionFade_obj::__alloc(::hx::Ctx *_hx_ctx, ::flixel::addons::transition::TransitionData data) {
	TransitionFade_obj *__this = (TransitionFade_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(TransitionFade_obj), true, "flixel.addons.transition.TransitionFade"));
	*(void **)__this = TransitionFade_obj::_hx_vtable;
	__this->__construct(data);
	return __this;
}

TransitionFade_obj::TransitionFade_obj()
{
}

void TransitionFade_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TransitionFade);
	HX_MARK_MEMBER_NAME(back,"back");
	HX_MARK_MEMBER_NAME(tweenStr,"tweenStr");
	HX_MARK_MEMBER_NAME(tweenStr2,"tweenStr2");
	HX_MARK_MEMBER_NAME(tweenValStart,"tweenValStart");
	HX_MARK_MEMBER_NAME(tweenValStart2,"tweenValStart2");
	HX_MARK_MEMBER_NAME(tweenValEnd,"tweenValEnd");
	HX_MARK_MEMBER_NAME(tweenValEnd2,"tweenValEnd2");
	 ::flixel::addons::transition::TransitionEffect_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void TransitionFade_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(back,"back");
	HX_VISIT_MEMBER_NAME(tweenStr,"tweenStr");
	HX_VISIT_MEMBER_NAME(tweenStr2,"tweenStr2");
	HX_VISIT_MEMBER_NAME(tweenValStart,"tweenValStart");
	HX_VISIT_MEMBER_NAME(tweenValStart2,"tweenValStart2");
	HX_VISIT_MEMBER_NAME(tweenValEnd,"tweenValEnd");
	HX_VISIT_MEMBER_NAME(tweenValEnd2,"tweenValEnd2");
	 ::flixel::addons::transition::TransitionEffect_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val TransitionFade_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"back") ) { return ::hx::Val( back ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"start") ) { return ::hx::Val( start_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return ::hx::Val( destroy_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"tweenStr") ) { return ::hx::Val( tweenStr ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"tweenStr2") ) { return ::hx::Val( tweenStr2 ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"makeSprite") ) { return ::hx::Val( makeSprite_dyn() ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"tweenValEnd") ) { return ::hx::Val( tweenValEnd ); }
		if (HX_FIELD_EQ(inName,"getGradient") ) { return ::hx::Val( getGradient_dyn() ); }
		if (HX_FIELD_EQ(inName,"finishTween") ) { return ::hx::Val( finishTween_dyn() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"tweenValEnd2") ) { return ::hx::Val( tweenValEnd2 ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"tweenValStart") ) { return ::hx::Val( tweenValStart ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"tweenValStart2") ) { return ::hx::Val( tweenValStart2 ); }
		if (HX_FIELD_EQ(inName,"setTweenValues") ) { return ::hx::Val( setTweenValues_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val TransitionFade_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"back") ) { back=inValue.Cast<  ::flixel::FlxSprite >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"tweenStr") ) { tweenStr=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"tweenStr2") ) { tweenStr2=inValue.Cast< ::String >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"tweenValEnd") ) { tweenValEnd=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"tweenValEnd2") ) { tweenValEnd2=inValue.Cast< Float >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"tweenValStart") ) { tweenValStart=inValue.Cast< Float >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"tweenValStart2") ) { tweenValStart2=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TransitionFade_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("back",27,da,10,41));
	outFields->push(HX_("tweenStr",06,cb,ce,11));
	outFields->push(HX_("tweenStr2",6c,da,22,83));
	outFields->push(HX_("tweenValStart",4c,bf,69,c2));
	outFields->push(HX_("tweenValStart2",66,a3,1d,5a));
	outFields->push(HX_("tweenValEnd",45,e0,eb,f3));
	outFields->push(HX_("tweenValEnd2",4d,5c,78,7a));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo TransitionFade_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::flixel::FlxSprite */ ,(int)offsetof(TransitionFade_obj,back),HX_("back",27,da,10,41)},
	{::hx::fsString,(int)offsetof(TransitionFade_obj,tweenStr),HX_("tweenStr",06,cb,ce,11)},
	{::hx::fsString,(int)offsetof(TransitionFade_obj,tweenStr2),HX_("tweenStr2",6c,da,22,83)},
	{::hx::fsFloat,(int)offsetof(TransitionFade_obj,tweenValStart),HX_("tweenValStart",4c,bf,69,c2)},
	{::hx::fsFloat,(int)offsetof(TransitionFade_obj,tweenValStart2),HX_("tweenValStart2",66,a3,1d,5a)},
	{::hx::fsFloat,(int)offsetof(TransitionFade_obj,tweenValEnd),HX_("tweenValEnd",45,e0,eb,f3)},
	{::hx::fsFloat,(int)offsetof(TransitionFade_obj,tweenValEnd2),HX_("tweenValEnd2",4d,5c,78,7a)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *TransitionFade_obj_sStaticStorageInfo = 0;
#endif

static ::String TransitionFade_obj_sMemberFields[] = {
	HX_("back",27,da,10,41),
	HX_("tweenStr",06,cb,ce,11),
	HX_("tweenStr2",6c,da,22,83),
	HX_("tweenValStart",4c,bf,69,c2),
	HX_("tweenValStart2",66,a3,1d,5a),
	HX_("tweenValEnd",45,e0,eb,f3),
	HX_("tweenValEnd2",4d,5c,78,7a),
	HX_("destroy",fa,2c,86,24),
	HX_("start",62,74,0b,84),
	HX_("setTweenValues",2b,80,ce,9b),
	HX_("makeSprite",93,b0,65,15),
	HX_("getGradient",a6,fc,32,50),
	HX_("finishTween",18,cd,75,40),
	::String(null()) };

::hx::Class TransitionFade_obj::__mClass;

void TransitionFade_obj::__register()
{
	TransitionFade_obj _hx_dummy;
	TransitionFade_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("flixel.addons.transition.TransitionFade",a1,63,fb,b1);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(TransitionFade_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< TransitionFade_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = TransitionFade_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = TransitionFade_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace flixel
} // end namespace addons
} // end namespace transition
