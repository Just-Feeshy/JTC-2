#include <hxcpp.h>

#ifndef INCLUDED_haxe_format_JsonPrinter
#include <haxe/format/JsonPrinter.h>
#endif
#ifndef INCLUDED_polymod_hscript_HScriptParams
#include <polymod/hscript/HScriptParams.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_b9dc96b340209742_28_new,"polymod.hscript.HScriptParams","new",0x613d1c58,"polymod.hscript.HScriptParams.new","polymod/hscript/HScriptable.hx",28,0xab5038e6)
HX_LOCAL_STACK_FRAME(_hx_pos_b9dc96b340209742_71_set_pathName,"polymod.hscript.HScriptParams","set_pathName",0xdbeb0715,"polymod.hscript.HScriptParams.set_pathName","polymod/hscript/HScriptable.hx",71,0xab5038e6)
HX_LOCAL_STACK_FRAME(_hx_pos_b9dc96b340209742_91_set_pathNameDynId,"polymod.hscript.HScriptParams","set_pathNameDynId",0x6cc8281f,"polymod.hscript.HScriptParams.set_pathNameDynId","polymod/hscript/HScriptable.hx",91,0xab5038e6)
HX_LOCAL_STACK_FRAME(_hx_pos_b9dc96b340209742_106_mergeContext,"polymod.hscript.HScriptParams","mergeContext",0xa175d71f,"polymod.hscript.HScriptParams.mergeContext","polymod/hscript/HScriptable.hx",106,0xab5038e6)
HX_LOCAL_STACK_FRAME(_hx_pos_b9dc96b340209742_112_mergeCancellable,"polymod.hscript.HScriptParams","mergeCancellable",0x8898a57c,"polymod.hscript.HScriptParams.mergeCancellable","polymod/hscript/HScriptable.hx",112,0xab5038e6)
HX_LOCAL_STACK_FRAME(_hx_pos_b9dc96b340209742_119_mergeRunBefore,"polymod.hscript.HScriptParams","mergeRunBefore",0xf583a75a,"polymod.hscript.HScriptParams.mergeRunBefore","polymod/hscript/HScriptable.hx",119,0xab5038e6)
HX_LOCAL_STACK_FRAME(_hx_pos_b9dc96b340209742_126_mergeOptional,"polymod.hscript.HScriptParams","mergeOptional",0x94e97870,"polymod.hscript.HScriptParams.mergeOptional","polymod/hscript/HScriptable.hx",126,0xab5038e6)
HX_LOCAL_STACK_FRAME(_hx_pos_b9dc96b340209742_133_mergePathName,"polymod.hscript.HScriptParams","mergePathName",0xb5198360,"polymod.hscript.HScriptParams.mergePathName","polymod/hscript/HScriptable.hx",133,0xab5038e6)
HX_LOCAL_STACK_FRAME(_hx_pos_b9dc96b340209742_152_copy,"polymod.hscript.HScriptParams","copy",0xacfde8bd,"polymod.hscript.HScriptParams.copy","polymod/hscript/HScriptable.hx",152,0xab5038e6)
HX_LOCAL_STACK_FRAME(_hx_pos_b9dc96b340209742_171_merge,"polymod.hscript.HScriptParams","merge",0x6c94dcb0,"polymod.hscript.HScriptParams.merge","polymod/hscript/HScriptable.hx",171,0xab5038e6)
HX_LOCAL_STACK_FRAME(_hx_pos_b9dc96b340209742_180_toString,"polymod.hscript.HScriptParams","toString",0xd77721b4,"polymod.hscript.HScriptParams.toString","polymod/hscript/HScriptable.hx",180,0xab5038e6)
HX_LOCAL_STACK_FRAME(_hx_pos_b9dc96b340209742_44_boot,"polymod.hscript.HScriptParams","boot",0xac54b13a,"polymod.hscript.HScriptParams.boot","polymod/hscript/HScriptable.hx",44,0xab5038e6)
HX_LOCAL_STACK_FRAME(_hx_pos_b9dc96b340209742_53_boot,"polymod.hscript.HScriptParams","boot",0xac54b13a,"polymod.hscript.HScriptParams.boot","polymod/hscript/HScriptable.hx",53,0xab5038e6)
HX_LOCAL_STACK_FRAME(_hx_pos_b9dc96b340209742_62_boot,"polymod.hscript.HScriptParams","boot",0xac54b13a,"polymod.hscript.HScriptParams.boot","polymod/hscript/HScriptable.hx",62,0xab5038e6)
namespace polymod{
namespace hscript{

void HScriptParams_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_b9dc96b340209742_28_new)
HXLINE(  88)		this->pathNameDynId = null();
HXLINE(  68)		this->pathName = null();
HXLINE(  60)		this->optional = null();
HXLINE(  51)		this->runBefore = null();
HXLINE(  42)		this->cancellable = null();
HXLINE(  35)		this->context = ::Array_obj< ::String >::__new(0);
            	}

