#include <hxcpp.h>

#ifndef INCLUDED_Alphabet
#include <Alphabet.h>
#endif
#ifndef INCLUDED_GhostTapping
#include <GhostTapping.h>
#endif
#ifndef INCLUDED_Options
#include <Options.h>
#endif
#ifndef INCLUDED_SaveType
#include <SaveType.h>
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
#ifndef INCLUDED_flixel_group_FlxTypedSpriteGroup
#include <flixel/group/FlxTypedSpriteGroup.h>
#endif
#ifndef INCLUDED_flixel_util_FlxSave
#include <flixel/util/FlxSave.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxDestroyable
#include <flixel/util/IFlxDestroyable.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_bd48113b8426f330_5_new,"GhostTapping","new",0x3964c2d8,"GhostTapping.new","GhostTapping.hx",5,0x67935f98)
HX_LOCAL_STACK_FRAME(_hx_pos_bd48113b8426f330_10_get_consequence,"GhostTapping","get_consequence",0xbdc62e92,"GhostTapping.get_consequence","GhostTapping.hx",10,0x67935f98)
HX_LOCAL_STACK_FRAME(_hx_pos_bd48113b8426f330_17_get_ghostTap,"GhostTapping","get_ghostTap",0x2fe570e5,"GhostTapping.get_ghostTap","GhostTapping.hx",17,0x67935f98)

void GhostTapping_obj::__construct(Float x,Float y,::String __o_text, ::SaveType saveType, ::Dynamic Callback){
            		::String text = __o_text;
            		if (::hx::IsNull(__o_text)) text = HX_("",00,00,00,00);
            	HX_STACKFRAME(&_hx_pos_bd48113b8426f330_5_new)
HXDLIN(   5)		super::__construct(x,y,text,saveType,Callback);
            	}

Dynamic GhostTapping_obj::__CreateEmpty() { return new GhostTapping_obj; }

void *GhostTapping_obj::_hx_vtable = 0;

Dynamic GhostTapping_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< GhostTapping_obj > _hx_result = new GhostTapping_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4]);
	return _hx_result;
}

bool GhostTapping_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x567b2b93) {
		if (inClassId<=(int)0x288ce903) {
			if (inClassId<=(int)0x2662d86e) {
				return inClassId==(int)0x00000001 || inClassId==(int)0x2662d86e;
			} else {
				return inClassId==(int)0x288ce903;
			}
		} else {
			return inClassId==(int)0x2c01639b || inClassId==(int)0x567b2b93;
		}
	} else {
		if (inClassId<=(int)0x7ccf8994) {
			return inClassId==(int)0x6d6f007e || inClassId==(int)0x7ccf8994;
		} else {
			return inClassId==(int)0x7dab0655;
		}
	}
}

Float GhostTapping_obj::get_consequence(){
            	HX_STACKFRAME(&_hx_pos_bd48113b8426f330_10_get_consequence)
HXDLIN(  10)		if (( (bool)(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic)) )) {
HXLINE(  11)			return ( (Float)(2) );
            		}
            		else {
HXLINE(  13)			return ( (Float)(1) );
            		}
HXLINE(  10)		return ((Float)0.);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(GhostTapping_obj,get_consequence,return )

bool GhostTapping_obj::get_ghostTap(){
            	HX_STACKFRAME(&_hx_pos_bd48113b8426f330_17_get_ghostTap)
HXDLIN(  17)		return ( (bool)(::flixel::FlxG_obj::save->data->__Field(HX_("ghostTapping",c6,6a,da,10),::hx::paccDynamic)) );
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(GhostTapping_obj,get_ghostTap,return )


::hx::ObjectPtr< GhostTapping_obj > GhostTapping_obj::__new(Float x,Float y,::String __o_text, ::SaveType saveType, ::Dynamic Callback) {
	::hx::ObjectPtr< GhostTapping_obj > __this = new GhostTapping_obj();
	__this->__construct(x,y,__o_text,saveType,Callback);
	return __this;
}

::hx::ObjectPtr< GhostTapping_obj > GhostTapping_obj::__alloc(::hx::Ctx *_hx_ctx,Float x,Float y,::String __o_text, ::SaveType saveType, ::Dynamic Callback) {
	GhostTapping_obj *__this = (GhostTapping_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(GhostTapping_obj), true, "GhostTapping"));
	*(void **)__this = GhostTapping_obj::_hx_vtable;
	__this->__construct(x,y,__o_text,saveType,Callback);
	return __this;
}

GhostTapping_obj::GhostTapping_obj()
{
}

bool GhostTapping_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"ghostTap") ) { if (inCallProp == ::hx::paccAlways) { outValue = ( get_ghostTap() ); return true; } }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"consequence") ) { if (inCallProp == ::hx::paccAlways) { outValue = ( get_consequence() ); return true; } }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_ghostTap") ) { outValue = get_ghostTap_dyn(); return true; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"get_consequence") ) { outValue = get_consequence_dyn(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *GhostTapping_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *GhostTapping_obj_sStaticStorageInfo = 0;
#endif

::hx::Class GhostTapping_obj::__mClass;

static ::String GhostTapping_obj_sStaticFields[] = {
	HX_("get_consequence",1a,68,d7,83),
	HX_("get_ghostTap",5d,72,bc,82),
	::String(null())
};

void GhostTapping_obj::__register()
{
	GhostTapping_obj _hx_dummy;
	GhostTapping_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("GhostTapping",e6,b6,ec,d8);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &GhostTapping_obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(GhostTapping_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< GhostTapping_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = GhostTapping_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = GhostTapping_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

