#include <hxcpp.h>

#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_lime_app_Future
#include <lime/app/Future.h>
#endif
#ifndef INCLUDED_lime_graphics_Image
#include <lime/graphics/Image.h>
#endif
#ifndef INCLUDED_lime_media_AudioBuffer
#include <lime/media/AudioBuffer.h>
#endif
#ifndef INCLUDED_lime_net__HTTPRequest_AbstractHTTPRequest
#include <lime/net/_HTTPRequest/AbstractHTTPRequest.h>
#endif
#ifndef INCLUDED_lime_net__HTTPRequest_String
#include <lime/net/_HTTPRequest_String.h>
#endif
#ifndef INCLUDED_lime_net__IHTTPRequest
#include <lime/net/_IHTTPRequest.h>
#endif
#ifndef INCLUDED_lime_text_Font
#include <lime/text/Font.h>
#endif
#ifndef INCLUDED_lime_utils_AssetLibrary
#include <lime/utils/AssetLibrary.h>
#endif
#ifndef INCLUDED_lime_utils__Bytes_Bytes_Impl_
#include <lime/utils/_Bytes/Bytes_Impl_.h>
#endif
#ifndef INCLUDED_polymod_Polymod
#include <polymod/Polymod.h>
#endif
#ifndef INCLUDED_polymod_PolymodConfig
#include <polymod/PolymodConfig.h>
#endif
#ifndef INCLUDED_polymod_backends_IBackend
#include <polymod/backends/IBackend.h>
#endif
#ifndef INCLUDED_polymod_backends_LimeBackend
#include <polymod/backends/LimeBackend.h>
#endif
#ifndef INCLUDED_polymod_backends_LimeModLibrary
#include <polymod/backends/LimeModLibrary.h>
#endif
#ifndef INCLUDED_polymod_backends_PolymodAssetLibrary
#include <polymod/backends/PolymodAssetLibrary.h>
#endif
#ifndef INCLUDED_polymod_fs_IFileSystem
#include <polymod/fs/IFileSystem.h>
#endif
#ifndef INCLUDED_polymod_util_Util
#include <polymod/util/Util.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_83234c3e57483dca_287_new,"polymod.backends.LimeModLibrary","new",0x1dcd2097,"polymod.backends.LimeModLibrary.new","polymod/backends/LimeBackend.hx",287,0xcff7dfd6)
HX_LOCAL_STACK_FRAME(_hx_pos_83234c3e57483dca_297_destroy,"polymod.backends.LimeModLibrary","destroy",0xabf164b1,"polymod.backends.LimeModLibrary.destroy","polymod/backends/LimeBackend.hx",297,0xcff7dfd6)
HX_LOCAL_STACK_FRAME(_hx_pos_83234c3e57483dca_305_getAsset,"polymod.backends.LimeModLibrary","getAsset",0x7c7601e3,"polymod.backends.LimeModLibrary.getAsset","polymod/backends/LimeBackend.hx",305,0xcff7dfd6)
HX_LOCAL_STACK_FRAME(_hx_pos_83234c3e57483dca_335_exists,"polymod.backends.LimeModLibrary","exists",0x99738a05,"polymod.backends.LimeModLibrary.exists","polymod/backends/LimeBackend.hx",335,0xcff7dfd6)
HX_LOCAL_STACK_FRAME(_hx_pos_83234c3e57483dca_368_existsDefault,"polymod.backends.LimeModLibrary","existsDefault",0x8382f13c,"polymod.backends.LimeModLibrary.existsDefault","polymod/backends/LimeBackend.hx",368,0xcff7dfd6)
HX_LOCAL_STACK_FRAME(_hx_pos_83234c3e57483dca_372_getAudioBuffer,"polymod.backends.LimeModLibrary","getAudioBuffer",0xec6c7ea9,"polymod.backends.LimeModLibrary.getAudioBuffer","polymod/backends/LimeBackend.hx",372,0xcff7dfd6)
HX_LOCAL_STACK_FRAME(_hx_pos_83234c3e57483dca_390_getBytes,"polymod.backends.LimeModLibrary","getBytes",0x13d4a05e,"polymod.backends.LimeModLibrary.getBytes","polymod/backends/LimeBackend.hx",390,0xcff7dfd6)
HX_LOCAL_STACK_FRAME(_hx_pos_83234c3e57483dca_409_getFont,"polymod.backends.LimeModLibrary","getFont",0x9dae453c,"polymod.backends.LimeModLibrary.getFont","polymod/backends/LimeBackend.hx",409,0xcff7dfd6)
HX_LOCAL_STACK_FRAME(_hx_pos_83234c3e57483dca_427_getImage,"polymod.backends.LimeModLibrary","getImage",0x13a5b74e,"polymod.backends.LimeModLibrary.getImage","polymod/backends/LimeBackend.hx",427,0xcff7dfd6)
HX_LOCAL_STACK_FRAME(_hx_pos_83234c3e57483dca_445_getPath,"polymod.backends.LimeModLibrary","getPath",0xa43fcd12,"polymod.backends.LimeModLibrary.getPath","polymod/backends/LimeBackend.hx",445,0xcff7dfd6)
HX_LOCAL_STACK_FRAME(_hx_pos_83234c3e57483dca_463_getText,"polymod.backends.LimeModLibrary","getText",0xa6e7b41a,"polymod.backends.LimeModLibrary.getText","polymod/backends/LimeBackend.hx",463,0xcff7dfd6)
HX_LOCAL_STACK_FRAME(_hx_pos_83234c3e57483dca_490_loadBytes,"polymod.backends.LimeModLibrary","loadBytes",0x7b4127dc,"polymod.backends.LimeModLibrary.loadBytes","polymod/backends/LimeBackend.hx",490,0xcff7dfd6)
HX_LOCAL_STACK_FRAME(_hx_pos_83234c3e57483dca_508_loadFont,"polymod.backends.LimeModLibrary","loadFont",0xaac5b77e,"polymod.backends.LimeModLibrary.loadFont","polymod/backends/LimeBackend.hx",508,0xcff7dfd6)
HX_LOCAL_STACK_FRAME(_hx_pos_83234c3e57483dca_534_loadImage,"polymod.backends.LimeModLibrary","loadImage",0x7b123ecc,"polymod.backends.LimeModLibrary.loadImage","polymod/backends/LimeBackend.hx",534,0xcff7dfd6)
HX_LOCAL_STACK_FRAME(_hx_pos_83234c3e57483dca_553_loadAudioBuffer,"polymod.backends.LimeModLibrary","loadAudioBuffer",0xf608b8a7,"polymod.backends.LimeModLibrary.loadAudioBuffer","polymod/backends/LimeBackend.hx",553,0xcff7dfd6)
HX_LOCAL_STACK_FRAME(_hx_pos_83234c3e57483dca_578_loadText,"polymod.backends.LimeModLibrary","loadText",0xb3ff265c,"polymod.backends.LimeModLibrary.loadText","polymod/backends/LimeBackend.hx",578,0xcff7dfd6)
HX_LOCAL_STACK_FRAME(_hx_pos_83234c3e57483dca_598_isLocal,"polymod.backends.LimeModLibrary","isLocal",0x9ce1a4d8,"polymod.backends.LimeModLibrary.isLocal","polymod/backends/LimeBackend.hx",598,0xcff7dfd6)
HX_LOCAL_STACK_FRAME(_hx_pos_83234c3e57483dca_616_list,"polymod.backends.LimeModLibrary","list",0xf45ffc47,"polymod.backends.LimeModLibrary.list","polymod/backends/LimeBackend.hx",616,0xcff7dfd6)
HX_LOCAL_STACK_FRAME(_hx_pos_83234c3e57483dca_247_LimeToPoly,"polymod.backends.LimeModLibrary","LimeToPoly",0x9363ab25,"polymod.backends.LimeModLibrary.LimeToPoly","polymod/backends/LimeBackend.hx",247,0xcff7dfd6)
HX_LOCAL_STACK_FRAME(_hx_pos_83234c3e57483dca_263_PolyToLime,"polymod.backends.LimeModLibrary","PolyToLime",0x8a076e65,"polymod.backends.LimeModLibrary.PolyToLime","polymod/backends/LimeBackend.hx",263,0xcff7dfd6)
namespace polymod{
namespace backends{

void LimeModLibrary_obj::__construct( ::polymod::backends::LimeBackend backend, ::lime::utils::AssetLibrary fallback,::String __o_pathPrefix){
            		::String pathPrefix = __o_pathPrefix;
            		if (::hx::IsNull(__o_pathPrefix)) pathPrefix = HX_("",00,00,00,00);
            	HX_STACKFRAME(&_hx_pos_83234c3e57483dca_287_new)
HXLINE( 288)		this->b = backend;
HXLINE( 289)		this->p = this->b->polymodLibrary;
HXLINE( 290)		this->pathPrefix = pathPrefix;
HXLINE( 291)		this->fallback = fallback;
HXLINE( 292)		this->hasFallback = ::hx::IsNotNull( this->fallback );
HXLINE( 293)		super::__construct();
            	}

Dynamic LimeModLibrary_obj::__CreateEmpty() { return new LimeModLibrary_obj; }

void *LimeModLibrary_obj::_hx_vtable = 0;

Dynamic LimeModLibrary_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< LimeModLibrary_obj > _hx_result = new LimeModLibrary_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return _hx_result;
}

bool LimeModLibrary_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x25654723) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x25654723;
	} else {
		return inClassId==(int)0x333eca03;
	}
}

