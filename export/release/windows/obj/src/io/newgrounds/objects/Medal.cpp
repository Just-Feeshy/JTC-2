#include <hxcpp.h>

#ifndef INCLUDED_haxe_Exception
#include <haxe/Exception.h>
#endif
#ifndef INCLUDED_io_newgrounds_Call
#include <io/newgrounds/Call.h>
#endif
#ifndef INCLUDED_io_newgrounds_ICallable
#include <io/newgrounds/ICallable.h>
#endif
#ifndef INCLUDED_io_newgrounds_NG
#include <io/newgrounds/NG.h>
#endif
#ifndef INCLUDED_io_newgrounds_NGLite
#include <io/newgrounds/NGLite.h>
#endif
#ifndef INCLUDED_io_newgrounds_components_Component
#include <io/newgrounds/components/Component.h>
#endif
#ifndef INCLUDED_io_newgrounds_components_ComponentList
#include <io/newgrounds/components/ComponentList.h>
#endif
#ifndef INCLUDED_io_newgrounds_components_MedalComponent
#include <io/newgrounds/components/MedalComponent.h>
#endif
#ifndef INCLUDED_io_newgrounds_objects_Medal
#include <io/newgrounds/objects/Medal.h>
#endif
#ifndef INCLUDED_io_newgrounds_objects_Object
#include <io/newgrounds/objects/Object.h>
#endif
#ifndef INCLUDED_io_newgrounds_utils_Dispatcher
#include <io/newgrounds/utils/Dispatcher.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_86dc0cd60a499658_42_new,"io.newgrounds.objects.Medal","new",0xa44b2a75,"io.newgrounds.objects.Medal.new","io/newgrounds/objects/Medal.hx",42,0x7fbeb13c)
HX_LOCAL_STACK_FRAME(_hx_pos_86dc0cd60a499658_29_get_id,"io.newgrounds.objects.Medal","get_id",0x1eae542f,"io.newgrounds.objects.Medal.get_id","io/newgrounds/objects/Medal.hx",29,0x7fbeb13c)
HX_LOCAL_STACK_FRAME(_hx_pos_86dc0cd60a499658_30_get_name,"io.newgrounds.objects.Medal","get_name",0xe95b279f,"io.newgrounds.objects.Medal.get_name","io/newgrounds/objects/Medal.hx",30,0x7fbeb13c)
HX_LOCAL_STACK_FRAME(_hx_pos_86dc0cd60a499658_31_get_description,"io.newgrounds.objects.Medal","get_description",0xbf5f6628,"io.newgrounds.objects.Medal.get_description","io/newgrounds/objects/Medal.hx",31,0x7fbeb13c)
HX_LOCAL_STACK_FRAME(_hx_pos_86dc0cd60a499658_32_get_icon,"io.newgrounds.objects.Medal","get_icon",0xe60e9ccd,"io.newgrounds.objects.Medal.get_icon","io/newgrounds/objects/Medal.hx",32,0x7fbeb13c)
HX_LOCAL_STACK_FRAME(_hx_pos_86dc0cd60a499658_33_get_value,"io.newgrounds.objects.Medal","get_value",0xe19b739d,"io.newgrounds.objects.Medal.get_value","io/newgrounds/objects/Medal.hx",33,0x7fbeb13c)
HX_LOCAL_STACK_FRAME(_hx_pos_86dc0cd60a499658_34_get_difficulty,"io.newgrounds.objects.Medal","get_difficulty",0x702aba8f,"io.newgrounds.objects.Medal.get_difficulty","io/newgrounds/objects/Medal.hx",34,0x7fbeb13c)
HX_LOCAL_STACK_FRAME(_hx_pos_86dc0cd60a499658_35_get_secret,"io.newgrounds.objects.Medal","get_secret",0x9afcc0c4,"io.newgrounds.objects.Medal.get_secret","io/newgrounds/objects/Medal.hx",35,0x7fbeb13c)
HX_LOCAL_STACK_FRAME(_hx_pos_86dc0cd60a499658_36_get_unlocked,"io.newgrounds.objects.Medal","get_unlocked",0xaa912377,"io.newgrounds.objects.Medal.get_unlocked","io/newgrounds/objects/Medal.hx",36,0x7fbeb13c)
HX_LOCAL_STACK_FRAME(_hx_pos_86dc0cd60a499658_50_parse,"io.newgrounds.objects.Medal","parse",0xd1675988,"io.newgrounds.objects.Medal.parse","io/newgrounds/objects/Medal.hx",50,0x7fbeb13c)
HX_LOCAL_STACK_FRAME(_hx_pos_86dc0cd60a499658_60_sendUnlock,"io.newgrounds.objects.Medal","sendUnlock",0x4d0e0cb7,"io.newgrounds.objects.Medal.sendUnlock","io/newgrounds/objects/Medal.hx",60,0x7fbeb13c)
HX_LOCAL_STACK_FRAME(_hx_pos_86dc0cd60a499658_76_onUnlockResponse,"io.newgrounds.objects.Medal","onUnlockResponse",0x7417bbaf,"io.newgrounds.objects.Medal.onUnlockResponse","io/newgrounds/objects/Medal.hx",76,0x7fbeb13c)
HX_LOCAL_STACK_FRAME(_hx_pos_86dc0cd60a499658_92_sendDebugUnlock,"io.newgrounds.objects.Medal","sendDebugUnlock",0x547a0ea4,"io.newgrounds.objects.Medal.sendDebugUnlock","io/newgrounds/objects/Medal.hx",92,0x7fbeb13c)
HX_LOCAL_STACK_FRAME(_hx_pos_86dc0cd60a499658_106_get_difficultyName,"io.newgrounds.objects.Medal","get_difficultyName",0xdf354c7a,"io.newgrounds.objects.Medal.get_difficultyName","io/newgrounds/objects/Medal.hx",106,0x7fbeb13c)
HX_LOCAL_STACK_FRAME(_hx_pos_86dc0cd60a499658_120_toString,"io.newgrounds.objects.Medal","toString",0x590fca77,"io.newgrounds.objects.Medal.toString","io/newgrounds/objects/Medal.hx",120,0x7fbeb13c)
HX_LOCAL_STACK_FRAME(_hx_pos_86dc0cd60a499658_22_boot,"io.newgrounds.objects.Medal","boot",0x1592fc7d,"io.newgrounds.objects.Medal.boot","io/newgrounds/objects/Medal.hx",22,0x7fbeb13c)
HX_LOCAL_STACK_FRAME(_hx_pos_86dc0cd60a499658_23_boot,"io.newgrounds.objects.Medal","boot",0x1592fc7d,"io.newgrounds.objects.Medal.boot","io/newgrounds/objects/Medal.hx",23,0x7fbeb13c)
HX_LOCAL_STACK_FRAME(_hx_pos_86dc0cd60a499658_24_boot,"io.newgrounds.objects.Medal","boot",0x1592fc7d,"io.newgrounds.objects.Medal.boot","io/newgrounds/objects/Medal.hx",24,0x7fbeb13c)
HX_LOCAL_STACK_FRAME(_hx_pos_86dc0cd60a499658_25_boot,"io.newgrounds.objects.Medal","boot",0x1592fc7d,"io.newgrounds.objects.Medal.boot","io/newgrounds/objects/Medal.hx",25,0x7fbeb13c)
HX_LOCAL_STACK_FRAME(_hx_pos_86dc0cd60a499658_26_boot,"io.newgrounds.objects.Medal","boot",0x1592fc7d,"io.newgrounds.objects.Medal.boot","io/newgrounds/objects/Medal.hx",26,0x7fbeb13c)
namespace io{
namespace newgrounds{
namespace objects{

void Medal_obj::__construct( ::io::newgrounds::NGLite core, ::Dynamic data){
            	HX_GC_STACKFRAME(&_hx_pos_86dc0cd60a499658_42_new)
HXLINE(  44)		this->onUnlock =  ::io::newgrounds::utils::Dispatcher_obj::__alloc( HX_CTX );
HXLINE(  46)		super::__construct(core,data);
            	}

Dynamic Medal_obj::__CreateEmpty() { return new Medal_obj; }

void *Medal_obj::_hx_vtable = 0;

Dynamic Medal_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Medal_obj > _hx_result = new Medal_obj();
	_hx_result->__construct(inArgs[0],inArgs[1]);
	return _hx_result;
}

bool Medal_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x596f3161) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x596f3161;
	} else {
		return inClassId==(int)0x7564f595;
	}
}

