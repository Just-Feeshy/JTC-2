#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif
#ifndef INCLUDED_haxe_Exception
#include <haxe/Exception.h>
#endif
#ifndef INCLUDED_polymod_Polymod
#include <polymod/Polymod.h>
#endif
#ifndef INCLUDED_polymod_format_BaseParseFormat
#include <polymod/format/BaseParseFormat.h>
#endif
#ifndef INCLUDED_polymod_format_CSV
#include <polymod/format/CSV.h>
#endif
#ifndef INCLUDED_polymod_format_CSVParseFormat
#include <polymod/format/CSVParseFormat.h>
#endif
#ifndef INCLUDED_polymod_format_TextFileFormat
#include <polymod/format/TextFileFormat.h>
#endif
#ifndef INCLUDED_polymod_util_Util
#include <polymod/util/Util.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_47f6066263d681f0_73_new,"polymod.format.CSVParseFormat","new",0x5ec44915,"polymod.format.CSVParseFormat.new","polymod/format/ParseRules.hx",73,0xc5c5c43b)
HX_LOCAL_STACK_FRAME(_hx_pos_47f6066263d681f0_81_get_isSimpleMode,"polymod.format.CSVParseFormat","get_isSimpleMode",0x118293f3,"polymod.format.CSVParseFormat.get_isSimpleMode","polymod/format/ParseRules.hx",81,0xc5c5c43b)
HX_LOCAL_STACK_FRAME(_hx_pos_47f6066263d681f0_86_parse,"polymod.format.CSVParseFormat","parse",0xf35d6028,"polymod.format.CSVParseFormat.parse","polymod/format/ParseRules.hx",86,0xc5c5c43b)
HX_LOCAL_STACK_FRAME(_hx_pos_47f6066263d681f0_90_append,"polymod.format.CSVParseFormat","append",0xa0a20845,"polymod.format.CSVParseFormat.append","polymod/format/ParseRules.hx",90,0xc5c5c43b)
HX_LOCAL_STACK_FRAME(_hx_pos_47f6066263d681f0_203_merge,"polymod.format.CSVParseFormat","merge",0x3bce72ad,"polymod.format.CSVParseFormat.merge","polymod/format/ParseRules.hx",203,0xc5c5c43b)
HX_LOCAL_STACK_FRAME(_hx_pos_47f6066263d681f0_244_print,"polymod.format.CSVParseFormat","print",0xfe932822,"polymod.format.CSVParseFormat.print","polymod/format/ParseRules.hx",244,0xc5c5c43b)
static const ::String _hx_array_data_2d231aa3_16[] = {
	HX_("\r\n",5d,0b,00,00),
};
static const ::String _hx_array_data_2d231aa3_17[] = {
	HX_("\r\n",5d,0b,00,00),
};
namespace polymod{
namespace format{

void CSVParseFormat_obj::__construct(::String delimeter,bool quotedCells){
            	HX_STACKFRAME(&_hx_pos_47f6066263d681f0_73_new)
HXLINE(  74)		this->format = ::polymod::format::TextFileFormat_obj::CSV_dyn();
HXLINE(  75)		this->delimeter = delimeter;
HXLINE(  76)		this->quotedCells = quotedCells;
            	}

Dynamic CSVParseFormat_obj::__CreateEmpty() { return new CSVParseFormat_obj; }

void *CSVParseFormat_obj::_hx_vtable = 0;

Dynamic CSVParseFormat_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< CSVParseFormat_obj > _hx_result = new CSVParseFormat_obj();
	_hx_result->__construct(inArgs[0],inArgs[1]);
	return _hx_result;
}

bool CSVParseFormat_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x1a821905;
}

static ::polymod::format::BaseParseFormat_obj _hx_polymod_format_CSVParseFormat__hx_polymod_format_BaseParseFormat= {
	( ::String (::hx::Object::*)(::String,::String,::String))&::polymod::format::CSVParseFormat_obj::append,
	( ::String (::hx::Object::*)(::String,::String,::String))&::polymod::format::CSVParseFormat_obj::merge,
};

