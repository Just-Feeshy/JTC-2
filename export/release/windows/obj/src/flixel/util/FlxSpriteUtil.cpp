#include <hxcpp.h>

#ifndef INCLUDED_95f339a1d026d52c
#define INCLUDED_95f339a1d026d52c
#include "hxMath.h"
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxCamera
#include <flixel/FlxCamera.h>
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
#ifndef INCLUDED_flixel_effects_FlxFlicker
#include <flixel/effects/FlxFlicker.h>
#endif
#ifndef INCLUDED_flixel_math_FlxPoint
#include <flixel/math/FlxPoint.h>
#endif
#ifndef INCLUDED_flixel_math_FlxRect
#include <flixel/math/FlxRect.h>
#endif
#ifndef INCLUDED_flixel_system_FlxAssets
#include <flixel/system/FlxAssets.h>
#endif
#ifndef INCLUDED_flixel_tweens_FlxTween
#include <flixel/tweens/FlxTween.h>
#endif
#ifndef INCLUDED_flixel_tweens_misc_NumTween
#include <flixel/tweens/misc/NumTween.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPool_flixel_math_FlxPoint
#include <flixel/util/FlxPool_flixel_math_FlxPoint.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPool_flixel_math_FlxRect
#include <flixel/util/FlxPool_flixel_math_FlxRect.h>
#endif
#ifndef INCLUDED_flixel_util_FlxSpriteUtil
#include <flixel/util/FlxSpriteUtil.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxDestroyable
#include <flixel/util/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxPool
#include <flixel/util/IFlxPool.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxPooled
#include <flixel/util/IFlxPooled.h>
#endif
#ifndef INCLUDED_openfl_display_BitmapData
#include <openfl/display/BitmapData.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObject
#include <openfl/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObjectContainer
#include <openfl/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_openfl_display_Graphics
#include <openfl/display/Graphics.h>
#endif
#ifndef INCLUDED_openfl_display_IBitmapDrawable
#include <openfl/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl_display_InteractiveObject
#include <openfl/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_openfl_display_Sprite
#include <openfl/display/Sprite.h>
#endif
#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
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

HX_LOCAL_STACK_FRAME(_hx_pos_aff86ac70b6ed09e_57_alphaMask,"flixel.util.FlxSpriteUtil","alphaMask",0xaad6793b,"flixel.util.FlxSpriteUtil.alphaMask","flixel/util/FlxSpriteUtil.hx",57,0xc647097f)
HX_LOCAL_STACK_FRAME(_hx_pos_aff86ac70b6ed09e_86_alphaMaskFlxSprite,"flixel.util.FlxSpriteUtil","alphaMaskFlxSprite",0x13c0dd5c,"flixel.util.FlxSpriteUtil.alphaMaskFlxSprite","flixel/util/FlxSpriteUtil.hx",86,0xc647097f)
HX_LOCAL_STACK_FRAME(_hx_pos_aff86ac70b6ed09e_106_screenWrap,"flixel.util.FlxSpriteUtil","screenWrap",0x74418065,"flixel.util.FlxSpriteUtil.screenWrap","flixel/util/FlxSpriteUtil.hx",106,0xc647097f)
HX_LOCAL_STACK_FRAME(_hx_pos_aff86ac70b6ed09e_139_bound,"flixel.util.FlxSpriteUtil","bound",0x7d89918f,"flixel.util.FlxSpriteUtil.bound","flixel/util/FlxSpriteUtil.hx",139,0xc647097f)
HX_LOCAL_STACK_FRAME(_hx_pos_aff86ac70b6ed09e_168_cameraWrap,"flixel.util.FlxSpriteUtil","cameraWrap",0x62291c1e,"flixel.util.FlxSpriteUtil.cameraWrap","flixel/util/FlxSpriteUtil.hx",168,0xc647097f)
HX_LOCAL_STACK_FRAME(_hx_pos_aff86ac70b6ed09e_206_cameraBound,"flixel.util.FlxSpriteUtil","cameraBound",0x6878d76a,"flixel.util.FlxSpriteUtil.cameraBound","flixel/util/FlxSpriteUtil.hx",206,0xc647097f)
HX_LOCAL_STACK_FRAME(_hx_pos_aff86ac70b6ed09e_247_space,"flixel.util.FlxSpriteUtil","space",0x47f36e17,"flixel.util.FlxSpriteUtil.space","flixel/util/FlxSpriteUtil.hx",247,0xc647097f)
HX_LOCAL_STACK_FRAME(_hx_pos_aff86ac70b6ed09e_349_drawLine,"flixel.util.FlxSpriteUtil","drawLine",0x239cc967,"flixel.util.FlxSpriteUtil.drawLine","flixel/util/FlxSpriteUtil.hx",349,0xc647097f)
HX_LOCAL_STACK_FRAME(_hx_pos_aff86ac70b6ed09e_376_drawCurve,"flixel.util.FlxSpriteUtil","drawCurve",0xdee9dfdc,"flixel.util.FlxSpriteUtil.drawCurve","flixel/util/FlxSpriteUtil.hx",376,0xc647097f)
HX_LOCAL_STACK_FRAME(_hx_pos_aff86ac70b6ed09e_400_drawRect,"flixel.util.FlxSpriteUtil","drawRect",0x2790fe97,"flixel.util.FlxSpriteUtil.drawRect","flixel/util/FlxSpriteUtil.hx",400,0xc647097f)
HX_LOCAL_STACK_FRAME(_hx_pos_aff86ac70b6ed09e_424_drawRoundRect,"flixel.util.FlxSpriteUtil","drawRoundRect",0x00e2de3f,"flixel.util.FlxSpriteUtil.drawRoundRect","flixel/util/FlxSpriteUtil.hx",424,0xc647097f)
HX_LOCAL_STACK_FRAME(_hx_pos_aff86ac70b6ed09e_452_drawRoundRectComplex,"flixel.util.FlxSpriteUtil","drawRoundRectComplex",0xe28185b1,"flixel.util.FlxSpriteUtil.drawRoundRectComplex","flixel/util/FlxSpriteUtil.hx",452,0xc647097f)
HX_LOCAL_STACK_FRAME(_hx_pos_aff86ac70b6ed09e_474_drawCircle,"flixel.util.FlxSpriteUtil","drawCircle",0x44dca643,"flixel.util.FlxSpriteUtil.drawCircle","flixel/util/FlxSpriteUtil.hx",474,0xc647097f)
HX_LOCAL_STACK_FRAME(_hx_pos_aff86ac70b6ed09e_514_drawEllipse,"flixel.util.FlxSpriteUtil","drawEllipse",0x1204b94b,"flixel.util.FlxSpriteUtil.drawEllipse","flixel/util/FlxSpriteUtil.hx",514,0xc647097f)
HX_LOCAL_STACK_FRAME(_hx_pos_aff86ac70b6ed09e_535_drawTriangle,"flixel.util.FlxSpriteUtil","drawTriangle",0x35f0a5bb,"flixel.util.FlxSpriteUtil.drawTriangle","flixel/util/FlxSpriteUtil.hx",535,0xc647097f)
HX_LOCAL_STACK_FRAME(_hx_pos_aff86ac70b6ed09e_557_drawPolygon,"flixel.util.FlxSpriteUtil","drawPolygon",0x190f7ae7,"flixel.util.FlxSpriteUtil.drawPolygon","flixel/util/FlxSpriteUtil.hx",557,0xc647097f)
HX_LOCAL_STACK_FRAME(_hx_pos_aff86ac70b6ed09e_578_beginDraw,"flixel.util.FlxSpriteUtil","beginDraw",0x53d0689e,"flixel.util.FlxSpriteUtil.beginDraw","flixel/util/FlxSpriteUtil.hx",578,0xc647097f)
HX_LOCAL_STACK_FRAME(_hx_pos_aff86ac70b6ed09e_596_endDraw,"flixel.util.FlxSpriteUtil","endDraw",0x51197d10,"flixel.util.FlxSpriteUtil.endDraw","flixel/util/FlxSpriteUtil.hx",596,0xc647097f)
HX_LOCAL_STACK_FRAME(_hx_pos_aff86ac70b6ed09e_611_updateSpriteGraphic,"flixel.util.FlxSpriteUtil","updateSpriteGraphic",0x448b866b,"flixel.util.FlxSpriteUtil.updateSpriteGraphic","flixel/util/FlxSpriteUtil.hx",611,0xc647097f)
HX_LOCAL_STACK_FRAME(_hx_pos_aff86ac70b6ed09e_635_setLineStyle,"flixel.util.FlxSpriteUtil","setLineStyle",0xc19fc36a,"flixel.util.FlxSpriteUtil.setLineStyle","flixel/util/FlxSpriteUtil.hx",635,0xc647097f)
HX_LOCAL_STACK_FRAME(_hx_pos_aff86ac70b6ed09e_657_getDefaultLineStyle,"flixel.util.FlxSpriteUtil","getDefaultLineStyle",0x36c9a563,"flixel.util.FlxSpriteUtil.getDefaultLineStyle","flixel/util/FlxSpriteUtil.hx",657,0xc647097f)
HX_LOCAL_STACK_FRAME(_hx_pos_aff86ac70b6ed09e_676_fill,"flixel.util.FlxSpriteUtil","fill",0x7a944252,"flixel.util.FlxSpriteUtil.fill","flixel/util/FlxSpriteUtil.hx",676,0xc647097f)
HX_LOCAL_STACK_FRAME(_hx_pos_aff86ac70b6ed09e_702_flicker,"flixel.util.FlxSpriteUtil","flicker",0xa3717289,"flixel.util.FlxSpriteUtil.flicker","flixel/util/FlxSpriteUtil.hx",702,0xc647097f)
HX_LOCAL_STACK_FRAME(_hx_pos_aff86ac70b6ed09e_712_isFlickering,"flixel.util.FlxSpriteUtil","isFlickering",0x05aae043,"flixel.util.FlxSpriteUtil.isFlickering","flixel/util/FlxSpriteUtil.hx",712,0xc647097f)
HX_LOCAL_STACK_FRAME(_hx_pos_aff86ac70b6ed09e_722_stopFlickering,"flixel.util.FlxSpriteUtil","stopFlickering",0x9d49141b,"flixel.util.FlxSpriteUtil.stopFlickering","flixel/util/FlxSpriteUtil.hx",722,0xc647097f)
HX_LOCAL_STACK_FRAME(_hx_pos_aff86ac70b6ed09e_740_fadeIn,"flixel.util.FlxSpriteUtil","fadeIn",0xd9639210,"flixel.util.FlxSpriteUtil.fadeIn","flixel/util/FlxSpriteUtil.hx",740,0xc647097f)
HX_LOCAL_STACK_FRAME(_hx_pos_aff86ac70b6ed09e_735_fadeIn,"flixel.util.FlxSpriteUtil","fadeIn",0xd9639210,"flixel.util.FlxSpriteUtil.fadeIn","flixel/util/FlxSpriteUtil.hx",735,0xc647097f)
HX_LOCAL_STACK_FRAME(_hx_pos_aff86ac70b6ed09e_753_fadeOut,"flixel.util.FlxSpriteUtil","fadeOut",0x5dc0d003,"flixel.util.FlxSpriteUtil.fadeOut","flixel/util/FlxSpriteUtil.hx",753,0xc647097f)
HX_LOCAL_STACK_FRAME(_hx_pos_aff86ac70b6ed09e_752_fadeOut,"flixel.util.FlxSpriteUtil","fadeOut",0x5dc0d003,"flixel.util.FlxSpriteUtil.fadeOut","flixel/util/FlxSpriteUtil.hx",752,0xc647097f)
HX_LOCAL_STACK_FRAME(_hx_pos_aff86ac70b6ed09e_759_alphaTween,"flixel.util.FlxSpriteUtil","alphaTween",0xe721b73c,"flixel.util.FlxSpriteUtil.alphaTween","flixel/util/FlxSpriteUtil.hx",759,0xc647097f)
HX_LOCAL_STACK_FRAME(_hx_pos_aff86ac70b6ed09e_39_boot,"flixel.util.FlxSpriteUtil","boot",0x77f3f801,"flixel.util.FlxSpriteUtil.boot","flixel/util/FlxSpriteUtil.hx",39,0xc647097f)
HX_LOCAL_STACK_FRAME(_hx_pos_aff86ac70b6ed09e_41_boot,"flixel.util.FlxSpriteUtil","boot",0x77f3f801,"flixel.util.FlxSpriteUtil.boot","flixel/util/FlxSpriteUtil.hx",41,0xc647097f)
namespace flixel{
namespace util{

void FlxSpriteUtil_obj::__construct() { }

Dynamic FlxSpriteUtil_obj::__CreateEmpty() { return new FlxSpriteUtil_obj; }

void *FlxSpriteUtil_obj::_hx_vtable = 0;

Dynamic FlxSpriteUtil_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< FlxSpriteUtil_obj > _hx_result = new FlxSpriteUtil_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool FlxSpriteUtil_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x0a1ec5f3;
}

