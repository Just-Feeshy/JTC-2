#include <hxcpp.h>

#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_hscript_Expr
#include <hscript/Expr.h>
#endif
#ifndef INCLUDED_hscript_Interp
#include <hscript/Interp.h>
#endif
#ifndef INCLUDED_hscript_Parser
#include <hscript/Parser.h>
#endif
#ifndef INCLUDED_polymod_hscript_PolymodParserEx
#include <polymod/hscript/PolymodParserEx.h>
#endif
#ifndef INCLUDED_polymod_hscript_Script
#include <polymod/hscript/Script.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_32df8e2241283cfa_293_new,"polymod.hscript.Script","new",0xa2d47230,"polymod.hscript.Script.new","polymod/hscript/HScriptable.hx",293,0xab5038e6)
HX_LOCAL_STACK_FRAME(_hx_pos_32df8e2241283cfa_305_set,"polymod.hscript.Script","set",0xa2d83d72,"polymod.hscript.Script.set","polymod/hscript/HScriptable.hx",305,0xab5038e6)
HX_LOCAL_STACK_FRAME(_hx_pos_32df8e2241283cfa_309_execute,"polymod.hscript.Script","execute",0xf54ad405,"polymod.hscript.Script.execute","polymod/hscript/HScriptable.hx",309,0xab5038e6)
HX_LOCAL_STACK_FRAME(_hx_pos_32df8e2241283cfa_284_buildParser,"polymod.hscript.Script","buildParser",0x97a8747d,"polymod.hscript.Script.buildParser","polymod/hscript/HScriptable.hx",284,0xab5038e6)
HX_LOCAL_STACK_FRAME(_hx_pos_32df8e2241283cfa_289_buildInterp,"polymod.hscript.Script","buildInterp",0x48a65172,"polymod.hscript.Script.buildInterp","polymod/hscript/HScriptable.hx",289,0xab5038e6)
namespace polymod{
namespace hscript{

void Script_obj::__construct(::String script){
            	HX_STACKFRAME(&_hx_pos_32df8e2241283cfa_293_new)
HXLINE( 294)		if (::hx::IsNull( ::polymod::hscript::Script_obj::parser )) {
HXLINE( 296)			::polymod::hscript::Script_obj::parser = ::polymod::hscript::Script_obj::buildParser();
HXLINE( 297)			::polymod::hscript::Script_obj::parser->allowTypes = true;
            		}
HXLINE( 299)		this->program = ::polymod::hscript::Script_obj::parser->parseString(script,null());
HXLINE( 300)		this->interp = ::polymod::hscript::Script_obj::buildInterp();
            	}

Dynamic Script_obj::__CreateEmpty() { return new Script_obj; }

void *Script_obj::_hx_vtable = 0;

Dynamic Script_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Script_obj > _hx_result = new Script_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool Script_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x038a9d0c;
}

void Script_obj::set(::String key, ::Dynamic value){
            	HX_STACKFRAME(&_hx_pos_32df8e2241283cfa_305_set)
HXDLIN( 305)		this->interp->variables->set(key,value);
            	}


HX_DEFINE_DYNAMIC_FUNC2(Script_obj,set,(void))

 ::Dynamic Script_obj::execute(){
            	HX_STACKFRAME(&_hx_pos_32df8e2241283cfa_309_execute)
HXLINE( 310)		 ::Dynamic result = this->interp->execute(this->program);
HXLINE( 311)		return  ::Dynamic(::hx::Anon_obj::Create(2)
            			->setFixed(0,HX_("script_result",d1,d3,8b,af),result)
            			->setFixed(1,HX_("script_variables",43,c8,a1,6b),this->interp->variables));
            	}


HX_DEFINE_DYNAMIC_FUNC0(Script_obj,execute,return )

 ::hscript::Parser Script_obj::parser;

