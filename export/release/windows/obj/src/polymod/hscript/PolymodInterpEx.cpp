#include <hxcpp.h>

#ifndef INCLUDED_95f339a1d026d52c
#define INCLUDED_95f339a1d026d52c
#include "hxMath.h"
#endif
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
#ifndef INCLUDED_hscript_CType
#include <hscript/CType.h>
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
#ifndef INCLUDED_hscript_ModuleDecl
#include <hscript/ModuleDecl.h>
#endif
#ifndef INCLUDED_hscript_Parser
#include <hscript/Parser.h>
#endif
#ifndef INCLUDED_hscript_Printer
#include <hscript/Printer.h>
#endif
#ifndef INCLUDED_polymod_hscript_PolymodInterpEx
#include <polymod/hscript/PolymodInterpEx.h>
#endif
#ifndef INCLUDED_polymod_hscript_PolymodParserEx
#include <polymod/hscript/PolymodParserEx.h>
#endif
#ifndef INCLUDED_polymod_hscript_PolymodScriptClass
#include <polymod/hscript/PolymodScriptClass.h>
#endif
#ifndef INCLUDED_polymod_hscript__PolymodAbstractScriptClass_PolymodAbstractScriptClass_Impl_
#include <polymod/hscript/_PolymodAbstractScriptClass/PolymodAbstractScriptClass_Impl_.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_8f34cfa83fc6733e_13_new,"polymod.hscript.PolymodInterpEx","new",0x69ee38dc,"polymod.hscript.PolymodInterpEx.new","polymod/hscript/PolymodInterpEx.hx",13,0xcb136796)
HX_LOCAL_STACK_FRAME(_hx_pos_8f34cfa83fc6733e_28_cnew,"polymod.hscript.PolymodInterpEx","cnew",0x3f44f3e1,"polymod.hscript.PolymodInterpEx.cnew","polymod/hscript/PolymodInterpEx.hx",28,0xcb136796)
HX_LOCAL_STACK_FRAME(_hx_pos_8f34cfa83fc6733e_76_fcall,"polymod.hscript.PolymodInterpEx","fcall",0xcffbc380,"polymod.hscript.PolymodInterpEx.fcall","polymod/hscript/PolymodInterpEx.hx",76,0xcb136796)
HX_LOCAL_STACK_FRAME(_hx_pos_8f34cfa83fc6733e_113_assign,"polymod.hscript.PolymodInterpEx","assign",0x6ed35333,"polymod.hscript.PolymodInterpEx.assign","polymod/hscript/PolymodInterpEx.hx",113,0xcb136796)
HX_LOCAL_STACK_FRAME(_hx_pos_8f34cfa83fc6733e_137_call,"polymod.hscript.PolymodInterpEx","call",0x3f3b1ca2,"polymod.hscript.PolymodInterpEx.call","polymod/hscript/PolymodInterpEx.hx",137,0xcb136796)
HX_LOCAL_STACK_FRAME(_hx_pos_8f34cfa83fc6733e_149_get,"polymod.hscript.PolymodInterpEx","get",0x69e8e912,"polymod.hscript.PolymodInterpEx.get","polymod/hscript/PolymodInterpEx.hx",149,0xcb136796)
HX_LOCAL_STACK_FRAME(_hx_pos_8f34cfa83fc6733e_179_set,"polymod.hscript.PolymodInterpEx","set",0x69f2041e,"polymod.hscript.PolymodInterpEx.set","polymod/hscript/PolymodInterpEx.hx",179,0xcb136796)
HX_LOCAL_STACK_FRAME(_hx_pos_8f34cfa83fc6733e_205_resolve,"polymod.hscript.PolymodInterpEx","resolve",0xb7fe6968,"polymod.hscript.PolymodInterpEx.resolve","polymod/hscript/PolymodInterpEx.hx",205,0xcb136796)
HX_LOCAL_STACK_FRAME(_hx_pos_8f34cfa83fc6733e_288_addModule,"polymod.hscript.PolymodInterpEx","addModule",0xeeb55729,"polymod.hscript.PolymodInterpEx.addModule","polymod/hscript/PolymodInterpEx.hx",288,0xcb136796)
HX_LOCAL_STACK_FRAME(_hx_pos_8f34cfa83fc6733e_295_createScriptClassInstance,"polymod.hscript.PolymodInterpEx","createScriptClassInstance",0x86f5a6c2,"polymod.hscript.PolymodInterpEx.createScriptClassInstance","polymod/hscript/PolymodInterpEx.hx",295,0xcb136796)
HX_LOCAL_STACK_FRAME(_hx_pos_8f34cfa83fc6733e_305_registerModule,"polymod.hscript.PolymodInterpEx","registerModule",0x4cfc6c73,"polymod.hscript.PolymodInterpEx.registerModule","polymod/hscript/PolymodInterpEx.hx",305,0xcb136796)
HX_LOCAL_STACK_FRAME(_hx_pos_8f34cfa83fc6733e_98_registerScriptClass,"polymod.hscript.PolymodInterpEx","registerScriptClass",0x054c0906,"polymod.hscript.PolymodInterpEx.registerScriptClass","polymod/hscript/PolymodInterpEx.hx",98,0xcb136796)
HX_LOCAL_STACK_FRAME(_hx_pos_8f34cfa83fc6733e_109_findScriptClassDescriptor,"polymod.hscript.PolymodInterpEx","findScriptClassDescriptor",0x15bf8d7f,"polymod.hscript.PolymodInterpEx.findScriptClassDescriptor","polymod/hscript/PolymodInterpEx.hx",109,0xcb136796)
HX_LOCAL_STACK_FRAME(_hx_pos_8f34cfa83fc6733e_94_boot,"polymod.hscript.PolymodInterpEx","boot",0x3e9c8836,"polymod.hscript.PolymodInterpEx.boot","polymod/hscript/PolymodInterpEx.hx",94,0xcb136796)
HX_LOCAL_STACK_FRAME(_hx_pos_8f34cfa83fc6733e_95_boot,"polymod.hscript.PolymodInterpEx","boot",0x3e9c8836,"polymod.hscript.PolymodInterpEx.boot","polymod/hscript/PolymodInterpEx.hx",95,0xcb136796)
namespace polymod{
namespace hscript{

void PolymodInterpEx_obj::__construct(::hx::Class targetCls, ::polymod::hscript::PolymodScriptClass proxy){
            	HX_STACKFRAME(&_hx_pos_8f34cfa83fc6733e_13_new)
HXLINE( 202)		this->_nextCallObject = null();
HXLINE(  92)		this->_proxy = null();
HXLINE(  19)		super::__construct();
HXLINE(  20)		this->_proxy = proxy;
HXLINE(  21)		this->variables->set(HX_("Type",da,1e,e2,37),( ( ::Dynamic)(::hx::ClassOf< ::Type >()) ));
HXLINE(  22)		this->variables->set(HX_("Math",e8,6d,2f,33),( ( ::Dynamic)(::hx::ClassOf< ::Math >()) ));
HXLINE(  23)		this->variables->set(HX_("Std",83,60,3f,00),( ( ::Dynamic)(::hx::ClassOf< ::Std >()) ));
HXLINE(  24)		this->targetCls = targetCls;
            	}

Dynamic PolymodInterpEx_obj::__CreateEmpty() { return new PolymodInterpEx_obj; }

void *PolymodInterpEx_obj::_hx_vtable = 0;

Dynamic PolymodInterpEx_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< PolymodInterpEx_obj > _hx_result = new PolymodInterpEx_obj();
	_hx_result->__construct(inArgs[0],inArgs[1]);
	return _hx_result;
}

bool PolymodInterpEx_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x25369478) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x25369478;
	} else {
		return inClassId==(int)0x2a95eb9f;
	}
}

 ::Dynamic PolymodInterpEx_obj::cnew(::String cl,::cpp::VirtualArray args){
            	HX_GC_STACKFRAME(&_hx_pos_8f34cfa83fc6733e_28_cnew)
HXLINE(  29)		if (::polymod::hscript::PolymodInterpEx_obj::_scriptClassDescriptors->exists(cl)) {
HXLINE(  32)			 ::polymod::hscript::PolymodScriptClass proxy =  ::polymod::hscript::PolymodScriptClass_obj::__alloc( HX_CTX ,::polymod::hscript::PolymodInterpEx_obj::_scriptClassDescriptors->get(cl),args);
HXLINE(  33)			return proxy;
            		}
            		else {
HXLINE(  35)			if (::hx::IsNotNull( this->_proxy )) {
HXLINE(  38)				if (::hx::IsNotNull( this->_proxy->_c->__Field(HX_("pkg",0c,5a,55,00),::hx::paccDynamic) )) {
HXLINE(  41)					::String packagedClass = ((( (::Array< ::String >)(this->_proxy->_c->__Field(HX_("pkg",0c,5a,55,00),::hx::paccDynamic)) )->join(HX_(".",2e,00,00,00)) + HX_(".",2e,00,00,00)) + cl);
HXLINE(  42)					if (::polymod::hscript::PolymodInterpEx_obj::_scriptClassDescriptors->exists(packagedClass)) {
HXLINE(  45)						 ::polymod::hscript::PolymodScriptClass proxy =  ::polymod::hscript::PolymodScriptClass_obj::__alloc( HX_CTX ,::polymod::hscript::PolymodInterpEx_obj::_scriptClassDescriptors->get(packagedClass),args);
HXLINE(  46)						return proxy;
            					}
            				}
HXLINE(  51)				bool _hx_tmp;
HXDLIN(  51)				if (::hx::IsNotNull( this->_proxy->_c->__Field(HX_("imports",6e,97,ca,69),::hx::paccDynamic) )) {
HXLINE(  51)					_hx_tmp = ( ( ::haxe::ds::StringMap)( ::Dynamic(this->_proxy->_c->__Field(HX_("imports",6e,97,ca,69),::hx::paccDynamic))) )->exists(cl);
            				}
            				else {
HXLINE(  51)					_hx_tmp = false;
            				}
HXDLIN(  51)				if (_hx_tmp) {
HXLINE(  53)					::String importedClass = ( (::Array< ::String >)(( ( ::haxe::ds::StringMap)( ::Dynamic(this->_proxy->_c->__Field(HX_("imports",6e,97,ca,69),::hx::paccDynamic))) )->get(cl)) )->join(HX_(".",2e,00,00,00));
HXLINE(  54)					if (::polymod::hscript::PolymodInterpEx_obj::_scriptClassDescriptors->exists(importedClass)) {
HXLINE(  57)						 ::polymod::hscript::PolymodScriptClass proxy =  ::polymod::hscript::PolymodScriptClass_obj::__alloc( HX_CTX ,::polymod::hscript::PolymodInterpEx_obj::_scriptClassDescriptors->get(importedClass),args);
HXLINE(  58)						return proxy;
            					}
HXLINE(  61)					::hx::Class c = ::Type_obj::resolveClass(importedClass);
HXLINE(  62)					if (::hx::IsNotNull( c )) {
HXLINE(  64)						return ::Type_obj::createInstance(c,args);
            					}
            				}
            			}
            		}
HXLINE(  68)		return this->super::cnew(cl,args);
            	}


 ::Dynamic PolymodInterpEx_obj::fcall( ::Dynamic o,::String f,::cpp::VirtualArray args){
            	HX_STACKFRAME(&_hx_pos_8f34cfa83fc6733e_76_fcall)
HXLINE(  78)		if (::Std_obj::isOfType(o,this->targetCls)) {
HXLINE(  81)			return this->super::fcall(o,(HX_("__super_",a4,b5,70,4b) + f),args);
            		}
            		else {
HXLINE(  83)			if (::Std_obj::isOfType(o,::hx::ClassOf< ::polymod::hscript::PolymodScriptClass >())) {
HXLINE(  85)				this->_nextCallObject = null();
HXLINE(  86)				 ::polymod::hscript::PolymodScriptClass proxy = ::hx::TCast<  ::polymod::hscript::PolymodScriptClass >::cast(o);
HXLINE(  87)				return proxy->callFunction(f,args);
            			}
            		}
HXLINE(  89)		return this->super::fcall(o,f,args);
            	}


 ::Dynamic PolymodInterpEx_obj::assign( ::hscript::Expr e1, ::hscript::Expr e2){
            	HX_STACKFRAME(&_hx_pos_8f34cfa83fc6733e_113_assign)
HXLINE( 114)		 ::Dynamic v = this->expr(e2);
HXLINE( 115)		if ((e1->_hx_getIndex() == 1)) {
HXLINE( 117)			::String id = e1->_hx_getString(0);
HXLINE( 118)			if (::hx::IsNotNull( this->_proxy->superClass )) {
HXLINE( 120)				if (::Reflect_obj::hasField(this->_proxy->superClass,id)) {
HXLINE( 122)					::Reflect_obj::setProperty(this->_proxy->superClass,id,v);
HXLINE( 123)					return v;
            				}
            				else {
HXLINE( 125)					if (::Type_obj::getInstanceFields(::Type_obj::getClass(this->_proxy->superClass))->contains(id)) {
HXLINE( 127)						::Reflect_obj::setProperty(this->_proxy->superClass,id,v);
HXLINE( 128)						return v;
            					}
            				}
            			}
            		}
HXLINE( 133)		return this->super::assign(e1,e2);
            	}


 ::Dynamic PolymodInterpEx_obj::call( ::Dynamic o, ::Dynamic f,::cpp::VirtualArray args){
            	HX_STACKFRAME(&_hx_pos_8f34cfa83fc6733e_137_call)
HXLINE( 139)		bool _hx_tmp;
HXDLIN( 139)		if (::hx::IsNull( o )) {
HXLINE( 139)			_hx_tmp = ::hx::IsNotNull( this->_nextCallObject );
            		}
            		else {
HXLINE( 139)			_hx_tmp = false;
            		}
HXDLIN( 139)		if (_hx_tmp) {
HXLINE( 141)			o = this->_nextCallObject;
            		}
HXLINE( 143)		 ::Dynamic r = this->super::call(o,f,args);
HXLINE( 144)		this->_nextCallObject = null();
HXLINE( 145)		return r;
            	}


 ::Dynamic PolymodInterpEx_obj::get( ::Dynamic o,::String f){
            	HX_STACKFRAME(&_hx_pos_8f34cfa83fc6733e_149_get)
HXLINE( 150)		if (::hx::IsNull( o )) {
HXLINE( 151)			 ::hscript::Error e = ::hscript::Error_obj::EInvalidAccess(f);
HXDLIN( 151)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(e));
            		}
