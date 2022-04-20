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
#ifndef INCLUDED_NoteAddon
#include <NoteAddon.h>
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

HX_DEFINE_STACK_FRAME(_hx_pos_3063870bc941355a_11_new,"NoteAddon","new",0x009fc800,"NoteAddon.new","AddonHandlerMain.hx",11,0xa00a22fb)
HX_LOCAL_STACK_FRAME(_hx_pos_3063870bc941355a_14_pressedByPlayer,"NoteAddon","pressedByPlayer",0xfdf218fa,"NoteAddon.pressedByPlayer","AddonHandlerMain.hx",14,0xa00a22fb)
HX_LOCAL_STACK_FRAME(_hx_pos_3063870bc941355a_18_useCustomPrefix,"NoteAddon","useCustomPrefix",0x9c655eaa,"NoteAddon.useCustomPrefix","AddonHandlerMain.hx",18,0xa00a22fb)
HX_LOCAL_STACK_FRAME(_hx_pos_3063870bc941355a_22_shouldBeIgnored,"NoteAddon","shouldBeIgnored",0x7cd1987c,"NoteAddon.shouldBeIgnored","AddonHandlerMain.hx",22,0xa00a22fb)
HX_LOCAL_STACK_FRAME(_hx_pos_3063870bc941355a_26_createSplashSprite,"NoteAddon","createSplashSprite",0x81b63248,"NoteAddon.createSplashSprite","AddonHandlerMain.hx",26,0xa00a22fb)
HX_LOCAL_STACK_FRAME(_hx_pos_3063870bc941355a_30_whenIsSpawned,"NoteAddon","whenIsSpawned",0x6f510a16,"NoteAddon.whenIsSpawned","AddonHandlerMain.hx",30,0xa00a22fb)
HX_LOCAL_STACK_FRAME(_hx_pos_3063870bc941355a_34_whenTiggerSceneActived,"NoteAddon","whenTiggerSceneActived",0xf3ca2f4e,"NoteAddon.whenTiggerSceneActived","AddonHandlerMain.hx",34,0xa00a22fb)
HX_LOCAL_STACK_FRAME(_hx_pos_3063870bc941355a_38_trailUpdate,"NoteAddon","trailUpdate",0x36403e0f,"NoteAddon.trailUpdate","AddonHandlerMain.hx",38,0xa00a22fb)
HX_LOCAL_STACK_FRAME(_hx_pos_3063870bc941355a_42_noteUpdate,"NoteAddon","noteUpdate",0xffd1cffb,"NoteAddon.noteUpdate","AddonHandlerMain.hx",42,0xa00a22fb)
HX_LOCAL_STACK_FRAME(_hx_pos_3063870bc941355a_46_allowRatingUssage,"NoteAddon","allowRatingUssage",0x6150b150,"NoteAddon.allowRatingUssage","AddonHandlerMain.hx",46,0xa00a22fb)
HX_LOCAL_STACK_FRAME(_hx_pos_3063870bc941355a_50_setNoteAlpha,"NoteAddon","setNoteAlpha",0xa9fbc66a,"NoteAddon.setNoteAlpha","AddonHandlerMain.hx",50,0xa00a22fb)
HX_LOCAL_STACK_FRAME(_hx_pos_3063870bc941355a_54_setNoteAngle,"NoteAddon","setNoteAngle",0xab4762df,"NoteAddon.setNoteAngle","AddonHandlerMain.hx",54,0xa00a22fb)
HX_LOCAL_STACK_FRAME(_hx_pos_3063870bc941355a_58_setXPosition,"NoteAddon","setXPosition",0xd0ad699f,"NoteAddon.setXPosition","AddonHandlerMain.hx",58,0xa00a22fb)
HX_LOCAL_STACK_FRAME(_hx_pos_3063870bc941355a_62_setVisibility,"NoteAddon","setVisibility",0x050fabb4,"NoteAddon.setVisibility","AddonHandlerMain.hx",62,0xa00a22fb)
HX_LOCAL_STACK_FRAME(_hx_pos_3063870bc941355a_66_getCustomNote,"NoteAddon","getCustomNote",0x93ae1419,"NoteAddon.getCustomNote","AddonHandlerMain.hx",66,0xa00a22fb)
HX_LOCAL_STACK_FRAME(_hx_pos_3063870bc941355a_70_getTrailGroup,"NoteAddon","getTrailGroup",0x14533d6f,"NoteAddon.getTrailGroup","AddonHandlerMain.hx",70,0xa00a22fb)
HX_LOCAL_STACK_FRAME(_hx_pos_3063870bc941355a_74_hasOppositeScroll,"NoteAddon","hasOppositeScroll",0x3c7098ee,"NoteAddon.hasOppositeScroll","AddonHandlerMain.hx",74,0xa00a22fb)
HX_LOCAL_STACK_FRAME(_hx_pos_3063870bc941355a_78_cantHaveHold,"NoteAddon","cantHaveHold",0xfa8c6aab,"NoteAddon.cantHaveHold","AddonHandlerMain.hx",78,0xa00a22fb)
HX_LOCAL_STACK_FRAME(_hx_pos_3063870bc941355a_82_getIndividualSpeed,"NoteAddon","getIndividualSpeed",0x81345798,"NoteAddon.getIndividualSpeed","AddonHandlerMain.hx",82,0xa00a22fb)
HX_LOCAL_STACK_FRAME(_hx_pos_3063870bc941355a_86_playerShouldntHit,"NoteAddon","playerShouldntHit",0xf3317259,"NoteAddon.playerShouldntHit","AddonHandlerMain.hx",86,0xa00a22fb)
HX_LOCAL_STACK_FRAME(_hx_pos_3063870bc941355a_90_noDefaultSplash,"NoteAddon","noDefaultSplash",0x857857a7,"NoteAddon.noDefaultSplash","AddonHandlerMain.hx",90,0xa00a22fb)
HX_LOCAL_STACK_FRAME(_hx_pos_3063870bc941355a_94_giveHealth,"NoteAddon","giveHealth",0xb48599ad,"NoteAddon.giveHealth","AddonHandlerMain.hx",94,0xa00a22fb)
HX_LOCAL_STACK_FRAME(_hx_pos_3063870bc941355a_98_getWobblePower,"NoteAddon","getWobblePower",0xa3e53d5e,"NoteAddon.getWobblePower","AddonHandlerMain.hx",98,0xa00a22fb)
HX_LOCAL_STACK_FRAME(_hx_pos_3063870bc941355a_101_set_ID,"NoteAddon","set_ID",0x1d82b7f8,"NoteAddon.set_ID","AddonHandlerMain.hx",101,0xa00a22fb)

