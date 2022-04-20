#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_hxjsonast_Position
#include <hxjsonast/Position.h>
#endif
#ifndef INCLUDED_json2object_PositionUtils
#include <json2object/PositionUtils.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_5264ea8bcde66021_28_new,"json2object.PositionUtils","new",0xe4efcf35,"json2object.PositionUtils.new","json2object/PositionUtils.hx",28,0x0dbc9fdc)
HX_LOCAL_STACK_FRAME(_hx_pos_5264ea8bcde66021_65_convertPosition,"json2object.PositionUtils","convertPosition",0xe72b7011,"json2object.PositionUtils.convertPosition","json2object/PositionUtils.hx",65,0x0dbc9fdc)
HX_LOCAL_STACK_FRAME(_hx_pos_5264ea8bcde66021_114_revert,"json2object.PositionUtils","revert",0x29b5222f,"json2object.PositionUtils.revert","json2object/PositionUtils.hx",114,0x0dbc9fdc)
namespace json2object{

void PositionUtils_obj::__construct(::String content){
            	HX_STACKFRAME(&_hx_pos_5264ea8bcde66021_28_new)
HXLINE(  30)		this->linesInfo = ::Array_obj< ::Dynamic>::__new();
HXLINE(  33)		int s = 0;
HXLINE(  34)		int e = 0;
HXLINE(  36)		int i = 0;
HXLINE(  37)		int lineCount = 0;
HXLINE(  38)		while((i < content.length)){
HXLINE(  39)			::String _hx_switch_0 = content.charAt(i);
            			if (  (_hx_switch_0==HX_("\n",0a,00,00,00)) ){
HXLINE(  50)				e = i;
HXLINE(  51)				this->linesInfo->push( ::Dynamic(::hx::Anon_obj::Create(3)
            					->setFixed(0,HX_("start",62,74,0b,84),s)
            					->setFixed(1,HX_("number",c9,86,7a,a1),lineCount)
            					->setFixed(2,HX_("end",db,03,4d,00),e)));
HXLINE(  52)				lineCount = (lineCount + 1);
HXLINE(  53)				i = (i + 1);
HXLINE(  54)				s = i;
HXLINE(  49)				goto _hx_goto_1;
            			}
            			if (  (_hx_switch_0==HX_("\r",0d,00,00,00)) ){
HXLINE(  41)				e = i;
HXLINE(  42)				if ((content.charAt((i + 1)) == HX_("\n",0a,00,00,00))) {
HXLINE(  43)					e = (e + 1);
            				}
HXLINE(  45)				this->linesInfo->push( ::Dynamic(::hx::Anon_obj::Create(3)
            					->setFixed(0,HX_("start",62,74,0b,84),s)
            					->setFixed(1,HX_("number",c9,86,7a,a1),lineCount)
            					->setFixed(2,HX_("end",db,03,4d,00),e)));
HXLINE(  46)				lineCount = (lineCount + 1);
HXLINE(  47)				i = (e + 1);
HXLINE(  48)				s = i;
HXLINE(  40)				goto _hx_goto_1;
            			}
            			/* default */{
HXLINE(  56)				i = (i + 1);
            			}
            			_hx_goto_1:;
            		}
HXLINE(  59)		this->linesInfo->push( ::Dynamic(::hx::Anon_obj::Create(3)
            			->setFixed(0,HX_("start",62,74,0b,84),s)
            			->setFixed(1,HX_("number",c9,86,7a,a1),lineCount)
            			->setFixed(2,HX_("end",db,03,4d,00),i)));
            	}

Dynamic PositionUtils_obj::__CreateEmpty() { return new PositionUtils_obj; }

void *PositionUtils_obj::_hx_vtable = 0;

Dynamic PositionUtils_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< PositionUtils_obj > _hx_result = new PositionUtils_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool PositionUtils_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x44803047;
}

 ::Dynamic PositionUtils_obj::convertPosition( ::hxjsonast::Position position){
            	HX_STACKFRAME(&_hx_pos_5264ea8bcde66021_65_convertPosition)
HXLINE(  66)		::String file = position->file;
HXLINE(  67)		int min = position->min;
HXLINE(  68)		int max = position->max;
HXLINE(  70)		 ::Dynamic pos =  ::Dynamic(::hx::Anon_obj::Create(4)
            			->setFixed(0,HX_("max",a4,0a,53,00),(max + 1))
            			->setFixed(1,HX_("min",92,11,53,00),(min + 1))
            			->setFixed(2,HX_("file",7c,ce,bb,43),file)
            			->setFixed(3,HX_("lines",ff,dd,01,75),::Array_obj< ::Dynamic>::__new(0)));
HXLINE(  71)		int lastLine = (this->linesInfo->length - 1);
HXLINE(  73)		int bounds_min = 0;
HXDLIN(  73)		int bounds_max = lastLine;
HXLINE(  74)		if (::hx::IsGreater( min,this->linesInfo->__get(0)->__Field(HX_("end",db,03,4d,00),::hx::paccDynamic) )) {
HXLINE(  75)			while((bounds_max > bounds_min)){
HXLINE(  76)				int i = ::Std_obj::_hx_int((( (Float)((bounds_min + bounds_max)) ) / ( (Float)(2) )));
HXLINE(  77)				 ::Dynamic line = this->linesInfo->__get(i);
HXLINE(  78)				if (::hx::IsEq( line->__Field(HX_("start",62,74,0b,84),::hx::paccDynamic),min )) {
HXLINE(  79)					bounds_min = i;
HXLINE(  80)					bounds_max = i;
            				}
HXLINE(  82)				if (::hx::IsLess( line->__Field(HX_("end",db,03,4d,00),::hx::paccDynamic),min )) {
HXLINE(  83)					bounds_min = (i + 1);
            				}
HXLINE(  85)				bool _hx_tmp;
HXDLIN(  85)				if (::hx::IsLessEq( line->__Field(HX_("start",62,74,0b,84),::hx::paccDynamic),min )) {
HXLINE(  85)					if (::hx::IsGreaterEq( line->__Field(HX_("end",db,03,4d,00),::hx::paccDynamic),min )) {
HXLINE(  85)						_hx_tmp = ::hx::IsLess( line->__Field(HX_("start",62,74,0b,84),::hx::paccDynamic),min );
            					}
            					else {
HXLINE(  85)						_hx_tmp = false;
            					}
            				}
            				else {
HXLINE(  85)					_hx_tmp = true;
            				}
HXDLIN(  85)				if (_hx_tmp) {
HXLINE(  86)					bounds_max = i;
            				}
            			}
            		}
HXLINE(  93)		{
HXLINE(  93)			int _g = bounds_min;
HXDLIN(  93)			int _g1 = this->linesInfo->length;
HXDLIN(  93)			while((_g < _g1)){
HXLINE(  93)				_g = (_g + 1);
HXDLIN(  93)				int i = (_g - 1);
HXLINE(  94)				 ::Dynamic line = this->linesInfo->__get(i);
HXLINE(  95)				bool _hx_tmp;
HXDLIN(  95)				if (::hx::IsLessEq( line->__Field(HX_("start",62,74,0b,84),::hx::paccDynamic),min )) {
HXLINE(  95)					_hx_tmp = ::hx::IsGreaterEq( line->__Field(HX_("end",db,03,4d,00),::hx::paccDynamic),max );
            				}
            				else {
HXLINE(  95)					_hx_tmp = false;
            				}
HXDLIN(  95)				if (_hx_tmp) {
HXLINE(  96)					( (::Array< ::Dynamic>)(pos->__Field(HX_("lines",ff,dd,01,75),::hx::paccDynamic)) )->push( ::Dynamic(::hx::Anon_obj::Create(3)
            						->setFixed(0,HX_("start",62,74,0b,84),((min - ( (int)(line->__Field(HX_("start",62,74,0b,84),::hx::paccDynamic)) )) + 1))
            						->setFixed(1,HX_("number",c9,86,7a,a1), ::Dynamic((line->__Field(HX_("number",c9,86,7a,a1),::hx::paccDynamic) + 1)))
            						->setFixed(2,HX_("end",db,03,4d,00),((max - ( (int)(line->__Field(HX_("start",62,74,0b,84),::hx::paccDynamic)) )) + 1))));
HXLINE(  97)					goto _hx_goto_4;
            				}
HXLINE(  99)				bool _hx_tmp1;
HXDLIN(  99)				if (::hx::IsLessEq( line->__Field(HX_("start",62,74,0b,84),::hx::paccDynamic),min )) {
HXLINE(  99)					_hx_tmp1 = ::hx::IsLessEq( min,line->__Field(HX_("end",db,03,4d,00),::hx::paccDynamic) );
            				}
            				else {
HXLINE(  99)					_hx_tmp1 = false;
            				}
HXDLIN(  99)				if (_hx_tmp1) {
HXLINE( 100)					( (::Array< ::Dynamic>)(pos->__Field(HX_("lines",ff,dd,01,75),::hx::paccDynamic)) )->push( ::Dynamic(::hx::Anon_obj::Create(3)
            						->setFixed(0,HX_("start",62,74,0b,84),((min - ( (int)(line->__Field(HX_("start",62,74,0b,84),::hx::paccDynamic)) )) + 1))
            						->setFixed(1,HX_("number",c9,86,7a,a1), ::Dynamic((line->__Field(HX_("number",c9,86,7a,a1),::hx::paccDynamic) + 1)))
            						->setFixed(2,HX_("end",db,03,4d,00), ::Dynamic((line->__Field(HX_("end",db,03,4d,00),::hx::paccDynamic) + 1)))));
            				}
HXLINE( 102)				bool _hx_tmp2;
HXDLIN( 102)				if (::hx::IsLessEq( line->__Field(HX_("start",62,74,0b,84),::hx::paccDynamic),max )) {
HXLINE( 102)					_hx_tmp2 = ::hx::IsLessEq( max,line->__Field(HX_("end",db,03,4d,00),::hx::paccDynamic) );
            				}
            				else {
HXLINE( 102)					_hx_tmp2 = false;
            				}
HXDLIN( 102)				if (_hx_tmp2) {
HXLINE( 103)					( (::Array< ::Dynamic>)(pos->__Field(HX_("lines",ff,dd,01,75),::hx::paccDynamic)) )->push( ::Dynamic(::hx::Anon_obj::Create(3)
            						->setFixed(0,HX_("start",62,74,0b,84), ::Dynamic((line->__Field(HX_("start",62,74,0b,84),::hx::paccDynamic) + 1)))
            						->setFixed(1,HX_("number",c9,86,7a,a1), ::Dynamic((line->__Field(HX_("number",c9,86,7a,a1),::hx::paccDynamic) + 1)))
            						->setFixed(2,HX_("end",db,03,4d,00),((max - ( (int)(line->__Field(HX_("start",62,74,0b,84),::hx::paccDynamic)) )) + 1))));
            				}
HXLINE( 105)				bool _hx_tmp3;
HXDLIN( 105)				if (::hx::IsLess( line->__Field(HX_("start",62,74,0b,84),::hx::paccDynamic),max )) {
HXLINE( 105)					_hx_tmp3 = ::hx::IsGreaterEq( line->__Field(HX_("end",db,03,4d,00),::hx::paccDynamic),max );
            				}
            				else {
HXLINE( 105)					_hx_tmp3 = true;
            				}
HXDLIN( 105)				if (_hx_tmp3) {
HXLINE( 106)					goto _hx_goto_4;
            				}
            			}
            			_hx_goto_4:;
            		}
HXLINE( 110)		return pos;
            	}


