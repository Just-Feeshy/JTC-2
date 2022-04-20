#include <hxcpp.h>

#ifndef INCLUDED_95f339a1d026d52c
#define INCLUDED_95f339a1d026d52c
#include "hxMath.h"
#endif
#ifndef INCLUDED_lime__internal_graphics_ImageDataUtil
#include <lime/_internal/graphics/ImageDataUtil.h>
#endif
#ifndef INCLUDED_lime_graphics_Image
#include <lime/graphics/Image.h>
#endif
#ifndef INCLUDED_lime_math_Rectangle
#include <lime/math/Rectangle.h>
#endif
#ifndef INCLUDED_lime_math_Vector2
#include <lime/math/Vector2.h>
#endif
#ifndef INCLUDED_lime_system_System
#include <lime/system/System.h>
#endif
#ifndef INCLUDED_openfl_display_BitmapData
#include <openfl/display/BitmapData.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObjectRenderer
#include <openfl/display/DisplayObjectRenderer.h>
#endif
#ifndef INCLUDED_openfl_display_IBitmapDrawable
#include <openfl/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl_display_Shader
#include <openfl/display/Shader.h>
#endif
#ifndef INCLUDED_openfl_display_ShaderParameter_Float
#include <openfl/display/ShaderParameter_Float.h>
#endif
#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_filters_BitmapFilter
#include <openfl/filters/BitmapFilter.h>
#endif
#ifndef INCLUDED_openfl_filters_BitmapFilterShader
#include <openfl/filters/BitmapFilterShader.h>
#endif
#ifndef INCLUDED_openfl_filters_BlurFilter
#include <openfl/filters/BlurFilter.h>
#endif
#ifndef INCLUDED_openfl_filters__BlurFilter_BlurShader
#include <openfl/filters/_BlurFilter/BlurShader.h>
#endif
#ifndef INCLUDED_openfl_geom_Point
#include <openfl/geom/Point.h>
#endif
#ifndef INCLUDED_openfl_geom_Rectangle
#include <openfl/geom/Rectangle.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_6e95f8db175a4230_166_new,"openfl.filters.BlurFilter","new",0x2ff6acc2,"openfl.filters.BlurFilter.new","openfl/filters/BlurFilter.hx",166,0x46563eac)
HX_LOCAL_STACK_FRAME(_hx_pos_6e95f8db175a4230_180_clone,"openfl.filters.BlurFilter","clone",0xcbbf4c3f,"openfl.filters.BlurFilter.clone","openfl/filters/BlurFilter.hx",180,0x46563eac)
HX_LOCAL_STACK_FRAME(_hx_pos_6e95f8db175a4230_185___applyFilter,"openfl.filters.BlurFilter","__applyFilter",0x511b0b88,"openfl.filters.BlurFilter.__applyFilter","openfl/filters/BlurFilter.hx",185,0x46563eac)
HX_LOCAL_STACK_FRAME(_hx_pos_6e95f8db175a4230_198___initShader,"openfl.filters.BlurFilter","__initShader",0xc19d1cd3,"openfl.filters.BlurFilter.__initShader","openfl/filters/BlurFilter.hx",198,0x46563eac)
HX_LOCAL_STACK_FRAME(_hx_pos_6e95f8db175a4230_220_get_blurX,"openfl.filters.BlurFilter","get_blurX",0xeb11be0a,"openfl.filters.BlurFilter.get_blurX","openfl/filters/BlurFilter.hx",220,0x46563eac)
HX_LOCAL_STACK_FRAME(_hx_pos_6e95f8db175a4230_224_set_blurX,"openfl.filters.BlurFilter","set_blurX",0xce62aa16,"openfl.filters.BlurFilter.set_blurX","openfl/filters/BlurFilter.hx",224,0x46563eac)
HX_LOCAL_STACK_FRAME(_hx_pos_6e95f8db175a4230_237_get_blurY,"openfl.filters.BlurFilter","get_blurY",0xeb11be0b,"openfl.filters.BlurFilter.get_blurY","openfl/filters/BlurFilter.hx",237,0x46563eac)
HX_LOCAL_STACK_FRAME(_hx_pos_6e95f8db175a4230_241_set_blurY,"openfl.filters.BlurFilter","set_blurY",0xce62aa17,"openfl.filters.BlurFilter.set_blurY","openfl/filters/BlurFilter.hx",241,0x46563eac)
HX_LOCAL_STACK_FRAME(_hx_pos_6e95f8db175a4230_254_get_quality,"openfl.filters.BlurFilter","get_quality",0xa28f7338,"openfl.filters.BlurFilter.get_quality","openfl/filters/BlurFilter.hx",254,0x46563eac)
HX_LOCAL_STACK_FRAME(_hx_pos_6e95f8db175a4230_258_set_quality,"openfl.filters.BlurFilter","set_quality",0xacfc7a44,"openfl.filters.BlurFilter.set_quality","openfl/filters/BlurFilter.hx",258,0x46563eac)
HX_LOCAL_STACK_FRAME(_hx_pos_6e95f8db175a4230_73_boot,"openfl.filters.BlurFilter","boot",0xbff97d90,"openfl.filters.BlurFilter.boot","openfl/filters/BlurFilter.hx",73,0x46563eac)
namespace openfl{
namespace filters{

void BlurFilter_obj::__construct(::hx::Null< Float >  __o_blurX,::hx::Null< Float >  __o_blurY,::hx::Null< int >  __o_quality){
            		Float blurX = __o_blurX.Default(4);
            		Float blurY = __o_blurY.Default(4);
            		int quality = __o_quality.Default(1);
            	HX_STACKFRAME(&_hx_pos_6e95f8db175a4230_166_new)
HXLINE( 167)		super::__construct();
HXLINE( 169)		this->set_blurX(blurX);
HXLINE( 170)		this->set_blurY(blurY);
HXLINE( 171)		this->set_quality(quality);
HXLINE( 173)		this->_hx___needSecondBitmapData = true;
HXLINE( 174)		this->_hx___preserveObject = false;
HXLINE( 175)		this->_hx___renderDirty = true;
            	}

Dynamic BlurFilter_obj::__CreateEmpty() { return new BlurFilter_obj; }

void *BlurFilter_obj::_hx_vtable = 0;

Dynamic BlurFilter_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< BlurFilter_obj > _hx_result = new BlurFilter_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return _hx_result;
}

bool BlurFilter_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x26de6bd2) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x26de6bd2;
	} else {
		return inClassId==(int)0x59e99fca;
	}
}

 ::openfl::filters::BitmapFilter BlurFilter_obj::clone(){
            	HX_GC_STACKFRAME(&_hx_pos_6e95f8db175a4230_180_clone)
HXDLIN( 180)		return  ::openfl::filters::BlurFilter_obj::__alloc( HX_CTX ,this->_hx___blurX,this->_hx___blurY,this->_hx___quality);
            	}


 ::openfl::display::BitmapData BlurFilter_obj::_hx___applyFilter( ::openfl::display::BitmapData bitmapData, ::openfl::display::BitmapData sourceBitmapData, ::openfl::geom::Rectangle sourceRect, ::openfl::geom::Point destPoint){
            	HX_STACKFRAME(&_hx_pos_6e95f8db175a4230_185___applyFilter)
HXLINE( 187)		int timer = ::lime::_hx_system::System_obj::getTimer();
HXDLIN( 187)		Float time;
HXDLIN( 187)		if ((timer > 0)) {
HXLINE( 187)			time = (( (Float)(timer) ) / ( (Float)(1000) ));
            		}
            		else {
HXLINE( 187)			time = ( (Float)(0) );
            		}
HXLINE( 188)		 ::lime::graphics::Image bitmapData1 = bitmapData->image;
HXDLIN( 188)		 ::lime::graphics::Image sourceBitmapData1 = sourceBitmapData->image;
HXDLIN( 188)		 ::lime::math::Rectangle finalImage = sourceRect->_hx___toLimeRectangle();
HXDLIN( 188)		 ::lime::math::Vector2 finalImage1 = destPoint->_hx___toLimeVector2();
HXDLIN( 188)		 ::lime::graphics::Image finalImage2 = ::lime::_internal::graphics::ImageDataUtil_obj::gaussianBlur(bitmapData1,sourceBitmapData1,finalImage,finalImage1,this->_hx___blurX,this->_hx___blurY,this->_hx___quality,null(),null());
HXLINE( 190)		int timer1 = ::lime::_hx_system::System_obj::getTimer();
HXDLIN( 190)		Float elapsed;
HXDLIN( 190)		if ((timer1 > 0)) {
HXLINE( 190)			elapsed = (( (Float)(timer1) ) / ( (Float)(1000) ));
            		}
            		else {
HXLINE( 190)			elapsed = ( (Float)(0) );
            		}
HXDLIN( 190)		Float elapsed1 = (elapsed - time);
HXLINE( 192)		if (::hx::IsInstanceEq( finalImage2,bitmapData->image )) {
HXLINE( 192)			return bitmapData;
            		}
HXLINE( 194)		return sourceBitmapData;
            	}


 ::openfl::display::Shader BlurFilter_obj::_hx___initShader( ::openfl::display::DisplayObjectRenderer renderer,int pass, ::openfl::display::BitmapData sourceBitmapData){
            	HX_STACKFRAME(&_hx_pos_6e95f8db175a4230_198___initShader)
HXLINE( 200)		if ((pass < this->_hx___horizontalPasses)) {
HXLINE( 202)			Float scale = ::Math_obj::pow(((Float)0.5),( (Float)((pass >> 1)) ));
HXLINE( 203)			::openfl::filters::BlurFilter_obj::_hx___blurShader->uRadius->value[0] = (this->get_blurX() * scale);
HXLINE( 204)			::openfl::filters::BlurFilter_obj::_hx___blurShader->uRadius->value[1] = ( (Float)(0) );
            		}
            		else {
HXLINE( 208)			Float scale = ::Math_obj::pow(((Float)0.5),( (Float)(((pass - this->_hx___horizontalPasses) >> 1)) ));
HXLINE( 209)			::openfl::filters::BlurFilter_obj::_hx___blurShader->uRadius->value[0] = ( (Float)(0) );
HXLINE( 210)			::openfl::filters::BlurFilter_obj::_hx___blurShader->uRadius->value[1] = (this->get_blurY() * scale);
            		}
HXLINE( 214)		return ::openfl::filters::BlurFilter_obj::_hx___blurShader;
            	}


