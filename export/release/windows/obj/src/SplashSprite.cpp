#include <hxcpp.h>

#ifndef INCLUDED_HelperStates
#include <HelperStates.h>
#endif
#ifndef INCLUDED_MusicBeatState
#include <MusicBeatState.h>
#endif
#ifndef INCLUDED_Note
#include <Note.h>
#endif
#ifndef INCLUDED_Paths
#include <Paths.h>
#endif
#ifndef INCLUDED_PlayState
#include <PlayState.h>
#endif
#ifndef INCLUDED_SplashSprite
#include <SplashSprite.h>
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
#ifndef INCLUDED_flixel_util_IFlxDestroyable
#include <flixel/util/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_haxe_Exception
#include <haxe/Exception.h>
#endif
#ifndef INCLUDED_lime_utils_Assets
#include <lime/utils/Assets.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_68e839f358d32a77_6_new,"SplashSprite","new",0x053d2bde,"SplashSprite.new","SplashSprite.hx",6,0xca117952)
HX_LOCAL_STACK_FRAME(_hx_pos_68e839f358d32a77_17_loadAnims,"SplashSprite","loadAnims",0xf08b233a,"SplashSprite.loadAnims","SplashSprite.hx",17,0xca117952)
HX_LOCAL_STACK_FRAME(_hx_pos_68e839f358d32a77_29_defaultStrumAnim,"SplashSprite","defaultStrumAnim",0x75f71cbb,"SplashSprite.defaultStrumAnim","SplashSprite.hx",29,0xca117952)
HX_LOCAL_STACK_FRAME(_hx_pos_68e839f358d32a77_43_set_texture,"SplashSprite","set_texture",0x6856397c,"SplashSprite.set_texture","SplashSprite.hx",43,0xca117952)

void SplashSprite_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_68e839f358d32a77_6_new)
HXLINE(  11)		this->prevTexture = HX_("",00,00,00,00);
HXLINE(   7)		this->texture = HX_("",00,00,00,00);
HXLINE(  14)		super::__construct(0,0,null());
            	}

Dynamic SplashSprite_obj::__CreateEmpty() { return new SplashSprite_obj; }

void *SplashSprite_obj::_hx_vtable = 0;

Dynamic SplashSprite_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< SplashSprite_obj > _hx_result = new SplashSprite_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool SplashSprite_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x36aff7ac) {
		if (inClassId<=(int)0x2c01639b) {
			return inClassId==(int)0x00000001 || inClassId==(int)0x2c01639b;
		} else {
			return inClassId==(int)0x36aff7ac;
		}
	} else {
		return inClassId==(int)0x7ccf8994 || inClassId==(int)0x7dab0655;
	}
}

