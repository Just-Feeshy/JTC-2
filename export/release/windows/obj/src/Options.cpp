#include <hxcpp.h>

#ifndef INCLUDED_Alphabet
#include <Alphabet.h>
#endif
#ifndef INCLUDED_MusicBeatSubstate
#include <MusicBeatSubstate.h>
#endif
#ifndef INCLUDED_Options
#include <Options.h>
#endif
#ifndef INCLUDED_OptionsSubState
#include <OptionsSubState.h>
#endif
#ifndef INCLUDED_Paths
#include <Paths.h>
#endif
#ifndef INCLUDED_SaveType
#include <SaveType.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
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
#ifndef INCLUDED_flixel_animation_FlxAnimationController
#include <flixel/animation/FlxAnimationController.h>
#endif
#ifndef INCLUDED_flixel_graphics_FlxGraphic
#include <flixel/graphics/FlxGraphic.h>
#endif
#ifndef INCLUDED_flixel_graphics_frames_FlxAtlasFrames
#include <flixel/graphics/frames/FlxAtlasFrames.h>
#endif
#ifndef INCLUDED_flixel_graphics_frames_FlxFramesCollection
#include <flixel/graphics/frames/FlxFramesCollection.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedSpriteGroup
#include <flixel/group/FlxTypedSpriteGroup.h>
#endif
#ifndef INCLUDED_flixel_math_FlxMath
#include <flixel/math/FlxMath.h>
#endif
#ifndef INCLUDED_flixel_util_FlxAxes
#include <flixel/util/FlxAxes.h>
#endif
#ifndef INCLUDED_flixel_util_FlxDestroyUtil
#include <flixel/util/FlxDestroyUtil.h>
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
#ifndef INCLUDED_lime_utils_Assets
#include <lime/utils/Assets.h>
#endif
#ifndef INCLUDED_sys_FileSystem
#include <sys/FileSystem.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_b0a8d9dcffdfdfda_55_new,"Options","new",0x492c7330,"Options.new","Options.hx",55,0x9d9a0240)
HX_DEFINE_STACK_FRAME(_hx_pos_b0a8d9dcffdfdfda_12_new,"Options","new",0x492c7330,"Options.new","Options.hx",12,0x9d9a0240)
HX_LOCAL_STACK_FRAME(_hx_pos_b0a8d9dcffdfdfda_60_set_optionTitle,"Options","set_optionTitle",0x17e8d956,"Options.set_optionTitle","Options.hx",60,0x9d9a0240)
HX_LOCAL_STACK_FRAME(_hx_pos_b0a8d9dcffdfdfda_66_update,"Options","update",0xf33a8539,"Options.update","Options.hx",66,0x9d9a0240)
HX_LOCAL_STACK_FRAME(_hx_pos_b0a8d9dcffdfdfda_80_destroy,"Options","destroy",0x66b077ca,"Options.destroy","Options.hx",80,0x9d9a0240)

void Options_obj::__construct(Float x,Float y,::String __o_text, ::SaveType saveType, ::Dynamic Callback){
            		HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_0, ::Options,_gthis) HXARGC(1)
            		void _hx_run( ::flixel::FlxSprite letters){
            			HX_GC_STACKFRAME(&_hx_pos_b0a8d9dcffdfdfda_55_new)
HXLINE(  55)			if (::hx::IsInstanceNotEq( letters,_gthis->optionIcon )) {
HXLINE(  56)				Float _gthis1 = _gthis->optionIcon->y;
HXDLIN(  56)				Float _hx_tmp = (_gthis1 + (_gthis->optionIcon->get_height() / ( (Float)(2) )));
HXDLIN(  56)				letters->set_y((_hx_tmp - (letters->get_height() / ( (Float)(2) ))));
            			}
            		}
            		HX_END_LOCAL_FUNC1((void))

            		::String text = __o_text;
            		if (::hx::IsNull(__o_text)) text = HX_("",00,00,00,00);
            	HX_GC_STACKFRAME(&_hx_pos_b0a8d9dcffdfdfda_12_new)
