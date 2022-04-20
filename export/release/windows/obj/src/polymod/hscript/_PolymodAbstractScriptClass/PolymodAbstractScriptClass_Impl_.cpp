#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_haxe_Exception
#include <haxe/Exception.h>
#endif
#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_hscript_Error
#include <hscript/Error.h>
#endif
#ifndef INCLUDED_hscript_Expr
#include <hscript/Expr.h>
#endif
#ifndef INCLUDED_hscript_Interp
#include <hscript/Interp.h>
#endif
#ifndef INCLUDED_polymod_hscript_PolymodInterpEx
#include <polymod/hscript/PolymodInterpEx.h>
#endif
#ifndef INCLUDED_polymod_hscript_PolymodScriptClass
#include <polymod/hscript/PolymodScriptClass.h>
#endif
#ifndef INCLUDED_polymod_hscript__PolymodAbstractScriptClass_PolymodAbstractScriptClass_Impl_
#include <polymod/hscript/_PolymodAbstractScriptClass/PolymodAbstractScriptClass_Impl_.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_e5741ac3fc6c4841_8_resolveField,"polymod.hscript._PolymodAbstractScriptClass.PolymodAbstractScriptClass_Impl_","resolveField",0x0877f2da,"polymod.hscript._PolymodAbstractScriptClass.PolymodAbstractScriptClass_Impl_.resolveField","polymod/hscript/PolymodAbstractScriptClass.hx",8,0x257f27b4)
HX_LOCAL_STACK_FRAME(_hx_pos_e5741ac3fc6c4841_30_resolveField,"polymod.hscript._PolymodAbstractScriptClass.PolymodAbstractScriptClass_Impl_","resolveField",0x0877f2da,"polymod.hscript._PolymodAbstractScriptClass.PolymodAbstractScriptClass_Impl_.resolveField","polymod/hscript/PolymodAbstractScriptClass.hx",30,0x257f27b4)
HX_LOCAL_STACK_FRAME(_hx_pos_e5741ac3fc6c4841_31_resolveField,"polymod.hscript._PolymodAbstractScriptClass.PolymodAbstractScriptClass_Impl_","resolveField",0x0877f2da,"polymod.hscript._PolymodAbstractScriptClass.PolymodAbstractScriptClass_Impl_.resolveField","polymod/hscript/PolymodAbstractScriptClass.hx",31,0x257f27b4)
HX_LOCAL_STACK_FRAME(_hx_pos_e5741ac3fc6c4841_32_resolveField,"polymod.hscript._PolymodAbstractScriptClass.PolymodAbstractScriptClass_Impl_","resolveField",0x0877f2da,"polymod.hscript._PolymodAbstractScriptClass.PolymodAbstractScriptClass_Impl_.resolveField","polymod/hscript/PolymodAbstractScriptClass.hx",32,0x257f27b4)
HX_LOCAL_STACK_FRAME(_hx_pos_e5741ac3fc6c4841_33_resolveField,"polymod.hscript._PolymodAbstractScriptClass.PolymodAbstractScriptClass_Impl_","resolveField",0x0877f2da,"polymod.hscript._PolymodAbstractScriptClass.PolymodAbstractScriptClass_Impl_.resolveField","polymod/hscript/PolymodAbstractScriptClass.hx",33,0x257f27b4)
HX_LOCAL_STACK_FRAME(_hx_pos_e5741ac3fc6c4841_34_resolveField,"polymod.hscript._PolymodAbstractScriptClass.PolymodAbstractScriptClass_Impl_","resolveField",0x0877f2da,"polymod.hscript._PolymodAbstractScriptClass.PolymodAbstractScriptClass_Impl_.resolveField","polymod/hscript/PolymodAbstractScriptClass.hx",34,0x257f27b4)
HX_LOCAL_STACK_FRAME(_hx_pos_e5741ac3fc6c4841_91_fieldRead,"polymod.hscript._PolymodAbstractScriptClass.PolymodAbstractScriptClass_Impl_","fieldRead",0x371bf504,"polymod.hscript._PolymodAbstractScriptClass.PolymodAbstractScriptClass_Impl_.fieldRead","polymod/hscript/PolymodAbstractScriptClass.hx",91,0x257f27b4)
HX_LOCAL_STACK_FRAME(_hx_pos_e5741ac3fc6c4841_95_fieldWrite,"polymod.hscript._PolymodAbstractScriptClass.PolymodAbstractScriptClass_Impl_","fieldWrite",0xeaf93b71,"polymod.hscript._PolymodAbstractScriptClass.PolymodAbstractScriptClass_Impl_.fieldWrite","polymod/hscript/PolymodAbstractScriptClass.hx",95,0x257f27b4)
namespace polymod{
namespace hscript{
namespace _PolymodAbstractScriptClass{

void PolymodAbstractScriptClass_Impl__obj::__construct() { }

Dynamic PolymodAbstractScriptClass_Impl__obj::__CreateEmpty() { return new PolymodAbstractScriptClass_Impl__obj; }

void *PolymodAbstractScriptClass_Impl__obj::_hx_vtable = 0;

Dynamic PolymodAbstractScriptClass_Impl__obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< PolymodAbstractScriptClass_Impl__obj > _hx_result = new PolymodAbstractScriptClass_Impl__obj();
	_hx_result->__construct();
	return _hx_result;
}

bool PolymodAbstractScriptClass_Impl__obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x3a7177cc;
}