void *CSVParseFormat_obj::_hx_getInterface(int inHash) {
	switch(inHash) {
		case (int)0xa2d29dcc: return &_hx_polymod_format_CSVParseFormat__hx_polymod_format_BaseParseFormat;
	}
	#ifdef HXCPP_SCRIPTABLE
	return super::_hx_getInterface(inHash);
	#else
	return 0;
	#endif
}

bool CSVParseFormat_obj::get_isSimpleMode(){
            	HX_STACKFRAME(&_hx_pos_47f6066263d681f0_81_get_isSimpleMode)
HXDLIN(  81)		if ((this->delimeter == HX_(",",2c,00,00,00))) {
HXDLIN(  81)			return (this->quotedCells == false);
            		}
            		else {
HXDLIN(  81)			return false;
            		}
HXDLIN(  81)		return false;
            	}


HX_DEFINE_DYNAMIC_FUNC0(CSVParseFormat_obj,get_isSimpleMode,return )

 ::polymod::format::CSV CSVParseFormat_obj::parse(::String str){
            	HX_STACKFRAME(&_hx_pos_47f6066263d681f0_86_parse)
HXDLIN(  86)		return ::polymod::format::CSV_obj::parse(str,this->delimeter,this->quotedCells);
            	}


HX_DEFINE_DYNAMIC_FUNC1(CSVParseFormat_obj,parse,return )