HXLINE(  15)		this->optionTitle = false;
HXLINE(  23)		 ::Options _gthis = ::hx::ObjectPtr<OBJ_>(this);
HXLINE(  24)		super::__construct(0,y,text,true,false,(x + 40));
HXLINE(  26)		this->saveType = saveType;
HXLINE(  27)		this->yMultiplier = 90;
HXLINE(  29)		this->callback = Callback;
HXLINE(  31)		this->optionIcon =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,(x - ( (Float)(120) )),y,null());
HXLINE(  32)		 ::flixel::FlxSprite _hx_tmp = this->optionIcon;
HXDLIN(  32)		::String library = null();
HXDLIN(  32)		 ::Dynamic cache = null();
HXDLIN(  32)		::String cacheFile = HX_("",00,00,00,00);
HXDLIN(  32)		if (( (bool)(cache) )) {
HXLINE(  32)			cacheFile = HX_("cache/",ad,5f,f2,b0);
            		}
HXDLIN(  32)		if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + HX_("circle_assets",12,4a,06,fa)))) {
HXLINE(  32)			cacheFile = HX_("",00,00,00,00);
            		}
HXDLIN(  32)		 ::flixel::graphics::frames::FlxAtlasFrames _hx_tmp1;
HXDLIN(  32)		::String cacheFile1 = HX_("",00,00,00,00);
HXDLIN(  32)		if (( (bool)(cache) )) {
HXLINE(  32)			cacheFile1 = HX_("cache/",ad,5f,f2,b0);
            		}
HXDLIN(  32)		if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + HX_("circle_assets",12,4a,06,fa)))) {
HXLINE(  32)			cacheFile1 = HX_("",00,00,00,00);
            		}
HXDLIN(  32)		if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile1) + HX_("circle_assets",12,4a,06,fa)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library),null())) {
HXLINE(  32)			if (::hx::IsNotNull( ::Paths_obj::ifImageCached((cacheFile + HX_("circle_assets",12,4a,06,fa))) )) {
HXLINE(  32)				 ::flixel::graphics::FlxGraphic _hx_tmp = ::Paths_obj::ifImageCached((cacheFile + HX_("circle_assets",12,4a,06,fa)));
HXDLIN(  32)				_hx_tmp1 = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSparrow(_hx_tmp,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + HX_("circle_assets",12,4a,06,fa)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library));
            			}
            			else {
HXLINE(  32)				::String _hx_tmp = ::Paths_obj::image((cacheFile + HX_("circle_assets",12,4a,06,fa)),library);
HXDLIN(  32)				_hx_tmp1 = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSparrow(_hx_tmp,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + HX_("circle_assets",12,4a,06,fa)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library));
            			}
            		}
            		else {
HXLINE(  32)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate asset - ",17,30,f9,e8) + ::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + HX_("circle_assets",12,4a,06,fa)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library))));
            		}
HXDLIN(  32)		_hx_tmp->set_frames(_hx_tmp1);
HXLINE(  34)		this->optionIcon->animation->addByPrefix(HX_("off",6f,93,54,00),HX_("arrowRIGHT0",7d,77,f3,86),null(),null(),null(),null());
HXLINE(  35)		this->optionIcon->animation->addByPrefix(HX_("on",1f,61,00,00),HX_("red0",bf,4d,a7,4b),null(),null(),null(),null());
HXLINE(  36)		this->optionIcon->animation->addByPrefix(HX_("other",d0,66,76,36),HX_("blue0",56,04,01,b5),null(),null(),null(),null());
HXLINE(  37)		this->optionIcon->animation->addByPrefix(HX_("modifier",57,db,c7,16),HX_("purple0",74,7e,2d,e7),null(),null(),null(),null());
HXLINE(  39)		 ::Dynamic _hx_tmp2;
HXDLIN(  39)		switch((int)(saveType->_hx_getIndex())){
            			case (int)1: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            				}
HXDLIN(  39)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            			}
            			break;
            			case (int)2: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            				}
            				else {
HXLINE(  39)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  39)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            				}
HXDLIN(  39)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)3: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            				}
HXDLIN(  39)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            			}
            			break;
            			case (int)4: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            				}
HXDLIN(  39)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)5: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            				}
HXDLIN(  39)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            			}
            			break;
            			case (int)6: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  39)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)7: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  39)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)8: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            				}
HXDLIN(  39)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            			}
            			break;
            			case (int)9: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            				}
HXDLIN(  39)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            			}
            			break;
            			case (int)10: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            				}