void LimeModLibrary_obj::destroy(){
            	HX_STACKFRAME(&_hx_pos_83234c3e57483dca_297_destroy)
HXLINE( 298)		this->b = null();
HXLINE( 299)		this->p = null();
HXLINE( 300)		this->fallback = null();
HXLINE( 301)		this->type = null();
            	}


HX_DEFINE_DYNAMIC_FUNC0(LimeModLibrary_obj,destroy,(void))

 ::Dynamic LimeModLibrary_obj::getAsset(::String id,::String type){
            	HX_STACKFRAME(&_hx_pos_83234c3e57483dca_305_getAsset)
HXLINE( 306)		if ((type == HX_("TEXT",ad,94,ba,37))) {
HXLINE( 307)			return this->getText(id);
            		}
HXLINE( 309)		::String symbol_modId;
HXDLIN( 309)		 ::polymod::backends::LimeModLibrary symbol_library;
HXDLIN( 309)		::String id1 = id;
HXDLIN( 309)		 ::haxe::ds::StringMap libs = null();
HXDLIN( 309)		::String symbol_fallbackId = id1;
HXDLIN( 309)		int colonIndex = id1.indexOf(HX_(":",3a,00,00,00),null());
HXDLIN( 309)		::String symbol_lib = id1.substring(0,colonIndex);
HXDLIN( 309)		::String symbol_nakedId = id1.substring((colonIndex + 1),null());
HXDLIN( 309)		symbol_library = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN( 309)		bool _hx_tmp;
HXDLIN( 309)		bool _hx_tmp1;
HXDLIN( 309)		if (::hx::IsNotNull( symbol_library )) {
HXLINE( 309)			_hx_tmp1 = ::hx::IsNotNull( symbol_library->pathPrefix );
            		}
            		else {
HXLINE( 309)			_hx_tmp1 = false;
            		}
HXDLIN( 309)		if (_hx_tmp1) {
HXLINE( 309)			_hx_tmp = (symbol_library->pathPrefix != HX_("",00,00,00,00));
            		}
            		else {
HXLINE( 309)			_hx_tmp = false;
            		}
HXDLIN( 309)		if (_hx_tmp) {
HXLINE( 309)			symbol_modId = (((HX_("",00,00,00,00) + symbol_library->pathPrefix) + HX_("/",2f,00,00,00)) + symbol_nakedId);
            		}
HXDLIN( 309)		symbol_modId = symbol_nakedId;
HXLINE( 312)		 ::polymod::backends::PolymodAssetLibrary _hx_tmp2 = this->p;
HXDLIN( 312)		if (_hx_tmp2->check(symbol_modId,::polymod::backends::LimeModLibrary_obj::LimeToPoly(type))) {
HXLINE( 315)			return this->super::getAsset(id,type);
            		}
            		else {
HXLINE( 317)			if (this->hasFallback) {
HXLINE( 320)				::String localePath = this->p->fileLocale(id);
HXLINE( 321)				if (this->fallback->exists(localePath,null())) {
HXLINE( 322)					return this->fallback->getAsset(localePath,type);
            				}
            				else {
HXLINE( 324)					return this->fallback->getAsset(id,type);
            				}
            			}
            		}
HXLINE( 327)		return null();
            	}


bool LimeModLibrary_obj::exists(::String id,::String type){
            	HX_STACKFRAME(&_hx_pos_83234c3e57483dca_335_exists)
HXLINE( 336)		::String symbol_modId;
HXDLIN( 336)		 ::polymod::backends::LimeModLibrary symbol_library;
HXDLIN( 336)		::String id1 = id;
HXDLIN( 336)		 ::haxe::ds::StringMap libs = null();
HXDLIN( 336)		::String symbol_fallbackId = id1;
HXDLIN( 336)		int colonIndex = id1.indexOf(HX_(":",3a,00,00,00),null());
HXDLIN( 336)		::String symbol_lib = id1.substring(0,colonIndex);
HXDLIN( 336)		::String symbol_nakedId = id1.substring((colonIndex + 1),null());
HXDLIN( 336)		symbol_library = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN( 336)		bool _hx_tmp;
HXDLIN( 336)		bool _hx_tmp1;
HXDLIN( 336)		if (::hx::IsNotNull( symbol_library )) {
HXLINE( 336)			_hx_tmp1 = ::hx::IsNotNull( symbol_library->pathPrefix );
            		}
            		else {
HXLINE( 336)			_hx_tmp1 = false;
            		}
HXDLIN( 336)		if (_hx_tmp1) {
HXLINE( 336)			_hx_tmp = (symbol_library->pathPrefix != HX_("",00,00,00,00));
            		}
            		else {
HXLINE( 336)			_hx_tmp = false;
            		}
HXDLIN( 336)		if (_hx_tmp) {
HXLINE( 336)			symbol_modId = (((HX_("",00,00,00,00) + symbol_library->pathPrefix) + HX_("/",2f,00,00,00)) + symbol_nakedId);
            		}
HXDLIN( 336)		symbol_modId = symbol_nakedId;
HXLINE( 337)		 ::polymod::backends::PolymodAssetLibrary _hx_tmp2 = this->p;
HXDLIN( 337)		if (_hx_tmp2->check(symbol_modId,::polymod::backends::LimeModLibrary_obj::LimeToPoly(type))) {
HXLINE( 340)			return true;
            		}
            		else {
HXLINE( 342)			if (this->hasFallback) {
HXLINE( 345)				return this->existsDefault(id,type);
            			}
            		}
HXLINE( 348)		return false;
            	}


bool LimeModLibrary_obj::existsDefault(::String id,::String type){
            	HX_STACKFRAME(&_hx_pos_83234c3e57483dca_368_existsDefault)
HXDLIN( 368)		return this->fallback->exists(id,type);
            	}


