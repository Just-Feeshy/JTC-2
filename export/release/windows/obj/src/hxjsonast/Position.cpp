#include <hxcpp.h>

#ifndef INCLUDED_hxjsonast_Position
#include <hxjsonast/Position.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_2271147a67414103_26_new,"hxjsonast.Position","new",0x3884981f,"hxjsonast.Position.new","hxjsonast/Position.hx",26,0x5d8d7dd0)
namespace hxjsonast{

void Position_obj::__construct(::String file,int min,int max){
            	HX_STACKFRAME(&_hx_pos_2271147a67414103_26_new)
HXLINE(  27)		this->file = file;
HXLINE(  28)		this->min = min;
HXLINE(  29)		this->max = max;
            	}

Dynamic Position_obj::__CreateEmpty() { return new Position_obj; }

void *Position_obj::_hx_vtable = 0;

Dynamic Position_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Position_obj > _hx_result = new Position_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return _hx_result;
}

bool Position_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x6ee9f253;
}


Position_obj::Position_obj()
{
}

void Position_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Position);
	HX_MARK_MEMBER_NAME(file,"file");
	HX_MARK_MEMBER_NAME(min,"min");
	HX_MARK_MEMBER_NAME(max,"max");
	HX_MARK_END_CLASS();
}

void Position_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(file,"file");
	HX_VISIT_MEMBER_NAME(min,"min");
	HX_VISIT_MEMBER_NAME(max,"max");
}

::hx::Val Position_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"min") ) { return ::hx::Val( min ); }
		if (HX_FIELD_EQ(inName,"max") ) { return ::hx::Val( max ); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"file") ) { return ::hx::Val( file ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val Position_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"min") ) { min=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"max") ) { max=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"file") ) { file=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Position_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("file",7c,ce,bb,43));
	outFields->push(HX_("min",92,11,53,00));
	outFields->push(HX_("max",a4,0a,53,00));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Position_obj_sMemberStorageInfo[] = {
	{::hx::fsString,(int)offsetof(Position_obj,file),HX_("file",7c,ce,bb,43)},
	{::hx::fsInt,(int)offsetof(Position_obj,min),HX_("min",92,11,53,00)},
	{::hx::fsInt,(int)offsetof(Position_obj,max),HX_("max",a4,0a,53,00)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *Position_obj_sStaticStorageInfo = 0;
#endif

static ::String Position_obj_sMemberFields[] = {
	HX_("file",7c,ce,bb,43),
	HX_("min",92,11,53,00),
	HX_("max",a4,0a,53,00),
	::String(null()) };

::hx::Class Position_obj::__mClass;

void Position_obj::__register()
{
	Position_obj _hx_dummy;
	Position_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("hxjsonast.Position",ad,9c,f8,1e);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Position_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Position_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Position_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Position_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace hxjsonast
