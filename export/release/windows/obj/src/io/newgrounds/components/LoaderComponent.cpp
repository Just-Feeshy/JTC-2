#include <hxcpp.h>

#ifndef INCLUDED_io_newgrounds_Call
#include <io/newgrounds/Call.h>
#endif
#ifndef INCLUDED_io_newgrounds_ICallable
#include <io/newgrounds/ICallable.h>
#endif
#ifndef INCLUDED_io_newgrounds_NGLite
#include <io/newgrounds/NGLite.h>
#endif
#ifndef INCLUDED_io_newgrounds_components_Component
#include <io/newgrounds/components/Component.h>
#endif
#ifndef INCLUDED_io_newgrounds_components_LoaderComponent
#include <io/newgrounds/components/LoaderComponent.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_00e1f7847e9f2f74_8_new,"io.newgrounds.components.LoaderComponent","new",0xdf59289e,"io.newgrounds.components.LoaderComponent.new","io/newgrounds/components/LoaderComponent.hx",8,0xde01b733)
HX_LOCAL_STACK_FRAME(_hx_pos_00e1f7847e9f2f74_12_loadAuthorUrl,"io.newgrounds.components.LoaderComponent","loadAuthorUrl",0x97db045c,"io.newgrounds.components.LoaderComponent.loadAuthorUrl","io/newgrounds/components/LoaderComponent.hx",12,0xde01b733)
HX_LOCAL_STACK_FRAME(_hx_pos_00e1f7847e9f2f74_19_loadMoreGames,"io.newgrounds.components.LoaderComponent","loadMoreGames",0x8a8e9724,"io.newgrounds.components.LoaderComponent.loadMoreGames","io/newgrounds/components/LoaderComponent.hx",19,0xde01b733)
HX_LOCAL_STACK_FRAME(_hx_pos_00e1f7847e9f2f74_26_loadNewgrounds,"io.newgrounds.components.LoaderComponent","loadNewgrounds",0xec7e4df4,"io.newgrounds.components.LoaderComponent.loadNewgrounds","io/newgrounds/components/LoaderComponent.hx",26,0xde01b733)
HX_LOCAL_STACK_FRAME(_hx_pos_00e1f7847e9f2f74_33_loadOfficialUrl,"io.newgrounds.components.LoaderComponent","loadOfficialUrl",0x58442cbc,"io.newgrounds.components.LoaderComponent.loadOfficialUrl","io/newgrounds/components/LoaderComponent.hx",33,0xde01b733)
HX_LOCAL_STACK_FRAME(_hx_pos_00e1f7847e9f2f74_40_loadReferral,"io.newgrounds.components.LoaderComponent","loadReferral",0x9900d5a5,"io.newgrounds.components.LoaderComponent.loadReferral","io/newgrounds/components/LoaderComponent.hx",40,0xde01b733)
namespace io{
namespace newgrounds{
namespace components{

void LoaderComponent_obj::__construct( ::io::newgrounds::NGLite core){
            	HX_STACKFRAME(&_hx_pos_00e1f7847e9f2f74_8_new)
HXDLIN(   8)		super::__construct(core);
            	}

Dynamic LoaderComponent_obj::__CreateEmpty() { return new LoaderComponent_obj; }

void *LoaderComponent_obj::_hx_vtable = 0;

Dynamic LoaderComponent_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< LoaderComponent_obj > _hx_result = new LoaderComponent_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool LoaderComponent_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x0edada7e) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x0edada7e;
	} else {
		return inClassId==(int)0x1718a611;
	}
}

 ::io::newgrounds::Call LoaderComponent_obj::loadAuthorUrl(::hx::Null< bool >  __o_redirect){
            		bool redirect = __o_redirect.Default(false);
            	HX_GC_STACKFRAME(&_hx_pos_00e1f7847e9f2f74_12_loadAuthorUrl)
HXDLIN(  12)		return  ::io::newgrounds::Call_obj::__alloc( HX_CTX ,this->_core,HX_("Loader.loadAuthorUrl",23,3d,b4,d4),null(),null())->addComponentParameter(HX_("host",68,cf,12,45),this->_core->host,null())->addComponentParameter(HX_("redirect",1c,f7,d8,9c),redirect,true);
            	}


HX_DEFINE_DYNAMIC_FUNC1(LoaderComponent_obj,loadAuthorUrl,return )

 ::io::newgrounds::Call LoaderComponent_obj::loadMoreGames(::hx::Null< bool >  __o_redirect){
            		bool redirect = __o_redirect.Default(false);
            	HX_GC_STACKFRAME(&_hx_pos_00e1f7847e9f2f74_19_loadMoreGames)
HXDLIN(  19)		return  ::io::newgrounds::Call_obj::__alloc( HX_CTX ,this->_core,HX_("Loader.loadMoreGames",eb,cf,67,c7),null(),null())->addComponentParameter(HX_("host",68,cf,12,45),this->_core->host,null())->addComponentParameter(HX_("redirect",1c,f7,d8,9c),redirect,true);
            	}