HX_DEFINE_DYNAMIC_FUNC1(PositionUtils_obj,convertPosition,return )

 ::hxjsonast::Position PositionUtils_obj::revert( ::Dynamic position){
            	HX_GC_STACKFRAME(&_hx_pos_5264ea8bcde66021_114_revert)
HXDLIN( 114)		return  ::hxjsonast::Position_obj::__alloc( HX_CTX ,( (::String)(position->__Field(HX_("file",7c,ce,bb,43),::hx::paccDynamic)) ),(( (int)(position->__Field(HX_("min",92,11,53,00),::hx::paccDynamic)) ) - 1),(( (int)(position->__Field(HX_("max",a4,0a,53,00),::hx::paccDynamic)) ) - 1));
            	}


HX_DEFINE_DYNAMIC_FUNC1(PositionUtils_obj,revert,return )


::hx::ObjectPtr< PositionUtils_obj > PositionUtils_obj::__new(::String content) {
	::hx::ObjectPtr< PositionUtils_obj > __this = new PositionUtils_obj();
	__this->__construct(content);
	return __this;
}

::hx::ObjectPtr< PositionUtils_obj > PositionUtils_obj::__alloc(::hx::Ctx *_hx_ctx,::String content) {
	PositionUtils_obj *__this = (PositionUtils_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(PositionUtils_obj), true, "json2object.PositionUtils"));
	*(void **)__this = PositionUtils_obj::_hx_vtable;
	__this->__construct(content);
	return __this;
}

