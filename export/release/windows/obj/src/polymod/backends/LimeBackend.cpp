#include <hxcpp.h>

#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_lime_utils_AssetCache
#include <lime/utils/AssetCache.h>
#endif
#ifndef INCLUDED_lime_utils_AssetLibrary
#include <lime/utils/AssetLibrary.h>
#endif
#ifndef INCLUDED_lime_utils_Assets
#include <lime/utils/Assets.h>
#endif
#ifndef INCLUDED_polymod_Polymod
#include <polymod/Polymod.h>
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

HX_DEFINE_STACK_FRAME(_hx_pos_dd7fd4041224ec8d_87_new,"polymod.backends.LimeBackend","new",0x58b914ba,"polymod.backends.LimeBackend.new","polymod/backends/LimeBackend.hx",87,0xcff7dfd6)
HX_LOCAL_STACK_FRAME(_hx_pos_dd7fd4041224ec8d_91_init,"polymod.backends.LimeBackend","init",0x45f1c576,"polymod.backends.LimeBackend.init","polymod/backends/LimeBackend.hx",91,0xcff7dfd6)
HX_LOCAL_STACK_FRAME(_hx_pos_dd7fd4041224ec8d_162_getModLibrary,"polymod.backends.LimeBackend","getModLibrary",0x229dc969,"polymod.backends.LimeBackend.getModLibrary","polymod/backends/LimeBackend.hx",162,0xcff7dfd6)
HX_LOCAL_STACK_FRAME(_hx_pos_dd7fd4041224ec8d_170_destroy,"polymod.backends.LimeBackend","destroy",0x24eda654,"polymod.backends.LimeBackend.destroy","polymod/backends/LimeBackend.hx",170,0xcff7dfd6)
HX_LOCAL_STACK_FRAME(_hx_pos_dd7fd4041224ec8d_183_exists,"polymod.backends.LimeBackend","exists",0x229a8dc2,"polymod.backends.LimeBackend.exists","polymod/backends/LimeBackend.hx",183,0xcff7dfd6)
HX_LOCAL_STACK_FRAME(_hx_pos_dd7fd4041224ec8d_190_getBytes,"polymod.backends.LimeBackend","getBytes",0x7791cd5b,"polymod.backends.LimeBackend.getBytes","polymod/backends/LimeBackend.hx",190,0xcff7dfd6)
HX_LOCAL_STACK_FRAME(_hx_pos_dd7fd4041224ec8d_197_getText,"polymod.backends.LimeBackend","getText",0x1fe3f5bd,"polymod.backends.LimeBackend.getText","polymod/backends/LimeBackend.hx",197,0xcff7dfd6)
HX_LOCAL_STACK_FRAME(_hx_pos_dd7fd4041224ec8d_204_getPath,"polymod.backends.LimeBackend","getPath",0x1d3c0eb5,"polymod.backends.LimeBackend.getPath","polymod/backends/LimeBackend.hx",204,0xcff7dfd6)
HX_LOCAL_STACK_FRAME(_hx_pos_dd7fd4041224ec8d_211_list,"polymod.backends.LimeBackend","list",0x47e9a6c4,"polymod.backends.LimeBackend.list","polymod/backends/LimeBackend.hx",211,0xcff7dfd6)
HX_LOCAL_STACK_FRAME(_hx_pos_dd7fd4041224ec8d_225_clearCache,"polymod.backends.LimeBackend","clearCache",0x4666345b,"polymod.backends.LimeBackend.clearCache","polymod/backends/LimeBackend.hx",225,0xcff7dfd6)
HX_LOCAL_STACK_FRAME(_hx_pos_dd7fd4041224ec8d_51_getDefaultAssetLibraries,"polymod.backends.LimeBackend","getDefaultAssetLibraries",0x999a899a,"polymod.backends.LimeBackend.getDefaultAssetLibraries","polymod/backends/LimeBackend.hx",51,0xcff7dfd6)
HX_LOCAL_STACK_FRAME(_hx_pos_dd7fd4041224ec8d_73_restoreDefaultAssetLibraries,"polymod.backends.LimeBackend","restoreDefaultAssetLibraries",0xaed402e2,"polymod.backends.LimeBackend.restoreDefaultAssetLibraries","polymod/backends/LimeBackend.hx",73,0xcff7dfd6)
namespace polymod{
namespace backends{

void LimeBackend_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_dd7fd4041224ec8d_87_new)
            	}

