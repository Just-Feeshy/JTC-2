#include <hxcpp.h>

#ifndef INCLUDED_JsonParser_1
#include <JsonParser_1.h>
#endif
#ifndef INCLUDED_Paths
#include <Paths.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_graphics_FlxGraphic
#include <flixel/graphics/FlxGraphic.h>
#endif
#ifndef INCLUDED_flixel_graphics_frames_FlxAtlasFrames
#include <flixel/graphics/frames/FlxAtlasFrames.h>
#endif
#ifndef INCLUDED_flixel_graphics_frames_FlxFramesCollection
#include <flixel/graphics/frames/FlxFramesCollection.h>
#endif
#ifndef INCLUDED_flixel_math_FlxRandom
#include <flixel/math/FlxRandom.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxDestroyable
#include <flixel/util/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_haxe_Exception
#include <haxe/Exception.h>
#endif
#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_json2object_Error
#include <json2object/Error.h>
#endif
#ifndef INCLUDED_json2object_PositionUtils
#include <json2object/PositionUtils.h>
#endif
#ifndef INCLUDED_json2object_reader_BaseParser
#include <json2object/reader/BaseParser.h>
#endif
#ifndef INCLUDED_lime_utils_Assets
#include <lime/utils/Assets.h>
#endif
#ifndef INCLUDED_openfl_display_BitmapData
#include <openfl/display/BitmapData.h>
#endif
#ifndef INCLUDED_openfl_display_IBitmapDrawable
#include <openfl/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl_utils_Assets
#include <openfl/utils/Assets.h>
#endif
#ifndef INCLUDED_sys_FileSystem
#include <sys/FileSystem.h>
#endif
#ifndef INCLUDED_sys_io_File
#include <sys/io/File.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_d75e02b628d1544a_32_cacheEitherWay,"Paths","cacheEitherWay",0x3e009ba8,"Paths.cacheEitherWay","Paths.hx",32,0x309ea470)
HX_LOCAL_STACK_FRAME(_hx_pos_d75e02b628d1544a_41_get_modJSON,"Paths","get_modJSON",0x853394a1,"Paths.get_modJSON","Paths.hx",41,0x309ea470)
HX_LOCAL_STACK_FRAME(_hx_pos_d75e02b628d1544a_52_setCurrentLevel,"Paths","setCurrentLevel",0x8a8c27ed,"Paths.setCurrentLevel","Paths.hx",52,0x309ea470)
HX_LOCAL_STACK_FRAME(_hx_pos_d75e02b628d1544a_56_getPath,"Paths","getPath",0x5f104ffb,"Paths.getPath","Paths.hx",56,0x309ea470)
HX_LOCAL_STACK_FRAME(_hx_pos_d75e02b628d1544a_76_getLibraryPath,"Paths","getLibraryPath",0xe56efeaa,"Paths.getLibraryPath","Paths.hx",76,0x309ea470)
HX_LOCAL_STACK_FRAME(_hx_pos_d75e02b628d1544a_81_getLibraryPathForce,"Paths","getLibraryPathForce",0xe1e5bae1,"Paths.getLibraryPathForce","Paths.hx",81,0x309ea470)
HX_LOCAL_STACK_FRAME(_hx_pos_d75e02b628d1544a_89_getPreloadPath,"Paths","getPreloadPath",0x2fdd9e78,"Paths.getPreloadPath","Paths.hx",89,0x309ea470)
HX_LOCAL_STACK_FRAME(_hx_pos_d75e02b628d1544a_97_file,"Paths","file",0x8f872fdc,"Paths.file","Paths.hx",97,0x309ea470)
HX_LOCAL_STACK_FRAME(_hx_pos_d75e02b628d1544a_102_xml,"Paths","xml",0x5a3d5877,"Paths.xml","Paths.hx",102,0x309ea470)
HX_LOCAL_STACK_FRAME(_hx_pos_d75e02b628d1544a_107_soundRandom,"Paths","soundRandom",0x8e79b2d2,"Paths.soundRandom","Paths.hx",107,0x309ea470)
HX_LOCAL_STACK_FRAME(_hx_pos_d75e02b628d1544a_112_font,"Paths","font",0x8f8bbf2f,"Paths.font","Paths.hx",112,0x309ea470)
HX_LOCAL_STACK_FRAME(_hx_pos_d75e02b628d1544a_118_mora,"Paths","mora",0x942c40f1,"Paths.mora","Paths.hx",118,0x309ea470)
HX_LOCAL_STACK_FRAME(_hx_pos_d75e02b628d1544a_128_txt,"Paths","txt",0x5a3a5910,"Paths.txt","Paths.hx",128,0x309ea470)
HX_LOCAL_STACK_FRAME(_hx_pos_d75e02b628d1544a_138_pak,"Paths","pak",0x5a373bfa,"Paths.pak","Paths.hx",138,0x309ea470)
HX_LOCAL_STACK_FRAME(_hx_pos_d75e02b628d1544a_148_json,"Paths","json",0x9233a388,"Paths.json","Paths.hx",148,0x309ea470)
HX_LOCAL_STACK_FRAME(_hx_pos_d75e02b628d1544a_157_getPackerAtlas,"Paths","getPackerAtlas",0xa8de8c4f,"Paths.getPackerAtlas","Paths.hx",157,0x309ea470)
HX_LOCAL_STACK_FRAME(_hx_pos_d75e02b628d1544a_179_sound,"Paths","sound",0x86f65f6f,"Paths.sound","Paths.hx",179,0x309ea470)
HX_LOCAL_STACK_FRAME(_hx_pos_d75e02b628d1544a_189_music,"Paths","music",0x1684a345,"Paths.music","Paths.hx",189,0x309ea470)
HX_LOCAL_STACK_FRAME(_hx_pos_d75e02b628d1544a_199_voices,"Paths","voices",0xbbb84fe1,"Paths.voices","Paths.hx",199,0x309ea470)
HX_LOCAL_STACK_FRAME(_hx_pos_d75e02b628d1544a_209_inst,"Paths","inst",0x9186a526,"Paths.inst","Paths.hx",209,0x309ea470)
HX_LOCAL_STACK_FRAME(_hx_pos_d75e02b628d1544a_218_ifImageCached,"Paths","ifImageCached",0x61cb9b60,"Paths.ifImageCached","Paths.hx",218,0x309ea470)
HX_LOCAL_STACK_FRAME(_hx_pos_d75e02b628d1544a_221_getCharacterFile,"Paths","getCharacterFile",0x0ed0f9af,"Paths.getCharacterFile","Paths.hx",221,0x309ea470)
HX_LOCAL_STACK_FRAME(_hx_pos_d75e02b628d1544a_235_getSparrowAtlas,"Paths","getSparrowAtlas",0x5a1f05f5,"Paths.getSparrowAtlas","Paths.hx",235,0x309ea470)
HX_LOCAL_STACK_FRAME(_hx_pos_d75e02b628d1544a_259_getNoteAtlas,"Paths","getNoteAtlas",0x95dcf5e3,"Paths.getNoteAtlas","Paths.hx",259,0x309ea470)
HX_LOCAL_STACK_FRAME(_hx_pos_d75e02b628d1544a_272_image,"Paths","image",0xc392f1fb,"Paths.image","Paths.hx",272,0x309ea470)
HX_LOCAL_STACK_FRAME(_hx_pos_d75e02b628d1544a_281_lua,"Paths","lua",0x5a344458,"Paths.lua","Paths.hx",281,0x309ea470)
HX_LOCAL_STACK_FRAME(_hx_pos_d75e02b628d1544a_21_boot,"Paths","boot",0x8ce6e592,"Paths.boot","Paths.hx",21,0x309ea470)
HX_LOCAL_STACK_FRAME(_hx_pos_d75e02b628d1544a_25_boot,"Paths","boot",0x8ce6e592,"Paths.boot","Paths.hx",25,0x309ea470)

