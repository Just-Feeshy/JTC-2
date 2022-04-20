#include <hxcpp.h>

#ifndef INCLUDED_Lambda
#include <Lambda.h>
#endif
#ifndef INCLUDED_MenuBackground
#include <MenuBackground.h>
#endif
#ifndef INCLUDED_Paths
#include <Paths.h>
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
#ifndef INCLUDED_flixel_FlxObject
#include <flixel/FlxObject.h>
#endif
#ifndef INCLUDED_flixel_FlxSprite
#include <flixel/FlxSprite.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedSpriteGroup
#include <flixel/group/FlxTypedSpriteGroup.h>
#endif
#ifndef INCLUDED_flixel_tweens_FlxEase
#include <flixel/tweens/FlxEase.h>
#endif
#ifndef INCLUDED_flixel_tweens_FlxTween
#include <flixel/tweens/FlxTween.h>
#endif
#ifndef INCLUDED_flixel_tweens_misc_VarTween
#include <flixel/tweens/misc/VarTween.h>
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

HX_DEFINE_STACK_FRAME(_hx_pos_a9b3000076e6615b_9_new,"MenuBackground","new",0x9244b9ff,"MenuBackground.new","MenuBackground.hx",9,0xd070ca51)
HX_LOCAL_STACK_FRAME(_hx_pos_a9b3000076e6615b_29_changeBackground,"MenuBackground","changeBackground",0x5567947f,"MenuBackground.changeBackground","MenuBackground.hx",29,0xd070ca51)

void MenuBackground_obj::__construct(Float x,Float y){
            	HX_GC_STACKFRAME(&_hx_pos_a9b3000076e6615b_9_new)
HXLINE(  10)		this->sway = ((Float)0);
HXLINE(  13)		super::__construct(x,y,null());
HXLINE(  15)		{
HXLINE(  15)			int _g = 0;
HXDLIN(  15)			int _g1 = ::Lambda_obj::count(::Paths_obj::get_modJSON()->__Field(HX_("weeks",ff,95,be,c7),::hx::paccDynamic),null());
HXDLIN(  15)			while((_g < _g1)){
HXLINE(  15)				_g = (_g + 1);
HXDLIN(  15)				int i = (_g - 1);
HXLINE(  16)				 ::flixel::FlxSprite bg =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,null(),null(),null());
HXDLIN(  16)				 ::flixel::FlxSprite bg1 = bg->loadGraphic(::Paths_obj::image(( (::String)(( ( ::haxe::ds::StringMap)( ::Dynamic(::Paths_obj::get_modJSON()->__Field(HX_("weeks",ff,95,be,c7),::hx::paccDynamic))) )->get((HX_("week_",eb,95,be,c7) + i))->__Field(HX_("week_background",99,dd,f4,07),::hx::paccDynamic)) ),null()),null(),null(),null(),null(),null());
HXLINE(  17)				int _hx_tmp = ::Std_obj::_hx_int((( (Float)(::flixel::FlxG_obj::width) ) * ((Float)1.02)));
HXDLIN(  17)				bg1->setGraphicSize(_hx_tmp,::Std_obj::_hx_int((( (Float)(::flixel::FlxG_obj::height) ) * ((Float)1.02))));
HXLINE(  18)				bg1->updateHitbox();
HXLINE(  20)				if ((i > 0)) {
HXLINE(  21)					bg1->set_alpha(( (Float)(0) ));
            				}
HXLINE(  23)				bg1->ID = i;
HXLINE(  25)				this->add(bg1);
            			}
            		}
            	}

Dynamic MenuBackground_obj::__CreateEmpty() { return new MenuBackground_obj; }

void *MenuBackground_obj::_hx_vtable = 0;

Dynamic MenuBackground_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< MenuBackground_obj > _hx_result = new MenuBackground_obj();
	_hx_result->__construct(inArgs[0],inArgs[1]);
	return _hx_result;
}

bool MenuBackground_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x37b5d14d) {
		if (inClassId<=(int)0x2c01639b) {
			if (inClassId<=(int)0x288ce903) {
				return inClassId==(int)0x00000001 || inClassId==(int)0x288ce903;
			} else {
				return inClassId==(int)0x2c01639b;
			}
		} else {
			return inClassId==(int)0x37b5d14d;
		}
	} else {
		return inClassId==(int)0x7ccf8994 || inClassId==(int)0x7dab0655;
	}
}