 ::openfl::display::Sprite FlxSpriteUtil_obj::flashGfxSprite;

 ::openfl::display::Graphics FlxSpriteUtil_obj::flashGfx;

 ::flixel::FlxSprite FlxSpriteUtil_obj::alphaMask( ::flixel::FlxSprite output, ::Dynamic source, ::Dynamic mask){
            	HX_GC_STACKFRAME(&_hx_pos_aff86ac70b6ed09e_57_alphaMask)
HXLINE(  58)		 ::openfl::display::BitmapData data = ::flixel::_hx_system::FlxAssets_obj::resolveBitmapData(source);
HXLINE(  59)		 ::openfl::display::BitmapData maskData = ::flixel::_hx_system::FlxAssets_obj::resolveBitmapData(mask);
HXLINE(  61)		bool _hx_tmp;
HXDLIN(  61)		if (::hx::IsNotNull( data )) {
HXLINE(  61)			_hx_tmp = ::hx::IsNull( maskData );
            		}
            		else {
HXLINE(  61)			_hx_tmp = true;
            		}
HXDLIN(  61)		if (_hx_tmp) {
HXLINE(  63)			return null();
            		}
HXLINE(  66)		data = data->clone();
HXLINE(  67)		 ::openfl::geom::Rectangle _hx_tmp1 =  ::openfl::geom::Rectangle_obj::__alloc( HX_CTX ,0,0,data->width,data->height);
HXDLIN(  67)		data->copyChannel(maskData,_hx_tmp1, ::openfl::geom::Point_obj::__alloc( HX_CTX ,null(),null()),8,8);
HXLINE(  68)		output->set_pixels(data);
HXLINE(  69)		return output;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FlxSpriteUtil_obj,alphaMask,return )

 ::flixel::FlxSprite FlxSpriteUtil_obj::alphaMaskFlxSprite( ::flixel::FlxSprite sprite, ::flixel::FlxSprite mask, ::flixel::FlxSprite output){
            	HX_GC_STACKFRAME(&_hx_pos_aff86ac70b6ed09e_86_alphaMaskFlxSprite)
HXLINE(  87)		sprite->drawFrame(null());
HXLINE(  88)		 ::openfl::display::BitmapData data = sprite->get_pixels()->clone();
HXLINE(  89)		 ::openfl::display::BitmapData _hx_tmp = mask->get_pixels();
HXDLIN(  89)		Float _hx_tmp1 = sprite->get_width();
HXDLIN(  89)		 ::openfl::geom::Rectangle _hx_tmp2 =  ::openfl::geom::Rectangle_obj::__alloc( HX_CTX ,0,0,_hx_tmp1,sprite->get_height());
HXDLIN(  89)		data->copyChannel(_hx_tmp,_hx_tmp2, ::openfl::geom::Point_obj::__alloc( HX_CTX ,null(),null()),8,8);
HXLINE(  90)		output->set_pixels(data);
HXLINE(  91)		return output;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FlxSpriteUtil_obj,alphaMaskFlxSprite,return )