void Paths_obj::__construct() { }

Dynamic Paths_obj::__CreateEmpty() { return new Paths_obj; }

void *Paths_obj::_hx_vtable = 0;

Dynamic Paths_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Paths_obj > _hx_result = new Paths_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool Paths_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x44c8e46a;
}

::String Paths_obj::SOUND_EXT;

 ::Dynamic Paths_obj::modJSON;

 ::haxe::ds::StringMap Paths_obj::bitLiteralMap;

::String Paths_obj::currentLevel;

void Paths_obj::cacheEitherWay(){
            	HX_STACKFRAME(&_hx_pos_d75e02b628d1544a_32_cacheEitherWay)
HXDLIN(  32)		if (::hx::IsNull( ::Paths_obj::bitLiteralMap->get(HX_("regular/splash",fa,3f,30,77)) )) {
HXLINE(  33)			 ::flixel::graphics::FlxGraphic splashGraphic = ::flixel::graphics::FlxGraphic_obj::fromBitmapData(::openfl::display::BitmapData_obj::fromFile(HX_("assets/shared/images/notes/regular/splash.png",9c,44,c9,92)),null(),null(),null());
HXLINE(  34)			splashGraphic->persist = true;
HXLINE(  35)			::Paths_obj::bitLiteralMap->set(HX_("regular/splash",fa,3f,30,77),splashGraphic);
            		}
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Paths_obj,cacheEitherWay,(void))

 ::Dynamic Paths_obj::get_modJSON(){
            	HX_GC_STACKFRAME(&_hx_pos_d75e02b628d1544a_41_get_modJSON)
HXDLIN(  41)		if (::hx::IsNull( ::Paths_obj::modJSON )) {
HXLINE(  42)			 ::JsonParser_1 parser =  ::JsonParser_1_obj::__alloc( HX_CTX ,null(),null(),null());
HXLINE(  44)			return parser->fromJson(::sys::io::File_obj::getContent(HX_("config/mod.json",81,23,c4,45)),HX_("mod.json",54,1b,d0,20));
            		}
            		else {
HXLINE(  46)			return ::Paths_obj::modJSON;
            		}
HXLINE(  41)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Paths_obj,get_modJSON,return )