HX_DEFINE_DYNAMIC_FUNC2(LimeModLibrary_obj,existsDefault,return )

 ::lime::media::AudioBuffer LimeModLibrary_obj::getAudioBuffer(::String id){
            	HX_STACKFRAME(&_hx_pos_83234c3e57483dca_372_getAudioBuffer)
HXLINE( 373)		::String symbol_modId;
HXDLIN( 373)		 ::polymod::backends::LimeModLibrary symbol_library;
HXDLIN( 373)		::String id1 = id;
HXDLIN( 373)		 ::haxe::ds::StringMap libs = null();
HXDLIN( 373)		::String symbol_fallbackId = id1;
HXDLIN( 373)		int colonIndex = id1.indexOf(HX_(":",3a,00,00,00),null());
HXDLIN( 373)		::String symbol_lib = id1.substring(0,colonIndex);
HXDLIN( 373)		::String symbol_nakedId = id1.substring((colonIndex + 1),null());
HXDLIN( 373)		symbol_library = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN( 373)		bool _hx_tmp;
HXDLIN( 373)		bool _hx_tmp1;
HXDLIN( 373)		if (::hx::IsNotNull( symbol_library )) {
HXLINE( 373)			_hx_tmp1 = ::hx::IsNotNull( symbol_library->pathPrefix );
            		}
            		else {
HXLINE( 373)			_hx_tmp1 = false;
            		}
HXDLIN( 373)		if (_hx_tmp1) {
HXLINE( 373)			_hx_tmp = (symbol_library->pathPrefix != HX_("",00,00,00,00));
            		}
            		else {
HXLINE( 373)			_hx_tmp = false;
            		}
HXDLIN( 373)		if (_hx_tmp) {
HXLINE( 373)			symbol_modId = (((HX_("",00,00,00,00) + symbol_library->pathPrefix) + HX_("/",2f,00,00,00)) + symbol_nakedId);
            		}
HXDLIN( 373)		symbol_modId = symbol_nakedId;
HXLINE( 374)		if (this->p->check(symbol_modId,null())) {
HXLINE( 376)			::Dynamic _hx_tmp = this->p->fileSystem;
HXDLIN( 376)			return ::lime::media::AudioBuffer_obj::fromBytes(::polymod::fs::IFileSystem_obj::getFileBytes(_hx_tmp,this->p->file(symbol_modId,null())));
            		}
            		else {
HXLINE( 378)			if (this->hasFallback) {
HXLINE( 380)				::String localePath = this->p->fileLocale(id);
HXLINE( 381)				if (this->fallback->exists(localePath,null())) {
HXLINE( 382)					return this->fallback->getAudioBuffer(localePath);
            				}
            				else {
HXLINE( 384)					return this->fallback->getAudioBuffer(id);
            				}
            			}
            		}
HXLINE( 386)		return null();
            	}


 ::haxe::io::Bytes LimeModLibrary_obj::getBytes(::String id){
            	HX_STACKFRAME(&_hx_pos_83234c3e57483dca_390_getBytes)
HXLINE( 391)		::String symbol_modId;
HXDLIN( 391)		 ::polymod::backends::LimeModLibrary symbol_library;
HXDLIN( 391)		::String id1 = id;
HXDLIN( 391)		 ::haxe::ds::StringMap libs = null();
HXDLIN( 391)		::String symbol_fallbackId = id1;
HXDLIN( 391)		int colonIndex = id1.indexOf(HX_(":",3a,00,00,00),null());
HXDLIN( 391)		::String symbol_lib = id1.substring(0,colonIndex);
HXDLIN( 391)		::String symbol_nakedId = id1.substring((colonIndex + 1),null());
HXDLIN( 391)		symbol_library = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN( 391)		bool _hx_tmp;
HXDLIN( 391)		bool _hx_tmp1;
HXDLIN( 391)		if (::hx::IsNotNull( symbol_library )) {
HXLINE( 391)			_hx_tmp1 = ::hx::IsNotNull( symbol_library->pathPrefix );
            		}
            		else {
HXLINE( 391)			_hx_tmp1 = false;
            		}
HXDLIN( 391)		if (_hx_tmp1) {
HXLINE( 391)			_hx_tmp = (symbol_library->pathPrefix != HX_("",00,00,00,00));
            		}
            		else {
HXLINE( 391)			_hx_tmp = false;
            		}
HXDLIN( 391)		if (_hx_tmp) {
HXLINE( 391)			symbol_modId = (((HX_("",00,00,00,00) + symbol_library->pathPrefix) + HX_("/",2f,00,00,00)) + symbol_nakedId);
            		}
HXDLIN( 391)		symbol_modId = symbol_nakedId;
HXLINE( 392)		::String file = this->p->file(symbol_modId,null());
HXLINE( 393)		if (this->p->check(symbol_modId,null())) {
HXLINE( 395)			::Dynamic _hx_tmp = this->p->fileSystem;
HXDLIN( 395)			return ::polymod::fs::IFileSystem_obj::getFileBytes(_hx_tmp,this->p->file(symbol_modId,null()));
            		}
            		else {
HXLINE( 397)			if (this->hasFallback) {
HXLINE( 399)				::String localePath = this->p->fileLocale(id);
HXLINE( 400)				if (this->fallback->exists(localePath,null())) {
HXLINE( 401)					return this->fallback->getBytes(localePath);
            				}
            				else {
HXLINE( 403)					return this->fallback->getBytes(id);
            				}
            			}
            		}
HXLINE( 405)		return null();
            	}


 ::lime::text::Font LimeModLibrary_obj::getFont(::String id){
            	HX_STACKFRAME(&_hx_pos_83234c3e57483dca_409_getFont)
HXLINE( 410)		::String symbol_modId;
HXDLIN( 410)		 ::polymod::backends::LimeModLibrary symbol_library;
HXDLIN( 410)		::String id1 = id;
HXDLIN( 410)		 ::haxe::ds::StringMap libs = null();
HXDLIN( 410)		::String symbol_fallbackId = id1;
HXDLIN( 410)		int colonIndex = id1.indexOf(HX_(":",3a,00,00,00),null());
HXDLIN( 410)		::String symbol_lib = id1.substring(0,colonIndex);
HXDLIN( 410)		::String symbol_nakedId = id1.substring((colonIndex + 1),null());
HXDLIN( 410)		symbol_library = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN( 410)		bool _hx_tmp;
HXDLIN( 410)		bool _hx_tmp1;
HXDLIN( 410)		if (::hx::IsNotNull( symbol_library )) {
HXLINE( 410)			_hx_tmp1 = ::hx::IsNotNull( symbol_library->pathPrefix );
            		}
            		else {
HXLINE( 410)			_hx_tmp1 = false;
            		}
HXDLIN( 410)		if (_hx_tmp1) {
HXLINE( 410)			_hx_tmp = (symbol_library->pathPrefix != HX_("",00,00,00,00));
            		}
            		else {
HXLINE( 410)			_hx_tmp = false;
            		}
HXDLIN( 410)		if (_hx_tmp) {
HXLINE( 410)			symbol_modId = (((HX_("",00,00,00,00) + symbol_library->pathPrefix) + HX_("/",2f,00,00,00)) + symbol_nakedId);
            		}
HXDLIN( 410)		symbol_modId = symbol_nakedId;
HXLINE( 411)		if (this->p->check(symbol_modId,null())) {
HXLINE( 413)			::Dynamic _hx_tmp = this->p->fileSystem;
HXDLIN( 413)			return ::lime::text::Font_obj::fromBytes(::polymod::fs::IFileSystem_obj::getFileBytes(_hx_tmp,this->p->file(symbol_modId,null())));
            		}
            		else {
HXLINE( 415)			if (this->hasFallback) {
HXLINE( 417)				::String localePath = this->p->fileLocale(id);
HXLINE( 418)				if (this->fallback->exists(localePath,null())) {
HXLINE( 419)					return this->fallback->getFont(localePath);
            				}
            				else {
HXLINE( 421)					return this->fallback->getFont(id);
            				}
            			}
            		}
HXLINE( 423)		return null();
            	}


 ::lime::graphics::Image LimeModLibrary_obj::getImage(::String id){
            	HX_STACKFRAME(&_hx_pos_83234c3e57483dca_427_getImage)
HXLINE( 428)		::String symbol_modId;
HXDLIN( 428)		 ::polymod::backends::LimeModLibrary symbol_library;
HXDLIN( 428)		::String id1 = id;
HXDLIN( 428)		 ::haxe::ds::StringMap libs = null();
HXDLIN( 428)		::String symbol_fallbackId = id1;
HXDLIN( 428)		int colonIndex = id1.indexOf(HX_(":",3a,00,00,00),null());
HXDLIN( 428)		::String symbol_lib = id1.substring(0,colonIndex);
HXDLIN( 428)		::String symbol_nakedId = id1.substring((colonIndex + 1),null());
HXDLIN( 428)		symbol_library = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN( 428)		bool _hx_tmp;
HXDLIN( 428)		bool _hx_tmp1;
HXDLIN( 428)		if (::hx::IsNotNull( symbol_library )) {
HXLINE( 428)			_hx_tmp1 = ::hx::IsNotNull( symbol_library->pathPrefix );
            		}
            		else {
HXLINE( 428)			_hx_tmp1 = false;
            		}
HXDLIN( 428)		if (_hx_tmp1) {
HXLINE( 428)			_hx_tmp = (symbol_library->pathPrefix != HX_("",00,00,00,00));
            		}
            		else {
HXLINE( 428)			_hx_tmp = false;
            		}
HXDLIN( 428)		if (_hx_tmp) {
HXLINE( 428)			symbol_modId = (((HX_("",00,00,00,00) + symbol_library->pathPrefix) + HX_("/",2f,00,00,00)) + symbol_nakedId);
            		}
HXDLIN( 428)		symbol_modId = symbol_nakedId;
HXLINE( 429)		if (this->p->check(symbol_modId,null())) {
HXLINE( 431)			::Dynamic _hx_tmp = this->p->fileSystem;
HXDLIN( 431)			return ::lime::graphics::Image_obj::fromBytes(::polymod::fs::IFileSystem_obj::getFileBytes(_hx_tmp,this->p->file(symbol_modId,null())));
            		}
            		else {
HXLINE( 433)			if (this->hasFallback) {
HXLINE( 435)				::String localePath = this->p->fileLocale(id);
HXLINE( 436)				if (this->fallback->exists(localePath,null())) {
HXLINE( 437)					return this->fallback->getImage(localePath);
            				}
            				else {
HXLINE( 439)					return this->fallback->getImage(id);
            				}
            			}
            		}
HXLINE( 441)		return null();
            	}


