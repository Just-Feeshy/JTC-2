#include <hxcpp.h>

#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_haxe_io_Path
#include <haxe/io/Path.h>
#endif
#ifndef INCLUDED_polymod_Polymod
#include <polymod/Polymod.h>
#endif
#ifndef INCLUDED_polymod_PolymodConfig
#include <polymod/PolymodConfig.h>
#endif
#ifndef INCLUDED_polymod_hscript_Script
#include <polymod/hscript/Script.h>
#endif
#ifndef INCLUDED_polymod_hscript_ScriptRunner
#include <polymod/hscript/ScriptRunner.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_dc57aa8d22eb51e7_205_new,"polymod.hscript.ScriptRunner","new",0x54c8fac0,"polymod.hscript.ScriptRunner.new","polymod/hscript/HScriptable.hx",205,0xab5038e6)
HX_LOCAL_STACK_FRAME(_hx_pos_dc57aa8d22eb51e7_214_load,"polymod.hscript.ScriptRunner","load",0xd9c783c6,"polymod.hscript.ScriptRunner.load","polymod/hscript/HScriptable.hx",214,0xab5038e6)
HX_LOCAL_STACK_FRAME(_hx_pos_dc57aa8d22eb51e7_245_get,"polymod.hscript.ScriptRunner","get",0x54c3aaf6,"polymod.hscript.ScriptRunner.get","polymod/hscript/HScriptable.hx",245,0xab5038e6)
HX_LOCAL_STACK_FRAME(_hx_pos_dc57aa8d22eb51e7_265_execute,"polymod.hscript.ScriptRunner","execute",0x19d6e495,"polymod.hscript.ScriptRunner.execute","polymod/hscript/HScriptable.hx",265,0xab5038e6)
HX_LOCAL_STACK_FRAME(_hx_pos_dc57aa8d22eb51e7_210_clearScripts,"polymod.hscript.ScriptRunner","clearScripts",0x50e5379b,"polymod.hscript.ScriptRunner.clearScripts","polymod/hscript/HScriptable.hx",210,0xab5038e6)
HX_LOCAL_STACK_FRAME(_hx_pos_dc57aa8d22eb51e7_238_scriptPath,"polymod.hscript.ScriptRunner","scriptPath",0x5101a2f0,"polymod.hscript.ScriptRunner.scriptPath","polymod/hscript/HScriptable.hx",238,0xab5038e6)
HX_LOCAL_STACK_FRAME(_hx_pos_dc57aa8d22eb51e7_202_boot,"polymod.hscript.ScriptRunner","boot",0xd32b6dd2,"polymod.hscript.ScriptRunner.boot","polymod/hscript/HScriptable.hx",202,0xab5038e6)
namespace polymod{
namespace hscript{

void ScriptRunner_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_dc57aa8d22eb51e7_205_new)
            	}

Dynamic ScriptRunner_obj::__CreateEmpty() { return new ScriptRunner_obj; }

void *ScriptRunner_obj::_hx_vtable = 0;

