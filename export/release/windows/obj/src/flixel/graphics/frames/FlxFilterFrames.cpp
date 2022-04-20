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
#ifndef INCLUDED_flixel_graphics_FlxGraphic
#include <flixel/graphics/FlxGraphic.h>
#endif
#ifndef INCLUDED_flixel_graphics_frames_FlxFilterFrames
#include <flixel/graphics/frames/FlxFilterFrames.h>
#endif
#ifndef INCLUDED_flixel_graphics_frames_FlxFrame
#include <flixel/graphics/frames/FlxFrame.h>
#endif
#ifndef INCLUDED_flixel_graphics_frames_FlxFrameCollectionType
#include <flixel/graphics/frames/FlxFrameCollectionType.h>
#endif
#ifndef INCLUDED_flixel_graphics_frames_FlxFramesCollection
#include <flixel/graphics/frames/FlxFramesCollection.h>
#endif
#ifndef INCLUDED_flixel_graphics_frames_FlxImageFrame
#include <flixel/graphics/frames/FlxImageFrame.h>
#endif
#ifndef INCLUDED_flixel_math_FlxPoint
#include <flixel/math/FlxPoint.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxDestroyable
#include <flixel/util/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxPooled
#include <flixel/util/IFlxPooled.h>
#endif
#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_openfl_display_BitmapData
#include <openfl/display/BitmapData.h>
#endif
#ifndef INCLUDED_openfl_display_IBitmapDrawable
#include <openfl/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl_filters_BitmapFilter
#include <openfl/filters/BitmapFilter.h>
#endif
#ifndef INCLUDED_openfl_geom_Point
#include <openfl/geom/Point.h>
#endif
#ifndef INCLUDED_openfl_geom_Rectangle
#include <openfl/geom/Rectangle.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_741532f23a714680_17_new,"flixel.graphics.frames.FlxFilterFrames","new",0x52a806cb,"flixel.graphics.frames.FlxFilterFrames.new","flixel/graphics/frames/FlxFilterFrames.hx",17,0x20aafb66)
HX_LOCAL_STACK_FRAME(_hx_pos_741532f23a714680_85_applyToSprite,"flixel.graphics.frames.FlxFilterFrames","applyToSprite",0xf5f46d99,"flixel.graphics.frames.FlxFilterFrames.applyToSprite","flixel/graphics/frames/FlxFilterFrames.hx",85,0x20aafb66)
HX_LOCAL_STACK_FRAME(_hx_pos_741532f23a714680_97_genFrames,"flixel.graphics.frames.FlxFilterFrames","genFrames",0xe134c901,"flixel.graphics.frames.FlxFilterFrames.genFrames","flixel/graphics/frames/FlxFilterFrames.hx",97,0x20aafb66)
HX_LOCAL_STACK_FRAME(_hx_pos_741532f23a714680_127_addFilter,"flixel.graphics.frames.FlxFilterFrames","addFilter",0xef32ad64,"flixel.graphics.frames.FlxFilterFrames.addFilter","flixel/graphics/frames/FlxFilterFrames.hx",127,0x20aafb66)
HX_LOCAL_STACK_FRAME(_hx_pos_741532f23a714680_140_removeFilter,"flixel.graphics.frames.FlxFilterFrames","removeFilter",0xcbf7df51,"flixel.graphics.frames.FlxFilterFrames.removeFilter","flixel/graphics/frames/FlxFilterFrames.hx",140,0x20aafb66)
HX_LOCAL_STACK_FRAME(_hx_pos_741532f23a714680_152_clearFilters,"flixel.graphics.frames.FlxFilterFrames","clearFilters",0xbc5a77e3,"flixel.graphics.frames.FlxFilterFrames.clearFilters","flixel/graphics/frames/FlxFilterFrames.hx",152,0x20aafb66)
HX_LOCAL_STACK_FRAME(_hx_pos_741532f23a714680_161_regenAndApplyFilters,"flixel.graphics.frames.FlxFilterFrames","regenAndApplyFilters",0x9bbb725c,"flixel.graphics.frames.FlxFilterFrames.regenAndApplyFilters","flixel/graphics/frames/FlxFilterFrames.hx",161,0x20aafb66)
HX_LOCAL_STACK_FRAME(_hx_pos_741532f23a714680_167_regenBitmaps,"flixel.graphics.frames.FlxFilterFrames","regenBitmaps",0xe849009c,"flixel.graphics.frames.FlxFilterFrames.regenBitmaps","flixel/graphics/frames/FlxFilterFrames.hx",167,0x20aafb66)
HX_LOCAL_STACK_FRAME(_hx_pos_741532f23a714680_188_applyFilter,"flixel.graphics.frames.FlxFilterFrames","applyFilter",0x9e90f931,"flixel.graphics.frames.FlxFilterFrames.applyFilter","flixel/graphics/frames/FlxFilterFrames.hx",188,0x20aafb66)
HX_LOCAL_STACK_FRAME(_hx_pos_741532f23a714680_202_applyFilters,"flixel.graphics.frames.FlxFilterFrames","applyFilters",0x20491222,"flixel.graphics.frames.FlxFilterFrames.applyFilters","flixel/graphics/frames/FlxFilterFrames.hx",202,0x20aafb66)
HX_LOCAL_STACK_FRAME(_hx_pos_741532f23a714680_207_destroy,"flixel.graphics.frames.FlxFilterFrames","destroy",0x700d74e5,"flixel.graphics.frames.FlxFilterFrames.destroy","flixel/graphics/frames/FlxFilterFrames.hx",207,0x20aafb66)
HX_LOCAL_STACK_FRAME(_hx_pos_741532f23a714680_218_set_filters,"flixel.graphics.frames.FlxFilterFrames","set_filters",0x770f2249,"flixel.graphics.frames.FlxFilterFrames.set_filters","flixel/graphics/frames/FlxFilterFrames.hx",218,0x20aafb66)
HX_LOCAL_STACK_FRAME(_hx_pos_741532f23a714680_33_fromFrames,"flixel.graphics.frames.FlxFilterFrames","fromFrames",0xdc1df1a5,"flixel.graphics.frames.FlxFilterFrames.fromFrames","flixel/graphics/frames/FlxFilterFrames.hx",33,0x20aafb66)
HX_LOCAL_STACK_FRAME(_hx_pos_741532f23a714680_19_boot,"flixel.graphics.frames.FlxFilterFrames","boot",0xf876eb67,"flixel.graphics.frames.FlxFilterFrames.boot","flixel/graphics/frames/FlxFilterFrames.hx",19,0x20aafb66)
HX_LOCAL_STACK_FRAME(_hx_pos_741532f23a714680_20_boot,"flixel.graphics.frames.FlxFilterFrames","boot",0xf876eb67,"flixel.graphics.frames.FlxFilterFrames.boot","flixel/graphics/frames/FlxFilterFrames.hx",20,0x20aafb66)
namespace flixel{
namespace graphics{
namespace frames{

void FlxFilterFrames_obj::__construct( ::flixel::graphics::frames::FlxFramesCollection sourceFrames,::hx::Null< int >  __o_widthInc,::hx::Null< int >  __o_heightInc,::Array< ::Dynamic> filters){
            		int widthInc = __o_widthInc.Default(0);
            		int heightInc = __o_heightInc.Default(0);
            	HX_STACKFRAME(&_hx_pos_741532f23a714680_17_new)
HXLINE(  49)		this->heightInc = 0;
HXLINE(  44)		this->widthInc = 0;
HXLINE(  58)		super::__construct(null(),::flixel::graphics::frames::FlxFrameCollectionType_obj::FILTER_dyn(),null());
HXLINE(  60)		this->sourceFrames = sourceFrames;
HXLINE(  62)		if ((widthInc < 0)) {
HXLINE(  62)			widthInc = 0;
            		}
HXLINE(  63)		if ((heightInc < 0)) {
HXLINE(  63)			heightInc = 0;
            		}
HXLINE(  65)		widthInc = (2 * ::Math_obj::ceil((((Float)0.5) * ( (Float)(widthInc) ))));
HXLINE(  66)		heightInc = (2 * ::Math_obj::ceil((((Float)0.5) * ( (Float)(heightInc) ))));
HXLINE(  68)		this->widthInc = widthInc;
HXLINE(  69)		this->heightInc = heightInc;
HXLINE(  71)		::Array< ::Dynamic> _hx_tmp;
HXDLIN(  71)		if (::hx::IsNull( filters )) {
HXLINE(  71)			_hx_tmp = ::Array_obj< ::Dynamic>::__new(0);
            		}
            		else {
HXLINE(  71)			_hx_tmp = filters;
            		}
HXDLIN(  71)		this->set_filters(_hx_tmp);
HXLINE(  73)		this->genFrames();
HXLINE(  74)		this->applyFilters();
            	}

Dynamic FlxFilterFrames_obj::__CreateEmpty() { return new FlxFilterFrames_obj; }

void *FlxFilterFrames_obj::_hx_vtable = 0;

Dynamic FlxFilterFrames_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< FlxFilterFrames_obj > _hx_result = new FlxFilterFrames_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return _hx_result;
}

bool FlxFilterFrames_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x214f249f) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x214f249f;
	} else {
		return inClassId==(int)0x7907b929;
	}
}

