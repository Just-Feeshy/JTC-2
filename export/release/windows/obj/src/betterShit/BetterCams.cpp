#include <hxcpp.h>

#ifndef INCLUDED_betterShit_BetterCams
#include <betterShit/BetterCams.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxCamera
#include <flixel/FlxCamera.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_math_FlxPoint
#include <flixel/math/FlxPoint.h>
#endif
#ifndef INCLUDED_flixel_system_scaleModes_BaseScaleMode
#include <flixel/system/scaleModes/BaseScaleMode.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxDestroyable
#include <flixel/util/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxPooled
#include <flixel/util/IFlxPooled.h>
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
#ifndef INCLUDED_openfl_filters_BitmapFilter
#include <openfl/filters/BitmapFilter.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_05a768f9f1f201fa_12_new,"betterShit.BetterCams","new",0xd42d5f84,"betterShit.BetterCams.new","betterShit/BetterCams.hx",12,0x98014fcb)
HX_LOCAL_STACK_FRAME(_hx_pos_05a768f9f1f201fa_33_lockFilter,"betterShit.BetterCams","lockFilter",0x51f9cf5f,"betterShit.BetterCams.lockFilter","betterShit/BetterCams.hx",33,0x98014fcb)
HX_LOCAL_STACK_FRAME(_hx_pos_05a768f9f1f201fa_38_eraseFilters,"betterShit.BetterCams","eraseFilters",0x662fd5d1,"betterShit.BetterCams.eraseFilters","betterShit/BetterCams.hx",38,0x98014fcb)
HX_LOCAL_STACK_FRAME(_hx_pos_05a768f9f1f201fa_43_get_getFilters,"betterShit.BetterCams","get_getFilters",0xf48beb6a,"betterShit.BetterCams.get_getFilters","betterShit/BetterCams.hx",43,0x98014fcb)
HX_LOCAL_STACK_FRAME(_hx_pos_05a768f9f1f201fa_53_set_engineX,"betterShit.BetterCams","set_engineX",0xe0153c9d,"betterShit.BetterCams.set_engineX","betterShit/BetterCams.hx",53,0x98014fcb)
HX_LOCAL_STACK_FRAME(_hx_pos_05a768f9f1f201fa_59_set_engineY,"betterShit.BetterCams","set_engineY",0xe0153c9e,"betterShit.BetterCams.set_engineY","betterShit/BetterCams.hx",59,0x98014fcb)
HX_LOCAL_STACK_FRAME(_hx_pos_05a768f9f1f201fa_68_set_engineAngle,"betterShit.BetterCams","set_engineAngle",0x8a18f678,"betterShit.BetterCams.set_engineAngle","betterShit/BetterCams.hx",68,0x98014fcb)
HX_LOCAL_STACK_FRAME(_hx_pos_05a768f9f1f201fa_74_set_angle,"betterShit.BetterCams","set_angle",0x5cd00e5a,"betterShit.BetterCams.set_angle","betterShit/BetterCams.hx",74,0x98014fcb)
HX_LOCAL_STACK_FRAME(_hx_pos_05a768f9f1f201fa_80_update,"betterShit.BetterCams","update",0x7e1b0565,"betterShit.BetterCams.update","betterShit/BetterCams.hx",80,0x98014fcb)
HX_LOCAL_STACK_FRAME(_hx_pos_05a768f9f1f201fa_88_destroy,"betterShit.BetterCams","destroy",0x60401e1e,"betterShit.BetterCams.destroy","betterShit/BetterCams.hx",88,0x98014fcb)
HX_LOCAL_STACK_FRAME(_hx_pos_05a768f9f1f201fa_95_updateFlashSpritePosition,"betterShit.BetterCams","updateFlashSpritePosition",0x83362939,"betterShit.BetterCams.updateFlashSpritePosition","betterShit/BetterCams.hx",95,0x98014fcb)
namespace betterShit{

void BetterCams_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_05a768f9f1f201fa_12_new)
HXLINE(  23)		this->engineAngle = ((Float)0);
HXLINE(  21)		this->engineY = ((Float)0);
HXLINE(  20)		this->engineX = ((Float)0);
HXLINE(  18)		this->betterFiltersEnabled = true;
HXLINE(  26)		this->lockedFilters = ::Array_obj< ::Dynamic>::__new();
HXLINE(  28)		this->filtersEnabled = false;
HXLINE(  30)		super::__construct(null(),null(),null(),null(),null());
            	}

