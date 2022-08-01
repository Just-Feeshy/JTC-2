#ifndef INCLUDED_feshixl_math_FeshMatrix4x4
#define INCLUDED_feshixl_math_FeshMatrix4x4

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_flixel_math_FlxMatrix
#include <flixel/math/FlxMatrix.h>
#endif
HX_DECLARE_CLASS2(feshixl,math,FeshMatrix4x4)
HX_DECLARE_CLASS2(flixel,math,FlxMatrix)
HX_DECLARE_CLASS2(openfl,geom,Matrix)

namespace feshixl{
namespace math{


class HXCPP_CLASS_ATTRIBUTES FeshMatrix4x4_obj : public  ::flixel::math::FlxMatrix_obj
{
	public:
		typedef  ::flixel::math::FlxMatrix_obj super;
		typedef FeshMatrix4x4_obj OBJ_;
		FeshMatrix4x4_obj();

	public:
		enum { _hx_ClassId = 0x24edc2ae };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="feshixl.math.FeshMatrix4x4")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"feshixl.math.FeshMatrix4x4"); }
		static ::hx::ObjectPtr< FeshMatrix4x4_obj > __new();
		static ::hx::ObjectPtr< FeshMatrix4x4_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~FeshMatrix4x4_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("FeshMatrix4x4",fb,97,02,55); }

		Float _13;
		Float _14;
		Float _23;
		Float _24;
		Float _31;
		Float _32;
		Float _33;
		Float _34;
		Float _43;
		Float _44;
		void initScale(::hx::Null< Float >  scaleX,::hx::Null< Float >  scaleY,::hx::Null< Float >  scaleZ);
		::Dynamic initScale_dyn();

		void initIdentity();
		::Dynamic initIdentity_dyn();

		void scale4x3(Float scaleX,Float scaleY,::hx::Null< Float >  scaleZ);
		::Dynamic scale4x3_dyn();

		void translate4x3(Float x,Float y,::hx::Null< Float >  z);
		::Dynamic translate4x3_dyn();

		void multiplyBy( ::feshixl::math::FeshMatrix4x4 b);
		::Dynamic multiplyBy_dyn();

		void multiplyValues(Float v);
		::Dynamic multiplyValues_dyn();

		 ::feshixl::math::FeshMatrix4x4 invert4x4( ::feshixl::math::FeshMatrix4x4 m);
		::Dynamic invert4x4_dyn();

		Float get__11();
		::Dynamic get__11_dyn();

		Float set__11(Float v);
		::Dynamic set__11_dyn();

		Float get__21();
		::Dynamic get__21_dyn();

		Float set__21(Float v);
		::Dynamic set__21_dyn();

		Float get__12();
		::Dynamic get__12_dyn();

		Float set__12(Float v);
		::Dynamic set__12_dyn();

		Float get__22();
		::Dynamic get__22_dyn();

		Float set__22(Float v);
		::Dynamic set__22_dyn();

		Float get__41();
		::Dynamic get__41_dyn();

		Float set__41(Float v);
		::Dynamic set__41_dyn();

		Float get__42();
		::Dynamic get__42_dyn();

		Float set__42(Float v);
		::Dynamic set__42_dyn();

};

} // end namespace feshixl
} // end namespace math

#endif /* INCLUDED_feshixl_math_FeshMatrix4x4 */ 