HXLINE( 152)		if (::Std_obj::isOfType(o,::hx::ClassOf< ::polymod::hscript::PolymodScriptClass >())) {
HXLINE( 154)			 ::polymod::hscript::PolymodScriptClass proxy = ::hx::TCast<  ::polymod::hscript::PolymodScriptClass >::cast(o);
HXLINE( 155)			if (proxy->_interp->variables->exists(f)) {
HXLINE( 157)				return proxy->_interp->variables->get(f);
            			}
            			else {
HXLINE( 159)				bool _hx_tmp;
HXDLIN( 159)				if (::hx::IsNotNull( proxy->superClass )) {
HXLINE( 159)					_hx_tmp = ::Reflect_obj::hasField(proxy->superClass,f);
            				}
            				else {
HXLINE( 159)					_hx_tmp = false;
            				}
HXDLIN( 159)				if (_hx_tmp) {
HXLINE( 161)					return ::Reflect_obj::getProperty(proxy->superClass,f);
            				}
            				else {
HXLINE( 165)					try {
            						HX_STACK_CATCHABLE( ::Dynamic, 0);
HXLINE( 167)						return ::polymod::hscript::_PolymodAbstractScriptClass::PolymodAbstractScriptClass_Impl__obj::resolveField(proxy,f);
            					} catch( ::Dynamic _hx_e) {
            						if (_hx_e.IsClass<  ::Dynamic >() ){
            							HX_STACK_BEGIN_CATCH
            							 ::Dynamic _g = _hx_e;
HXLINE( 169)							{
HXLINE( 169)								null();
            							}
            						}
            						else {
            							HX_STACK_DO_THROW(_hx_e);
            						}
            					}
HXLINE( 172)					 ::hscript::Error e = ::hscript::Error_obj::EUnknownVariable(f);
HXDLIN( 172)					HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(e));
            				}
            			}
            		}
