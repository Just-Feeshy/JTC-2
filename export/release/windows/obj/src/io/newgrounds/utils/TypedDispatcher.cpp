#include <hxcpp.h>

#ifndef INCLUDED_io_newgrounds_utils_TypedDispatcher
#include <io/newgrounds/utils/TypedDispatcher.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_930dd3809f5d6707_68_new,"io.newgrounds.utils.TypedDispatcher","new",0x6d9a1f8c,"io.newgrounds.utils.TypedDispatcher.new","io/newgrounds/utils/Dispatcher.hx",68,0xfeb6ebdf)
HX_LOCAL_STACK_FRAME(_hx_pos_930dd3809f5d6707_74_add,"io.newgrounds.utils.TypedDispatcher","add",0x6d90414d,"io.newgrounds.utils.TypedDispatcher.add","io/newgrounds/utils/Dispatcher.hx",74,0xfeb6ebdf)
HX_LOCAL_STACK_FRAME(_hx_pos_930dd3809f5d6707_94_addOnce,"io.newgrounds.utils.TypedDispatcher","addOnce",0x0bab156e,"io.newgrounds.utils.TypedDispatcher.addOnce","io/newgrounds/utils/Dispatcher.hx",94,0xfeb6ebdf)
HX_LOCAL_STACK_FRAME(_hx_pos_930dd3809f5d6707_97_remove,"io.newgrounds.utils.TypedDispatcher","remove",0xfbf31098,"io.newgrounds.utils.TypedDispatcher.remove","io/newgrounds/utils/Dispatcher.hx",97,0xfeb6ebdf)
HX_LOCAL_STACK_FRAME(_hx_pos_930dd3809f5d6707_103_dispatch,"io.newgrounds.utils.TypedDispatcher","dispatch",0x9c93000e,"io.newgrounds.utils.TypedDispatcher.dispatch","io/newgrounds/utils/Dispatcher.hx",103,0xfeb6ebdf)
namespace io{
namespace newgrounds{
namespace utils{

void TypedDispatcher_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_930dd3809f5d6707_68_new)
HXLINE(  70)		this->_list = ::Array_obj< ::Dynamic>::__new();
HXLINE(  71)		this->_once = ::Array_obj< ::Dynamic>::__new();
            	}

Dynamic TypedDispatcher_obj::__CreateEmpty() { return new TypedDispatcher_obj; }

void *TypedDispatcher_obj::_hx_vtable = 0;

Dynamic TypedDispatcher_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< TypedDispatcher_obj > _hx_result = new TypedDispatcher_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool TypedDispatcher_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x49af1d52;
}

bool TypedDispatcher_obj::add( ::Dynamic handler,::hx::Null< bool >  __o_once){
            		bool once = __o_once.Default(false);
            	HX_STACKFRAME(&_hx_pos_930dd3809f5d6707_74_add)
HXLINE(  76)		if ((this->_list->indexOf(handler,null()) != -1)) {
HXLINE(  79)			bool _hx_tmp;
HXDLIN(  79)			if (!(once)) {
HXLINE(  79)				_hx_tmp = (this->_once->indexOf(handler,null()) != -1);
            			}
            			else {
HXLINE(  79)				_hx_tmp = false;
            			}
HXDLIN(  79)			if (_hx_tmp) {
HXLINE(  80)				this->_once->remove(handler);
            			}
HXLINE(  82)			return false;
            		}
HXLINE(  85)		this->_list->unshift(handler);
HXLINE(  86)		if (once) {
HXLINE(  87)			this->_once->unshift(handler);
            		}
HXLINE(  89)		return true;
            	}


HX_DEFINE_DYNAMIC_FUNC2(TypedDispatcher_obj,add,return )

bool TypedDispatcher_obj::addOnce( ::Dynamic handler){
            	HX_STACKFRAME(&_hx_pos_930dd3809f5d6707_94_addOnce)
HXDLIN(  94)		return this->add(handler,true);
            	}


HX_DEFINE_DYNAMIC_FUNC1(TypedDispatcher_obj,addOnce,return )

bool TypedDispatcher_obj::remove( ::Dynamic handler){
            	HX_STACKFRAME(&_hx_pos_930dd3809f5d6707_97_remove)
HXLINE(  99)		this->_once->remove(handler);
HXLINE( 100)		return this->_list->remove(handler);
            	}


HX_DEFINE_DYNAMIC_FUNC1(TypedDispatcher_obj,remove,return )

void TypedDispatcher_obj::dispatch( ::Dynamic arg){
            	HX_STACKFRAME(&_hx_pos_930dd3809f5d6707_103_dispatch)
HXLINE( 105)		int i = (this->_list->length - 1);
HXLINE( 106)		while((i >= 0)){
HXLINE( 108)			 ::Dynamic handler = this->_list->__get(i);
HXLINE( 110)			if (this->_once->remove(handler)) {
HXLINE( 111)				this->_list->remove(handler);
            			}
HXLINE( 113)			handler(arg);
HXLINE( 115)			i = (i - 1);
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(TypedDispatcher_obj,dispatch,(void))


TypedDispatcher_obj::TypedDispatcher_obj()
{
}

void TypedDispatcher_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TypedDispatcher);
	HX_MARK_MEMBER_NAME(_list,"_list");
	HX_MARK_MEMBER_NAME(_once,"_once");
	HX_MARK_END_CLASS();
}

void TypedDispatcher_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_list,"_list");
	HX_VISIT_MEMBER_NAME(_once,"_once");
}

::hx::Val TypedDispatcher_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
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

::hx::Val TypedDispatcher_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_list") ) { _list=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_once") ) { _once=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TypedDispatcher_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("_list",3d,38,c4,fa));
	outFields->push(HX_("_once",60,99,c3,fc));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo TypedDispatcher_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(TypedDispatcher_obj,_list),HX_("_list",3d,38,c4,fa)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(TypedDispatcher_obj,_once),HX_("_once",60,99,c3,fc)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *TypedDispatcher_obj_sStaticStorageInfo = 0;
#endif

static ::String TypedDispatcher_obj_sMemberFields[] = {
	HX_("_list",3d,38,c4,fa),
	HX_("_once",60,99,c3,fc),
	HX_("add",21,f2,49,00),
	HX_("addOnce",42,c0,ef,85),
	HX_("remove",44,9c,88,04),
	HX_("dispatch",ba,ce,63,1e),
	::String(null()) };

::hx::Class TypedDispatcher_obj::__mClass;

void TypedDispatcher_obj::__register()
{
	TypedDispatcher_obj _hx_dummy;
	TypedDispatcher_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("io.newgrounds.utils.TypedDispatcher",9a,a9,20,db);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(TypedDispatcher_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< TypedDispatcher_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = TypedDispatcher_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = TypedDispatcher_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace io
} // end namespace newgrounds
} // end namespace utils
