#include <hxcpp.h>

#ifndef INCLUDED_95f339a1d026d52c
#define INCLUDED_95f339a1d026d52c
#include "hxMath.h"
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED__UnicodeString_UnicodeString_Impl_
#include <_UnicodeString/UnicodeString_Impl_.h>
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
#ifndef INCLUDED_flixel_graphics_FlxGraphic
#include <flixel/graphics/FlxGraphic.h>
#endif
#ifndef INCLUDED_flixel_graphics_atlas_FlxAtlas
#include <flixel/graphics/atlas/FlxAtlas.h>
#endif
#ifndef INCLUDED_flixel_graphics_atlas_FlxNode
#include <flixel/graphics/atlas/FlxNode.h>
#endif
#ifndef INCLUDED_flixel_graphics_frames_FlxFrame
#include <flixel/graphics/frames/FlxFrame.h>
#endif
#ifndef INCLUDED_flixel_graphics_frames_FlxFramesCollection
#include <flixel/graphics/frames/FlxFramesCollection.h>
#endif
#ifndef INCLUDED_flixel_graphics_frames_FlxImageFrame
#include <flixel/graphics/frames/FlxImageFrame.h>
#endif
#ifndef INCLUDED_flixel_math_FlxMatrix
#include <flixel/math/FlxMatrix.h>
#endif
#ifndef INCLUDED_flixel_math_FlxPoint
#include <flixel/math/FlxPoint.h>
#endif
#ifndef INCLUDED_flixel_system_FlxAssets
#include <flixel/system/FlxAssets.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_BitmapFrontEnd
#include <flixel/system/frontEnds/BitmapFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_text_FlxText
#include <flixel/text/FlxText.h>
#endif
#ifndef INCLUDED_flixel_text_FlxTextBorderStyle
#include <flixel/text/FlxTextBorderStyle.h>
#endif
#ifndef INCLUDED_flixel_text_FlxTextFormat
#include <flixel/text/FlxTextFormat.h>
#endif
#ifndef INCLUDED_flixel_text_FlxTextFormatMarkerPair
#include <flixel/text/FlxTextFormatMarkerPair.h>
#endif
#ifndef INCLUDED_flixel_text__FlxText_FlxTextAlign_Impl_
#include <flixel/text/_FlxText/FlxTextAlign_Impl_.h>
#endif
#ifndef INCLUDED_flixel_text__FlxText_FlxTextFormatRange
#include <flixel/text/_FlxText/FlxTextFormatRange.h>
#endif
#ifndef INCLUDED_flixel_util_FlxDestroyUtil
#include <flixel/util/FlxDestroyUtil.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPool_flixel_math_FlxPoint
#include <flixel/util/FlxPool_flixel_math_FlxPoint.h>
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
#ifndef INCLUDED_flixel_util_helpers_FlxRange
#include <flixel/util/helpers/FlxRange.h>
#endif
#ifndef INCLUDED_lime_text_Font
#include <lime/text/Font.h>
#endif
#ifndef INCLUDED_openfl_display_BitmapData
#include <openfl/display/BitmapData.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObject
#include <openfl/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl_display_IBitmapDrawable
#include <openfl/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl_display_InteractiveObject
#include <openfl/display/InteractiveObject.h>
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
#ifndef INCLUDED_openfl_geom_Rectangle
#include <openfl/geom/Rectangle.h>
#endif
#ifndef INCLUDED_openfl_text_Font
#include <openfl/text/Font.h>
#endif
#ifndef INCLUDED_openfl_text_TextField
#include <openfl/text/TextField.h>
#endif
#ifndef INCLUDED_openfl_text_TextFormat
#include <openfl/text/TextFormat.h>
#endif
#ifndef INCLUDED_openfl_utils_Assets
#include <openfl/utils/Assets.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_7d9cf70d988be490_39_new,"flixel.text.FlxText","new",0x8fca03a2,"flixel.text.FlxText.new","flixel/text/FlxText.hx",39,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_218_destroy,"flixel.text.FlxText","destroy",0x1704293c,"flixel.text.FlxText.destroy","flixel/text/FlxText.hx",218,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_228_drawFrame,"flixel.text.FlxText","drawFrame",0xd9b5be4b,"flixel.text.FlxText.drawFrame","flixel/text/FlxText.hx",228,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_242_stampOnAtlas,"flixel.text.FlxText","stampOnAtlas",0x66244e67,"flixel.text.FlxText.stampOnAtlas","flixel/text/FlxText.hx",242,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_281_applyMarkup,"flixel.text.FlxText","applyMarkup",0x660988f8,"flixel.text.FlxText.applyMarkup","flixel/text/FlxText.hx",281,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_395_addFormat,"flixel.text.FlxText","addFormat",0xc0d9d4fa,"flixel.text.FlxText.addFormat","flixel/text/FlxText.hx",395,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_390_addFormat,"flixel.text.FlxText","addFormat",0xc0d9d4fa,"flixel.text.FlxText.addFormat","flixel/text/FlxText.hx",390,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_407_removeFormat,"flixel.text.FlxText","removeFormat",0xa79a7f19,"flixel.text.FlxText.removeFormat","flixel/text/FlxText.hx",407,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_453_clearFormats,"flixel.text.FlxText","clearFormats",0xf58bc7cd,"flixel.text.FlxText.clearFormats","flixel/text/FlxText.hx",453,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_474_setFormat,"flixel.text.FlxText","setFormat",0x685d153b,"flixel.text.FlxText.setFormat","flixel/text/FlxText.hx",474,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_506_setBorderStyle,"flixel.text.FlxText","setBorderStyle",0x26cf9c21,"flixel.text.FlxText.setBorderStyle","flixel/text/FlxText.hx",506,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_516_updateHitbox,"flixel.text.FlxText","updateHitbox",0x91c9e8ff,"flixel.text.FlxText.updateHitbox","flixel/text/FlxText.hx",516,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_522_set_fieldWidth,"flixel.text.FlxText","set_fieldWidth",0x9c758fa7,"flixel.text.FlxText.set_fieldWidth","flixel/text/FlxText.hx",522,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_544_get_fieldWidth,"flixel.text.FlxText","get_fieldWidth",0x7c55a733,"flixel.text.FlxText.get_fieldWidth","flixel/text/FlxText.hx",544,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_548_set_autoSize,"flixel.text.FlxText","set_autoSize",0x346abbcb,"flixel.text.FlxText.set_autoSize","flixel/text/FlxText.hx",548,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_560_get_autoSize,"flixel.text.FlxText","get_autoSize",0x1f719857,"flixel.text.FlxText.get_autoSize","flixel/text/FlxText.hx",560,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_564_set_text,"flixel.text.FlxText","set_text",0xb6d09f28,"flixel.text.FlxText.set_text","flixel/text/FlxText.hx",564,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_577_get_size,"flixel.text.FlxText","get_size",0x07cd19c8,"flixel.text.FlxText.get_size","flixel/text/FlxText.hx",577,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_581_set_size,"flixel.text.FlxText","set_size",0xb62a733c,"flixel.text.FlxText.set_size","flixel/text/FlxText.hx",581,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_588_set_color,"flixel.text.FlxText","set_color",0x7c7dca88,"flixel.text.FlxText.set_color","flixel/text/FlxText.hx",588,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_601_get_font,"flixel.text.FlxText","get_font",0xff39d6d6,"flixel.text.FlxText.get_font","flixel/text/FlxText.hx",601,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_605_set_font,"flixel.text.FlxText","set_font",0xad97304a,"flixel.text.FlxText.set_font","flixel/text/FlxText.hx",605,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_629_get_embedded,"flixel.text.FlxText","get_embedded",0xce5a2211,"flixel.text.FlxText.get_embedded","flixel/text/FlxText.hx",629,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_634_get_systemFont,"flixel.text.FlxText","get_systemFont",0xd6b43ca5,"flixel.text.FlxText.get_systemFont","flixel/text/FlxText.hx",634,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_638_set_systemFont,"flixel.text.FlxText","set_systemFont",0xf6d42519,"flixel.text.FlxText.set_systemFont","flixel/text/FlxText.hx",638,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_647_get_bold,"flixel.text.FlxText","get_bold",0xfc94fa8c,"flixel.text.FlxText.get_bold","flixel/text/FlxText.hx",647,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_651_set_bold,"flixel.text.FlxText","set_bold",0xaaf25400,"flixel.text.FlxText.set_bold","flixel/text/FlxText.hx",651,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_662_get_italic,"flixel.text.FlxText","get_italic",0xadf337b7,"flixel.text.FlxText.get_italic","flixel/text/FlxText.hx",662,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_666_set_italic,"flixel.text.FlxText","set_italic",0xb170d62b,"flixel.text.FlxText.set_italic","flixel/text/FlxText.hx",666,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_677_get_wordWrap,"flixel.text.FlxText","get_wordWrap",0xf0d31d3b,"flixel.text.FlxText.get_wordWrap","flixel/text/FlxText.hx",677,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_681_set_wordWrap,"flixel.text.FlxText","set_wordWrap",0x05cc40af,"flixel.text.FlxText.set_wordWrap","flixel/text/FlxText.hx",681,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_692_get_alignment,"flixel.text.FlxText","get_alignment",0xf34d507c,"flixel.text.FlxText.get_alignment","flixel/text/FlxText.hx",692,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_696_set_alignment,"flixel.text.FlxText","set_alignment",0x38533288,"flixel.text.FlxText.set_alignment","flixel/text/FlxText.hx",696,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_703_set_borderStyle,"flixel.text.FlxText","set_borderStyle",0x0a5ab38a,"flixel.text.FlxText.set_borderStyle","flixel/text/FlxText.hx",703,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_711_set_borderColor,"flixel.text.FlxText","set_borderColor",0xd0997fbc,"flixel.text.FlxText.set_borderColor","flixel/text/FlxText.hx",711,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_719_set_borderSize,"flixel.text.FlxText","set_borderSize",0x0b7e6088,"flixel.text.FlxText.set_borderSize","flixel/text/FlxText.hx",719,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_727_set_borderQuality,"flixel.text.FlxText","set_borderQuality",0x9eac1b58,"flixel.text.FlxText.set_borderQuality","flixel/text/FlxText.hx",727,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_736_set_graphic,"flixel.text.FlxText","set_graphic",0x740d070d,"flixel.text.FlxText.set_graphic","flixel/text/FlxText.hx",736,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_744_get_width,"flixel.text.FlxText","get_width",0x1933231f,"flixel.text.FlxText.get_width","flixel/text/FlxText.hx",744,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_750_get_height,"flixel.text.FlxText","get_height",0xa9db10ae,"flixel.text.FlxText.get_height","flixel/text/FlxText.hx",750,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_756_updateColorTransform,"flixel.text.FlxText","updateColorTransform",0x81f611f0,"flixel.text.FlxText.updateColorTransform","flixel/text/FlxText.hx",756,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_775_regenGraphic,"flixel.text.FlxText","regenGraphic",0xc617a9e9,"flixel.text.FlxText.regenGraphic","flixel/text/FlxText.hx",775,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_876_drawTextFieldTo,"flixel.text.FlxText","drawTextFieldTo",0xda5cac46,"flixel.text.FlxText.drawTextFieldTo","flixel/text/FlxText.hx",876,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_898_draw,"flixel.text.FlxText","draw",0x3a66d282,"flixel.text.FlxText.draw","flixel/text/FlxText.hx",898,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_909_calcFrame,"flixel.text.FlxText","calcFrame",0x04b3a41a,"flixel.text.FlxText.calcFrame","flixel/text/FlxText.hx",909,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_921_applyBorderStyle,"flixel.text.FlxText","applyBorderStyle",0x7fb82955,"flixel.text.FlxText.applyBorderStyle","flixel/text/FlxText.hx",921,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_987_applyBorderTransparency,"flixel.text.FlxText","applyBorderTransparency",0x59c1b674,"flixel.text.FlxText.applyBorderTransparency","flixel/text/FlxText.hx",987,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_1003_copyTextWithOffset,"flixel.text.FlxText","copyTextWithOffset",0x8b535ed9,"flixel.text.FlxText.copyTextWithOffset","flixel/text/FlxText.hx",1003,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_1010_applyFormats,"flixel.text.FlxText","applyFormats",0x597a620c,"flixel.text.FlxText.applyFormats","flixel/text/FlxText.hx",1010,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_1036_copyTextFormat,"flixel.text.FlxText","copyTextFormat",0xce0953d7,"flixel.text.FlxText.copyTextFormat","flixel/text/FlxText.hx",1036,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_1053_dtfCopy,"flixel.text.FlxText","dtfCopy",0x79c34ded,"flixel.text.FlxText.dtfCopy","flixel/text/FlxText.hx",1053,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_1059_updateDefaultFormat,"flixel.text.FlxText","updateDefaultFormat",0x3cb6b251,"flixel.text.FlxText.updateDefaultFormat","flixel/text/FlxText.hx",1059,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_1066_set_frames,"flixel.text.FlxText","set_frames",0x579256e1,"flixel.text.FlxText.set_frames","flixel/text/FlxText.hx",1066,0xdf165a6e)
HX_LOCAL_STACK_FRAME(_hx_pos_7d9cf70d988be490_44_boot,"flixel.text.FlxText","boot",0x39122ab0,"flixel.text.FlxText.boot","flixel/text/FlxText.hx",44,0xdf165a6e)
namespace flixel{
namespace text{

void FlxText_obj::__construct(::hx::Null< Float >  __o_X,::hx::Null< Float >  __o_Y,::hx::Null< Float >  __o_FieldWidth,::String Text,::hx::Null< int >  __o_Size,::hx::Null< bool >  __o_EmbeddedFont){
            		Float X = __o_X.Default(0);
            		Float Y = __o_Y.Default(0);
            		Float FieldWidth = __o_FieldWidth.Default(0);
            		int Size = __o_Size.Default(8);
            		bool EmbeddedFont = __o_EmbeddedFont.Default(true);
            	HX_GC_STACKFRAME(&_hx_pos_7d9cf70d988be490_39_new)
HXLINE( 156)		this->_hasBorderAlpha = false;
HXLINE( 147)		this->_regen = true;
HXLINE( 141)		this->_formatRanges = ::Array_obj< ::Dynamic>::__new(0);
HXLINE( 114)		this->borderQuality = ((Float)1);
HXLINE( 107)		this->borderSize = ((Float)1);
HXLINE( 102)		this->borderColor = 0;
HXLINE(  97)		this->borderStyle = ::flixel::text::FlxTextBorderStyle_obj::NONE_dyn();
HXLINE(  49)		this->text = HX_("",00,00,00,00);
HXLINE( 178)		super::__construct(X,Y,null());
HXLINE( 180)		bool _hx_tmp;
HXDLIN( 180)		if (::hx::IsNotNull( Text )) {
HXLINE( 180)			_hx_tmp = (Text == HX_("",00,00,00,00));
            		}
            		else {
HXLINE( 180)			_hx_tmp = true;
            		}
HXDLIN( 180)		if (_hx_tmp) {
HXLINE( 184)			this->set_text(HX_("",00,00,00,00));
HXLINE( 185)			Text = HX_(" ",20,00,00,00);
            		}
            		else {
HXLINE( 189)			this->set_text(Text);
            		}
HXLINE( 192)		this->textField =  ::openfl::text::TextField_obj::__alloc( HX_CTX );
HXLINE( 193)		this->textField->set_selectable(false);
HXLINE( 194)		this->textField->set_multiline(true);
HXLINE( 195)		this->textField->set_wordWrap(true);
HXLINE( 196)		this->_defaultFormat =  ::openfl::text::TextFormat_obj::__alloc( HX_CTX ,null(),Size,16777215,null(),null(),null(),null(),null(),null(),null(),null(),null(),null());
HXLINE( 197)		this->set_font(::flixel::_hx_system::FlxAssets_obj::FONT_DEFAULT);
HXLINE( 198)		this->_formatAdjusted =  ::openfl::text::TextFormat_obj::__alloc( HX_CTX ,null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());
HXLINE( 199)		this->textField->set_defaultTextFormat(this->_defaultFormat);
HXLINE( 200)		this->textField->set_text(Text);
HXLINE( 201)		this->set_fieldWidth(FieldWidth);
HXLINE( 202)		this->textField->set_embedFonts(EmbeddedFont);
HXLINE( 203)		this->textField->set_sharpness(( (Float)(100) ));
HXLINE( 204)		Float _hx_tmp1;
HXDLIN( 204)		if ((Text.length <= 0)) {
HXLINE( 204)			_hx_tmp1 = ( (Float)(1) );
            		}
            		else {
HXLINE( 204)			_hx_tmp1 = ( (Float)(10) );
            		}
HXDLIN( 204)		this->textField->set_height(_hx_tmp1);
HXLINE( 206)		this->set_allowCollisions(0);
HXLINE( 207)		this->set_moves(false);
HXLINE( 209)		this->drawFrame(null());
HXLINE( 211)		 ::flixel::math::FlxPoint point = ::flixel::math::FlxPoint_obj::_pool->get()->set(1,1);
HXDLIN( 211)		point->_inPool = false;
HXDLIN( 211)		this->shadowOffset = point;
            	}

Dynamic FlxText_obj::__CreateEmpty() { return new FlxText_obj; }

void *FlxText_obj::_hx_vtable = 0;

Dynamic FlxText_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< FlxText_obj > _hx_result = new FlxText_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5]);
	return _hx_result;
}