void Paths_obj::setCurrentLevel(::String name){
            	HX_STACKFRAME(&_hx_pos_d75e02b628d1544a_52_setCurrentLevel)
HXDLIN(  52)		::Paths_obj::currentLevel = name.toLowerCase();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Paths_obj,setCurrentLevel,(void))

::String Paths_obj::getPath(::String file,::String type,::String library){
            	HX_STACKFRAME(&_hx_pos_d75e02b628d1544a_56_getPath)
HXLINE(  57)		if (::hx::IsNotNull( library )) {
HXLINE(  58)			return ::Paths_obj::getLibraryPath(file,library);
            		}
HXLINE(  60)		if (::hx::IsNotNull( ::Paths_obj::currentLevel )) {
HXLINE(  62)			::String library = ::Paths_obj::currentLevel;
HXDLIN(  62)			::String levelPath;
HXDLIN(  62)			if (::sys::FileSystem_obj::exists((HX_("mod_assets/",8f,2c,df,15) + file))) {
HXLINE(  62)				levelPath = (HX_("mod_assets/",8f,2c,df,15) + file);
            			}
            			else {
HXLINE(  62)				levelPath = (((((HX_("",00,00,00,00) + library) + HX_(":assets/",52,05,4a,2c)) + library) + HX_("/",2f,00,00,00)) + file);
            			}
HXLINE(  63)			if (::openfl::utils::Assets_obj::exists(levelPath,type)) {
HXLINE(  64)				return levelPath;
            			}
HXLINE(  66)			if (::sys::FileSystem_obj::exists((HX_("mod_assets/",8f,2c,df,15) + file))) {
HXLINE(  66)				levelPath = (HX_("mod_assets/",8f,2c,df,15) + file);
            			}
            			else {
HXLINE(  66)				levelPath = ((((HX_("shared",a5,5e,2b,1d) + HX_(":assets/",52,05,4a,2c)) + HX_("shared",a5,5e,2b,1d)) + HX_("/",2f,00,00,00)) + file);
            			}
HXLINE(  67)			if (::openfl::utils::Assets_obj::exists(levelPath,type)) {
HXLINE(  68)				return levelPath;
            			}
            		}
HXLINE(  71)		if (::sys::FileSystem_obj::exists((HX_("mod_assets/",8f,2c,df,15) + file))) {
HXLINE(  71)			return (HX_("mod_assets/",8f,2c,df,15) + file);
            		}
            		else {
HXLINE(  71)			return (HX_("assets/",4c,2a,dc,36) + file);
            		}
HXDLIN(  71)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Paths_obj,getPath,return )

::String Paths_obj::getLibraryPath(::String file,::String __o_library){
            		::String library = __o_library;
            		if (::hx::IsNull(__o_library)) library = HX_("preload",c9,47,43,35);
            	HX_STACKFRAME(&_hx_pos_d75e02b628d1544a_76_getLibraryPath)
HXDLIN(  76)		bool _hx_tmp;
HXDLIN(  76)		if ((library != HX_("preload",c9,47,43,35))) {
HXDLIN(  76)			_hx_tmp = (library == HX_("default",c1,d8,c3,9b));
            		}
            		else {
HXDLIN(  76)			_hx_tmp = true;
            		}
HXDLIN(  76)		if (_hx_tmp) {
HXDLIN(  76)			if (::sys::FileSystem_obj::exists((HX_("mod_assets/",8f,2c,df,15) + file))) {
HXDLIN(  76)				return (HX_("mod_assets/",8f,2c,df,15) + file);
            			}
            			else {
HXDLIN(  76)				return (HX_("assets/",4c,2a,dc,36) + file);
            			}
            		}
            		else {
HXDLIN(  76)			if (::sys::FileSystem_obj::exists((HX_("mod_assets/",8f,2c,df,15) + file))) {
HXDLIN(  76)				return (HX_("mod_assets/",8f,2c,df,15) + file);
            			}
            			else {
HXDLIN(  76)				return (((((HX_("",00,00,00,00) + library) + HX_(":assets/",52,05,4a,2c)) + library) + HX_("/",2f,00,00,00)) + file);
            			}
            		}
HXDLIN(  76)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Paths_obj,getLibraryPath,return )

