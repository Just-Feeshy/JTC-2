#include <hxcpp.h>

#ifndef INCLUDED_BackgroundDancer
#include <BackgroundDancer.h>
#endif
#ifndef INCLUDED_BackgroundGirls
#include <BackgroundGirls.h>
#endif
#ifndef INCLUDED_Paths
#include <Paths.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_example_code_DefaultStage
#include <example_code/DefaultStage.h>
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
#ifndef INCLUDED_flixel_addons_effects_chainable_FlxWaveDirection
#include <flixel/addons/effects/chainable/FlxWaveDirection.h>
#endif
#ifndef INCLUDED_flixel_addons_effects_chainable_FlxWaveEffect
#include <flixel/addons/effects/chainable/FlxWaveEffect.h>
#endif
#ifndef INCLUDED_flixel_addons_effects_chainable_FlxWaveMode
#include <flixel/addons/effects/chainable/FlxWaveMode.h>
#endif
#ifndef INCLUDED_flixel_addons_effects_chainable_IFlxEffect
#include <flixel/addons/effects/chainable/IFlxEffect.h>
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
#ifndef INCLUDED_flixel_math_FlxPoint
#include <flixel/math/FlxPoint.h>
#endif
#ifndef INCLUDED_flixel_system_FlxSound
#include <flixel/system/FlxSound.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_SoundFrontEnd
#include <flixel/system/frontEnds/SoundFrontEnd.h>
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
#ifndef INCLUDED_lime_utils_Assets
#include <lime/utils/Assets.h>
#endif
#ifndef INCLUDED_sys_FileSystem
#include <sys/FileSystem.h>
#endif
#ifndef INCLUDED_template_StageBuilder
#include <template/StageBuilder.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_95b33a292328d79f_11_new,"example_code.DefaultStage","new",0xfb11ff1b,"example_code.DefaultStage.new","example_code/DefaultStage.hx",11,0x444bc5d4)
static const int _hx_array_data_408fd5a9_2[] = {
	(int)0,(int)1,(int)2,(int)3,(int)4,(int)5,(int)6,(int)7,(int)8,(int)9,(int)10,(int)11,(int)12,(int)13,(int)14,(int)15,(int)16,(int)17,(int)18,
};
HX_LOCAL_STACK_FRAME(_hx_pos_95b33a292328d79f_317_destroy,"example_code.DefaultStage","destroy",0x70e1d535,"example_code.DefaultStage.destroy","example_code/DefaultStage.hx",317,0x444bc5d4)
HX_LOCAL_STACK_FRAME(_hx_pos_95b33a292328d79f_326_setMainGameStage,"example_code.DefaultStage","setMainGameStage",0x332c4156,"example_code.DefaultStage.setMainGameStage","example_code/DefaultStage.hx",326,0x444bc5d4)
namespace example_code{

void DefaultStage_obj::__construct(::String song){
            	HX_GC_STACKFRAME(&_hx_pos_95b33a292328d79f_11_new)
HXLINE(  25)		this->isPixel = false;
HXLINE(  28)		super::__construct(song);
HXLINE(  30)		::String _hx_switch_0 = song;
            		if (  (_hx_switch_0==HX_("limo",1f,17,b3,47)) ){
HXLINE(  86)			this->setDefaultCameraZoom(((Float)0.90));
HXLINE(  88)			 ::flixel::FlxSprite skyBG =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,-120,-50,null());
HXDLIN(  88)			 ::flixel::FlxSprite skyBG1 = skyBG->loadGraphic(::Paths_obj::image(HX_("limo/limoSunset",45,de,4f,6e),null()),null(),null(),null(),null(),null());
HXLINE(  89)			skyBG1->scrollFactor->set(((Float)0.1),((Float)0.1));
HXLINE(  90)			this->addToStage(skyBG1);
HXLINE(  92)			 ::flixel::FlxSprite bgLimo =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,-200,480,null());
HXLINE(  93)			::String library = null();
HXDLIN(  93)			 ::Dynamic cache = null();
HXDLIN(  93)			::String cacheFile = HX_("",00,00,00,00);
HXDLIN(  93)			if (( (bool)(cache) )) {
HXLINE(  93)				cacheFile = HX_("cache/",ad,5f,f2,b0);
            			}
HXDLIN(  93)			if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + HX_("limo/bgLimo",b4,c7,45,2c)))) {
HXLINE(  93)				cacheFile = HX_("",00,00,00,00);
            			}
HXDLIN(  93)			 ::flixel::graphics::frames::FlxAtlasFrames _hx_tmp;
HXDLIN(  93)			::String cacheFile1 = HX_("",00,00,00,00);
HXDLIN(  93)			if (( (bool)(cache) )) {
HXLINE(  93)				cacheFile1 = HX_("cache/",ad,5f,f2,b0);
            			}
HXDLIN(  93)			if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + HX_("limo/bgLimo",b4,c7,45,2c)))) {
HXLINE(  93)				cacheFile1 = HX_("",00,00,00,00);
            			}
HXDLIN(  93)			if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile1) + HX_("limo/bgLimo",b4,c7,45,2c)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library),null())) {
HXLINE(  93)				if (::hx::IsNotNull( ::Paths_obj::ifImageCached((cacheFile + HX_("limo/bgLimo",b4,c7,45,2c))) )) {
HXLINE(  93)					 ::flixel::graphics::FlxGraphic _hx_tmp1 = ::Paths_obj::ifImageCached((cacheFile + HX_("limo/bgLimo",b4,c7,45,2c)));
HXDLIN(  93)					_hx_tmp = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSparrow(_hx_tmp1,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + HX_("limo/bgLimo",b4,c7,45,2c)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library));
            				}
            				else {
HXLINE(  93)					::String _hx_tmp1 = ::Paths_obj::image((cacheFile + HX_("limo/bgLimo",b4,c7,45,2c)),library);
HXDLIN(  93)					_hx_tmp = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSparrow(_hx_tmp1,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + HX_("limo/bgLimo",b4,c7,45,2c)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library));
            				}
            			}
            			else {
HXLINE(  93)				HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate asset - ",17,30,f9,e8) + ::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + HX_("limo/bgLimo",b4,c7,45,2c)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library))));
            			}
HXDLIN(  93)			bgLimo->set_frames(_hx_tmp);
HXLINE(  94)			bgLimo->animation->addByPrefix(HX_("drive",0a,69,bc,df),HX_("background limo pink",65,40,fe,9c),24,null(),null(),null());
HXLINE(  95)			bgLimo->animation->play(HX_("drive",0a,69,bc,df),null(),null(),null());
HXLINE(  96)			bgLimo->scrollFactor->set(((Float)0.4),((Float)0.4));
HXLINE(  97)			this->addToStage(bgLimo);
HXLINE(  99)			this->grpLimoDancers =  ::flixel::group::FlxTypedGroup_obj::__alloc( HX_CTX ,null());
HXLINE( 100)			this->addToStage(this->grpLimoDancers);
HXLINE( 102)			{
HXLINE( 103)				{
HXLINE( 104)					 ::BackgroundDancer dancer =  ::BackgroundDancer_obj::__alloc( HX_CTX ,( (Float)(130) ),(bgLimo->y - ( (Float)(400) )));
HXLINE( 105)					dancer->scrollFactor->set(((Float)0.4),((Float)0.4));
HXLINE( 106)					this->grpLimoDancers->add(dancer).StaticCast<  ::BackgroundDancer >();
            				}
HXLINE( 103)				{
HXLINE( 104)					 ::BackgroundDancer dancer1 =  ::BackgroundDancer_obj::__alloc( HX_CTX ,( (Float)(500) ),(bgLimo->y - ( (Float)(400) )));
HXLINE( 105)					dancer1->scrollFactor->set(((Float)0.4),((Float)0.4));
HXLINE( 106)					this->grpLimoDancers->add(dancer1).StaticCast<  ::BackgroundDancer >();
            				}
HXLINE( 103)				{
HXLINE( 104)					 ::BackgroundDancer dancer2 =  ::BackgroundDancer_obj::__alloc( HX_CTX ,( (Float)(870) ),(bgLimo->y - ( (Float)(400) )));
HXLINE( 105)					dancer2->scrollFactor->set(((Float)0.4),((Float)0.4));
HXLINE( 106)					this->grpLimoDancers->add(dancer2).StaticCast<  ::BackgroundDancer >();
            				}
HXLINE( 103)				{
HXLINE( 104)					 ::BackgroundDancer dancer3 =  ::BackgroundDancer_obj::__alloc( HX_CTX ,( (Float)(1240) ),(bgLimo->y - ( (Float)(400) )));
HXLINE( 105)					dancer3->scrollFactor->set(((Float)0.4),((Float)0.4));
HXLINE( 106)					this->grpLimoDancers->add(dancer3).StaticCast<  ::BackgroundDancer >();
            				}
HXLINE( 103)				{
HXLINE( 104)					 ::BackgroundDancer dancer4 =  ::BackgroundDancer_obj::__alloc( HX_CTX ,( (Float)(1610) ),(bgLimo->y - ( (Float)(400) )));
HXLINE( 105)					dancer4->scrollFactor->set(((Float)0.4),((Float)0.4));
HXLINE( 106)					this->grpLimoDancers->add(dancer4).StaticCast<  ::BackgroundDancer >();
            				}
            			}