bool FlxText_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x752f90b6) {
		if (inClassId<=(int)0x2c01639b) {
			return inClassId==(int)0x00000001 || inClassId==(int)0x2c01639b;
		} else {
			return inClassId==(int)0x752f90b6;
		}
	} else {
		return inClassId==(int)0x7ccf8994 || inClassId==(int)0x7dab0655;
	}
}

void FlxText_obj::destroy(){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_218_destroy)
HXLINE( 219)		this->textField = null();
HXLINE( 220)		this->_font = null();
HXLINE( 221)		this->_defaultFormat = null();
HXLINE( 222)		this->_formatAdjusted = null();
HXLINE( 223)		this->shadowOffset = ( ( ::flixel::math::FlxPoint)(::flixel::util::FlxDestroyUtil_obj::put(this->shadowOffset)) );
HXLINE( 224)		this->super::destroy();
            	}


void FlxText_obj::drawFrame(::hx::Null< bool >  __o_Force){
            		bool Force = __o_Force.Default(false);
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_228_drawFrame)
HXLINE( 229)		bool _hx_tmp;
HXDLIN( 229)		if (!(this->_regen)) {
HXLINE( 229)			_hx_tmp = Force;
            		}
            		else {
HXLINE( 229)			_hx_tmp = true;
            		}
HXDLIN( 229)		this->_regen = _hx_tmp;
HXLINE( 230)		this->super::drawFrame(this->_regen);
            	}


bool FlxText_obj::stampOnAtlas( ::flixel::graphics::atlas::FlxAtlas atlas){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_242_stampOnAtlas)
HXLINE( 243)		this->regenGraphic();
HXLINE( 245)		 ::flixel::graphics::atlas::FlxNode node = atlas->addNode(this->graphic->bitmap,this->graphic->key);
HXLINE( 246)		bool result = ::hx::IsNotNull( node );
HXLINE( 248)		if (::hx::IsNotNull( node )) {
HXLINE( 250)			this->set_frames(node->getImageFrame());
            		}
HXLINE( 253)		return result;
            	}


HX_DEFINE_DYNAMIC_FUNC1(FlxText_obj,stampOnAtlas,return )

 ::flixel::text::FlxText FlxText_obj::applyMarkup(::String input,::Array< ::Dynamic> rules){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_281_applyMarkup)
HXLINE( 282)		bool _hx_tmp;
HXDLIN( 282)		if (::hx::IsNotNull( rules )) {
HXLINE( 282)			_hx_tmp = (rules->length == 0);
            		}
            		else {
HXLINE( 282)			_hx_tmp = true;
            		}
HXDLIN( 282)		if (_hx_tmp) {
HXLINE( 283)			return ::hx::ObjectPtr<OBJ_>(this);
            		}
HXLINE( 285)		this->clearFormats();
HXLINE( 287)		::Array< int > rangeStarts = ::Array_obj< int >::__new(0);
HXLINE( 288)		::Array< int > rangeEnds = ::Array_obj< int >::__new(0);
HXLINE( 289)		::Array< ::Dynamic> rulesToApply = ::Array_obj< ::Dynamic>::__new(0);
HXLINE( 291)		int i = 0;
HXLINE( 292)		{
HXLINE( 292)			int _g = 0;
HXDLIN( 292)			while((_g < rules->length)){
HXLINE( 292)				 ::flixel::text::FlxTextFormatMarkerPair rule = rules->__get(_g).StaticCast<  ::flixel::text::FlxTextFormatMarkerPair >();
HXDLIN( 292)				_g = (_g + 1);
HXLINE( 294)				bool _hx_tmp;
HXDLIN( 294)				if (::hx::IsNotNull( rule->marker )) {
HXLINE( 294)					_hx_tmp = ::hx::IsNull( rule->format );
            				}
            				else {
HXLINE( 294)					_hx_tmp = true;
            				}
HXDLIN( 294)				if (_hx_tmp) {
HXLINE( 295)					continue;
            				}
HXLINE( 297)				bool start = false;
HXLINE( 298)				int markerLength = ::_UnicodeString::UnicodeString_Impl__obj::get_length(rule->marker);
HXLINE( 300)				if ((input.indexOf(rule->marker,null()) == -1)) {
HXLINE( 301)					continue;
            				}
HXLINE( 304)				{
HXLINE( 304)					int _g1 = 0;
HXDLIN( 304)					int _g2 = ::_UnicodeString::UnicodeString_Impl__obj::get_length(input);
HXDLIN( 304)					while((_g1 < _g2)){
HXLINE( 304)						_g1 = (_g1 + 1);
HXDLIN( 304)						int charIndex = (_g1 - 1);
HXLINE( 306)						::String a = ::_UnicodeString::UnicodeString_Impl__obj::substr(input,charIndex,markerLength);
HXDLIN( 306)						if ((a != rule->marker)) {
HXLINE( 307)							continue;
            						}
HXLINE( 309)						if (start) {
HXLINE( 311)							start = false;
HXLINE( 312)							rangeEnds->push(charIndex);
            						}
            						else {
HXLINE( 316)							start = true;
HXLINE( 317)							rangeStarts->push(charIndex);
HXLINE( 318)							rulesToApply->push(rule);
            						}
            					}
            				}
HXLINE( 322)				if (start) {
HXLINE( 325)					rangeEnds->push(-1);
            				}
HXLINE( 328)				i = (i + 1);
            			}
            		}
HXLINE( 332)		{
HXLINE( 332)			int _g1 = 0;
HXDLIN( 332)			while((_g1 < rules->length)){
HXLINE( 332)				 ::flixel::text::FlxTextFormatMarkerPair rule = rules->__get(_g1).StaticCast<  ::flixel::text::FlxTextFormatMarkerPair >();
HXDLIN( 332)				_g1 = (_g1 + 1);
HXLINE( 333)				input = ::StringTools_obj::replace(input,rule->marker,HX_("",00,00,00,00));
            			}
            		}