::String Paths_obj::getLibraryPathForce(::String file,::String library){
            	HX_STACKFRAME(&_hx_pos_d75e02b628d1544a_81_getLibraryPathForce)
HXDLIN(  81)		if (::sys::FileSystem_obj::exists((HX_("mod_assets/",8f,2c,df,15) + file))) {
HXLINE(  82)			return (HX_("mod_assets/",8f,2c,df,15) + file);
            		}
            		else {
HXLINE(  84)			return (((((HX_("",00,00,00,00) + library) + HX_(":assets/",52,05,4a,2c)) + library) + HX_("/",2f,00,00,00)) + file);
            		}
HXLINE(  81)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Paths_obj,getLibraryPathForce,return )

::String Paths_obj::getPreloadPath(::String file){
            	HX_STACKFRAME(&_hx_pos_d75e02b628d1544a_89_getPreloadPath)
HXDLIN(  89)		if (::sys::FileSystem_obj::exists((HX_("mod_assets/",8f,2c,df,15) + file))) {
HXLINE(  90)			return (HX_("mod_assets/",8f,2c,df,15) + file);
            		}
            		else {
HXLINE(  92)			return (HX_("assets/",4c,2a,dc,36) + file);
            		}
HXLINE(  89)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Paths_obj,getPreloadPath,return )

::String Paths_obj::file(::String file,::String __o_type,::String library){
            		::String type = __o_type;
            		if (::hx::IsNull(__o_type)) type = HX_("TEXT",ad,94,ba,37);
            	HX_STACKFRAME(&_hx_pos_d75e02b628d1544a_97_file)
HXDLIN(  97)		return ::Paths_obj::getPath(file,type,library);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Paths_obj,file,return )

::String Paths_obj::xml(::String key,::String library){
            	HX_STACKFRAME(&_hx_pos_d75e02b628d1544a_102_xml)
HXDLIN( 102)		return ::Paths_obj::getPath(((HX_("data/",c5,0e,88,d4) + key) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Paths_obj,xml,return )

::String Paths_obj::soundRandom(::String key,int min,int max,::String library){
            	HX_STACKFRAME(&_hx_pos_d75e02b628d1544a_107_soundRandom)
HXDLIN( 107)		::String key1 = (key + ::flixel::FlxG_obj::random->_hx_int(min,max,null()));
HXDLIN( 107)		if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("sounds/",eb,02,a5,b6) + key1) + HX_(".",2e,00,00,00)) + HX_("ogg",4f,94,54,00)),HX_("SOUND",af,c4,ba,fe),library),null())) {
HXDLIN( 107)			return ::Paths_obj::getPath((((HX_("sounds/",eb,02,a5,b6) + key1) + HX_(".",2e,00,00,00)) + HX_("ogg",4f,94,54,00)),HX_("SOUND",af,c4,ba,fe),library);
            		}
            		else {
HXDLIN( 107)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate sound - ",98,e2,ed,38) + key1)));
            		}
HXDLIN( 107)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Paths_obj,soundRandom,return )

::String Paths_obj::font(::String key){
            	HX_STACKFRAME(&_hx_pos_d75e02b628d1544a_112_font)
HXDLIN( 112)		return (HX_("assets/fonts/",37,ff,a5,9c) + key);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Paths_obj,font,return )

::String Paths_obj::mora(::String key,::String type,::String library){
            	HX_STACKFRAME(&_hx_pos_d75e02b628d1544a_118_mora)
HXDLIN( 118)		if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("feeshdata/",8a,24,9b,7f) + key) + HX_(".",2e,00,00,00)) + type),HX_("TEXT",ad,94,ba,37),library),null())) {
HXLINE( 119)			return ::Paths_obj::getPath((((HX_("feeshdata/",8a,24,9b,7f) + key) + HX_(".",2e,00,00,00)) + type),HX_("TEXT",ad,94,ba,37),library);
            		}
            		else {
HXLINE( 121)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate file - ",63,30,27,df) + (((HX_("",00,00,00,00) + key) + HX_(".",2e,00,00,00)) + type))));
            		}
HXLINE( 118)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Paths_obj,mora,return )

::String Paths_obj::txt(::String key,::String library){
            	HX_STACKFRAME(&_hx_pos_d75e02b628d1544a_128_txt)
HXDLIN( 128)		if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath(((HX_("data/",c5,0e,88,d4) + key) + HX_(".txt",02,3f,c0,1e)),HX_("TEXT",ad,94,ba,37),library),null())) {
HXLINE( 129)			return ::Paths_obj::getPath(((HX_("data/",c5,0e,88,d4) + key) + HX_(".txt",02,3f,c0,1e)),HX_("TEXT",ad,94,ba,37),library);
            		}
            		else {
HXLINE( 131)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Warning: could not locate text file - ",84,62,2b,42) + key)));
            		}
HXLINE( 128)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Paths_obj,txt,return )

