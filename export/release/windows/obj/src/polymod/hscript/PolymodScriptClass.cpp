#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
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
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
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
#ifndef INCLUDED_hscript_FieldKind
#include <hscript/FieldKind.h>
#endif
#ifndef INCLUDED_hscript_Interp
#include <hscript/Interp.h>
#endif
#ifndef INCLUDED_hscript_Printer
#include <hscript/Printer.h>
#endif
#ifndef INCLUDED_polymod_Polymod
#include <polymod/Polymod.h>
#endif
#ifndef INCLUDED_polymod_PolymodConfig
#include <polymod/PolymodConfig.h>
#endif
#ifndef INCLUDED_polymod_backends_PolymodAssetLibrary
#include <polymod/backends/PolymodAssetLibrary.h>
#endif
#ifndef INCLUDED_polymod_hscript_Param
#include <polymod/hscript/Param.h>
#endif
#ifndef INCLUDED_polymod_hscript_PolymodInterpEx
#include <polymod/hscript/PolymodInterpEx.h>
#endif
#ifndef INCLUDED_polymod_hscript_PolymodScriptClass
#include <polymod/hscript/PolymodScriptClass.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_bb882bfc11b6c975_20_new,"polymod.hscript.PolymodScriptClass","new",0x5779cc7c,"polymod.hscript.PolymodScriptClass.new","polymod/hscript/PolymodScriptClass.hx",20,0xd2a2e232)
HX_LOCAL_STACK_FRAME(_hx_pos_bb882bfc11b6c975_209_createSuperClass,"polymod.hscript.PolymodScriptClass","createSuperClass",0x1bf6c93d,"polymod.hscript.PolymodScriptClass.createSuperClass","polymod/hscript/PolymodScriptClass.hx",209,0xd2a2e232)
HX_LOCAL_STACK_FRAME(_hx_pos_bb882bfc11b6c975_251_callFunction,"polymod.hscript.PolymodScriptClass","callFunction",0xbef4ee3a,"polymod.hscript.PolymodScriptClass.callFunction","polymod/hscript/PolymodScriptClass.hx",251,0xd2a2e232)
HX_LOCAL_STACK_FRAME(_hx_pos_bb882bfc11b6c975_327_get_className,"polymod.hscript.PolymodScriptClass","get_className",0x3eee1d96,"polymod.hscript.PolymodScriptClass.get_className","polymod/hscript/PolymodScriptClass.hx",327,0xd2a2e232)
HX_LOCAL_STACK_FRAME(_hx_pos_bb882bfc11b6c975_338_superConstructor,"polymod.hscript.PolymodScriptClass","superConstructor",0x4460b1a3,"polymod.hscript.PolymodScriptClass.superConstructor","polymod/hscript/PolymodScriptClass.hx",338,0xd2a2e232)
HX_LOCAL_STACK_FRAME(_hx_pos_bb882bfc11b6c975_353_callFunction0,"polymod.hscript.PolymodScriptClass","callFunction0",0x575b84b6,"polymod.hscript.PolymodScriptClass.callFunction0","polymod/hscript/PolymodScriptClass.hx",353,0xd2a2e232)
HX_LOCAL_STACK_FRAME(_hx_pos_bb882bfc11b6c975_358_callFunction1,"polymod.hscript.PolymodScriptClass","callFunction1",0x575b84b7,"polymod.hscript.PolymodScriptClass.callFunction1","polymod/hscript/PolymodScriptClass.hx",358,0xd2a2e232)
HX_LOCAL_STACK_FRAME(_hx_pos_bb882bfc11b6c975_363_callFunction2,"polymod.hscript.PolymodScriptClass","callFunction2",0x575b84b8,"polymod.hscript.PolymodScriptClass.callFunction2","polymod/hscript/PolymodScriptClass.hx",363,0xd2a2e232)
HX_LOCAL_STACK_FRAME(_hx_pos_bb882bfc11b6c975_368_callFunction3,"polymod.hscript.PolymodScriptClass","callFunction3",0x575b84b9,"polymod.hscript.PolymodScriptClass.callFunction3","polymod/hscript/PolymodScriptClass.hx",368,0xd2a2e232)
HX_LOCAL_STACK_FRAME(_hx_pos_bb882bfc11b6c975_373_callFunction4,"polymod.hscript.PolymodScriptClass","callFunction4",0x575b84ba,"polymod.hscript.PolymodScriptClass.callFunction4","polymod/hscript/PolymodScriptClass.hx",373,0xd2a2e232)
HX_LOCAL_STACK_FRAME(_hx_pos_bb882bfc11b6c975_377_findFunction,"polymod.hscript.PolymodScriptClass","findFunction",0x743038d5,"polymod.hscript.PolymodScriptClass.findFunction","polymod/hscript/PolymodScriptClass.hx",377,0xd2a2e232)
HX_LOCAL_STACK_FRAME(_hx_pos_bb882bfc11b6c975_400_findVar,"polymod.hscript.PolymodScriptClass","findVar",0x8c812a4a,"polymod.hscript.PolymodScriptClass.findVar","polymod/hscript/PolymodScriptClass.hx",400,0xd2a2e232)
HX_LOCAL_STACK_FRAME(_hx_pos_bb882bfc11b6c975_423_findField,"polymod.hscript.PolymodScriptClass","findField",0x5daebedd,"polymod.hscript.PolymodScriptClass.findField","polymod/hscript/PolymodScriptClass.hx",423,0xd2a2e232)
HX_LOCAL_STACK_FRAME(_hx_pos_bb882bfc11b6c975_441_listFunctions,"polymod.hscript.PolymodScriptClass","listFunctions",0x61840939,"polymod.hscript.PolymodScriptClass.listFunctions","polymod/hscript/PolymodScriptClass.hx",441,0xd2a2e232)
HX_LOCAL_STACK_FRAME(_hx_pos_bb882bfc11b6c975_449_buildCaches,"polymod.hscript.PolymodScriptClass","buildCaches",0x3b4cbddb,"polymod.hscript.PolymodScriptClass.buildCaches","polymod/hscript/PolymodScriptClass.hx",449,0xd2a2e232)
HX_LOCAL_STACK_FRAME(_hx_pos_bb882bfc11b6c975_36_registerScriptClassByString,"polymod.hscript.PolymodScriptClass","registerScriptClassByString",0x0e021cce,"polymod.hscript.PolymodScriptClass.registerScriptClassByString","polymod/hscript/PolymodScriptClass.hx",36,0xd2a2e232)
HX_LOCAL_STACK_FRAME(_hx_pos_bb882bfc11b6c975_44_registerScriptClassByPath,"polymod.hscript.PolymodScriptClass","registerScriptClassByPath",0x7bfdf062,"polymod.hscript.PolymodScriptClass.registerScriptClassByPath","polymod/hscript/PolymodScriptClass.hx",44,0xd2a2e232)
HX_LOCAL_STACK_FRAME(_hx_pos_bb882bfc11b6c975_57_registerAllScriptClasses,"polymod.hscript.PolymodScriptClass","registerAllScriptClasses",0xd57aa4e1,"polymod.hscript.PolymodScriptClass.registerAllScriptClasses","polymod/hscript/PolymodScriptClass.hx",57,0xd2a2e232)
HX_LOCAL_STACK_FRAME(_hx_pos_bb882bfc11b6c975_70_clearScriptClasses,"polymod.hscript.PolymodScriptClass","clearScriptClasses",0x79a5fd72,"polymod.hscript.PolymodScriptClass.clearScriptClasses","polymod/hscript/PolymodScriptClass.hx",70,0xd2a2e232)
HX_LOCAL_STACK_FRAME(_hx_pos_bb882bfc11b6c975_78_listScriptClasses,"polymod.hscript.PolymodScriptClass","listScriptClasses",0x773f95b9,"polymod.hscript.PolymodScriptClass.listScriptClasses","polymod/hscript/PolymodScriptClass.hx",78,0xd2a2e232)
HX_LOCAL_STACK_FRAME(_hx_pos_bb882bfc11b6c975_93_listScriptClassesExtending,"polymod.hscript.PolymodScriptClass","listScriptClassesExtending",0xf36faa4f,"polymod.hscript.PolymodScriptClass.listScriptClassesExtending","polymod/hscript/PolymodScriptClass.hx",93,0xd2a2e232)
HX_LOCAL_STACK_FRAME(_hx_pos_bb882bfc11b6c975_114_listScriptClassesExtendingClass,"polymod.hscript.PolymodScriptClass","listScriptClassesExtendingClass",0x573f7f69,"polymod.hscript.PolymodScriptClass.listScriptClassesExtendingClass","polymod/hscript/PolymodScriptClass.hx",114,0xd2a2e232)
HX_LOCAL_STACK_FRAME(_hx_pos_bb882bfc11b6c975_118_getSuperClasses,"polymod.hscript.PolymodScriptClass","getSuperClasses",0xb1f9763d,"polymod.hscript.PolymodScriptClass.getSuperClasses","polymod/hscript/PolymodScriptClass.hx",118,0xd2a2e232)
HX_LOCAL_STACK_FRAME(_hx_pos_bb882bfc11b6c975_173_createScriptClassInstance,"polymod.hscript.PolymodScriptClass","createScriptClassInstance",0x7dc4f262,"polymod.hscript.PolymodScriptClass.createScriptClassInstance","polymod/hscript/PolymodScriptClass.hx",173,0xd2a2e232)
HX_LOCAL_STACK_FRAME(_hx_pos_bb882bfc11b6c975_25_boot,"polymod.hscript.PolymodScriptClass","boot",0x2b322096,"polymod.hscript.PolymodScriptClass.boot","polymod/hscript/PolymodScriptClass.hx",25,0xd2a2e232)
HX_LOCAL_STACK_FRAME(_hx_pos_bb882bfc11b6c975_26_boot,"polymod.hscript.PolymodScriptClass","boot",0x2b322096,"polymod.hscript.PolymodScriptClass.boot","polymod/hscript/PolymodScriptClass.hx",26,0xd2a2e232)
namespace polymod{
namespace hscript{

void PolymodScriptClass_obj::__construct( ::Dynamic c,::cpp::VirtualArray args){
            	HX_GC_STACKFRAME(&_hx_pos_bb882bfc11b6c975_20_new)
HXLINE( 446)		this->_cachedVarDecls = null();
HXLINE( 445)		this->_cachedFunctionDecls = null();
HXLINE( 444)		this->_cachedFieldDecls = null();
HXLINE( 322)		this->superClass = null();
HXLINE( 181)		::hx::Class targetClass = null();
HXLINE( 182)		{
HXLINE( 182)			 ::hscript::CType _g = c->__Field(HX_("extend",da,d1,1a,c7),::hx::paccDynamic);
HXDLIN( 182)			if (::hx::IsNull( _g )) {
HXLINE( 187)				 ::Dynamic _hx_tmp = ::haxe::Log_obj::trace;
HXDLIN( 187)				::String _hx_tmp1 = (HX_("Could not determine target class for: ",71,9c,bd,86) + ::Std_obj::string(c));
HXDLIN( 187)				_hx_tmp(_hx_tmp1,::hx::SourceInfo(HX_("polymod/hscript/PolymodScriptClass.hx",32,e2,a2,d2),187,HX_("polymod.hscript.PolymodScriptClass",8a,1e,8b,1c),HX_("new",60,d0,53,00)));
            			}
            			else {
HXLINE( 182)				if ((_g->_hx_getIndex() == 0)) {
HXLINE( 184)					::Array< ::String > pth = _g->_hx_getObject(0).StaticCast< ::Array< ::String > >();
HXDLIN( 184)					::Array< ::Dynamic> params = _g->_hx_getObject(1).StaticCast< ::Array< ::Dynamic> >();
HXLINE( 185)					::Dynamic this1 = ::polymod::hscript::PolymodScriptClass_obj::scriptClassOverrides;
HXDLIN( 185)					targetClass = ( ( ::haxe::ds::StringMap)(this1) )->get(pth->join(HX_(".",2e,00,00,00)));
            				}
            				else {
HXLINE( 187)					 ::Dynamic _hx_tmp = ::haxe::Log_obj::trace;
HXDLIN( 187)					::String _hx_tmp1 = (HX_("Could not determine target class for: ",71,9c,bd,86) + ::Std_obj::string(c));
HXDLIN( 187)					_hx_tmp(_hx_tmp1,::hx::SourceInfo(HX_("polymod/hscript/PolymodScriptClass.hx",32,e2,a2,d2),187,HX_("polymod.hscript.PolymodScriptClass",8a,1e,8b,1c),HX_("new",60,d0,53,00)));
            				}
            			}
            		}
HXLINE( 189)		this->_interp =  ::polymod::hscript::PolymodInterpEx_obj::__alloc( HX_CTX ,targetClass,::hx::ObjectPtr<OBJ_>(this));
HXLINE( 190)		this->_c = c;
HXLINE( 191)		this->buildCaches();
HXLINE( 193)		 ::Dynamic ctorField = this->findField(HX_("new",60,d0,53,00));
HXLINE( 194)		if (::hx::IsNotNull( ctorField )) {
HXLINE( 196)			this->callFunction(HX_("new",60,d0,53,00),args);
HXLINE( 197)			bool _hx_tmp;
HXDLIN( 197)			if (::hx::IsNull( this->superClass )) {
HXLINE( 197)				_hx_tmp = ::hx::IsNotNull( this->_c->__Field(HX_("extend",da,d1,1a,c7),::hx::paccDynamic) );
            			}
            			else {
HXLINE( 197)				_hx_tmp = false;
            			}
HXDLIN( 197)			if (_hx_tmp) {
HXLINE( 199)				 ::hscript::Error e = ::hscript::Error_obj::ECustom(HX_("super() not called",4e,ec,82,2e));
HXDLIN( 199)				HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(e));
            			}
            		}
            		else {
HXLINE( 202)			if (::hx::IsNotNull( this->_c->__Field(HX_("extend",da,d1,1a,c7),::hx::paccDynamic) )) {
HXLINE( 204)				this->createSuperClass(args);
            			}
            		}
            	}

Dynamic PolymodScriptClass_obj::__CreateEmpty() { return new PolymodScriptClass_obj; }

void *PolymodScriptClass_obj::_hx_vtable = 0;

Dynamic PolymodScriptClass_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< PolymodScriptClass_obj > _hx_result = new PolymodScriptClass_obj();
	_hx_result->__construct(inArgs[0],inArgs[1]);
	return _hx_result;
}