HXLINE( 109)			 ::flixel::FlxSprite overlayShit =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,-500,-600,null());
HXDLIN( 109)			 ::flixel::FlxSprite overlayShit1 = overlayShit->loadGraphic(::Paths_obj::image(HX_("limo/limoOverlay",01,f0,58,a8),null()),null(),null(),null(),null(),null());
HXLINE( 110)			overlayShit1->set_alpha(((Float)0.5));
HXLINE( 119)			::String library1 = null();
HXDLIN( 119)			 ::Dynamic cache1 = null();
HXDLIN( 119)			::String cacheFile2 = HX_("",00,00,00,00);
HXDLIN( 119)			if (( (bool)(cache1) )) {
HXLINE( 119)				cacheFile2 = HX_("cache/",ad,5f,f2,b0);
            			}
HXDLIN( 119)			if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + HX_("limo/limoDrive",3b,67,64,e6)))) {
HXLINE( 119)				cacheFile2 = HX_("",00,00,00,00);
            			}
HXDLIN( 119)			 ::flixel::graphics::frames::FlxAtlasFrames limoTex;
HXDLIN( 119)			::String cacheFile3 = HX_("",00,00,00,00);
HXDLIN( 119)			if (( (bool)(cache1) )) {
HXLINE( 119)				cacheFile3 = HX_("cache/",ad,5f,f2,b0);
            			}
HXDLIN( 119)			if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + HX_("limo/limoDrive",3b,67,64,e6)))) {
HXLINE( 119)				cacheFile3 = HX_("",00,00,00,00);
            			}
HXDLIN( 119)			if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile3) + HX_("limo/limoDrive",3b,67,64,e6)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library1),null())) {
HXLINE( 119)				if (::hx::IsNotNull( ::Paths_obj::ifImageCached((cacheFile2 + HX_("limo/limoDrive",3b,67,64,e6))) )) {
HXLINE( 119)					 ::flixel::graphics::FlxGraphic limoTex1 = ::Paths_obj::ifImageCached((cacheFile2 + HX_("limo/limoDrive",3b,67,64,e6)));
HXDLIN( 119)					limoTex = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSparrow(limoTex1,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile2) + HX_("limo/limoDrive",3b,67,64,e6)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library1));
            				}
            				else {
HXLINE( 119)					::String limoTex1 = ::Paths_obj::image((cacheFile2 + HX_("limo/limoDrive",3b,67,64,e6)),library1);
HXDLIN( 119)					limoTex = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSparrow(limoTex1,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile2) + HX_("limo/limoDrive",3b,67,64,e6)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library1));
            				}
            			}
            			else {
HXLINE( 119)				HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate asset - ",17,30,f9,e8) + ::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile2) + HX_("limo/limoDrive",3b,67,64,e6)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library1))));
            			}
HXLINE( 121)			this->limo =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,-120,550,null());
HXLINE( 122)			this->limo->set_frames(limoTex);
HXLINE( 123)			this->limo->animation->addByPrefix(HX_("drive",0a,69,bc,df),HX_("Limo stage",1d,b3,df,4c),24,null(),null(),null());
HXLINE( 124)			this->limo->animation->play(HX_("drive",0a,69,bc,df),null(),null(),null());
HXLINE( 125)			this->limo->set_antialiasing(true);
HXLINE( 127)			 ::flixel::FlxSprite _hx_tmp1 =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,-300,160,null());
HXDLIN( 127)			this->fastCar = _hx_tmp1->loadGraphic(::Paths_obj::image(HX_("limo/fastCarLol",c1,b0,ed,94),null()),null(),null(),null(),null(),null());
HXLINE( 128)			this->addToStage(this->limo);
HXLINE(  85)			goto _hx_goto_0;
            		}
            		if (  (_hx_switch_0==HX_("mall",d4,3a,56,48)) ){
HXLINE( 132)			this->setDefaultCameraZoom(((Float)0.80));
HXLINE( 134)			 ::flixel::FlxSprite bg =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,-1000,-500,null());
HXDLIN( 134)			 ::flixel::FlxSprite bg1 = bg->loadGraphic(::Paths_obj::image(HX_("christmas/bgWalls",57,9f,1b,51),null()),null(),null(),null(),null(),null());
HXLINE( 135)			bg1->set_antialiasing(true);
HXLINE( 136)			bg1->scrollFactor->set(((Float)0.2),((Float)0.2));
HXLINE( 137)			bg1->set_active(false);
HXLINE( 138)			bg1->setGraphicSize(::Std_obj::_hx_int((bg1->get_width() * ((Float)0.8))),null());
HXLINE( 139)			bg1->updateHitbox();
HXLINE( 140)			this->addToStage(bg1);
HXLINE( 142)			this->upperBoppers =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,-240,-90,null());
HXLINE( 143)			 ::flixel::FlxSprite _hx_tmp = this->upperBoppers;
HXDLIN( 143)			::String library = null();
HXDLIN( 143)			 ::Dynamic cache = null();
HXDLIN( 143)			::String cacheFile = HX_("",00,00,00,00);
HXDLIN( 143)			if (( (bool)(cache) )) {
HXLINE( 143)				cacheFile = HX_("cache/",ad,5f,f2,b0);
            			}
HXDLIN( 143)			if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + HX_("christmas/upperBop",2e,2f,6d,ac)))) {
HXLINE( 143)				cacheFile = HX_("",00,00,00,00);
            			}
HXDLIN( 143)			 ::flixel::graphics::frames::FlxAtlasFrames _hx_tmp1;
HXDLIN( 143)			::String cacheFile1 = HX_("",00,00,00,00);
HXDLIN( 143)			if (( (bool)(cache) )) {
HXLINE( 143)				cacheFile1 = HX_("cache/",ad,5f,f2,b0);
            			}
HXDLIN( 143)			if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + HX_("christmas/upperBop",2e,2f,6d,ac)))) {
HXLINE( 143)				cacheFile1 = HX_("",00,00,00,00);
            			}
HXDLIN( 143)			if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile1) + HX_("christmas/upperBop",2e,2f,6d,ac)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library),null())) {
HXLINE( 143)				if (::hx::IsNotNull( ::Paths_obj::ifImageCached((cacheFile + HX_("christmas/upperBop",2e,2f,6d,ac))) )) {
HXLINE( 143)					 ::flixel::graphics::FlxGraphic _hx_tmp = ::Paths_obj::ifImageCached((cacheFile + HX_("christmas/upperBop",2e,2f,6d,ac)));
HXDLIN( 143)					_hx_tmp1 = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSparrow(_hx_tmp,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + HX_("christmas/upperBop",2e,2f,6d,ac)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library));
            				}
            				else {
HXLINE( 143)					::String _hx_tmp = ::Paths_obj::image((cacheFile + HX_("christmas/upperBop",2e,2f,6d,ac)),library);
HXDLIN( 143)					_hx_tmp1 = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSparrow(_hx_tmp,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + HX_("christmas/upperBop",2e,2f,6d,ac)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library));
            				}
            			}
            			else {
HXLINE( 143)				HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate asset - ",17,30,f9,e8) + ::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + HX_("christmas/upperBop",2e,2f,6d,ac)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library))));
            			}
