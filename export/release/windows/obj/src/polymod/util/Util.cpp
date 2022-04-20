#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif
#ifndef INCLUDED_Xml
#include <Xml.h>
#endif
#ifndef INCLUDED__Xml_XmlType_Impl_
#include <_Xml/XmlType_Impl_.h>
#endif
#ifndef INCLUDED_haxe_Exception
#include <haxe/Exception.h>
#endif
#ifndef INCLUDED_haxe_io_Path
#include <haxe/io/Path.h>
#endif
#ifndef INCLUDED_polymod_Polymod
#include <polymod/Polymod.h>
#endif
#ifndef INCLUDED_polymod_PolymodConfig
#include <polymod/PolymodConfig.h>
#endif
#ifndef INCLUDED_polymod_format_BaseParseFormat
#include <polymod/format/BaseParseFormat.h>
#endif
#ifndef INCLUDED_polymod_format_ParseRules
#include <polymod/format/ParseRules.h>
#endif
#ifndef INCLUDED_polymod_fs_IFileSystem
#include <polymod/fs/IFileSystem.h>
#endif
#ifndef INCLUDED_polymod_util_Util
#include <polymod/util/Util.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_ed681bbd235d58c2_598_filterUnique_String,"polymod.util.Util","filterUnique_String",0xb97d6def,"polymod.util.Util.filterUnique_String","polymod/util/Util.hx",598,0xa14dd688)
HX_LOCAL_STACK_FRAME(_hx_pos_ed681bbd235d58c2_26_listAllParentDirs,"polymod.util.Util","listAllParentDirs",0x87b05d3b,"polymod.util.Util.listAllParentDirs","polymod/util/Util.hx",26,0xa14dd688)
HX_LOCAL_STACK_FRAME(_hx_pos_ed681bbd235d58c2_39_mergeAndAppendText,"polymod.util.Util","mergeAndAppendText",0x67a3775e,"polymod.util.Util.mergeAndAppendText","polymod/util/Util.hx",39,0xa14dd688)
HX_LOCAL_STACK_FRAME(_hx_pos_ed681bbd235d58c2_70_mergeText,"polymod.util.Util","mergeText",0x57ba76ad,"polymod.util.Util.mergeText","polymod/util/Util.hx",70,0xa14dd688)
HX_LOCAL_STACK_FRAME(_hx_pos_ed681bbd235d58c2_95_appendText,"polymod.util.Util","appendText",0x7713f37f,"polymod.util.Util.appendText","polymod/util/Util.hx",95,0xa14dd688)
HX_LOCAL_STACK_FRAME(_hx_pos_ed681bbd235d58c2_114_appendCSVOrTSV,"polymod.util.Util","appendCSVOrTSV",0x2835cee0,"polymod.util.Util.appendCSVOrTSV","polymod/util/Util.hx",114,0xa14dd688)
HX_LOCAL_STACK_FRAME(_hx_pos_ed681bbd235d58c2_139_appendSpecialXML,"polymod.util.Util","appendSpecialXML",0x73990970,"polymod.util.Util.appendSpecialXML","polymod/util/Util.hx",139,0xa14dd688)
HX_LOCAL_STACK_FRAME(_hx_pos_ed681bbd235d58c2_153_appendXML,"polymod.util.Util","appendXML",0x02d76b45,"polymod.util.Util.appendXML","polymod/util/Util.hx",153,0xa14dd688)
HX_LOCAL_STACK_FRAME(_hx_pos_ed681bbd235d58c2_163_stripComments,"polymod.util.Util","stripComments",0x58071354,"polymod.util.Util.stripComments","polymod/util/Util.hx",163,0xa14dd688)
HX_LOCAL_STACK_FRAME(_hx_pos_ed681bbd235d58c2_179_stripPathPrefix,"polymod.util.Util","stripPathPrefix",0x8fa3bf37,"polymod.util.Util.stripPathPrefix","polymod/util/Util.hx",179,0xa14dd688)
HX_LOCAL_STACK_FRAME(_hx_pos_ed681bbd235d58c2_191_trimLeadingWhiteSpace,"polymod.util.Util","trimLeadingWhiteSpace",0x8424d7a9,"polymod.util.Util.trimLeadingWhiteSpace","polymod/util/Util.hx",191,0xa14dd688)
static const ::String _hx_array_data_e4da7d96_17[] = {
	HX_("\r",0d,00,00,00),HX_("\n",0a,00,00,00),HX_(" ",20,00,00,00),HX_("\t",09,00,00,00),
};
HX_LOCAL_STACK_FRAME(_hx_pos_ed681bbd235d58c2_206_trimTrailingWhiteSpace,"polymod.util.Util","trimTrailingWhiteSpace",0xf0555eb3,"polymod.util.Util.trimTrailingWhiteSpace","polymod/util/Util.hx",206,0xa14dd688)
static const ::String _hx_array_data_e4da7d96_21[] = {
	HX_("\r",0d,00,00,00),HX_("\n",0a,00,00,00),HX_(" ",20,00,00,00),HX_("\t",09,00,00,00),
};
HX_LOCAL_STACK_FRAME(_hx_pos_ed681bbd235d58c2_222_stripXML,"polymod.util.Util","stripXML",0x7ce10bb7,"polymod.util.Util.stripXML","polymod/util/Util.hx",222,0xa14dd688)
HX_LOCAL_STACK_FRAME(_hx_pos_ed681bbd235d58c2_279_pathMerge,"polymod.util.Util","pathMerge",0xdef3b5fb,"polymod.util.Util.pathMerge","polymod/util/Util.hx",279,0xa14dd688)
HX_LOCAL_STACK_FRAME(_hx_pos_ed681bbd235d58c2_284_pathAppend,"polymod.util.Util","pathAppend",0xbe17a937,"polymod.util.Util.pathAppend","polymod/util/Util.hx",284,0xa14dd688)
HX_LOCAL_STACK_FRAME(_hx_pos_ed681bbd235d58c2_288_stripAssetsPrefix,"polymod.util.Util","stripAssetsPrefix",0x41146495,"polymod.util.Util.stripAssetsPrefix","polymod/util/Util.hx",288,0xa14dd688)
HX_LOCAL_STACK_FRAME(_hx_pos_ed681bbd235d58c2_297_pathSpecial,"polymod.util.Util","pathSpecial",0x2c60243c,"polymod.util.Util.pathSpecial","polymod/util/Util.hx",297,0xa14dd688)
HX_LOCAL_STACK_FRAME(_hx_pos_ed681bbd235d58c2_308_pathJoin,"polymod.util.Util","pathJoin",0xdb757a07,"polymod.util.Util.pathJoin","polymod/util/Util.hx",308,0xa14dd688)
HX_LOCAL_STACK_FRAME(_hx_pos_ed681bbd235d58c2_325_cleanSlashes,"polymod.util.Util","cleanSlashes",0xd056153a,"polymod.util.Util.cleanSlashes","polymod/util/Util.hx",325,0xa14dd688)
HX_LOCAL_STACK_FRAME(_hx_pos_ed681bbd235d58c2_333_sl,"polymod.util.Util","sl",0x225af071,"polymod.util.Util.sl","polymod/util/Util.hx",333,0xa14dd688)
HX_LOCAL_STACK_FRAME(_hx_pos_ed681bbd235d58c2_338_copyXml,"polymod.util.Util","copyXml",0x532c6e4a,"polymod.util.Util.copyXml","polymod/util/Util.hx",338,0xa14dd688)
HX_LOCAL_STACK_FRAME(_hx_pos_ed681bbd235d58c2_386_uCat,"polymod.util.Util","uCat",0xa4805479,"polymod.util.Util.uCat","polymod/util/Util.hx",386,0xa14dd688)
HX_LOCAL_STACK_FRAME(_hx_pos_ed681bbd235d58c2_398_uCharAt,"polymod.util.Util","uCharAt",0xfcfcb8e6,"polymod.util.Util.uCharAt","polymod/util/Util.hx",398,0xa14dd688)
HX_LOCAL_STACK_FRAME(_hx_pos_ed681bbd235d58c2_403_uJoin,"polymod.util.Util","uJoin",0x5074aa27,"polymod.util.Util.uJoin","polymod/util/Util.hx",403,0xa14dd688)
HX_LOCAL_STACK_FRAME(_hx_pos_ed681bbd235d58c2_419_uCombine,"polymod.util.Util","uCombine",0x0afe7862,"polymod.util.Util.uCombine","polymod/util/Util.hx",419,0xa14dd688)
HX_LOCAL_STACK_FRAME(_hx_pos_ed681bbd235d58c2_429_uExtension,"polymod.util.Util","uExtension",0x84fa6022,"polymod.util.Util.uExtension","polymod/util/Util.hx",429,0xa14dd688)
HX_LOCAL_STACK_FRAME(_hx_pos_ed681bbd235d58c2_444_uIndexOf,"polymod.util.Util","uIndexOf",0x718f96ac,"polymod.util.Util.uIndexOf","polymod/util/Util.hx",444,0xa14dd688)
HX_LOCAL_STACK_FRAME(_hx_pos_ed681bbd235d58c2_453_uLastIndexOf,"polymod.util.Util","uLastIndexOf",0x5cdb7876,"polymod.util.Util.uLastIndexOf","polymod/util/Util.hx",453,0xa14dd688)
HX_LOCAL_STACK_FRAME(_hx_pos_ed681bbd235d58c2_462_uLength,"polymod.util.Util","uLength",0xe48ed463,"polymod.util.Util.uLength","polymod/util/Util.hx",462,0xa14dd688)
HX_LOCAL_STACK_FRAME(_hx_pos_ed681bbd235d58c2_467_uPathPop,"polymod.util.Util","uPathPop",0x9a48d2cf,"polymod.util.Util.uPathPop","polymod/util/Util.hx",467,0xa14dd688)
HX_LOCAL_STACK_FRAME(_hx_pos_ed681bbd235d58c2_480_uTrimFinalCharIf,"polymod.util.Util","uTrimFinalCharIf",0x396afb8a,"polymod.util.Util.uTrimFinalCharIf","polymod/util/Util.hx",480,0xa14dd688)
HX_LOCAL_STACK_FRAME(_hx_pos_ed681bbd235d58c2_492_uTrimFinalEndlines,"polymod.util.Util","uTrimFinalEndlines",0xe685f73b,"polymod.util.Util.uTrimFinalEndlines","polymod/util/Util.hx",492,0xa14dd688)
HX_LOCAL_STACK_FRAME(_hx_pos_ed681bbd235d58c2_513_uTrimFirstCharIf,"polymod.util.Util","uTrimFirstCharIf",0xd7685bc4,"polymod.util.Util.uTrimFirstCharIf","polymod/util/Util.hx",513,0xa14dd688)
HX_LOCAL_STACK_FRAME(_hx_pos_ed681bbd235d58c2_525_uTrimFirstEndlines,"polymod.util.Util","uTrimFirstEndlines",0x06c759f5,"polymod.util.Util.uTrimFirstEndlines","polymod/util/Util.hx",525,0xa14dd688)
HX_LOCAL_STACK_FRAME(_hx_pos_ed681bbd235d58c2_550_uSplit,"polymod.util.Util","uSplit",0x44e6e9fd,"polymod.util.Util.uSplit","polymod/util/Util.hx",550,0xa14dd688)
HX_LOCAL_STACK_FRAME(_hx_pos_ed681bbd235d58c2_555_uSplitReplace,"polymod.util.Util","uSplitReplace",0xad0c6fb7,"polymod.util.Util.uSplitReplace","polymod/util/Util.hx",555,0xa14dd688)
HX_LOCAL_STACK_FRAME(_hx_pos_ed681bbd235d58c2_583_uSubstr,"polymod.util.Util","uSubstr",0xdf922eae,"polymod.util.Util.uSubstr","polymod/util/Util.hx",583,0xa14dd688)
HX_LOCAL_STACK_FRAME(_hx_pos_ed681bbd235d58c2_592_uSubstring,"polymod.util.Util","uSubstring",0x82d1bef4,"polymod.util.Util.uSubstring","polymod/util/Util.hx",592,0xa14dd688)
namespace polymod{
namespace util{

void Util_obj::__construct() { }

Dynamic Util_obj::__CreateEmpty() { return new Util_obj; }

void *Util_obj::_hx_vtable = 0;

Dynamic Util_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Util_obj > _hx_result = new Util_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool Util_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x7d31ad5a;
}

::Array< ::String > Util_obj::filterUnique_String(::Array< ::String > input){
            	HX_STACKFRAME(&_hx_pos_ed681bbd235d58c2_598_filterUnique_String)
HXLINE( 599)		::Array< ::String > output = ::Array_obj< ::String >::__new(0);
HXLINE( 600)		{
HXLINE( 600)			int _g = 0;
HXDLIN( 600)			while((_g < input->length)){
HXLINE( 600)				::String item = input->__get(_g);
HXDLIN( 600)				_g = (_g + 1);
HXLINE( 602)				if ((output->indexOf(item,null()) == -1)) {
HXLINE( 605)					output->push(item);
            				}
            			}
            		}
HXLINE( 608)		return output;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Util_obj,filterUnique_String,return )

::Array< ::String > Util_obj::listAllParentDirs(::String filePath){
            	HX_STACKFRAME(&_hx_pos_ed681bbd235d58c2_26_listAllParentDirs)
HXLINE(  27)		::Array< ::String > parentDirs = ::Array_obj< ::String >::__new();
HXLINE(  28)		::String parentDir = filePath;
HXLINE(  29)		while(true){
HXLINE(  29)			bool _hx_tmp;
HXDLIN(  29)			if (::hx::IsNotNull( parentDir )) {
HXLINE(  29)				_hx_tmp = (parentDir != HX_("",00,00,00,00));
            			}
            			else {
HXLINE(  29)				_hx_tmp = false;
            			}
HXDLIN(  29)			if (!(_hx_tmp)) {
HXLINE(  29)				goto _hx_goto_2;
            			}
HXLINE(  31)			parentDirs->push(parentDir);
HXLINE(  32)			parentDir = ::haxe::io::Path_obj::directory(parentDir);
            		}
            		_hx_goto_2:;
HXLINE(  34)		return parentDirs;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Util_obj,listAllParentDirs,return )

::String Util_obj::mergeAndAppendText(::String baseText,::String id,::Array< ::String > dirs, ::Dynamic getModText,::Dynamic fileSystem, ::polymod::format::ParseRules parseRules){
            	HX_STACKFRAME(&_hx_pos_ed681bbd235d58c2_39_mergeAndAppendText)
HXLINE(  40)		::String text = baseText;
HXLINE(  42)		{
HXLINE(  42)			int _g = 0;
HXDLIN(  42)			while((_g < dirs->length)){
HXLINE(  42)				::String d = dirs->__get(_g);
HXDLIN(  42)				_g = (_g + 1);
HXLINE(  44)				::String theDir = d;
HXDLIN(  44)				if (::hx::IsNull( theDir )) {
HXLINE(  44)					theDir = HX_("",00,00,00,00);
            				}
HXDLIN(  44)				if (::polymod::fs::IFileSystem_obj::exists(fileSystem,::polymod::util::Util_obj::pathSpecial(id,::polymod::PolymodConfig_obj::get_mergeFolder(),theDir))) {
HXLINE(  46)					text = ::polymod::util::Util_obj::mergeText(text,id,d,getModText,parseRules);
            				}
HXLINE(  48)				::String theDir1 = d;
HXDLIN(  48)				if (::hx::IsNull( theDir1 )) {
HXLINE(  48)					theDir1 = HX_("",00,00,00,00);
            				}
HXDLIN(  48)				if (::polymod::fs::IFileSystem_obj::exists(fileSystem,::polymod::util::Util_obj::pathSpecial(id,::polymod::PolymodConfig_obj::get_appendFolder(),theDir1))) {
HXLINE(  50)					text = ::polymod::util::Util_obj::appendText(text,id,d,getModText,parseRules);
            				}
            			}
            		}
HXLINE(  54)		return text;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC6(Util_obj,mergeAndAppendText,return )

::String Util_obj::mergeText(::String baseText,::String id,::String __o_theDir, ::Dynamic getModText, ::polymod::format::ParseRules parseRules){
            		::String theDir = __o_theDir;
            		if (::hx::IsNull(__o_theDir)) theDir = HX_("",00,00,00,00);
            	HX_STACKFRAME(&_hx_pos_ed681bbd235d58c2_70_mergeText)
HXLINE(  71)		::String extension = ::polymod::util::Util_obj::uExtension(id,true);
HXLINE(  72)		::String id1 = id;
HXDLIN(  72)		if ((::polymod::util::Util_obj::uIndexOf(id1,HX_("assets/",4c,2a,dc,36),null()) == 0)) {
HXLINE(  72)			id1 = ::polymod::util::Util_obj::uSubstring(id1,7,null());
            		}
HXDLIN(  72)		id = id1;
HXLINE(  73)		::String mergeFile = ::polymod::PolymodConfig_obj::get_mergeFolder();
HXDLIN(  73)		::String mergeFile1 = ((mergeFile + ::polymod::util::Util_obj::sl()) + id);
HXLINE(  75)		::Dynamic format = parseRules->get(id);
HXLINE(  76)		if (::hx::IsNull( format )) {
HXLINE(  79)			format = parseRules->get(extension);
            		}
HXLINE(  81)		if (::hx::IsNotNull( format )) {
HXLINE(  83)			::String mergeText = ( (::String)(getModText(mergeFile1,theDir)) );
HXLINE(  84)			return ::polymod::format::BaseParseFormat_obj::merge(format,baseText,mergeText,id);
            		}
            		else {
HXLINE(  88)			::polymod::Polymod_obj::error(HX_("merge_error",c1,8f,ea,85),((((HX_("Could not merge file (",38,a5,87,a2) + id) + HX_("), no parse format was specified for extension (",ef,41,09,3b)) + extension) + HX_(").",e5,23,00,00)),null());
HXLINE(  89)			return baseText;
            		}
HXLINE(  81)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(Util_obj,mergeText,return )

::String Util_obj::appendText(::String baseText,::String id,::String theDir, ::Dynamic getModText, ::polymod::format::ParseRules parseRules){
            	HX_STACKFRAME(&_hx_pos_ed681bbd235d58c2_95_appendText)
HXLINE(  96)		::String extension = ::polymod::util::Util_obj::uExtension(id,true);
HXLINE(  97)		::String id1 = id;
HXDLIN(  97)		if ((::polymod::util::Util_obj::uIndexOf(id1,HX_("assets/",4c,2a,dc,36),null()) == 0)) {
HXLINE(  97)			id1 = ::polymod::util::Util_obj::uSubstring(id1,7,null());
            		}
HXDLIN(  97)		id = id1;
HXLINE(  99)		::Dynamic format = parseRules->get(id);
HXLINE( 100)		if (::hx::IsNull( format )) {
HXLINE( 103)			format = parseRules->get(extension);
            		}
HXLINE( 105)		if (::hx::IsNotNull( format )) {
HXLINE( 107)			::String appendText = ( (::String)(getModText(::polymod::util::Util_obj::pathJoin(::polymod::PolymodConfig_obj::get_appendFolder(),id),theDir)) );
HXLINE( 108)			return ::polymod::format::BaseParseFormat_obj::append(format,baseText,appendText,id);
            		}
HXLINE( 110)		return baseText;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(Util_obj,appendText,return )

::String Util_obj::appendCSVOrTSV(::String baseText,::String appendText,::String id){
            	HX_STACKFRAME(&_hx_pos_ed681bbd235d58c2_114_appendCSVOrTSV)
HXLINE( 115)		::String lastChar = ::polymod::util::Util_obj::uCharAt(baseText,(::polymod::util::Util_obj::uLength(baseText) - 1));
HXLINE( 116)		::String lastLastChar = ::polymod::util::Util_obj::uCharAt(baseText,(::polymod::util::Util_obj::uLength(baseText) - 1));
HXLINE( 117)		::String joiner = HX_("",00,00,00,00);
HXLINE( 118)		::String endLine = HX_("\n",0a,00,00,00);
HXLINE( 119)		int crIndex = ::polymod::util::Util_obj::uIndexOf(baseText,HX_("\r",0d,00,00,00),null());
HXLINE( 120)		int lfIndex = ::polymod::util::Util_obj::uIndexOf(baseText,HX_("\n",0a,00,00,00),null());
HXLINE( 122)		bool _hx_tmp;
HXDLIN( 122)		if ((crIndex != -1)) {
HXLINE( 122)			_hx_tmp = (lfIndex == (crIndex + 1));
            		}
            		else {
HXLINE( 122)			_hx_tmp = false;
            		}
HXDLIN( 122)		if (_hx_tmp) {
HXLINE( 124)			endLine = HX_("\r\n",5d,0b,00,00);
            		}
HXLINE( 127)		if ((lastChar != HX_("\n",0a,00,00,00))) {
HXLINE( 129)			joiner = endLine;
            		}
HXLINE( 132)		::String otherEndline;
HXDLIN( 132)		if ((endLine == HX_("\n",0a,00,00,00))) {
HXLINE( 132)			otherEndline = HX_("\r\n",5d,0b,00,00);
            		}
            		else {
HXLINE( 132)			otherEndline = HX_("\n",0a,00,00,00);
            		}
HXLINE( 133)		appendText = ::polymod::util::Util_obj::uSplitReplace(appendText,otherEndline,endLine);
HXLINE( 135)		return ::polymod::util::Util_obj::uCombine(::Array_obj< ::String >::__new(3)->init(0,baseText)->init(1,joiner)->init(2,appendText));
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Util_obj,appendCSVOrTSV,return )

::String Util_obj::appendSpecialXML(::String a,::String b,::Array< ::String > headers,::Array< ::String > footers){
            	HX_STACKFRAME(&_hx_pos_ed681bbd235d58c2_139_appendSpecialXML)
HXLINE( 140)		a = ::polymod::util::Util_obj::stripXML(a,true,true,headers,footers);
HXLINE( 141)		b = ::polymod::util::Util_obj::stripXML(b,true,true,headers,footers);
HXLINE( 143)		::String txt = HX_("<?xml version=\"1.0\" encoding=\"utf-8\" ?>",b7,30,4d,85);
HXLINE( 144)		txt = ::polymod::util::Util_obj::uCat(txt,HX_("<data>",18,b5,f1,d1));
HXLINE( 145)		txt = ::polymod::util::Util_obj::uCat(txt,a);
HXLINE( 146)		txt = ::polymod::util::Util_obj::uCat(txt,b);
HXLINE( 147)		txt = ::polymod::util::Util_obj::uCat(txt,HX_("</data>",81,d9,55,5e));
HXLINE( 149)		return txt;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Util_obj,appendSpecialXML,return )

::String Util_obj::appendXML(::String a,::String b){
            	HX_STACKFRAME(&_hx_pos_ed681bbd235d58c2_153_appendXML)
HXLINE( 154)		a = ::polymod::util::Util_obj::stripXML(a,false,true,null(),null());
HXLINE( 155)		b = ::polymod::util::Util_obj::stripXML(b,true,false,null(),null());
HXLINE( 157)		::String txt = ::polymod::util::Util_obj::uCat(a,b);
HXLINE( 159)		return txt;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Util_obj,appendXML,return )

::String Util_obj::stripComments(::String txt){
            	HX_STACKFRAME(&_hx_pos_ed681bbd235d58c2_163_stripComments)
HXLINE( 164)		int start = ::polymod::util::Util_obj::uIndexOf(txt,HX_("<!--",05,ff,c1,27),null());
HXLINE( 165)		int end = ::polymod::util::Util_obj::uIndexOf(txt,HX_("-->",de,4c,22,00),null());
HXLINE( 166)		while(true){
HXLINE( 166)			bool _hx_tmp;
HXDLIN( 166)			if ((start != -1)) {
HXLINE( 166)				_hx_tmp = (end != -1);
            			}
            			else {
HXLINE( 166)				_hx_tmp = false;
            			}
HXDLIN( 166)			if (!(_hx_tmp)) {
HXLINE( 166)				goto _hx_goto_11;
            			}
HXLINE( 168)			int len = ::polymod::util::Util_obj::uLength(txt);
HXLINE( 169)			::String before = ::polymod::util::Util_obj::uSubstr(txt,0,start);
HXLINE( 170)			::String after = ::polymod::util::Util_obj::uSubstr(txt,(end + 3),(len - (end + 3)));
HXLINE( 171)			txt = ::polymod::util::Util_obj::uCat(before,after);
HXLINE( 172)			start = ::polymod::util::Util_obj::uIndexOf(txt,HX_("<!--",05,ff,c1,27),null());
HXLINE( 173)			end = ::polymod::util::Util_obj::uIndexOf(txt,HX_("-->",de,4c,22,00),null());
            		}
            		_hx_goto_11:;
HXLINE( 175)		return txt;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Util_obj,stripComments,return )

::String Util_obj::stripPathPrefix(::String value,::String prefix){
            	HX_STACKFRAME(&_hx_pos_ed681bbd235d58c2_179_stripPathPrefix)
HXLINE( 180)		::String result = value;
HXLINE( 181)		if ((result.indexOf(prefix,null()) == 0)) {
HXLINE( 182)			result = result.substr(prefix.length,null());
            		}
HXLINE( 184)		if ((result.indexOf(HX_("/",2f,00,00,00),null()) == 0)) {
HXLINE( 185)			result = result.substr(1,null());
            		}
HXLINE( 187)		return result;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Util_obj,stripPathPrefix,return )

::String Util_obj::trimLeadingWhiteSpace(::String txt){
            	HX_STACKFRAME(&_hx_pos_ed681bbd235d58c2_191_trimLeadingWhiteSpace)
HXLINE( 192)		::Array< ::String > white = ::Array_obj< ::String >::fromData( _hx_array_data_e4da7d96_17,4);
HXLINE( 193)		int len = ::polymod::util::Util_obj::uLength(txt);
HXLINE( 194)		{
HXLINE( 194)			int _g = 0;
HXDLIN( 194)			while((_g < white->length)){
HXLINE( 194)				::String w = white->__get(_g);
HXDLIN( 194)				_g = (_g + 1);
HXLINE( 196)				while((::polymod::util::Util_obj::uIndexOf(txt,w,null()) == 0)){
HXLINE( 198)					txt = ::polymod::util::Util_obj::uSubstr(txt,1,(len - 1));
HXLINE( 199)					len = (len - 1);
            				}
            			}
            		}
HXLINE( 202)		return txt;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Util_obj,trimLeadingWhiteSpace,return )

::String Util_obj::trimTrailingWhiteSpace(::String txt){
            	HX_STACKFRAME(&_hx_pos_ed681bbd235d58c2_206_trimTrailingWhiteSpace)
HXLINE( 207)		::Array< ::String > white = ::Array_obj< ::String >::fromData( _hx_array_data_e4da7d96_21,4);
HXLINE( 208)		int len = ::polymod::util::Util_obj::uLength(txt);
HXLINE( 209)		{
HXLINE( 209)			int _g = 0;
HXDLIN( 209)			while((_g < white->length)){
HXLINE( 209)				::String w = white->__get(_g);
HXDLIN( 209)				_g = (_g + 1);
HXLINE( 211)				while((::polymod::util::Util_obj::uCharAt(txt,(len - 1)) == w)){
HXLINE( 213)					txt = ::polymod::util::Util_obj::uSubstr(txt,0,(len - 1));
HXLINE( 214)					len = (len - 1);
            				}
            			}
            		}
HXLINE( 217)		return txt;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Util_obj,trimTrailingWhiteSpace,return )

::String Util_obj::stripXML(::String txt,::hx::Null< bool >  __o_stripHeader,::hx::Null< bool >  __o_stripFooter,::Array< ::String > headers,::Array< ::String > footers){
            		bool stripHeader = __o_stripHeader.Default(true);
            		bool stripFooter = __o_stripFooter.Default(true);
            	HX_STACKFRAME(&_hx_pos_ed681bbd235d58c2_222_stripXML)
HXLINE( 223)		txt = ::polymod::util::Util_obj::stripComments(txt);
HXLINE( 225)		if (stripHeader) {
HXLINE( 227)			if ((::polymod::util::Util_obj::uIndexOf(txt,HX_("<?xml",34,ad,0a,b6),null()) == 0)) {
HXLINE( 229)				int i = ::polymod::util::Util_obj::uIndexOf(txt,HX_(">",3e,00,00,00),null());
HXLINE( 230)				txt = ::polymod::util::Util_obj::uSubstr(txt,(i + 1),(::polymod::util::Util_obj::uLength(txt) - (i + 1)));
HXLINE( 231)				txt = ::polymod::util::Util_obj::trimLeadingWhiteSpace(txt);
            			}
HXLINE( 233)			if ((::polymod::util::Util_obj::uIndexOf(txt,HX_("<data",66,24,6e,ce),null()) == 0)) {
HXLINE( 235)				int i = ::polymod::util::Util_obj::uIndexOf(txt,HX_(">",3e,00,00,00),null());
HXLINE( 236)				txt = ::polymod::util::Util_obj::uSubstr(txt,(i + 1),(::polymod::util::Util_obj::uLength(txt) - (i + 1)));
HXLINE( 237)				txt = ::polymod::util::Util_obj::trimLeadingWhiteSpace(txt);
            			}
HXLINE( 239)			if (::hx::IsNotNull( headers )) {
HXLINE( 241)				int _g = 0;
HXDLIN( 241)				while((_g < headers->length)){
HXLINE( 241)					::String header = headers->__get(_g);
HXDLIN( 241)					_g = (_g + 1);
HXLINE( 243)					if ((::polymod::util::Util_obj::uIndexOf(txt,header,null()) == 0)) {
HXLINE( 245)						int i = ::polymod::util::Util_obj::uIndexOf(txt,HX_(">",3e,00,00,00),null());
HXLINE( 246)						txt = ::polymod::util::Util_obj::uSubstr(txt,(i + 1),(::polymod::util::Util_obj::uLength(txt) - (i + 1)));
HXLINE( 247)						txt = ::polymod::util::Util_obj::trimLeadingWhiteSpace(txt);
            					}
            				}
            			}
            		}
HXLINE( 252)		if (stripFooter) {
HXLINE( 254)			txt = ::polymod::util::Util_obj::trimTrailingWhiteSpace(txt);
HXLINE( 255)			int ulen = ::polymod::util::Util_obj::uLength(txt);
HXLINE( 256)			if ((::polymod::util::Util_obj::uLastIndexOf(txt,HX_("</data>",81,d9,55,5e),null()) == (ulen - 7))) {
HXLINE( 258)				txt = ::polymod::util::Util_obj::uSubstr(txt,0,(ulen - 7));
            			}
HXLINE( 260)			if (::hx::IsNotNull( footers )) {
HXLINE( 262)				int _g = 0;
HXDLIN( 262)				while((_g < footers->length)){
HXLINE( 262)					::String footer = footers->__get(_g);
HXDLIN( 262)					_g = (_g + 1);
HXLINE( 264)					txt = ::polymod::util::Util_obj::trimTrailingWhiteSpace(txt);
HXLINE( 265)					int ulen = ::polymod::util::Util_obj::uLength(txt);
HXLINE( 266)					int footerlen = ::polymod::util::Util_obj::uLength(footer);
HXLINE( 267)					if ((::polymod::util::Util_obj::uLastIndexOf(txt,footer,null()) == (ulen - footerlen))) {
HXLINE( 269)						txt = ::polymod::util::Util_obj::uSubstr(txt,0,(ulen - footerlen));
            					}
            				}
            			}
            		}
HXLINE( 274)		return txt;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(Util_obj,stripXML,return )

::String Util_obj::pathMerge(::String id,::String __o_theDir){
            		::String theDir = __o_theDir;
            		if (::hx::IsNull(__o_theDir)) theDir = HX_("",00,00,00,00);
            	HX_STACKFRAME(&_hx_pos_ed681bbd235d58c2_279_pathMerge)
HXDLIN( 279)		return ::polymod::util::Util_obj::pathSpecial(id,::polymod::PolymodConfig_obj::get_mergeFolder(),theDir);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Util_obj,pathMerge,return )

::String Util_obj::pathAppend(::String id,::String __o_theDir){
            		::String theDir = __o_theDir;
            		if (::hx::IsNull(__o_theDir)) theDir = HX_("",00,00,00,00);
            	HX_STACKFRAME(&_hx_pos_ed681bbd235d58c2_284_pathAppend)
HXDLIN( 284)		return ::polymod::util::Util_obj::pathSpecial(id,::polymod::PolymodConfig_obj::get_appendFolder(),theDir);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Util_obj,pathAppend,return )

::String Util_obj::stripAssetsPrefix(::String id){
            	HX_STACKFRAME(&_hx_pos_ed681bbd235d58c2_288_stripAssetsPrefix)
HXLINE( 289)		if ((::polymod::util::Util_obj::uIndexOf(id,HX_("assets/",4c,2a,dc,36),null()) == 0)) {
HXLINE( 291)			id = ::polymod::util::Util_obj::uSubstring(id,7,null());
            		}
HXLINE( 293)		return id;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Util_obj,stripAssetsPrefix,return )

::String Util_obj::pathSpecial(::String id,::String __o_special,::String __o_theDir){
            		::String special = __o_special;
            		if (::hx::IsNull(__o_special)) special = HX_("",00,00,00,00);
            		::String theDir = __o_theDir;
            		if (::hx::IsNull(__o_theDir)) theDir = HX_("",00,00,00,00);
            	HX_STACKFRAME(&_hx_pos_ed681bbd235d58c2_297_pathSpecial)
HXLINE( 299)		::String id1 = id;
HXDLIN( 299)		if ((::polymod::util::Util_obj::uIndexOf(id1,HX_("assets/",4c,2a,dc,36),null()) == 0)) {
HXLINE( 299)			id1 = ::polymod::util::Util_obj::uSubstring(id1,7,null());
            		}
HXDLIN( 299)		id = id1;
HXLINE( 300)		::String thePath = ::polymod::util::Util_obj::sl();
HXDLIN( 300)		::String thePath1 = ::polymod::util::Util_obj::uCombine(::Array_obj< ::String >::__new(5)->init(0,theDir)->init(1,thePath)->init(2,special)->init(3,::polymod::util::Util_obj::sl())->init(4,id));
HXLINE( 301)		return thePath1;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Util_obj,pathSpecial,return )

::String Util_obj::pathJoin(::String a,::String b){
            	HX_STACKFRAME(&_hx_pos_ed681bbd235d58c2_308_pathJoin)
HXLINE( 309)		bool aSlash;
HXDLIN( 309)		int aSlash1 = ::polymod::util::Util_obj::uLastIndexOf(a,HX_("/",2f,00,00,00),null());
HXDLIN( 309)		if ((aSlash1 != (::polymod::util::Util_obj::uLength(a) - 1))) {
HXLINE( 309)			int aSlash1 = ::polymod::util::Util_obj::uLastIndexOf(a,HX_("\\",5c,00,00,00),null());
HXDLIN( 309)			aSlash = (aSlash1 == (::polymod::util::Util_obj::uLength(a) - 1));
            		}
            		else {
HXLINE( 309)			aSlash = true;
            		}
HXLINE( 310)		bool bSlash;
HXDLIN( 310)		if ((::polymod::util::Util_obj::uIndexOf(b,HX_("/",2f,00,00,00),null()) != 0)) {
HXLINE( 310)			bSlash = (::polymod::util::Util_obj::uIndexOf(b,HX_("\\",5c,00,00,00),null()) == 0);
            		}
            		else {
HXLINE( 310)			bSlash = true;
            		}
HXLINE( 311)		::String str = HX_("",00,00,00,00);
HXLINE( 312)		bool _hx_tmp;
HXDLIN( 312)		if (!(aSlash)) {
HXLINE( 312)			_hx_tmp = bSlash;
            		}
            		else {
HXLINE( 312)			_hx_tmp = true;
            		}
HXDLIN( 312)		if (_hx_tmp) {
HXLINE( 314)			str = ::polymod::util::Util_obj::uCombine(::Array_obj< ::String >::__new(2)->init(0,a)->init(1,b));
            		}
            		else {
HXLINE( 318)			str = ::polymod::util::Util_obj::uCombine(::Array_obj< ::String >::__new(3)->init(0,a)->init(1,::polymod::util::Util_obj::sl())->init(2,b));
            		}
HXLINE( 320)		str = ::polymod::util::Util_obj::cleanSlashes(str);
HXLINE( 321)		return str;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Util_obj,pathJoin,return )

::String Util_obj::cleanSlashes(::String str){
            	HX_STACKFRAME(&_hx_pos_ed681bbd235d58c2_325_cleanSlashes)
HXLINE( 326)		str = ::polymod::util::Util_obj::uSplitReplace(str,HX_("\\",5c,00,00,00),HX_("/",2f,00,00,00));
HXLINE( 327)		str = ::polymod::util::Util_obj::uSplitReplace(str,HX_("//",20,29,00,00),HX_("/",2f,00,00,00));
HXLINE( 328)		return str;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Util_obj,cleanSlashes,return )

::String Util_obj::sl(){
            	HX_STACKFRAME(&_hx_pos_ed681bbd235d58c2_333_sl)
HXDLIN( 333)		return HX_("/",2f,00,00,00);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Util_obj,sl,return )

 ::Xml Util_obj::copyXml( ::Xml data, ::Xml parent){
            	HX_STACKFRAME(&_hx_pos_ed681bbd235d58c2_338_copyXml)
HXLINE( 339)		 ::Xml c = null();
HXLINE( 340)		if ((data->nodeType == ::Xml_obj::Element)) {
HXLINE( 342)			if ((data->nodeType != ::Xml_obj::Element)) {
HXLINE( 342)				HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, expected Element but found ",d8,90,8b,bb) + ::_Xml::XmlType_Impl__obj::toString(data->nodeType))));
            			}
HXDLIN( 342)			c = ::Xml_obj::createElement(data->nodeName);
HXLINE( 343)			{
HXLINE( 343)				 ::Dynamic att = data->attributes();
HXDLIN( 343)				while(( (bool)(att->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE( 343)					::String att1 = ( (::String)(att->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXLINE( 345)					c->set(att1,data->get(att1));
            				}
            			}
HXLINE( 347)			{
HXLINE( 347)				 ::Dynamic el = data->elements();
HXDLIN( 347)				while(( (bool)(el->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE( 347)					 ::Xml el1 = ( ( ::Xml)(el->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXLINE( 349)					c->addChild(::polymod::util::Util_obj::copyXml(el1,c));
            				}
            			}
            		}
            		else {
HXLINE( 352)			if ((data->nodeType == ::Xml_obj::PCData)) {
HXLINE( 354)				bool c1;
HXDLIN( 354)				if ((data->nodeType != ::Xml_obj::Document)) {
HXLINE( 354)					c1 = (data->nodeType == ::Xml_obj::Element);
            				}
            				else {
HXLINE( 354)					c1 = true;
            				}
HXDLIN( 354)				if (c1) {
HXLINE( 354)					HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(data->nodeType))));
            				}
HXDLIN( 354)				c = ::Xml_obj::createPCData(data->nodeValue);
            			}
            			else {
HXLINE( 356)				if ((data->nodeType == ::Xml_obj::CData)) {
HXLINE( 358)					bool c1;
HXDLIN( 358)					if ((data->nodeType != ::Xml_obj::Document)) {
HXLINE( 358)						c1 = (data->nodeType == ::Xml_obj::Element);
            					}
            					else {
HXLINE( 358)						c1 = true;
            					}
HXDLIN( 358)					if (c1) {
HXLINE( 358)						HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(data->nodeType))));
            					}
HXDLIN( 358)					c = ::Xml_obj::createCData(data->nodeValue);
            				}
            				else {
HXLINE( 360)					if ((data->nodeType == ::Xml_obj::Comment)) {
HXLINE( 362)						bool c1;
HXDLIN( 362)						if ((data->nodeType != ::Xml_obj::Document)) {
HXLINE( 362)							c1 = (data->nodeType == ::Xml_obj::Element);
            						}
            						else {
HXLINE( 362)							c1 = true;
            						}
HXDLIN( 362)						if (c1) {
HXLINE( 362)							HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(data->nodeType))));
            						}
HXDLIN( 362)						c = ::Xml_obj::createComment(data->nodeValue);
            					}
            					else {
HXLINE( 364)						if ((data->nodeType == ::Xml_obj::DocType)) {
HXLINE( 366)							bool c1;
HXDLIN( 366)							if ((data->nodeType != ::Xml_obj::Document)) {
HXLINE( 366)								c1 = (data->nodeType == ::Xml_obj::Element);
            							}
            							else {
HXLINE( 366)								c1 = true;
            							}
HXDLIN( 366)							if (c1) {
HXLINE( 366)								HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(data->nodeType))));
            							}
HXDLIN( 366)							c = ::Xml_obj::createDocType(data->nodeValue);
            						}
            						else {
HXLINE( 368)							if ((data->nodeType == ::Xml_obj::ProcessingInstruction)) {
HXLINE( 370)								bool c1;
HXDLIN( 370)								if ((data->nodeType != ::Xml_obj::Document)) {
HXLINE( 370)									c1 = (data->nodeType == ::Xml_obj::Element);
            								}
            								else {
HXLINE( 370)									c1 = true;
            								}
HXDLIN( 370)								if (c1) {
HXLINE( 370)									HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(data->nodeType))));
            								}
HXDLIN( 370)								c = ::Xml_obj::createProcessingInstruction(data->nodeValue);
            							}
            							else {
HXLINE( 372)								if ((data->nodeType == ::Xml_obj::Document)) {
HXLINE( 374)									c = ::Xml_obj::createDocument();
HXLINE( 375)									{
HXLINE( 375)										 ::Dynamic el = data->elements();
HXDLIN( 375)										while(( (bool)(el->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE( 375)											 ::Xml el1 = ( ( ::Xml)(el->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXLINE( 377)											c->addChild(::polymod::util::Util_obj::copyXml(el1,c));
            										}
            									}
            								}
            							}
            						}
            					}
            				}
            			}
            		}
HXLINE( 380)		c->parent = parent;
HXLINE( 381)		return c;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Util_obj,copyXml,return )

::String Util_obj::uCat(::String a,::String b){
            	HX_GC_STACKFRAME(&_hx_pos_ed681bbd235d58c2_386_uCat)
HXLINE( 387)		 ::StringBuf sb =  ::StringBuf_obj::__alloc( HX_CTX );
HXLINE( 388)		{
HXLINE( 388)			::String x = ::Std_obj::string(a);
HXDLIN( 388)			if (::hx::IsNotNull( sb->charBuf )) {
HXLINE( 388)				sb->flush();
            			}
HXDLIN( 388)			if (::hx::IsNull( sb->b )) {
HXLINE( 388)				sb->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(x));
            			}
            			else {
HXLINE( 388)				::Array< ::String > sb1 = sb->b;
HXDLIN( 388)				sb1->push(::Std_obj::string(x));
            			}
            		}
HXLINE( 389)		{
HXLINE( 389)			::String x1 = ::Std_obj::string(b);
HXDLIN( 389)			if (::hx::IsNotNull( sb->charBuf )) {
HXLINE( 389)				sb->flush();
            			}
HXDLIN( 389)			if (::hx::IsNull( sb->b )) {
HXLINE( 389)				sb->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(x1));
            			}
            			else {
HXLINE( 389)				::Array< ::String > sb1 = sb->b;
HXDLIN( 389)				sb1->push(::Std_obj::string(x1));
            			}
            		}
HXLINE( 390)		return sb->toString();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Util_obj,uCat,return )