bool PolymodScriptClass_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x5fef6af4;
}

void PolymodScriptClass_obj::createSuperClass(::cpp::VirtualArray args){
            	HX_GC_STACKFRAME(&_hx_pos_bb882bfc11b6c975_209_createSuperClass)
HXLINE( 210)		if (::hx::IsNull( args )) {
HXLINE( 212)			args = ::cpp::VirtualArray_obj::__new(0);
            		}
HXLINE( 215)		::String extendString =  ::hscript::Printer_obj::__alloc( HX_CTX )->typeToString(this->_c->__Field(HX_("extend",da,d1,1a,c7),::hx::paccDynamic));
HXLINE( 216)		bool _hx_tmp;
HXDLIN( 216)		if (::hx::IsNotNull( this->_c->__Field(HX_("pkg",0c,5a,55,00),::hx::paccDynamic) )) {
HXLINE( 216)			_hx_tmp = (extendString.indexOf(HX_(".",2e,00,00,00),null()) == -1);
            		}
            		else {
HXLINE( 216)			_hx_tmp = false;
            		}
HXDLIN( 216)		if (_hx_tmp) {
HXLINE( 218)			extendString = ((( (::Array< ::String >)(this->_c->__Field(HX_("pkg",0c,5a,55,00),::hx::paccDynamic)) )->join(HX_(".",2e,00,00,00)) + HX_(".",2e,00,00,00)) + extendString);
            		}
HXLINE( 221)		 ::Dynamic classDescriptor = ::polymod::hscript::PolymodInterpEx_obj::findScriptClassDescriptor(extendString);
HXLINE( 222)		if (::hx::IsNotNull( classDescriptor )) {
HXLINE( 224)			 ::polymod::hscript::PolymodScriptClass abstractSuperClass =  ::polymod::hscript::PolymodScriptClass_obj::__alloc( HX_CTX ,classDescriptor,args);
HXLINE( 225)			this->superClass = abstractSuperClass;
            		}
            		else {
HXLINE( 229)			::hx::Class clsToCreate = null();
HXLINE( 232)			if (::polymod::hscript::PolymodScriptClass_obj::scriptClassOverrides->exists(extendString)) {
HXLINE( 235)				clsToCreate = ::polymod::hscript::PolymodScriptClass_obj::scriptClassOverrides->get(extendString);
            			}
HXLINE( 237)			if (::hx::IsNull( clsToCreate )) {
HXLINE( 239)				clsToCreate = ::Type_obj::resolveClass(extendString);
            			}
HXLINE( 241)			if (::hx::IsNull( clsToCreate )) {
HXLINE( 243)				 ::hscript::Error e = ::hscript::Error_obj::ECustom((HX_("could not resolve super class: ",59,6c,54,7d) + extendString));
HXDLIN( 243)				HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(e));
            			}
HXLINE( 246)			this->superClass = ::Type_obj::createInstance(clsToCreate,args);
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(PolymodScriptClass_obj,createSuperClass,(void))

 ::Dynamic PolymodScriptClass_obj::callFunction(::String name,::cpp::VirtualArray args){
            	HX_GC_STACKFRAME(&_hx_pos_bb882bfc11b6c975_251_callFunction)
HXLINE( 253)		 ::Dynamic field = this->findField(name);
HXLINE( 254)		 ::Dynamic r = null();
HXLINE( 256)		if (::hx::IsNotNull( field )) {
HXLINE( 259)			 ::Dynamic fn = this->findFunction(name);
HXLINE( 260)			 ::haxe::ds::StringMap previousValues =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
HXLINE( 261)			int i = 0;
HXLINE( 262)			{
HXLINE( 262)				int _g = 0;
HXDLIN( 262)				::Array< ::Dynamic> _g1 = ( (::Array< ::Dynamic>)(fn->__Field(HX_("args",5d,8d,74,40),::hx::paccDynamic)) );
HXDLIN( 262)				while((_g < _g1->length)){
HXLINE( 262)					 ::Dynamic a = _g1->__get(_g);
HXDLIN( 262)					_g = (_g + 1);
HXLINE( 264)					 ::Dynamic value = null();
HXLINE( 266)					bool _hx_tmp;
HXDLIN( 266)					if (::hx::IsNotNull( args )) {
HXLINE( 266)						_hx_tmp = (i < args->get_length());
            					}
            					else {
HXLINE( 266)						_hx_tmp = false;
            					}
HXDLIN( 266)					if (_hx_tmp) {
HXLINE( 268)						value = args->__get(i);
            					}
            					else {
HXLINE( 270)						if (::hx::IsNotNull( a->__Field(HX_("value",71,7f,b8,31),::hx::paccDynamic) )) {
HXLINE( 272)							value = this->_interp->expr(a->__Field(HX_("value",71,7f,b8,31),::hx::paccDynamic));
            						}
            					}
HXLINE( 275)					if (this->_interp->variables->exists(( (::String)(a->__Field(HX_("name",4b,72,ff,48),::hx::paccDynamic)) ))) {
HXLINE( 277)						::String key = ( (::String)(a->__Field(HX_("name",4b,72,ff,48),::hx::paccDynamic)) );
HXDLIN( 277)						previousValues->set(key,this->_interp->variables->get( ::Dynamic(a->__Field(HX_("name",4b,72,ff,48),::hx::paccDynamic))));
            					}
HXLINE( 279)					this->_interp->variables->set(( (::String)(a->__Field(HX_("name",4b,72,ff,48),::hx::paccDynamic)) ),value);
HXLINE( 280)					i = (i + 1);
            				}
            			}
HXLINE( 283)			r = this->_interp->execute(fn->__Field(HX_("expr",35,fd,1d,43),::hx::paccDynamic));
HXLINE( 285)			{
HXLINE( 285)				int _g2 = 0;
HXDLIN( 285)				::Array< ::Dynamic> _g3 = ( (::Array< ::Dynamic>)(fn->__Field(HX_("args",5d,8d,74,40),::hx::paccDynamic)) );
HXDLIN( 285)				while((_g2 < _g3->length)){
HXLINE( 285)					 ::Dynamic a = _g3->__get(_g2);
HXDLIN( 285)					_g2 = (_g2 + 1);
HXLINE( 287)					if (previousValues->exists(( (::String)(a->__Field(HX_("name",4b,72,ff,48),::hx::paccDynamic)) ))) {
HXLINE( 289)						::Dynamic this1 = this->_interp->variables;
HXDLIN( 289)						::String key = ( (::String)(a->__Field(HX_("name",4b,72,ff,48),::hx::paccDynamic)) );
HXDLIN( 289)						( ( ::haxe::ds::StringMap)(this1) )->set(key,previousValues->get( ::Dynamic(a->__Field(HX_("name",4b,72,ff,48),::hx::paccDynamic))));
            					}
            					else {
HXLINE( 293)						this->_interp->variables->remove(( (::String)(a->__Field(HX_("name",4b,72,ff,48),::hx::paccDynamic)) ));
            					}
            				}
            			}
            		}
            		else {
HXLINE( 300)			::cpp::VirtualArray fixedArgs = ::cpp::VirtualArray_obj::__new(0);
HXLINE( 302)			::String fixedName = (HX_("__super_",a4,b5,70,4b) + name);
HXLINE( 303)			{
HXLINE( 303)				int _g = 0;
HXDLIN( 303)				while((_g < args->get_length())){
HXLINE( 303)					 ::Dynamic a = args->__get(_g);
HXDLIN( 303)					_g = (_g + 1);
HXLINE( 305)					if (::Std_obj::isOfType(a,::hx::ClassOf< ::polymod::hscript::PolymodScriptClass >())) {
HXLINE( 307)						fixedArgs->push(::hx::TCast<  ::polymod::hscript::PolymodScriptClass >::cast(a)->superClass);
            					}
            					else {
HXLINE( 311)						fixedArgs->push(a);
            					}
            				}
            			}
HXLINE( 314)			 ::Dynamic r1 = this->superClass;
HXDLIN( 314)			r = ::Reflect_obj::callMethod(r1,::Reflect_obj::field(this->superClass,fixedName),fixedArgs);
            		}
HXLINE( 316)		return r;
            	}


HX_DEFINE_DYNAMIC_FUNC2(PolymodScriptClass_obj,callFunction,return )

::String PolymodScriptClass_obj::get_className(){
            	HX_STACKFRAME(&_hx_pos_bb882bfc11b6c975_327_get_className)
HXLINE( 328)		::String name = HX_("",00,00,00,00);
HXLINE( 329)		if (::hx::IsNotNull( this->_c->__Field(HX_("pkg",0c,5a,55,00),::hx::paccDynamic) )) {
HXLINE( 331)			name = (name + ( (::Array< ::String >)(this->_c->__Field(HX_("pkg",0c,5a,55,00),::hx::paccDynamic)) )->join(HX_(".",2e,00,00,00)));
            		}
HXLINE( 333)		name = ( (::String)((name + this->_c->__Field(HX_("name",4b,72,ff,48),::hx::paccDynamic))) );
HXLINE( 334)		return name;
            	}


HX_DEFINE_DYNAMIC_FUNC0(PolymodScriptClass_obj,get_className,return )

void PolymodScriptClass_obj::superConstructor( ::Dynamic __o_arg0, ::Dynamic __o_arg1, ::Dynamic __o_arg2, ::Dynamic __o_arg3){
            		 ::Dynamic arg0 = __o_arg0;
            		if (::hx::IsNull(__o_arg0)) arg0 = ::polymod::hscript::Param_obj::Unused_dyn();
            		 ::Dynamic arg1 = __o_arg1;
            		if (::hx::IsNull(__o_arg1)) arg1 = ::polymod::hscript::Param_obj::Unused_dyn();
            		 ::Dynamic arg2 = __o_arg2;
            		if (::hx::IsNull(__o_arg2)) arg2 = ::polymod::hscript::Param_obj::Unused_dyn();
            		 ::Dynamic arg3 = __o_arg3;
            		if (::hx::IsNull(__o_arg3)) arg3 = ::polymod::hscript::Param_obj::Unused_dyn();
            	HX_STACKFRAME(&_hx_pos_bb882bfc11b6c975_338_superConstructor)
HXLINE( 339)		::cpp::VirtualArray args = ::cpp::VirtualArray_obj::__new(0);
HXLINE( 340)		if (::hx::IsPointerNotEq( arg0,::polymod::hscript::Param_obj::Unused_dyn() )) {
HXLINE( 341)			args->push(arg0);
            		}
HXLINE( 342)		if (::hx::IsPointerNotEq( arg1,::polymod::hscript::Param_obj::Unused_dyn() )) {
HXLINE( 343)			args->push(arg1);
            		}
HXLINE( 344)		if (::hx::IsPointerNotEq( arg2,::polymod::hscript::Param_obj::Unused_dyn() )) {
HXLINE( 345)			args->push(arg2);
            		}
HXLINE( 346)		if (::hx::IsPointerNotEq( arg3,::polymod::hscript::Param_obj::Unused_dyn() )) {
HXLINE( 347)			args->push(arg3);
            		}
HXLINE( 348)		this->createSuperClass(args);
            	}


HX_DEFINE_DYNAMIC_FUNC4(PolymodScriptClass_obj,superConstructor,(void))

 ::Dynamic PolymodScriptClass_obj::callFunction0(::String name){
            	HX_STACKFRAME(&_hx_pos_bb882bfc11b6c975_353_callFunction0)
HXDLIN( 353)		return this->callFunction(name,null());
            	}


HX_DEFINE_DYNAMIC_FUNC1(PolymodScriptClass_obj,callFunction0,return )

 ::Dynamic PolymodScriptClass_obj::callFunction1(::String name, ::Dynamic arg0){
            	HX_STACKFRAME(&_hx_pos_bb882bfc11b6c975_358_callFunction1)
HXDLIN( 358)		return this->callFunction(name,::cpp::VirtualArray_obj::__new(1)->init(0,arg0));
            	}


HX_DEFINE_DYNAMIC_FUNC2(PolymodScriptClass_obj,callFunction1,return )

 ::Dynamic PolymodScriptClass_obj::callFunction2(::String name, ::Dynamic arg0, ::Dynamic arg1){
            	HX_STACKFRAME(&_hx_pos_bb882bfc11b6c975_363_callFunction2)
HXDLIN( 363)		return this->callFunction(name,::cpp::VirtualArray_obj::__new(2)->init(0,arg0)->init(1,arg1));
            	}


HX_DEFINE_DYNAMIC_FUNC3(PolymodScriptClass_obj,callFunction2,return )

 ::Dynamic PolymodScriptClass_obj::callFunction3(::String name, ::Dynamic arg0, ::Dynamic arg1, ::Dynamic arg2){
            	HX_STACKFRAME(&_hx_pos_bb882bfc11b6c975_368_callFunction3)
HXDLIN( 368)		return this->callFunction(name,::cpp::VirtualArray_obj::__new(3)->init(0,arg0)->init(1,arg1)->init(2,arg2));
            	}


HX_DEFINE_DYNAMIC_FUNC4(PolymodScriptClass_obj,callFunction3,return )

 ::Dynamic PolymodScriptClass_obj::callFunction4(::String name, ::Dynamic arg0, ::Dynamic arg1, ::Dynamic arg2, ::Dynamic arg3){
            	HX_STACKFRAME(&_hx_pos_bb882bfc11b6c975_373_callFunction4)
HXDLIN( 373)		return this->callFunction(name,::cpp::VirtualArray_obj::__new(4)->init(0,arg0)->init(1,arg1)->init(2,arg2)->init(3,arg3));
            	}


HX_DEFINE_DYNAMIC_FUNC5(PolymodScriptClass_obj,callFunction4,return )

 ::Dynamic PolymodScriptClass_obj::findFunction(::String name){
            	HX_STACKFRAME(&_hx_pos_bb882bfc11b6c975_377_findFunction)
HXLINE( 378)		if (::hx::IsNotNull( this->_cachedFunctionDecls )) {
HXLINE( 380)			return this->_cachedFunctionDecls->get(name);
            		}
HXLINE( 383)		{
HXLINE( 383)			int _g = 0;
HXDLIN( 383)			::Array< ::Dynamic> _g1 = ( (::Array< ::Dynamic>)(this->_c->__Field(HX_("fields",79,8e,8e,80),::hx::paccDynamic)) );
HXDLIN( 383)			while((_g < _g1->length)){
HXLINE( 383)				 ::Dynamic f = _g1->__get(_g);
HXDLIN( 383)				_g = (_g + 1);
HXLINE( 385)				if (::hx::IsEq( f->__Field(HX_("name",4b,72,ff,48),::hx::paccDynamic),name )) {
HXLINE( 387)					 ::hscript::FieldKind _g = f->__Field(HX_("kind",54,e1,09,47),::hx::paccDynamic);
HXDLIN( 387)					if ((_g->_hx_getIndex() == 0)) {
HXLINE( 389)						 ::Dynamic fn = _g->_hx_getObject(0);
HXLINE( 390)						return fn;
            					}
            				}
            			}
            		}
HXLINE( 396)		return null();
            	}


HX_DEFINE_DYNAMIC_FUNC1(PolymodScriptClass_obj,findFunction,return )

 ::Dynamic PolymodScriptClass_obj::findVar(::String name){
            	HX_STACKFRAME(&_hx_pos_bb882bfc11b6c975_400_findVar)
HXLINE( 401)		if (::hx::IsNotNull( this->_cachedVarDecls )) {
HXLINE( 403)			this->_cachedVarDecls->get_bool(name);
            		}
HXLINE( 406)		{
HXLINE( 406)			int _g = 0;
HXDLIN( 406)			::Array< ::Dynamic> _g1 = ( (::Array< ::Dynamic>)(this->_c->__Field(HX_("fields",79,8e,8e,80),::hx::paccDynamic)) );
HXDLIN( 406)			while((_g < _g1->length)){
HXLINE( 406)				 ::Dynamic f = _g1->__get(_g);
HXDLIN( 406)				_g = (_g + 1);
HXLINE( 408)				if (::hx::IsEq( f->__Field(HX_("name",4b,72,ff,48),::hx::paccDynamic),name )) {
HXLINE( 410)					 ::hscript::FieldKind _g = f->__Field(HX_("kind",54,e1,09,47),::hx::paccDynamic);
HXDLIN( 410)					if ((_g->_hx_getIndex() == 1)) {
HXLINE( 412)						 ::Dynamic v = _g->_hx_getObject(0);
HXLINE( 413)						return v;
            					}
            				}
            			}
            		}
HXLINE( 419)		return null();
            	}


HX_DEFINE_DYNAMIC_FUNC1(PolymodScriptClass_obj,findVar,return )

 ::Dynamic PolymodScriptClass_obj::findField(::String name){
            	HX_STACKFRAME(&_hx_pos_bb882bfc11b6c975_423_findField)
HXLINE( 424)		if (::hx::IsNotNull( this->_cachedFieldDecls )) {
HXLINE( 426)			return this->_cachedFieldDecls->get(name);
            		}
HXLINE( 429)		{
HXLINE( 429)			int _g = 0;
HXDLIN( 429)			::Array< ::Dynamic> _g1 = ( (::Array< ::Dynamic>)(this->_c->__Field(HX_("fields",79,8e,8e,80),::hx::paccDynamic)) );
HXDLIN( 429)			while((_g < _g1->length)){
HXLINE( 429)				 ::Dynamic f = _g1->__get(_g);
HXDLIN( 429)				_g = (_g + 1);
HXLINE( 431)				if (::hx::IsEq( f->__Field(HX_("name",4b,72,ff,48),::hx::paccDynamic),name )) {
HXLINE( 433)					return f;
            				}
            			}
            		}
HXLINE( 436)		return null();
            	}


HX_DEFINE_DYNAMIC_FUNC1(PolymodScriptClass_obj,findField,return )

 ::haxe::ds::StringMap PolymodScriptClass_obj::listFunctions(){
            	HX_STACKFRAME(&_hx_pos_bb882bfc11b6c975_441_listFunctions)
HXDLIN( 441)		return this->_cachedFunctionDecls;
            	}


HX_DEFINE_DYNAMIC_FUNC0(PolymodScriptClass_obj,listFunctions,return )

void PolymodScriptClass_obj::buildCaches(){
            	HX_GC_STACKFRAME(&_hx_pos_bb882bfc11b6c975_449_buildCaches)
HXLINE( 450)		this->_cachedFieldDecls =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
HXLINE( 451)		this->_cachedFunctionDecls =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
HXLINE( 452)		this->_cachedVarDecls =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
HXLINE( 454)		{
HXLINE( 454)			int _g = 0;
HXDLIN( 454)			::Array< ::Dynamic> _g1 = ( (::Array< ::Dynamic>)(this->_c->__Field(HX_("fields",79,8e,8e,80),::hx::paccDynamic)) );
HXDLIN( 454)			while((_g < _g1->length)){
HXLINE( 454)				 ::Dynamic f = _g1->__get(_g);
HXDLIN( 454)				_g = (_g + 1);
HXLINE( 456)				this->_cachedFieldDecls->set(( (::String)(f->__Field(HX_("name",4b,72,ff,48),::hx::paccDynamic)) ),f);
HXLINE( 457)				{
HXLINE( 457)					 ::hscript::FieldKind _g2 = f->__Field(HX_("kind",54,e1,09,47),::hx::paccDynamic);
HXDLIN( 457)					switch((int)(_g2->_hx_getIndex())){
            						case (int)0: {
HXLINE( 459)							 ::Dynamic fn = _g2->_hx_getObject(0);
HXLINE( 460)							this->_cachedFunctionDecls->set(( (::String)(f->__Field(HX_("name",4b,72,ff,48),::hx::paccDynamic)) ),fn);
            						}
            						break;
            						case (int)1: {
HXLINE( 461)							 ::Dynamic v = _g2->_hx_getObject(0);
HXDLIN( 461)							{
HXLINE( 462)								this->_cachedVarDecls->set(( (::String)(f->__Field(HX_("name",4b,72,ff,48),::hx::paccDynamic)) ),v);
HXLINE( 463)								if (::hx::IsNotNull( v->__Field(HX_("expr",35,fd,1d,43),::hx::paccDynamic) )) {
HXLINE( 465)									 ::Dynamic varValue = this->_interp->expr(v->__Field(HX_("expr",35,fd,1d,43),::hx::paccDynamic));
HXLINE( 466)									this->_interp->variables->set(( (::String)(f->__Field(HX_("name",4b,72,ff,48),::hx::paccDynamic)) ),varValue);
            								}
            							}
            						}
            						break;
            					}
            				}
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC0(PolymodScriptClass_obj,buildCaches,(void))

 ::polymod::hscript::PolymodInterpEx PolymodScriptClass_obj::scriptInterp;

 ::haxe::ds::StringMap PolymodScriptClass_obj::scriptClassOverrides;

void PolymodScriptClass_obj::registerScriptClassByString(::String body){
            	HX_STACKFRAME(&_hx_pos_bb882bfc11b6c975_36_registerScriptClassByString)
HXDLIN(  36)		::polymod::hscript::PolymodScriptClass_obj::scriptInterp->addModule(body);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(PolymodScriptClass_obj,registerScriptClassByString,(void))

void PolymodScriptClass_obj::registerScriptClassByPath(::String path){
            	HX_STACKFRAME(&_hx_pos_bb882bfc11b6c975_44_registerScriptClassByPath)
HXLINE(  45)		::String scriptBody = ::polymod::Polymod_obj::assetLibrary->getText(path);
HXLINE(  46)		::polymod::hscript::PolymodScriptClass_obj::registerScriptClassByString(scriptBody);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(PolymodScriptClass_obj,registerScriptClassByPath,(void))

void PolymodScriptClass_obj::registerAllScriptClasses(){
            	HX_STACKFRAME(&_hx_pos_bb882bfc11b6c975_57_registerAllScriptClasses)
HXDLIN(  57)		int _g = 0;
HXDLIN(  57)		::Array< ::String > _g1 = ::polymod::Polymod_obj::assetLibrary->list(HX_("TEXT",ad,94,ba,37));
HXDLIN(  57)		while((_g < _g1->length)){
HXDLIN(  57)			::String textPath = _g1->__get(_g);
HXDLIN(  57)			_g = (_g + 1);
HXLINE(  59)			if (::StringTools_obj::endsWith(textPath,::polymod::PolymodConfig_obj::get_scriptClassExt())) {
HXLINE(  61)				::polymod::hscript::PolymodScriptClass_obj::registerScriptClassByPath(textPath);
            			}
            		}
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(PolymodScriptClass_obj,registerAllScriptClasses,(void))

void PolymodScriptClass_obj::clearScriptClasses(){
            	HX_STACKFRAME(&_hx_pos_bb882bfc11b6c975_70_clearScriptClasses)
HXDLIN(  70)		::polymod::hscript::PolymodInterpEx_obj::_scriptClassDescriptors->clear();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(PolymodScriptClass_obj,clearScriptClasses,(void))

::Array< ::String > PolymodScriptClass_obj::listScriptClasses(){
            	HX_STACKFRAME(&_hx_pos_bb882bfc11b6c975_78_listScriptClasses)
HXLINE(  79)		::Array< ::String > result = ::Array_obj< ::String >::__new(0);
HXLINE(  81)		{
HXLINE(  81)			::Dynamic map = ::polymod::hscript::PolymodInterpEx_obj::_scriptClassDescriptors;
HXDLIN(  81)			::Dynamic _g_map = map;
HXDLIN(  81)			 ::Dynamic _g_keys = ::haxe::IMap_obj::keys(map);
HXDLIN(  81)			while(( (bool)(_g_keys->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE(  81)				::String key = ( (::String)(_g_keys->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXDLIN(  81)				 ::Dynamic _g1_value = ::haxe::IMap_obj::get(_g_map,key);
HXDLIN(  81)				::String _g1_key = key;
HXDLIN(  81)				::String key1 = _g1_key;
HXDLIN(  81)				 ::Dynamic _value = _g1_value;
HXLINE(  83)				result->push(key1);
            			}
            		}
HXLINE(  85)		return result;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(PolymodScriptClass_obj,listScriptClasses,return )

::Array< ::String > PolymodScriptClass_obj::listScriptClassesExtending(::String clsPath){
            	HX_STACKFRAME(&_hx_pos_bb882bfc11b6c975_93_listScriptClassesExtending)
HXLINE(  94)		::Array< ::String > result = ::Array_obj< ::String >::__new(0);
HXLINE(  96)		{
HXLINE(  96)			::Dynamic map = ::polymod::hscript::PolymodInterpEx_obj::_scriptClassDescriptors;
HXDLIN(  96)			::Dynamic _g_map = map;
HXDLIN(  96)			 ::Dynamic _g_keys = ::haxe::IMap_obj::keys(map);
HXDLIN(  96)			while(( (bool)(_g_keys->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE(  96)				::String key = ( (::String)(_g_keys->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXDLIN(  96)				 ::Dynamic _g1_value = ::haxe::IMap_obj::get(_g_map,key);
HXDLIN(  96)				::String _g1_key = key;
HXDLIN(  96)				::String key1 = _g1_key;
HXDLIN(  96)				 ::Dynamic value = _g1_value;
HXLINE(  97)				{
HXLINE(  98)					::Array< ::String > superClasses = ::polymod::hscript::PolymodScriptClass_obj::getSuperClasses(value);
HXLINE(  99)					if ((superClasses->indexOf(clsPath,null()) != -1)) {
HXLINE( 101)						result->push(key1);
            					}
            				}
            			}
            		}
HXLINE( 104)		return result;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(PolymodScriptClass_obj,listScriptClassesExtending,return )

::Array< ::String > PolymodScriptClass_obj::listScriptClassesExtendingClass(::hx::Class cls){
            	HX_STACKFRAME(&_hx_pos_bb882bfc11b6c975_114_listScriptClassesExtendingClass)
HXDLIN( 114)		return ::polymod::hscript::PolymodScriptClass_obj::listScriptClassesExtending(::Type_obj::getClassName(cls));
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(PolymodScriptClass_obj,listScriptClassesExtendingClass,return )

::Array< ::String > PolymodScriptClass_obj::getSuperClasses( ::Dynamic classDecl){
            	HX_GC_STACKFRAME(&_hx_pos_bb882bfc11b6c975_118_getSuperClasses)
HXLINE( 119)		if (::hx::IsNull( classDecl->__Field(HX_("extend",da,d1,1a,c7),::hx::paccDynamic) )) {
HXLINE( 122)			return ::Array_obj< ::String >::__new(0);
            		}
HXLINE( 126)		::String extendString =  ::hscript::Printer_obj::__alloc( HX_CTX )->typeToString(classDecl->__Field(HX_("extend",da,d1,1a,c7),::hx::paccDynamic));
HXLINE( 128)		bool _hx_tmp;
HXDLIN( 128)		if (::hx::IsNotNull( classDecl->__Field(HX_("pkg",0c,5a,55,00),::hx::paccDynamic) )) {
HXLINE( 128)			_hx_tmp = (extendString.indexOf(HX_(".",2e,00,00,00),null()) == -1);
            		}
            		else {
HXLINE( 128)			_hx_tmp = false;
            		}
HXDLIN( 128)		if (_hx_tmp) {
HXLINE( 130)			::String extendPkg = ( (::Array< ::String >)(classDecl->__Field(HX_("pkg",0c,5a,55,00),::hx::paccDynamic)) )->join(HX_(".",2e,00,00,00));
HXLINE( 131)			extendString = (((HX_("",00,00,00,00) + extendPkg) + HX_(".",2e,00,00,00)) + extendString);
            		}
HXLINE( 135)		 ::Dynamic classDescriptor = ::polymod::hscript::PolymodInterpEx_obj::findScriptClassDescriptor(extendString);
HXLINE( 137)		if (::hx::IsNotNull( classDescriptor )) {
HXLINE( 139)			::Array< ::String > result = ::Array_obj< ::String >::__new(1)->init(0,extendString);
HXLINE( 142)			return result->concat(::polymod::hscript::PolymodScriptClass_obj::getSuperClasses(classDescriptor));
            		}
            		else {
HXLINE( 147)			::hx::Class superClass = ::Type_obj::resolveClass(extendString);
HXLINE( 148)			if (::hx::IsNotNull( superClass )) {
HXLINE( 150)				::Array< ::String > result = ::Array_obj< ::String >::__new(0);
HXLINE( 152)				while(::hx::IsNotNull( superClass )){
HXLINE( 155)					result->push(::Type_obj::getClassName(superClass));
HXLINE( 158)					superClass = ::Type_obj::getSuperClass(superClass);
            				}
HXLINE( 160)				return result;
            			}
            			else {
HXLINE( 165)				::polymod::Polymod_obj::error(HX_("script_class_not_found",5b,b3,70,1a),((HX_("The superclass ",54,0a,f1,df) + extendString) + HX_(" could not be found, is it a valid class?",4e,f4,82,ee)),null());
HXLINE( 166)				return ::Array_obj< ::String >::__new(0);
            			}
            		}
HXLINE( 137)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(PolymodScriptClass_obj,getSuperClasses,return )

 ::polymod::hscript::PolymodScriptClass PolymodScriptClass_obj::createScriptClassInstance(::String name,::cpp::VirtualArray args){
            	HX_STACKFRAME(&_hx_pos_bb882bfc11b6c975_173_createScriptClassInstance)
HXDLIN( 173)		return ::polymod::hscript::PolymodScriptClass_obj::scriptInterp->createScriptClassInstance(name,args);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(PolymodScriptClass_obj,createScriptClassInstance,return )


::hx::ObjectPtr< PolymodScriptClass_obj > PolymodScriptClass_obj::__new( ::Dynamic c,::cpp::VirtualArray args) {
	::hx::ObjectPtr< PolymodScriptClass_obj > __this = new PolymodScriptClass_obj();
	__this->__construct(c,args);
	return __this;
}

::hx::ObjectPtr< PolymodScriptClass_obj > PolymodScriptClass_obj::__alloc(::hx::Ctx *_hx_ctx, ::Dynamic c,::cpp::VirtualArray args) {
	PolymodScriptClass_obj *__this = (PolymodScriptClass_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(PolymodScriptClass_obj), true, "polymod.hscript.PolymodScriptClass"));
	*(void **)__this = PolymodScriptClass_obj::_hx_vtable;
	__this->__construct(c,args);
	return __this;
}

PolymodScriptClass_obj::PolymodScriptClass_obj()
{
}

void PolymodScriptClass_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PolymodScriptClass);
	HX_MARK_MEMBER_NAME(_c,"_c");
	HX_MARK_MEMBER_NAME(_interp,"_interp");
	HX_MARK_MEMBER_NAME(superClass,"superClass");
	HX_MARK_MEMBER_NAME(className,"className");
	HX_MARK_MEMBER_NAME(_cachedFieldDecls,"_cachedFieldDecls");
	HX_MARK_MEMBER_NAME(_cachedFunctionDecls,"_cachedFunctionDecls");
	HX_MARK_MEMBER_NAME(_cachedVarDecls,"_cachedVarDecls");
	HX_MARK_END_CLASS();
}

void PolymodScriptClass_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_c,"_c");
	HX_VISIT_MEMBER_NAME(_interp,"_interp");
	HX_VISIT_MEMBER_NAME(superClass,"superClass");
	HX_VISIT_MEMBER_NAME(className,"className");
	HX_VISIT_MEMBER_NAME(_cachedFieldDecls,"_cachedFieldDecls");
	HX_VISIT_MEMBER_NAME(_cachedFunctionDecls,"_cachedFunctionDecls");
	HX_VISIT_MEMBER_NAME(_cachedVarDecls,"_cachedVarDecls");
}

::hx::Val PolymodScriptClass_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"_c") ) { return ::hx::Val( _c ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_interp") ) { return ::hx::Val( _interp ); }
		if (HX_FIELD_EQ(inName,"findVar") ) { return ::hx::Val( findVar_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"className") ) { return ::hx::Val( inCallProp == ::hx::paccAlways ? get_className() : className ); }
		if (HX_FIELD_EQ(inName,"findField") ) { return ::hx::Val( findField_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"superClass") ) { return ::hx::Val( superClass ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"buildCaches") ) { return ::hx::Val( buildCaches_dyn() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"callFunction") ) { return ::hx::Val( callFunction_dyn() ); }
		if (HX_FIELD_EQ(inName,"findFunction") ) { return ::hx::Val( findFunction_dyn() ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"get_className") ) { return ::hx::Val( get_className_dyn() ); }
		if (HX_FIELD_EQ(inName,"callFunction0") ) { return ::hx::Val( callFunction0_dyn() ); }
		if (HX_FIELD_EQ(inName,"callFunction1") ) { return ::hx::Val( callFunction1_dyn() ); }
		if (HX_FIELD_EQ(inName,"callFunction2") ) { return ::hx::Val( callFunction2_dyn() ); }
		if (HX_FIELD_EQ(inName,"callFunction3") ) { return ::hx::Val( callFunction3_dyn() ); }
		if (HX_FIELD_EQ(inName,"callFunction4") ) { return ::hx::Val( callFunction4_dyn() ); }
		if (HX_FIELD_EQ(inName,"listFunctions") ) { return ::hx::Val( listFunctions_dyn() ); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_cachedVarDecls") ) { return ::hx::Val( _cachedVarDecls ); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"createSuperClass") ) { return ::hx::Val( createSuperClass_dyn() ); }
		if (HX_FIELD_EQ(inName,"superConstructor") ) { return ::hx::Val( superConstructor_dyn() ); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_cachedFieldDecls") ) { return ::hx::Val( _cachedFieldDecls ); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"_cachedFunctionDecls") ) { return ::hx::Val( _cachedFunctionDecls ); }
	}
	return super::__Field(inName,inCallProp);
}

bool PolymodScriptClass_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"scriptInterp") ) { outValue = ( scriptInterp ); return true; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"getSuperClasses") ) { outValue = getSuperClasses_dyn(); return true; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"listScriptClasses") ) { outValue = listScriptClasses_dyn(); return true; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"clearScriptClasses") ) { outValue = clearScriptClasses_dyn(); return true; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"scriptClassOverrides") ) { outValue = ( scriptClassOverrides ); return true; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"registerAllScriptClasses") ) { outValue = registerAllScriptClasses_dyn(); return true; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"registerScriptClassByPath") ) { outValue = registerScriptClassByPath_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"createScriptClassInstance") ) { outValue = createScriptClassInstance_dyn(); return true; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"listScriptClassesExtending") ) { outValue = listScriptClassesExtending_dyn(); return true; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"registerScriptClassByString") ) { outValue = registerScriptClassByString_dyn(); return true; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"listScriptClassesExtendingClass") ) { outValue = listScriptClassesExtendingClass_dyn(); return true; }
	}
	return false;
}

::hx::Val PolymodScriptClass_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"_c") ) { _c=inValue.Cast<  ::Dynamic >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_interp") ) { _interp=inValue.Cast<  ::polymod::hscript::PolymodInterpEx >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"className") ) { className=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"superClass") ) { superClass=inValue.Cast<  ::Dynamic >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_cachedVarDecls") ) { _cachedVarDecls=inValue.Cast<  ::haxe::ds::StringMap >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_cachedFieldDecls") ) { _cachedFieldDecls=inValue.Cast<  ::haxe::ds::StringMap >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"_cachedFunctionDecls") ) { _cachedFunctionDecls=inValue.Cast<  ::haxe::ds::StringMap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool PolymodScriptClass_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"scriptInterp") ) { scriptInterp=ioValue.Cast<  ::polymod::hscript::PolymodInterpEx >(); return true; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"scriptClassOverrides") ) { scriptClassOverrides=ioValue.Cast<  ::haxe::ds::StringMap >(); return true; }
	}
	return false;
}

