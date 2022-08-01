#include <hxcpp.h>

#ifndef INCLUDED_95f339a1d026d52c
#define INCLUDED_95f339a1d026d52c
#include "hxMath.h"
#endif
#ifndef INCLUDED_feshixl_math_FeshMatrix4x4
#include <feshixl/math/FeshMatrix4x4.h>
#endif
#ifndef INCLUDED_flixel_math_FlxMatrix
#include <flixel/math/FlxMatrix.h>
#endif
#ifndef INCLUDED_openfl_geom_Matrix
#include <openfl/geom/Matrix.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_23a9d83b11245a9e_33_new,"feshixl.math.FeshMatrix4x4","new",0x57c0978c,"feshixl.math.FeshMatrix4x4.new","feshixl/math/FeshMatrix4x4.hx",33,0x976fb9c4)
HX_LOCAL_STACK_FRAME(_hx_pos_23a9d83b11245a9e_38_initScale,"feshixl.math.FeshMatrix4x4","initScale",0x99cd5986,"feshixl.math.FeshMatrix4x4.initScale","feshixl/math/FeshMatrix4x4.hx",38,0x976fb9c4)
HX_LOCAL_STACK_FRAME(_hx_pos_23a9d83b11245a9e_45_initIdentity,"feshixl.math.FeshMatrix4x4","initIdentity",0xa8f4bfc2,"feshixl.math.FeshMatrix4x4.initIdentity","feshixl/math/FeshMatrix4x4.hx",45,0x976fb9c4)
HX_LOCAL_STACK_FRAME(_hx_pos_23a9d83b11245a9e_52_scale4x3,"feshixl.math.FeshMatrix4x4","scale4x3",0xdedafaf9,"feshixl.math.FeshMatrix4x4.scale4x3","feshixl/math/FeshMatrix4x4.hx",52,0x976fb9c4)
HX_LOCAL_STACK_FRAME(_hx_pos_23a9d83b11245a9e_58_translate4x3,"feshixl.math.FeshMatrix4x4","translate4x3",0x0b85feb5,"feshixl.math.FeshMatrix4x4.translate4x3","feshixl/math/FeshMatrix4x4.hx",58,0x976fb9c4)
HX_LOCAL_STACK_FRAME(_hx_pos_23a9d83b11245a9e_77_multiplyBy,"feshixl.math.FeshMatrix4x4","multiplyBy",0xba9aa36f,"feshixl.math.FeshMatrix4x4.multiplyBy","feshixl/math/FeshMatrix4x4.hx",77,0x976fb9c4)
HX_LOCAL_STACK_FRAME(_hx_pos_23a9d83b11245a9e_108_multiplyValues,"feshixl.math.FeshMatrix4x4","multiplyValues",0xbee3fd7a,"feshixl.math.FeshMatrix4x4.multiplyValues","feshixl/math/FeshMatrix4x4.hx",108,0x976fb9c4)
HX_LOCAL_STACK_FRAME(_hx_pos_23a9d83b11245a9e_130_invert4x4,"feshixl.math.FeshMatrix4x4","invert4x4",0x9b9078c6,"feshixl.math.FeshMatrix4x4.invert4x4","feshixl/math/FeshMatrix4x4.hx",130,0x976fb9c4)
HX_LOCAL_STACK_FRAME(_hx_pos_23a9d83b11245a9e_169_get__11,"feshixl.math.FeshMatrix4x4","get__11",0xb73ad6c2,"feshixl.math.FeshMatrix4x4.get__11","feshixl/math/FeshMatrix4x4.hx",169,0x976fb9c4)
HX_LOCAL_STACK_FRAME(_hx_pos_23a9d83b11245a9e_173_set__11,"feshixl.math.FeshMatrix4x4","set__11",0xaa3c67ce,"feshixl.math.FeshMatrix4x4.set__11","feshixl/math/FeshMatrix4x4.hx",173,0x976fb9c4)
HX_LOCAL_STACK_FRAME(_hx_pos_23a9d83b11245a9e_177_get__21,"feshixl.math.FeshMatrix4x4","get__21",0xb73ad7a1,"feshixl.math.FeshMatrix4x4.get__21","feshixl/math/FeshMatrix4x4.hx",177,0x976fb9c4)
HX_LOCAL_STACK_FRAME(_hx_pos_23a9d83b11245a9e_181_set__21,"feshixl.math.FeshMatrix4x4","set__21",0xaa3c68ad,"feshixl.math.FeshMatrix4x4.set__21","feshixl/math/FeshMatrix4x4.hx",181,0x976fb9c4)
HX_LOCAL_STACK_FRAME(_hx_pos_23a9d83b11245a9e_185_get__12,"feshixl.math.FeshMatrix4x4","get__12",0xb73ad6c3,"feshixl.math.FeshMatrix4x4.get__12","feshixl/math/FeshMatrix4x4.hx",185,0x976fb9c4)
HX_LOCAL_STACK_FRAME(_hx_pos_23a9d83b11245a9e_189_set__12,"feshixl.math.FeshMatrix4x4","set__12",0xaa3c67cf,"feshixl.math.FeshMatrix4x4.set__12","feshixl/math/FeshMatrix4x4.hx",189,0x976fb9c4)
HX_LOCAL_STACK_FRAME(_hx_pos_23a9d83b11245a9e_193_get__22,"feshixl.math.FeshMatrix4x4","get__22",0xb73ad7a2,"feshixl.math.FeshMatrix4x4.get__22","feshixl/math/FeshMatrix4x4.hx",193,0x976fb9c4)
HX_LOCAL_STACK_FRAME(_hx_pos_23a9d83b11245a9e_197_set__22,"feshixl.math.FeshMatrix4x4","set__22",0xaa3c68ae,"feshixl.math.FeshMatrix4x4.set__22","feshixl/math/FeshMatrix4x4.hx",197,0x976fb9c4)
HX_LOCAL_STACK_FRAME(_hx_pos_23a9d83b11245a9e_201_get__41,"feshixl.math.FeshMatrix4x4","get__41",0xb73ad95f,"feshixl.math.FeshMatrix4x4.get__41","feshixl/math/FeshMatrix4x4.hx",201,0x976fb9c4)
HX_LOCAL_STACK_FRAME(_hx_pos_23a9d83b11245a9e_205_set__41,"feshixl.math.FeshMatrix4x4","set__41",0xaa3c6a6b,"feshixl.math.FeshMatrix4x4.set__41","feshixl/math/FeshMatrix4x4.hx",205,0x976fb9c4)
HX_LOCAL_STACK_FRAME(_hx_pos_23a9d83b11245a9e_209_get__42,"feshixl.math.FeshMatrix4x4","get__42",0xb73ad960,"feshixl.math.FeshMatrix4x4.get__42","feshixl/math/FeshMatrix4x4.hx",209,0x976fb9c4)
HX_LOCAL_STACK_FRAME(_hx_pos_23a9d83b11245a9e_213_set__42,"feshixl.math.FeshMatrix4x4","set__42",0xaa3c6a6c,"feshixl.math.FeshMatrix4x4.set__42","feshixl/math/FeshMatrix4x4.hx",213,0x976fb9c4)
namespace feshixl{
namespace math{

void FeshMatrix4x4_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_23a9d83b11245a9e_33_new)
HXLINE(  34)		this->initIdentity();
HXLINE(  35)		super::__construct(null(),null(),null(),null(),null(),null());
            	}