::String Util_obj::uCharAt(::String str,int index){
            	HX_STACKFRAME(&_hx_pos_ed681bbd235d58c2_398_uCharAt)
HXDLIN( 398)		return str.charAt(index);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Util_obj,uCharAt,return )

::String Util_obj::uJoin(::Array< ::String > arr,::String token){
            	HX_GC_STACKFRAME(&_hx_pos_ed681bbd235d58c2_403_uJoin)
HXLINE( 404)		 ::StringBuf sb =  ::StringBuf_obj::__alloc( HX_CTX );
HXLINE( 405)		int i = 0;
HXLINE( 406)		{
HXLINE( 406)			int _g = 0;
HXDLIN( 406)			while((_g < arr->length)){
HXLINE( 406)				::String str = arr->__get(_g);
HXDLIN( 406)				_g = (_g + 1);
HXLINE( 408)				{
HXLINE( 408)					if (::hx::IsNotNull( sb->charBuf )) {
HXLINE( 408)						sb->flush();
            					}
HXDLIN( 408)					if (::hx::IsNull( sb->b )) {
HXLINE( 408)						sb->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(str));
            					}
            					else {
HXLINE( 408)						::Array< ::String > sb1 = sb->b;
HXDLIN( 408)						sb1->push(::Std_obj::string(str));
            					}
            				}
HXLINE( 409)				if ((i != (arr->length - 1))) {
HXLINE( 411)					if (::hx::IsNotNull( sb->charBuf )) {
HXLINE( 411)						sb->flush();
            					}
HXDLIN( 411)					if (::hx::IsNull( sb->b )) {
HXLINE( 411)						sb->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(token));
            					}
            					else {
HXLINE( 411)						::Array< ::String > sb1 = sb->b;
HXDLIN( 411)						sb1->push(::Std_obj::string(token));
            					}
            				}
HXLINE( 413)				i = (i + 1);
            			}
            		}