HXLINE( 175)		return this->super::get(o,f);
            	}


 ::Dynamic PolymodInterpEx_obj::set( ::Dynamic o,::String f, ::Dynamic v){
            	HX_STACKFRAME(&_hx_pos_8f34cfa83fc6733e_179_set)
HXLINE( 180)		if (::hx::IsNull( o )) {
HXLINE( 181)			 ::hscript::Error e = ::hscript::Error_obj::EInvalidAccess(f);
HXDLIN( 181)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(e));
            		}
HXLINE( 182)		if (::Std_obj::isOfType(o,::hx::ClassOf< ::polymod::hscript::PolymodScriptClass >())) {
HXLINE( 184)			 ::polymod::hscript::PolymodScriptClass proxy = ::hx::TCast<  ::polymod::hscript::PolymodScriptClass >::cast(o);
HXLINE( 185)			if (proxy->_interp->variables->exists(f)) {
HXLINE( 187)				proxy->_interp->variables->set(f,v);
            			}
            			else {
HXLINE( 189)				bool _hx_tmp;
HXDLIN( 189)				if (::hx::IsNotNull( proxy->superClass )) {
HXLINE( 189)					_hx_tmp = ::Reflect_obj::hasField(proxy->superClass,f);
            				}
            				else {
HXLINE( 189)					_hx_tmp = false;
            				}
HXDLIN( 189)				if (_hx_tmp) {
HXLINE( 191)					::Reflect_obj::setProperty(proxy->superClass,f,v);
            				}
            				else {
HXLINE( 195)					 ::hscript::Error e = ::hscript::Error_obj::EUnknownVariable(f);
HXDLIN( 195)					HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(e));
            				}
            			}