Dynamic FeshMatrix4x4_obj::__CreateEmpty() { return new FeshMatrix4x4_obj; }

void *FeshMatrix4x4_obj::_hx_vtable = 0;

Dynamic FeshMatrix4x4_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< FeshMatrix4x4_obj > _hx_result = new FeshMatrix4x4_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool FeshMatrix4x4_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x24edc2ae) {
		if (inClassId<=(int)0x065caf19) {
			return inClassId==(int)0x00000001 || inClassId==(int)0x065caf19;
		} else {
			return inClassId==(int)0x24edc2ae;
		}
	} else {
		return inClassId==(int)0x666c094f;
	}
}

void FeshMatrix4x4_obj::initScale(::hx::Null< Float >  __o_scaleX,::hx::Null< Float >  __o_scaleY,::hx::Null< Float >  __o_scaleZ){
            		Float scaleX = __o_scaleX.Default(0);
            		Float scaleY = __o_scaleY.Default(0);
            		Float scaleZ = __o_scaleZ.Default(1);
            	HX_STACKFRAME(&_hx_pos_23a9d83b11245a9e_38_initScale)
HXLINE(  39)		this->set__11(scaleX);
HXDLIN(  39)		this->set__12(((Float)0.0));
HXDLIN(  39)		this->_13 = ((Float)0.0);
HXDLIN(  39)		this->_14 = ((Float)0.0);
HXLINE(  40)		this->set__21(((Float)0.0));
HXDLIN(  40)		this->set__22(scaleY);
HXDLIN(  40)		this->_23 = ((Float)0.0);
HXDLIN(  40)		this->_24 = ((Float)0.0);
HXLINE(  41)		this->_31 = ((Float)0.0);
HXDLIN(  41)		this->_32 = ((Float)0.0);
HXDLIN(  41)		this->_33 = scaleZ;
HXDLIN(  41)		this->_34 = ((Float)0.0);
HXLINE(  42)		this->set__41(((Float)0.0));
HXDLIN(  42)		this->set__42(((Float)0.0));
HXDLIN(  42)		this->_43 = ((Float)0.0);
HXDLIN(  42)		this->_44 = ((Float)1.0);
            	}


HX_DEFINE_DYNAMIC_FUNC3(FeshMatrix4x4_obj,initScale,(void))

