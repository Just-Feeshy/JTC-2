#ifndef INCLUDED_ModLua
#define INCLUDED_ModLua

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_cc9afe4755847ade
#define INCLUDED_cc9afe4755847ade
#include "linc_lua.h"
#endif
HX_DECLARE_CLASS0(ModLua)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS2(flixel,util,IFlxDestroyable)
HX_DECLARE_CLASS1(haxe,IMap)
HX_DECLARE_CLASS2(haxe,ds,StringMap)



class HXCPP_CLASS_ATTRIBUTES ModLua_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef ModLua_obj OBJ_;
		ModLua_obj();

	public:
		enum { _hx_ClassId = 0x569356f6 };

		void __construct(::String luaScript);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="ModLua")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"ModLua"); }
		static ::hx::ObjectPtr< ModLua_obj > __new(::String luaScript);
		static ::hx::ObjectPtr< ModLua_obj > __alloc(::hx::Ctx *_hx_ctx,::String luaScript);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~ModLua_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("ModLua",36,94,48,f5); }

		 cpp::Reference<lua_State> lua;
		::String luaScript;
		 ::haxe::ds::StringMap luaSprites;
		 ::haxe::ds::StringMap luaCameras;
		 ::haxe::ds::StringMap luaTweens;
		void execute();
		::Dynamic execute_dyn();

		void addCallback(::String name, ::Dynamic method);
		::Dynamic addCallback_dyn();

		void set(::String variable, ::Dynamic data);
		::Dynamic set_dyn();

		 ::Dynamic call(::String event,::cpp::VirtualArray args,::hx::Null< int >  index);
		::Dynamic call_dyn();

		 ::flixel::FlxSprite getSprite(::String name);
		::Dynamic getSprite_dyn();

		void close();
		::Dynamic close_dyn();

		int convertToLua(::cpp::VirtualArray args,::hx::Null< int >  index);
		::Dynamic convertToLua_dyn();

};


#endif /* INCLUDED_ModLua */ 
