#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_Exception
#include <haxe/Exception.h>
#endif
#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_polymod_Framework
#include <polymod/Framework.h>
#endif
#ifndef INCLUDED_polymod_ModMetadata
#include <polymod/ModMetadata.h>
#endif
#ifndef INCLUDED_polymod_Polymod
#include <polymod/Polymod.h>
#endif
#ifndef INCLUDED_polymod_PolymodConfig
#include <polymod/PolymodConfig.h>
#endif
#ifndef INCLUDED_polymod_PolymodError
#include <polymod/PolymodError.h>
#endif
#ifndef INCLUDED_polymod_PolymodErrorType
#include <polymod/PolymodErrorType.h>
#endif
#ifndef INCLUDED_polymod_backends_PolymodAssetLibrary
#include <polymod/backends/PolymodAssetLibrary.h>
#endif
#ifndef INCLUDED_polymod_backends_PolymodAssets
#include <polymod/backends/PolymodAssets.h>
#endif
#ifndef INCLUDED_polymod_format_ParseRules
#include <polymod/format/ParseRules.h>
#endif
#ifndef INCLUDED_polymod_fs_IFileSystem
#include <polymod/fs/IFileSystem.h>
#endif
#ifndef INCLUDED_polymod_fs_PolymodFileSystem
#include <polymod/fs/PolymodFileSystem.h>
#endif
#ifndef INCLUDED_polymod_hscript_PolymodScriptClass
#include <polymod/hscript/PolymodScriptClass.h>
#endif
#ifndef INCLUDED_polymod_util_SemanticVersion
#include <polymod/util/SemanticVersion.h>
#endif
#ifndef INCLUDED_polymod_util_Util
#include <polymod/util/Util.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_321500f50b2e3bfa_159_init,"polymod.Polymod","init",0x00ecc620,"polymod.Polymod.init","polymod/Polymod.hx",159,0xd80c6d61)
HX_LOCAL_STACK_FRAME(_hx_pos_321500f50b2e3bfa_297_getFileSystem,"polymod.Polymod","getFileSystem",0x7a45cdb1,"polymod.Polymod.getFileSystem","polymod/Polymod.hx",297,0xd80c6d61)
HX_LOCAL_STACK_FRAME(_hx_pos_321500f50b2e3bfa_313_loadMod,"polymod.Polymod","loadMod",0x8d884f2c,"polymod.Polymod.loadMod","polymod/Polymod.hx",313,0xd80c6d61)
HX_LOCAL_STACK_FRAME(_hx_pos_321500f50b2e3bfa_336_loadMods,"polymod.Polymod","loadMods",0x49bcf7c7,"polymod.Polymod.loadMods","polymod/Polymod.hx",336,0xd80c6d61)
HX_LOCAL_STACK_FRAME(_hx_pos_321500f50b2e3bfa_359_unloadMod,"polymod.Polymod","unloadMod",0x18ebf1f3,"polymod.Polymod.unloadMod","polymod/Polymod.hx",359,0xd80c6d61)
HX_LOCAL_STACK_FRAME(_hx_pos_321500f50b2e3bfa_382_unloadMods,"polymod.Polymod","unloadMods",0xb587c320,"polymod.Polymod.unloadMods","polymod/Polymod.hx",382,0xd80c6d61)
HX_LOCAL_STACK_FRAME(_hx_pos_321500f50b2e3bfa_408_unloadAllMods,"polymod.Polymod","unloadAllMods",0x8ef264e3,"polymod.Polymod.unloadAllMods","polymod/Polymod.hx",408,0xd80c6d61)
HX_LOCAL_STACK_FRAME(_hx_pos_321500f50b2e3bfa_430_disable,"polymod.Polymod","disable",0x360328d8,"polymod.Polymod.disable","polymod/Polymod.hx",430,0xd80c6d61)
HX_LOCAL_STACK_FRAME(_hx_pos_321500f50b2e3bfa_444_getDefaultIgnoreList,"polymod.Polymod","getDefaultIgnoreList",0xc5278c4b,"polymod.Polymod.getDefaultIgnoreList","polymod/Polymod.hx",444,0xd80c6d61)
HX_LOCAL_STACK_FRAME(_hx_pos_321500f50b2e3bfa_455_scan,"polymod.Polymod","scan",0x0780888d,"polymod.Polymod.scan","polymod/Polymod.hx",455,0xd80c6d61)
HX_LOCAL_STACK_FRAME(_hx_pos_321500f50b2e3bfa_536_clearCache,"polymod.Polymod","clearCache",0x8ce21085,"polymod.Polymod.clearCache","polymod/Polymod.hx",536,0xd80c6d61)
HX_LOCAL_STACK_FRAME(_hx_pos_321500f50b2e3bfa_549_error,"polymod.Polymod","error",0x8351eeb8,"polymod.Polymod.error","polymod/Polymod.hx",549,0xd80c6d61)
HX_LOCAL_STACK_FRAME(_hx_pos_321500f50b2e3bfa_557_warning,"polymod.Polymod","warning",0x8e76994c,"polymod.Polymod.warning","polymod/Polymod.hx",557,0xd80c6d61)
HX_LOCAL_STACK_FRAME(_hx_pos_321500f50b2e3bfa_565_notice,"polymod.Polymod","notice",0x44af4728,"polymod.Polymod.notice","polymod/Polymod.hx",565,0xd80c6d61)
HX_LOCAL_STACK_FRAME(_hx_pos_321500f50b2e3bfa_573_debug,"polymod.Polymod","debug",0xe7477543,"polymod.Polymod.debug","polymod/Polymod.hx",573,0xd80c6d61)
HX_LOCAL_STACK_FRAME(_hx_pos_321500f50b2e3bfa_589_listModFiles,"polymod.Polymod","listModFiles",0x718ff9e3,"polymod.Polymod.listModFiles","polymod/Polymod.hx",589,0xd80c6d61)
HX_LOCAL_STACK_FRAME(_hx_pos_321500f50b2e3bfa_134_boot,"polymod.Polymod","boot",0xfc4d0f42,"polymod.Polymod.boot","polymod/Polymod.hx",134,0xd80c6d61)
HX_LOCAL_STACK_FRAME(_hx_pos_321500f50b2e3bfa_139_boot,"polymod.Polymod","boot",0xfc4d0f42,"polymod.Polymod.boot","polymod/Polymod.hx",139,0xd80c6d61)
HX_LOCAL_STACK_FRAME(_hx_pos_321500f50b2e3bfa_151_boot,"polymod.Polymod","boot",0xfc4d0f42,"polymod.Polymod.boot","polymod/Polymod.hx",151,0xd80c6d61)
namespace polymod{

void Polymod_obj::__construct() { }

Dynamic Polymod_obj::__CreateEmpty() { return new Polymod_obj; }

void *Polymod_obj::_hx_vtable = 0;

Dynamic Polymod_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Polymod_obj > _hx_result = new Polymod_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool Polymod_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x4937d120;
}

 ::Dynamic Polymod_obj::onError;

 ::polymod::backends::PolymodAssetLibrary Polymod_obj::assetLibrary;

 ::Dynamic Polymod_obj::prevParams;