HXLINE( 336)		{
HXLINE( 336)			int _g2 = 0;
HXDLIN( 336)			int _g3 = rangeStarts->length;
HXDLIN( 336)			while((_g2 < _g3)){
HXLINE( 336)				_g2 = (_g2 + 1);
HXDLIN( 336)				int i = (_g2 - 1);
HXLINE( 339)				int delIndex = rangeStarts->__get(i);
HXLINE( 340)				int markerLength = ::_UnicodeString::UnicodeString_Impl__obj::get_length(rulesToApply->__get(i).StaticCast<  ::flixel::text::FlxTextFormatMarkerPair >()->marker);
HXLINE( 343)				{
HXLINE( 343)					int _g = 0;
HXDLIN( 343)					int _g1 = rangeStarts->length;
HXDLIN( 343)					while((_g < _g1)){
HXLINE( 343)						_g = (_g + 1);
HXDLIN( 343)						int j = (_g - 1);
HXLINE( 345)						if ((rangeStarts->__get(j) > delIndex)) {
HXLINE( 347)							::Array< int > rangeStarts1 = rangeStarts;
HXDLIN( 347)							int j1 = j;
HXDLIN( 347)							rangeStarts1[j1] = (rangeStarts1->__get(j1) - markerLength);
            						}
HXLINE( 349)						if ((rangeEnds->__get(j) > delIndex)) {
HXLINE( 351)							::Array< int > rangeEnds1 = rangeEnds;
HXDLIN( 351)							int j1 = j;
HXDLIN( 351)							rangeEnds1[j1] = (rangeEnds1->__get(j1) - markerLength);
            						}
            					}
            				}
HXLINE( 356)				delIndex = rangeEnds->__get(i);
HXLINE( 359)				{
HXLINE( 359)					int _g3 = 0;
HXDLIN( 359)					int _g4 = rangeStarts->length;
HXDLIN( 359)					while((_g3 < _g4)){
HXLINE( 359)						_g3 = (_g3 + 1);
HXDLIN( 359)						int j = (_g3 - 1);
HXLINE( 361)						if ((rangeStarts->__get(j) > delIndex)) {
HXLINE( 363)							::Array< int > rangeStarts1 = rangeStarts;
HXDLIN( 363)							int j1 = j;
HXDLIN( 363)							rangeStarts1[j1] = (rangeStarts1->__get(j1) - markerLength);
            						}
HXLINE( 365)						if ((rangeEnds->__get(j) > delIndex)) {
HXLINE( 367)							::Array< int > rangeEnds1 = rangeEnds;
HXDLIN( 367)							int j1 = j;
HXDLIN( 367)							rangeEnds1[j1] = (rangeEnds1->__get(j1) - markerLength);
            						}
            					}
            				}
            			}
            		}
HXLINE( 373)		this->set_text(input);
HXLINE( 376)		{
HXLINE( 376)			int _g4 = 0;
HXDLIN( 376)			int _g5 = rangeStarts->length;
HXDLIN( 376)			while((_g4 < _g5)){
HXLINE( 376)				_g4 = (_g4 + 1);
HXDLIN( 376)				int i = (_g4 - 1);
HXLINE( 377)				this->addFormat(rulesToApply->__get(i).StaticCast<  ::flixel::text::FlxTextFormatMarkerPair >()->format,rangeStarts->__get(i),rangeEnds->__get(i));
            			}
            		}
HXLINE( 379)		return ::hx::ObjectPtr<OBJ_>(this);
            	}


HX_DEFINE_DYNAMIC_FUNC2(FlxText_obj,applyMarkup,return )

 ::flixel::text::FlxText FlxText_obj::addFormat( ::flixel::text::FlxTextFormat Format,::hx::Null< int >  __o_Start,::hx::Null< int >  __o_End){
            		HX_BEGIN_LOCAL_FUNC_S0(::hx::LocalFunc,_hx_Closure_0) HXARGC(2)
            		int _hx_run( ::flixel::text::_FlxText::FlxTextFormatRange left, ::flixel::text::_FlxText::FlxTextFormatRange right){
            			HX_GC_STACKFRAME(&_hx_pos_7d9cf70d988be490_395_addFormat)
HXLINE( 395)			if (::hx::IsLess( left->range->start,right->range->start )) {
HXLINE( 395)				return -1;
            			}
            			else {
HXLINE( 395)				return 1;
            			}
HXDLIN( 395)			return 0;
            		}
            		HX_END_LOCAL_FUNC2(return)

            		int Start = __o_Start.Default(-1);
            		int End = __o_End.Default(-1);
            	HX_GC_STACKFRAME(&_hx_pos_7d9cf70d988be490_390_addFormat)
HXLINE( 391)		::Array< ::Dynamic> _hx_tmp = this->_formatRanges;
HXDLIN( 391)		_hx_tmp->push( ::flixel::text::_FlxText::FlxTextFormatRange_obj::__alloc( HX_CTX ,Format,Start,End));
HXLINE( 393)		this->_formatRanges->sort( ::Dynamic(new _hx_Closure_0()));
HXLINE( 397)		this->_regen = true;
HXLINE( 399)		return ::hx::ObjectPtr<OBJ_>(this);
            	}


HX_DEFINE_DYNAMIC_FUNC3(FlxText_obj,addFormat,return )

 ::flixel::text::FlxText FlxText_obj::removeFormat( ::flixel::text::FlxTextFormat Format, ::Dynamic Start, ::Dynamic End){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_407_removeFormat)
HXLINE( 408)		int i = this->_formatRanges->length;
HXLINE( 409)		while(true){
HXLINE( 409)			i = (i - 1);
HXDLIN( 409)			if (!(((i + 1) > 0))) {
HXLINE( 409)				goto _hx_goto_14;
            			}
HXLINE( 411)			 ::flixel::text::_FlxText::FlxTextFormatRange formatRange = this->_formatRanges->__get(i).StaticCast<  ::flixel::text::_FlxText::FlxTextFormatRange >();
HXLINE( 412)			if (::hx::IsInstanceNotEq( formatRange->format,Format )) {
HXLINE( 413)				continue;
            			}
HXLINE( 415)			bool _hx_tmp;
HXDLIN( 415)			if (::hx::IsNotNull( Start )) {
HXLINE( 415)				_hx_tmp = ::hx::IsNotNull( End );
            			}
            			else {
HXLINE( 415)				_hx_tmp = false;
            			}
HXDLIN( 415)			if (_hx_tmp) {
HXLINE( 417)				 ::flixel::util::helpers::FlxRange range = formatRange->range;
HXLINE( 418)				bool _hx_tmp;
HXDLIN( 418)				if (::hx::IsLess( Start,range->end )) {
HXLINE( 418)					_hx_tmp = ::hx::IsLessEq( End,range->start );
            				}
            				else {
HXLINE( 418)					_hx_tmp = true;
            				}
HXDLIN( 418)				if (_hx_tmp) {
HXLINE( 419)					continue;
            				}
HXLINE( 421)				bool _hx_tmp1;
HXDLIN( 421)				if (::hx::IsGreater( Start,range->start )) {
HXLINE( 421)					_hx_tmp1 = ::hx::IsLess( End,range->end );
            				}
            				else {
HXLINE( 421)					_hx_tmp1 = false;
            				}
HXDLIN( 421)				if (_hx_tmp1) {
HXLINE( 423)					this->addFormat(formatRange->format,(End + 1),range->end);
HXLINE( 424)					range->end = Start;
HXLINE( 425)					continue;
            				}
HXLINE( 428)				bool _hx_tmp2;
HXDLIN( 428)				if (::hx::IsLessEq( Start,range->start )) {
HXLINE( 428)					_hx_tmp2 = ::hx::IsLess( End,range->end );
            				}
            				else {
HXLINE( 428)					_hx_tmp2 = false;
            				}
HXDLIN( 428)				if (_hx_tmp2) {
HXLINE( 430)					range->start = End;
HXLINE( 431)					continue;
            				}
HXLINE( 434)				bool _hx_tmp3;
HXDLIN( 434)				if (::hx::IsGreater( Start,range->start )) {
HXLINE( 434)					_hx_tmp3 = ::hx::IsGreaterEq( End,range->end );
            				}
            				else {
HXLINE( 434)					_hx_tmp3 = false;
            				}
HXDLIN( 434)				if (_hx_tmp3) {
HXLINE( 436)					range->end = Start;
HXLINE( 437)					continue;
            				}
            			}
HXLINE( 441)			this->_formatRanges->remove(formatRange);
            		}
            		_hx_goto_14:;
HXLINE( 444)		this->_regen = true;
HXLINE( 446)		return ::hx::ObjectPtr<OBJ_>(this);
            	}


HX_DEFINE_DYNAMIC_FUNC3(FlxText_obj,removeFormat,return )

 ::flixel::text::FlxText FlxText_obj::clearFormats(){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_453_clearFormats)
HXLINE( 454)		this->_formatRanges = ::Array_obj< ::Dynamic>::__new(0);
HXLINE( 455)		{
HXLINE( 455)			this->textField->set_defaultTextFormat(this->_defaultFormat);
HXDLIN( 455)			this->textField->setTextFormat(this->_defaultFormat,null(),null());
HXDLIN( 455)			this->_regen = true;
            		}
HXLINE( 457)		return ::hx::ObjectPtr<OBJ_>(this);
            	}


HX_DEFINE_DYNAMIC_FUNC0(FlxText_obj,clearFormats,return )

 ::flixel::text::FlxText FlxText_obj::setFormat(::String Font,::hx::Null< int >  __o_Size,::hx::Null< int >  __o_Color,::String Alignment, ::flixel::text::FlxTextBorderStyle BorderStyle,::hx::Null< int >  __o_BorderColor,::hx::Null< bool >  __o_EmbeddedFont){
            		int Size = __o_Size.Default(8);
            		int Color = __o_Color.Default(-1);
            		int BorderColor = __o_BorderColor.Default(0);
            		bool EmbeddedFont = __o_EmbeddedFont.Default(true);
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_474_setFormat)
HXLINE( 475)		if (::hx::IsNull( BorderStyle )) {
HXLINE( 475)			BorderStyle = ::flixel::text::FlxTextBorderStyle_obj::NONE_dyn();
            		}
HXLINE( 477)		if (EmbeddedFont) {
HXLINE( 479)			this->set_font(Font);
            		}
            		else {
HXLINE( 481)			if (::hx::IsNotNull( Font )) {
HXLINE( 483)				this->set_systemFont(Font);
            			}
            		}
HXLINE( 486)		this->set_size(Size);
HXLINE( 487)		this->set_color(Color);
HXLINE( 488)		if (::hx::IsNotNull( Alignment )) {
HXLINE( 489)			this->set_alignment(Alignment);
            		}
HXLINE( 490)		{
HXLINE( 490)			this->set_borderStyle(BorderStyle);
HXDLIN( 490)			this->set_borderColor(BorderColor);
HXDLIN( 490)			this->set_borderSize(( (Float)(1) ));
HXDLIN( 490)			this->set_borderQuality(( (Float)(1) ));
            		}
HXLINE( 492)		{
HXLINE( 492)			this->textField->set_defaultTextFormat(this->_defaultFormat);
HXDLIN( 492)			this->textField->setTextFormat(this->_defaultFormat,null(),null());
HXDLIN( 492)			this->_regen = true;
            		}
HXLINE( 494)		return ::hx::ObjectPtr<OBJ_>(this);
            	}


HX_DEFINE_DYNAMIC_FUNC7(FlxText_obj,setFormat,return )

 ::flixel::text::FlxText FlxText_obj::setBorderStyle( ::flixel::text::FlxTextBorderStyle Style,::hx::Null< int >  __o_Color,::hx::Null< Float >  __o_Size,::hx::Null< Float >  __o_Quality){
            		int Color = __o_Color.Default(0);
            		Float Size = __o_Size.Default(1);
            		Float Quality = __o_Quality.Default(1);
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_506_setBorderStyle)
HXLINE( 507)		this->set_borderStyle(Style);
HXLINE( 508)		this->set_borderColor(Color);
HXLINE( 509)		this->set_borderSize(Size);
HXLINE( 510)		this->set_borderQuality(Quality);
HXLINE( 512)		return ::hx::ObjectPtr<OBJ_>(this);
            	}


HX_DEFINE_DYNAMIC_FUNC4(FlxText_obj,setBorderStyle,return )

void FlxText_obj::updateHitbox(){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_516_updateHitbox)
HXLINE( 517)		this->regenGraphic();
HXLINE( 518)		this->super::updateHitbox();
            	}


Float FlxText_obj::set_fieldWidth(Float value){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_522_set_fieldWidth)
HXLINE( 523)		if (::hx::IsNull( this->textField )) {
HXLINE( 524)			return value;
            		}
HXLINE( 526)		if ((value <= 0)) {
HXLINE( 528)			this->set_wordWrap(false);
HXLINE( 529)			this->set_autoSize(true);
            		}
            		else {
HXLINE( 533)			this->set_autoSize(false);
HXLINE( 534)			this->set_wordWrap(true);
HXLINE( 535)			this->textField->set_width(value);
            		}
HXLINE( 538)		this->_regen = true;
HXLINE( 539)		return value;
            	}