int Medal_obj::get_id(){
            	HX_STACKFRAME(&_hx_pos_86dc0cd60a499658_29_get_id)
HXDLIN(  29)		return ( (int)(this->_data->__Field(HX_("id",db,5b,00,00),::hx::paccDynamic)) );
            	}


HX_DEFINE_DYNAMIC_FUNC0(Medal_obj,get_id,return )

::String Medal_obj::get_name(){
            	HX_STACKFRAME(&_hx_pos_86dc0cd60a499658_30_get_name)
HXDLIN(  30)		return ( (::String)(this->_data->__Field(HX_("name",4b,72,ff,48),::hx::paccDynamic)) );
            	}


HX_DEFINE_DYNAMIC_FUNC0(Medal_obj,get_name,return )

::String Medal_obj::get_description(){
            	HX_STACKFRAME(&_hx_pos_86dc0cd60a499658_31_get_description)
HXDLIN(  31)		return ( (::String)(this->_data->__Field(HX_("description",fc,08,1d,5f),::hx::paccDynamic)) );
            	}


HX_DEFINE_DYNAMIC_FUNC0(Medal_obj,get_description,return )

::String Medal_obj::get_icon(){
            	HX_STACKFRAME(&_hx_pos_86dc0cd60a499658_32_get_icon)
HXDLIN(  32)		return ( (::String)(this->_data->__Field(HX_("icon",79,e7,b2,45),::hx::paccDynamic)) );
            	}


