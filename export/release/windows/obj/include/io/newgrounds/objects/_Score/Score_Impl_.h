#ifndef INCLUDED_io_newgrounds_objects__Score_Score_Impl_
#define INCLUDED_io_newgrounds_objects__Score_Score_Impl_

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(io,newgrounds,objects,_Score,Score_Impl_)

namespace io{
namespace newgrounds{
namespace objects{
namespace _Score{


class HXCPP_CLASS_ATTRIBUTES Score_Impl__obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef Score_Impl__obj OBJ_;
		Score_Impl__obj();

	public:
		enum { _hx_ClassId = 0x5c1f387d };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="io.newgrounds.objects._Score.Score_Impl_")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"io.newgrounds.objects._Score.Score_Impl_"); }

		inline static ::hx::ObjectPtr< Score_Impl__obj > __new() {
			::hx::ObjectPtr< Score_Impl__obj > __this = new Score_Impl__obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< Score_Impl__obj > __alloc(::hx::Ctx *_hx_ctx) {
			Score_Impl__obj *__this = (Score_Impl__obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Score_Impl__obj), false, "io.newgrounds.objects._Score.Score_Impl_"));
			*(void **)__this = Score_Impl__obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Score_Impl__obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Score_Impl_",52,91,8d,c8); }

		static ::String get_formatted_value( ::Dynamic this1);
		static ::Dynamic get_formatted_value_dyn();

		static ::String get_formattedValue( ::Dynamic this1);
		static ::Dynamic get_formattedValue_dyn();

};

} // end namespace io
} // end namespace newgrounds
} // end namespace objects
} // end namespace _Score

#endif /* INCLUDED_io_newgrounds_objects__Score_Score_Impl_ */ 