void FeshMatrix4x4_obj::initIdentity(){
            	HX_STACKFRAME(&_hx_pos_23a9d83b11245a9e_45_initIdentity)
HXLINE(  46)		this->set__11(((Float)1.0));
HXDLIN(  46)		this->set__12(((Float)0.0));
HXDLIN(  46)		this->_13 = ((Float)0.0);
HXDLIN(  46)		this->_14 = ((Float)0.0);
HXLINE(  47)		this->set__21(((Float)0.0));
HXDLIN(  47)		this->set__22(((Float)1.0));
HXDLIN(  47)		this->_23 = ((Float)0.0);
HXDLIN(  47)		this->_24 = ((Float)0.0);
HXLINE(  48)		this->_31 = ((Float)0.0);
HXDLIN(  48)		this->_32 = ((Float)0.0);
HXDLIN(  48)		this->_33 = ((Float)1.0);
HXDLIN(  48)		this->_34 = ((Float)0.0);
HXLINE(  49)		this->set__41(((Float)0.0));
HXDLIN(  49)		this->set__42(((Float)0.0));
HXDLIN(  49)		this->_43 = ((Float)0.0);
HXDLIN(  49)		this->_44 = ((Float)1.0);
            	}


HX_DEFINE_DYNAMIC_FUNC0(FeshMatrix4x4_obj,initIdentity,(void))

void FeshMatrix4x4_obj::scale4x3(Float scaleX,Float scaleY,::hx::Null< Float >  __o_scaleZ){
            		Float scaleZ = __o_scaleZ.Default(1);
            	HX_GC_STACKFRAME(&_hx_pos_23a9d83b11245a9e_52_scale4x3)
HXLINE(  53)		 ::feshixl::math::FeshMatrix4x4 temp =  ::feshixl::math::FeshMatrix4x4_obj::__alloc( HX_CTX );
HXLINE(  54)		temp->initScale(scaleX,scaleY,scaleZ);
HXLINE(  55)		this->multiplyBy(temp);
            	}


HX_DEFINE_DYNAMIC_FUNC3(FeshMatrix4x4_obj,scale4x3,(void))

void FeshMatrix4x4_obj::translate4x3(Float x,Float y,::hx::Null< Float >  __o_z){
            		Float z = __o_z.Default(0);
            	HX_STACKFRAME(&_hx_pos_23a9d83b11245a9e_58_translate4x3)
HXLINE(  59)		Float _hx_tmp = this->get__11();
HXDLIN(  59)		this->set__11((_hx_tmp + (x * this->_14)));
HXLINE(  60)		Float _hx_tmp1 = this->get__12();
HXDLIN(  60)		this->set__12((_hx_tmp1 + (y * this->_14)));
HXLINE(  61)		 ::feshixl::math::FeshMatrix4x4 _hx_tmp2 = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN(  61)		_hx_tmp2->_13 = (_hx_tmp2->_13 + (z * this->_14));
HXLINE(  63)		Float _hx_tmp3 = this->get__21();
HXDLIN(  63)		this->set__21((_hx_tmp3 + (x * this->_24)));
HXLINE(  64)		Float _hx_tmp4 = this->get__22();
HXDLIN(  64)		this->set__22((_hx_tmp4 + (y * this->_24)));
HXLINE(  65)		 ::feshixl::math::FeshMatrix4x4 _hx_tmp5 = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN(  65)		_hx_tmp5->_23 = (_hx_tmp5->_23 + (z * this->_24));
HXLINE(  67)		 ::feshixl::math::FeshMatrix4x4 _hx_tmp6 = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN(  67)		_hx_tmp6->_31 = (_hx_tmp6->_31 + (x * this->_34));
HXLINE(  68)		 ::feshixl::math::FeshMatrix4x4 _hx_tmp7 = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN(  68)		_hx_tmp7->_32 = (_hx_tmp7->_32 + (y * this->_34));
HXLINE(  69)		 ::feshixl::math::FeshMatrix4x4 _hx_tmp8 = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN(  69)		_hx_tmp8->_33 = (_hx_tmp8->_33 + (z * this->_34));
HXLINE(  71)		Float _hx_tmp9 = this->get__41();
HXDLIN(  71)		this->set__41((_hx_tmp9 + (x * this->_44)));
HXLINE(  72)		Float _hx_tmp10 = this->get__42();
HXDLIN(  72)		this->set__42((_hx_tmp10 + (y * this->_44)));
HXLINE(  73)		 ::feshixl::math::FeshMatrix4x4 _hx_tmp11 = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN(  73)		_hx_tmp11->_43 = (_hx_tmp11->_43 + (z * this->_44));
            	}


HX_DEFINE_DYNAMIC_FUNC3(FeshMatrix4x4_obj,translate4x3,(void))

