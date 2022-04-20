#ifndef INCLUDED_example_code_DefaultStage
#define INCLUDED_example_code_DefaultStage

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_template_StageBuilder
#include <template/StageBuilder.h>
#endif
HX_DECLARE_CLASS0(BackgroundGirls)
HX_DECLARE_CLASS1(example_code,DefaultStage)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS2(flixel,_hx_system,FlxSound)
HX_DECLARE_CLASS2(flixel,util,IFlxDestroyable)
HX_DECLARE_CLASS1(_hx_template,StageBuilder)

namespace example_code{


class HXCPP_CLASS_ATTRIBUTES DefaultStage_obj : public  ::_hx_template::StageBuilder_obj
{
	public:
		typedef  ::_hx_template::StageBuilder_obj super;
		typedef DefaultStage_obj OBJ_;
		DefaultStage_obj();

	public:
		enum { _hx_ClassId = 0x296008c7 };

		void __construct(::String song);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="example_code.DefaultStage")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"example_code.DefaultStage"); }
		static ::hx::ObjectPtr< DefaultStage_obj > __new(::String song);
		static ::hx::ObjectPtr< DefaultStage_obj > __alloc(::hx::Ctx *_hx_ctx,::String song);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~DefaultStage_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("DefaultStage",5d,f2,78,01); }

		static ::String setMainGameStage(::String song);
		static ::Dynamic setMainGameStage_dyn();

		 ::flixel::FlxSprite halloweenBG;
		 ::flixel::group::FlxTypedGroup phillyCityLights;
		 ::flixel::group::FlxTypedGroup grpLimoDancers;
		 ::flixel::FlxSprite phillyTrain;
		 ::flixel::FlxSprite limo;
		 ::flixel::FlxSprite upperBoppers;
		 ::flixel::FlxSprite bottomBoppers;
		 ::flixel::FlxSprite fastCar;
		 ::flixel::FlxSprite santa;
		 ::BackgroundGirls bgGirls;
		 ::flixel::_hx_system::FlxSound trainSound;
		bool isPixel;
		void destroy();

};

} // end namespace example_code

#endif /* INCLUDED_example_code_DefaultStage */ 
