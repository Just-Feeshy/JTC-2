#include <hxcpp.h>

#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_lime_utils_AssetLibrary
#include <lime/utils/AssetLibrary.h>
#endif
#ifndef INCLUDED_polymod_backends_LimeModLibrary
#include <polymod/backends/LimeModLibrary.h>
#endif
#ifndef INCLUDED_polymod_backends__LimeBackend_IdAndLibrary
#include <polymod/backends/_LimeBackend/IdAndLibrary.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_04fa384cfca16a40_720_new,"polymod.backends._LimeBackend.IdAndLibrary","new",0x62fe42a8,"polymod.backends._LimeBackend.IdAndLibrary.new","polymod/backends/LimeBackend.hx",720,0xcff7dfd6)
namespace polymod{
namespace backends{
namespace _LimeBackend{

void IdAndLibrary_obj::__construct(::String id, ::haxe::ds::StringMap libs, ::polymod::backends::LimeModLibrary l){
            	HX_STACKFRAME(&_hx_pos_04fa384cfca16a40_720_new)
HXLINE( 721)		this->fallbackId = id;
HXLINE( 722)		int colonIndex = id.indexOf(HX_(":",3a,00,00,00),null());
HXLINE( 723)		this->lib = id.substring(0,colonIndex);
HXLINE( 724)		this->nakedId = id.substring((colonIndex + 1),null());
HXLINE( 725)		if (::hx::IsNotNull( l )) {
HXLINE( 727)			this->library = l;
            		}
            		else {
HXLINE( 729)			if (::hx::IsNotNull( libs )) {
HXLINE( 731)				bool _hx_tmp;
HXDLIN( 731)				if ((this->lib != HX_("",00,00,00,00))) {
HXLINE( 731)					_hx_tmp = ::hx::IsNull( this->lib );
            				}
            				else {
HXLINE( 731)					_hx_tmp = true;
            				}
HXDLIN( 731)				if (_hx_tmp) {
HXLINE( 733)					this->lib = HX_("default",c1,d8,c3,9b);
            				}
HXLINE( 735)				this->library = ( ( ::polymod::backends::LimeModLibrary)(libs->get(this->lib)) );
            			}
            		}
HXLINE( 737)		bool _hx_tmp;
HXDLIN( 737)		bool _hx_tmp1;
HXDLIN( 737)		if (::hx::IsNotNull( this->library )) {
HXLINE( 737)			_hx_tmp1 = ::hx::IsNotNull( this->library->pathPrefix );
            		}
            		else {
HXLINE( 737)			_hx_tmp1 = false;
            		}
HXDLIN( 737)		if (_hx_tmp1) {
HXLINE( 737)			_hx_tmp = (this->library->pathPrefix != HX_("",00,00,00,00));
            		}
            		else {
HXLINE( 737)			_hx_tmp = false;
            		}
HXDLIN( 737)		if (_hx_tmp) {
HXLINE( 739)			this->modId = (((HX_("",00,00,00,00) + this->library->pathPrefix) + HX_("/",2f,00,00,00)) + this->nakedId);
            		}
HXLINE( 741)		this->modId = this->nakedId;
            	}

Dynamic IdAndLibrary_obj::__CreateEmpty() { return new IdAndLibrary_obj; }

void *IdAndLibrary_obj::_hx_vtable = 0;

Dynamic IdAndLibrary_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< IdAndLibrary_obj > _hx_result = new IdAndLibrary_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return _hx_result;
}

bool IdAndLibrary_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x082cc890;
}


::hx::ObjectPtr< IdAndLibrary_obj > IdAndLibrary_obj::__new(::String id, ::haxe::ds::StringMap libs, ::polymod::backends::LimeModLibrary l) {
	::hx::ObjectPtr< IdAndLibrary_obj > __this = new IdAndLibrary_obj();
	__this->__construct(id,libs,l);
	return __this;
}

::hx::ObjectPtr< IdAndLibrary_obj > IdAndLibrary_obj::__alloc(::hx::Ctx *_hx_ctx,::String id, ::haxe::ds::StringMap libs, ::polymod::backends::LimeModLibrary l) {
	IdAndLibrary_obj *__this = (IdAndLibrary_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(IdAndLibrary_obj), true, "polymod.backends._LimeBackend.IdAndLibrary"));
	*(void **)__this = IdAndLibrary_obj::_hx_vtable;
	__this->__construct(id,libs,l);
	return __this;
}

