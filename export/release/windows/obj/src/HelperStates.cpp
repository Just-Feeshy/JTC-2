#include <hxcpp.h>

#ifndef INCLUDED_CameraNote
#include <CameraNote.h>
#endif
#ifndef INCLUDED_HelperStates
#include <HelperStates.h>
#endif
#ifndef INCLUDED_ModLua
#include <ModLua.h>
#endif
#ifndef INCLUDED_MusicBeatState
#include <MusicBeatState.h>
#endif
#ifndef INCLUDED_PlayState
#include <PlayState.h>
#endif
#ifndef INCLUDED_Register
#include <Register.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_betterShit_BetterCams
#include <betterShit/BetterCams.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxCamera
#include <flixel/FlxCamera.h>
#endif
#ifndef INCLUDED_flixel_FlxState
#include <flixel/FlxState.h>
#endif
#ifndef INCLUDED_flixel_addons_transition_FlxTransitionableState
#include <flixel/addons/transition/FlxTransitionableState.h>
#endif
#ifndef INCLUDED_flixel_addons_transition_TransitionData
#include <flixel/addons/transition/TransitionData.h>
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
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxDestroyable
#include <flixel/util/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_df6619041da74cb6_23_new,"HelperStates","new",0xeef4f662,"HelperStates.new","HelperStates.hx",23,0x44cd6b4e)
HX_LOCAL_STACK_FRAME(_hx_pos_df6619041da74cb6_29_create,"HelperStates","create",0xc77c6e3a,"HelperStates.create","HelperStates.hx",29,0x44cd6b4e)
HX_LOCAL_STACK_FRAME(_hx_pos_df6619041da74cb6_41_onCreate,"HelperStates","onCreate",0x21e83039,"HelperStates.onCreate","HelperStates.hx",41,0x44cd6b4e)
HX_LOCAL_STACK_FRAME(_hx_pos_df6619041da74cb6_52_callLua,"HelperStates","callLua",0x0847febc,"HelperStates.callLua","HelperStates.hx",52,0x44cd6b4e)
HX_LOCAL_STACK_FRAME(_hx_pos_df6619041da74cb6_59_resetScript,"HelperStates","resetScript",0x5a8ec93c,"HelperStates.resetScript","HelperStates.hx",59,0x44cd6b4e)
HX_LOCAL_STACK_FRAME(_hx_pos_df6619041da74cb6_68_clearStuff,"HelperStates","clearStuff",0xdff95465,"HelperStates.clearStuff","HelperStates.hx",68,0x44cd6b4e)
HX_LOCAL_STACK_FRAME(_hx_pos_df6619041da74cb6_78_destroy,"HelperStates","destroy",0xd87f7bfc,"HelperStates.destroy","HelperStates.hx",78,0x44cd6b4e)
HX_LOCAL_STACK_FRAME(_hx_pos_df6619041da74cb6_91_getLua,"HelperStates","getLua",0xee8e9a00,"HelperStates.getLua","HelperStates.hx",91,0x44cd6b4e)
HX_LOCAL_STACK_FRAME(_hx_pos_df6619041da74cb6_95_luaExist,"HelperStates","luaExist",0xbba8f09d,"HelperStates.luaExist","HelperStates.hx",95,0x44cd6b4e)
HX_LOCAL_STACK_FRAME(_hx_pos_df6619041da74cb6_21_boot,"HelperStates","boot",0x1f7b9ff0,"HelperStates.boot","HelperStates.hx",21,0x44cd6b4e)

void HelperStates_obj::__construct(){
            	HX_GC_STACKFRAME(&_hx_pos_df6619041da74cb6_23_new)
HXLINE(  24)		super::__construct(null(),null());
HXLINE(  26)		this->modifiableSprites =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
            	}

bool HelperStates_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x2f064378) {
		if (inClassId<=(int)0x29d19794) {
			if (inClassId<=(int)0x23a57bae) {
				return inClassId==(int)0x00000001 || inClassId==(int)0x23a57bae;
			} else {
				return inClassId==(int)0x29d19794;
			}
		} else {
			return inClassId==(int)0x2f064378;
		}
	} else {
		if (inClassId<=(int)0x7c795c9f) {
			return inClassId==(int)0x62817b24 || inClassId==(int)0x7c795c9f;
		} else {
			return inClassId==(int)0x7ccf8994;
		}
	}
}