HXDLIN( 143)			_hx_tmp->set_frames(_hx_tmp1);
HXLINE( 144)			this->upperBoppers->animation->addByPrefix(HX_("bop",03,be,4a,00),HX_("Upper Crowd Bob",a4,72,cf,77),24,false,null(),null());
HXLINE( 145)			this->upperBoppers->set_antialiasing(true);
HXLINE( 146)			this->upperBoppers->scrollFactor->set(((Float)0.33),((Float)0.33));
HXLINE( 147)			 ::flixel::FlxSprite _hx_tmp2 = this->upperBoppers;
HXDLIN( 147)			_hx_tmp2->setGraphicSize(::Std_obj::_hx_int((this->upperBoppers->get_width() * ((Float)0.85))),null());
HXLINE( 148)			this->upperBoppers->updateHitbox();
HXLINE( 149)			this->addToStage(this->upperBoppers);
HXLINE( 151)			 ::flixel::FlxSprite bgEscalator =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,-1100,-600,null());
HXDLIN( 151)			 ::flixel::FlxSprite bgEscalator1 = bgEscalator->loadGraphic(::Paths_obj::image(HX_("christmas/bgEscalator",64,1f,c0,d5),null()),null(),null(),null(),null(),null());
HXLINE( 152)			bgEscalator1->set_antialiasing(true);
HXLINE( 153)			bgEscalator1->scrollFactor->set(((Float)0.3),((Float)0.3));
HXLINE( 154)			bgEscalator1->set_active(false);
HXLINE( 155)			bgEscalator1->setGraphicSize(::Std_obj::_hx_int((bgEscalator1->get_width() * ((Float)0.9))),null());
HXLINE( 156)			bgEscalator1->updateHitbox();
HXLINE( 157)			this->addToStage(bgEscalator1);
HXLINE( 159)			 ::flixel::FlxSprite tree =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,370,-250,null());
HXDLIN( 159)			 ::flixel::FlxSprite tree1 = tree->loadGraphic(::Paths_obj::image(HX_("christmas/christmasTree",73,57,6d,7b),null()),null(),null(),null(),null(),null());
HXLINE( 160)			tree1->set_antialiasing(true);
HXLINE( 161)			tree1->scrollFactor->set(((Float)0.40),((Float)0.40));
HXLINE( 162)			this->addToStage(tree1);
HXLINE( 164)			this->bottomBoppers =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,-300,140,null());
HXLINE( 165)			 ::flixel::FlxSprite _hx_tmp3 = this->bottomBoppers;
HXDLIN( 165)			::String library1 = null();
HXDLIN( 165)			 ::Dynamic cache1 = null();
HXDLIN( 165)			::String cacheFile2 = HX_("",00,00,00,00);
HXDLIN( 165)			if (( (bool)(cache1) )) {
HXLINE( 165)				cacheFile2 = HX_("cache/",ad,5f,f2,b0);
            			}
HXDLIN( 165)			if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + HX_("christmas/bottomBop",cb,69,c5,59)))) {
HXLINE( 165)				cacheFile2 = HX_("",00,00,00,00);
            			}
HXDLIN( 165)			 ::flixel::graphics::frames::FlxAtlasFrames _hx_tmp4;
HXDLIN( 165)			::String cacheFile3 = HX_("",00,00,00,00);
HXDLIN( 165)			if (( (bool)(cache1) )) {
HXLINE( 165)				cacheFile3 = HX_("cache/",ad,5f,f2,b0);
            			}
HXDLIN( 165)			if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + HX_("christmas/bottomBop",cb,69,c5,59)))) {
HXLINE( 165)				cacheFile3 = HX_("",00,00,00,00);
            			}
HXDLIN( 165)			if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile3) + HX_("christmas/bottomBop",cb,69,c5,59)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library1),null())) {
HXLINE( 165)				if (::hx::IsNotNull( ::Paths_obj::ifImageCached((cacheFile2 + HX_("christmas/bottomBop",cb,69,c5,59))) )) {
HXLINE( 165)					 ::flixel::graphics::FlxGraphic _hx_tmp = ::Paths_obj::ifImageCached((cacheFile2 + HX_("christmas/bottomBop",cb,69,c5,59)));
HXDLIN( 165)					_hx_tmp4 = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSparrow(_hx_tmp,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile2) + HX_("christmas/bottomBop",cb,69,c5,59)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library1));
            				}
            				else {
HXLINE( 165)					::String _hx_tmp = ::Paths_obj::image((cacheFile2 + HX_("christmas/bottomBop",cb,69,c5,59)),library1);
HXDLIN( 165)					_hx_tmp4 = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSparrow(_hx_tmp,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile2) + HX_("christmas/bottomBop",cb,69,c5,59)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library1));
            				}
            			}
            			else {
HXLINE( 165)				HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate asset - ",17,30,f9,e8) + ::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile2) + HX_("christmas/bottomBop",cb,69,c5,59)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library1))));
            			}
HXDLIN( 165)			_hx_tmp3->set_frames(_hx_tmp4);
HXLINE( 166)			this->bottomBoppers->animation->addByPrefix(HX_("bop",03,be,4a,00),HX_("Bottom Level Boppers",c8,41,25,54),24,false,null(),null());
HXLINE( 167)			this->bottomBoppers->set_antialiasing(true);
HXLINE( 168)			this->bottomBoppers->scrollFactor->set(((Float)0.9),((Float)0.9));
HXLINE( 169)			 ::flixel::FlxSprite _hx_tmp5 = this->bottomBoppers;
HXDLIN( 169)			_hx_tmp5->setGraphicSize(::Std_obj::_hx_int(this->bottomBoppers->get_width()),null());
HXLINE( 170)			this->bottomBoppers->updateHitbox();
HXLINE( 171)			this->addToStage(this->bottomBoppers);
HXLINE( 173)			 ::flixel::FlxSprite fgSnow =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,-600,700,null());
HXDLIN( 173)			 ::flixel::FlxSprite fgSnow1 = fgSnow->loadGraphic(::Paths_obj::image(HX_("christmas/fgSnow",91,40,e7,37),null()),null(),null(),null(),null(),null());
HXLINE( 174)			fgSnow1->set_active(false);
HXLINE( 175)			fgSnow1->set_antialiasing(true);
HXLINE( 176)			this->addToStage(fgSnow1);
HXLINE( 178)			this->santa =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,-840,150,null());
HXLINE( 179)			 ::flixel::FlxSprite _hx_tmp6 = this->santa;
HXDLIN( 179)			::String library2 = null();
HXDLIN( 179)			 ::Dynamic cache2 = null();
HXDLIN( 179)			::String cacheFile4 = HX_("",00,00,00,00);
HXDLIN( 179)			if (( (bool)(cache2) )) {
HXLINE( 179)				cacheFile4 = HX_("cache/",ad,5f,f2,b0);
            			}
HXDLIN( 179)			if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + HX_("christmas/santa",00,86,f4,2d)))) {
HXLINE( 179)				cacheFile4 = HX_("",00,00,00,00);
            			}
HXDLIN( 179)			 ::flixel::graphics::frames::FlxAtlasFrames _hx_tmp7;
HXDLIN( 179)			::String cacheFile5 = HX_("",00,00,00,00);
HXDLIN( 179)			if (( (bool)(cache2) )) {
HXLINE( 179)				cacheFile5 = HX_("cache/",ad,5f,f2,b0);
            			}
HXDLIN( 179)			if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + HX_("christmas/santa",00,86,f4,2d)))) {
HXLINE( 179)				cacheFile5 = HX_("",00,00,00,00);
            			}
HXDLIN( 179)			if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile5) + HX_("christmas/santa",00,86,f4,2d)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library2),null())) {
HXLINE( 179)				if (::hx::IsNotNull( ::Paths_obj::ifImageCached((cacheFile4 + HX_("christmas/santa",00,86,f4,2d))) )) {
HXLINE( 179)					 ::flixel::graphics::FlxGraphic _hx_tmp = ::Paths_obj::ifImageCached((cacheFile4 + HX_("christmas/santa",00,86,f4,2d)));
HXDLIN( 179)					_hx_tmp7 = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSparrow(_hx_tmp,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile4) + HX_("christmas/santa",00,86,f4,2d)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library2));
            				}
            				else {
HXLINE( 179)					::String _hx_tmp = ::Paths_obj::image((cacheFile4 + HX_("christmas/santa",00,86,f4,2d)),library2);
HXDLIN( 179)					_hx_tmp7 = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSparrow(_hx_tmp,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile4) + HX_("christmas/santa",00,86,f4,2d)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library2));
            				}
            			}
            			else {
HXLINE( 179)				HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate asset - ",17,30,f9,e8) + ::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile4) + HX_("christmas/santa",00,86,f4,2d)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library2))));
            			}