 ::Dynamic PolymodAbstractScriptClass_Impl__obj::resolveField( ::polymod::hscript::PolymodScriptClass this1,::String name){
            	HX_STACKFRAME(&_hx_pos_e5741ac3fc6c4841_8_resolveField)
HXLINE(   9)		::String _hx_switch_0 = name;
            		if (  (_hx_switch_0==HX_("callFunction",d6,4d,95,4c)) ){
HXLINE(  18)			return this1->callFunction_dyn();
HXDLIN(  18)			goto _hx_goto_0;
            		}
            		if (  (_hx_switch_0==HX_("createSuperClass",d9,26,35,dd)) ){
HXLINE(  14)			return this1->createSuperClass_dyn();
HXDLIN(  14)			goto _hx_goto_0;
            		}
            		if (  (_hx_switch_0==HX_("findFunction",71,98,d0,01)) ){
HXLINE(  16)			return this1->findFunction_dyn();
HXDLIN(  16)			goto _hx_goto_0;
            		}
            		if (  (_hx_switch_0==HX_("superClass",bd,a8,07,a8)) ){
HXLINE(  12)			return this1->superClass;
HXDLIN(  12)			goto _hx_goto_0;
            		}
            		/* default */{
HXLINE(  20)			if (::hx::IsNotNull( this1->findFunction(name) )) {
HXLINE(  22)				 ::Dynamic fn = this1->findFunction(name);
HXLINE(  23)				int nargs = 0;
HXLINE(  24)				if (::hx::IsNotNull( fn->__Field(HX_("args",5d,8d,74,40),::hx::paccDynamic) )) {
HXLINE(  26)					nargs = ( (::Array< ::Dynamic>)(fn->__Field(HX_("args",5d,8d,74,40),::hx::paccDynamic)) )->length;
            				}
HXLINE(  28)				switch((int)(nargs)){
            					case (int)0: {
            						HX_BEGIN_LOCAL_FUNC_S2(::hx::LocalFunc,_hx_Closure_0,::String,name1, ::Dynamic,_g) HXARGC(0)
            						 ::Dynamic _hx_run(){
            							HX_STACKFRAME(&_hx_pos_e5741ac3fc6c4841_30_resolveField)
HXLINE(  30)							return _g(name1);
            						}
            						HX_END_LOCAL_FUNC0(return)

HXLINE(  30)						 ::Dynamic _g = this1->callFunction0_dyn();
HXDLIN(  30)						::String name1 = name;
HXDLIN(  30)						return  ::Dynamic(new _hx_Closure_0(name1,_g));
            					}
            					break;
            					case (int)1: {
            						HX_BEGIN_LOCAL_FUNC_S2(::hx::LocalFunc,_hx_Closure_1,::String,name1, ::Dynamic,_g) HXARGC(1)
            						 ::Dynamic _hx_run( ::Dynamic arg0){
            							HX_STACKFRAME(&_hx_pos_e5741ac3fc6c4841_31_resolveField)
HXLINE(  31)							return _g(name1,arg0);
            						}
            						HX_END_LOCAL_FUNC1(return)

HXLINE(  31)						 ::Dynamic _g = this1->callFunction1_dyn();
HXDLIN(  31)						::String name1 = name;
HXDLIN(  31)						return  ::Dynamic(new _hx_Closure_1(name1,_g));
            					}
            					break;
            					case (int)2: {
            						HX_BEGIN_LOCAL_FUNC_S2(::hx::LocalFunc,_hx_Closure_2,::String,name1, ::Dynamic,_g) HXARGC(2)
            						 ::Dynamic _hx_run( ::Dynamic arg0, ::Dynamic arg1){
            							HX_STACKFRAME(&_hx_pos_e5741ac3fc6c4841_32_resolveField)
HXLINE(  32)							return _g(name1,arg0,arg1);
            						}
            						HX_END_LOCAL_FUNC2(return)

HXLINE(  32)						 ::Dynamic _g = this1->callFunction2_dyn();
HXDLIN(  32)						::String name1 = name;
HXDLIN(  32)						return  ::Dynamic(new _hx_Closure_2(name1,_g));
            					}
            					break;
            					case (int)3: {
            						HX_BEGIN_LOCAL_FUNC_S2(::hx::LocalFunc,_hx_Closure_3,::String,name1, ::Dynamic,_g) HXARGC(3)
            						 ::Dynamic _hx_run( ::Dynamic arg0, ::Dynamic arg1, ::Dynamic arg2){
            							HX_STACKFRAME(&_hx_pos_e5741ac3fc6c4841_33_resolveField)
HXLINE(  33)							return _g(name1,arg0,arg1,arg2);
            						}
            						HX_END_LOCAL_FUNC3(return)

HXLINE(  33)						 ::Dynamic _g = this1->callFunction3_dyn();
HXDLIN(  33)						::String name1 = name;
HXDLIN(  33)						return  ::Dynamic(new _hx_Closure_3(name1,_g));
            					}
            					break;
            					case (int)4: {
            						HX_BEGIN_LOCAL_FUNC_S2(::hx::LocalFunc,_hx_Closure_4,::String,name1, ::Dynamic,_g) HXARGC(4)
            						 ::Dynamic _hx_run( ::Dynamic arg0, ::Dynamic arg1, ::Dynamic arg2, ::Dynamic arg3){
            							HX_STACKFRAME(&_hx_pos_e5741ac3fc6c4841_34_resolveField)
HXLINE(  34)							return _g(name1,arg0,arg1,arg2,arg3);
            						}
            						HX_END_LOCAL_FUNC4(return)

HXLINE(  34)						 ::Dynamic _g = this1->callFunction4_dyn();
HXDLIN(  34)						::String name1 = name;
HXDLIN(  34)						return  ::Dynamic(new _hx_Closure_4(name1,_g));
            					}
            					break;
            					default:{
HXLINE(  35)						 ::hscript::Error e = ::hscript::Error_obj::ECustom(HX_("only 4 params allowed in script class functions (.bind limitation)",6b,b5,61,a2));
HXDLIN(  35)						HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(e));
            					}
            				}
            			}
            			else {
HXLINE(  38)				if (::hx::IsNotNull( this1->findVar(name) )) {
HXLINE(  40)					 ::Dynamic v = this1->findVar(name);
HXLINE(  42)					 ::Dynamic varValue = null();
HXLINE(  43)					if ((this1->_interp->variables->exists(name) == false)) {
HXLINE(  45)						if (::hx::IsNotNull( v->__Field(HX_("expr",35,fd,1d,43),::hx::paccDynamic) )) {
HXLINE(  47)							varValue = this1->_interp->expr(v->__Field(HX_("expr",35,fd,1d,43),::hx::paccDynamic));
HXLINE(  48)							this1->_interp->variables->set(name,varValue);
            						}
            					}
            					else {
HXLINE(  53)						varValue = this1->_interp->variables->get(name);
            					}
HXLINE(  55)					return varValue;
            				}
            				else {
HXLINE(  57)					if (::Reflect_obj::isFunction(::Reflect_obj::getProperty(this1->superClass,name))) {
HXLINE(  59)						return ::Reflect_obj::getProperty(this1->superClass,name);
            					}
            					else {
HXLINE(  61)						if (::Reflect_obj::hasField(this1->superClass,name)) {
HXLINE(  63)							return ::Reflect_obj::field(this1->superClass,name);
            						}
            						else {
HXLINE(  65)							bool _hx_tmp;
HXDLIN(  65)							if (::hx::IsNotNull( this1->superClass )) {
HXLINE(  65)								_hx_tmp = ::Std_obj::isOfType(this1->superClass,::hx::ClassOf< ::polymod::hscript::PolymodScriptClass >());
            							}
            							else {
HXLINE(  65)								_hx_tmp = false;
            							}
HXDLIN(  65)							if (_hx_tmp) {
HXLINE(  67)								 ::polymod::hscript::PolymodScriptClass superScriptClass = ::hx::TCast<  ::polymod::hscript::PolymodScriptClass >::cast(this1->superClass);
HXLINE(  68)								try {
            									HX_STACK_CATCHABLE( ::Dynamic, 0);
HXLINE(  70)									return ::polymod::hscript::_PolymodAbstractScriptClass::PolymodAbstractScriptClass_Impl__obj::fieldRead(superScriptClass,name);
            								} catch( ::Dynamic _hx_e) {
            									if (_hx_e.IsClass<  ::Dynamic >() ){
            										HX_STACK_BEGIN_CATCH
            										 ::Dynamic _g = _hx_e;
HXLINE(  72)										{
HXLINE(  72)											null();
            										}
            									}
            									else {
            										HX_STACK_DO_THROW(_hx_e);
            									}
            								}
            							}
            						}
            					}
            				}
            			}
            		}
            		_hx_goto_0:;
HXLINE(  78)		if (::hx::IsNull( this1->superClass )) {
HXLINE(  80)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(((((HX_("field '",41,d3,2d,fc) + name) + HX_("' does not exist in script class '",81,39,73,9e)) + this1->get_className()) + HX_("'",27,00,00,00))));
            		}
            		else {
HXLINE(  84)			::String _hx_tmp = ((((HX_("field '",41,d3,2d,fc) + name) + HX_("' does not exist in script class '",81,39,73,9e)) + this1->get_className()) + HX_("' or super class '",f6,d2,52,57));
HXDLIN(  84)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(((_hx_tmp + ::Type_obj::getClassName(::Type_obj::getClass(this1->superClass))) + HX_("'",27,00,00,00))));
            		}