::String LimeModLibrary_obj::getPath(::String id){
            	HX_STACKFRAME(&_hx_pos_83234c3e57483dca_445_getPath)
HXLINE( 446)		::String symbol_modId;
HXDLIN( 446)		 ::polymod::backends::LimeModLibrary symbol_library;
HXDLIN( 446)		::String id1 = id;
HXDLIN( 446)		 ::haxe::ds::StringMap libs = null();
HXDLIN( 446)		::String symbol_fallbackId = id1;
HXDLIN( 446)		int colonIndex = id1.indexOf(HX_(":",3a,00,00,00),null());
HXDLIN( 446)		::String symbol_lib = id1.substring(0,colonIndex);
HXDLIN( 446)		::String symbol_nakedId = id1.substring((colonIndex + 1),null());
HXDLIN( 446)		symbol_library = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN( 446)		bool _hx_tmp;
HXDLIN( 446)		bool _hx_tmp1;
HXDLIN( 446)		if (::hx::IsNotNull( symbol_library )) {
HXLINE( 446)			_hx_tmp1 = ::hx::IsNotNull( symbol_library->pathPrefix );
            		}
            		else {
HXLINE( 446)			_hx_tmp1 = false;
            		}
HXDLIN( 446)		if (_hx_tmp1) {
HXLINE( 446)			_hx_tmp = (symbol_library->pathPrefix != HX_("",00,00,00,00));
            		}
            		else {
HXLINE( 446)			_hx_tmp = false;
            		}
HXDLIN( 446)		if (_hx_tmp) {
HXLINE( 446)			symbol_modId = (((HX_("",00,00,00,00) + symbol_library->pathPrefix) + HX_("/",2f,00,00,00)) + symbol_nakedId);
            		}
HXDLIN( 446)		symbol_modId = symbol_nakedId;
HXLINE( 447)		if (this->p->check(symbol_modId,null())) {
HXLINE( 449)			return this->p->file(symbol_modId,null());
            		}
            		else {
HXLINE( 451)			if (this->hasFallback) {
HXLINE( 453)				::String localePath = this->p->fileLocale(id);
HXLINE( 454)				if (this->fallback->exists(localePath,null())) {
HXLINE( 455)					return this->fallback->getPath(localePath);
            				}
            				else {
HXLINE( 457)					return this->fallback->getPath(id);
            				}
            			}
            		}
HXLINE( 459)		return null();
            	}