HXLINE( 415)		return sb->toString();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Util_obj,uJoin,return )

::String Util_obj::uCombine(::Array< ::String > arr){
            	HX_GC_STACKFRAME(&_hx_pos_ed681bbd235d58c2_419_uCombine)
HXLINE( 420)		 ::StringBuf sb =  ::StringBuf_obj::__alloc( HX_CTX );
HXLINE( 421)		{
HXLINE( 421)			int _g = 0;
HXDLIN( 421)			while((_g < arr->length)){
HXLINE( 421)				::String str = arr->__get(_g);
HXDLIN( 421)				_g = (_g + 1);
HXLINE( 423)				{
HXLINE( 423)					if (::hx::IsNotNull( sb->charBuf )) {
HXLINE( 423)						sb->flush();
            					}
HXDLIN( 423)					if (::hx::IsNull( sb->b )) {
HXLINE( 423)						sb->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(str));
            					}
            					else {
HXLINE( 423)						::Array< ::String > sb1 = sb->b;
HXDLIN( 423)						sb1->push(::Std_obj::string(str));
            					}
            				}
            			}
            		}
HXLINE( 425)		return sb->toString();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Util_obj,uCombine,return )

::String Util_obj::uExtension(::String str,::hx::Null< bool >  __o_lowerCase){
            		bool lowerCase = __o_lowerCase.Default(false);
            	HX_STACKFRAME(&_hx_pos_ed681bbd235d58c2_429_uExtension)
HXLINE( 430)		int i = ::polymod::util::Util_obj::uLastIndexOf(str,HX_(".",2e,00,00,00),null());
HXLINE( 431)		::String extension = ::polymod::util::Util_obj::uSubstr(str,(i + 1),(::polymod::util::Util_obj::uLength(str) - (i + 1)));
HXLINE( 432)		if (lowerCase) {
HXLINE( 434)			extension = extension.toLowerCase();
            		}
HXLINE( 436)		return extension;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Util_obj,uExtension,return )