::String CSVParseFormat_obj::append(::String baseText,::String appendText,::String id){
            	HX_STACKFRAME(&_hx_pos_47f6066263d681f0_90_append)
HXLINE(  91)		::String endLine = HX_("\n",0a,00,00,00);
HXLINE(  92)		if ((baseText.indexOf(HX_("\r\n",5d,0b,00,00),null()) != -1)) {
HXLINE(  94)			endLine = HX_("\r\n",5d,0b,00,00);
            		}
HXLINE(  96)		if (this->lookForHeaders) {
HXLINE(  98)			 ::polymod::format::CSV baseCSV;
HXLINE(  99)			 ::polymod::format::CSV appendCSV;
HXLINE( 102)			::String appendEndLine = HX_("\n",0a,00,00,00);
HXLINE( 103)			if ((appendText.indexOf(HX_("\r\n",5d,0b,00,00),null()) != -1)) {
HXLINE( 105)				appendEndLine = HX_("\r\n",5d,0b,00,00);
            			}
HXLINE( 107)			int appendLength = ::polymod::util::Util_obj::uLength(appendText);
HXLINE( 108)			int appendLast = ::polymod::util::Util_obj::uLastIndexOf(appendText,appendEndLine,null());
HXLINE( 109)			bool _hx_tmp;
HXDLIN( 109)			if ((appendLast != (appendLength - 1))) {
HXLINE( 109)				_hx_tmp = (appendLast == (appendLength - 2));
            			}
            			else {
HXLINE( 109)				_hx_tmp = true;
            			}
HXDLIN( 109)			if (_hx_tmp) {
HXLINE( 111)				appendText = ::polymod::util::Util_obj::uSubstr(appendText,0,(appendLength - ::polymod::util::Util_obj::uLength(appendEndLine)));
            			}
HXLINE( 114)			try {
            				HX_STACK_CATCHABLE( ::Dynamic, 0);
HXLINE( 116)				baseCSV = ::polymod::format::CSV_obj::parseWithFormat(baseText,::hx::ObjectPtr<OBJ_>(this));
HXLINE( 117)				appendCSV = ::polymod::format::CSV_obj::parseWithFormat(appendText,::hx::ObjectPtr<OBJ_>(this));
            			} catch( ::Dynamic _hx_e) {
            				if (_hx_e.IsClass<  ::Dynamic >() ){
            					HX_STACK_BEGIN_CATCH
            					 ::Dynamic _g = _hx_e;
HXLINE( 119)					{
HXLINE( 119)						null();
            					}
HXDLIN( 119)					 ::Dynamic msg = ::haxe::Exception_obj::caught(_g)->unwrap();
HXLINE( 121)					::polymod::Polymod_obj::error(HX_("append_error",63,d4,ca,e5),(((HX_("CSV append error (",c4,5c,df,c8) + id) + HX_("): ",0f,4f,1f,00)) + ::Std_obj::string(msg)),null());
HXLINE( 122)					return baseText;
            				}
            				else {
            					HX_STACK_DO_THROW(_hx_e);
            				}
            			}
HXLINE( 125)			::String finalText = baseText;
HXLINE( 126)			int finalLength = ::polymod::util::Util_obj::uLength(finalText);
HXLINE( 128)			int lastEndLine = ::polymod::util::Util_obj::uLastIndexOf(finalText,endLine,null());
HXLINE( 129)			bool addFinalEndline = false;
HXLINE( 131)			bool _hx_tmp1;
HXDLIN( 131)			if ((lastEndLine != (finalLength - 1))) {
HXLINE( 131)				_hx_tmp1 = (lastEndLine == (finalLength - 2));
            			}
            			else {
HXLINE( 131)				_hx_tmp1 = true;
            			}
HXDLIN( 131)			if (_hx_tmp1) {
HXLINE( 133)				finalText = ::polymod::util::Util_obj::uSubstr(finalText,0,(finalLength - ::polymod::util::Util_obj::uLength(endLine)));
HXLINE( 134)				addFinalEndline = true;
            			}
HXLINE( 137)			int compareFields = 0;
HXLINE( 138)			{
HXLINE( 138)				int _g = 0;
HXDLIN( 138)				int _g1 = baseCSV->fields->length;
HXDLIN( 138)				while((_g < _g1)){
HXLINE( 138)					_g = (_g + 1);
HXDLIN( 138)					int i = (_g - 1);
HXLINE( 140)					::String baseField = baseCSV->fields->__get(i);
HXLINE( 141)					bool appendFieldExists = (appendCSV->fields->indexOf(baseField,null()) != -1);
HXLINE( 142)					if (appendFieldExists) {
HXLINE( 143)						compareFields = (compareFields + 1);
            					}
            				}
            			}
HXLINE( 146)			if (this->lookForHeaders) {
HXLINE( 148)				if ((compareFields < ::Std_obj::_hx_int((( (Float)(baseCSV->fields->length) ) / ( (Float)(2) ))))) {
HXLINE( 150)					::polymod::Polymod_obj::error(HX_("append_error",63,d4,ca,e5),((HX_("Mod file (",42,83,9f,5c) + id) + HX_(") is missing most or all of the expected header fields",e4,52,a8,00)),HX_("init",10,3b,bb,45));
            				}
            			}
HXLINE( 154)			::Array< ::String > missingFields = ::Array_obj< ::String >::__new(0);
HXLINE( 156)			{
HXLINE( 156)				int _g2 = 0;
HXDLIN( 156)				int _g3 = appendCSV->grid->length;
HXDLIN( 156)				while((_g2 < _g3)){
HXLINE( 156)					_g2 = (_g2 + 1);
HXDLIN( 156)					int r = (_g2 - 1);
HXLINE( 158)					::String line = HX_("",00,00,00,00);
HXLINE( 159)					{
HXLINE( 159)						int _g = 0;
HXDLIN( 159)						int _g1 = baseCSV->fields->length;
HXDLIN( 159)						while((_g < _g1)){
HXLINE( 159)							_g = (_g + 1);
HXDLIN( 159)							int bi = (_g - 1);
HXLINE( 161)							::String baseField = baseCSV->fields->__get(bi);
HXLINE( 162)							int appendField = appendCSV->fields->indexOf(baseField,null());
HXLINE( 163)							if ((appendField != -1)) {
HXLINE( 165)								::String appendValue = appendCSV->grid->__get(r).StaticCast< ::Array< ::String > >()->__get(appendField);
HXLINE( 166)								if (::hx::IsNull( appendValue )) {
HXLINE( 168)									appendValue = HX_("",00,00,00,00);
            								}
HXLINE( 170)								line = (line + appendValue);
            							}
            							else {
HXLINE( 174)								if ((missingFields->indexOf(baseField,null()) == -1)) {
HXLINE( 176)									missingFields->push(baseField);
            								}
            							}
HXLINE( 179)							if ((bi != (baseCSV->fields->length - 1))) {
HXLINE( 181)								line = (line + this->delimeter);
            							}
            						}
            					}
HXLINE( 184)					finalText = (finalText + (endLine + line));
            				}
            			}
HXLINE( 187)			if (addFinalEndline) {
HXLINE( 189)				finalText = (finalText + endLine);
            			}
HXLINE( 192)			{
HXLINE( 192)				int _g4 = 0;
HXDLIN( 192)				while((_g4 < missingFields->length)){
HXLINE( 192)					::String baseField = missingFields->__get(_g4);
HXDLIN( 192)					_g4 = (_g4 + 1);
HXLINE( 194)					::polymod::Polymod_obj::warning(HX_("append_error",63,d4,ca,e5),((((HX_("Mod file (",42,83,9f,5c) + id) + HX_(") is missing expected field \"",0d,3e,8d,c8)) + baseField) + HX_("\", values will default to empty string.",aa,16,7f,ae)),HX_("init",10,3b,bb,45));
            				}
            			}
HXLINE( 197)			return finalText;
            		}
HXLINE( 199)		return ::polymod::util::Util_obj::appendCSVOrTSV(baseText,appendText,id);
            	}