HXDLIN( 179)			_hx_tmp6->set_frames(_hx_tmp7);
HXLINE( 180)			this->santa->animation->addByPrefix(HX_("idle",14,a7,b3,45),HX_("santa idle in fear",72,07,31,fd),24,false,null(),null());
HXLINE( 181)			this->santa->set_antialiasing(true);
HXLINE( 182)			this->addToStage(this->santa);
HXLINE( 131)			goto _hx_goto_0;
            		}
            		if (  (_hx_switch_0==HX_("mallEvil",88,d3,e3,a7)) ){
HXLINE( 186)			 ::flixel::FlxSprite bg =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,-400,-500,null());
HXDLIN( 186)			 ::flixel::FlxSprite bg1 = bg->loadGraphic(::Paths_obj::image(HX_("christmas/evilBG",86,9d,17,83),null()),null(),null(),null(),null(),null());
HXLINE( 187)			bg1->set_antialiasing(true);
HXLINE( 188)			bg1->scrollFactor->set(((Float)0.2),((Float)0.2));
HXLINE( 189)			bg1->set_active(false);
HXLINE( 190)			bg1->setGraphicSize(::Std_obj::_hx_int((bg1->get_width() * ((Float)0.8))),null());
HXLINE( 191)			bg1->updateHitbox();
HXLINE( 192)			this->addToStage(bg1);
HXLINE( 194)			 ::flixel::FlxSprite evilTree =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,300,-300,null());
HXDLIN( 194)			 ::flixel::FlxSprite evilTree1 = evilTree->loadGraphic(::Paths_obj::image(HX_("christmas/evilTree",7f,5b,65,3a),null()),null(),null(),null(),null(),null());
HXLINE( 195)			evilTree1->set_antialiasing(true);
HXLINE( 196)			evilTree1->scrollFactor->set(((Float)0.2),((Float)0.2));
HXLINE( 197)			this->addToStage(evilTree1);
HXLINE( 199)			 ::flixel::FlxSprite evilSnow =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,-200,700,null());
HXDLIN( 199)			 ::flixel::FlxSprite evilSnow1 = evilSnow->loadGraphic(::Paths_obj::image(HX_("christmas/evilSnow",a4,24,b9,39),null()),null(),null(),null(),null(),null());
HXLINE( 200)			evilSnow1->set_antialiasing(true);
HXLINE( 201)			this->addToStage(evilSnow1);
HXLINE( 185)			goto _hx_goto_0;
            		}
            		if (  (_hx_switch_0==HX_("philly",28,77,5e,ef)) ){
HXLINE(  46)			 ::flixel::FlxSprite bg =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,-100,null(),null());
HXDLIN(  46)			 ::flixel::FlxSprite bg1 = bg->loadGraphic(::Paths_obj::image(HX_("philly/sky",3a,d3,d5,cc),null()),null(),null(),null(),null(),null());
HXLINE(  47)			bg1->scrollFactor->set(((Float)0.1),((Float)0.1));
HXLINE(  48)			this->addToStage(bg1);
HXLINE(  50)			 ::flixel::FlxSprite city =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,-10,null(),null());
HXDLIN(  50)			 ::flixel::FlxSprite city1 = city->loadGraphic(::Paths_obj::image(HX_("philly/city",32,0d,ae,63),null()),null(),null(),null(),null(),null());
HXLINE(  51)			city1->scrollFactor->set(((Float)0.3),((Float)0.3));
HXLINE(  52)			city1->setGraphicSize(::Std_obj::_hx_int((city1->get_width() * ((Float)0.85))),null());
HXLINE(  53)			city1->updateHitbox();
HXLINE(  54)			this->addToStage(city1);
HXLINE(  56)			this->phillyCityLights =  ::flixel::group::FlxTypedGroup_obj::__alloc( HX_CTX ,null());
HXLINE(  57)			this->addToStage(this->phillyCityLights);
HXLINE(  59)			{
HXLINE(  60)				{
HXLINE(  61)					 ::flixel::FlxSprite light =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,city1->x,null(),null());
HXDLIN(  61)					 ::flixel::FlxSprite light1 = light->loadGraphic(::Paths_obj::image((HX_("philly/win",75,da,d8,cc) + 0),null()),null(),null(),null(),null(),null());
HXLINE(  62)					light1->scrollFactor->set(((Float)0.3),((Float)0.3));
HXLINE(  63)					light1->set_visible(false);
HXLINE(  64)					light1->setGraphicSize(::Std_obj::_hx_int((light1->get_width() * ((Float)0.85))),null());
HXLINE(  65)					light1->updateHitbox();
HXLINE(  66)					light1->set_antialiasing(true);
HXLINE(  67)					this->phillyCityLights->add(light1).StaticCast<  ::flixel::FlxSprite >();
            				}
HXLINE(  60)				{
HXLINE(  61)					 ::flixel::FlxSprite light2 =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,city1->x,null(),null());
HXDLIN(  61)					 ::flixel::FlxSprite light3 = light2->loadGraphic(::Paths_obj::image((HX_("philly/win",75,da,d8,cc) + 1),null()),null(),null(),null(),null(),null());
HXLINE(  62)					light3->scrollFactor->set(((Float)0.3),((Float)0.3));
HXLINE(  63)					light3->set_visible(false);
HXLINE(  64)					light3->setGraphicSize(::Std_obj::_hx_int((light3->get_width() * ((Float)0.85))),null());
HXLINE(  65)					light3->updateHitbox();
HXLINE(  66)					light3->set_antialiasing(true);
HXLINE(  67)					this->phillyCityLights->add(light3).StaticCast<  ::flixel::FlxSprite >();
            				}
HXLINE(  60)				{
HXLINE(  61)					 ::flixel::FlxSprite light4 =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,city1->x,null(),null());
HXDLIN(  61)					 ::flixel::FlxSprite light5 = light4->loadGraphic(::Paths_obj::image((HX_("philly/win",75,da,d8,cc) + 2),null()),null(),null(),null(),null(),null());
HXLINE(  62)					light5->scrollFactor->set(((Float)0.3),((Float)0.3));
HXLINE(  63)					light5->set_visible(false);
HXLINE(  64)					light5->setGraphicSize(::Std_obj::_hx_int((light5->get_width() * ((Float)0.85))),null());
HXLINE(  65)					light5->updateHitbox();
HXLINE(  66)					light5->set_antialiasing(true);
HXLINE(  67)					this->phillyCityLights->add(light5).StaticCast<  ::flixel::FlxSprite >();
            				}
HXLINE(  60)				{
HXLINE(  61)					 ::flixel::FlxSprite light6 =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,city1->x,null(),null());
HXDLIN(  61)					 ::flixel::FlxSprite light7 = light6->loadGraphic(::Paths_obj::image((HX_("philly/win",75,da,d8,cc) + 3),null()),null(),null(),null(),null(),null());
HXLINE(  62)					light7->scrollFactor->set(((Float)0.3),((Float)0.3));
HXLINE(  63)					light7->set_visible(false);
HXLINE(  64)					light7->setGraphicSize(::Std_obj::_hx_int((light7->get_width() * ((Float)0.85))),null());
HXLINE(  65)					light7->updateHitbox();
HXLINE(  66)					light7->set_antialiasing(true);
HXLINE(  67)					this->phillyCityLights->add(light7).StaticCast<  ::flixel::FlxSprite >();
            				}
HXLINE(  60)				{
HXLINE(  61)					 ::flixel::FlxSprite light8 =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,city1->x,null(),null());
HXDLIN(  61)					 ::flixel::FlxSprite light9 = light8->loadGraphic(::Paths_obj::image((HX_("philly/win",75,da,d8,cc) + 4),null()),null(),null(),null(),null(),null());
HXLINE(  62)					light9->scrollFactor->set(((Float)0.3),((Float)0.3));
HXLINE(  63)					light9->set_visible(false);
HXLINE(  64)					light9->setGraphicSize(::Std_obj::_hx_int((light9->get_width() * ((Float)0.85))),null());
HXLINE(  65)					light9->updateHitbox();
HXLINE(  66)					light9->set_antialiasing(true);
HXLINE(  67)					this->phillyCityLights->add(light9).StaticCast<  ::flixel::FlxSprite >();
            				}
            			}
HXLINE(  70)			 ::flixel::FlxSprite streetBehind =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,-40,50,null());
HXDLIN(  70)			 ::flixel::FlxSprite streetBehind1 = streetBehind->loadGraphic(::Paths_obj::image(HX_("philly/behindTrain",07,a4,6d,d4),null()),null(),null(),null(),null(),null());
HXLINE(  71)			this->addToStage(streetBehind1);
HXLINE(  73)			 ::flixel::FlxSprite _hx_tmp =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,2000,360,null());
HXDLIN(  73)			this->phillyTrain = _hx_tmp->loadGraphic(::Paths_obj::image(HX_("philly/train",61,ce,51,a4),null()),null(),null(),null(),null(),null());
HXLINE(  74)			this->addToStage(this->phillyTrain);
HXLINE(  76)			 ::flixel::_hx_system::FlxSound _hx_tmp1 =  ::flixel::_hx_system::FlxSound_obj::__alloc( HX_CTX );
HXDLIN(  76)			::String library = null();
HXDLIN(  76)			::String _hx_tmp2;
HXDLIN(  76)			if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("sounds/",eb,02,a5,b6) + HX_("train_passes",56,da,5a,7f)) + HX_(".",2e,00,00,00)) + HX_("ogg",4f,94,54,00)),HX_("SOUND",af,c4,ba,fe),library),null())) {
HXLINE(  76)				_hx_tmp2 = ::Paths_obj::getPath((((HX_("sounds/",eb,02,a5,b6) + HX_("train_passes",56,da,5a,7f)) + HX_(".",2e,00,00,00)) + HX_("ogg",4f,94,54,00)),HX_("SOUND",af,c4,ba,fe),library);
            			}
            			else {
HXLINE(  76)				HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate sound - ",98,e2,ed,38) + HX_("train_passes",56,da,5a,7f))));
            			}
