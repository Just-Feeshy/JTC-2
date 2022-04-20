#ifndef INCLUDED_io_newgrounds_objects_ScoreBoard
#define INCLUDED_io_newgrounds_objects_ScoreBoard

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_io_newgrounds_objects_Object
#include <io/newgrounds/objects/Object.h>
#endif
HX_DECLARE_CLASS2(io,newgrounds,NGLite)
HX_DECLARE_CLASS3(io,newgrounds,objects,Object)
HX_DECLARE_CLASS3(io,newgrounds,objects,ScoreBoard)

namespace io{
namespace newgrounds{
namespace objects{


class HXCPP_CLASS_ATTRIBUTES ScoreBoard_obj : public  ::io::newgrounds::objects::Object_obj
{
	public:
		typedef  ::io::newgrounds::objects::Object_obj super;
		typedef ScoreBoard_obj OBJ_;
		ScoreBoard_obj();

	public:
		enum { _hx_ClassId = 0x143ee596 };

		void __construct( ::io::newgrounds::NGLite core, ::Dynamic data);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="io.newgrounds.objects.ScoreBoard")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"io.newgrounds.objects.ScoreBoard"); }
		static ::hx::ObjectPtr< ScoreBoard_obj > __new( ::io::newgrounds::NGLite core, ::Dynamic data);
		static ::hx::ObjectPtr< ScoreBoard_obj > __alloc(::hx::Ctx *_hx_ctx, ::io::newgrounds::NGLite core, ::Dynamic data);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~ScoreBoard_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("ScoreBoard",14,3e,15,e9); }

		::Array< ::Dynamic> scores;
		int get_id();
		::Dynamic get_id_dyn();

		::String get_name();
		::Dynamic get_name_dyn();

		void requestScores(::hx::Null< int >  limit,::hx::Null< int >  skip,::String period,::hx::Null< bool >  social,::String tag, ::Dynamic user);
		::Dynamic requestScores_dyn();

		void onScoresReceived( ::Dynamic response);
		::Dynamic onScoresReceived_dyn();

		void postScore(int value,::String tag);
		::Dynamic postScore_dyn();

		void onScorePosted( ::Dynamic response);
		::Dynamic onScorePosted_dyn();

		virtual ::String toString();
		::Dynamic toString_dyn();

};

} // end namespace io
} // end namespace newgrounds
} // end namespace objects

#endif /* INCLUDED_io_newgrounds_objects_ScoreBoard */ 
