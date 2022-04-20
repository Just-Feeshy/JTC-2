#include <hxcpp.h>

#ifndef INCLUDED_CustomNoteHandler
#include <CustomNoteHandler.h>
#endif
#ifndef INCLUDED_NoteAddon
#include <NoteAddon.h>
#endif
#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_eb2ec6553bdc9e1d_19_spawn,"CustomNoteHandler","spawn",0x11eaec34,"CustomNoteHandler.spawn","CustomNoteHandler.hx",19,0x29748777)
HX_LOCAL_STACK_FRAME(_hx_pos_eb2ec6553bdc9e1d_38_configAddons,"CustomNoteHandler","configAddons",0x148d8e7c,"CustomNoteHandler.configAddons","CustomNoteHandler.hx",38,0x29748777)
HX_LOCAL_STACK_FRAME(_hx_pos_eb2ec6553bdc9e1d_7_boot,"CustomNoteHandler","boot",0xd140d859,"CustomNoteHandler.boot","CustomNoteHandler.hx",7,0x29748777)
HX_LOCAL_STACK_FRAME(_hx_pos_eb2ec6553bdc9e1d_12_boot,"CustomNoteHandler","boot",0xd140d859,"CustomNoteHandler.boot","CustomNoteHandler.hx",12,0x29748777)
static const ::String _hx_array_data_8cdd7da7_6[] = {
	HX_("poison",08,d9,31,f7),HX_("spiritual star",83,67,fb,93),HX_("trippy",2e,c2,d0,4a),HX_("reverse poison",46,c0,80,7a),HX_("planet notes",b9,fc,5e,75),
};
HX_LOCAL_STACK_FRAME(_hx_pos_eb2ec6553bdc9e1d_13_boot,"CustomNoteHandler","boot",0xd140d859,"CustomNoteHandler.boot","CustomNoteHandler.hx",13,0x29748777)
static const ::String _hx_array_data_8cdd7da7_8[] = {
	HX_("reverse",22,39,fc,1a),HX_("poison",08,d9,31,f7),HX_("spiritual star",83,67,fb,93),HX_("trippy",2e,c2,d0,4a),HX_("reverse poison",46,c0,80,7a),HX_("ocean",fe,7b,37,2b),HX_("side note",1b,77,6d,8e),HX_("planet notes",b9,fc,5e,75),
};
HX_LOCAL_STACK_FRAME(_hx_pos_eb2ec6553bdc9e1d_14_boot,"CustomNoteHandler","boot",0xd140d859,"CustomNoteHandler.boot","CustomNoteHandler.hx",14,0x29748777)
static const ::String _hx_array_data_8cdd7da7_10[] = {
	HX_("poison",08,d9,31,f7),HX_("trippy",2e,c2,d0,4a),HX_("reverse poison",46,c0,80,7a),HX_("planet notes",b9,fc,5e,75),
};
HX_LOCAL_STACK_FRAME(_hx_pos_eb2ec6553bdc9e1d_15_boot,"CustomNoteHandler","boot",0xd140d859,"CustomNoteHandler.boot","CustomNoteHandler.hx",15,0x29748777)
static const ::String _hx_array_data_8cdd7da7_12[] = {
	HX_("poison",08,d9,31,f7),HX_("regular",5c,52,88,82),HX_("reverse",22,39,fc,1a),HX_("ocean",fe,7b,37,2b),HX_("side note",1b,77,6d,8e),
};
HX_LOCAL_STACK_FRAME(_hx_pos_eb2ec6553bdc9e1d_17_boot,"CustomNoteHandler","boot",0xd140d859,"CustomNoteHandler.boot","CustomNoteHandler.hx",17,0x29748777)

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

::Array< ::Dynamic> CustomNoteHandler_obj::customNoteAddon;

