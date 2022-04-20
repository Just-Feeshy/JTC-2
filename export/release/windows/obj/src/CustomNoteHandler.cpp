#include <hxcpp.h>

#ifndef INCLUDED_CustomNoteHandler
#include <CustomNoteHandler.h>
#endif
#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_eb2ec6553bdc9e1d_24_spawn,"CustomNoteHandler","spawn",0x11eaec34,"CustomNoteHandler.spawn","CustomNoteHandler.hx",24,0x29748777)
HX_LOCAL_STACK_FRAME(_hx_pos_eb2ec6553bdc9e1d_9_boot,"CustomNoteHandler","boot",0xd140d859,"CustomNoteHandler.boot","CustomNoteHandler.hx",9,0x29748777)
HX_LOCAL_STACK_FRAME(_hx_pos_eb2ec6553bdc9e1d_14_boot,"CustomNoteHandler","boot",0xd140d859,"CustomNoteHandler.boot","CustomNoteHandler.hx",14,0x29748777)
static const ::String _hx_array_data_8cdd7da7_3[] = {
	HX_("poison",08,d9,31,f7),HX_("spiritual star",83,67,fb,93),HX_("trippy",2e,c2,d0,4a),HX_("reverse poison",46,c0,80,7a),HX_("planet notes",b9,fc,5e,75),
};
HX_LOCAL_STACK_FRAME(_hx_pos_eb2ec6553bdc9e1d_15_boot,"CustomNoteHandler","boot",0xd140d859,"CustomNoteHandler.boot","CustomNoteHandler.hx",15,0x29748777)
static const ::String _hx_array_data_8cdd7da7_5[] = {
	HX_("reverse",22,39,fc,1a),HX_("poison",08,d9,31,f7),HX_("spiritual star",83,67,fb,93),HX_("trippy",2e,c2,d0,4a),HX_("reverse poison",46,c0,80,7a),HX_("ocean",fe,7b,37,2b),HX_("side note",1b,77,6d,8e),HX_("planet notes",b9,fc,5e,75),
};
HX_LOCAL_STACK_FRAME(_hx_pos_eb2ec6553bdc9e1d_16_boot,"CustomNoteHandler","boot",0xd140d859,"CustomNoteHandler.boot","CustomNoteHandler.hx",16,0x29748777)
static const ::String _hx_array_data_8cdd7da7_7[] = {
	HX_("poison",08,d9,31,f7),HX_("trippy",2e,c2,d0,4a),HX_("reverse poison",46,c0,80,7a),HX_("planet notes",b9,fc,5e,75),
};
HX_LOCAL_STACK_FRAME(_hx_pos_eb2ec6553bdc9e1d_17_boot,"CustomNoteHandler","boot",0xd140d859,"CustomNoteHandler.boot","CustomNoteHandler.hx",17,0x29748777)
static const ::String _hx_array_data_8cdd7da7_9[] = {
	HX_("poison",08,d9,31,f7),HX_("regular",5c,52,88,82),HX_("reverse",22,39,fc,1a),HX_("ocean",fe,7b,37,2b),HX_("side note",1b,77,6d,8e),
};
HX_LOCAL_STACK_FRAME(_hx_pos_eb2ec6553bdc9e1d_22_boot,"CustomNoteHandler","boot",0xd140d859,"CustomNoteHandler.boot","CustomNoteHandler.hx",22,0x29748777)

void CustomNoteHandler_obj::__construct() { }

Dynamic CustomNoteHandler_obj::__CreateEmpty() { return new CustomNoteHandler_obj; }

void *CustomNoteHandler_obj::_hx_vtable = 0;

Dynamic CustomNoteHandler_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< CustomNoteHandler_obj > _hx_result = new CustomNoteHandler_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool CustomNoteHandler_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x7fd163ab;
}

bool CustomNoteHandler_obj::funni;

 ::haxe::ds::StringMap CustomNoteHandler_obj::triggerWarning;

 ::haxe::ds::StringMap CustomNoteHandler_obj::yourNoteData;

::Array< ::String > CustomNoteHandler_obj::dontHitNotes;

::Array< ::String > CustomNoteHandler_obj::noNoteAbstractStrum;

::Array< ::String > CustomNoteHandler_obj::ouchyNotes;

::Array< ::String > CustomNoteHandler_obj::lowNotesTick;

 ::haxe::ds::StringMap CustomNoteHandler_obj::customNoteAddon;

