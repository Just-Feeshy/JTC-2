#include <hxcpp.h>

#ifndef INCLUDED_ClassType
#include <ClassType.h>
#endif
#ifndef INCLUDED_CustomNoteHandler
#include <CustomNoteHandler.h>
#endif
#ifndef INCLUDED_HelperStates
#include <HelperStates.h>
#endif
#ifndef INCLUDED_ModLua
#include <ModLua.h>
#endif
#ifndef INCLUDED_Paths
#include <Paths.h>
#endif
#ifndef INCLUDED_Register
#include <Register.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_example_code_DefaultEvents
#include <example_code/DefaultEvents.h>
#endif
#ifndef INCLUDED_example_code_DefaultStage
#include <example_code/DefaultStage.h>
#endif
#ifndef INCLUDED_feshixl_group_FeshEventGroup
#include <feshixl/group/FeshEventGroup.h>
#endif
#ifndef INCLUDED_feshixl_group_IFeshEvent
#include <feshixl/group/IFeshEvent.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
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
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_tweens_FlxEase
#include <flixel/tweens/FlxEase.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxDestroyable
#include <flixel/util/IFlxDestroyable.h>
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
#ifndef INCLUDED_sys_io_File
#include <sys/io/File.h>
#endif
#ifndef INCLUDED_template_StageBuilder
#include <template/StageBuilder.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_22d9f9875ce3d2de_59_get_regJSON,"Register","get_regJSON",0x7dc5cb28,"Register.get_regJSON","Register.hx",59,0xfbf2141b)
HX_LOCAL_STACK_FRAME(_hx_pos_22d9f9875ce3d2de_74_setup,"Register","setup",0x1a9cee52,"Register.setup","Register.hx",74,0xfbf2141b)
HX_LOCAL_STACK_FRAME(_hx_pos_22d9f9875ce3d2de_80_attachLuaToState,"Register","attachLuaToState",0x8c82562e,"Register.attachLuaToState","Register.hx",80,0xfbf2141b)
HX_LOCAL_STACK_FRAME(_hx_pos_22d9f9875ce3d2de_85_add,"Register","add",0x77da22b6,"Register.add","Register.hx",85,0xfbf2141b)
HX_LOCAL_STACK_FRAME(_hx_pos_22d9f9875ce3d2de_97_implementCustomNote,"Register","implementCustomNote",0x3331625b,"Register.implementCustomNote","Register.hx",97,0xfbf2141b)
HX_LOCAL_STACK_FRAME(_hx_pos_22d9f9875ce3d2de_100_getWeekFromSong,"Register","getWeekFromSong",0x56e5b43e,"Register.getWeekFromSong","Register.hx",100,0xfbf2141b)
HX_LOCAL_STACK_FRAME(_hx_pos_22d9f9875ce3d2de_119_forNameClass,"Register","forNameClass",0x90014a6f,"Register.forNameClass","Register.hx",119,0xfbf2141b)
HX_LOCAL_STACK_FRAME(_hx_pos_22d9f9875ce3d2de_123_getFlxEaseByString,"Register","getFlxEaseByString",0x378ba6bd,"Register.getFlxEaseByString","Register.hx",123,0xfbf2141b)
HX_LOCAL_STACK_FRAME(_hx_pos_22d9f9875ce3d2de_64_boot,"Register","boot",0x67b5d5fd,"Register.boot","Register.hx",64,0xfbf2141b)
HX_LOCAL_STACK_FRAME(_hx_pos_22d9f9875ce3d2de_67_boot,"Register","boot",0x67b5d5fd,"Register.boot","Register.hx",67,0xfbf2141b)

void Register_obj::__construct() { }

Dynamic Register_obj::__CreateEmpty() { return new Register_obj; }

void *Register_obj::_hx_vtable = 0;

Dynamic Register_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Register_obj > _hx_result = new Register_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool Register_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x05e25543;
}

::String Register_obj::get_regJSON(){
            	HX_STACKFRAME(&_hx_pos_22d9f9875ce3d2de_59_get_regJSON)
HXDLIN(  59)		return ::sys::io::File_obj::getContent(HX_("config/mod.json",81,23,c4,45)).split(HX_(":",3a,00,00,00))->__get(1).split(HX_("\"",22,00,00,00))->__get(1);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Register_obj,get_regJSON,return )

 ::feshixl::group::FeshEventGroup Register_obj::events;