void FeshMatrix4x4_obj::multiplyBy( ::feshixl::math::FeshMatrix4x4 b){
            	HX_STACKFRAME(&_hx_pos_23a9d83b11245a9e_77_multiplyBy)
HXLINE(  78)		Float a11 = this->get__11();
HXDLIN(  78)		Float a12 = this->get__12();
HXDLIN(  78)		Float a13 = this->_13;
HXDLIN(  78)		Float a14 = this->_14;
HXLINE(  79)		Float a21 = this->get__21();
HXDLIN(  79)		Float a22 = this->get__22();
HXDLIN(  79)		Float a23 = this->_23;
HXDLIN(  79)		Float a24 = this->_24;
HXLINE(  80)		Float a31 = this->_31;
HXDLIN(  80)		Float a32 = this->_32;
HXDLIN(  80)		Float a33 = this->_33;
HXDLIN(  80)		Float a34 = this->_34;
HXLINE(  81)		Float a41 = this->get__41();
HXDLIN(  81)		Float a42 = this->get__42();
HXDLIN(  81)		Float a43 = this->_43;
HXDLIN(  81)		Float a44 = this->_44;
HXLINE(  82)		Float b11 = b->get__11();
HXDLIN(  82)		Float b12 = b->get__12();
HXDLIN(  82)		Float b13 = b->_13;
HXDLIN(  82)		Float b14 = b->_14;
HXLINE(  83)		Float b21 = b->get__21();
HXDLIN(  83)		Float b22 = b->get__22();
HXDLIN(  83)		Float b23 = b->_23;
HXDLIN(  83)		Float b24 = b->_24;
HXLINE(  84)		Float b31 = b->_31;
HXDLIN(  84)		Float b32 = b->_32;
HXDLIN(  84)		Float b33 = b->_33;
HXDLIN(  84)		Float b34 = b->_34;
HXLINE(  85)		Float b41 = b->get__41();
HXDLIN(  85)		Float b42 = b->get__42();
HXDLIN(  85)		Float b43 = b->_43;
HXDLIN(  85)		Float b44 = b->_44;
HXLINE(  87)		this->set__11(((((a11 * b11) + (a12 * b21)) + (a13 * b31)) + (a14 * b41)));
HXLINE(  88)		this->set__12(((((a11 * b12) + (a12 * b22)) + (a13 * b32)) + (a14 * b42)));
HXLINE(  89)		this->_13 = ((((a11 * b13) + (a12 * b23)) + (a13 * b33)) + (a14 * b43));
HXLINE(  90)		this->_14 = ((((a11 * b14) + (a12 * b24)) + (a13 * b34)) + (a14 * b44));
HXLINE(  92)		this->set__21(((((a21 * b11) + (a22 * b21)) + (a23 * b31)) + (a24 * b41)));
HXLINE(  93)		this->set__22(((((a21 * b12) + (a22 * b22)) + (a23 * b32)) + (a24 * b42)));
HXLINE(  94)		this->_23 = ((((a21 * b13) + (a22 * b23)) + (a23 * b33)) + (a24 * b43));
HXLINE(  95)		this->_24 = ((((a21 * b14) + (a22 * b24)) + (a23 * b34)) + (a24 * b44));
HXLINE(  97)		this->_31 = ((((a31 * b11) + (a32 * b21)) + (a33 * b31)) + (a34 * b41));
HXLINE(  98)		this->_32 = ((((a31 * b12) + (a32 * b22)) + (a33 * b32)) + (a34 * b42));
HXLINE(  99)		this->_33 = ((((a31 * b13) + (a32 * b23)) + (a33 * b33)) + (a34 * b43));
HXLINE( 100)		this->_34 = ((((a31 * b14) + (a32 * b24)) + (a33 * b34)) + (a34 * b44));
HXLINE( 102)		this->set__41(((((a41 * b11) + (a42 * b21)) + (a43 * b31)) + (a44 * b41)));
HXLINE( 103)		this->set__42(((((a41 * b12) + (a42 * b22)) + (a43 * b32)) + (a44 * b42)));
HXLINE( 104)		this->_43 = ((((a41 * b13) + (a42 * b23)) + (a43 * b33)) + (a44 * b43));
HXLINE( 105)		this->_44 = ((((a41 * b14) + (a42 * b24)) + (a43 * b34)) + (a44 * b44));
            	}


HX_DEFINE_DYNAMIC_FUNC1(FeshMatrix4x4_obj,multiplyBy,(void))

void FeshMatrix4x4_obj::multiplyValues(Float v){
            	HX_STACKFRAME(&_hx_pos_23a9d83b11245a9e_108_multiplyValues)
HXLINE( 109)		this->set__11((this->get__11() * v));
HXLINE( 110)		this->set__12((this->get__12() * v));
HXLINE( 111)		 ::feshixl::math::FeshMatrix4x4 _hx_tmp = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN( 111)		_hx_tmp->_13 = (_hx_tmp->_13 * v);
HXLINE( 112)		 ::feshixl::math::FeshMatrix4x4 _hx_tmp1 = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN( 112)		_hx_tmp1->_14 = (_hx_tmp1->_14 * v);
HXLINE( 114)		this->set__21((this->get__21() * v));
HXLINE( 115)		this->set__22((this->get__22() * v));
HXLINE( 116)		 ::feshixl::math::FeshMatrix4x4 _hx_tmp2 = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN( 116)		_hx_tmp2->_23 = (_hx_tmp2->_23 * v);
HXLINE( 117)		 ::feshixl::math::FeshMatrix4x4 _hx_tmp3 = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN( 117)		_hx_tmp3->_24 = (_hx_tmp3->_24 * v);
HXLINE( 119)		 ::feshixl::math::FeshMatrix4x4 _hx_tmp4 = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN( 119)		_hx_tmp4->_31 = (_hx_tmp4->_31 * v);
HXLINE( 120)		 ::feshixl::math::FeshMatrix4x4 _hx_tmp5 = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN( 120)		_hx_tmp5->_32 = (_hx_tmp5->_32 * v);
HXLINE( 121)		 ::feshixl::math::FeshMatrix4x4 _hx_tmp6 = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN( 121)		_hx_tmp6->_33 = (_hx_tmp6->_33 * v);
HXLINE( 122)		 ::feshixl::math::FeshMatrix4x4 _hx_tmp7 = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN( 122)		_hx_tmp7->_34 = (_hx_tmp7->_34 * v);
HXLINE( 124)		this->set__41((this->get__41() * v));
HXLINE( 125)		this->set__42((this->get__42() * v));
HXLINE( 126)		 ::feshixl::math::FeshMatrix4x4 _hx_tmp8 = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN( 126)		_hx_tmp8->_43 = (_hx_tmp8->_43 * v);
HXLINE( 127)		 ::feshixl::math::FeshMatrix4x4 _hx_tmp9 = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN( 127)		_hx_tmp9->_44 = (_hx_tmp9->_44 * v);
            	}