::Array< ::Dynamic> Polymod_obj::init( ::Dynamic params){
            	HX_STACKFRAME(&_hx_pos_321500f50b2e3bfa_159_init)
HXLINE( 160)		::polymod::Polymod_obj::onError = params->__Field(HX_("errorCallback",ad,29,bf,d7),::hx::paccDynamic);
HXLINE( 162)		::String modRoot;
HXDLIN( 162)		if (::hx::IsNull( params->__Field(HX_("modRoot",04,ba,da,e0),::hx::paccDynamic) )) {
HXLINE( 162)			modRoot = ( (::String)( ::Dynamic(params->__Field(HX_("fileSystemParams",31,48,18,b7),::hx::paccDynamic))->__Field(HX_("modRoot",04,ba,da,e0),::hx::paccDynamic)) );
            		}
            		else {
HXLINE( 162)			modRoot = ( (::String)(params->__Field(HX_("modRoot",04,ba,da,e0),::hx::paccDynamic)) );
            		}
HXLINE( 163)		::Array< ::String > dirs;
HXDLIN( 163)		if (::hx::IsNull( params->__Field(HX_("dirs",86,66,69,42),::hx::paccDynamic) )) {
HXLINE( 163)			dirs = ::Array_obj< ::String >::__new(0);
            		}
            		else {
HXLINE( 163)			dirs = ( (::Array< ::String >)(params->__Field(HX_("dirs",86,66,69,42),::hx::paccDynamic)) );
            		}
HXLINE( 164)		 ::polymod::util::SemanticVersion apiVersion = null();
HXLINE( 165)		try {
            			HX_STACK_CATCHABLE( ::Dynamic, 0);
HXLINE( 167)			::String apiStr = ( (::String)(params->__Field(HX_("apiVersion",9e,39,c9,e5),::hx::paccDynamic)) );
HXLINE( 168)			bool _hx_tmp;
HXDLIN( 168)			if (::hx::IsNotNull( apiStr )) {
HXLINE( 168)				_hx_tmp = (apiStr == HX_("",00,00,00,00));
            			}
            			else {
HXLINE( 168)				_hx_tmp = true;
            			}
HXDLIN( 168)			if (_hx_tmp) {
HXLINE( 170)				apiStr = HX_("*.*.*",a2,34,5c,4d);
            			}
HXLINE( 172)			apiVersion = ::polymod::util::SemanticVersion_obj::fromString(apiStr);
            		} catch( ::Dynamic _hx_e) {
            			if (_hx_e.IsClass<  ::Dynamic >() ){
            				HX_STACK_BEGIN_CATCH
            				 ::Dynamic _g = _hx_e;
HXLINE( 174)				{
HXLINE( 174)					null();
            				}
HXDLIN( 174)				 ::Dynamic msg = ::haxe::Exception_obj::caught(_g)->unwrap();
HXLINE( 176)				::polymod::Polymod_obj::error(HX_("parse_api_version",e7,a5,59,ab),((HX_("Error parsing API version: (",f8,97,84,65) + ::Std_obj::string(msg)) + HX_(")",29,00,00,00)),HX_("init",10,3b,bb,45));
HXLINE( 177)				return ::Array_obj< ::Dynamic>::__new(0);
            			}
            			else {
            				HX_STACK_DO_THROW(_hx_e);
            			}
            		}
HXLINE( 180)		::Array< ::Dynamic> modMeta = ::Array_obj< ::Dynamic>::__new(0);
HXLINE( 181)		::Array< ::Dynamic> modVers = ::Array_obj< ::Dynamic>::__new(0);
HXLINE( 183)		if (::hx::IsNull( params->__Field(HX_("fileSystemParams",31,48,18,b7),::hx::paccDynamic) )) {
HXLINE( 184)			params->__SetField(HX_("fileSystemParams",31,48,18,b7), ::Dynamic(::hx::Anon_obj::Create(1)
            				->setFixed(0,HX_("modRoot",04,ba,da,e0),modRoot)),::hx::paccDynamic);
            		}
HXLINE( 185)		if (::hx::IsNull(  ::Dynamic(params->__Field(HX_("fileSystemParams",31,48,18,b7),::hx::paccDynamic))->__Field(HX_("modRoot",04,ba,da,e0),::hx::paccDynamic) )) {
HXLINE( 186)			 ::Dynamic(params->__Field(HX_("fileSystemParams",31,48,18,b7),::hx::paccDynamic))->__SetField(HX_("modRoot",04,ba,da,e0),modRoot,::hx::paccDynamic);
            		}
HXLINE( 187)		::Dynamic fileSystem = ::polymod::fs::PolymodFileSystem_obj::makeFileSystem( ::Dynamic(params->__Field(HX_("customFilesystem",7c,dd,ec,23),::hx::paccDynamic)),params->__Field(HX_("fileSystemParams",31,48,18,b7),::hx::paccDynamic));
HXLINE( 189)		if (::hx::IsNotNull( params->__Field(HX_("modVersions",3d,b3,b4,55),::hx::paccDynamic) )) {
HXLINE( 191)			int _g = 0;
HXDLIN( 191)			::Array< ::String > _g1 = ( (::Array< ::String >)(params->__Field(HX_("modVersions",3d,b3,b4,55),::hx::paccDynamic)) );
HXDLIN( 191)			while((_g < _g1->length)){
HXLINE( 191)				::String str = _g1->__get(_g);
HXDLIN( 191)				_g = (_g + 1);
HXLINE( 193)				 ::polymod::util::SemanticVersion semVer = null();
HXLINE( 194)				try {
            					HX_STACK_CATCHABLE( ::Dynamic, 0);
HXLINE( 196)					semVer = ::polymod::util::SemanticVersion_obj::fromString(str);
            				} catch( ::Dynamic _hx_e) {
            					if (_hx_e.IsClass<  ::Dynamic >() ){
            						HX_STACK_BEGIN_CATCH
            						 ::Dynamic _g = _hx_e;
HXLINE( 198)						{
HXLINE( 198)							null();
            						}
HXDLIN( 198)						 ::Dynamic msg = ::haxe::Exception_obj::caught(_g)->unwrap();
HXLINE( 199)						{
HXLINE( 200)							::polymod::Polymod_obj::error(HX_("param_mod_version",69,37,99,54),((HX_("There was an error with one of the mod version patterns you provided: (",e3,09,19,27) + ::Std_obj::string(msg)) + HX_(")",29,00,00,00)),HX_("init",10,3b,bb,45));
HXLINE( 201)							semVer = ::polymod::util::SemanticVersion_obj::fromString(HX_("*.*.*",a2,34,5c,4d));
            						}
            					}
            					else {
            						HX_STACK_DO_THROW(_hx_e);
            					}
            				}
HXLINE( 203)				modVers->push(semVer);
            			}
            		}
HXLINE( 207)		{
HXLINE( 207)			int _g = 0;
HXDLIN( 207)			int _g1 = dirs->length;
HXDLIN( 207)			while((_g < _g1)){
HXLINE( 207)				_g = (_g + 1);
HXDLIN( 207)				int i = (_g - 1);
HXLINE( 209)				if (::hx::IsNotNull( dirs->__get(i) )) {
HXLINE( 211)					::String origDir = dirs->__get(i);
HXLINE( 212)					dirs[i] = ::polymod::util::Util_obj::pathJoin(modRoot,dirs->__get(i));
HXLINE( 213)					 ::polymod::ModMetadata meta = ::polymod::fs::IFileSystem_obj::getMetadata(fileSystem,dirs->__get(i));
HXLINE( 215)					if (::hx::IsNotNull( meta )) {
HXLINE( 217)						meta->id = origDir;
HXLINE( 218)						int apiScore = meta->apiVersion->checkCompatibility(apiVersion);
HXLINE( 219)						if (::hx::IsLess( apiScore,::polymod::PolymodConfig_obj::get_apiVersionMatch() )) {
HXLINE( 222)							::String _hx_tmp = ((((HX_("Mod \"",24,57,85,9f) + origDir) + HX_("\" was built for incompatible API version ",c7,84,bf,95)) + meta->apiVersion->toString()) + HX_(", current API version is \"",15,c2,53,3d));
HXLINE( 221)							::polymod::Polymod_obj::error(HX_("version_conflict_api",b4,79,7a,d1),((_hx_tmp + ( (::String)(params->__Field(HX_("apiVersion",9e,39,c9,e5),::hx::paccDynamic)) ).toString()) + HX_("\"",22,00,00,00)),HX_("init",10,3b,bb,45));
            						}
            						else {
HXLINE( 227)							if ((apiVersion->major == 0)) {
HXLINE( 230)								if ((apiVersion->minor != meta->apiVersion->minor)) {
HXLINE( 234)									::String _hx_tmp = ((((HX_("Mod \"",24,57,85,9f) + origDir) + HX_("\" was built for API version ",5c,9c,7b,4e)) + meta->apiVersion->toString()) + HX_(", current API version is \"",15,c2,53,3d));
HXLINE( 232)									::polymod::Polymod_obj::warning(HX_("version_prerelease_api",26,70,a7,43),(HX_("Modding API is in pre-release, some things might have changed!\n",23,df,36,3a) + ((_hx_tmp + ( (::String)(params->__Field(HX_("apiVersion",9e,39,c9,e5),::hx::paccDynamic)) ).toString()) + HX_("\"",22,00,00,00))),HX_("init",10,3b,bb,45));
            								}
            							}
            						}
HXLINE( 239)						 ::polymod::util::SemanticVersion modVer;
HXDLIN( 239)						if ((modVers->length > i)) {
HXLINE( 239)							modVer = modVers->__get(i).StaticCast<  ::polymod::util::SemanticVersion >();
            						}
            						else {
HXLINE( 239)							modVer = null();
            						}
HXLINE( 240)						if (::hx::IsNotNull( modVer )) {
HXLINE( 242)							int score = modVer->checkCompatibility(meta->modVersion);
HXLINE( 243)							if ((score < 3)) {
HXLINE( 246)								::String _hx_tmp = ((HX_("Mod pack wants version \"",54,e5,c2,7c) + modVer->toString()) + HX_("\" of mod \"",39,4b,41,1e));
HXDLIN( 246)								::String _hx_tmp1 = ((_hx_tmp + meta->id) + HX_("\", found incompatibile version ",fa,1d,c3,c1));
HXLINE( 245)								::polymod::Polymod_obj::error(HX_("version_conflict_mod",dc,93,83,d1),((_hx_tmp1 + meta->modVersion->toString()) + HX_("\" instead.",2a,29,8d,44)),HX_("init",10,3b,bb,45));
            							}
            						}
HXLINE( 250)						modMeta->push(meta);
            					}
            				}
            			}
            		}
HXLINE( 255)		::polymod::Polymod_obj::assetLibrary = ::polymod::backends::PolymodAssets_obj::init( ::Dynamic(::hx::Anon_obj::Create(9)
            			->setFixed(0,HX_("customBackend",63,24,96,a5), ::Dynamic(params->__Field(HX_("customBackend",63,24,96,a5),::hx::paccDynamic)))
            			->setFixed(1,HX_("fileSystem",8b,de,66,d3),fileSystem)
            			->setFixed(2,HX_("parseRules",c4,aa,37,1b), ::Dynamic(params->__Field(HX_("parseRules",c4,aa,37,1b),::hx::paccDynamic)))
            			->setFixed(3,HX_("extensionMap",5d,28,7a,23), ::Dynamic(params->__Field(HX_("extensionMap",5d,28,7a,23),::hx::paccDynamic)))
            			->setFixed(4,HX_("frameworkParams",64,76,eb,26), ::Dynamic(params->__Field(HX_("frameworkParams",64,76,eb,26),::hx::paccDynamic)))
            			->setFixed(5,HX_("dirs",86,66,69,42),dirs)
            			->setFixed(6,HX_("assetPrefix",a2,cb,18,44), ::Dynamic(params->__Field(HX_("assetPrefix",a2,cb,18,44),::hx::paccDynamic)))
            			->setFixed(7,HX_("framework",7e,94,a4,51), ::Dynamic(params->__Field(HX_("framework",7e,94,a4,51),::hx::paccDynamic)))
            			->setFixed(8,HX_("ignoredFiles",05,36,92,57), ::Dynamic(params->__Field(HX_("ignoredFiles",05,36,92,57),::hx::paccDynamic)))));
HXLINE( 270)		if (::hx::IsNull( ::polymod::Polymod_obj::assetLibrary )) {
HXLINE( 272)			return null();
            		}
HXLINE( 279)		::polymod::Polymod_obj::prevParams = params;
HXLINE( 282)		if (( (bool)(params->__Field(HX_("useScriptedClasses",15,54,ee,b9),::hx::paccDynamic)) )) {
HXLINE( 283)			::polymod::Polymod_obj::notice(HX_("script_class_parsing",75,11,4a,91),HX_("Parsing script classes...",ed,70,06,29),null());
HXLINE( 284)			::polymod::hscript::PolymodScriptClass_obj::registerAllScriptClasses();
HXLINE( 286)			::Array< ::String > classList = ::polymod::hscript::PolymodScriptClass_obj::listScriptClasses();
HXLINE( 287)			::polymod::Polymod_obj::notice(HX_("script_class_parsed",2c,47,17,23),((HX_("Parsed and registered ",66,30,a4,ff) + classList->length) + HX_(" scripted classes.",5e,ca,55,f0)),null());
            		}
HXLINE( 290)		return modMeta;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Polymod_obj,init,return )

