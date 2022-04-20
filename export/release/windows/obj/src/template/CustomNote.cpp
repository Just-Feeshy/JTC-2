#include <hxcpp.h>

#ifndef INCLUDED_Character
#include <Character.h>
#endif
#ifndef INCLUDED_Compile
#include <Compile.h>
#endif
#ifndef INCLUDED_Note
#include <Note.h>
#endif
#ifndef INCLUDED_SplashSprite
#include <SplashSprite.h>
#endif
#ifndef INCLUDED_Strum
#include <Strum.h>
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
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxDestroyable
#include <flixel/util/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_template_CustomNote
#include <template/CustomNote.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_eba961b4f0a3b16a_9_new,"template.CustomNote","new",0xd6f52889,"template.CustomNote.new","template/CustomNote.hx",9,0xc1584e66)
HX_LOCAL_STACK_FRAME(_hx_pos_eba961b4f0a3b16a_12_pressedByPlayer,"template.CustomNote","pressedByPlayer",0x02daa303,"template.CustomNote.pressedByPlayer","template/CustomNote.hx",12,0xc1584e66)
HX_LOCAL_STACK_FRAME(_hx_pos_eba961b4f0a3b16a_16_useCustomPrefix,"template.CustomNote","useCustomPrefix",0xa14de8b3,"template.CustomNote.useCustomPrefix","template/CustomNote.hx",16,0xc1584e66)
HX_LOCAL_STACK_FRAME(_hx_pos_eba961b4f0a3b16a_20_shouldBeIgnored,"template.CustomNote","shouldBeIgnored",0x81ba2285,"template.CustomNote.shouldBeIgnored","template/CustomNote.hx",20,0xc1584e66)
HX_LOCAL_STACK_FRAME(_hx_pos_eba961b4f0a3b16a_24_createSplashSprite,"template.CustomNote","createSplashSprite",0xbb32d3df,"template.CustomNote.createSplashSprite","template/CustomNote.hx",24,0xc1584e66)
HX_LOCAL_STACK_FRAME(_hx_pos_eba961b4f0a3b16a_28_whenIsSpawned,"template.CustomNote","whenIsSpawned",0xc125cfdf,"template.CustomNote.whenIsSpawned","template/CustomNote.hx",28,0xc1584e66)
HX_LOCAL_STACK_FRAME(_hx_pos_eba961b4f0a3b16a_32_whenTiggerSceneActived,"template.CustomNote","whenTiggerSceneActived",0x102ce865,"template.CustomNote.whenTiggerSceneActived","template/CustomNote.hx",32,0xc1584e66)
HX_LOCAL_STACK_FRAME(_hx_pos_eba961b4f0a3b16a_36_trailUpdate,"template.CustomNote","trailUpdate",0x5426cf98,"template.CustomNote.trailUpdate","template/CustomNote.hx",36,0xc1584e66)
HX_LOCAL_STACK_FRAME(_hx_pos_eba961b4f0a3b16a_40_noteUpdate,"template.CustomNote","noteUpdate",0x54e78292,"template.CustomNote.noteUpdate","template/CustomNote.hx",40,0xc1584e66)
HX_LOCAL_STACK_FRAME(_hx_pos_eba961b4f0a3b16a_44_allowRatingUssage,"template.CustomNote","allowRatingUssage",0xd8f68f99,"template.CustomNote.allowRatingUssage","template/CustomNote.hx",44,0xc1584e66)
HX_LOCAL_STACK_FRAME(_hx_pos_eba961b4f0a3b16a_48_setNoteAlpha,"template.CustomNote","setNoteAlpha",0xb5d48cc1,"template.CustomNote.setNoteAlpha","template/CustomNote.hx",48,0xc1584e66)
HX_LOCAL_STACK_FRAME(_hx_pos_eba961b4f0a3b16a_52_setNoteAngle,"template.CustomNote","setNoteAngle",0xb7202936,"template.CustomNote.setNoteAngle","template/CustomNote.hx",52,0xc1584e66)
HX_LOCAL_STACK_FRAME(_hx_pos_eba961b4f0a3b16a_56_setXPosition,"template.CustomNote","setXPosition",0xdc862ff6,"template.CustomNote.setXPosition","template/CustomNote.hx",56,0xc1584e66)
HX_LOCAL_STACK_FRAME(_hx_pos_eba961b4f0a3b16a_60_setVisibility,"template.CustomNote","setVisibility",0x56e4717d,"template.CustomNote.setVisibility","template/CustomNote.hx",60,0xc1584e66)
HX_LOCAL_STACK_FRAME(_hx_pos_eba961b4f0a3b16a_64_getTrailGroup,"template.CustomNote","getTrailGroup",0x66280338,"template.CustomNote.getTrailGroup","template/CustomNote.hx",64,0xc1584e66)
HX_LOCAL_STACK_FRAME(_hx_pos_eba961b4f0a3b16a_68_hasOppositeScroll,"template.CustomNote","hasOppositeScroll",0xb4167737,"template.CustomNote.hasOppositeScroll","template/CustomNote.hx",68,0xc1584e66)
HX_LOCAL_STACK_FRAME(_hx_pos_eba961b4f0a3b16a_72_cantHaveHold,"template.CustomNote","cantHaveHold",0x06653102,"template.CustomNote.cantHaveHold","template/CustomNote.hx",72,0xc1584e66)
HX_LOCAL_STACK_FRAME(_hx_pos_eba961b4f0a3b16a_76_getIndividualSpeed,"template.CustomNote","getIndividualSpeed",0xbab0f92f,"template.CustomNote.getIndividualSpeed","template/CustomNote.hx",76,0xc1584e66)
HX_LOCAL_STACK_FRAME(_hx_pos_eba961b4f0a3b16a_80_playerShouldntHit,"template.CustomNote","playerShouldntHit",0x6ad750a2,"template.CustomNote.playerShouldntHit","template/CustomNote.hx",80,0xc1584e66)
HX_LOCAL_STACK_FRAME(_hx_pos_eba961b4f0a3b16a_84_noDefaultSplash,"template.CustomNote","noDefaultSplash",0x8a60e1b0,"template.CustomNote.noDefaultSplash","template/CustomNote.hx",84,0xc1584e66)
HX_LOCAL_STACK_FRAME(_hx_pos_eba961b4f0a3b16a_88_giveHealth,"template.CustomNote","giveHealth",0x099b4c44,"template.CustomNote.giveHealth","template/CustomNote.hx",88,0xc1584e66)
HX_LOCAL_STACK_FRAME(_hx_pos_eba961b4f0a3b16a_92_getWobblePower,"template.CustomNote","getWobblePower",0xec3d8775,"template.CustomNote.getWobblePower","template/CustomNote.hx",92,0xc1584e66)
HX_LOCAL_STACK_FRAME(_hx_pos_eba961b4f0a3b16a_95_set_ID,"template.CustomNote","set_ID",0xf957930f,"template.CustomNote.set_ID","template/CustomNote.hx",95,0xc1584e66)
namespace _hx_template{

void CustomNote_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_eba961b4f0a3b16a_9_new)
            	}