Dynamic LimeBackend_obj::__CreateEmpty() { return new LimeBackend_obj; }

void *LimeBackend_obj::_hx_vtable = 0;

Dynamic LimeBackend_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< LimeBackend_obj > _hx_result = new LimeBackend_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool LimeBackend_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x7a28a88e;
}

static ::polymod::backends::IBackend_obj _hx_polymod_backends_LimeBackend__hx_polymod_backends_IBackend= {
	( bool (::hx::Object::*)( ::Dynamic))&::polymod::backends::LimeBackend_obj::init,
	( void (::hx::Object::*)())&::polymod::backends::LimeBackend_obj::destroy,
	( void (::hx::Object::*)())&::polymod::backends::LimeBackend_obj::clearCache,
	( bool (::hx::Object::*)(::String))&::polymod::backends::LimeBackend_obj::exists,
	(  ::haxe::io::Bytes (::hx::Object::*)(::String))&::polymod::backends::LimeBackend_obj::getBytes,
	( ::String (::hx::Object::*)(::String))&::polymod::backends::LimeBackend_obj::getText,
	( ::String (::hx::Object::*)(::String))&::polymod::backends::LimeBackend_obj::getPath,
	( ::Array< ::String > (::hx::Object::*)(::String))&::polymod::backends::LimeBackend_obj::list,
};

void *LimeBackend_obj::_hx_getInterface(int inHash) {
	switch(inHash) {
		case (int)0x4ed455e0: return &_hx_polymod_backends_LimeBackend__hx_polymod_backends_IBackend;
	}
	#ifdef HXCPP_SCRIPTABLE
	return super::_hx_getInterface(inHash);
	#else
	return 0;
	#endif
}

