#include <hxcpp.h>

#ifndef INCLUDED_hscript_ModuleDecl
#include <hscript/ModuleDecl.h>
#endif
#ifndef INCLUDED_hscript_Parser
#include <hscript/Parser.h>
#endif
#ifndef INCLUDED_polymod_hscript_PolymodParserEx
#include <polymod/hscript/PolymodParserEx.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_41825c838ee3f202_5_new,"polymod.hscript.PolymodParserEx","new",0x1f18b627,"polymod.hscript.PolymodParserEx.new","polymod/hscript/PolymodParserEx.hx",5,0xb85f5cab)
HX_LOCAL_STACK_FRAME(_hx_pos_41825c838ee3f202_8_parseModule,"polymod.hscript.PolymodParserEx","parseModule",0xab6a6606,"polymod.hscript.PolymodParserEx.parseModule","polymod/hscript/PolymodParserEx.hx",8,0xb85f5cab)
namespace polymod{
namespace hscript{

void PolymodParserEx_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_41825c838ee3f202_5_new)
HXDLIN(   5)		super::__construct();
            	}

Dynamic PolymodParserEx_obj::__CreateEmpty() { return new PolymodParserEx_obj; }

void *PolymodParserEx_obj::_hx_vtable = 0;

Dynamic PolymodParserEx_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< PolymodParserEx_obj > _hx_result = new PolymodParserEx_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool PolymodParserEx_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x1b857072) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x1b857072;
	} else {
		return inClassId==(int)0x5b61440b;
	}
}

::Array< ::Dynamic> PolymodParserEx_obj::parseModule(::String content,::String __o_origin){
            		::String origin = __o_origin;
            		if (::hx::IsNull(__o_origin)) origin = HX_("hscript",73,8c,18,2c);
            	HX_STACKFRAME(&_hx_pos_41825c838ee3f202_8_parseModule)
HXLINE(   9)		::Array< ::Dynamic> decls = this->super::parseModule(content,origin);
HXLINE(  10)		return decls;
            	}



::hx::ObjectPtr< PolymodParserEx_obj > PolymodParserEx_obj::__new() {
	::hx::ObjectPtr< PolymodParserEx_obj > __this = new PolymodParserEx_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< PolymodParserEx_obj > PolymodParserEx_obj::__alloc(::hx::Ctx *_hx_ctx) {
	PolymodParserEx_obj *__this = (PolymodParserEx_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(PolymodParserEx_obj), true, "polymod.hscript.PolymodParserEx"));
	*(void **)__this = PolymodParserEx_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

PolymodParserEx_obj::PolymodParserEx_obj()
{
}

::hx::Val PolymodParserEx_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"parseModule") ) { return ::hx::Val( parseModule_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *PolymodParserEx_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *PolymodParserEx_obj_sStaticStorageInfo = 0;
#endif

static ::String PolymodParserEx_obj_sMemberFields[] = {
	HX_("parseModule",3f,e1,0f,3c),
	::String(null()) };

::hx::Class PolymodParserEx_obj::__mClass;

void PolymodParserEx_obj::__register()
{
	PolymodParserEx_obj _hx_dummy;
	PolymodParserEx_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("polymod.hscript.PolymodParserEx",b5,16,93,b2);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(PolymodParserEx_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< PolymodParserEx_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = PolymodParserEx_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = PolymodParserEx_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace polymod
} // end namespace hscript