void NoteAddon_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_3063870bc941355a_11_new)
            	}

Dynamic NoteAddon_obj::__CreateEmpty() { return new NoteAddon_obj; }

void *NoteAddon_obj::_hx_vtable = 0;

Dynamic NoteAddon_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< NoteAddon_obj > _hx_result = new NoteAddon_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool NoteAddon_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x6dae4f6a;
}

void NoteAddon_obj::pressedByPlayer( ::Note note, ::Character player, ::Character opponent, ::Character girlfriend){
            	HX_STACKFRAME(&_hx_pos_3063870bc941355a_14_pressedByPlayer)
HXDLIN(  14)		return;
            	}


HX_DEFINE_DYNAMIC_FUNC4(NoteAddon_obj,pressedByPlayer,(void))

bool NoteAddon_obj::useCustomPrefix( ::Note note){
            	HX_STACKFRAME(&_hx_pos_3063870bc941355a_18_useCustomPrefix)
HXDLIN(  18)		return false;
            	}


HX_DEFINE_DYNAMIC_FUNC1(NoteAddon_obj,useCustomPrefix,return )

bool NoteAddon_obj::shouldBeIgnored(){
            	HX_STACKFRAME(&_hx_pos_3063870bc941355a_22_shouldBeIgnored)
HXDLIN(  22)		return false;
            	}


HX_DEFINE_DYNAMIC_FUNC0(NoteAddon_obj,shouldBeIgnored,return )

void NoteAddon_obj::createSplashSprite( ::SplashSprite splash, ::Strum strumNote,::String rating){
            	HX_STACKFRAME(&_hx_pos_3063870bc941355a_26_createSplashSprite)
HXDLIN(  26)		return;
            	}