::String LimeModLibrary_obj::getText(::String id){
            	HX_STACKFRAME(&_hx_pos_83234c3e57483dca_463_getText)
HXLINE( 464)		::String symbol_modId;
HXDLIN( 464)		 ::polymod::backends::LimeModLibrary symbol_library;
HXDLIN( 464)		::String id1 = id;
HXDLIN( 464)		 ::haxe::ds::StringMap libs = null();
HXDLIN( 464)		::String symbol_fallbackId = id1;
HXDLIN( 464)		int colonIndex = id1.indexOf(HX_(":",3a,00,00,00),null());
HXDLIN( 464)		::String symbol_lib = id1.substring(0,colonIndex);
HXDLIN( 464)		::String symbol_nakedId = id1.substring((colonIndex + 1),null());
HXDLIN( 464)		symbol_library = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN( 464)		bool _hx_tmp;
HXDLIN( 464)		bool _hx_tmp1;
HXDLIN( 464)		if (::hx::IsNotNull( symbol_library )) {
HXLINE( 464)			_hx_tmp1 = ::hx::IsNotNull( symbol_library->pathPrefix );
            		}
            		else {
HXLINE( 464)			_hx_tmp1 = false;
            		}
HXDLIN( 464)		if (_hx_tmp1) {
HXLINE( 464)			_hx_tmp = (symbol_library->pathPrefix != HX_("",00,00,00,00));
            		}
            		else {
HXLINE( 464)			_hx_tmp = false;
            		}
HXDLIN( 464)		if (_hx_tmp) {
HXLINE( 464)			symbol_modId = (((HX_("",00,00,00,00) + symbol_library->pathPrefix) + HX_("/",2f,00,00,00)) + symbol_nakedId);
            		}
HXDLIN( 464)		symbol_modId = symbol_nakedId;
HXLINE( 465)		::String modText = null();
HXLINE( 466)		if (this->p->check(symbol_modId,null())) {
HXLINE( 469)			modText = this->super::getText(symbol_modId);
            		}
            		else {
HXLINE( 471)			if (this->hasFallback) {
HXLINE( 473)				::String localePath = this->p->fileLocale(id);
HXLINE( 474)				if (this->fallback->exists(localePath,null())) {
HXLINE( 475)					modText = this->fallback->getText(localePath);
            				}
            				else {
HXLINE( 477)					modText = this->fallback->getText(id);
            				}
            			}
            		}
HXLINE( 480)		if (::hx::IsNotNull( modText )) {
HXLINE( 483)			modText = this->p->mergeAndAppendText(id,modText);
            		}
HXLINE( 486)		return modText;
            	}


 ::lime::app::Future LimeModLibrary_obj::loadBytes(::String id){
            	HX_STACKFRAME(&_hx_pos_83234c3e57483dca_490_loadBytes)
HXLINE( 491)		::String symbol_modId;
HXDLIN( 491)		 ::polymod::backends::LimeModLibrary symbol_library;
HXDLIN( 491)		::String id1 = id;
HXDLIN( 491)		 ::haxe::ds::StringMap libs = null();
HXDLIN( 491)		::String symbol_fallbackId = id1;
HXDLIN( 491)		int colonIndex = id1.indexOf(HX_(":",3a,00,00,00),null());
HXDLIN( 491)		::String symbol_lib = id1.substring(0,colonIndex);
HXDLIN( 491)		::String symbol_nakedId = id1.substring((colonIndex + 1),null());
HXDLIN( 491)		symbol_library = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN( 491)		bool _hx_tmp;
HXDLIN( 491)		bool _hx_tmp1;
HXDLIN( 491)		if (::hx::IsNotNull( symbol_library )) {
HXLINE( 491)			_hx_tmp1 = ::hx::IsNotNull( symbol_library->pathPrefix );
            		}
            		else {
HXLINE( 491)			_hx_tmp1 = false;
            		}
HXDLIN( 491)		if (_hx_tmp1) {
HXLINE( 491)			_hx_tmp = (symbol_library->pathPrefix != HX_("",00,00,00,00));
            		}
            		else {
HXLINE( 491)			_hx_tmp = false;
            		}
HXDLIN( 491)		if (_hx_tmp) {
HXLINE( 491)			symbol_modId = (((HX_("",00,00,00,00) + symbol_library->pathPrefix) + HX_("/",2f,00,00,00)) + symbol_nakedId);
            		}
HXDLIN( 491)		symbol_modId = symbol_nakedId;
HXLINE( 492)		if (this->p->check(symbol_modId,null())) {
HXLINE( 494)			return ::lime::utils::_Bytes::Bytes_Impl__obj::loadFromFile(this->p->file(symbol_modId,null()));
            		}
            		else {
HXLINE( 496)			if (this->hasFallback) {
HXLINE( 498)				::String localePath = this->p->fileLocale(id);
HXLINE( 499)				if (this->fallback->exists(localePath,null())) {
HXLINE( 500)					return this->fallback->loadBytes(localePath);
            				}
            				else {
HXLINE( 502)					return this->fallback->loadBytes(id);
            				}
            			}
            		}
HXLINE( 504)		return ::lime::utils::_Bytes::Bytes_Impl__obj::loadFromFile(HX_("",00,00,00,00));
            	}


 ::lime::app::Future LimeModLibrary_obj::loadFont(::String id){
            	HX_STACKFRAME(&_hx_pos_83234c3e57483dca_508_loadFont)
HXLINE( 509)		::String symbol_modId;
HXDLIN( 509)		 ::polymod::backends::LimeModLibrary symbol_library;
HXDLIN( 509)		::String id1 = id;
HXDLIN( 509)		 ::haxe::ds::StringMap libs = null();
HXDLIN( 509)		::String symbol_fallbackId = id1;
HXDLIN( 509)		int colonIndex = id1.indexOf(HX_(":",3a,00,00,00),null());
HXDLIN( 509)		::String symbol_lib = id1.substring(0,colonIndex);
HXDLIN( 509)		::String symbol_nakedId = id1.substring((colonIndex + 1),null());
HXDLIN( 509)		symbol_library = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN( 509)		bool _hx_tmp;
HXDLIN( 509)		bool _hx_tmp1;
HXDLIN( 509)		if (::hx::IsNotNull( symbol_library )) {
HXLINE( 509)			_hx_tmp1 = ::hx::IsNotNull( symbol_library->pathPrefix );
            		}
            		else {
HXLINE( 509)			_hx_tmp1 = false;
            		}
HXDLIN( 509)		if (_hx_tmp1) {
HXLINE( 509)			_hx_tmp = (symbol_library->pathPrefix != HX_("",00,00,00,00));
            		}
            		else {
HXLINE( 509)			_hx_tmp = false;
            		}
HXDLIN( 509)		if (_hx_tmp) {
HXLINE( 509)			symbol_modId = (((HX_("",00,00,00,00) + symbol_library->pathPrefix) + HX_("/",2f,00,00,00)) + symbol_nakedId);
            		}
HXDLIN( 509)		symbol_modId = symbol_nakedId;
HXLINE( 510)		if (this->p->check(symbol_modId,null())) {
HXLINE( 515)			::Dynamic this1 = this->paths;
HXDLIN( 515)			return ::lime::text::Font_obj::loadFromFile(( ( ::haxe::ds::StringMap)(this1) )->get_string(this->p->file(symbol_modId,null())));
            		}
            		else {
HXLINE( 518)			if (this->hasFallback) {
HXLINE( 520)				::String localePath = this->p->fileLocale(id);
HXLINE( 521)				if (this->fallback->exists(localePath,null())) {
HXLINE( 522)					return this->fallback->loadFont(localePath);
            				}
            				else {
HXLINE( 524)					return this->fallback->loadFont(id);
            				}
            			}
            		}
HXLINE( 529)		return ::lime::text::Font_obj::loadFromFile(this->paths->get_string(HX_("",00,00,00,00)));
            	}


 ::lime::app::Future LimeModLibrary_obj::loadImage(::String id){
            	HX_STACKFRAME(&_hx_pos_83234c3e57483dca_534_loadImage)
HXLINE( 535)		::polymod::Polymod_obj::debug(((HX_("LimeModLibrary.loadImage(",b3,5f,aa,b1) + id) + HX_(")",29,00,00,00)),::hx::SourceInfo(HX_("polymod/backends/LimeBackend.hx",d6,df,f7,cf),535,HX_("polymod.backends.LimeModLibrary",25,89,45,45),HX_("loadImage",55,6b,a0,d8)));
HXLINE( 536)		::String symbol_modId;
HXDLIN( 536)		 ::polymod::backends::LimeModLibrary symbol_library;
HXDLIN( 536)		::String id1 = id;
HXDLIN( 536)		 ::haxe::ds::StringMap libs = null();
HXDLIN( 536)		::String symbol_fallbackId = id1;
HXDLIN( 536)		int colonIndex = id1.indexOf(HX_(":",3a,00,00,00),null());
HXDLIN( 536)		::String symbol_lib = id1.substring(0,colonIndex);
HXDLIN( 536)		::String symbol_nakedId = id1.substring((colonIndex + 1),null());
HXDLIN( 536)		symbol_library = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN( 536)		bool _hx_tmp;
HXDLIN( 536)		bool _hx_tmp1;
HXDLIN( 536)		if (::hx::IsNotNull( symbol_library )) {
HXLINE( 536)			_hx_tmp1 = ::hx::IsNotNull( symbol_library->pathPrefix );
            		}
            		else {
HXLINE( 536)			_hx_tmp1 = false;
            		}
HXDLIN( 536)		if (_hx_tmp1) {
HXLINE( 536)			_hx_tmp = (symbol_library->pathPrefix != HX_("",00,00,00,00));
            		}
            		else {
HXLINE( 536)			_hx_tmp = false;
            		}
HXDLIN( 536)		if (_hx_tmp) {
HXLINE( 536)			symbol_modId = (((HX_("",00,00,00,00) + symbol_library->pathPrefix) + HX_("/",2f,00,00,00)) + symbol_nakedId);
            		}
HXDLIN( 536)		symbol_modId = symbol_nakedId;
HXLINE( 537)		if (this->p->check(symbol_modId,null())) {
HXLINE( 539)			return ::lime::graphics::Image_obj::loadFromFile(this->p->file(symbol_modId,null()));
            		}
            		else {
HXLINE( 541)			if (this->hasFallback) {
HXLINE( 543)				::String localePath = this->p->fileLocale(id);
HXLINE( 544)				if (this->fallback->exists(localePath,null())) {
HXLINE( 545)					return this->fallback->loadImage(localePath);
            				}
            				else {
HXLINE( 547)					return this->fallback->loadImage(id);
            				}
            			}
            		}
HXLINE( 549)		return ::lime::graphics::Image_obj::loadFromFile(HX_("",00,00,00,00));
            	}


 ::lime::app::Future LimeModLibrary_obj::loadAudioBuffer(::String id){
            	HX_STACKFRAME(&_hx_pos_83234c3e57483dca_553_loadAudioBuffer)
HXLINE( 554)		::String symbol_modId;
HXDLIN( 554)		 ::polymod::backends::LimeModLibrary symbol_library;
HXDLIN( 554)		::String id1 = id;
HXDLIN( 554)		 ::haxe::ds::StringMap libs = null();
HXDLIN( 554)		::String symbol_fallbackId = id1;
HXDLIN( 554)		int colonIndex = id1.indexOf(HX_(":",3a,00,00,00),null());
HXDLIN( 554)		::String symbol_lib = id1.substring(0,colonIndex);
HXDLIN( 554)		::String symbol_nakedId = id1.substring((colonIndex + 1),null());
HXDLIN( 554)		symbol_library = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN( 554)		bool _hx_tmp;
HXDLIN( 554)		bool _hx_tmp1;
HXDLIN( 554)		if (::hx::IsNotNull( symbol_library )) {
HXLINE( 554)			_hx_tmp1 = ::hx::IsNotNull( symbol_library->pathPrefix );
            		}
            		else {
HXLINE( 554)			_hx_tmp1 = false;
            		}
HXDLIN( 554)		if (_hx_tmp1) {
HXLINE( 554)			_hx_tmp = (symbol_library->pathPrefix != HX_("",00,00,00,00));
            		}
            		else {
HXLINE( 554)			_hx_tmp = false;
            		}
HXDLIN( 554)		if (_hx_tmp) {
HXLINE( 554)			symbol_modId = (((HX_("",00,00,00,00) + symbol_library->pathPrefix) + HX_("/",2f,00,00,00)) + symbol_nakedId);
            		}
HXDLIN( 554)		symbol_modId = symbol_nakedId;
HXLINE( 555)		if (this->p->check(symbol_modId,null())) {
HXLINE( 557)			::Dynamic this1 = this->pathGroups;
HXDLIN( 557)			if (( ( ::haxe::ds::StringMap)(this1) )->exists(this->p->file(symbol_modId,null()))) {
HXLINE( 559)				::Dynamic this1 = this->pathGroups;
HXDLIN( 559)				return ::lime::media::AudioBuffer_obj::loadFromFiles(( (::Array< ::String >)(( ( ::haxe::ds::StringMap)(this1) )->get(this->p->file(symbol_modId,null()))) ));
            			}
            			else {
HXLINE( 563)				::Dynamic this1 = this->paths;
HXDLIN( 563)				return ::lime::media::AudioBuffer_obj::loadFromFile(( ( ::haxe::ds::StringMap)(this1) )->get_string(this->p->file(symbol_modId,null())));
            			}
            		}
            		else {
HXLINE( 566)			if (this->hasFallback) {
HXLINE( 568)				::String localePath = this->p->fileLocale(id);
HXLINE( 569)				if (this->fallback->exists(localePath,null())) {
HXLINE( 570)					return this->fallback->loadAudioBuffer(localePath);
            				}
            				else {
HXLINE( 572)					return this->fallback->loadAudioBuffer(id);
            				}
            			}
            		}
HXLINE( 574)		return ::lime::media::AudioBuffer_obj::loadFromFile(HX_("",00,00,00,00));
            	}


 ::lime::app::Future LimeModLibrary_obj::loadText(::String id){
            	HX_GC_STACKFRAME(&_hx_pos_83234c3e57483dca_578_loadText)
HXLINE( 579)		::String symbol_modId;
HXDLIN( 579)		 ::polymod::backends::LimeModLibrary symbol_library;
HXDLIN( 579)		::String id1 = id;
HXDLIN( 579)		 ::haxe::ds::StringMap libs = null();
HXDLIN( 579)		::String symbol_fallbackId = id1;
HXDLIN( 579)		int colonIndex = id1.indexOf(HX_(":",3a,00,00,00),null());
HXDLIN( 579)		::String symbol_lib = id1.substring(0,colonIndex);
HXDLIN( 579)		::String symbol_nakedId = id1.substring((colonIndex + 1),null());
HXDLIN( 579)		symbol_library = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN( 579)		bool _hx_tmp;
HXDLIN( 579)		bool _hx_tmp1;
HXDLIN( 579)		if (::hx::IsNotNull( symbol_library )) {
HXLINE( 579)			_hx_tmp1 = ::hx::IsNotNull( symbol_library->pathPrefix );
            		}
            		else {
HXLINE( 579)			_hx_tmp1 = false;
            		}
HXDLIN( 579)		if (_hx_tmp1) {
HXLINE( 579)			_hx_tmp = (symbol_library->pathPrefix != HX_("",00,00,00,00));
            		}
            		else {
HXLINE( 579)			_hx_tmp = false;
            		}
HXDLIN( 579)		if (_hx_tmp) {
HXLINE( 579)			symbol_modId = (((HX_("",00,00,00,00) + symbol_library->pathPrefix) + HX_("/",2f,00,00,00)) + symbol_nakedId);
            		}
HXDLIN( 579)		symbol_modId = symbol_nakedId;
HXLINE( 580)		if (this->p->check(symbol_modId,null())) {
HXLINE( 582)			 ::lime::net::_HTTPRequest_String request =  ::lime::net::_HTTPRequest_String_obj::__alloc( HX_CTX ,null());
HXLINE( 583)			::Dynamic this1 = this->paths;
HXDLIN( 583)			return request->load(( ( ::haxe::ds::StringMap)(this1) )->get_string(this->p->file(symbol_modId,null())));
            		}
            		else {
HXLINE( 585)			if (this->hasFallback) {
HXLINE( 587)				::String localePath = this->p->fileLocale(id);
HXLINE( 588)				if (this->fallback->exists(localePath,null())) {
HXLINE( 589)					return this->fallback->loadText(localePath);
            				}
            				else {
HXLINE( 591)					return this->fallback->loadText(id);
            				}
            			}
            		}
HXLINE( 593)		 ::lime::net::_HTTPRequest_String request =  ::lime::net::_HTTPRequest_String_obj::__alloc( HX_CTX ,null());
HXLINE( 594)		return request->load(HX_("",00,00,00,00));
            	}


