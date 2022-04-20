#include <hxcpp.h>

#ifndef INCLUDED_Conductor
#include <Conductor.h>
#endif
#ifndef INCLUDED_FeeshSprite
#include <FeeshSprite.h>
#endif
#ifndef INCLUDED_Paths
#include <Paths.h>
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
#ifndef INCLUDED_flixel_util_IFlxDestroyable
#include <flixel/util/IFlxDestroyable.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_a717ae4c7792bf04_85_new,"FeeshSprite","new",0xc39c4f92,"FeeshSprite.new","Feeshmora.hx",85,0xa899d0f2)
HX_LOCAL_STACK_FRAME(_hx_pos_a717ae4c7792bf04_103_update,"FeeshSprite","update",0x13e31217,"FeeshSprite.update","Feeshmora.hx",103,0xa899d0f2)

void FeeshSprite_obj::__construct(Float x,Float y,::String __o_ab, ::Dynamic __o_secondSprite){
            		::String ab = __o_ab;
            		if (::hx::IsNull(__o_ab)) ab = HX_("rings",c3,5a,69,e9);
            		 ::Dynamic secondSprite = __o_secondSprite;
            		if (::hx::IsNull(__o_secondSprite)) secondSprite = false;
            	HX_STACKFRAME(&_hx_pos_a717ae4c7792bf04_85_new)
HXLINE(  86)		this->curAbstract = HX_("rings",c3,5a,69,e9);
HXLINE(  89)		super::__construct(x,y,null());
HXLINE(  90)		this->curAbstract = ab;
HXLINE(  92)		this->set_antialiasing(true);
HXLINE(  94)		if ((this->curAbstract == HX_("rings",c3,5a,69,e9))) {
HXLINE(  96)			if (( (bool)(secondSprite) )) {
HXLINE(  97)				this->loadGraphic(::Paths_obj::image(HX_("reversePoison",ca,0b,0d,79),null()),null(),null(),null(),null(),null());
            			}
            			else {
HXLINE(  99)				this->loadGraphic(::Paths_obj::image(HX_("reverse",22,39,fc,1a),null()),null(),null(),null(),null(),null());
            			}
            		}
            	}

Dynamic FeeshSprite_obj::__CreateEmpty() { return new FeeshSprite_obj; }

void *FeeshSprite_obj::_hx_vtable = 0;

Dynamic FeeshSprite_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< FeeshSprite_obj > _hx_result = new FeeshSprite_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return _hx_result;
}

bool FeeshSprite_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x2c01639b) {
		if (inClassId<=(int)0x0a05cef8) {
			return inClassId==(int)0x00000001 || inClassId==(int)0x0a05cef8;
		} else {
			return inClassId==(int)0x2c01639b;
		}
	} else {
		return inClassId==(int)0x7ccf8994 || inClassId==(int)0x7dab0655;
	}
}

void FeeshSprite_obj::update(Float elapsed){
            	HX_STACKFRAME(&_hx_pos_a717ae4c7792bf04_103_update)
HXLINE( 104)		if ((this->curAbstract == HX_("rings",c3,5a,69,e9))) {
HXLINE( 105)			this->set_angle((this->angle + (( (Float)(::Conductor_obj::bpm) ) / ( (Float)(120) ))));
            		}
HXLINE( 107)		this->super::update(elapsed);
            	}



::hx::ObjectPtr< FeeshSprite_obj > FeeshSprite_obj::__new(Float x,Float y,::String __o_ab, ::Dynamic __o_secondSprite) {
	::hx::ObjectPtr< FeeshSprite_obj > __this = new FeeshSprite_obj();
	__this->__construct(x,y,__o_ab,__o_secondSprite);
	return __this;
}

::hx::ObjectPtr< FeeshSprite_obj > FeeshSprite_obj::__alloc(::hx::Ctx *_hx_ctx,Float x,Float y,::String __o_ab, ::Dynamic __o_secondSprite) {
	FeeshSprite_obj *__this = (FeeshSprite_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(FeeshSprite_obj), true, "FeeshSprite"));
	*(void **)__this = FeeshSprite_obj::_hx_vtable;
	__this->__construct(x,y,__o_ab,__o_secondSprite);
	return __this;
}

FeeshSprite_obj::FeeshSprite_obj()
{
}

void FeeshSprite_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FeeshSprite);
	HX_MARK_MEMBER_NAME(curAbstract,"curAbstract");
	 ::flixel::FlxSprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FeeshSprite_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(curAbstract,"curAbstract");
	 ::flixel::FlxSprite_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val FeeshSprite_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return ::hx::Val( update_dyn() ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"curAbstract") ) { return ::hx::Val( curAbstract ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val FeeshSprite_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"curAbstract") ) { curAbstract=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FeeshSprite_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("curAbstract",82,82,bd,29));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo FeeshSprite_obj_sMemberStorageInfo[] = {
	{::hx::fsString,(int)offsetof(FeeshSprite_obj,curAbstract),HX_("curAbstract",82,82,bd,29)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *FeeshSprite_obj_sStaticStorageInfo = 0;
#endif

static ::String FeeshSprite_obj_sMemberFields[] = {
	HX_("curAbstract",82,82,bd,29),
	HX_("update",09,86,05,87),
	::String(null()) };

::hx::Class FeeshSprite_obj::__mClass;

void FeeshSprite_obj::__register()
{
	FeeshSprite_obj _hx_dummy;
	FeeshSprite_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("FeeshSprite",a0,de,fc,e1);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(FeeshSprite_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< FeeshSprite_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = FeeshSprite_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = FeeshSprite_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