Dynamic HScriptParams_obj::__CreateEmpty() { return new HScriptParams_obj; }

void *HScriptParams_obj::_hx_vtable = 0;

Dynamic HScriptParams_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< HScriptParams_obj > _hx_result = new HScriptParams_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool HScriptParams_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x0c51ea74;
}

::String HScriptParams_obj::set_pathName(::String newValue){
            	HX_STACKFRAME(&_hx_pos_b9dc96b340209742_71_set_pathName)
HXLINE(  72)		if (::hx::IsNotNull( this->pathNameDynId )) {
HXLINE(  73)			return null();
            		}
HXLINE(  75)		this->pathName = newValue;
HXLINE(  76)		return this->pathName;
            	}


HX_DEFINE_DYNAMIC_FUNC1(HScriptParams_obj,set_pathName,return )

::String HScriptParams_obj::set_pathNameDynId(::String newValue){
            	HX_STACKFRAME(&_hx_pos_b9dc96b340209742_91_set_pathNameDynId)
HXLINE(  92)		this->set_pathName(null());
HXLINE(  93)		this->pathNameDynId = newValue;
HXLINE(  94)		return this->pathNameDynId;
            	}


HX_DEFINE_DYNAMIC_FUNC1(HScriptParams_obj,set_pathNameDynId,return )

 ::polymod::hscript::HScriptParams HScriptParams_obj::mergeContext(::Array< ::String > newValues){
            	HX_STACKFRAME(&_hx_pos_b9dc96b340209742_106_mergeContext)
HXLINE( 107)		this->context = this->context->concat(newValues);
HXLINE( 108)		return ::hx::ObjectPtr<OBJ_>(this);
            	}


HX_DEFINE_DYNAMIC_FUNC1(HScriptParams_obj,mergeContext,return )

 ::polymod::hscript::HScriptParams HScriptParams_obj::mergeCancellable( ::Dynamic newValue){
            	HX_STACKFRAME(&_hx_pos_b9dc96b340209742_112_mergeCancellable)
HXLINE( 113)		if (::hx::IsNotNull( newValue )) {
HXLINE( 114)			this->cancellable = newValue;
            		}
HXLINE( 115)		return ::hx::ObjectPtr<OBJ_>(this);
            	}


HX_DEFINE_DYNAMIC_FUNC1(HScriptParams_obj,mergeCancellable,return )

 ::polymod::hscript::HScriptParams HScriptParams_obj::mergeRunBefore( ::Dynamic newValue){
            	HX_STACKFRAME(&_hx_pos_b9dc96b340209742_119_mergeRunBefore)
HXLINE( 120)		if (::hx::IsNotNull( newValue )) {
HXLINE( 121)			this->runBefore = newValue;
            		}
HXLINE( 122)		return ::hx::ObjectPtr<OBJ_>(this);
            	}


HX_DEFINE_DYNAMIC_FUNC1(HScriptParams_obj,mergeRunBefore,return )

 ::polymod::hscript::HScriptParams HScriptParams_obj::mergeOptional( ::Dynamic newValue){
            	HX_STACKFRAME(&_hx_pos_b9dc96b340209742_126_mergeOptional)
HXLINE( 127)		if (::hx::IsNotNull( newValue )) {
HXLINE( 128)			this->optional = newValue;
            		}
HXLINE( 129)		return ::hx::ObjectPtr<OBJ_>(this);
            	}