::Array< ::Dynamic> Register_obj::stages;

void Register_obj::setup(){
            	HX_GC_STACKFRAME(&_hx_pos_22d9f9875ce3d2de_74_setup)
HXDLIN(  74)		 ::feshixl::group::FeshEventGroup _hx_tmp = ::Register_obj::events;
HXDLIN(  74)		_hx_tmp->add( ::example_code::DefaultEvents_obj::__alloc( HX_CTX ));
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Register_obj,setup,(void))

void Register_obj::attachLuaToState(::hx::Class state, ::ModLua luaClass){
            	HX_STACKFRAME(&_hx_pos_22d9f9875ce3d2de_80_attachLuaToState)
HXDLIN(  80)		::Dynamic this1 = ::HelperStates_obj::scriptsInStates;
HXDLIN(  80)		( ( ::haxe::ds::StringMap)(this1) )->set(::Type_obj::getClassName(state),luaClass);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Register_obj,attachLuaToState,(void))

void Register_obj::add( ::ClassType addonType, ::Dynamic addonClass){
            	HX_STACKFRAME(&_hx_pos_22d9f9875ce3d2de_85_add)
HXDLIN(  85)		switch((int)(addonType->_hx_getIndex())){
            			case (int)0: {
HXLINE(  87)				::Dynamic daEvent = addonClass;
HXLINE(  89)				if (!(::Register_obj::events->members->contains(daEvent))) {
HXLINE(  90)					::Register_obj::events->add(daEvent);
            				}
            			}
            			break;
            			case (int)1: {
HXLINE(  92)				::Array< ::Dynamic> _hx_tmp = ::Register_obj::stages;
HXDLIN(  92)				_hx_tmp->push(::Type_obj::getClass(addonClass));
            			}
            			break;
            		}
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Register_obj,add,(void))

void Register_obj::implementCustomNote(::String name,::hx::Class addonClass){
            	HX_STACKFRAME(&_hx_pos_22d9f9875ce3d2de_97_implementCustomNote)
HXDLIN(  97)		::CustomNoteHandler_obj::customNoteAddon->set(name,addonClass);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Register_obj,implementCustomNote,(void))