 ::hscript::Parser Script_obj::buildParser(){
            	HX_GC_STACKFRAME(&_hx_pos_32df8e2241283cfa_284_buildParser)
HXDLIN( 284)		return  ::polymod::hscript::PolymodParserEx_obj::__alloc( HX_CTX );
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Script_obj,buildParser,return )

 ::hscript::Interp Script_obj::buildInterp(){
            	HX_GC_STACKFRAME(&_hx_pos_32df8e2241283cfa_289_buildInterp)
HXDLIN( 289)		return  ::hscript::Interp_obj::__alloc( HX_CTX );
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Script_obj,buildInterp,return )


::hx::ObjectPtr< Script_obj > Script_obj::__new(::String script) {
	::hx::ObjectPtr< Script_obj > __this = new Script_obj();
	__this->__construct(script);
	return __this;
}

::hx::ObjectPtr< Script_obj > Script_obj::__alloc(::hx::Ctx *_hx_ctx,::String script) {
	Script_obj *__this = (Script_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Script_obj), true, "polymod.hscript.Script"));
	*(void **)__this = Script_obj::_hx_vtable;
	__this->__construct(script);
	return __this;
}

Script_obj::Script_obj()
{
}

void Script_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Script);
	HX_MARK_MEMBER_NAME(program,"program");
	HX_MARK_MEMBER_NAME(interp,"interp");
	HX_MARK_END_CLASS();
}

void Script_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(program,"program");
	HX_VISIT_MEMBER_NAME(interp,"interp");
}

::hx::Val Script_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return ::hx::Val( set_dyn() ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"interp") ) { return ::hx::Val( interp ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"program") ) { return ::hx::Val( program ); }
		if (HX_FIELD_EQ(inName,"execute") ) { return ::hx::Val( execute_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

bool Script_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"parser") ) { outValue = ( parser ); return true; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"buildParser") ) { outValue = buildParser_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"buildInterp") ) { outValue = buildInterp_dyn(); return true; }
	}
	return false;
}

::hx::Val Script_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"interp") ) { interp=inValue.Cast<  ::hscript::Interp >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"program") ) { program=inValue.Cast<  ::hscript::Expr >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool Script_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"parser") ) { parser=ioValue.Cast<  ::hscript::Parser >(); return true; }
	}
	return false;
}

void Script_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("program",84,4a,f9,f3));
	outFields->push(HX_("interp",d4,79,86,9e));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Script_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::hscript::Expr */ ,(int)offsetof(Script_obj,program),HX_("program",84,4a,f9,f3)},
	{::hx::fsObject /*  ::hscript::Interp */ ,(int)offsetof(Script_obj,interp),HX_("interp",d4,79,86,9e)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo Script_obj_sStaticStorageInfo[] = {
	{::hx::fsObject /*  ::hscript::Parser */ ,(void *) &Script_obj::parser,HX_("parser",df,9c,88,ed)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static ::String Script_obj_sMemberFields[] = {
	HX_("program",84,4a,f9,f3),
	HX_("interp",d4,79,86,9e),
	HX_("set",a2,9b,57,00),
	HX_("execute",35,0a,0d,cc),
	::String(null()) };

static void Script_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Script_obj::parser,"parser");
};

#ifdef HXCPP_VISIT_ALLOCS
static void Script_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Script_obj::parser,"parser");
};

#endif

::hx::Class Script_obj::__mClass;

static ::String Script_obj_sStaticFields[] = {
	HX_("parser",df,9c,88,ed),
	HX_("buildParser",ad,82,f9,3d),
	HX_("buildInterp",a2,5f,f7,ee),
	::String(null())
};

void Script_obj::__register()
{
	Script_obj _hx_dummy;
	Script_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("polymod.hscript.Script",3e,da,4b,75);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Script_obj::__GetStatic;
	__mClass->mSetStaticField = &Script_obj::__SetStatic;
	__mClass->mMarkFunc = Script_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(Script_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Script_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Script_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = Script_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Script_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Script_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace polymod
} // end namespace hscript