::Dynamic Polymod_obj::getFileSystem(){
            	HX_STACKFRAME(&_hx_pos_321500f50b2e3bfa_297_getFileSystem)
HXLINE( 298)		if (::hx::IsNull( ::polymod::Polymod_obj::assetLibrary )) {
HXLINE( 299)			::polymod::Polymod_obj::warning(HX_("polymod_not_loaded",da,0d,b2,b2),HX_("Polymod is not loaded yet, cannot return file system.",28,63,63,9d),HX_("init",10,3b,bb,45));
HXLINE( 300)			return null();
            		}
HXLINE( 302)		return ::polymod::Polymod_obj::assetLibrary->fileSystem;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Polymod_obj,getFileSystem,return )

void Polymod_obj::loadMod(::String modId){
            	HX_STACKFRAME(&_hx_pos_321500f50b2e3bfa_313_loadMod)
HXLINE( 315)		bool _hx_tmp;
HXDLIN( 315)		if (::hx::IsNotNull( ::polymod::Polymod_obj::prevParams )) {
HXLINE( 315)			_hx_tmp = ::hx::IsNull( ::polymod::Polymod_obj::assetLibrary );
            		}
            		else {
HXLINE( 315)			_hx_tmp = true;
            		}
HXDLIN( 315)		if (_hx_tmp) {
HXLINE( 317)			::polymod::Polymod_obj::warning(HX_("polymod_not_loaded",da,0d,b2,b2),((HX_("Polymod is not loaded yet, cannot load mod \"",6d,a4,2f,d2) + modId) + HX_("\".",cc,1d,00,00)),HX_("init",10,3b,bb,45));
HXLINE( 318)			return;
            		}
HXLINE( 321)		 ::Dynamic newParams = ::Reflect_obj::copy(::polymod::Polymod_obj::prevParams);
HXLINE( 323)		newParams->__SetField(HX_("dirs",86,66,69,42),( (::Array< ::String >)(newParams->__Field(HX_("dirs",86,66,69,42),::hx::paccDynamic)) )->concat(::Array_obj< ::String >::__new(1)->init(0,modId)),::hx::paccDynamic);
HXLINE( 325)		::polymod::Polymod_obj::init(newParams);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Polymod_obj,loadMod,(void))