int Register_obj::getWeekFromSong(::String song){
            	HX_STACKFRAME(&_hx_pos_22d9f9875ce3d2de_100_getWeekFromSong)
HXLINE( 101)		int week = 0;
HXLINE( 106)		while(::hx::IsNotNull( ( ( ::haxe::ds::StringMap)( ::Dynamic(::Paths_obj::get_modJSON()->__Field(HX_("weeks",ff,95,be,c7),::hx::paccDynamic))) )->get((HX_("week_",eb,95,be,c7) + week)) )){
HXLINE( 107)			if (( (::Array< ::String >)(( ( ::haxe::ds::StringMap)( ::Dynamic(::Paths_obj::get_modJSON()->__Field(HX_("weeks",ff,95,be,c7),::hx::paccDynamic))) )->get((HX_("week_",eb,95,be,c7) + week))->__Field(HX_("week_data",95,bd,ba,c4),::hx::paccDynamic)) )->contains(song)) {
HXLINE( 108)				return week;
            			}
HXLINE( 111)			week = (week + 1);
            		}
HXLINE( 114)		HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(HX_("Error: song not found in method - getWeekFromSong",ea,aa,bb,64)));
HXDLIN( 114)		return 0;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Register_obj,getWeekFromSong,return )

 ::Dynamic Register_obj::forNameClass(::String type,::cpp::VirtualArray args){
            	HX_STACKFRAME(&_hx_pos_22d9f9875ce3d2de_119_forNameClass)
HXDLIN( 119)		return ::Type_obj::createInstance(::Type_obj::resolveClass(type),args);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Register_obj,forNameClass,return )

 ::Dynamic Register_obj::getFlxEaseByString(::String ease){
            	HX_STACKFRAME(&_hx_pos_22d9f9875ce3d2de_123_getFlxEaseByString)
HXDLIN( 123)		::String _hx_switch_0 = ::StringTools_obj::trim(ease.toLowerCase());
            		if (  (_hx_switch_0==HX_("backin",cc,4d,99,4a)) ){
HXLINE( 125)			return ::flixel::tweens::FlxEase_obj::backIn_dyn();
HXDLIN( 125)			goto _hx_goto_8;
            		}
            		if (  (_hx_switch_0==HX_("backinout",42,fa,a0,07)) ){
HXLINE( 127)			return ::flixel::tweens::FlxEase_obj::backInOut_dyn();
HXDLIN( 127)			goto _hx_goto_8;
            		}
            		if (  (_hx_switch_0==HX_("backout",c7,58,8f,fb)) ){
HXLINE( 129)			return ::flixel::tweens::FlxEase_obj::backOut_dyn();
HXDLIN( 129)			goto _hx_goto_8;
            		}
            		if (  (_hx_switch_0==HX_("bouncein",6d,53,b0,4c)) ){
HXLINE( 131)			return ::flixel::tweens::FlxEase_obj::bounceIn_dyn();
HXDLIN( 131)			goto _hx_goto_8;
            		}
            		if (  (_hx_switch_0==HX_("bounceinout",41,6f,66,e6)) ){
HXLINE( 133)			return ::flixel::tweens::FlxEase_obj::bounceInOut_dyn();
HXDLIN( 133)			goto _hx_goto_8;
            		}
            		if (  (_hx_switch_0==HX_("bounceout",06,40,9d,cd)) ){
HXLINE( 135)			return ::flixel::tweens::FlxEase_obj::bounceOut_dyn();
HXDLIN( 135)			goto _hx_goto_8;
            		}
            		if (  (_hx_switch_0==HX_("circin",7c,6f,0d,56)) ){
HXLINE( 137)			return ::flixel::tweens::FlxEase_obj::circIn_dyn();
HXDLIN( 137)			goto _hx_goto_8;
            		}
            		if (  (_hx_switch_0==HX_("circinout",92,06,0d,e1)) ){
HXLINE( 139)			return ::flixel::tweens::FlxEase_obj::circInOut_dyn();
HXDLIN( 139)			goto _hx_goto_8;
            		}
            		if (  (_hx_switch_0==HX_("circout",17,b1,b8,f5)) ){
HXLINE( 141)			return ::flixel::tweens::FlxEase_obj::circOut_dyn();
HXDLIN( 141)			goto _hx_goto_8;
            		}
            		if (  (_hx_switch_0==HX_("cubein",1a,80,4a,34)) ){
HXLINE( 143)			return ::flixel::tweens::FlxEase_obj::cubeIn_dyn();
HXDLIN( 143)			goto _hx_goto_8;
            		}
            		if (  (_hx_switch_0==HX_("cubeinout",b4,ac,c9,c2)) ){
HXLINE( 145)			return ::flixel::tweens::FlxEase_obj::cubeInOut_dyn();
HXDLIN( 145)			goto _hx_goto_8;
            		}
            		if (  (_hx_switch_0==HX_("cubeout",b9,2a,ea,8c)) ){
HXLINE( 147)			return ::flixel::tweens::FlxEase_obj::cubeOut_dyn();
HXDLIN( 147)			goto _hx_goto_8;
            		}
            		if (  (_hx_switch_0==HX_("elasticin",fa,3c,61,27)) ){
HXLINE( 149)			return ::flixel::tweens::FlxEase_obj::elasticIn_dyn();
HXDLIN( 149)			goto _hx_goto_8;
            		}
            		if (  (_hx_switch_0==HX_("elasticinout",d4,3b,a0,39)) ){
HXLINE( 151)			return ::flixel::tweens::FlxEase_obj::elasticInOut_dyn();
HXDLIN( 151)			goto _hx_goto_8;
            		}
            		if (  (_hx_switch_0==HX_("elasticout",d9,b1,b8,4d)) ){
HXLINE( 153)			return ::flixel::tweens::FlxEase_obj::elasticOut_dyn();
HXDLIN( 153)			goto _hx_goto_8;
            		}
            		if (  (_hx_switch_0==HX_("expoin",97,89,7d,c4)) ){
HXLINE( 155)			return ::flixel::tweens::FlxEase_obj::expoIn_dyn();
HXDLIN( 155)			goto _hx_goto_8;
            		}
            		if (  (_hx_switch_0==HX_("expoinout",57,ef,01,5a)) ){
HXLINE( 157)			return ::flixel::tweens::FlxEase_obj::expoInOut_dyn();
HXDLIN( 157)			goto _hx_goto_8;
            		}
            		if (  (_hx_switch_0==HX_("expoout",9c,6e,5f,29)) ){
HXLINE( 159)			return ::flixel::tweens::FlxEase_obj::expoOut_dyn();
HXDLIN( 159)			goto _hx_goto_8;
            		}
            		if (  (_hx_switch_0==HX_("quadin",6c,94,9f,cc)) ){
HXLINE( 161)			return ::flixel::tweens::FlxEase_obj::quadIn_dyn();
HXDLIN( 161)			goto _hx_goto_8;
            		}
            		if (  (_hx_switch_0==HX_("quadinout",a2,97,0c,bc)) ){
HXLINE( 163)			return ::flixel::tweens::FlxEase_obj::quadInOut_dyn();
HXDLIN( 163)			goto _hx_goto_8;
            		}
            		if (  (_hx_switch_0==HX_("quadout",27,de,06,3f)) ){
HXLINE( 165)			return ::flixel::tweens::FlxEase_obj::quadOut_dyn();
HXDLIN( 165)			goto _hx_goto_8;
            		}
            		if (  (_hx_switch_0==HX_("quartin",a4,9b,4b,48)) ){
HXLINE( 167)			return ::flixel::tweens::FlxEase_obj::quartIn_dyn();
HXDLIN( 167)			goto _hx_goto_8;
            		}
            		if (  (_hx_switch_0==HX_("quartinout",6a,e3,62,99)) ){
HXLINE( 169)			return ::flixel::tweens::FlxEase_obj::quartInOut_dyn();
HXDLIN( 169)			goto _hx_goto_8;
            		}
            		if (  (_hx_switch_0==HX_("quartout",ef,27,e1,f9)) ){
HXLINE( 171)			return ::flixel::tweens::FlxEase_obj::quartOut_dyn();
HXDLIN( 171)			goto _hx_goto_8;
            		}
            		if (  (_hx_switch_0==HX_("quintin",30,65,db,e0)) ){
HXLINE( 173)			return ::flixel::tweens::FlxEase_obj::quintIn_dyn();
HXDLIN( 173)			goto _hx_goto_8;
            		}
            		if (  (_hx_switch_0==HX_("quintinout",5e,99,a0,bc)) ){
HXLINE( 175)			return ::flixel::tweens::FlxEase_obj::quintInOut_dyn();
HXDLIN( 175)			goto _hx_goto_8;
            		}
            		if (  (_hx_switch_0==HX_("quintout",e3,b8,21,df)) ){
HXLINE( 177)			return ::flixel::tweens::FlxEase_obj::quintOut_dyn();
HXDLIN( 177)			goto _hx_goto_8;
            		}
            		if (  (_hx_switch_0==HX_("sinein",72,df,1f,b9)) ){
HXLINE( 179)			return ::flixel::tweens::FlxEase_obj::sineIn_dyn();
HXDLIN( 179)			goto _hx_goto_8;
            		}
            		if (  (_hx_switch_0==HX_("sineinout",5c,74,84,36)) ){
HXLINE( 181)			return ::flixel::tweens::FlxEase_obj::sineInOut_dyn();
HXDLIN( 181)			goto _hx_goto_8;
            		}
            		if (  (_hx_switch_0==HX_("sineout",61,38,c8,42)) ){
HXLINE( 183)			return ::flixel::tweens::FlxEase_obj::sineOut_dyn();
HXDLIN( 183)			goto _hx_goto_8;
            		}
            		if (  (_hx_switch_0==HX_("smootherstepin",8c,7c,27,7b)) ){
HXLINE( 191)			return ::flixel::tweens::FlxEase_obj::smootherStepIn_dyn();
HXDLIN( 191)			goto _hx_goto_8;
            		}
            		if (  (_hx_switch_0==HX_("smootherstepinout",82,83,8c,0a)) ){
HXLINE( 193)			return ::flixel::tweens::FlxEase_obj::smootherStepInOut_dyn();
HXDLIN( 193)			goto _hx_goto_8;
            		}
            		if (  (_hx_switch_0==HX_("smootherstepout",07,12,6a,47)) ){
HXLINE( 195)			return ::flixel::tweens::FlxEase_obj::smootherStepOut_dyn();
HXDLIN( 195)			goto _hx_goto_8;
            		}
            		if (  (_hx_switch_0==HX_("smoothstepin",df,0c,da,16)) ){
HXLINE( 185)			return ::flixel::tweens::FlxEase_obj::smoothStepIn_dyn();
HXDLIN( 185)			goto _hx_goto_8;
            		}
            		if (  (_hx_switch_0==HX_("smoothstepinout",0f,a9,b0,af)) ){
HXLINE( 187)			return ::flixel::tweens::FlxEase_obj::smoothStepInOut_dyn();
HXDLIN( 187)			goto _hx_goto_8;
            		}
            		if (  (_hx_switch_0==HX_("smoothstepout",54,ca,f5,e7)) ){
HXLINE( 189)			return ::flixel::tweens::FlxEase_obj::smoothStepInOut_dyn();
HXDLIN( 189)			goto _hx_goto_8;
            		}
            		/* default */{
HXLINE( 197)			return ::flixel::tweens::FlxEase_obj::linear_dyn();
            		}
            		_hx_goto_8:;
HXLINE( 123)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Register_obj,getFlxEaseByString,return )