::String Paths_obj::pak(::String key,::String library){
            	HX_STACKFRAME(&_hx_pos_d75e02b628d1544a_138_pak)
HXDLIN( 138)		if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath(((HX_("pakdata/",2b,97,6b,64) + key) + HX_(".pak",ec,21,bd,1e)),HX_("TEXT",ad,94,ba,37),library),null())) {
HXLINE( 139)			return ::Paths_obj::getPath(((HX_("pakdata/",2b,97,6b,64) + key) + HX_(".pak",ec,21,bd,1e)),HX_("TEXT",ad,94,ba,37),library);
            		}
            		else {
HXLINE( 141)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate pak file - ",9d,15,94,65) + key)));
            		}
HXLINE( 138)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Paths_obj,pak,return )

::String Paths_obj::json(::String key,::String library){
            	HX_STACKFRAME(&_hx_pos_d75e02b628d1544a_148_json)
HXDLIN( 148)		if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath(((HX_("data/",c5,0e,88,d4) + key) + HX_(".json",56,f1,d6,c2)),HX_("TEXT",ad,94,ba,37),library),null())) {
HXLINE( 149)			return ::Paths_obj::getPath(((HX_("data/",c5,0e,88,d4) + key) + HX_(".json",56,f1,d6,c2)),HX_("TEXT",ad,94,ba,37),library);
            		}
            		else {
HXLINE( 151)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate json file - ",13,f3,9f,29) + key)));
            		}
HXLINE( 148)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Paths_obj,json,return )

 ::flixel::graphics::frames::FlxAtlasFrames Paths_obj::getPackerAtlas(::String key,::String library, ::Dynamic cache){
            	HX_STACKFRAME(&_hx_pos_d75e02b628d1544a_157_getPackerAtlas)
HXLINE( 158)		::String cacheFile = HX_("",00,00,00,00);
HXLINE( 160)		if (( (bool)(cache) )) {
HXLINE( 161)			cacheFile = HX_("cache/",ad,5f,f2,b0);
            		}
HXLINE( 163)		if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + key))) {
HXLINE( 164)			cacheFile = HX_("",00,00,00,00);
            		}
HXLINE( 166)		if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + key) + HX_(".txt",02,3f,c0,1e)),HX_("TEXT",ad,94,ba,37),library),null())) {
HXLINE( 167)			if (::hx::IsNotNull( ::Paths_obj::ifImageCached((cacheFile + key)) )) {
HXLINE( 168)				 ::flixel::graphics::FlxGraphic _hx_tmp = ::Paths_obj::ifImageCached((cacheFile + key));
HXDLIN( 168)				return ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSpriteSheetPacker(_hx_tmp,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + key) + HX_(".txt",02,3f,c0,1e)),HX_("TEXT",ad,94,ba,37),library));
            			}
            			else {
HXLINE( 170)				::String _hx_tmp = ::Paths_obj::image((cacheFile + key),library);
HXDLIN( 170)				return ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSpriteSheetPacker(_hx_tmp,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + key) + HX_(".txt",02,3f,c0,1e)),HX_("TEXT",ad,94,ba,37),library));
            			}
            		}
            		else {
HXLINE( 172)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate asset - ",17,30,f9,e8) + ::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + key) + HX_(".txt",02,3f,c0,1e)),HX_("TEXT",ad,94,ba,37),library))));
            		}
HXLINE( 166)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Paths_obj,getPackerAtlas,return )

::String Paths_obj::sound(::String key,::String library){
            	HX_STACKFRAME(&_hx_pos_d75e02b628d1544a_179_sound)
HXDLIN( 179)		if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("sounds/",eb,02,a5,b6) + key) + HX_(".",2e,00,00,00)) + HX_("ogg",4f,94,54,00)),HX_("SOUND",af,c4,ba,fe),library),null())) {
HXLINE( 180)			return ::Paths_obj::getPath((((HX_("sounds/",eb,02,a5,b6) + key) + HX_(".",2e,00,00,00)) + HX_("ogg",4f,94,54,00)),HX_("SOUND",af,c4,ba,fe),library);
            		}
            		else {
HXLINE( 182)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate sound - ",98,e2,ed,38) + key)));
            		}
HXLINE( 179)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Paths_obj,sound,return )

::String Paths_obj::music(::String key,::String library){
            	HX_STACKFRAME(&_hx_pos_d75e02b628d1544a_189_music)
HXDLIN( 189)		if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("music/",ea,bf,1b,3f) + key) + HX_(".",2e,00,00,00)) + HX_("ogg",4f,94,54,00)),HX_("MUSIC",85,08,49,8e),library),null())) {
HXLINE( 190)			return ::Paths_obj::getPath((((HX_("music/",ea,bf,1b,3f) + key) + HX_(".",2e,00,00,00)) + HX_("ogg",4f,94,54,00)),HX_("MUSIC",85,08,49,8e),library);
            		}
            		else {
HXLINE( 192)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate music - ",82,28,df,2c) + key)));
            		}
HXLINE( 189)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Paths_obj,music,return )