void CustomNoteHandler_obj::spawn(){
            	HX_GC_STACKFRAME(&_hx_pos_eb2ec6553bdc9e1d_24_spawn)
HXLINE(  25)		 ::haxe::ds::StringMap _g =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
HXDLIN(  25)		_g->set(HX_("reverse",22,39,fc,1a),false);
HXDLIN(  25)		_g->set(HX_("spiritual star",83,67,fb,93),false);
HXDLIN(  25)		_g->set(HX_("poison",08,d9,31,f7),false);
HXDLIN(  25)		_g->set(HX_("reverse poison",46,c0,80,7a),false);
HXDLIN(  25)		_g->set(HX_("side note",1b,77,6d,8e),false);
HXDLIN(  25)		_g->set(HX_("ocean",fe,7b,37,2b),false);
HXDLIN(  25)		::CustomNoteHandler_obj::triggerWarning = _g;
HXLINE(  35)		 ::haxe::ds::StringMap _g1 =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
HXDLIN(  35)		_g1->set(HX_("trippy",2e,c2,d0,4a),0);
HXDLIN(  35)		{
HXLINE(  35)			 ::Dynamic value = null();
HXDLIN(  35)			_g1->set(HX_("side note",1b,77,6d,8e),value);
            		}
HXDLIN(  35)		::CustomNoteHandler_obj::yourNoteData = _g1;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(CustomNoteHandler_obj,spawn,(void))


CustomNoteHandler_obj::CustomNoteHandler_obj()
{
}

bool CustomNoteHandler_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"funni") ) { outValue = ( funni ); return true; }
		if (HX_FIELD_EQ(inName,"spawn") ) { outValue = spawn_dyn(); return true; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"ouchyNotes") ) { outValue = ( ouchyNotes ); return true; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"yourNoteData") ) { outValue = ( yourNoteData ); return true; }
		if (HX_FIELD_EQ(inName,"dontHitNotes") ) { outValue = ( dontHitNotes ); return true; }
		if (HX_FIELD_EQ(inName,"lowNotesTick") ) { outValue = ( lowNotesTick ); return true; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"triggerWarning") ) { outValue = ( triggerWarning ); return true; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"customNoteAddon") ) { outValue = ( customNoteAddon ); return true; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"noNoteAbstractStrum") ) { outValue = ( noNoteAbstractStrum ); return true; }
	}
	return false;
}

bool CustomNoteHandler_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"funni") ) { funni=ioValue.Cast< bool >(); return true; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"ouchyNotes") ) { ouchyNotes=ioValue.Cast< ::Array< ::String > >(); return true; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"yourNoteData") ) { yourNoteData=ioValue.Cast<  ::haxe::ds::StringMap >(); return true; }
		if (HX_FIELD_EQ(inName,"dontHitNotes") ) { dontHitNotes=ioValue.Cast< ::Array< ::String > >(); return true; }
		if (HX_FIELD_EQ(inName,"lowNotesTick") ) { lowNotesTick=ioValue.Cast< ::Array< ::String > >(); return true; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"triggerWarning") ) { triggerWarning=ioValue.Cast<  ::haxe::ds::StringMap >(); return true; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"customNoteAddon") ) { customNoteAddon=ioValue.Cast<  ::haxe::ds::StringMap >(); return true; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"noNoteAbstractStrum") ) { noNoteAbstractStrum=ioValue.Cast< ::Array< ::String > >(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *CustomNoteHandler_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo CustomNoteHandler_obj_sStaticStorageInfo[] = {
	{::hx::fsBool,(void *) &CustomNoteHandler_obj::funni,HX_("funni",3a,fa,88,08)},
	{::hx::fsObject /*  ::haxe::ds::StringMap */ ,(void *) &CustomNoteHandler_obj::triggerWarning,HX_("triggerWarning",04,44,0b,fe)},
	{::hx::fsObject /*  ::haxe::ds::StringMap */ ,(void *) &CustomNoteHandler_obj::yourNoteData,HX_("yourNoteData",0f,14,bd,f0)},
	{::hx::fsObject /* ::Array< ::String > */ ,(void *) &CustomNoteHandler_obj::dontHitNotes,HX_("dontHitNotes",9f,5e,76,7d)},
	{::hx::fsObject /* ::Array< ::String > */ ,(void *) &CustomNoteHandler_obj::noNoteAbstractStrum,HX_("noNoteAbstractStrum",34,48,6c,c9)},
	{::hx::fsObject /* ::Array< ::String > */ ,(void *) &CustomNoteHandler_obj::ouchyNotes,HX_("ouchyNotes",93,4c,00,60)},
	{::hx::fsObject /* ::Array< ::String > */ ,(void *) &CustomNoteHandler_obj::lowNotesTick,HX_("lowNotesTick",0a,d9,ed,ba)},
	{::hx::fsObject /*  ::haxe::ds::StringMap */ ,(void *) &CustomNoteHandler_obj::customNoteAddon,HX_("customNoteAddon",3d,82,85,72)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static void CustomNoteHandler_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CustomNoteHandler_obj::funni,"funni");
	HX_MARK_MEMBER_NAME(CustomNoteHandler_obj::triggerWarning,"triggerWarning");
	HX_MARK_MEMBER_NAME(CustomNoteHandler_obj::yourNoteData,"yourNoteData");
	HX_MARK_MEMBER_NAME(CustomNoteHandler_obj::dontHitNotes,"dontHitNotes");
	HX_MARK_MEMBER_NAME(CustomNoteHandler_obj::noNoteAbstractStrum,"noNoteAbstractStrum");
	HX_MARK_MEMBER_NAME(CustomNoteHandler_obj::ouchyNotes,"ouchyNotes");
	HX_MARK_MEMBER_NAME(CustomNoteHandler_obj::lowNotesTick,"lowNotesTick");
	HX_MARK_MEMBER_NAME(CustomNoteHandler_obj::customNoteAddon,"customNoteAddon");
};

#ifdef HXCPP_VISIT_ALLOCS
static void CustomNoteHandler_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CustomNoteHandler_obj::funni,"funni");
	HX_VISIT_MEMBER_NAME(CustomNoteHandler_obj::triggerWarning,"triggerWarning");
	HX_VISIT_MEMBER_NAME(CustomNoteHandler_obj::yourNoteData,"yourNoteData");
	HX_VISIT_MEMBER_NAME(CustomNoteHandler_obj::dontHitNotes,"dontHitNotes");
	HX_VISIT_MEMBER_NAME(CustomNoteHandler_obj::noNoteAbstractStrum,"noNoteAbstractStrum");
	HX_VISIT_MEMBER_NAME(CustomNoteHandler_obj::ouchyNotes,"ouchyNotes");
	HX_VISIT_MEMBER_NAME(CustomNoteHandler_obj::lowNotesTick,"lowNotesTick");
	HX_VISIT_MEMBER_NAME(CustomNoteHandler_obj::customNoteAddon,"customNoteAddon");
};