Register_obj::Register_obj()
{
}

bool Register_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"add") ) { outValue = add_dyn(); return true; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"setup") ) { outValue = setup_dyn(); return true; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"events") ) { outValue = ( events ); return true; }
		if (HX_FIELD_EQ(inName,"stages") ) { outValue = ( stages ); return true; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"regJSON") ) { if (inCallProp == ::hx::paccAlways) { outValue = ( get_regJSON() ); return true; } }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_regJSON") ) { outValue = get_regJSON_dyn(); return true; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"forNameClass") ) { outValue = forNameClass_dyn(); return true; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"getWeekFromSong") ) { outValue = getWeekFromSong_dyn(); return true; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"attachLuaToState") ) { outValue = attachLuaToState_dyn(); return true; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"getFlxEaseByString") ) { outValue = getFlxEaseByString_dyn(); return true; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"implementCustomNote") ) { outValue = implementCustomNote_dyn(); return true; }
	}
	return false;
}

bool Register_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"events") ) { events=ioValue.Cast<  ::feshixl::group::FeshEventGroup >(); return true; }
		if (HX_FIELD_EQ(inName,"stages") ) { stages=ioValue.Cast< ::Array< ::Dynamic> >(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *Register_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo Register_obj_sStaticStorageInfo[] = {
	{::hx::fsObject /*  ::feshixl::group::FeshEventGroup */ ,(void *) &Register_obj::events,HX_("events",19,4f,6a,96)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(void *) &Register_obj::stages,HX_("stages",f5,fb,f1,05)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static void Register_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Register_obj::events,"events");
	HX_MARK_MEMBER_NAME(Register_obj::stages,"stages");
};

#ifdef HXCPP_VISIT_ALLOCS
static void Register_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Register_obj::events,"events");
	HX_VISIT_MEMBER_NAME(Register_obj::stages,"stages");
};