Dynamic BetterCams_obj::__CreateEmpty() { return new BetterCams_obj; }

void *BetterCams_obj::_hx_vtable = 0;

Dynamic BetterCams_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< BetterCams_obj > _hx_result = new BetterCams_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool BetterCams_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x79a9d584) {
		if (inClassId<=(int)0x1ff7ce3b) {
			return inClassId==(int)0x00000001 || inClassId==(int)0x1ff7ce3b;
		} else {
			return inClassId==(int)0x79a9d584;
		}
	} else {
		return inClassId==(int)0x7ccf8994;
	}
}

void BetterCams_obj::lockFilter( ::openfl::filters::BitmapFilter filters){
            	HX_STACKFRAME(&_hx_pos_05a768f9f1f201fa_33_lockFilter)
HXLINE(  34)		this->lockedFilters->push(filters);
HXLINE(  35)		this->setFilters(this->get_getFilters());
            	}


HX_DEFINE_DYNAMIC_FUNC1(BetterCams_obj,lockFilter,(void))

void BetterCams_obj::eraseFilters(){
            	HX_STACKFRAME(&_hx_pos_05a768f9f1f201fa_38_eraseFilters)
HXLINE(  39)		this->lockedFilters = ::Array_obj< ::Dynamic>::__new(0);
HXLINE(  40)		this->setFilters(::Array_obj< ::Dynamic>::__new(0));
            	}


HX_DEFINE_DYNAMIC_FUNC0(BetterCams_obj,eraseFilters,(void))

::Array< ::Dynamic> BetterCams_obj::get_getFilters(){
            	HX_STACKFRAME(&_hx_pos_05a768f9f1f201fa_43_get_getFilters)
HXLINE(  44)		::Array< ::Dynamic> daFilters = this->_filters;
HXLINE(  46)		{
HXLINE(  46)			int _g = 0;
HXDLIN(  46)			int _g1 = this->lockedFilters->length;
HXDLIN(  46)			while((_g < _g1)){
HXLINE(  46)				_g = (_g + 1);
HXDLIN(  46)				int i = (_g - 1);
HXLINE(  47)				if (!(daFilters->contains(this->lockedFilters->__get(i).StaticCast<  ::openfl::filters::BitmapFilter >()))) {
HXLINE(  48)					daFilters->push(this->lockedFilters->__get(i).StaticCast<  ::openfl::filters::BitmapFilter >());
            				}
            			}
            		}
HXLINE(  50)		return daFilters;
            	}


HX_DEFINE_DYNAMIC_FUNC0(BetterCams_obj,get_getFilters,return )

Float BetterCams_obj::set_engineX(Float x){
            	HX_STACKFRAME(&_hx_pos_05a768f9f1f201fa_53_set_engineX)
HXLINE(  54)		this->engineX = x;
HXLINE(  55)		this->updateFlashSpritePosition();
HXLINE(  56)		return this->engineX;
            	}


HX_DEFINE_DYNAMIC_FUNC1(BetterCams_obj,set_engineX,return )

Float BetterCams_obj::set_engineY(Float y){
            	HX_STACKFRAME(&_hx_pos_05a768f9f1f201fa_59_set_engineY)
HXLINE(  60)		this->engineY = y;
HXLINE(  61)		this->updateFlashSpritePosition();
HXLINE(  62)		return this->engineY;
            	}


HX_DEFINE_DYNAMIC_FUNC1(BetterCams_obj,set_engineY,return )

Float BetterCams_obj::set_engineAngle(Float Angle){
            	HX_STACKFRAME(&_hx_pos_05a768f9f1f201fa_68_set_engineAngle)
HXLINE(  69)		this->engineAngle = Angle;
HXLINE(  70)		this->set_angle(this->angle);
HXLINE(  71)		return Angle;
            	}