HXLINE( 197)			return v;
            		}
HXLINE( 199)		return this->super::set(o,f,v);
            	}


 ::Dynamic PolymodInterpEx_obj::resolve(::String id){
            	HX_STACKFRAME(&_hx_pos_8f34cfa83fc6733e_205_resolve)
HXLINE( 206)		this->_nextCallObject = null();
HXLINE( 207)		bool _hx_tmp;
HXDLIN( 207)		if ((id == HX_("super",7b,01,c0,84))) {
HXLINE( 207)			_hx_tmp = ::hx::IsNotNull( this->_proxy );
            		}
            		else {
HXLINE( 207)			_hx_tmp = false;
            		}
HXDLIN( 207)		if (_hx_tmp) {
HXLINE( 209)			if (::hx::IsNull( this->_proxy->superClass )) {
HXLINE( 211)				return this->_proxy->superConstructor_dyn();
            			}
            			else {
HXLINE( 215)				return this->_proxy->superClass;
            			}
            		}
            		else {
HXLINE( 218)			bool _hx_tmp;
HXDLIN( 218)			if ((id == HX_("this",5e,06,fc,4c))) {
HXLINE( 218)				_hx_tmp = ::hx::IsNotNull( this->_proxy );
            			}
            			else {
HXLINE( 218)				_hx_tmp = false;
            			}
HXDLIN( 218)			if (_hx_tmp) {
HXLINE( 220)				return this->_proxy;
            			}
            			else {
HXLINE( 222)				if ((id == HX_("null",87,9e,0e,49))) {
HXLINE( 224)					return null();
            				}
            			}
            		}
HXLINE( 227)		 ::Dynamic l = this->locals->get(id);
HXLINE( 228)		if (::hx::IsNotNull( l )) {
HXLINE( 230)			return  ::Dynamic(l->__Field(HX_("r",72,00,00,00),::hx::paccDynamic));
            		}
HXLINE( 232)		 ::Dynamic v = this->variables->get(id);
HXLINE( 233)		if (::hx::IsNotNull( v )) {
HXLINE( 235)			return v;
            		}
HXLINE( 238)		::Array< ::String > m = ( (::Array< ::String >)(( ( ::haxe::ds::StringMap)( ::Dynamic(this->_proxy->_c->__Field(HX_("imports",6e,97,ca,69),::hx::paccDynamic))) )->get(id)) );
HXLINE( 239)		if (::hx::IsNotNull( m )) {
HXLINE( 241)			::String importedClass = m->join(HX_(".",2e,00,00,00));
HXLINE( 245)			 ::Dynamic result = ::Type_obj::resolveClass(importedClass);
HXLINE( 246)			if (::hx::IsNotNull( result )) {
HXLINE( 247)				return result;
            			}
HXLINE( 250)			result = ::Type_obj::resolveEnum(importedClass);
HXLINE( 251)			if (::hx::IsNotNull( result )) {
HXLINE( 252)				return result;
            			}
            		}
HXLINE( 255)		bool _hx_tmp1;
HXDLIN( 255)		if (::hx::IsNotNull( this->_proxy )) {
HXLINE( 255)			_hx_tmp1 = ::hx::IsNotNull( this->_proxy->findFunction(id) );
            		}
            		else {
HXLINE( 255)			_hx_tmp1 = false;
            		}
HXDLIN( 255)		if (_hx_tmp1) {
HXLINE( 257)			this->_nextCallObject = this->_proxy;
HXLINE( 258)			return ::polymod::hscript::_PolymodAbstractScriptClass::PolymodAbstractScriptClass_Impl__obj::resolveField(this->_proxy,id);
            		}
            		else {
HXLINE( 260)			bool _hx_tmp;
HXDLIN( 260)			bool _hx_tmp1;
HXDLIN( 260)			if (::hx::IsNotNull( this->_proxy )) {
HXLINE( 260)				_hx_tmp1 = ::hx::IsNotNull( this->_proxy->superClass );
            			}
            			else {
HXLINE( 260)				_hx_tmp1 = false;
            			}
HXDLIN( 260)			if (_hx_tmp1) {
HXLINE( 262)				if (!(::Reflect_obj::hasField(this->_proxy->superClass,id))) {
HXLINE( 260)					_hx_tmp = ::hx::IsNotNull( ::Reflect_obj::getProperty(this->_proxy->superClass,id) );
            				}
            				else {
HXLINE( 260)					_hx_tmp = true;
            				}
            			}
            			else {
HXLINE( 260)				_hx_tmp = false;
            			}
HXDLIN( 260)			if (_hx_tmp) {
HXLINE( 264)				this->_nextCallObject = this->_proxy->superClass;
HXLINE( 265)				return ::Reflect_obj::getProperty(this->_proxy->superClass,id);
            			}
            			else {
HXLINE( 267)				if (::hx::IsNotNull( this->_proxy )) {
HXLINE( 269)					try {
            						HX_STACK_CATCHABLE( ::Dynamic, 0);
HXLINE( 271)						 ::Dynamic r = ::polymod::hscript::_PolymodAbstractScriptClass::PolymodAbstractScriptClass_Impl__obj::resolveField(this->_proxy,id);
HXLINE( 272)						this->_nextCallObject = this->_proxy;
HXLINE( 273)						return r;
            					} catch( ::Dynamic _hx_e) {
            						if (_hx_e.IsClass<  ::Dynamic >() ){
            							HX_STACK_BEGIN_CATCH
            							 ::Dynamic _g = _hx_e;
HXLINE( 275)							{
HXLINE( 275)								null();
            							}
            						}
            						else {
            							HX_STACK_DO_THROW(_hx_e);
            						}
            					}
HXLINE( 278)					 ::hscript::Error e = ::hscript::Error_obj::EUnknownVariable(id);
HXDLIN( 278)					HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(e));
            				}
            				else {
HXLINE( 282)					 ::hscript::Error e = ::hscript::Error_obj::EUnknownVariable(id);
HXDLIN( 282)					HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(e));
            				}
            			}
            		}