void Polymod_obj::loadMods(::Array< ::String > modIds){
            	HX_STACKFRAME(&_hx_pos_321500f50b2e3bfa_336_loadMods)
HXLINE( 338)		bool _hx_tmp;
HXDLIN( 338)		if (::hx::IsNotNull( ::polymod::Polymod_obj::prevParams )) {
HXLINE( 338)			_hx_tmp = ::hx::IsNull( ::polymod::Polymod_obj::assetLibrary );
            		}
            		else {
HXLINE( 338)			_hx_tmp = true;
            		}
HXDLIN( 338)		if (_hx_tmp) {
HXLINE( 340)			::polymod::Polymod_obj::warning(HX_("polymod_not_loaded",da,0d,b2,b2),((HX_("Polymod is not loaded yet, cannot load mod \"",6d,a4,2f,d2) + ::Std_obj::string(modIds)) + HX_("\".",cc,1d,00,00)),HX_("init",10,3b,bb,45));
HXLINE( 341)			return;
            		}
HXLINE( 344)		 ::Dynamic newParams = ::Reflect_obj::copy(::polymod::Polymod_obj::prevParams);
HXLINE( 346)		newParams->__SetField(HX_("dirs",86,66,69,42),( (::Array< ::String >)(newParams->__Field(HX_("dirs",86,66,69,42),::hx::paccDynamic)) )->concat(modIds),::hx::paccDynamic);
HXLINE( 348)		::polymod::Polymod_obj::init(newParams);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Polymod_obj,loadMods,(void))