IdAndLibrary_obj::IdAndLibrary_obj()
{
}

void IdAndLibrary_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(IdAndLibrary);
	HX_MARK_MEMBER_NAME(library,"library");
	HX_MARK_MEMBER_NAME(lib,"lib");
	HX_MARK_MEMBER_NAME(modId,"modId");
	HX_MARK_MEMBER_NAME(nakedId,"nakedId");
	HX_MARK_MEMBER_NAME(fallbackId,"fallbackId");
	HX_MARK_END_CLASS();
}

void IdAndLibrary_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(library,"library");
	HX_VISIT_MEMBER_NAME(lib,"lib");
	HX_VISIT_MEMBER_NAME(modId,"modId");
	HX_VISIT_MEMBER_NAME(nakedId,"nakedId");
	HX_VISIT_MEMBER_NAME(fallbackId,"fallbackId");
}

::hx::Val IdAndLibrary_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"lib") ) { return ::hx::Val( lib ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"modId") ) { return ::hx::Val( modId ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"library") ) { return ::hx::Val( library ); }
		if (HX_FIELD_EQ(inName,"nakedId") ) { return ::hx::Val( nakedId ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"fallbackId") ) { return ::hx::Val( fallbackId ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val IdAndLibrary_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"lib") ) { lib=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"modId") ) { modId=inValue.Cast< ::String >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"library") ) { library=inValue.Cast<  ::polymod::backends::LimeModLibrary >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nakedId") ) { nakedId=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"fallbackId") ) { fallbackId=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void IdAndLibrary_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("library",fb,26,70,3f));
	outFields->push(HX_("lib",45,4f,52,00));
	outFields->push(HX_("modId",3d,0b,58,0c));
	outFields->push(HX_("nakedId",f2,c6,c5,85));
	outFields->push(HX_("fallbackId",9d,fc,13,82));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo IdAndLibrary_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::polymod::backends::LimeModLibrary */ ,(int)offsetof(IdAndLibrary_obj,library),HX_("library",fb,26,70,3f)},
	{::hx::fsString,(int)offsetof(IdAndLibrary_obj,lib),HX_("lib",45,4f,52,00)},
	{::hx::fsString,(int)offsetof(IdAndLibrary_obj,modId),HX_("modId",3d,0b,58,0c)},
	{::hx::fsString,(int)offsetof(IdAndLibrary_obj,nakedId),HX_("nakedId",f2,c6,c5,85)},
	{::hx::fsString,(int)offsetof(IdAndLibrary_obj,fallbackId),HX_("fallbackId",9d,fc,13,82)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *IdAndLibrary_obj_sStaticStorageInfo = 0;
#endif

static ::String IdAndLibrary_obj_sMemberFields[] = {
	HX_("library",fb,26,70,3f),
	HX_("lib",45,4f,52,00),
	HX_("modId",3d,0b,58,0c),
	HX_("nakedId",f2,c6,c5,85),
	HX_("fallbackId",9d,fc,13,82),
	::String(null()) };

::hx::Class IdAndLibrary_obj::__mClass;

void IdAndLibrary_obj::__register()
{
	IdAndLibrary_obj _hx_dummy;
	IdAndLibrary_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("polymod.backends._LimeBackend.IdAndLibrary",b6,0e,36,8a);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(IdAndLibrary_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< IdAndLibrary_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = IdAndLibrary_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = IdAndLibrary_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace polymod
} // end namespace backends
} // end namespace _LimeBackend
