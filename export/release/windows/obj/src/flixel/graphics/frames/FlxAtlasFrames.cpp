#include <hxcpp.h>

#ifndef INCLUDED_95f339a1d026d52c
#define INCLUDED_95f339a1d026d52c
#include "hxMath.h"
#endif
#ifndef INCLUDED_Lambda
#include <Lambda.h>
#endif
#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_Xml
#include <Xml.h>
#endif
#ifndef INCLUDED__Xml_XmlType_Impl_
#include <_Xml/XmlType_Impl_.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_graphics_FlxGraphic
#include <flixel/graphics/FlxGraphic.h>
#endif
#ifndef INCLUDED_flixel_graphics_frames_FlxAtlasFrames
#include <flixel/graphics/frames/FlxAtlasFrames.h>
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
#ifndef INCLUDED_flixel_math_FlxPoint
#include <flixel/math/FlxPoint.h>
#endif
#ifndef INCLUDED_flixel_math_FlxRect
#include <flixel/math/FlxRect.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_BitmapFrontEnd
#include <flixel/system/frontEnds/BitmapFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPool_flixel_math_FlxPoint
#include <flixel/util/FlxPool_flixel_math_FlxPoint.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPool_flixel_math_FlxRect
#include <flixel/util/FlxPool_flixel_math_FlxRect.h>
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
#ifndef INCLUDED_haxe_format_JsonParser
#include <haxe/format/JsonParser.h>
#endif
#ifndef INCLUDED_haxe_xml__Access_AttribAccess_Impl_
#include <haxe/xml/_Access/AttribAccess_Impl_.h>
#endif
#ifndef INCLUDED_haxe_xml__Access_HasAttribAccess_Impl_
#include <haxe/xml/_Access/HasAttribAccess_Impl_.h>
#endif
#ifndef INCLUDED_haxe_xml__Access_NodeListAccess_Impl_
#include <haxe/xml/_Access/NodeListAccess_Impl_.h>
#endif
#ifndef INCLUDED_openfl_geom_Rectangle
#include <openfl/geom/Rectangle.h>
#endif
#ifndef INCLUDED_openfl_utils_Assets
#include <openfl/utils/Assets.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_d294561f5bda5770_24_new,"flixel.graphics.frames.FlxAtlasFrames","new",0xed20cbc8,"flixel.graphics.frames.FlxAtlasFrames.new","flixel/graphics/frames/FlxAtlasFrames.hx",24,0x501ecb67)
HX_LOCAL_STACK_FRAME(_hx_pos_d294561f5bda5770_405_addBorder,"flixel.graphics.frames.FlxAtlasFrames","addBorder",0x1a31fb55,"flixel.graphics.frames.FlxAtlasFrames.addBorder","flixel/graphics/frames/FlxAtlasFrames.hx",405,0x501ecb67)
HX_LOCAL_STACK_FRAME(_hx_pos_d294561f5bda5770_38_fromTexturePackerJson,"flixel.graphics.frames.FlxAtlasFrames","fromTexturePackerJson",0xae76e627,"flixel.graphics.frames.FlxAtlasFrames.fromTexturePackerJson","flixel/graphics/frames/FlxAtlasFrames.hx",38,0x501ecb67)
HX_LOCAL_STACK_FRAME(_hx_pos_d294561f5bda5770_97_texturePackerHelper,"flixel.graphics.frames.FlxAtlasFrames","texturePackerHelper",0x397d6e77,"flixel.graphics.frames.FlxAtlasFrames.texturePackerHelper","flixel/graphics/frames/FlxAtlasFrames.hx",97,0x501ecb67)
HX_LOCAL_STACK_FRAME(_hx_pos_d294561f5bda5770_128_fromLibGdx,"flixel.graphics.frames.FlxAtlasFrames","fromLibGdx",0x5ef5c818,"flixel.graphics.frames.FlxAtlasFrames.fromLibGdx","flixel/graphics/frames/FlxAtlasFrames.hx",128,0x501ecb67)
HX_LOCAL_STACK_FRAME(_hx_pos_d294561f5bda5770_207_getDimensions,"flixel.graphics.frames.FlxAtlasFrames","getDimensions",0x0a6267eb,"flixel.graphics.frames.FlxAtlasFrames.getDimensions","flixel/graphics/frames/FlxAtlasFrames.hx",207,0x501ecb67)
HX_LOCAL_STACK_FRAME(_hx_pos_d294561f5bda5770_228_fromSparrow,"flixel.graphics.frames.FlxAtlasFrames","fromSparrow",0x30bf432a,"flixel.graphics.frames.FlxAtlasFrames.fromSparrow","flixel/graphics/frames/FlxAtlasFrames.hx",228,0x501ecb67)
HX_LOCAL_STACK_FRAME(_hx_pos_d294561f5bda5770_293_fromTexturePackerXml,"flixel.graphics.frames.FlxAtlasFrames","fromTexturePackerXml",0x5ca98eb8,"flixel.graphics.frames.FlxAtlasFrames.fromTexturePackerXml","flixel/graphics/frames/FlxAtlasFrames.hx",293,0x501ecb67)
HX_LOCAL_STACK_FRAME(_hx_pos_d294561f5bda5770_345_fromSpriteSheetPacker,"flixel.graphics.frames.FlxAtlasFrames","fromSpriteSheetPacker",0x4fb8a81e,"flixel.graphics.frames.FlxAtlasFrames.fromSpriteSheetPacker","flixel/graphics/frames/FlxAtlasFrames.hx",345,0x501ecb67)
HX_LOCAL_STACK_FRAME(_hx_pos_d294561f5bda5770_391_findFrame,"flixel.graphics.frames.FlxAtlasFrames","findFrame",0xf36e229c,"flixel.graphics.frames.FlxAtlasFrames.findFrame","flixel/graphics/frames/FlxAtlasFrames.hx",391,0x501ecb67)
namespace flixel{
namespace graphics{
namespace frames{

void FlxAtlasFrames_obj::__construct( ::flixel::graphics::FlxGraphic parent, ::flixel::math::FlxPoint border){
            	HX_STACKFRAME(&_hx_pos_d294561f5bda5770_24_new)
HXDLIN(  24)		super::__construct(parent,::flixel::graphics::frames::FlxFrameCollectionType_obj::ATLAS_dyn(),border);
            	}

Dynamic FlxAtlasFrames_obj::__CreateEmpty() { return new FlxAtlasFrames_obj; }

void *FlxAtlasFrames_obj::_hx_vtable = 0;

Dynamic FlxAtlasFrames_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< FlxAtlasFrames_obj > _hx_result = new FlxAtlasFrames_obj();
	_hx_result->__construct(inArgs[0],inArgs[1]);
	return _hx_result;
}

bool FlxAtlasFrames_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x1ee6bdec) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x1ee6bdec;
	} else {
		return inClassId==(int)0x7907b929;
	}
}

 ::flixel::graphics::frames::FlxFramesCollection FlxAtlasFrames_obj::addBorder( ::flixel::math::FlxPoint border){
            	HX_GC_STACKFRAME(&_hx_pos_d294561f5bda5770_405_addBorder)
HXLINE( 406)		 ::flixel::math::FlxPoint point = ::flixel::math::FlxPoint_obj::_pool->get()->set(( (Float)(0) ),( (Float)(0) ));
HXDLIN( 406)		point->_inPool = false;
HXDLIN( 406)		 ::flixel::math::FlxPoint point1 = point;
HXDLIN( 406)		point1->_weak = true;
HXDLIN( 406)		 ::flixel::math::FlxPoint resultBorder = point1->addPoint(this->border)->addPoint(border);
HXLINE( 407)		 ::flixel::graphics::frames::FlxAtlasFrames atlasFrames = ::flixel::graphics::frames::FlxAtlasFrames_obj::findFrame(this->parent,resultBorder);
HXLINE( 408)		if (::hx::IsNotNull( atlasFrames )) {
HXLINE( 409)			return atlasFrames;
            		}
HXLINE( 411)		atlasFrames =  ::flixel::graphics::frames::FlxAtlasFrames_obj::__alloc( HX_CTX ,this->parent,resultBorder);
HXLINE( 413)		{
HXLINE( 413)			int _g = 0;
HXDLIN( 413)			::Array< ::Dynamic> _g1 = this->frames;
HXDLIN( 413)			while((_g < _g1->length)){
HXLINE( 413)				 ::flixel::graphics::frames::FlxFrame frame = _g1->__get(_g).StaticCast<  ::flixel::graphics::frames::FlxFrame >();
HXDLIN( 413)				_g = (_g + 1);
HXLINE( 414)				atlasFrames->pushFrame(frame->setBorderTo(border,null()));
            			}
            		}
HXLINE( 416)		return atlasFrames;
            	}


 ::flixel::graphics::frames::FlxAtlasFrames FlxAtlasFrames_obj::fromTexturePackerJson( ::Dynamic Source, ::Dynamic Description){
            	HX_GC_STACKFRAME(&_hx_pos_d294561f5bda5770_38_fromTexturePackerJson)
HXLINE(  39)		 ::flixel::graphics::FlxGraphic graphic = ::flixel::FlxG_obj::bitmap->add(Source,false,null());
HXLINE(  40)		if (::hx::IsNull( graphic )) {
HXLINE(  41)			return null();
            		}
HXLINE(  44)		 ::flixel::graphics::frames::FlxAtlasFrames frames = ::flixel::graphics::frames::FlxAtlasFrames_obj::findFrame(graphic,null());
HXLINE(  45)		if (::hx::IsNotNull( frames )) {
HXLINE(  46)			return frames;
            		}
HXLINE(  48)		bool _hx_tmp;
HXDLIN(  48)		if (::hx::IsNotNull( graphic )) {
HXLINE(  48)			_hx_tmp = ::hx::IsNull( Description );
            		}
            		else {
HXLINE(  48)			_hx_tmp = true;
            		}
HXDLIN(  48)		if (_hx_tmp) {
HXLINE(  49)			return null();
            		}
HXLINE(  51)		frames =  ::flixel::graphics::frames::FlxAtlasFrames_obj::__alloc( HX_CTX ,graphic,null());
HXLINE(  53)		 ::Dynamic data;
HXLINE(  55)		if (::Std_obj::isOfType(Description,::hx::ClassOf< ::String >())) {
HXLINE(  57)			::String json = ( (::String)(Description) );
HXLINE(  59)			if (::openfl::utils::Assets_obj::exists(json,null())) {
HXLINE(  60)				json = ::openfl::utils::Assets_obj::getText(json);
            			}
HXLINE(  62)			data =  ::haxe::format::JsonParser_obj::__alloc( HX_CTX ,json)->doParse();
            		}
            		else {
HXLINE(  66)			data = Description;
            		}
HXLINE(  70)		if (::Std_obj::isOfType( ::Dynamic(data->__Field(HX_("frames",a6,af,85,ac),::hx::paccDynamic)),::hx::ArrayBase::__mClass)) {
HXLINE(  72)			int _g = 0;
HXDLIN(  72)			::Array< ::Dynamic> _g1 = ::Lambda_obj::array(data->__Field(HX_("frames",a6,af,85,ac),::hx::paccDynamic));
HXDLIN(  72)			while((_g < _g1->length)){
HXLINE(  72)				 ::Dynamic frame = _g1->__get(_g);
HXDLIN(  72)				_g = (_g + 1);
HXLINE(  74)				::flixel::graphics::frames::FlxAtlasFrames_obj::texturePackerHelper(( (::String)(frame->__Field(HX_("filename",c7,2e,6a,77),::hx::paccDynamic)) ),frame,frames);
            			}
            		}
            		else {
HXLINE(  80)			int _g = 0;
HXDLIN(  80)			::Array< ::String > _g1 = ::Reflect_obj::fields( ::Dynamic(data->__Field(HX_("frames",a6,af,85,ac),::hx::paccDynamic)));
HXDLIN(  80)			while((_g < _g1->length)){
HXLINE(  80)				::String frameName = _g1->__get(_g);
HXDLIN(  80)				_g = (_g + 1);
HXLINE(  82)				::flixel::graphics::frames::FlxAtlasFrames_obj::texturePackerHelper(frameName,::Reflect_obj::field( ::Dynamic(data->__Field(HX_("frames",a6,af,85,ac),::hx::paccDynamic)),frameName),frames);
            			}
            		}
HXLINE(  86)		return frames;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FlxAtlasFrames_obj,fromTexturePackerJson,return )