HX_DEFINE_DYNAMIC_FUNC1(BetterCams_obj,set_engineAngle,return )

Float BetterCams_obj::set_angle(Float Angle){
            	HX_STACKFRAME(&_hx_pos_05a768f9f1f201fa_74_set_angle)
HXLINE(  75)		this->angle = Angle;
HXLINE(  76)		this->flashSprite->set_rotation((this->engineAngle + Angle));
HXLINE(  77)		return Angle;
            	}


void BetterCams_obj::update(Float elapsed){
            	HX_STACKFRAME(&_hx_pos_05a768f9f1f201fa_80_update)
HXLINE(  81)		this->filtersEnabled = false;
HXLINE(  83)		this->super::update(elapsed);
HXLINE(  85)		 ::openfl::display::Sprite _hx_tmp = this->flashSprite;
HXDLIN(  85)		::Array< ::Dynamic> _hx_tmp1;
HXDLIN(  85)		if (this->betterFiltersEnabled) {
HXLINE(  85)			_hx_tmp1 = this->get_getFilters();
            		}
            		else {
HXLINE(  85)			_hx_tmp1 = null();
            		}
HXDLIN(  85)		_hx_tmp->set_filters(_hx_tmp1);
            	}


void BetterCams_obj::destroy(){
            	HX_STACKFRAME(&_hx_pos_05a768f9f1f201fa_88_destroy)
HXLINE(  89)		this->super::destroy();
HXLINE(  91)		this->lockedFilters->removeRange(0,this->lockedFilters->length);
HXLINE(  92)		this->lockedFilters = null();
            	}


void BetterCams_obj::updateFlashSpritePosition(){
            	HX_STACKFRAME(&_hx_pos_05a768f9f1f201fa_95_updateFlashSpritePosition)
HXLINE(  96)		if (::hx::IsNotNull( this->flashSprite )) {
HXLINE(  97)			this->flashSprite->set_x((((this->x + this->engineX) * ::flixel::FlxG_obj::scaleMode->scale->x) + this->_flashOffset->x));
HXLINE(  98)			this->flashSprite->set_y((((this->y + this->engineY) * ::flixel::FlxG_obj::scaleMode->scale->y) + this->_flashOffset->y));
            		}
            	}



