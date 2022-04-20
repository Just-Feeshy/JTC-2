#include <hxcpp.h>

#ifndef INCLUDED_Character
#include <Character.h>
#endif
#ifndef INCLUDED_Conductor
#include <Conductor.h>
#endif
#ifndef INCLUDED_HelperStates
#include <HelperStates.h>
#endif
#ifndef INCLUDED_JsonParser_18
#include <JsonParser_18.h>
#endif
#ifndef INCLUDED_Lambda
#include <Lambda.h>
#endif
#ifndef INCLUDED_MusicBeatState
#include <MusicBeatState.h>
#endif
#ifndef INCLUDED_Paths
#include <Paths.h>
#endif
#ifndef INCLUDED_PlayState
#include <PlayState.h>
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
#ifndef INCLUDED_flixel_animation_FlxAnimation
#include <flixel/animation/FlxAnimation.h>
#endif
#ifndef INCLUDED_flixel_animation_FlxAnimationController
#include <flixel/animation/FlxAnimationController.h>
#endif
#ifndef INCLUDED_flixel_animation_FlxBaseAnimation
#include <flixel/animation/FlxBaseAnimation.h>
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
#ifndef INCLUDED_flixel_math_FlxPoint
#include <flixel/math/FlxPoint.h>
#endif
#ifndef INCLUDED_flixel_math_FlxRandom
#include <flixel/math/FlxRandom.h>
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
#ifndef INCLUDED_flixel_util_IFlxPooled
#include <flixel/util/IFlxPooled.h>
#endif
#ifndef INCLUDED_haxe_Exception
#include <haxe/Exception.h>
#endif
#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_json2object_Error
#include <json2object/Error.h>
#endif
#ifndef INCLUDED_json2object_PositionUtils
#include <json2object/PositionUtils.h>
#endif
#ifndef INCLUDED_json2object_reader_BaseParser
#include <json2object/reader/BaseParser.h>
#endif
#ifndef INCLUDED_lime_utils_Assets
#include <lime/utils/Assets.h>
#endif
#ifndef INCLUDED_sys_FileSystem
#include <sys/FileSystem.h>
#endif
#ifndef INCLUDED_sys_io_File
#include <sys/io/File.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_ae240c01d039da8e_20_new,"Character","new",0x74bf54fb,"Character.new","Character.hx",20,0xf073a2d5)
HX_LOCAL_STACK_FRAME(_hx_pos_ae240c01d039da8e_111_update,"Character","update",0x0e18944e,"Character.update","Character.hx",111,0xf073a2d5)
HX_LOCAL_STACK_FRAME(_hx_pos_ae240c01d039da8e_140_destroy,"Character","destroy",0xce1f9b15,"Character.destroy","Character.hx",140,0xf073a2d5)
HX_LOCAL_STACK_FRAME(_hx_pos_ae240c01d039da8e_155_get__info,"Character","get__info",0x91db1b7f,"Character.get__info","Character.hx",155,0xf073a2d5)
HX_LOCAL_STACK_FRAME(_hx_pos_ae240c01d039da8e_175_dance,"Character","dance",0xde4da48e,"Character.dance","Character.hx",175,0xf073a2d5)
HX_LOCAL_STACK_FRAME(_hx_pos_ae240c01d039da8e_236_playAnim,"Character","playAnim",0xed2bd3aa,"Character.playAnim","Character.hx",236,0xf073a2d5)
HX_LOCAL_STACK_FRAME(_hx_pos_ae240c01d039da8e_291_addOffset,"Character","addOffset",0x6dc9376f,"Character.addOffset","Character.hx",291,0xf073a2d5)
HX_LOCAL_STACK_FRAME(_hx_pos_ae240c01d039da8e_295_changeOffsets,"Character","changeOffsets",0x365d224b,"Character.changeOffsets","Character.hx",295,0xf073a2d5)
HX_LOCAL_STACK_FRAME(_hx_pos_ae240c01d039da8e_305_updateFinalized,"Character","updateFinalized",0x527af6d8,"Character.updateFinalized","Character.hx",305,0xf073a2d5)
HX_LOCAL_STACK_FRAME(_hx_pos_ae240c01d039da8e_316_refresh,"Character","refresh",0x96ba47f6,"Character.refresh","Character.hx",316,0xf073a2d5)
HX_LOCAL_STACK_FRAME(_hx_pos_ae240c01d039da8e_334_setIndexis,"Character","setIndexis",0x96f698bf,"Character.setIndexis","Character.hx",334,0xf073a2d5)
static const ::String _hx_array_data_e3a4bb89_16[] = {
	HX_("sad",16,98,57,00),HX_("danceLeft",da,cc,f9,df),HX_("danceRight",a9,7f,a6,91),HX_("hairBlow",b4,c9,39,c9),HX_("hairFall",bd,48,d6,cb),
};
static const int _hx_array_data_e3a4bb89_17[] = {
	(int)0,(int)1,(int)2,(int)3,(int)4,(int)5,(int)6,(int)7,(int)8,(int)9,(int)10,(int)11,(int)12,
};
static const int _hx_array_data_e3a4bb89_18[] = {
	(int)30,(int)0,(int)1,(int)2,(int)3,(int)4,(int)5,(int)6,(int)7,(int)8,(int)9,(int)10,(int)11,(int)12,(int)13,(int)14,
};
static const int _hx_array_data_e3a4bb89_19[] = {
	(int)15,(int)16,(int)17,(int)18,(int)19,(int)20,(int)21,(int)22,(int)23,(int)24,(int)25,(int)26,(int)27,(int)28,(int)29,
};
static const int _hx_array_data_e3a4bb89_20[] = {
	(int)0,(int)1,(int)2,(int)3,
};
static const int _hx_array_data_e3a4bb89_21[] = {
	(int)0,(int)1,(int)2,(int)3,(int)4,(int)5,(int)6,(int)7,(int)8,(int)9,(int)10,(int)11,
};
static const ::String _hx_array_data_e3a4bb89_22[] = {
	HX_("singUP",6a,52,21,b9),HX_("danceLeft",da,cc,f9,df),HX_("danceRight",a9,7f,a6,91),
};
static const int _hx_array_data_e3a4bb89_23[] = {
	(int)0,
};
static const int _hx_array_data_e3a4bb89_24[] = {
	(int)30,(int)0,(int)1,(int)2,(int)3,(int)4,(int)5,(int)6,(int)7,(int)8,(int)9,(int)10,(int)11,(int)12,(int)13,(int)14,
};
static const int _hx_array_data_e3a4bb89_25[] = {
	(int)15,(int)16,(int)17,(int)18,(int)19,(int)20,(int)21,(int)22,(int)23,(int)24,(int)25,(int)26,(int)27,(int)28,(int)29,
};
static const ::String _hx_array_data_e3a4bb89_26[] = {
	HX_("sad",16,98,57,00),HX_("danceLeft",da,cc,f9,df),HX_("danceRight",a9,7f,a6,91),HX_("hairBlow",b4,c9,39,c9),HX_("hairFall",bd,48,d6,cb),
};
static const int _hx_array_data_e3a4bb89_27[] = {
	(int)0,(int)1,(int)2,(int)3,(int)4,(int)5,(int)6,(int)7,(int)8,(int)9,(int)10,(int)11,(int)12,
};
static const int _hx_array_data_e3a4bb89_28[] = {
	(int)30,(int)0,(int)1,(int)2,(int)3,(int)4,(int)5,(int)6,(int)7,(int)8,(int)9,(int)10,(int)11,(int)12,(int)13,(int)14,
};
static const int _hx_array_data_e3a4bb89_29[] = {
	(int)15,(int)16,(int)17,(int)18,(int)19,(int)20,(int)21,(int)22,(int)23,(int)24,(int)25,(int)26,(int)27,(int)28,(int)29,
};
static const int _hx_array_data_e3a4bb89_30[] = {
	(int)0,(int)1,(int)2,(int)3,
};
static const int _hx_array_data_e3a4bb89_31[] = {
	(int)0,(int)1,(int)2,(int)3,(int)4,(int)5,(int)6,(int)7,(int)8,(int)9,(int)10,(int)11,
};
static const ::String _hx_array_data_e3a4bb89_32[] = {
	HX_("singUP",6a,52,21,b9),HX_("danceLeft",da,cc,f9,df),HX_("danceRight",a9,7f,a6,91),
};
static const int _hx_array_data_e3a4bb89_33[] = {
	(int)2,
};
static const int _hx_array_data_e3a4bb89_34[] = {
	(int)30,(int)0,(int)1,(int)2,(int)3,(int)4,(int)5,(int)6,(int)7,(int)8,(int)9,(int)10,(int)11,(int)12,(int)13,(int)14,
};
static const int _hx_array_data_e3a4bb89_35[] = {
	(int)15,(int)16,(int)17,(int)18,(int)19,(int)20,(int)21,(int)22,(int)23,(int)24,(int)25,(int)26,(int)27,(int)28,(int)29,
};
static const ::String _hx_array_data_e3a4bb89_36[] = {
	HX_("danceLeft",da,cc,f9,df),HX_("danceRight",a9,7f,a6,91),
};
static const int _hx_array_data_e3a4bb89_37[] = {
	(int)0,(int)2,(int)6,
};
static const int _hx_array_data_e3a4bb89_38[] = {
	(int)8,(int)10,(int)12,(int)14,
};
HX_LOCAL_STACK_FRAME(_hx_pos_ae240c01d039da8e_310_loadInfo,"Character","loadInfo",0x7301f339,"Character.loadInfo","Character.hx",310,0xf073a2d5)

