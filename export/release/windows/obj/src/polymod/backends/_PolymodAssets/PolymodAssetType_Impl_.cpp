#include <hxcpp.h>

#ifndef INCLUDED_polymod_backends__PolymodAssets_PolymodAssetType_Impl_
#include <polymod/backends/_PolymodAssets/PolymodAssetType_Impl_.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_f18b9fd15d26d526_235_fromString,"polymod.backends._PolymodAssets.PolymodAssetType_Impl_","fromString",0xa9047b18,"polymod.backends._PolymodAssets.PolymodAssetType_Impl_.fromString","polymod/backends/PolymodAssets.hx",235,0xd8b6783c)
HX_LOCAL_STACK_FRAME(_hx_pos_f18b9fd15d26d526_222_boot,"polymod.backends._PolymodAssets.PolymodAssetType_Impl_","boot",0x35ee15af,"polymod.backends._PolymodAssets.PolymodAssetType_Impl_.boot","polymod/backends/PolymodAssets.hx",222,0xd8b6783c)
HX_LOCAL_STACK_FRAME(_hx_pos_f18b9fd15d26d526_223_boot,"polymod.backends._PolymodAssets.PolymodAssetType_Impl_","boot",0x35ee15af,"polymod.backends._PolymodAssets.PolymodAssetType_Impl_.boot","polymod/backends/PolymodAssets.hx",223,0xd8b6783c)
HX_LOCAL_STACK_FRAME(_hx_pos_f18b9fd15d26d526_224_boot,"polymod.backends._PolymodAssets.PolymodAssetType_Impl_","boot",0x35ee15af,"polymod.backends._PolymodAssets.PolymodAssetType_Impl_.boot","polymod/backends/PolymodAssets.hx",224,0xd8b6783c)
HX_LOCAL_STACK_FRAME(_hx_pos_f18b9fd15d26d526_225_boot,"polymod.backends._PolymodAssets.PolymodAssetType_Impl_","boot",0x35ee15af,"polymod.backends._PolymodAssets.PolymodAssetType_Impl_.boot","polymod/backends/PolymodAssets.hx",225,0xd8b6783c)
HX_LOCAL_STACK_FRAME(_hx_pos_f18b9fd15d26d526_226_boot,"polymod.backends._PolymodAssets.PolymodAssetType_Impl_","boot",0x35ee15af,"polymod.backends._PolymodAssets.PolymodAssetType_Impl_.boot","polymod/backends/PolymodAssets.hx",226,0xd8b6783c)
HX_LOCAL_STACK_FRAME(_hx_pos_f18b9fd15d26d526_227_boot,"polymod.backends._PolymodAssets.PolymodAssetType_Impl_","boot",0x35ee15af,"polymod.backends._PolymodAssets.PolymodAssetType_Impl_.boot","polymod/backends/PolymodAssets.hx",227,0xd8b6783c)
HX_LOCAL_STACK_FRAME(_hx_pos_f18b9fd15d26d526_228_boot,"polymod.backends._PolymodAssets.PolymodAssetType_Impl_","boot",0x35ee15af,"polymod.backends._PolymodAssets.PolymodAssetType_Impl_.boot","polymod/backends/PolymodAssets.hx",228,0xd8b6783c)
HX_LOCAL_STACK_FRAME(_hx_pos_f18b9fd15d26d526_229_boot,"polymod.backends._PolymodAssets.PolymodAssetType_Impl_","boot",0x35ee15af,"polymod.backends._PolymodAssets.PolymodAssetType_Impl_.boot","polymod/backends/PolymodAssets.hx",229,0xd8b6783c)
HX_LOCAL_STACK_FRAME(_hx_pos_f18b9fd15d26d526_230_boot,"polymod.backends._PolymodAssets.PolymodAssetType_Impl_","boot",0x35ee15af,"polymod.backends._PolymodAssets.PolymodAssetType_Impl_.boot","polymod/backends/PolymodAssets.hx",230,0xd8b6783c)
HX_LOCAL_STACK_FRAME(_hx_pos_f18b9fd15d26d526_231_boot,"polymod.backends._PolymodAssets.PolymodAssetType_Impl_","boot",0x35ee15af,"polymod.backends._PolymodAssets.PolymodAssetType_Impl_.boot","polymod/backends/PolymodAssets.hx",231,0xd8b6783c)
HX_LOCAL_STACK_FRAME(_hx_pos_f18b9fd15d26d526_232_boot,"polymod.backends._PolymodAssets.PolymodAssetType_Impl_","boot",0x35ee15af,"polymod.backends._PolymodAssets.PolymodAssetType_Impl_.boot","polymod/backends/PolymodAssets.hx",232,0xd8b6783c)
namespace polymod{
namespace backends{
namespace _PolymodAssets{

void PolymodAssetType_Impl__obj::__construct() { }

Dynamic PolymodAssetType_Impl__obj::__CreateEmpty() { return new PolymodAssetType_Impl__obj; }

void *PolymodAssetType_Impl__obj::_hx_vtable = 0;

Dynamic PolymodAssetType_Impl__obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< PolymodAssetType_Impl__obj > _hx_result = new PolymodAssetType_Impl__obj();
	_hx_result->__construct();
	return _hx_result;
}

bool PolymodAssetType_Impl__obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x058f3cc3;
}

::String PolymodAssetType_Impl__obj::BYTES;

::String PolymodAssetType_Impl__obj::TEXT;

::String PolymodAssetType_Impl__obj::IMAGE;

::String PolymodAssetType_Impl__obj::VIDEO;

::String PolymodAssetType_Impl__obj::FONT;

::String PolymodAssetType_Impl__obj::AUDIO_GENERIC;

::String PolymodAssetType_Impl__obj::AUDIO_MUSIC;

::String PolymodAssetType_Impl__obj::AUDIO_SOUND;

::String PolymodAssetType_Impl__obj::MANIFEST;

::String PolymodAssetType_Impl__obj::TEMPLATE;

::String PolymodAssetType_Impl__obj::UNKNOWN;

::String PolymodAssetType_Impl__obj::fromString(::String str){
            	HX_STACKFRAME(&_hx_pos_f18b9fd15d26d526_235_fromString)
HXLINE( 236)		str = str.toUpperCase();
HXLINE( 237)		::String _hx_switch_0 = str;
            		if (  (_hx_switch_0==HX_("AUDIO_GENERIC",2e,f6,26,23)) ||  (_hx_switch_0==HX_("AUDIO_MUSIC",fc,6c,05,48)) ||  (_hx_switch_0==HX_("AUDIO_SOUND",26,29,77,b8)) ||  (_hx_switch_0==HX_("BYTES",4b,40,86,3b)) ||  (_hx_switch_0==HX_("FONT",cf,25,81,2e)) ||  (_hx_switch_0==HX_("IMAGE",3b,57,57,3b)) ||  (_hx_switch_0==HX_("MANIFEST",af,8b,af,29)) ||  (_hx_switch_0==HX_("TEMPLATE",3a,78,cd,05)) ||  (_hx_switch_0==HX_("TEXT",ad,94,ba,37)) ||  (_hx_switch_0==HX_("UNKNOWN",6a,f7,4e,61)) ||  (_hx_switch_0==HX_("VIDEO",5b,4c,ea,b4)) ){
HXLINE( 240)			return str;
HXDLIN( 240)			goto _hx_goto_0;
            		}
            		/* default */{
HXLINE( 242)			return HX_("UNKNOWN",6a,f7,4e,61);
            		}
            		_hx_goto_0:;
HXLINE( 237)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(PolymodAssetType_Impl__obj,fromString,return )


PolymodAssetType_Impl__obj::PolymodAssetType_Impl__obj()
{
}

bool PolymodAssetType_Impl__obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"fromString") ) { outValue = fromString_dyn(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *PolymodAssetType_Impl__obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo PolymodAssetType_Impl__obj_sStaticStorageInfo[] = {
	{::hx::fsString,(void *) &PolymodAssetType_Impl__obj::BYTES,HX_("BYTES",4b,40,86,3b)},
	{::hx::fsString,(void *) &PolymodAssetType_Impl__obj::TEXT,HX_("TEXT",ad,94,ba,37)},
	{::hx::fsString,(void *) &PolymodAssetType_Impl__obj::IMAGE,HX_("IMAGE",3b,57,57,3b)},
	{::hx::fsString,(void *) &PolymodAssetType_Impl__obj::VIDEO,HX_("VIDEO",5b,4c,ea,b4)},
	{::hx::fsString,(void *) &PolymodAssetType_Impl__obj::FONT,HX_("FONT",cf,25,81,2e)},
	{::hx::fsString,(void *) &PolymodAssetType_Impl__obj::AUDIO_GENERIC,HX_("AUDIO_GENERIC",2e,f6,26,23)},
	{::hx::fsString,(void *) &PolymodAssetType_Impl__obj::AUDIO_MUSIC,HX_("AUDIO_MUSIC",fc,6c,05,48)},
	{::hx::fsString,(void *) &PolymodAssetType_Impl__obj::AUDIO_SOUND,HX_("AUDIO_SOUND",26,29,77,b8)},
	{::hx::fsString,(void *) &PolymodAssetType_Impl__obj::MANIFEST,HX_("MANIFEST",af,8b,af,29)},
	{::hx::fsString,(void *) &PolymodAssetType_Impl__obj::TEMPLATE,HX_("TEMPLATE",3a,78,cd,05)},
	{::hx::fsString,(void *) &PolymodAssetType_Impl__obj::UNKNOWN,HX_("UNKNOWN",6a,f7,4e,61)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static void PolymodAssetType_Impl__obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PolymodAssetType_Impl__obj::BYTES,"BYTES");
	HX_MARK_MEMBER_NAME(PolymodAssetType_Impl__obj::TEXT,"TEXT");
	HX_MARK_MEMBER_NAME(PolymodAssetType_Impl__obj::IMAGE,"IMAGE");
	HX_MARK_MEMBER_NAME(PolymodAssetType_Impl__obj::VIDEO,"VIDEO");
	HX_MARK_MEMBER_NAME(PolymodAssetType_Impl__obj::FONT,"FONT");
	HX_MARK_MEMBER_NAME(PolymodAssetType_Impl__obj::AUDIO_GENERIC,"AUDIO_GENERIC");
	HX_MARK_MEMBER_NAME(PolymodAssetType_Impl__obj::AUDIO_MUSIC,"AUDIO_MUSIC");
	HX_MARK_MEMBER_NAME(PolymodAssetType_Impl__obj::AUDIO_SOUND,"AUDIO_SOUND");
	HX_MARK_MEMBER_NAME(PolymodAssetType_Impl__obj::MANIFEST,"MANIFEST");
	HX_MARK_MEMBER_NAME(PolymodAssetType_Impl__obj::TEMPLATE,"TEMPLATE");
	HX_MARK_MEMBER_NAME(PolymodAssetType_Impl__obj::UNKNOWN,"UNKNOWN");
};

#ifdef HXCPP_VISIT_ALLOCS
static void PolymodAssetType_Impl__obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PolymodAssetType_Impl__obj::BYTES,"BYTES");
	HX_VISIT_MEMBER_NAME(PolymodAssetType_Impl__obj::TEXT,"TEXT");
	HX_VISIT_MEMBER_NAME(PolymodAssetType_Impl__obj::IMAGE,"IMAGE");
	HX_VISIT_MEMBER_NAME(PolymodAssetType_Impl__obj::VIDEO,"VIDEO");
	HX_VISIT_MEMBER_NAME(PolymodAssetType_Impl__obj::FONT,"FONT");
	HX_VISIT_MEMBER_NAME(PolymodAssetType_Impl__obj::AUDIO_GENERIC,"AUDIO_GENERIC");
	HX_VISIT_MEMBER_NAME(PolymodAssetType_Impl__obj::AUDIO_MUSIC,"AUDIO_MUSIC");
	HX_VISIT_MEMBER_NAME(PolymodAssetType_Impl__obj::AUDIO_SOUND,"AUDIO_SOUND");
	HX_VISIT_MEMBER_NAME(PolymodAssetType_Impl__obj::MANIFEST,"MANIFEST");
	HX_VISIT_MEMBER_NAME(PolymodAssetType_Impl__obj::TEMPLATE,"TEMPLATE");
	HX_VISIT_MEMBER_NAME(PolymodAssetType_Impl__obj::UNKNOWN,"UNKNOWN");
};