void FlxAtlasFrames_obj::texturePackerHelper(::String FrameName, ::Dynamic FrameData, ::flixel::graphics::frames::FlxAtlasFrames Frames){
            	HX_STACKFRAME(&_hx_pos_d294561f5bda5770_97_texturePackerHelper)
HXLINE(  98)		bool rotated = ( (bool)(FrameData->__Field(HX_("rotated",a9,49,1d,f1),::hx::paccDynamic)) );
HXLINE(  99)		::String name = FrameName;
HXLINE( 100)		Float X = ( (Float)( ::Dynamic(FrameData->__Field(HX_("sourceSize",3c,87,b7,74),::hx::paccDynamic))->__Field(HX_("w",77,00,00,00),::hx::paccDynamic)) );
HXDLIN( 100)		Float Y = ( (Float)( ::Dynamic(FrameData->__Field(HX_("sourceSize",3c,87,b7,74),::hx::paccDynamic))->__Field(HX_("h",68,00,00,00),::hx::paccDynamic)) );
HXDLIN( 100)		 ::flixel::math::FlxPoint point = ::flixel::math::FlxPoint_obj::_pool->get()->set(X,Y);
HXDLIN( 100)		point->_inPool = false;
HXDLIN( 100)		 ::flixel::math::FlxPoint sourceSize = point;
HXLINE( 101)		Float X1 = ( (Float)( ::Dynamic(FrameData->__Field(HX_("spriteSourceSize",a1,7f,c1,03),::hx::paccDynamic))->__Field(HX_("x",78,00,00,00),::hx::paccDynamic)) );
HXDLIN( 101)		Float Y1 = ( (Float)( ::Dynamic(FrameData->__Field(HX_("spriteSourceSize",a1,7f,c1,03),::hx::paccDynamic))->__Field(HX_("y",79,00,00,00),::hx::paccDynamic)) );
HXDLIN( 101)		 ::flixel::math::FlxPoint point1 = ::flixel::math::FlxPoint_obj::_pool->get()->set(X1,Y1);
HXDLIN( 101)		point1->_inPool = false;
HXDLIN( 101)		 ::flixel::math::FlxPoint offset = point1;
HXLINE( 102)		int angle = 0;
HXLINE( 103)		 ::flixel::math::FlxRect frameRect = null();
HXLINE( 105)		if (rotated) {
HXLINE( 107)			Float X = ( (Float)( ::Dynamic(FrameData->__Field(HX_("frame",2d,78,83,06),::hx::paccDynamic))->__Field(HX_("x",78,00,00,00),::hx::paccDynamic)) );
HXDLIN( 107)			Float Y = ( (Float)( ::Dynamic(FrameData->__Field(HX_("frame",2d,78,83,06),::hx::paccDynamic))->__Field(HX_("y",79,00,00,00),::hx::paccDynamic)) );
HXDLIN( 107)			Float Width = ( (Float)( ::Dynamic(FrameData->__Field(HX_("frame",2d,78,83,06),::hx::paccDynamic))->__Field(HX_("h",68,00,00,00),::hx::paccDynamic)) );
HXDLIN( 107)			Float Height = ( (Float)( ::Dynamic(FrameData->__Field(HX_("frame",2d,78,83,06),::hx::paccDynamic))->__Field(HX_("w",77,00,00,00),::hx::paccDynamic)) );
HXDLIN( 107)			 ::flixel::math::FlxRect _this = ::flixel::math::FlxRect_obj::_pool->get();
HXDLIN( 107)			_this->x = X;
HXDLIN( 107)			_this->y = Y;
HXDLIN( 107)			_this->width = Width;
HXDLIN( 107)			_this->height = Height;
HXDLIN( 107)			 ::flixel::math::FlxRect rect = _this;
HXDLIN( 107)			rect->_inPool = false;
HXDLIN( 107)			frameRect = rect;
HXLINE( 108)			angle = -90;
            		}
            		else {
HXLINE( 112)			Float X = ( (Float)( ::Dynamic(FrameData->__Field(HX_("frame",2d,78,83,06),::hx::paccDynamic))->__Field(HX_("x",78,00,00,00),::hx::paccDynamic)) );
HXDLIN( 112)			Float Y = ( (Float)( ::Dynamic(FrameData->__Field(HX_("frame",2d,78,83,06),::hx::paccDynamic))->__Field(HX_("y",79,00,00,00),::hx::paccDynamic)) );
HXDLIN( 112)			Float Width = ( (Float)( ::Dynamic(FrameData->__Field(HX_("frame",2d,78,83,06),::hx::paccDynamic))->__Field(HX_("w",77,00,00,00),::hx::paccDynamic)) );
HXDLIN( 112)			Float Height = ( (Float)( ::Dynamic(FrameData->__Field(HX_("frame",2d,78,83,06),::hx::paccDynamic))->__Field(HX_("h",68,00,00,00),::hx::paccDynamic)) );
HXDLIN( 112)			 ::flixel::math::FlxRect _this = ::flixel::math::FlxRect_obj::_pool->get();
HXDLIN( 112)			_this->x = X;
HXDLIN( 112)			_this->y = Y;
HXDLIN( 112)			_this->width = Width;
HXDLIN( 112)			_this->height = Height;
HXDLIN( 112)			 ::flixel::math::FlxRect rect = _this;
HXDLIN( 112)			rect->_inPool = false;
HXDLIN( 112)			frameRect = rect;
            		}
HXLINE( 115)		Frames->addAtlasFrame(frameRect,sourceSize,offset,name,angle,null(),null());
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FlxAtlasFrames_obj,texturePackerHelper,(void))

 ::flixel::graphics::frames::FlxAtlasFrames FlxAtlasFrames_obj::fromLibGdx( ::Dynamic source,::String description){
            	HX_GC_STACKFRAME(&_hx_pos_d294561f5bda5770_128_fromLibGdx)
HXLINE( 129)		 ::flixel::graphics::FlxGraphic graphic = ::flixel::FlxG_obj::bitmap->add(source,null(),null());
HXLINE( 130)		if (::hx::IsNull( graphic )) {
HXLINE( 131)			return null();
            		}
HXLINE( 134)		 ::flixel::graphics::frames::FlxAtlasFrames frames = ::flixel::graphics::frames::FlxAtlasFrames_obj::findFrame(graphic,null());
HXLINE( 135)		if (::hx::IsNotNull( frames )) {
HXLINE( 136)			return frames;
            		}
HXLINE( 138)		bool _hx_tmp;
HXDLIN( 138)		if (::hx::IsNotNull( graphic )) {
HXLINE( 138)			_hx_tmp = ::hx::IsNull( description );
            		}
            		else {
HXLINE( 138)			_hx_tmp = true;
            		}
HXDLIN( 138)		if (_hx_tmp) {
HXLINE( 139)			return null();
            		}
HXLINE( 141)		frames =  ::flixel::graphics::frames::FlxAtlasFrames_obj::__alloc( HX_CTX ,graphic,null());
HXLINE( 143)		if (::openfl::utils::Assets_obj::exists(description,null())) {
HXLINE( 144)			description = ::openfl::utils::Assets_obj::getText(description);
            		}
HXLINE( 146)		::String pack = ::StringTools_obj::trim(description);
HXLINE( 147)		::Array< ::String > lines = pack.split(HX_("\n",0a,00,00,00));
HXLINE( 150)		int repeatLine;
HXDLIN( 150)		if ((lines->__get(3).indexOf(HX_("repeat:",7f,d8,87,a6),null()) > -1)) {
HXLINE( 150)			repeatLine = 3;
            		}
            		else {
HXLINE( 150)			repeatLine = 4;
            		}
HXLINE( 151)		lines->removeRange(0,(repeatLine + 1));
HXLINE( 153)		int numElementsPerImage = 7;
HXLINE( 154)		int numImages = ::Std_obj::_hx_int((( (Float)(lines->length) ) / ( (Float)(numElementsPerImage) )));
HXLINE( 156)		{
HXLINE( 156)			int _g = 0;
HXDLIN( 156)			int _g1 = numImages;
HXDLIN( 156)			while((_g < _g1)){
HXLINE( 156)				_g = (_g + 1);
HXDLIN( 156)				int i = (_g - 1);
HXLINE( 158)				int curIndex = (i * numElementsPerImage);
HXLINE( 160)				curIndex = (curIndex + 1);
HXDLIN( 160)				::String name = lines->__get((curIndex - 1));
HXLINE( 161)				curIndex = (curIndex + 1);
HXDLIN( 161)				bool rotated = (lines->__get((curIndex - 1)).indexOf(HX_("true",4e,a7,03,4d),null()) >= 0);
HXLINE( 162)				int angle;
HXDLIN( 162)				if (rotated) {
HXLINE( 162)					angle = 90;
            				}
            				else {
HXLINE( 162)					angle = 0;
            				}
HXLINE( 164)				curIndex = (curIndex + 1);
HXDLIN( 164)				::String tempString = lines->__get((curIndex - 1));
HXLINE( 165)				 ::Dynamic size = ::flixel::graphics::frames::FlxAtlasFrames_obj::getDimensions(tempString);
HXLINE( 167)				int imageX = ( (int)(size->__Field(HX_("x",78,00,00,00),::hx::paccDynamic)) );
HXLINE( 168)				int imageY = ( (int)(size->__Field(HX_("y",79,00,00,00),::hx::paccDynamic)) );
HXLINE( 170)				curIndex = (curIndex + 1);
HXDLIN( 170)				tempString = lines->__get((curIndex - 1));
HXLINE( 171)				size = ::flixel::graphics::frames::FlxAtlasFrames_obj::getDimensions(tempString);
HXLINE( 173)				int imageWidth = ( (int)(size->__Field(HX_("x",78,00,00,00),::hx::paccDynamic)) );
HXLINE( 174)				int imageHeight = ( (int)(size->__Field(HX_("y",79,00,00,00),::hx::paccDynamic)) );
HXLINE( 176)				 ::flixel::math::FlxRect _this = ::flixel::math::FlxRect_obj::_pool->get();
HXDLIN( 176)				_this->x = ( (Float)(imageX) );
HXDLIN( 176)				_this->y = ( (Float)(imageY) );
HXDLIN( 176)				_this->width = ( (Float)(imageWidth) );
HXDLIN( 176)				_this->height = ( (Float)(imageHeight) );
HXDLIN( 176)				 ::flixel::math::FlxRect rect = _this;
HXDLIN( 176)				rect->_inPool = false;
HXDLIN( 176)				 ::flixel::math::FlxRect rect1 = rect;
HXLINE( 178)				curIndex = (curIndex + 1);
HXDLIN( 178)				tempString = lines->__get((curIndex - 1));
HXLINE( 179)				size = ::flixel::graphics::frames::FlxAtlasFrames_obj::getDimensions(tempString);
HXLINE( 181)				Float X = ( (Float)(size->__Field(HX_("x",78,00,00,00),::hx::paccDynamic)) );
HXDLIN( 181)				Float Y = ( (Float)(size->__Field(HX_("y",79,00,00,00),::hx::paccDynamic)) );
HXDLIN( 181)				 ::flixel::math::FlxPoint point = ::flixel::math::FlxPoint_obj::_pool->get()->set(X,Y);
HXDLIN( 181)				point->_inPool = false;
HXDLIN( 181)				 ::flixel::math::FlxPoint sourceSize = point;
HXLINE( 183)				curIndex = (curIndex + 1);
HXDLIN( 183)				tempString = lines->__get((curIndex - 1));
HXLINE( 184)				size = ::flixel::graphics::frames::FlxAtlasFrames_obj::getDimensions(tempString);
HXLINE( 186)				curIndex = (curIndex + 1);
HXDLIN( 186)				tempString = lines->__get((curIndex - 1));
HXLINE( 187)				 ::Dynamic index = ::Std_obj::parseInt(tempString.split(HX_(":",3a,00,00,00))->__get(1));
HXLINE( 189)				if (::hx::IsNotEq( index,-1 )) {
HXLINE( 190)					name = (name + (HX_("_",5f,00,00,00) + index));
            				}
HXLINE( 196)				Float X1 = ( (Float)(size->__Field(HX_("x",78,00,00,00),::hx::paccDynamic)) );
HXDLIN( 196)				Float Y1 = ((sourceSize->y - ( (Float)(size->__Field(HX_("y",79,00,00,00),::hx::paccDynamic)) )) - ( (Float)(imageHeight) ));
HXDLIN( 196)				 ::flixel::math::FlxPoint point1 = ::flixel::math::FlxPoint_obj::_pool->get()->set(X1,Y1);
HXDLIN( 196)				point1->_inPool = false;
HXDLIN( 196)				 ::flixel::math::FlxPoint offset = point1;
HXLINE( 197)				frames->addAtlasFrame(rect1,sourceSize,offset,name,angle,null(),null());
            			}
            		}
HXLINE( 200)		return frames;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FlxAtlasFrames_obj,fromLibGdx,return )

 ::Dynamic FlxAtlasFrames_obj::getDimensions(::String line){
            	HX_STACKFRAME(&_hx_pos_d294561f5bda5770_207_getDimensions)
HXLINE( 208)		int colonPosition = line.indexOf(HX_(":",3a,00,00,00),null());
HXLINE( 209)		int comaPosition = line.indexOf(HX_(",",2c,00,00,00),null());
HXLINE( 212)		 ::Dynamic _hx_tmp = ::Std_obj::parseInt(line.substring((colonPosition + 1),comaPosition));
HXLINE( 211)		return  ::Dynamic(::hx::Anon_obj::Create(2)
            			->setFixed(0,HX_("x",78,00,00,00),_hx_tmp)
            			->setFixed(1,HX_("y",79,00,00,00),::Std_obj::parseInt(line.substring((comaPosition + 1),line.length))));
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxAtlasFrames_obj,getDimensions,return )

 ::flixel::graphics::frames::FlxAtlasFrames FlxAtlasFrames_obj::fromSparrow( ::Dynamic Source,::String Description){
            	HX_GC_STACKFRAME(&_hx_pos_d294561f5bda5770_228_fromSparrow)
HXLINE( 229)		 ::flixel::graphics::FlxGraphic graphic = ::flixel::FlxG_obj::bitmap->add(Source,null(),null());
HXLINE( 230)		if (::hx::IsNull( graphic )) {
HXLINE( 231)			return null();
            		}
HXLINE( 234)		 ::flixel::graphics::frames::FlxAtlasFrames frames = ::flixel::graphics::frames::FlxAtlasFrames_obj::findFrame(graphic,null());
HXLINE( 235)		if (::hx::IsNotNull( frames )) {
HXLINE( 236)			return frames;
            		}
HXLINE( 238)		bool _hx_tmp;
HXDLIN( 238)		if (::hx::IsNotNull( graphic )) {
HXLINE( 238)			_hx_tmp = ::hx::IsNull( Description );
            		}
            		else {
HXLINE( 238)			_hx_tmp = true;
            		}
HXDLIN( 238)		if (_hx_tmp) {
HXLINE( 239)			return null();
            		}
HXLINE( 241)		frames =  ::flixel::graphics::frames::FlxAtlasFrames_obj::__alloc( HX_CTX ,graphic,null());
HXLINE( 243)		if (::openfl::utils::Assets_obj::exists(Description,null())) {
HXLINE( 244)			Description = ::openfl::utils::Assets_obj::getText(Description);
            		}
HXLINE( 246)		 ::Xml x = ::Xml_obj::parse(Description)->firstElement();
HXDLIN( 246)		bool _hx_tmp1;
HXDLIN( 246)		if ((x->nodeType != ::Xml_obj::Document)) {
HXLINE( 246)			_hx_tmp1 = (x->nodeType != ::Xml_obj::Element);
            		}
            		else {
HXLINE( 246)			_hx_tmp1 = false;
            		}
HXDLIN( 246)		if (_hx_tmp1) {
HXLINE( 246)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Invalid nodeType ",3b,e0,cb,e1) + ::_Xml::XmlType_Impl__obj::toString(x->nodeType))));
            		}
HXDLIN( 246)		 ::Xml this1 = x;
HXDLIN( 246)		 ::Xml data = this1;
HXLINE( 248)		{
HXLINE( 248)			int _g = 0;
HXDLIN( 248)			::Array< ::Dynamic> _g1 = ::haxe::xml::_Access::NodeListAccess_Impl__obj::resolve(data,HX_("SubTexture",5b,7b,fb,11));
HXDLIN( 248)			while((_g < _g1->length)){
HXLINE( 248)				 ::Xml texture = _g1->__get(_g).StaticCast<  ::Xml >();
HXDLIN( 248)				_g = (_g + 1);
HXLINE( 250)				::String name = ::haxe::xml::_Access::AttribAccess_Impl__obj::resolve(texture,HX_("name",4b,72,ff,48));
HXLINE( 251)				bool trimmed = ::haxe::xml::_Access::HasAttribAccess_Impl__obj::resolve(texture,HX_("frameX",8b,af,85,ac));
HXLINE( 252)				bool rotated;
HXDLIN( 252)				if (::haxe::xml::_Access::HasAttribAccess_Impl__obj::resolve(texture,HX_("rotated",a9,49,1d,f1))) {
HXLINE( 252)					rotated = (::haxe::xml::_Access::AttribAccess_Impl__obj::resolve(texture,HX_("rotated",a9,49,1d,f1)) == HX_("true",4e,a7,03,4d));
            				}
            				else {
HXLINE( 252)					rotated = false;
            				}
HXLINE( 253)				bool flipX;
HXDLIN( 253)				if (::haxe::xml::_Access::HasAttribAccess_Impl__obj::resolve(texture,HX_("flipX",0b,45,92,02))) {
HXLINE( 253)					flipX = (::haxe::xml::_Access::AttribAccess_Impl__obj::resolve(texture,HX_("flipX",0b,45,92,02)) == HX_("true",4e,a7,03,4d));
            				}
            				else {
HXLINE( 253)					flipX = false;
            				}
HXLINE( 254)				bool flipY;
HXDLIN( 254)				if (::haxe::xml::_Access::HasAttribAccess_Impl__obj::resolve(texture,HX_("flipY",0c,45,92,02))) {
HXLINE( 254)					flipY = (::haxe::xml::_Access::AttribAccess_Impl__obj::resolve(texture,HX_("flipY",0c,45,92,02)) == HX_("true",4e,a7,03,4d));
            				}
            				else {
HXLINE( 254)					flipY = false;
            				}
HXLINE( 256)				Float X = ::Std_obj::parseFloat(::haxe::xml::_Access::AttribAccess_Impl__obj::resolve(texture,HX_("x",78,00,00,00)));
HXDLIN( 256)				Float Y = ::Std_obj::parseFloat(::haxe::xml::_Access::AttribAccess_Impl__obj::resolve(texture,HX_("y",79,00,00,00)));
HXDLIN( 256)				Float Width = ::Std_obj::parseFloat(::haxe::xml::_Access::AttribAccess_Impl__obj::resolve(texture,HX_("width",06,b6,62,ca)));
HXDLIN( 256)				Float Height = ::Std_obj::parseFloat(::haxe::xml::_Access::AttribAccess_Impl__obj::resolve(texture,HX_("height",e7,07,4c,02)));
HXDLIN( 256)				 ::flixel::math::FlxRect _this = ::flixel::math::FlxRect_obj::_pool->get();
HXDLIN( 256)				_this->x = X;
HXDLIN( 256)				_this->y = Y;
HXDLIN( 256)				_this->width = Width;
HXDLIN( 256)				_this->height = Height;
HXDLIN( 256)				 ::flixel::math::FlxRect rect = _this;
HXDLIN( 256)				rect->_inPool = false;
HXDLIN( 256)				 ::flixel::math::FlxRect rect1 = rect;
HXLINE( 259)				 ::openfl::geom::Rectangle size;
HXDLIN( 259)				if (trimmed) {
HXLINE( 261)					 ::Dynamic size1 = ::Std_obj::parseInt(::haxe::xml::_Access::AttribAccess_Impl__obj::resolve(texture,HX_("frameX",8b,af,85,ac)));
HXDLIN( 261)					 ::Dynamic size2 = ::Std_obj::parseInt(::haxe::xml::_Access::AttribAccess_Impl__obj::resolve(texture,HX_("frameY",8c,af,85,ac)));
HXDLIN( 261)					 ::Dynamic size3 = ::Std_obj::parseInt(::haxe::xml::_Access::AttribAccess_Impl__obj::resolve(texture,HX_("frameWidth",99,ea,88,ad)));
HXLINE( 259)					size =  ::openfl::geom::Rectangle_obj::__alloc( HX_CTX ,size1,size2,size3,::Std_obj::parseInt(::haxe::xml::_Access::AttribAccess_Impl__obj::resolve(texture,HX_("frameHeight",f4,d3,93,e0))));
            				}
            				else {
HXLINE( 259)					size =  ::openfl::geom::Rectangle_obj::__alloc( HX_CTX ,0,0,rect1->width,rect1->height);
            				}
HXLINE( 269)				int angle;
HXDLIN( 269)				if (rotated) {
HXLINE( 269)					angle = -90;
            				}
            				else {
HXLINE( 269)					angle = 0;
            				}
HXLINE( 271)				Float X1 = -(size->get_left());
HXDLIN( 271)				Float Y1 = -(size->get_top());
HXDLIN( 271)				 ::flixel::math::FlxPoint point = ::flixel::math::FlxPoint_obj::_pool->get()->set(X1,Y1);
HXDLIN( 271)				point->_inPool = false;
HXDLIN( 271)				 ::flixel::math::FlxPoint offset = point;
HXLINE( 272)				Float X2 = size->width;
HXDLIN( 272)				Float Y2 = size->height;
HXDLIN( 272)				 ::flixel::math::FlxPoint point1 = ::flixel::math::FlxPoint_obj::_pool->get()->set(X2,Y2);
HXDLIN( 272)				point1->_inPool = false;
HXDLIN( 272)				 ::flixel::math::FlxPoint sourceSize = point1;
HXLINE( 274)				bool _hx_tmp;
HXDLIN( 274)				if (rotated) {
HXLINE( 274)					_hx_tmp = !(trimmed);
            				}
            				else {
HXLINE( 274)					_hx_tmp = false;
            				}
HXDLIN( 274)				if (_hx_tmp) {
HXLINE( 275)					sourceSize->set(size->height,size->width);
            				}
HXLINE( 277)				frames->addAtlasFrame(rect1,sourceSize,offset,name,angle,flipX,flipY);
            			}
            		}
HXLINE( 280)		return frames;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FlxAtlasFrames_obj,fromSparrow,return )

 ::flixel::graphics::frames::FlxAtlasFrames FlxAtlasFrames_obj::fromTexturePackerXml( ::Dynamic Source,::String Description){
            	HX_GC_STACKFRAME(&_hx_pos_d294561f5bda5770_293_fromTexturePackerXml)
HXLINE( 294)		 ::flixel::graphics::FlxGraphic graphic = ::flixel::FlxG_obj::bitmap->add(Source,false,null());
HXLINE( 295)		if (::hx::IsNull( graphic )) {
HXLINE( 296)			return null();
            		}
HXLINE( 299)		 ::flixel::graphics::frames::FlxAtlasFrames frames = ::flixel::graphics::frames::FlxAtlasFrames_obj::findFrame(graphic,null());
HXLINE( 300)		if (::hx::IsNotNull( frames )) {
HXLINE( 301)			return frames;
            		}
HXLINE( 303)		bool _hx_tmp;
HXDLIN( 303)		if (::hx::IsNotNull( graphic )) {
HXLINE( 303)			_hx_tmp = ::hx::IsNull( Description );
            		}
            		else {
HXLINE( 303)			_hx_tmp = true;
            		}
HXDLIN( 303)		if (_hx_tmp) {
HXLINE( 304)			return null();
            		}
HXLINE( 306)		frames =  ::flixel::graphics::frames::FlxAtlasFrames_obj::__alloc( HX_CTX ,graphic,null());
HXLINE( 308)		if (::openfl::utils::Assets_obj::exists(Description,null())) {
HXLINE( 309)			Description = ::openfl::utils::Assets_obj::getText(Description);
            		}
HXLINE( 311)		 ::Xml xml = ::Xml_obj::parse(Description);
HXLINE( 313)		{
HXLINE( 313)			 ::Dynamic sprite = xml->firstElement()->elements();
HXDLIN( 313)			while(( (bool)(sprite->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE( 313)				 ::Xml sprite1 = ( ( ::Xml)(sprite->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXLINE( 315)				bool trimmed;
HXDLIN( 315)				if (!(sprite1->exists(HX_("oX",09,61,00,00)))) {
HXLINE( 315)					trimmed = sprite1->exists(HX_("oY",0a,61,00,00));
            				}
            				else {
HXLINE( 315)					trimmed = true;
            				}
HXLINE( 316)				bool rotated;
HXDLIN( 316)				if (sprite1->exists(HX_("r",72,00,00,00))) {
HXLINE( 316)					rotated = (sprite1->get(HX_("r",72,00,00,00)) == HX_("y",79,00,00,00));
            				}
            				else {
HXLINE( 316)					rotated = false;
            				}
HXLINE( 317)				int angle;
HXDLIN( 317)				if (rotated) {
HXLINE( 317)					angle = -90;
            				}
            				else {
HXLINE( 317)					angle = 0;
            				}
HXLINE( 318)				::String name = sprite1->get(HX_("n",6e,00,00,00));
HXLINE( 319)				 ::flixel::math::FlxPoint point = ::flixel::math::FlxPoint_obj::_pool->get()->set(0,0);
HXDLIN( 319)				point->_inPool = false;
HXDLIN( 319)				 ::flixel::math::FlxPoint offset = point;
HXLINE( 320)				Float X = ( (Float)(::Std_obj::parseInt(sprite1->get(HX_("x",78,00,00,00)))) );
HXDLIN( 320)				Float Y = ( (Float)(::Std_obj::parseInt(sprite1->get(HX_("y",79,00,00,00)))) );
HXDLIN( 320)				Float Width = ( (Float)(::Std_obj::parseInt(sprite1->get(HX_("w",77,00,00,00)))) );
HXDLIN( 320)				Float Height = ( (Float)(::Std_obj::parseInt(sprite1->get(HX_("h",68,00,00,00)))) );
HXDLIN( 320)				 ::flixel::math::FlxRect _this = ::flixel::math::FlxRect_obj::_pool->get();
HXDLIN( 320)				_this->x = X;
HXDLIN( 320)				_this->y = Y;
HXDLIN( 320)				_this->width = Width;
HXDLIN( 320)				_this->height = Height;
HXDLIN( 320)				 ::flixel::math::FlxRect rect = _this;
HXDLIN( 320)				rect->_inPool = false;
HXDLIN( 320)				 ::flixel::math::FlxRect rect1 = rect;
HXLINE( 321)				Float X1 = rect1->width;
HXDLIN( 321)				Float Y1 = rect1->height;
HXDLIN( 321)				 ::flixel::math::FlxPoint point1 = ::flixel::math::FlxPoint_obj::_pool->get()->set(X1,Y1);
HXDLIN( 321)				point1->_inPool = false;
HXDLIN( 321)				 ::flixel::math::FlxPoint sourceSize = point1;
HXLINE( 323)				if (trimmed) {
HXLINE( 325)					 ::Dynamic _hx_tmp = ::Std_obj::parseInt(sprite1->get(HX_("oX",09,61,00,00)));
HXDLIN( 325)					offset->set(_hx_tmp,::Std_obj::parseInt(sprite1->get(HX_("oY",0a,61,00,00))));
HXLINE( 326)					 ::Dynamic _hx_tmp1 = ::Std_obj::parseInt(sprite1->get(HX_("oW",08,61,00,00)));
HXDLIN( 326)					sourceSize->set(_hx_tmp1,::Std_obj::parseInt(sprite1->get(HX_("oH",f9,60,00,00))));
            				}
HXLINE( 329)				frames->addAtlasFrame(rect1,sourceSize,offset,name,angle,null(),null());
            			}
            		}
HXLINE( 332)		return frames;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FlxAtlasFrames_obj,fromTexturePackerXml,return )

 ::flixel::graphics::frames::FlxAtlasFrames FlxAtlasFrames_obj::fromSpriteSheetPacker( ::Dynamic Source,::String Description){
            	HX_GC_STACKFRAME(&_hx_pos_d294561f5bda5770_345_fromSpriteSheetPacker)
HXLINE( 346)		 ::flixel::graphics::FlxGraphic graphic = ::flixel::FlxG_obj::bitmap->add(Source,null(),null());
HXLINE( 347)		if (::hx::IsNull( graphic )) {
HXLINE( 348)			return null();
            		}
HXLINE( 351)		 ::flixel::graphics::frames::FlxAtlasFrames frames = ::flixel::graphics::frames::FlxAtlasFrames_obj::findFrame(graphic,null());
HXLINE( 352)		if (::hx::IsNotNull( frames )) {
HXLINE( 353)			return frames;
            		}
HXLINE( 355)		bool _hx_tmp;
HXDLIN( 355)		if (::hx::IsNotNull( graphic )) {
HXLINE( 355)			_hx_tmp = ::hx::IsNull( Description );
            		}
            		else {
HXLINE( 355)			_hx_tmp = true;
            		}
HXDLIN( 355)		if (_hx_tmp) {
HXLINE( 356)			return null();
            		}
HXLINE( 358)		frames =  ::flixel::graphics::frames::FlxAtlasFrames_obj::__alloc( HX_CTX ,graphic,null());
HXLINE( 360)		if (::openfl::utils::Assets_obj::exists(Description,null())) {
HXLINE( 361)			Description = ::openfl::utils::Assets_obj::getText(Description);
            		}
HXLINE( 363)		::String pack = ::StringTools_obj::trim(Description);
HXLINE( 364)		::Array< ::String > lines = pack.split(HX_("\n",0a,00,00,00));
HXLINE( 366)		{
HXLINE( 366)			int _g = 0;
HXDLIN( 366)			int _g1 = lines->length;
HXDLIN( 366)			while((_g < _g1)){
HXLINE( 366)				_g = (_g + 1);
HXDLIN( 366)				int i = (_g - 1);
HXLINE( 368)				::Array< ::String > currImageData = lines->__get(i).split(HX_("=",3d,00,00,00));
HXLINE( 369)				::String name = ::StringTools_obj::trim(currImageData->__get(0));
HXLINE( 370)				::Array< ::String > currImageRegion = ::StringTools_obj::trim(currImageData->__get(1)).split(HX_(" ",20,00,00,00));
HXLINE( 372)				Float X = ( (Float)(::Std_obj::parseInt(currImageRegion->__get(0))) );
HXDLIN( 372)				Float Y = ( (Float)(::Std_obj::parseInt(currImageRegion->__get(1))) );
HXDLIN( 372)				Float Width = ( (Float)(::Std_obj::parseInt(currImageRegion->__get(2))) );
HXDLIN( 372)				Float Height = ( (Float)(::Std_obj::parseInt(currImageRegion->__get(3))) );
HXDLIN( 372)				 ::flixel::math::FlxRect _this = ::flixel::math::FlxRect_obj::_pool->get();
HXDLIN( 372)				_this->x = X;
HXDLIN( 372)				_this->y = Y;
HXDLIN( 372)				_this->width = Width;
HXDLIN( 372)				_this->height = Height;
HXDLIN( 372)				 ::flixel::math::FlxRect rect = _this;
HXDLIN( 372)				rect->_inPool = false;
HXDLIN( 372)				 ::flixel::math::FlxRect rect1 = rect;
HXLINE( 374)				Float X1 = rect1->width;
HXDLIN( 374)				Float Y1 = rect1->height;
HXDLIN( 374)				 ::flixel::math::FlxPoint point = ::flixel::math::FlxPoint_obj::_pool->get()->set(X1,Y1);
HXDLIN( 374)				point->_inPool = false;
HXDLIN( 374)				 ::flixel::math::FlxPoint sourceSize = point;
HXLINE( 375)				 ::flixel::math::FlxPoint point1 = ::flixel::math::FlxPoint_obj::_pool->get()->set(( (Float)(0) ),( (Float)(0) ));
HXDLIN( 375)				point1->_inPool = false;
HXDLIN( 375)				 ::flixel::math::FlxPoint offset = point1;
HXLINE( 377)				frames->addAtlasFrame(rect1,sourceSize,offset,name,0,null(),null());
            			}
            		}
HXLINE( 380)		return frames;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FlxAtlasFrames_obj,fromSpriteSheetPacker,return )

 ::flixel::graphics::frames::FlxAtlasFrames FlxAtlasFrames_obj::findFrame( ::flixel::graphics::FlxGraphic graphic, ::flixel::math::FlxPoint border){
            	HX_STACKFRAME(&_hx_pos_d294561f5bda5770_391_findFrame)
HXLINE( 392)		if (::hx::IsNull( border )) {
HXLINE( 393)			 ::flixel::math::FlxPoint point = ::flixel::math::FlxPoint_obj::_pool->get()->set(( (Float)(0) ),( (Float)(0) ));
HXDLIN( 393)			point->_inPool = false;
HXDLIN( 393)			 ::flixel::math::FlxPoint point1 = point;
HXDLIN( 393)			point1->_weak = true;
HXDLIN( 393)			border = point1;
            		}
HXLINE( 395)		 ::flixel::graphics::frames::FlxFrameCollectionType type = ::flixel::graphics::frames::FlxFrameCollectionType_obj::ATLAS_dyn();
HXDLIN( 395)		::cpp::VirtualArray collections = ( (::cpp::VirtualArray)(graphic->frameCollections->get(type)) );
HXDLIN( 395)		if (::hx::IsNull( collections )) {
HXLINE( 395)			collections = ::Array_obj< ::Dynamic>::__new();
HXDLIN( 395)			graphic->frameCollections->set(type,collections);
            		}
HXDLIN( 395)		::Array< ::Dynamic> atlasFrames = collections;
HXLINE( 397)		{
HXLINE( 397)			int _g = 0;
HXDLIN( 397)			while((_g < atlasFrames->length)){
HXLINE( 397)				 ::flixel::graphics::frames::FlxAtlasFrames atlas = atlasFrames->__get(_g).StaticCast<  ::flixel::graphics::frames::FlxAtlasFrames >();
HXDLIN( 397)				_g = (_g + 1);
HXLINE( 398)				 ::flixel::math::FlxPoint _this = atlas->border;
HXDLIN( 398)				bool result;
HXDLIN( 398)				if ((::Math_obj::abs((_this->x - border->x)) <= ((Float)0.0000001))) {
HXLINE( 398)					result = (::Math_obj::abs((_this->y - border->y)) <= ((Float)0.0000001));
            				}
            				else {
HXLINE( 398)					result = false;
            				}
HXDLIN( 398)				if (border->_weak) {
HXLINE( 398)					border->put();
            				}
HXDLIN( 398)				if (result) {
HXLINE( 399)					return atlas;
            				}
            			}
            		}
HXLINE( 401)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FlxAtlasFrames_obj,findFrame,return )


::hx::ObjectPtr< FlxAtlasFrames_obj > FlxAtlasFrames_obj::__new( ::flixel::graphics::FlxGraphic parent, ::flixel::math::FlxPoint border) {
	::hx::ObjectPtr< FlxAtlasFrames_obj > __this = new FlxAtlasFrames_obj();
	__this->__construct(parent,border);
	return __this;
}

::hx::ObjectPtr< FlxAtlasFrames_obj > FlxAtlasFrames_obj::__alloc(::hx::Ctx *_hx_ctx, ::flixel::graphics::FlxGraphic parent, ::flixel::math::FlxPoint border) {
	FlxAtlasFrames_obj *__this = (FlxAtlasFrames_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(FlxAtlasFrames_obj), true, "flixel.graphics.frames.FlxAtlasFrames"));
	*(void **)__this = FlxAtlasFrames_obj::_hx_vtable;
	__this->__construct(parent,border);
	return __this;
}

FlxAtlasFrames_obj::FlxAtlasFrames_obj()
{
}

::hx::Val FlxAtlasFrames_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"addBorder") ) { return ::hx::Val( addBorder_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

bool FlxAtlasFrames_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"findFrame") ) { outValue = findFrame_dyn(); return true; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"fromLibGdx") ) { outValue = fromLibGdx_dyn(); return true; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"fromSparrow") ) { outValue = fromSparrow_dyn(); return true; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"getDimensions") ) { outValue = getDimensions_dyn(); return true; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"texturePackerHelper") ) { outValue = texturePackerHelper_dyn(); return true; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"fromTexturePackerXml") ) { outValue = fromTexturePackerXml_dyn(); return true; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"fromTexturePackerJson") ) { outValue = fromTexturePackerJson_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"fromSpriteSheetPacker") ) { outValue = fromSpriteSheetPacker_dyn(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *FlxAtlasFrames_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *FlxAtlasFrames_obj_sStaticStorageInfo = 0;
#endif

static ::String FlxAtlasFrames_obj_sMemberFields[] = {
	HX_("addBorder",ed,81,3e,1c),
	::String(null()) };

::hx::Class FlxAtlasFrames_obj::__mClass;

static ::String FlxAtlasFrames_obj_sStaticFields[] = {
	HX_("fromTexturePackerJson",bf,f0,7e,be),
	HX_("texturePackerHelper",0f,23,bd,b2),
	HX_("fromLibGdx",80,06,df,27),
	HX_("getDimensions",83,1a,12,39),
	HX_("fromSparrow",c2,9f,ec,33),
	HX_("fromTexturePackerXml",20,df,27,fb),
	HX_("fromSpriteSheetPacker",b6,b2,c0,5f),
	HX_("findFrame",34,a9,7a,f5),
	::String(null())
};

void FlxAtlasFrames_obj::__register()
{
	FlxAtlasFrames_obj _hx_dummy;
	FlxAtlasFrames_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("flixel.graphics.frames.FlxAtlasFrames",d6,87,d5,6f);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &FlxAtlasFrames_obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(FlxAtlasFrames_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(FlxAtlasFrames_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< FlxAtlasFrames_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = FlxAtlasFrames_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = FlxAtlasFrames_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace flixel
} // end namespace graphics
} // end namespace frames
