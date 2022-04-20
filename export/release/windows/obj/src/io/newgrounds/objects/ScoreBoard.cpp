#include <hxcpp.h>

#ifndef INCLUDED_io_newgrounds_Call
#include <io/newgrounds/Call.h>
#endif
#ifndef INCLUDED_io_newgrounds_ICallable
#include <io/newgrounds/ICallable.h>
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
#ifndef INCLUDED_io_newgrounds_components_ScoreBoardComponent
#include <io/newgrounds/components/ScoreBoardComponent.h>
#endif
#ifndef INCLUDED_io_newgrounds_objects_Object
#include <io/newgrounds/objects/Object.h>
#endif
#ifndef INCLUDED_io_newgrounds_objects_ScoreBoard
#include <io/newgrounds/objects/ScoreBoard.h>
#endif
#ifndef INCLUDED_io_newgrounds_utils_Dispatcher
#include <io/newgrounds/utils/Dispatcher.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_7ac8815ad63e6f2e_28_new,"io.newgrounds.objects.ScoreBoard","new",0x95fff55a,"io.newgrounds.objects.ScoreBoard.new","io/newgrounds/objects/ScoreBoard.hx",28,0xcf70b515)
HX_LOCAL_STACK_FRAME(_hx_pos_7ac8815ad63e6f2e_22_get_id,"io.newgrounds.objects.ScoreBoard","get_id",0x51f1a66a,"io.newgrounds.objects.ScoreBoard.get_id","io/newgrounds/objects/ScoreBoard.hx",22,0xcf70b515)
HX_LOCAL_STACK_FRAME(_hx_pos_7ac8815ad63e6f2e_26_get_name,"io.newgrounds.objects.ScoreBoard","get_name",0xf1c3be9a,"io.newgrounds.objects.ScoreBoard.get_name","io/newgrounds/objects/ScoreBoard.hx",26,0xcf70b515)
HX_LOCAL_STACK_FRAME(_hx_pos_7ac8815ad63e6f2e_44_requestScores,"io.newgrounds.objects.ScoreBoard","requestScores",0x060b8f0a,"io.newgrounds.objects.ScoreBoard.requestScores","io/newgrounds/objects/ScoreBoard.hx",44,0xcf70b515)
HX_LOCAL_STACK_FRAME(_hx_pos_7ac8815ad63e6f2e_49_onScoresReceived,"io.newgrounds.objects.ScoreBoard","onScoresReceived",0x87029367,"io.newgrounds.objects.ScoreBoard.onScoresReceived","io/newgrounds/objects/ScoreBoard.hx",49,0xcf70b515)
HX_LOCAL_STACK_FRAME(_hx_pos_7ac8815ad63e6f2e_62_postScore,"io.newgrounds.objects.ScoreBoard","postScore",0xf1639f4c,"io.newgrounds.objects.ScoreBoard.postScore","io/newgrounds/objects/ScoreBoard.hx",62,0xcf70b515)
HX_LOCAL_STACK_FRAME(_hx_pos_7ac8815ad63e6f2e_67_onScorePosted,"io.newgrounds.objects.ScoreBoard","onScorePosted",0x3214e44c,"io.newgrounds.objects.ScoreBoard.onScorePosted","io/newgrounds/objects/ScoreBoard.hx",67,0xcf70b515)
HX_LOCAL_STACK_FRAME(_hx_pos_7ac8815ad63e6f2e_74_toString,"io.newgrounds.objects.ScoreBoard","toString",0x61786172,"io.newgrounds.objects.ScoreBoard.toString","io/newgrounds/objects/ScoreBoard.hx",74,0xcf70b515)
namespace io{
namespace newgrounds{
namespace objects{

void ScoreBoard_obj::__construct( ::io::newgrounds::NGLite core, ::Dynamic data){
            	HX_STACKFRAME(&_hx_pos_7ac8815ad63e6f2e_28_new)
HXDLIN(  28)		super::__construct(core,data);
            	}

Dynamic ScoreBoard_obj::__CreateEmpty() { return new ScoreBoard_obj; }

void *ScoreBoard_obj::_hx_vtable = 0;

Dynamic ScoreBoard_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< ScoreBoard_obj > _hx_result = new ScoreBoard_obj();
	_hx_result->__construct(inArgs[0],inArgs[1]);
	return _hx_result;
}

bool ScoreBoard_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x143ee596) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x143ee596;
	} else {
		return inClassId==(int)0x596f3161;
	}
}