void PolymodScriptClass_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("_c",24,53,00,00));
	outFields->push(HX_("_interp",73,8b,fd,0c));
	outFields->push(HX_("superClass",bd,a8,07,a8));
	outFields->push(HX_("className",a3,92,3d,dc));
	outFields->push(HX_("_cachedFieldDecls",90,46,68,95));
	outFields->push(HX_("_cachedFunctionDecls",50,dc,0a,a2));
	outFields->push(HX_("_cachedVarDecls",03,4f,f9,02));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo PolymodScriptClass_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::Dynamic */ ,(int)offsetof(PolymodScriptClass_obj,_c),HX_("_c",24,53,00,00)},
	{::hx::fsObject /*  ::polymod::hscript::PolymodInterpEx */ ,(int)offsetof(PolymodScriptClass_obj,_interp),HX_("_interp",73,8b,fd,0c)},
	{::hx::fsObject /*  ::Dynamic */ ,(int)offsetof(PolymodScriptClass_obj,superClass),HX_("superClass",bd,a8,07,a8)},
	{::hx::fsString,(int)offsetof(PolymodScriptClass_obj,className),HX_("className",a3,92,3d,dc)},
	{::hx::fsObject /*  ::haxe::ds::StringMap */ ,(int)offsetof(PolymodScriptClass_obj,_cachedFieldDecls),HX_("_cachedFieldDecls",90,46,68,95)},
	{::hx::fsObject /*  ::haxe::ds::StringMap */ ,(int)offsetof(PolymodScriptClass_obj,_cachedFunctionDecls),HX_("_cachedFunctionDecls",50,dc,0a,a2)},
	{::hx::fsObject /*  ::haxe::ds::StringMap */ ,(int)offsetof(PolymodScriptClass_obj,_cachedVarDecls),HX_("_cachedVarDecls",03,4f,f9,02)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo PolymodScriptClass_obj_sStaticStorageInfo[] = {
	{::hx::fsObject /*  ::polymod::hscript::PolymodInterpEx */ ,(void *) &PolymodScriptClass_obj::scriptInterp,HX_("scriptInterp",3f,d6,15,36)},
	{::hx::fsObject /*  ::haxe::ds::StringMap */ ,(void *) &PolymodScriptClass_obj::scriptClassOverrides,HX_("scriptClassOverrides",ba,c0,1d,6c)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static ::String PolymodScriptClass_obj_sMemberFields[] = {
	HX_("createSuperClass",d9,26,35,dd),
	HX_("callFunction",d6,4d,95,4c),
	HX_("_c",24,53,00,00),
	HX_("_interp",73,8b,fd,0c),
	HX_("superClass",bd,a8,07,a8),
	HX_("className",a3,92,3d,dc),
	HX_("get_className",7a,66,a1,9d),
	HX_("superConstructor",3f,0f,9f,05),
	HX_("callFunction0",9a,cd,0e,b6),
	HX_("callFunction1",9b,cd,0e,b6),
	HX_("callFunction2",9c,cd,0e,b6),
	HX_("callFunction3",9d,cd,0e,b6),
	HX_("callFunction4",9e,cd,0e,b6),
	HX_("findFunction",71,98,d0,01),
	HX_("findVar",2e,f0,74,25),
	HX_("findField",c1,c5,8a,ef),
	HX_("listFunctions",1d,52,37,c0),
	HX_("_cachedFieldDecls",90,46,68,95),
	HX_("_cachedFunctionDecls",50,dc,0a,a2),
	HX_("_cachedVarDecls",03,4f,f9,02),
	HX_("buildCaches",bf,45,63,01),
	::String(null()) };

static void PolymodScriptClass_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PolymodScriptClass_obj::scriptInterp,"scriptInterp");
	HX_MARK_MEMBER_NAME(PolymodScriptClass_obj::scriptClassOverrides,"scriptClassOverrides");
};

#ifdef HXCPP_VISIT_ALLOCS
static void PolymodScriptClass_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PolymodScriptClass_obj::scriptInterp,"scriptInterp");
	HX_VISIT_MEMBER_NAME(PolymodScriptClass_obj::scriptClassOverrides,"scriptClassOverrides");
};