void Character_obj::__construct(Float x,Float y,::String __o_character, ::Dynamic __o_isPlayer, ::Dynamic hardInfo){
            		::String character = __o_character;
            		if (::hx::IsNull(__o_character)) character = HX_("bf",c4,55,00,00);
            		 ::Dynamic isPlayer = __o_isPlayer;
            		if (::hx::IsNull(__o_isPlayer)) isPlayer = false;
            	HX_GC_STACKFRAME(&_hx_pos_ae240c01d039da8e_20_new)
HXLINE( 152)		this->danced = false;
HXLINE(  41)		this->finalizedHeight = ((Float)0);
HXLINE(  40)		this->finalizedWidth = ((Float)0);
HXLINE(  36)		this->hasBePlayer = HX_("",00,00,00,00);
HXLINE(  35)		this->isPlayer = false;
HXLINE(  33)		this->holdTimer = ((Float)0);
HXLINE(  31)		this->customAnimation = false;
HXLINE(  29)		this->curCharacter = HX_("bf",c4,55,00,00);
HXLINE(  27)		this->debugMode = false;
HXLINE(  45)		super::__construct(x,y,null());
HXLINE(  47)		this->finalizedX = x;
HXLINE(  48)		this->finalizedY = y;
HXLINE(  50)		this->animOffsets =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
HXLINE(  51)		this->animations = ::Array_obj< ::String >::__new();
HXLINE(  52)		this->curCharacter = character;
HXLINE(  53)		this->isPlayer = ( (bool)(isPlayer) );
HXLINE(  55)		if (( (bool)(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic)) )) {
HXLINE(  56)			this->set_antialiasing(true);
            		}
HXLINE(  58)		{
HXLINE(  65)			if (::hx::IsNull( hardInfo )) {
HXLINE(  66)				this->_info = ::Character_obj::loadInfo((HX_("characters/",45,3c,bf,be) + this->curCharacter));
            			}
            			else {
HXLINE(  68)				this->_info = hardInfo;
            			}
HXLINE(  70)			if ((( (::String)(this->get__info()->__Field(HX_("file",7c,ce,bb,43),::hx::paccDynamic)) ).split(HX_(".",2e,00,00,00))->__get(1) == HX_("xml",d7,6d,5b,00))) {
HXLINE(  71)				::String key = ( (::String)(this->get__info()->__Field(HX_("file",7c,ce,bb,43),::hx::paccDynamic)) ).split(HX_(".",2e,00,00,00))->__get(0);
HXDLIN(  71)				::String cacheFile = HX_("",00,00,00,00);
HXDLIN(  71)				cacheFile = HX_("cache/",ad,5f,f2,b0);
HXDLIN(  71)				if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + key))) {
HXLINE(  71)					cacheFile = HX_("",00,00,00,00);
            				}
HXDLIN(  71)				 ::flixel::graphics::frames::FlxAtlasFrames _hx_tmp;
HXDLIN(  71)				::String cacheFile1 = HX_("",00,00,00,00);
HXDLIN(  71)				cacheFile1 = HX_("cache/",ad,5f,f2,b0);
HXDLIN(  71)				if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + key))) {
HXLINE(  71)					cacheFile1 = HX_("",00,00,00,00);
            				}
HXDLIN(  71)				if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile1) + key) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),HX_("shared",a5,5e,2b,1d)),null())) {
HXLINE(  71)					if (::hx::IsNotNull( ::Paths_obj::ifImageCached((cacheFile + key)) )) {
HXLINE(  71)						 ::flixel::graphics::FlxGraphic _hx_tmp1 = ::Paths_obj::ifImageCached((cacheFile + key));
HXDLIN(  71)						_hx_tmp = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSparrow(_hx_tmp1,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + key) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),HX_("shared",a5,5e,2b,1d)));
            					}
            					else {
HXLINE(  71)						::String _hx_tmp1 = ::Paths_obj::image((cacheFile + key),HX_("shared",a5,5e,2b,1d));
HXDLIN(  71)						_hx_tmp = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSparrow(_hx_tmp1,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + key) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),HX_("shared",a5,5e,2b,1d)));
            					}
            				}
            				else {
HXLINE(  71)					HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate asset - ",17,30,f9,e8) + ::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + key) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),HX_("shared",a5,5e,2b,1d)))));
            				}
