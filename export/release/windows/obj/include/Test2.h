#ifndef INCLUDED_Test2
#define INCLUDED_Test2

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_Test1
#include <Test1.h>
#endif
HX_DECLARE_STACK_FRAME(_hx_pos_86e19373cd85c608_13_new)
HX_DECLARE_CLASS0(Test1)
HX_DECLARE_CLASS0(Test2)



class HXCPP_CLASS_ATTRIBUTES Test2_obj : public  ::Test1_obj
{
	public:
		typedef  ::Test1_obj super;
		typedef Test2_obj OBJ_;
		Test2_obj();

	public:
		enum { _hx_ClassId = 0x3d52c4c0 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="Test2")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"Test2"); }

		inline static ::hx::ObjectPtr< Test2_obj > __new() {
			::hx::ObjectPtr< Test2_obj > __this = new Test2_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< Test2_obj > __alloc(::hx::Ctx *_hx_ctx) {
			Test2_obj *__this = (Test2_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Test2_obj), false, "Test2"));
			*(void **)__this = Test2_obj::_hx_vtable;
{
            	HX_STACKFRAME(&_hx_pos_86e19373cd85c608_13_new)
HXDLIN(  13)		__this->super::__construct();
            	}
		
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Test2_obj();

		HX_DO_RTTI_ALL;
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Test2",80,ef,c2,a0); }

};


#endif /* INCLUDED_Test2 */ 