HX_DEFINE_DYNAMIC_FUNC1(HScriptParams_obj,mergeOptional,return )

 ::polymod::hscript::HScriptParams HScriptParams_obj::mergePathName(::String newValue,::String newDynValue){
            	HX_STACKFRAME(&_hx_pos_b9dc96b340209742_133_mergePathName)
HXLINE( 134)		if (::hx::IsNotNull( newDynValue )) {
HXLINE( 136)			this->set_pathNameDynId(newDynValue);
HXLINE( 137)			this->set_pathName(null());
            		}
            		else {
HXLINE( 141)			bool _hx_tmp;
HXDLIN( 141)			if (::hx::IsNull( this->pathNameDynId )) {
HXLINE( 141)				_hx_tmp = ::hx::IsNotNull( newValue );
            			}
            			else {
HXLINE( 141)				_hx_tmp = false;
            			}
HXDLIN( 141)			if (_hx_tmp) {
HXLINE( 142)				this->set_pathName(newValue);
            			}
            		}
HXLINE( 144)		return ::hx::ObjectPtr<OBJ_>(this);
            	}


HX_DEFINE_DYNAMIC_FUNC2(HScriptParams_obj,mergePathName,return )

 ::polymod::hscript::HScriptParams HScriptParams_obj::copy(){
            	HX_GC_STACKFRAME(&_hx_pos_b9dc96b340209742_152_copy)
HXLINE( 153)		 ::polymod::hscript::HScriptParams result =  ::polymod::hscript::HScriptParams_obj::__alloc( HX_CTX );
HXLINE( 155)		result->cancellable = this->cancellable;
HXLINE( 156)		result->context = this->context;
HXLINE( 157)		result->optional = this->optional;
HXLINE( 158)		result->set_pathName(this->pathName);
HXLINE( 159)		result->set_pathNameDynId(this->pathNameDynId);
HXLINE( 160)		result->runBefore = this->runBefore;
HXLINE( 162)		return result;
            	}


HX_DEFINE_DYNAMIC_FUNC0(HScriptParams_obj,copy,return )

 ::polymod::hscript::HScriptParams HScriptParams_obj::merge( ::polymod::hscript::HScriptParams newValue){
            	HX_STACKFRAME(&_hx_pos_b9dc96b340209742_171_merge)
HXDLIN( 171)		return this->mergeCancellable(newValue->cancellable)->mergeContext(newValue->context)->mergeOptional(newValue->optional)->mergePathName(newValue->pathName,newValue->pathNameDynId)->mergeRunBefore(newValue->runBefore);
            	}


HX_DEFINE_DYNAMIC_FUNC1(HScriptParams_obj,merge,return )

::String HScriptParams_obj::toString(){
            	HX_STACKFRAME(&_hx_pos_b9dc96b340209742_180_toString)
HXDLIN( 180)		 ::Dynamic replacer = null();
HXDLIN( 180)		::String space = null();
HXDLIN( 180)		return ::haxe::format::JsonPrinter_obj::print(::hx::ObjectPtr<OBJ_>(this),replacer,space);
            	}


HX_DEFINE_DYNAMIC_FUNC0(HScriptParams_obj,toString,return )

bool HScriptParams_obj::CANCELLABLE_DEFAULT;

bool HScriptParams_obj::RUN_BEFORE_DEFAULT;

bool HScriptParams_obj::OPTIONAL_DEFAULT;


::hx::ObjectPtr< HScriptParams_obj > HScriptParams_obj::__new() {
	::hx::ObjectPtr< HScriptParams_obj > __this = new HScriptParams_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< HScriptParams_obj > HScriptParams_obj::__alloc(::hx::Ctx *_hx_ctx) {
	HScriptParams_obj *__this = (HScriptParams_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(HScriptParams_obj), true, "polymod.hscript.HScriptParams"));
	*(void **)__this = HScriptParams_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

HScriptParams_obj::HScriptParams_obj()
{
}

void HScriptParams_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HScriptParams);
	HX_MARK_MEMBER_NAME(context,"context");
	HX_MARK_MEMBER_NAME(cancellable,"cancellable");
	HX_MARK_MEMBER_NAME(runBefore,"runBefore");
	HX_MARK_MEMBER_NAME(optional,"optional");
	HX_MARK_MEMBER_NAME(pathName,"pathName");
	HX_MARK_MEMBER_NAME(pathNameDynId,"pathNameDynId");
	HX_MARK_END_CLASS();
}