HX_DEFINE_DYNAMIC_FUNC1(FeshMatrix4x4_obj,multiplyValues,(void))

 ::feshixl::math::FeshMatrix4x4 FeshMatrix4x4_obj::invert4x4( ::feshixl::math::FeshMatrix4x4 m){
            	HX_STACKFRAME(&_hx_pos_23a9d83b11245a9e_130_invert4x4)
HXLINE( 131)		Float m11 = m->get__11();
HXDLIN( 131)		Float m12 = m->get__12();
HXDLIN( 131)		Float m13 = m->_13;
HXDLIN( 131)		Float m14 = m->_14;
HXLINE( 132)		Float m21 = m->get__21();
HXDLIN( 132)		Float m22 = m->get__22();
HXDLIN( 132)		Float m23 = m->_23;
HXDLIN( 132)		Float m24 = m->_24;
HXLINE( 133)		Float m31 = m->_31;
HXDLIN( 133)		Float m32 = m->_32;
HXDLIN( 133)		Float m33 = m->_33;
HXDLIN( 133)		Float m34 = m->_34;
HXLINE( 134)		Float m41 = m->get__41();
HXDLIN( 134)		Float m42 = m->get__42();
HXDLIN( 134)		Float m43 = m->_43;
HXDLIN( 134)		Float m44 = m->_44;
HXLINE( 136)		this->set__11((((((((m22 * m33) * m44) - ((m22 * m34) * m43)) - ((m32 * m23) * m44)) + ((m32 * m24) * m43)) + ((m42 * m23) * m34)) - ((m42 * m24) * m33)));
HXLINE( 137)		this->set__12((((((((-(m12) * m33) * m44) + ((m12 * m34) * m43)) + ((m32 * m13) * m44)) - ((m32 * m14) * m43)) - ((m42 * m13) * m34)) + ((m42 * m14) * m33)));
HXLINE( 138)		this->_13 = (((((((m12 * m23) * m44) - ((m12 * m24) * m43)) - ((m22 * m13) * m44)) + ((m22 * m14) * m43)) + ((m42 * m13) * m24)) - ((m42 * m14) * m23));
HXLINE( 139)		this->_14 = (((((((-(m12) * m23) * m34) + ((m12 * m24) * m33)) + ((m22 * m13) * m34)) - ((m22 * m14) * m33)) - ((m32 * m13) * m24)) + ((m32 * m14) * m23));
HXLINE( 141)		this->set__21((((((((-(m21) * m33) * m44) + ((m21 * m34) * m43)) + ((m31 * m23) * m44)) - ((m31 * m24) * m43)) - ((m41 * m23) * m34)) + ((m41 * m24) * m33)));
HXLINE( 142)		this->set__22((((((((m11 * m33) * m44) - ((m11 * m34) * m43)) - ((m31 * m13) * m44)) + ((m31 * m14) * m43)) + ((m41 * m13) * m34)) - ((m41 * m14) * m33)));
HXLINE( 143)		this->_23 = (((((((-(m11) * m23) * m44) + ((m11 * m24) * m43)) + ((m21 * m13) * m44)) - ((m21 * m14) * m43)) - ((m41 * m13) * m24)) + ((m41 * m14) * m23));
HXLINE( 144)		this->_24 = (((((((m11 * m23) * m34) - ((m11 * m24) * m33)) - ((m21 * m13) * m34)) + ((m21 * m14) * m33)) + ((m31 * m13) * m24)) - ((m31 * m14) * m23));
HXLINE( 146)		this->_31 = (((((((m21 * m32) * m44) - ((m21 * m34) * m42)) - ((m31 * m22) * m44)) + ((m31 * m24) * m42)) + ((m41 * m22) * m34)) - ((m41 * m24) * m32));
HXLINE( 147)		this->_32 = (((((((-(m11) * m32) * m44) + ((m11 * m34) * m42)) + ((m31 * m12) * m44)) - ((m31 * m14) * m42)) - ((m41 * m12) * m34)) + ((m41 * m14) * m32));
HXLINE( 148)		this->_33 = (((((((m11 * m22) * m44) - ((m11 * m24) * m42)) - ((m21 * m12) * m44)) + ((m21 * m14) * m42)) + ((m41 * m12) * m24)) - ((m41 * m14) * m22));
HXLINE( 149)		this->_34 = (((((((-(m11) * m22) * m34) + ((m11 * m24) * m32)) + ((m21 * m12) * m34)) - ((m21 * m14) * m32)) - ((m31 * m12) * m24)) + ((m31 * m14) * m22));
HXLINE( 151)		this->set__41((((((((-(m21) * m32) * m43) + ((m21 * m33) * m42)) + ((m31 * m22) * m43)) - ((m31 * m23) * m42)) - ((m41 * m22) * m33)) + ((m41 * m23) * m32)));
HXLINE( 152)		this->set__42((((((((m11 * m32) * m43) - ((m11 * m33) * m42)) - ((m31 * m12) * m43)) + ((m31 * m13) * m42)) + ((m41 * m12) * m33)) - ((m41 * m13) * m32)));
HXLINE( 153)		this->_43 = (((((((-(m11) * m22) * m43) + ((m11 * m23) * m42)) + ((m21 * m12) * m43)) - ((m21 * m13) * m42)) - ((m41 * m12) * m23)) + ((m41 * m13) * m22));
HXLINE( 154)		this->_44 = (((((((m11 * m22) * m33) - ((m11 * m23) * m32)) - ((m21 * m12) * m33)) + ((m21 * m13) * m32)) + ((m31 * m12) * m23)) - ((m31 * m13) * m22));
HXLINE( 156)		Float det = (m11 * this->get__11());
HXDLIN( 156)		Float det1 = (det + (m12 * this->get__21()));
HXDLIN( 156)		Float det2 = (det1 + (m13 * this->_31));
HXDLIN( 156)		Float det3 = (det2 + (m14 * this->get__41()));
HXLINE( 158)		if ((::Math_obj::abs(det3) > ((Float)0.0000001))) {
HXLINE( 159)			det3 = (((Float)1.0) / det3);
            		}
            		else {
HXLINE( 161)			det3 = ( (Float)(0) );
            		}
HXLINE( 164)		this->multiplyValues(det3);
HXLINE( 165)		return ::hx::ObjectPtr<OBJ_>(this);
            	}