HXDLIN(  76)			this->trainSound = _hx_tmp1->loadEmbedded(_hx_tmp2,null(),null(),null());
HXLINE(  77)			::flixel::FlxG_obj::sound->list->add(this->trainSound).StaticCast<  ::flixel::_hx_system::FlxSound >();
HXLINE(  81)			 ::flixel::FlxSprite street =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,-40,streetBehind1->y,null());
HXDLIN(  81)			 ::flixel::FlxSprite street1 = street->loadGraphic(::Paths_obj::image(HX_("philly/street",4a,23,ee,ee),null()),null(),null(),null(),null(),null());
HXLINE(  82)			this->addToStage(street1);
HXLINE(  45)			goto _hx_goto_0;
            		}
            		if (  (_hx_switch_0==HX_("school",74,b8,c8,40)) ){
HXLINE( 205)			this->setPixel(true);
HXLINE( 207)			 ::flixel::FlxSprite bgSky =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,null(),null(),null());
HXDLIN( 207)			 ::flixel::FlxSprite bgSky1 = bgSky->loadGraphic(::Paths_obj::image(HX_("weeb/weebSky",52,34,cf,a4),null()),null(),null(),null(),null(),null());
HXLINE( 208)			bgSky1->scrollFactor->set(((Float)0.1),((Float)0.1));
HXLINE( 209)			this->addToStage(bgSky1);
HXLINE( 211)			int repositionShit = -200;
HXLINE( 213)			 ::flixel::FlxSprite bgSchool =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,repositionShit,0,null());
HXDLIN( 213)			 ::flixel::FlxSprite bgSchool1 = bgSchool->loadGraphic(::Paths_obj::image(HX_("weeb/weebSchool",a3,21,c0,f5),null()),null(),null(),null(),null(),null());
HXLINE( 214)			bgSchool1->scrollFactor->set(((Float)0.6),((Float)0.90));
HXLINE( 215)			this->addToStage(bgSchool1);
HXLINE( 217)			 ::flixel::FlxSprite bgStreet =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,repositionShit,null(),null());
HXDLIN( 217)			 ::flixel::FlxSprite bgStreet1 = bgStreet->loadGraphic(::Paths_obj::image(HX_("weeb/weebStreet",32,81,24,c6),null()),null(),null(),null(),null(),null());
HXLINE( 218)			bgStreet1->scrollFactor->set(((Float)0.95),((Float)0.95));
HXLINE( 219)			this->addToStage(bgStreet1);
HXLINE( 221)			 ::flixel::FlxSprite fgTrees =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,(repositionShit + 170),130,null());
HXDLIN( 221)			 ::flixel::FlxSprite fgTrees1 = fgTrees->loadGraphic(::Paths_obj::image(HX_("weeb/weebTreesBack",4d,ac,bd,40),null()),null(),null(),null(),null(),null());
HXLINE( 222)			fgTrees1->scrollFactor->set(((Float)0.9),((Float)0.9));
HXLINE( 223)			this->addToStage(fgTrees1);
HXLINE( 225)			 ::flixel::FlxSprite bgTrees =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,(repositionShit - 380),-800,null());
HXLINE( 226)			::String library = null();
HXDLIN( 226)			 ::Dynamic cache = null();
HXDLIN( 226)			::String cacheFile = HX_("",00,00,00,00);
HXDLIN( 226)			if (( (bool)(cache) )) {
HXLINE( 226)				cacheFile = HX_("cache/",ad,5f,f2,b0);
            			}
HXDLIN( 226)			if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + HX_("weeb/weebTrees",06,ab,3a,76)))) {
HXLINE( 226)				cacheFile = HX_("",00,00,00,00);
            			}
HXDLIN( 226)			 ::flixel::graphics::frames::FlxAtlasFrames treetex;
HXDLIN( 226)			if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + HX_("weeb/weebTrees",06,ab,3a,76)) + HX_(".txt",02,3f,c0,1e)),HX_("TEXT",ad,94,ba,37),library),null())) {
HXLINE( 226)				if (::hx::IsNotNull( ::Paths_obj::ifImageCached((cacheFile + HX_("weeb/weebTrees",06,ab,3a,76))) )) {
HXLINE( 226)					 ::flixel::graphics::FlxGraphic treetex1 = ::Paths_obj::ifImageCached((cacheFile + HX_("weeb/weebTrees",06,ab,3a,76)));
HXDLIN( 226)					treetex = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSpriteSheetPacker(treetex1,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + HX_("weeb/weebTrees",06,ab,3a,76)) + HX_(".txt",02,3f,c0,1e)),HX_("TEXT",ad,94,ba,37),library));
            				}
            				else {
HXLINE( 226)					::String treetex1 = ::Paths_obj::image((cacheFile + HX_("weeb/weebTrees",06,ab,3a,76)),library);
HXDLIN( 226)					treetex = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSpriteSheetPacker(treetex1,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + HX_("weeb/weebTrees",06,ab,3a,76)) + HX_(".txt",02,3f,c0,1e)),HX_("TEXT",ad,94,ba,37),library));
            				}
            			}
            			else {
HXLINE( 226)				HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate asset - ",17,30,f9,e8) + ::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + HX_("weeb/weebTrees",06,ab,3a,76)) + HX_(".txt",02,3f,c0,1e)),HX_("TEXT",ad,94,ba,37),library))));
            			}
HXLINE( 227)			bgTrees->set_frames(treetex);
HXLINE( 228)			bgTrees->animation->add(HX_("treeLoop",e2,72,7f,2b),::Array_obj< int >::fromData( _hx_array_data_408fd5a9_2,19),12,null(),null(),null());
HXLINE( 229)			bgTrees->animation->play(HX_("treeLoop",e2,72,7f,2b),null(),null(),null());
HXLINE( 230)			bgTrees->scrollFactor->set(((Float)0.85),((Float)0.85));
HXLINE( 231)			this->addToStage(bgTrees);
HXLINE( 233)			 ::flixel::FlxSprite treeLeaves =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,repositionShit,-40,null());
HXLINE( 234)			::String library1 = null();
HXDLIN( 234)			 ::Dynamic cache1 = null();
HXDLIN( 234)			::String cacheFile1 = HX_("",00,00,00,00);
HXDLIN( 234)			if (( (bool)(cache1) )) {
HXLINE( 234)				cacheFile1 = HX_("cache/",ad,5f,f2,b0);
            			}
HXDLIN( 234)			if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + HX_("weeb/petals",8d,ca,2b,c2)))) {
HXLINE( 234)				cacheFile1 = HX_("",00,00,00,00);
            			}
HXDLIN( 234)			 ::flixel::graphics::frames::FlxAtlasFrames _hx_tmp;
HXDLIN( 234)			::String cacheFile2 = HX_("",00,00,00,00);
HXDLIN( 234)			if (( (bool)(cache1) )) {
HXLINE( 234)				cacheFile2 = HX_("cache/",ad,5f,f2,b0);
            			}
HXDLIN( 234)			if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + HX_("weeb/petals",8d,ca,2b,c2)))) {
HXLINE( 234)				cacheFile2 = HX_("",00,00,00,00);
            			}
HXDLIN( 234)			if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile2) + HX_("weeb/petals",8d,ca,2b,c2)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library1),null())) {
HXLINE( 234)				if (::hx::IsNotNull( ::Paths_obj::ifImageCached((cacheFile1 + HX_("weeb/petals",8d,ca,2b,c2))) )) {
HXLINE( 234)					 ::flixel::graphics::FlxGraphic _hx_tmp1 = ::Paths_obj::ifImageCached((cacheFile1 + HX_("weeb/petals",8d,ca,2b,c2)));
HXDLIN( 234)					_hx_tmp = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSparrow(_hx_tmp1,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile1) + HX_("weeb/petals",8d,ca,2b,c2)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library1));
            				}
            				else {
HXLINE( 234)					::String _hx_tmp1 = ::Paths_obj::image((cacheFile1 + HX_("weeb/petals",8d,ca,2b,c2)),library1);
HXDLIN( 234)					_hx_tmp = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSparrow(_hx_tmp1,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile1) + HX_("weeb/petals",8d,ca,2b,c2)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library1));
            				}
            			}
            			else {
HXLINE( 234)				HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate asset - ",17,30,f9,e8) + ::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile1) + HX_("weeb/petals",8d,ca,2b,c2)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library1))));
            			}