::String Paths_obj::voices(::String song){
            	HX_STACKFRAME(&_hx_pos_d75e02b628d1544a_199_voices)
HXDLIN( 199)		if (::lime::utils::Assets_obj::exists((((HX_("songs:assets/songs/",c1,ed,e6,7e) + song.toLowerCase()) + HX_("/Voices.",1e,f6,e5,90)) + HX_("ogg",4f,94,54,00)),null())) {
HXLINE( 200)			return (((HX_("songs:assets/songs/",c1,ed,e6,7e) + song.toLowerCase()) + HX_("/Voices.",1e,f6,e5,90)) + HX_("ogg",4f,94,54,00));
            		}
            		else {
HXLINE( 202)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(((HX_("Error: could not locate voices - ",7e,8c,57,81) + song) + HX_("ogg",4f,94,54,00))));
            		}
HXLINE( 199)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Paths_obj,voices,return )

::String Paths_obj::inst(::String song){
            	HX_STACKFRAME(&_hx_pos_d75e02b628d1544a_209_inst)
HXDLIN( 209)		if (::lime::utils::Assets_obj::exists((((HX_("songs:assets/songs/",c1,ed,e6,7e) + song.toLowerCase()) + HX_("/Inst.",f9,6e,13,1c)) + HX_("ogg",4f,94,54,00)),null())) {
HXLINE( 210)			return (((HX_("songs:assets/songs/",c1,ed,e6,7e) + song.toLowerCase()) + HX_("/Inst.",f9,6e,13,1c)) + HX_("ogg",4f,94,54,00));
            		}
            		else {
HXLINE( 212)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(((HX_("Error: could not locate instrumental - ",cd,74,af,c4) + song) + HX_("ogg",4f,94,54,00))));
            		}
HXLINE( 209)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Paths_obj,inst,return )

 ::flixel::graphics::FlxGraphic Paths_obj::ifImageCached(::String key){
            	HX_STACKFRAME(&_hx_pos_d75e02b628d1544a_218_ifImageCached)
HXDLIN( 218)		return ( ( ::flixel::graphics::FlxGraphic)(::Paths_obj::bitLiteralMap->get(key)) );
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Paths_obj,ifImageCached,return )

::String Paths_obj::getCharacterFile(::String key,::String library, ::Dynamic cache){
            	HX_STACKFRAME(&_hx_pos_d75e02b628d1544a_221_getCharacterFile)
HXLINE( 222)		::String cacheFile = HX_("",00,00,00,00);
HXLINE( 224)		if (( (bool)(cache) )) {
HXLINE( 225)			cacheFile = HX_("cache/",ad,5f,f2,b0);
            		}
HXLINE( 228)		if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + key))) {
HXLINE( 229)			cacheFile = HX_("",00,00,00,00);
            		}
HXLINE( 231)		return ::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + key) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Paths_obj,getCharacterFile,return )

 ::flixel::graphics::frames::FlxAtlasFrames Paths_obj::getSparrowAtlas(::String key,::String library, ::Dynamic cache){
            	HX_STACKFRAME(&_hx_pos_d75e02b628d1544a_235_getSparrowAtlas)
HXLINE( 236)		::String cacheFile = HX_("",00,00,00,00);
HXLINE( 238)		if (( (bool)(cache) )) {
HXLINE( 239)			cacheFile = HX_("cache/",ad,5f,f2,b0);
            		}
HXLINE( 242)		if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + key))) {
HXLINE( 243)			cacheFile = HX_("",00,00,00,00);
            		}
HXLINE( 245)		::String cacheFile1 = HX_("",00,00,00,00);
HXDLIN( 245)		if (( (bool)(cache) )) {
HXLINE( 245)			cacheFile1 = HX_("cache/",ad,5f,f2,b0);
            		}
HXDLIN( 245)		if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + key))) {
HXLINE( 245)			cacheFile1 = HX_("",00,00,00,00);
            		}
HXDLIN( 245)		if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile1) + key) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library),null())) {
HXLINE( 247)			if (::hx::IsNotNull( ::Paths_obj::ifImageCached((cacheFile + key)) )) {
HXLINE( 248)				 ::flixel::graphics::FlxGraphic _hx_tmp = ::Paths_obj::ifImageCached((cacheFile + key));
HXDLIN( 248)				return ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSparrow(_hx_tmp,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + key) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library));
            			}
            			else {
HXLINE( 250)				::String _hx_tmp = ::Paths_obj::image((cacheFile + key),library);
HXDLIN( 250)				return ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSparrow(_hx_tmp,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + key) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library));
            			}
            		}
            		else {
HXLINE( 253)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate asset - ",17,30,f9,e8) + ::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + key) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library))));
            		}
