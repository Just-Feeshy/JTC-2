#include <hxcpp.h>

#ifndef INCLUDED_io_newgrounds_utils_Dispatcher
#include <io/newgrounds/utils/Dispatcher.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_50ed06ee64fb384d_11_new,"io.newgrounds.utils.Dispatcher","new",0x0b5c5750,"io.newgrounds.utils.Dispatcher.new","io/newgrounds/utils/Dispatcher.hx",11,0xfeb6ebdf)
HX_LOCAL_STACK_FRAME(_hx_pos_50ed06ee64fb384d_17_add,"io.newgrounds.utils.Dispatcher","add",0x0b527911,"io.newgrounds.utils.Dispatcher.add","io/newgrounds/utils/Dispatcher.hx",17,0xfeb6ebdf)
HX_LOCAL_STACK_FRAME(_hx_pos_50ed06ee64fb384d_37_addOnce,"io.newgrounds.utils.Dispatcher","addOnce",0x96de7f32,"io.newgrounds.utils.Dispatcher.addOnce","io/newgrounds/utils/Dispatcher.hx",37,0xfeb6ebdf)
HX_LOCAL_STACK_FRAME(_hx_pos_50ed06ee64fb384d_40_remove,"io.newgrounds.utils.Dispatcher","remove",0xbfbb0b54,"io.newgrounds.utils.Dispatcher.remove","io/newgrounds/utils/Dispatcher.hx",40,0xfeb6ebdf)
HX_LOCAL_STACK_FRAME(_hx_pos_50ed06ee64fb384d_46_dispatch,"io.newgrounds.utils.Dispatcher","dispatch",0xde5c21ca,"io.newgrounds.utils.Dispatcher.dispatch","io/newgrounds/utils/Dispatcher.hx",46,0xfeb6ebdf)
namespace io{
namespace newgrounds{
namespace utils{

void Dispatcher_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_50ed06ee64fb384d_11_new)
HXLINE(  13)		this->_list = ::Array_obj< ::Dynamic>::__new();
HXLINE(  14)		this->_once = ::Array_obj< ::Dynamic>::__new();
            	}

Dynamic Dispatcher_obj::__CreateEmpty() { return new Dispatcher_obj; }

void *Dispatcher_obj::_hx_vtable = 0;

Dynamic Dispatcher_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Dispatcher_obj > _hx_result = new Dispatcher_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool Dispatcher_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x26e8d6a6;
}

bool Dispatcher_obj::add( ::Dynamic handler,::hx::Null< bool >  __o_once){
            		bool once = __o_once.Default(false);
            	HX_STACKFRAME(&_hx_pos_50ed06ee64fb384d_17_add)
HXLINE(  19)		if ((this->_list->indexOf(handler,null()) != -1)) {
HXLINE(  22)			bool _hx_tmp;
HXDLIN(  22)			if (!(once)) {
HXLINE(  22)				_hx_tmp = (this->_once->indexOf(handler,null()) != -1);
            			}
            			else {
HXLINE(  22)				_hx_tmp = false;
            			}
HXDLIN(  22)			if (_hx_tmp) {
HXLINE(  23)				this->_once->remove(handler);
            			}
HXLINE(  25)			return false;
            		}
HXLINE(  28)		this->_list->unshift(handler);
HXLINE(  29)		if (once) {
HXLINE(  30)			this->_once->unshift(handler);
            		}
HXLINE(  32)		return true;
            	}


HX_DEFINE_DYNAMIC_FUNC2(Dispatcher_obj,add,return )

bool Dispatcher_obj::addOnce( ::Dynamic handler){
            	HX_STACKFRAME(&_hx_pos_50ed06ee64fb384d_37_addOnce)
HXDLIN(  37)		return this->add(handler,true);
            	}


HX_DEFINE_DYNAMIC_FUNC1(Dispatcher_obj,addOnce,return )

bool Dispatcher_obj::remove( ::Dynamic handler){
            	HX_STACKFRAME(&_hx_pos_50ed06ee64fb384d_40_remove)
HXLINE(  42)		this->_once->remove(handler);
HXLINE(  43)		return this->_list->remove(handler);
            	}


HX_DEFINE_DYNAMIC_FUNC1(Dispatcher_obj,remove,return )

void Dispatcher_obj::dispatch(){
            	HX_STACKFRAME(&_hx_pos_50ed06ee64fb384d_46_dispatch)
HXLINE(  48)		int i = (this->_list->length - 1);
HXLINE(  49)		while((i >= 0)){
HXLINE(  51)			 ::Dynamic handler = this->_list->__get(i);
HXLINE(  53)			if (this->_once->remove(handler)) {
HXLINE(  54)				this->_list->remove(handler);
            			}
HXLINE(  56)			handler();
HXLINE(  58)			i = (i - 1);
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC0(Dispatcher_obj,dispatch,(void))


Dispatcher_obj::Dispatcher_obj()
{
}

void Dispatcher_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Dispatcher);
	HX_MARK_MEMBER_NAME(_list,"_list");
	HX_MARK_MEMBER_NAME(_once,"_once");
	HX_MARK_END_CLASS();
}

void Dispatcher_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_list,"_list");
	HX_VISIT_MEMBER_NAME(_once,"_once");
}

::hx::Val Dispatcher_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"add") ) { return ::hx::Val( add_dyn() ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_list") ) { return ::hx::Val( _list ); }
		if (HX_FIELD_EQ(inName,"_once") ) { return ::hx::Val( _once ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"remove") ) { return ::hx::Val( remove_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"addOnce") ) { return ::hx::Val( addOnce_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"dispatch") ) { return ::hx::Val( dispatch_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val Dispatcher_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_list") ) { _list=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_once") ) { _once=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Dispatcher_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("_list",3d,38,c4,fa));
	outFields->push(HX_("_once",60,99,c3,fc));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Dispatcher_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(Dispatcher_obj,_list),HX_("_list",3d,38,c4,fa)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(Dispatcher_obj,_once),HX_("_once",60,99,c3,fc)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *Dispatcher_obj_sStaticStorageInfo = 0;
#endif

static ::String Dispatcher_obj_sMemberFields[] = {
	HX_("_list",3d,38,c4,fa),
	HX_("_once",60,99,c3,fc),
	HX_("add",21,f2,49,00),
	HX_("addOnce",42,c0,ef,85),
	HX_("remove",44,9c,88,04),
	HX_("dispatch",ba,ce,63,1e),
	::String(null()) };

::hx::Class Dispatcher_obj::__mClass;

void Dispatcher_obj::__register()
{
	Dispatcher_obj _hx_dummy;
	Dispatcher_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("io.newgrounds.utils.Dispatcher",5e,af,72,8c);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Dispatcher_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Dispatcher_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Dispatcher_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Dispatcher_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace io
} // end namespace newgrounds
} // end namespace utils