 ::flixel::FlxSprite FlxSpriteUtil_obj::screenWrap( ::flixel::FlxSprite sprite,::hx::Null< bool >  __o_Left,::hx::Null< bool >  __o_Right,::hx::Null< bool >  __o_Top,::hx::Null< bool >  __o_Bottom){
            		bool Left = __o_Left.Default(true);
            		bool Right = __o_Right.Default(true);
            		bool Top = __o_Top.Default(true);
            		bool Bottom = __o_Bottom.Default(true);
            	HX_STACKFRAME(&_hx_pos_aff86ac70b6ed09e_106_screenWrap)
HXLINE( 107)		bool _hx_tmp;
HXDLIN( 107)		if (Left) {
HXLINE( 107)			_hx_tmp = ((sprite->x + (( (Float)(sprite->frameWidth) ) / ( (Float)(2) ))) <= 0);
            		}
            		else {
HXLINE( 107)			_hx_tmp = false;
            		}
HXDLIN( 107)		if (_hx_tmp) {
HXLINE( 109)			sprite->set_x(( (Float)(::flixel::FlxG_obj::width) ));
            		}
            		else {
HXLINE( 111)			bool _hx_tmp;
HXDLIN( 111)			if (Right) {
HXLINE( 111)				_hx_tmp = (sprite->x >= ::flixel::FlxG_obj::width);
            			}
            			else {
HXLINE( 111)				_hx_tmp = false;
            			}
HXDLIN( 111)			if (_hx_tmp) {
HXLINE( 113)				sprite->set_x(( (Float)(0) ));
            			}
            		}
HXLINE( 116)		bool _hx_tmp1;
HXDLIN( 116)		if (Top) {
HXLINE( 116)			_hx_tmp1 = ((sprite->y + (( (Float)(sprite->frameHeight) ) / ( (Float)(2) ))) <= 0);
            		}
            		else {
HXLINE( 116)			_hx_tmp1 = false;
            		}
HXDLIN( 116)		if (_hx_tmp1) {
HXLINE( 118)			sprite->set_y(( (Float)(::flixel::FlxG_obj::height) ));
            		}
            		else {
HXLINE( 120)			bool _hx_tmp;
HXDLIN( 120)			if (Bottom) {
HXLINE( 120)				_hx_tmp = (sprite->y >= ::flixel::FlxG_obj::height);
            			}
            			else {
HXLINE( 120)				_hx_tmp = false;
            			}
HXDLIN( 120)			if (_hx_tmp) {
HXLINE( 122)				sprite->set_y(( (Float)(0) ));
            			}
            		}
HXLINE( 124)		return sprite;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(FlxSpriteUtil_obj,screenWrap,return )

 ::flixel::FlxSprite FlxSpriteUtil_obj::bound( ::flixel::FlxSprite sprite,::hx::Null< Float >  __o_MinX,::hx::Null< Float >  __o_MaxX,::hx::Null< Float >  __o_MinY,::hx::Null< Float >  __o_MaxY){
            		Float MinX = __o_MinX.Default(0);
            		Float MaxX = __o_MaxX.Default(0);
            		Float MinY = __o_MinY.Default(0);
            		Float MaxY = __o_MaxY.Default(0);
            	HX_STACKFRAME(&_hx_pos_aff86ac70b6ed09e_139_bound)
HXLINE( 140)		if ((MaxX <= 0)) {
HXLINE( 142)			MaxX = ( (Float)(::flixel::FlxG_obj::width) );
            		}
HXLINE( 144)		if ((MaxY <= 0)) {
HXLINE( 146)			MaxY = ( (Float)(::flixel::FlxG_obj::height) );
            		}
HXLINE( 149)		MaxX = (MaxX - ( (Float)(sprite->frameWidth) ));
HXLINE( 150)		MaxY = (MaxY - ( (Float)(sprite->frameHeight) ));
HXLINE( 152)		Float Value = sprite->x;
HXDLIN( 152)		Float lowerBound;
HXDLIN( 152)		bool lowerBound1;
HXDLIN( 152)		if (::hx::IsNotNull( MinX )) {
HXLINE( 152)			lowerBound1 = (Value < MinX);
            		}
            		else {
HXLINE( 152)			lowerBound1 = false;
            		}
HXDLIN( 152)		if (lowerBound1) {
HXLINE( 152)			lowerBound = MinX;
            		}
            		else {
HXLINE( 152)			lowerBound = Value;
            		}
HXDLIN( 152)		Float _hx_tmp;
HXDLIN( 152)		bool _hx_tmp1;
HXDLIN( 152)		if (::hx::IsNotNull( MaxX )) {
HXLINE( 152)			_hx_tmp1 = (lowerBound > MaxX);
            		}
            		else {
HXLINE( 152)			_hx_tmp1 = false;
            		}
HXDLIN( 152)		if (_hx_tmp1) {
HXLINE( 152)			_hx_tmp = MaxX;
            		}
            		else {
HXLINE( 152)			_hx_tmp = lowerBound;
            		}
HXDLIN( 152)		sprite->set_x(_hx_tmp);
HXLINE( 153)		Float Value1 = sprite->y;
HXDLIN( 153)		Float lowerBound2;
HXDLIN( 153)		bool lowerBound3;
HXDLIN( 153)		if (::hx::IsNotNull( MinY )) {
HXLINE( 153)			lowerBound3 = (Value1 < MinY);
            		}
            		else {
HXLINE( 153)			lowerBound3 = false;
            		}
HXDLIN( 153)		if (lowerBound3) {
HXLINE( 153)			lowerBound2 = MinY;
            		}
            		else {
HXLINE( 153)			lowerBound2 = Value1;
            		}
HXDLIN( 153)		Float _hx_tmp2;
HXDLIN( 153)		bool _hx_tmp3;
HXDLIN( 153)		if (::hx::IsNotNull( MaxY )) {
HXLINE( 153)			_hx_tmp3 = (lowerBound2 > MaxY);
            		}
            		else {
HXLINE( 153)			_hx_tmp3 = false;
            		}
HXDLIN( 153)		if (_hx_tmp3) {
HXLINE( 153)			_hx_tmp2 = MaxY;
            		}
            		else {
HXLINE( 153)			_hx_tmp2 = lowerBound2;
            		}
HXDLIN( 153)		sprite->set_y(_hx_tmp2);
HXLINE( 155)		return sprite;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(FlxSpriteUtil_obj,bound,return )

 ::flixel::FlxSprite FlxSpriteUtil_obj::cameraWrap( ::flixel::FlxSprite sprite, ::flixel::FlxCamera camera,::hx::Null< int >  __o_edges){
            		int edges = __o_edges.Default(4369);
            	HX_STACKFRAME(&_hx_pos_aff86ac70b6ed09e_168_cameraWrap)
HXLINE( 169)		if (::hx::IsNull( camera )) {
HXLINE( 170)			camera = ::flixel::FlxG_obj::camera;
            		}
HXLINE( 172)		 ::flixel::math::FlxRect spriteBounds = sprite->getScreenBounds(null(),camera);
HXLINE( 173)		 ::flixel::math::FlxRect viewBounds = camera->getViewRect(null());
HXLINE( 174)		Float X = ((sprite->x - spriteBounds->x) - camera->scroll->x);
HXDLIN( 174)		Float Y = ((sprite->y - spriteBounds->y) - camera->scroll->y);
HXDLIN( 174)		 ::flixel::math::FlxPoint point = ::flixel::math::FlxPoint_obj::_pool->get()->set(X,Y);
HXDLIN( 174)		point->_inPool = false;
HXDLIN( 174)		 ::flixel::math::FlxPoint offset = point;
HXLINE( 179)		bool _hx_tmp;
HXDLIN( 179)		int dir = 1;
HXDLIN( 179)		if (((edges & dir) == dir)) {
HXLINE( 179)			_hx_tmp = ((spriteBounds->x + spriteBounds->width) < viewBounds->x);
            		}
            		else {
HXLINE( 179)			_hx_tmp = false;
            		}
HXDLIN( 179)		if (_hx_tmp) {
HXLINE( 180)			sprite->set_x(((camera->scroll->x + (viewBounds->x + viewBounds->width)) + offset->x));
            		}
            		else {
HXLINE( 181)			bool _hx_tmp;
HXDLIN( 181)			int dir = 16;
HXDLIN( 181)			if (((edges & dir) == dir)) {
HXLINE( 181)				_hx_tmp = (spriteBounds->x > (viewBounds->x + viewBounds->width));
            			}
            			else {
HXLINE( 181)				_hx_tmp = false;
            			}
HXDLIN( 181)			if (_hx_tmp) {
HXLINE( 182)				sprite->set_x((((camera->scroll->x + viewBounds->x) + offset->x) - spriteBounds->width));
            			}
            		}
HXLINE( 184)		bool _hx_tmp1;
HXDLIN( 184)		int dir1 = 256;
HXDLIN( 184)		if (((edges & dir1) == dir1)) {
HXLINE( 184)			_hx_tmp1 = ((spriteBounds->y + spriteBounds->height) < viewBounds->y);
            		}
            		else {
HXLINE( 184)			_hx_tmp1 = false;
            		}
HXDLIN( 184)		if (_hx_tmp1) {
HXLINE( 185)			sprite->set_y(((camera->scroll->y + (viewBounds->y + viewBounds->height)) + offset->y));
            		}
            		else {
HXLINE( 186)			bool _hx_tmp;
HXDLIN( 186)			int dir = 4096;
HXDLIN( 186)			if (((edges & dir) == dir)) {
HXLINE( 186)				_hx_tmp = (spriteBounds->y > (viewBounds->y + viewBounds->height));
            			}
            			else {
HXLINE( 186)				_hx_tmp = false;
            			}
HXDLIN( 186)			if (_hx_tmp) {
HXLINE( 187)				sprite->set_y((((camera->scroll->y + viewBounds->y) + offset->y) - spriteBounds->height));
            			}
            		}
HXLINE( 189)		if (!(spriteBounds->_inPool)) {
HXLINE( 189)			spriteBounds->_inPool = true;
HXDLIN( 189)			spriteBounds->_weak = false;
HXDLIN( 189)			::flixel::math::FlxRect_obj::_pool->putUnsafe(spriteBounds);
            		}
HXLINE( 190)		if (!(viewBounds->_inPool)) {
HXLINE( 190)			viewBounds->_inPool = true;
HXDLIN( 190)			viewBounds->_weak = false;
HXDLIN( 190)			::flixel::math::FlxRect_obj::_pool->putUnsafe(viewBounds);
            		}
HXLINE( 191)		offset->put();
HXLINE( 193)		return sprite;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FlxSpriteUtil_obj,cameraWrap,return )

 ::flixel::FlxSprite FlxSpriteUtil_obj::cameraBound( ::flixel::FlxSprite sprite, ::flixel::FlxCamera camera,::hx::Null< int >  __o_edges){
            		int edges = __o_edges.Default(4369);
            	HX_STACKFRAME(&_hx_pos_aff86ac70b6ed09e_206_cameraBound)
HXLINE( 207)		if (::hx::IsNull( camera )) {
HXLINE( 208)			camera = ::flixel::FlxG_obj::camera;
            		}
HXLINE( 210)		 ::flixel::math::FlxRect spriteBounds = sprite->getScreenBounds(null(),camera);
HXLINE( 211)		 ::flixel::math::FlxRect viewBounds = camera->getViewRect(null());
HXLINE( 212)		Float X = ((sprite->x - spriteBounds->x) - camera->scroll->x);
HXDLIN( 212)		Float Y = ((sprite->y - spriteBounds->y) - camera->scroll->y);
HXDLIN( 212)		 ::flixel::math::FlxPoint point = ::flixel::math::FlxPoint_obj::_pool->get()->set(X,Y);
HXDLIN( 212)		point->_inPool = false;
HXDLIN( 212)		 ::flixel::math::FlxPoint offset = point;
HXLINE( 217)		bool _hx_tmp;
HXDLIN( 217)		int dir = 1;
HXDLIN( 217)		if (((edges & dir) == dir)) {
HXLINE( 217)			_hx_tmp = (spriteBounds->x < viewBounds->x);
            		}
            		else {
HXLINE( 217)			_hx_tmp = false;
            		}
HXDLIN( 217)		if (_hx_tmp) {
HXLINE( 218)			sprite->set_x(((camera->scroll->x + viewBounds->x) + offset->x));
            		}
            		else {
HXLINE( 219)			bool _hx_tmp;
HXDLIN( 219)			int dir = 16;
HXDLIN( 219)			if (((edges & dir) == dir)) {
HXLINE( 219)				_hx_tmp = ((spriteBounds->x + spriteBounds->width) > (viewBounds->x + viewBounds->width));
            			}
            			else {
HXLINE( 219)				_hx_tmp = false;
            			}
HXDLIN( 219)			if (_hx_tmp) {
HXLINE( 220)				sprite->set_x((((camera->scroll->x + (viewBounds->x + viewBounds->width)) + offset->x) - spriteBounds->width));
            			}
            		}
HXLINE( 222)		bool _hx_tmp1;
HXDLIN( 222)		int dir1 = 256;
HXDLIN( 222)		if (((edges & dir1) == dir1)) {
HXLINE( 222)			_hx_tmp1 = (spriteBounds->y < viewBounds->y);
            		}
            		else {
HXLINE( 222)			_hx_tmp1 = false;
            		}
HXDLIN( 222)		if (_hx_tmp1) {
HXLINE( 223)			sprite->set_y(((camera->scroll->y + viewBounds->y) + offset->y));
            		}
            		else {
HXLINE( 224)			bool _hx_tmp;
HXDLIN( 224)			int dir = 4096;
HXDLIN( 224)			if (((edges & dir) == dir)) {
HXLINE( 224)				_hx_tmp = ((spriteBounds->y + spriteBounds->height) > (viewBounds->y + viewBounds->height));
            			}
            			else {
HXLINE( 224)				_hx_tmp = false;
            			}
HXDLIN( 224)			if (_hx_tmp) {
HXLINE( 225)				sprite->set_y((((camera->scroll->y + (viewBounds->y + viewBounds->height)) + offset->y) - spriteBounds->height));
            			}
            		}
HXLINE( 227)		if (!(spriteBounds->_inPool)) {
HXLINE( 227)			spriteBounds->_inPool = true;
HXDLIN( 227)			spriteBounds->_weak = false;
HXDLIN( 227)			::flixel::math::FlxRect_obj::_pool->putUnsafe(spriteBounds);
            		}
HXLINE( 228)		if (!(viewBounds->_inPool)) {
HXLINE( 228)			viewBounds->_inPool = true;
HXDLIN( 228)			viewBounds->_weak = false;
HXDLIN( 228)			::flixel::math::FlxRect_obj::_pool->putUnsafe(viewBounds);
            		}
HXLINE( 229)		offset->put();
HXLINE( 231)		return sprite;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FlxSpriteUtil_obj,cameraBound,return )

void FlxSpriteUtil_obj::space(::Array< ::Dynamic> objects,Float startX,Float startY, ::Dynamic horizontalSpacing, ::Dynamic verticalSpacing,::hx::Null< bool >  __o_spaceFromBounds, ::Dynamic position){
            		bool spaceFromBounds = __o_spaceFromBounds.Default(false);
            	HX_STACKFRAME(&_hx_pos_aff86ac70b6ed09e_247_space)
HXLINE( 248)		Float prevWidth = ( (Float)(0) );
HXLINE( 249)		Float runningX = ( (Float)(0) );
HXLINE( 251)		if (::hx::IsNotNull( horizontalSpacing )) {
HXLINE( 253)			if (spaceFromBounds) {
HXLINE( 255)				prevWidth = objects->__get(0).StaticCast<  ::flixel::FlxObject >()->get_width();
            			}
HXLINE( 257)			runningX = startX;
            		}
            		else {
HXLINE( 261)			runningX = objects->__get(0).StaticCast<  ::flixel::FlxObject >()->x;
            		}
HXLINE( 264)		Float prevHeight = ( (Float)(0) );
HXLINE( 265)		Float runningY = ( (Float)(0) );
HXLINE( 267)		if (::hx::IsNotNull( verticalSpacing )) {
HXLINE( 269)			if (spaceFromBounds) {
HXLINE( 271)				prevHeight = objects->__get(0).StaticCast<  ::flixel::FlxObject >()->get_height();
            			}
HXLINE( 273)			runningY = startY;
            		}
            		else {
HXLINE( 277)			runningY = objects->__get(0).StaticCast<  ::flixel::FlxObject >()->y;
            		}
HXLINE( 280)		if (::hx::IsNotNull( position )) {
HXLINE( 282)			position(objects->__get(0).StaticCast<  ::flixel::FlxObject >(),runningX,runningY);
            		}
            		else {
HXLINE( 286)			objects->__get(0).StaticCast<  ::flixel::FlxObject >()->set_x(runningX);
HXLINE( 287)			objects->__get(0).StaticCast<  ::flixel::FlxObject >()->set_y(runningY);
            		}
HXLINE( 290)		Float curX = ( (Float)(0) );
HXLINE( 291)		Float curY = ( (Float)(0) );
HXLINE( 293)		{
HXLINE( 293)			int _g = 1;
HXDLIN( 293)			int _g1 = objects->length;
HXDLIN( 293)			while((_g < _g1)){
HXLINE( 293)				_g = (_g + 1);
HXDLIN( 293)				int i = (_g - 1);
HXLINE( 295)				 ::flixel::FlxObject object = objects->__get(i).StaticCast<  ::flixel::FlxObject >();
HXLINE( 297)				if (::hx::IsNotNull( horizontalSpacing )) {
HXLINE( 299)					curX = ((runningX + prevWidth) + horizontalSpacing);
HXLINE( 300)					runningX = curX;
            				}
            				else {
HXLINE( 304)					curX = object->x;
            				}
HXLINE( 307)				if (::hx::IsNotNull( verticalSpacing )) {
HXLINE( 309)					curY = ((runningY + prevHeight) + verticalSpacing);
HXLINE( 310)					runningY = curY;
            				}
            				else {
HXLINE( 314)					curY = object->y;
            				}
HXLINE( 317)				if (::hx::IsNotNull( position )) {
HXLINE( 319)					position(object,curX,curY);
            				}
            				else {
HXLINE( 323)					object->set_x(curX);
HXLINE( 324)					object->set_y(curY);
            				}
HXLINE( 327)				if (spaceFromBounds) {
HXLINE( 329)					prevWidth = object->get_width();
HXLINE( 330)					prevHeight = object->get_height();
            				}
            			}
            		}
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC7(FlxSpriteUtil_obj,space,(void))

 ::flixel::FlxSprite FlxSpriteUtil_obj::drawLine( ::flixel::FlxSprite sprite,Float StartX,Float StartY,Float EndX,Float EndY, ::Dynamic lineStyle, ::Dynamic drawStyle){
            	HX_STACKFRAME(&_hx_pos_aff86ac70b6ed09e_349_drawLine)
HXLINE( 350)		 ::Dynamic lineStyle1 = lineStyle;
HXDLIN( 350)		if (::hx::IsNull( lineStyle1 )) {
HXLINE( 350)			lineStyle1 =  ::Dynamic(::hx::Anon_obj::Create(2)
            				->setFixed(0,HX_("color",63,71,5c,4a),-1)
            				->setFixed(1,HX_("thickness",74,f1,66,5a),1));
            		}
HXDLIN( 350)		if (::hx::IsNull( lineStyle1->__Field(HX_("thickness",74,f1,66,5a),::hx::paccDynamic) )) {
HXLINE( 350)			lineStyle1->__SetField(HX_("thickness",74,f1,66,5a),1,::hx::paccDynamic);
            		}
HXDLIN( 350)		if (::hx::IsNull( lineStyle1->__Field(HX_("color",63,71,5c,4a),::hx::paccDynamic) )) {
HXLINE( 350)			lineStyle1->__SetField(HX_("color",63,71,5c,4a),-1,::hx::paccDynamic);
            		}
HXDLIN( 350)		lineStyle = lineStyle1;
HXLINE( 351)		{
HXLINE( 351)			::flixel::util::FlxSpriteUtil_obj::flashGfx->clear();
HXDLIN( 351)			if (::hx::IsNotNull( lineStyle )) {
HXLINE( 351)				 ::Dynamic color;
HXDLIN( 351)				if (::hx::IsNull( lineStyle->__Field(HX_("color",63,71,5c,4a),::hx::paccDynamic) )) {
HXLINE( 351)					color = -16777216;
            				}
            				else {
HXLINE( 351)					color = lineStyle->__Field(HX_("color",63,71,5c,4a),::hx::paccDynamic);
            				}
HXDLIN( 351)				if (::hx::IsNull( lineStyle->__Field(HX_("thickness",74,f1,66,5a),::hx::paccDynamic) )) {
HXLINE( 351)					lineStyle->__SetField(HX_("thickness",74,f1,66,5a),1,::hx::paccDynamic);
            				}
HXDLIN( 351)				if (::hx::IsNull( lineStyle->__Field(HX_("pixelHinting",d5,9b,fb,6c),::hx::paccDynamic) )) {
HXLINE( 351)					lineStyle->__SetField(HX_("pixelHinting",d5,9b,fb,6c),false,::hx::paccDynamic);
            				}
HXDLIN( 351)				if (::hx::IsNull( lineStyle->__Field(HX_("miterLimit",f6,5c,6a,54),::hx::paccDynamic) )) {
HXLINE( 351)					lineStyle->__SetField(HX_("miterLimit",f6,5c,6a,54),3,::hx::paccDynamic);
            				}
HXDLIN( 351)				::flixel::util::FlxSpriteUtil_obj::flashGfx->lineStyle(lineStyle->__Field(HX_("thickness",74,f1,66,5a),::hx::paccDynamic),(( (int)(color) ) & 16777215),(( (Float)(((( (int)(color) ) >> 24) & 255)) ) / ( (Float)(255) )),lineStyle->__Field(HX_("pixelHinting",d5,9b,fb,6c),::hx::paccDynamic),lineStyle->__Field(HX_("scaleMode",0d,db,d3,2b),::hx::paccDynamic),lineStyle->__Field(HX_("capsStyle",50,61,32,83),::hx::paccDynamic),lineStyle->__Field(HX_("jointStyle",87,ef,1c,e2),::hx::paccDynamic),lineStyle->__Field(HX_("miterLimit",f6,5c,6a,54),::hx::paccDynamic));
            			}
HXDLIN( 351)			if ((0 != 0)) {
HXLINE( 351)				::flixel::util::FlxSpriteUtil_obj::flashGfx->beginFill((0 & 16777215),(( (Float)(((0 >> 24) & 255)) ) / ( (Float)(255) )));
            			}
            		}
HXLINE( 352)		::flixel::util::FlxSpriteUtil_obj::flashGfx->moveTo(StartX,StartY);
HXLINE( 353)		::flixel::util::FlxSpriteUtil_obj::flashGfx->lineTo(EndX,EndY);
HXLINE( 354)		{
HXLINE( 354)			::flixel::util::FlxSpriteUtil_obj::flashGfx->endFill();
HXDLIN( 354)			::flixel::util::FlxSpriteUtil_obj::updateSpriteGraphic(sprite,drawStyle);
            		}
HXLINE( 355)		return sprite;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC7(FlxSpriteUtil_obj,drawLine,return )

 ::flixel::FlxSprite FlxSpriteUtil_obj::drawCurve( ::flixel::FlxSprite sprite,Float StartX,Float StartY,Float EndX,Float EndY,Float ControlX,Float ControlY,::hx::Null< int >  __o_FillColor, ::Dynamic lineStyle, ::Dynamic drawStyle){
            		int FillColor = __o_FillColor.Default(0);
            	HX_STACKFRAME(&_hx_pos_aff86ac70b6ed09e_376_drawCurve)
HXLINE( 377)		 ::Dynamic lineStyle1 = lineStyle;
HXDLIN( 377)		if (::hx::IsNull( lineStyle1 )) {
HXLINE( 377)			lineStyle1 =  ::Dynamic(::hx::Anon_obj::Create(2)
            				->setFixed(0,HX_("color",63,71,5c,4a),-1)
            				->setFixed(1,HX_("thickness",74,f1,66,5a),1));
            		}
HXDLIN( 377)		if (::hx::IsNull( lineStyle1->__Field(HX_("thickness",74,f1,66,5a),::hx::paccDynamic) )) {
HXLINE( 377)			lineStyle1->__SetField(HX_("thickness",74,f1,66,5a),1,::hx::paccDynamic);
            		}
HXDLIN( 377)		if (::hx::IsNull( lineStyle1->__Field(HX_("color",63,71,5c,4a),::hx::paccDynamic) )) {
HXLINE( 377)			lineStyle1->__SetField(HX_("color",63,71,5c,4a),-1,::hx::paccDynamic);
            		}
HXDLIN( 377)		lineStyle = lineStyle1;
HXLINE( 378)		{
HXLINE( 378)			::flixel::util::FlxSpriteUtil_obj::flashGfx->clear();
HXDLIN( 378)			if (::hx::IsNotNull( lineStyle )) {
HXLINE( 378)				 ::Dynamic color;
HXDLIN( 378)				if (::hx::IsNull( lineStyle->__Field(HX_("color",63,71,5c,4a),::hx::paccDynamic) )) {
HXLINE( 378)					color = -16777216;
            				}
            				else {
HXLINE( 378)					color = lineStyle->__Field(HX_("color",63,71,5c,4a),::hx::paccDynamic);
            				}
HXDLIN( 378)				if (::hx::IsNull( lineStyle->__Field(HX_("thickness",74,f1,66,5a),::hx::paccDynamic) )) {
HXLINE( 378)					lineStyle->__SetField(HX_("thickness",74,f1,66,5a),1,::hx::paccDynamic);
            				}
HXDLIN( 378)				if (::hx::IsNull( lineStyle->__Field(HX_("pixelHinting",d5,9b,fb,6c),::hx::paccDynamic) )) {
HXLINE( 378)					lineStyle->__SetField(HX_("pixelHinting",d5,9b,fb,6c),false,::hx::paccDynamic);
            				}
HXDLIN( 378)				if (::hx::IsNull( lineStyle->__Field(HX_("miterLimit",f6,5c,6a,54),::hx::paccDynamic) )) {
HXLINE( 378)					lineStyle->__SetField(HX_("miterLimit",f6,5c,6a,54),3,::hx::paccDynamic);
            				}
HXDLIN( 378)				::flixel::util::FlxSpriteUtil_obj::flashGfx->lineStyle(lineStyle->__Field(HX_("thickness",74,f1,66,5a),::hx::paccDynamic),(( (int)(color) ) & 16777215),(( (Float)(((( (int)(color) ) >> 24) & 255)) ) / ( (Float)(255) )),lineStyle->__Field(HX_("pixelHinting",d5,9b,fb,6c),::hx::paccDynamic),lineStyle->__Field(HX_("scaleMode",0d,db,d3,2b),::hx::paccDynamic),lineStyle->__Field(HX_("capsStyle",50,61,32,83),::hx::paccDynamic),lineStyle->__Field(HX_("jointStyle",87,ef,1c,e2),::hx::paccDynamic),lineStyle->__Field(HX_("miterLimit",f6,5c,6a,54),::hx::paccDynamic));
            			}
HXDLIN( 378)			if ((FillColor != 0)) {
HXLINE( 378)				::flixel::util::FlxSpriteUtil_obj::flashGfx->beginFill((FillColor & 16777215),(( (Float)(((FillColor >> 24) & 255)) ) / ( (Float)(255) )));
            			}
            		}
HXLINE( 379)		::flixel::util::FlxSpriteUtil_obj::flashGfx->moveTo(StartX,StartY);
HXLINE( 380)		::flixel::util::FlxSpriteUtil_obj::flashGfx->curveTo(EndX,EndY,ControlX,ControlY);
HXLINE( 381)		{
HXLINE( 381)			::flixel::util::FlxSpriteUtil_obj::flashGfx->endFill();
HXDLIN( 381)			::flixel::util::FlxSpriteUtil_obj::updateSpriteGraphic(sprite,drawStyle);
            		}
HXLINE( 382)		return sprite;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC10(FlxSpriteUtil_obj,drawCurve,return )

 ::flixel::FlxSprite FlxSpriteUtil_obj::drawRect( ::flixel::FlxSprite sprite,Float X,Float Y,Float Width,Float Height,::hx::Null< int >  __o_FillColor, ::Dynamic lineStyle, ::Dynamic drawStyle){
            		int FillColor = __o_FillColor.Default(-1);
            	HX_STACKFRAME(&_hx_pos_aff86ac70b6ed09e_400_drawRect)
HXLINE( 401)		{
HXLINE( 401)			::flixel::util::FlxSpriteUtil_obj::flashGfx->clear();
HXDLIN( 401)			if (::hx::IsNotNull( lineStyle )) {
HXLINE( 401)				 ::Dynamic color;
HXDLIN( 401)				if (::hx::IsNull( lineStyle->__Field(HX_("color",63,71,5c,4a),::hx::paccDynamic) )) {
HXLINE( 401)					color = -16777216;
            				}
            				else {
HXLINE( 401)					color = lineStyle->__Field(HX_("color",63,71,5c,4a),::hx::paccDynamic);
            				}
HXDLIN( 401)				if (::hx::IsNull( lineStyle->__Field(HX_("thickness",74,f1,66,5a),::hx::paccDynamic) )) {
HXLINE( 401)					lineStyle->__SetField(HX_("thickness",74,f1,66,5a),1,::hx::paccDynamic);
            				}
HXDLIN( 401)				if (::hx::IsNull( lineStyle->__Field(HX_("pixelHinting",d5,9b,fb,6c),::hx::paccDynamic) )) {
HXLINE( 401)					lineStyle->__SetField(HX_("pixelHinting",d5,9b,fb,6c),false,::hx::paccDynamic);
            				}
HXDLIN( 401)				if (::hx::IsNull( lineStyle->__Field(HX_("miterLimit",f6,5c,6a,54),::hx::paccDynamic) )) {
HXLINE( 401)					lineStyle->__SetField(HX_("miterLimit",f6,5c,6a,54),3,::hx::paccDynamic);
            				}
HXDLIN( 401)				::flixel::util::FlxSpriteUtil_obj::flashGfx->lineStyle(lineStyle->__Field(HX_("thickness",74,f1,66,5a),::hx::paccDynamic),(( (int)(color) ) & 16777215),(( (Float)(((( (int)(color) ) >> 24) & 255)) ) / ( (Float)(255) )),lineStyle->__Field(HX_("pixelHinting",d5,9b,fb,6c),::hx::paccDynamic),lineStyle->__Field(HX_("scaleMode",0d,db,d3,2b),::hx::paccDynamic),lineStyle->__Field(HX_("capsStyle",50,61,32,83),::hx::paccDynamic),lineStyle->__Field(HX_("jointStyle",87,ef,1c,e2),::hx::paccDynamic),lineStyle->__Field(HX_("miterLimit",f6,5c,6a,54),::hx::paccDynamic));
            			}
HXDLIN( 401)			if ((FillColor != 0)) {
HXLINE( 401)				::flixel::util::FlxSpriteUtil_obj::flashGfx->beginFill((FillColor & 16777215),(( (Float)(((FillColor >> 24) & 255)) ) / ( (Float)(255) )));
            			}
            		}
HXLINE( 402)		::flixel::util::FlxSpriteUtil_obj::flashGfx->drawRect(X,Y,Width,Height);
HXLINE( 403)		{
HXLINE( 403)			::flixel::util::FlxSpriteUtil_obj::flashGfx->endFill();
HXDLIN( 403)			::flixel::util::FlxSpriteUtil_obj::updateSpriteGraphic(sprite,drawStyle);
            		}
HXLINE( 404)		return sprite;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC8(FlxSpriteUtil_obj,drawRect,return )

 ::flixel::FlxSprite FlxSpriteUtil_obj::drawRoundRect( ::flixel::FlxSprite sprite,Float X,Float Y,Float Width,Float Height,Float EllipseWidth,Float EllipseHeight,::hx::Null< int >  __o_FillColor, ::Dynamic lineStyle, ::Dynamic drawStyle){
            		int FillColor = __o_FillColor.Default(-1);
            	HX_STACKFRAME(&_hx_pos_aff86ac70b6ed09e_424_drawRoundRect)
HXLINE( 425)		{
HXLINE( 425)			::flixel::util::FlxSpriteUtil_obj::flashGfx->clear();
HXDLIN( 425)			if (::hx::IsNotNull( lineStyle )) {
HXLINE( 425)				 ::Dynamic color;
HXDLIN( 425)				if (::hx::IsNull( lineStyle->__Field(HX_("color",63,71,5c,4a),::hx::paccDynamic) )) {
HXLINE( 425)					color = -16777216;
            				}
            				else {
HXLINE( 425)					color = lineStyle->__Field(HX_("color",63,71,5c,4a),::hx::paccDynamic);
            				}
HXDLIN( 425)				if (::hx::IsNull( lineStyle->__Field(HX_("thickness",74,f1,66,5a),::hx::paccDynamic) )) {
HXLINE( 425)					lineStyle->__SetField(HX_("thickness",74,f1,66,5a),1,::hx::paccDynamic);
            				}
HXDLIN( 425)				if (::hx::IsNull( lineStyle->__Field(HX_("pixelHinting",d5,9b,fb,6c),::hx::paccDynamic) )) {
HXLINE( 425)					lineStyle->__SetField(HX_("pixelHinting",d5,9b,fb,6c),false,::hx::paccDynamic);
            				}
HXDLIN( 425)				if (::hx::IsNull( lineStyle->__Field(HX_("miterLimit",f6,5c,6a,54),::hx::paccDynamic) )) {
HXLINE( 425)					lineStyle->__SetField(HX_("miterLimit",f6,5c,6a,54),3,::hx::paccDynamic);
            				}
HXDLIN( 425)				::flixel::util::FlxSpriteUtil_obj::flashGfx->lineStyle(lineStyle->__Field(HX_("thickness",74,f1,66,5a),::hx::paccDynamic),(( (int)(color) ) & 16777215),(( (Float)(((( (int)(color) ) >> 24) & 255)) ) / ( (Float)(255) )),lineStyle->__Field(HX_("pixelHinting",d5,9b,fb,6c),::hx::paccDynamic),lineStyle->__Field(HX_("scaleMode",0d,db,d3,2b),::hx::paccDynamic),lineStyle->__Field(HX_("capsStyle",50,61,32,83),::hx::paccDynamic),lineStyle->__Field(HX_("jointStyle",87,ef,1c,e2),::hx::paccDynamic),lineStyle->__Field(HX_("miterLimit",f6,5c,6a,54),::hx::paccDynamic));
            			}
HXDLIN( 425)			if ((FillColor != 0)) {
HXLINE( 425)				::flixel::util::FlxSpriteUtil_obj::flashGfx->beginFill((FillColor & 16777215),(( (Float)(((FillColor >> 24) & 255)) ) / ( (Float)(255) )));
            			}
            		}
HXLINE( 426)		::flixel::util::FlxSpriteUtil_obj::flashGfx->drawRoundRect(X,Y,Width,Height,EllipseWidth,EllipseHeight);
HXLINE( 427)		{
HXLINE( 427)			::flixel::util::FlxSpriteUtil_obj::flashGfx->endFill();
HXDLIN( 427)			::flixel::util::FlxSpriteUtil_obj::updateSpriteGraphic(sprite,drawStyle);
            		}
HXLINE( 428)		return sprite;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC10(FlxSpriteUtil_obj,drawRoundRect,return )

 ::flixel::FlxSprite FlxSpriteUtil_obj::drawRoundRectComplex( ::flixel::FlxSprite sprite,Float X,Float Y,Float Width,Float Height,Float TopLeftRadius,Float TopRightRadius,Float BottomLeftRadius,Float BottomRightRadius,::hx::Null< int >  __o_FillColor, ::Dynamic lineStyle, ::Dynamic drawStyle){
            		int FillColor = __o_FillColor.Default(-1);
            	HX_STACKFRAME(&_hx_pos_aff86ac70b6ed09e_452_drawRoundRectComplex)
HXLINE( 453)		{
HXLINE( 453)			::flixel::util::FlxSpriteUtil_obj::flashGfx->clear();
HXDLIN( 453)			if (::hx::IsNotNull( lineStyle )) {
HXLINE( 453)				 ::Dynamic color;
HXDLIN( 453)				if (::hx::IsNull( lineStyle->__Field(HX_("color",63,71,5c,4a),::hx::paccDynamic) )) {
HXLINE( 453)					color = -16777216;
            				}
            				else {
HXLINE( 453)					color = lineStyle->__Field(HX_("color",63,71,5c,4a),::hx::paccDynamic);
            				}
HXDLIN( 453)				if (::hx::IsNull( lineStyle->__Field(HX_("thickness",74,f1,66,5a),::hx::paccDynamic) )) {
HXLINE( 453)					lineStyle->__SetField(HX_("thickness",74,f1,66,5a),1,::hx::paccDynamic);
            				}
HXDLIN( 453)				if (::hx::IsNull( lineStyle->__Field(HX_("pixelHinting",d5,9b,fb,6c),::hx::paccDynamic) )) {
HXLINE( 453)					lineStyle->__SetField(HX_("pixelHinting",d5,9b,fb,6c),false,::hx::paccDynamic);
            				}
HXDLIN( 453)				if (::hx::IsNull( lineStyle->__Field(HX_("miterLimit",f6,5c,6a,54),::hx::paccDynamic) )) {
HXLINE( 453)					lineStyle->__SetField(HX_("miterLimit",f6,5c,6a,54),3,::hx::paccDynamic);
            				}
HXDLIN( 453)				::flixel::util::FlxSpriteUtil_obj::flashGfx->lineStyle(lineStyle->__Field(HX_("thickness",74,f1,66,5a),::hx::paccDynamic),(( (int)(color) ) & 16777215),(( (Float)(((( (int)(color) ) >> 24) & 255)) ) / ( (Float)(255) )),lineStyle->__Field(HX_("pixelHinting",d5,9b,fb,6c),::hx::paccDynamic),lineStyle->__Field(HX_("scaleMode",0d,db,d3,2b),::hx::paccDynamic),lineStyle->__Field(HX_("capsStyle",50,61,32,83),::hx::paccDynamic),lineStyle->__Field(HX_("jointStyle",87,ef,1c,e2),::hx::paccDynamic),lineStyle->__Field(HX_("miterLimit",f6,5c,6a,54),::hx::paccDynamic));
            			}
HXDLIN( 453)			if ((FillColor != 0)) {
HXLINE( 453)				::flixel::util::FlxSpriteUtil_obj::flashGfx->beginFill((FillColor & 16777215),(( (Float)(((FillColor >> 24) & 255)) ) / ( (Float)(255) )));
            			}
            		}
HXLINE( 454)		::flixel::util::FlxSpriteUtil_obj::flashGfx->drawRoundRectComplex(X,Y,Width,Height,TopLeftRadius,TopRightRadius,BottomLeftRadius,BottomRightRadius);
HXLINE( 455)		{
HXLINE( 455)			::flixel::util::FlxSpriteUtil_obj::flashGfx->endFill();
HXDLIN( 455)			::flixel::util::FlxSpriteUtil_obj::updateSpriteGraphic(sprite,drawStyle);
            		}
HXLINE( 456)		return sprite;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC12(FlxSpriteUtil_obj,drawRoundRectComplex,return )

 ::flixel::FlxSprite FlxSpriteUtil_obj::drawCircle( ::flixel::FlxSprite sprite,::hx::Null< Float >  __o_X,::hx::Null< Float >  __o_Y,::hx::Null< Float >  __o_Radius,::hx::Null< int >  __o_FillColor, ::Dynamic lineStyle, ::Dynamic drawStyle){
            		Float X = __o_X.Default(-1);
            		Float Y = __o_Y.Default(-1);
            		Float Radius = __o_Radius.Default(-1);
            		int FillColor = __o_FillColor.Default(-1);
            	HX_STACKFRAME(&_hx_pos_aff86ac70b6ed09e_474_drawCircle)
HXLINE( 475)		bool _hx_tmp;
HXDLIN( 475)		if ((X != -1)) {
HXLINE( 475)			_hx_tmp = (Y == -1);
            		}
            		else {
HXLINE( 475)			_hx_tmp = true;
            		}
HXDLIN( 475)		if (_hx_tmp) {
HXLINE( 477)			 ::flixel::math::FlxPoint midPoint = sprite->getGraphicMidpoint(null());
HXLINE( 479)			if ((X == -1)) {
HXLINE( 480)				X = (midPoint->x - sprite->x);
            			}
HXLINE( 481)			if ((Y == -1)) {
HXLINE( 482)				Y = (midPoint->y - sprite->y);
            			}
HXLINE( 484)			midPoint->put();
            		}
HXLINE( 487)		if ((Radius < 1)) {
HXLINE( 489)			Float minVal = ::Math_obj::min(( (Float)(sprite->frameWidth) ),( (Float)(sprite->frameHeight) ));
HXLINE( 490)			Radius = (minVal / ( (Float)(2) ));
            		}
HXLINE( 493)		{
HXLINE( 493)			::flixel::util::FlxSpriteUtil_obj::flashGfx->clear();
HXDLIN( 493)			if (::hx::IsNotNull( lineStyle )) {
HXLINE( 493)				 ::Dynamic color;
HXDLIN( 493)				if (::hx::IsNull( lineStyle->__Field(HX_("color",63,71,5c,4a),::hx::paccDynamic) )) {
HXLINE( 493)					color = -16777216;
            				}
            				else {
HXLINE( 493)					color = lineStyle->__Field(HX_("color",63,71,5c,4a),::hx::paccDynamic);
            				}
HXDLIN( 493)				if (::hx::IsNull( lineStyle->__Field(HX_("thickness",74,f1,66,5a),::hx::paccDynamic) )) {
HXLINE( 493)					lineStyle->__SetField(HX_("thickness",74,f1,66,5a),1,::hx::paccDynamic);
            				}
HXDLIN( 493)				if (::hx::IsNull( lineStyle->__Field(HX_("pixelHinting",d5,9b,fb,6c),::hx::paccDynamic) )) {
HXLINE( 493)					lineStyle->__SetField(HX_("pixelHinting",d5,9b,fb,6c),false,::hx::paccDynamic);
            				}
HXDLIN( 493)				if (::hx::IsNull( lineStyle->__Field(HX_("miterLimit",f6,5c,6a,54),::hx::paccDynamic) )) {
HXLINE( 493)					lineStyle->__SetField(HX_("miterLimit",f6,5c,6a,54),3,::hx::paccDynamic);
            				}
HXDLIN( 493)				::flixel::util::FlxSpriteUtil_obj::flashGfx->lineStyle(lineStyle->__Field(HX_("thickness",74,f1,66,5a),::hx::paccDynamic),(( (int)(color) ) & 16777215),(( (Float)(((( (int)(color) ) >> 24) & 255)) ) / ( (Float)(255) )),lineStyle->__Field(HX_("pixelHinting",d5,9b,fb,6c),::hx::paccDynamic),lineStyle->__Field(HX_("scaleMode",0d,db,d3,2b),::hx::paccDynamic),lineStyle->__Field(HX_("capsStyle",50,61,32,83),::hx::paccDynamic),lineStyle->__Field(HX_("jointStyle",87,ef,1c,e2),::hx::paccDynamic),lineStyle->__Field(HX_("miterLimit",f6,5c,6a,54),::hx::paccDynamic));
            			}
HXDLIN( 493)			if ((FillColor != 0)) {
HXLINE( 493)				::flixel::util::FlxSpriteUtil_obj::flashGfx->beginFill((FillColor & 16777215),(( (Float)(((FillColor >> 24) & 255)) ) / ( (Float)(255) )));
            			}
            		}
HXLINE( 494)		::flixel::util::FlxSpriteUtil_obj::flashGfx->drawCircle(X,Y,Radius);
HXLINE( 495)		{
HXLINE( 495)			::flixel::util::FlxSpriteUtil_obj::flashGfx->endFill();
HXDLIN( 495)			::flixel::util::FlxSpriteUtil_obj::updateSpriteGraphic(sprite,drawStyle);
            		}
HXLINE( 496)		return sprite;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC7(FlxSpriteUtil_obj,drawCircle,return )

 ::flixel::FlxSprite FlxSpriteUtil_obj::drawEllipse( ::flixel::FlxSprite sprite,Float X,Float Y,Float Width,Float Height,::hx::Null< int >  __o_FillColor, ::Dynamic lineStyle, ::Dynamic drawStyle){
            		int FillColor = __o_FillColor.Default(-1);
            	HX_STACKFRAME(&_hx_pos_aff86ac70b6ed09e_514_drawEllipse)
HXLINE( 515)		{
HXLINE( 515)			::flixel::util::FlxSpriteUtil_obj::flashGfx->clear();
HXDLIN( 515)			if (::hx::IsNotNull( lineStyle )) {
HXLINE( 515)				 ::Dynamic color;
HXDLIN( 515)				if (::hx::IsNull( lineStyle->__Field(HX_("color",63,71,5c,4a),::hx::paccDynamic) )) {
HXLINE( 515)					color = -16777216;
            				}
            				else {
HXLINE( 515)					color = lineStyle->__Field(HX_("color",63,71,5c,4a),::hx::paccDynamic);
            				}
HXDLIN( 515)				if (::hx::IsNull( lineStyle->__Field(HX_("thickness",74,f1,66,5a),::hx::paccDynamic) )) {
HXLINE( 515)					lineStyle->__SetField(HX_("thickness",74,f1,66,5a),1,::hx::paccDynamic);
            				}
HXDLIN( 515)				if (::hx::IsNull( lineStyle->__Field(HX_("pixelHinting",d5,9b,fb,6c),::hx::paccDynamic) )) {
HXLINE( 515)					lineStyle->__SetField(HX_("pixelHinting",d5,9b,fb,6c),false,::hx::paccDynamic);
            				}
HXDLIN( 515)				if (::hx::IsNull( lineStyle->__Field(HX_("miterLimit",f6,5c,6a,54),::hx::paccDynamic) )) {
HXLINE( 515)					lineStyle->__SetField(HX_("miterLimit",f6,5c,6a,54),3,::hx::paccDynamic);
            				}
HXDLIN( 515)				::flixel::util::FlxSpriteUtil_obj::flashGfx->lineStyle(lineStyle->__Field(HX_("thickness",74,f1,66,5a),::hx::paccDynamic),(( (int)(color) ) & 16777215),(( (Float)(((( (int)(color) ) >> 24) & 255)) ) / ( (Float)(255) )),lineStyle->__Field(HX_("pixelHinting",d5,9b,fb,6c),::hx::paccDynamic),lineStyle->__Field(HX_("scaleMode",0d,db,d3,2b),::hx::paccDynamic),lineStyle->__Field(HX_("capsStyle",50,61,32,83),::hx::paccDynamic),lineStyle->__Field(HX_("jointStyle",87,ef,1c,e2),::hx::paccDynamic),lineStyle->__Field(HX_("miterLimit",f6,5c,6a,54),::hx::paccDynamic));
            			}
HXDLIN( 515)			if ((FillColor != 0)) {
HXLINE( 515)				::flixel::util::FlxSpriteUtil_obj::flashGfx->beginFill((FillColor & 16777215),(( (Float)(((FillColor >> 24) & 255)) ) / ( (Float)(255) )));
            			}
            		}
HXLINE( 516)		::flixel::util::FlxSpriteUtil_obj::flashGfx->drawEllipse(X,Y,Width,Height);
HXLINE( 517)		{
HXLINE( 517)			::flixel::util::FlxSpriteUtil_obj::flashGfx->endFill();
HXDLIN( 517)			::flixel::util::FlxSpriteUtil_obj::updateSpriteGraphic(sprite,drawStyle);
            		}
HXLINE( 518)		return sprite;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC8(FlxSpriteUtil_obj,drawEllipse,return )

 ::flixel::FlxSprite FlxSpriteUtil_obj::drawTriangle( ::flixel::FlxSprite sprite,Float X,Float Y,Float Height,::hx::Null< int >  __o_FillColor, ::Dynamic lineStyle, ::Dynamic drawStyle){
            		int FillColor = __o_FillColor.Default(-1);
            	HX_STACKFRAME(&_hx_pos_aff86ac70b6ed09e_535_drawTriangle)
HXLINE( 536)		{
HXLINE( 536)			::flixel::util::FlxSpriteUtil_obj::flashGfx->clear();
HXDLIN( 536)			if (::hx::IsNotNull( lineStyle )) {
HXLINE( 536)				 ::Dynamic color;
HXDLIN( 536)				if (::hx::IsNull( lineStyle->__Field(HX_("color",63,71,5c,4a),::hx::paccDynamic) )) {
HXLINE( 536)					color = -16777216;
            				}
            				else {
HXLINE( 536)					color = lineStyle->__Field(HX_("color",63,71,5c,4a),::hx::paccDynamic);
            				}
HXDLIN( 536)				if (::hx::IsNull( lineStyle->__Field(HX_("thickness",74,f1,66,5a),::hx::paccDynamic) )) {
HXLINE( 536)					lineStyle->__SetField(HX_("thickness",74,f1,66,5a),1,::hx::paccDynamic);
            				}
HXDLIN( 536)				if (::hx::IsNull( lineStyle->__Field(HX_("pixelHinting",d5,9b,fb,6c),::hx::paccDynamic) )) {
HXLINE( 536)					lineStyle->__SetField(HX_("pixelHinting",d5,9b,fb,6c),false,::hx::paccDynamic);
            				}
HXDLIN( 536)				if (::hx::IsNull( lineStyle->__Field(HX_("miterLimit",f6,5c,6a,54),::hx::paccDynamic) )) {
HXLINE( 536)					lineStyle->__SetField(HX_("miterLimit",f6,5c,6a,54),3,::hx::paccDynamic);
            				}
HXDLIN( 536)				::flixel::util::FlxSpriteUtil_obj::flashGfx->lineStyle(lineStyle->__Field(HX_("thickness",74,f1,66,5a),::hx::paccDynamic),(( (int)(color) ) & 16777215),(( (Float)(((( (int)(color) ) >> 24) & 255)) ) / ( (Float)(255) )),lineStyle->__Field(HX_("pixelHinting",d5,9b,fb,6c),::hx::paccDynamic),lineStyle->__Field(HX_("scaleMode",0d,db,d3,2b),::hx::paccDynamic),lineStyle->__Field(HX_("capsStyle",50,61,32,83),::hx::paccDynamic),lineStyle->__Field(HX_("jointStyle",87,ef,1c,e2),::hx::paccDynamic),lineStyle->__Field(HX_("miterLimit",f6,5c,6a,54),::hx::paccDynamic));
            			}
HXDLIN( 536)			if ((FillColor != 0)) {
HXLINE( 536)				::flixel::util::FlxSpriteUtil_obj::flashGfx->beginFill((FillColor & 16777215),(( (Float)(((FillColor >> 24) & 255)) ) / ( (Float)(255) )));
            			}
            		}
HXLINE( 537)		::flixel::util::FlxSpriteUtil_obj::flashGfx->moveTo((X + (Height / ( (Float)(2) ))),Y);
HXLINE( 538)		::flixel::util::FlxSpriteUtil_obj::flashGfx->lineTo((X + Height),(Height + Y));
HXLINE( 539)		::flixel::util::FlxSpriteUtil_obj::flashGfx->lineTo(X,(Height + Y));
HXLINE( 540)		::flixel::util::FlxSpriteUtil_obj::flashGfx->lineTo((X + (Height / ( (Float)(2) ))),Y);
HXLINE( 541)		{
HXLINE( 541)			::flixel::util::FlxSpriteUtil_obj::flashGfx->endFill();
HXDLIN( 541)			::flixel::util::FlxSpriteUtil_obj::updateSpriteGraphic(sprite,drawStyle);
            		}
HXLINE( 542)		return sprite;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC7(FlxSpriteUtil_obj,drawTriangle,return )

 ::flixel::FlxSprite FlxSpriteUtil_obj::drawPolygon( ::flixel::FlxSprite sprite,::Array< ::Dynamic> Vertices,::hx::Null< int >  __o_FillColor, ::Dynamic lineStyle, ::Dynamic drawStyle){
            		int FillColor = __o_FillColor.Default(-1);
            	HX_STACKFRAME(&_hx_pos_aff86ac70b6ed09e_557_drawPolygon)
HXLINE( 558)		{
HXLINE( 558)			::flixel::util::FlxSpriteUtil_obj::flashGfx->clear();
HXDLIN( 558)			if (::hx::IsNotNull( lineStyle )) {
HXLINE( 558)				 ::Dynamic color;
HXDLIN( 558)				if (::hx::IsNull( lineStyle->__Field(HX_("color",63,71,5c,4a),::hx::paccDynamic) )) {
HXLINE( 558)					color = -16777216;
            				}
            				else {
HXLINE( 558)					color = lineStyle->__Field(HX_("color",63,71,5c,4a),::hx::paccDynamic);
            				}
HXDLIN( 558)				if (::hx::IsNull( lineStyle->__Field(HX_("thickness",74,f1,66,5a),::hx::paccDynamic) )) {
HXLINE( 558)					lineStyle->__SetField(HX_("thickness",74,f1,66,5a),1,::hx::paccDynamic);
            				}
HXDLIN( 558)				if (::hx::IsNull( lineStyle->__Field(HX_("pixelHinting",d5,9b,fb,6c),::hx::paccDynamic) )) {
HXLINE( 558)					lineStyle->__SetField(HX_("pixelHinting",d5,9b,fb,6c),false,::hx::paccDynamic);
            				}
HXDLIN( 558)				if (::hx::IsNull( lineStyle->__Field(HX_("miterLimit",f6,5c,6a,54),::hx::paccDynamic) )) {
HXLINE( 558)					lineStyle->__SetField(HX_("miterLimit",f6,5c,6a,54),3,::hx::paccDynamic);
            				}
HXDLIN( 558)				::flixel::util::FlxSpriteUtil_obj::flashGfx->lineStyle(lineStyle->__Field(HX_("thickness",74,f1,66,5a),::hx::paccDynamic),(( (int)(color) ) & 16777215),(( (Float)(((( (int)(color) ) >> 24) & 255)) ) / ( (Float)(255) )),lineStyle->__Field(HX_("pixelHinting",d5,9b,fb,6c),::hx::paccDynamic),lineStyle->__Field(HX_("scaleMode",0d,db,d3,2b),::hx::paccDynamic),lineStyle->__Field(HX_("capsStyle",50,61,32,83),::hx::paccDynamic),lineStyle->__Field(HX_("jointStyle",87,ef,1c,e2),::hx::paccDynamic),lineStyle->__Field(HX_("miterLimit",f6,5c,6a,54),::hx::paccDynamic));
            			}
HXDLIN( 558)			if ((FillColor != 0)) {
HXLINE( 558)				::flixel::util::FlxSpriteUtil_obj::flashGfx->beginFill((FillColor & 16777215),(( (Float)(((FillColor >> 24) & 255)) ) / ( (Float)(255) )));
            			}
            		}
HXLINE( 559)		 ::flixel::math::FlxPoint p = Vertices->shift().StaticCast<  ::flixel::math::FlxPoint >();
HXLINE( 560)		::flixel::util::FlxSpriteUtil_obj::flashGfx->moveTo(p->x,p->y);
HXLINE( 561)		{
HXLINE( 561)			int _g = 0;
HXDLIN( 561)			while((_g < Vertices->length)){
HXLINE( 561)				 ::flixel::math::FlxPoint p = Vertices->__get(_g).StaticCast<  ::flixel::math::FlxPoint >();
HXDLIN( 561)				_g = (_g + 1);
HXLINE( 563)				::flixel::util::FlxSpriteUtil_obj::flashGfx->lineTo(p->x,p->y);
            			}
            		}
HXLINE( 565)		{
HXLINE( 565)			::flixel::util::FlxSpriteUtil_obj::flashGfx->endFill();
HXDLIN( 565)			::flixel::util::FlxSpriteUtil_obj::updateSpriteGraphic(sprite,drawStyle);
            		}
HXLINE( 566)		Vertices->unshift(p);
HXLINE( 567)		return sprite;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(FlxSpriteUtil_obj,drawPolygon,return )

void FlxSpriteUtil_obj::beginDraw(int FillColor, ::Dynamic lineStyle){
            	HX_STACKFRAME(&_hx_pos_aff86ac70b6ed09e_578_beginDraw)
HXLINE( 579)		::flixel::util::FlxSpriteUtil_obj::flashGfx->clear();
HXLINE( 580)		if (::hx::IsNotNull( lineStyle )) {
HXLINE( 580)			 ::Dynamic color;
HXDLIN( 580)			if (::hx::IsNull( lineStyle->__Field(HX_("color",63,71,5c,4a),::hx::paccDynamic) )) {
HXLINE( 580)				color = -16777216;
            			}
            			else {
HXLINE( 580)				color = lineStyle->__Field(HX_("color",63,71,5c,4a),::hx::paccDynamic);
            			}
HXDLIN( 580)			if (::hx::IsNull( lineStyle->__Field(HX_("thickness",74,f1,66,5a),::hx::paccDynamic) )) {
HXLINE( 580)				lineStyle->__SetField(HX_("thickness",74,f1,66,5a),1,::hx::paccDynamic);
            			}
HXDLIN( 580)			if (::hx::IsNull( lineStyle->__Field(HX_("pixelHinting",d5,9b,fb,6c),::hx::paccDynamic) )) {
HXLINE( 580)				lineStyle->__SetField(HX_("pixelHinting",d5,9b,fb,6c),false,::hx::paccDynamic);
            			}
HXDLIN( 580)			if (::hx::IsNull( lineStyle->__Field(HX_("miterLimit",f6,5c,6a,54),::hx::paccDynamic) )) {
HXLINE( 580)				lineStyle->__SetField(HX_("miterLimit",f6,5c,6a,54),3,::hx::paccDynamic);
            			}
HXDLIN( 580)			::flixel::util::FlxSpriteUtil_obj::flashGfx->lineStyle(lineStyle->__Field(HX_("thickness",74,f1,66,5a),::hx::paccDynamic),(( (int)(color) ) & 16777215),(( (Float)(((( (int)(color) ) >> 24) & 255)) ) / ( (Float)(255) )),lineStyle->__Field(HX_("pixelHinting",d5,9b,fb,6c),::hx::paccDynamic),lineStyle->__Field(HX_("scaleMode",0d,db,d3,2b),::hx::paccDynamic),lineStyle->__Field(HX_("capsStyle",50,61,32,83),::hx::paccDynamic),lineStyle->__Field(HX_("jointStyle",87,ef,1c,e2),::hx::paccDynamic),lineStyle->__Field(HX_("miterLimit",f6,5c,6a,54),::hx::paccDynamic));
            		}
HXLINE( 582)		if ((FillColor != 0)) {
HXLINE( 584)			::flixel::util::FlxSpriteUtil_obj::flashGfx->beginFill((FillColor & 16777215),(( (Float)(((FillColor >> 24) & 255)) ) / ( (Float)(255) )));
            		}
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FlxSpriteUtil_obj,beginDraw,(void))

 ::flixel::FlxSprite FlxSpriteUtil_obj::endDraw( ::flixel::FlxSprite sprite, ::Dynamic drawStyle){
            	HX_STACKFRAME(&_hx_pos_aff86ac70b6ed09e_596_endDraw)
HXLINE( 597)		::flixel::util::FlxSpriteUtil_obj::flashGfx->endFill();
HXLINE( 598)		::flixel::util::FlxSpriteUtil_obj::updateSpriteGraphic(sprite,drawStyle);
HXLINE( 599)		return sprite;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FlxSpriteUtil_obj,endDraw,return )

 ::flixel::FlxSprite FlxSpriteUtil_obj::updateSpriteGraphic( ::flixel::FlxSprite sprite, ::Dynamic drawStyle){
            	HX_STACKFRAME(&_hx_pos_aff86ac70b6ed09e_611_updateSpriteGraphic)
HXLINE( 612)		if (::hx::IsNull( drawStyle )) {
HXLINE( 614)			drawStyle =  ::Dynamic(::hx::Anon_obj::Create(1)
            				->setFixed(0,HX_("smoothing",74,d5,e1,95),false));
            		}
            		else {
HXLINE( 616)			if (::hx::IsNull( drawStyle->__Field(HX_("smoothing",74,d5,e1,95),::hx::paccDynamic) )) {
HXLINE( 618)				drawStyle->__SetField(HX_("smoothing",74,d5,e1,95),false,::hx::paccDynamic);
            			}
            		}
HXLINE( 621)		sprite->get_pixels()->draw(::flixel::util::FlxSpriteUtil_obj::flashGfxSprite,( ( ::openfl::geom::Matrix)(drawStyle->__Field(HX_("matrix",41,36,c8,bb),::hx::paccDynamic)) ),( ( ::openfl::geom::ColorTransform)(drawStyle->__Field(HX_("colorTransform",89,d7,3f,ad),::hx::paccDynamic)) ),drawStyle->__Field(HX_("blendMode",54,e4,37,0c),::hx::paccDynamic),( ( ::openfl::geom::Rectangle)(drawStyle->__Field(HX_("clipRect",14,90,6a,58),::hx::paccDynamic)) ),drawStyle->__Field(HX_("smoothing",74,d5,e1,95),::hx::paccDynamic));
HXLINE( 622)		sprite->dirty = true;
HXLINE( 623)		return sprite;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FlxSpriteUtil_obj,updateSpriteGraphic,return )

void FlxSpriteUtil_obj::setLineStyle( ::Dynamic lineStyle){
            	HX_STACKFRAME(&_hx_pos_aff86ac70b6ed09e_635_setLineStyle)
HXDLIN( 635)		if (::hx::IsNotNull( lineStyle )) {
HXLINE( 637)			 ::Dynamic color;
HXDLIN( 637)			if (::hx::IsNull( lineStyle->__Field(HX_("color",63,71,5c,4a),::hx::paccDynamic) )) {
HXLINE( 637)				color = -16777216;
            			}
            			else {
HXLINE( 637)				color = lineStyle->__Field(HX_("color",63,71,5c,4a),::hx::paccDynamic);
            			}
HXLINE( 639)			if (::hx::IsNull( lineStyle->__Field(HX_("thickness",74,f1,66,5a),::hx::paccDynamic) )) {
HXLINE( 640)				lineStyle->__SetField(HX_("thickness",74,f1,66,5a),1,::hx::paccDynamic);
            			}
HXLINE( 641)			if (::hx::IsNull( lineStyle->__Field(HX_("pixelHinting",d5,9b,fb,6c),::hx::paccDynamic) )) {
HXLINE( 642)				lineStyle->__SetField(HX_("pixelHinting",d5,9b,fb,6c),false,::hx::paccDynamic);
            			}
HXLINE( 643)			if (::hx::IsNull( lineStyle->__Field(HX_("miterLimit",f6,5c,6a,54),::hx::paccDynamic) )) {
HXLINE( 644)				lineStyle->__SetField(HX_("miterLimit",f6,5c,6a,54),3,::hx::paccDynamic);
            			}
HXLINE( 646)			::flixel::util::FlxSpriteUtil_obj::flashGfx->lineStyle(lineStyle->__Field(HX_("thickness",74,f1,66,5a),::hx::paccDynamic),(( (int)(color) ) & 16777215),(( (Float)(((( (int)(color) ) >> 24) & 255)) ) / ( (Float)(255) )),lineStyle->__Field(HX_("pixelHinting",d5,9b,fb,6c),::hx::paccDynamic),lineStyle->__Field(HX_("scaleMode",0d,db,d3,2b),::hx::paccDynamic),lineStyle->__Field(HX_("capsStyle",50,61,32,83),::hx::paccDynamic),lineStyle->__Field(HX_("jointStyle",87,ef,1c,e2),::hx::paccDynamic),lineStyle->__Field(HX_("miterLimit",f6,5c,6a,54),::hx::paccDynamic));
            		}
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxSpriteUtil_obj,setLineStyle,(void))

 ::Dynamic FlxSpriteUtil_obj::getDefaultLineStyle( ::Dynamic lineStyle){
            	HX_STACKFRAME(&_hx_pos_aff86ac70b6ed09e_657_getDefaultLineStyle)
HXLINE( 658)		if (::hx::IsNull( lineStyle )) {
HXLINE( 659)			lineStyle =  ::Dynamic(::hx::Anon_obj::Create(2)
            				->setFixed(0,HX_("color",63,71,5c,4a),-1)
            				->setFixed(1,HX_("thickness",74,f1,66,5a),1));
            		}
HXLINE( 660)		if (::hx::IsNull( lineStyle->__Field(HX_("thickness",74,f1,66,5a),::hx::paccDynamic) )) {
HXLINE( 661)			lineStyle->__SetField(HX_("thickness",74,f1,66,5a),1,::hx::paccDynamic);
            		}
HXLINE( 662)		if (::hx::IsNull( lineStyle->__Field(HX_("color",63,71,5c,4a),::hx::paccDynamic) )) {
HXLINE( 663)			lineStyle->__SetField(HX_("color",63,71,5c,4a),-1,::hx::paccDynamic);
            		}
HXLINE( 665)		return lineStyle;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxSpriteUtil_obj,getDefaultLineStyle,return )

 ::flixel::FlxSprite FlxSpriteUtil_obj::fill( ::flixel::FlxSprite sprite,int FillColor){
            	HX_STACKFRAME(&_hx_pos_aff86ac70b6ed09e_676_fill)
HXLINE( 677)		 ::openfl::display::BitmapData _hx_tmp = sprite->get_pixels();
HXDLIN( 677)		_hx_tmp->fillRect(sprite->get_pixels()->rect,FillColor);
HXLINE( 679)		 ::openfl::display::BitmapData _hx_tmp1 = sprite->get_pixels();
HXDLIN( 679)		if (::hx::IsInstanceNotEq( _hx_tmp1,sprite->framePixels )) {
HXLINE( 681)			sprite->dirty = true;
            		}
HXLINE( 684)		return sprite;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FlxSpriteUtil_obj,fill,return )

 ::flixel::effects::FlxFlicker FlxSpriteUtil_obj::flicker( ::flixel::FlxObject Object,::hx::Null< Float >  __o_Duration,::hx::Null< Float >  __o_Interval,::hx::Null< bool >  __o_EndVisibility,::hx::Null< bool >  __o_ForceRestart, ::Dynamic CompletionCallback, ::Dynamic ProgressCallback){
            		Float Duration = __o_Duration.Default(1);
            		Float Interval = __o_Interval.Default(((Float)0.04));
            		bool EndVisibility = __o_EndVisibility.Default(true);
            		bool ForceRestart = __o_ForceRestart.Default(true);
            	HX_STACKFRAME(&_hx_pos_aff86ac70b6ed09e_702_flicker)
HXDLIN( 702)		return ::flixel::effects::FlxFlicker_obj::flicker(Object,Duration,Interval,EndVisibility,ForceRestart,CompletionCallback,ProgressCallback);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC7(FlxSpriteUtil_obj,flicker,return )

bool FlxSpriteUtil_obj::isFlickering( ::flixel::FlxObject Object){
            	HX_STACKFRAME(&_hx_pos_aff86ac70b6ed09e_712_isFlickering)
HXDLIN( 712)		return ::flixel::effects::FlxFlicker_obj::isFlickering(Object);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxSpriteUtil_obj,isFlickering,return )

 ::flixel::FlxObject FlxSpriteUtil_obj::stopFlickering( ::flixel::FlxObject Object){
            	HX_STACKFRAME(&_hx_pos_aff86ac70b6ed09e_722_stopFlickering)
HXLINE( 723)		::flixel::effects::FlxFlicker_obj::stopFlickering(Object);
HXLINE( 724)		return Object;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxSpriteUtil_obj,stopFlickering,return )

 ::flixel::FlxSprite FlxSpriteUtil_obj::fadeIn( ::flixel::FlxSprite sprite,::hx::Null< Float >  __o_Duration, ::Dynamic ResetAlpha, ::Dynamic OnComplete){
            		HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_0, ::flixel::FlxSprite,sprite1) HXARGC(1)
            		void _hx_run(Float f){
            			HX_STACKFRAME(&_hx_pos_aff86ac70b6ed09e_740_fadeIn)
HXLINE( 740)			::flixel::util::FlxSpriteUtil_obj::alphaTween(sprite1,f);
            		}
            		HX_END_LOCAL_FUNC1((void))

            		Float Duration = __o_Duration.Default(1);
            	HX_STACKFRAME(&_hx_pos_aff86ac70b6ed09e_735_fadeIn)
HXLINE( 736)		if (( (bool)(ResetAlpha) )) {
HXLINE( 738)			sprite->set_alpha(( (Float)(0) ));
            		}
HXLINE( 740)		 ::flixel::FlxSprite sprite1 = sprite;
HXDLIN( 740)		 ::Dynamic _hx_tmp =  ::Dynamic(new _hx_Closure_0(sprite1));
HXDLIN( 740)		::flixel::tweens::FlxTween_obj::num(sprite->alpha,( (Float)(1) ),Duration, ::Dynamic(::hx::Anon_obj::Create(1)
            			->setFixed(0,HX_("onComplete",f8,d4,7e,5d),OnComplete)),_hx_tmp);
HXLINE( 741)		return sprite;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(FlxSpriteUtil_obj,fadeIn,return )

 ::flixel::FlxSprite FlxSpriteUtil_obj::fadeOut( ::flixel::FlxSprite sprite,::hx::Null< Float >  __o_Duration, ::Dynamic OnComplete){
            		HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_0, ::flixel::FlxSprite,sprite1) HXARGC(1)
            		void _hx_run(Float f){
            			HX_STACKFRAME(&_hx_pos_aff86ac70b6ed09e_753_fadeOut)
HXLINE( 753)			::flixel::util::FlxSpriteUtil_obj::alphaTween(sprite1,f);
            		}
            		HX_END_LOCAL_FUNC1((void))

            		Float Duration = __o_Duration.Default(1);
            	HX_STACKFRAME(&_hx_pos_aff86ac70b6ed09e_752_fadeOut)
HXLINE( 753)		 ::flixel::FlxSprite sprite1 = sprite;
HXDLIN( 753)		 ::Dynamic _hx_tmp =  ::Dynamic(new _hx_Closure_0(sprite1));
HXDLIN( 753)		::flixel::tweens::FlxTween_obj::num(sprite->alpha,( (Float)(0) ),Duration, ::Dynamic(::hx::Anon_obj::Create(1)
            			->setFixed(0,HX_("onComplete",f8,d4,7e,5d),OnComplete)),_hx_tmp);
HXLINE( 754)		return sprite;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FlxSpriteUtil_obj,fadeOut,return )

void FlxSpriteUtil_obj::alphaTween( ::flixel::FlxSprite sprite,Float f){
            	HX_STACKFRAME(&_hx_pos_aff86ac70b6ed09e_759_alphaTween)
HXDLIN( 759)		sprite->set_alpha(f);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FlxSpriteUtil_obj,alphaTween,(void))


FlxSpriteUtil_obj::FlxSpriteUtil_obj()
{
}

bool FlxSpriteUtil_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"fill") ) { outValue = fill_dyn(); return true; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"bound") ) { outValue = bound_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"space") ) { outValue = space_dyn(); return true; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"fadeIn") ) { outValue = fadeIn_dyn(); return true; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"endDraw") ) { outValue = endDraw_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"flicker") ) { outValue = flicker_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"fadeOut") ) { outValue = fadeOut_dyn(); return true; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"flashGfx") ) { outValue = ( flashGfx ); return true; }
		if (HX_FIELD_EQ(inName,"drawLine") ) { outValue = drawLine_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"drawRect") ) { outValue = drawRect_dyn(); return true; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"alphaMask") ) { outValue = alphaMask_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"drawCurve") ) { outValue = drawCurve_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"beginDraw") ) { outValue = beginDraw_dyn(); return true; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"screenWrap") ) { outValue = screenWrap_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"cameraWrap") ) { outValue = cameraWrap_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"drawCircle") ) { outValue = drawCircle_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"alphaTween") ) { outValue = alphaTween_dyn(); return true; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"cameraBound") ) { outValue = cameraBound_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"drawEllipse") ) { outValue = drawEllipse_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"drawPolygon") ) { outValue = drawPolygon_dyn(); return true; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"drawTriangle") ) { outValue = drawTriangle_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"setLineStyle") ) { outValue = setLineStyle_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"isFlickering") ) { outValue = isFlickering_dyn(); return true; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"drawRoundRect") ) { outValue = drawRoundRect_dyn(); return true; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"flashGfxSprite") ) { outValue = ( flashGfxSprite ); return true; }
		if (HX_FIELD_EQ(inName,"stopFlickering") ) { outValue = stopFlickering_dyn(); return true; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"alphaMaskFlxSprite") ) { outValue = alphaMaskFlxSprite_dyn(); return true; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"updateSpriteGraphic") ) { outValue = updateSpriteGraphic_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"getDefaultLineStyle") ) { outValue = getDefaultLineStyle_dyn(); return true; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"drawRoundRectComplex") ) { outValue = drawRoundRectComplex_dyn(); return true; }
	}
	return false;
}