void MenuBackground_obj::changeBackground(int selected,int change){
            	HX_STACKFRAME(&_hx_pos_a9b3000076e6615b_29_changeBackground)
HXLINE(  30)		int prevSelected = (selected - change);
HXLINE(  32)		if ((prevSelected > ::Lambda_obj::count(::Paths_obj::get_modJSON()->__Field(HX_("weeks",ff,95,be,c7),::hx::paccDynamic),null()))) {
HXLINE(  33)			prevSelected = 0;
            		}
HXLINE(  34)		if ((prevSelected < 0)) {
HXLINE(  35)			prevSelected = ::Lambda_obj::count(::Paths_obj::get_modJSON()->__Field(HX_("weeks",ff,95,be,c7),::hx::paccDynamic),null());
            		}
HXLINE(  37)		{
HXLINE(  37)			int _g = 0;
HXDLIN(  37)			int _g1 = ::Lambda_obj::count(::Paths_obj::get_modJSON()->__Field(HX_("weeks",ff,95,be,c7),::hx::paccDynamic),null());
HXDLIN(  37)			while((_g < _g1)){
HXLINE(  37)				_g = (_g + 1);
HXDLIN(  37)				int i = (_g - 1);
HXLINE(  38)				if ((change >= 1)) {
HXLINE(  39)					bool _hx_tmp;
HXDLIN(  39)					if ((Dynamic( this->group->members->__get(i)).StaticCast<  ::flixel::FlxSprite >()->ID != prevSelected)) {
HXLINE(  39)						_hx_tmp = (Dynamic( this->group->members->__get(i)).StaticCast<  ::flixel::FlxSprite >()->ID != selected);
            					}
            					else {
HXLINE(  39)						_hx_tmp = false;
            					}
HXDLIN(  39)					if (_hx_tmp) {
HXLINE(  40)						Dynamic( this->group->members->__get(i)).StaticCast<  ::flixel::FlxSprite >()->set_alpha(( (Float)(0) ));
            					}
HXLINE(  41)					if ((Dynamic( this->group->members->__get(i)).StaticCast<  ::flixel::FlxSprite >()->ID == selected)) {
HXLINE(  42)						::flixel::tweens::FlxTween_obj::tween(Dynamic( this->group->members->__get(i)).StaticCast<  ::flixel::FlxSprite >(), ::Dynamic(::hx::Anon_obj::Create(1)
            							->setFixed(0,HX_("alpha",5e,a7,96,21),1)),((Float)0.3), ::Dynamic(::hx::Anon_obj::Create(1)
            							->setFixed(0,HX_("ease",ee,8b,0c,43),::flixel::tweens::FlxEase_obj::quadOut_dyn())));
            					}
            				}
            				else {
HXLINE(  43)					if ((change <= -1)) {
HXLINE(  44)						bool _hx_tmp;
HXDLIN(  44)						if ((Dynamic( this->group->members->__get(i)).StaticCast<  ::flixel::FlxSprite >()->ID != prevSelected)) {
HXLINE(  44)							_hx_tmp = (Dynamic( this->group->members->__get(i)).StaticCast<  ::flixel::FlxSprite >()->ID != selected);
            						}
            						else {
HXLINE(  44)							_hx_tmp = false;
            						}
HXDLIN(  44)						if (_hx_tmp) {
HXLINE(  45)							Dynamic( this->group->members->__get(i)).StaticCast<  ::flixel::FlxSprite >()->set_alpha(( (Float)(0) ));
            						}
            						else {
HXLINE(  46)							if ((Dynamic( this->group->members->__get(i)).StaticCast<  ::flixel::FlxSprite >()->ID == selected)) {
HXLINE(  47)								Dynamic( this->group->members->__get(i)).StaticCast<  ::flixel::FlxSprite >()->set_alpha(( (Float)(1) ));
            							}
            						}
HXLINE(  49)						if ((Dynamic( this->group->members->__get(i)).StaticCast<  ::flixel::FlxSprite >()->ID == prevSelected)) {
HXLINE(  50)							::flixel::tweens::FlxTween_obj::tween(Dynamic( this->group->members->__get(i)).StaticCast<  ::flixel::FlxSprite >(), ::Dynamic(::hx::Anon_obj::Create(1)
            								->setFixed(0,HX_("alpha",5e,a7,96,21),0)),((Float)0.3), ::Dynamic(::hx::Anon_obj::Create(1)
            								->setFixed(0,HX_("ease",ee,8b,0c,43),::flixel::tweens::FlxEase_obj::quadOut_dyn())));
            						}
            					}
            				}
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC2(MenuBackground_obj,changeBackground,(void))


::hx::ObjectPtr< MenuBackground_obj > MenuBackground_obj::__new(Float x,Float y) {
	::hx::ObjectPtr< MenuBackground_obj > __this = new MenuBackground_obj();
	__this->__construct(x,y);
	return __this;
}

::hx::ObjectPtr< MenuBackground_obj > MenuBackground_obj::__alloc(::hx::Ctx *_hx_ctx,Float x,Float y) {
	MenuBackground_obj *__this = (MenuBackground_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(MenuBackground_obj), true, "MenuBackground"));
	*(void **)__this = MenuBackground_obj::_hx_vtable;
	__this->__construct(x,y);
	return __this;
}

MenuBackground_obj::MenuBackground_obj()
{
}

::hx::Val MenuBackground_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"sway") ) { return ::hx::Val( sway ); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"changeBackground") ) { return ::hx::Val( changeBackground_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val MenuBackground_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"sway") ) { sway=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void MenuBackground_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("sway",9c,2a,5e,4c));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo MenuBackground_obj_sMemberStorageInfo[] = {
	{::hx::fsFloat,(int)offsetof(MenuBackground_obj,sway),HX_("sway",9c,2a,5e,4c)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *MenuBackground_obj_sStaticStorageInfo = 0;
#endif

static ::String MenuBackground_obj_sMemberFields[] = {
	HX_("sway",9c,2a,5e,4c),
	HX_("changeBackground",7e,55,cf,b2),
	::String(null()) };

::hx::Class MenuBackground_obj::__mClass;

void MenuBackground_obj::__register()
{
	MenuBackground_obj _hx_dummy;
	MenuBackground_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("MenuBackground",8d,4e,ca,55);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(MenuBackground_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< MenuBackground_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = MenuBackground_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = MenuBackground_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