HX_DEFINE_DYNAMIC_FUNC0(Medal_obj,get_icon,return )

int Medal_obj::get_value(){
            	HX_STACKFRAME(&_hx_pos_86dc0cd60a499658_33_get_value)
HXDLIN(  33)		return ( (int)(this->_data->__Field(HX_("value",71,7f,b8,31),::hx::paccDynamic)) );
            	}


HX_DEFINE_DYNAMIC_FUNC0(Medal_obj,get_value,return )

int Medal_obj::get_difficulty(){
            	HX_STACKFRAME(&_hx_pos_86dc0cd60a499658_34_get_difficulty)
HXDLIN(  34)		return ( (int)(this->_data->__Field(HX_("difficulty",3b,4e,8e,47),::hx::paccDynamic)) );
            	}


HX_DEFINE_DYNAMIC_FUNC0(Medal_obj,get_difficulty,return )

bool Medal_obj::get_secret(){
            	HX_STACKFRAME(&_hx_pos_86dc0cd60a499658_35_get_secret)
HXDLIN(  35)		return ::hx::IsEq( this->_data->__Field(HX_("secret",70,0e,4a,64),::hx::paccDynamic),1 );
            	}


HX_DEFINE_DYNAMIC_FUNC0(Medal_obj,get_secret,return )

bool Medal_obj::get_unlocked(){
            	HX_STACKFRAME(&_hx_pos_86dc0cd60a499658_36_get_unlocked)
HXDLIN(  36)		return ( (bool)(this->_data->__Field(HX_("unlocked",23,34,0e,5c),::hx::paccDynamic)) );
            	}


HX_DEFINE_DYNAMIC_FUNC0(Medal_obj,get_unlocked,return )