int Util_obj::uIndexOf(::String str,::String substr, ::Dynamic startIndex){
            	HX_STACKFRAME(&_hx_pos_ed681bbd235d58c2_444_uIndexOf)
HXDLIN( 444)		return str.indexOf(substr,startIndex);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Util_obj,uIndexOf,return )

int Util_obj::uLastIndexOf(::String str,::String value, ::Dynamic startIndex){
            	HX_STACKFRAME(&_hx_pos_ed681bbd235d58c2_453_uLastIndexOf)
HXDLIN( 453)		return str.lastIndexOf(value,startIndex);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Util_obj,uLastIndexOf,return )

int Util_obj::uLength(::String str){
            	HX_STACKFRAME(&_hx_pos_ed681bbd235d58c2_462_uLength)
HXDLIN( 462)		return str.length;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Util_obj,uLength,return )

::String Util_obj::uPathPop(::String str){
            	HX_STACKFRAME(&_hx_pos_ed681bbd235d58c2_467_uPathPop)
HXLINE( 473)		::Array< ::String > path = str.split(HX_("/",2f,00,00,00));
HXLINE( 474)		path->pop();
HXLINE( 475)		return path->join(HX_("/",2f,00,00,00));
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Util_obj,uPathPop,return )

::String Util_obj::uTrimFinalCharIf(::String str,::String match){
            	HX_STACKFRAME(&_hx_pos_ed681bbd235d58c2_480_uTrimFinalCharIf)
HXLINE( 481)		int uLength = ::polymod::util::Util_obj::uLength(str);
HXLINE( 482)		int last = ::polymod::util::Util_obj::uLastIndexOf(str,match,null());
HXLINE( 483)		if ((last == (uLength - 1))) {
HXLINE( 485)			str = ::polymod::util::Util_obj::uSubstr(str,0,(uLength - 1));
HXLINE( 486)			uLength = ::polymod::util::Util_obj::uLength(str);
            		}
HXLINE( 488)		return str;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Util_obj,uTrimFinalCharIf,return )

