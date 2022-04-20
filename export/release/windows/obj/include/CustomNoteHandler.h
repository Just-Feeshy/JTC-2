#ifndef INCLUDED_CustomNoteHandler
#define INCLUDED_CustomNoteHandler

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(CustomNoteHandler)
HX_DECLARE_CLASS1(haxe,IMap)
HX_DECLARE_CLASS2(haxe,ds,StringMap)



class HXCPP_CLASS_ATTRIBUTES CustomNoteHandler_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef CustomNoteHandler_obj OBJ_;
		CustomNoteHandler_obj();

	public:
		enum { _hx_ClassId = 0x7fd163ab };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="CustomNoteHandler")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"CustomNoteHandler"); }

		inline static ::hx::ObjectPtr< CustomNoteHandler_obj > __new() {
			::hx::ObjectPtr< CustomNoteHandler_obj > __this = new CustomNoteHandler_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< CustomNoteHandler_obj > __alloc(::hx::Ctx *_hx_ctx) {
			CustomNoteHandler_obj *__this = (CustomNoteHandler_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(CustomNoteHandler_obj), false, "CustomNoteHandler"));
			*(void **)__this = CustomNoteHandler_obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~CustomNoteHandler_obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("CustomNoteHandler",a7,7d,dd,8c); }

		static void __boot();
		static bool funni;
		static  ::haxe::ds::StringMap triggerWarning;
		static  ::haxe::ds::StringMap yourNoteData;
		static ::Array< ::String > dontHitNotes;
		static ::Array< ::String > noNoteAbstractStrum;
		static ::Array< ::String > ouchyNotes;
		static ::Array< ::String > lowNotesTick;
		static  ::haxe::ds::StringMap customNoteAddon;
		static void spawn();
		static ::Dynamic spawn_dyn();

};


#endif /* INCLUDED_CustomNoteHandler */ 