void Medal_obj::parse( ::Dynamic _tmp_data){
            	HX_STACKFRAME(&_hx_pos_86dc0cd60a499658_50_parse)
HXLINE(  52)		 ::Dynamic data = _tmp_data;
HXDLIN(  52)		bool wasLocked;
HXDLIN(  52)		if (::hx::IsNotNull( this->_data )) {
HXLINE(  52)			wasLocked = !(( (bool)(this->_data->__Field(HX_("unlocked",23,34,0e,5c),::hx::paccDynamic)) ));
            		}
            		else {
HXLINE(  52)			wasLocked = true;
            		}
HXLINE(  54)		this->super::parse(data);
HXLINE(  56)		bool _hx_tmp;
HXDLIN(  56)		if (wasLocked) {
HXLINE(  56)			_hx_tmp = ( (bool)(this->_data->__Field(HX_("unlocked",23,34,0e,5c),::hx::paccDynamic)) );
            		}
            		else {
HXLINE(  56)			_hx_tmp = false;
            		}
HXDLIN(  56)		if (_hx_tmp) {
HXLINE(  57)			this->onUnlock->dispatch();
            		}
            	}


void Medal_obj::sendUnlock(){
            	HX_STACKFRAME(&_hx_pos_86dc0cd60a499658_60_sendUnlock)
HXLINE(  62)		if (::hx::IsNull( this->_core->sessionId )) {
HXLINE(  64)			this->_data->__SetField(HX_("unlocked",23,34,0e,5c),true,::hx::paccDynamic);
HXLINE(  65)			this->onUnlock->dispatch();
            		}
HXLINE(  69)		this->_core->calls->medal->unlock(( (int)(this->_data->__Field(HX_("id",db,5b,00,00),::hx::paccDynamic)) ))->addDataHandler(this->onUnlockResponse_dyn())->send();
            	}


HX_DEFINE_DYNAMIC_FUNC0(Medal_obj,sendUnlock,(void))