HX_DEFINE_DYNAMIC_FUNC3(CSVParseFormat_obj,append,return )

::String CSVParseFormat_obj::merge(::String baseText,::String mergeText,::String id){
            	HX_STACKFRAME(&_hx_pos_47f6066263d681f0_203_merge)
HXLINE( 204)		 ::polymod::format::CSV baseCSV;
HXLINE( 205)		 ::polymod::format::CSV mergeCSV;
HXLINE( 206)		try {
            			HX_STACK_CATCHABLE( ::Dynamic, 0);
HXLINE( 208)			baseCSV = ::polymod::format::CSV_obj::parseWithFormat(baseText,::hx::ObjectPtr<OBJ_>(this));
HXLINE( 209)			mergeCSV = ::polymod::format::CSV_obj::parseWithFormat(mergeText,::hx::ObjectPtr<OBJ_>(this));
            		} catch( ::Dynamic _hx_e) {
            			if (_hx_e.IsClass<  ::Dynamic >() ){
            				HX_STACK_BEGIN_CATCH
            				 ::Dynamic _g = _hx_e;
HXLINE( 211)				{
HXLINE( 211)					null();
            				}
HXDLIN( 211)				 ::Dynamic msg = ::haxe::Exception_obj::caught(_g)->unwrap();
HXLINE( 213)				::polymod::Polymod_obj::error(HX_("merge_error",c1,8f,ea,85),(((HX_("CSV merge error (",6e,2a,b4,ea) + id) + HX_("): ",0f,4f,1f,00)) + ::Std_obj::string(msg)),null());
HXLINE( 214)				return baseText;
            			}
            			else {
            				HX_STACK_DO_THROW(_hx_e);
            			}
            		}
HXLINE( 217)		{
HXLINE( 217)			int _g = 0;
HXDLIN( 217)			::Array< ::Dynamic> _g1 = mergeCSV->grid;
HXDLIN( 217)			while((_g < _g1->length)){
HXLINE( 217)				::Array< ::String > row = _g1->__get(_g).StaticCast< ::Array< ::String > >();
HXDLIN( 217)				_g = (_g + 1);
HXLINE( 219)				::String flag;
HXDLIN( 219)				if ((row->length > 0)) {
HXLINE( 219)					flag = row->__get(0);
            				}
            				else {
HXLINE( 219)					flag = HX_("",00,00,00,00);
            				}
HXLINE( 220)				if ((flag != HX_("",00,00,00,00))) {
HXLINE( 222)					int _g = 0;
HXDLIN( 222)					int _g1 = baseCSV->grid->length;
HXDLIN( 222)					while((_g < _g1)){
HXLINE( 222)						_g = (_g + 1);
HXDLIN( 222)						int i = (_g - 1);
HXLINE( 224)						::Array< ::String > otherRow = baseCSV->grid->__get(i).StaticCast< ::Array< ::String > >();
HXLINE( 225)						::String otherFlag = otherRow->__get(0);
HXLINE( 226)						if ((flag == otherFlag)) {
HXLINE( 228)							int _g = 0;
HXDLIN( 228)							int _g1 = row->length;
HXDLIN( 228)							while((_g < _g1)){
HXLINE( 228)								_g = (_g + 1);
HXDLIN( 228)								int j = (_g - 1);
HXLINE( 230)								if ((j < otherRow->length)) {
HXLINE( 232)									otherRow[j] = row->__get(j);
            								}
            							}
            						}
            					}
            				}
            			}
            		}
HXLINE( 239)		::String result = this->print(baseCSV);
HXLINE( 240)		return result;
            	}