#endif

::hx::Class CustomNoteHandler_obj::__mClass;

static ::String CustomNoteHandler_obj_sStaticFields[] = {
	HX_("funni",3a,fa,88,08),
	HX_("triggerWarning",04,44,0b,fe),
	HX_("yourNoteData",0f,14,bd,f0),
	HX_("dontHitNotes",9f,5e,76,7d),
	HX_("noNoteAbstractStrum",34,48,6c,c9),
	HX_("ouchyNotes",93,4c,00,60),
	HX_("lowNotesTick",0a,d9,ed,ba),
	HX_("customNoteAddon",3d,82,85,72),
	HX_("spawn",3b,9e,66,81),
	::String(null())
};

void CustomNoteHandler_obj::__register()
{
	CustomNoteHandler_obj _hx_dummy;
	CustomNoteHandler_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("CustomNoteHandler",a7,7d,dd,8c);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &CustomNoteHandler_obj::__GetStatic;
	__mClass->mSetStaticField = &CustomNoteHandler_obj::__SetStatic;
	__mClass->mMarkFunc = CustomNoteHandler_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(CustomNoteHandler_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< CustomNoteHandler_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = CustomNoteHandler_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = CustomNoteHandler_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = CustomNoteHandler_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void CustomNoteHandler_obj::__boot()
{
{
            	HX_STACKFRAME(&_hx_pos_eb2ec6553bdc9e1d_9_boot)
HXDLIN(   9)		funni = false;
            	}
{
            	HX_STACKFRAME(&_hx_pos_eb2ec6553bdc9e1d_14_boot)
HXDLIN(  14)		dontHitNotes = ::Array_obj< ::String >::fromData( _hx_array_data_8cdd7da7_3,5);
            	}
{
            	HX_STACKFRAME(&_hx_pos_eb2ec6553bdc9e1d_15_boot)
HXDLIN(  15)		noNoteAbstractStrum = ::Array_obj< ::String >::fromData( _hx_array_data_8cdd7da7_5,8);
            	}
{
            	HX_STACKFRAME(&_hx_pos_eb2ec6553bdc9e1d_16_boot)
HXDLIN(  16)		ouchyNotes = ::Array_obj< ::String >::fromData( _hx_array_data_8cdd7da7_7,4);
            	}
{
            	HX_STACKFRAME(&_hx_pos_eb2ec6553bdc9e1d_17_boot)
HXDLIN(  17)		lowNotesTick = ::Array_obj< ::String >::fromData( _hx_array_data_8cdd7da7_9,5);
            	}
{
            	HX_GC_STACKFRAME(&_hx_pos_eb2ec6553bdc9e1d_22_boot)
HXDLIN(  22)		customNoteAddon =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
            	}
}