void Polymod_obj::unloadMod(::String modId){
            	HX_STACKFRAME(&_hx_pos_321500f50b2e3bfa_359_unloadMod)
HXLINE( 361)		bool _hx_tmp;
HXDLIN( 361)		if (::hx::IsNotNull( ::polymod::Polymod_obj::prevParams )) {
HXLINE( 361)			_hx_tmp = ::hx::IsNull( ::polymod::Polymod_obj::assetLibrary );
            		}
            		else {
HXLINE( 361)			_hx_tmp = true;
            		}
HXDLIN( 361)		if (_hx_tmp) {
HXLINE( 363)			::polymod::Polymod_obj::warning(HX_("polymod_not_loaded",da,0d,b2,b2),((HX_("Polymod is not loaded yet, cannot load mod \"",6d,a4,2f,d2) + modId) + HX_("\".",cc,1d,00,00)),HX_("init",10,3b,bb,45));
HXLINE( 364)			return;
            		}
HXLINE( 367)		 ::Dynamic newParams = ::Reflect_obj::copy(::polymod::Polymod_obj::prevParams);
HXLINE( 369)		( (::Array< ::String >)(newParams->__Field(HX_("dirs",86,66,69,42),::hx::paccDynamic)) )->remove(modId);
HXLINE( 371)		::polymod::Polymod_obj::init(newParams);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Polymod_obj,unloadMod,(void))

void Polymod_obj::unloadMods(::Array< ::String > modIds){
            	HX_STACKFRAME(&_hx_pos_321500f50b2e3bfa_382_unloadMods)
HXLINE( 384)		bool _hx_tmp;
HXDLIN( 384)		if (::hx::IsNotNull( ::polymod::Polymod_obj::prevParams )) {
HXLINE( 384)			_hx_tmp = ::hx::IsNull( ::polymod::Polymod_obj::assetLibrary );
            		}
            		else {
HXLINE( 384)			_hx_tmp = true;
            		}
HXDLIN( 384)		if (_hx_tmp) {
HXLINE( 386)			::polymod::Polymod_obj::warning(HX_("polymod_not_loaded",da,0d,b2,b2),((HX_("Polymod is not loaded yet, cannot load mod \"",6d,a4,2f,d2) + ::Std_obj::string(modIds)) + HX_("\".",cc,1d,00,00)),HX_("init",10,3b,bb,45));
HXLINE( 387)			return;
            		}
HXLINE( 390)		 ::Dynamic newParams = ::Reflect_obj::copy(::polymod::Polymod_obj::prevParams);
HXLINE( 392)		{
HXLINE( 392)			int _g = 0;
HXDLIN( 392)			while((_g < modIds->length)){
HXLINE( 392)				::String modId = modIds->__get(_g);
HXDLIN( 392)				_g = (_g + 1);
HXLINE( 394)				( (::Array< ::String >)(newParams->__Field(HX_("dirs",86,66,69,42),::hx::paccDynamic)) )->remove(modId);
            			}
            		}
HXLINE( 397)		::polymod::Polymod_obj::init(newParams);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Polymod_obj,unloadMods,(void))

void Polymod_obj::unloadAllMods(){
            	HX_STACKFRAME(&_hx_pos_321500f50b2e3bfa_408_unloadAllMods)
HXLINE( 410)		if (::hx::IsNull( ::polymod::Polymod_obj::assetLibrary )) {
HXLINE( 412)			::polymod::Polymod_obj::warning(HX_("polymod_not_loaded",da,0d,b2,b2),HX_("Polymod is not loaded yet, cannot clear mods.",c7,ac,0e,58),HX_("init",10,3b,bb,45));
HXLINE( 413)			return;
            		}
HXLINE( 416)		 ::Dynamic newParams = ::Reflect_obj::copy(::polymod::Polymod_obj::prevParams);
HXLINE( 418)		newParams->__SetField(HX_("dirs",86,66,69,42),::Array_obj< ::String >::__new(0),::hx::paccDynamic);
HXLINE( 420)		::polymod::Polymod_obj::init(newParams);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Polymod_obj,unloadAllMods,(void))

void Polymod_obj::disable(){
            	HX_STACKFRAME(&_hx_pos_321500f50b2e3bfa_430_disable)
HXLINE( 432)		if (::hx::IsNull( ::polymod::Polymod_obj::assetLibrary )) {
HXLINE( 434)			::polymod::Polymod_obj::warning(HX_("polymod_not_loaded",da,0d,b2,b2),HX_("Polymod is not loaded yet, cannot clear mods.",c7,ac,0e,58),HX_("init",10,3b,bb,45));
HXLINE( 435)			return;
            		}
HXLINE( 438)		::polymod::Polymod_obj::assetLibrary->destroy();
HXLINE( 439)		::polymod::Polymod_obj::assetLibrary = null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Polymod_obj,disable,(void))

::Array< ::String > Polymod_obj::getDefaultIgnoreList(){
            	HX_STACKFRAME(&_hx_pos_321500f50b2e3bfa_444_getDefaultIgnoreList)
HXDLIN( 444)		::Array< ::String > _hx_tmp = ::polymod::PolymodConfig_obj::get_modIgnoreFiles();
HXDLIN( 444)		::String _hx_tmp1 = ::polymod::PolymodConfig_obj::get_modMetadataFile();
HXDLIN( 444)		return _hx_tmp->concat(::Array_obj< ::String >::__new(2)->init(0,_hx_tmp1)->init(1,::polymod::PolymodConfig_obj::get_modIconFile()));
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Polymod_obj,getDefaultIgnoreList,return )