void FlxFilterFrames_obj::applyToSprite( ::flixel::FlxSprite spr,::hx::Null< bool >  __o_saveAnimations,::hx::Null< bool >  __o_updateFrames){
            		bool saveAnimations = __o_saveAnimations.Default(false);
            		bool updateFrames = __o_updateFrames.Default(false);
            	HX_STACKFRAME(&_hx_pos_741532f23a714680_85_applyToSprite)
HXLINE(  86)		if (updateFrames) {
HXLINE(  87)			this->set_filters(this->filters);
            		}
HXLINE(  89)		Float w = spr->get_width();
HXLINE(  90)		Float h = spr->get_height();
HXLINE(  91)		spr->setFrames(::hx::ObjectPtr<OBJ_>(this),saveAnimations);
HXLINE(  92)		{
HXLINE(  92)			 ::flixel::math::FlxPoint _this = spr->offset;
HXDLIN(  92)			Float Y = (((Float)0.5) * ( (Float)(this->heightInc) ));
HXDLIN(  92)			_this->set_x((_this->x + (((Float)0.5) * ( (Float)(this->widthInc) ))));
HXDLIN(  92)			_this->set_y((_this->y + Y));
            		}
HXLINE(  93)		spr->setSize(w,h);
            	}


HX_DEFINE_DYNAMIC_FUNC3(FlxFilterFrames_obj,applyToSprite,(void))

