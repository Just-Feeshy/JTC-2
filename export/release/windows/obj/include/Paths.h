#ifndef INCLUDED_Paths
#define INCLUDED_Paths

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Paths)
HX_DECLARE_CLASS2(flixel,graphics,FlxGraphic)
HX_DECLARE_CLASS3(flixel,graphics,frames,FlxAtlasFrames)
HX_DECLARE_CLASS3(flixel,graphics,frames,FlxFramesCollection)
HX_DECLARE_CLASS2(flixel,util,IFlxDestroyable)
HX_DECLARE_CLASS1(haxe,IMap)
HX_DECLARE_CLASS2(haxe,ds,StringMap)



class HXCPP_CLASS_ATTRIBUTES Paths_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef Paths_obj OBJ_;
		Paths_obj();

	public:
		enum { _hx_ClassId = 0x44c8e46a };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="Paths")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"Paths"); }

		inline static ::hx::ObjectPtr< Paths_obj > __new() {
			::hx::ObjectPtr< Paths_obj > __this = new Paths_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< Paths_obj > __alloc(::hx::Ctx *_hx_ctx) {
			Paths_obj *__this = (Paths_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Paths_obj), false, "Paths"));
			*(void **)__this = Paths_obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Paths_obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Paths",0e,7b,84,50); }

		static void __boot();
		static ::String SOUND_EXT;
		static  ::Dynamic modJSON;
		static  ::haxe::ds::StringMap bitLiteralMap;
		static ::String currentLevel;
		static void cacheEitherWay();
		static ::Dynamic cacheEitherWay_dyn();

		static  ::Dynamic get_modJSON();
		static ::Dynamic get_modJSON_dyn();

		static void setCurrentLevel(::String name);
		static ::Dynamic setCurrentLevel_dyn();

		static ::String getPath(::String file,::String type,::String library);
		static ::Dynamic getPath_dyn();

		static ::String getLibraryPath(::String file,::String library);
		static ::Dynamic getLibraryPath_dyn();

		static ::String getLibraryPathForce(::String file,::String library);
		static ::Dynamic getLibraryPathForce_dyn();

		static ::String getPreloadPath(::String file);
		static ::Dynamic getPreloadPath_dyn();

		static ::String file(::String file,::String type,::String library);
		static ::Dynamic file_dyn();

		static ::String xml(::String key,::String library);
		static ::Dynamic xml_dyn();

		static ::String soundRandom(::String key,int min,int max,::String library);
		static ::Dynamic soundRandom_dyn();

		static ::String font(::String key);
		static ::Dynamic font_dyn();

		static ::String mora(::String key,::String type,::String library);
		static ::Dynamic mora_dyn();

		static ::String txt(::String key,::String library);
		static ::Dynamic txt_dyn();

		static ::String pak(::String key,::String library);
		static ::Dynamic pak_dyn();

		static ::String json(::String key,::String library);
		static ::Dynamic json_dyn();

		static  ::flixel::graphics::frames::FlxAtlasFrames getPackerAtlas(::String key,::String library, ::Dynamic cache);
		static ::Dynamic getPackerAtlas_dyn();

		static ::String sound(::String key,::String library);
		static ::Dynamic sound_dyn();

		static ::String music(::String key,::String library);
		static ::Dynamic music_dyn();

		static ::String voices(::String song);
		static ::Dynamic voices_dyn();

		static ::String inst(::String song);
		static ::Dynamic inst_dyn();

		static  ::flixel::graphics::FlxGraphic ifImageCached(::String key);
		static ::Dynamic ifImageCached_dyn();

		static ::String getCharacterFile(::String key,::String library, ::Dynamic cache);
		static ::Dynamic getCharacterFile_dyn();

		static  ::flixel::graphics::frames::FlxAtlasFrames getSparrowAtlas(::String key,::String library, ::Dynamic cache);
		static ::Dynamic getSparrowAtlas_dyn();

		static  ::flixel::graphics::frames::FlxAtlasFrames getNoteAtlas(::String key);
		static ::Dynamic getNoteAtlas_dyn();

		static ::String image(::String key,::String library);
		static ::Dynamic image_dyn();

		static ::String lua(::String key);
		static ::Dynamic lua_dyn();

};


#endif /* INCLUDED_Paths */ 