::Array< ::Dynamic> Polymod_obj::scan(::String modRoot,::String __o_apiVersionStr, ::Dynamic errorCallback,::Dynamic fileSystem){
            		::String apiVersionStr = __o_apiVersionStr;
            		if (::hx::IsNull(__o_apiVersionStr)) apiVersionStr = HX_("*.*.*",a2,34,5c,4d);
            	HX_STACKFRAME(&_hx_pos_321500f50b2e3bfa_455_scan)
HXLINE( 456)		::polymod::Polymod_obj::onError = errorCallback;
HXLINE( 457)		 ::polymod::util::SemanticVersion apiVersion = null();
HXLINE( 458)		try {
            			HX_STACK_CATCHABLE( ::Dynamic, 0);
HXLINE( 460)			apiVersion = ::polymod::util::SemanticVersion_obj::fromString(apiVersionStr);
            		} catch( ::Dynamic _hx_e) {
            			if (_hx_e.IsClass<  ::Dynamic >() ){
            				HX_STACK_BEGIN_CATCH
            				 ::Dynamic _g = _hx_e;
HXLINE( 462)				{
HXLINE( 462)					null();
            				}
HXDLIN( 462)				 ::Dynamic msg = ::haxe::Exception_obj::caught(_g)->unwrap();
HXLINE( 464)				::polymod::Polymod_obj::error(((HX_("Error parsing provided API version (",a5,19,fc,e7) + ::Std_obj::string(msg)) + HX_(")",29,00,00,00)),HX_("scan",7d,fd,4e,4c),null());
HXLINE( 465)				return ::Array_obj< ::Dynamic>::__new(0);
            			}
            			else {
            				HX_STACK_DO_THROW(_hx_e);
            			}
            		}
HXLINE( 468)		if (::hx::IsNull( fileSystem )) {
HXLINE( 469)			fileSystem = ::polymod::fs::PolymodFileSystem_obj::makeFileSystem(null(), ::Dynamic(::hx::Anon_obj::Create(1)
            				->setFixed(0,HX_("modRoot",04,ba,da,e0),modRoot)));
            		}
HXLINE( 471)		::Array< ::Dynamic> modMeta = ::Array_obj< ::Dynamic>::__new(0);
HXLINE( 473)		bool _hx_tmp;
HXDLIN( 473)		if (::polymod::fs::IFileSystem_obj::exists(fileSystem,modRoot)) {
HXLINE( 473)			_hx_tmp = !(::polymod::fs::IFileSystem_obj::isDirectory(fileSystem,modRoot));
            		}
            		else {
HXLINE( 473)			_hx_tmp = true;
            		}
HXDLIN( 473)		if (_hx_tmp) {
HXLINE( 475)			return modMeta;
            		}
HXLINE( 477)		::Array< ::String > dirs = ::polymod::fs::IFileSystem_obj::readDirectory(fileSystem,modRoot);
HXLINE( 478)		::polymod::Polymod_obj::debug((((HX_("Scan found ",c1,c3,48,d8) + dirs->length) + HX_(" folders in ",e0,dc,95,8f)) + modRoot),::hx::SourceInfo(HX_("polymod/Polymod.hx",61,6d,0c,d8),478,HX_("polymod.Polymod",5e,af,2e,e4),HX_("scan",7d,fd,4e,4c)));
HXLINE( 481)		int l = dirs->length;
HXLINE( 482)		{
HXLINE( 482)			int _g = 0;
HXDLIN( 482)			int _g1 = l;
HXDLIN( 482)			while((_g < _g1)){
HXLINE( 482)				_g = (_g + 1);
HXDLIN( 482)				int i = (_g - 1);
HXLINE( 484)				int j = ((l - i) - 1);
HXLINE( 485)				::String dir = dirs->__get(j);
HXLINE( 486)				::String testDir = (((HX_("",00,00,00,00) + modRoot) + HX_("/",2f,00,00,00)) + dir);
HXLINE( 487)				bool _hx_tmp;
HXDLIN( 487)				if (::polymod::fs::IFileSystem_obj::isDirectory(fileSystem,testDir)) {
HXLINE( 487)					_hx_tmp = !(::polymod::fs::IFileSystem_obj::exists(fileSystem,testDir));
            				}
            				else {
HXLINE( 487)					_hx_tmp = true;
            				}
HXDLIN( 487)				if (_hx_tmp) {
HXLINE( 489)					dirs->removeRange(j,1);
            				}
            			}
            		}
HXLINE( 493)		{
HXLINE( 493)			int _g2 = 0;
HXDLIN( 493)			int _g3 = dirs->length;
HXDLIN( 493)			while((_g2 < _g3)){
HXLINE( 493)				_g2 = (_g2 + 1);
HXDLIN( 493)				int i = (_g2 - 1);
HXLINE( 495)				if (::hx::IsNotNull( dirs->__get(i) )) {
HXLINE( 497)					::String origDir = dirs->__get(i);
HXLINE( 498)					dirs[i] = (((HX_("",00,00,00,00) + modRoot) + HX_("/",2f,00,00,00)) + dirs->__get(i));
HXLINE( 499)					 ::polymod::ModMetadata meta = ::polymod::fs::IFileSystem_obj::getMetadata(fileSystem,dirs->__get(i));
HXLINE( 501)					if (::hx::IsNotNull( meta )) {
HXLINE( 503)						meta->id = origDir;
HXLINE( 504)						int apiScore = meta->apiVersion->checkCompatibility(apiVersion);
HXLINE( 505)						if (::hx::IsLess( apiScore,::polymod::PolymodConfig_obj::get_apiVersionMatch() )) {
HXLINE( 508)							::String _hx_tmp = ((((HX_("Mod \"",24,57,85,9f) + origDir) + HX_("\" was built for incompatible API version ",c7,84,bf,95)) + ::Std_obj::string(meta->apiVersion)) + HX_(", current version is \"",2f,75,7e,99));
HXLINE( 507)							::polymod::Polymod_obj::error(HX_("version_conflict_api",b4,79,7a,d1),((_hx_tmp + ::Std_obj::string(apiVersion)) + HX_("\"",22,00,00,00)),HX_("scan",7d,fd,4e,4c));
            						}
            						else {
HXLINE( 512)							if ((apiVersion->major == 0)) {
HXLINE( 515)								if ((apiVersion->minor != meta->apiVersion->minor)) {
HXLINE( 519)									::String _hx_tmp = ((((HX_("Mod \"",24,57,85,9f) + origDir) + HX_("\" was built for incompatible API version ",c7,84,bf,95)) + ::Std_obj::string(meta->apiVersion)) + HX_(", current version is \"",2f,75,7e,99));
HXLINE( 517)									::polymod::Polymod_obj::warning(HX_("version_prerelease_api",26,70,a7,43),(HX_("Modding API is in pre-release, some things might have changed!\n",23,df,36,3a) + ((_hx_tmp + ::Std_obj::string(apiVersion)) + HX_("\"",22,00,00,00))),HX_("scan",7d,fd,4e,4c));
            								}
            							}
            						}
HXLINE( 524)						modMeta->push(meta);
            					}
            				}
            			}
            		}
HXLINE( 529)		return modMeta;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Polymod_obj,scan,return )