#endif

::hx::Class PolymodAssetType_Impl__obj::__mClass;

static ::String PolymodAssetType_Impl__obj_sStaticFields[] = {
	HX_("BYTES",4b,40,86,3b),
	HX_("TEXT",ad,94,ba,37),
	HX_("IMAGE",3b,57,57,3b),
	HX_("VIDEO",5b,4c,ea,b4),
	HX_("FONT",cf,25,81,2e),
	HX_("AUDIO_GENERIC",2e,f6,26,23),
	HX_("AUDIO_MUSIC",fc,6c,05,48),
	HX_("AUDIO_SOUND",26,29,77,b8),
	HX_("MANIFEST",af,8b,af,29),
	HX_("TEMPLATE",3a,78,cd,05),
	HX_("UNKNOWN",6a,f7,4e,61),
	HX_("fromString",db,2d,74,54),
	::String(null())
};

void PolymodAssetType_Impl__obj::__register()
{
	PolymodAssetType_Impl__obj _hx_dummy;
	PolymodAssetType_Impl__obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("polymod.backends._PolymodAssets.PolymodAssetType_Impl_",11,40,a5,34);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &PolymodAssetType_Impl__obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mMarkFunc = PolymodAssetType_Impl__obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(PolymodAssetType_Impl__obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< PolymodAssetType_Impl__obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = PolymodAssetType_Impl__obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = PolymodAssetType_Impl__obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = PolymodAssetType_Impl__obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void PolymodAssetType_Impl__obj::__boot()
{
{
            	HX_STACKFRAME(&_hx_pos_f18b9fd15d26d526_222_boot)
HXDLIN( 222)		BYTES = HX_("BYTES",4b,40,86,3b);
            	}
{
            	HX_STACKFRAME(&_hx_pos_f18b9fd15d26d526_223_boot)
HXDLIN( 223)		TEXT = HX_("TEXT",ad,94,ba,37);
            	}
{
            	HX_STACKFRAME(&_hx_pos_f18b9fd15d26d526_224_boot)
HXDLIN( 224)		IMAGE = HX_("IMAGE",3b,57,57,3b);
            	}
{
            	HX_STACKFRAME(&_hx_pos_f18b9fd15d26d526_225_boot)
HXDLIN( 225)		VIDEO = HX_("VIDEO",5b,4c,ea,b4);
            	}
{
            	HX_STACKFRAME(&_hx_pos_f18b9fd15d26d526_226_boot)
HXDLIN( 226)		FONT = HX_("FONT",cf,25,81,2e);
            	}
{
            	HX_STACKFRAME(&_hx_pos_f18b9fd15d26d526_227_boot)
HXDLIN( 227)		AUDIO_GENERIC = HX_("AUDIO_GENERIC",2e,f6,26,23);
            	}
{
            	HX_STACKFRAME(&_hx_pos_f18b9fd15d26d526_228_boot)
HXDLIN( 228)		AUDIO_MUSIC = HX_("AUDIO_MUSIC",fc,6c,05,48);
            	}
{
            	HX_STACKFRAME(&_hx_pos_f18b9fd15d26d526_229_boot)
HXDLIN( 229)		AUDIO_SOUND = HX_("AUDIO_SOUND",26,29,77,b8);
            	}
{
            	HX_STACKFRAME(&_hx_pos_f18b9fd15d26d526_230_boot)
HXDLIN( 230)		MANIFEST = HX_("MANIFEST",af,8b,af,29);
            	}
{
            	HX_STACKFRAME(&_hx_pos_f18b9fd15d26d526_231_boot)
HXDLIN( 231)		TEMPLATE = HX_("TEMPLATE",3a,78,cd,05);
            	}
{
            	HX_STACKFRAME(&_hx_pos_f18b9fd15d26d526_232_boot)
HXDLIN( 232)		UNKNOWN = HX_("UNKNOWN",6a,f7,4e,61);
            	}
}

} // end namespace polymod
} // end namespace backends
} // end namespace _PolymodAssets
