#ifndef INCLUDED_polymod_backends__PolymodAssets_PolymodAssetType_Impl_
#define INCLUDED_polymod_backends__PolymodAssets_PolymodAssetType_Impl_

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(polymod,backends,_PolymodAssets,PolymodAssetType_Impl_)

namespace polymod{
namespace backends{
namespace _PolymodAssets{


class HXCPP_CLASS_ATTRIBUTES PolymodAssetType_Impl__obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef PolymodAssetType_Impl__obj OBJ_;
		PolymodAssetType_Impl__obj();

	public:
		enum { _hx_ClassId = 0x058f3cc3 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="polymod.backends._PolymodAssets.PolymodAssetType_Impl_")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"polymod.backends._PolymodAssets.PolymodAssetType_Impl_"); }

		inline static ::hx::ObjectPtr< PolymodAssetType_Impl__obj > __new() {
			::hx::ObjectPtr< PolymodAssetType_Impl__obj > __this = new PolymodAssetType_Impl__obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< PolymodAssetType_Impl__obj > __alloc(::hx::Ctx *_hx_ctx) {
			PolymodAssetType_Impl__obj *__this = (PolymodAssetType_Impl__obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(PolymodAssetType_Impl__obj), false, "polymod.backends._PolymodAssets.PolymodAssetType_Impl_"));
			*(void **)__this = PolymodAssetType_Impl__obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~PolymodAssetType_Impl__obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("PolymodAssetType_Impl_",b4,c1,25,5c); }

		static void __boot();
		static ::String BYTES;
		static ::String TEXT;
		static ::String IMAGE;
		static ::String VIDEO;
		static ::String FONT;
		static ::String AUDIO_GENERIC;
		static ::String AUDIO_MUSIC;
		static ::String AUDIO_SOUND;
		static ::String MANIFEST;
		static ::String TEMPLATE;
		static ::String UNKNOWN;
		static ::String fromString(::String str);
		static ::Dynamic fromString_dyn();

};

} // end namespace polymod
} // end namespace backends
} // end namespace _PolymodAssets

#endif /* INCLUDED_polymod_backends__PolymodAssets_PolymodAssetType_Impl_ */ 