HXLINE( 245)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Paths_obj,getSparrowAtlas,return )

 ::flixel::graphics::frames::FlxAtlasFrames Paths_obj::getNoteAtlas(::String key){
            	HX_STACKFRAME(&_hx_pos_d75e02b628d1544a_259_getNoteAtlas)
HXDLIN( 259)		if (::lime::utils::Assets_obj::exists(::Paths_obj::image((HX_("notes/",ce,dc,b5,31) + key),null()),null())) {
HXLINE( 260)			if (::hx::IsNotNull( ::Paths_obj::ifImageCached(key) )) {
HXLINE( 261)				::String _hx_tmp = ::Paths_obj::image((HX_("notes/",ce,dc,b5,31) + key),null());
HXDLIN( 261)				::String library = null();
HXDLIN( 261)				return ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSparrow(_hx_tmp,::Paths_obj::getPath(((HX_("images/notes/",85,60,c0,8b) + key) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library));
            			}
            			else {
HXLINE( 263)				::String _hx_tmp = ::Paths_obj::image((HX_("notes/",ce,dc,b5,31) + key),null());
HXDLIN( 263)				::String library = null();
HXDLIN( 263)				return ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSparrow(_hx_tmp,::Paths_obj::getPath(((HX_("images/notes/",85,60,c0,8b) + key) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library));
            			}
            		}
            		else {
HXLINE( 265)			::String library = null();
HXDLIN( 265)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate asset - ",17,30,f9,e8) + ::Paths_obj::getPath(((HX_("images/",77,50,74,c1) + key) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library))));
            		}
HXLINE( 259)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Paths_obj,getNoteAtlas,return )

::String Paths_obj::image(::String key,::String library){
            	HX_STACKFRAME(&_hx_pos_d75e02b628d1544a_272_image)
HXDLIN( 272)		if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath(((HX_("images/",77,50,74,c1) + key) + HX_(".png",3b,2d,bd,1e)),HX_("IMAGE",3b,57,57,3b),library),null())) {
HXLINE( 273)			return ::Paths_obj::getPath(((HX_("images/",77,50,74,c1) + key) + HX_(".png",3b,2d,bd,1e)),HX_("IMAGE",3b,57,57,3b),library);
            		}
            		else {
HXLINE( 275)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate asset - ",17,30,f9,e8) + ::Paths_obj::getPath(((HX_("images/",77,50,74,c1) + key) + HX_(".png",3b,2d,bd,1e)),HX_("TEXT",ad,94,ba,37),library))));
            		}
HXLINE( 272)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Paths_obj,image,return )

::String Paths_obj::lua(::String key){
            	HX_STACKFRAME(&_hx_pos_d75e02b628d1544a_281_lua)
HXDLIN( 281)		if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath(((HX_("scripts/",27,8b,98,1a) + key) + HX_(".lua",4a,2a,ba,1e)),HX_("TEXT",ad,94,ba,37),HX_("",00,00,00,00)),null())) {
HXLINE( 282)			return ::Paths_obj::getPath(((HX_("scripts/",27,8b,98,1a) + key) + HX_(".lua",4a,2a,ba,1e)),HX_("TEXT",ad,94,ba,37),HX_("",00,00,00,00));
            		}
            		else {
HXLINE( 284)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate asset - ",17,30,f9,e8) + ::Paths_obj::getPath(((HX_("scripts/",27,8b,98,1a) + key) + HX_(".lua",4a,2a,ba,1e)),HX_("TEXT",ad,94,ba,37),HX_("",00,00,00,00)))));
            		}
HXLINE( 281)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Paths_obj,lua,return )


Paths_obj::Paths_obj()
{
}

bool Paths_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"xml") ) { outValue = xml_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"txt") ) { outValue = txt_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"pak") ) { outValue = pak_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"lua") ) { outValue = lua_dyn(); return true; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"file") ) { outValue = file_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"font") ) { outValue = font_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"mora") ) { outValue = mora_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"json") ) { outValue = json_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"inst") ) { outValue = inst_dyn(); return true; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"sound") ) { outValue = sound_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"music") ) { outValue = music_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"image") ) { outValue = image_dyn(); return true; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"voices") ) { outValue = voices_dyn(); return true; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"modJSON") ) { outValue = ( inCallProp == ::hx::paccAlways ? get_modJSON() : modJSON ); return true; }
		if (HX_FIELD_EQ(inName,"getPath") ) { outValue = getPath_dyn(); return true; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_modJSON") ) { outValue = get_modJSON_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"soundRandom") ) { outValue = soundRandom_dyn(); return true; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"currentLevel") ) { outValue = ( currentLevel ); return true; }
		if (HX_FIELD_EQ(inName,"getNoteAtlas") ) { outValue = getNoteAtlas_dyn(); return true; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"bitLiteralMap") ) { outValue = ( bitLiteralMap ); return true; }
		if (HX_FIELD_EQ(inName,"ifImageCached") ) { outValue = ifImageCached_dyn(); return true; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"cacheEitherWay") ) { outValue = cacheEitherWay_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"getLibraryPath") ) { outValue = getLibraryPath_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"getPreloadPath") ) { outValue = getPreloadPath_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"getPackerAtlas") ) { outValue = getPackerAtlas_dyn(); return true; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"setCurrentLevel") ) { outValue = setCurrentLevel_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"getSparrowAtlas") ) { outValue = getSparrowAtlas_dyn(); return true; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getCharacterFile") ) { outValue = getCharacterFile_dyn(); return true; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"getLibraryPathForce") ) { outValue = getLibraryPathForce_dyn(); return true; }
	}
	return false;
}

