#ifndef INCLUDED_Conductor
#define INCLUDED_Conductor

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_STACK_FRAME(_hx_pos_9bd24c9adde08dff_33_new)
HX_DECLARE_CLASS0(Conductor)



class HXCPP_CLASS_ATTRIBUTES Conductor_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef Conductor_obj OBJ_;
		Conductor_obj();

	public:
		enum { _hx_ClassId = 0x3ee4ed07 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="Conductor")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"Conductor"); }

		inline static ::hx::ObjectPtr< Conductor_obj > __new() {
			::hx::ObjectPtr< Conductor_obj > __this = new Conductor_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< Conductor_obj > __alloc(::hx::Ctx *_hx_ctx) {
			Conductor_obj *__this = (Conductor_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Conductor_obj), false, "Conductor"));
			*(void **)__this = Conductor_obj::_hx_vtable;
{
            	HX_STACKFRAME(&_hx_pos_9bd24c9adde08dff_33_new)
            	}
		
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Conductor_obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Conductor",c7,77,a1,7b); }

		static void __boot();
		static int bpm;
		static Float crochet;
		static Float stepCrochet;
		static Float songPosition;
		static Float trackPosition;
		static Float lastSongPos;
		static Float offset;
		static int safeFrames;
		static Float safeZoneOffset;
		static ::Array< ::Dynamic> bpmChangeMap;
		static void mapBPMChanges( ::Dynamic song);
		static ::Dynamic mapBPMChanges_dyn();

		static void changeBPM(int newBpm);
		static ::Dynamic changeBPM_dyn();

};


#endif /* INCLUDED_Conductor */ 
