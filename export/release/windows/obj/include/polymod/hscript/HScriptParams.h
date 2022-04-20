#ifndef INCLUDED_polymod_hscript_HScriptParams
#define INCLUDED_polymod_hscript_HScriptParams

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(polymod,hscript,HScriptParams)

namespace polymod{
namespace hscript{


class HXCPP_CLASS_ATTRIBUTES HScriptParams_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef HScriptParams_obj OBJ_;
		HScriptParams_obj();

	public:
		enum { _hx_ClassId = 0x0c51ea74 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="polymod.hscript.HScriptParams")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"polymod.hscript.HScriptParams"); }
		static ::hx::ObjectPtr< HScriptParams_obj > __new();
		static ::hx::ObjectPtr< HScriptParams_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~HScriptParams_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("HScriptParams",19,f0,3f,eb); }

		static void __boot();
		static bool CANCELLABLE_DEFAULT;
		static bool RUN_BEFORE_DEFAULT;
		static bool OPTIONAL_DEFAULT;
		::Array< ::String > context;
		 ::Dynamic cancellable;
		 ::Dynamic runBefore;
		 ::Dynamic optional;
		::String pathName;
		::String set_pathName(::String newValue);
		::Dynamic set_pathName_dyn();

		::String pathNameDynId;
		::String set_pathNameDynId(::String newValue);
		::Dynamic set_pathNameDynId_dyn();

		 ::polymod::hscript::HScriptParams mergeContext(::Array< ::String > newValues);
		::Dynamic mergeContext_dyn();

		 ::polymod::hscript::HScriptParams mergeCancellable( ::Dynamic newValue);
		::Dynamic mergeCancellable_dyn();

		 ::polymod::hscript::HScriptParams mergeRunBefore( ::Dynamic newValue);
		::Dynamic mergeRunBefore_dyn();

		 ::polymod::hscript::HScriptParams mergeOptional( ::Dynamic newValue);
		::Dynamic mergeOptional_dyn();

		 ::polymod::hscript::HScriptParams mergePathName(::String newValue,::String newDynValue);
		::Dynamic mergePathName_dyn();

		 ::polymod::hscript::HScriptParams copy();
		::Dynamic copy_dyn();

		 ::polymod::hscript::HScriptParams merge( ::polymod::hscript::HScriptParams newValue);
		::Dynamic merge_dyn();

		virtual ::String toString();
		::Dynamic toString_dyn();

};

} // end namespace polymod
} // end namespace hscript

#endif /* INCLUDED_polymod_hscript_HScriptParams */ 