bool Paths_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"modJSON") ) { modJSON=ioValue.Cast<  ::Dynamic >(); return true; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"currentLevel") ) { currentLevel=ioValue.Cast< ::String >(); return true; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"bitLiteralMap") ) { bitLiteralMap=ioValue.Cast<  ::haxe::ds::StringMap >(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *Paths_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo Paths_obj_sStaticStorageInfo[] = {
	{::hx::fsString,(void *) &Paths_obj::SOUND_EXT,HX_("SOUND_EXT",b1,35,8c,6f)},
	{::hx::fsObject /*  ::Dynamic */ ,(void *) &Paths_obj::modJSON,HX_("modJSON",ea,a9,7b,db)},
	{::hx::fsObject /*  ::haxe::ds::StringMap */ ,(void *) &Paths_obj::bitLiteralMap,HX_("bitLiteralMap",9a,07,1b,b4)},
	{::hx::fsString,(void *) &Paths_obj::currentLevel,HX_("currentLevel",8b,fa,6e,b9)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static void Paths_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Paths_obj::SOUND_EXT,"SOUND_EXT");
	HX_MARK_MEMBER_NAME(Paths_obj::modJSON,"modJSON");
	HX_MARK_MEMBER_NAME(Paths_obj::bitLiteralMap,"bitLiteralMap");
	HX_MARK_MEMBER_NAME(Paths_obj::currentLevel,"currentLevel");
};

#ifdef HXCPP_VISIT_ALLOCS
static void Paths_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Paths_obj::SOUND_EXT,"SOUND_EXT");
	HX_VISIT_MEMBER_NAME(Paths_obj::modJSON,"modJSON");
	HX_VISIT_MEMBER_NAME(Paths_obj::bitLiteralMap,"bitLiteralMap");
	HX_VISIT_MEMBER_NAME(Paths_obj::currentLevel,"currentLevel");
};

#endif

::hx::Class Paths_obj::__mClass;

static ::String Paths_obj_sStaticFields[] = {
	HX_("SOUND_EXT",b1,35,8c,6f),
	HX_("modJSON",ea,a9,7b,db),
	HX_("bitLiteralMap",9a,07,1b,b4),
	HX_("currentLevel",8b,fa,6e,b9),
	HX_("cacheEitherWay",48,c2,69,8c),
	HX_("get_modJSON",01,0a,76,61),
	HX_("setCurrentLevel",4d,cd,24,d8),
	HX_("getPath",5b,95,d4,1c),
	HX_("getLibraryPath",4a,25,d8,33),
	HX_("getLibraryPathForce",41,90,ac,3f),
	HX_("getPreloadPath",18,c5,46,7e),
	HX_("file",7c,ce,bb,43),
	HX_("xml",d7,6d,5b,00),
	HX_("soundRandom",32,28,bc,6a),
	HX_("font",cf,5d,c0,43),
	HX_("mora",91,df,60,48),
	HX_("txt",70,6e,58,00),
	HX_("pak",5a,51,55,00),
	HX_("json",28,42,68,46),
	HX_("getPackerAtlas",ef,b2,47,f7),
	HX_("sound",cf,8c,cc,80),
	HX_("music",a5,d0,5a,10),
	HX_("voices",81,d6,49,5d),
	HX_("inst",c6,43,bb,45),
	HX_("ifImageCached",c0,28,9e,ab),
	HX_("getCharacterFile",4f,08,c9,a6),
	HX_("getSparrowAtlas",55,ab,b7,a7),
	HX_("getNoteAtlas",83,34,c1,73),
	HX_("image",5b,1f,69,bd),
	HX_("lua",b8,59,52,00),
	::String(null())
};

void Paths_obj::__register()
{
	Paths_obj _hx_dummy;
	Paths_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("Paths",0e,7b,84,50);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Paths_obj::__GetStatic;
	__mClass->mSetStaticField = &Paths_obj::__SetStatic;
	__mClass->mMarkFunc = Paths_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(Paths_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< Paths_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = Paths_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Paths_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Paths_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void Paths_obj::__boot()
{
{
            	HX_STACKFRAME(&_hx_pos_d75e02b628d1544a_21_boot)
HXDLIN(  21)		SOUND_EXT = HX_("ogg",4f,94,54,00);
            	}
{
            	HX_GC_STACKFRAME(&_hx_pos_d75e02b628d1544a_25_boot)
HXDLIN(  25)		bitLiteralMap =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
            	}
}

