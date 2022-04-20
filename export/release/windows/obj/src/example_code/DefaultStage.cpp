#include <hxcpp.h>

#ifndef INCLUDED_example_code_DefaultStage
#include <example_code/DefaultStage.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxDestroyable
#include <flixel/util/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_template_StageBuilder
#include <template/StageBuilder.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_95b33a292328d79f_7_new,"example_code.DefaultStage","new",0xfb11ff1b,"example_code.DefaultStage.new","example_code/DefaultStage.hx",7,0x444bc5d4)
HX_LOCAL_STACK_FRAME(_hx_pos_95b33a292328d79f_14_setMainGameStage,"example_code.DefaultStage","setMainGameStage",0x332c4156,"example_code.DefaultStage.setMainGameStage","example_code/DefaultStage.hx",14,0x444bc5d4)
namespace example_code{

void DefaultStage_obj::__construct(::String song){
            	HX_STACKFRAME(&_hx_pos_95b33a292328d79f_7_new)
HXDLIN(   7)		super::__construct(song);
            	}

Dynamic DefaultStage_obj::__CreateEmpty() { return new DefaultStage_obj; }

void *DefaultStage_obj::_hx_vtable = 0;

Dynamic DefaultStage_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< DefaultStage_obj > _hx_result = new DefaultStage_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool DefaultStage_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x296008c7) {
		if (inClassId<=(int)0x0b48a01f) {
			return inClassId==(int)0x00000001 || inClassId==(int)0x0b48a01f;
		} else {
			return inClassId==(int)0x296008c7;
		}
	} else {
		return inClassId==(int)0x7ccf8994;
	}
}

::String DefaultStage_obj::setMainGameStage(::String song){
            	HX_STACKFRAME(&_hx_pos_95b33a292328d79f_14_setMainGameStage)
HXDLIN(  14)		::String _hx_switch_0 = song.toLowerCase();
            		if (  (_hx_switch_0==HX_("cocoa",09,9d,55,4a)) ||  (_hx_switch_0==HX_("eggnog",61,04,ba,f4)) ){
HXLINE(  22)			return HX_("mall",d4,3a,56,48);
HXDLIN(  22)			goto _hx_goto_1;
            		}
            		if (  (_hx_switch_0==HX_("monster",1a,54,b0,b8)) ||  (_hx_switch_0==HX_("south",0d,92,cc,80)) ||  (_hx_switch_0==HX_("spookeez",0c,7a,2b,75)) ){
HXLINE(  16)			return HX_("spooky",eb,bd,9e,c1);
HXDLIN(  16)			goto _hx_goto_1;
            		}
            		if (  (_hx_switch_0==HX_("blammed",96,02,00,3c)) ||  (_hx_switch_0==HX_("philly",28,77,5e,ef)) ||  (_hx_switch_0==HX_("pico",e5,e8,57,4a)) ){
HXLINE(  18)			return HX_("philly",28,77,5e,ef);
HXDLIN(  18)			goto _hx_goto_1;
            		}
            		if (  (_hx_switch_0==HX_("high",62,37,0e,45)) ||  (_hx_switch_0==HX_("milf",d6,4c,5c,48)) ||  (_hx_switch_0==HX_("satin-panties",fe,64,00,d1)) ){
HXLINE(  20)			return HX_("limo",1f,17,b3,47);
HXDLIN(  20)			goto _hx_goto_1;
            		}
            		if (  (_hx_switch_0==HX_("roses",04,6c,64,ed)) ||  (_hx_switch_0==HX_("senpai",3c,df,8d,6b)) ){
HXLINE(  26)			return HX_("school",74,b8,c8,40);
HXDLIN(  26)			goto _hx_goto_1;
            		}
            		if (  (_hx_switch_0==HX_("thorns",9c,bf,c7,8c)) ){
HXLINE(  28)			return HX_("schoolEvil",28,a1,f5,f7);
HXDLIN(  28)			goto _hx_goto_1;
            		}
            		if (  (_hx_switch_0==HX_("winter-horrorland",9d,39,f4,1e)) ){
HXLINE(  24)			return HX_("mallEvil",88,d3,e3,a7);
HXDLIN(  24)			goto _hx_goto_1;
            		}
            		/* default */{
HXLINE(  30)			return HX_("stage",be,6a,0b,84);
            		}
            		_hx_goto_1:;
HXLINE(  14)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(DefaultStage_obj,setMainGameStage,return )


::hx::ObjectPtr< DefaultStage_obj > DefaultStage_obj::__new(::String song) {
	::hx::ObjectPtr< DefaultStage_obj > __this = new DefaultStage_obj();
	__this->__construct(song);
	return __this;
}

::hx::ObjectPtr< DefaultStage_obj > DefaultStage_obj::__alloc(::hx::Ctx *_hx_ctx,::String song) {
	DefaultStage_obj *__this = (DefaultStage_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(DefaultStage_obj), true, "example_code.DefaultStage"));
	*(void **)__this = DefaultStage_obj::_hx_vtable;
	__this->__construct(song);
	return __this;
}

DefaultStage_obj::DefaultStage_obj()
{
}

bool DefaultStage_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 16:
		if (HX_FIELD_EQ(inName,"setMainGameStage") ) { outValue = setMainGameStage_dyn(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *DefaultStage_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *DefaultStage_obj_sStaticStorageInfo = 0;
#endif

::hx::Class DefaultStage_obj::__mClass;

static ::String DefaultStage_obj_sStaticFields[] = {
	HX_("setMainGameStage",f1,48,13,33),
	::String(null())
};

void DefaultStage_obj::__register()
{
	DefaultStage_obj _hx_dummy;
	DefaultStage_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("example_code.DefaultStage",a9,d5,8f,40);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &DefaultStage_obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(DefaultStage_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< DefaultStage_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = DefaultStage_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = DefaultStage_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace example_code