HX_DEFINE_DYNAMIC_FUNC1(LoaderComponent_obj,loadMoreGames,return )

 ::io::newgrounds::Call LoaderComponent_obj::loadNewgrounds(::hx::Null< bool >  __o_redirect){
            		bool redirect = __o_redirect.Default(false);
            	HX_GC_STACKFRAME(&_hx_pos_00e1f7847e9f2f74_26_loadNewgrounds)
HXDLIN(  26)		return  ::io::newgrounds::Call_obj::__alloc( HX_CTX ,this->_core,HX_("Loader.loadNewgrounds",4d,c3,b6,ed),null(),null())->addComponentParameter(HX_("host",68,cf,12,45),this->_core->host,null())->addComponentParameter(HX_("redirect",1c,f7,d8,9c),redirect,true);
            	}


HX_DEFINE_DYNAMIC_FUNC1(LoaderComponent_obj,loadNewgrounds,return )

 ::io::newgrounds::Call LoaderComponent_obj::loadOfficialUrl(::hx::Null< bool >  __o_redirect){
            		bool redirect = __o_redirect.Default(false);
            	HX_GC_STACKFRAME(&_hx_pos_00e1f7847e9f2f74_33_loadOfficialUrl)
HXDLIN(  33)		return  ::io::newgrounds::Call_obj::__alloc( HX_CTX ,this->_core,HX_("Loader.loadOfficialUrl",43,65,72,68),null(),null())->addComponentParameter(HX_("host",68,cf,12,45),this->_core->host,null())->addComponentParameter(HX_("redirect",1c,f7,d8,9c),redirect,true);
            	}


HX_DEFINE_DYNAMIC_FUNC1(LoaderComponent_obj,loadOfficialUrl,return )

 ::io::newgrounds::Call LoaderComponent_obj::loadReferral(::hx::Null< bool >  __o_redirect){
            		bool redirect = __o_redirect.Default(false);
            	HX_GC_STACKFRAME(&_hx_pos_00e1f7847e9f2f74_40_loadReferral)
HXDLIN(  40)		return  ::io::newgrounds::Call_obj::__alloc( HX_CTX ,this->_core,HX_("Loader.loadReferral",be,12,dd,bc),null(),null())->addComponentParameter(HX_("host",68,cf,12,45),this->_core->host,null())->addComponentParameter(HX_("redirect",1c,f7,d8,9c),redirect,true);
            	}


HX_DEFINE_DYNAMIC_FUNC1(LoaderComponent_obj,loadReferral,return )


::hx::ObjectPtr< LoaderComponent_obj > LoaderComponent_obj::__new( ::io::newgrounds::NGLite core) {
	::hx::ObjectPtr< LoaderComponent_obj > __this = new LoaderComponent_obj();
	__this->__construct(core);
	return __this;
}

::hx::ObjectPtr< LoaderComponent_obj > LoaderComponent_obj::__alloc(::hx::Ctx *_hx_ctx, ::io::newgrounds::NGLite core) {
	LoaderComponent_obj *__this = (LoaderComponent_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(LoaderComponent_obj), true, "io.newgrounds.components.LoaderComponent"));
	*(void **)__this = LoaderComponent_obj::_hx_vtable;
	__this->__construct(core);
	return __this;
}

LoaderComponent_obj::LoaderComponent_obj()
{
}

::hx::Val LoaderComponent_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"loadReferral") ) { return ::hx::Val( loadReferral_dyn() ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"loadAuthorUrl") ) { return ::hx::Val( loadAuthorUrl_dyn() ); }
		if (HX_FIELD_EQ(inName,"loadMoreGames") ) { return ::hx::Val( loadMoreGames_dyn() ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"loadNewgrounds") ) { return ::hx::Val( loadNewgrounds_dyn() ); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"loadOfficialUrl") ) { return ::hx::Val( loadOfficialUrl_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *LoaderComponent_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *LoaderComponent_obj_sStaticStorageInfo = 0;
#endif

static ::String LoaderComponent_obj_sMemberFields[] = {
	HX_("loadAuthorUrl",9e,b2,d9,35),
	HX_("loadMoreGames",66,45,8d,28),
	HX_("loadNewgrounds",72,19,58,8d),
	HX_("loadOfficialUrl",7e,6f,fc,75),
	HX_("loadReferral",a3,25,68,d5),
	::String(null()) };

::hx::Class LoaderComponent_obj::__mClass;

void LoaderComponent_obj::__register()
{
	LoaderComponent_obj _hx_dummy;
	LoaderComponent_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("io.newgrounds.components.LoaderComponent",ac,41,7d,a9);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(LoaderComponent_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< LoaderComponent_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = LoaderComponent_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = LoaderComponent_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace io
} // end namespace newgrounds
} // end namespace components
