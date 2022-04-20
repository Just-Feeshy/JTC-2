#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
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
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_Encoding
#include <haxe/io/Encoding.h>
#endif
#ifndef INCLUDED_polymod_Polymod
#include <polymod/Polymod.h>
#endif
#ifndef INCLUDED_polymod_backends_IBackend
#include <polymod/backends/IBackend.h>
#endif
#ifndef INCLUDED_polymod_backends_PolymodAssetLibrary
#include <polymod/backends/PolymodAssetLibrary.h>
#endif
#ifndef INCLUDED_polymod_format_ParseRules
#include <polymod/format/ParseRules.h>
#endif
#ifndef INCLUDED_polymod_fs_IFileSystem
#include <polymod/fs/IFileSystem.h>
#endif
#ifndef INCLUDED_polymod_hscript_PolymodScriptClass
#include <polymod/hscript/PolymodScriptClass.h>
#endif
#ifndef INCLUDED_polymod_hscript_ScriptRunner
#include <polymod/hscript/ScriptRunner.h>
#endif
#ifndef INCLUDED_polymod_util_Util
#include <polymod/util/Util.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_41154335dca776f0_58_new,"polymod.backends.PolymodAssetLibrary","new",0xd3ebdd3c,"polymod.backends.PolymodAssetLibrary.new","polymod/backends/PolymodAssetLibrary.hx",58,0xd1edfd94)
HX_LOCAL_STACK_FRAME(_hx_pos_41154335dca776f0_134_destroy,"polymod.backends.PolymodAssetLibrary","destroy",0x1f3bd7d6,"polymod.backends.PolymodAssetLibrary.destroy","polymod/backends/PolymodAssetLibrary.hx",134,0xd1edfd94)
HX_LOCAL_STACK_FRAME(_hx_pos_41154335dca776f0_144_mergeAndAppendText,"polymod.backends.PolymodAssetLibrary","mergeAndAppendText",0xf742862a,"polymod.backends.PolymodAssetLibrary.mergeAndAppendText","polymod/backends/PolymodAssetLibrary.hx",144,0xd1edfd94)
HX_LOCAL_STACK_FRAME(_hx_pos_41154335dca776f0_150_getExtensionType,"polymod.backends.PolymodAssetLibrary","getExtensionType",0x9080a107,"polymod.backends.PolymodAssetLibrary.getExtensionType","polymod/backends/PolymodAssetLibrary.hx",150,0xd1edfd94)
HX_LOCAL_STACK_FRAME(_hx_pos_41154335dca776f0_164_getTextDirectly,"polymod.backends.PolymodAssetLibrary","getTextDirectly",0x8a3e4055,"polymod.backends.PolymodAssetLibrary.getTextDirectly","polymod/backends/PolymodAssetLibrary.hx",164,0xd1edfd94)
HX_LOCAL_STACK_FRAME(_hx_pos_41154335dca776f0_188_exists,"polymod.backends.PolymodAssetLibrary","exists",0xbb428280,"polymod.backends.PolymodAssetLibrary.exists","polymod/backends/PolymodAssetLibrary.hx",188,0xd1edfd94)
HX_LOCAL_STACK_FRAME(_hx_pos_41154335dca776f0_193_getText,"polymod.backends.PolymodAssetLibrary","getText",0x1a32273f,"polymod.backends.PolymodAssetLibrary.getText","polymod/backends/PolymodAssetLibrary.hx",193,0xd1edfd94)
HX_LOCAL_STACK_FRAME(_hx_pos_41154335dca776f0_198_getBytes,"polymod.backends.PolymodAssetLibrary","getBytes",0x81aeed99,"polymod.backends.PolymodAssetLibrary.getBytes","polymod/backends/PolymodAssetLibrary.hx",198,0xd1edfd94)
HX_LOCAL_STACK_FRAME(_hx_pos_41154335dca776f0_203_getPath,"polymod.backends.PolymodAssetLibrary","getPath",0x178a4037,"polymod.backends.PolymodAssetLibrary.getPath","polymod/backends/PolymodAssetLibrary.hx",203,0xd1edfd94)
HX_LOCAL_STACK_FRAME(_hx_pos_41154335dca776f0_208_clearCache,"polymod.backends.PolymodAssetLibrary","clearCache",0xea3a6019,"polymod.backends.PolymodAssetLibrary.clearCache","polymod/backends/PolymodAssetLibrary.hx",208,0xd1edfd94)
HX_LOCAL_STACK_FRAME(_hx_pos_41154335dca776f0_213_list,"polymod.backends.PolymodAssetLibrary","list",0x99265002,"polymod.backends.PolymodAssetLibrary.list","polymod/backends/PolymodAssetLibrary.hx",213,0xd1edfd94)
HX_LOCAL_STACK_FRAME(_hx_pos_41154335dca776f0_217_listModFiles,"polymod.backends.PolymodAssetLibrary","listModFiles",0x114a5677,"polymod.backends.PolymodAssetLibrary.listModFiles","polymod/backends/PolymodAssetLibrary.hx",217,0xd1edfd94)
HX_LOCAL_STACK_FRAME(_hx_pos_41154335dca776f0_240_check,"polymod.backends.PolymodAssetLibrary","check",0x391094a4,"polymod.backends.PolymodAssetLibrary.check","polymod/backends/PolymodAssetLibrary.hx",240,0xd1edfd94)
HX_LOCAL_STACK_FRAME(_hx_pos_41154335dca776f0_251_getType,"polymod.backends.PolymodAssetLibrary","getType",0x1a414d4c,"polymod.backends.PolymodAssetLibrary.getType","polymod/backends/PolymodAssetLibrary.hx",251,0xd1edfd94)
HX_LOCAL_STACK_FRAME(_hx_pos_41154335dca776f0_261_checkDirectly,"polymod.backends.PolymodAssetLibrary","checkDirectly",0xba101aba,"polymod.backends.PolymodAssetLibrary.checkDirectly","polymod/backends/PolymodAssetLibrary.hx",261,0xd1edfd94)
HX_LOCAL_STACK_FRAME(_hx_pos_41154335dca776f0_285_file,"polymod.backends.PolymodAssetLibrary","file",0x952f0220,"polymod.backends.PolymodAssetLibrary.file","polymod/backends/PolymodAssetLibrary.hx",285,0xd1edfd94)
HX_LOCAL_STACK_FRAME(_hx_pos_41154335dca776f0_336_fileLocale,"polymod.backends.PolymodAssetLibrary","fileLocale",0x0e5f42da,"polymod.backends.PolymodAssetLibrary.fileLocale","polymod/backends/PolymodAssetLibrary.hx",336,0xd1edfd94)
HX_LOCAL_STACK_FRAME(_hx_pos_41154335dca776f0_340__checkExists,"polymod.backends.PolymodAssetLibrary","_checkExists",0xbf011669,"polymod.backends.PolymodAssetLibrary._checkExists","polymod/backends/PolymodAssetLibrary.hx",340,0xd1edfd94)
HX_LOCAL_STACK_FRAME(_hx_pos_41154335dca776f0_364_init,"polymod.backends.PolymodAssetLibrary","init",0x972e6eb4,"polymod.backends.PolymodAssetLibrary.init","polymod/backends/PolymodAssetLibrary.hx",364,0xd1edfd94)
HX_LOCAL_STACK_FRAME(_hx_pos_41154335dca776f0_379_initExtensions,"polymod.backends.PolymodAssetLibrary","initExtensions",0x4b48d7e8,"polymod.backends.PolymodAssetLibrary.initExtensions","polymod/backends/PolymodAssetLibrary.hx",379,0xd1edfd94)
HX_LOCAL_STACK_FRAME(_hx_pos_41154335dca776f0_411__extensionSet,"polymod.backends.PolymodAssetLibrary","_extensionSet",0x73b0841e,"polymod.backends.PolymodAssetLibrary._extensionSet","polymod/backends/PolymodAssetLibrary.hx",411,0xd1edfd94)
HX_LOCAL_STACK_FRAME(_hx_pos_41154335dca776f0_418_initMod,"polymod.backends.PolymodAssetLibrary","initMod",0xc63f886e,"polymod.backends.PolymodAssetLibrary.initMod","polymod/backends/PolymodAssetLibrary.hx",418,0xd1edfd94)
HX_LOCAL_STACK_FRAME(_hx_pos_41154335dca776f0_465_stripAssetsPrefix,"polymod.backends.PolymodAssetLibrary","stripAssetsPrefix",0x388a3349,"polymod.backends.PolymodAssetLibrary.stripAssetsPrefix","polymod/backends/PolymodAssetLibrary.hx",465,0xd1edfd94)
HX_LOCAL_STACK_FRAME(_hx_pos_41154335dca776f0_481_prependAssetsPrefix,"polymod.backends.PolymodAssetLibrary","prependAssetsPrefix",0x09e91f7f,"polymod.backends.PolymodAssetLibrary.prependAssetsPrefix","polymod/backends/PolymodAssetLibrary.hx",481,0xd1edfd94)
namespace polymod{
namespace backends{

void PolymodAssetLibrary_obj::__construct( ::Dynamic params){
            	HX_STACKFRAME(&_hx_pos_41154335dca776f0_58_new)
HXLINE(  69)		this->parseRules = null();
HXLINE(  67)		this->ignoredFiles = null();
HXLINE(  66)		this->dirs = null();
HXLINE(  65)		this->assetPrefix = HX_("assets/",4c,2a,dc,36);
HXLINE(  74)		this->backend =  ::Dynamic(params->__Field(HX_("backend",14,bc,87,fb),::hx::paccDynamic));
HXLINE(  75)		this->fileSystem =  ::Dynamic(params->__Field(HX_("fileSystem",8b,de,66,d3),::hx::paccDynamic));
HXLINE(  76)		this->backend->__SetField(HX_("polymodLibrary",a5,49,05,cb),::hx::ObjectPtr<OBJ_>(this),::hx::paccDynamic);
HXLINE(  77)		this->dirs = ( (::Array< ::String >)(params->__Field(HX_("dirs",86,66,69,42),::hx::paccDynamic)) );
HXLINE(  78)		this->parseRules = ( ( ::polymod::format::ParseRules)(params->__Field(HX_("parseRules",c4,aa,37,1b),::hx::paccDynamic)) );
HXLINE(  79)		::Array< ::String > _hx_tmp;
HXDLIN(  79)		if (::hx::IsNotNull( params->__Field(HX_("ignoredFiles",05,36,92,57),::hx::paccDynamic) )) {
HXLINE(  79)			_hx_tmp = ( (::Array< ::String >)(params->__Field(HX_("ignoredFiles",05,36,92,57),::hx::paccDynamic)) )->copy();
            		}
            		else {
HXLINE(  79)			_hx_tmp = ::Array_obj< ::String >::__new(0);
            		}
HXDLIN(  79)		this->ignoredFiles = _hx_tmp;
HXLINE(  80)		this->extensions = ( ( ::haxe::ds::StringMap)(params->__Field(HX_("extensionMap",5d,28,7a,23),::hx::paccDynamic)) );
HXLINE(  81)		if (::hx::IsNotNull( params->__Field(HX_("assetPrefix",a2,cb,18,44),::hx::paccDynamic) )) {
HXLINE(  82)			this->assetPrefix = ( (::String)(params->__Field(HX_("assetPrefix",a2,cb,18,44),::hx::paccDynamic)) );
            		}
HXLINE(  94)		::polymod::backends::IBackend_obj::clearCache(this->backend);
HXLINE(  95)		this->init();
            	}

Dynamic PolymodAssetLibrary_obj::__CreateEmpty() { return new PolymodAssetLibrary_obj; }

void *PolymodAssetLibrary_obj::_hx_vtable = 0;

Dynamic PolymodAssetLibrary_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< PolymodAssetLibrary_obj > _hx_result = new PolymodAssetLibrary_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool PolymodAssetLibrary_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x6eaea9ac;
}

void PolymodAssetLibrary_obj::destroy(){
            	HX_STACKFRAME(&_hx_pos_41154335dca776f0_134_destroy)
HXLINE( 135)		if (::hx::IsNotNull( this->backend )) {
HXLINE( 137)			::polymod::backends::IBackend_obj::destroy(this->backend);
            		}
HXLINE( 139)		::polymod::hscript::PolymodScriptClass_obj::clearScriptClasses();
HXLINE( 140)		::polymod::hscript::ScriptRunner_obj::clearScripts();
            	}


HX_DEFINE_DYNAMIC_FUNC0(PolymodAssetLibrary_obj,destroy,(void))

::String PolymodAssetLibrary_obj::mergeAndAppendText(::String id,::String modText){
            	HX_STACKFRAME(&_hx_pos_41154335dca776f0_144_mergeAndAppendText)
HXLINE( 145)		modText = ::polymod::util::Util_obj::mergeAndAppendText(modText,id,this->dirs,this->getTextDirectly_dyn(),this->fileSystem,this->parseRules);
HXLINE( 146)		return modText;
            	}


HX_DEFINE_DYNAMIC_FUNC2(PolymodAssetLibrary_obj,mergeAndAppendText,return )

::String PolymodAssetLibrary_obj::getExtensionType(::String ext){
            	HX_STACKFRAME(&_hx_pos_41154335dca776f0_150_getExtensionType)
HXLINE( 151)		ext = ext.toLowerCase();
HXLINE( 152)		if ((this->extensions->exists(ext) == false)) {
HXLINE( 153)			return HX_("BYTES",4b,40,86,3b);
            		}
HXLINE( 154)		return this->extensions->get_string(ext);
            	}


HX_DEFINE_DYNAMIC_FUNC1(PolymodAssetLibrary_obj,getExtensionType,return )

::String PolymodAssetLibrary_obj::getTextDirectly(::String id,::String __o_directory){
            		::String directory = __o_directory;
            		if (::hx::IsNull(__o_directory)) directory = HX_("",00,00,00,00);
            	HX_STACKFRAME(&_hx_pos_41154335dca776f0_164_getTextDirectly)
HXLINE( 165)		 ::haxe::io::Bytes bytes = null();
HXLINE( 166)		if (this->checkDirectly(id,directory)) {
HXLINE( 168)			::Dynamic bytes1 = this->fileSystem;
HXDLIN( 168)			bytes = ::polymod::fs::IFileSystem_obj::getFileBytes(bytes1,this->file(id,directory));
            		}
            		else {
HXLINE( 172)			bytes = ::polymod::backends::IBackend_obj::getBytes(this->backend,id);
            		}
HXLINE( 175)		if (::hx::IsNull( bytes )) {
HXLINE( 177)			return null();
            		}
            		else {
HXLINE( 181)			return bytes->getString(0,bytes->length,null());
            		}
HXLINE( 175)		return null();
            	}


HX_DEFINE_DYNAMIC_FUNC2(PolymodAssetLibrary_obj,getTextDirectly,return )

bool PolymodAssetLibrary_obj::exists(::String id){
            	HX_STACKFRAME(&_hx_pos_41154335dca776f0_188_exists)
HXDLIN( 188)		return ::polymod::backends::IBackend_obj::exists(this->backend,id);
            	}


HX_DEFINE_DYNAMIC_FUNC1(PolymodAssetLibrary_obj,exists,return )

::String PolymodAssetLibrary_obj::getText(::String id){
            	HX_STACKFRAME(&_hx_pos_41154335dca776f0_193_getText)
HXDLIN( 193)		return ::polymod::backends::IBackend_obj::getText(this->backend,id);
            	}


HX_DEFINE_DYNAMIC_FUNC1(PolymodAssetLibrary_obj,getText,return )

