#include <hxcpp.h>

#ifndef INCLUDED_HelperStates
#include <HelperStates.h>
#endif
#ifndef INCLUDED_MusicBeatState
#include <MusicBeatState.h>
#endif
#ifndef INCLUDED_PlayState
#include <PlayState.h>
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
#ifndef INCLUDED_flixel_FlxGame
#include <flixel/FlxGame.h>
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
#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObject
#include <openfl/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObjectContainer
#include <openfl/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_openfl_display_IBitmapDrawable
#include <openfl/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl_display_InteractiveObject
#include <openfl/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_openfl_display_Sprite
#include <openfl/display/Sprite.h>
#endif
#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_template_StageBuilder
#include <template/StageBuilder.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_16decf10274984e4_17_new,"template.StageBuilder","new",0x56923e43,"template.StageBuilder.new","template/StageBuilder.hx",17,0xc66da3ac)
HX_LOCAL_STACK_FRAME(_hx_pos_16decf10274984e4_25_addToStage,"template.StageBuilder","addToStage",0xf7ee479f,"template.StageBuilder.addToStage","template/StageBuilder.hx",25,0xc66da3ac)
HX_LOCAL_STACK_FRAME(_hx_pos_16decf10274984e4_32_destroy,"template.StageBuilder","destroy",0xd2f4c85d,"template.StageBuilder.destroy","template/StageBuilder.hx",32,0xc66da3ac)
namespace _hx_template{

void StageBuilder_obj::__construct(::String song){
            	HX_GC_STACKFRAME(&_hx_pos_16decf10274984e4_17_new)
HXLINE(  18)		super::__construct();
HXLINE(  20)		this->sprites =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
HXLINE(  22)		this->song = song;
            	}

Dynamic StageBuilder_obj::__CreateEmpty() { return new StageBuilder_obj; }

void *StageBuilder_obj::_hx_vtable = 0;

Dynamic StageBuilder_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< StageBuilder_obj > _hx_result = new StageBuilder_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool StageBuilder_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x0b48a01f) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x0b48a01f;
	} else {
		return inClassId==(int)0x7ccf8994;
	}
}

void StageBuilder_obj::addToStage(::String name, ::flixel::FlxBasic thing){
            	HX_STACKFRAME(&_hx_pos_16decf10274984e4_25_addToStage)
HXLINE(  26)		this->sprites->set(name,thing);
HXLINE(  28)		if (::Std_obj::isOfType(thing,::hx::ClassOf< ::PlayState >())) {
HXLINE(  29)			::flixel::FlxG_obj::game->_state->add(thing).StaticCast<  ::flixel::FlxBasic >();
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC2(StageBuilder_obj,addToStage,(void))

void StageBuilder_obj::destroy(){
            	HX_STACKFRAME(&_hx_pos_16decf10274984e4_32_destroy)
HXLINE(  33)		if (::hx::IsNotNull( this->sprites )) {
HXLINE(  34)			{
HXLINE(  34)				 ::Dynamic k = this->sprites->keys();
HXDLIN(  34)				while(( (bool)(k->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE(  34)					::String k1 = ( (::String)(k->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXLINE(  35)					( ( ::flixel::FlxBasic)(this->sprites->get(k1)) )->destroy();
            				}
            			}
HXLINE(  38)			this->sprites->clear();
            		}
HXLINE(  41)		this->sprites = null();
HXLINE(  42)		this->song = null();
            	}



::hx::ObjectPtr< StageBuilder_obj > StageBuilder_obj::__new(::String song) {
	::hx::ObjectPtr< StageBuilder_obj > __this = new StageBuilder_obj();
	__this->__construct(song);
	return __this;
}

::hx::ObjectPtr< StageBuilder_obj > StageBuilder_obj::__alloc(::hx::Ctx *_hx_ctx,::String song) {
	StageBuilder_obj *__this = (StageBuilder_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(StageBuilder_obj), true, "template.StageBuilder"));
	*(void **)__this = StageBuilder_obj::_hx_vtable;
	__this->__construct(song);
	return __this;
}

StageBuilder_obj::StageBuilder_obj()
{
}

void StageBuilder_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(StageBuilder);
	HX_MARK_MEMBER_NAME(sprites,"sprites");
	HX_MARK_MEMBER_NAME(song,"song");
	HX_MARK_MEMBER_NAME(directory,"directory");
	 ::flixel::FlxBasic_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void StageBuilder_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(sprites,"sprites");
	HX_VISIT_MEMBER_NAME(song,"song");
	HX_VISIT_MEMBER_NAME(directory,"directory");
	 ::flixel::FlxBasic_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val StageBuilder_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"song") ) { return ::hx::Val( song ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"sprites") ) { return ::hx::Val( sprites ); }
		if (HX_FIELD_EQ(inName,"destroy") ) { return ::hx::Val( destroy_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"directory") ) { return ::hx::Val( directory ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"addToStage") ) { return ::hx::Val( addToStage_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val StageBuilder_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"song") ) { song=inValue.Cast< ::String >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"sprites") ) { sprites=inValue.Cast<  ::haxe::ds::StringMap >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"directory") ) { directory=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void StageBuilder_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("sprites",ce,a8,8a,5f));
	outFields->push(HX_("song",d5,23,58,4c));
	outFields->push(HX_("directory",6d,f2,44,10));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo StageBuilder_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::haxe::ds::StringMap */ ,(int)offsetof(StageBuilder_obj,sprites),HX_("sprites",ce,a8,8a,5f)},
	{::hx::fsString,(int)offsetof(StageBuilder_obj,song),HX_("song",d5,23,58,4c)},
	{::hx::fsString,(int)offsetof(StageBuilder_obj,directory),HX_("directory",6d,f2,44,10)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *StageBuilder_obj_sStaticStorageInfo = 0;
#endif

static ::String StageBuilder_obj_sMemberFields[] = {
	HX_("sprites",ce,a8,8a,5f),
	HX_("song",d5,23,58,4c),
	HX_("directory",6d,f2,44,10),
	HX_("addToStage",22,e3,19,b8),
	HX_("destroy",fa,2c,86,24),
	::String(null()) };

::hx::Class StageBuilder_obj::__mClass;

void StageBuilder_obj::__register()
{
	StageBuilder_obj _hx_dummy;
	StageBuilder_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("template.StageBuilder",d1,60,e7,e9);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(StageBuilder_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< StageBuilder_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = StageBuilder_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = StageBuilder_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace template