Float BlurFilter_obj::get_blurX(){
            	HX_STACKFRAME(&_hx_pos_6e95f8db175a4230_220_get_blurX)
HXDLIN( 220)		return this->_hx___blurX;
            	}


HX_DEFINE_DYNAMIC_FUNC0(BlurFilter_obj,get_blurX,return )

Float BlurFilter_obj::set_blurX(Float value){
            	HX_STACKFRAME(&_hx_pos_6e95f8db175a4230_224_set_blurX)
HXLINE( 225)		if ((value != this->_hx___blurX)) {
HXLINE( 227)			this->_hx___blurX = value;
HXLINE( 228)			this->_hx___renderDirty = true;
HXLINE( 229)			int _hx_tmp;
HXDLIN( 229)			if ((value > 0)) {
HXLINE( 229)				_hx_tmp = ::Math_obj::ceil(value);
            			}
            			else {
HXLINE( 229)				_hx_tmp = 0;
            			}
HXDLIN( 229)			this->_hx___leftExtension = _hx_tmp;
HXLINE( 230)			this->_hx___rightExtension = this->_hx___leftExtension;
            		}
HXLINE( 232)		return value;
            	}


HX_DEFINE_DYNAMIC_FUNC1(BlurFilter_obj,set_blurX,return )

Float BlurFilter_obj::get_blurY(){
            	HX_STACKFRAME(&_hx_pos_6e95f8db175a4230_237_get_blurY)
HXDLIN( 237)		return this->_hx___blurY;
            	}