bool CustomNote_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x29d8891d;
}

void CustomNote_obj::pressedByPlayer( ::Note note, ::Character player, ::Character opponent, ::Character girlfriend){
            	HX_STACKFRAME(&_hx_pos_eba961b4f0a3b16a_12_pressedByPlayer)
HXDLIN(  12)		return;
            	}


HX_DEFINE_DYNAMIC_FUNC4(CustomNote_obj,pressedByPlayer,(void))

bool CustomNote_obj::useCustomPrefix( ::Note note){
            	HX_STACKFRAME(&_hx_pos_eba961b4f0a3b16a_16_useCustomPrefix)
HXDLIN(  16)		return false;
            	}


HX_DEFINE_DYNAMIC_FUNC1(CustomNote_obj,useCustomPrefix,return )

bool CustomNote_obj::shouldBeIgnored(){
            	HX_STACKFRAME(&_hx_pos_eba961b4f0a3b16a_20_shouldBeIgnored)
HXDLIN(  20)		return false;
            	}


HX_DEFINE_DYNAMIC_FUNC0(CustomNote_obj,shouldBeIgnored,return )

void CustomNote_obj::createSplashSprite( ::SplashSprite splash, ::Strum strumNote,::String rating){
            	HX_STACKFRAME(&_hx_pos_eba961b4f0a3b16a_24_createSplashSprite)
HXDLIN(  24)		return;
            	}


