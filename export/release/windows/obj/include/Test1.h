#ifndef INCLUDED_Test1
#define INCLUDED_Test1

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Test1)



class HXCPP_CLASS_ATTRIBUTES Test1_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef Test1_obj OBJ_;
		Test1_obj();

	public:
		enum { _hx_ClassId = 0x3d52c4bf };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="Test1")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"Test1"); }
		static ::hx::ObjectPtr< Test1_obj > __new();
		static ::hx::ObjectPtr< Test1_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Test1_obj();

		HX_DO_RTTI_ALL;
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Test1",7f,ef,c2,a0); }

};


#endif /* INCLUDED_Test1 */ 