bool FlxSpriteUtil_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"flashGfx") ) { flashGfx=ioValue.Cast<  ::openfl::display::Graphics >(); return true; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"flashGfxSprite") ) { flashGfxSprite=ioValue.Cast<  ::openfl::display::Sprite >(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *FlxSpriteUtil_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo FlxSpriteUtil_obj_sStaticStorageInfo[] = {
	{::hx::fsObject /*  ::openfl::display::Sprite */ ,(void *) &FlxSpriteUtil_obj::flashGfxSprite,HX_("flashGfxSprite",8e,26,3f,ab)},
	{::hx::fsObject /*  ::openfl::display::Graphics */ ,(void *) &FlxSpriteUtil_obj::flashGfx,HX_("flashGfx",a9,b1,ce,99)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static void FlxSpriteUtil_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxSpriteUtil_obj::flashGfxSprite,"flashGfxSprite");
	HX_MARK_MEMBER_NAME(FlxSpriteUtil_obj::flashGfx,"flashGfx");
};

#ifdef HXCPP_VISIT_ALLOCS
static void FlxSpriteUtil_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxSpriteUtil_obj::flashGfxSprite,"flashGfxSprite");
	HX_VISIT_MEMBER_NAME(FlxSpriteUtil_obj::flashGfx,"flashGfx");
};