HX_DEFINE_DYNAMIC_FUNC0(BlurFilter_obj,get_blurY,return )

Float BlurFilter_obj::set_blurY(Float value){
            	HX_STACKFRAME(&_hx_pos_6e95f8db175a4230_241_set_blurY)
HXLINE( 242)		if ((value != this->_hx___blurY)) {
HXLINE( 244)			this->_hx___blurY = value;
HXLINE( 245)			this->_hx___renderDirty = true;
HXLINE( 246)			int _hx_tmp;
HXDLIN( 246)			if ((value > 0)) {
HXLINE( 246)				_hx_tmp = ::Math_obj::ceil(value);
            			}
            			else {
HXLINE( 246)				_hx_tmp = 0;
            			}
HXDLIN( 246)			this->_hx___topExtension = _hx_tmp;
HXLINE( 247)			this->_hx___bottomExtension = this->_hx___topExtension;
            		}
HXLINE( 249)		return value;
            	}


HX_DEFINE_DYNAMIC_FUNC1(BlurFilter_obj,set_blurY,return )

int BlurFilter_obj::get_quality(){
            	HX_STACKFRAME(&_hx_pos_6e95f8db175a4230_254_get_quality)
HXDLIN( 254)		return this->_hx___quality;
            	}


HX_DEFINE_DYNAMIC_FUNC0(BlurFilter_obj,get_quality,return )