HX_DEFINE_DYNAMIC_FUNC3(CustomNote_obj,createSplashSprite,(void))

void CustomNote_obj::whenIsSpawned( ::Note note){
            	HX_STACKFRAME(&_hx_pos_eba961b4f0a3b16a_28_whenIsSpawned)
HXDLIN(  28)		return;
            	}


HX_DEFINE_DYNAMIC_FUNC1(CustomNote_obj,whenIsSpawned,(void))

void CustomNote_obj::whenTiggerSceneActived(){
            	HX_STACKFRAME(&_hx_pos_eba961b4f0a3b16a_32_whenTiggerSceneActived)
HXDLIN(  32)		return;
            	}


HX_DEFINE_DYNAMIC_FUNC0(CustomNote_obj,whenTiggerSceneActived,(void))

void CustomNote_obj::trailUpdate( ::Note note){
            	HX_STACKFRAME(&_hx_pos_eba961b4f0a3b16a_36_trailUpdate)
HXDLIN(  36)		return;
            	}


HX_DEFINE_DYNAMIC_FUNC1(CustomNote_obj,trailUpdate,(void))

void CustomNote_obj::noteUpdate( ::Note note){
            	HX_STACKFRAME(&_hx_pos_eba961b4f0a3b16a_40_noteUpdate)
HXDLIN(  40)		return;
            	}


HX_DEFINE_DYNAMIC_FUNC1(CustomNote_obj,noteUpdate,(void))

bool CustomNote_obj::allowRatingUssage(){
            	HX_STACKFRAME(&_hx_pos_eba961b4f0a3b16a_44_allowRatingUssage)
HXDLIN(  44)		return false;
            	}


HX_DEFINE_DYNAMIC_FUNC0(CustomNote_obj,allowRatingUssage,return )

Float CustomNote_obj::setNoteAlpha(Float alpha){
            	HX_STACKFRAME(&_hx_pos_eba961b4f0a3b16a_48_setNoteAlpha)
HXDLIN(  48)		return alpha;
            	}


HX_DEFINE_DYNAMIC_FUNC1(CustomNote_obj,setNoteAlpha,return )

Float CustomNote_obj::setNoteAngle(Float angle){
            	HX_STACKFRAME(&_hx_pos_eba961b4f0a3b16a_52_setNoteAngle)
HXDLIN(  52)		return angle;
            	}


HX_DEFINE_DYNAMIC_FUNC1(CustomNote_obj,setNoteAngle,return )

Float CustomNote_obj::setXPosition(Float x){
            	HX_STACKFRAME(&_hx_pos_eba961b4f0a3b16a_56_setXPosition)
HXDLIN(  56)		return x;
            	}


HX_DEFINE_DYNAMIC_FUNC1(CustomNote_obj,setXPosition,return )

bool CustomNote_obj::setVisibility(bool staticArrowVisible){
            	HX_STACKFRAME(&_hx_pos_eba961b4f0a3b16a_60_setVisibility)
HXDLIN(  60)		return staticArrowVisible;
            	}


HX_DEFINE_DYNAMIC_FUNC1(CustomNote_obj,setVisibility,return )

 ::flixel::group::FlxTypedGroup CustomNote_obj::getTrailGroup(){
            	HX_STACKFRAME(&_hx_pos_eba961b4f0a3b16a_64_getTrailGroup)
HXDLIN(  64)		return null();
            	}