::String Util_obj::uTrimFinalEndlines(::String str){
            	HX_STACKFRAME(&_hx_pos_ed681bbd235d58c2_492_uTrimFinalEndlines)
HXLINE( 493)		bool done = false;
HXLINE( 494)		::String fix = HX_("",00,00,00,00);
HXLINE( 495)		::String last = HX_("",00,00,00,00);
HXLINE( 496)		while(!(done)){
HXLINE( 498)			::String fix = ::polymod::util::Util_obj::uTrimFinalCharIf(str,HX_("\n",0a,00,00,00));
HXLINE( 499)			fix = ::polymod::util::Util_obj::uTrimFinalCharIf(fix,HX_("\r",0d,00,00,00));
HXLINE( 500)			if ((fix == str)) {
HXLINE( 502)				done = true;
            			}
            			else {
HXLINE( 506)				str = fix;
            			}
            		}
HXLINE( 509)		return str;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Util_obj,uTrimFinalEndlines,return )

::String Util_obj::uTrimFirstCharIf(::String str,::String match){
            	HX_STACKFRAME(&_hx_pos_ed681bbd235d58c2_513_uTrimFirstCharIf)
HXLINE( 514)		int uLength = ::polymod::util::Util_obj::uLength(str);
HXLINE( 515)		int first = ::polymod::util::Util_obj::uIndexOf(str,match,null());
HXLINE( 516)		if ((first == 0)) {
HXLINE( 518)			str = ::polymod::util::Util_obj::uSubstr(str,1,uLength);
HXLINE( 519)			uLength = ::polymod::util::Util_obj::uLength(str);
            		}
HXLINE( 521)		return str;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Util_obj,uTrimFirstCharIf,return )