HXDLIN( 234)			treeLeaves->set_frames(_hx_tmp);
HXLINE( 235)			treeLeaves->animation->addByPrefix(HX_("leaves",9c,23,7b,96),HX_("PETALS ALL",0a,57,91,88),24,true,null(),null());
HXLINE( 236)			treeLeaves->animation->play(HX_("leaves",9c,23,7b,96),null(),null(),null());
HXLINE( 237)			treeLeaves->scrollFactor->set(((Float)0.85),((Float)0.85));
HXLINE( 238)			this->addToStage(treeLeaves);
HXLINE( 240)			int widShit = ::Std_obj::_hx_int((bgSky1->get_width() * ( (Float)(6) )));
HXLINE( 242)			bgSky1->setGraphicSize(widShit,null());
HXLINE( 243)			bgSchool1->setGraphicSize(widShit,null());
HXLINE( 244)			bgStreet1->setGraphicSize(widShit,null());
HXLINE( 245)			bgTrees->setGraphicSize(::Std_obj::_hx_int((( (Float)(widShit) ) * ((Float)1.4))),null());
HXLINE( 246)			fgTrees1->setGraphicSize(::Std_obj::_hx_int((( (Float)(widShit) ) * ((Float)0.8))),null());
HXLINE( 247)			treeLeaves->setGraphicSize(widShit,null());
HXLINE( 249)			fgTrees1->updateHitbox();
HXLINE( 250)			bgSky1->updateHitbox();
HXLINE( 251)			bgSchool1->updateHitbox();
HXLINE( 252)			bgStreet1->updateHitbox();
HXLINE( 253)			bgTrees->updateHitbox();
HXLINE( 254)			treeLeaves->updateHitbox();
HXLINE( 256)			this->bgGirls =  ::BackgroundGirls_obj::__alloc( HX_CTX ,( (Float)(-100) ),( (Float)(190) ));
HXLINE( 257)			this->bgGirls->scrollFactor->set(((Float)0.9),((Float)0.9));
HXLINE( 259)			if ((song == HX_("roses",04,6c,64,ed))) {
HXLINE( 261)				this->bgGirls->getScared();
            			}
HXLINE( 264)			 ::BackgroundGirls _hx_tmp1 = this->bgGirls;
HXDLIN( 264)			_hx_tmp1->setGraphicSize(::Std_obj::_hx_int((this->bgGirls->get_width() * ( (Float)(6) ))),null());
HXLINE( 265)			this->bgGirls->updateHitbox();
HXLINE( 266)			this->addToStage(this->bgGirls);
HXLINE( 204)			goto _hx_goto_0;
            		}
            		if (  (_hx_switch_0==HX_("schoolEvil",28,a1,f5,f7)) ){
HXLINE( 270)			this->setPixel(true);
HXLINE( 272)			 ::flixel::addons::effects::chainable::FlxWaveEffect waveEffectBG =  ::flixel::addons::effects::chainable::FlxWaveEffect_obj::__alloc( HX_CTX ,::flixel::addons::effects::chainable::FlxWaveMode_obj::ALL_dyn(),2,-1,3,2,null(),null());
HXLINE( 273)			 ::flixel::addons::effects::chainable::FlxWaveEffect waveEffectFG =  ::flixel::addons::effects::chainable::FlxWaveEffect_obj::__alloc( HX_CTX ,::flixel::addons::effects::chainable::FlxWaveMode_obj::ALL_dyn(),2,-1,5,2,null(),null());
HXLINE( 275)			int posX = 400;
HXLINE( 276)			int posY = 200;
HXLINE( 278)			 ::flixel::FlxSprite bg =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,posX,posY,null());
HXLINE( 279)			::String library = null();
HXDLIN( 279)			 ::Dynamic cache = null();
HXDLIN( 279)			::String cacheFile = HX_("",00,00,00,00);
HXDLIN( 279)			if (( (bool)(cache) )) {
HXLINE( 279)				cacheFile = HX_("cache/",ad,5f,f2,b0);
            			}
HXDLIN( 279)			if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + HX_("weeb/animatedEvilSchool",8f,dd,53,cd)))) {
HXLINE( 279)				cacheFile = HX_("",00,00,00,00);
            			}
HXDLIN( 279)			 ::flixel::graphics::frames::FlxAtlasFrames _hx_tmp;
HXDLIN( 279)			::String cacheFile1 = HX_("",00,00,00,00);
HXDLIN( 279)			if (( (bool)(cache) )) {
HXLINE( 279)				cacheFile1 = HX_("cache/",ad,5f,f2,b0);
            			}
HXDLIN( 279)			if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + HX_("weeb/animatedEvilSchool",8f,dd,53,cd)))) {
HXLINE( 279)				cacheFile1 = HX_("",00,00,00,00);
            			}
HXDLIN( 279)			if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile1) + HX_("weeb/animatedEvilSchool",8f,dd,53,cd)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library),null())) {
HXLINE( 279)				if (::hx::IsNotNull( ::Paths_obj::ifImageCached((cacheFile + HX_("weeb/animatedEvilSchool",8f,dd,53,cd))) )) {
HXLINE( 279)					 ::flixel::graphics::FlxGraphic _hx_tmp1 = ::Paths_obj::ifImageCached((cacheFile + HX_("weeb/animatedEvilSchool",8f,dd,53,cd)));
HXDLIN( 279)					_hx_tmp = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSparrow(_hx_tmp1,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + HX_("weeb/animatedEvilSchool",8f,dd,53,cd)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library));
            				}
            				else {
HXLINE( 279)					::String _hx_tmp1 = ::Paths_obj::image((cacheFile + HX_("weeb/animatedEvilSchool",8f,dd,53,cd)),library);
HXDLIN( 279)					_hx_tmp = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSparrow(_hx_tmp1,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + HX_("weeb/animatedEvilSchool",8f,dd,53,cd)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library));
            				}
            			}
            			else {
HXLINE( 279)				HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate asset - ",17,30,f9,e8) + ::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + HX_("weeb/animatedEvilSchool",8f,dd,53,cd)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library))));
            			}
HXDLIN( 279)			bg->set_frames(_hx_tmp);
HXLINE( 280)			bg->animation->addByPrefix(HX_("idle",14,a7,b3,45),HX_("background 2",80,07,9d,17),24,null(),null(),null());
HXLINE( 281)			bg->animation->play(HX_("idle",14,a7,b3,45),null(),null(),null());
HXLINE( 282)			bg->scrollFactor->set(((Float)0.8),((Float)0.9));
HXLINE( 283)			bg->scale->set(6,6);
HXLINE( 284)			this->addToStage(bg);
HXLINE( 269)			goto _hx_goto_0;
            		}
            		if (  (_hx_switch_0==HX_("spooky",eb,bd,9e,c1)) ){
HXLINE(  34)			::String library = null();
HXDLIN(  34)			 ::Dynamic cache = null();
HXDLIN(  34)			::String cacheFile = HX_("",00,00,00,00);
HXDLIN(  34)			if (( (bool)(cache) )) {
HXLINE(  34)				cacheFile = HX_("cache/",ad,5f,f2,b0);
            			}
HXDLIN(  34)			if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + HX_("halloween_bg",77,a6,29,9b)))) {
HXLINE(  34)				cacheFile = HX_("",00,00,00,00);
            			}
HXDLIN(  34)			 ::flixel::graphics::frames::FlxAtlasFrames hallowTex;
HXDLIN(  34)			::String cacheFile1 = HX_("",00,00,00,00);
HXDLIN(  34)			if (( (bool)(cache) )) {
HXLINE(  34)				cacheFile1 = HX_("cache/",ad,5f,f2,b0);
            			}
HXDLIN(  34)			if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + HX_("halloween_bg",77,a6,29,9b)))) {
HXLINE(  34)				cacheFile1 = HX_("",00,00,00,00);
            			}