HXLINE( 255)		return null();
            	}


void PolymodInterpEx_obj::addModule(::String moduleContents){
            	HX_GC_STACKFRAME(&_hx_pos_8f34cfa83fc6733e_288_addModule)
HXLINE( 289)		 ::polymod::hscript::PolymodParserEx parser =  ::polymod::hscript::PolymodParserEx_obj::__alloc( HX_CTX );
HXLINE( 290)		::Array< ::Dynamic> decls = parser->parseModule(moduleContents,null());
HXLINE( 291)		this->registerModule(decls);
            	}


HX_DEFINE_DYNAMIC_FUNC1(PolymodInterpEx_obj,addModule,(void))

 ::polymod::hscript::PolymodScriptClass PolymodInterpEx_obj::createScriptClassInstance(::String className,::cpp::VirtualArray args){
            	HX_STACKFRAME(&_hx_pos_8f34cfa83fc6733e_295_createScriptClassInstance)
HXLINE( 296)		if (::hx::IsNull( args )) {
HXLINE( 298)			args = ::cpp::VirtualArray_obj::__new(0);
            		}
HXLINE( 300)		 ::polymod::hscript::PolymodScriptClass r = ( ( ::polymod::hscript::PolymodScriptClass)(this->cnew(className,args)) );
HXLINE( 301)		return r;
            	}