HX_DEFINE_DYNAMIC_FUNC1(FeshMatrix4x4_obj,invert4x4,return )

Float FeshMatrix4x4_obj::get__11(){
            	HX_STACKFRAME(&_hx_pos_23a9d83b11245a9e_169_get__11)
HXDLIN( 169)		return this->a;
            	}


HX_DEFINE_DYNAMIC_FUNC0(FeshMatrix4x4_obj,get__11,return )

Float FeshMatrix4x4_obj::set__11(Float v){
            	HX_STACKFRAME(&_hx_pos_23a9d83b11245a9e_173_set__11)
HXDLIN( 173)		return (this->a = v);
            	}


HX_DEFINE_DYNAMIC_FUNC1(FeshMatrix4x4_obj,set__11,return )

Float FeshMatrix4x4_obj::get__21(){
            	HX_STACKFRAME(&_hx_pos_23a9d83b11245a9e_177_get__21)
HXDLIN( 177)		return this->b;
            	}


HX_DEFINE_DYNAMIC_FUNC0(FeshMatrix4x4_obj,get__21,return )

Float FeshMatrix4x4_obj::set__21(Float v){
            	HX_STACKFRAME(&_hx_pos_23a9d83b11245a9e_181_set__21)
HXDLIN( 181)		return (this->b = v);
            	}


HX_DEFINE_DYNAMIC_FUNC1(FeshMatrix4x4_obj,set__21,return )

Float FeshMatrix4x4_obj::get__12(){
            	HX_STACKFRAME(&_hx_pos_23a9d83b11245a9e_185_get__12)
HXDLIN( 185)		return this->c;
            	}


HX_DEFINE_DYNAMIC_FUNC0(FeshMatrix4x4_obj,get__12,return )

Float FeshMatrix4x4_obj::set__12(Float v){
            	HX_STACKFRAME(&_hx_pos_23a9d83b11245a9e_189_set__12)
HXDLIN( 189)		return (this->c = v);
            	}


HX_DEFINE_DYNAMIC_FUNC1(FeshMatrix4x4_obj,set__12,return )

Float FeshMatrix4x4_obj::get__22(){
            	HX_STACKFRAME(&_hx_pos_23a9d83b11245a9e_193_get__22)
HXDLIN( 193)		return this->d;
            	}


HX_DEFINE_DYNAMIC_FUNC0(FeshMatrix4x4_obj,get__22,return )

Float FeshMatrix4x4_obj::set__22(Float v){
            	HX_STACKFRAME(&_hx_pos_23a9d83b11245a9e_197_set__22)
HXDLIN( 197)		return (this->d = v);
            	}


HX_DEFINE_DYNAMIC_FUNC1(FeshMatrix4x4_obj,set__22,return )

Float FeshMatrix4x4_obj::get__41(){
            	HX_STACKFRAME(&_hx_pos_23a9d83b11245a9e_201_get__41)
HXDLIN( 201)		return this->tx;
            	}


HX_DEFINE_DYNAMIC_FUNC0(FeshMatrix4x4_obj,get__41,return )

Float FeshMatrix4x4_obj::set__41(Float v){
            	HX_STACKFRAME(&_hx_pos_23a9d83b11245a9e_205_set__41)
HXDLIN( 205)		return (this->tx = v);
            	}