HX_DEFINE_DYNAMIC_FUNC3(CSVParseFormat_obj,merge,return )

::String CSVParseFormat_obj::print( ::polymod::format::CSV csv){
            	HX_GC_STACKFRAME(&_hx_pos_47f6066263d681f0_244_print)
HXLINE( 245)		 ::StringBuf buf =  ::StringBuf_obj::__alloc( HX_CTX );
HXLINE( 247)		int lf = 10;
HXLINE( 248)		int dq = 34;
HXLINE( 250)		{
HXLINE( 250)			int _g = 0;
HXDLIN( 250)			int _g1 = csv->fields->length;
HXDLIN( 250)			while((_g < _g1)){
HXLINE( 250)				_g = (_g + 1);
HXDLIN( 250)				int i = (_g - 1);
HXLINE( 252)				{
HXLINE( 252)					::String x = csv->fields->__get(i);
HXDLIN( 252)					if (::hx::IsNotNull( buf->charBuf )) {
HXLINE( 252)						buf->flush();
            					}
HXDLIN( 252)					if (::hx::IsNull( buf->b )) {
HXLINE( 252)						buf->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(x));
            					}
            					else {
HXLINE( 252)						::Array< ::String > buf1 = buf->b;
HXDLIN( 252)						buf1->push(::Std_obj::string(x));
            					}
            				}
HXLINE( 253)				if ((i != (csv->fields->length - 1))) {
HXLINE( 255)					::String x = this->delimeter;
HXDLIN( 255)					if (::hx::IsNotNull( buf->charBuf )) {
HXLINE( 255)						buf->flush();
            					}
HXDLIN( 255)					if (::hx::IsNull( buf->b )) {
HXLINE( 255)						buf->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(x));
            					}
            					else {
HXLINE( 255)						::Array< ::String > buf1 = buf->b;
HXDLIN( 255)						buf1->push(::Std_obj::string(x));
            					}
            				}
            			}
            		}
HXLINE( 259)		::String strSoFar = buf->toString();
HXLINE( 261)		if ((strSoFar.indexOf(HX_("\n",0a,00,00,00),null()) == -1)) {
HXLINE( 263)			if (::hx::IsNotNull( buf->charBuf )) {
HXLINE( 263)				buf->flush();
            			}
HXDLIN( 263)			if (::hx::IsNull( buf->b )) {
HXLINE( 263)				buf->b = ::Array_obj< ::String >::fromData( _hx_array_data_2d231aa3_16,1);
            			}
            			else {
HXLINE( 263)				buf->b->push(HX_("\r\n",5d,0b,00,00));
            			}
            		}