void HelperStates_obj::create(){
            	HX_STACKFRAME(&_hx_pos_df6619041da74cb6_29_create)
HXLINE(  30)		this->super::create();
HXLINE(  36)		if (::HelperStates_obj::luaExist(::Type_obj::getClass(::hx::ObjectPtr<OBJ_>(this)))) {
HXLINE(  37)			::HelperStates_obj::getLua(::Type_obj::getClass(::hx::ObjectPtr<OBJ_>(this)))->execute();
            		}
            	}


 ::Dynamic HelperStates_obj::onCreate(){
            	HX_STACKFRAME(&_hx_pos_df6619041da74cb6_41_onCreate)
HXLINE(  43)		if (::HelperStates_obj::luaExist(::Type_obj::getClass(::hx::ObjectPtr<OBJ_>(this)))) {
HXLINE(  44)			return ::HelperStates_obj::getLua(::Type_obj::getClass(::hx::ObjectPtr<OBJ_>(this)))->call(HX_("onCreate",7b,5d,bc,5b),::cpp::VirtualArray_obj::__new(0),null());
            		}
HXLINE(  47)		return null();
            	}


HX_DEFINE_DYNAMIC_FUNC0(HelperStates_obj,onCreate,return )

void HelperStates_obj::callLua(::String name,::cpp::VirtualArray args){
            	HX_STACKFRAME(&_hx_pos_df6619041da74cb6_52_callLua)
HXDLIN(  52)		if (::HelperStates_obj::luaExist(::Type_obj::getClass(::hx::ObjectPtr<OBJ_>(this)))) {
HXLINE(  53)			::HelperStates_obj::getLua(::Type_obj::getClass(::hx::ObjectPtr<OBJ_>(this)))->call(name,args,null());
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC2(HelperStates_obj,callLua,(void))

void HelperStates_obj::resetScript(){
            	HX_GC_STACKFRAME(&_hx_pos_df6619041da74cb6_59_resetScript)
HXDLIN(  59)		if (::HelperStates_obj::luaExist(::Type_obj::getClass(::hx::ObjectPtr<OBJ_>(this)))) {
HXLINE(  60)			::String file = ::HelperStates_obj::getLua(::Type_obj::getClass(::hx::ObjectPtr<OBJ_>(this)))->luaScript;
HXLINE(  62)			::hx::Class _hx_tmp = ::Type_obj::getClass(::hx::ObjectPtr<OBJ_>(this));
HXDLIN(  62)			::Register_obj::attachLuaToState(_hx_tmp, ::ModLua_obj::__alloc( HX_CTX ,file));
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC0(HelperStates_obj,resetScript,(void))

void HelperStates_obj::clearStuff(){
            	HX_STACKFRAME(&_hx_pos_df6619041da74cb6_68_clearStuff)
HXDLIN(  68)		if (!(::Std_obj::isOfType(::hx::ObjectPtr<OBJ_>(this),::hx::ClassOf< ::PlayState >()))) {
HXLINE(  69)			if (::hx::IsNotNull( ::PlayState_obj::camNOTE )) {
HXLINE(  70)				::PlayState_obj::camHUD = null();
HXLINE(  71)				::PlayState_obj::camNOTE = null();
            			}
HXLINE(  74)			::PlayState_obj::modStorage = ::Array_obj< ::String >::__new(0);
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC0(HelperStates_obj,clearStuff,(void))

void HelperStates_obj::destroy(){
            	HX_STACKFRAME(&_hx_pos_df6619041da74cb6_78_destroy)
HXLINE(  80)		if (::HelperStates_obj::luaExist(::Type_obj::getClass(::hx::ObjectPtr<OBJ_>(this)))) {
HXLINE(  81)			::HelperStates_obj::getLua(::Type_obj::getClass(::hx::ObjectPtr<OBJ_>(this)))->close();
            		}
HXLINE(  84)		this->resetScript();
HXLINE(  87)		this->super::destroy();
            	}


 ::haxe::ds::StringMap HelperStates_obj::scriptsInStates;

 ::ModLua HelperStates_obj::getLua(::hx::Class state){
            	HX_STACKFRAME(&_hx_pos_df6619041da74cb6_91_getLua)
HXDLIN(  91)		::Dynamic this1 = ::HelperStates_obj::scriptsInStates;
HXDLIN(  91)		return ( ( ::ModLua)(( ( ::haxe::ds::StringMap)(this1) )->get(::Type_obj::getClassName(state))) );
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(HelperStates_obj,getLua,return )

bool HelperStates_obj::luaExist(::hx::Class state){
            	HX_STACKFRAME(&_hx_pos_df6619041da74cb6_95_luaExist)
HXDLIN(  95)		::Dynamic this1 = ::HelperStates_obj::scriptsInStates;
HXDLIN(  95)		return ( ( ::haxe::ds::StringMap)(this1) )->exists(::Type_obj::getClassName(state));
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(HelperStates_obj,luaExist,return )


HelperStates_obj::HelperStates_obj()
{
}

void HelperStates_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HelperStates);
	HX_MARK_MEMBER_NAME(modifiableSprites,"modifiableSprites");
	 ::flixel::addons::ui::FlxUIState_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void HelperStates_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(modifiableSprites,"modifiableSprites");
	 ::flixel::addons::ui::FlxUIState_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val HelperStates_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return ::hx::Val( create_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"callLua") ) { return ::hx::Val( callLua_dyn() ); }
		if (HX_FIELD_EQ(inName,"destroy") ) { return ::hx::Val( destroy_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"onCreate") ) { return ::hx::Val( onCreate_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"clearStuff") ) { return ::hx::Val( clearStuff_dyn() ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"resetScript") ) { return ::hx::Val( resetScript_dyn() ); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"modifiableSprites") ) { return ::hx::Val( modifiableSprites ); }
	}
	return super::__Field(inName,inCallProp);
}

bool HelperStates_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"getLua") ) { outValue = getLua_dyn(); return true; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"luaExist") ) { outValue = luaExist_dyn(); return true; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"scriptsInStates") ) { outValue = ( scriptsInStates ); return true; }
	}
	return false;
}