void Medal_obj::onUnlockResponse( ::Dynamic response){
            	HX_STACKFRAME(&_hx_pos_86dc0cd60a499658_76_onUnlockResponse)
HXDLIN(  76)		bool _hx_tmp;
HXDLIN(  76)		if (( (bool)(response->__Field(HX_("success",c3,25,4e,b8),::hx::paccDynamic)) )) {
HXDLIN(  76)			_hx_tmp = ( (bool)( ::Dynamic( ::Dynamic(response->__Field(HX_("result",dd,68,84,08),::hx::paccDynamic))->__Field(HX_("data",2a,56,63,42),::hx::paccDynamic))->__Field(HX_("success",c3,25,4e,b8),::hx::paccDynamic)) );
            		}
            		else {
HXDLIN(  76)			_hx_tmp = false;
            		}
HXDLIN(  76)		if (_hx_tmp) {
HXLINE(  78)			this->parse( ::Dynamic( ::Dynamic( ::Dynamic(response->__Field(HX_("result",dd,68,84,08),::hx::paccDynamic))->__Field(HX_("data",2a,56,63,42),::hx::paccDynamic))->__Field(HX_("medal",f7,fd,bb,05),::hx::paccDynamic)));
HXLINE(  81)			if (!(( (bool)(this->_data->__Field(HX_("unlocked",23,34,0e,5c),::hx::paccDynamic)) ))) {
HXLINE(  83)				this->_data->__SetField(HX_("unlocked",23,34,0e,5c),true,::hx::paccDynamic);
HXLINE(  84)				this->onUnlock->dispatch();
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(Medal_obj,onUnlockResponse,(void))

void Medal_obj::sendDebugUnlock(){
            	HX_STACKFRAME(&_hx_pos_86dc0cd60a499658_92_sendDebugUnlock)
HXDLIN(  92)		if (::hx::IsNull( ::io::newgrounds::NG_obj::core->sessionId )) {
HXLINE(  94)			this->onUnlock->dispatch();
            		}
            		else {
HXLINE(  98)			this->_data->__SetField(HX_("unlocked",23,34,0e,5c),false,::hx::paccDynamic);
HXLINE( 100)			this->sendUnlock();
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC0(Medal_obj,sendDebugUnlock,(void))

::String Medal_obj::get_difficultyName(){
            	HX_STACKFRAME(&_hx_pos_86dc0cd60a499658_106_get_difficultyName)
HXDLIN( 106)		switch((int)(( (int)(this->_data->__Field(HX_("difficulty",3b,4e,8e,47),::hx::paccDynamic)) ))){
            			case (int)1: {
HXLINE( 108)				return HX_("Easy",22,b8,e5,2d);
            			}
            			break;
            			case (int)2: {
HXLINE( 109)				return HX_("Moderate",e3,cf,c7,aa);
            			}
            			break;
            			case (int)3: {
HXLINE( 110)				return HX_("Challenging",40,14,ca,6e);
            			}
            			break;
            			case (int)4: {
HXLINE( 111)				return HX_("Difficult",5e,00,a1,8e);
            			}
            			break;
            			case (int)5: {
HXLINE( 112)				return HX_("Brutal",fa,42,ea,54);
            			}
            			break;
            			default:{
HXLINE( 114)				HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("invalid difficulty: ",6a,cc,0d,2d) + ( (int)(this->_data->__Field(HX_("difficulty",3b,4e,8e,47),::hx::paccDynamic)) ))));
            			}
            		}
HXLINE( 106)		return null();
            	}


HX_DEFINE_DYNAMIC_FUNC0(Medal_obj,get_difficultyName,return )

::String Medal_obj::toString(){
            	HX_STACKFRAME(&_hx_pos_86dc0cd60a499658_120_toString)
HXDLIN( 120)		::String _hx_tmp;
HXDLIN( 120)		if (( (bool)(this->_data->__Field(HX_("unlocked",23,34,0e,5c),::hx::paccDynamic)) )) {
HXDLIN( 120)			_hx_tmp = HX_("unlocked",23,34,0e,5c);
            		}
            		else {
HXDLIN( 120)			_hx_tmp = HX_("locked",0a,05,c7,59);
            		}
HXDLIN( 120)		::String _hx_tmp1 = ( (::String)(((((((((HX_("Medal: ",3d,04,82,b8) + this->_data->__Field(HX_("id",db,5b,00,00),::hx::paccDynamic)) + HX_("@",40,00,00,00)) + this->_data->__Field(HX_("name",4b,72,ff,48),::hx::paccDynamic)) + HX_(" (",08,1c,00,00)) + _hx_tmp) + HX_(", ",74,26,00,00)) + this->_data->__Field(HX_("value",71,7f,b8,31),::hx::paccDynamic)) + HX_(" pts, ",03,ae,50,95))) );
HXDLIN( 120)		::String _hx_tmp2;
HXDLIN( 120)		switch((int)(( (int)(this->_data->__Field(HX_("difficulty",3b,4e,8e,47),::hx::paccDynamic)) ))){
            			case (int)1: {
HXDLIN( 120)				_hx_tmp2 = HX_("Easy",22,b8,e5,2d);
            			}
            			break;
            			case (int)2: {
HXDLIN( 120)				_hx_tmp2 = HX_("Moderate",e3,cf,c7,aa);
            			}
            			break;
            			case (int)3: {
HXDLIN( 120)				_hx_tmp2 = HX_("Challenging",40,14,ca,6e);
            			}
            			break;
            			case (int)4: {
HXDLIN( 120)				_hx_tmp2 = HX_("Difficult",5e,00,a1,8e);
            			}
            			break;
            			case (int)5: {
HXDLIN( 120)				_hx_tmp2 = HX_("Brutal",fa,42,ea,54);
            			}
            			break;
            			default:{
HXDLIN( 120)				HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("invalid difficulty: ",6a,cc,0d,2d) + ( (int)(this->_data->__Field(HX_("difficulty",3b,4e,8e,47),::hx::paccDynamic)) ))));
            			}
            		}
HXDLIN( 120)		return ((_hx_tmp1 + _hx_tmp2) + HX_(").",e5,23,00,00));
            	}


HX_DEFINE_DYNAMIC_FUNC0(Medal_obj,toString,return )

int Medal_obj::EASY;

int Medal_obj::MODERATE;

int Medal_obj::CHALLENGING;

int Medal_obj::DIFFICULT;

int Medal_obj::BRUTAL;