::String Util_obj::uTrimFirstEndlines(::String str){
            	HX_STACKFRAME(&_hx_pos_ed681bbd235d58c2_525_uTrimFirstEndlines)
HXLINE( 526)		bool done = false;
HXLINE( 527)		::String fix = HX_("",00,00,00,00);
HXLINE( 528)		::String last = HX_("",00,00,00,00);
HXLINE( 529)		while(!(done)){
HXLINE( 531)			::String fix = ::polymod::util::Util_obj::uTrimFirstCharIf(str,HX_("\n",0a,00,00,00));
HXLINE( 532)			fix = ::polymod::util::Util_obj::uTrimFirstCharIf(fix,HX_("\r",0d,00,00,00));
HXLINE( 533)			if ((fix == str)) {
HXLINE( 535)				done = true;
            			}
            			else {
HXLINE( 539)				str = fix;
            			}
            		}
HXLINE( 542)		return str;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Util_obj,uTrimFirstEndlines,return )

::Array< ::String > Util_obj::uSplit(::String str,::String substr){
            	HX_STACKFRAME(&_hx_pos_ed681bbd235d58c2_550_uSplit)
HXDLIN( 550)		return str.split(substr);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Util_obj,uSplit,return )

::String Util_obj::uSplitReplace(::String s,::String substr,::String by){
            	HX_GC_STACKFRAME(&_hx_pos_ed681bbd235d58c2_555_uSplitReplace)
HXLINE( 556)		if ((::polymod::util::Util_obj::uIndexOf(s,substr,null()) == -1)) {
HXLINE( 557)			return s;
            		}
HXLINE( 559)		::Array< ::String > arr = ::polymod::util::Util_obj::uSplit(s,substr);
HXLINE( 561)		bool _hx_tmp;
HXDLIN( 561)		if (::hx::IsNotNull( arr )) {
HXLINE( 561)			_hx_tmp = (arr->length < 2);
            		}
            		else {
HXLINE( 561)			_hx_tmp = true;
            		}
HXDLIN( 561)		if (_hx_tmp) {
HXLINE( 562)			return s;
            		}
HXLINE( 564)		 ::StringBuf sb =  ::StringBuf_obj::__alloc( HX_CTX );
HXLINE( 565)		{
HXLINE( 565)			int _g = 0;
HXDLIN( 565)			int _g1 = arr->length;
HXDLIN( 565)			while((_g < _g1)){
HXLINE( 565)				_g = (_g + 1);
HXDLIN( 565)				int i = (_g - 1);
HXLINE( 567)				::String bit = arr->__get(i);
HXLINE( 568)				{
HXLINE( 568)					if (::hx::IsNotNull( sb->charBuf )) {
HXLINE( 568)						sb->flush();
            					}
HXDLIN( 568)					if (::hx::IsNull( sb->b )) {
HXLINE( 568)						sb->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(bit));
            					}
            					else {
HXLINE( 568)						::Array< ::String > sb1 = sb->b;
HXDLIN( 568)						sb1->push(::Std_obj::string(bit));
            					}
            				}
HXLINE( 569)				if ((i != (arr->length - 1))) {
HXLINE( 571)					if (::hx::IsNotNull( sb->charBuf )) {
HXLINE( 571)						sb->flush();
            					}
HXDLIN( 571)					if (::hx::IsNull( sb->b )) {
HXLINE( 571)						sb->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(by));
            					}
            					else {
HXLINE( 571)						::Array< ::String > sb1 = sb->b;
HXDLIN( 571)						sb1->push(::Std_obj::string(by));
            					}
            				}
            			}
            		}
