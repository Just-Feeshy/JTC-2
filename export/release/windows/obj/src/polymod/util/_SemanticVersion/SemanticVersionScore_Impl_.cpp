#include <hxcpp.h>

#ifndef INCLUDED_haxe_Exception
#include <haxe/Exception.h>
#endif
#ifndef INCLUDED_polymod_util__SemanticVersion_SemanticVersionScore_Impl_
#include <polymod/util/_SemanticVersion/SemanticVersionScore_Impl_.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_35840ec4cad173d1_247_fromString,"polymod.util._SemanticVersion.SemanticVersionScore_Impl_","fromString",0x71071862,"polymod.util._SemanticVersion.SemanticVersionScore_Impl_.fromString","polymod/util/SemanticVersion.hx",247,0xe2d86840)
HX_LOCAL_STACK_FRAME(_hx_pos_35840ec4cad173d1_240_boot,"polymod.util._SemanticVersion.SemanticVersionScore_Impl_","boot",0x9f7c3f79,"polymod.util._SemanticVersion.SemanticVersionScore_Impl_.boot","polymod/util/SemanticVersion.hx",240,0xe2d86840)
HX_LOCAL_STACK_FRAME(_hx_pos_35840ec4cad173d1_241_boot,"polymod.util._SemanticVersion.SemanticVersionScore_Impl_","boot",0x9f7c3f79,"polymod.util._SemanticVersion.SemanticVersionScore_Impl_.boot","polymod/util/SemanticVersion.hx",241,0xe2d86840)
HX_LOCAL_STACK_FRAME(_hx_pos_35840ec4cad173d1_242_boot,"polymod.util._SemanticVersion.SemanticVersionScore_Impl_","boot",0x9f7c3f79,"polymod.util._SemanticVersion.SemanticVersionScore_Impl_.boot","polymod/util/SemanticVersion.hx",242,0xe2d86840)
HX_LOCAL_STACK_FRAME(_hx_pos_35840ec4cad173d1_243_boot,"polymod.util._SemanticVersion.SemanticVersionScore_Impl_","boot",0x9f7c3f79,"polymod.util._SemanticVersion.SemanticVersionScore_Impl_.boot","polymod/util/SemanticVersion.hx",243,0xe2d86840)
namespace polymod{
namespace util{
namespace _SemanticVersion{

void SemanticVersionScore_Impl__obj::__construct() { }

Dynamic SemanticVersionScore_Impl__obj::__CreateEmpty() { return new SemanticVersionScore_Impl__obj; }

void *SemanticVersionScore_Impl__obj::_hx_vtable = 0;

Dynamic SemanticVersionScore_Impl__obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< SemanticVersionScore_Impl__obj > _hx_result = new SemanticVersionScore_Impl__obj();
	_hx_result->__construct();
	return _hx_result;
}

bool SemanticVersionScore_Impl__obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x4d5c95c3;
}

int SemanticVersionScore_Impl__obj::NONE;

int SemanticVersionScore_Impl__obj::MATCH_MAJOR;

int SemanticVersionScore_Impl__obj::MATCH_MINOR;

int SemanticVersionScore_Impl__obj::MATCH_PATCH;

int SemanticVersionScore_Impl__obj::fromString(::String value){
            	HX_STACKFRAME(&_hx_pos_35840ec4cad173d1_247_fromString)
HXDLIN( 247)		::String _hx_switch_0 = value;
            		if (  (_hx_switch_0==HX_("MATCH_MAJOR",3f,a7,33,f4)) ){
HXLINE( 252)			return 1;
HXDLIN( 252)			goto _hx_goto_0;
            		}
            		if (  (_hx_switch_0==HX_("MATCH_MINOR",3b,65,80,f9)) ){
HXLINE( 254)			return 2;
HXDLIN( 254)			goto _hx_goto_0;
            		}
            		if (  (_hx_switch_0==HX_("MATCH_PATCH",ce,f0,6e,ae)) ){
HXLINE( 256)			return 3;
HXDLIN( 256)			goto _hx_goto_0;
            		}
            		if (  (_hx_switch_0==HX_("NONE",b8,da,ca,33)) ){
HXLINE( 250)			return 0;
HXDLIN( 250)			goto _hx_goto_0;
            		}
            		/* default */{
HXLINE( 258)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("SemanticVersionScore: Unknown value ",0b,3a,d0,3c) + value)));
            		}
            		_hx_goto_0:;