void FlxFilterFrames_obj::genFrames(){
            	HX_GC_STACKFRAME(&_hx_pos_741532f23a714680_97_genFrames)
HXLINE(  98)		 ::openfl::display::BitmapData canvas;
HXLINE(  99)		 ::flixel::graphics::FlxGraphic graph;
HXLINE( 100)		 ::flixel::graphics::frames::FlxFrame filterFrame;
HXLINE( 102)		{
HXLINE( 102)			int _g = 0;
HXDLIN( 102)			::Array< ::Dynamic> _g1 = this->sourceFrames->frames;
HXDLIN( 102)			while((_g < _g1->length)){
HXLINE( 102)				 ::flixel::graphics::frames::FlxFrame frame = _g1->__get(_g).StaticCast<  ::flixel::graphics::frames::FlxFrame >();
HXDLIN( 102)				_g = (_g + 1);
HXLINE( 104)				int canvas1 = ::Std_obj::_hx_int((frame->sourceSize->x + this->widthInc));
HXDLIN( 104)				canvas =  ::openfl::display::BitmapData_obj::__alloc( HX_CTX ,canvas1,::Std_obj::_hx_int((frame->sourceSize->y + this->heightInc)),true,0);
HXLINE( 105)				graph = ::flixel::graphics::FlxGraphic_obj::fromBitmapData(canvas,false,null(),false);
HXLINE( 107)				filterFrame = graph->get_imageFrame()->get_frame();
HXLINE( 109)				this->frames->push(filterFrame);
HXLINE( 110)				if (::hx::IsNotNull( frame->name )) {
HXLINE( 112)					filterFrame->name = frame->name;
HXLINE( 113)					this->framesHash->set(frame->name,filterFrame);
            				}
            			}
            		}
HXLINE( 117)		this->regenBitmaps(false);
            	}


HX_DEFINE_DYNAMIC_FUNC0(FlxFilterFrames_obj,genFrames,(void))