HXLINE( 266)		::Array< ::Dynamic> grid = csv->grid;
HXLINE( 268)		{
HXLINE( 268)			int _g2 = 0;
HXDLIN( 268)			int _g3 = grid->length;
HXDLIN( 268)			while((_g2 < _g3)){
HXLINE( 268)				_g2 = (_g2 + 1);
HXDLIN( 268)				int iy = (_g2 - 1);
HXLINE( 270)				::Array< ::String > row = grid->__get(iy).StaticCast< ::Array< ::String > >();
HXLINE( 271)				{
HXLINE( 271)					int _g = 0;
HXDLIN( 271)					int _g1 = row->length;
HXDLIN( 271)					while((_g < _g1)){
HXLINE( 271)						_g = (_g + 1);
HXDLIN( 271)						int ix = (_g - 1);
HXLINE( 273)						::String cell = row->__get(ix);
HXLINE( 274)						if (this->quotedCells) {
HXLINE( 276)							if ((dq >= 127)) {
HXLINE( 276)								::String x = ::String::fromCharCode(dq);
HXDLIN( 276)								if (::hx::IsNotNull( buf->charBuf )) {
HXLINE( 276)									buf->flush();
            								}
HXDLIN( 276)								if (::hx::IsNull( buf->b )) {
HXLINE( 276)									buf->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(x));
            								}
            								else {
HXLINE( 276)									::Array< ::String > buf1 = buf->b;
HXDLIN( 276)									buf1->push(::Std_obj::string(x));
            								}
            							}
            							else {
HXLINE( 276)								if (::hx::IsNull( buf->charBuf )) {
HXLINE( 276)									buf->charBuf = ::Array_obj< char >::__new();
            								}
HXDLIN( 276)								buf->charBuf->push(dq);
            							}
            						}
HXLINE( 278)						{
HXLINE( 278)							if (::hx::IsNotNull( buf->charBuf )) {
HXLINE( 278)								buf->flush();
            							}
HXDLIN( 278)							if (::hx::IsNull( buf->b )) {
HXLINE( 278)								buf->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(cell));
            							}
            							else {
HXLINE( 278)								::Array< ::String > buf1 = buf->b;
HXDLIN( 278)								buf1->push(::Std_obj::string(cell));
            							}
            						}
HXLINE( 279)						if (this->quotedCells) {
HXLINE( 281)							if ((dq >= 127)) {
HXLINE( 281)								::String x = ::String::fromCharCode(dq);
HXDLIN( 281)								if (::hx::IsNotNull( buf->charBuf )) {
HXLINE( 281)									buf->flush();
            								}
HXDLIN( 281)								if (::hx::IsNull( buf->b )) {
HXLINE( 281)									buf->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(x));
            								}
            								else {
HXLINE( 281)									::Array< ::String > buf1 = buf->b;
HXDLIN( 281)									buf1->push(::Std_obj::string(x));
            								}
            							}
            							else {
HXLINE( 281)								if (::hx::IsNull( buf->charBuf )) {
HXLINE( 281)									buf->charBuf = ::Array_obj< char >::__new();
            								}
HXDLIN( 281)								buf->charBuf->push(dq);
            							}
            						}
HXLINE( 283)						if ((ix != (row->length - 1))) {
HXLINE( 285)							::String x = this->delimeter;
HXDLIN( 285)							if (::hx::IsNotNull( buf->charBuf )) {
HXLINE( 285)								buf->flush();
            							}
HXDLIN( 285)							if (::hx::IsNull( buf->b )) {
HXLINE( 285)								buf->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(x));
            							}
            							else {
HXLINE( 285)								::Array< ::String > buf1 = buf->b;
HXDLIN( 285)								buf1->push(::Std_obj::string(x));
            							}
            						}
            					}
            				}
HXLINE( 288)				if ((iy != (grid->length - 1))) {
HXLINE( 290)					if (::hx::IsNotNull( buf->charBuf )) {
HXLINE( 290)						buf->flush();
            					}
HXDLIN( 290)					if (::hx::IsNull( buf->b )) {
HXLINE( 290)						buf->b = ::Array_obj< ::String >::fromData( _hx_array_data_2d231aa3_17,1);
            					}
            					else {
HXLINE( 290)						buf->b->push(HX_("\r\n",5d,0b,00,00));
            					}
            				}
            			}
            		}
HXLINE( 294)		return buf->toString();
            	}


HX_DEFINE_DYNAMIC_FUNC1(CSVParseFormat_obj,print,return )


::hx::ObjectPtr< CSVParseFormat_obj > CSVParseFormat_obj::__new(::String delimeter,bool quotedCells) {
	::hx::ObjectPtr< CSVParseFormat_obj > __this = new CSVParseFormat_obj();
	__this->__construct(delimeter,quotedCells);
	return __this;
}

::hx::ObjectPtr< CSVParseFormat_obj > CSVParseFormat_obj::__alloc(::hx::Ctx *_hx_ctx,::String delimeter,bool quotedCells) {
	CSVParseFormat_obj *__this = (CSVParseFormat_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(CSVParseFormat_obj), true, "polymod.format.CSVParseFormat"));
	*(void **)__this = CSVParseFormat_obj::_hx_vtable;
	__this->__construct(delimeter,quotedCells);
	return __this;
}

CSVParseFormat_obj::CSVParseFormat_obj()
{
}