HX_DEFINE_DYNAMIC_FUNC3(NoteAddon_obj,createSplashSprite,(void))

void NoteAddon_obj::whenIsSpawned( ::Note note){
            	HX_STACKFRAME(&_hx_pos_3063870bc941355a_30_whenIsSpawned)
HXDLIN(  30)		return;
            	}


HX_DEFINE_DYNAMIC_FUNC1(NoteAddon_obj,whenIsSpawned,(void))

void NoteAddon_obj::whenTiggerSceneActived(){
            	HX_STACKFRAME(&_hx_pos_3063870bc941355a_34_whenTiggerSceneActived)
HXDLIN(  34)		return;
            	}


HX_DEFINE_DYNAMIC_FUNC0(NoteAddon_obj,whenTiggerSceneActived,(void))

void NoteAddon_obj::trailUpdate( ::Note note){
            	HX_STACKFRAME(&_hx_pos_3063870bc941355a_38_trailUpdate)
HXDLIN(  38)		return;
            	}


HX_DEFINE_DYNAMIC_FUNC1(NoteAddon_obj,trailUpdate,(void))

void NoteAddon_obj::noteUpdate( ::Note note){
            	HX_STACKFRAME(&_hx_pos_3063870bc941355a_42_noteUpdate)
HXDLIN(  42)		return;
            	}


HX_DEFINE_DYNAMIC_FUNC1(NoteAddon_obj,noteUpdate,(void))

bool NoteAddon_obj::allowRatingUssage(){
            	HX_STACKFRAME(&_hx_pos_3063870bc941355a_46_allowRatingUssage)
HXDLIN(  46)		return false;
            	}


HX_DEFINE_DYNAMIC_FUNC0(NoteAddon_obj,allowRatingUssage,return )

Float NoteAddon_obj::setNoteAlpha(Float alpha){
            	HX_STACKFRAME(&_hx_pos_3063870bc941355a_50_setNoteAlpha)
HXDLIN(  50)		return alpha;
            	}


HX_DEFINE_DYNAMIC_FUNC1(NoteAddon_obj,setNoteAlpha,return )

Float NoteAddon_obj::setNoteAngle(Float angle){
            	HX_STACKFRAME(&_hx_pos_3063870bc941355a_54_setNoteAngle)
HXDLIN(  54)		return angle;
            	}


HX_DEFINE_DYNAMIC_FUNC1(NoteAddon_obj,setNoteAngle,return )

Float NoteAddon_obj::setXPosition(Float x){
            	HX_STACKFRAME(&_hx_pos_3063870bc941355a_58_setXPosition)
HXDLIN(  58)		return x;
            	}


HX_DEFINE_DYNAMIC_FUNC1(NoteAddon_obj,setXPosition,return )

bool NoteAddon_obj::setVisibility(bool staticArrowVisible){
            	HX_STACKFRAME(&_hx_pos_3063870bc941355a_62_setVisibility)
HXDLIN(  62)		return staticArrowVisible;
            	}


HX_DEFINE_DYNAMIC_FUNC1(NoteAddon_obj,setVisibility,return )

::String NoteAddon_obj::getCustomNote(){
            	HX_STACKFRAME(&_hx_pos_3063870bc941355a_66_getCustomNote)
HXDLIN(  66)		return HX_("",00,00,00,00);
            	}


HX_DEFINE_DYNAMIC_FUNC0(NoteAddon_obj,getCustomNote,return )

 ::flixel::group::FlxTypedGroup NoteAddon_obj::getTrailGroup(){
            	HX_STACKFRAME(&_hx_pos_3063870bc941355a_70_getTrailGroup)
HXDLIN(  70)		return null();
            	}


HX_DEFINE_DYNAMIC_FUNC0(NoteAddon_obj,getTrailGroup,return )

bool NoteAddon_obj::hasOppositeScroll(){
            	HX_STACKFRAME(&_hx_pos_3063870bc941355a_74_hasOppositeScroll)
HXDLIN(  74)		return false;
            	}


HX_DEFINE_DYNAMIC_FUNC0(NoteAddon_obj,hasOppositeScroll,return )