HX_DEFINE_DYNAMIC_FUNC0(CustomNote_obj,getTrailGroup,return )

bool CustomNote_obj::hasOppositeScroll(){
            	HX_STACKFRAME(&_hx_pos_eba961b4f0a3b16a_68_hasOppositeScroll)
HXDLIN(  68)		return false;
            	}


HX_DEFINE_DYNAMIC_FUNC0(CustomNote_obj,hasOppositeScroll,return )

bool CustomNote_obj::cantHaveHold(){
            	HX_STACKFRAME(&_hx_pos_eba961b4f0a3b16a_72_cantHaveHold)
HXDLIN(  72)		return false;
            	}


HX_DEFINE_DYNAMIC_FUNC0(CustomNote_obj,cantHaveHold,return )

Float CustomNote_obj::getIndividualSpeed(){
            	HX_STACKFRAME(&_hx_pos_eba961b4f0a3b16a_76_getIndividualSpeed)
HXDLIN(  76)		return ( (Float)(0) );
            	}


HX_DEFINE_DYNAMIC_FUNC0(CustomNote_obj,getIndividualSpeed,return )

bool CustomNote_obj::playerShouldntHit(){
            	HX_STACKFRAME(&_hx_pos_eba961b4f0a3b16a_80_playerShouldntHit)
HXDLIN(  80)		return false;
            	}


HX_DEFINE_DYNAMIC_FUNC0(CustomNote_obj,playerShouldntHit,return )

bool CustomNote_obj::noDefaultSplash(){
            	HX_STACKFRAME(&_hx_pos_eba961b4f0a3b16a_84_noDefaultSplash)
HXDLIN(  84)		return false;
            	}


HX_DEFINE_DYNAMIC_FUNC0(CustomNote_obj,noDefaultSplash,return )

Float CustomNote_obj::giveHealth(){
            	HX_STACKFRAME(&_hx_pos_eba961b4f0a3b16a_88_giveHealth)
HXDLIN(  88)		return ( (Float)(0) );
            	}


HX_DEFINE_DYNAMIC_FUNC0(CustomNote_obj,giveHealth,return )

int CustomNote_obj::getWobblePower(){
            	HX_STACKFRAME(&_hx_pos_eba961b4f0a3b16a_92_getWobblePower)
HXDLIN(  92)		return 0;
            	}


HX_DEFINE_DYNAMIC_FUNC0(CustomNote_obj,getWobblePower,return )

int CustomNote_obj::set_ID(int compileID){
            	HX_STACKFRAME(&_hx_pos_eba961b4f0a3b16a_95_set_ID)
HXLINE(  96)		bool _hx_tmp;
HXDLIN(  96)		if ((::Compile_obj::tempNoteAbstracts->length > 0)) {
HXLINE(  96)			_hx_tmp = ::Compile_obj::preloadAddon;
            		}
            		else {
HXLINE(  96)			_hx_tmp = false;
            		}
HXDLIN(  96)		if (_hx_tmp) {
HXLINE(  97)			return compileID;
            		}
HXLINE(  99)		return this->ID;
            	}


HX_DEFINE_DYNAMIC_FUNC1(CustomNote_obj,set_ID,return )


CustomNote_obj::CustomNote_obj()
{
}