HX_DEFINE_DYNAMIC_FUNC1(FlxText_obj,set_fieldWidth,return )

Float FlxText_obj::get_fieldWidth(){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_544_get_fieldWidth)
HXDLIN( 544)		if (::hx::IsNotNull( this->textField )) {
HXDLIN( 544)			return this->textField->get_width();
            		}
            		else {
HXDLIN( 544)			return ( (Float)(0) );
            		}
HXDLIN( 544)		return ((Float)0.);
            	}


HX_DEFINE_DYNAMIC_FUNC0(FlxText_obj,get_fieldWidth,return )

bool FlxText_obj::set_autoSize(bool value){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_548_set_autoSize)
HXLINE( 549)		if (::hx::IsNotNull( this->textField )) {
HXLINE( 551)			 ::Dynamic _hx_tmp;
HXDLIN( 551)			if (value) {
HXLINE( 551)				_hx_tmp = 1;
            			}
            			else {
HXLINE( 551)				_hx_tmp = 2;
            			}
HXDLIN( 551)			this->textField->set_autoSize(_hx_tmp);
HXLINE( 552)			this->_regen = true;
            		}
HXLINE( 555)		return value;
            	}


HX_DEFINE_DYNAMIC_FUNC1(FlxText_obj,set_autoSize,return )

bool FlxText_obj::get_autoSize(){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_560_get_autoSize)
HXDLIN( 560)		if (::hx::IsNotNull( this->textField )) {
HXDLIN( 560)			return ::hx::IsNotEq( this->textField->get_autoSize(),2 );
            		}
            		else {
HXDLIN( 560)			return false;
            		}
HXDLIN( 560)		return false;
            	}


HX_DEFINE_DYNAMIC_FUNC0(FlxText_obj,get_autoSize,return )

::String FlxText_obj::set_text(::String Text){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_564_set_text)
HXLINE( 565)		this->text = Text;
HXLINE( 566)		if (::hx::IsNotNull( this->textField )) {
HXLINE( 568)			::String ot = this->textField->get_text();
HXLINE( 569)			this->textField->set_text(Text);
HXLINE( 570)			bool _hx_tmp;
HXDLIN( 570)			if ((this->textField->get_text() == ot)) {
HXLINE( 570)				_hx_tmp = this->_regen;
            			}
            			else {
HXLINE( 570)				_hx_tmp = true;
            			}
HXDLIN( 570)			this->_regen = _hx_tmp;
            		}
HXLINE( 572)		return Text;
            	}


HX_DEFINE_DYNAMIC_FUNC1(FlxText_obj,set_text,return )

int FlxText_obj::get_size(){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_577_get_size)
HXDLIN( 577)		return ::Std_obj::_hx_int(( (Float)(this->_defaultFormat->size) ));
            	}


HX_DEFINE_DYNAMIC_FUNC0(FlxText_obj,get_size,return )

int FlxText_obj::set_size(int Size){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_581_set_size)
HXLINE( 582)		this->_defaultFormat->size = Size;
HXLINE( 583)		{
HXLINE( 583)			this->textField->set_defaultTextFormat(this->_defaultFormat);
HXDLIN( 583)			this->textField->setTextFormat(this->_defaultFormat,null(),null());
HXDLIN( 583)			this->_regen = true;
            		}
HXLINE( 584)		return Size;
            	}


HX_DEFINE_DYNAMIC_FUNC1(FlxText_obj,set_size,return )

int FlxText_obj::set_color(int Color){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_588_set_color)
HXLINE( 589)		if (::hx::IsEq( this->_defaultFormat->color,(Color & 16777215) )) {
HXLINE( 591)			return Color;
            		}
HXLINE( 593)		this->_defaultFormat->color = (Color & 16777215);
HXLINE( 594)		this->color = Color;
HXLINE( 595)		{
HXLINE( 595)			this->textField->set_defaultTextFormat(this->_defaultFormat);
HXDLIN( 595)			this->textField->setTextFormat(this->_defaultFormat,null(),null());
HXDLIN( 595)			this->_regen = true;
            		}
HXLINE( 596)		return Color;
            	}


::String FlxText_obj::get_font(){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_601_get_font)
HXDLIN( 601)		return this->_font;
            	}


HX_DEFINE_DYNAMIC_FUNC0(FlxText_obj,get_font,return )

::String FlxText_obj::set_font(::String Font){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_605_set_font)
HXLINE( 606)		this->textField->set_embedFonts(true);
HXLINE( 608)		if (::hx::IsNotNull( Font )) {
HXLINE( 610)			::String newFontName = Font;
HXLINE( 611)			if (::openfl::utils::Assets_obj::exists(Font,HX_("FONT",cf,25,81,2e))) {
HXLINE( 613)				newFontName = ::openfl::utils::Assets_obj::getFont(Font,null())->name;
            			}
HXLINE( 616)			this->_defaultFormat->font = newFontName;
            		}
            		else {
HXLINE( 620)			this->_defaultFormat->font = ::flixel::_hx_system::FlxAssets_obj::FONT_DEFAULT;
            		}
HXLINE( 623)		{
HXLINE( 623)			this->textField->set_defaultTextFormat(this->_defaultFormat);
HXDLIN( 623)			this->textField->setTextFormat(this->_defaultFormat,null(),null());
HXDLIN( 623)			this->_regen = true;
            		}
HXLINE( 624)		return (this->_font = this->_defaultFormat->font);
            	}


HX_DEFINE_DYNAMIC_FUNC1(FlxText_obj,set_font,return )

bool FlxText_obj::get_embedded(){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_629_get_embedded)
HXDLIN( 629)		return this->textField->set_embedFonts(true);
            	}


HX_DEFINE_DYNAMIC_FUNC0(FlxText_obj,get_embedded,return )

::String FlxText_obj::get_systemFont(){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_634_get_systemFont)
HXDLIN( 634)		return this->_defaultFormat->font;
            	}


HX_DEFINE_DYNAMIC_FUNC0(FlxText_obj,get_systemFont,return )

::String FlxText_obj::set_systemFont(::String Font){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_638_set_systemFont)
HXLINE( 639)		this->textField->set_embedFonts(false);
HXLINE( 640)		this->_defaultFormat->font = Font;
HXLINE( 641)		{
HXLINE( 641)			this->textField->set_defaultTextFormat(this->_defaultFormat);
HXDLIN( 641)			this->textField->setTextFormat(this->_defaultFormat,null(),null());
HXDLIN( 641)			this->_regen = true;
            		}
HXLINE( 642)		return Font;
            	}


HX_DEFINE_DYNAMIC_FUNC1(FlxText_obj,set_systemFont,return )

bool FlxText_obj::get_bold(){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_647_get_bold)
HXDLIN( 647)		return ( (bool)(this->_defaultFormat->bold) );
            	}


HX_DEFINE_DYNAMIC_FUNC0(FlxText_obj,get_bold,return )

bool FlxText_obj::set_bold(bool value){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_651_set_bold)
HXLINE( 652)		if (::hx::IsNotEq( this->_defaultFormat->bold,value )) {
HXLINE( 654)			this->_defaultFormat->bold = value;
HXLINE( 655)			{
HXLINE( 655)				this->textField->set_defaultTextFormat(this->_defaultFormat);
HXDLIN( 655)				this->textField->setTextFormat(this->_defaultFormat,null(),null());
HXDLIN( 655)				this->_regen = true;
            			}
            		}
HXLINE( 657)		return value;
            	}


HX_DEFINE_DYNAMIC_FUNC1(FlxText_obj,set_bold,return )

bool FlxText_obj::get_italic(){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_662_get_italic)
HXDLIN( 662)		return ( (bool)(this->_defaultFormat->italic) );
            	}


HX_DEFINE_DYNAMIC_FUNC0(FlxText_obj,get_italic,return )

bool FlxText_obj::set_italic(bool value){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_666_set_italic)
HXLINE( 667)		if (::hx::IsNotEq( this->_defaultFormat->italic,value )) {
HXLINE( 669)			this->_defaultFormat->italic = value;
HXLINE( 670)			{
HXLINE( 670)				this->textField->set_defaultTextFormat(this->_defaultFormat);
HXDLIN( 670)				this->textField->setTextFormat(this->_defaultFormat,null(),null());
HXDLIN( 670)				this->_regen = true;
            			}
            		}
HXLINE( 672)		return value;
            	}


HX_DEFINE_DYNAMIC_FUNC1(FlxText_obj,set_italic,return )

bool FlxText_obj::get_wordWrap(){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_677_get_wordWrap)
HXDLIN( 677)		return this->textField->get_wordWrap();
            	}


HX_DEFINE_DYNAMIC_FUNC0(FlxText_obj,get_wordWrap,return )

bool FlxText_obj::set_wordWrap(bool value){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_681_set_wordWrap)
HXLINE( 682)		if ((this->textField->get_wordWrap() != value)) {
HXLINE( 684)			this->textField->set_wordWrap(value);
HXLINE( 685)			this->_regen = true;
            		}
HXLINE( 687)		return value;
            	}


HX_DEFINE_DYNAMIC_FUNC1(FlxText_obj,set_wordWrap,return )

::String FlxText_obj::get_alignment(){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_692_get_alignment)
HXDLIN( 692)		return ::flixel::text::_FlxText::FlxTextAlign_Impl__obj::fromOpenFL(this->_defaultFormat->align);
            	}


HX_DEFINE_DYNAMIC_FUNC0(FlxText_obj,get_alignment,return )

::String FlxText_obj::set_alignment(::String Alignment){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_696_set_alignment)
HXLINE( 697)		this->_defaultFormat->align = ::flixel::text::_FlxText::FlxTextAlign_Impl__obj::toOpenFL(Alignment);
HXLINE( 698)		{
HXLINE( 698)			this->textField->set_defaultTextFormat(this->_defaultFormat);
HXDLIN( 698)			this->textField->setTextFormat(this->_defaultFormat,null(),null());
HXDLIN( 698)			this->_regen = true;
            		}
HXLINE( 699)		return Alignment;
            	}


HX_DEFINE_DYNAMIC_FUNC1(FlxText_obj,set_alignment,return )

 ::flixel::text::FlxTextBorderStyle FlxText_obj::set_borderStyle( ::flixel::text::FlxTextBorderStyle style){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_703_set_borderStyle)
HXLINE( 704)		if (::hx::IsPointerNotEq( style,this->borderStyle )) {
HXLINE( 705)			this->_regen = true;
            		}
HXLINE( 707)		return (this->borderStyle = style);
            	}


HX_DEFINE_DYNAMIC_FUNC1(FlxText_obj,set_borderStyle,return )

int FlxText_obj::set_borderColor(int Color){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_711_set_borderColor)
HXLINE( 712)		bool _hx_tmp;
HXDLIN( 712)		if ((this->borderColor != Color)) {
HXLINE( 712)			_hx_tmp = ::hx::IsPointerNotEq( this->borderStyle,::flixel::text::FlxTextBorderStyle_obj::NONE_dyn() );
            		}
            		else {
HXLINE( 712)			_hx_tmp = false;
            		}
HXDLIN( 712)		if (_hx_tmp) {
HXLINE( 713)			this->_regen = true;
            		}
HXLINE( 714)		this->_hasBorderAlpha = ((( (Float)(((Color >> 24) & 255)) ) / ( (Float)(255) )) < 1);
HXLINE( 715)		return (this->borderColor = Color);
            	}


HX_DEFINE_DYNAMIC_FUNC1(FlxText_obj,set_borderColor,return )

Float FlxText_obj::set_borderSize(Float Value){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_719_set_borderSize)
HXLINE( 720)		bool _hx_tmp;
HXDLIN( 720)		if ((Value != this->borderSize)) {
HXLINE( 720)			_hx_tmp = ::hx::IsPointerNotEq( this->borderStyle,::flixel::text::FlxTextBorderStyle_obj::NONE_dyn() );
            		}
            		else {
HXLINE( 720)			_hx_tmp = false;
            		}
HXDLIN( 720)		if (_hx_tmp) {
HXLINE( 721)			this->_regen = true;
            		}
HXLINE( 723)		return (this->borderSize = Value);
            	}


HX_DEFINE_DYNAMIC_FUNC1(FlxText_obj,set_borderSize,return )

