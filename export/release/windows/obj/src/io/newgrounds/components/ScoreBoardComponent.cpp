#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_IntMap
#include <haxe/ds/IntMap.h>
#endif
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
#ifndef INCLUDED_io_newgrounds_components_ScoreBoardComponent
#include <io/newgrounds/components/ScoreBoardComponent.h>
#endif
#ifndef INCLUDED_io_newgrounds_objects_Object
#include <io/newgrounds/objects/Object.h>
#endif
#ifndef INCLUDED_io_newgrounds_objects_ScoreBoard
#include <io/newgrounds/objects/ScoreBoard.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_da79cbc10962842a_17_new,"io.newgrounds.components.ScoreBoardComponent","new",0x13dd471d,"io.newgrounds.components.ScoreBoardComponent.new","io/newgrounds/components/ScoreBoardComponent.hx",17,0x1ae19214)
HX_LOCAL_STACK_FRAME(_hx_pos_da79cbc10962842a_25_getBoards,"io.newgrounds.components.ScoreBoardComponent","getBoards",0x4d9d76c0,"io.newgrounds.components.ScoreBoardComponent.getBoards","io/newgrounds/components/ScoreBoardComponent.hx",25,0x1ae19214)
HX_LOCAL_STACK_FRAME(_hx_pos_da79cbc10962842a_53_getScores,"io.newgrounds.components.ScoreBoardComponent","getScores",0x3a20a094,"io.newgrounds.components.ScoreBoardComponent.getScores","io/newgrounds/components/ScoreBoardComponent.hx",53,0x1ae19214)
HX_LOCAL_STACK_FRAME(_hx_pos_da79cbc10962842a_74_postScore,"io.newgrounds.components.ScoreBoardComponent","postScore",0xaa6d254f,"io.newgrounds.components.ScoreBoardComponent.postScore","io/newgrounds/components/ScoreBoardComponent.hx",74,0x1ae19214)
HX_LOCAL_STACK_FRAME(_hx_pos_da79cbc10962842a_90_createBoard,"io.newgrounds.components.ScoreBoardComponent","createBoard",0x2792b9c7,"io.newgrounds.components.ScoreBoardComponent.createBoard","io/newgrounds/components/ScoreBoardComponent.hx",90,0x1ae19214)
namespace io{
namespace newgrounds{
namespace components{

void ScoreBoardComponent_obj::__construct( ::io::newgrounds::NGLite core){
            	HX_STACKFRAME(&_hx_pos_da79cbc10962842a_17_new)
HXDLIN(  17)		super::__construct(core);
            	}

Dynamic ScoreBoardComponent_obj::__CreateEmpty() { return new ScoreBoardComponent_obj; }

void *ScoreBoardComponent_obj::_hx_vtable = 0;

Dynamic ScoreBoardComponent_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< ScoreBoardComponent_obj > _hx_result = new ScoreBoardComponent_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool ScoreBoardComponent_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x1718a611) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x1718a611;
	} else {
		return inClassId==(int)0x54ed1d99;
	}
}

 ::io::newgrounds::Call ScoreBoardComponent_obj::getBoards(){
            	HX_GC_STACKFRAME(&_hx_pos_da79cbc10962842a_25_getBoards)
HXDLIN(  25)		return  ::io::newgrounds::Call_obj::__alloc( HX_CTX ,this->_core,HX_("ScoreBoard.getBoards",69,7d,4f,47),null(),null());
            	}


HX_DEFINE_DYNAMIC_FUNC0(ScoreBoardComponent_obj,getBoards,return )

 ::io::newgrounds::Call ScoreBoardComponent_obj::getScores(int id,::hx::Null< int >  __o_limit,::hx::Null< int >  __o_skip,::String __o_period,::hx::Null< bool >  __o_social,::String tag, ::Dynamic user){
            		int limit = __o_limit.Default(10);
            		int skip = __o_skip.Default(0);
            		::String period = __o_period;
            		if (::hx::IsNull(__o_period)) period = HX_("D",44,00,00,00);
            		bool social = __o_social.Default(false);
            	HX_GC_STACKFRAME(&_hx_pos_da79cbc10962842a_53_getScores)
HXLINE(  55)		bool _hx_tmp;
HXDLIN(  55)		bool _hx_tmp1;
HXDLIN(  55)		if (::hx::IsNotNull( user )) {
HXLINE(  55)			_hx_tmp1 = !(::Std_obj::isOfType(user,( ( ::Dynamic)(::hx::ClassOf< ::String >()) )));
            		}
            		else {
HXLINE(  55)			_hx_tmp1 = false;
            		}
HXDLIN(  55)		if (_hx_tmp1) {
HXLINE(  55)			_hx_tmp = !(::Std_obj::isOfType(user,( ( ::Dynamic)(::hx::ClassOf< int >()) )));
            		}
            		else {
HXLINE(  55)			_hx_tmp = false;
            		}
HXDLIN(  55)		if (_hx_tmp) {
HXLINE(  56)			user =  ::Dynamic(user->__Field(HX_("id",db,5b,00,00),::hx::paccDynamic));
            		}
HXLINE(  58)		return  ::io::newgrounds::Call_obj::__alloc( HX_CTX ,this->_core,HX_("ScoreBoard.getScores",3d,a7,d2,33),null(),null())->addComponentParameter(HX_("id",db,5b,00,00),id,null())->addComponentParameter(HX_("limit",3b,1f,01,75),limit,10)->addComponentParameter(HX_("skip",7f,16,55,4c),skip,0)->addComponentParameter(HX_("period",01,61,1b,3b),period,HX_("D",44,00,00,00))->addComponentParameter(HX_("social",ad,03,45,26),social,false)->addComponentParameter(HX_("tag",5a,5a,58,00),tag,null())->addComponentParameter(HX_("user",4b,92,ad,4d),user,null());
            	}