void Polymod_obj::clearCache(){
            	HX_STACKFRAME(&_hx_pos_321500f50b2e3bfa_536_clearCache)
HXLINE( 537)		if (::hx::IsNull( ::polymod::Polymod_obj::assetLibrary )) {
HXLINE( 539)			::polymod::Polymod_obj::warning(HX_("polymod_not_loaded",da,0d,b2,b2),HX_("Polymod is not loaded yet, cannot clear cache.",42,67,e9,a4),null());
HXLINE( 540)			return;
            		}
HXLINE( 543)		::polymod::Polymod_obj::debug(HX_("Clearing backend asset cache...",d3,d2,af,22),::hx::SourceInfo(HX_("polymod/Polymod.hx",61,6d,0c,d8),543,HX_("polymod.Polymod",5e,af,2e,e4),HX_("clearCache",75,d9,1e,16)));
HXLINE( 544)		::polymod::Polymod_obj::assetLibrary->clearCache();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Polymod_obj,clearCache,(void))

void Polymod_obj::error(::String code,::String message,::String __o_origin){
            		::String origin = __o_origin;
            		if (::hx::IsNull(__o_origin)) origin = HX_("unknown",8a,23,7b,e1);
            	HX_GC_STACKFRAME(&_hx_pos_321500f50b2e3bfa_549_error)
HXDLIN( 549)		if (::hx::IsNotNull( ::polymod::Polymod_obj::onError )) {
HXLINE( 551)			::polymod::Polymod_obj::onError( ::polymod::PolymodError_obj::__alloc( HX_CTX ,::polymod::PolymodErrorType_obj::ERROR_dyn(),code,message,origin));
            		}
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Polymod_obj,error,(void))

void Polymod_obj::warning(::String code,::String message,::String __o_origin){
            		::String origin = __o_origin;
            		if (::hx::IsNull(__o_origin)) origin = HX_("unknown",8a,23,7b,e1);
            	HX_GC_STACKFRAME(&_hx_pos_321500f50b2e3bfa_557_warning)
HXDLIN( 557)		if (::hx::IsNotNull( ::polymod::Polymod_obj::onError )) {
HXLINE( 559)			::polymod::Polymod_obj::onError( ::polymod::PolymodError_obj::__alloc( HX_CTX ,::polymod::PolymodErrorType_obj::WARNING_dyn(),code,message,origin));
            		}
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Polymod_obj,warning,(void))

void Polymod_obj::notice(::String code,::String message,::String __o_origin){
            		::String origin = __o_origin;
            		if (::hx::IsNull(__o_origin)) origin = HX_("unknown",8a,23,7b,e1);
            	HX_GC_STACKFRAME(&_hx_pos_321500f50b2e3bfa_565_notice)
HXDLIN( 565)		if (::hx::IsNotNull( ::polymod::Polymod_obj::onError )) {
HXLINE( 567)			::polymod::Polymod_obj::onError( ::polymod::PolymodError_obj::__alloc( HX_CTX ,::polymod::PolymodErrorType_obj::NOTICE_dyn(),code,message,origin));
            		}
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Polymod_obj,notice,(void))

void Polymod_obj::debug(::String message, ::Dynamic posInfo){
            	HX_STACKFRAME(&_hx_pos_321500f50b2e3bfa_573_debug)
HXDLIN( 573)		if (( (bool)(::polymod::PolymodConfig_obj::get_debug()) )) {
HXLINE( 575)			if (::hx::IsNotNull( posInfo )) {
HXLINE( 576)				::haxe::Log_obj::trace( ::Dynamic((((((HX_("[POLYMOD] (",aa,f3,20,e2) + posInfo->__Field(HX_("fileName",e7,5a,43,62),::hx::paccDynamic)) + HX_("#",23,00,00,00)) + posInfo->__Field(HX_("lineNumber",dd,81,22,76),::hx::paccDynamic)) + HX_("): ",0f,4f,1f,00)) + message)),::hx::SourceInfo(HX_("polymod/Polymod.hx",61,6d,0c,d8),576,HX_("polymod.Polymod",5e,af,2e,e4),HX_("debug",53,52,1f,d7)));
            			}
            			else {
HXLINE( 578)				::haxe::Log_obj::trace((HX_("[POLYMOD] ",be,72,e3,64) + message),::hx::SourceInfo(HX_("polymod/Polymod.hx",61,6d,0c,d8),578,HX_("polymod.Polymod",5e,af,2e,e4),HX_("debug",53,52,1f,d7)));
            			}
            		}
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Polymod_obj,debug,(void))

