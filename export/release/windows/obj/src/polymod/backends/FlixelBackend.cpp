#include <hxcpp.h>

#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_BitmapFrontEnd
#include <flixel/system/frontEnds/BitmapFrontEnd.h>
#endif
#ifndef INCLUDED_openfl_utils_Assets
#include <openfl/utils/Assets.h>
#endif
#ifndef INCLUDED_openfl_utils_IAssetCache
#include <openfl/utils/IAssetCache.h>
#endif
#ifndef INCLUDED_polymod_Polymod
#include <polymod/Polymod.h>
#endif
#ifndef INCLUDED_polymod_backends_FlixelBackend
#include <polymod/backends/FlixelBackend.h>
#endif
#ifndef INCLUDED_polymod_backends_IBackend
#include <polymod/backends/IBackend.h>
#endif
#ifndef INCLUDED_polymod_backends_LimeBackend
#include <polymod/backends/LimeBackend.h>
#endif
#ifndef INCLUDED_polymod_backends_OpenFLBackend
#include <polymod/backends/OpenFLBackend.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_25c02a9b4a4d1d66_23_new,"polymod.backends.FlixelBackend","new",0xf1013513,"polymod.backends.FlixelBackend.new","polymod/backends/FlixelBackend.hx",23,0xa9a7859d)
HX_LOCAL_STACK_FRAME(_hx_pos_25c02a9b4a4d1d66_34_clearCache,"polymod.backends.FlixelBackend","clearCache",0xf7ebc122,"polymod.backends.FlixelBackend.clearCache","polymod/backends/FlixelBackend.hx",34,0xa9a7859d)
HX_LOCAL_STACK_FRAME(_hx_pos_25c02a9b4a4d1d66_78_destroy,"polymod.backends.FlixelBackend","destroy",0x926f672d,"polymod.backends.FlixelBackend.destroy","polymod/backends/FlixelBackend.hx",78,0xa9a7859d)
namespace polymod{
namespace backends{

void FlixelBackend_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_25c02a9b4a4d1d66_23_new)
HXLINE(  24)		super::__construct();
HXLINE(  25)		::polymod::Polymod_obj::debug(HX_("Initialized Flixel backend.",92,68,b4,08),::hx::SourceInfo(HX_("polymod/backends/FlixelBackend.hx",9d,85,a7,a9),25,HX_("polymod.backends.FlixelBackend",a1,af,3e,08),HX_("new",60,d0,53,00)));
            	}

Dynamic FlixelBackend_obj::__CreateEmpty() { return new FlixelBackend_obj; }

void *FlixelBackend_obj::_hx_vtable = 0;

Dynamic FlixelBackend_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< FlixelBackend_obj > _hx_result = new FlixelBackend_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool FlixelBackend_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x12bf7dcf) {
		if (inClassId<=(int)0x0065a5e7) {
			return inClassId==(int)0x00000001 || inClassId==(int)0x0065a5e7;
		} else {
			return inClassId==(int)0x12bf7dcf;
		}
	} else {
		return inClassId==(int)0x7a28a88e;
	}
}

void FlixelBackend_obj::clearCache(){
            	HX_STACKFRAME(&_hx_pos_25c02a9b4a4d1d66_34_clearCache)
HXLINE(  35)		::polymod::Polymod_obj::notice(HX_("functionality_not_implemented",e2,d8,5e,2f),(HX_("Watch out, the Flixel backend's clearCache function kinda sucks. ",27,46,f0,89) + HX_("Ideally you should just disable Flixel's caching and manage everything yourself.",99,1c,90,37)),null());
HXLINE(  57)		::Array< ::String > bitmapsToClear = ::openfl::utils::Assets_obj::list(HX_("IMAGE",3b,57,57,3b));
HXLINE(  58)		::polymod::Polymod_obj::debug((HX_("Known image keys: ",9c,75,8e,3a) + bitmapsToClear->length),::hx::SourceInfo(HX_("polymod/backends/FlixelBackend.hx",9d,85,a7,a9),58,HX_("polymod.backends.FlixelBackend",a1,af,3e,08),HX_("clearCache",75,d9,1e,16)));
HXLINE(  59)		int count = 0;
HXLINE(  60)		{
HXLINE(  60)			int _g = 0;
HXDLIN(  60)			while((_g < bitmapsToClear->length)){
HXLINE(  60)				::String key = bitmapsToClear->__get(_g);
HXDLIN(  60)				_g = (_g + 1);
HXLINE(  63)				::flixel::FlxG_obj::bitmap->removeByKey(key);
HXLINE(  65)				::openfl::utils::IAssetCache_obj::removeBitmapData(::openfl::utils::Assets_obj::cache,key);
            			}
            		}
HXLINE(  67)		::polymod::Polymod_obj::debug(((HX_("Cleared ",94,fb,d2,0a) + count) + HX_(" items from Flixel bitmap cache.",4f,b9,98,0c)),::hx::SourceInfo(HX_("polymod/backends/FlixelBackend.hx",9d,85,a7,a9),67,HX_("polymod.backends.FlixelBackend",a1,af,3e,08),HX_("clearCache",75,d9,1e,16)));
HXLINE(  70)		this->super::clearCache();
            	}


void FlixelBackend_obj::destroy(){
            	HX_STACKFRAME(&_hx_pos_25c02a9b4a4d1d66_78_destroy)
HXLINE(  80)		this->clearCache();
HXLINE(  81)		this->super::destroy();
            	}



::hx::ObjectPtr< FlixelBackend_obj > FlixelBackend_obj::__new() {
	::hx::ObjectPtr< FlixelBackend_obj > __this = new FlixelBackend_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< FlixelBackend_obj > FlixelBackend_obj::__alloc(::hx::Ctx *_hx_ctx) {
	FlixelBackend_obj *__this = (FlixelBackend_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(FlixelBackend_obj), true, "polymod.backends.FlixelBackend"));
	*(void **)__this = FlixelBackend_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

FlixelBackend_obj::FlixelBackend_obj()
{
}

::hx::Val FlixelBackend_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return ::hx::Val( destroy_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"clearCache") ) { return ::hx::Val( clearCache_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *FlixelBackend_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *FlixelBackend_obj_sStaticStorageInfo = 0;
#endif

static ::String FlixelBackend_obj_sMemberFields[] = {
	HX_("clearCache",75,d9,1e,16),
	HX_("destroy",fa,2c,86,24),
	::String(null()) };

::hx::Class FlixelBackend_obj::__mClass;

void FlixelBackend_obj::__register()
{
	FlixelBackend_obj _hx_dummy;
	FlixelBackend_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("polymod.backends.FlixelBackend",a1,af,3e,08);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(FlixelBackend_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< FlixelBackend_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = FlixelBackend_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = FlixelBackend_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace polymod
} // end namespace backends