Dynamic ScriptRunner_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< ScriptRunner_obj > _hx_result = new ScriptRunner_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool ScriptRunner_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x540eac1c;
}

 ::polymod::hscript::Script ScriptRunner_obj::load(::String name, ::Dynamic assetHandler){
            	HX_GC_STACKFRAME(&_hx_pos_dc57aa8d22eb51e7_214_load)
HXLINE( 215)		if (::hx::IsNull( assetHandler )) {
HXLINE( 217)			::polymod::Polymod_obj::error(HX_("script_no_asset_handler",71,e7,76,7d),HX_("Class does not import an Assets class for Polymod to fetch scripts with!",ba,f6,fa,16),null());
HXLINE( 218)			return null();
            		}
HXLINE( 221)		::String scriptPath = ((HX_("",00,00,00,00) + ::polymod::PolymodConfig_obj::get_scriptLibrary()) + HX_(":",3a,00,00,00));
HXDLIN( 221)		::String scriptPath1 = (scriptPath + ::polymod::PolymodConfig_obj::get_rootPath());
HXDLIN( 221)		::String scriptPath2 = ::haxe::io::Path_obj::join(::Array_obj< ::String >::__new(2)->init(0,scriptPath1)->init(1,((HX_("",00,00,00,00) + name) + ::polymod::PolymodConfig_obj::get_scriptExt())));
HXLINE( 222)		::polymod::Polymod_obj::debug(((HX_("Fetching script \"",e5,ec,bb,b3) + scriptPath2) + HX_("\"...",0c,51,9c,16)),::hx::SourceInfo(HX_("polymod/hscript/HScriptable.hx",e6,38,50,ab),222,HX_("polymod.hscript.ScriptRunner",ce,da,0c,c9),HX_("load",26,9a,b7,47)));
HXLINE( 223)		if (!(( (bool)(assetHandler->__Field(HX_("exists",dc,1d,e0,bf),::hx::paccDynamic)(scriptPath2)) ))) {
HXLINE( 226)			::polymod::Polymod_obj::debug(((HX_("Note: Script at path \"",77,1d,ca,f0) + scriptPath2) + HX_("\" not found! This may cause problems if it is not optional...",8b,ed,22,8f)),::hx::SourceInfo(HX_("polymod/hscript/HScriptable.hx",e6,38,50,ab),226,HX_("polymod.hscript.ScriptRunner",ce,da,0c,c9),HX_("load",26,9a,b7,47)));
HXLINE( 227)			return null();
            		}
HXLINE( 230)		 ::polymod::hscript::Script script =  ::polymod::hscript::Script_obj::__alloc( HX_CTX ,( (::String)(assetHandler->__Field(HX_("getText",63,7c,7c,1f),::hx::paccDynamic)(scriptPath2)) ));
HXLINE( 231)		::polymod::hscript::ScriptRunner_obj::scripts->set(name,script);
HXLINE( 232)		::polymod::Polymod_obj::debug(((HX_("Script ",95,23,35,fa) + name) + HX_(" loaded successfully.",ac,11,6e,71)),::hx::SourceInfo(HX_("polymod/hscript/HScriptable.hx",e6,38,50,ab),232,HX_("polymod.hscript.ScriptRunner",ce,da,0c,c9),HX_("load",26,9a,b7,47)));
HXLINE( 233)		return script;
            	}


HX_DEFINE_DYNAMIC_FUNC2(ScriptRunner_obj,load,return )

 ::polymod::hscript::Script ScriptRunner_obj::get(::String name, ::Dynamic assetHandler){
            	HX_STACKFRAME(&_hx_pos_dc57aa8d22eb51e7_245_get)
HXLINE( 247)		if (!(::polymod::hscript::ScriptRunner_obj::scripts->exists(name))) {
HXLINE( 249)			::polymod::Polymod_obj::debug(((HX_("Note: Late script load (",01,1c,99,a7) + name) + HX_("). This is normal for dynamic pathNames.",2d,46,9d,91)),::hx::SourceInfo(HX_("polymod/hscript/HScriptable.hx",e6,38,50,ab),249,HX_("polymod.hscript.ScriptRunner",ce,da,0c,c9),HX_("get",96,80,4e,00)));
HXLINE( 250)			this->load(name,assetHandler);
            		}
HXLINE( 253)		 ::polymod::hscript::Script result = ( ( ::polymod::hscript::Script)(::polymod::hscript::ScriptRunner_obj::scripts->get(name)) );
HXLINE( 255)		if (::hx::IsNull( result )) {
HXLINE( 258)			return null();
            		}
HXLINE( 261)		return ( ( ::polymod::hscript::Script)(::polymod::hscript::ScriptRunner_obj::scripts->get(name)) );
            	}


HX_DEFINE_DYNAMIC_FUNC2(ScriptRunner_obj,get,return )

 ::Dynamic ScriptRunner_obj::execute(::String name, ::Dynamic assetHandler){
            	HX_STACKFRAME(&_hx_pos_dc57aa8d22eb51e7_265_execute)
HXLINE( 266)		 ::polymod::hscript::Script script = this->get(name,assetHandler);
HXLINE( 267)		if (::hx::IsNull( script )) {
HXLINE( 269)			::polymod::Polymod_obj::error(HX_("script_not_loaded",e5,0d,38,f6),((HX_("Could not load script ",07,17,25,36) + name) + HX_(" for execution.",6d,cd,3c,0e)),null());
            		}
HXLINE( 271)		return script->execute();
            	}