HX_DEFINE_DYNAMIC_FUNC2(PolymodInterpEx_obj,createScriptClassInstance,return )

void PolymodInterpEx_obj::registerModule(::Array< ::Dynamic> module){
            	HX_GC_STACKFRAME(&_hx_pos_8f34cfa83fc6733e_305_registerModule)
HXLINE( 306)		::Array< ::String > pkg = null();
HXLINE( 307)		 ::haxe::ds::StringMap imports =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
HXLINE( 308)		{
HXLINE( 308)			int _g = 0;
HXDLIN( 308)			while((_g < module->length)){
HXLINE( 308)				 ::hscript::ModuleDecl decl = module->__get(_g).StaticCast<  ::hscript::ModuleDecl >();
HXDLIN( 308)				_g = (_g + 1);
HXLINE( 310)				switch((int)(decl->_hx_getIndex())){
            					case (int)0: {
HXLINE( 312)						::Array< ::String > path = decl->_hx_getObject(0).StaticCast< ::Array< ::String > >();
HXLINE( 313)						pkg = path;
            					}
            					break;
            					case (int)1: {
HXLINE( 314)						 ::Dynamic _g = decl->_hx_getObject(1);
HXDLIN( 314)						{
HXLINE( 314)							::Array< ::String > path = decl->_hx_getObject(0).StaticCast< ::Array< ::String > >();
HXDLIN( 314)							{
HXLINE( 315)								::String last = path->__get((path->length - 1));
HXLINE( 316)								imports->set(last,path);
            							}
            						}
            					}
            					break;
            					case (int)2: {
HXLINE( 317)						 ::Dynamic c = decl->_hx_getObject(0);
HXDLIN( 317)						{
HXLINE( 318)							 ::hscript::CType extend = c->__Field(HX_("extend",da,d1,1a,c7),::hx::paccDynamic);
HXLINE( 319)							if (::hx::IsNotNull( extend )) {
HXLINE( 321)								::String superClassPath =  ::hscript::Printer_obj::__alloc( HX_CTX )->typeToString(extend);
HXLINE( 322)								if (imports->exists(superClassPath)) {
HXLINE( 324)									if (::hx::IsNotNull( extend )) {
HXLINE( 324)										if ((extend->_hx_getIndex() == 0)) {
HXLINE( 326)											::Array< ::String > _g = extend->_hx_getObject(0).StaticCast< ::Array< ::String > >();
HXDLIN( 326)											{
HXLINE( 326)												::Array< ::Dynamic> params = extend->_hx_getObject(1).StaticCast< ::Array< ::Dynamic> >();
HXLINE( 327)												extend = ::hscript::CType_obj::CTPath(( (::Array< ::String >)(imports->get(superClassPath)) ),params);
            											}
            										}
            									}
            								}
            							}
HXLINE( 332)							 ::Dynamic classDecl =  ::Dynamic(::hx::Anon_obj::Create(10)
            								->setFixed(0,HX_("fields",79,8e,8e,80), ::Dynamic(c->__Field(HX_("fields",79,8e,8e,80),::hx::paccDynamic)))
            								->setFixed(1,HX_("isPrivate",39,aa,6d,8d), ::Dynamic(c->__Field(HX_("isPrivate",39,aa,6d,8d),::hx::paccDynamic)))
            								->setFixed(2,HX_("implement",a3,71,3f,af), ::Dynamic(c->__Field(HX_("implement",a3,71,3f,af),::hx::paccDynamic)))
            								->setFixed(3,HX_("extend",da,d1,1a,c7),extend)
            								->setFixed(4,HX_("params",46,fb,7a,ed), ::Dynamic(c->__Field(HX_("params",46,fb,7a,ed),::hx::paccDynamic)))
            								->setFixed(5,HX_("pkg",0c,5a,55,00),pkg)
            								->setFixed(6,HX_("isExtern",ea,70,84,1f), ::Dynamic(c->__Field(HX_("isExtern",ea,70,84,1f),::hx::paccDynamic)))
            								->setFixed(7,HX_("meta",c5,4a,59,48), ::Dynamic(c->__Field(HX_("meta",c5,4a,59,48),::hx::paccDynamic)))
            								->setFixed(8,HX_("name",4b,72,ff,48), ::Dynamic(c->__Field(HX_("name",4b,72,ff,48),::hx::paccDynamic)))
            								->setFixed(9,HX_("imports",6e,97,ca,69),imports));
HXLINE( 344)							::polymod::hscript::PolymodInterpEx_obj::registerScriptClass(classDecl);
            						}
            					}
            					break;
            					case (int)3: {
HXLINE( 345)						 ::Dynamic _g = decl->_hx_getObject(0);
            					}
            					break;
            				}
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(PolymodInterpEx_obj,registerModule,(void))

 ::haxe::ds::StringMap PolymodInterpEx_obj::_scriptClassDescriptors;

 ::haxe::ds::StringMap PolymodInterpEx_obj::_scriptClassOverrides;

void PolymodInterpEx_obj::registerScriptClass( ::Dynamic c){
            	HX_STACKFRAME(&_hx_pos_8f34cfa83fc6733e_98_registerScriptClass)
HXLINE(  99)		::String name = ( (::String)(c->__Field(HX_("name",4b,72,ff,48),::hx::paccDynamic)) );
HXLINE( 100)		if (::hx::IsNotNull( c->__Field(HX_("pkg",0c,5a,55,00),::hx::paccDynamic) )) {
HXLINE( 102)			name = ((( (::Array< ::String >)(c->__Field(HX_("pkg",0c,5a,55,00),::hx::paccDynamic)) )->join(HX_(".",2e,00,00,00)) + HX_(".",2e,00,00,00)) + name);
            		}
HXLINE( 104)		::polymod::hscript::PolymodInterpEx_obj::_scriptClassDescriptors->set(name,c);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(PolymodInterpEx_obj,registerScriptClass,(void))

 ::Dynamic PolymodInterpEx_obj::findScriptClassDescriptor(::String name){
            	HX_STACKFRAME(&_hx_pos_8f34cfa83fc6733e_109_findScriptClassDescriptor)
HXDLIN( 109)		return ::polymod::hscript::PolymodInterpEx_obj::_scriptClassDescriptors->get(name);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(PolymodInterpEx_obj,findScriptClassDescriptor,return )


::hx::ObjectPtr< PolymodInterpEx_obj > PolymodInterpEx_obj::__new(::hx::Class targetCls, ::polymod::hscript::PolymodScriptClass proxy) {
	::hx::ObjectPtr< PolymodInterpEx_obj > __this = new PolymodInterpEx_obj();
	__this->__construct(targetCls,proxy);
	return __this;
}

::hx::ObjectPtr< PolymodInterpEx_obj > PolymodInterpEx_obj::__alloc(::hx::Ctx *_hx_ctx,::hx::Class targetCls, ::polymod::hscript::PolymodScriptClass proxy) {
	PolymodInterpEx_obj *__this = (PolymodInterpEx_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(PolymodInterpEx_obj), true, "polymod.hscript.PolymodInterpEx"));
	*(void **)__this = PolymodInterpEx_obj::_hx_vtable;
	__this->__construct(targetCls,proxy);
	return __this;
}

PolymodInterpEx_obj::PolymodInterpEx_obj()
{
}

void PolymodInterpEx_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PolymodInterpEx);
	HX_MARK_MEMBER_NAME(targetCls,"targetCls");
	HX_MARK_MEMBER_NAME(_proxy,"_proxy");
	HX_MARK_MEMBER_NAME(_nextCallObject,"_nextCallObject");
	 ::hscript::Interp_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void PolymodInterpEx_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(targetCls,"targetCls");
	HX_VISIT_MEMBER_NAME(_proxy,"_proxy");
	HX_VISIT_MEMBER_NAME(_nextCallObject,"_nextCallObject");
	 ::hscript::Interp_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val PolymodInterpEx_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"get") ) { return ::hx::Val( get_dyn() ); }
		if (HX_FIELD_EQ(inName,"set") ) { return ::hx::Val( set_dyn() ); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"cnew") ) { return ::hx::Val( cnew_dyn() ); }
		if (HX_FIELD_EQ(inName,"call") ) { return ::hx::Val( call_dyn() ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"fcall") ) { return ::hx::Val( fcall_dyn() ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_proxy") ) { return ::hx::Val( _proxy ); }
		if (HX_FIELD_EQ(inName,"assign") ) { return ::hx::Val( assign_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"resolve") ) { return ::hx::Val( resolve_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"targetCls") ) { return ::hx::Val( targetCls ); }
		if (HX_FIELD_EQ(inName,"addModule") ) { return ::hx::Val( addModule_dyn() ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"registerModule") ) { return ::hx::Val( registerModule_dyn() ); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_nextCallObject") ) { return ::hx::Val( _nextCallObject ); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"createScriptClassInstance") ) { return ::hx::Val( createScriptClassInstance_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

bool PolymodInterpEx_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 19:
		if (HX_FIELD_EQ(inName,"registerScriptClass") ) { outValue = registerScriptClass_dyn(); return true; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"_scriptClassOverrides") ) { outValue = ( _scriptClassOverrides ); return true; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"_scriptClassDescriptors") ) { outValue = ( _scriptClassDescriptors ); return true; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"findScriptClassDescriptor") ) { outValue = findScriptClassDescriptor_dyn(); return true; }
	}
	return false;
}