HXDLIN(  71)				this->set_frames(_hx_tmp);
            			}
            			else {
HXLINE(  72)				if ((( (::String)(this->get__info()->__Field(HX_("file",7c,ce,bb,43),::hx::paccDynamic)) ).split(HX_(".",2e,00,00,00))->__get(1) == HX_("txt",70,6e,58,00))) {
HXLINE(  73)					::String key = ( (::String)(this->get__info()->__Field(HX_("file",7c,ce,bb,43),::hx::paccDynamic)) ).split(HX_(".",2e,00,00,00))->__get(0);
HXDLIN(  73)					::String cacheFile = HX_("",00,00,00,00);
HXDLIN(  73)					cacheFile = HX_("cache/",ad,5f,f2,b0);
HXDLIN(  73)					if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + key))) {
HXLINE(  73)						cacheFile = HX_("",00,00,00,00);
            					}
HXDLIN(  73)					 ::flixel::graphics::frames::FlxAtlasFrames _hx_tmp;
HXDLIN(  73)					if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + key) + HX_(".txt",02,3f,c0,1e)),HX_("TEXT",ad,94,ba,37),HX_("shared",a5,5e,2b,1d)),null())) {
HXLINE(  73)						if (::hx::IsNotNull( ::Paths_obj::ifImageCached((cacheFile + key)) )) {
HXLINE(  73)							 ::flixel::graphics::FlxGraphic _hx_tmp1 = ::Paths_obj::ifImageCached((cacheFile + key));
HXDLIN(  73)							_hx_tmp = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSpriteSheetPacker(_hx_tmp1,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + key) + HX_(".txt",02,3f,c0,1e)),HX_("TEXT",ad,94,ba,37),HX_("shared",a5,5e,2b,1d)));
            						}
            						else {
HXLINE(  73)							::String _hx_tmp1 = ::Paths_obj::image((cacheFile + key),HX_("shared",a5,5e,2b,1d));
HXDLIN(  73)							_hx_tmp = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSpriteSheetPacker(_hx_tmp1,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + key) + HX_(".txt",02,3f,c0,1e)),HX_("TEXT",ad,94,ba,37),HX_("shared",a5,5e,2b,1d)));
            						}
            					}
            					else {
HXLINE(  73)						HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate asset - ",17,30,f9,e8) + ::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + key) + HX_(".txt",02,3f,c0,1e)),HX_("TEXT",ad,94,ba,37),HX_("shared",a5,5e,2b,1d)))));
            					}
HXDLIN(  73)					this->set_frames(_hx_tmp);
            				}
            			}
HXLINE(  75)			this->setIndexis(this->curCharacter);
HXLINE(  77)			{
HXLINE(  77)				 ::Dynamic anim = ( ( ::haxe::ds::StringMap)( ::Dynamic(this->get__info()->__Field(HX_("animations",ef,34,1c,83),::hx::paccDynamic))) )->keys();
HXDLIN(  77)				while(( (bool)(anim->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE(  77)					::String anim1 = ( (::String)(anim->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXLINE(  78)					this->animations->push(anim1);
HXLINE(  79)					 ::flixel::animation::FlxAnimationController _hx_tmp = this->animation;
HXDLIN(  79)					::String _hx_tmp1 = ( (::String)(( ( ::haxe::ds::StringMap)( ::Dynamic(this->get__info()->__Field(HX_("animations",ef,34,1c,83),::hx::paccDynamic))) )->get(anim1)->__Field(HX_("prefix",92,d9,b6,ae),::hx::paccDynamic)) );
HXDLIN(  79)					int _hx_tmp2 = ( (int)(( ( ::haxe::ds::StringMap)( ::Dynamic(this->get__info()->__Field(HX_("animations",ef,34,1c,83),::hx::paccDynamic))) )->get(anim1)->__Field(HX_("framerate",8d,e5,4b,4e),::hx::paccDynamic)) );
HXDLIN(  79)					_hx_tmp->addByPrefix(anim1,_hx_tmp1,_hx_tmp2,( ( ::haxe::ds::StringMap)( ::Dynamic(this->get__info()->__Field(HX_("animations",ef,34,1c,83),::hx::paccDynamic))) )->get(anim1)->__Field(HX_("looped",c3,5f,b9,61),::hx::paccDynamic),null(),null());
HXLINE(  80)					int _hx_tmp3 = ( (int)( ::Dynamic(( ( ::haxe::ds::StringMap)( ::Dynamic(this->get__info()->__Field(HX_("animations",ef,34,1c,83),::hx::paccDynamic))) )->get(anim1)->__Field(HX_("offset",93,97,3f,60),::hx::paccDynamic))->__GetItem(0)) );
HXDLIN(  80)					this->addOffset(anim1,_hx_tmp3, ::Dynamic(( ( ::haxe::ds::StringMap)( ::Dynamic(this->get__info()->__Field(HX_("animations",ef,34,1c,83),::hx::paccDynamic))) )->get(anim1)->__Field(HX_("offset",93,97,3f,60),::hx::paccDynamic))->__GetItem(1));
HXLINE(  82)					bool _hx_tmp4;
HXDLIN(  82)					if (::StringTools_obj::endsWith(anim1,HX_("player",61,eb,b8,37))) {
HXLINE(  82)						_hx_tmp4 = ( (bool)(isPlayer) );
            					}
            					else {
HXLINE(  82)						_hx_tmp4 = false;
            					}
HXDLIN(  82)					if (_hx_tmp4) {
HXLINE(  83)						this->hasBePlayer = HX_("player",61,eb,b8,37);
            					}
            				}
            			}
HXLINE(  86)			this->finalizedWidth = this->get_width();
HXLINE(  87)			this->finalizedHeight = this->get_height();
HXLINE(  89)			if (( (bool)(this->get__info()->__Field(HX_("pixel",86,c6,a3,c2),::hx::paccDynamic)) )) {
HXLINE(  90)				Float _hx_tmp = this->get_width();
HXDLIN(  90)				this->setGraphicSize(::Std_obj::_hx_int((_hx_tmp * ::PlayState_obj::daPixelZoom)),null());
HXLINE(  91)				this->updateHitbox();
            			}
HXLINE(  94)			if (( (bool)(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic)) )) {
HXLINE(  95)				this->set_antialiasing(!(( (bool)(this->get__info()->__Field(HX_("pixel",86,c6,a3,c2),::hx::paccDynamic)) )));
            			}
            			else {
HXLINE(  97)				this->set_antialiasing(false);
            			}
HXLINE(  99)			this->playAnim(( (::String)(this->get__info()->__Field(HX_("playAnim",25,ea,84,30),::hx::paccDynamic)) ),null(),null(),null());
HXLINE( 101)			this->set_flipX(( (bool)(this->get__info()->__Field(HX_("isPlayer",eb,86,22,90),::hx::paccDynamic)) ));
            		}
HXLINE( 104)		this->dance();
HXLINE( 106)		if (( (bool)(isPlayer) )) {
HXLINE( 107)			this->set_flipX(!(this->flipX));
            		}
            	}

Dynamic Character_obj::__CreateEmpty() { return new Character_obj; }

void *Character_obj::_hx_vtable = 0;

Dynamic Character_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Character_obj > _hx_result = new Character_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4]);
	return _hx_result;
}