::Array< ::String > Polymod_obj::listModFiles(::String type){
            	HX_STACKFRAME(&_hx_pos_321500f50b2e3bfa_589_listModFiles)
HXDLIN( 589)		if (::hx::IsNotNull( ::polymod::Polymod_obj::assetLibrary )) {
HXLINE( 591)			return ::polymod::Polymod_obj::assetLibrary->listModFiles(type);
            		}
            		else {
HXLINE( 595)			::polymod::Polymod_obj::warning(HX_("polymod_not_loaded",da,0d,b2,b2),HX_("Polymod is not loaded yet, cannot list files.",56,45,79,c2),null());
HXLINE( 596)			return ::Array_obj< ::String >::__new(0);
            		}
HXLINE( 589)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Polymod_obj,listModFiles,return )


Polymod_obj::Polymod_obj()
{
}

bool Polymod_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { outValue = init_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"scan") ) { outValue = scan_dyn(); return true; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"error") ) { outValue = error_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"debug") ) { outValue = debug_dyn(); return true; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"notice") ) { outValue = notice_dyn(); return true; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onError") ) { outValue = ( onError ); return true; }
		if (HX_FIELD_EQ(inName,"loadMod") ) { outValue = loadMod_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"disable") ) { outValue = disable_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"warning") ) { outValue = warning_dyn(); return true; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"loadMods") ) { outValue = loadMods_dyn(); return true; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"unloadMod") ) { outValue = unloadMod_dyn(); return true; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"prevParams") ) { outValue = ( prevParams ); return true; }
		if (HX_FIELD_EQ(inName,"unloadMods") ) { outValue = unloadMods_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"clearCache") ) { outValue = clearCache_dyn(); return true; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"assetLibrary") ) { outValue = ( assetLibrary ); return true; }
		if (HX_FIELD_EQ(inName,"listModFiles") ) { outValue = listModFiles_dyn(); return true; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"getFileSystem") ) { outValue = getFileSystem_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"unloadAllMods") ) { outValue = unloadAllMods_dyn(); return true; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"getDefaultIgnoreList") ) { outValue = getDefaultIgnoreList_dyn(); return true; }
	}
	return false;
}

bool Polymod_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"onError") ) { onError=ioValue.Cast<  ::Dynamic >(); return true; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"prevParams") ) { prevParams=ioValue.Cast<  ::Dynamic >(); return true; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"assetLibrary") ) { assetLibrary=ioValue.Cast<  ::polymod::backends::PolymodAssetLibrary >(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *Polymod_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo Polymod_obj_sStaticStorageInfo[] = {
	{::hx::fsObject /*  ::Dynamic */ ,(void *) &Polymod_obj::onError,HX_("onError",29,6a,67,09)},
	{::hx::fsObject /*  ::polymod::backends::PolymodAssetLibrary */ ,(void *) &Polymod_obj::assetLibrary,HX_("assetLibrary",eb,02,c2,5f)},
	{::hx::fsObject /*  ::Dynamic */ ,(void *) &Polymod_obj::prevParams,HX_("prevParams",99,66,f0,ed)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static void Polymod_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Polymod_obj::onError,"onError");
	HX_MARK_MEMBER_NAME(Polymod_obj::assetLibrary,"assetLibrary");
	HX_MARK_MEMBER_NAME(Polymod_obj::prevParams,"prevParams");
};

#ifdef HXCPP_VISIT_ALLOCS
static void Polymod_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Polymod_obj::onError,"onError");
	HX_VISIT_MEMBER_NAME(Polymod_obj::assetLibrary,"assetLibrary");
	HX_VISIT_MEMBER_NAME(Polymod_obj::prevParams,"prevParams");
};

#endif

::hx::Class Polymod_obj::__mClass;

static ::String Polymod_obj_sStaticFields[] = {
	HX_("onError",29,6a,67,09),
	HX_("assetLibrary",eb,02,c2,5f),
	HX_("prevParams",99,66,f0,ed),
	HX_("init",10,3b,bb,45),
	HX_("getFileSystem",c1,3a,d9,2f),
	HX_("loadMod",3c,90,dd,08),
	HX_("loadMods",b7,a4,00,b9),
	HX_("unloadMod",03,97,df,04),
	HX_("unloadMods",10,8c,c4,3e),
	HX_("unloadAllMods",f3,d1,85,44),
	HX_("disable",e8,69,58,b1),
	HX_("getDefaultIgnoreList",3b,e1,b2,45),
	HX_("scan",7d,fd,4e,4c),
	HX_("clearCache",75,d9,1e,16),
	HX_("error",c8,cb,29,73),
	HX_("warning",5c,da,cb,09),
	HX_("notice",18,d8,b8,31),
	HX_("debug",53,52,1f,d7),
	HX_("listModFiles",d3,de,44,5a),
	::String(null())
};

void Polymod_obj::__register()
{
	Polymod_obj _hx_dummy;
	Polymod_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("polymod.Polymod",5e,af,2e,e4);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Polymod_obj::__GetStatic;
	__mClass->mSetStaticField = &Polymod_obj::__SetStatic;
	__mClass->mMarkFunc = Polymod_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(Polymod_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< Polymod_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = Polymod_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Polymod_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Polymod_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void Polymod_obj::__boot()
{
{
            	HX_STACKFRAME(&_hx_pos_321500f50b2e3bfa_134_boot)
HXDLIN( 134)		onError = null();
            	}
{
            	HX_STACKFRAME(&_hx_pos_321500f50b2e3bfa_139_boot)
HXDLIN( 139)		assetLibrary = null();
            	}
{
            	HX_STACKFRAME(&_hx_pos_321500f50b2e3bfa_151_boot)
HXDLIN( 151)		prevParams = null();
            	}
}

} // end namespace polymod