HXDLIN(  39)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            			}
            			break;
            			case (int)11: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            				}
            				else {
HXLINE(  39)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  39)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            				}
HXDLIN(  39)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            			}
            			break;
            			case (int)12: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            				}
HXDLIN(  39)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            			}
            			break;
            			case (int)13: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            				}
HXDLIN(  39)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            			}
            			break;
            			case (int)14: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            				}
HXDLIN(  39)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            			}
            			break;
            			case (int)15: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            				}
HXDLIN(  39)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            			}
            			break;
            			case (int)16: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            				}
HXDLIN(  39)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)17: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            				}
HXDLIN(  39)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            			}
            			break;
            			case (int)18: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            				}
HXDLIN(  39)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            			}
            			break;
            			case (int)19: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            				}
HXDLIN(  39)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            			}
            			break;
            			case (int)20: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            				}
HXDLIN(  39)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            			}
            			break;
            			case (int)21: {
HXLINE(  39)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  39)					::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            				}
HXDLIN(  39)				_hx_tmp2 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            			}
            			break;
            			default:{
HXLINE(  39)				_hx_tmp2 = null();
            			}
            		}
HXDLIN(  39)		if (( (bool)(_hx_tmp2) )) {
HXLINE(  40)			this->optionIcon->animation->play(HX_("on",1f,61,00,00),null(),null(),null());
            		}
            		else {
HXLINE(  42)			this->optionIcon->animation->play(HX_("off",6f,93,54,00),null(),null(),null());
            		}
HXLINE(  44)		 ::flixel::FlxSprite _hx_tmp3 = this->optionIcon;
HXDLIN(  44)		_hx_tmp3->setGraphicSize(::Std_obj::_hx_int((this->optionIcon->get_width() * ((Float)0.8))),null());
HXLINE(  45)		this->optionIcon->updateHitbox();
HXLINE(  47)		 ::Dynamic _hx_tmp4;
HXDLIN(  47)		switch((int)(::SaveType_obj::GRAPHICS_dyn()->_hx_getIndex())){
            			case (int)1: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("helpme",59,84,4e,04),false,::hx::paccDynamic);
            				}
HXDLIN(  47)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("helpme",59,84,4e,04),::hx::paccDynamic));
            			}
            			break;
            			case (int)2: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            				}
            				else {
HXLINE(  47)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  47)						::flixel::FlxG_obj::save->data->__SetField(HX_("dfjk",c3,18,67,42),0,::hx::paccDynamic);
            					}
            				}
HXDLIN(  47)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("dfjk",c3,18,67,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)3: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("perfectMode",10,4f,4c,f3),0,::hx::paccDynamic);
            				}
HXDLIN(  47)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("perfectMode",10,4f,4c,f3),::hx::paccDynamic));
            			}
            			break;
            			case (int)4: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("flip",ad,12,be,43),false,::hx::paccDynamic);
            				}
HXDLIN(  47)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("flip",ad,12,be,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)5: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("customhell",ee,e6,d9,b7),false,::hx::paccDynamic);
            				}
HXDLIN(  47)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customhell",ee,e6,d9,b7),::hx::paccDynamic));
            			}
            			break;
            			case (int)6: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("fair",e4,b9,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  47)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fair",e4,b9,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)7: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("fade",7c,b5,b5,43),false,::hx::paccDynamic);
            				}
HXDLIN(  47)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fade",7c,b5,b5,43),::hx::paccDynamic));
            			}
            			break;
            			case (int)8: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("showstuff",d7,8c,51,1f),true,::hx::paccDynamic);
            				}
HXDLIN(  47)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showstuff",d7,8c,51,1f),::hx::paccDynamic));
            			}
            			break;
            			case (int)9: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("showEffect",6e,ff,17,ca),true,::hx::paccDynamic);
            				}
HXDLIN(  47)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showEffect",6e,ff,17,ca),::hx::paccDynamic));
            			}
            			break;
            			case (int)10: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("showAntialiasing",91,3f,42,e7),true,::hx::paccDynamic);
            				}