void SplashSprite_obj::loadAnims(::String txtr){
            	HX_STACKFRAME(&_hx_pos_68e839f358d32a77_17_loadAnims)
HXLINE(  18)		this->animation->destroyAnimations();
HXLINE(  19)		 ::flixel::graphics::frames::FlxAtlasFrames _hx_tmp;
HXDLIN(  19)		if (::lime::utils::Assets_obj::exists(::Paths_obj::image((HX_("notes/",ce,dc,b5,31) + txtr),null()),null())) {
HXLINE(  19)			if (::hx::IsNotNull( ::Paths_obj::ifImageCached(txtr) )) {
HXLINE(  19)				::String _hx_tmp1 = ::Paths_obj::image((HX_("notes/",ce,dc,b5,31) + txtr),null());
HXDLIN(  19)				::String library = null();
HXDLIN(  19)				_hx_tmp = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSparrow(_hx_tmp1,::Paths_obj::getPath(((HX_("images/notes/",85,60,c0,8b) + txtr) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library));
            			}
            			else {
HXLINE(  19)				::String _hx_tmp1 = ::Paths_obj::image((HX_("notes/",ce,dc,b5,31) + txtr),null());
HXDLIN(  19)				::String library = null();
HXDLIN(  19)				_hx_tmp = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSparrow(_hx_tmp1,::Paths_obj::getPath(((HX_("images/notes/",85,60,c0,8b) + txtr) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library));
            			}
            		}
            		else {
HXLINE(  19)			::String library = null();
HXDLIN(  19)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate asset - ",17,30,f9,e8) + ::Paths_obj::getPath(((HX_("images/",77,50,74,c1) + txtr) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library))));
            		}
HXDLIN(  19)		this->set_frames(_hx_tmp);
HXLINE(  21)		this->setGraphicSize(::Std_obj::_hx_int((::Note_obj::swagWidth * ( (Float)(4) ))),null());
HXLINE(  22)		this->updateHitbox();
HXLINE(  24)		if ((txtr == HX_("regular/splash",fa,3f,30,77))) {
HXLINE(  25)			this->defaultStrumAnim();
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(SplashSprite_obj,loadAnims,(void))

void SplashSprite_obj::defaultStrumAnim(){
            	HX_STACKFRAME(&_hx_pos_68e839f358d32a77_29_defaultStrumAnim)
HXDLIN(  29)		if (( (bool)(::PlayState_obj::SONG->__Field(HX_("fifthKey",e8,b7,40,b0),::hx::paccDynamic)) )) {
HXLINE(  30)			this->animation->addByPrefix(HX_("sploosh0",4c,e1,c8,44),HX_("left splash",60,70,89,24),24,false,null(),null());
HXLINE(  31)			this->animation->addByPrefix(HX_("sploosh1",4d,e1,c8,44),HX_("down splash",65,11,58,4b),24,false,null(),null());
HXLINE(  32)			this->animation->addByPrefix(HX_("sploosh2",4e,e1,c8,44),HX_("reverse splash",a5,68,e7,42),24,false,null(),null());
HXLINE(  33)			this->animation->addByPrefix(HX_("sploosh3",4f,e1,c8,44),HX_("up splash",8c,44,ae,60),24,false,null(),null());
HXLINE(  34)			this->animation->addByPrefix(HX_("sploosh4",50,e1,c8,44),HX_("right splash",2b,c1,a4,0f),24,false,null(),null());
            		}
            		else {
HXLINE(  36)			this->animation->addByPrefix(HX_("sploosh0",4c,e1,c8,44),HX_("left splash",60,70,89,24),24,false,null(),null());
HXLINE(  37)			this->animation->addByPrefix(HX_("sploosh1",4d,e1,c8,44),HX_("down splash",65,11,58,4b),24,false,null(),null());
HXLINE(  38)			this->animation->addByPrefix(HX_("sploosh2",4e,e1,c8,44),HX_("up splash",8c,44,ae,60),24,false,null(),null());
HXLINE(  39)			this->animation->addByPrefix(HX_("sploosh3",4f,e1,c8,44),HX_("right splash",2b,c1,a4,0f),24,false,null(),null());
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC0(SplashSprite_obj,defaultStrumAnim,(void))

::String SplashSprite_obj::set_texture(::String value){
            	HX_STACKFRAME(&_hx_pos_68e839f358d32a77_43_set_texture)
HXLINE(  44)		if ((value != this->prevTexture)) {
HXLINE(  45)			this->prevTexture = value;
HXLINE(  46)			this->loadAnims(value);
            		}
HXLINE(  49)		this->texture = value;
HXLINE(  50)		return value;
            	}


HX_DEFINE_DYNAMIC_FUNC1(SplashSprite_obj,set_texture,return )


::hx::ObjectPtr< SplashSprite_obj > SplashSprite_obj::__new() {
	::hx::ObjectPtr< SplashSprite_obj > __this = new SplashSprite_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< SplashSprite_obj > SplashSprite_obj::__alloc(::hx::Ctx *_hx_ctx) {
	SplashSprite_obj *__this = (SplashSprite_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(SplashSprite_obj), true, "SplashSprite"));
	*(void **)__this = SplashSprite_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

SplashSprite_obj::SplashSprite_obj()
{
}

void SplashSprite_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SplashSprite);
	HX_MARK_MEMBER_NAME(texture,"texture");
	HX_MARK_MEMBER_NAME(buildAnim,"buildAnim");
	HX_MARK_MEMBER_NAME(prevTexture,"prevTexture");
	 ::flixel::FlxSprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void SplashSprite_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(texture,"texture");
	HX_VISIT_MEMBER_NAME(buildAnim,"buildAnim");
	HX_VISIT_MEMBER_NAME(prevTexture,"prevTexture");
	 ::flixel::FlxSprite_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val SplashSprite_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"texture") ) { return ::hx::Val( texture ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"buildAnim") ) { return ::hx::Val( buildAnim ); }
		if (HX_FIELD_EQ(inName,"loadAnims") ) { return ::hx::Val( loadAnims_dyn() ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"prevTexture") ) { return ::hx::Val( prevTexture ); }
		if (HX_FIELD_EQ(inName,"set_texture") ) { return ::hx::Val( set_texture_dyn() ); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"defaultStrumAnim") ) { return ::hx::Val( defaultStrumAnim_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val SplashSprite_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"texture") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_texture(inValue.Cast< ::String >()) );texture=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"buildAnim") ) { buildAnim=inValue.Cast<  ::Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"prevTexture") ) { prevTexture=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SplashSprite_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("texture",db,c8,e0,9e));
	outFields->push(HX_("prevTexture",28,46,29,05));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo SplashSprite_obj_sMemberStorageInfo[] = {
	{::hx::fsString,(int)offsetof(SplashSprite_obj,texture),HX_("texture",db,c8,e0,9e)},
	{::hx::fsObject /*  ::Dynamic */ ,(int)offsetof(SplashSprite_obj,buildAnim),HX_("buildAnim",5f,bc,ad,e0)},
	{::hx::fsString,(int)offsetof(SplashSprite_obj,prevTexture),HX_("prevTexture",28,46,29,05)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *SplashSprite_obj_sStaticStorageInfo = 0;
#endif

static ::String SplashSprite_obj_sMemberFields[] = {
	HX_("texture",db,c8,e0,9e),
	HX_("buildAnim",5f,bc,ad,e0),
	HX_("prevTexture",28,46,29,05),
	HX_("loadAnims",3c,15,1b,3e),
	HX_("defaultStrumAnim",f9,4e,8e,aa),
	HX_("set_texture",fe,2f,48,2f),
	::String(null()) };

::hx::Class SplashSprite_obj::__mClass;

void SplashSprite_obj::__register()
{
	SplashSprite_obj _hx_dummy;
	SplashSprite_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("SplashSprite",ec,a4,ce,4d);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(SplashSprite_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< SplashSprite_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = SplashSprite_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = SplashSprite_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