bool LimeBackend_obj::init( ::Dynamic params){
            	HX_GC_STACKFRAME(&_hx_pos_dd7fd4041224ec8d_91_init)
HXLINE(  93)		 ::haxe::ds::StringMap defaultLibraries = ::polymod::backends::LimeBackend_obj::getDefaultAssetLibraries();
HXLINE(  95)		this->modLibraries =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
HXLINE(  97)		bool hasMoreThanDefault = false;
HXLINE(  98)		{
HXLINE(  98)			 ::Dynamic key = defaultLibraries->keys();
HXDLIN(  98)			while(( (bool)(key->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE(  98)				::String key1 = ( (::String)(key->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXLINE( 100)				if ((key1 != HX_("default",c1,d8,c3,9b))) {
HXLINE( 102)					hasMoreThanDefault = true;
HXLINE( 103)					goto _hx_goto_1;
            				}
            			}
            			_hx_goto_1:;
            		}
HXLINE( 107)		if (::hx::IsNull( params )) {
HXLINE( 110)			params =  ::Dynamic(::hx::Anon_obj::Create(0));
            		}
HXLINE( 113)		bool _hx_tmp;
HXDLIN( 113)		if (hasMoreThanDefault) {
HXLINE( 113)			_hx_tmp = ::hx::IsNull( params->__Field(HX_("assetLibraryPaths",43,04,19,3e),::hx::paccDynamic) );
            		}
            		else {
HXLINE( 113)			_hx_tmp = false;
            		}
HXDLIN( 113)		if (_hx_tmp) {
HXLINE( 115)			::polymod::Polymod_obj::error(HX_("lime_missing_asset_library_info",04,f7,5a,a0),HX_("Your Lime/OpenFL configuration is using custom asset libraries, but you have not provided the frameworkParams.assetLibraryPaths parameter in Polymod.init() that tells Polymod which asset libraries to expect and what their mod sub-directory prefixes should be.",10,70,c8,1a),HX_("init",10,3b,bb,45));
HXLINE( 118)			return false;
            		}
HXLINE( 122)		{
HXLINE( 122)			 ::Dynamic key1 = defaultLibraries->keys();
HXDLIN( 122)			while(( (bool)(key1->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE( 122)				::String key = ( (::String)(key1->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXLINE( 124)				::String pathPrefix = HX_("",00,00,00,00);
HXLINE( 125)				if (hasMoreThanDefault) {
HXLINE( 127)					bool _hx_tmp;
HXDLIN( 127)					if (!(( ( ::haxe::ds::StringMap)( ::Dynamic(params->__Field(HX_("assetLibraryPaths",43,04,19,3e),::hx::paccDynamic))) )->exists(key))) {
HXLINE( 127)						_hx_tmp = (key != HX_("default",c1,d8,c3,9b));
            					}
            					else {
HXLINE( 127)						_hx_tmp = false;
            					}
HXDLIN( 127)					if (_hx_tmp) {
HXLINE( 129)						::polymod::Polymod_obj::error(HX_("lime_missing_asset_library_reference",75,a9,dc,e7),((HX_("Your Lime/OpenFL configuration is using custom asset libraries, and you provided frameworkParams in Polymod.init(), but we couldn't find a match for this asset library: (",d0,a8,8f,c6) + key) + HX_(")",29,00,00,00)),HX_("init",10,3b,bb,45));
HXLINE( 133)						return false;
            					}
            					else {
HXLINE( 137)						if ((key == HX_("default",c1,d8,c3,9b))) {
HXLINE( 139)							pathPrefix = HX_("",00,00,00,00);
            						}
            						else {
HXLINE( 143)							pathPrefix = ( ( ::haxe::ds::StringMap)( ::Dynamic(params->__Field(HX_("assetLibraryPaths",43,04,19,3e),::hx::paccDynamic))) )->get_string(key);
            						}
            					}
            				}
HXLINE( 147)				 ::lime::utils::AssetLibrary fallbackLibrary = ( ( ::lime::utils::AssetLibrary)(defaultLibraries->get(key)) );
HXLINE( 148)				 ::polymod::backends::LimeModLibrary modLibrary = this->getModLibrary(fallbackLibrary,pathPrefix);
HXLINE( 149)				this->modLibraries->set(key,modLibrary);
            			}
            		}
HXLINE( 152)		{
HXLINE( 152)			 ::Dynamic key2 = this->modLibraries->keys();
HXDLIN( 152)			while(( (bool)(key2->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE( 152)				::String key = ( (::String)(key2->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXLINE( 154)				::lime::utils::Assets_obj::registerLibrary(key,( ( ::lime::utils::AssetLibrary)(this->modLibraries->get(key)) ));
            			}
            		}
HXLINE( 157)		return true;
            	}


HX_DEFINE_DYNAMIC_FUNC1(LimeBackend_obj,init,return )

 ::polymod::backends::LimeModLibrary LimeBackend_obj::getModLibrary( ::lime::utils::AssetLibrary fallbackLibrary,::String pathPrefix){
            	HX_GC_STACKFRAME(&_hx_pos_dd7fd4041224ec8d_162_getModLibrary)
HXDLIN( 162)		return  ::polymod::backends::LimeModLibrary_obj::__alloc( HX_CTX ,::hx::ObjectPtr<OBJ_>(this),fallbackLibrary,pathPrefix);
            	}


HX_DEFINE_DYNAMIC_FUNC2(LimeBackend_obj,getModLibrary,return )

void LimeBackend_obj::destroy(){
            	HX_STACKFRAME(&_hx_pos_dd7fd4041224ec8d_170_destroy)
HXLINE( 171)		this->polymodLibrary = null();
HXLINE( 172)		::polymod::backends::LimeBackend_obj::restoreDefaultAssetLibraries();
HXLINE( 173)		{
HXLINE( 173)			 ::Dynamic key = this->modLibraries->keys();
HXDLIN( 173)			while(( (bool)(key->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE( 173)				::String key1 = ( (::String)(key->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXLINE( 175)				 ::polymod::backends::LimeModLibrary modLibrary = ( ( ::polymod::backends::LimeModLibrary)(this->modLibraries->get(key1)) );
HXLINE( 176)				modLibrary->destroy();
HXLINE( 177)				this->modLibraries->remove(key1);
            			}
            		}
HXLINE( 179)		this->modLibraries = null();
            	}


HX_DEFINE_DYNAMIC_FUNC0(LimeBackend_obj,destroy,(void))

bool LimeBackend_obj::exists(::String id){
            	HX_STACKFRAME(&_hx_pos_dd7fd4041224ec8d_183_exists)
HXLINE( 184)		::String symbol_modId;
HXDLIN( 184)		 ::polymod::backends::LimeModLibrary symbol_library;
HXDLIN( 184)		::String id1 = id;
HXDLIN( 184)		 ::haxe::ds::StringMap libs = this->modLibraries;
HXDLIN( 184)		 ::polymod::backends::LimeModLibrary l = null();
HXDLIN( 184)		::String symbol_fallbackId = id1;
HXDLIN( 184)		int colonIndex = id1.indexOf(HX_(":",3a,00,00,00),null());
HXDLIN( 184)		::String symbol_lib = id1.substring(0,colonIndex);
HXDLIN( 184)		::String symbol_nakedId = id1.substring((colonIndex + 1),null());
HXDLIN( 184)		if (::hx::IsNotNull( l )) {
HXLINE( 184)			symbol_library = l;
            		}
            		else {
HXLINE( 184)			if (::hx::IsNotNull( libs )) {
HXLINE( 184)				bool _hx_tmp;
HXDLIN( 184)				if ((symbol_lib != HX_("",00,00,00,00))) {
HXLINE( 184)					_hx_tmp = ::hx::IsNull( symbol_lib );
            				}
            				else {
HXLINE( 184)					_hx_tmp = true;
            				}
HXDLIN( 184)				if (_hx_tmp) {
HXLINE( 184)					symbol_lib = HX_("default",c1,d8,c3,9b);
            				}
HXDLIN( 184)				symbol_library = ( ( ::polymod::backends::LimeModLibrary)(libs->get(symbol_lib)) );
            			}
            		}
HXDLIN( 184)		bool _hx_tmp;
HXDLIN( 184)		bool _hx_tmp1;
HXDLIN( 184)		if (::hx::IsNotNull( symbol_library )) {
HXLINE( 184)			_hx_tmp1 = ::hx::IsNotNull( symbol_library->pathPrefix );
            		}
            		else {
HXLINE( 184)			_hx_tmp1 = false;
            		}
HXDLIN( 184)		if (_hx_tmp1) {
HXLINE( 184)			_hx_tmp = (symbol_library->pathPrefix != HX_("",00,00,00,00));
            		}
            		else {
HXLINE( 184)			_hx_tmp = false;
            		}
HXDLIN( 184)		if (_hx_tmp) {
HXLINE( 184)			symbol_modId = (((HX_("",00,00,00,00) + symbol_library->pathPrefix) + HX_("/",2f,00,00,00)) + symbol_nakedId);
            		}
HXDLIN( 184)		symbol_modId = symbol_nakedId;
HXLINE( 185)		bool e = symbol_library->exists(symbol_modId,null());
HXLINE( 186)		return e;
            	}


HX_DEFINE_DYNAMIC_FUNC1(LimeBackend_obj,exists,return )

 ::haxe::io::Bytes LimeBackend_obj::getBytes(::String id){
            	HX_STACKFRAME(&_hx_pos_dd7fd4041224ec8d_190_getBytes)
HXLINE( 191)		::String symbol_modId;
HXDLIN( 191)		 ::polymod::backends::LimeModLibrary symbol_library;
HXDLIN( 191)		::String id1 = id;
HXDLIN( 191)		 ::haxe::ds::StringMap libs = this->modLibraries;
HXDLIN( 191)		 ::polymod::backends::LimeModLibrary l = null();
HXDLIN( 191)		::String symbol_fallbackId = id1;
HXDLIN( 191)		int colonIndex = id1.indexOf(HX_(":",3a,00,00,00),null());
HXDLIN( 191)		::String symbol_lib = id1.substring(0,colonIndex);
HXDLIN( 191)		::String symbol_nakedId = id1.substring((colonIndex + 1),null());
HXDLIN( 191)		if (::hx::IsNotNull( l )) {
HXLINE( 191)			symbol_library = l;
            		}
            		else {
HXLINE( 191)			if (::hx::IsNotNull( libs )) {
HXLINE( 191)				bool _hx_tmp;
HXDLIN( 191)				if ((symbol_lib != HX_("",00,00,00,00))) {
HXLINE( 191)					_hx_tmp = ::hx::IsNull( symbol_lib );
            				}
            				else {
HXLINE( 191)					_hx_tmp = true;
            				}
HXDLIN( 191)				if (_hx_tmp) {
HXLINE( 191)					symbol_lib = HX_("default",c1,d8,c3,9b);
            				}
HXDLIN( 191)				symbol_library = ( ( ::polymod::backends::LimeModLibrary)(libs->get(symbol_lib)) );
            			}
            		}
HXDLIN( 191)		bool _hx_tmp;
HXDLIN( 191)		bool _hx_tmp1;
HXDLIN( 191)		if (::hx::IsNotNull( symbol_library )) {
HXLINE( 191)			_hx_tmp1 = ::hx::IsNotNull( symbol_library->pathPrefix );
            		}
            		else {
HXLINE( 191)			_hx_tmp1 = false;
            		}
HXDLIN( 191)		if (_hx_tmp1) {
HXLINE( 191)			_hx_tmp = (symbol_library->pathPrefix != HX_("",00,00,00,00));
            		}
            		else {
HXLINE( 191)			_hx_tmp = false;
            		}
HXDLIN( 191)		if (_hx_tmp) {
HXLINE( 191)			symbol_modId = (((HX_("",00,00,00,00) + symbol_library->pathPrefix) + HX_("/",2f,00,00,00)) + symbol_nakedId);
            		}
HXDLIN( 191)		symbol_modId = symbol_nakedId;
HXLINE( 192)		 ::haxe::io::Bytes bytes = symbol_library->getBytes(symbol_modId);
HXLINE( 193)		return bytes;
            	}


HX_DEFINE_DYNAMIC_FUNC1(LimeBackend_obj,getBytes,return )

::String LimeBackend_obj::getText(::String id){
            	HX_STACKFRAME(&_hx_pos_dd7fd4041224ec8d_197_getText)
HXLINE( 198)		::String symbol_modId;
HXDLIN( 198)		 ::polymod::backends::LimeModLibrary symbol_library;
HXDLIN( 198)		::String id1 = id;
HXDLIN( 198)		 ::haxe::ds::StringMap libs = this->modLibraries;
HXDLIN( 198)		 ::polymod::backends::LimeModLibrary l = null();
HXDLIN( 198)		::String symbol_fallbackId = id1;
HXDLIN( 198)		int colonIndex = id1.indexOf(HX_(":",3a,00,00,00),null());
HXDLIN( 198)		::String symbol_lib = id1.substring(0,colonIndex);
HXDLIN( 198)		::String symbol_nakedId = id1.substring((colonIndex + 1),null());
HXDLIN( 198)		if (::hx::IsNotNull( l )) {
HXLINE( 198)			symbol_library = l;
            		}
            		else {
HXLINE( 198)			if (::hx::IsNotNull( libs )) {
HXLINE( 198)				bool _hx_tmp;
HXDLIN( 198)				if ((symbol_lib != HX_("",00,00,00,00))) {
HXLINE( 198)					_hx_tmp = ::hx::IsNull( symbol_lib );
            				}
            				else {
HXLINE( 198)					_hx_tmp = true;
            				}
HXDLIN( 198)				if (_hx_tmp) {
HXLINE( 198)					symbol_lib = HX_("default",c1,d8,c3,9b);
            				}
HXDLIN( 198)				symbol_library = ( ( ::polymod::backends::LimeModLibrary)(libs->get(symbol_lib)) );
            			}
            		}
HXDLIN( 198)		bool _hx_tmp;
HXDLIN( 198)		bool _hx_tmp1;
HXDLIN( 198)		if (::hx::IsNotNull( symbol_library )) {
HXLINE( 198)			_hx_tmp1 = ::hx::IsNotNull( symbol_library->pathPrefix );
            		}
            		else {
HXLINE( 198)			_hx_tmp1 = false;
            		}
HXDLIN( 198)		if (_hx_tmp1) {
HXLINE( 198)			_hx_tmp = (symbol_library->pathPrefix != HX_("",00,00,00,00));
            		}
            		else {
HXLINE( 198)			_hx_tmp = false;
            		}
HXDLIN( 198)		if (_hx_tmp) {
HXLINE( 198)			symbol_modId = (((HX_("",00,00,00,00) + symbol_library->pathPrefix) + HX_("/",2f,00,00,00)) + symbol_nakedId);
            		}
HXDLIN( 198)		symbol_modId = symbol_nakedId;
HXLINE( 199)		::String text = symbol_library->getText(symbol_modId);
HXLINE( 200)		return text;
            	}


HX_DEFINE_DYNAMIC_FUNC1(LimeBackend_obj,getText,return )

::String LimeBackend_obj::getPath(::String id){
            	HX_STACKFRAME(&_hx_pos_dd7fd4041224ec8d_204_getPath)
HXLINE( 205)		::String symbol_modId;
HXDLIN( 205)		 ::polymod::backends::LimeModLibrary symbol_library;
HXDLIN( 205)		::String id1 = id;
HXDLIN( 205)		 ::haxe::ds::StringMap libs = this->modLibraries;
HXDLIN( 205)		 ::polymod::backends::LimeModLibrary l = null();
HXDLIN( 205)		::String symbol_fallbackId = id1;
HXDLIN( 205)		int colonIndex = id1.indexOf(HX_(":",3a,00,00,00),null());
HXDLIN( 205)		::String symbol_lib = id1.substring(0,colonIndex);
HXDLIN( 205)		::String symbol_nakedId = id1.substring((colonIndex + 1),null());
HXDLIN( 205)		if (::hx::IsNotNull( l )) {
HXLINE( 205)			symbol_library = l;
            		}
            		else {
HXLINE( 205)			if (::hx::IsNotNull( libs )) {
HXLINE( 205)				bool _hx_tmp;
HXDLIN( 205)				if ((symbol_lib != HX_("",00,00,00,00))) {
HXLINE( 205)					_hx_tmp = ::hx::IsNull( symbol_lib );
            				}
            				else {
HXLINE( 205)					_hx_tmp = true;
            				}
HXDLIN( 205)				if (_hx_tmp) {
HXLINE( 205)					symbol_lib = HX_("default",c1,d8,c3,9b);
            				}
HXDLIN( 205)				symbol_library = ( ( ::polymod::backends::LimeModLibrary)(libs->get(symbol_lib)) );
            			}
            		}
HXDLIN( 205)		bool _hx_tmp;
HXDLIN( 205)		bool _hx_tmp1;
HXDLIN( 205)		if (::hx::IsNotNull( symbol_library )) {
HXLINE( 205)			_hx_tmp1 = ::hx::IsNotNull( symbol_library->pathPrefix );
            		}
            		else {
HXLINE( 205)			_hx_tmp1 = false;
            		}
HXDLIN( 205)		if (_hx_tmp1) {
HXLINE( 205)			_hx_tmp = (symbol_library->pathPrefix != HX_("",00,00,00,00));
            		}
            		else {
HXLINE( 205)			_hx_tmp = false;
            		}
HXDLIN( 205)		if (_hx_tmp) {
HXLINE( 205)			symbol_modId = (((HX_("",00,00,00,00) + symbol_library->pathPrefix) + HX_("/",2f,00,00,00)) + symbol_nakedId);
            		}
HXDLIN( 205)		symbol_modId = symbol_nakedId;
HXLINE( 206)		::String path = symbol_library->getPath(symbol_modId);
HXLINE( 207)		return path;
            	}


HX_DEFINE_DYNAMIC_FUNC1(LimeBackend_obj,getPath,return )

::Array< ::String > LimeBackend_obj::list(::String type){
            	HX_STACKFRAME(&_hx_pos_dd7fd4041224ec8d_211_list)
HXLINE( 212)		if (::hx::IsNull( this->modLibraries )) {
HXLINE( 213)			return ::Array_obj< ::String >::__new(0);
            		}
HXLINE( 215)		::Array< ::String > arr = ::Array_obj< ::String >::__new(0);
HXLINE( 216)		{
HXLINE( 216)			 ::Dynamic modLibrary = this->modLibraries->iterator();
HXDLIN( 216)			while(( (bool)(modLibrary->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE( 216)				 ::polymod::backends::LimeModLibrary modLibrary1 = ( ( ::polymod::backends::LimeModLibrary)(modLibrary->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXLINE( 218)				::String arr1;
HXDLIN( 218)				if (::hx::IsNull( type )) {
HXLINE( 218)					arr1 = null();
            				}
            				else {
HXLINE( 218)					arr1 = ::polymod::backends::LimeModLibrary_obj::PolyToLime(type);
            				}
HXDLIN( 218)				arr = arr->concat(modLibrary1->list(arr1));
            			}
            		}
HXLINE( 220)		return arr;
            	}


HX_DEFINE_DYNAMIC_FUNC1(LimeBackend_obj,list,return )

void LimeBackend_obj::clearCache(){
            	HX_STACKFRAME(&_hx_pos_dd7fd4041224ec8d_225_clearCache)
HXDLIN( 225)		if (::hx::IsNotNull( ::polymod::backends::LimeBackend_obj::defaultAssetLibraries )) {
HXLINE( 227)			{
HXLINE( 227)				 ::Dynamic key = ::lime::utils::Assets_obj::cache->audio->keys();
HXDLIN( 227)				while(( (bool)(key->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE( 227)					::String key1 = ( (::String)(key->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXLINE( 229)					::lime::utils::Assets_obj::cache->audio->remove(key1);
            				}
            			}
HXLINE( 231)			{
HXLINE( 231)				 ::Dynamic key1 = ::lime::utils::Assets_obj::cache->font->keys();
HXDLIN( 231)				while(( (bool)(key1->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE( 231)					::String key = ( (::String)(key1->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXLINE( 233)					::lime::utils::Assets_obj::cache->font->remove(key);
            				}
            			}
HXLINE( 235)			{
HXLINE( 235)				 ::Dynamic key2 = ::lime::utils::Assets_obj::cache->image->keys();
HXDLIN( 235)				while(( (bool)(key2->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE( 235)					::String key = ( (::String)(key2->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXLINE( 237)					::lime::utils::Assets_obj::cache->image->remove(key);
            				}
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC0(LimeBackend_obj,clearCache,(void))

 ::haxe::ds::StringMap LimeBackend_obj::defaultAssetLibraries;

 ::haxe::ds::StringMap LimeBackend_obj::getDefaultAssetLibraries(){
            	HX_GC_STACKFRAME(&_hx_pos_dd7fd4041224ec8d_51_getDefaultAssetLibraries)
HXLINE(  52)		if (::hx::IsNull( ::polymod::backends::LimeBackend_obj::defaultAssetLibraries )) {
HXLINE(  54)			::polymod::backends::LimeBackend_obj::defaultAssetLibraries =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
HXLINE(  57)			 ::haxe::ds::StringMap libraries = ::lime::utils::Assets_obj::libraries;
HXLINE(  60)			{
HXLINE(  60)				 ::Dynamic key = libraries->keys();
HXDLIN(  60)				while(( (bool)(key->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE(  60)					::String key1 = ( (::String)(key->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXLINE(  62)					{
HXLINE(  62)						::Dynamic this1 = ::polymod::backends::LimeBackend_obj::defaultAssetLibraries;
HXDLIN(  62)						( ( ::haxe::ds::StringMap)(this1) )->set(key1,::lime::utils::Assets_obj::getLibrary(key1));
            					}
            				}
            			}
            		}
HXLINE(  65)		return ::polymod::backends::LimeBackend_obj::defaultAssetLibraries;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(LimeBackend_obj,getDefaultAssetLibraries,return )

void LimeBackend_obj::restoreDefaultAssetLibraries(){
            	HX_STACKFRAME(&_hx_pos_dd7fd4041224ec8d_73_restoreDefaultAssetLibraries)
HXDLIN(  73)		if (::hx::IsNotNull( ::polymod::backends::LimeBackend_obj::defaultAssetLibraries )) {
HXLINE(  75)			 ::Dynamic key = ::polymod::backends::LimeBackend_obj::defaultAssetLibraries->keys();
HXDLIN(  75)			while(( (bool)(key->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE(  75)				::String key1 = ( (::String)(key->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXLINE(  77)				::lime::utils::Assets_obj::registerLibrary(key1,( ( ::lime::utils::AssetLibrary)(::polymod::backends::LimeBackend_obj::defaultAssetLibraries->get(key1)) ));
            			}
            		}
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(LimeBackend_obj,restoreDefaultAssetLibraries,(void))


::hx::ObjectPtr< LimeBackend_obj > LimeBackend_obj::__new() {
	::hx::ObjectPtr< LimeBackend_obj > __this = new LimeBackend_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< LimeBackend_obj > LimeBackend_obj::__alloc(::hx::Ctx *_hx_ctx) {
	LimeBackend_obj *__this = (LimeBackend_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(LimeBackend_obj), true, "polymod.backends.LimeBackend"));
	*(void **)__this = LimeBackend_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

LimeBackend_obj::LimeBackend_obj()
{
}

void LimeBackend_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(LimeBackend);
	HX_MARK_MEMBER_NAME(polymodLibrary,"polymodLibrary");
	HX_MARK_MEMBER_NAME(modLibraries,"modLibraries");
	HX_MARK_END_CLASS();
}

void LimeBackend_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(polymodLibrary,"polymodLibrary");
	HX_VISIT_MEMBER_NAME(modLibraries,"modLibraries");
}

::hx::Val LimeBackend_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { return ::hx::Val( init_dyn() ); }
		if (HX_FIELD_EQ(inName,"list") ) { return ::hx::Val( list_dyn() ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"exists") ) { return ::hx::Val( exists_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return ::hx::Val( destroy_dyn() ); }
		if (HX_FIELD_EQ(inName,"getText") ) { return ::hx::Val( getText_dyn() ); }
		if (HX_FIELD_EQ(inName,"getPath") ) { return ::hx::Val( getPath_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getBytes") ) { return ::hx::Val( getBytes_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"clearCache") ) { return ::hx::Val( clearCache_dyn() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"modLibraries") ) { return ::hx::Val( modLibraries ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"getModLibrary") ) { return ::hx::Val( getModLibrary_dyn() ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"polymodLibrary") ) { return ::hx::Val( polymodLibrary ); }
	}
	return super::__Field(inName,inCallProp);
}

bool LimeBackend_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 21:
		if (HX_FIELD_EQ(inName,"defaultAssetLibraries") ) { outValue = ( defaultAssetLibraries ); return true; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"getDefaultAssetLibraries") ) { outValue = getDefaultAssetLibraries_dyn(); return true; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"restoreDefaultAssetLibraries") ) { outValue = restoreDefaultAssetLibraries_dyn(); return true; }
	}
	return false;
}

::hx::Val LimeBackend_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"modLibraries") ) { modLibraries=inValue.Cast<  ::haxe::ds::StringMap >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"polymodLibrary") ) { polymodLibrary=inValue.Cast<  ::polymod::backends::PolymodAssetLibrary >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool LimeBackend_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 21:
		if (HX_FIELD_EQ(inName,"defaultAssetLibraries") ) { defaultAssetLibraries=ioValue.Cast<  ::haxe::ds::StringMap >(); return true; }
	}
	return false;
}

void LimeBackend_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("polymodLibrary",a5,49,05,cb));
	outFields->push(HX_("modLibraries",f7,30,d4,b6));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo LimeBackend_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::polymod::backends::PolymodAssetLibrary */ ,(int)offsetof(LimeBackend_obj,polymodLibrary),HX_("polymodLibrary",a5,49,05,cb)},
	{::hx::fsObject /*  ::haxe::ds::StringMap */ ,(int)offsetof(LimeBackend_obj,modLibraries),HX_("modLibraries",f7,30,d4,b6)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo LimeBackend_obj_sStaticStorageInfo[] = {
	{::hx::fsObject /*  ::haxe::ds::StringMap */ ,(void *) &LimeBackend_obj::defaultAssetLibraries,HX_("defaultAssetLibraries",aa,e4,43,2c)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static ::String LimeBackend_obj_sMemberFields[] = {
	HX_("polymodLibrary",a5,49,05,cb),
	HX_("modLibraries",f7,30,d4,b6),
	HX_("init",10,3b,bb,45),
	HX_("getModLibrary",8f,d0,49,17),
	HX_("destroy",fa,2c,86,24),
	HX_("exists",dc,1d,e0,bf),
	HX_("getBytes",f5,17,6f,1d),
	HX_("getText",63,7c,7c,1f),
	HX_("getPath",5b,95,d4,1c),
	HX_("list",5e,1c,b3,47),
	HX_("clearCache",75,d9,1e,16),
	::String(null()) };

static void LimeBackend_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(LimeBackend_obj::defaultAssetLibraries,"defaultAssetLibraries");
};

#ifdef HXCPP_VISIT_ALLOCS
static void LimeBackend_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(LimeBackend_obj::defaultAssetLibraries,"defaultAssetLibraries");
};

#endif

::hx::Class LimeBackend_obj::__mClass;

static ::String LimeBackend_obj_sStaticFields[] = {
	HX_("defaultAssetLibraries",aa,e4,43,2c),
	HX_("getDefaultAssetLibraries",34,28,d8,ca),
	HX_("restoreDefaultAssetLibraries",7c,f6,ed,bd),
	::String(null())
};

void LimeBackend_obj::__register()
{
	LimeBackend_obj _hx_dummy;
	LimeBackend_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("polymod.backends.LimeBackend",c8,ef,b5,4e);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &LimeBackend_obj::__GetStatic;
	__mClass->mSetStaticField = &LimeBackend_obj::__SetStatic;
	__mClass->mMarkFunc = LimeBackend_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(LimeBackend_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(LimeBackend_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< LimeBackend_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = LimeBackend_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = LimeBackend_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = LimeBackend_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace polymod
} // end namespace backends