HXLINE( 575)		return sb->toString();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Util_obj,uSplitReplace,return )

::String Util_obj::uSubstr(::String str,int pos, ::Dynamic len){
            	HX_STACKFRAME(&_hx_pos_ed681bbd235d58c2_583_uSubstr)
HXDLIN( 583)		return str.substr(pos,len);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Util_obj,uSubstr,return )

::String Util_obj::uSubstring(::String str,int startIndex, ::Dynamic endIndex){
            	HX_STACKFRAME(&_hx_pos_ed681bbd235d58c2_592_uSubstring)
HXDLIN( 592)		return str.substring(startIndex,endIndex);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Util_obj,uSubstring,return )


Util_obj::Util_obj()
{
}

bool Util_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"sl") ) { outValue = sl_dyn(); return true; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"uCat") ) { outValue = uCat_dyn(); return true; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"uJoin") ) { outValue = uJoin_dyn(); return true; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"uSplit") ) { outValue = uSplit_dyn(); return true; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"copyXml") ) { outValue = copyXml_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"uCharAt") ) { outValue = uCharAt_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"uLength") ) { outValue = uLength_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"uSubstr") ) { outValue = uSubstr_dyn(); return true; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"stripXML") ) { outValue = stripXML_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"pathJoin") ) { outValue = pathJoin_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"uCombine") ) { outValue = uCombine_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"uIndexOf") ) { outValue = uIndexOf_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"uPathPop") ) { outValue = uPathPop_dyn(); return true; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"mergeText") ) { outValue = mergeText_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"appendXML") ) { outValue = appendXML_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"pathMerge") ) { outValue = pathMerge_dyn(); return true; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"appendText") ) { outValue = appendText_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"pathAppend") ) { outValue = pathAppend_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"uExtension") ) { outValue = uExtension_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"uSubstring") ) { outValue = uSubstring_dyn(); return true; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"pathSpecial") ) { outValue = pathSpecial_dyn(); return true; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"cleanSlashes") ) { outValue = cleanSlashes_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"uLastIndexOf") ) { outValue = uLastIndexOf_dyn(); return true; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"stripComments") ) { outValue = stripComments_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"uSplitReplace") ) { outValue = uSplitReplace_dyn(); return true; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"appendCSVOrTSV") ) { outValue = appendCSVOrTSV_dyn(); return true; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"stripPathPrefix") ) { outValue = stripPathPrefix_dyn(); return true; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"appendSpecialXML") ) { outValue = appendSpecialXML_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"uTrimFinalCharIf") ) { outValue = uTrimFinalCharIf_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"uTrimFirstCharIf") ) { outValue = uTrimFirstCharIf_dyn(); return true; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"listAllParentDirs") ) { outValue = listAllParentDirs_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"stripAssetsPrefix") ) { outValue = stripAssetsPrefix_dyn(); return true; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"mergeAndAppendText") ) { outValue = mergeAndAppendText_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"uTrimFinalEndlines") ) { outValue = uTrimFinalEndlines_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"uTrimFirstEndlines") ) { outValue = uTrimFirstEndlines_dyn(); return true; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"filterUnique_String") ) { outValue = filterUnique_String_dyn(); return true; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"trimLeadingWhiteSpace") ) { outValue = trimLeadingWhiteSpace_dyn(); return true; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"trimTrailingWhiteSpace") ) { outValue = trimTrailingWhiteSpace_dyn(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *Util_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *Util_obj_sStaticStorageInfo = 0;
#endif

::hx::Class Util_obj::__mClass;

static ::String Util_obj_sStaticFields[] = {
	HX_("filterUnique_String",c7,cc,12,5a),
	HX_("listAllParentDirs",13,d6,d3,bd),
	HX_("mergeAndAppendText",86,bb,89,90),
	HX_("mergeText",85,57,4d,74),
	HX_("appendText",a7,cf,05,5b),
	HX_("appendCSVOrTSV",08,df,4c,88),
	HX_("appendSpecialXML",98,73,b2,53),
	HX_("appendXML",1d,4c,6a,1f),
	HX_("stripComments",2c,40,17,46),
	HX_("stripPathPrefix",0f,d2,ba,43),
	HX_("trimLeadingWhiteSpace",81,9c,f1,7b),
	HX_("trimTrailingWhiteSpace",db,d6,b4,cb),
	HX_("stripXML",df,0d,70,dd),
	HX_("pathMerge",d3,96,86,fb),
	HX_("pathAppend",5f,85,09,a2),
	HX_("stripAssetsPrefix",6d,dd,37,77),
	HX_("pathSpecial",14,eb,0e,bc),
	HX_("pathJoin",2f,7c,04,3c),
	HX_("cleanSlashes",62,4b,95,f9),
	HX_("sl",99,64,00,00),
	HX_("copyXml",22,e9,88,43),
	HX_("uCat",a1,22,89,4d),
	HX_("uCharAt",be,33,59,ed),
	HX_("uJoin",ff,3e,20,8f),
	HX_("uCombine",8a,7a,8d,6b),
	HX_("uExtension",4a,3c,ec,68),
	HX_("uIndexOf",d4,98,1e,d2),
	HX_("uLastIndexOf",9e,ae,1a,86),
	HX_("uLength",3b,4f,eb,d4),
	HX_("uPathPop",f7,d4,d7,fa),
	HX_("uTrimFinalCharIf",b2,65,84,19),
	HX_("uTrimFinalEndlines",63,3b,6c,0f),
	HX_("uTrimFirstCharIf",ec,c5,81,b7),
	HX_("uTrimFirstEndlines",1d,9e,ad,2f),
	HX_("uSplit",25,92,5d,dc),
	HX_("uSplitReplace",8f,9c,1c,9b),
	HX_("uSubstr",86,a9,ee,cf),
	HX_("uSubstring",1c,9b,c3,66),
	::String(null())
};

void Util_obj::__register()
{
	Util_obj _hx_dummy;
	Util_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("polymod.util.Util",96,7d,da,e4);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Util_obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(Util_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< Util_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Util_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Util_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace polymod
} // end namespace util