void FlxFilterFrames_obj::addFilter( ::openfl::filters::BitmapFilter filter){
            	HX_STACKFRAME(&_hx_pos_741532f23a714680_127_addFilter)
HXDLIN( 127)		if (::hx::IsNotNull( filter )) {
HXLINE( 129)			this->filters->push(filter);
HXLINE( 130)			this->applyFilter(filter);
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(FlxFilterFrames_obj,addFilter,(void))

void FlxFilterFrames_obj::removeFilter( ::openfl::filters::BitmapFilter filter){
            	HX_STACKFRAME(&_hx_pos_741532f23a714680_140_removeFilter)
HXLINE( 141)		bool _hx_tmp;
HXDLIN( 141)		if ((this->filters->length != 0)) {
HXLINE( 141)			_hx_tmp = ::hx::IsNull( filter );
            		}
            		else {
HXLINE( 141)			_hx_tmp = true;
            		}
HXDLIN( 141)		if (_hx_tmp) {
HXLINE( 142)			return;
            		}
HXLINE( 144)		if (this->filters->remove(filter)) {
HXLINE( 145)			this->regenAndApplyFilters();
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(FlxFilterFrames_obj,removeFilter,(void))

void FlxFilterFrames_obj::clearFilters(){
            	HX_STACKFRAME(&_hx_pos_741532f23a714680_152_clearFilters)
HXLINE( 153)		if ((this->filters->length == 0)) {
HXLINE( 154)			return;
            		}
HXLINE( 156)		this->filters->removeRange(0,this->filters->length);
HXLINE( 157)		this->regenBitmaps(null());
            	}


HX_DEFINE_DYNAMIC_FUNC0(FlxFilterFrames_obj,clearFilters,(void))

void FlxFilterFrames_obj::regenAndApplyFilters(){
            	HX_STACKFRAME(&_hx_pos_741532f23a714680_161_regenAndApplyFilters)
HXLINE( 162)		this->regenBitmaps(null());
HXLINE( 163)		this->applyFilters();
            	}


HX_DEFINE_DYNAMIC_FUNC0(FlxFilterFrames_obj,regenAndApplyFilters,(void))

void FlxFilterFrames_obj::regenBitmaps(::hx::Null< bool >  __o_fill){
            		bool fill = __o_fill.Default(true);
            	HX_STACKFRAME(&_hx_pos_741532f23a714680_167_regenBitmaps)
HXLINE( 168)		int numFrames = this->frames->length;
HXLINE( 169)		 ::flixel::graphics::frames::FlxFrame frame;
HXLINE( 170)		 ::flixel::graphics::frames::FlxFrame sourceFrame;
HXLINE( 171)		 ::openfl::geom::Point frameOffset = ::flixel::graphics::frames::FlxFilterFrames_obj::point;
HXLINE( 173)		{
HXLINE( 173)			int _g = 0;
HXDLIN( 173)			int _g1 = numFrames;
HXDLIN( 173)			while((_g < _g1)){
HXLINE( 173)				_g = (_g + 1);
HXDLIN( 173)				int i = (_g - 1);
HXLINE( 175)				sourceFrame = this->sourceFrames->frames->__get(i).StaticCast<  ::flixel::graphics::frames::FlxFrame >();
HXLINE( 176)				frame = this->frames->__get(i).StaticCast<  ::flixel::graphics::frames::FlxFrame >();
HXLINE( 178)				if (fill) {
HXLINE( 179)					frame->parent->bitmap->fillRect(frame->parent->bitmap->rect,0);
            				}
HXLINE( 181)				frameOffset->setTo((( (Float)(this->widthInc) ) * ((Float)0.5)),(( (Float)(this->heightInc) ) * ((Float)0.5)));
HXLINE( 183)				sourceFrame->paint(frame->parent->bitmap,frameOffset,true,null());
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(FlxFilterFrames_obj,regenBitmaps,(void))

void FlxFilterFrames_obj::applyFilter( ::openfl::filters::BitmapFilter filter){
            	HX_STACKFRAME(&_hx_pos_741532f23a714680_188_applyFilter)
HXLINE( 189)		 ::openfl::display::BitmapData bitmap;
HXLINE( 191)		{
HXLINE( 191)			int _g = 0;
HXDLIN( 191)			::Array< ::Dynamic> _g1 = this->frames;
HXDLIN( 191)			while((_g < _g1->length)){
HXLINE( 191)				 ::flixel::graphics::frames::FlxFrame frame = _g1->__get(_g).StaticCast<  ::flixel::graphics::frames::FlxFrame >();
HXDLIN( 191)				_g = (_g + 1);
HXLINE( 193)				::flixel::graphics::frames::FlxFilterFrames_obj::point->setTo(( (Float)(0) ),( (Float)(0) ));
HXLINE( 194)				::flixel::graphics::frames::FlxFilterFrames_obj::rect->setTo(( (Float)(0) ),( (Float)(0) ),frame->sourceSize->x,frame->sourceSize->y);
HXLINE( 195)				bitmap = frame->parent->bitmap;
HXLINE( 196)				bitmap->applyFilter(bitmap,::flixel::graphics::frames::FlxFilterFrames_obj::rect,::flixel::graphics::frames::FlxFilterFrames_obj::point,filter);
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(FlxFilterFrames_obj,applyFilter,(void))

void FlxFilterFrames_obj::applyFilters(){
            	HX_STACKFRAME(&_hx_pos_741532f23a714680_202_applyFilters)
HXDLIN( 202)		int _g = 0;
HXDLIN( 202)		::Array< ::Dynamic> _g1 = this->filters;
HXDLIN( 202)		while((_g < _g1->length)){
HXDLIN( 202)			 ::openfl::filters::BitmapFilter filter = _g1->__get(_g).StaticCast<  ::openfl::filters::BitmapFilter >();
HXDLIN( 202)			_g = (_g + 1);
HXLINE( 203)			this->applyFilter(filter);
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC0(FlxFilterFrames_obj,applyFilters,(void))

void FlxFilterFrames_obj::destroy(){
            	HX_STACKFRAME(&_hx_pos_741532f23a714680_207_destroy)
HXLINE( 208)		this->sourceFrames = null();
HXLINE( 209)		this->set_filters(null());
HXLINE( 211)		{
HXLINE( 211)			int _g = 0;
HXDLIN( 211)			::Array< ::Dynamic> _g1 = this->frames;
HXDLIN( 211)			while((_g < _g1->length)){
HXLINE( 211)				 ::flixel::graphics::frames::FlxFrame frame = _g1->__get(_g).StaticCast<  ::flixel::graphics::frames::FlxFrame >();
HXDLIN( 211)				_g = (_g + 1);
HXLINE( 212)				frame->parent->destroy();
            			}
            		}
HXLINE( 214)		this->super::destroy();
            	}


::Array< ::Dynamic> FlxFilterFrames_obj::set_filters(::Array< ::Dynamic> value){
            	HX_STACKFRAME(&_hx_pos_741532f23a714680_218_set_filters)
HXLINE( 219)		this->filters = value;
HXLINE( 221)		if (::hx::IsNotNull( value )) {
HXLINE( 222)			this->regenAndApplyFilters();
            		}
HXLINE( 224)		return this->filters;
            	}


HX_DEFINE_DYNAMIC_FUNC1(FlxFilterFrames_obj,set_filters,return )

 ::openfl::geom::Point FlxFilterFrames_obj::point;

 ::openfl::geom::Rectangle FlxFilterFrames_obj::rect;

 ::flixel::graphics::frames::FlxFilterFrames FlxFilterFrames_obj::fromFrames( ::flixel::graphics::frames::FlxFramesCollection frames,::hx::Null< int >  __o_widthInc,::hx::Null< int >  __o_heightInc,::Array< ::Dynamic> filters){
            		int widthInc = __o_widthInc.Default(0);
            		int heightInc = __o_heightInc.Default(0);
            	HX_GC_STACKFRAME(&_hx_pos_741532f23a714680_33_fromFrames)
HXDLIN(  33)		return  ::flixel::graphics::frames::FlxFilterFrames_obj::__alloc( HX_CTX ,frames,widthInc,heightInc,filters);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(FlxFilterFrames_obj,fromFrames,return )


::hx::ObjectPtr< FlxFilterFrames_obj > FlxFilterFrames_obj::__new( ::flixel::graphics::frames::FlxFramesCollection sourceFrames,::hx::Null< int >  __o_widthInc,::hx::Null< int >  __o_heightInc,::Array< ::Dynamic> filters) {
	::hx::ObjectPtr< FlxFilterFrames_obj > __this = new FlxFilterFrames_obj();
	__this->__construct(sourceFrames,__o_widthInc,__o_heightInc,filters);
	return __this;
}

::hx::ObjectPtr< FlxFilterFrames_obj > FlxFilterFrames_obj::__alloc(::hx::Ctx *_hx_ctx, ::flixel::graphics::frames::FlxFramesCollection sourceFrames,::hx::Null< int >  __o_widthInc,::hx::Null< int >  __o_heightInc,::Array< ::Dynamic> filters) {
	FlxFilterFrames_obj *__this = (FlxFilterFrames_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(FlxFilterFrames_obj), true, "flixel.graphics.frames.FlxFilterFrames"));
	*(void **)__this = FlxFilterFrames_obj::_hx_vtable;
	__this->__construct(sourceFrames,__o_widthInc,__o_heightInc,filters);
	return __this;
}

FlxFilterFrames_obj::FlxFilterFrames_obj()
{
}

void FlxFilterFrames_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxFilterFrames);
	HX_MARK_MEMBER_NAME(sourceFrames,"sourceFrames");
	HX_MARK_MEMBER_NAME(widthInc,"widthInc");
	HX_MARK_MEMBER_NAME(heightInc,"heightInc");
	HX_MARK_MEMBER_NAME(filters,"filters");
	 ::flixel::graphics::frames::FlxFramesCollection_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FlxFilterFrames_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(sourceFrames,"sourceFrames");
	HX_VISIT_MEMBER_NAME(widthInc,"widthInc");
	HX_VISIT_MEMBER_NAME(heightInc,"heightInc");
	HX_VISIT_MEMBER_NAME(filters,"filters");
	 ::flixel::graphics::frames::FlxFramesCollection_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val FlxFilterFrames_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"filters") ) { return ::hx::Val( filters ); }
		if (HX_FIELD_EQ(inName,"destroy") ) { return ::hx::Val( destroy_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"widthInc") ) { return ::hx::Val( widthInc ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"heightInc") ) { return ::hx::Val( heightInc ); }
		if (HX_FIELD_EQ(inName,"genFrames") ) { return ::hx::Val( genFrames_dyn() ); }
		if (HX_FIELD_EQ(inName,"addFilter") ) { return ::hx::Val( addFilter_dyn() ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"applyFilter") ) { return ::hx::Val( applyFilter_dyn() ); }
		if (HX_FIELD_EQ(inName,"set_filters") ) { return ::hx::Val( set_filters_dyn() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"sourceFrames") ) { return ::hx::Val( sourceFrames ); }
		if (HX_FIELD_EQ(inName,"removeFilter") ) { return ::hx::Val( removeFilter_dyn() ); }
		if (HX_FIELD_EQ(inName,"clearFilters") ) { return ::hx::Val( clearFilters_dyn() ); }
		if (HX_FIELD_EQ(inName,"regenBitmaps") ) { return ::hx::Val( regenBitmaps_dyn() ); }
		if (HX_FIELD_EQ(inName,"applyFilters") ) { return ::hx::Val( applyFilters_dyn() ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"applyToSprite") ) { return ::hx::Val( applyToSprite_dyn() ); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"regenAndApplyFilters") ) { return ::hx::Val( regenAndApplyFilters_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

bool FlxFilterFrames_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"rect") ) { outValue = ( rect ); return true; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"point") ) { outValue = ( point ); return true; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"fromFrames") ) { outValue = fromFrames_dyn(); return true; }
	}
	return false;
}

::hx::Val FlxFilterFrames_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"filters") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_filters(inValue.Cast< ::Array< ::Dynamic> >()) );filters=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"widthInc") ) { widthInc=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"heightInc") ) { heightInc=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"sourceFrames") ) { sourceFrames=inValue.Cast<  ::flixel::graphics::frames::FlxFramesCollection >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool FlxFilterFrames_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"rect") ) { rect=ioValue.Cast<  ::openfl::geom::Rectangle >(); return true; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"point") ) { point=ioValue.Cast<  ::openfl::geom::Point >(); return true; }
	}
	return false;
}