HXLINE( 247)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(SemanticVersionScore_Impl__obj,fromString,return )


SemanticVersionScore_Impl__obj::SemanticVersionScore_Impl__obj()
{
}

bool SemanticVersionScore_Impl__obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"fromString") ) { outValue = fromString_dyn(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *SemanticVersionScore_Impl__obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo SemanticVersionScore_Impl__obj_sStaticStorageInfo[] = {
	{::hx::fsInt,(void *) &SemanticVersionScore_Impl__obj::NONE,HX_("NONE",b8,da,ca,33)},
	{::hx::fsInt,(void *) &SemanticVersionScore_Impl__obj::MATCH_MAJOR,HX_("MATCH_MAJOR",3f,a7,33,f4)},
	{::hx::fsInt,(void *) &SemanticVersionScore_Impl__obj::MATCH_MINOR,HX_("MATCH_MINOR",3b,65,80,f9)},
	{::hx::fsInt,(void *) &SemanticVersionScore_Impl__obj::MATCH_PATCH,HX_("MATCH_PATCH",ce,f0,6e,ae)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static void SemanticVersionScore_Impl__obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SemanticVersionScore_Impl__obj::NONE,"NONE");
	HX_MARK_MEMBER_NAME(SemanticVersionScore_Impl__obj::MATCH_MAJOR,"MATCH_MAJOR");
	HX_MARK_MEMBER_NAME(SemanticVersionScore_Impl__obj::MATCH_MINOR,"MATCH_MINOR");
	HX_MARK_MEMBER_NAME(SemanticVersionScore_Impl__obj::MATCH_PATCH,"MATCH_PATCH");
};

#ifdef HXCPP_VISIT_ALLOCS
static void SemanticVersionScore_Impl__obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SemanticVersionScore_Impl__obj::NONE,"NONE");
	HX_VISIT_MEMBER_NAME(SemanticVersionScore_Impl__obj::MATCH_MAJOR,"MATCH_MAJOR");
	HX_VISIT_MEMBER_NAME(SemanticVersionScore_Impl__obj::MATCH_MINOR,"MATCH_MINOR");
	HX_VISIT_MEMBER_NAME(SemanticVersionScore_Impl__obj::MATCH_PATCH,"MATCH_PATCH");
};

#endif

::hx::Class SemanticVersionScore_Impl__obj::__mClass;

static ::String SemanticVersionScore_Impl__obj_sStaticFields[] = {
	HX_("NONE",b8,da,ca,33),
	HX_("MATCH_MAJOR",3f,a7,33,f4),
	HX_("MATCH_MINOR",3b,65,80,f9),
	HX_("MATCH_PATCH",ce,f0,6e,ae),
	HX_("fromString",db,2d,74,54),
	::String(null())
};

void SemanticVersionScore_Impl__obj::__register()
{
	SemanticVersionScore_Impl__obj _hx_dummy;
	SemanticVersionScore_Impl__obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("polymod.util._SemanticVersion.SemanticVersionScore_Impl_",87,6a,9b,9a);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &SemanticVersionScore_Impl__obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mMarkFunc = SemanticVersionScore_Impl__obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(SemanticVersionScore_Impl__obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< SemanticVersionScore_Impl__obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = SemanticVersionScore_Impl__obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = SemanticVersionScore_Impl__obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = SemanticVersionScore_Impl__obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void SemanticVersionScore_Impl__obj::__boot()
{
{
            	HX_STACKFRAME(&_hx_pos_35840ec4cad173d1_240_boot)
HXDLIN( 240)		NONE = 0;
            	}
{
            	HX_STACKFRAME(&_hx_pos_35840ec4cad173d1_241_boot)
HXDLIN( 241)		MATCH_MAJOR = 1;
            	}
{
            	HX_STACKFRAME(&_hx_pos_35840ec4cad173d1_242_boot)
HXDLIN( 242)		MATCH_MINOR = 2;
            	}
{
            	HX_STACKFRAME(&_hx_pos_35840ec4cad173d1_243_boot)
HXDLIN( 243)		MATCH_PATCH = 3;
            	}
}

} // end namespace polymod
} // end namespace util
} // end namespace _SemanticVersion