::hx::Val PolymodInterpEx_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"_proxy") ) { _proxy=inValue.Cast<  ::polymod::hscript::PolymodScriptClass >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"targetCls") ) { targetCls=inValue.Cast< ::hx::Class >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_nextCallObject") ) { _nextCallObject=inValue.Cast<  ::Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool PolymodInterpEx_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 21:
		if (HX_FIELD_EQ(inName,"_scriptClassOverrides") ) { _scriptClassOverrides=ioValue.Cast<  ::haxe::ds::StringMap >(); return true; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"_scriptClassDescriptors") ) { _scriptClassDescriptors=ioValue.Cast<  ::haxe::ds::StringMap >(); return true; }
	}
	return false;
}

void PolymodInterpEx_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("targetCls",d9,6a,2a,69));
	outFields->push(HX_("_proxy",af,35,77,c4));
	outFields->push(HX_("_nextCallObject",6f,f5,6f,e2));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo PolymodInterpEx_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /* ::hx::Class */ ,(int)offsetof(PolymodInterpEx_obj,targetCls),HX_("targetCls",d9,6a,2a,69)},
	{::hx::fsObject /*  ::polymod::hscript::PolymodScriptClass */ ,(int)offsetof(PolymodInterpEx_obj,_proxy),HX_("_proxy",af,35,77,c4)},
	{::hx::fsObject /*  ::Dynamic */ ,(int)offsetof(PolymodInterpEx_obj,_nextCallObject),HX_("_nextCallObject",6f,f5,6f,e2)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo PolymodInterpEx_obj_sStaticStorageInfo[] = {
	{::hx::fsObject /*  ::haxe::ds::StringMap */ ,(void *) &PolymodInterpEx_obj::_scriptClassDescriptors,HX_("_scriptClassDescriptors",96,63,e8,65)},
	{::hx::fsObject /*  ::haxe::ds::StringMap */ ,(void *) &PolymodInterpEx_obj::_scriptClassOverrides,HX_("_scriptClassOverrides",99,ca,b8,da)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static ::String PolymodInterpEx_obj_sMemberFields[] = {
	HX_("targetCls",d9,6a,2a,69),
	HX_("cnew",dd,ef,c3,41),
	HX_("fcall",04,44,99,fc),
	HX_("_proxy",af,35,77,c4),
	HX_("assign",2f,46,06,4c),
	HX_("call",9e,18,ba,41),
	HX_("get",96,80,4e,00),
	HX_("set",a2,9b,57,00),
	HX_("_nextCallObject",6f,f5,6f,e2),
	HX_("resolve",ec,12,60,67),
	HX_("addModule",ad,69,f7,78),
	HX_("createScriptClassInstance",46,01,b4,df),
	HX_("registerModule",6f,bb,14,87),
	::String(null()) };

static void PolymodInterpEx_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PolymodInterpEx_obj::_scriptClassDescriptors,"_scriptClassDescriptors");
	HX_MARK_MEMBER_NAME(PolymodInterpEx_obj::_scriptClassOverrides,"_scriptClassOverrides");
};

#ifdef HXCPP_VISIT_ALLOCS
static void PolymodInterpEx_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PolymodInterpEx_obj::_scriptClassDescriptors,"_scriptClassDescriptors");
	HX_VISIT_MEMBER_NAME(PolymodInterpEx_obj::_scriptClassOverrides,"_scriptClassOverrides");
};