int BlurFilter_obj::set_quality(int value){
            	HX_STACKFRAME(&_hx_pos_6e95f8db175a4230_258_set_quality)
HXLINE( 261)		int _hx_tmp;
HXDLIN( 261)		if ((this->_hx___blurX <= 0)) {
HXLINE( 261)			_hx_tmp = 0;
            		}
            		else {
HXLINE( 261)			_hx_tmp = (::Math_obj::round((this->_hx___blurX * (( (Float)(value) ) / ( (Float)(4) )))) + 1);
            		}
HXDLIN( 261)		this->_hx___horizontalPasses = _hx_tmp;
HXLINE( 262)		int _hx_tmp1;
HXDLIN( 262)		if ((this->_hx___blurY <= 0)) {
HXLINE( 262)			_hx_tmp1 = 0;
            		}
            		else {
HXLINE( 262)			_hx_tmp1 = (::Math_obj::round((this->_hx___blurY * (( (Float)(value) ) / ( (Float)(4) )))) + 1);
            		}
HXDLIN( 262)		this->_hx___verticalPasses = _hx_tmp1;
HXLINE( 264)		this->_hx___numShaderPasses = (this->_hx___horizontalPasses + this->_hx___verticalPasses);
HXLINE( 266)		if ((value != this->_hx___quality)) {
HXLINE( 266)			this->_hx___renderDirty = true;
            		}
HXLINE( 267)		return (this->_hx___quality = value);
            	}


HX_DEFINE_DYNAMIC_FUNC1(BlurFilter_obj,set_quality,return )

 ::openfl::filters::_BlurFilter::BlurShader BlurFilter_obj::_hx___blurShader;


::hx::ObjectPtr< BlurFilter_obj > BlurFilter_obj::__new(::hx::Null< Float >  __o_blurX,::hx::Null< Float >  __o_blurY,::hx::Null< int >  __o_quality) {
	::hx::ObjectPtr< BlurFilter_obj > __this = new BlurFilter_obj();
	__this->__construct(__o_blurX,__o_blurY,__o_quality);
	return __this;
}

::hx::ObjectPtr< BlurFilter_obj > BlurFilter_obj::__alloc(::hx::Ctx *_hx_ctx,::hx::Null< Float >  __o_blurX,::hx::Null< Float >  __o_blurY,::hx::Null< int >  __o_quality) {
	BlurFilter_obj *__this = (BlurFilter_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(BlurFilter_obj), true, "openfl.filters.BlurFilter"));
	*(void **)__this = BlurFilter_obj::_hx_vtable;
	__this->__construct(__o_blurX,__o_blurY,__o_quality);
	return __this;
}

BlurFilter_obj::BlurFilter_obj()
{
}

::hx::Val BlurFilter_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"blurX") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_blurX() ); }
		if (HX_FIELD_EQ(inName,"blurY") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_blurY() ); }
		if (HX_FIELD_EQ(inName,"clone") ) { return ::hx::Val( clone_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"quality") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_quality() ); }
		if (HX_FIELD_EQ(inName,"__blurX") ) { return ::hx::Val( _hx___blurX ); }
		if (HX_FIELD_EQ(inName,"__blurY") ) { return ::hx::Val( _hx___blurY ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"__quality") ) { return ::hx::Val( _hx___quality ); }
		if (HX_FIELD_EQ(inName,"get_blurX") ) { return ::hx::Val( get_blurX_dyn() ); }
		if (HX_FIELD_EQ(inName,"set_blurX") ) { return ::hx::Val( set_blurX_dyn() ); }
		if (HX_FIELD_EQ(inName,"get_blurY") ) { return ::hx::Val( get_blurY_dyn() ); }
		if (HX_FIELD_EQ(inName,"set_blurY") ) { return ::hx::Val( set_blurY_dyn() ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_quality") ) { return ::hx::Val( get_quality_dyn() ); }
		if (HX_FIELD_EQ(inName,"set_quality") ) { return ::hx::Val( set_quality_dyn() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"__initShader") ) { return ::hx::Val( _hx___initShader_dyn() ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"__applyFilter") ) { return ::hx::Val( _hx___applyFilter_dyn() ); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"__verticalPasses") ) { return ::hx::Val( _hx___verticalPasses ); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"__horizontalPasses") ) { return ::hx::Val( _hx___horizontalPasses ); }
	}
	return super::__Field(inName,inCallProp);
}

bool BlurFilter_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"__blurShader") ) { outValue = ( _hx___blurShader ); return true; }
	}
	return false;
}

