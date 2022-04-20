#ifndef INCLUDED_hxjsonast_Position
#define INCLUDED_hxjsonast_Position

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_STACK_FRAME(_hx_pos_2271147a67414103_26_new)
HX_DECLARE_CLASS1(hxjsonast,Position)

namespace hxjsonast{


class HXCPP_CLASS_ATTRIBUTES Position_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef Position_obj OBJ_;
		Position_obj();

	public:
		enum { _hx_ClassId = 0x6ee9f253 };

		void __construct(::String file,int min,int max);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="hxjsonast.Position")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"hxjsonast.Position"); }

		inline static ::hx::ObjectPtr< Position_obj > __new(::String file,int min,int max) {
			::hx::ObjectPtr< Position_obj > __this = new Position_obj();
			__this->__construct(file,min,max);
			return __this;
		}

		inline static ::hx::ObjectPtr< Position_obj > __alloc(::hx::Ctx *_hx_ctx,::String file,int min,int max) {
			Position_obj *__this = (Position_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Position_obj), true, "hxjsonast.Position"));
			*(void **)__this = Position_obj::_hx_vtable;
{
            	HX_STACKFRAME(&_hx_pos_2271147a67414103_26_new)
HXLINE(  27)		( ( ::hxjsonast::Position)(__this) )->file = file;
HXLINE(  28)		( ( ::hxjsonast::Position)(__this) )->min = min;
HXLINE(  29)		( ( ::hxjsonast::Position)(__this) )->max = max;
            	}
		
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Position_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Position",c9,5c,ac,a4); }

		::String file;
		int min;
		int max;
};

} // end namespace hxjsonast

#endif /* INCLUDED_hxjsonast_Position */ 