Float FlxText_obj::set_borderQuality(Float Value){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_727_set_borderQuality)
HXLINE( 728)		Float lowerBound;
HXDLIN( 728)		if ((Value < 0)) {
HXLINE( 728)			lowerBound = ( (Float)(0) );
            		}
            		else {
HXLINE( 728)			lowerBound = Value;
            		}
HXDLIN( 728)		if ((lowerBound > 1)) {
HXLINE( 728)			Value = ( (Float)(1) );
            		}
            		else {
HXLINE( 728)			Value = lowerBound;
            		}
HXLINE( 729)		bool _hx_tmp;
HXDLIN( 729)		if ((Value != this->borderQuality)) {
HXLINE( 729)			_hx_tmp = ::hx::IsPointerNotEq( this->borderStyle,::flixel::text::FlxTextBorderStyle_obj::NONE_dyn() );
            		}
            		else {
HXLINE( 729)			_hx_tmp = false;
            		}
HXDLIN( 729)		if (_hx_tmp) {
HXLINE( 730)			this->_regen = true;
            		}
HXLINE( 732)		return (this->borderQuality = Value);
            	}


HX_DEFINE_DYNAMIC_FUNC1(FlxText_obj,set_borderQuality,return )

 ::flixel::graphics::FlxGraphic FlxText_obj::set_graphic( ::flixel::graphics::FlxGraphic Value){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_736_set_graphic)
HXLINE( 737)		 ::flixel::graphics::FlxGraphic oldGraphic = this->graphic;
HXLINE( 738)		 ::flixel::graphics::FlxGraphic graph = this->super::set_graphic(Value);
HXLINE( 739)		::flixel::FlxG_obj::bitmap->removeIfNoUse(oldGraphic);
HXLINE( 740)		return graph;
            	}


Float FlxText_obj::get_width(){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_744_get_width)
HXLINE( 745)		this->regenGraphic();
HXLINE( 746)		return this->super::get_width();
            	}


Float FlxText_obj::get_height(){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_750_get_height)
HXLINE( 751)		this->regenGraphic();
HXLINE( 752)		return this->super::get_height();
            	}


void FlxText_obj::updateColorTransform(){
            	HX_GC_STACKFRAME(&_hx_pos_7d9cf70d988be490_756_updateColorTransform)
HXLINE( 757)		if (::hx::IsNull( this->colorTransform )) {
HXLINE( 758)			this->colorTransform =  ::openfl::geom::ColorTransform_obj::__alloc( HX_CTX ,null(),null(),null(),null(),null(),null(),null(),null());
            		}
HXLINE( 760)		if ((this->alpha != 1)) {
HXLINE( 762)			this->colorTransform->alphaMultiplier = this->alpha;
HXLINE( 763)			this->useColorTransform = true;
            		}
            		else {
HXLINE( 767)			this->colorTransform->alphaMultiplier = ( (Float)(1) );
HXLINE( 768)			this->useColorTransform = false;
            		}
HXLINE( 771)		this->dirty = true;
            	}


void FlxText_obj::regenGraphic(){
            	HX_GC_STACKFRAME(&_hx_pos_7d9cf70d988be490_775_regenGraphic)
HXLINE( 776)		bool _hx_tmp;
HXDLIN( 776)		if (::hx::IsNotNull( this->textField )) {
HXLINE( 776)			_hx_tmp = !(this->_regen);
            		}
            		else {
HXLINE( 776)			_hx_tmp = true;
            		}
HXDLIN( 776)		if (_hx_tmp) {
HXLINE( 777)			return;
            		}
HXLINE( 779)		int oldWidth = 0;
HXLINE( 780)		int oldHeight = 4;
HXLINE( 782)		if (::hx::IsNotNull( this->graphic )) {
HXLINE( 784)			oldWidth = this->graphic->width;
HXLINE( 785)			oldHeight = this->graphic->height;
            		}
HXLINE( 788)		Float newWidth = this->textField->get_width();
HXLINE( 790)		Float newHeight = (this->textField->get_textHeight() + 4);
HXLINE( 793)		if ((this->textField->get_textHeight() == 0)) {
HXLINE( 795)			newHeight = ( (Float)(oldHeight) );
            		}
HXLINE( 798)		bool _hx_tmp1;
HXDLIN( 798)		if ((oldWidth == newWidth)) {
HXLINE( 798)			_hx_tmp1 = (oldHeight != newHeight);
            		}
            		else {
HXLINE( 798)			_hx_tmp1 = true;
            		}
HXDLIN( 798)		if (_hx_tmp1) {
HXLINE( 801)			this->set_height(newHeight);
HXLINE( 802)			::String key = ::flixel::FlxG_obj::bitmap->getUniqueKey(HX_("text",ad,cc,f9,4c));
HXLINE( 803)			int _hx_tmp = ::Std_obj::_hx_int(newWidth);
HXDLIN( 803)			this->makeGraphic(_hx_tmp,::Std_obj::_hx_int(newHeight),0,false,key);
HXLINE( 805)			if (this->_hasBorderAlpha) {
HXLINE( 806)				this->_borderPixels = this->graphic->bitmap->clone();
            			}
HXLINE( 807)			this->frameHeight = ::Std_obj::_hx_int(this->get_height());
HXLINE( 808)			 ::openfl::text::TextField _hx_tmp1 = this->textField;
HXDLIN( 808)			_hx_tmp1->set_height((this->get_height() * ((Float)1.2)));
HXLINE( 809)			this->_flashRect->x = ( (Float)(0) );
HXLINE( 810)			this->_flashRect->y = ( (Float)(0) );
HXLINE( 811)			this->_flashRect->width = newWidth;
HXLINE( 812)			this->_flashRect->height = newHeight;
            		}
            		else {
HXLINE( 816)			this->graphic->bitmap->fillRect(this->_flashRect,0);
HXLINE( 817)			if (this->_hasBorderAlpha) {
HXLINE( 819)				if (::hx::IsNull( this->_borderPixels )) {
HXLINE( 820)					this->_borderPixels =  ::openfl::display::BitmapData_obj::__alloc( HX_CTX ,this->frameWidth,this->frameHeight,true,null());
            				}
            				else {
HXLINE( 822)					this->_borderPixels->fillRect(this->_flashRect,0);
            				}
            			}
            		}
HXLINE( 826)		bool _hx_tmp2;
HXDLIN( 826)		bool _hx_tmp3;
HXDLIN( 826)		if (::hx::IsNotNull( this->textField )) {
HXLINE( 826)			_hx_tmp3 = ::hx::IsNotNull( this->textField->get_text() );
            		}
            		else {
HXLINE( 826)			_hx_tmp3 = false;
            		}
HXDLIN( 826)		if (_hx_tmp3) {
HXLINE( 826)			_hx_tmp2 = (this->textField->get_text().length > 0);
            		}
            		else {
HXLINE( 826)			_hx_tmp2 = false;
            		}
HXDLIN( 826)		if (_hx_tmp2) {
HXLINE( 829)			this->copyTextFormat(this->_defaultFormat,this->_formatAdjusted,null());
HXLINE( 831)			this->_matrix->identity();
HXLINE( 833)			this->applyBorderStyle();
HXLINE( 834)			if (this->_hasBorderAlpha) {
HXLINE( 834)				if (::hx::IsNull( this->_borderColorTransform )) {
HXLINE( 834)					this->_borderColorTransform =  ::openfl::geom::ColorTransform_obj::__alloc( HX_CTX ,null(),null(),null(),null(),null(),null(),null(),null());
            				}
HXDLIN( 834)				this->_borderColorTransform->alphaMultiplier = (( (Float)(((this->borderColor >> 24) & 255)) ) / ( (Float)(255) ));
HXDLIN( 834)				this->_borderPixels->colorTransform(this->_borderPixels->rect,this->_borderColorTransform);
HXDLIN( 834)				this->graphic->bitmap->draw(this->_borderPixels,null(),null(),null(),null(),null());
            			}
HXLINE( 835)			this->applyFormats(this->_formatAdjusted,false);
HXLINE( 837)			this->drawTextFieldTo(this->graphic->bitmap);
            		}
HXLINE( 840)		this->_regen = false;
HXLINE( 841)		this->set_frame(this->frame);
            	}


HX_DEFINE_DYNAMIC_FUNC0(FlxText_obj,regenGraphic,(void))

void FlxText_obj::drawTextFieldTo( ::openfl::display::BitmapData graphic){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_876_drawTextFieldTo)
HXDLIN( 876)		graphic->draw(this->textField,this->_matrix,null(),null(),null(),null());
            	}


HX_DEFINE_DYNAMIC_FUNC1(FlxText_obj,drawTextFieldTo,(void))

void FlxText_obj::draw(){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_898_draw)
HXLINE( 899)		this->regenGraphic();
HXLINE( 900)		this->super::draw();
            	}


void FlxText_obj::calcFrame(::hx::Null< bool >  __o_RunOnCpp){
            		bool RunOnCpp = __o_RunOnCpp.Default(false);
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_909_calcFrame)
HXLINE( 910)		if (::hx::IsNull( this->textField )) {
HXLINE( 911)			return;
            		}
HXLINE( 913)		bool _hx_tmp;
HXDLIN( 913)		if (::flixel::FlxG_obj::renderTile) {
HXLINE( 913)			_hx_tmp = !(RunOnCpp);
            		}
            		else {
HXLINE( 913)			_hx_tmp = false;
            		}
HXDLIN( 913)		if (_hx_tmp) {
HXLINE( 914)			return;
            		}
HXLINE( 916)		this->regenGraphic();
HXLINE( 917)		this->super::calcFrame(RunOnCpp);
            	}


void FlxText_obj::applyBorderStyle(){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_921_applyBorderStyle)
HXLINE( 922)		int iterations = ::Std_obj::_hx_int((this->borderSize * this->borderQuality));
HXLINE( 923)		if ((iterations <= 0)) {
HXLINE( 925)			iterations = 1;
            		}
