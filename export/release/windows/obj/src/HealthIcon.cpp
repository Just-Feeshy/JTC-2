#include <hxcpp.h>

#ifndef INCLUDED_95f339a1d026d52c
#define INCLUDED_95f339a1d026d52c
#include "hxMath.h"
#endif
#ifndef INCLUDED_HealthIcon
#include <HealthIcon.h>
#endif
#ifndef INCLUDED_JsonParser_18
#include <JsonParser_18.h>
#endif
#ifndef INCLUDED_Paths
#include <Paths.h>
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
#ifndef INCLUDED_flixel_animation_FlxAnimationController
#include <flixel/animation/FlxAnimationController.h>
#endif
#ifndef INCLUDED_flixel_math_FlxPoint
#include <flixel/math/FlxPoint.h>
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
#ifndef INCLUDED_json2object_Error
#include <json2object/Error.h>
#endif
#ifndef INCLUDED_json2object_PositionUtils
#include <json2object/PositionUtils.h>
#endif
#ifndef INCLUDED_json2object_reader_BaseParser
#include <json2object/reader/BaseParser.h>
#endif
#ifndef INCLUDED_sys_FileSystem
#include <sys/FileSystem.h>
#endif
#ifndef INCLUDED_sys_io_File
#include <sys/io/File.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_eb8a54c9c53eb75f_13_new,"HealthIcon","new",0x9b7badc7,"HealthIcon.new","HealthIcon.hx",13,0xf7836789)
HX_LOCAL_STACK_FRAME(_hx_pos_eb8a54c9c53eb75f_53_loadAllAnims,"HealthIcon","loadAllAnims",0xc49b3260,"HealthIcon.loadAllAnims","HealthIcon.hx",53,0xf7836789)
HX_LOCAL_STACK_FRAME(_hx_pos_eb8a54c9c53eb75f_60_createAnim,"HealthIcon","createAnim",0x0a88f4a6,"HealthIcon.createAnim","HealthIcon.hx",60,0xf7836789)
HX_LOCAL_STACK_FRAME(_hx_pos_eb8a54c9c53eb75f_66_loadJSON,"HealthIcon","loadJSON",0x5be8dc87,"HealthIcon.loadJSON","HealthIcon.hx",66,0xf7836789)
HX_LOCAL_STACK_FRAME(_hx_pos_eb8a54c9c53eb75f_73_update,"HealthIcon","update",0x767ac302,"HealthIcon.update","HealthIcon.hx",73,0xf7836789)

void HealthIcon_obj::__construct(::String __o__hx_char,::hx::Null< bool >  __o_isPlayer, ::Dynamic __o_storyBPM, ::Dynamic __o_loadAnims){
            		::String _hx_char = __o__hx_char;
            		if (::hx::IsNull(__o__hx_char)) _hx_char = HX_("bf",c4,55,00,00);
            		bool isPlayer = __o_isPlayer.Default(false);
            		 ::Dynamic storyBPM = __o_storyBPM;
            		if (::hx::IsNull(__o_storyBPM)) storyBPM = 0;
            		 ::Dynamic loadAnims = __o_loadAnims;
            		if (::hx::IsNull(__o_loadAnims)) loadAnims = true;
            	HX_STACKFRAME(&_hx_pos_eb8a54c9c53eb75f_13_new)
HXLINE(  25)		this->updatePref = ((Float)1);
HXLINE(  20)		this->iconSway = ((Float)0);
HXLINE(  29)		super::__construct(null(),null(),null());
HXLINE(  31)		Float _hx_tmp;
HXDLIN(  31)		if (( (bool)(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic)) )) {
HXLINE(  31)			_hx_tmp = ( (Float)(1) );
            		}
            		else {
HXLINE(  31)			_hx_tmp = ((Float)1.5);
            		}
HXDLIN(  31)		this->updatePref = _hx_tmp;
HXLINE(  33)		this->loadGraphic(::Paths_obj::image(HX_("iconGrid",df,9a,73,71),null()),true,150,150,null(),null());
HXLINE(  35)		if (( (bool)(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic)) )) {
HXLINE(  36)			this->set_antialiasing(true);
            		}
HXLINE(  38)		this->iconCharacters = ::Array_obj< ::String >::__new();
HXLINE(  40)		if (( (bool)(loadAnims) )) {
HXLINE(  41)			this->loadAllAnims(isPlayer);
            		}
HXLINE(  43)		this->animation->play(_hx_char,null(),null(),null());
HXLINE(  44)		this->scrollFactor->set(null(),null());
HXLINE(  46)		if (::hx::IsLessEq( storyBPM,0 )) {
HXLINE(  47)			 ::HealthIcon _hx_tmp = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN(  47)			_hx_tmp->updatePref = (_hx_tmp->updatePref + 1);
            		}
HXLINE(  49)		this->BPM = ( (int)(storyBPM) );
            	}