bool Character_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x55af02e5) {
		if (inClassId<=(int)0x2c01639b) {
			return inClassId==(int)0x00000001 || inClassId==(int)0x2c01639b;
		} else {
			return inClassId==(int)0x55af02e5;
		}
	} else {
		return inClassId==(int)0x7ccf8994 || inClassId==(int)0x7dab0655;
	}
}

void Character_obj::update(Float elapsed){
            	HX_STACKFRAME(&_hx_pos_ae240c01d039da8e_111_update)
HXLINE( 112)		if (!(this->isPlayer)) {
HXLINE( 114)			if (::StringTools_obj::startsWith(this->animation->_curAnim->name,HX_("sing",4f,96,53,4c))) {
HXLINE( 116)				 ::Character _hx_tmp = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN( 116)				_hx_tmp->holdTimer = (_hx_tmp->holdTimer + elapsed);
            			}
HXLINE( 119)			Float dadVar = ( (Float)(4) );
HXLINE( 121)			if ((this->curCharacter == HX_("dad",47,36,4c,00))) {
HXLINE( 122)				dadVar = ((Float)6.1);
            			}
HXLINE( 123)			if ((this->holdTimer >= ((::Conductor_obj::stepCrochet * dadVar) * ((Float)0.001)))) {
HXLINE( 125)				this->dance();
HXLINE( 126)				this->holdTimer = ( (Float)(0) );
            			}
            		}
HXLINE( 130)		::String _hx_switch_0 = this->curCharacter;
            		if (  (_hx_switch_0==HX_("fesh",94,cb,b8,43)) ||  (_hx_switch_0==HX_("gf",1f,5a,00,00)) ){
HXLINE( 133)			bool _hx_tmp;
HXDLIN( 133)			if ((this->animation->_curAnim->name == HX_("hairFall",bd,48,d6,cb))) {
HXLINE( 133)				_hx_tmp = this->animation->_curAnim->finished;
            			}
            			else {
HXLINE( 133)				_hx_tmp = false;
            			}
HXDLIN( 133)			if (_hx_tmp) {
HXLINE( 134)				this->playAnim(HX_("danceRight",a9,7f,a6,91),null(),null(),null());
            			}
HXLINE( 133)			goto _hx_goto_2;
            		}
            		_hx_goto_2:;
HXLINE( 137)		Float _hx_tmp;
HXDLIN( 137)		if (( (bool)(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic)) )) {
HXLINE( 137)			_hx_tmp = ( (Float)(1) );
            		}
            		else {
HXLINE( 137)			_hx_tmp = ((Float)1.5);
            		}
HXDLIN( 137)		this->super::update((elapsed / _hx_tmp));
            	}


void Character_obj::destroy(){
            	HX_STACKFRAME(&_hx_pos_ae240c01d039da8e_140_destroy)
HXLINE( 141)		this->super::destroy();
HXLINE( 143)		this->animOffsets->clear();
HXLINE( 145)		this->curCharacter = null();
HXLINE( 147)		this->animOffsets = null();
HXLINE( 148)		this->animations = null();
HXLINE( 149)		this->_info = null();
            	}


 ::Dynamic Character_obj::get__info(){
            	HX_GC_STACKFRAME(&_hx_pos_ae240c01d039da8e_155_get__info)
HXDLIN( 155)		if (::hx::IsNull( this->_info )) {
HXLINE( 158)			 ::haxe::ds::StringMap _hx_tmp =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
HXLINE( 156)			return  ::Dynamic(::hx::Anon_obj::Create(7)
            				->setFixed(0,HX_("animations",ef,34,1c,83),_hx_tmp)
            				->setFixed(1,HX_("isPlayer",eb,86,22,90),false)
            				->setFixed(2,HX_("pixel",86,c6,a3,c2),false)
            				->setFixed(3,HX_("position",a9,a0,fa,ca), ::haxe::ds::StringMap_obj::__alloc( HX_CTX ))
            				->setFixed(4,HX_("playAnim",25,ea,84,30),HX_("",00,00,00,00))
            				->setFixed(5,HX_("file",7c,ce,bb,43),HX_("",00,00,00,00))
            				->setFixed(6,HX_("icon",79,e7,b2,45),::Array_obj< int >::__new(0)));
            		}
            		else {
HXLINE( 166)			return this->_info;
            		}
HXLINE( 155)		return null();
            	}


HX_DEFINE_DYNAMIC_FUNC0(Character_obj,get__info,return )