::hx::ObjectPtr< BetterCams_obj > BetterCams_obj::__new() {
	::hx::ObjectPtr< BetterCams_obj > __this = new BetterCams_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< BetterCams_obj > BetterCams_obj::__alloc(::hx::Ctx *_hx_ctx) {
	BetterCams_obj *__this = (BetterCams_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(BetterCams_obj), true, "betterShit.BetterCams"));
	*(void **)__this = BetterCams_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

BetterCams_obj::BetterCams_obj()
{
}

void BetterCams_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BetterCams);
	HX_MARK_MEMBER_NAME(lockedFilters,"lockedFilters");
	HX_MARK_MEMBER_NAME(betterFiltersEnabled,"betterFiltersEnabled");
	HX_MARK_MEMBER_NAME(engineX,"engineX");
	HX_MARK_MEMBER_NAME(engineY,"engineY");
	HX_MARK_MEMBER_NAME(engineAngle,"engineAngle");
	 ::flixel::FlxCamera_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void BetterCams_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(lockedFilters,"lockedFilters");
	HX_VISIT_MEMBER_NAME(betterFiltersEnabled,"betterFiltersEnabled");
	HX_VISIT_MEMBER_NAME(engineX,"engineX");
	HX_VISIT_MEMBER_NAME(engineY,"engineY");
	HX_VISIT_MEMBER_NAME(engineAngle,"engineAngle");
	 ::flixel::FlxCamera_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val BetterCams_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return ::hx::Val( update_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"engineX") ) { return ::hx::Val( engineX ); }
		if (HX_FIELD_EQ(inName,"engineY") ) { return ::hx::Val( engineY ); }
		if (HX_FIELD_EQ(inName,"destroy") ) { return ::hx::Val( destroy_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"set_angle") ) { return ::hx::Val( set_angle_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getFilters") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_getFilters() ); }
		if (HX_FIELD_EQ(inName,"lockFilter") ) { return ::hx::Val( lockFilter_dyn() ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"engineAngle") ) { return ::hx::Val( engineAngle ); }
		if (HX_FIELD_EQ(inName,"set_engineX") ) { return ::hx::Val( set_engineX_dyn() ); }
		if (HX_FIELD_EQ(inName,"set_engineY") ) { return ::hx::Val( set_engineY_dyn() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"eraseFilters") ) { return ::hx::Val( eraseFilters_dyn() ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"lockedFilters") ) { return ::hx::Val( lockedFilters ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_getFilters") ) { return ::hx::Val( get_getFilters_dyn() ); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"set_engineAngle") ) { return ::hx::Val( set_engineAngle_dyn() ); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"betterFiltersEnabled") ) { return ::hx::Val( betterFiltersEnabled ); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"updateFlashSpritePosition") ) { return ::hx::Val( updateFlashSpritePosition_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val BetterCams_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"engineX") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_engineX(inValue.Cast< Float >()) );engineX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"engineY") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_engineY(inValue.Cast< Float >()) );engineY=inValue.Cast< Float >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"engineAngle") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_engineAngle(inValue.Cast< Float >()) );engineAngle=inValue.Cast< Float >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"lockedFilters") ) { lockedFilters=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"betterFiltersEnabled") ) { betterFiltersEnabled=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BetterCams_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("getFilters",c5,27,a8,58));
	outFields->push(HX_("lockedFilters",d1,d9,e3,8b));
	outFields->push(HX_("betterFiltersEnabled",56,61,71,8d));
	outFields->push(HX_("engineX",56,82,3a,f7));
	outFields->push(HX_("engineY",57,82,3a,f7));
	outFields->push(HX_("engineAngle",b1,0c,e6,c2));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo BetterCams_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(BetterCams_obj,lockedFilters),HX_("lockedFilters",d1,d9,e3,8b)},
	{::hx::fsBool,(int)offsetof(BetterCams_obj,betterFiltersEnabled),HX_("betterFiltersEnabled",56,61,71,8d)},
	{::hx::fsFloat,(int)offsetof(BetterCams_obj,engineX),HX_("engineX",56,82,3a,f7)},
	{::hx::fsFloat,(int)offsetof(BetterCams_obj,engineY),HX_("engineY",57,82,3a,f7)},
	{::hx::fsFloat,(int)offsetof(BetterCams_obj,engineAngle),HX_("engineAngle",b1,0c,e6,c2)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *BetterCams_obj_sStaticStorageInfo = 0;
#endif

static ::String BetterCams_obj_sMemberFields[] = {
	HX_("lockedFilters",d1,d9,e3,8b),
	HX_("betterFiltersEnabled",56,61,71,8d),
	HX_("engineX",56,82,3a,f7),
	HX_("engineY",57,82,3a,f7),
	HX_("engineAngle",b1,0c,e6,c2),
	HX_("lockFilter",03,72,db,cf),
	HX_("eraseFilters",75,69,ba,59),
	HX_("get_getFilters",0e,b0,9d,ce),
	HX_("set_engineX",79,e9,a1,87),
	HX_("set_engineY",7a,e9,a1,87),
	HX_("set_engineAngle",54,41,93,7f),
	HX_("set_angle",36,8c,dc,49),
	HX_("update",09,86,05,87),
	HX_("destroy",fa,2c,86,24),
	HX_("updateFlashSpritePosition",15,1f,55,df),
	::String(null()) };

::hx::Class BetterCams_obj::__mClass;

void BetterCams_obj::__register()
{
	BetterCams_obj _hx_dummy;
	BetterCams_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("betterShit.BetterCams",92,8d,26,1a);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(BetterCams_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< BetterCams_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = BetterCams_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = BetterCams_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace betterShit
