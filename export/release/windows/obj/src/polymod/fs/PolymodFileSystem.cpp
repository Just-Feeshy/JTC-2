#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_polymod_Polymod
#include <polymod/Polymod.h>
#endif
#ifndef INCLUDED_polymod_fs_IFileSystem
#include <polymod/fs/IFileSystem.h>
#endif
#ifndef INCLUDED_polymod_fs_PolymodFileSystem
#include <polymod/fs/PolymodFileSystem.h>
#endif
#ifndef INCLUDED_polymod_fs_SysFileSystem
#include <polymod/fs/SysFileSystem.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_229e9118b7a14b67_14_makeFileSystem,"polymod.fs.PolymodFileSystem","makeFileSystem",0x8f424faf,"polymod.fs.PolymodFileSystem.makeFileSystem","polymod/fs/PolymodFileSystem.hx",14,0x1f0c5646)
HX_LOCAL_STACK_FRAME(_hx_pos_229e9118b7a14b67_41__detectFileSystem,"polymod.fs.PolymodFileSystem","_detectFileSystem",0x97531557,"polymod.fs.PolymodFileSystem._detectFileSystem","polymod/fs/PolymodFileSystem.hx",41,0x1f0c5646)
namespace polymod{
namespace fs{

void PolymodFileSystem_obj::__construct() { }

Dynamic PolymodFileSystem_obj::__CreateEmpty() { return new PolymodFileSystem_obj; }

void *PolymodFileSystem_obj::_hx_vtable = 0;

Dynamic PolymodFileSystem_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< PolymodFileSystem_obj > _hx_result = new PolymodFileSystem_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool PolymodFileSystem_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x4abdba0a;
}

::Dynamic PolymodFileSystem_obj::makeFileSystem( ::Dynamic cls, ::Dynamic params){
            	HX_STACKFRAME(&_hx_pos_229e9118b7a14b67_14_makeFileSystem)
HXDLIN(  14)		if (::hx::IsNull( cls )) {
HXLINE(  17)			return ::polymod::fs::PolymodFileSystem_obj::_detectFileSystem(params);
            		}
            		else {
HXLINE(  19)			if (::Std_obj::isOfType(cls,::hx::ClassOf< ::polymod::fs::IFileSystem >())) {
HXLINE(  21)				return cls;
            			}
            			else {
HXLINE(  23)				if (::Std_obj::isOfType(cls,::hx::ClassOf< ::hx::Class >())) {
HXLINE(  26)					return ::Type_obj::createInstance(cls,::cpp::VirtualArray_obj::__new(1)->init(0,params));
            				}
            				else {
HXLINE(  30)					::polymod::Polymod_obj::error(HX_("bad_custom_filesystem",3f,07,25,1b),HX_("Passed an unknown type for a custom filesystem. Reverting to default...",67,80,99,57),null());
HXLINE(  31)					return ::polymod::fs::PolymodFileSystem_obj::makeFileSystem(null(),params);
            				}
            			}
            		}
HXLINE(  14)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(PolymodFileSystem_obj,makeFileSystem,return )

 ::polymod::fs::SysFileSystem PolymodFileSystem_obj::_detectFileSystem( ::Dynamic params){
            	HX_GC_STACKFRAME(&_hx_pos_229e9118b7a14b67_41__detectFileSystem)
HXDLIN(  41)		return  ::polymod::fs::SysFileSystem_obj::__alloc( HX_CTX ,params);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(PolymodFileSystem_obj,_detectFileSystem,return )


PolymodFileSystem_obj::PolymodFileSystem_obj()
{
}

bool PolymodFileSystem_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 14:
		if (HX_FIELD_EQ(inName,"makeFileSystem") ) { outValue = makeFileSystem_dyn(); return true; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_detectFileSystem") ) { outValue = _detectFileSystem_dyn(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *PolymodFileSystem_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *PolymodFileSystem_obj_sStaticStorageInfo = 0;
#endif

::hx::Class PolymodFileSystem_obj::__mClass;

static ::String PolymodFileSystem_obj_sStaticFields[] = {
	HX_("makeFileSystem",19,12,97,6e),
	HX_("_detectFileSystem",2d,31,f4,85),
	::String(null())
};

void PolymodFileSystem_obj::__register()
{
	PolymodFileSystem_obj _hx_dummy;
	PolymodFileSystem_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("polymod.fs.PolymodFileSystem",18,92,e3,1f);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &PolymodFileSystem_obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(PolymodFileSystem_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< PolymodFileSystem_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = PolymodFileSystem_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = PolymodFileSystem_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace polymod
} // end namespace fs