bool NoteAddon_obj::cantHaveHold(){
            	HX_STACKFRAME(&_hx_pos_3063870bc941355a_78_cantHaveHold)
HXDLIN(  78)		return false;
            	}


HX_DEFINE_DYNAMIC_FUNC0(NoteAddon_obj,cantHaveHold,return )

Float NoteAddon_obj::getIndividualSpeed(){
            	HX_STACKFRAME(&_hx_pos_3063870bc941355a_82_getIndividualSpeed)
HXDLIN(  82)		return ( (Float)(0) );
            	}


HX_DEFINE_DYNAMIC_FUNC0(NoteAddon_obj,getIndividualSpeed,return )

bool NoteAddon_obj::playerShouldntHit(){
            	HX_STACKFRAME(&_hx_pos_3063870bc941355a_86_playerShouldntHit)
HXDLIN(  86)		return false;
            	}


HX_DEFINE_DYNAMIC_FUNC0(NoteAddon_obj,playerShouldntHit,return )

bool NoteAddon_obj::noDefaultSplash(){
            	HX_STACKFRAME(&_hx_pos_3063870bc941355a_90_noDefaultSplash)
HXDLIN(  90)		return false;
            	}


HX_DEFINE_DYNAMIC_FUNC0(NoteAddon_obj,noDefaultSplash,return )

Float NoteAddon_obj::giveHealth(){
            	HX_STACKFRAME(&_hx_pos_3063870bc941355a_94_giveHealth)
HXDLIN(  94)		return ( (Float)(0) );
            	}


HX_DEFINE_DYNAMIC_FUNC0(NoteAddon_obj,giveHealth,return )

int NoteAddon_obj::getWobblePower(){
            	HX_STACKFRAME(&_hx_pos_3063870bc941355a_98_getWobblePower)
HXDLIN(  98)		return 0;
            	}


HX_DEFINE_DYNAMIC_FUNC0(NoteAddon_obj,getWobblePower,return )

int NoteAddon_obj::set_ID(int compileID){
            	HX_STACKFRAME(&_hx_pos_3063870bc941355a_101_set_ID)
HXLINE( 102)		bool _hx_tmp;
HXDLIN( 102)		if ((::Compile_obj::tempNoteAbstracts->length > 0)) {
HXLINE( 102)			_hx_tmp = ::Compile_obj::preloadAddon;
            		}
            		else {
HXLINE( 102)			_hx_tmp = false;
            		}
HXDLIN( 102)		if (_hx_tmp) {
HXLINE( 103)			return compileID;
            		}
HXLINE( 105)		return this->ID;
            	}


HX_DEFINE_DYNAMIC_FUNC1(NoteAddon_obj,set_ID,return )


::hx::ObjectPtr< NoteAddon_obj > NoteAddon_obj::__new() {
	::hx::ObjectPtr< NoteAddon_obj > __this = new NoteAddon_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< NoteAddon_obj > NoteAddon_obj::__alloc(::hx::Ctx *_hx_ctx) {
	NoteAddon_obj *__this = (NoteAddon_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(NoteAddon_obj), false, "NoteAddon"));
	*(void **)__this = NoteAddon_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

NoteAddon_obj::NoteAddon_obj()
{
}

::hx::Val NoteAddon_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
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
		if (HX_FIELD_EQ(inName,"getCustomNote") ) { return ::hx::Val( getCustomNote_dyn() ); }
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

::hx::Val NoteAddon_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"ID") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_ID(inValue.Cast< int >()) );ID=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void NoteAddon_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("ID",db,3f,00,00));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo NoteAddon_obj_sMemberStorageInfo[] = {
	{::hx::fsInt,(int)offsetof(NoteAddon_obj,ID),HX_("ID",db,3f,00,00)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *NoteAddon_obj_sStaticStorageInfo = 0;
#endif

static ::String NoteAddon_obj_sMemberFields[] = {
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
	HX_("getCustomNote",79,54,24,03),
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

::hx::Class NoteAddon_obj::__mClass;

void NoteAddon_obj::__register()
{
	NoteAddon_obj _hx_dummy;
	NoteAddon_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("NoteAddon",0e,08,a4,fb);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(NoteAddon_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< NoteAddon_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = NoteAddon_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = NoteAddon_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