HXDLIN(  34)			if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile1) + HX_("halloween_bg",77,a6,29,9b)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library),null())) {
HXLINE(  34)				if (::hx::IsNotNull( ::Paths_obj::ifImageCached((cacheFile + HX_("halloween_bg",77,a6,29,9b))) )) {
HXLINE(  34)					 ::flixel::graphics::FlxGraphic hallowTex1 = ::Paths_obj::ifImageCached((cacheFile + HX_("halloween_bg",77,a6,29,9b)));
HXDLIN(  34)					hallowTex = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSparrow(hallowTex1,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + HX_("halloween_bg",77,a6,29,9b)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library));
            				}
            				else {
HXLINE(  34)					::String hallowTex1 = ::Paths_obj::image((cacheFile + HX_("halloween_bg",77,a6,29,9b)),library);
HXDLIN(  34)					hallowTex = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSparrow(hallowTex1,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + HX_("halloween_bg",77,a6,29,9b)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library));
            				}
            			}
            			else {
HXLINE(  34)				HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate asset - ",17,30,f9,e8) + ::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + HX_("halloween_bg",77,a6,29,9b)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library))));
            			}
HXLINE(  36)			this->halloweenBG =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,-200,-100,null());
HXLINE(  37)			this->halloweenBG->set_frames(hallowTex);
HXLINE(  38)			this->halloweenBG->animation->addByPrefix(HX_("idle",14,a7,b3,45),HX_("halloweem bg0",37,fc,3c,6c),null(),null(),null(),null());
HXLINE(  39)			this->halloweenBG->animation->addByPrefix(HX_("lightning",0a,39,4a,d7),HX_("halloweem bg lightning strike",af,54,50,5b),24,false,null(),null());
HXLINE(  40)			this->halloweenBG->animation->play(HX_("idle",14,a7,b3,45),null(),null(),null());
HXLINE(  41)			this->halloweenBG->set_antialiasing(( (bool)(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic)) ));
HXLINE(  42)			this->addToStage(this->halloweenBG);
HXLINE(  33)			goto _hx_goto_0;
            		}
            		/* default */{
HXLINE( 288)			this->setDefaultCameraZoom(((Float)0.90));
HXLINE( 290)			 ::flixel::FlxSprite bg =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,-600,-200,null());
HXDLIN( 290)			 ::flixel::FlxSprite bg1 = bg->loadGraphic(::Paths_obj::image(HX_("stageback",e5,7b,3b,06),null()),null(),null(),null(),null(),null());
HXLINE( 291)			bg1->set_antialiasing(true);
HXLINE( 292)			bg1->scrollFactor->set(((Float)0.9),((Float)0.9));
HXLINE( 293)			bg1->set_active(false);
HXLINE( 294)			this->addToStage(bg1);
HXLINE( 296)			 ::flixel::FlxSprite stageFront =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,-650,600,null());
HXDLIN( 296)			 ::flixel::FlxSprite stageFront1 = stageFront->loadGraphic(::Paths_obj::image(HX_("stagefront",2b,fd,b0,c6),null()),null(),null(),null(),null(),null());
HXLINE( 297)			stageFront1->setGraphicSize(::Std_obj::_hx_int((stageFront1->get_width() * ((Float)1.1))),null());
HXLINE( 298)			stageFront1->updateHitbox();
HXLINE( 299)			stageFront1->set_antialiasing(true);
HXLINE( 300)			stageFront1->scrollFactor->set(((Float)0.9),((Float)0.9));
HXLINE( 301)			stageFront1->set_active(false);
HXLINE( 302)			this->addToStage(stageFront1);
HXLINE( 304)			 ::flixel::FlxSprite stageCurtains =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,-500,-300,null());
HXDLIN( 304)			 ::flixel::FlxSprite stageCurtains1 = stageCurtains->loadGraphic(::Paths_obj::image(HX_("stagecurtains",df,ec,1a,4b),null()),null(),null(),null(),null(),null());
HXLINE( 305)			stageCurtains1->setGraphicSize(::Std_obj::_hx_int((stageCurtains1->get_width() * ((Float)0.9))),null());
HXLINE( 306)			stageCurtains1->updateHitbox();
HXLINE( 307)			stageCurtains1->set_antialiasing(true);
HXLINE( 308)			stageCurtains1->scrollFactor->set(((Float)1.3),((Float)1.3));
HXLINE( 309)			stageCurtains1->set_active(false);
HXLINE( 311)			this->addToStage(stageCurtains1);
            		}
            		_hx_goto_0:;
            	}

Dynamic DefaultStage_obj::__CreateEmpty() { return new DefaultStage_obj; }

void *DefaultStage_obj::_hx_vtable = 0;

Dynamic DefaultStage_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< DefaultStage_obj > _hx_result = new DefaultStage_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool DefaultStage_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x296008c7) {
		if (inClassId<=(int)0x0b48a01f) {
			return inClassId==(int)0x00000001 || inClassId==(int)0x0b48a01f;
		} else {
			return inClassId==(int)0x296008c7;
		}
	} else {
		return inClassId==(int)0x7ccf8994;
	}
}

void DefaultStage_obj::destroy(){
            	HX_STACKFRAME(&_hx_pos_95b33a292328d79f_317_destroy)
HXDLIN( 317)		this->super::destroy();
            	}


::String DefaultStage_obj::setMainGameStage(::String song){
            	HX_STACKFRAME(&_hx_pos_95b33a292328d79f_326_setMainGameStage)
HXDLIN( 326)		::String _hx_switch_0 = song.toLowerCase();
            		if (  (_hx_switch_0==HX_("cocoa",09,9d,55,4a)) ||  (_hx_switch_0==HX_("eggnog",61,04,ba,f4)) ){
HXLINE( 334)			return HX_("mall",d4,3a,56,48);
HXDLIN( 334)			goto _hx_goto_4;
            		}
            		if (  (_hx_switch_0==HX_("monster",1a,54,b0,b8)) ||  (_hx_switch_0==HX_("south",0d,92,cc,80)) ||  (_hx_switch_0==HX_("spookeez",0c,7a,2b,75)) ){
HXLINE( 328)			return HX_("spooky",eb,bd,9e,c1);
HXDLIN( 328)			goto _hx_goto_4;
            		}
            		if (  (_hx_switch_0==HX_("blammed",96,02,00,3c)) ||  (_hx_switch_0==HX_("philly",28,77,5e,ef)) ||  (_hx_switch_0==HX_("pico",e5,e8,57,4a)) ){
HXLINE( 330)			return HX_("philly",28,77,5e,ef);
HXDLIN( 330)			goto _hx_goto_4;
            		}
            		if (  (_hx_switch_0==HX_("high",62,37,0e,45)) ||  (_hx_switch_0==HX_("milf",d6,4c,5c,48)) ||  (_hx_switch_0==HX_("satin-panties",fe,64,00,d1)) ){
HXLINE( 332)			return HX_("limo",1f,17,b3,47);
HXDLIN( 332)			goto _hx_goto_4;
            		}
            		if (  (_hx_switch_0==HX_("roses",04,6c,64,ed)) ||  (_hx_switch_0==HX_("senpai",3c,df,8d,6b)) ){
HXLINE( 338)			return HX_("school",74,b8,c8,40);
HXDLIN( 338)			goto _hx_goto_4;
            		}
            		if (  (_hx_switch_0==HX_("thorns",9c,bf,c7,8c)) ){
HXLINE( 340)			return HX_("schoolEvil",28,a1,f5,f7);
HXDLIN( 340)			goto _hx_goto_4;
            		}
            		if (  (_hx_switch_0==HX_("winter-horrorland",9d,39,f4,1e)) ){
HXLINE( 336)			return HX_("mallEvil",88,d3,e3,a7);
HXDLIN( 336)			goto _hx_goto_4;
            		}
            		/* default */{
HXLINE( 342)			return HX_("stage",be,6a,0b,84);
            		}
            		_hx_goto_4:;
HXLINE( 326)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(DefaultStage_obj,setMainGameStage,return )


::hx::ObjectPtr< DefaultStage_obj > DefaultStage_obj::__new(::String song) {
	::hx::ObjectPtr< DefaultStage_obj > __this = new DefaultStage_obj();
	__this->__construct(song);
	return __this;
}

::hx::ObjectPtr< DefaultStage_obj > DefaultStage_obj::__alloc(::hx::Ctx *_hx_ctx,::String song) {
	DefaultStage_obj *__this = (DefaultStage_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(DefaultStage_obj), true, "example_code.DefaultStage"));
	*(void **)__this = DefaultStage_obj::_hx_vtable;
	__this->__construct(song);
	return __this;
}

DefaultStage_obj::DefaultStage_obj()
{
}