#endif

::hx::Class FlxSpriteUtil_obj::__mClass;

static ::String FlxSpriteUtil_obj_sStaticFields[] = {
	HX_("flashGfxSprite",8e,26,3f,ab),
	HX_("flashGfx",a9,b1,ce,99),
	HX_("alphaMask",6a,1b,50,e2),
	HX_("alphaMaskFlxSprite",4d,fd,ae,12),
	HX_("screenWrap",56,c7,35,c7),
	HX_("bound",3e,b0,fc,b6),
	HX_("cameraWrap",0f,63,1d,b5),
	HX_("cameraBound",59,a3,42,ab),
	HX_("space",c6,8c,66,81),
	HX_("drawLine",18,c2,1c,5c),
	HX_("drawCurve",0b,82,63,16),
	HX_("drawRect",48,f7,10,60),
	HX_("drawRoundRect",ee,c3,aa,e2),
	HX_("drawRoundRectComplex",e2,43,2c,11),
	HX_("drawCircle",34,ed,d0,97),
	HX_("drawEllipse",3a,85,ce,54),
	HX_("drawTriangle",ec,4a,b9,63),
	HX_("drawPolygon",d6,46,d9,5b),
	HX_("beginDraw",cd,0a,4a,8b),
	HX_("endDraw",7f,e5,94,24),
	HX_("updateSpriteGraphic",5a,59,f9,55),
	HX_("setLineStyle",9b,68,68,ef),
	HX_("getDefaultLineStyle",52,78,37,48),
	HX_("fill",83,ce,bb,43),
	HX_("flicker",f8,da,ec,76),
	HX_("isFlickering",74,85,73,33),
	HX_("stopFlickering",8c,27,6a,4a),
	HX_("fadeIn",81,4c,ab,e4),
	HX_("fadeOut",72,38,3c,31),
	HX_("alphaTween",2d,fe,15,3a),
	::String(null())
};

void FlxSpriteUtil_obj::__register()
{
	FlxSpriteUtil_obj _hx_dummy;
	FlxSpriteUtil_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("flixel.util.FlxSpriteUtil",ff,7e,4e,f7);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &FlxSpriteUtil_obj::__GetStatic;
	__mClass->mSetStaticField = &FlxSpriteUtil_obj::__SetStatic;
	__mClass->mMarkFunc = FlxSpriteUtil_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(FlxSpriteUtil_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< FlxSpriteUtil_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = FlxSpriteUtil_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = FlxSpriteUtil_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = FlxSpriteUtil_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void FlxSpriteUtil_obj::__boot()
{
{
            	HX_GC_STACKFRAME(&_hx_pos_aff86ac70b6ed09e_39_boot)
HXDLIN(  39)		flashGfxSprite =  ::openfl::display::Sprite_obj::__alloc( HX_CTX );
            	}
{
            	HX_STACKFRAME(&_hx_pos_aff86ac70b6ed09e_41_boot)
HXDLIN(  41)		flashGfx = ::flixel::util::FlxSpriteUtil_obj::flashGfxSprite->get_graphics();
            	}
}

} // end namespace flixel
} // end namespace util