void FlxFilterFrames_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("sourceFrames",e1,6a,8c,a2));
	outFields->push(HX_("widthInc",78,16,e2,af));
	outFields->push(HX_("heightInc",37,67,9a,ae));
	outFields->push(HX_("filters",bb,a1,46,09));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo FlxFilterFrames_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::flixel::graphics::frames::FlxFramesCollection */ ,(int)offsetof(FlxFilterFrames_obj,sourceFrames),HX_("sourceFrames",e1,6a,8c,a2)},
	{::hx::fsInt,(int)offsetof(FlxFilterFrames_obj,widthInc),HX_("widthInc",78,16,e2,af)},
	{::hx::fsInt,(int)offsetof(FlxFilterFrames_obj,heightInc),HX_("heightInc",37,67,9a,ae)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(FlxFilterFrames_obj,filters),HX_("filters",bb,a1,46,09)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo FlxFilterFrames_obj_sStaticStorageInfo[] = {
	{::hx::fsObject /*  ::openfl::geom::Point */ ,(void *) &FlxFilterFrames_obj::point,HX_("point",50,b4,8f,c6)},
	{::hx::fsObject /*  ::openfl::geom::Rectangle */ ,(void *) &FlxFilterFrames_obj::rect,HX_("rect",24,4d,a7,4b)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static ::String FlxFilterFrames_obj_sMemberFields[] = {
	HX_("sourceFrames",e1,6a,8c,a2),
	HX_("widthInc",78,16,e2,af),
	HX_("heightInc",37,67,9a,ae),
	HX_("filters",bb,a1,46,09),
	HX_("applyToSprite",6e,e3,09,2b),
	HX_("genFrames",56,70,5b,2f),
	HX_("addFilter",b9,54,59,3d),
	HX_("removeFilter",1c,bb,62,f4),
	HX_("clearFilters",ae,53,c5,e4),
	HX_("regenAndApplyFilters",27,91,67,08),
	HX_("regenBitmaps",67,dc,b3,10),
	HX_("applyFilter",c6,df,2f,c1),
	HX_("applyFilters",ed,ed,b3,48),
	HX_("destroy",fa,2c,86,24),
	HX_("set_filters",de,08,ae,99),
	::String(null()) };

static void FlxFilterFrames_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxFilterFrames_obj::point,"point");
	HX_MARK_MEMBER_NAME(FlxFilterFrames_obj::rect,"rect");
};

#ifdef HXCPP_VISIT_ALLOCS
static void FlxFilterFrames_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxFilterFrames_obj::point,"point");
	HX_VISIT_MEMBER_NAME(FlxFilterFrames_obj::rect,"rect");
};