::hx::Val BlurFilter_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"blurX") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_blurX(inValue.Cast< Float >()) ); }
		if (HX_FIELD_EQ(inName,"blurY") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_blurY(inValue.Cast< Float >()) ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"quality") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_quality(inValue.Cast< int >()) ); }
		if (HX_FIELD_EQ(inName,"__blurX") ) { _hx___blurX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"__blurY") ) { _hx___blurY=inValue.Cast< Float >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"__quality") ) { _hx___quality=inValue.Cast< int >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"__verticalPasses") ) { _hx___verticalPasses=inValue.Cast< int >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"__horizontalPasses") ) { _hx___horizontalPasses=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool BlurFilter_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"__blurShader") ) { _hx___blurShader=ioValue.Cast<  ::openfl::filters::_BlurFilter::BlurShader >(); return true; }
	}
	return false;
}

void BlurFilter_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("blurX",d1,0f,01,b5));
	outFields->push(HX_("blurY",d2,0f,01,b5));
	outFields->push(HX_("quality",bf,04,4c,44));
	outFields->push(HX_("__blurX",b1,68,5f,1f));
	outFields->push(HX_("__blurY",b2,68,5f,1f));
	outFields->push(HX_("__horizontalPasses",a3,9a,5d,02));
	outFields->push(HX_("__quality",9f,55,9a,c5));
	outFields->push(HX_("__verticalPasses",b5,4b,f5,ec));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo BlurFilter_obj_sMemberStorageInfo[] = {
	{::hx::fsFloat,(int)offsetof(BlurFilter_obj,_hx___blurX),HX_("__blurX",b1,68,5f,1f)},
	{::hx::fsFloat,(int)offsetof(BlurFilter_obj,_hx___blurY),HX_("__blurY",b2,68,5f,1f)},
	{::hx::fsInt,(int)offsetof(BlurFilter_obj,_hx___horizontalPasses),HX_("__horizontalPasses",a3,9a,5d,02)},
	{::hx::fsInt,(int)offsetof(BlurFilter_obj,_hx___quality),HX_("__quality",9f,55,9a,c5)},
	{::hx::fsInt,(int)offsetof(BlurFilter_obj,_hx___verticalPasses),HX_("__verticalPasses",b5,4b,f5,ec)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo BlurFilter_obj_sStaticStorageInfo[] = {
	{::hx::fsObject /*  ::openfl::filters::_BlurFilter::BlurShader */ ,(void *) &BlurFilter_obj::_hx___blurShader,HX_("__blurShader",4c,e8,3f,cd)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static ::String BlurFilter_obj_sMemberFields[] = {
	HX_("__blurX",b1,68,5f,1f),
	HX_("__blurY",b2,68,5f,1f),
	HX_("__horizontalPasses",a3,9a,5d,02),
	HX_("__quality",9f,55,9a,c5),
	HX_("__verticalPasses",b5,4b,f5,ec),
	HX_("clone",5d,13,63,48),
	HX_("__applyFilter",a6,20,a8,09),
	HX_("__initShader",75,95,f9,59),
	HX_("get_blurX",28,6c,aa,f8),
	HX_("set_blurX",34,58,fb,db),
	HX_("get_blurY",29,6c,aa,f8),
	HX_("set_blurY",35,58,fb,db),
	HX_("get_quality",d6,64,46,ca),
	HX_("set_quality",e2,6b,b3,d4),
	::String(null()) };

static void BlurFilter_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BlurFilter_obj::_hx___blurShader,"__blurShader");
};

#ifdef HXCPP_VISIT_ALLOCS
static void BlurFilter_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BlurFilter_obj::_hx___blurShader,"__blurShader");
};

#endif

::hx::Class BlurFilter_obj::__mClass;

static ::String BlurFilter_obj_sStaticFields[] = {
	HX_("__blurShader",4c,e8,3f,cd),
	::String(null())
};

void BlurFilter_obj::__register()
{
	BlurFilter_obj _hx_dummy;
	BlurFilter_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("openfl.filters.BlurFilter",d0,e3,34,2e);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &BlurFilter_obj::__GetStatic;
	__mClass->mSetStaticField = &BlurFilter_obj::__SetStatic;
	__mClass->mMarkFunc = BlurFilter_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(BlurFilter_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(BlurFilter_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< BlurFilter_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = BlurFilter_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = BlurFilter_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = BlurFilter_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void BlurFilter_obj::__boot()
{
{
            	HX_GC_STACKFRAME(&_hx_pos_6e95f8db175a4230_73_boot)
HXDLIN(  73)		_hx___blurShader =  ::openfl::filters::_BlurFilter::BlurShader_obj::__alloc( HX_CTX );
            	}
}

} // end namespace openfl
} // end namespace filters