HXLINE(  78)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(PolymodAbstractScriptClass_Impl__obj,resolveField,return )

 ::Dynamic PolymodAbstractScriptClass_Impl__obj::fieldRead( ::polymod::hscript::PolymodScriptClass this1,::String name){
            	HX_STACKFRAME(&_hx_pos_e5741ac3fc6c4841_91_fieldRead)
HXDLIN(  91)		return ::polymod::hscript::_PolymodAbstractScriptClass::PolymodAbstractScriptClass_Impl__obj::resolveField(this1,name);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(PolymodAbstractScriptClass_Impl__obj,fieldRead,return )

 ::Dynamic PolymodAbstractScriptClass_Impl__obj::fieldWrite( ::polymod::hscript::PolymodScriptClass this1,::String name, ::Dynamic value){
            	HX_STACKFRAME(&_hx_pos_e5741ac3fc6c4841_95_fieldWrite)
HXLINE(  99)		if (::hx::IsNotNull( this1->findVar(name) )) {
HXLINE( 101)			this1->_interp->variables->set(name,value);
HXLINE( 102)			return value;
            		}
            		else {
HXLINE( 104)			if (::Reflect_obj::hasField(this1->superClass,name)) {
HXLINE( 106)				::Reflect_obj::setProperty(this1->superClass,name,value);
HXLINE( 107)				return value;
            			}
            			else {
HXLINE( 109)				bool _hx_tmp;
HXDLIN( 109)				if (::hx::IsNotNull( this1->superClass )) {
HXLINE( 109)					_hx_tmp = ::Std_obj::isOfType(this1->superClass,::hx::ClassOf< ::polymod::hscript::PolymodScriptClass >());
            				}
            				else {
HXLINE( 109)					_hx_tmp = false;
            				}
HXDLIN( 109)				if (_hx_tmp) {
HXLINE( 111)					 ::polymod::hscript::PolymodScriptClass superScriptClass = ::hx::TCast<  ::polymod::hscript::PolymodScriptClass >::cast(this1->superClass);
HXLINE( 112)					try {
            						HX_STACK_CATCHABLE( ::Dynamic, 0);
HXLINE( 114)						return ::polymod::hscript::_PolymodAbstractScriptClass::PolymodAbstractScriptClass_Impl__obj::fieldWrite(superScriptClass,name,value);
            					} catch( ::Dynamic _hx_e) {
            						if (_hx_e.IsClass<  ::Dynamic >() ){
            							HX_STACK_BEGIN_CATCH
            							 ::Dynamic _g = _hx_e;
HXLINE( 116)							{
HXLINE( 116)								null();
            							}
            						}
            						else {
            							HX_STACK_DO_THROW(_hx_e);
            						}
            					}
            				}
            			}
            		}
HXLINE( 122)		if (::hx::IsNull( this1->superClass )) {
HXLINE( 124)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(((((HX_("field '",41,d3,2d,fc) + name) + HX_("' does not exist in script class '",81,39,73,9e)) + this1->get_className()) + HX_("'",27,00,00,00))));
            		}
            		else {
HXLINE( 128)			::String _hx_tmp = ((((HX_("field '",41,d3,2d,fc) + name) + HX_("' does not exist in script class '",81,39,73,9e)) + this1->get_className()) + HX_("' or super class '",f6,d2,52,57));
HXDLIN( 128)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(((_hx_tmp + ::Type_obj::getClassName(::Type_obj::getClass(this1->superClass))) + HX_("'",27,00,00,00))));
            		}