HXDLIN(  47)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic));
            			}
            			break;
            			case (int)11: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            				}
            				else {
HXLINE(  47)					if (!(::Std_obj::isOfType( ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic)),::hx::ClassOf< int >()))) {
HXLINE(  47)						::flixel::FlxG_obj::save->data->__SetField(HX_("lowFps",b5,3f,e3,66),60,::hx::paccDynamic);
            					}
            				}
HXDLIN(  47)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("lowFps",b5,3f,e3,66),::hx::paccDynamic));
            			}
            			break;
            			case (int)12: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("fpsMulti",d0,e5,0a,9a),1,::hx::paccDynamic);
            				}
HXDLIN(  47)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("fpsMulti",d0,e5,0a,9a),::hx::paccDynamic));
            			}
            			break;
            			case (int)13: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("safeballs",27,09,dd,0f),false,::hx::paccDynamic);
            				}
HXDLIN(  47)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("safeballs",27,09,dd,0f),::hx::paccDynamic));
            			}
            			break;
            			case (int)14: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("blind",55,f1,f7,b4),false,::hx::paccDynamic);
            				}
HXDLIN(  47)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("blind",55,f1,f7,b4),::hx::paccDynamic));
            			}
            			break;
            			case (int)15: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("xWobble",e9,16,a8,71),false,::hx::paccDynamic);
            				}
HXDLIN(  47)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("xWobble",e9,16,a8,71),::hx::paccDynamic));
            			}
            			break;
            			case (int)16: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("simpInputs",82,af,d8,42),false,::hx::paccDynamic);
            				}
HXDLIN(  47)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("simpInputs",82,af,d8,42),::hx::paccDynamic));
            			}
            			break;
            			case (int)17: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("preload",c9,47,43,35),true,::hx::paccDynamic);
            				}
HXDLIN(  47)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic));
            			}
            			break;
            			case (int)18: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("customKeys",45,c2,ae,a4),HX_("",00,00,00,00),::hx::paccDynamic);
            				}
HXDLIN(  47)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("customKeys",45,c2,ae,a4),::hx::paccDynamic));
            			}
            			break;
            			case (int)19: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("camMove",c0,36,52,d3),false,::hx::paccDynamic);
            				}
HXDLIN(  47)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("camMove",c0,36,52,d3),::hx::paccDynamic));
            			}
            			break;
            			case (int)20: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("ghostTapping",c6,6a,da,10),false,::hx::paccDynamic);
            				}
HXDLIN(  47)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic));
            			}
            			break;
            			case (int)21: {
HXLINE(  47)				if (::hx::IsNull( ::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic) )) {
HXLINE(  47)					::flixel::FlxG_obj::save->data->__SetField(HX_("menuBinds",f7,79,d8,4d),::cpp::VirtualArray_obj::__new(2)->init(0,HX_("SPACE",a6,c4,54,ff))->init(1,HX_("PLUS MINUS",0a,4b,e8,81)),::hx::paccDynamic);
            				}
HXDLIN(  47)				_hx_tmp4 =  ::Dynamic(::flixel::FlxG_obj::save->data->__Field(HX_("menuBinds",f7,79,d8,4d),::hx::paccDynamic));
            			}
            			break;
            			default:{
HXLINE(  47)				_hx_tmp4 = null();
            			}
            		}
HXDLIN(  47)		if (( (bool)(_hx_tmp4) )) {
HXLINE(  48)			this->optionIcon->set_antialiasing(true);
            		}
HXLINE(  50)		this->add(this->optionIcon);
HXLINE(  52)		this->callback(::hx::ObjectPtr<OBJ_>(this),false);
HXLINE(  54)		this->group->forEach( ::Dynamic(new _hx_Closure_0(_gthis)),false);
            	}

Dynamic Options_obj::__CreateEmpty() { return new Options_obj; }

void *Options_obj::_hx_vtable = 0;

Dynamic Options_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Options_obj > _hx_result = new Options_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4]);
	return _hx_result;
}

bool Options_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x567b2b93) {
		if (inClassId<=(int)0x2c01639b) {
			if (inClassId<=(int)0x288ce903) {
				return inClassId==(int)0x00000001 || inClassId==(int)0x288ce903;
			} else {
				return inClassId==(int)0x2c01639b;
			}
		} else {
			return inClassId==(int)0x567b2b93;
		}
	} else {
		if (inClassId<=(int)0x7ccf8994) {
			return inClassId==(int)0x6d6f007e || inClassId==(int)0x7ccf8994;
		} else {
			return inClassId==(int)0x7dab0655;
		}
	}
}