#endif

::hx::Class Register_obj::__mClass;

static ::String Register_obj_sStaticFields[] = {
	HX_("get_regJSON",93,7d,03,ec),
	HX_("events",19,4f,6a,96),
	HX_("stages",f5,fb,f1,05),
	HX_("setup",7d,ae,2f,7a),
	HX_("attachLuaToState",e3,ff,8e,af),
	HX_("add",21,f2,49,00),
	HX_("implementCustomNote",c6,f7,57,ac),
	HX_("getWeekFromSong",29,78,c4,16),
	HX_("forNameClass",a4,b5,bf,97),
	HX_("getFlxEaseByString",b2,e7,5d,b6),
	::String(null())
};

void Register_obj::__register()
{
	Register_obj _hx_dummy;
	Register_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("Register",83,62,51,aa);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Register_obj::__GetStatic;
	__mClass->mSetStaticField = &Register_obj::__SetStatic;
	__mClass->mMarkFunc = Register_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(Register_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< Register_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = Register_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Register_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Register_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void Register_obj::__boot()
{
{
            	HX_GC_STACKFRAME(&_hx_pos_22d9f9875ce3d2de_64_boot)
HXDLIN(  64)		events =  ::feshixl::group::FeshEventGroup_obj::__alloc( HX_CTX ,null());
            	}
{
            	HX_STACKFRAME(&_hx_pos_22d9f9875ce3d2de_67_boot)
HXDLIN(  67)		stages = ::Array_obj< ::Dynamic>::__new(1)->init(0,::hx::ClassOf< ::example_code::DefaultStage >());
            	}
}

