#ifndef INCLUDED_io_newgrounds_components_ScoreBoardComponent
#define INCLUDED_io_newgrounds_components_ScoreBoardComponent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_io_newgrounds_components_Component
#include <io/newgrounds/components/Component.h>
#endif
HX_DECLARE_CLASS1(haxe,IMap)
HX_DECLARE_CLASS2(haxe,ds,IntMap)
HX_DECLARE_CLASS2(io,newgrounds,Call)
HX_DECLARE_CLASS2(io,newgrounds,ICallable)
HX_DECLARE_CLASS2(io,newgrounds,NGLite)
HX_DECLARE_CLASS3(io,newgrounds,components,Component)
HX_DECLARE_CLASS3(io,newgrounds,components,ScoreBoardComponent)
HX_DECLARE_CLASS3(io,newgrounds,objects,Object)
HX_DECLARE_CLASS3(io,newgrounds,objects,ScoreBoard)

namespace io{
namespace newgrounds{
namespace components{


class HXCPP_CLASS_ATTRIBUTES ScoreBoardComponent_obj : public  ::io::newgrounds::components::Component_obj
{
	public:
		typedef  ::io::newgrounds::components::Component_obj super;
		typedef ScoreBoardComponent_obj OBJ_;
		ScoreBoardComponent_obj();

	public:
		enum { _hx_ClassId = 0x54ed1d99 };

		void __construct( ::io::newgrounds::NGLite core);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="io.newgrounds.components.ScoreBoardComponent")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"io.newgrounds.components.ScoreBoardComponent"); }
		static ::hx::ObjectPtr< ScoreBoardComponent_obj > __new( ::io::newgrounds::NGLite core);
		static ::hx::ObjectPtr< ScoreBoardComponent_obj > __alloc(::hx::Ctx *_hx_ctx, ::io::newgrounds::NGLite core);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~ScoreBoardComponent_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("ScoreBoardComponent",09,30,4b,8c); }

		 ::haxe::ds::IntMap allById;
		 ::io::newgrounds::Call getBoards();
		::Dynamic getBoards_dyn();

		 ::io::newgrounds::Call getScores(int id,::hx::Null< int >  limit,::hx::Null< int >  skip,::String period,::hx::Null< bool >  social,::String tag, ::Dynamic user);
		::Dynamic getScores_dyn();

		 ::io::newgrounds::Call postScore(int id,int value,::String tag);
		::Dynamic postScore_dyn();

		 ::io::newgrounds::objects::ScoreBoard createBoard( ::Dynamic data);
		::Dynamic createBoard_dyn();

};

} // end namespace io
} // end namespace newgrounds
} // end namespace components

#endif /* INCLUDED_io_newgrounds_components_ScoreBoardComponent */ 