bool LimeModLibrary_obj::isLocal(::String id,::String type){
            	HX_STACKFRAME(&_hx_pos_83234c3e57483dca_598_isLocal)
HXLINE( 599)		::String symbol_modId;
HXDLIN( 599)		 ::polymod::backends::LimeModLibrary symbol_library;
HXDLIN( 599)		::String id1 = id;
HXDLIN( 599)		 ::haxe::ds::StringMap libs = null();
HXDLIN( 599)		::String symbol_fallbackId = id1;
HXDLIN( 599)		int colonIndex = id1.indexOf(HX_(":",3a,00,00,00),null());
HXDLIN( 599)		::String symbol_lib = id1.substring(0,colonIndex);
HXDLIN( 599)		::String symbol_nakedId = id1.substring((colonIndex + 1),null());
HXDLIN( 599)		symbol_library = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN( 599)		bool _hx_tmp;
HXDLIN( 599)		bool _hx_tmp1;
HXDLIN( 599)		if (::hx::IsNotNull( symbol_library )) {
HXLINE( 599)			_hx_tmp1 = ::hx::IsNotNull( symbol_library->pathPrefix );
            		}
            		else {
HXLINE( 599)			_hx_tmp1 = false;
            		}
HXDLIN( 599)		if (_hx_tmp1) {
HXLINE( 599)			_hx_tmp = (symbol_library->pathPrefix != HX_("",00,00,00,00));
            		}
            		else {
HXLINE( 599)			_hx_tmp = false;
            		}
HXDLIN( 599)		if (_hx_tmp) {
HXLINE( 599)			symbol_modId = (((HX_("",00,00,00,00) + symbol_library->pathPrefix) + HX_("/",2f,00,00,00)) + symbol_nakedId);
            		}
HXDLIN( 599)		symbol_modId = symbol_nakedId;
HXLINE( 600)		if (this->p->check(symbol_modId,null())) {
HXLINE( 602)			return true;
            		}
            		else {
HXLINE( 604)			if (this->hasFallback) {
HXLINE( 606)				::String localePath = this->p->fileLocale(id);
HXLINE( 607)				if (this->fallback->exists(localePath,null())) {
HXLINE( 608)					return this->fallback->isLocal(localePath,type);
            				}
            				else {
HXLINE( 610)					return this->fallback->isLocal(id,type);
            				}
            			}
            		}
HXLINE( 612)		return false;
            	}