PositionUtils_obj::PositionUtils_obj()
{
}

void PositionUtils_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PositionUtils);
	HX_MARK_MEMBER_NAME(linesInfo,"linesInfo");
	HX_MARK_END_CLASS();
}

void PositionUtils_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(linesInfo,"linesInfo");
}

::hx::Val PositionUtils_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"revert") ) { return ::hx::Val( revert_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"linesInfo") ) { return ::hx::Val( linesInfo ); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"convertPosition") ) { return ::hx::Val( convertPosition_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val PositionUtils_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"linesInfo") ) { linesInfo=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PositionUtils_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("linesInfo",0d,ae,76,1b));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo PositionUtils_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(PositionUtils_obj,linesInfo),HX_("linesInfo",0d,ae,76,1b)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *PositionUtils_obj_sStaticStorageInfo = 0;
#endif

static ::String PositionUtils_obj_sMemberFields[] = {
	HX_("linesInfo",0d,ae,76,1b),
	HX_("convertPosition",bc,05,62,00),
	HX_("revert",e4,ed,73,0a),
	::String(null()) };

::hx::Class PositionUtils_obj::__mClass;

void PositionUtils_obj::__register()
{
	PositionUtils_obj _hx_dummy;
	PositionUtils_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("json2object.PositionUtils",c3,10,49,3d);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(PositionUtils_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< PositionUtils_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = PositionUtils_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = PositionUtils_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace json2object