HX_DEFINE_DYNAMIC_FUNC7(ScoreBoardComponent_obj,getScores,return )

 ::io::newgrounds::Call ScoreBoardComponent_obj::postScore(int id,int value,::String tag){
            	HX_GC_STACKFRAME(&_hx_pos_da79cbc10962842a_74_postScore)
HXDLIN(  74)		return  ::io::newgrounds::Call_obj::__alloc( HX_CTX ,this->_core,HX_("ScoreBoard.postScore",f8,2b,1f,a4),true,true)->addComponentParameter(HX_("id",db,5b,00,00),id,null())->addComponentParameter(HX_("value",71,7f,b8,31),value,null())->addComponentParameter(HX_("tag",5a,5a,58,00),tag,null());
            	}


HX_DEFINE_DYNAMIC_FUNC3(ScoreBoardComponent_obj,postScore,return )

 ::io::newgrounds::objects::ScoreBoard ScoreBoardComponent_obj::createBoard( ::Dynamic data){
            	HX_GC_STACKFRAME(&_hx_pos_da79cbc10962842a_90_createBoard)
HXLINE(  92)		 ::io::newgrounds::objects::ScoreBoard board =  ::io::newgrounds::objects::ScoreBoard_obj::__alloc( HX_CTX ,this->_core,data);
HXLINE(  93)		{
HXLINE(  93)			 ::io::newgrounds::NGLite _this = this->_core;
HXDLIN(  93)			 ::Dynamic any = (HX_("created ",38,75,f4,2b) + ::Std_obj::string(board));
HXDLIN(  93)			if (_this->verbose) {
HXLINE(  93)				_this->log(any,::hx::SourceInfo(HX_("io/newgrounds/components/ScoreBoardComponent.hx",14,92,e1,1a),93,HX_("io.newgrounds.components.ScoreBoardComponent",ab,74,52,f3),HX_("createBoard",0a,be,68,e0)));
            			}
            		}
HXLINE(  95)		this->allById->set(( (int)(board->_data->__Field(HX_("id",db,5b,00,00),::hx::paccDynamic)) ),board);
HXLINE(  97)		return board;
            	}


HX_DEFINE_DYNAMIC_FUNC1(ScoreBoardComponent_obj,createBoard,return )


::hx::ObjectPtr< ScoreBoardComponent_obj > ScoreBoardComponent_obj::__new( ::io::newgrounds::NGLite core) {
	::hx::ObjectPtr< ScoreBoardComponent_obj > __this = new ScoreBoardComponent_obj();
	__this->__construct(core);
	return __this;
}

::hx::ObjectPtr< ScoreBoardComponent_obj > ScoreBoardComponent_obj::__alloc(::hx::Ctx *_hx_ctx, ::io::newgrounds::NGLite core) {
	ScoreBoardComponent_obj *__this = (ScoreBoardComponent_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(ScoreBoardComponent_obj), true, "io.newgrounds.components.ScoreBoardComponent"));
	*(void **)__this = ScoreBoardComponent_obj::_hx_vtable;
	__this->__construct(core);
	return __this;
}

ScoreBoardComponent_obj::ScoreBoardComponent_obj()
{
}

void ScoreBoardComponent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ScoreBoardComponent);
	HX_MARK_MEMBER_NAME(allById,"allById");
	 ::io::newgrounds::components::Component_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void ScoreBoardComponent_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(allById,"allById");
	 ::io::newgrounds::components::Component_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val ScoreBoardComponent_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"allById") ) { return ::hx::Val( allById ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"getBoards") ) { return ::hx::Val( getBoards_dyn() ); }
		if (HX_FIELD_EQ(inName,"getScores") ) { return ::hx::Val( getScores_dyn() ); }
		if (HX_FIELD_EQ(inName,"postScore") ) { return ::hx::Val( postScore_dyn() ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"createBoard") ) { return ::hx::Val( createBoard_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val ScoreBoardComponent_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"allById") ) { allById=inValue.Cast<  ::haxe::ds::IntMap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ScoreBoardComponent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("allById",53,c3,6f,4b));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo ScoreBoardComponent_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::haxe::ds::IntMap */ ,(int)offsetof(ScoreBoardComponent_obj,allById),HX_("allById",53,c3,6f,4b)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *ScoreBoardComponent_obj_sStaticStorageInfo = 0;
#endif

static ::String ScoreBoardComponent_obj_sMemberFields[] = {
	HX_("allById",53,c3,6f,4b),
	HX_("getBoards",43,d4,3e,d5),
	HX_("getScores",17,fe,c1,c1),
	HX_("postScore",d2,82,0e,32),
	HX_("createBoard",0a,be,68,e0),
	::String(null()) };

::hx::Class ScoreBoardComponent_obj::__mClass;

void ScoreBoardComponent_obj::__register()
{
	ScoreBoardComponent_obj _hx_dummy;
	ScoreBoardComponent_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("io.newgrounds.components.ScoreBoardComponent",ab,74,52,f3);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(ScoreBoardComponent_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< ScoreBoardComponent_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = ScoreBoardComponent_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = ScoreBoardComponent_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace io
} // end namespace newgrounds
} // end namespace components