Dynamic HealthIcon_obj::__CreateEmpty() { return new HealthIcon_obj; }

void *HealthIcon_obj::_hx_vtable = 0;

Dynamic HealthIcon_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< HealthIcon_obj > _hx_result = new HealthIcon_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return _hx_result;
}

bool HealthIcon_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x2c01639b) {
		if (inClassId<=(int)0x10bce115) {
			return inClassId==(int)0x00000001 || inClassId==(int)0x10bce115;
		} else {
			return inClassId==(int)0x2c01639b;
		}
	} else {
		return inClassId==(int)0x7ccf8994 || inClassId==(int)0x7dab0655;
	}
}

void HealthIcon_obj::loadAllAnims(bool isPlayer){
            	HX_STACKFRAME(&_hx_pos_eb8a54c9c53eb75f_53_loadAllAnims)
HXDLIN(  53)		int _g = 0;
HXDLIN(  53)		int _g1 = ::sys::FileSystem_obj::readDirectory(HX_("config/characters",17,86,f6,a5))->length;
HXDLIN(  53)		while((_g < _g1)){
HXDLIN(  53)			_g = (_g + 1);
HXDLIN(  53)			int i = (_g - 1);
HXLINE(  54)			 ::Dynamic funnyJson = this->loadJSON((HX_("characters/",45,3c,bf,be) + ::sys::FileSystem_obj::readDirectory(HX_("config/characters",17,86,f6,a5))->__get(i).split(HX_(".",2e,00,00,00))->__get(0)));
HXLINE(  55)			::String _hx_tmp = ::sys::FileSystem_obj::readDirectory(HX_("config/characters",17,86,f6,a5))->__get(i).split(HX_(".",2e,00,00,00))->__get(0);
HXDLIN(  55)			this->createAnim(_hx_tmp,( (::Array< int >)(funnyJson->__Field(HX_("icon",79,e7,b2,45),::hx::paccDynamic)) ),isPlayer);
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(HealthIcon_obj,loadAllAnims,(void))

void HealthIcon_obj::createAnim(::String character,::Array< int > iconAnimInfo,::hx::Null< bool >  __o_isPlayer){
            		bool isPlayer = __o_isPlayer.Default(false);
            	HX_STACKFRAME(&_hx_pos_eb8a54c9c53eb75f_60_createAnim)
HXDLIN(  60)		if (!(this->iconCharacters->contains(character))) {
HXLINE(  61)			this->iconCharacters->push(character);
HXLINE(  62)			this->animation->add(character,iconAnimInfo,0,false,isPlayer,null());
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC3(HealthIcon_obj,createAnim,(void))

 ::Dynamic HealthIcon_obj::loadJSON(::String character){
            	HX_GC_STACKFRAME(&_hx_pos_eb8a54c9c53eb75f_66_loadJSON)
HXLINE(  67)		 ::JsonParser_18 parser =  ::JsonParser_18_obj::__alloc( HX_CTX ,null(),null(),null());
HXLINE(  69)		::String _hx_tmp = ::sys::io::File_obj::getContent(((HX_("config/",2d,93,39,10) + character) + HX_(".json",56,f1,d6,c2)));
HXDLIN(  69)		return parser->fromJson(_hx_tmp,((HX_("",00,00,00,00) + character.split(HX_("/",2f,00,00,00))->__get(1)) + HX_(".json",56,f1,d6,c2)));
            	}


HX_DEFINE_DYNAMIC_FUNC1(HealthIcon_obj,loadJSON,return )

void HealthIcon_obj::update(Float elapsed){
            	HX_STACKFRAME(&_hx_pos_eb8a54c9c53eb75f_73_update)
HXLINE(  74)		this->super::update((elapsed / this->updatePref));
HXLINE(  76)		if (::hx::IsNotNull( this->sprTracker )) {
HXLINE(  77)			Float _hx_tmp = this->sprTracker->x;
HXDLIN(  77)			Float _hx_tmp1 = ((_hx_tmp + this->sprTracker->get_width()) + 10);
HXDLIN(  77)			this->setPosition(_hx_tmp1,(this->sprTracker->y - ( (Float)(30) )));
            		}
HXLINE(  79)		if ((this->BPM >= 1)) {
HXLINE(  80)			Float currentSway = (this->iconSway * (( (Float)(this->BPM) ) / ( (Float)(120) )));
HXLINE(  81)			 ::HealthIcon _hx_tmp = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN(  81)			_hx_tmp->iconSway = (_hx_tmp->iconSway + ((Float)0.004));
HXLINE(  83)			this->set_angle((( (Float)(15) ) * ::Math_obj::sin((currentSway * ::Math_obj::PI))));
            		}
            	}



::hx::ObjectPtr< HealthIcon_obj > HealthIcon_obj::__new(::String __o__hx_char,::hx::Null< bool >  __o_isPlayer, ::Dynamic __o_storyBPM, ::Dynamic __o_loadAnims) {
	::hx::ObjectPtr< HealthIcon_obj > __this = new HealthIcon_obj();
	__this->__construct(__o__hx_char,__o_isPlayer,__o_storyBPM,__o_loadAnims);
	return __this;
}

::hx::ObjectPtr< HealthIcon_obj > HealthIcon_obj::__alloc(::hx::Ctx *_hx_ctx,::String __o__hx_char,::hx::Null< bool >  __o_isPlayer, ::Dynamic __o_storyBPM, ::Dynamic __o_loadAnims) {
	HealthIcon_obj *__this = (HealthIcon_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(HealthIcon_obj), true, "HealthIcon"));
	*(void **)__this = HealthIcon_obj::_hx_vtable;
	__this->__construct(__o__hx_char,__o_isPlayer,__o_storyBPM,__o_loadAnims);
	return __this;
}

HealthIcon_obj::HealthIcon_obj()
{
}

void HealthIcon_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HealthIcon);
	HX_MARK_MEMBER_NAME(sprTracker,"sprTracker");
	HX_MARK_MEMBER_NAME(iconSway,"iconSway");
	HX_MARK_MEMBER_NAME(BPM,"BPM");
	HX_MARK_MEMBER_NAME(iconCharacters,"iconCharacters");
	HX_MARK_MEMBER_NAME(updatePref,"updatePref");
	 ::flixel::FlxSprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void HealthIcon_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(sprTracker,"sprTracker");
	HX_VISIT_MEMBER_NAME(iconSway,"iconSway");
	HX_VISIT_MEMBER_NAME(BPM,"BPM");
	HX_VISIT_MEMBER_NAME(iconCharacters,"iconCharacters");
	HX_VISIT_MEMBER_NAME(updatePref,"updatePref");
	 ::flixel::FlxSprite_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val HealthIcon_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"BPM") ) { return ::hx::Val( BPM ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return ::hx::Val( update_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"iconSway") ) { return ::hx::Val( iconSway ); }
		if (HX_FIELD_EQ(inName,"loadJSON") ) { return ::hx::Val( loadJSON_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"sprTracker") ) { return ::hx::Val( sprTracker ); }
		if (HX_FIELD_EQ(inName,"updatePref") ) { return ::hx::Val( updatePref ); }
		if (HX_FIELD_EQ(inName,"createAnim") ) { return ::hx::Val( createAnim_dyn() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"loadAllAnims") ) { return ::hx::Val( loadAllAnims_dyn() ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"iconCharacters") ) { return ::hx::Val( iconCharacters ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val HealthIcon_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"BPM") ) { BPM=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"iconSway") ) { iconSway=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"sprTracker") ) { sprTracker=inValue.Cast<  ::flixel::FlxSprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"updatePref") ) { updatePref=inValue.Cast< Float >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"iconCharacters") ) { iconCharacters=inValue.Cast< ::Array< ::String > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void HealthIcon_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("sprTracker",03,a3,e2,78));
	outFields->push(HX_("iconSway",b5,ee,65,79));
	outFields->push(HX_("BPM",bf,5a,32,00));
	outFields->push(HX_("iconCharacters",83,b5,99,00));
	outFields->push(HX_("updatePref",8c,a9,13,03));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo HealthIcon_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::flixel::FlxSprite */ ,(int)offsetof(HealthIcon_obj,sprTracker),HX_("sprTracker",03,a3,e2,78)},
	{::hx::fsFloat,(int)offsetof(HealthIcon_obj,iconSway),HX_("iconSway",b5,ee,65,79)},
	{::hx::fsInt,(int)offsetof(HealthIcon_obj,BPM),HX_("BPM",bf,5a,32,00)},
	{::hx::fsObject /* ::Array< ::String > */ ,(int)offsetof(HealthIcon_obj,iconCharacters),HX_("iconCharacters",83,b5,99,00)},
	{::hx::fsFloat,(int)offsetof(HealthIcon_obj,updatePref),HX_("updatePref",8c,a9,13,03)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *HealthIcon_obj_sStaticStorageInfo = 0;
#endif

static ::String HealthIcon_obj_sMemberFields[] = {
	HX_("sprTracker",03,a3,e2,78),
	HX_("iconSway",b5,ee,65,79),
	HX_("BPM",bf,5a,32,00),
	HX_("iconCharacters",83,b5,99,00),
	HX_("updatePref",8c,a9,13,03),
	HX_("loadAllAnims",a7,74,30,d5),
	HX_("createAnim",2d,47,ff,52),
	HX_("loadJSON",4e,af,ef,b6),
	HX_("update",09,86,05,87),
	::String(null()) };

::hx::Class HealthIcon_obj::__mClass;

void HealthIcon_obj::__register()
{
	HealthIcon_obj _hx_dummy;
	HealthIcon_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("HealthIcon",55,be,f9,f8);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(HealthIcon_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< HealthIcon_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = HealthIcon_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = HealthIcon_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