void HScriptParams_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(context,"context");
	HX_VISIT_MEMBER_NAME(cancellable,"cancellable");
	HX_VISIT_MEMBER_NAME(runBefore,"runBefore");
	HX_VISIT_MEMBER_NAME(optional,"optional");
	HX_VISIT_MEMBER_NAME(pathName,"pathName");
	HX_VISIT_MEMBER_NAME(pathNameDynId,"pathNameDynId");
}

::hx::Val HScriptParams_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"copy") ) { return ::hx::Val( copy_dyn() ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"merge") ) { return ::hx::Val( merge_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"context") ) { return ::hx::Val( context ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"optional") ) { return ::hx::Val( optional ); }
		if (HX_FIELD_EQ(inName,"pathName") ) { return ::hx::Val( pathName ); }
		if (HX_FIELD_EQ(inName,"toString") ) { return ::hx::Val( toString_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"runBefore") ) { return ::hx::Val( runBefore ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"cancellable") ) { return ::hx::Val( cancellable ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"set_pathName") ) { return ::hx::Val( set_pathName_dyn() ); }
		if (HX_FIELD_EQ(inName,"mergeContext") ) { return ::hx::Val( mergeContext_dyn() ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"pathNameDynId") ) { return ::hx::Val( pathNameDynId ); }
		if (HX_FIELD_EQ(inName,"mergeOptional") ) { return ::hx::Val( mergeOptional_dyn() ); }
		if (HX_FIELD_EQ(inName,"mergePathName") ) { return ::hx::Val( mergePathName_dyn() ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"mergeRunBefore") ) { return ::hx::Val( mergeRunBefore_dyn() ); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"mergeCancellable") ) { return ::hx::Val( mergeCancellable_dyn() ); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"set_pathNameDynId") ) { return ::hx::Val( set_pathNameDynId_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

bool HScriptParams_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 16:
		if (HX_FIELD_EQ(inName,"OPTIONAL_DEFAULT") ) { outValue = ( OPTIONAL_DEFAULT ); return true; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"RUN_BEFORE_DEFAULT") ) { outValue = ( RUN_BEFORE_DEFAULT ); return true; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"CANCELLABLE_DEFAULT") ) { outValue = ( CANCELLABLE_DEFAULT ); return true; }
	}
	return false;
}

::hx::Val HScriptParams_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"context") ) { context=inValue.Cast< ::Array< ::String > >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"optional") ) { optional=inValue.Cast<  ::Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pathName") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_pathName(inValue.Cast< ::String >()) );pathName=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"runBefore") ) { runBefore=inValue.Cast<  ::Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"cancellable") ) { cancellable=inValue.Cast<  ::Dynamic >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"pathNameDynId") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_pathNameDynId(inValue.Cast< ::String >()) );pathNameDynId=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool HScriptParams_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 16:
		if (HX_FIELD_EQ(inName,"OPTIONAL_DEFAULT") ) { OPTIONAL_DEFAULT=ioValue.Cast< bool >(); return true; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"RUN_BEFORE_DEFAULT") ) { RUN_BEFORE_DEFAULT=ioValue.Cast< bool >(); return true; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"CANCELLABLE_DEFAULT") ) { CANCELLABLE_DEFAULT=ioValue.Cast< bool >(); return true; }
	}
	return false;
}