::Array< ::String > LimeModLibrary_obj::list(::String type){
            	HX_STACKFRAME(&_hx_pos_83234c3e57483dca_616_list)
HXLINE( 617)		::Array< ::String > fallbackList;
HXDLIN( 617)		if (this->hasFallback) {
HXLINE( 617)			fallbackList = this->fallback->list(type);
            		}
            		else {
HXLINE( 617)			fallbackList = ::Array_obj< ::String >::__new(0);
            		}
HXLINE( 619)		::String requestedType;
HXDLIN( 619)		if (::hx::IsNotNull( type )) {
HXLINE( 619)			requestedType = type;
            		}
            		else {
HXLINE( 619)			requestedType = null();
            		}
HXLINE( 620)		::Array< ::String > items = ::Array_obj< ::String >::__new(0);
HXLINE( 622)		{
HXLINE( 622)			 ::Dynamic id = this->p->type->keys();
HXDLIN( 622)			while(( (bool)(id->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE( 622)				::String id1 = ( (::String)(id->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXLINE( 624)				bool _hx_tmp;
HXDLIN( 624)				if (!(::StringTools_obj::startsWith(id1,::polymod::PolymodConfig_obj::get_appendFolder()))) {
HXLINE( 624)					_hx_tmp = ::StringTools_obj::startsWith(id1,::polymod::PolymodConfig_obj::get_mergeFolder());
            				}
            				else {
HXLINE( 624)					_hx_tmp = true;
            				}
HXDLIN( 624)				if (_hx_tmp) {
HXLINE( 625)					continue;
            				}
HXLINE( 637)				bool _hx_tmp1;
HXDLIN( 637)				if (::hx::IsNotNull( requestedType )) {
HXLINE( 637)					_hx_tmp1 = this->exists(id1,requestedType);
            				}
            				else {
HXLINE( 637)					_hx_tmp1 = true;
            				}
HXDLIN( 637)				if (_hx_tmp1) {
HXLINE( 639)					items->push(this->p->prependAssetsPrefix(id1));
            				}
            			}
            		}
HXLINE( 648)		{
HXLINE( 648)			int _g = 0;
HXDLIN( 648)			while((_g < fallbackList->length)){
HXLINE( 648)				::String fallbackId = fallbackList->__get(_g);
HXDLIN( 648)				_g = (_g + 1);
HXLINE( 689)				::String assetId = fallbackId;
HXLINE( 690)				bool _hx_tmp;
HXDLIN( 690)				if (::hx::IsNotNull( requestedType )) {
HXLINE( 690)					_hx_tmp = this->fallback->exists(assetId,type);
            				}
            				else {
HXLINE( 690)					_hx_tmp = true;
            				}
HXDLIN( 690)				if (_hx_tmp) {
HXLINE( 692)					items->push(assetId);
            				}
            			}
            		}
HXLINE( 697)		return ::polymod::util::Util_obj::filterUnique_String(items);
            	}


::String LimeModLibrary_obj::LimeToPoly(::String type){
            	HX_STACKFRAME(&_hx_pos_83234c3e57483dca_247_LimeToPoly)
HXDLIN( 247)		::String _hx_switch_0 = type;
            		if (  (_hx_switch_0==HX_("BINARY",01,68,8e,9f)) ){
HXLINE( 249)			return HX_("BYTES",4b,40,86,3b);
HXDLIN( 249)			goto _hx_goto_20;
            		}
            		if (  (_hx_switch_0==HX_("FONT",cf,25,81,2e)) ){
HXLINE( 250)			return HX_("FONT",cf,25,81,2e);
HXDLIN( 250)			goto _hx_goto_20;
            		}
            		if (  (_hx_switch_0==HX_("IMAGE",3b,57,57,3b)) ){
HXLINE( 251)			return HX_("IMAGE",3b,57,57,3b);
HXDLIN( 251)			goto _hx_goto_20;
            		}
            		if (  (_hx_switch_0==HX_("MANIFEST",af,8b,af,29)) ){
HXLINE( 254)			return HX_("MANIFEST",af,8b,af,29);
HXDLIN( 254)			goto _hx_goto_20;
            		}
            		if (  (_hx_switch_0==HX_("MUSIC",85,08,49,8e)) ){
HXLINE( 252)			return HX_("AUDIO_MUSIC",fc,6c,05,48);
HXDLIN( 252)			goto _hx_goto_20;
            		}
            		if (  (_hx_switch_0==HX_("SOUND",af,c4,ba,fe)) ){
HXLINE( 253)			return HX_("AUDIO_SOUND",26,29,77,b8);
HXDLIN( 253)			goto _hx_goto_20;
            		}
            		if (  (_hx_switch_0==HX_("TEMPLATE",3a,78,cd,05)) ){
HXLINE( 255)			return HX_("TEMPLATE",3a,78,cd,05);
HXDLIN( 255)			goto _hx_goto_20;
            		}
            		if (  (_hx_switch_0==HX_("TEXT",ad,94,ba,37)) ){
HXLINE( 256)			return HX_("TEXT",ad,94,ba,37);
HXDLIN( 256)			goto _hx_goto_20;
            		}
            		/* default */{
HXLINE( 257)			return HX_("UNKNOWN",6a,f7,4e,61);
            		}
            		_hx_goto_20:;
HXLINE( 247)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(LimeModLibrary_obj,LimeToPoly,return )

::String LimeModLibrary_obj::PolyToLime(::String type){
            	HX_STACKFRAME(&_hx_pos_83234c3e57483dca_263_PolyToLime)
HXDLIN( 263)		::String _hx_switch_0 = type;
            		if (  (_hx_switch_0==HX_("AUDIO_GENERIC",2e,f6,26,23)) ){
HXLINE( 270)			return HX_("SOUND",af,c4,ba,fe);
HXDLIN( 270)			goto _hx_goto_22;
            		}
            		if (  (_hx_switch_0==HX_("AUDIO_MUSIC",fc,6c,05,48)) ){
HXLINE( 268)			return HX_("MUSIC",85,08,49,8e);
HXDLIN( 268)			goto _hx_goto_22;
            		}
            		if (  (_hx_switch_0==HX_("AUDIO_SOUND",26,29,77,b8)) ){
HXLINE( 269)			return HX_("SOUND",af,c4,ba,fe);
HXDLIN( 269)			goto _hx_goto_22;
            		}
            		if (  (_hx_switch_0==HX_("BYTES",4b,40,86,3b)) ){
HXLINE( 265)			return HX_("BINARY",01,68,8e,9f);
HXDLIN( 265)			goto _hx_goto_22;
            		}
            		if (  (_hx_switch_0==HX_("FONT",cf,25,81,2e)) ){
HXLINE( 266)			return HX_("FONT",cf,25,81,2e);
HXDLIN( 266)			goto _hx_goto_22;
            		}
            		if (  (_hx_switch_0==HX_("IMAGE",3b,57,57,3b)) ){
HXLINE( 267)			return HX_("IMAGE",3b,57,57,3b);
HXDLIN( 267)			goto _hx_goto_22;
            		}
            		if (  (_hx_switch_0==HX_("MANIFEST",af,8b,af,29)) ){
HXLINE( 271)			return HX_("MANIFEST",af,8b,af,29);
HXDLIN( 271)			goto _hx_goto_22;
            		}
            		if (  (_hx_switch_0==HX_("TEMPLATE",3a,78,cd,05)) ){
HXLINE( 272)			return HX_("TEMPLATE",3a,78,cd,05);
HXDLIN( 272)			goto _hx_goto_22;
            		}
            		if (  (_hx_switch_0==HX_("TEXT",ad,94,ba,37)) ){
HXLINE( 273)			return HX_("TEXT",ad,94,ba,37);
HXDLIN( 273)			goto _hx_goto_22;
            		}
            		/* default */{
HXLINE( 274)			return HX_("BINARY",01,68,8e,9f);
            		}
            		_hx_goto_22:;
HXLINE( 263)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(LimeModLibrary_obj,PolyToLime,return )


::hx::ObjectPtr< LimeModLibrary_obj > LimeModLibrary_obj::__new( ::polymod::backends::LimeBackend backend, ::lime::utils::AssetLibrary fallback,::String __o_pathPrefix) {
	::hx::ObjectPtr< LimeModLibrary_obj > __this = new LimeModLibrary_obj();
	__this->__construct(backend,fallback,__o_pathPrefix);
	return __this;
}

::hx::ObjectPtr< LimeModLibrary_obj > LimeModLibrary_obj::__alloc(::hx::Ctx *_hx_ctx, ::polymod::backends::LimeBackend backend, ::lime::utils::AssetLibrary fallback,::String __o_pathPrefix) {
	LimeModLibrary_obj *__this = (LimeModLibrary_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(LimeModLibrary_obj), true, "polymod.backends.LimeModLibrary"));
	*(void **)__this = LimeModLibrary_obj::_hx_vtable;
	__this->__construct(backend,fallback,__o_pathPrefix);
	return __this;
}

LimeModLibrary_obj::LimeModLibrary_obj()
{
}

void LimeModLibrary_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(LimeModLibrary);
	HX_MARK_MEMBER_NAME(pathPrefix,"pathPrefix");
	HX_MARK_MEMBER_NAME(b,"b");
	HX_MARK_MEMBER_NAME(p,"p");
	HX_MARK_MEMBER_NAME(fallback,"fallback");
	HX_MARK_MEMBER_NAME(hasFallback,"hasFallback");
	HX_MARK_MEMBER_NAME(type,"type");
	 ::lime::utils::AssetLibrary_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void LimeModLibrary_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(pathPrefix,"pathPrefix");
	HX_VISIT_MEMBER_NAME(b,"b");
	HX_VISIT_MEMBER_NAME(p,"p");
	HX_VISIT_MEMBER_NAME(fallback,"fallback");
	HX_VISIT_MEMBER_NAME(hasFallback,"hasFallback");
	HX_VISIT_MEMBER_NAME(type,"type");
	 ::lime::utils::AssetLibrary_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val LimeModLibrary_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"b") ) { return ::hx::Val( b ); }
		if (HX_FIELD_EQ(inName,"p") ) { return ::hx::Val( p ); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { return ::hx::Val( type ); }
		if (HX_FIELD_EQ(inName,"list") ) { return ::hx::Val( list_dyn() ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"exists") ) { return ::hx::Val( exists_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return ::hx::Val( destroy_dyn() ); }
		if (HX_FIELD_EQ(inName,"getFont") ) { return ::hx::Val( getFont_dyn() ); }
		if (HX_FIELD_EQ(inName,"getPath") ) { return ::hx::Val( getPath_dyn() ); }
		if (HX_FIELD_EQ(inName,"getText") ) { return ::hx::Val( getText_dyn() ); }
		if (HX_FIELD_EQ(inName,"isLocal") ) { return ::hx::Val( isLocal_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"fallback") ) { return ::hx::Val( fallback ); }
		if (HX_FIELD_EQ(inName,"getAsset") ) { return ::hx::Val( getAsset_dyn() ); }
		if (HX_FIELD_EQ(inName,"getBytes") ) { return ::hx::Val( getBytes_dyn() ); }
		if (HX_FIELD_EQ(inName,"getImage") ) { return ::hx::Val( getImage_dyn() ); }
		if (HX_FIELD_EQ(inName,"loadFont") ) { return ::hx::Val( loadFont_dyn() ); }
		if (HX_FIELD_EQ(inName,"loadText") ) { return ::hx::Val( loadText_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"loadBytes") ) { return ::hx::Val( loadBytes_dyn() ); }
		if (HX_FIELD_EQ(inName,"loadImage") ) { return ::hx::Val( loadImage_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"pathPrefix") ) { return ::hx::Val( pathPrefix ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"hasFallback") ) { return ::hx::Val( hasFallback ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"existsDefault") ) { return ::hx::Val( existsDefault_dyn() ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getAudioBuffer") ) { return ::hx::Val( getAudioBuffer_dyn() ); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"loadAudioBuffer") ) { return ::hx::Val( loadAudioBuffer_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

bool LimeModLibrary_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"LimeToPoly") ) { outValue = LimeToPoly_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"PolyToLime") ) { outValue = PolyToLime_dyn(); return true; }
	}
	return false;
}

::hx::Val LimeModLibrary_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"b") ) { b=inValue.Cast<  ::polymod::backends::LimeBackend >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p") ) { p=inValue.Cast<  ::polymod::backends::PolymodAssetLibrary >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { type=inValue.Cast<  ::haxe::ds::StringMap >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"fallback") ) { fallback=inValue.Cast<  ::lime::utils::AssetLibrary >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"pathPrefix") ) { pathPrefix=inValue.Cast< ::String >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"hasFallback") ) { hasFallback=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void LimeModLibrary_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("pathPrefix",17,7d,ec,c0));
	outFields->push(HX_("b",62,00,00,00));
	outFields->push(HX_("p",70,00,00,00));
	outFields->push(HX_("fallback",22,f0,9d,2a));
	outFields->push(HX_("hasFallback",9c,d5,54,fd));
	outFields->push(HX_("type",ba,f2,08,4d));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo LimeModLibrary_obj_sMemberStorageInfo[] = {
	{::hx::fsString,(int)offsetof(LimeModLibrary_obj,pathPrefix),HX_("pathPrefix",17,7d,ec,c0)},
	{::hx::fsObject /*  ::polymod::backends::LimeBackend */ ,(int)offsetof(LimeModLibrary_obj,b),HX_("b",62,00,00,00)},
	{::hx::fsObject /*  ::polymod::backends::PolymodAssetLibrary */ ,(int)offsetof(LimeModLibrary_obj,p),HX_("p",70,00,00,00)},
	{::hx::fsObject /*  ::lime::utils::AssetLibrary */ ,(int)offsetof(LimeModLibrary_obj,fallback),HX_("fallback",22,f0,9d,2a)},
	{::hx::fsBool,(int)offsetof(LimeModLibrary_obj,hasFallback),HX_("hasFallback",9c,d5,54,fd)},
	{::hx::fsObject /*  ::haxe::ds::StringMap */ ,(int)offsetof(LimeModLibrary_obj,type),HX_("type",ba,f2,08,4d)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *LimeModLibrary_obj_sStaticStorageInfo = 0;
#endif

static ::String LimeModLibrary_obj_sMemberFields[] = {
	HX_("pathPrefix",17,7d,ec,c0),
	HX_("b",62,00,00,00),
	HX_("p",70,00,00,00),
	HX_("fallback",22,f0,9d,2a),
	HX_("hasFallback",9c,d5,54,fd),
	HX_("type",ba,f2,08,4d),
	HX_("destroy",fa,2c,86,24),
	HX_("getAsset",7a,79,10,86),
	HX_("exists",dc,1d,e0,bf),
	HX_("existsDefault",45,96,7c,43),
	HX_("getAudioBuffer",80,41,e3,26),
	HX_("getBytes",f5,17,6f,1d),
	HX_("getFont",85,0d,43,16),
	HX_("getImage",e5,2e,40,1d),
	HX_("getPath",5b,95,d4,1c),
	HX_("getText",63,7c,7c,1f),
	HX_("loadBytes",65,54,cf,d8),
	HX_("loadFont",15,2f,60,b4),
	HX_("loadImage",55,6b,a0,d8),
	HX_("loadAudioBuffer",f0,71,7c,e3),
	HX_("loadText",f3,9d,99,bd),
	HX_("isLocal",21,6d,76,15),
	HX_("list",5e,1c,b3,47),
	::String(null()) };

::hx::Class LimeModLibrary_obj::__mClass;

static ::String LimeModLibrary_obj_sStaticFields[] = {
	HX_("LimeToPoly",7c,76,3c,12),
	HX_("PolyToLime",bc,39,e0,08),
	::String(null())
};

void LimeModLibrary_obj::__register()
{
	LimeModLibrary_obj _hx_dummy;
	LimeModLibrary_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("polymod.backends.LimeModLibrary",25,89,45,45);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &LimeModLibrary_obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(LimeModLibrary_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(LimeModLibrary_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< LimeModLibrary_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = LimeModLibrary_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = LimeModLibrary_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace polymod
} // end namespace backends