void CustomNoteHandler_obj::spawn(){
            	HX_GC_STACKFRAME(&_hx_pos_eb2ec6553bdc9e1d_19_spawn)
HXLINE(  20)		 ::haxe::ds::StringMap _g =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
HXDLIN(  20)		_g->set(HX_("reverse",22,39,fc,1a),false);
HXDLIN(  20)		_g->set(HX_("spiritual star",83,67,fb,93),false);
HXDLIN(  20)		_g->set(HX_("poison",08,d9,31,f7),false);
HXDLIN(  20)		_g->set(HX_("reverse poison",46,c0,80,7a),false);
HXDLIN(  20)		_g->set(HX_("side note",1b,77,6d,8e),false);
HXDLIN(  20)		_g->set(HX_("ocean",fe,7b,37,2b),false);
HXDLIN(  20)		::CustomNoteHandler_obj::triggerWarning = _g;
HXLINE(  30)		 ::haxe::ds::StringMap _g1 =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
HXDLIN(  30)		_g1->set(HX_("trippy",2e,c2,d0,4a),0);
HXDLIN(  30)		{
HXLINE(  30)			 ::Dynamic value = null();
HXDLIN(  30)			_g1->set(HX_("side note",1b,77,6d,8e),value);
            		}
HXDLIN(  30)		::CustomNoteHandler_obj::yourNoteData = _g1;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(CustomNoteHandler_obj,spawn,(void))

void CustomNoteHandler_obj::configAddons(){
            	HX_STACKFRAME(&_hx_pos_eb2ec6553bdc9e1d_38_configAddons)
HXDLIN(  38)		if (!(::CustomNoteHandler_obj::funni)) {
HXLINE(  39)			{
HXLINE(  39)				int _g = 0;
HXDLIN(  39)				int _g1 = ::CustomNoteHandler_obj::customNoteAddon->length;
HXDLIN(  39)				while((_g < _g1)){
HXLINE(  39)					_g = (_g + 1);
HXDLIN(  39)					int i = (_g - 1);
HXLINE(  40)					 ::NoteAddon v = ::CustomNoteHandler_obj::customNoteAddon->__get(i).StaticCast<  ::NoteAddon >();
HXLINE(  42)					bool _hx_tmp;
HXDLIN(  42)					if ((v->getCustomNote() != HX_("",00,00,00,00))) {
HXLINE(  42)						_hx_tmp = ::hx::IsNotNull( v->getCustomNote() );
            					}
            					else {
HXLINE(  42)						_hx_tmp = false;
            					}
HXDLIN(  42)					if (_hx_tmp) {
HXLINE(  43)						bool _hx_tmp;
HXDLIN(  43)						if (v->playerShouldntHit()) {
HXLINE(  43)							_hx_tmp = !(::CustomNoteHandler_obj::dontHitNotes->contains(v->getCustomNote()));
            						}
            						else {
HXLINE(  43)							_hx_tmp = false;
            						}
HXDLIN(  43)						if (_hx_tmp) {
HXLINE(  44)							::CustomNoteHandler_obj::dontHitNotes->push(v->getCustomNote());
            						}
            						else {
HXLINE(  45)							bool _hx_tmp;
HXDLIN(  45)							if (v->noDefaultSplash()) {
HXLINE(  45)								_hx_tmp = !(::CustomNoteHandler_obj::noNoteAbstractStrum->contains(v->getCustomNote()));
            							}
            							else {
HXLINE(  45)								_hx_tmp = false;
            							}
HXDLIN(  45)							if (_hx_tmp) {
HXLINE(  46)								::CustomNoteHandler_obj::noNoteAbstractStrum->push(v->getCustomNote());
            							}
            							else {
HXLINE(  47)								bool _hx_tmp;
HXDLIN(  47)								if ((v->giveHealth() < 0)) {
HXLINE(  47)									_hx_tmp = !(::CustomNoteHandler_obj::ouchyNotes->contains(v->getCustomNote()));
            								}
            								else {
HXLINE(  47)									_hx_tmp = false;
            								}
HXDLIN(  47)								if (_hx_tmp) {
HXLINE(  48)									::CustomNoteHandler_obj::ouchyNotes->push(v->getCustomNote());
            								}
            							}
            						}
            					}
            				}
            			}
HXLINE(  52)			bool _hx_tmp;
HXDLIN(  52)			if (::hx::IsNotNull( ::CustomNoteHandler_obj::customNoteAddon->__get(0).StaticCast<  ::NoteAddon >() )) {
HXLINE(  52)				_hx_tmp = (::CustomNoteHandler_obj::customNoteAddon->__get(0).StaticCast<  ::NoteAddon >()->getCustomNote() != HX_("",00,00,00,00));
            			}
            			else {
HXLINE(  52)				_hx_tmp = false;
            			}
HXDLIN(  52)			if (_hx_tmp) {
HXLINE(  53)				int _g = 0;
HXDLIN(  53)				int _g1 = ::CustomNoteHandler_obj::customNoteAddon->length;
HXDLIN(  53)				while((_g < _g1)){
HXLINE(  53)					_g = (_g + 1);
HXDLIN(  53)					int i = (_g - 1);
HXLINE(  54)					 ::NoteAddon v = ::CustomNoteHandler_obj::customNoteAddon->__get(i).StaticCast<  ::NoteAddon >();
HXLINE(  56)					{
HXLINE(  56)						::Dynamic this1 = ::CustomNoteHandler_obj::triggerWarning;
HXDLIN(  56)						( ( ::haxe::ds::StringMap)(this1) )->set(v->getCustomNote(),false);
            					}
            				}
            			}
HXLINE(  60)			::CustomNoteHandler_obj::funni = true;
            		}
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(CustomNoteHandler_obj,configAddons,(void))


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
		if (HX_FIELD_EQ(inName,"configAddons") ) { outValue = configAddons_dyn(); return true; }
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
		if (HX_FIELD_EQ(inName,"customNoteAddon") ) { customNoteAddon=ioValue.Cast< ::Array< ::Dynamic> >(); return true; }
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
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(void *) &CustomNoteHandler_obj::customNoteAddon,HX_("customNoteAddon",3d,82,85,72)},
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
	HX_("configAddons",55,3b,2d,fe),
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
            	HX_STACKFRAME(&_hx_pos_eb2ec6553bdc9e1d_7_boot)
HXDLIN(   7)		funni = false;
            	}
{
            	HX_STACKFRAME(&_hx_pos_eb2ec6553bdc9e1d_12_boot)
HXDLIN(  12)		dontHitNotes = ::Array_obj< ::String >::fromData( _hx_array_data_8cdd7da7_6,5);
            	}
{
            	HX_STACKFRAME(&_hx_pos_eb2ec6553bdc9e1d_13_boot)
HXDLIN(  13)		noNoteAbstractStrum = ::Array_obj< ::String >::fromData( _hx_array_data_8cdd7da7_8,8);
            	}
{
            	HX_STACKFRAME(&_hx_pos_eb2ec6553bdc9e1d_14_boot)
HXDLIN(  14)		ouchyNotes = ::Array_obj< ::String >::fromData( _hx_array_data_8cdd7da7_10,4);
            	}
{
            	HX_STACKFRAME(&_hx_pos_eb2ec6553bdc9e1d_15_boot)
HXDLIN(  15)		lowNotesTick = ::Array_obj< ::String >::fromData( _hx_array_data_8cdd7da7_12,5);
            	}
{
            	HX_STACKFRAME(&_hx_pos_eb2ec6553bdc9e1d_17_boot)
HXDLIN(  17)		customNoteAddon = ::Array_obj< ::Dynamic>::__new(0);
            	}
}