void Character_obj::dance(){
            	HX_STACKFRAME(&_hx_pos_ae240c01d039da8e_175_dance)
HXDLIN( 175)		if (!(this->debugMode)) {
HXLINE( 177)			::String _hx_switch_0 = this->curCharacter;
            			if (  (_hx_switch_0==HX_("fesh",94,cb,b8,43)) ||  (_hx_switch_0==HX_("gf",1f,5a,00,00)) ){
HXLINE( 180)				if (!(::StringTools_obj::startsWith(this->animation->_curAnim->name,HX_("hair",22,27,08,45)))) {
HXLINE( 182)					this->danced = !(this->danced);
HXLINE( 184)					if (this->danced) {
HXLINE( 185)						this->playAnim(HX_("danceRight",a9,7f,a6,91),null(),null(),null());
            					}
            					else {
HXLINE( 187)						this->playAnim(HX_("danceLeft",da,cc,f9,df),null(),null(),null());
            					}
            				}
HXLINE( 180)				goto _hx_goto_6;
            			}
            			if (  (_hx_switch_0==HX_("gf-car",a6,63,ab,07)) ){
HXLINE( 202)				if (!(::StringTools_obj::startsWith(this->animation->_curAnim->name,HX_("hair",22,27,08,45)))) {
HXLINE( 204)					this->danced = !(this->danced);
HXLINE( 206)					if (this->danced) {
HXLINE( 207)						this->playAnim(HX_("danceRight",a9,7f,a6,91),null(),null(),null());
            					}
            					else {
HXLINE( 209)						this->playAnim(HX_("danceLeft",da,cc,f9,df),null(),null(),null());
            					}
            				}
HXLINE( 202)				goto _hx_goto_6;
            			}
            			if (  (_hx_switch_0==HX_("gf-christmas",94,26,b1,6d)) ){
HXLINE( 191)				if (!(::StringTools_obj::startsWith(this->animation->_curAnim->name,HX_("hair",22,27,08,45)))) {
HXLINE( 193)					this->danced = !(this->danced);
HXLINE( 195)					if (this->danced) {
HXLINE( 196)						this->playAnim(HX_("danceRight",a9,7f,a6,91),null(),null(),null());
            					}
            					else {
HXLINE( 198)						this->playAnim(HX_("danceLeft",da,cc,f9,df),null(),null(),null());
            					}
            				}
HXLINE( 191)				goto _hx_goto_6;
            			}
            			if (  (_hx_switch_0==HX_("gf-pixel",98,3e,8c,55)) ){
HXLINE( 212)				if (!(::StringTools_obj::startsWith(this->animation->_curAnim->name,HX_("hair",22,27,08,45)))) {
HXLINE( 214)					this->danced = !(this->danced);
HXLINE( 216)					if (this->danced) {
HXLINE( 217)						this->playAnim(HX_("danceRight",a9,7f,a6,91),null(),null(),null());
            					}
            					else {
HXLINE( 219)						this->playAnim(HX_("danceLeft",da,cc,f9,df),null(),null(),null());
            					}
            				}
HXLINE( 212)				goto _hx_goto_6;
            			}
            			if (  (_hx_switch_0==HX_("spooky",eb,bd,9e,c1)) ){
HXLINE( 223)				this->danced = !(this->danced);
HXLINE( 225)				if (this->danced) {
HXLINE( 226)					this->playAnim(HX_("danceRight",a9,7f,a6,91),null(),null(),null());
            				}
            				else {
HXLINE( 228)					this->playAnim(HX_("danceLeft",da,cc,f9,df),null(),null(),null());
            				}
HXLINE( 222)				goto _hx_goto_6;
            			}
            			/* default */{
HXLINE( 230)				this->playAnim(HX_("idle",14,a7,b3,45),null(),null(),null());
            			}
            			_hx_goto_6:;
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC0(Character_obj,dance,(void))

void Character_obj::playAnim(::String AnimName,::hx::Null< bool >  __o_Force,::hx::Null< bool >  __o_Reversed,::hx::Null< int >  __o_Frame){
            		bool Force = __o_Force.Default(false);
            		bool Reversed = __o_Reversed.Default(false);
            		int Frame = __o_Frame.Default(0);
            	HX_STACKFRAME(&_hx_pos_ae240c01d039da8e_236_playAnim)
HXLINE( 242)		if (!(this->animation->_animations->exists(AnimName))) {
HXLINE( 243)			 ::flixel::math::FlxRandom getRandom = ::flixel::FlxG_obj::random;
HXDLIN( 243)			int getRandom1 = getRandom->_hx_int(0,(::Lambda_obj::count(this->animation->_animations,null()) - 1),null());
HXLINE( 244)			int index = 0;
HXLINE( 246)			::String tempAnimName = HX_("",00,00,00,00);
HXLINE( 248)			{
HXLINE( 248)				 ::Dynamic k = this->animation->_animations->keys();
HXDLIN( 248)				while(( (bool)(k->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE( 248)					::String k1 = ( (::String)(k->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXLINE( 249)					if ((index >= getRandom1)) {
HXLINE( 250)						tempAnimName = ( ( ::flixel::animation::FlxBaseAnimation)(this->animation->_animations->get(k1)) )->name;
HXLINE( 251)						goto _hx_goto_8;
            					}
HXLINE( 254)					index = (index + 1);
            				}
            				_hx_goto_8:;
            			}
HXLINE( 257)			this->animation->play(tempAnimName,Force,Reversed,Frame);
HXLINE( 259)			AnimName = tempAnimName;
            		}
            		else {
HXLINE( 261)			this->animation->play(AnimName,Force,Reversed,Frame);
            		}
HXLINE( 264)		::Array< Float > daOffset = ( (::Array< Float >)(this->animOffsets->get(AnimName)) );
HXLINE( 265)		if (this->animOffsets->exists(AnimName)) {
HXLINE( 267)			this->offset->set(daOffset->__get(0),daOffset->__get(1));
            		}
            		else {
HXLINE( 270)			this->offset->set(0,0);
            		}
HXLINE( 272)		bool _hx_tmp;
HXDLIN( 272)		if (!(::StringTools_obj::startsWith(this->curCharacter,HX_("gf",1f,5a,00,00)))) {
HXLINE( 272)			_hx_tmp = (this->curCharacter == HX_("fesh",94,cb,b8,43));
            		}
            		else {
HXLINE( 272)			_hx_tmp = true;
            		}
HXDLIN( 272)		if (_hx_tmp) {
HXLINE( 274)			if ((AnimName == HX_("singLEFT",d6,39,ef,3b))) {
HXLINE( 276)				this->danced = true;
            			}
            			else {
HXLINE( 278)				if ((AnimName == HX_("singRIGHT",0d,6f,70,ac))) {
HXLINE( 280)					this->danced = false;
            				}
            			}
HXLINE( 283)			bool _hx_tmp;
HXDLIN( 283)			if ((AnimName != HX_("singUP",6a,52,21,b9))) {
HXLINE( 283)				_hx_tmp = (AnimName == HX_("singDOWN",31,2a,ad,36));
            			}
            			else {
HXLINE( 283)				_hx_tmp = true;
            			}
HXDLIN( 283)			if (_hx_tmp) {
HXLINE( 285)				this->danced = !(this->danced);
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC4(Character_obj,playAnim,(void))

void Character_obj::addOffset(::String name,::hx::Null< Float >  __o_x,::hx::Null< Float >  __o_y){
            		Float x = __o_x.Default(0);
            		Float y = __o_y.Default(0);
            	HX_STACKFRAME(&_hx_pos_ae240c01d039da8e_291_addOffset)
HXDLIN( 291)		::Array< Float > v = ::Array_obj< Float >::__new(2)->init(0,x)->init(1,y);
HXDLIN( 291)		this->animOffsets->set(name,v);
            	}


HX_DEFINE_DYNAMIC_FUNC3(Character_obj,addOffset,(void))

void Character_obj::changeOffsets(::String name,Float value, ::flixel::util::FlxAxes axes){
            	HX_STACKFRAME(&_hx_pos_ae240c01d039da8e_295_changeOffsets)
HXDLIN( 295)		if (::hx::IsPointerEq( axes,::flixel::util::FlxAxes_obj::X_dyn() )) {
HXLINE( 296)			this->animOffsets->get(name)->__SetItem(0,value);
            		}
            		else {
HXLINE( 297)			if (::hx::IsPointerEq( axes,::flixel::util::FlxAxes_obj::Y_dyn() )) {
HXLINE( 298)				this->animOffsets->get(name)->__SetItem(1,value);
            			}
            			else {
HXLINE( 300)				this->animOffsets->get(name)->__SetItem(0,value);
HXLINE( 301)				this->animOffsets->get(name)->__SetItem(1,value);
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC3(Character_obj,changeOffsets,(void))

void Character_obj::updateFinalized(Float x,Float y){
            	HX_STACKFRAME(&_hx_pos_ae240c01d039da8e_305_updateFinalized)
HXLINE( 306)		this->finalizedX = x;
HXLINE( 307)		this->finalizedY = y;
            	}


HX_DEFINE_DYNAMIC_FUNC2(Character_obj,updateFinalized,(void))

void Character_obj::refresh(::String character, ::flixel::math::FlxPoint camPos){
            	HX_STACKFRAME(&_hx_pos_ae240c01d039da8e_316_refresh)
HXLINE( 317)		this->setPosition(this->finalizedX,this->finalizedY);
HXLINE( 319)		if (::sys::FileSystem_obj::exists(((HX_("config/characters/",38,ce,be,91) + this->curCharacter) + HX_(".json",56,f1,d6,c2)))) {
HXLINE( 322)			Float _hx_tmp = this->x;
HXDLIN( 322)			this->set_x((_hx_tmp + ( ( ::haxe::ds::StringMap)( ::Dynamic(this->get__info()->__Field(HX_("position",a9,a0,fa,ca),::hx::paccDynamic))) )->get(HX_("x",78,00,00,00))));
HXLINE( 323)			Float _hx_tmp1 = this->y;
HXDLIN( 323)			this->set_y((_hx_tmp1 + ( ( ::haxe::ds::StringMap)( ::Dynamic(this->get__info()->__Field(HX_("position",a9,a0,fa,ca),::hx::paccDynamic))) )->get(HX_("y",79,00,00,00))));
HXLINE( 325)			Float _hx_tmp2 = this->getGraphicMidpoint(null())->x;
HXDLIN( 325)			camPos->set(_hx_tmp2,this->getGraphicMidpoint(null())->y);
HXLINE( 327)			Float camPos1 = camPos->x;
HXDLIN( 327)			camPos->set_x((camPos1 + ( ( ::haxe::ds::StringMap)( ::Dynamic(this->get__info()->__Field(HX_("position",a9,a0,fa,ca),::hx::paccDynamic))) )->get(HX_("camPosX",f3,d7,4d,d5))));
HXLINE( 328)			Float camPos2 = camPos->y;
HXDLIN( 328)			camPos->set_y((camPos2 + ( ( ::haxe::ds::StringMap)( ::Dynamic(this->get__info()->__Field(HX_("position",a9,a0,fa,ca),::hx::paccDynamic))) )->get(HX_("camPosY",f4,d7,4d,d5))));
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC2(Character_obj,refresh,(void))

void Character_obj::setIndexis(::String character){
            	HX_STACKFRAME(&_hx_pos_ae240c01d039da8e_334_setIndexis)
HXDLIN( 334)		::String _hx_switch_0 = character;
            		if (  (_hx_switch_0==HX_("fesh",94,cb,b8,43)) ||  (_hx_switch_0==HX_("gf",1f,5a,00,00)) ){
HXLINE( 336)			this->animations = ::Array_obj< ::String >::fromData( _hx_array_data_e3a4bb89_16,5);
HXLINE( 338)			this->animation->addByIndices(HX_("sad",16,98,57,00),HX_("gf sad",95,c1,1f,ff),::Array_obj< int >::fromData( _hx_array_data_e3a4bb89_17,13),HX_("",00,00,00,00),24,false,null(),null());
HXLINE( 339)			this->animation->addByIndices(HX_("danceLeft",da,cc,f9,df),HX_("GF Dancing Beat",47,47,24,df),::Array_obj< int >::fromData( _hx_array_data_e3a4bb89_18,16),HX_("",00,00,00,00),24,false,null(),null());
HXLINE( 340)			this->animation->addByIndices(HX_("danceRight",a9,7f,a6,91),HX_("GF Dancing Beat",47,47,24,df),::Array_obj< int >::fromData( _hx_array_data_e3a4bb89_19,15),HX_("",00,00,00,00),24,false,null(),null());
HXLINE( 341)			this->animation->addByIndices(HX_("hairBlow",b4,c9,39,c9),HX_("GF Dancing Beat Hair blowing",4b,14,4a,db),::Array_obj< int >::fromData( _hx_array_data_e3a4bb89_20,4),HX_("",00,00,00,00),24,null(),null(),null());
HXLINE( 342)			this->animation->addByIndices(HX_("hairFall",bd,48,d6,cb),HX_("GF Dancing Beat Hair Landing",52,45,8f,42),::Array_obj< int >::fromData( _hx_array_data_e3a4bb89_21,12),HX_("",00,00,00,00),24,false,null(),null());
HXLINE( 335)			goto _hx_goto_14;
            		}
            		if (  (_hx_switch_0==HX_("gf-car",a6,63,ab,07)) ){
HXLINE( 352)			this->animations = ::Array_obj< ::String >::fromData( _hx_array_data_e3a4bb89_22,3);
HXLINE( 354)			this->animation->addByIndices(HX_("singUP",6a,52,21,b9),HX_("GF Dancing Beat Hair blowing CAR",9f,79,4b,90),::Array_obj< int >::fromData( _hx_array_data_e3a4bb89_23,1),HX_("",00,00,00,00),24,false,null(),null());
HXLINE( 355)			this->animation->addByIndices(HX_("danceLeft",da,cc,f9,df),HX_("GF Dancing Beat Hair blowing CAR",9f,79,4b,90),::Array_obj< int >::fromData( _hx_array_data_e3a4bb89_24,16),HX_("",00,00,00,00),24,false,null(),null());
HXLINE( 356)			this->animation->addByIndices(HX_("danceRight",a9,7f,a6,91),HX_("GF Dancing Beat Hair blowing CAR",9f,79,4b,90),::Array_obj< int >::fromData( _hx_array_data_e3a4bb89_25,15),HX_("",00,00,00,00),24,false,null(),null());
HXLINE( 351)			goto _hx_goto_14;
            		}
            		if (  (_hx_switch_0==HX_("gf-christmas",94,26,b1,6d)) ){
HXLINE( 344)			this->animations = ::Array_obj< ::String >::fromData( _hx_array_data_e3a4bb89_26,5);
HXLINE( 346)			this->animation->addByIndices(HX_("sad",16,98,57,00),HX_("gf sad",95,c1,1f,ff),::Array_obj< int >::fromData( _hx_array_data_e3a4bb89_27,13),HX_("",00,00,00,00),24,false,null(),null());
HXLINE( 347)			this->animation->addByIndices(HX_("danceLeft",da,cc,f9,df),HX_("GF Dancing Beat",47,47,24,df),::Array_obj< int >::fromData( _hx_array_data_e3a4bb89_28,16),HX_("",00,00,00,00),24,false,null(),null());
HXLINE( 348)			this->animation->addByIndices(HX_("danceRight",a9,7f,a6,91),HX_("GF Dancing Beat",47,47,24,df),::Array_obj< int >::fromData( _hx_array_data_e3a4bb89_29,15),HX_("",00,00,00,00),24,false,null(),null());
HXLINE( 349)			this->animation->addByIndices(HX_("hairBlow",b4,c9,39,c9),HX_("GF Dancing Beat Hair blowing",4b,14,4a,db),::Array_obj< int >::fromData( _hx_array_data_e3a4bb89_30,4),HX_("",00,00,00,00),24,null(),null(),null());
HXLINE( 350)			this->animation->addByIndices(HX_("hairFall",bd,48,d6,cb),HX_("GF Dancing Beat Hair Landing",52,45,8f,42),::Array_obj< int >::fromData( _hx_array_data_e3a4bb89_31,12),HX_("",00,00,00,00),24,false,null(),null());
HXLINE( 343)			goto _hx_goto_14;
            		}
            		if (  (_hx_switch_0==HX_("gf-pixel",98,3e,8c,55)) ){
HXLINE( 358)			this->animations = ::Array_obj< ::String >::fromData( _hx_array_data_e3a4bb89_32,3);
HXLINE( 360)			this->animation->addByIndices(HX_("singUP",6a,52,21,b9),HX_("GF IDLE",b5,30,b6,22),::Array_obj< int >::fromData( _hx_array_data_e3a4bb89_33,1),HX_("",00,00,00,00),24,false,null(),null());
HXLINE( 361)			this->animation->addByIndices(HX_("danceLeft",da,cc,f9,df),HX_("GF IDLE",b5,30,b6,22),::Array_obj< int >::fromData( _hx_array_data_e3a4bb89_34,16),HX_("",00,00,00,00),24,false,null(),null());
HXLINE( 362)			this->animation->addByIndices(HX_("danceRight",a9,7f,a6,91),HX_("GF IDLE",b5,30,b6,22),::Array_obj< int >::fromData( _hx_array_data_e3a4bb89_35,15),HX_("",00,00,00,00),24,false,null(),null());
HXLINE( 357)			goto _hx_goto_14;
            		}
            		if (  (_hx_switch_0==HX_("spooky",eb,bd,9e,c1)) ){
HXLINE( 364)			this->animations = ::Array_obj< ::String >::fromData( _hx_array_data_e3a4bb89_36,2);
HXLINE( 366)			this->animation->addByIndices(HX_("danceLeft",da,cc,f9,df),HX_("spooky dance idle",36,a7,32,19),::Array_obj< int >::fromData( _hx_array_data_e3a4bb89_37,3),HX_("",00,00,00,00),12,false,null(),null());
HXLINE( 367)			this->animation->addByIndices(HX_("danceRight",a9,7f,a6,91),HX_("spooky dance idle",36,a7,32,19),::Array_obj< int >::fromData( _hx_array_data_e3a4bb89_38,4),HX_("",00,00,00,00),12,false,null(),null());
HXLINE( 363)			goto _hx_goto_14;
            		}
            		_hx_goto_14:;
            	}


HX_DEFINE_DYNAMIC_FUNC1(Character_obj,setIndexis,(void))

 ::Dynamic Character_obj::loadInfo(::String character){
            	HX_GC_STACKFRAME(&_hx_pos_ae240c01d039da8e_310_loadInfo)
HXLINE( 311)		 ::JsonParser_18 parser =  ::JsonParser_18_obj::__alloc( HX_CTX ,null(),null(),null());
HXLINE( 313)		::String _hx_tmp = ::sys::io::File_obj::getContent(((HX_("config/",2d,93,39,10) + character) + HX_(".json",56,f1,d6,c2)));
HXDLIN( 313)		return parser->fromJson(_hx_tmp,((HX_("",00,00,00,00) + character.split(HX_("/",2f,00,00,00))->__get(1)) + HX_(".json",56,f1,d6,c2)));
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Character_obj,loadInfo,return )


::hx::ObjectPtr< Character_obj > Character_obj::__new(Float x,Float y,::String __o_character, ::Dynamic __o_isPlayer, ::Dynamic hardInfo) {
	::hx::ObjectPtr< Character_obj > __this = new Character_obj();
	__this->__construct(x,y,__o_character,__o_isPlayer,hardInfo);
	return __this;
}

::hx::ObjectPtr< Character_obj > Character_obj::__alloc(::hx::Ctx *_hx_ctx,Float x,Float y,::String __o_character, ::Dynamic __o_isPlayer, ::Dynamic hardInfo) {
	Character_obj *__this = (Character_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Character_obj), true, "Character"));
	*(void **)__this = Character_obj::_hx_vtable;
	__this->__construct(x,y,__o_character,__o_isPlayer,hardInfo);
	return __this;
}

Character_obj::Character_obj()
{
}

void Character_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Character);
	HX_MARK_MEMBER_NAME(finalizedX,"finalizedX");
	HX_MARK_MEMBER_NAME(finalizedY,"finalizedY");
	HX_MARK_MEMBER_NAME(animOffsets,"animOffsets");
	HX_MARK_MEMBER_NAME(animations,"animations");
	HX_MARK_MEMBER_NAME(debugMode,"debugMode");
	HX_MARK_MEMBER_NAME(curCharacter,"curCharacter");
	HX_MARK_MEMBER_NAME(customAnimation,"customAnimation");
	HX_MARK_MEMBER_NAME(holdTimer,"holdTimer");
	HX_MARK_MEMBER_NAME(isPlayer,"isPlayer");
	HX_MARK_MEMBER_NAME(hasBePlayer,"hasBePlayer");
	HX_MARK_MEMBER_NAME(_info,"_info");
	HX_MARK_MEMBER_NAME(finalizedWidth,"finalizedWidth");
	HX_MARK_MEMBER_NAME(finalizedHeight,"finalizedHeight");
	HX_MARK_MEMBER_NAME(danced,"danced");
	 ::flixel::FlxSprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Character_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(finalizedX,"finalizedX");
	HX_VISIT_MEMBER_NAME(finalizedY,"finalizedY");
	HX_VISIT_MEMBER_NAME(animOffsets,"animOffsets");
	HX_VISIT_MEMBER_NAME(animations,"animations");
	HX_VISIT_MEMBER_NAME(debugMode,"debugMode");
	HX_VISIT_MEMBER_NAME(curCharacter,"curCharacter");
	HX_VISIT_MEMBER_NAME(customAnimation,"customAnimation");
	HX_VISIT_MEMBER_NAME(holdTimer,"holdTimer");
	HX_VISIT_MEMBER_NAME(isPlayer,"isPlayer");
	HX_VISIT_MEMBER_NAME(hasBePlayer,"hasBePlayer");
	HX_VISIT_MEMBER_NAME(_info,"_info");
	HX_VISIT_MEMBER_NAME(finalizedWidth,"finalizedWidth");
	HX_VISIT_MEMBER_NAME(finalizedHeight,"finalizedHeight");
	HX_VISIT_MEMBER_NAME(danced,"danced");
	 ::flixel::FlxSprite_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val Character_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_info") ) { return ::hx::Val( inCallProp == ::hx::paccAlways ? get__info() : _info ); }
		if (HX_FIELD_EQ(inName,"dance") ) { return ::hx::Val( dance_dyn() ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return ::hx::Val( update_dyn() ); }
		if (HX_FIELD_EQ(inName,"danced") ) { return ::hx::Val( danced ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return ::hx::Val( destroy_dyn() ); }
		if (HX_FIELD_EQ(inName,"refresh") ) { return ::hx::Val( refresh_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"isPlayer") ) { return ::hx::Val( isPlayer ); }
		if (HX_FIELD_EQ(inName,"playAnim") ) { return ::hx::Val( playAnim_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"debugMode") ) { return ::hx::Val( debugMode ); }
		if (HX_FIELD_EQ(inName,"holdTimer") ) { return ::hx::Val( holdTimer ); }
		if (HX_FIELD_EQ(inName,"get__info") ) { return ::hx::Val( get__info_dyn() ); }
		if (HX_FIELD_EQ(inName,"addOffset") ) { return ::hx::Val( addOffset_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"finalizedX") ) { return ::hx::Val( finalizedX ); }
		if (HX_FIELD_EQ(inName,"finalizedY") ) { return ::hx::Val( finalizedY ); }
		if (HX_FIELD_EQ(inName,"animations") ) { return ::hx::Val( animations ); }
		if (HX_FIELD_EQ(inName,"setIndexis") ) { return ::hx::Val( setIndexis_dyn() ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"animOffsets") ) { return ::hx::Val( animOffsets ); }
		if (HX_FIELD_EQ(inName,"hasBePlayer") ) { return ::hx::Val( hasBePlayer ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"curCharacter") ) { return ::hx::Val( curCharacter ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"changeOffsets") ) { return ::hx::Val( changeOffsets_dyn() ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"finalizedWidth") ) { return ::hx::Val( finalizedWidth ); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"customAnimation") ) { return ::hx::Val( customAnimation ); }
		if (HX_FIELD_EQ(inName,"finalizedHeight") ) { return ::hx::Val( finalizedHeight ); }
		if (HX_FIELD_EQ(inName,"updateFinalized") ) { return ::hx::Val( updateFinalized_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

bool Character_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"loadInfo") ) { outValue = loadInfo_dyn(); return true; }
	}
	return false;
}

::hx::Val Character_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_info") ) { _info=inValue.Cast<  ::Dynamic >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"danced") ) { danced=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"isPlayer") ) { isPlayer=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"debugMode") ) { debugMode=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"holdTimer") ) { holdTimer=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"finalizedX") ) { finalizedX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"finalizedY") ) { finalizedY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"animations") ) { animations=inValue.Cast< ::Array< ::String > >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"animOffsets") ) { animOffsets=inValue.Cast<  ::haxe::ds::StringMap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasBePlayer") ) { hasBePlayer=inValue.Cast< ::String >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"curCharacter") ) { curCharacter=inValue.Cast< ::String >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"finalizedWidth") ) { finalizedWidth=inValue.Cast< Float >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"customAnimation") ) { customAnimation=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"finalizedHeight") ) { finalizedHeight=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Character_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("finalizedX",92,c0,8d,6c));
	outFields->push(HX_("finalizedY",93,c0,8d,6c));
	outFields->push(HX_("animOffsets",6f,ff,7a,f8));
	outFields->push(HX_("animations",ef,34,1c,83));
	outFields->push(HX_("debugMode",56,77,ac,2b));
	outFields->push(HX_("curCharacter",09,86,7c,d7));
	outFields->push(HX_("customAnimation",13,49,e9,63));
	outFields->push(HX_("holdTimer",06,82,13,a9));
	outFields->push(HX_("isPlayer",eb,86,22,90));
	outFields->push(HX_("hasBePlayer",fe,ce,4b,8c));
	outFields->push(HX_("_info",4d,54,cc,f8));
	outFields->push(HX_("finalizedWidth",20,8b,3b,e9));
	outFields->push(HX_("finalizedHeight",8d,a9,2d,e1));
	outFields->push(HX_("danced",d1,49,8f,1e));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Character_obj_sMemberStorageInfo[] = {
	{::hx::fsFloat,(int)offsetof(Character_obj,finalizedX),HX_("finalizedX",92,c0,8d,6c)},
	{::hx::fsFloat,(int)offsetof(Character_obj,finalizedY),HX_("finalizedY",93,c0,8d,6c)},
	{::hx::fsObject /*  ::haxe::ds::StringMap */ ,(int)offsetof(Character_obj,animOffsets),HX_("animOffsets",6f,ff,7a,f8)},
	{::hx::fsObject /* ::Array< ::String > */ ,(int)offsetof(Character_obj,animations),HX_("animations",ef,34,1c,83)},
	{::hx::fsBool,(int)offsetof(Character_obj,debugMode),HX_("debugMode",56,77,ac,2b)},
	{::hx::fsString,(int)offsetof(Character_obj,curCharacter),HX_("curCharacter",09,86,7c,d7)},
	{::hx::fsBool,(int)offsetof(Character_obj,customAnimation),HX_("customAnimation",13,49,e9,63)},
	{::hx::fsFloat,(int)offsetof(Character_obj,holdTimer),HX_("holdTimer",06,82,13,a9)},
	{::hx::fsBool,(int)offsetof(Character_obj,isPlayer),HX_("isPlayer",eb,86,22,90)},
	{::hx::fsString,(int)offsetof(Character_obj,hasBePlayer),HX_("hasBePlayer",fe,ce,4b,8c)},
	{::hx::fsObject /*  ::Dynamic */ ,(int)offsetof(Character_obj,_info),HX_("_info",4d,54,cc,f8)},
	{::hx::fsFloat,(int)offsetof(Character_obj,finalizedWidth),HX_("finalizedWidth",20,8b,3b,e9)},
	{::hx::fsFloat,(int)offsetof(Character_obj,finalizedHeight),HX_("finalizedHeight",8d,a9,2d,e1)},
	{::hx::fsBool,(int)offsetof(Character_obj,danced),HX_("danced",d1,49,8f,1e)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *Character_obj_sStaticStorageInfo = 0;
#endif

static ::String Character_obj_sMemberFields[] = {
	HX_("finalizedX",92,c0,8d,6c),
	HX_("finalizedY",93,c0,8d,6c),
	HX_("animOffsets",6f,ff,7a,f8),
	HX_("animations",ef,34,1c,83),
	HX_("debugMode",56,77,ac,2b),
	HX_("curCharacter",09,86,7c,d7),
	HX_("customAnimation",13,49,e9,63),
	HX_("holdTimer",06,82,13,a9),
	HX_("isPlayer",eb,86,22,90),
	HX_("hasBePlayer",fe,ce,4b,8c),
	HX_("_info",4d,54,cc,f8),
	HX_("finalizedWidth",20,8b,3b,e9),
	HX_("finalizedHeight",8d,a9,2d,e1),
	HX_("update",09,86,05,87),
	HX_("destroy",fa,2c,86,24),
	HX_("danced",d1,49,8f,1e),
	HX_("get__info",a4,b0,75,3c),
	HX_("dance",33,83,83,d4),
	HX_("playAnim",25,ea,84,30),
	HX_("addOffset",94,cc,63,18),
	HX_("changeOffsets",f0,ad,39,38),
	HX_("updateFinalized",bd,75,4d,ed),
	HX_("refresh",db,d9,20,ed),
	HX_("setIndexis",fa,83,9e,33),
	::String(null()) };

::hx::Class Character_obj::__mClass;

static ::String Character_obj_sStaticFields[] = {
	HX_("loadInfo",b4,09,5b,b6),
	::String(null())
};

void Character_obj::__register()
{
	Character_obj _hx_dummy;
	Character_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("Character",89,bb,a4,e3);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Character_obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(Character_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Character_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Character_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Character_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Character_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

