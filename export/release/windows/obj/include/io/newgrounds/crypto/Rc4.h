#ifndef INCLUDED_io_newgrounds_crypto_Rc4
#define INCLUDED_io_newgrounds_crypto_Rc4

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS3(io,newgrounds,crypto,Rc4)

namespace io{
namespace newgrounds{
namespace crypto{


class HXCPP_CLASS_ATTRIBUTES Rc4_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef Rc4_obj OBJ_;
		Rc4_obj();

	public:
		enum { _hx_ClassId = 0x649f6b90 };

		void __construct( ::haxe::io::Bytes key);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="io.newgrounds.crypto.Rc4")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"io.newgrounds.crypto.Rc4"); }
		static ::hx::ObjectPtr< Rc4_obj > __new( ::haxe::io::Bytes key);
		static ::hx::ObjectPtr< Rc4_obj > __alloc(::hx::Ctx *_hx_ctx, ::haxe::io::Bytes key);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Rc4_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Rc4",43,8f,3e,00); }

		 ::haxe::io::Bytes perm;
		int index1;
		int index2;
		void swap(int i,int j);
		::Dynamic swap_dyn();

		 ::haxe::io::Bytes crypt( ::haxe::io::Bytes input);
		::Dynamic crypt_dyn();

};

} // end namespace io
} // end namespace newgrounds
} // end namespace crypto

#endif /* INCLUDED_io_newgrounds_crypto_Rc4 */ 
