#include <hxcpp.h>

#ifndef INCLUDED_95f339a1d026d52c
#define INCLUDED_95f339a1d026d52c
#include "hxMath.h"
#endif
#ifndef INCLUDED_CameraNote
#include <CameraNote.h>
#endif
#ifndef INCLUDED_WiggleEffect
#include <WiggleEffect.h>
#endif
#ifndef INCLUDED_WiggleEffectType
#include <WiggleEffectType.h>
#endif
#ifndef INCLUDED_WiggleShader
#include <WiggleShader.h>
#endif
#ifndef INCLUDED_betterShit_BetterCams
#include <betterShit/BetterCams.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxCamera
#include <flixel/FlxCamera.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_graphics_tile_FlxGraphicsShader
#include <flixel/graphics/tile/FlxGraphicsShader.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_CameraFrontEnd
#include <flixel/system/frontEnds/CameraFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxDestroyable
#include <flixel/util/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_openfl_display_GraphicsShader
#include <openfl/display/GraphicsShader.h>
#endif
#ifndef INCLUDED_openfl_display_Shader
#include <openfl/display/Shader.h>
#endif
#ifndef INCLUDED_openfl_filters_BitmapFilter
#include <openfl/filters/BitmapFilter.h>
#endif
#ifndef INCLUDED_openfl_filters_ShaderFilter
#include <openfl/filters/ShaderFilter.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_d0668deb9460d109_11_new,"CameraNote","new",0xe2f7ddc9,"CameraNote.new","CameraNote.hx",11,0x9d24adc7)
HX_LOCAL_STACK_FRAME(_hx_pos_d0668deb9460d109_19_createNoteCam,"CameraNote","createNoteCam",0x73da3a4a,"CameraNote.createNoteCam","CameraNote.hx",19,0x9d24adc7)
HX_LOCAL_STACK_FRAME(_hx_pos_d0668deb9460d109_36_setFilters,"CameraNote","setFilters",0xdb7e27f0,"CameraNote.setFilters","CameraNote.hx",36,0x9d24adc7)
HX_LOCAL_STACK_FRAME(_hx_pos_d0668deb9460d109_47_update,"CameraNote","update",0xc00f0040,"CameraNote.update","CameraNote.hx",47,0x9d24adc7)
HX_LOCAL_STACK_FRAME(_hx_pos_d0668deb9460d109_62_destroy,"CameraNote","destroy",0xd3c7a2e3,"CameraNote.destroy","CameraNote.hx",62,0x9d24adc7)

void CameraNote_obj::__construct(){
            	HX_GC_STACKFRAME(&_hx_pos_d0668deb9460d109_11_new)
HXLINE(  15)		this->noteWiggleFLAG =  ::WiggleEffect_obj::__alloc( HX_CTX );
HXLINE(  11)		super::__construct();
            	}

Dynamic CameraNote_obj::__CreateEmpty() { return new CameraNote_obj; }

void *CameraNote_obj::_hx_vtable = 0;

Dynamic CameraNote_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< CameraNote_obj > _hx_result = new CameraNote_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool CameraNote_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x3bfe74df) {
		if (inClassId<=(int)0x1ff7ce3b) {
			return inClassId==(int)0x00000001 || inClassId==(int)0x1ff7ce3b;
		} else {
			return inClassId==(int)0x3bfe74df;
		}
	} else {
		return inClassId==(int)0x79a9d584 || inClassId==(int)0x7ccf8994;
	}
}

void CameraNote_obj::createNoteCam(::String note){
            	HX_GC_STACKFRAME(&_hx_pos_d0668deb9460d109_19_createNoteCam)
HXLINE(  21)		if (::hx::IsNotNull( this->camNoteWOBBLE )) {
HXLINE(  22)			return;
            		}
HXLINE(  24)		this->camNoteWOBBLE =  ::flixel::FlxCamera_obj::__alloc( HX_CTX ,null(),null(),null(),null(),null());
HXLINE(  25)		{
HXLINE(  25)			 ::flixel::FlxCamera _hx_tmp = this->camNoteWOBBLE;
HXDLIN(  25)			_hx_tmp->bgColor = (_hx_tmp->bgColor & 16777215);
HXDLIN(  25)			 ::flixel::FlxCamera _hx_tmp1 = this->camNoteWOBBLE;
HXDLIN(  25)			_hx_tmp1->bgColor = (_hx_tmp1->bgColor | 0);
            		}
HXLINE(  26)		 ::flixel::FlxCamera _hx_tmp2 = this->camNoteWOBBLE;
HXDLIN(  26)		_hx_tmp2->setFilters(::Array_obj< ::Dynamic>::__new(1)->init(0, ::openfl::filters::ShaderFilter_obj::__alloc( HX_CTX ,this->noteWiggleFLAG->shader)));
HXLINE(  27)		::flixel::FlxG_obj::cameras->add(this->camNoteWOBBLE,null()).StaticCast<  ::flixel::FlxCamera >();
HXLINE(  29)		this->noteWiggleFLAG->set_effectType(::WiggleEffectType_obj::DREAMY_dyn());
HXLINE(  30)		this->noteWiggleFLAG->set_waveSpeed(( (Float)(1) ));
HXLINE(  31)		this->noteWiggleFLAG->set_waveFrequency((::Math_obj::PI * ( (Float)(3) )));
            	}