#endif

::hx::Class PolymodInterpEx_obj::__mClass;

static ::String PolymodInterpEx_obj_sStaticFields[] = {
	HX_("_scriptClassDescriptors",96,63,e8,65),
	HX_("_scriptClassOverrides",99,ca,b8,da),
	HX_("registerScriptClass",8a,e8,47,cc),
	HX_("findScriptClassDescriptor",03,e8,7d,6e),
	::String(null())
};

void PolymodInterpEx_obj::__register()
{
	PolymodInterpEx_obj _hx_dummy;
	PolymodInterpEx_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("polymod.hscript.PolymodInterpEx",ea,da,79,04);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &PolymodInterpEx_obj::__GetStatic;
	__mClass->mSetStaticField = &PolymodInterpEx_obj::__SetStatic;
	__mClass->mMarkFunc = PolymodInterpEx_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(PolymodInterpEx_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(PolymodInterpEx_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< PolymodInterpEx_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = PolymodInterpEx_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = PolymodInterpEx_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = PolymodInterpEx_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void PolymodInterpEx_obj::__boot()
{
{
            	HX_GC_STACKFRAME(&_hx_pos_8f34cfa83fc6733e_94_boot)
HXDLIN(  94)		_scriptClassDescriptors =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
            	}
{
            	HX_GC_STACKFRAME(&_hx_pos_8f34cfa83fc6733e_95_boot)
HXDLIN(  95)		_scriptClassOverrides =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
            	}
}

} // end namespace polymod
} // end namespace hscript
