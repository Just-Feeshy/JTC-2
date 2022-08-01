#ifndef INCLUDED_feshixl_math_FeshMatrix3x3
#define INCLUDED_feshixl_math_FeshMatrix3x3

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_flixel_math_FlxMatrix
#include <flixel/math/FlxMatrix.h>
#endif
HX_DECLARE_CLASS2(feshixl,math,FeshMatrix3x3)
HX_DECLARE_CLASS2(flixel,math,FlxMatrix)
HX_DECLARE_CLASS2(openfl,geom,Matrix)

namespace feshixl{
namespace math{


class HXCPP_CLASS_ATTRIBUTES FeshMatrix3x3_obj : public  ::flixel::math::FlxMatrix_obj
{
	public:
		typedef  ::flixel::math::FlxMatrix_obj super;
		typedef FeshMatrix3x3_obj OBJ_;
		FeshMatrix3x3_obj();

	public:
		enum { _hx_ClassId = 0x24ed006c };

		void __construct( ::Dynamic a, ::Dynamic b, ::Dynamic c, ::Dynamic d, ::Dynamic tx, ::Dynamic ty);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="feshixl.math.FeshMatrix3x3")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"feshixl.math.FeshMatrix3x3"); }
		static ::hx::ObjectPtr< FeshMatrix3x3_obj > __new( ::Dynamic a, ::Dynamic b, ::Dynamic c, ::Dynamic d, ::Dynamic tx, ::Dynamic ty);
		static ::hx::ObjectPtr< FeshMatrix3x3_obj > __alloc(::hx::Ctx *_hx_ctx, ::Dynamic a, ::Dynamic b, ::Dynamic c, ::Dynamic d, ::Dynamic tx, ::Dynamic ty);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~FeshMatrix3x3_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("FeshMatrix3x3",b9,d5,01,55); }

		void rotateWithTrig3D(Float thetaX,Float thetaY,Float thetaZ,::hx::Null< Float >  z,::hx::Null< bool >  hasPerspective);
		::Dynamic rotateWithTrig3D_dyn();

};

} // end namespace feshixl
} // end namespace math

#endif /* INCLUDED_feshixl_math_FeshMatrix3x3 */ 