HXLINE( 927)		Float delta = (this->borderSize / ( (Float)(iterations) ));
HXLINE( 929)		switch((int)(this->borderStyle->_hx_getIndex())){
            			case (int)0: {
            			}
            			break;
            			case (int)1: {
HXLINE( 934)				this->applyFormats(this->_formatAdjusted,true);
HXLINE( 936)				{
HXLINE( 936)					int _g = 0;
HXDLIN( 936)					int _g1 = iterations;
HXDLIN( 936)					while((_g < _g1)){
HXLINE( 936)						_g = (_g + 1);
HXDLIN( 936)						int i = (_g - 1);
HXLINE( 938)						{
HXLINE( 938)							 ::openfl::display::BitmapData graphic;
HXDLIN( 938)							if (this->_hasBorderAlpha) {
HXLINE( 938)								graphic = this->_borderPixels;
            							}
            							else {
HXLINE( 938)								graphic = this->graphic->bitmap;
            							}
HXDLIN( 938)							this->_matrix->translate(delta,delta);
HXDLIN( 938)							this->drawTextFieldTo(graphic);
            						}
            					}
            				}
HXLINE( 941)				this->_matrix->translate((-(this->shadowOffset->x) * this->borderSize),(-(this->shadowOffset->y) * this->borderSize));
            			}
            			break;
            			case (int)2: {
HXLINE( 946)				this->applyFormats(this->_formatAdjusted,true);
HXLINE( 948)				Float curDelta = delta;
HXLINE( 949)				{
HXLINE( 949)					int _g = 0;
HXDLIN( 949)					int _g1 = iterations;
HXDLIN( 949)					while((_g < _g1)){
HXLINE( 949)						_g = (_g + 1);
HXDLIN( 949)						int i = (_g - 1);
HXLINE( 951)						{
HXLINE( 951)							 ::openfl::display::BitmapData graphic;
HXDLIN( 951)							if (this->_hasBorderAlpha) {
HXLINE( 951)								graphic = this->_borderPixels;
            							}
            							else {
HXLINE( 951)								graphic = this->graphic->bitmap;
            							}
HXDLIN( 951)							this->_matrix->translate(-(curDelta),-(curDelta));
HXDLIN( 951)							this->drawTextFieldTo(graphic);
            						}
HXLINE( 952)						{
HXLINE( 952)							 ::openfl::display::BitmapData graphic1;
HXDLIN( 952)							if (this->_hasBorderAlpha) {
HXLINE( 952)								graphic1 = this->_borderPixels;
            							}
            							else {
HXLINE( 952)								graphic1 = this->graphic->bitmap;
            							}
HXDLIN( 952)							this->_matrix->translate(curDelta,( (Float)(0) ));
HXDLIN( 952)							this->drawTextFieldTo(graphic1);
            						}
HXLINE( 953)						{
HXLINE( 953)							 ::openfl::display::BitmapData graphic2;
HXDLIN( 953)							if (this->_hasBorderAlpha) {
HXLINE( 953)								graphic2 = this->_borderPixels;
            							}
            							else {
HXLINE( 953)								graphic2 = this->graphic->bitmap;
            							}
HXDLIN( 953)							this->_matrix->translate(curDelta,( (Float)(0) ));
HXDLIN( 953)							this->drawTextFieldTo(graphic2);
            						}
HXLINE( 954)						{
HXLINE( 954)							 ::openfl::display::BitmapData graphic3;
HXDLIN( 954)							if (this->_hasBorderAlpha) {
HXLINE( 954)								graphic3 = this->_borderPixels;
            							}
            							else {
HXLINE( 954)								graphic3 = this->graphic->bitmap;
            							}
HXDLIN( 954)							this->_matrix->translate(( (Float)(0) ),curDelta);
HXDLIN( 954)							this->drawTextFieldTo(graphic3);
            						}
HXLINE( 955)						{
HXLINE( 955)							 ::openfl::display::BitmapData graphic4;
HXDLIN( 955)							if (this->_hasBorderAlpha) {
HXLINE( 955)								graphic4 = this->_borderPixels;
            							}
            							else {
HXLINE( 955)								graphic4 = this->graphic->bitmap;
            							}
HXDLIN( 955)							this->_matrix->translate(( (Float)(0) ),curDelta);
HXDLIN( 955)							this->drawTextFieldTo(graphic4);
            						}
HXLINE( 956)						{
HXLINE( 956)							 ::openfl::display::BitmapData graphic5;
HXDLIN( 956)							if (this->_hasBorderAlpha) {
HXLINE( 956)								graphic5 = this->_borderPixels;
            							}
            							else {
HXLINE( 956)								graphic5 = this->graphic->bitmap;
            							}
HXDLIN( 956)							this->_matrix->translate(-(curDelta),( (Float)(0) ));
HXDLIN( 956)							this->drawTextFieldTo(graphic5);
            						}
HXLINE( 957)						{
HXLINE( 957)							 ::openfl::display::BitmapData graphic6;
HXDLIN( 957)							if (this->_hasBorderAlpha) {
HXLINE( 957)								graphic6 = this->_borderPixels;
            							}
            							else {
HXLINE( 957)								graphic6 = this->graphic->bitmap;
            							}
HXDLIN( 957)							this->_matrix->translate(-(curDelta),( (Float)(0) ));
HXDLIN( 957)							this->drawTextFieldTo(graphic6);
            						}
HXLINE( 958)						{
HXLINE( 958)							 ::openfl::display::BitmapData graphic7;
HXDLIN( 958)							if (this->_hasBorderAlpha) {
HXLINE( 958)								graphic7 = this->_borderPixels;
            							}
            							else {
HXLINE( 958)								graphic7 = this->graphic->bitmap;
            							}
HXDLIN( 958)							this->_matrix->translate(( (Float)(0) ),-(curDelta));
HXDLIN( 958)							this->drawTextFieldTo(graphic7);
            						}
HXLINE( 960)						this->_matrix->translate(curDelta,( (Float)(0) ));
HXLINE( 961)						curDelta = (curDelta + delta);
            					}
            				}
            			}
            			break;
            			case (int)3: {
HXLINE( 968)				this->applyFormats(this->_formatAdjusted,true);
HXLINE( 970)				Float curDelta = delta;
HXLINE( 971)				{
HXLINE( 971)					int _g = 0;
HXDLIN( 971)					int _g1 = iterations;
HXDLIN( 971)					while((_g < _g1)){
HXLINE( 971)						_g = (_g + 1);
HXDLIN( 971)						int i = (_g - 1);
HXLINE( 973)						{
HXLINE( 973)							 ::openfl::display::BitmapData graphic;
HXDLIN( 973)							if (this->_hasBorderAlpha) {
HXLINE( 973)								graphic = this->_borderPixels;
            							}
            							else {
HXLINE( 973)								graphic = this->graphic->bitmap;
            							}
HXDLIN( 973)							this->_matrix->translate(-(curDelta),-(curDelta));
HXDLIN( 973)							this->drawTextFieldTo(graphic);
            						}
HXLINE( 974)						{
HXLINE( 974)							 ::openfl::display::BitmapData graphic1;
HXDLIN( 974)							if (this->_hasBorderAlpha) {
HXLINE( 974)								graphic1 = this->_borderPixels;
            							}
            							else {
HXLINE( 974)								graphic1 = this->graphic->bitmap;
            							}
HXDLIN( 974)							this->_matrix->translate((curDelta * ( (Float)(2) )),( (Float)(0) ));
HXDLIN( 974)							this->drawTextFieldTo(graphic1);
            						}
HXLINE( 975)						{
HXLINE( 975)							 ::openfl::display::BitmapData graphic2;
HXDLIN( 975)							if (this->_hasBorderAlpha) {
HXLINE( 975)								graphic2 = this->_borderPixels;
            							}
            							else {
HXLINE( 975)								graphic2 = this->graphic->bitmap;
            							}
HXDLIN( 975)							this->_matrix->translate(( (Float)(0) ),(curDelta * ( (Float)(2) )));
HXDLIN( 975)							this->drawTextFieldTo(graphic2);
            						}
HXLINE( 976)						{
HXLINE( 976)							 ::openfl::display::BitmapData graphic3;
HXDLIN( 976)							if (this->_hasBorderAlpha) {
HXLINE( 976)								graphic3 = this->_borderPixels;
            							}
            							else {
HXLINE( 976)								graphic3 = this->graphic->bitmap;
            							}
HXDLIN( 976)							this->_matrix->translate((-(curDelta) * ( (Float)(2) )),( (Float)(0) ));
HXDLIN( 976)							this->drawTextFieldTo(graphic3);
            						}
HXLINE( 978)						this->_matrix->translate(curDelta,-(curDelta));
HXLINE( 979)						curDelta = (curDelta + delta);
            					}
            				}
            			}
            			break;
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC0(FlxText_obj,applyBorderStyle,(void))

void FlxText_obj::applyBorderTransparency(){
            	HX_GC_STACKFRAME(&_hx_pos_7d9cf70d988be490_987_applyBorderTransparency)
HXLINE( 988)		if (!(this->_hasBorderAlpha)) {
HXLINE( 989)			return;
            		}
HXLINE( 991)		if (::hx::IsNull( this->_borderColorTransform )) {
HXLINE( 992)			this->_borderColorTransform =  ::openfl::geom::ColorTransform_obj::__alloc( HX_CTX ,null(),null(),null(),null(),null(),null(),null(),null());
            		}
HXLINE( 994)		this->_borderColorTransform->alphaMultiplier = (( (Float)(((this->borderColor >> 24) & 255)) ) / ( (Float)(255) ));
HXLINE( 995)		this->_borderPixels->colorTransform(this->_borderPixels->rect,this->_borderColorTransform);
HXLINE( 996)		this->graphic->bitmap->draw(this->_borderPixels,null(),null(),null(),null(),null());
            	}


HX_DEFINE_DYNAMIC_FUNC0(FlxText_obj,applyBorderTransparency,(void))

void FlxText_obj::copyTextWithOffset(Float x,Float y){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_1003_copyTextWithOffset)
HXLINE(1004)		 ::openfl::display::BitmapData graphic;
HXDLIN(1004)		if (this->_hasBorderAlpha) {
HXLINE(1004)			graphic = this->_borderPixels;
            		}
            		else {
HXLINE(1004)			graphic = this->graphic->bitmap;
            		}
HXLINE(1005)		this->_matrix->translate(x,y);
HXLINE(1006)		this->drawTextFieldTo(graphic);
            	}


HX_DEFINE_DYNAMIC_FUNC2(FlxText_obj,copyTextWithOffset,(void))

void FlxText_obj::applyFormats( ::openfl::text::TextFormat FormatAdjusted,::hx::Null< bool >  __o_UseBorderColor){
            		bool UseBorderColor = __o_UseBorderColor.Default(false);
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_1010_applyFormats)
HXLINE(1012)		this->copyTextFormat(this->_defaultFormat,FormatAdjusted,false);
HXLINE(1013)		 ::Dynamic _hx_tmp;
HXDLIN(1013)		if (UseBorderColor) {
HXLINE(1013)			_hx_tmp = (this->borderColor & 16777215);
            		}
            		else {
HXLINE(1013)			_hx_tmp = this->_defaultFormat->color;
            		}
HXDLIN(1013)		FormatAdjusted->color = _hx_tmp;
HXLINE(1014)		this->textField->setTextFormat(FormatAdjusted,null(),null());
HXLINE(1017)		{
HXLINE(1017)			int _g = 0;
HXDLIN(1017)			::Array< ::Dynamic> _g1 = this->_formatRanges;
HXDLIN(1017)			while((_g < _g1->length)){
HXLINE(1017)				 ::flixel::text::_FlxText::FlxTextFormatRange formatRange = _g1->__get(_g).StaticCast<  ::flixel::text::_FlxText::FlxTextFormatRange >();
HXDLIN(1017)				_g = (_g + 1);
HXLINE(1019)				int _hx_tmp = (this->textField->get_text().length - 1);
HXDLIN(1019)				if (::hx::IsLess( _hx_tmp,formatRange->range->start )) {
HXLINE(1022)					goto _hx_goto_59;
            				}
            				else {
HXLINE(1026)					 ::openfl::text::TextFormat textFormat = formatRange->format->format;
HXLINE(1027)					this->copyTextFormat(textFormat,FormatAdjusted,false);
HXLINE(1028)					 ::Dynamic _hx_tmp;
HXDLIN(1028)					if (UseBorderColor) {
HXLINE(1028)						_hx_tmp = (formatRange->format->borderColor & 16777215);
            					}
            					else {
HXLINE(1028)						_hx_tmp = textFormat->color;
            					}
HXDLIN(1028)					FormatAdjusted->color = _hx_tmp;
            				}
HXLINE(1031)				 ::openfl::text::TextField _hx_tmp1 = this->textField;
HXDLIN(1031)				int formatRange1 = ( (int)(formatRange->range->start) );
HXDLIN(1031)				int formatRange2 = ( (int)(formatRange->range->end) );
HXDLIN(1031)				_hx_tmp1->setTextFormat(FormatAdjusted,formatRange1,::Std_obj::_hx_int(::Math_obj::min(( (Float)(formatRange2) ),( (Float)(this->textField->get_text().length) ))));
            			}
            			_hx_goto_59:;
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC2(FlxText_obj,applyFormats,(void))

void FlxText_obj::copyTextFormat( ::openfl::text::TextFormat from, ::openfl::text::TextFormat to,::hx::Null< bool >  __o_withAlign){
            		bool withAlign = __o_withAlign.Default(true);
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_1036_copyTextFormat)
HXLINE(1037)		to->font = from->font;
HXLINE(1038)		to->bold = from->bold;
HXLINE(1039)		to->italic = from->italic;
HXLINE(1040)		to->size = from->size;
HXLINE(1041)		to->color = from->color;
HXLINE(1042)		to->leading = from->leading;
HXLINE(1043)		if (withAlign) {
HXLINE(1044)			to->align = from->align;
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC3(FlxText_obj,copyTextFormat,(void))

 ::openfl::text::TextFormat FlxText_obj::dtfCopy(){
            	HX_GC_STACKFRAME(&_hx_pos_7d9cf70d988be490_1053_dtfCopy)
HXLINE(1054)		 ::openfl::text::TextFormat dtf = this->textField->get_defaultTextFormat();
HXLINE(1055)		return  ::openfl::text::TextFormat_obj::__alloc( HX_CTX ,dtf->font,dtf->size,dtf->color,dtf->bold,dtf->italic,dtf->underline,dtf->url,dtf->target,dtf->align,null(),null(),null(),null());
            	}


HX_DEFINE_DYNAMIC_FUNC0(FlxText_obj,dtfCopy,return )

void FlxText_obj::updateDefaultFormat(){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_1059_updateDefaultFormat)
HXLINE(1060)		this->textField->set_defaultTextFormat(this->_defaultFormat);
HXLINE(1061)		this->textField->setTextFormat(this->_defaultFormat,null(),null());
HXLINE(1062)		this->_regen = true;
            	}


HX_DEFINE_DYNAMIC_FUNC0(FlxText_obj,updateDefaultFormat,(void))

 ::flixel::graphics::frames::FlxFramesCollection FlxText_obj::set_frames( ::flixel::graphics::frames::FlxFramesCollection Frames){
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_1066_set_frames)
HXLINE(1067)		this->super::set_frames(Frames);
HXLINE(1068)		this->_regen = false;
HXLINE(1069)		return Frames;
            	}