void HScriptParams_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("context",ef,95,77,19));
	outFields->push(HX_("cancellable",4c,0c,aa,7a));
	outFields->push(HX_("runBefore",2a,ba,8e,c0));
	outFields->push(HX_("optional",a0,af,6e,1e));
	outFields->push(HX_("pathName",90,ba,9e,3e));
	outFields->push(HX_("pathNameDynId",c4,f6,b0,70));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo HScriptParams_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /* ::Array< ::String > */ ,(int)offsetof(HScriptParams_obj,context),HX_("context",ef,95,77,19)},
	{::hx::fsObject /*  ::Dynamic */ ,(int)offsetof(HScriptParams_obj,cancellable),HX_("cancellable",4c,0c,aa,7a)},
	{::hx::fsObject /*  ::Dynamic */ ,(int)offsetof(HScriptParams_obj,runBefore),HX_("runBefore",2a,ba,8e,c0)},
	{::hx::fsObject /*  ::Dynamic */ ,(int)offsetof(HScriptParams_obj,optional),HX_("optional",a0,af,6e,1e)},
	{::hx::fsString,(int)offsetof(HScriptParams_obj,pathName),HX_("pathName",90,ba,9e,3e)},
	{::hx::fsString,(int)offsetof(HScriptParams_obj,pathNameDynId),HX_("pathNameDynId",c4,f6,b0,70)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo HScriptParams_obj_sStaticStorageInfo[] = {
	{::hx::fsBool,(void *) &HScriptParams_obj::CANCELLABLE_DEFAULT,HX_("CANCELLABLE_DEFAULT",4e,2a,8c,df)},
	{::hx::fsBool,(void *) &HScriptParams_obj::RUN_BEFORE_DEFAULT,HX_("RUN_BEFORE_DEFAULT",75,2b,cc,dd)},
	{::hx::fsBool,(void *) &HScriptParams_obj::OPTIONAL_DEFAULT,HX_("OPTIONAL_DEFAULT",c2,e5,fc,20)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static ::String HScriptParams_obj_sMemberFields[] = {
	HX_("context",ef,95,77,19),
	HX_("cancellable",4c,0c,aa,7a),
	HX_("runBefore",2a,ba,8e,c0),
	HX_("optional",a0,af,6e,1e),
	HX_("pathName",90,ba,9e,3e),
	HX_("set_pathName",0d,92,b1,08),
	HX_("pathNameDynId",c4,f6,b0,70),
	HX_("set_pathNameDynId",27,da,8e,9a),
	HX_("mergeContext",17,62,3c,ce),
	HX_("mergeCancellable",74,0c,cc,a7),
	HX_("mergeRunBefore",52,e0,3c,c9),
	HX_("mergeOptional",78,86,dc,95),
	HX_("mergePathName",68,91,0c,b6),
	HX_("copy",b5,bb,c4,41),
	HX_("merge",b8,a2,c6,05),
	HX_("toString",ac,d0,6e,38),
	::String(null()) };

static void HScriptParams_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HScriptParams_obj::CANCELLABLE_DEFAULT,"CANCELLABLE_DEFAULT");
	HX_MARK_MEMBER_NAME(HScriptParams_obj::RUN_BEFORE_DEFAULT,"RUN_BEFORE_DEFAULT");
	HX_MARK_MEMBER_NAME(HScriptParams_obj::OPTIONAL_DEFAULT,"OPTIONAL_DEFAULT");
};

#ifdef HXCPP_VISIT_ALLOCS
static void HScriptParams_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HScriptParams_obj::CANCELLABLE_DEFAULT,"CANCELLABLE_DEFAULT");
	HX_VISIT_MEMBER_NAME(HScriptParams_obj::RUN_BEFORE_DEFAULT,"RUN_BEFORE_DEFAULT");
	HX_VISIT_MEMBER_NAME(HScriptParams_obj::OPTIONAL_DEFAULT,"OPTIONAL_DEFAULT");
};

#endif

::hx::Class HScriptParams_obj::__mClass;

static ::String HScriptParams_obj_sStaticFields[] = {
	HX_("CANCELLABLE_DEFAULT",4e,2a,8c,df),
	HX_("RUN_BEFORE_DEFAULT",75,2b,cc,dd),
	HX_("OPTIONAL_DEFAULT",c2,e5,fc,20),
	::String(null())
};

void HScriptParams_obj::__register()
{
	HScriptParams_obj _hx_dummy;
	HScriptParams_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("polymod.hscript.HScriptParams",66,50,3a,d4);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &HScriptParams_obj::__GetStatic;
	__mClass->mSetStaticField = &HScriptParams_obj::__SetStatic;
	__mClass->mMarkFunc = HScriptParams_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(HScriptParams_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(HScriptParams_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< HScriptParams_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = HScriptParams_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = HScriptParams_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = HScriptParams_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void HScriptParams_obj::__boot()
{
{
            	HX_STACKFRAME(&_hx_pos_b9dc96b340209742_44_boot)
HXDLIN(  44)		CANCELLABLE_DEFAULT = false;
            	}
{
            	HX_STACKFRAME(&_hx_pos_b9dc96b340209742_53_boot)
HXDLIN(  53)		RUN_BEFORE_DEFAULT = false;
            	}
{
            	HX_STACKFRAME(&_hx_pos_b9dc96b340209742_62_boot)
HXDLIN(  62)		OPTIONAL_DEFAULT = false;
            	}
}

} // end namespace polymod
} // end namespace hscript