bool Options_obj::set_optionTitle(bool value){
            	HX_STACKFRAME(&_hx_pos_b0a8d9dcffdfdfda_60_set_optionTitle)
HXLINE(  61)		if (value) {
HXLINE(  61)			 ::flixel::util::FlxAxes axes = ::flixel::util::FlxAxes_obj::X_dyn();
HXDLIN(  61)			if (::hx::IsNull( axes )) {
HXLINE(  61)				axes = ::flixel::util::FlxAxes_obj::XY_dyn();
            			}
HXDLIN(  61)			bool _hx_tmp;
HXDLIN(  61)			switch((int)(axes->_hx_getIndex())){
            				case (int)0: case (int)2: {
HXLINE(  61)					_hx_tmp = true;
            				}
            				break;
            				default:{
HXLINE(  61)					_hx_tmp = false;
            				}
            			}
HXDLIN(  61)			if (_hx_tmp) {
HXLINE(  61)				int _hx_tmp = ::flixel::FlxG_obj::width;
HXDLIN(  61)				this->set_x(((( (Float)(_hx_tmp) ) - this->get_width()) / ( (Float)(2) )));
            			}
HXDLIN(  61)			bool _hx_tmp1;
HXDLIN(  61)			switch((int)(axes->_hx_getIndex())){
            				case (int)1: case (int)2: {
HXLINE(  61)					_hx_tmp1 = true;
            				}
            				break;
            				default:{
HXLINE(  61)					_hx_tmp1 = false;
            				}
            			}
HXDLIN(  61)			if (_hx_tmp1) {
HXLINE(  61)				int _hx_tmp = ::flixel::FlxG_obj::height;
HXDLIN(  61)				this->set_y(((( (Float)(_hx_tmp) ) - this->get_height()) / ( (Float)(2) )));
            			}
            		}
HXLINE(  62)		this->optionTitle = true;
HXLINE(  63)		return value;
            	}


HX_DEFINE_DYNAMIC_FUNC1(Options_obj,set_optionTitle,return )

void Options_obj::update(Float elapsed){
            	HX_STACKFRAME(&_hx_pos_b0a8d9dcffdfdfda_66_update)
HXLINE(  67)		Float scaledY = ::flixel::math::FlxMath_obj::remapToRange(( (Float)(this->targetY) ),( (Float)(0) ),( (Float)(1) ),( (Float)(0) ),((Float)1.3));
HXLINE(  68)		Float a = this->y;
HXDLIN(  68)		this->set_y((a + (((Float)0.16) * ((((scaledY * ( (Float)(this->yMultiplier) )) + (( (Float)(::flixel::FlxG_obj::height) ) * ((Float)0.48))) - ( (Float)(130) )) - a))));
HXLINE(  70)		if (!(this->optionTitle)) {
HXLINE(  71)			if ((this->targetY == 0)) {
HXLINE(  72)				Float a = this->x;
HXDLIN(  72)				this->set_x((a + (((Float)0.16) * (( (Float)((this->targetY + 140)) ) - a))));
            			}
            			else {
HXLINE(  74)				Float a = this->x;
HXDLIN(  74)				this->set_x((a + (((Float)0.16) * (( (Float)((this->targetY + 90)) ) - a))));
            			}
            		}
HXLINE(  77)		this->super::update(elapsed);
            	}


void Options_obj::destroy(){
            	HX_STACKFRAME(&_hx_pos_b0a8d9dcffdfdfda_80_destroy)
HXLINE(  81)		this->super::destroy();
HXLINE(  83)		this->optionIcon = ( ( ::flixel::FlxSprite)(::flixel::util::FlxDestroyUtil_obj::destroy(this->optionIcon)) );
HXLINE(  84)		this->optionSubState = ( ( ::OptionsSubState)(::flixel::util::FlxDestroyUtil_obj::destroy(this->optionSubState)) );
HXLINE(  86)		this->callback = null();
HXLINE(  87)		this->saveType = null();
            	}