HX_DEFINE_DYNAMIC_FUNC2(ScriptRunner_obj,execute,return )

 ::haxe::ds::StringMap ScriptRunner_obj::scripts;

void ScriptRunner_obj::clearScripts(){
            	HX_STACKFRAME(&_hx_pos_dc57aa8d22eb51e7_210_clearScripts)
HXDLIN( 210)		::polymod::hscript::ScriptRunner_obj::scripts->clear();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(ScriptRunner_obj,clearScripts,(void))

::String ScriptRunner_obj::scriptPath(::String pathName){
            	HX_STACKFRAME(&_hx_pos_dc57aa8d22eb51e7_238_scriptPath)
HXLINE( 239)		::String _hx_tmp = ((HX_("",00,00,00,00) + ::polymod::PolymodConfig_obj::get_scriptLibrary()) + HX_(":",3a,00,00,00));
HXDLIN( 239)		::String _hx_tmp1 = (_hx_tmp + ::polymod::PolymodConfig_obj::get_rootPath());
HXLINE( 238)		return ::haxe::io::Path_obj::join(::Array_obj< ::String >::__new(2)->init(0,_hx_tmp1)->init(1,((HX_("",00,00,00,00) + pathName) + ::polymod::PolymodConfig_obj::get_scriptExt())));
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ScriptRunner_obj,scriptPath,return )


::hx::ObjectPtr< ScriptRunner_obj > ScriptRunner_obj::__new() {
	::hx::ObjectPtr< ScriptRunner_obj > __this = new ScriptRunner_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< ScriptRunner_obj > ScriptRunner_obj::__alloc(::hx::Ctx *_hx_ctx) {
	ScriptRunner_obj *__this = (ScriptRunner_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(ScriptRunner_obj), false, "polymod.hscript.ScriptRunner"));
	*(void **)__this = ScriptRunner_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

ScriptRunner_obj::ScriptRunner_obj()
{
}

::hx::Val ScriptRunner_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"get") ) { return ::hx::Val( get_dyn() ); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"load") ) { return ::hx::Val( load_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"execute") ) { return ::hx::Val( execute_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

bool ScriptRunner_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"scripts") ) { outValue = ( scripts ); return true; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"scriptPath") ) { outValue = scriptPath_dyn(); return true; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"clearScripts") ) { outValue = clearScripts_dyn(); return true; }
	}
	return false;
}

bool ScriptRunner_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"scripts") ) { scripts=ioValue.Cast<  ::haxe::ds::StringMap >(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *ScriptRunner_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo ScriptRunner_obj_sStaticStorageInfo[] = {
	{::hx::fsObject /*  ::haxe::ds::StringMap */ ,(void *) &ScriptRunner_obj::scripts,HX_("scripts",08,fc,e3,2c)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static ::String ScriptRunner_obj_sMemberFields[] = {
	HX_("load",26,9a,b7,47),
	HX_("get",96,80,4e,00),
	HX_("execute",35,0a,0d,cc),
	::String(null()) };

static void ScriptRunner_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ScriptRunner_obj::scripts,"scripts");
};

#ifdef HXCPP_VISIT_ALLOCS
static void ScriptRunner_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ScriptRunner_obj::scripts,"scripts");
};

#endif

::hx::Class ScriptRunner_obj::__mClass;

static ::String ScriptRunner_obj_sStaticFields[] = {
	HX_("scripts",08,fc,e3,2c),
	HX_("clearScripts",fb,ad,62,08),
	HX_("scriptPath",50,c1,32,43),
	::String(null())
};

void ScriptRunner_obj::__register()
{
	ScriptRunner_obj _hx_dummy;
	ScriptRunner_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("polymod.hscript.ScriptRunner",ce,da,0c,c9);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &ScriptRunner_obj::__GetStatic;
	__mClass->mSetStaticField = &ScriptRunner_obj::__SetStatic;
	__mClass->mMarkFunc = ScriptRunner_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(ScriptRunner_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(ScriptRunner_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< ScriptRunner_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = ScriptRunner_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = ScriptRunner_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = ScriptRunner_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void ScriptRunner_obj::__boot()
{
{
            	HX_GC_STACKFRAME(&_hx_pos_dc57aa8d22eb51e7_202_boot)
HXDLIN( 202)		scripts =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
            	}
}

} // end namespace polymod
} // end namespace hscript