::hx::ObjectPtr< Medal_obj > Medal_obj::__new( ::io::newgrounds::NGLite core, ::Dynamic data) {
	::hx::ObjectPtr< Medal_obj > __this = new Medal_obj();
	__this->__construct(core,data);
	return __this;
}

::hx::ObjectPtr< Medal_obj > Medal_obj::__alloc(::hx::Ctx *_hx_ctx, ::io::newgrounds::NGLite core, ::Dynamic data) {
	Medal_obj *__this = (Medal_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Medal_obj), true, "io.newgrounds.objects.Medal"));
	*(void **)__this = Medal_obj::_hx_vtable;
	__this->__construct(core,data);
	return __this;
}

Medal_obj::Medal_obj()
{
}

void Medal_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Medal);
	HX_MARK_MEMBER_NAME(onUnlock,"onUnlock");
	 ::io::newgrounds::objects::Object_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Medal_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(onUnlock,"onUnlock");
	 ::io::newgrounds::objects::Object_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val Medal_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_id() ); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_name() ); }
		if (HX_FIELD_EQ(inName,"icon") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_icon() ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_value() ); }
		if (HX_FIELD_EQ(inName,"parse") ) { return ::hx::Val( parse_dyn() ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"get_id") ) { return ::hx::Val( get_id_dyn() ); }
		if (HX_FIELD_EQ(inName,"secret") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_secret() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_name") ) { return ::hx::Val( get_name_dyn() ); }
		if (HX_FIELD_EQ(inName,"get_icon") ) { return ::hx::Val( get_icon_dyn() ); }
		if (HX_FIELD_EQ(inName,"unlocked") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_unlocked() ); }
		if (HX_FIELD_EQ(inName,"onUnlock") ) { return ::hx::Val( onUnlock ); }
		if (HX_FIELD_EQ(inName,"toString") ) { return ::hx::Val( toString_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_value") ) { return ::hx::Val( get_value_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"difficulty") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_difficulty() ); }
		if (HX_FIELD_EQ(inName,"get_secret") ) { return ::hx::Val( get_secret_dyn() ); }
		if (HX_FIELD_EQ(inName,"sendUnlock") ) { return ::hx::Val( sendUnlock_dyn() ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"description") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_description() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_unlocked") ) { return ::hx::Val( get_unlocked_dyn() ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_difficulty") ) { return ::hx::Val( get_difficulty_dyn() ); }
		if (HX_FIELD_EQ(inName,"difficultyName") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_difficultyName() ); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"get_description") ) { return ::hx::Val( get_description_dyn() ); }
		if (HX_FIELD_EQ(inName,"sendDebugUnlock") ) { return ::hx::Val( sendDebugUnlock_dyn() ); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"onUnlockResponse") ) { return ::hx::Val( onUnlockResponse_dyn() ); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"get_difficultyName") ) { return ::hx::Val( get_difficultyName_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val Medal_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"onUnlock") ) { onUnlock=inValue.Cast<  ::io::newgrounds::utils::Dispatcher >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Medal_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("id",db,5b,00,00));
	outFields->push(HX_("name",4b,72,ff,48));
	outFields->push(HX_("description",fc,08,1d,5f));
	outFields->push(HX_("icon",79,e7,b2,45));
	outFields->push(HX_("value",71,7f,b8,31));
	outFields->push(HX_("difficulty",3b,4e,8e,47));
	outFields->push(HX_("secret",70,0e,4a,64));
	outFields->push(HX_("unlocked",23,34,0e,5c));
	outFields->push(HX_("difficultyName",26,26,4a,94));
	outFields->push(HX_("onUnlock",43,99,39,45));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Medal_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::io::newgrounds::utils::Dispatcher */ ,(int)offsetof(Medal_obj,onUnlock),HX_("onUnlock",43,99,39,45)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo Medal_obj_sStaticStorageInfo[] = {
	{::hx::fsInt,(void *) &Medal_obj::EASY,HX_("EASY",02,54,cd,2d)},
	{::hx::fsInt,(void *) &Medal_obj::MODERATE,HX_("MODERATE",c3,a3,9b,2a)},
	{::hx::fsInt,(void *) &Medal_obj::CHALLENGING,HX_("CHALLENGING",40,88,d3,60)},
	{::hx::fsInt,(void *) &Medal_obj::DIFFICULT,HX_("DIFFICULT",5e,90,26,e8)},
	{::hx::fsInt,(void *) &Medal_obj::BRUTAL,HX_("BRUTAL",da,7a,d8,d2)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static ::String Medal_obj_sMemberFields[] = {
	HX_("get_id",24,f3,2f,a3),
	HX_("get_name",d4,2d,ba,c8),
	HX_("get_description",93,c0,fe,1f),
	HX_("get_icon",02,a3,6d,c5),
	HX_("get_value",c8,db,61,75),
	HX_("get_difficulty",84,d6,83,bd),
	HX_("get_secret",39,7e,d1,54),
	HX_("get_unlocked",2c,e8,27,11),
	HX_("onUnlock",43,99,39,45),
	HX_("parse",33,90,55,bd),
	HX_("sendUnlock",2c,ca,e2,06),
	HX_("onUnlockResponse",e4,7e,e7,9e),
	HX_("sendDebugUnlock",0f,69,19,b5),
	HX_("get_difficultyName",ef,06,e4,2f),
	HX_("toString",ac,d0,6e,38),
	::String(null()) };

static void Medal_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Medal_obj::EASY,"EASY");
	HX_MARK_MEMBER_NAME(Medal_obj::MODERATE,"MODERATE");
	HX_MARK_MEMBER_NAME(Medal_obj::CHALLENGING,"CHALLENGING");
	HX_MARK_MEMBER_NAME(Medal_obj::DIFFICULT,"DIFFICULT");
	HX_MARK_MEMBER_NAME(Medal_obj::BRUTAL,"BRUTAL");
};