int FlxText_obj::VERTICAL_GUTTER;


::hx::ObjectPtr< FlxText_obj > FlxText_obj::__new(::hx::Null< Float >  __o_X,::hx::Null< Float >  __o_Y,::hx::Null< Float >  __o_FieldWidth,::String Text,::hx::Null< int >  __o_Size,::hx::Null< bool >  __o_EmbeddedFont) {
	::hx::ObjectPtr< FlxText_obj > __this = new FlxText_obj();
	__this->__construct(__o_X,__o_Y,__o_FieldWidth,Text,__o_Size,__o_EmbeddedFont);
	return __this;
}

::hx::ObjectPtr< FlxText_obj > FlxText_obj::__alloc(::hx::Ctx *_hx_ctx,::hx::Null< Float >  __o_X,::hx::Null< Float >  __o_Y,::hx::Null< Float >  __o_FieldWidth,::String Text,::hx::Null< int >  __o_Size,::hx::Null< bool >  __o_EmbeddedFont) {
	FlxText_obj *__this = (FlxText_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(FlxText_obj), true, "flixel.text.FlxText"));
	*(void **)__this = FlxText_obj::_hx_vtable;
	__this->__construct(__o_X,__o_Y,__o_FieldWidth,Text,__o_Size,__o_EmbeddedFont);
	return __this;
}

FlxText_obj::FlxText_obj()
{
}