void CSVParseFormat_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CSVParseFormat);
	HX_MARK_MEMBER_NAME(format,"format");
	HX_MARK_MEMBER_NAME(isSimpleMode,"isSimpleMode");
	HX_MARK_MEMBER_NAME(delimeter,"delimeter");
	HX_MARK_MEMBER_NAME(quotedCells,"quotedCells");
	HX_MARK_MEMBER_NAME(lookForHeaders,"lookForHeaders");
	HX_MARK_END_CLASS();
}

void CSVParseFormat_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(format,"format");
	HX_VISIT_MEMBER_NAME(isSimpleMode,"isSimpleMode");
	HX_VISIT_MEMBER_NAME(delimeter,"delimeter");
	HX_VISIT_MEMBER_NAME(quotedCells,"quotedCells");
	HX_VISIT_MEMBER_NAME(lookForHeaders,"lookForHeaders");
}

::hx::Val CSVParseFormat_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"parse") ) { return ::hx::Val( parse_dyn() ); }
		if (HX_FIELD_EQ(inName,"merge") ) { return ::hx::Val( merge_dyn() ); }
		if (HX_FIELD_EQ(inName,"print") ) { return ::hx::Val( print_dyn() ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"format") ) { return ::hx::Val( format ); }
		if (HX_FIELD_EQ(inName,"append") ) { return ::hx::Val( append_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"delimeter") ) { return ::hx::Val( delimeter ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"quotedCells") ) { return ::hx::Val( quotedCells ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"isSimpleMode") ) { return ::hx::Val( inCallProp == ::hx::paccAlways ? get_isSimpleMode() : isSimpleMode ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"lookForHeaders") ) { return ::hx::Val( lookForHeaders ); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"get_isSimpleMode") ) { return ::hx::Val( get_isSimpleMode_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val CSVParseFormat_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"format") ) { format=inValue.Cast<  ::polymod::format::TextFileFormat >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"delimeter") ) { delimeter=inValue.Cast< ::String >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"quotedCells") ) { quotedCells=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"isSimpleMode") ) { isSimpleMode=inValue.Cast< bool >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"lookForHeaders") ) { lookForHeaders=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CSVParseFormat_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("format",37,8f,8e,fd));
	outFields->push(HX_("isSimpleMode",3f,2d,b3,cd));
	outFields->push(HX_("delimeter",8b,2c,83,83));
	outFields->push(HX_("quotedCells",c9,09,54,60));
	outFields->push(HX_("lookForHeaders",7c,8d,66,72));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo CSVParseFormat_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::polymod::format::TextFileFormat */ ,(int)offsetof(CSVParseFormat_obj,format),HX_("format",37,8f,8e,fd)},
	{::hx::fsBool,(int)offsetof(CSVParseFormat_obj,isSimpleMode),HX_("isSimpleMode",3f,2d,b3,cd)},
	{::hx::fsString,(int)offsetof(CSVParseFormat_obj,delimeter),HX_("delimeter",8b,2c,83,83)},
	{::hx::fsBool,(int)offsetof(CSVParseFormat_obj,quotedCells),HX_("quotedCells",c9,09,54,60)},
	{::hx::fsBool,(int)offsetof(CSVParseFormat_obj,lookForHeaders),HX_("lookForHeaders",7c,8d,66,72)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *CSVParseFormat_obj_sStaticStorageInfo = 0;
#endif

static ::String CSVParseFormat_obj_sMemberFields[] = {
	HX_("format",37,8f,8e,fd),
	HX_("isSimpleMode",3f,2d,b3,cd),
	HX_("delimeter",8b,2c,83,83),
	HX_("quotedCells",c9,09,54,60),
	HX_("lookForHeaders",7c,8d,66,72),
	HX_("get_isSimpleMode",c8,19,52,d2),
	HX_("parse",33,90,55,bd),
	HX_("append",da,e1,d3,8f),
	HX_("merge",b8,a2,c6,05),
	HX_("print",2d,58,8b,c8),
	::String(null()) };

::hx::Class CSVParseFormat_obj::__mClass;

void CSVParseFormat_obj::__register()
{
	CSVParseFormat_obj _hx_dummy;
	CSVParseFormat_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("polymod.format.CSVParseFormat",a3,1a,23,2d);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(CSVParseFormat_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< CSVParseFormat_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = CSVParseFormat_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = CSVParseFormat_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace polymod
} // end namespace format