::hx::Val CustomNote_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"ID") ) { return ::hx::Val( ID ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"set_ID") ) { return ::hx::Val( set_ID_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"noteUpdate") ) { return ::hx::Val( noteUpdate_dyn() ); }
		if (HX_FIELD_EQ(inName,"giveHealth") ) { return ::hx::Val( giveHealth_dyn() ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"trailUpdate") ) { return ::hx::Val( trailUpdate_dyn() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"setNoteAlpha") ) { return ::hx::Val( setNoteAlpha_dyn() ); }
		if (HX_FIELD_EQ(inName,"setNoteAngle") ) { return ::hx::Val( setNoteAngle_dyn() ); }
		if (HX_FIELD_EQ(inName,"setXPosition") ) { return ::hx::Val( setXPosition_dyn() ); }
		if (HX_FIELD_EQ(inName,"cantHaveHold") ) { return ::hx::Val( cantHaveHold_dyn() ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"whenIsSpawned") ) { return ::hx::Val( whenIsSpawned_dyn() ); }
		if (HX_FIELD_EQ(inName,"setVisibility") ) { return ::hx::Val( setVisibility_dyn() ); }
		if (HX_FIELD_EQ(inName,"getTrailGroup") ) { return ::hx::Val( getTrailGroup_dyn() ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getWobblePower") ) { return ::hx::Val( getWobblePower_dyn() ); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"pressedByPlayer") ) { return ::hx::Val( pressedByPlayer_dyn() ); }
		if (HX_FIELD_EQ(inName,"useCustomPrefix") ) { return ::hx::Val( useCustomPrefix_dyn() ); }
		if (HX_FIELD_EQ(inName,"shouldBeIgnored") ) { return ::hx::Val( shouldBeIgnored_dyn() ); }
		if (HX_FIELD_EQ(inName,"noDefaultSplash") ) { return ::hx::Val( noDefaultSplash_dyn() ); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"allowRatingUssage") ) { return ::hx::Val( allowRatingUssage_dyn() ); }
		if (HX_FIELD_EQ(inName,"hasOppositeScroll") ) { return ::hx::Val( hasOppositeScroll_dyn() ); }
		if (HX_FIELD_EQ(inName,"playerShouldntHit") ) { return ::hx::Val( playerShouldntHit_dyn() ); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"createSplashSprite") ) { return ::hx::Val( createSplashSprite_dyn() ); }
		if (HX_FIELD_EQ(inName,"getIndividualSpeed") ) { return ::hx::Val( getIndividualSpeed_dyn() ); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"whenTiggerSceneActived") ) { return ::hx::Val( whenTiggerSceneActived_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val CustomNote_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"ID") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_ID(inValue.Cast< int >()) );ID=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CustomNote_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("ID",db,3f,00,00));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo CustomNote_obj_sMemberStorageInfo[] = {
	{::hx::fsInt,(int)offsetof(CustomNote_obj,ID),HX_("ID",db,3f,00,00)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *CustomNote_obj_sStaticStorageInfo = 0;
#endif

static ::String CustomNote_obj_sMemberFields[] = {
	HX_("ID",db,3f,00,00),
	HX_("pressedByPlayer",5a,31,c1,e7),
	HX_("useCustomPrefix",0a,77,34,86),
	HX_("shouldBeIgnored",dc,b0,a0,66),
	HX_("createSplashSprite",e8,95,da,7f),
	HX_("whenIsSpawned",76,4a,c7,de),
	HX_("whenTiggerSceneActived",ee,e2,78,9f),
	HX_("trailUpdate",6f,a6,c3,af),
	HX_("noteUpdate",9b,93,19,25),
	HX_("allowRatingUssage",b0,a1,5e,af),
	HX_("setNoteAlpha",0a,b2,73,83),
	HX_("setNoteAngle",7f,4e,bf,84),
	HX_("setXPosition",3f,55,25,aa),
	HX_("setVisibility",14,ec,85,74),
	HX_("getTrailGroup",cf,7d,c9,83),
	HX_("hasOppositeScroll",4e,89,7e,8a),
	HX_("cantHaveHold",4b,56,04,d4),
	HX_("getIndividualSpeed",38,bb,58,7f),
	HX_("playerShouldntHit",b9,62,3f,41),
	HX_("noDefaultSplash",07,70,47,6f),
	HX_("giveHealth",4d,5d,cd,d9),
	HX_("getWobblePower",fe,50,e7,bb),
	HX_("set_ID",98,2b,78,6f),
	::String(null()) };

::hx::Class CustomNote_obj::__mClass;

void CustomNote_obj::__register()
{
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("template.CustomNote",17,30,2a,61);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(CustomNote_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TIsInterface< (int)0x6f46765d >;
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace template