void DefaultStage_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(DefaultStage);
	HX_MARK_MEMBER_NAME(halloweenBG,"halloweenBG");
	HX_MARK_MEMBER_NAME(phillyCityLights,"phillyCityLights");
	HX_MARK_MEMBER_NAME(grpLimoDancers,"grpLimoDancers");
	HX_MARK_MEMBER_NAME(phillyTrain,"phillyTrain");
	HX_MARK_MEMBER_NAME(limo,"limo");
	HX_MARK_MEMBER_NAME(upperBoppers,"upperBoppers");
	HX_MARK_MEMBER_NAME(bottomBoppers,"bottomBoppers");
	HX_MARK_MEMBER_NAME(fastCar,"fastCar");
	HX_MARK_MEMBER_NAME(santa,"santa");
	HX_MARK_MEMBER_NAME(bgGirls,"bgGirls");
	HX_MARK_MEMBER_NAME(trainSound,"trainSound");
	HX_MARK_MEMBER_NAME(isPixel,"isPixel");
	 ::_hx_template::StageBuilder_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void DefaultStage_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(halloweenBG,"halloweenBG");
	HX_VISIT_MEMBER_NAME(phillyCityLights,"phillyCityLights");
	HX_VISIT_MEMBER_NAME(grpLimoDancers,"grpLimoDancers");
	HX_VISIT_MEMBER_NAME(phillyTrain,"phillyTrain");
	HX_VISIT_MEMBER_NAME(limo,"limo");
	HX_VISIT_MEMBER_NAME(upperBoppers,"upperBoppers");
	HX_VISIT_MEMBER_NAME(bottomBoppers,"bottomBoppers");
	HX_VISIT_MEMBER_NAME(fastCar,"fastCar");
	HX_VISIT_MEMBER_NAME(santa,"santa");
	HX_VISIT_MEMBER_NAME(bgGirls,"bgGirls");
	HX_VISIT_MEMBER_NAME(trainSound,"trainSound");
	HX_VISIT_MEMBER_NAME(isPixel,"isPixel");
	 ::_hx_template::StageBuilder_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val DefaultStage_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"limo") ) { return ::hx::Val( limo ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"santa") ) { return ::hx::Val( santa ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"fastCar") ) { return ::hx::Val( fastCar ); }
		if (HX_FIELD_EQ(inName,"bgGirls") ) { return ::hx::Val( bgGirls ); }
		if (HX_FIELD_EQ(inName,"isPixel") ) { return ::hx::Val( isPixel ); }
		if (HX_FIELD_EQ(inName,"destroy") ) { return ::hx::Val( destroy_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"trainSound") ) { return ::hx::Val( trainSound ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"halloweenBG") ) { return ::hx::Val( halloweenBG ); }
		if (HX_FIELD_EQ(inName,"phillyTrain") ) { return ::hx::Val( phillyTrain ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"upperBoppers") ) { return ::hx::Val( upperBoppers ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"bottomBoppers") ) { return ::hx::Val( bottomBoppers ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"grpLimoDancers") ) { return ::hx::Val( grpLimoDancers ); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"phillyCityLights") ) { return ::hx::Val( phillyCityLights ); }
	}
	return super::__Field(inName,inCallProp);
}

bool DefaultStage_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 16:
		if (HX_FIELD_EQ(inName,"setMainGameStage") ) { outValue = setMainGameStage_dyn(); return true; }
	}
	return false;
}

::hx::Val DefaultStage_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"limo") ) { limo=inValue.Cast<  ::flixel::FlxSprite >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"santa") ) { santa=inValue.Cast<  ::flixel::FlxSprite >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"fastCar") ) { fastCar=inValue.Cast<  ::flixel::FlxSprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bgGirls") ) { bgGirls=inValue.Cast<  ::BackgroundGirls >(); return inValue; }
		if (HX_FIELD_EQ(inName,"isPixel") ) { isPixel=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"trainSound") ) { trainSound=inValue.Cast<  ::flixel::_hx_system::FlxSound >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"halloweenBG") ) { halloweenBG=inValue.Cast<  ::flixel::FlxSprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"phillyTrain") ) { phillyTrain=inValue.Cast<  ::flixel::FlxSprite >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"upperBoppers") ) { upperBoppers=inValue.Cast<  ::flixel::FlxSprite >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"bottomBoppers") ) { bottomBoppers=inValue.Cast<  ::flixel::FlxSprite >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"grpLimoDancers") ) { grpLimoDancers=inValue.Cast<  ::flixel::group::FlxTypedGroup >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"phillyCityLights") ) { phillyCityLights=inValue.Cast<  ::flixel::group::FlxTypedGroup >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void DefaultStage_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("halloweenBG",92,b2,88,5c));
	outFields->push(HX_("phillyCityLights",30,e0,12,1f));
	outFields->push(HX_("grpLimoDancers",70,18,93,51));
	outFields->push(HX_("phillyTrain",80,9b,65,bb));
	outFields->push(HX_("limo",1f,17,b3,47));
	outFields->push(HX_("upperBoppers",37,47,71,21));
	outFields->push(HX_("bottomBoppers",ce,2c,ba,6e));
	outFields->push(HX_("fastCar",d8,f2,1f,de));
	outFields->push(HX_("santa",8d,45,86,77));
	outFields->push(HX_("bgGirls",92,16,2b,41));
	outFields->push(HX_("trainSound",e7,b3,e5,da));
	outFields->push(HX_("isPixel",3c,6a,29,5f));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo DefaultStage_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::flixel::FlxSprite */ ,(int)offsetof(DefaultStage_obj,halloweenBG),HX_("halloweenBG",92,b2,88,5c)},
	{::hx::fsObject /*  ::flixel::group::FlxTypedGroup */ ,(int)offsetof(DefaultStage_obj,phillyCityLights),HX_("phillyCityLights",30,e0,12,1f)},
	{::hx::fsObject /*  ::flixel::group::FlxTypedGroup */ ,(int)offsetof(DefaultStage_obj,grpLimoDancers),HX_("grpLimoDancers",70,18,93,51)},
	{::hx::fsObject /*  ::flixel::FlxSprite */ ,(int)offsetof(DefaultStage_obj,phillyTrain),HX_("phillyTrain",80,9b,65,bb)},
	{::hx::fsObject /*  ::flixel::FlxSprite */ ,(int)offsetof(DefaultStage_obj,limo),HX_("limo",1f,17,b3,47)},
	{::hx::fsObject /*  ::flixel::FlxSprite */ ,(int)offsetof(DefaultStage_obj,upperBoppers),HX_("upperBoppers",37,47,71,21)},
	{::hx::fsObject /*  ::flixel::FlxSprite */ ,(int)offsetof(DefaultStage_obj,bottomBoppers),HX_("bottomBoppers",ce,2c,ba,6e)},
	{::hx::fsObject /*  ::flixel::FlxSprite */ ,(int)offsetof(DefaultStage_obj,fastCar),HX_("fastCar",d8,f2,1f,de)},
	{::hx::fsObject /*  ::flixel::FlxSprite */ ,(int)offsetof(DefaultStage_obj,santa),HX_("santa",8d,45,86,77)},
	{::hx::fsObject /*  ::BackgroundGirls */ ,(int)offsetof(DefaultStage_obj,bgGirls),HX_("bgGirls",92,16,2b,41)},
	{::hx::fsObject /*  ::flixel::_hx_system::FlxSound */ ,(int)offsetof(DefaultStage_obj,trainSound),HX_("trainSound",e7,b3,e5,da)},
	{::hx::fsBool,(int)offsetof(DefaultStage_obj,isPixel),HX_("isPixel",3c,6a,29,5f)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *DefaultStage_obj_sStaticStorageInfo = 0;
#endif

static ::String DefaultStage_obj_sMemberFields[] = {
	HX_("halloweenBG",92,b2,88,5c),
	HX_("phillyCityLights",30,e0,12,1f),
	HX_("grpLimoDancers",70,18,93,51),
	HX_("phillyTrain",80,9b,65,bb),
	HX_("limo",1f,17,b3,47),
	HX_("upperBoppers",37,47,71,21),
	HX_("bottomBoppers",ce,2c,ba,6e),
	HX_("fastCar",d8,f2,1f,de),
	HX_("santa",8d,45,86,77),
	HX_("bgGirls",92,16,2b,41),
	HX_("trainSound",e7,b3,e5,da),
	HX_("isPixel",3c,6a,29,5f),
	HX_("destroy",fa,2c,86,24),
	::String(null()) };

::hx::Class DefaultStage_obj::__mClass;

static ::String DefaultStage_obj_sStaticFields[] = {
	HX_("setMainGameStage",f1,48,13,33),
	::String(null())
};

void DefaultStage_obj::__register()
{
	DefaultStage_obj _hx_dummy;
	DefaultStage_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("example_code.DefaultStage",a9,d5,8f,40);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &DefaultStage_obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(DefaultStage_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(DefaultStage_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< DefaultStage_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = DefaultStage_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = DefaultStage_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace example_code