#endif

::hx::Class FlxFilterFrames_obj::__mClass;

static ::String FlxFilterFrames_obj_sStaticFields[] = {
	HX_("point",50,b4,8f,c6),
	HX_("rect",24,4d,a7,4b),
	HX_("fromFrames",b0,b4,c9,ef),
	::String(null())
};

void FlxFilterFrames_obj::__register()
{
	FlxFilterFrames_obj _hx_dummy;
	FlxFilterFrames_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("flixel.graphics.frames.FlxFilterFrames",59,45,3c,01);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &FlxFilterFrames_obj::__GetStatic;
	__mClass->mSetStaticField = &FlxFilterFrames_obj::__SetStatic;
	__mClass->mMarkFunc = FlxFilterFrames_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(FlxFilterFrames_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(FlxFilterFrames_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< FlxFilterFrames_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = FlxFilterFrames_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = FlxFilterFrames_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = FlxFilterFrames_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void FlxFilterFrames_obj::__boot()
{
{
            	HX_GC_STACKFRAME(&_hx_pos_741532f23a714680_19_boot)
HXDLIN(  19)		point =  ::openfl::geom::Point_obj::__alloc( HX_CTX ,null(),null());
            	}
{
            	HX_GC_STACKFRAME(&_hx_pos_741532f23a714680_20_boot)
HXDLIN(  20)		rect =  ::openfl::geom::Rectangle_obj::__alloc( HX_CTX ,null(),null(),null(),null());
            	}
}

} // end namespace flixel
} // end namespace graphics
} // end namespace frames