::hx::Val HelperStates_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 17:
		if (HX_FIELD_EQ(inName,"modifiableSprites") ) { modifiableSprites=inValue.Cast<  ::haxe::ds::StringMap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool HelperStates_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 15:
		if (HX_FIELD_EQ(inName,"scriptsInStates") ) { scriptsInStates=ioValue.Cast<  ::haxe::ds::StringMap >(); return true; }
	}
	return false;
}

void HelperStates_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("modifiableSprites",2a,7a,ad,19));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo HelperStates_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::haxe::ds::StringMap */ ,(int)offsetof(HelperStates_obj,modifiableSprites),HX_("modifiableSprites",2a,7a,ad,19)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo HelperStates_obj_sStaticStorageInfo[] = {
	{::hx::fsObject /*  ::haxe::ds::StringMap */ ,(void *) &HelperStates_obj::scriptsInStates,HX_("scriptsInStates",2f,23,f7,ea)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static ::String HelperStates_obj_sMemberFields[] = {
	HX_("modifiableSprites",2a,7a,ad,19),
	HX_("create",fc,66,0f,7c),
	HX_("onCreate",7b,5d,bc,5b),
	HX_("callLua",ba,af,4e,54),
	HX_("resetScript",3a,d1,74,e7),
	HX_("clearStuff",27,d6,24,59),
	HX_("destroy",fa,2c,86,24),
	::String(null()) };

static void HelperStates_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HelperStates_obj::scriptsInStates,"scriptsInStates");
};

#ifdef HXCPP_VISIT_ALLOCS
static void HelperStates_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HelperStates_obj::scriptsInStates,"scriptsInStates");
};

#endif

::hx::Class HelperStates_obj::__mClass;

void HelperStates_obj::__register()
{
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("HelperStates",70,dd,a5,0e);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mMarkFunc = HelperStates_obj_sMarkStatics;
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(HelperStates_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TIsInterface< (int)0x0ea5dd70 >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = HelperStates_obj_sVisitStatics;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void HelperStates_obj::__boot()
{
{
            	HX_GC_STACKFRAME(&_hx_pos_df6619041da74cb6_21_boot)
HXDLIN(  21)		scriptsInStates =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
            	}
}