int ScoreBoard_obj::get_id(){
            	HX_STACKFRAME(&_hx_pos_7ac8815ad63e6f2e_22_get_id)
HXDLIN(  22)		return ( (int)(this->_data->__Field(HX_("id",db,5b,00,00),::hx::paccDynamic)) );
            	}


HX_DEFINE_DYNAMIC_FUNC0(ScoreBoard_obj,get_id,return )

::String ScoreBoard_obj::get_name(){
            	HX_STACKFRAME(&_hx_pos_7ac8815ad63e6f2e_26_get_name)
HXDLIN(  26)		return ( (::String)(this->_data->__Field(HX_("name",4b,72,ff,48),::hx::paccDynamic)) );
            	}


HX_DEFINE_DYNAMIC_FUNC0(ScoreBoard_obj,get_name,return )

void ScoreBoard_obj::requestScores(::hx::Null< int >  __o_limit,::hx::Null< int >  __o_skip,::String __o_period,::hx::Null< bool >  __o_social,::String tag, ::Dynamic user){
            		int limit = __o_limit.Default(10);
            		int skip = __o_skip.Default(0);
            		::String period = __o_period;
            		if (::hx::IsNull(__o_period)) period = HX_("A",41,00,00,00);
            		bool social = __o_social.Default(false);
            	HX_STACKFRAME(&_hx_pos_7ac8815ad63e6f2e_44_requestScores)
HXDLIN(  44)		this->_core->calls->scoreBoard->getScores(( (int)(this->_data->__Field(HX_("id",db,5b,00,00),::hx::paccDynamic)) ),limit,skip,period,social,tag,user)->addDataHandler(this->onScoresReceived_dyn())->send();
            	}


HX_DEFINE_DYNAMIC_FUNC6(ScoreBoard_obj,requestScores,(void))

void ScoreBoard_obj::onScoresReceived( ::Dynamic response){
            	HX_STACKFRAME(&_hx_pos_7ac8815ad63e6f2e_49_onScoresReceived)
HXLINE(  51)		bool _hx_tmp;
HXDLIN(  51)		if (( (bool)(response->__Field(HX_("success",c3,25,4e,b8),::hx::paccDynamic)) )) {
HXLINE(  51)			_hx_tmp = !(( (bool)( ::Dynamic( ::Dynamic(response->__Field(HX_("result",dd,68,84,08),::hx::paccDynamic))->__Field(HX_("data",2a,56,63,42),::hx::paccDynamic))->__Field(HX_("success",c3,25,4e,b8),::hx::paccDynamic)) ));
            		}
            		else {
HXLINE(  51)			_hx_tmp = true;
            		}
HXDLIN(  51)		if (_hx_tmp) {
HXLINE(  52)			return;
            		}
HXLINE(  54)		this->scores = ( (::Array< ::Dynamic>)( ::Dynamic( ::Dynamic(response->__Field(HX_("result",dd,68,84,08),::hx::paccDynamic))->__Field(HX_("data",2a,56,63,42),::hx::paccDynamic))->__Field(HX_("scores",e1,74,6b,45),::hx::paccDynamic)) );
HXLINE(  55)		{
HXLINE(  55)			 ::io::newgrounds::NGLite _this = this->_core;
HXDLIN(  55)			if (_this->verbose) {
HXLINE(  55)				_this->log(((HX_("received ",df,37,9f,ba) + this->scores->length) + HX_(" scores",01,4d,1a,78)),::hx::SourceInfo(HX_("io/newgrounds/objects/ScoreBoard.hx",15,b5,70,cf),55,HX_("io.newgrounds.objects.ScoreBoard",68,00,98,e9),HX_("onScoresReceived",a1,cc,31,bb)));
            			}
            		}
HXLINE(  57)		this->onUpdate->dispatch();
            	}


HX_DEFINE_DYNAMIC_FUNC1(ScoreBoard_obj,onScoresReceived,(void))

void ScoreBoard_obj::postScore(int value,::String tag){
            	HX_STACKFRAME(&_hx_pos_7ac8815ad63e6f2e_62_postScore)
HXDLIN(  62)		this->_core->calls->scoreBoard->postScore(( (int)(this->_data->__Field(HX_("id",db,5b,00,00),::hx::paccDynamic)) ),value,tag)->addDataHandler(this->onScorePosted_dyn())->send();
            	}