HXLINE( 122)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(PolymodAbstractScriptClass_Impl__obj,fieldWrite,return )


PolymodAbstractScriptClass_Impl__obj::PolymodAbstractScriptClass_Impl__obj()
{
}

bool PolymodAbstractScriptClass_Impl__obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"fieldRead") ) { outValue = fieldRead_dyn(); return true; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"fieldWrite") ) { outValue = fieldWrite_dyn(); return true; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"resolveField") ) { outValue = resolveField_dyn(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *PolymodAbstractScriptClass_Impl__obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *PolymodAbstractScriptClass_Impl__obj_sStaticStorageInfo = 0;
#endif

::hx::Class PolymodAbstractScriptClass_Impl__obj::__mClass;

static ::String PolymodAbstractScriptClass_Impl__obj_sStaticFields[] = {
	HX_("resolveField",2e,da,18,39),
	HX_("fieldRead",30,f1,f5,e2),
	HX_("fieldWrite",c5,e5,db,9d),
	::String(null())
};

void PolymodAbstractScriptClass_Impl__obj::__register()
{
	PolymodAbstractScriptClass_Impl__obj _hx_dummy;
	PolymodAbstractScriptClass_Impl__obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("polymod.hscript._PolymodAbstractScriptClass.PolymodAbstractScriptClass_Impl_",42,13,b7,60);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &PolymodAbstractScriptClass_Impl__obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(PolymodAbstractScriptClass_Impl__obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< PolymodAbstractScriptClass_Impl__obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = PolymodAbstractScriptClass_Impl__obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = PolymodAbstractScriptClass_Impl__obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace polymod
} // end namespace hscript
} // end namespace _PolymodAbstractScriptClass
