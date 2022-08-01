#include <hxcpp.h>

#ifndef INCLUDED_95f339a1d026d52c
#define INCLUDED_95f339a1d026d52c
#include "hxMath.h"
#endif
#ifndef INCLUDED_feshixl_math_FeshMatrix3x3
#include <feshixl/math/FeshMatrix3x3.h>
#endif
#ifndef INCLUDED_flixel_math_FlxMatrix
#include <flixel/math/FlxMatrix.h>
#endif
#ifndef INCLUDED_openfl_geom_Matrix
#include <openfl/geom/Matrix.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_5321edc19891513c_5_new,"feshixl.math.FeshMatrix3x3","new",0x9ac48c4a,"feshixl.math.FeshMatrix3x3.new","feshixl/math/FeshMatrix3x3.hx",5,0x306b26c6)
HX_LOCAL_STACK_FRAME(_hx_pos_5321edc19891513c_6_rotateWithTrig3D,"feshixl.math.FeshMatrix3x3","rotateWithTrig3D",0xeead6f44,"feshixl.math.FeshMatrix3x3.rotateWithTrig3D","feshixl/math/FeshMatrix3x3.hx",6,0x306b26c6)
namespace feshixl{
namespace math{

void FeshMatrix3x3_obj::__construct( ::Dynamic a, ::Dynamic b, ::Dynamic c, ::Dynamic d, ::Dynamic tx, ::Dynamic ty){
            	HX_STACKFRAME(&_hx_pos_5321edc19891513c_5_new)
HXDLIN(   5)		super::__construct(a,b,c,d,tx,ty);
            	}

Dynamic FeshMatrix3x3_obj::__CreateEmpty() { return new FeshMatrix3x3_obj; }

void *FeshMatrix3x3_obj::_hx_vtable = 0;

Dynamic FeshMatrix3x3_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< FeshMatrix3x3_obj > _hx_result = new FeshMatrix3x3_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5]);
	return _hx_result;
}

bool FeshMatrix3x3_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x24ed006c) {
		if (inClassId<=(int)0x065caf19) {
			return inClassId==(int)0x00000001 || inClassId==(int)0x065caf19;
		} else {
			return inClassId==(int)0x24ed006c;
		}
	} else {
		return inClassId==(int)0x666c094f;
	}
}

void FeshMatrix3x3_obj::rotateWithTrig3D(Float thetaX,Float thetaY,Float thetaZ,::hx::Null< Float >  __o_z,::hx::Null< bool >  __o_hasPerspective){
            		Float z = __o_z.Default(0);
            		bool hasPerspective = __o_hasPerspective.Default(true);
            	HX_STACKFRAME(&_hx_pos_5321edc19891513c_6_rotateWithTrig3D)
HXLINE(   8)		Float xc = ::Math_obj::cos(thetaX);
HXLINE(   9)		Float xs = ::Math_obj::sin(thetaX);
HXLINE(  10)		Float yc = ::Math_obj::cos(thetaY);
HXLINE(  11)		Float ys = ::Math_obj::sin(thetaY);
HXLINE(  12)		Float zc = ::Math_obj::cos(thetaZ);
HXLINE(  13)		Float zs = ::Math_obj::sin(thetaZ);
HXLINE(  15)		Float p1 = ( (Float)(1) );
HXLINE(  16)		Float p2 = ( (Float)(1) );
HXLINE(  17)		Float p3 = ( (Float)(1) );
HXLINE(  19)		{
HXLINE(  19)			Float a1 = ((this->a * zc) - (this->b * zs));
HXDLIN(  19)			this->b = ((this->a * zs) + (this->b * zc));
HXDLIN(  19)			this->a = a1;
HXDLIN(  19)			Float c1 = ((this->c * zc) - (this->d * zs));
HXDLIN(  19)			this->d = ((this->c * zs) + (this->d * zc));
HXDLIN(  19)			this->c = c1;
HXDLIN(  19)			Float tx1 = ((this->tx * zc) - (this->ty * zs));
HXDLIN(  19)			this->ty = ((this->tx * zs) + (this->ty * zc));
HXDLIN(  19)			this->tx = tx1;
            		}
HXLINE(  21)		Float a11 = (p1 * ((( (Float)(0) ) * ys) + (this->a * yc)));
HXLINE(  22)		this->b = (p1 * ((this->b * xc) - (((z * yc) - (this->a * ys)) * xs)));
HXLINE(  23)		this->a = a11;
HXLINE(  25)		Float c11 = (p2 * ((( (Float)(0) ) * ys) + (this->c * yc)));
HXLINE(  26)		this->d = (p2 * ((this->d * xc) - (((z * yc) - (this->c * ys)) * xs)));
HXLINE(  27)		this->c = c11;
HXLINE(  29)		Float tx11 = (p3 * ((( (Float)(0) ) * ys) + (this->tx * yc)));
HXLINE(  30)		this->ty = (p3 * ((this->ty * xc) - (((z * yc) - (this->tx * ys)) * xs)));
HXLINE(  31)		this->tx = tx11;
            	}


HX_DEFINE_DYNAMIC_FUNC5(FeshMatrix3x3_obj,rotateWithTrig3D,(void))


::hx::ObjectPtr< FeshMatrix3x3_obj > FeshMatrix3x3_obj::__new( ::Dynamic a, ::Dynamic b, ::Dynamic c, ::Dynamic d, ::Dynamic tx, ::Dynamic ty) {
	::hx::ObjectPtr< FeshMatrix3x3_obj > __this = new FeshMatrix3x3_obj();
	__this->__construct(a,b,c,d,tx,ty);
	return __this;
}

::hx::ObjectPtr< FeshMatrix3x3_obj > FeshMatrix3x3_obj::__alloc(::hx::Ctx *_hx_ctx, ::Dynamic a, ::Dynamic b, ::Dynamic c, ::Dynamic d, ::Dynamic tx, ::Dynamic ty) {
	FeshMatrix3x3_obj *__this = (FeshMatrix3x3_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(FeshMatrix3x3_obj), true, "feshixl.math.FeshMatrix3x3"));
	*(void **)__this = FeshMatrix3x3_obj::_hx_vtable;
	__this->__construct(a,b,c,d,tx,ty);
	return __this;
}

FeshMatrix3x3_obj::FeshMatrix3x3_obj()
{
}

::hx::Val FeshMatrix3x3_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 16:
		if (HX_FIELD_EQ(inName,"rotateWithTrig3D") ) { return ::hx::Val( rotateWithTrig3D_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *FeshMatrix3x3_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *FeshMatrix3x3_obj_sStaticStorageInfo = 0;
#endif

static ::String FeshMatrix3x3_obj_sMemberFields[] = {
	HX_("rotateWithTrig3D",6e,d5,c8,c0),
	::String(null()) };

::hx::Class FeshMatrix3x3_obj::__mClass;

void FeshMatrix3x3_obj::__register()
{
	FeshMatrix3x3_obj _hx_dummy;
	FeshMatrix3x3_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("feshixl.math.FeshMatrix3x3",58,5f,aa,22);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(FeshMatrix3x3_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< FeshMatrix3x3_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = FeshMatrix3x3_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = FeshMatrix3x3_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace feshixl
} // end namespace math
