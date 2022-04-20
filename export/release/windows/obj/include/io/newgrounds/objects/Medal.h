#ifndef INCLUDED_io_newgrounds_objects_Medal
#define INCLUDED_io_newgrounds_objects_Medal

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_io_newgrounds_objects_Object
#include <io/newgrounds/objects/Object.h>
#endif
HX_DECLARE_CLASS2(io,newgrounds,NGLite)
HX_DECLARE_CLASS3(io,newgrounds,objects,Medal)
HX_DECLARE_CLASS3(io,newgrounds,objects,Object)
HX_DECLARE_CLASS3(io,newgrounds,utils,Dispatcher)

namespace io{
namespace newgrounds{
namespace objects{


class HXCPP_CLASS_ATTRIBUTES Medal_obj : public  ::io::newgrounds::objects::Object_obj
{
	public:
		typedef  ::io::newgrounds::objects::Object_obj super;
		typedef Medal_obj OBJ_;
		Medal_obj();

	public:
		enum { _hx_ClassId = 0x7564f595 };

		void __construct( ::io::newgrounds::NGLite core, ::Dynamic data);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="io.newgrounds.objects.Medal")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"io.newgrounds.objects.Medal"); }
		static ::hx::ObjectPtr< Medal_obj > __new( ::io::newgrounds::NGLite core, ::Dynamic data);
		static ::hx::ObjectPtr< Medal_obj > __alloc(::hx::Ctx *_hx_ctx, ::io::newgrounds::NGLite core, ::Dynamic data);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Medal_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Medal",d7,6d,e9,98); }

		static void __boot();
		static int EASY;
		static int MODERATE;
		static int CHALLENGING;
		static int DIFFICULT;
		static int BRUTAL;
		int get_id();
		::Dynamic get_id_dyn();

		::String get_name();
		::Dynamic get_name_dyn();

		::String get_description();
		::Dynamic get_description_dyn();

		::String get_icon();
		::Dynamic get_icon_dyn();

		int get_value();
		::Dynamic get_value_dyn();

		int get_difficulty();
		::Dynamic get_difficulty_dyn();

		bool get_secret();
		::Dynamic get_secret_dyn();

		bool get_unlocked();
		::Dynamic get_unlocked_dyn();

		 ::io::newgrounds::utils::Dispatcher onUnlock;
		void parse( ::Dynamic _tmp_data);

		void sendUnlock();
		::Dynamic sendUnlock_dyn();

		void onUnlockResponse( ::Dynamic response);
		::Dynamic onUnlockResponse_dyn();

		void sendDebugUnlock();
		::Dynamic sendDebugUnlock_dyn();

		::String get_difficultyName();
		::Dynamic get_difficultyName_dyn();

		virtual ::String toString();
		::Dynamic toString_dyn();

};

} // end namespace io
} // end namespace newgrounds
} // end namespace objects

#endif /* INCLUDED_io_newgrounds_objects_Medal */ 