void FlxText_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxText);
	HX_MARK_MEMBER_NAME(text,"text");
	HX_MARK_MEMBER_NAME(borderStyle,"borderStyle");
	HX_MARK_MEMBER_NAME(borderColor,"borderColor");
	HX_MARK_MEMBER_NAME(borderSize,"borderSize");
	HX_MARK_MEMBER_NAME(borderQuality,"borderQuality");
	HX_MARK_MEMBER_NAME(textField,"textField");
	HX_MARK_MEMBER_NAME(shadowOffset,"shadowOffset");
	HX_MARK_MEMBER_NAME(_defaultFormat,"_defaultFormat");
	HX_MARK_MEMBER_NAME(_formatAdjusted,"_formatAdjusted");
	HX_MARK_MEMBER_NAME(_formatRanges,"_formatRanges");
	HX_MARK_MEMBER_NAME(_font,"_font");
	HX_MARK_MEMBER_NAME(_regen,"_regen");
	HX_MARK_MEMBER_NAME(_borderPixels,"_borderPixels");
	HX_MARK_MEMBER_NAME(_borderColorTransform,"_borderColorTransform");
	HX_MARK_MEMBER_NAME(_hasBorderAlpha,"_hasBorderAlpha");
	 ::flixel::FlxSprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FlxText_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(text,"text");
	HX_VISIT_MEMBER_NAME(borderStyle,"borderStyle");
	HX_VISIT_MEMBER_NAME(borderColor,"borderColor");
	HX_VISIT_MEMBER_NAME(borderSize,"borderSize");
	HX_VISIT_MEMBER_NAME(borderQuality,"borderQuality");
	HX_VISIT_MEMBER_NAME(textField,"textField");
	HX_VISIT_MEMBER_NAME(shadowOffset,"shadowOffset");
	HX_VISIT_MEMBER_NAME(_defaultFormat,"_defaultFormat");
	HX_VISIT_MEMBER_NAME(_formatAdjusted,"_formatAdjusted");
	HX_VISIT_MEMBER_NAME(_formatRanges,"_formatRanges");
	HX_VISIT_MEMBER_NAME(_font,"_font");
	HX_VISIT_MEMBER_NAME(_regen,"_regen");
	HX_VISIT_MEMBER_NAME(_borderPixels,"_borderPixels");
	HX_VISIT_MEMBER_NAME(_borderColorTransform,"_borderColorTransform");
	HX_VISIT_MEMBER_NAME(_hasBorderAlpha,"_hasBorderAlpha");
	 ::flixel::FlxSprite_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val FlxText_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"text") ) { return ::hx::Val( text ); }
		if (HX_FIELD_EQ(inName,"size") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_size() ); }
		if (HX_FIELD_EQ(inName,"font") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_font() ); }
		if (HX_FIELD_EQ(inName,"bold") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_bold() ); }
		if (HX_FIELD_EQ(inName,"draw") ) { return ::hx::Val( draw_dyn() ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_font") ) { return ::hx::Val( _font ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"italic") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_italic() ); }
		if (HX_FIELD_EQ(inName,"_regen") ) { return ::hx::Val( _regen ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return ::hx::Val( destroy_dyn() ); }
		if (HX_FIELD_EQ(inName,"dtfCopy") ) { return ::hx::Val( dtfCopy_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"embedded") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_embedded() ); }
		if (HX_FIELD_EQ(inName,"wordWrap") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_wordWrap() ); }
		if (HX_FIELD_EQ(inName,"autoSize") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_autoSize() ); }
		if (HX_FIELD_EQ(inName,"set_text") ) { return ::hx::Val( set_text_dyn() ); }
		if (HX_FIELD_EQ(inName,"get_size") ) { return ::hx::Val( get_size_dyn() ); }
		if (HX_FIELD_EQ(inName,"set_size") ) { return ::hx::Val( set_size_dyn() ); }
		if (HX_FIELD_EQ(inName,"get_font") ) { return ::hx::Val( get_font_dyn() ); }
		if (HX_FIELD_EQ(inName,"set_font") ) { return ::hx::Val( set_font_dyn() ); }
		if (HX_FIELD_EQ(inName,"get_bold") ) { return ::hx::Val( get_bold_dyn() ); }
		if (HX_FIELD_EQ(inName,"set_bold") ) { return ::hx::Val( set_bold_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"alignment") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_alignment() ); }
		if (HX_FIELD_EQ(inName,"textField") ) { return ::hx::Val( textField ); }
		if (HX_FIELD_EQ(inName,"drawFrame") ) { return ::hx::Val( drawFrame_dyn() ); }
		if (HX_FIELD_EQ(inName,"addFormat") ) { return ::hx::Val( addFormat_dyn() ); }
		if (HX_FIELD_EQ(inName,"setFormat") ) { return ::hx::Val( setFormat_dyn() ); }
		if (HX_FIELD_EQ(inName,"set_color") ) { return ::hx::Val( set_color_dyn() ); }
		if (HX_FIELD_EQ(inName,"get_width") ) { return ::hx::Val( get_width_dyn() ); }
		if (HX_FIELD_EQ(inName,"calcFrame") ) { return ::hx::Val( calcFrame_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"systemFont") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_systemFont() ); }
		if (HX_FIELD_EQ(inName,"borderSize") ) { return ::hx::Val( borderSize ); }
		if (HX_FIELD_EQ(inName,"fieldWidth") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_fieldWidth() ); }
		if (HX_FIELD_EQ(inName,"get_italic") ) { return ::hx::Val( get_italic_dyn() ); }
		if (HX_FIELD_EQ(inName,"set_italic") ) { return ::hx::Val( set_italic_dyn() ); }
		if (HX_FIELD_EQ(inName,"get_height") ) { return ::hx::Val( get_height_dyn() ); }
		if (HX_FIELD_EQ(inName,"set_frames") ) { return ::hx::Val( set_frames_dyn() ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"borderStyle") ) { return ::hx::Val( borderStyle ); }
		if (HX_FIELD_EQ(inName,"borderColor") ) { return ::hx::Val( borderColor ); }
		if (HX_FIELD_EQ(inName,"applyMarkup") ) { return ::hx::Val( applyMarkup_dyn() ); }
		if (HX_FIELD_EQ(inName,"set_graphic") ) { return ::hx::Val( set_graphic_dyn() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"shadowOffset") ) { return ::hx::Val( shadowOffset ); }
		if (HX_FIELD_EQ(inName,"stampOnAtlas") ) { return ::hx::Val( stampOnAtlas_dyn() ); }
		if (HX_FIELD_EQ(inName,"removeFormat") ) { return ::hx::Val( removeFormat_dyn() ); }
		if (HX_FIELD_EQ(inName,"clearFormats") ) { return ::hx::Val( clearFormats_dyn() ); }
		if (HX_FIELD_EQ(inName,"updateHitbox") ) { return ::hx::Val( updateHitbox_dyn() ); }
		if (HX_FIELD_EQ(inName,"set_autoSize") ) { return ::hx::Val( set_autoSize_dyn() ); }
		if (HX_FIELD_EQ(inName,"get_autoSize") ) { return ::hx::Val( get_autoSize_dyn() ); }
		if (HX_FIELD_EQ(inName,"get_embedded") ) { return ::hx::Val( get_embedded_dyn() ); }
		if (HX_FIELD_EQ(inName,"get_wordWrap") ) { return ::hx::Val( get_wordWrap_dyn() ); }
		if (HX_FIELD_EQ(inName,"set_wordWrap") ) { return ::hx::Val( set_wordWrap_dyn() ); }
		if (HX_FIELD_EQ(inName,"regenGraphic") ) { return ::hx::Val( regenGraphic_dyn() ); }
		if (HX_FIELD_EQ(inName,"applyFormats") ) { return ::hx::Val( applyFormats_dyn() ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"borderQuality") ) { return ::hx::Val( borderQuality ); }
		if (HX_FIELD_EQ(inName,"_formatRanges") ) { return ::hx::Val( _formatRanges ); }
		if (HX_FIELD_EQ(inName,"_borderPixels") ) { return ::hx::Val( _borderPixels ); }
		if (HX_FIELD_EQ(inName,"get_alignment") ) { return ::hx::Val( get_alignment_dyn() ); }
		if (HX_FIELD_EQ(inName,"set_alignment") ) { return ::hx::Val( set_alignment_dyn() ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_defaultFormat") ) { return ::hx::Val( _defaultFormat ); }
		if (HX_FIELD_EQ(inName,"setBorderStyle") ) { return ::hx::Val( setBorderStyle_dyn() ); }
		if (HX_FIELD_EQ(inName,"set_fieldWidth") ) { return ::hx::Val( set_fieldWidth_dyn() ); }
		if (HX_FIELD_EQ(inName,"get_fieldWidth") ) { return ::hx::Val( get_fieldWidth_dyn() ); }
		if (HX_FIELD_EQ(inName,"get_systemFont") ) { return ::hx::Val( get_systemFont_dyn() ); }
		if (HX_FIELD_EQ(inName,"set_systemFont") ) { return ::hx::Val( set_systemFont_dyn() ); }
		if (HX_FIELD_EQ(inName,"set_borderSize") ) { return ::hx::Val( set_borderSize_dyn() ); }
		if (HX_FIELD_EQ(inName,"copyTextFormat") ) { return ::hx::Val( copyTextFormat_dyn() ); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_formatAdjusted") ) { return ::hx::Val( _formatAdjusted ); }
		if (HX_FIELD_EQ(inName,"_hasBorderAlpha") ) { return ::hx::Val( _hasBorderAlpha ); }
		if (HX_FIELD_EQ(inName,"set_borderStyle") ) { return ::hx::Val( set_borderStyle_dyn() ); }
		if (HX_FIELD_EQ(inName,"set_borderColor") ) { return ::hx::Val( set_borderColor_dyn() ); }
		if (HX_FIELD_EQ(inName,"drawTextFieldTo") ) { return ::hx::Val( drawTextFieldTo_dyn() ); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"applyBorderStyle") ) { return ::hx::Val( applyBorderStyle_dyn() ); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"set_borderQuality") ) { return ::hx::Val( set_borderQuality_dyn() ); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"copyTextWithOffset") ) { return ::hx::Val( copyTextWithOffset_dyn() ); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"updateDefaultFormat") ) { return ::hx::Val( updateDefaultFormat_dyn() ); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"updateColorTransform") ) { return ::hx::Val( updateColorTransform_dyn() ); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"_borderColorTransform") ) { return ::hx::Val( _borderColorTransform ); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"applyBorderTransparency") ) { return ::hx::Val( applyBorderTransparency_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val FlxText_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"text") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_text(inValue.Cast< ::String >()) );text=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"size") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_size(inValue.Cast< int >()) ); }
		if (HX_FIELD_EQ(inName,"font") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_font(inValue.Cast< ::String >()) ); }
		if (HX_FIELD_EQ(inName,"bold") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_bold(inValue.Cast< bool >()) ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_font") ) { _font=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"italic") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_italic(inValue.Cast< bool >()) ); }
		if (HX_FIELD_EQ(inName,"_regen") ) { _regen=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"wordWrap") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_wordWrap(inValue.Cast< bool >()) ); }
		if (HX_FIELD_EQ(inName,"autoSize") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_autoSize(inValue.Cast< bool >()) ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"alignment") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_alignment(inValue.Cast< ::String >()) ); }
		if (HX_FIELD_EQ(inName,"textField") ) { textField=inValue.Cast<  ::openfl::text::TextField >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"systemFont") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_systemFont(inValue.Cast< ::String >()) ); }
		if (HX_FIELD_EQ(inName,"borderSize") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_borderSize(inValue.Cast< Float >()) );borderSize=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fieldWidth") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_fieldWidth(inValue.Cast< Float >()) ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"borderStyle") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_borderStyle(inValue.Cast<  ::flixel::text::FlxTextBorderStyle >()) );borderStyle=inValue.Cast<  ::flixel::text::FlxTextBorderStyle >(); return inValue; }
		if (HX_FIELD_EQ(inName,"borderColor") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_borderColor(inValue.Cast< int >()) );borderColor=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"shadowOffset") ) { shadowOffset=inValue.Cast<  ::flixel::math::FlxPoint >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"borderQuality") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_borderQuality(inValue.Cast< Float >()) );borderQuality=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_formatRanges") ) { _formatRanges=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_borderPixels") ) { _borderPixels=inValue.Cast<  ::openfl::display::BitmapData >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_defaultFormat") ) { _defaultFormat=inValue.Cast<  ::openfl::text::TextFormat >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_formatAdjusted") ) { _formatAdjusted=inValue.Cast<  ::openfl::text::TextFormat >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_hasBorderAlpha") ) { _hasBorderAlpha=inValue.Cast< bool >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"_borderColorTransform") ) { _borderColorTransform=inValue.Cast<  ::openfl::geom::ColorTransform >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxText_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("text",ad,cc,f9,4c));
	outFields->push(HX_("size",c1,a0,53,4c));
	outFields->push(HX_("font",cf,5d,c0,43));
	outFields->push(HX_("embedded",8a,19,62,de));
	outFields->push(HX_("systemFont",5e,c4,43,f2));
	outFields->push(HX_("bold",85,81,1b,41));
	outFields->push(HX_("italic",f0,2e,64,06));
	outFields->push(HX_("wordWrap",b4,14,db,00));
	outFields->push(HX_("alignment",e3,e2,3d,ea));
	outFields->push(HX_("borderStyle",a5,70,96,10));
	outFields->push(HX_("borderColor",d7,3c,d5,d6));
	outFields->push(HX_("borderSize",cd,ff,ed,06));
	outFields->push(HX_("borderQuality",33,95,25,79));
	outFields->push(HX_("textField",cd,24,81,99));
	outFields->push(HX_("fieldWidth",ec,2e,e5,97));
	outFields->push(HX_("autoSize",d0,8f,79,2f));
	outFields->push(HX_("shadowOffset",93,fb,0b,dc));
	outFields->push(HX_("_defaultFormat",19,53,59,36));
	outFields->push(HX_("_formatAdjusted",a4,c9,b6,80));
	outFields->push(HX_("_formatRanges",8c,b9,14,d7));
	outFields->push(HX_("_font",ae,79,d1,f6));
	outFields->push(HX_("_regen",fe,75,a6,e2));
	outFields->push(HX_("_borderPixels",18,bc,51,cc));
	outFields->push(HX_("_borderColorTransform",74,07,2f,6f));
	outFields->push(HX_("_hasBorderAlpha",37,fe,f9,e8));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo FlxText_obj_sMemberStorageInfo[] = {
	{::hx::fsString,(int)offsetof(FlxText_obj,text),HX_("text",ad,cc,f9,4c)},
	{::hx::fsObject /*  ::flixel::text::FlxTextBorderStyle */ ,(int)offsetof(FlxText_obj,borderStyle),HX_("borderStyle",a5,70,96,10)},
	{::hx::fsInt,(int)offsetof(FlxText_obj,borderColor),HX_("borderColor",d7,3c,d5,d6)},
	{::hx::fsFloat,(int)offsetof(FlxText_obj,borderSize),HX_("borderSize",cd,ff,ed,06)},
	{::hx::fsFloat,(int)offsetof(FlxText_obj,borderQuality),HX_("borderQuality",33,95,25,79)},
	{::hx::fsObject /*  ::openfl::text::TextField */ ,(int)offsetof(FlxText_obj,textField),HX_("textField",cd,24,81,99)},
	{::hx::fsObject /*  ::flixel::math::FlxPoint */ ,(int)offsetof(FlxText_obj,shadowOffset),HX_("shadowOffset",93,fb,0b,dc)},
	{::hx::fsObject /*  ::openfl::text::TextFormat */ ,(int)offsetof(FlxText_obj,_defaultFormat),HX_("_defaultFormat",19,53,59,36)},
	{::hx::fsObject /*  ::openfl::text::TextFormat */ ,(int)offsetof(FlxText_obj,_formatAdjusted),HX_("_formatAdjusted",a4,c9,b6,80)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(FlxText_obj,_formatRanges),HX_("_formatRanges",8c,b9,14,d7)},
	{::hx::fsString,(int)offsetof(FlxText_obj,_font),HX_("_font",ae,79,d1,f6)},
	{::hx::fsBool,(int)offsetof(FlxText_obj,_regen),HX_("_regen",fe,75,a6,e2)},
	{::hx::fsObject /*  ::openfl::display::BitmapData */ ,(int)offsetof(FlxText_obj,_borderPixels),HX_("_borderPixels",18,bc,51,cc)},
	{::hx::fsObject /*  ::openfl::geom::ColorTransform */ ,(int)offsetof(FlxText_obj,_borderColorTransform),HX_("_borderColorTransform",74,07,2f,6f)},
	{::hx::fsBool,(int)offsetof(FlxText_obj,_hasBorderAlpha),HX_("_hasBorderAlpha",37,fe,f9,e8)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo FlxText_obj_sStaticStorageInfo[] = {
	{::hx::fsInt,(void *) &FlxText_obj::VERTICAL_GUTTER,HX_("VERTICAL_GUTTER",04,b3,89,07)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static ::String FlxText_obj_sMemberFields[] = {
	HX_("text",ad,cc,f9,4c),
	HX_("borderStyle",a5,70,96,10),
	HX_("borderColor",d7,3c,d5,d6),
	HX_("borderSize",cd,ff,ed,06),
	HX_("borderQuality",33,95,25,79),
	HX_("textField",cd,24,81,99),
	HX_("shadowOffset",93,fb,0b,dc),
	HX_("_defaultFormat",19,53,59,36),
	HX_("_formatAdjusted",a4,c9,b6,80),
	HX_("_formatRanges",8c,b9,14,d7),
	HX_("_font",ae,79,d1,f6),
	HX_("_regen",fe,75,a6,e2),
	HX_("_borderPixels",18,bc,51,cc),
	HX_("_borderColorTransform",74,07,2f,6f),
	HX_("_hasBorderAlpha",37,fe,f9,e8),
	HX_("destroy",fa,2c,86,24),
	HX_("drawFrame",89,ad,8e,ce),
	HX_("stampOnAtlas",e9,f9,45,2b),
	HX_("applyMarkup",b6,43,6b,f6),
	HX_("addFormat",38,c4,b2,b5),
	HX_("removeFormat",9b,2a,bc,6c),
	HX_("clearFormats",4f,73,ad,ba),
	HX_("setFormat",79,04,36,5d),
	HX_("setBorderStyle",23,ac,54,b8),
	HX_("updateHitbox",81,94,eb,56),
	HX_("set_fieldWidth",a9,9f,fa,2d),
	HX_("get_fieldWidth",35,b7,da,0d),
	HX_("set_autoSize",4d,67,8c,f9),
	HX_("get_autoSize",d9,43,93,e4),
	HX_("set_text",aa,e1,11,7b),
	HX_("get_size",4a,5c,0e,cc),
	HX_("set_size",be,b5,6b,7a),
	HX_("set_color",c6,b9,56,71),
	HX_("get_font",58,19,7b,c3),
	HX_("set_font",cc,72,d8,71),
	HX_("get_embedded",93,cd,7b,93),
	HX_("get_systemFont",a7,4c,39,68),
	HX_("set_systemFont",1b,35,59,88),
	HX_("get_bold",0e,3d,d6,c0),
	HX_("set_bold",82,96,33,6f),
	HX_("get_italic",b9,9e,eb,f6),
	HX_("set_italic",2d,3d,69,fa),
	HX_("get_wordWrap",bd,c8,f4,b5),
	HX_("set_wordWrap",31,ec,ed,ca),
	HX_("get_alignment",ba,b6,a1,ab),
	HX_("set_alignment",c6,98,a7,f0),
	HX_("set_borderStyle",48,a5,43,cd),
	HX_("set_borderColor",7a,71,82,93),
	HX_("set_borderSize",8a,70,03,9d),
	HX_("set_borderQuality",96,78,03,a3),
	HX_("set_graphic",cb,c1,6e,04),
	HX_("get_width",5d,12,0c,0e),
	HX_("get_height",b0,77,d3,f2),
	HX_("updateColorTransform",72,0f,d2,2f),
	HX_("regenGraphic",6b,55,39,8b),
	HX_("drawTextFieldTo",04,9e,45,9d),
	HX_("draw",04,2c,70,42),
	HX_("calcFrame",58,93,8c,f9),
	HX_("applyBorderStyle",d7,bd,a2,48),
	HX_("applyBorderTransparency",32,96,af,17),
	HX_("copyTextWithOffset",db,97,6d,53),
	HX_("applyFormats",8e,0d,9c,1e),
	HX_("copyTextFormat",d9,63,8e,5f),
	HX_("dtfCopy",ab,51,45,87),
	HX_("updateDefaultFormat",0f,5b,8e,8b),
	HX_("set_frames",e3,bd,8a,a0),
	::String(null()) };

static void FlxText_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxText_obj::VERTICAL_GUTTER,"VERTICAL_GUTTER");
};

#ifdef HXCPP_VISIT_ALLOCS
static void FlxText_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxText_obj::VERTICAL_GUTTER,"VERTICAL_GUTTER");
};

#endif

::hx::Class FlxText_obj::__mClass;

static ::String FlxText_obj_sStaticFields[] = {
	HX_("VERTICAL_GUTTER",04,b3,89,07),
	::String(null())
};

void FlxText_obj::__register()
{
	FlxText_obj _hx_dummy;
	FlxText_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("flixel.text.FlxText",b0,4a,1b,ca);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mMarkFunc = FlxText_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(FlxText_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(FlxText_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< FlxText_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = FlxText_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = FlxText_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = FlxText_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void FlxText_obj::__boot()
{
{
            	HX_STACKFRAME(&_hx_pos_7d9cf70d988be490_44_boot)
HXDLIN(  44)		VERTICAL_GUTTER = 4;
            	}
}

} // end namespace flixel
} // end namespace text
