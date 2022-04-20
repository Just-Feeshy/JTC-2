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
#ifndef INCLUDED_PlayState
#include <PlayState.h>
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
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxDestroyable
#include <flixel/util/IFlxDestroyable.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_78db3896d9facf1f_24_new,"feshixl.group.FeshEventGroup","new",0x6cb4b75f,"feshixl.group.FeshEventGroup.new","feshixl/group/FeshEventGroup.hx",24,0x40d667ef)
HX_LOCAL_STACK_FRAME(_hx_pos_78db3896d9facf1f_38_whenTriggered,"feshixl.group.FeshEventGroup","whenTriggered",0xee64393c,"feshixl.group.FeshEventGroup.whenTriggered","feshixl/group/FeshEventGroup.hx",38,0x40d667ef)
HX_LOCAL_STACK_FRAME(_hx_pos_78db3896d9facf1f_62_whenGameIsRunning,"feshixl.group.FeshEventGroup","whenGameIsRunning",0x946dcd08,"feshixl.group.FeshEventGroup.whenGameIsRunning","feshixl/group/FeshEventGroup.hx",62,0x40d667ef)
HX_LOCAL_STACK_FRAME(_hx_pos_78db3896d9facf1f_85_whenNoteIsPressed,"feshixl.group.FeshEventGroup","whenNoteIsPressed",0xe9bb8dab,"feshixl.group.FeshEventGroup.whenNoteIsPressed","feshixl/group/FeshEventGroup.hx",85,0x40d667ef)
HX_LOCAL_STACK_FRAME(_hx_pos_78db3896d9facf1f_104_add,"feshixl.group.FeshEventGroup","add",0x6caad920,"feshixl.group.FeshEventGroup.add","feshixl/group/FeshEventGroup.hx",104,0x40d667ef)
HX_LOCAL_STACK_FRAME(_hx_pos_78db3896d9facf1f_124_remove,"feshixl.group.FeshEventGroup","remove",0x43c8dea5,"feshixl.group.FeshEventGroup.remove","feshixl/group/FeshEventGroup.hx",124,0x40d667ef)
HX_LOCAL_STACK_FRAME(_hx_pos_78db3896d9facf1f_140_destroy,"feshixl.group.FeshEventGroup","destroy",0x3d7fff79,"feshixl.group.FeshEventGroup.destroy","feshixl/group/FeshEventGroup.hx",140,0x40d667ef)
namespace feshixl{
namespace group{

void FeshEventGroup_obj::__construct(::Array< ::Dynamic> members){
            	HX_STACKFRAME(&_hx_pos_78db3896d9facf1f_24_new)
HXDLIN(  24)		if (::hx::IsNotNull( members )) {
HXLINE(  25)			this->members = members;
            		}
            		else {
HXLINE(  27)			this->members = ::Array_obj< ::Dynamic>::__new(0);
            		}
            	}

Dynamic FeshEventGroup_obj::__CreateEmpty() { return new FeshEventGroup_obj; }

void *FeshEventGroup_obj::_hx_vtable = 0;

Dynamic FeshEventGroup_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< FeshEventGroup_obj > _hx_result = new FeshEventGroup_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool FeshEventGroup_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x53bb30f7;
}

static ::flixel::util::IFlxDestroyable_obj _hx_feshixl_group_FeshEventGroup__hx_flixel_util_IFlxDestroyable= {
	( void (::hx::Object::*)())&::feshixl::group::FeshEventGroup_obj::destroy,
};

static ::feshixl::group::IFeshEvent_obj _hx_feshixl_group_FeshEventGroup__hx_feshixl_group_IFeshEvent= {
	( void (::hx::Object::*)(::String,::String,::String, ::PlayState))&::feshixl::group::FeshEventGroup_obj::whenTriggered,
	( void (::hx::Object::*)(::Array< ::String >, ::PlayState))&::feshixl::group::FeshEventGroup_obj::whenGameIsRunning,
	( void (::hx::Object::*)( ::Note, ::PlayState))&::feshixl::group::FeshEventGroup_obj::whenNoteIsPressed,
};

void *FeshEventGroup_obj::_hx_getInterface(int inHash) {
	switch(inHash) {
		case (int)0xd4fe2fcd: return &_hx_feshixl_group_FeshEventGroup__hx_flixel_util_IFlxDestroyable;
		case (int)0xf0fb0b33: return &_hx_feshixl_group_FeshEventGroup__hx_feshixl_group_IFeshEvent;
	}
	#ifdef HXCPP_SCRIPTABLE
	return super::_hx_getInterface(inHash);
	#else
	return 0;
	#endif
}

void FeshEventGroup_obj::whenTriggered(::String eventName,::String eventValue,::String eventValue2, ::PlayState playState){
            	HX_STACKFRAME(&_hx_pos_78db3896d9facf1f_38_whenTriggered)
HXDLIN(  38)		if (::hx::IsNotNull( this->members )) {
HXLINE(  39)			int i = 0;
HXLINE(  40)			::Dynamic basic = null();
HXLINE(  42)			while((i < this->members->length)){
HXLINE(  43)				basic = this->members->__get(i);
HXLINE(  45)				if (::hx::IsNotNull( basic )) {
HXLINE(  46)					::feshixl::group::IFeshEvent_obj::whenTriggered(basic,eventName,eventValue,eventValue2,playState);
            				}
HXLINE(  48)				i = (i + 1);
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC4(FeshEventGroup_obj,whenTriggered,(void))

void FeshEventGroup_obj::whenGameIsRunning(::Array< ::String > activeEvents, ::PlayState playState){
            	HX_STACKFRAME(&_hx_pos_78db3896d9facf1f_62_whenGameIsRunning)
HXDLIN(  62)		if (::hx::IsNotNull( this->members )) {
HXLINE(  63)			int i = 0;
HXLINE(  64)			::Dynamic basic = null();
HXLINE(  66)			while((i < this->members->length)){
HXLINE(  67)				basic = this->members->__get(i);
HXLINE(  69)				if (::hx::IsNotNull( basic )) {
HXLINE(  70)					::feshixl::group::IFeshEvent_obj::whenGameIsRunning(basic,activeEvents,playState);
            				}
HXLINE(  72)				i = (i + 1);
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC2(FeshEventGroup_obj,whenGameIsRunning,(void))

void FeshEventGroup_obj::whenNoteIsPressed( ::Note note, ::PlayState playState){
            	HX_STACKFRAME(&_hx_pos_78db3896d9facf1f_85_whenNoteIsPressed)
HXDLIN(  85)		if (::hx::IsNotNull( this->members )) {
HXLINE(  86)			int i = 0;
HXLINE(  87)			::Dynamic basic = null();
HXLINE(  89)			while((i < this->members->length)){
HXLINE(  90)				basic = this->members->__get(i);
HXLINE(  92)				if (::hx::IsNotNull( basic )) {
HXLINE(  93)					::feshixl::group::IFeshEvent_obj::whenNoteIsPressed(basic,note,playState);
            				}
HXLINE(  95)				i = (i + 1);
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC2(FeshEventGroup_obj,whenNoteIsPressed,(void))

::Dynamic FeshEventGroup_obj::add(::Dynamic Object){
            	HX_STACKFRAME(&_hx_pos_78db3896d9facf1f_104_add)
HXLINE( 105)		if (::hx::IsNull( Object )) {
HXLINE( 106)			return null();
            		}
HXLINE( 109)		if ((this->members->indexOf(Object,null()) >= 0)) {
HXLINE( 110)			return Object;
            		}
HXLINE( 112)		this->members->push(Object);
HXLINE( 114)		return Object;
            	}


HX_DEFINE_DYNAMIC_FUNC1(FeshEventGroup_obj,add,return )

void FeshEventGroup_obj::remove(::Dynamic Object, ::Dynamic __o_Splice){
            		 ::Dynamic Splice = __o_Splice;
            		if (::hx::IsNull(__o_Splice)) Splice = true;
            	HX_STACKFRAME(&_hx_pos_78db3896d9facf1f_124_remove)
HXLINE( 125)		if (::hx::IsNull( this->members )) {
HXLINE( 126)			return;
            		}
HXLINE( 128)		int index = this->members->indexOf(Object,null());
HXLINE( 130)		if ((index < 0)) {
HXLINE( 131)			return;
            		}
HXLINE( 133)		if (( (bool)(Splice) )) {
HXLINE( 134)			this->members->removeRange(index,1);
            		}
            		else {
HXLINE( 136)			this->members[index] = null();
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC2(FeshEventGroup_obj,remove,(void))

void FeshEventGroup_obj::destroy(){
            	HX_STACKFRAME(&_hx_pos_78db3896d9facf1f_140_destroy)
HXDLIN( 140)		if (::hx::IsNotNull( this->members )) {
HXLINE( 141)			int i = 0;
HXLINE( 142)			::Dynamic basic = null();
HXLINE( 144)			while((i < this->members->length)){
HXLINE( 145)				basic = this->members->__get(i);
HXLINE( 147)				if (::hx::IsNotNull( basic )) {
HXLINE( 148)					basic = null();
            				}
HXLINE( 150)				i = (i + 1);
            			}
HXLINE( 153)			this->members = null();
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC0(FeshEventGroup_obj,destroy,(void))


::hx::ObjectPtr< FeshEventGroup_obj > FeshEventGroup_obj::__new(::Array< ::Dynamic> members) {
	::hx::ObjectPtr< FeshEventGroup_obj > __this = new FeshEventGroup_obj();
	__this->__construct(members);
	return __this;
}

::hx::ObjectPtr< FeshEventGroup_obj > FeshEventGroup_obj::__alloc(::hx::Ctx *_hx_ctx,::Array< ::Dynamic> members) {
	FeshEventGroup_obj *__this = (FeshEventGroup_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(FeshEventGroup_obj), true, "feshixl.group.FeshEventGroup"));
	*(void **)__this = FeshEventGroup_obj::_hx_vtable;
	__this->__construct(members);
	return __this;
}

FeshEventGroup_obj::FeshEventGroup_obj()
{
}

void FeshEventGroup_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FeshEventGroup);
	HX_MARK_MEMBER_NAME(members,"members");
	HX_MARK_END_CLASS();
}

void FeshEventGroup_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(members,"members");
}

::hx::Val FeshEventGroup_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"add") ) { return ::hx::Val( add_dyn() ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"remove") ) { return ::hx::Val( remove_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"members") ) { return ::hx::Val( members ); }
		if (HX_FIELD_EQ(inName,"destroy") ) { return ::hx::Val( destroy_dyn() ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"whenTriggered") ) { return ::hx::Val( whenTriggered_dyn() ); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"whenGameIsRunning") ) { return ::hx::Val( whenGameIsRunning_dyn() ); }
		if (HX_FIELD_EQ(inName,"whenNoteIsPressed") ) { return ::hx::Val( whenNoteIsPressed_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val FeshEventGroup_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"members") ) { members=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FeshEventGroup_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("members",d9,2c,70,1a));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo FeshEventGroup_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(FeshEventGroup_obj,members),HX_("members",d9,2c,70,1a)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *FeshEventGroup_obj_sStaticStorageInfo = 0;
#endif

static ::String FeshEventGroup_obj_sMemberFields[] = {
	HX_("members",d9,2c,70,1a),
	HX_("whenTriggered",7d,fd,1a,18),
	HX_("whenGameIsRunning",c9,45,e2,c7),
	HX_("whenNoteIsPressed",6c,06,30,1d),
	HX_("add",21,f2,49,00),
	HX_("remove",44,9c,88,04),
	HX_("destroy",fa,2c,86,24),
	::String(null()) };

::hx::Class FeshEventGroup_obj::__mClass;

void FeshEventGroup_obj::__register()
{
	FeshEventGroup_obj _hx_dummy;
	FeshEventGroup_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("feshixl.group.FeshEventGroup",ed,1b,58,fa);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(FeshEventGroup_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< FeshEventGroup_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = FeshEventGroup_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = FeshEventGroup_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace feshixl
} // end namespace group