HX_DEFINE_DYNAMIC_FUNC2(ScoreBoard_obj,postScore,(void))

void ScoreBoard_obj::onScorePosted( ::Dynamic response){
            	HX_STACKFRAME(&_hx_pos_7ac8815ad63e6f2e_67_onScorePosted)
            	}


HX_DEFINE_DYNAMIC_FUNC1(ScoreBoard_obj,onScorePosted,(void))

::String ScoreBoard_obj::toString(){
            	HX_STACKFRAME(&_hx_pos_7ac8815ad63e6f2e_74_toString)
HXDLIN(  74)		return ( (::String)((((HX_("ScoreBoard: ",ba,1d,70,47) + this->_data->__Field(HX_("id",db,5b,00,00),::hx::paccDynamic)) + HX_("@",40,00,00,00)) + this->_data->__Field(HX_("name",4b,72,ff,48),::hx::paccDynamic))) );
            	}


HX_DEFINE_DYNAMIC_FUNC0(ScoreBoard_obj,toString,return )


::hx::ObjectPtr< ScoreBoard_obj > ScoreBoard_obj::__new( ::io::newgrounds::NGLite core, ::Dynamic data) {
	::hx::ObjectPtr< ScoreBoard_obj > __this = new ScoreBoard_obj();
	__this->__construct(core,data);
	return __this;
}

::hx::ObjectPtr< ScoreBoard_obj > ScoreBoard_obj::__alloc(::hx::Ctx *_hx_ctx, ::io::newgrounds::NGLite core, ::Dynamic data) {
	ScoreBoard_obj *__this = (ScoreBoard_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(ScoreBoard_obj), true, "io.newgrounds.objects.ScoreBoard"));
	*(void **)__this = ScoreBoard_obj::_hx_vtable;
	__this->__construct(core,data);
	return __this;
}

ScoreBoard_obj::ScoreBoard_obj()
{
}

void ScoreBoard_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ScoreBoard);
	HX_MARK_MEMBER_NAME(scores,"scores");
	 ::io::newgrounds::objects::Object_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void ScoreBoard_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(scores,"scores");
	 ::io::newgrounds::objects::Object_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val ScoreBoard_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_id() ); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_name() ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"scores") ) { return ::hx::Val( scores ); }
		if (HX_FIELD_EQ(inName,"get_id") ) { return ::hx::Val( get_id_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_name") ) { return ::hx::Val( get_name_dyn() ); }
		if (HX_FIELD_EQ(inName,"toString") ) { return ::hx::Val( toString_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"postScore") ) { return ::hx::Val( postScore_dyn() ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"requestScores") ) { return ::hx::Val( requestScores_dyn() ); }
		if (HX_FIELD_EQ(inName,"onScorePosted") ) { return ::hx::Val( onScorePosted_dyn() ); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"onScoresReceived") ) { return ::hx::Val( onScoresReceived_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val ScoreBoard_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"scores") ) { scores=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ScoreBoard_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("scores",e1,74,6b,45));
	outFields->push(HX_("id",db,5b,00,00));
	outFields->push(HX_("name",4b,72,ff,48));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo ScoreBoard_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(ScoreBoard_obj,scores),HX_("scores",e1,74,6b,45)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *ScoreBoard_obj_sStaticStorageInfo = 0;
#endif

static ::String ScoreBoard_obj_sMemberFields[] = {
	HX_("scores",e1,74,6b,45),
	HX_("get_id",24,f3,2f,a3),
	HX_("get_name",d4,2d,ba,c8),
	HX_("requestScores",90,ad,15,01),
	HX_("onScoresReceived",a1,cc,31,bb),
	HX_("postScore",d2,82,0e,32),
	HX_("onScorePosted",d2,02,1f,2d),
	HX_("toString",ac,d0,6e,38),
	::String(null()) };

::hx::Class ScoreBoard_obj::__mClass;

void ScoreBoard_obj::__register()
{
	ScoreBoard_obj _hx_dummy;
	ScoreBoard_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("io.newgrounds.objects.ScoreBoard",68,00,98,e9);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(ScoreBoard_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< ScoreBoard_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = ScoreBoard_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = ScoreBoard_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace io
} // end namespace newgrounds
} // end namespace objects
