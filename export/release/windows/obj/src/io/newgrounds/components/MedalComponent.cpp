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
#ifndef INCLUDED_io_newgrounds_components_MedalComponent
#include <io/newgrounds/components/MedalComponent.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_e83152b561156c48_9_new,"io.newgrounds.components.MedalComponent","new",0x0464a176,"io.newgrounds.components.MedalComponent.new","io/newgrounds/components/MedalComponent.hx",9,0x4b954b39)
HX_LOCAL_STACK_FRAME(_hx_pos_e83152b561156c48_13_unlock,"io.newgrounds.components.MedalComponent","unlock",0x7f9f236e,"io.newgrounds.components.MedalComponent.unlock","io/newgrounds/components/MedalComponent.hx",13,0x4b954b39)
HX_LOCAL_STACK_FRAME(_hx_pos_e83152b561156c48_19_getList,"io.newgrounds.components.MedalComponent","getList",0xd053e02a,"io.newgrounds.components.MedalComponent.getList","io/newgrounds/components/MedalComponent.hx",19,0x4b954b39)
namespace io{
namespace newgrounds{
namespace components{

void MedalComponent_obj::__construct( ::io::newgrounds::NGLite core){
            	HX_STACKFRAME(&_hx_pos_e83152b561156c48_9_new)
HXDLIN(   9)		super::__construct(core);
            	}

Dynamic MedalComponent_obj::__CreateEmpty() { return new MedalComponent_obj; }

void *MedalComponent_obj::_hx_vtable = 0;

Dynamic MedalComponent_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< MedalComponent_obj > _hx_result = new MedalComponent_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool MedalComponent_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x1718a611) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x1718a611;
	} else {
		return inClassId==(int)0x3c6255f2;
	}
}

 ::io::newgrounds::Call MedalComponent_obj::unlock(int id){
            	HX_GC_STACKFRAME(&_hx_pos_e83152b561156c48_13_unlock)
HXDLIN(  13)		return  ::io::newgrounds::Call_obj::__alloc( HX_CTX ,this->_core,HX_("Medal.unlock",7b,04,94,a8),true,true)->addComponentParameter(HX_("id",db,5b,00,00),id,null());
            	}


HX_DEFINE_DYNAMIC_FUNC1(MedalComponent_obj,unlock,return )

 ::io::newgrounds::Call MedalComponent_obj::getList(){
            	HX_GC_STACKFRAME(&_hx_pos_e83152b561156c48_19_getList)
HXDLIN(  19)		return  ::io::newgrounds::Call_obj::__alloc( HX_CTX ,this->_core,HX_("Medal.getList",7d,ea,a3,7d),null(),null());
            	}


HX_DEFINE_DYNAMIC_FUNC0(MedalComponent_obj,getList,return )


::hx::ObjectPtr< MedalComponent_obj > MedalComponent_obj::__new( ::io::newgrounds::NGLite core) {
	::hx::ObjectPtr< MedalComponent_obj > __this = new MedalComponent_obj();
	__this->__construct(core);
	return __this;
}

::hx::ObjectPtr< MedalComponent_obj > MedalComponent_obj::__alloc(::hx::Ctx *_hx_ctx, ::io::newgrounds::NGLite core) {
	MedalComponent_obj *__this = (MedalComponent_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(MedalComponent_obj), true, "io.newgrounds.components.MedalComponent"));
	*(void **)__this = MedalComponent_obj::_hx_vtable;
	__this->__construct(core);
	return __this;
}

MedalComponent_obj::MedalComponent_obj()
{
}

::hx::Val MedalComponent_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"unlock") ) { return ::hx::Val( unlock_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"getList") ) { return ::hx::Val( getList_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *MedalComponent_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *MedalComponent_obj_sStaticStorageInfo = 0;
#endif

static ::String MedalComponent_obj_sMemberFields[] = {
	HX_("unlock",c4,a2,8c,65),
	HX_("getList",14,cc,35,1a),
	::String(null()) };

::hx::Class MedalComponent_obj::__mClass;

void MedalComponent_obj::__register()
{
	MedalComponent_obj _hx_dummy;
	MedalComponent_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("io.newgrounds.components.MedalComponent",84,6e,75,f2);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(MedalComponent_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< MedalComponent_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = MedalComponent_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = MedalComponent_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace io
} // end namespace newgrounds
} // end namespace components