::hx::ObjectPtr< Options_obj > Options_obj::__new(Float x,Float y,::String __o_text, ::SaveType saveType, ::Dynamic Callback) {
	::hx::ObjectPtr< Options_obj > __this = new Options_obj();
	__this->__construct(x,y,__o_text,saveType,Callback);
	return __this;
}

::hx::ObjectPtr< Options_obj > Options_obj::__alloc(::hx::Ctx *_hx_ctx,Float x,Float y,::String __o_text, ::SaveType saveType, ::Dynamic Callback) {
	Options_obj *__this = (Options_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Options_obj), true, "Options"));
	*(void **)__this = Options_obj::_hx_vtable;
	__this->__construct(x,y,__o_text,saveType,Callback);
	return __this;
}

Options_obj::Options_obj()
{
}

void Options_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Options);
	HX_MARK_MEMBER_NAME(optionIcon,"optionIcon");
	HX_MARK_MEMBER_NAME(optionTitle,"optionTitle");
	HX_MARK_MEMBER_NAME(optionSubState,"optionSubState");
	HX_MARK_MEMBER_NAME(saveType,"saveType");
	HX_MARK_MEMBER_NAME(callback,"callback");
	 ::Alphabet_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Options_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(optionIcon,"optionIcon");
	HX_VISIT_MEMBER_NAME(optionTitle,"optionTitle");
	HX_VISIT_MEMBER_NAME(optionSubState,"optionSubState");
	HX_VISIT_MEMBER_NAME(saveType,"saveType");
	HX_VISIT_MEMBER_NAME(callback,"callback");
	 ::Alphabet_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val Options_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return ::hx::Val( update_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return ::hx::Val( destroy_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"saveType") ) { return ::hx::Val( saveType ); }
		if (HX_FIELD_EQ(inName,"callback") ) { return ::hx::Val( callback ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"optionIcon") ) { return ::hx::Val( optionIcon ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"optionTitle") ) { return ::hx::Val( optionTitle ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"optionSubState") ) { return ::hx::Val( optionSubState ); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"set_optionTitle") ) { return ::hx::Val( set_optionTitle_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val Options_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"saveType") ) { saveType=inValue.Cast<  ::SaveType >(); return inValue; }
		if (HX_FIELD_EQ(inName,"callback") ) { callback=inValue.Cast<  ::Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"optionIcon") ) { optionIcon=inValue.Cast<  ::flixel::FlxSprite >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"optionTitle") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_optionTitle(inValue.Cast< bool >()) );optionTitle=inValue.Cast< bool >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"optionSubState") ) { optionSubState=inValue.Cast<  ::OptionsSubState >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Options_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("optionIcon",8e,45,4e,8b));
	outFields->push(HX_("optionTitle",e3,09,92,b2));
	outFields->push(HX_("optionSubState",06,59,37,6a));
	outFields->push(HX_("saveType",97,8c,c2,00));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Options_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::flixel::FlxSprite */ ,(int)offsetof(Options_obj,optionIcon),HX_("optionIcon",8e,45,4e,8b)},
	{::hx::fsBool,(int)offsetof(Options_obj,optionTitle),HX_("optionTitle",e3,09,92,b2)},
	{::hx::fsObject /*  ::OptionsSubState */ ,(int)offsetof(Options_obj,optionSubState),HX_("optionSubState",06,59,37,6a)},
	{::hx::fsObject /*  ::SaveType */ ,(int)offsetof(Options_obj,saveType),HX_("saveType",97,8c,c2,00)},
	{::hx::fsObject /*  ::Dynamic */ ,(int)offsetof(Options_obj,callback),HX_("callback",c5,99,06,7f)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *Options_obj_sStaticStorageInfo = 0;
#endif

static ::String Options_obj_sMemberFields[] = {
	HX_("optionIcon",8e,45,4e,8b),
	HX_("optionTitle",e3,09,92,b2),
	HX_("optionSubState",06,59,37,6a),
	HX_("saveType",97,8c,c2,00),
	HX_("callback",c5,99,06,7f),
	HX_("set_optionTitle",86,3e,3f,6f),
	HX_("update",09,86,05,87),
	HX_("destroy",fa,2c,86,24),
	::String(null()) };

::hx::Class Options_obj::__mClass;

void Options_obj::__register()
{
	Options_obj _hx_dummy;
	Options_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("Options",3e,5b,4f,ad);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Options_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Options_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Options_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Options_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