HX_DEFINE_DYNAMIC_FUNC1(FeshMatrix4x4_obj,set__41,return )

Float FeshMatrix4x4_obj::get__42(){
            	HX_STACKFRAME(&_hx_pos_23a9d83b11245a9e_209_get__42)
HXDLIN( 209)		return this->ty;
            	}


HX_DEFINE_DYNAMIC_FUNC0(FeshMatrix4x4_obj,get__42,return )

Float FeshMatrix4x4_obj::set__42(Float v){
            	HX_STACKFRAME(&_hx_pos_23a9d83b11245a9e_213_set__42)
HXDLIN( 213)		return (this->ty = v);
            	}


HX_DEFINE_DYNAMIC_FUNC1(FeshMatrix4x4_obj,set__42,return )


::hx::ObjectPtr< FeshMatrix4x4_obj > FeshMatrix4x4_obj::__new() {
	::hx::ObjectPtr< FeshMatrix4x4_obj > __this = new FeshMatrix4x4_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< FeshMatrix4x4_obj > FeshMatrix4x4_obj::__alloc(::hx::Ctx *_hx_ctx) {
	FeshMatrix4x4_obj *__this = (FeshMatrix4x4_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(FeshMatrix4x4_obj), true, "feshixl.math.FeshMatrix4x4"));
	*(void **)__this = FeshMatrix4x4_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

FeshMatrix4x4_obj::FeshMatrix4x4_obj()
{
}

::hx::Val FeshMatrix4x4_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_11") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get__11() ); }
		if (HX_FIELD_EQ(inName,"_12") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get__12() ); }
		if (HX_FIELD_EQ(inName,"_13") ) { return ::hx::Val( _13 ); }
		if (HX_FIELD_EQ(inName,"_14") ) { return ::hx::Val( _14 ); }
		if (HX_FIELD_EQ(inName,"_21") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get__21() ); }
		if (HX_FIELD_EQ(inName,"_22") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get__22() ); }
		if (HX_FIELD_EQ(inName,"_23") ) { return ::hx::Val( _23 ); }
		if (HX_FIELD_EQ(inName,"_24") ) { return ::hx::Val( _24 ); }
		if (HX_FIELD_EQ(inName,"_31") ) { return ::hx::Val( _31 ); }
		if (HX_FIELD_EQ(inName,"_32") ) { return ::hx::Val( _32 ); }
		if (HX_FIELD_EQ(inName,"_33") ) { return ::hx::Val( _33 ); }
		if (HX_FIELD_EQ(inName,"_34") ) { return ::hx::Val( _34 ); }
		if (HX_FIELD_EQ(inName,"_41") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get__41() ); }
		if (HX_FIELD_EQ(inName,"_42") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get__42() ); }
		if (HX_FIELD_EQ(inName,"_43") ) { return ::hx::Val( _43 ); }
		if (HX_FIELD_EQ(inName,"_44") ) { return ::hx::Val( _44 ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"get__11") ) { return ::hx::Val( get__11_dyn() ); }
		if (HX_FIELD_EQ(inName,"set__11") ) { return ::hx::Val( set__11_dyn() ); }
		if (HX_FIELD_EQ(inName,"get__21") ) { return ::hx::Val( get__21_dyn() ); }
		if (HX_FIELD_EQ(inName,"set__21") ) { return ::hx::Val( set__21_dyn() ); }
		if (HX_FIELD_EQ(inName,"get__12") ) { return ::hx::Val( get__12_dyn() ); }
		if (HX_FIELD_EQ(inName,"set__12") ) { return ::hx::Val( set__12_dyn() ); }
		if (HX_FIELD_EQ(inName,"get__22") ) { return ::hx::Val( get__22_dyn() ); }
		if (HX_FIELD_EQ(inName,"set__22") ) { return ::hx::Val( set__22_dyn() ); }
		if (HX_FIELD_EQ(inName,"get__41") ) { return ::hx::Val( get__41_dyn() ); }
		if (HX_FIELD_EQ(inName,"set__41") ) { return ::hx::Val( set__41_dyn() ); }
		if (HX_FIELD_EQ(inName,"get__42") ) { return ::hx::Val( get__42_dyn() ); }
		if (HX_FIELD_EQ(inName,"set__42") ) { return ::hx::Val( set__42_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"scale4x3") ) { return ::hx::Val( scale4x3_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"initScale") ) { return ::hx::Val( initScale_dyn() ); }
		if (HX_FIELD_EQ(inName,"invert4x4") ) { return ::hx::Val( invert4x4_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"multiplyBy") ) { return ::hx::Val( multiplyBy_dyn() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"initIdentity") ) { return ::hx::Val( initIdentity_dyn() ); }
		if (HX_FIELD_EQ(inName,"translate4x3") ) { return ::hx::Val( translate4x3_dyn() ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"multiplyValues") ) { return ::hx::Val( multiplyValues_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val FeshMatrix4x4_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_11") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set__11(inValue.Cast< Float >()) ); }
		if (HX_FIELD_EQ(inName,"_12") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set__12(inValue.Cast< Float >()) ); }
		if (HX_FIELD_EQ(inName,"_13") ) { _13=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_14") ) { _14=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_21") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set__21(inValue.Cast< Float >()) ); }
		if (HX_FIELD_EQ(inName,"_22") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set__22(inValue.Cast< Float >()) ); }
		if (HX_FIELD_EQ(inName,"_23") ) { _23=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_24") ) { _24=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_31") ) { _31=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_32") ) { _32=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_33") ) { _33=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_34") ) { _34=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_41") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set__41(inValue.Cast< Float >()) ); }
		if (HX_FIELD_EQ(inName,"_42") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set__42(inValue.Cast< Float >()) ); }
		if (HX_FIELD_EQ(inName,"_43") ) { _43=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_44") ) { _44=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FeshMatrix4x4_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("_11",ff,40,48,00));
	outFields->push(HX_("_12",00,41,48,00));
	outFields->push(HX_("_13",01,41,48,00));
	outFields->push(HX_("_14",02,41,48,00));
	outFields->push(HX_("_21",de,41,48,00));
	outFields->push(HX_("_22",df,41,48,00));
	outFields->push(HX_("_23",e0,41,48,00));
	outFields->push(HX_("_24",e1,41,48,00));
	outFields->push(HX_("_31",bd,42,48,00));
	outFields->push(HX_("_32",be,42,48,00));
	outFields->push(HX_("_33",bf,42,48,00));
	outFields->push(HX_("_34",c0,42,48,00));
	outFields->push(HX_("_41",9c,43,48,00));
	outFields->push(HX_("_42",9d,43,48,00));
	outFields->push(HX_("_43",9e,43,48,00));
	outFields->push(HX_("_44",9f,43,48,00));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo FeshMatrix4x4_obj_sMemberStorageInfo[] = {
	{::hx::fsFloat,(int)offsetof(FeshMatrix4x4_obj,_13),HX_("_13",01,41,48,00)},
	{::hx::fsFloat,(int)offsetof(FeshMatrix4x4_obj,_14),HX_("_14",02,41,48,00)},
	{::hx::fsFloat,(int)offsetof(FeshMatrix4x4_obj,_23),HX_("_23",e0,41,48,00)},
	{::hx::fsFloat,(int)offsetof(FeshMatrix4x4_obj,_24),HX_("_24",e1,41,48,00)},
	{::hx::fsFloat,(int)offsetof(FeshMatrix4x4_obj,_31),HX_("_31",bd,42,48,00)},
	{::hx::fsFloat,(int)offsetof(FeshMatrix4x4_obj,_32),HX_("_32",be,42,48,00)},
	{::hx::fsFloat,(int)offsetof(FeshMatrix4x4_obj,_33),HX_("_33",bf,42,48,00)},
	{::hx::fsFloat,(int)offsetof(FeshMatrix4x4_obj,_34),HX_("_34",c0,42,48,00)},
	{::hx::fsFloat,(int)offsetof(FeshMatrix4x4_obj,_43),HX_("_43",9e,43,48,00)},
	{::hx::fsFloat,(int)offsetof(FeshMatrix4x4_obj,_44),HX_("_44",9f,43,48,00)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *FeshMatrix4x4_obj_sStaticStorageInfo = 0;
#endif

static ::String FeshMatrix4x4_obj_sMemberFields[] = {
	HX_("_13",01,41,48,00),
	HX_("_14",02,41,48,00),
	HX_("_23",e0,41,48,00),
	HX_("_24",e1,41,48,00),
	HX_("_31",bd,42,48,00),
	HX_("_32",be,42,48,00),
	HX_("_33",bf,42,48,00),
	HX_("_34",c0,42,48,00),
	HX_("_43",9e,43,48,00),
	HX_("_44",9f,43,48,00),
	HX_("initScale",5a,e9,60,94),
	HX_("initIdentity",6e,cc,e5,5d),
	HX_("scale4x3",a5,41,45,01),
	HX_("translate4x3",61,0b,77,c0),
	HX_("multiplyBy",1b,ed,24,01),
	HX_("multiplyValues",26,8d,b2,5b),
	HX_("invert4x4",9a,08,24,96),
	HX_("get__11",96,09,bd,26),
	HX_("set__11",a2,9a,be,19),
	HX_("get__21",75,0a,bd,26),
	HX_("set__21",81,9b,be,19),
	HX_("get__12",97,09,bd,26),
	HX_("set__12",a3,9a,be,19),
	HX_("get__22",76,0a,bd,26),
	HX_("set__22",82,9b,be,19),
	HX_("get__41",33,0c,bd,26),
	HX_("set__41",3f,9d,be,19),
	HX_("get__42",34,0c,bd,26),
	HX_("set__42",40,9d,be,19),
	::String(null()) };

::hx::Class FeshMatrix4x4_obj::__mClass;

void FeshMatrix4x4_obj::__register()
{
	FeshMatrix4x4_obj _hx_dummy;
	FeshMatrix4x4_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("feshixl.math.FeshMatrix4x4",9a,21,ab,22);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(FeshMatrix4x4_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< FeshMatrix4x4_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = FeshMatrix4x4_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = FeshMatrix4x4_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace feshixl
} // end namespace math