#ifdef HXCPP_VISIT_ALLOCS
static void Medal_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Medal_obj::EASY,"EASY");
	HX_VISIT_MEMBER_NAME(Medal_obj::MODERATE,"MODERATE");
	HX_VISIT_MEMBER_NAME(Medal_obj::CHALLENGING,"CHALLENGING");
	HX_VISIT_MEMBER_NAME(Medal_obj::DIFFICULT,"DIFFICULT");
	HX_VISIT_MEMBER_NAME(Medal_obj::BRUTAL,"BRUTAL");
};

#endif

::hx::Class Medal_obj::__mClass;

static ::String Medal_obj_sStaticFields[] = {
	HX_("EASY",02,54,cd,2d),
	HX_("MODERATE",c3,a3,9b,2a),
	HX_("CHALLENGING",40,88,d3,60),
	HX_("DIFFICULT",5e,90,26,e8),
	HX_("BRUTAL",da,7a,d8,d2),
	::String(null())
};

void Medal_obj::__register()
{
	Medal_obj _hx_dummy;
	Medal_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("io.newgrounds.objects.Medal",03,cc,85,e6);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mMarkFunc = Medal_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(Medal_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Medal_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Medal_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = Medal_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Medal_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Medal_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void Medal_obj::__boot()
{
{
            	HX_STACKFRAME(&_hx_pos_86dc0cd60a499658_22_boot)
HXDLIN(  22)		EASY = 1;
            	}
{
            	HX_STACKFRAME(&_hx_pos_86dc0cd60a499658_23_boot)
HXDLIN(  23)		MODERATE = 2;
            	}
{
            	HX_STACKFRAME(&_hx_pos_86dc0cd60a499658_24_boot)
HXDLIN(  24)		CHALLENGING = 3;
            	}
{
            	HX_STACKFRAME(&_hx_pos_86dc0cd60a499658_25_boot)
HXDLIN(  25)		DIFFICULT = 4;
            	}
{
            	HX_STACKFRAME(&_hx_pos_86dc0cd60a499658_26_boot)
HXDLIN(  26)		BRUTAL = 5;
            	}
}

} // end namespace io
} // end namespace newgrounds
} // end namespace objects