#endif

::hx::Class PolymodScriptClass_obj::__mClass;

static ::String PolymodScriptClass_obj_sStaticFields[] = {
	HX_("scriptInterp",3f,d6,15,36),
	HX_("scriptClassOverrides",ba,c0,1d,6c),
	HX_("registerScriptClassByString",b2,ac,fd,14),
	HX_("registerScriptClassByPath",46,ff,ec,dd),
	HX_("registerAllScriptClasses",7d,fe,f9,42),
	HX_("clearScriptClasses",0e,fa,6b,cd),
	HX_("listScriptClasses",9d,20,93,cc),
	HX_("listScriptClassesExtending",eb,a2,ad,42),
	HX_("listScriptClassesExtendingClass",4d,d1,0a,8c),
	HX_("getSuperClasses",21,c0,bb,9a),
	HX_("createScriptClassInstance",46,01,b4,df),
	::String(null())
};

void PolymodScriptClass_obj::__register()
{
	PolymodScriptClass_obj _hx_dummy;
	PolymodScriptClass_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("polymod.hscript.PolymodScriptClass",8a,1e,8b,1c);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &PolymodScriptClass_obj::__GetStatic;
	__mClass->mSetStaticField = &PolymodScriptClass_obj::__SetStatic;
	__mClass->mMarkFunc = PolymodScriptClass_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(PolymodScriptClass_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(PolymodScriptClass_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< PolymodScriptClass_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = PolymodScriptClass_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = PolymodScriptClass_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = PolymodScriptClass_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void PolymodScriptClass_obj::__boot()
{
{
            	HX_GC_STACKFRAME(&_hx_pos_bb882bfc11b6c975_25_boot)
HXDLIN(  25)		scriptInterp =  ::polymod::hscript::PolymodInterpEx_obj::__alloc( HX_CTX ,null(),null());
            	}
{
            	HX_GC_STACKFRAME(&_hx_pos_bb882bfc11b6c975_26_boot)
HXDLIN(  26)		scriptClassOverrides =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
            	}
}

} // end namespace polymod
} // end namespace hscript