HX_DEFINE_DYNAMIC_FUNC1(CameraNote_obj,createNoteCam,(void))

void CameraNote_obj::setFilters(::Array< ::Dynamic> filters){
            	HX_GC_STACKFRAME(&_hx_pos_d0668deb9460d109_36_setFilters)
HXLINE(  37)		if (::hx::IsNotNull( this->camNoteWOBBLE )) {
HXLINE(  38)			::Array< ::Dynamic> littleShit = filters->concat(::Array_obj< ::Dynamic>::__new(0));
HXLINE(  39)			littleShit->push( ::openfl::filters::ShaderFilter_obj::__alloc( HX_CTX ,this->noteWiggleFLAG->shader));
HXLINE(  41)			this->camNoteWOBBLE->setFilters(littleShit);
            		}
HXLINE(  44)		this->super::setFilters(filters);
            	}


void CameraNote_obj::update(Float elapsed){
            	HX_STACKFRAME(&_hx_pos_d0668deb9460d109_47_update)
HXLINE(  48)		this->super::update(elapsed);
HXLINE(  50)		if (::hx::IsNotNull( this->camNoteWOBBLE )) {
HXLINE(  51)			this->noteWiggleFLAG->set_waveAmplitude(((Float)0.02));
HXLINE(  54)			this->camNoteWOBBLE->set_x(this->x);
HXLINE(  55)			this->camNoteWOBBLE->set_y(this->y);
HXLINE(  56)			this->camNoteWOBBLE->set_zoom(this->zoom);
HXLINE(  57)			this->camNoteWOBBLE->set_angle(this->angle);
            		}
            	}


void CameraNote_obj::destroy(){
            	HX_STACKFRAME(&_hx_pos_d0668deb9460d109_62_destroy)
HXDLIN(  62)		if (::hx::IsNotNull( this->camNoteWOBBLE )) {
HXLINE(  63)			this->camNoteWOBBLE->destroy();
            		}
            	}



::hx::ObjectPtr< CameraNote_obj > CameraNote_obj::__new() {
	::hx::ObjectPtr< CameraNote_obj > __this = new CameraNote_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< CameraNote_obj > CameraNote_obj::__alloc(::hx::Ctx *_hx_ctx) {
	CameraNote_obj *__this = (CameraNote_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(CameraNote_obj), true, "CameraNote"));
	*(void **)__this = CameraNote_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

CameraNote_obj::CameraNote_obj()
{
}

void CameraNote_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CameraNote);
	HX_MARK_MEMBER_NAME(camNoteWOBBLE,"camNoteWOBBLE");
	HX_MARK_MEMBER_NAME(noteWiggleFLAG,"noteWiggleFLAG");
	 ::betterShit::BetterCams_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void CameraNote_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(camNoteWOBBLE,"camNoteWOBBLE");
	HX_VISIT_MEMBER_NAME(noteWiggleFLAG,"noteWiggleFLAG");
	 ::betterShit::BetterCams_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val CameraNote_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return ::hx::Val( update_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return ::hx::Val( destroy_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"setFilters") ) { return ::hx::Val( setFilters_dyn() ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"camNoteWOBBLE") ) { return ::hx::Val( camNoteWOBBLE ); }
		if (HX_FIELD_EQ(inName,"createNoteCam") ) { return ::hx::Val( createNoteCam_dyn() ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"noteWiggleFLAG") ) { return ::hx::Val( noteWiggleFLAG ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val CameraNote_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 13:
		if (HX_FIELD_EQ(inName,"camNoteWOBBLE") ) { camNoteWOBBLE=inValue.Cast<  ::flixel::FlxCamera >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"noteWiggleFLAG") ) { noteWiggleFLAG=inValue.Cast<  ::WiggleEffect >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CameraNote_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("camNoteWOBBLE",b2,fe,63,93));
	outFields->push(HX_("noteWiggleFLAG",69,1d,b2,a8));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo CameraNote_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::flixel::FlxCamera */ ,(int)offsetof(CameraNote_obj,camNoteWOBBLE),HX_("camNoteWOBBLE",b2,fe,63,93)},
	{::hx::fsObject /*  ::WiggleEffect */ ,(int)offsetof(CameraNote_obj,noteWiggleFLAG),HX_("noteWiggleFLAG",69,1d,b2,a8)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *CameraNote_obj_sStaticStorageInfo = 0;
#endif

static ::String CameraNote_obj_sMemberFields[] = {
	HX_("camNoteWOBBLE",b2,fe,63,93),
	HX_("noteWiggleFLAG",69,1d,b2,a8),
	HX_("createNoteCam",a1,ef,89,35),
	HX_("setFilters",39,c6,25,5c),
	HX_("update",09,86,05,87),
	HX_("destroy",fa,2c,86,24),
	::String(null()) };

::hx::Class CameraNote_obj::__mClass;

void CameraNote_obj::__register()
{
	CameraNote_obj _hx_dummy;
	CameraNote_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("CameraNote",57,45,d9,a5);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(CameraNote_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< CameraNote_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = CameraNote_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = CameraNote_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