 ::haxe::io::Bytes PolymodAssetLibrary_obj::getBytes(::String id){
            	HX_STACKFRAME(&_hx_pos_41154335dca776f0_198_getBytes)
HXDLIN( 198)		return ::polymod::backends::IBackend_obj::getBytes(this->backend,id);
            	}


HX_DEFINE_DYNAMIC_FUNC1(PolymodAssetLibrary_obj,getBytes,return )

::String PolymodAssetLibrary_obj::getPath(::String id){
            	HX_STACKFRAME(&_hx_pos_41154335dca776f0_203_getPath)
HXDLIN( 203)		return ::polymod::backends::IBackend_obj::getPath(this->backend,id);
            	}


HX_DEFINE_DYNAMIC_FUNC1(PolymodAssetLibrary_obj,getPath,return )

void PolymodAssetLibrary_obj::clearCache(){
            	HX_STACKFRAME(&_hx_pos_41154335dca776f0_208_clearCache)
HXDLIN( 208)		::polymod::backends::IBackend_obj::clearCache(this->backend);
            	}


HX_DEFINE_DYNAMIC_FUNC0(PolymodAssetLibrary_obj,clearCache,(void))

::Array< ::String > PolymodAssetLibrary_obj::list(::String type){
            	HX_STACKFRAME(&_hx_pos_41154335dca776f0_213_list)
HXDLIN( 213)		return ::polymod::backends::IBackend_obj::list(this->backend,type);
            	}


HX_DEFINE_DYNAMIC_FUNC1(PolymodAssetLibrary_obj,list,return )

::Array< ::String > PolymodAssetLibrary_obj::listModFiles(::String type){
            	HX_STACKFRAME(&_hx_pos_41154335dca776f0_217_listModFiles)
HXLINE( 218)		::Array< ::String > items = ::Array_obj< ::String >::__new(0);
HXLINE( 220)		{
HXLINE( 220)			 ::Dynamic id = this->type->keys();
HXDLIN( 220)			while(( (bool)(id->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE( 220)				::String id1 = ( (::String)(id->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXLINE( 222)				bool _hx_tmp;
HXDLIN( 222)				if ((id1.indexOf(HX_("_append",79,f3,4a,fe),null()) != 0)) {
HXLINE( 222)					_hx_tmp = (id1.indexOf(HX_("_merge",f9,e9,ad,01),null()) == 0);
            				}
            				else {
HXLINE( 222)					_hx_tmp = true;
            				}
HXDLIN( 222)				if (_hx_tmp) {
HXLINE( 223)					continue;
            				}
HXLINE( 224)				bool _hx_tmp1;
HXDLIN( 224)				bool _hx_tmp2;
HXDLIN( 224)				if (::hx::IsNotNull( type )) {
HXLINE( 224)					_hx_tmp2 = (type == HX_("BYTES",4b,40,86,3b));
            				}
            				else {
HXLINE( 224)					_hx_tmp2 = true;
            				}
HXDLIN( 224)				if (!(_hx_tmp2)) {
HXLINE( 224)					_hx_tmp1 = this->check(id1,type);
            				}
            				else {
HXLINE( 224)					_hx_tmp1 = true;
            				}
HXDLIN( 224)				if (_hx_tmp1) {
HXLINE( 226)					items->push(id1);
            				}
            			}
            		}
HXLINE( 230)		return items;
            	}


HX_DEFINE_DYNAMIC_FUNC1(PolymodAssetLibrary_obj,listModFiles,return )

bool PolymodAssetLibrary_obj::check(::String id,::String type){
            	HX_STACKFRAME(&_hx_pos_41154335dca776f0_240_check)
HXLINE( 241)		bool exists = this->_checkExists(id);
HXLINE( 242)		bool _hx_tmp;
HXDLIN( 242)		bool _hx_tmp1;
HXDLIN( 242)		if (exists) {
HXLINE( 242)			_hx_tmp1 = ::hx::IsNotNull( type );
            		}
            		else {
HXLINE( 242)			_hx_tmp1 = false;
            		}
HXDLIN( 242)		if (_hx_tmp1) {
HXLINE( 242)			_hx_tmp = (type != HX_("BYTES",4b,40,86,3b));
            		}
            		else {
HXLINE( 242)			_hx_tmp = false;
            		}
HXDLIN( 242)		if (_hx_tmp) {
HXLINE( 244)			::String otherType = this->type->get_string(id);
HXLINE( 245)			bool exists1;
HXDLIN( 245)			bool exists2;
HXDLIN( 245)			if ((otherType != type)) {
HXLINE( 245)				exists2 = (otherType == HX_("BYTES",4b,40,86,3b));
            			}
            			else {
HXLINE( 245)				exists2 = true;
            			}
HXDLIN( 245)			if (!(exists2)) {
HXLINE( 245)				exists1 = ::hx::IsNull( otherType );
            			}
            			else {
HXLINE( 245)				exists1 = true;
            			}
HXDLIN( 245)			if (!(exists1)) {
HXLINE( 245)				exists = (otherType == HX_("",00,00,00,00));
            			}
            			else {
HXLINE( 245)				exists = true;
            			}
            		}
HXLINE( 247)		return exists;
            	}


HX_DEFINE_DYNAMIC_FUNC2(PolymodAssetLibrary_obj,check,return )

::String PolymodAssetLibrary_obj::getType(::String id){
            	HX_STACKFRAME(&_hx_pos_41154335dca776f0_251_getType)
HXLINE( 252)		bool exists = this->_checkExists(id);
HXLINE( 253)		if (exists) {
HXLINE( 255)			return this->type->get_string(id);
            		}
HXLINE( 257)		return null();
            	}


HX_DEFINE_DYNAMIC_FUNC1(PolymodAssetLibrary_obj,getType,return )

bool PolymodAssetLibrary_obj::checkDirectly(::String id,::String __o_dir){
            		::String dir = __o_dir;
            		if (::hx::IsNull(__o_dir)) dir = HX_("",00,00,00,00);
            	HX_STACKFRAME(&_hx_pos_41154335dca776f0_261_checkDirectly)
HXLINE( 262)		id = this->stripAssetsPrefix(id);
HXLINE( 263)		bool _hx_tmp;
HXDLIN( 263)		if (::hx::IsNotNull( dir )) {
HXLINE( 263)			_hx_tmp = (dir == HX_("",00,00,00,00));
            		}
            		else {
HXLINE( 263)			_hx_tmp = true;
            		}
HXDLIN( 263)		if (_hx_tmp) {
HXLINE( 265)			return ::polymod::fs::IFileSystem_obj::exists(this->fileSystem,id);
            		}
            		else {
HXLINE( 269)			::String thePath = ::polymod::util::Util_obj::uCombine(::Array_obj< ::String >::__new(3)->init(0,dir)->init(1,::polymod::util::Util_obj::sl())->init(2,id));
HXLINE( 270)			if (::polymod::fs::IFileSystem_obj::exists(this->fileSystem,thePath)) {
HXLINE( 272)				return true;
            			}
            		}
HXLINE( 275)		return false;
            	}


HX_DEFINE_DYNAMIC_FUNC2(PolymodAssetLibrary_obj,checkDirectly,return )

::String PolymodAssetLibrary_obj::file(::String id,::String __o_theDir){
            		::String theDir = __o_theDir;
            		if (::hx::IsNull(__o_theDir)) theDir = HX_("",00,00,00,00);
            	HX_STACKFRAME(&_hx_pos_41154335dca776f0_285_file)
HXLINE( 286)		::String idStripped = this->stripAssetsPrefix(id);
HXLINE( 287)		if ((theDir != HX_("",00,00,00,00))) {
HXLINE( 289)			return ::polymod::util::Util_obj::pathJoin(theDir,idStripped);
            		}
HXLINE( 292)		::String result = HX_("",00,00,00,00);
HXLINE( 293)		bool resultLocalized = false;
HXLINE( 294)		{
HXLINE( 294)			int _g = 0;
HXDLIN( 294)			::Array< ::String > _g1 = this->dirs;
HXDLIN( 294)			while((_g < _g1->length)){
HXLINE( 294)				::String modDir = _g1->__get(_g);
HXDLIN( 294)				_g = (_g + 1);
HXLINE( 310)				if (!(resultLocalized)) {
HXLINE( 312)					::String filePath = ::polymod::util::Util_obj::pathJoin(modDir,idStripped);
HXLINE( 313)					if (::polymod::fs::IFileSystem_obj::exists(this->fileSystem,filePath)) {
HXLINE( 314)						result = filePath;
            					}
            				}
            			}
            		}
HXLINE( 317)		return result;
            	}


HX_DEFINE_DYNAMIC_FUNC2(PolymodAssetLibrary_obj,file,return )

::String PolymodAssetLibrary_obj::fileLocale(::String id){
            	HX_STACKFRAME(&_hx_pos_41154335dca776f0_336_fileLocale)
HXDLIN( 336)		return null();
            	}


HX_DEFINE_DYNAMIC_FUNC1(PolymodAssetLibrary_obj,fileLocale,return )

bool PolymodAssetLibrary_obj::_checkExists(::String id){
            	HX_STACKFRAME(&_hx_pos_41154335dca776f0_340__checkExists)
HXLINE( 341)		bool _hx_tmp;
HXDLIN( 341)		if ((this->ignoredFiles->length > 0)) {
HXLINE( 341)			_hx_tmp = (this->ignoredFiles->indexOf(id,null()) != -1);
            		}
            		else {
HXLINE( 341)			_hx_tmp = false;
            		}
HXDLIN( 341)		if (_hx_tmp) {
HXLINE( 342)			return false;
            		}
HXLINE( 343)		id = this->stripAssetsPrefix(id);
HXLINE( 344)		{
HXLINE( 344)			int _g = 0;
HXDLIN( 344)			::Array< ::String > _g1 = this->dirs;
HXDLIN( 344)			while((_g < _g1->length)){
HXLINE( 344)				::String d = _g1->__get(_g);
HXDLIN( 344)				_g = (_g + 1);
HXLINE( 355)				::String filePath = ::polymod::util::Util_obj::pathJoin(d,id);
HXLINE( 356)				if (::polymod::fs::IFileSystem_obj::exists(this->fileSystem,filePath)) {
HXLINE( 357)					return true;
            				}
            			}
            		}
HXLINE( 360)		return false;
            	}


HX_DEFINE_DYNAMIC_FUNC1(PolymodAssetLibrary_obj,_checkExists,return )

void PolymodAssetLibrary_obj::init(){
            	HX_GC_STACKFRAME(&_hx_pos_41154335dca776f0_364_init)
HXLINE( 365)		this->type =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
HXLINE( 366)		this->initExtensions();
HXLINE( 367)		if (::hx::IsNull( this->parseRules )) {
HXLINE( 368)			this->parseRules = ::polymod::format::ParseRules_obj::getDefault();
            		}
HXLINE( 369)		if (::hx::IsNotNull( this->dirs )) {
HXLINE( 371)			int _g = 0;
HXDLIN( 371)			::Array< ::String > _g1 = this->dirs;
HXDLIN( 371)			while((_g < _g1->length)){
HXLINE( 371)				::String d = _g1->__get(_g);
HXDLIN( 371)				_g = (_g + 1);
HXLINE( 373)				this->initMod(d);
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC0(PolymodAssetLibrary_obj,init,(void))

void PolymodAssetLibrary_obj::initExtensions(){
            	HX_GC_STACKFRAME(&_hx_pos_41154335dca776f0_379_initExtensions)
HXLINE( 380)		this->extensions =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
HXLINE( 381)		this->_extensionSet(HX_("mp3",70,17,53,00),HX_("AUDIO_GENERIC",2e,f6,26,23));
HXLINE( 382)		this->_extensionSet(HX_("ogg",4f,94,54,00),HX_("AUDIO_GENERIC",2e,f6,26,23));
HXLINE( 383)		this->_extensionSet(HX_("wav",2c,a1,5a,00),HX_("AUDIO_GENERIC",2e,f6,26,23));
HXLINE( 384)		this->_extensionSet(HX_("jpg",e1,d0,50,00),HX_("IMAGE",3b,57,57,3b));
HXLINE( 385)		this->_extensionSet(HX_("png",a9,5c,55,00),HX_("IMAGE",3b,57,57,3b));
HXLINE( 386)		this->_extensionSet(HX_("gif",04,84,4e,00),HX_("IMAGE",3b,57,57,3b));
HXLINE( 387)		this->_extensionSet(HX_("tga",8e,5f,58,00),HX_("IMAGE",3b,57,57,3b));
HXLINE( 388)		this->_extensionSet(HX_("bmp",45,bc,4a,00),HX_("IMAGE",3b,57,57,3b));
HXLINE( 389)		this->_extensionSet(HX_("tif",51,61,58,00),HX_("IMAGE",3b,57,57,3b));
HXLINE( 390)		this->_extensionSet(HX_("tiff",f5,c5,fc,4c),HX_("IMAGE",3b,57,57,3b));
HXLINE( 391)		this->_extensionSet(HX_("txt",70,6e,58,00),HX_("TEXT",ad,94,ba,37));
HXLINE( 392)		this->_extensionSet(HX_("xml",d7,6d,5b,00),HX_("TEXT",ad,94,ba,37));
HXLINE( 393)		this->_extensionSet(HX_("json",28,42,68,46),HX_("TEXT",ad,94,ba,37));
HXLINE( 394)		this->_extensionSet(HX_("csv",c6,83,4b,00),HX_("TEXT",ad,94,ba,37));
HXLINE( 395)		this->_extensionSet(HX_("tsv",17,6a,58,00),HX_("TEXT",ad,94,ba,37));
HXLINE( 396)		this->_extensionSet(HX_("mpf",a3,17,53,00),HX_("TEXT",ad,94,ba,37));
HXLINE( 397)		this->_extensionSet(HX_("tsx",19,6a,58,00),HX_("TEXT",ad,94,ba,37));
HXLINE( 398)		this->_extensionSet(HX_("tmx",df,64,58,00),HX_("TEXT",ad,94,ba,37));
HXLINE( 399)		this->_extensionSet(HX_("vdf",78,e1,59,00),HX_("TEXT",ad,94,ba,37));
HXLINE( 400)		this->_extensionSet(HX_("ttf",e6,6a,58,00),HX_("FONT",cf,25,81,2e));
HXLINE( 401)		this->_extensionSet(HX_("otf",a1,9f,54,00),HX_("FONT",cf,25,81,2e));
HXLINE( 402)		this->_extensionSet(HX_("webm",59,5d,f5,4e),HX_("VIDEO",5b,4c,ea,b4));
HXLINE( 403)		this->_extensionSet(HX_("mp4",71,17,53,00),HX_("VIDEO",5b,4c,ea,b4));
HXLINE( 404)		this->_extensionSet(HX_("mov",d4,16,53,00),HX_("VIDEO",5b,4c,ea,b4));
HXLINE( 405)		this->_extensionSet(HX_("avi",d4,01,4a,00),HX_("VIDEO",5b,4c,ea,b4));
HXLINE( 406)		this->_extensionSet(HX_("mkv",58,13,53,00),HX_("VIDEO",5b,4c,ea,b4));
            	}


HX_DEFINE_DYNAMIC_FUNC0(PolymodAssetLibrary_obj,initExtensions,(void))

void PolymodAssetLibrary_obj::_extensionSet(::String str,::String type){
            	HX_STACKFRAME(&_hx_pos_41154335dca776f0_411__extensionSet)
HXDLIN( 411)		if ((this->extensions->exists(str) == false)) {
HXLINE( 413)			this->extensions->set(str,type);
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC2(PolymodAssetLibrary_obj,_extensionSet,(void))

void PolymodAssetLibrary_obj::initMod(::String d){
            	HX_STACKFRAME(&_hx_pos_41154335dca776f0_418_initMod)
HXLINE( 419)		::polymod::Polymod_obj::notice(HX_("mod_load_prepare",0b,06,0c,a8),(HX_("Preparing to load mod ",af,df,0f,0f) + d),null());
HXLINE( 420)		if (::hx::IsNull( d )) {
HXLINE( 421)			return;
            		}
HXLINE( 423)		::Array< ::String > all = null();
HXLINE( 425)		bool _hx_tmp;
HXDLIN( 425)		if ((d != HX_("",00,00,00,00))) {
HXLINE( 425)			_hx_tmp = ::hx::IsNull( d );
            		}
            		else {
HXLINE( 425)			_hx_tmp = true;
            		}
HXDLIN( 425)		if (_hx_tmp) {
HXLINE( 427)			all = ::Array_obj< ::String >::__new(0);
            		}
HXLINE( 430)		try {
            			HX_STACK_CATCHABLE( ::Dynamic, 0);
HXLINE( 432)			if (::polymod::fs::IFileSystem_obj::exists(this->fileSystem,d)) {
HXLINE( 434)				all = ::polymod::fs::IFileSystem_obj::readDirectoryRecursive(this->fileSystem,d);
            			}
            			else {
HXLINE( 438)				all = ::Array_obj< ::String >::__new(0);
            			}
            		} catch( ::Dynamic _hx_e) {
            			if (_hx_e.IsClass<  ::Dynamic >() ){
            				HX_STACK_BEGIN_CATCH
            				 ::Dynamic _g = _hx_e;
HXLINE( 441)				{
HXLINE( 441)					null();
            				}
HXDLIN( 441)				 ::Dynamic msg = ::haxe::Exception_obj::caught(_g)->unwrap();
HXLINE( 443)				::polymod::Polymod_obj::error(HX_("mod_load_failed",b9,4d,47,d7),(((HX_("Failed to load mod ",96,38,88,94) + d) + HX_(" : ",c6,7a,18,00)) + ::Std_obj::string(msg)),null());
HXLINE( 444)				HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((((HX_("ModAssetLibrary._initMod(\"",ee,56,22,54) + d) + HX_("\") failed: ",1c,33,2e,41)) + ::Std_obj::string(msg))));
            			}
            			else {
            				HX_STACK_DO_THROW(_hx_e);
            			}
            		}
HXLINE( 446)		{
HXLINE( 446)			int _g = 0;
HXDLIN( 446)			while((_g < all->length)){
HXLINE( 446)				::String f = all->__get(_g);
HXDLIN( 446)				_g = (_g + 1);
HXLINE( 448)				int doti = ::polymod::util::Util_obj::uLastIndexOf(f,HX_(".",2e,00,00,00),null());
HXLINE( 449)				::String ext;
HXDLIN( 449)				if ((doti != -1)) {
HXLINE( 449)					ext = f.substring((doti + 1),null());
            				}
            				else {
HXLINE( 449)					ext = HX_("",00,00,00,00);
            				}
HXLINE( 450)				ext = ext.toLowerCase();
HXLINE( 451)				::String assetType = this->getExtensionType(ext);
HXLINE( 452)				this->type->set(f,assetType);
            			}
            		}
HXLINE( 454)		::polymod::Polymod_obj::notice(HX_("mod_load_done",7e,41,03,65),(HX_("Done loading mod ",80,69,cc,c8) + d),null());
            	}


HX_DEFINE_DYNAMIC_FUNC1(PolymodAssetLibrary_obj,initMod,(void))

::String PolymodAssetLibrary_obj::stripAssetsPrefix(::String id){
            	HX_STACKFRAME(&_hx_pos_41154335dca776f0_465_stripAssetsPrefix)
HXLINE( 466)		if ((::polymod::util::Util_obj::uIndexOf(id,this->assetPrefix,null()) == 0)) {
HXLINE( 468)			id = ::polymod::util::Util_obj::uSubstring(id,this->assetPrefix.length,null());
            		}
HXLINE( 470)		return id;
            	}


HX_DEFINE_DYNAMIC_FUNC1(PolymodAssetLibrary_obj,stripAssetsPrefix,return )

::String PolymodAssetLibrary_obj::prependAssetsPrefix(::String id){
            	HX_STACKFRAME(&_hx_pos_41154335dca776f0_481_prependAssetsPrefix)
HXLINE( 482)		if ((::polymod::util::Util_obj::uIndexOf(id,this->assetPrefix,null()) == 0)) {
HXLINE( 484)			return id;
            		}
HXLINE( 486)		return ((HX_("",00,00,00,00) + this->assetPrefix) + id);
            	}


HX_DEFINE_DYNAMIC_FUNC1(PolymodAssetLibrary_obj,prependAssetsPrefix,return )


::hx::ObjectPtr< PolymodAssetLibrary_obj > PolymodAssetLibrary_obj::__new( ::Dynamic params) {
	::hx::ObjectPtr< PolymodAssetLibrary_obj > __this = new PolymodAssetLibrary_obj();
	__this->__construct(params);
	return __this;
}

::hx::ObjectPtr< PolymodAssetLibrary_obj > PolymodAssetLibrary_obj::__alloc(::hx::Ctx *_hx_ctx, ::Dynamic params) {
	PolymodAssetLibrary_obj *__this = (PolymodAssetLibrary_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(PolymodAssetLibrary_obj), true, "polymod.backends.PolymodAssetLibrary"));
	*(void **)__this = PolymodAssetLibrary_obj::_hx_vtable;
	__this->__construct(params);
	return __this;
}

PolymodAssetLibrary_obj::PolymodAssetLibrary_obj()
{
}

void PolymodAssetLibrary_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PolymodAssetLibrary);
	HX_MARK_MEMBER_NAME(backend,"backend");
	HX_MARK_MEMBER_NAME(fileSystem,"fileSystem");
	HX_MARK_MEMBER_NAME(type,"type");
	HX_MARK_MEMBER_NAME(assetPrefix,"assetPrefix");
	HX_MARK_MEMBER_NAME(dirs,"dirs");
	HX_MARK_MEMBER_NAME(ignoredFiles,"ignoredFiles");
	HX_MARK_MEMBER_NAME(parseRules,"parseRules");
	HX_MARK_MEMBER_NAME(extensions,"extensions");
	HX_MARK_END_CLASS();
}

void PolymodAssetLibrary_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(backend,"backend");
	HX_VISIT_MEMBER_NAME(fileSystem,"fileSystem");
	HX_VISIT_MEMBER_NAME(type,"type");
	HX_VISIT_MEMBER_NAME(assetPrefix,"assetPrefix");
	HX_VISIT_MEMBER_NAME(dirs,"dirs");
	HX_VISIT_MEMBER_NAME(ignoredFiles,"ignoredFiles");
	HX_VISIT_MEMBER_NAME(parseRules,"parseRules");
	HX_VISIT_MEMBER_NAME(extensions,"extensions");
}

::hx::Val PolymodAssetLibrary_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { return ::hx::Val( type ); }
		if (HX_FIELD_EQ(inName,"dirs") ) { return ::hx::Val( dirs ); }
		if (HX_FIELD_EQ(inName,"list") ) { return ::hx::Val( list_dyn() ); }
		if (HX_FIELD_EQ(inName,"file") ) { return ::hx::Val( file_dyn() ); }
		if (HX_FIELD_EQ(inName,"init") ) { return ::hx::Val( init_dyn() ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"check") ) { return ::hx::Val( check_dyn() ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"exists") ) { return ::hx::Val( exists_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"backend") ) { return ::hx::Val( backend ); }
		if (HX_FIELD_EQ(inName,"destroy") ) { return ::hx::Val( destroy_dyn() ); }
		if (HX_FIELD_EQ(inName,"getText") ) { return ::hx::Val( getText_dyn() ); }
		if (HX_FIELD_EQ(inName,"getPath") ) { return ::hx::Val( getPath_dyn() ); }
		if (HX_FIELD_EQ(inName,"getType") ) { return ::hx::Val( getType_dyn() ); }
		if (HX_FIELD_EQ(inName,"initMod") ) { return ::hx::Val( initMod_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getBytes") ) { return ::hx::Val( getBytes_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"fileSystem") ) { return ::hx::Val( fileSystem ); }
		if (HX_FIELD_EQ(inName,"parseRules") ) { return ::hx::Val( parseRules ); }
		if (HX_FIELD_EQ(inName,"extensions") ) { return ::hx::Val( extensions ); }
		if (HX_FIELD_EQ(inName,"clearCache") ) { return ::hx::Val( clearCache_dyn() ); }
		if (HX_FIELD_EQ(inName,"fileLocale") ) { return ::hx::Val( fileLocale_dyn() ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"assetPrefix") ) { return ::hx::Val( assetPrefix ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"ignoredFiles") ) { return ::hx::Val( ignoredFiles ); }
		if (HX_FIELD_EQ(inName,"listModFiles") ) { return ::hx::Val( listModFiles_dyn() ); }
		if (HX_FIELD_EQ(inName,"_checkExists") ) { return ::hx::Val( _checkExists_dyn() ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"checkDirectly") ) { return ::hx::Val( checkDirectly_dyn() ); }
		if (HX_FIELD_EQ(inName,"_extensionSet") ) { return ::hx::Val( _extensionSet_dyn() ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"initExtensions") ) { return ::hx::Val( initExtensions_dyn() ); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"getTextDirectly") ) { return ::hx::Val( getTextDirectly_dyn() ); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getExtensionType") ) { return ::hx::Val( getExtensionType_dyn() ); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"stripAssetsPrefix") ) { return ::hx::Val( stripAssetsPrefix_dyn() ); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"mergeAndAppendText") ) { return ::hx::Val( mergeAndAppendText_dyn() ); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"prependAssetsPrefix") ) { return ::hx::Val( prependAssetsPrefix_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val PolymodAssetLibrary_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { type=inValue.Cast<  ::haxe::ds::StringMap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"dirs") ) { dirs=inValue.Cast< ::Array< ::String > >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"backend") ) { backend=inValue.Cast< ::Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"fileSystem") ) { fileSystem=inValue.Cast< ::Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"parseRules") ) { parseRules=inValue.Cast<  ::polymod::format::ParseRules >(); return inValue; }
		if (HX_FIELD_EQ(inName,"extensions") ) { extensions=inValue.Cast<  ::haxe::ds::StringMap >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"assetPrefix") ) { assetPrefix=inValue.Cast< ::String >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"ignoredFiles") ) { ignoredFiles=inValue.Cast< ::Array< ::String > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PolymodAssetLibrary_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("backend",14,bc,87,fb));
	outFields->push(HX_("fileSystem",8b,de,66,d3));
	outFields->push(HX_("type",ba,f2,08,4d));
	outFields->push(HX_("assetPrefix",a2,cb,18,44));
	outFields->push(HX_("dirs",86,66,69,42));
	outFields->push(HX_("ignoredFiles",05,36,92,57));
	outFields->push(HX_("parseRules",c4,aa,37,1b));
	outFields->push(HX_("extensions",14,7c,70,89));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo PolymodAssetLibrary_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /* ::Dynamic */ ,(int)offsetof(PolymodAssetLibrary_obj,backend),HX_("backend",14,bc,87,fb)},
	{::hx::fsObject /* ::Dynamic */ ,(int)offsetof(PolymodAssetLibrary_obj,fileSystem),HX_("fileSystem",8b,de,66,d3)},
	{::hx::fsObject /*  ::haxe::ds::StringMap */ ,(int)offsetof(PolymodAssetLibrary_obj,type),HX_("type",ba,f2,08,4d)},
	{::hx::fsString,(int)offsetof(PolymodAssetLibrary_obj,assetPrefix),HX_("assetPrefix",a2,cb,18,44)},
	{::hx::fsObject /* ::Array< ::String > */ ,(int)offsetof(PolymodAssetLibrary_obj,dirs),HX_("dirs",86,66,69,42)},
	{::hx::fsObject /* ::Array< ::String > */ ,(int)offsetof(PolymodAssetLibrary_obj,ignoredFiles),HX_("ignoredFiles",05,36,92,57)},
	{::hx::fsObject /*  ::polymod::format::ParseRules */ ,(int)offsetof(PolymodAssetLibrary_obj,parseRules),HX_("parseRules",c4,aa,37,1b)},
	{::hx::fsObject /*  ::haxe::ds::StringMap */ ,(int)offsetof(PolymodAssetLibrary_obj,extensions),HX_("extensions",14,7c,70,89)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *PolymodAssetLibrary_obj_sStaticStorageInfo = 0;
#endif

static ::String PolymodAssetLibrary_obj_sMemberFields[] = {
	HX_("backend",14,bc,87,fb),
	HX_("fileSystem",8b,de,66,d3),
	HX_("type",ba,f2,08,4d),
	HX_("assetPrefix",a2,cb,18,44),
	HX_("dirs",86,66,69,42),
	HX_("ignoredFiles",05,36,92,57),
	HX_("parseRules",c4,aa,37,1b),
	HX_("extensions",14,7c,70,89),
	HX_("destroy",fa,2c,86,24),
	HX_("mergeAndAppendText",86,bb,89,90),
	HX_("getExtensionType",63,87,3c,56),
	HX_("getTextDirectly",79,59,58,bb),
	HX_("exists",dc,1d,e0,bf),
	HX_("getText",63,7c,7c,1f),
	HX_("getBytes",f5,17,6f,1d),
	HX_("getPath",5b,95,d4,1c),
	HX_("clearCache",75,d9,1e,16),
	HX_("list",5e,1c,b3,47),
	HX_("listModFiles",d3,de,44,5a),
	HX_("check",c8,98,b6,45),
	HX_("getType",70,a2,8b,1f),
	HX_("checkDirectly",de,e2,4c,4c),
	HX_("file",7c,ce,bb,43),
	HX_("fileLocale",36,bc,43,3a),
	HX_("_checkExists",c5,9e,fb,07),
	HX_("init",10,3b,bb,45),
	HX_("initExtensions",44,2f,3b,ae),
	HX_("_extensionSet",42,4c,ed,05),
	HX_("initMod",92,dd,89,cb),
	HX_("stripAssetsPrefix",6d,dd,37,77),
	HX_("prependAssetsPrefix",a3,9a,f0,8e),
	::String(null()) };

::hx::Class PolymodAssetLibrary_obj::__mClass;

void PolymodAssetLibrary_obj::__register()
{
	PolymodAssetLibrary_obj _hx_dummy;
	PolymodAssetLibrary_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("polymod.backends.PolymodAssetLibrary",4a,cf,f5,08);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(PolymodAssetLibrary_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< PolymodAssetLibrary_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = PolymodAssetLibrary_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = PolymodAssetLibrary_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace polymod
} // end namespace backends
