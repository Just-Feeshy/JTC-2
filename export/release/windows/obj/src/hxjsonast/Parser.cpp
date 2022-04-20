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
#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_hxjsonast_Error
#include <hxjsonast/Error.h>
#endif
#ifndef INCLUDED_hxjsonast_JObjectField
#include <hxjsonast/JObjectField.h>
#endif
#ifndef INCLUDED_hxjsonast_Json
#include <hxjsonast/Json.h>
#endif
#ifndef INCLUDED_hxjsonast_JsonValue
#include <hxjsonast/JsonValue.h>
#endif
#ifndef INCLUDED_hxjsonast_Parser
#include <hxjsonast/Parser.h>
#endif
#ifndef INCLUDED_hxjsonast_Position
#include <hxjsonast/Position.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_5a224932378bec66_24_new,"hxjsonast.Parser","new",0x25959e55,"hxjsonast.Parser.new","hxjsonast/Parser.hx",24,0xd2d3ba9a)
HX_LOCAL_STACK_FRAME(_hx_pos_5a224932378bec66_31_parseRec,"hxjsonast.Parser","parseRec",0x23ff5cc8,"hxjsonast.Parser.parseRec","hxjsonast/Parser.hx",31,0xd2d3ba9a)
HX_LOCAL_STACK_FRAME(_hx_pos_5a224932378bec66_135_parseString,"hxjsonast.Parser","parseString",0x8ccd2059,"hxjsonast.Parser.parseString","hxjsonast/Parser.hx",135,0xd2d3ba9a)
HX_LOCAL_STACK_FRAME(_hx_pos_5a224932378bec66_210_parseNumber,"hxjsonast.Parser","parseNumber",0x1d177e51,"hxjsonast.Parser.parseNumber","hxjsonast/Parser.hx",210,0xd2d3ba9a)
HX_LOCAL_STACK_FRAME(_hx_pos_5a224932378bec66_264_nextChar,"hxjsonast.Parser","nextChar",0x3b127f54,"hxjsonast.Parser.nextChar","hxjsonast/Parser.hx",264,0xd2d3ba9a)
HX_LOCAL_STACK_FRAME(_hx_pos_5a224932378bec66_268_mk,"hxjsonast.Parser","mk",0x12894709,"hxjsonast.Parser.mk","hxjsonast/Parser.hx",268,0xd2d3ba9a)
HX_LOCAL_STACK_FRAME(_hx_pos_5a224932378bec66_272_mkPos,"hxjsonast.Parser","mkPos",0x5d6d1a0b,"hxjsonast.Parser.mkPos","hxjsonast/Parser.hx",272,0xd2d3ba9a)
HX_LOCAL_STACK_FRAME(_hx_pos_5a224932378bec66_275_invalidChar,"hxjsonast.Parser","invalidChar",0xaa2ef862,"hxjsonast.Parser.invalidChar","hxjsonast/Parser.hx",275,0xd2d3ba9a)
HX_LOCAL_STACK_FRAME(_hx_pos_5a224932378bec66_281_invalidNumber,"hxjsonast.Parser","invalidNumber",0xb82c9b55,"hxjsonast.Parser.invalidNumber","hxjsonast/Parser.hx",281,0xd2d3ba9a)
HX_LOCAL_STACK_FRAME(_hx_pos_5a224932378bec66_17_parse,"hxjsonast.Parser","parse",0x111e8568,"hxjsonast.Parser.parse","hxjsonast/Parser.hx",17,0xd2d3ba9a)
namespace hxjsonast{

void Parser_obj::__construct(::String source,::String filename){
            	HX_STACKFRAME(&_hx_pos_5a224932378bec66_24_new)
HXLINE(  25)		this->source = source;
HXLINE(  26)		this->filename = filename;
HXLINE(  27)		this->pos = 0;
            	}

Dynamic Parser_obj::__CreateEmpty() { return new Parser_obj; }

void *Parser_obj::_hx_vtable = 0;

Dynamic Parser_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Parser_obj > _hx_result = new Parser_obj();
	_hx_result->__construct(inArgs[0],inArgs[1]);
	return _hx_result;
}

bool Parser_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x7f7a3b45;
}

 ::hxjsonast::Json Parser_obj::parseRec(){
            	HX_GC_STACKFRAME(&_hx_pos_5a224932378bec66_31_parseRec)
HXDLIN(  31)		while(true){
HXLINE(  32)			int c = this->source.cca(this->pos++);
HXLINE(  33)			switch((int)(c)){
            				case (int)9: case (int)10: case (int)13: case (int)32: {
            				}
            				break;
            				case (int)34: {
HXLINE( 124)					int save = this->pos;
HXLINE( 125)					::String s = this->parseString();
HXLINE( 126)					return  ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JString(s), ::hxjsonast::Position_obj::__alloc( HX_CTX ,this->filename,(save - 1),this->pos));
            				}
            				break;
            				case (int)45: case (int)48: case (int)49: case (int)50: case (int)51: case (int)52: case (int)53: case (int)54: case (int)55: case (int)56: case (int)57: {
HXLINE( 128)					int start = (this->pos - 1);
HXDLIN( 128)					bool minus = (c == 45);
HXDLIN( 128)					bool digit = !(minus);
HXDLIN( 128)					bool zero = (c == 48);
HXDLIN( 128)					bool point = false;
HXDLIN( 128)					bool e = false;
HXDLIN( 128)					bool pm = false;
HXDLIN( 128)					bool end = false;
HXDLIN( 128)					while(true){
HXLINE( 128)						switch((int)(this->source.cca(this->pos++))){
            							case (int)43: case (int)45: {
HXLINE( 128)								bool _hx_tmp;
HXDLIN( 128)								if (e) {
HXLINE( 128)									_hx_tmp = pm;
            								}
            								else {
HXLINE( 128)									_hx_tmp = true;
            								}
HXDLIN( 128)								if (_hx_tmp) {
HXLINE( 128)									this->invalidNumber(start);
            								}
HXDLIN( 128)								digit = false;
HXDLIN( 128)								pm = true;
            							}
            							break;
            							case (int)46: {
HXLINE( 128)								bool _hx_tmp;
HXDLIN( 128)								if (!(minus)) {
HXLINE( 128)									_hx_tmp = point;
            								}
            								else {
HXLINE( 128)									_hx_tmp = true;
            								}
HXDLIN( 128)								if (_hx_tmp) {
HXLINE( 128)									this->invalidNumber(start);
            								}
HXDLIN( 128)								digit = false;
HXDLIN( 128)								point = true;
            							}
            							break;
            							case (int)48: {
HXLINE( 128)								bool _hx_tmp;
HXDLIN( 128)								if (zero) {
HXLINE( 128)									_hx_tmp = !(point);
            								}
            								else {
HXLINE( 128)									_hx_tmp = false;
            								}
HXDLIN( 128)								if (_hx_tmp) {
HXLINE( 128)									this->invalidNumber(start);
            								}
HXDLIN( 128)								if (minus) {
HXLINE( 128)									minus = false;
HXDLIN( 128)									zero = true;
            								}
HXDLIN( 128)								digit = true;
            							}
            							break;
            							case (int)49: case (int)50: case (int)51: case (int)52: case (int)53: case (int)54: case (int)55: case (int)56: case (int)57: {
HXLINE( 128)								bool _hx_tmp;
HXDLIN( 128)								if (zero) {
HXLINE( 128)									_hx_tmp = !(point);
            								}
            								else {
HXLINE( 128)									_hx_tmp = false;
            								}
HXDLIN( 128)								if (_hx_tmp) {
HXLINE( 128)									this->invalidNumber(start);
            								}
HXDLIN( 128)								if (minus) {
HXLINE( 128)									minus = false;
            								}
HXDLIN( 128)								digit = true;
HXDLIN( 128)								zero = false;
            							}
            							break;
            							case (int)69: case (int)101: {
HXLINE( 128)								bool _hx_tmp;
HXDLIN( 128)								bool _hx_tmp1;
HXDLIN( 128)								if (!(minus)) {
HXLINE( 128)									_hx_tmp1 = zero;
            								}
            								else {
HXLINE( 128)									_hx_tmp1 = true;
            								}
HXDLIN( 128)								if (!(_hx_tmp1)) {
HXLINE( 128)									_hx_tmp = e;
            								}
            								else {
HXLINE( 128)									_hx_tmp = true;
            								}
HXDLIN( 128)								if (_hx_tmp) {
HXLINE( 128)									this->invalidNumber(start);
            								}
HXDLIN( 128)								digit = false;
HXDLIN( 128)								e = true;
            							}
            							break;
            							default:{
HXLINE( 128)								if (!(digit)) {
HXLINE( 128)									this->invalidNumber(start);
            								}
HXDLIN( 128)								this->pos--;
HXDLIN( 128)								end = true;
            							}
            						}
HXDLIN( 128)						if (end) {
HXLINE( 128)							goto _hx_goto_2;
            						}
            					}
            					_hx_goto_2:;
HXDLIN( 128)					::String s = this->source.substr(start,(this->pos - start));
HXDLIN( 128)					return  ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNumber(s), ::hxjsonast::Position_obj::__alloc( HX_CTX ,this->filename,start,this->pos));
            				}
            				break;
            				case (int)91: {
HXLINE(  78)					::Array< ::Dynamic> values = ::Array_obj< ::Dynamic>::__new(0);
HXLINE(  79)					 ::Dynamic comma = null();
HXLINE(  80)					int startPos = (this->pos - 1);
HXLINE(  81)					while(true){
HXLINE(  82)						switch((int)(this->source.cca(this->pos++))){
            							case (int)9: case (int)10: case (int)13: case (int)32: {
            							}
            							break;
            							case (int)44: {
HXLINE(  90)								if (( (bool)(comma) )) {
HXLINE(  91)									comma = false;
            								}
            								else {
HXLINE(  93)									this->invalidChar();
            								}
            							}
            							break;
            							case (int)93: {
HXLINE(  86)								if (::hx::IsEq( comma,false )) {
HXLINE(  87)									this->invalidChar();
            								}
HXLINE(  88)								return  ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JArray(values), ::hxjsonast::Position_obj::__alloc( HX_CTX ,this->filename,startPos,this->pos));
            							}
            							break;
            							default:{
HXLINE(  95)								if (( (bool)(comma) )) {
HXLINE(  96)									this->invalidChar();
            								}
HXLINE(  97)								this->pos--;
HXLINE(  98)								values->push(this->parseRec());
HXLINE(  99)								comma = true;
            							}
            						}
            					}
            				}
            				break;
            				case (int)102: {
HXLINE( 110)					int save = this->pos;
HXLINE( 111)					bool _hx_tmp;
HXDLIN( 111)					bool _hx_tmp1;
HXDLIN( 111)					bool _hx_tmp2;
HXDLIN( 111)					if ((this->source.cca(this->pos++) == 97)) {
HXLINE( 111)						_hx_tmp2 = (this->source.cca(this->pos++) != 108);
            					}
            					else {
HXLINE( 111)						_hx_tmp2 = true;
            					}
HXDLIN( 111)					if (!(_hx_tmp2)) {
HXLINE( 111)						_hx_tmp1 = (this->source.cca(this->pos++) != 115);
            					}
            					else {
HXLINE( 111)						_hx_tmp1 = true;
            					}
HXDLIN( 111)					if (!(_hx_tmp1)) {
HXLINE( 111)						_hx_tmp = (this->source.cca(this->pos++) != 101);
            					}
            					else {
HXLINE( 111)						_hx_tmp = true;
            					}
HXDLIN( 111)					if (_hx_tmp) {
HXLINE( 112)						this->pos = save;
HXLINE( 113)						this->invalidChar();
            					}
HXLINE( 115)					return  ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JBool(false), ::hxjsonast::Position_obj::__alloc( HX_CTX ,this->filename,(save - 1),this->pos));
            				}
            				break;
            				case (int)110: {
HXLINE( 117)					int save = this->pos;
HXLINE( 118)					bool _hx_tmp;
HXDLIN( 118)					bool _hx_tmp1;
HXDLIN( 118)					if ((this->source.cca(this->pos++) == 117)) {
HXLINE( 118)						_hx_tmp1 = (this->source.cca(this->pos++) != 108);
            					}
            					else {
HXLINE( 118)						_hx_tmp1 = true;
            					}
HXDLIN( 118)					if (!(_hx_tmp1)) {
HXLINE( 118)						_hx_tmp = (this->source.cca(this->pos++) != 108);
            					}
            					else {
HXLINE( 118)						_hx_tmp = true;
            					}
HXDLIN( 118)					if (_hx_tmp) {
HXLINE( 119)						this->pos = save;
HXLINE( 120)						this->invalidChar();
            					}
HXLINE( 122)					return  ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNull_dyn(), ::hxjsonast::Position_obj::__alloc( HX_CTX ,this->filename,(save - 1),this->pos));
            				}
            				break;
            				case (int)116: {
HXLINE( 103)					int save = this->pos;
HXLINE( 104)					bool _hx_tmp;
HXDLIN( 104)					bool _hx_tmp1;
HXDLIN( 104)					if ((this->source.cca(this->pos++) == 114)) {
HXLINE( 104)						_hx_tmp1 = (this->source.cca(this->pos++) != 117);
            					}
            					else {
HXLINE( 104)						_hx_tmp1 = true;
            					}
HXDLIN( 104)					if (!(_hx_tmp1)) {
HXLINE( 104)						_hx_tmp = (this->source.cca(this->pos++) != 101);
            					}
            					else {
HXLINE( 104)						_hx_tmp = true;
            					}
HXDLIN( 104)					if (_hx_tmp) {
HXLINE( 105)						this->pos = save;
HXLINE( 106)						this->invalidChar();
            					}
HXLINE( 108)					return  ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JBool(true), ::hxjsonast::Position_obj::__alloc( HX_CTX ,this->filename,(save - 1),this->pos));
            				}
            				break;
            				case (int)123: {
HXLINE(  37)					::Array< ::Dynamic> fields = ::Array_obj< ::Dynamic>::__new();
HXLINE(  38)					 ::haxe::ds::StringMap names =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
HXLINE(  39)					::String field = null();
HXLINE(  40)					 ::hxjsonast::Position fieldPos = null();
HXLINE(  41)					 ::Dynamic comma = null();
HXLINE(  42)					int startPos = (this->pos - 1);
HXLINE(  43)					while(true){
HXLINE(  44)						switch((int)(this->source.cca(this->pos++))){
            							case (int)9: case (int)10: case (int)13: case (int)32: {
            							}
            							break;
            							case (int)34: {
HXLINE(  64)								if (( (bool)(comma) )) {
HXLINE(  65)									this->invalidChar();
            								}
HXLINE(  66)								int fieldStartPos = (this->pos - 1);
HXLINE(  67)								field = this->parseString();
HXLINE(  68)								fieldPos =  ::hxjsonast::Position_obj::__alloc( HX_CTX ,this->filename,fieldStartPos,this->pos);
HXLINE(  69)								if (names->exists(field)) {
HXLINE(  70)									HX_STACK_DO_THROW(::haxe::Exception_obj::thrown( ::hxjsonast::Error_obj::__alloc( HX_CTX ,((HX_("Duplicate field name \"",88,8d,40,07) + field) + HX_("\"",22,00,00,00)),fieldPos)));
            								}
            								else {
HXLINE(  72)									names->set(field,true);
            								}
            							}
            							break;
            							case (int)44: {
HXLINE(  59)								if (( (bool)(comma) )) {
HXLINE(  60)									comma = false;
            								}
            								else {
HXLINE(  62)									this->invalidChar();
            								}
            							}
            							break;
            							case (int)58: {
HXLINE(  52)								if (::hx::IsNull( field )) {
HXLINE(  53)									this->invalidChar();
            								}
HXLINE(  54)								fields->push( ::hxjsonast::JObjectField_obj::__alloc( HX_CTX ,field,fieldPos,this->parseRec()));
HXLINE(  55)								field = null();
HXLINE(  56)								fieldPos = null();
HXLINE(  57)								comma = true;
            							}
            							break;
            							case (int)125: {
HXLINE(  48)								bool _hx_tmp;
HXDLIN(  48)								if (::hx::IsNull( field )) {
HXLINE(  48)									_hx_tmp = ::hx::IsEq( comma,false );
            								}
            								else {
HXLINE(  48)									_hx_tmp = true;
            								}
HXDLIN(  48)								if (_hx_tmp) {
HXLINE(  49)									this->invalidChar();
            								}
HXLINE(  50)								return  ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JObject(fields), ::hxjsonast::Position_obj::__alloc( HX_CTX ,this->filename,startPos,this->pos));
            							}
            							break;
            							default:{
HXLINE(  74)								this->invalidChar();
            							}
            						}
            					}
            				}
            				break;
            				default:{
HXLINE( 130)					this->invalidChar();
            				}
            			}
            		}
HXLINE(  31)		return null();
            	}


HX_DEFINE_DYNAMIC_FUNC0(Parser_obj,parseRec,return )

::String Parser_obj::parseString(){
            	HX_GC_STACKFRAME(&_hx_pos_5a224932378bec66_135_parseString)
HXLINE( 136)		int start = this->pos;
HXLINE( 137)		 ::StringBuf buf = null();
HXLINE( 138)		while(true){
HXLINE( 139)			int c = this->source.cca(this->pos++);
HXLINE( 140)			if ((c == 34)) {
HXLINE( 141)				goto _hx_goto_6;
            			}
HXLINE( 142)			if ((c == 92)) {
HXLINE( 143)				if (::hx::IsNull( buf )) {
HXLINE( 144)					buf =  ::StringBuf_obj::__alloc( HX_CTX );
            				}
HXLINE( 145)				{
HXLINE( 145)					::String s = this->source;
HXDLIN( 145)					 ::Dynamic len = ((this->pos - start) - 1);
HXDLIN( 145)					if (::hx::IsNotNull( buf->charBuf )) {
HXLINE( 145)						buf->flush();
            					}
HXDLIN( 145)					if (::hx::IsNull( buf->b )) {
HXLINE( 145)						buf->b = ::Array_obj< ::String >::__new(1)->init(0,s.substr(start,len));
            					}
            					else {
HXLINE( 145)						::Array< ::String > buf1 = buf->b;
HXDLIN( 145)						buf1->push(s.substr(start,len));
            					}
            				}
HXLINE( 146)				c = this->source.cca(this->pos++);
HXLINE( 147)				switch((int)(c)){
            					case (int)34: case (int)47: case (int)92: {
HXLINE( 159)						if ((c >= 127)) {
HXLINE( 159)							::String x = ::String::fromCharCode(c);
HXDLIN( 159)							if (::hx::IsNotNull( buf->charBuf )) {
HXLINE( 159)								buf->flush();
            							}
HXDLIN( 159)							if (::hx::IsNull( buf->b )) {
HXLINE( 159)								buf->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(x));
            							}
            							else {
HXLINE( 159)								::Array< ::String > buf1 = buf->b;
HXDLIN( 159)								buf1->push(::Std_obj::string(x));
            							}
            						}
            						else {
HXLINE( 159)							if (::hx::IsNull( buf->charBuf )) {
HXLINE( 159)								buf->charBuf = ::Array_obj< char >::__new();
            							}
HXDLIN( 159)							buf->charBuf->push(c);
            						}
            					}
            					break;
            					case (int)98: {
HXLINE( 155)						if (::hx::IsNull( buf->charBuf )) {
HXLINE( 155)							buf->charBuf = ::Array_obj< char >::__new();
            						}
HXDLIN( 155)						buf->charBuf->push(8);
            					}
            					break;
            					case (int)102: {
HXLINE( 157)						if (::hx::IsNull( buf->charBuf )) {
HXLINE( 157)							buf->charBuf = ::Array_obj< char >::__new();
            						}
HXDLIN( 157)						buf->charBuf->push(12);
            					}
            					break;
            					case (int)110: {
HXLINE( 151)						if (::hx::IsNull( buf->charBuf )) {
HXLINE( 151)							buf->charBuf = ::Array_obj< char >::__new();
            						}
HXDLIN( 151)						buf->charBuf->push(10);
            					}
            					break;
            					case (int)114: {
HXLINE( 149)						if (::hx::IsNull( buf->charBuf )) {
HXLINE( 149)							buf->charBuf = ::Array_obj< char >::__new();
            						}
HXDLIN( 149)						buf->charBuf->push(13);
            					}
            					break;
            					case (int)116: {
HXLINE( 153)						if (::hx::IsNull( buf->charBuf )) {
HXLINE( 153)							buf->charBuf = ::Array_obj< char >::__new();
            						}
HXDLIN( 153)						buf->charBuf->push(9);
            					}
            					break;
            					case (int)117: {
HXLINE( 161)						 ::Dynamic uc = ::Std_obj::parseInt((HX_("0x",48,2a,00,00) + this->source.substr(this->pos,4)));
HXLINE( 162)						 ::hxjsonast::Parser _hx_tmp = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN( 162)						_hx_tmp->pos = (_hx_tmp->pos + 4);
HXLINE( 164)						if (::hx::IsLessEq( uc,127 )) {
HXLINE( 165)							int c = ( (int)(uc) );
HXDLIN( 165)							if ((c >= 127)) {
HXLINE( 165)								::String x = ::String::fromCharCode(c);
HXDLIN( 165)								if (::hx::IsNotNull( buf->charBuf )) {
HXLINE( 165)									buf->flush();
            								}
HXDLIN( 165)								if (::hx::IsNull( buf->b )) {
HXLINE( 165)									buf->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(x));
            								}
            								else {
HXLINE( 165)									::Array< ::String > buf1 = buf->b;
HXDLIN( 165)									buf1->push(::Std_obj::string(x));
            								}
            							}
            							else {
HXLINE( 165)								if (::hx::IsNull( buf->charBuf )) {
HXLINE( 165)									buf->charBuf = ::Array_obj< char >::__new();
            								}
HXDLIN( 165)								buf->charBuf->push(c);
            							}
            						}
            						else {
HXLINE( 166)							if (::hx::IsLessEq( uc,2047 )) {
HXLINE( 167)								{
HXLINE( 167)									int c = (192 | (( (int)(uc) ) >> 6));
HXDLIN( 167)									if ((c >= 127)) {
HXLINE( 167)										::String x = ::String::fromCharCode(c);
HXDLIN( 167)										if (::hx::IsNotNull( buf->charBuf )) {
HXLINE( 167)											buf->flush();
            										}
HXDLIN( 167)										if (::hx::IsNull( buf->b )) {
HXLINE( 167)											buf->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(x));
            										}
            										else {
HXLINE( 167)											::Array< ::String > buf1 = buf->b;
HXDLIN( 167)											buf1->push(::Std_obj::string(x));
            										}
            									}
            									else {
HXLINE( 167)										if (::hx::IsNull( buf->charBuf )) {
HXLINE( 167)											buf->charBuf = ::Array_obj< char >::__new();
            										}
HXDLIN( 167)										buf->charBuf->push(c);
            									}
            								}
HXLINE( 168)								{
HXLINE( 168)									int c1 = (128 | (( (int)(uc) ) & 63));
HXDLIN( 168)									if ((c1 >= 127)) {
HXLINE( 168)										::String x = ::String::fromCharCode(c1);
HXDLIN( 168)										if (::hx::IsNotNull( buf->charBuf )) {
HXLINE( 168)											buf->flush();
            										}
HXDLIN( 168)										if (::hx::IsNull( buf->b )) {
HXLINE( 168)											buf->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(x));
            										}
            										else {
HXLINE( 168)											::Array< ::String > buf1 = buf->b;
HXDLIN( 168)											buf1->push(::Std_obj::string(x));
            										}
            									}
            									else {
HXLINE( 168)										if (::hx::IsNull( buf->charBuf )) {
HXLINE( 168)											buf->charBuf = ::Array_obj< char >::__new();
            										}
HXDLIN( 168)										buf->charBuf->push(c1);
            									}
            								}
            							}
            							else {
HXLINE( 169)								if (::hx::IsLessEq( uc,65535 )) {
HXLINE( 170)									{
HXLINE( 170)										int c = (224 | (( (int)(uc) ) >> 12));
HXDLIN( 170)										if ((c >= 127)) {
HXLINE( 170)											::String x = ::String::fromCharCode(c);
HXDLIN( 170)											if (::hx::IsNotNull( buf->charBuf )) {
HXLINE( 170)												buf->flush();
            											}
HXDLIN( 170)											if (::hx::IsNull( buf->b )) {
HXLINE( 170)												buf->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(x));
            											}
            											else {
HXLINE( 170)												::Array< ::String > buf1 = buf->b;
HXDLIN( 170)												buf1->push(::Std_obj::string(x));
            											}
            										}
            										else {
HXLINE( 170)											if (::hx::IsNull( buf->charBuf )) {
HXLINE( 170)												buf->charBuf = ::Array_obj< char >::__new();
            											}
HXDLIN( 170)											buf->charBuf->push(c);
            										}
            									}
HXLINE( 171)									{
HXLINE( 171)										int c1 = (128 | ((( (int)(uc) ) >> 6) & 63));
HXDLIN( 171)										if ((c1 >= 127)) {
HXLINE( 171)											::String x = ::String::fromCharCode(c1);
HXDLIN( 171)											if (::hx::IsNotNull( buf->charBuf )) {
HXLINE( 171)												buf->flush();
            											}
HXDLIN( 171)											if (::hx::IsNull( buf->b )) {
HXLINE( 171)												buf->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(x));
            											}
            											else {
HXLINE( 171)												::Array< ::String > buf1 = buf->b;
HXDLIN( 171)												buf1->push(::Std_obj::string(x));
            											}
            										}
            										else {
HXLINE( 171)											if (::hx::IsNull( buf->charBuf )) {
HXLINE( 171)												buf->charBuf = ::Array_obj< char >::__new();
            											}
HXDLIN( 171)											buf->charBuf->push(c1);
            										}
            									}
HXLINE( 172)									{
HXLINE( 172)										int c2 = (128 | (( (int)(uc) ) & 63));
HXDLIN( 172)										if ((c2 >= 127)) {
HXLINE( 172)											::String x = ::String::fromCharCode(c2);
HXDLIN( 172)											if (::hx::IsNotNull( buf->charBuf )) {
HXLINE( 172)												buf->flush();
            											}
HXDLIN( 172)											if (::hx::IsNull( buf->b )) {
HXLINE( 172)												buf->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(x));
            											}
            											else {
HXLINE( 172)												::Array< ::String > buf1 = buf->b;
HXDLIN( 172)												buf1->push(::Std_obj::string(x));
            											}
            										}
            										else {
HXLINE( 172)											if (::hx::IsNull( buf->charBuf )) {
HXLINE( 172)												buf->charBuf = ::Array_obj< char >::__new();
            											}
HXDLIN( 172)											buf->charBuf->push(c2);
            										}
            									}
            								}
            								else {
HXLINE( 174)									{
HXLINE( 174)										int c = (240 | (( (int)(uc) ) >> 18));
HXDLIN( 174)										if ((c >= 127)) {
HXLINE( 174)											::String x = ::String::fromCharCode(c);
HXDLIN( 174)											if (::hx::IsNotNull( buf->charBuf )) {
HXLINE( 174)												buf->flush();
            											}
HXDLIN( 174)											if (::hx::IsNull( buf->b )) {
HXLINE( 174)												buf->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(x));
            											}
            											else {
HXLINE( 174)												::Array< ::String > buf1 = buf->b;
HXDLIN( 174)												buf1->push(::Std_obj::string(x));
            											}
            										}
            										else {
HXLINE( 174)											if (::hx::IsNull( buf->charBuf )) {
HXLINE( 174)												buf->charBuf = ::Array_obj< char >::__new();
            											}
HXDLIN( 174)											buf->charBuf->push(c);
            										}
            									}
HXLINE( 175)									{
HXLINE( 175)										int c1 = (128 | ((( (int)(uc) ) >> 12) & 63));
HXDLIN( 175)										if ((c1 >= 127)) {
HXLINE( 175)											::String x = ::String::fromCharCode(c1);
HXDLIN( 175)											if (::hx::IsNotNull( buf->charBuf )) {
HXLINE( 175)												buf->flush();
            											}
HXDLIN( 175)											if (::hx::IsNull( buf->b )) {
HXLINE( 175)												buf->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(x));
            											}
            											else {
HXLINE( 175)												::Array< ::String > buf1 = buf->b;
HXDLIN( 175)												buf1->push(::Std_obj::string(x));
            											}
            										}
            										else {
HXLINE( 175)											if (::hx::IsNull( buf->charBuf )) {
HXLINE( 175)												buf->charBuf = ::Array_obj< char >::__new();
            											}
HXDLIN( 175)											buf->charBuf->push(c1);
            										}
            									}
HXLINE( 176)									{
HXLINE( 176)										int c2 = (128 | ((( (int)(uc) ) >> 6) & 63));
HXDLIN( 176)										if ((c2 >= 127)) {
HXLINE( 176)											::String x = ::String::fromCharCode(c2);
HXDLIN( 176)											if (::hx::IsNotNull( buf->charBuf )) {
HXLINE( 176)												buf->flush();
            											}
HXDLIN( 176)											if (::hx::IsNull( buf->b )) {
HXLINE( 176)												buf->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(x));
            											}
            											else {
HXLINE( 176)												::Array< ::String > buf1 = buf->b;
HXDLIN( 176)												buf1->push(::Std_obj::string(x));
            											}
            										}
            										else {
HXLINE( 176)											if (::hx::IsNull( buf->charBuf )) {
HXLINE( 176)												buf->charBuf = ::Array_obj< char >::__new();
            											}
HXDLIN( 176)											buf->charBuf->push(c2);
            										}
            									}
HXLINE( 177)									{
HXLINE( 177)										int c3 = (128 | (( (int)(uc) ) & 63));
HXDLIN( 177)										if ((c3 >= 127)) {
HXLINE( 177)											::String x = ::String::fromCharCode(c3);
HXDLIN( 177)											if (::hx::IsNotNull( buf->charBuf )) {
HXLINE( 177)												buf->flush();
            											}
HXDLIN( 177)											if (::hx::IsNull( buf->b )) {
HXLINE( 177)												buf->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(x));
            											}
            											else {
HXLINE( 177)												::Array< ::String > buf1 = buf->b;
HXDLIN( 177)												buf1->push(::Std_obj::string(x));
            											}
            										}
            										else {
HXLINE( 177)											if (::hx::IsNull( buf->charBuf )) {
HXLINE( 177)												buf->charBuf = ::Array_obj< char >::__new();
            											}
HXDLIN( 177)											buf->charBuf->push(c3);
            										}
            									}
            								}
            							}
            						}
            					}
            					break;
            					default:{
HXLINE( 183)						::String _hx_tmp = (HX_("Invalid escape sequence \\",73,af,f7,b2) + ::String::fromCharCode(c));
HXDLIN( 183)						HX_STACK_DO_THROW(::haxe::Exception_obj::thrown( ::hxjsonast::Error_obj::__alloc( HX_CTX ,_hx_tmp, ::hxjsonast::Position_obj::__alloc( HX_CTX ,this->filename,(this->pos - 2),this->pos))));
            					}
            				}
HXLINE( 185)				start = this->pos;
            			}
            			else {
HXLINE( 189)				if ((c >= 128)) {
HXLINE( 190)					this->pos++;
HXLINE( 191)					if ((c >= 252)) {
HXLINE( 191)						 ::hxjsonast::Parser _hx_tmp = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN( 191)						_hx_tmp->pos = (_hx_tmp->pos + 4);
            					}
            					else {
HXLINE( 192)						if ((c >= 248)) {
HXLINE( 192)							 ::hxjsonast::Parser _hx_tmp = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN( 192)							_hx_tmp->pos = (_hx_tmp->pos + 3);
            						}
            						else {
HXLINE( 193)							if ((c >= 240)) {
HXLINE( 193)								 ::hxjsonast::Parser _hx_tmp = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN( 193)								_hx_tmp->pos = (_hx_tmp->pos + 2);
            							}
            							else {
HXLINE( 194)								if ((c >= 224)) {
HXLINE( 194)									this->pos++;
            								}
            							}
            						}
            					}
            				}
            				else {
HXLINE( 197)					if ((c == 0)) {
HXLINE( 198)						this->pos--;
HXLINE( 199)						HX_STACK_DO_THROW(::haxe::Exception_obj::thrown( ::hxjsonast::Error_obj::__alloc( HX_CTX ,HX_("Unclosed string",ac,02,ef,ea), ::hxjsonast::Position_obj::__alloc( HX_CTX ,this->filename,(start - 1),this->pos))));
            					}
            				}
            			}
            		}
            		_hx_goto_6:;
HXLINE( 202)		if (::hx::IsNull( buf )) {
HXLINE( 203)			return this->source.substr(start,((this->pos - start) - 1));
            		}
            		else {
HXLINE( 205)			{
HXLINE( 205)				::String s = this->source;
HXDLIN( 205)				 ::Dynamic len = ((this->pos - start) - 1);
HXDLIN( 205)				if (::hx::IsNotNull( buf->charBuf )) {
HXLINE( 205)					buf->flush();
            				}
HXDLIN( 205)				if (::hx::IsNull( buf->b )) {
HXLINE( 205)					buf->b = ::Array_obj< ::String >::__new(1)->init(0,s.substr(start,len));
            				}
            				else {
HXLINE( 205)					::Array< ::String > buf1 = buf->b;
HXDLIN( 205)					buf1->push(s.substr(start,len));
            				}
            			}
HXLINE( 206)			return buf->toString();
            		}
HXLINE( 202)		return null();
            	}


HX_DEFINE_DYNAMIC_FUNC0(Parser_obj,parseString,return )

 ::hxjsonast::Json Parser_obj::parseNumber(int c){
            	HX_GC_STACKFRAME(&_hx_pos_5a224932378bec66_210_parseNumber)
HXLINE( 211)		int start = (this->pos - 1);
HXLINE( 212)		bool minus = (c == 45);
HXLINE( 213)		bool digit = !(minus);
HXLINE( 214)		bool zero = (c == 48);
HXLINE( 215)		bool point = false;
HXLINE( 216)		bool e = false;
HXLINE( 217)		bool pm = false;
HXLINE( 218)		bool end = false;
HXLINE( 219)		while(true){
HXLINE( 220)			switch((int)(this->source.cca(this->pos++))){
            				case (int)43: case (int)45: {
HXLINE( 247)					bool _hx_tmp;
HXDLIN( 247)					if (e) {
HXLINE( 247)						_hx_tmp = pm;
            					}
            					else {
HXLINE( 247)						_hx_tmp = true;
            					}
HXDLIN( 247)					if (_hx_tmp) {
HXLINE( 248)						this->invalidNumber(start);
            					}
HXLINE( 249)					digit = false;
HXDLIN( 249)					pm = true;
            				}
            				break;
            				case (int)46: {
HXLINE( 237)					bool _hx_tmp;
HXDLIN( 237)					if (!(minus)) {
HXLINE( 237)						_hx_tmp = point;
            					}
            					else {
HXLINE( 237)						_hx_tmp = true;
            					}
HXDLIN( 237)					if (_hx_tmp) {
HXLINE( 238)						this->invalidNumber(start);
            					}
HXLINE( 239)					digit = false;
HXLINE( 240)					point = true;
            				}
            				break;
            				case (int)48: {
HXLINE( 222)					bool _hx_tmp;
HXDLIN( 222)					if (zero) {
HXLINE( 222)						_hx_tmp = !(point);
            					}
            					else {
HXLINE( 222)						_hx_tmp = false;
            					}
HXDLIN( 222)					if (_hx_tmp) {
HXLINE( 223)						this->invalidNumber(start);
            					}
HXLINE( 224)					if (minus) {
HXLINE( 225)						minus = false;
HXLINE( 226)						zero = true;
            					}
HXLINE( 228)					digit = true;
            				}
            				break;
            				case (int)49: case (int)50: case (int)51: case (int)52: case (int)53: case (int)54: case (int)55: case (int)56: case (int)57: {
HXLINE( 230)					bool _hx_tmp;
HXDLIN( 230)					if (zero) {
HXLINE( 230)						_hx_tmp = !(point);
            					}
            					else {
HXLINE( 230)						_hx_tmp = false;
            					}
HXDLIN( 230)					if (_hx_tmp) {
HXLINE( 231)						this->invalidNumber(start);
            					}
HXLINE( 232)					if (minus) {
HXLINE( 233)						minus = false;
            					}
HXLINE( 234)					digit = true;
HXLINE( 235)					zero = false;
            				}
            				break;
            				case (int)69: case (int)101: {
HXLINE( 242)					bool _hx_tmp;
HXDLIN( 242)					bool _hx_tmp1;
HXDLIN( 242)					if (!(minus)) {
HXLINE( 242)						_hx_tmp1 = zero;
            					}
            					else {
HXLINE( 242)						_hx_tmp1 = true;
            					}
HXDLIN( 242)					if (!(_hx_tmp1)) {
HXLINE( 242)						_hx_tmp = e;
            					}
            					else {
HXLINE( 242)						_hx_tmp = true;
            					}
HXDLIN( 242)					if (_hx_tmp) {
HXLINE( 243)						this->invalidNumber(start);
            					}
HXLINE( 244)					digit = false;
HXLINE( 245)					e = true;
            				}
            				break;
            				default:{
HXLINE( 251)					if (!(digit)) {
HXLINE( 252)						this->invalidNumber(start);
            					}
HXLINE( 253)					this->pos--;
HXLINE( 254)					end = true;
            				}
            			}
HXLINE( 256)			if (end) {
HXLINE( 257)				goto _hx_goto_8;
            			}
            		}
            		_hx_goto_8:;
HXLINE( 259)		::String s = this->source.substr(start,(this->pos - start));
HXLINE( 260)		return  ::hxjsonast::Json_obj::__alloc( HX_CTX ,::hxjsonast::JsonValue_obj::JNumber(s), ::hxjsonast::Position_obj::__alloc( HX_CTX ,this->filename,start,this->pos));
            	}


HX_DEFINE_DYNAMIC_FUNC1(Parser_obj,parseNumber,return )

int Parser_obj::nextChar(){
            	HX_STACKFRAME(&_hx_pos_5a224932378bec66_264_nextChar)
HXDLIN( 264)		return this->source.cca(this->pos++);
            	}


HX_DEFINE_DYNAMIC_FUNC0(Parser_obj,nextChar,return )

 ::hxjsonast::Json Parser_obj::mk( ::hxjsonast::Position pos, ::hxjsonast::JsonValue value){
            	HX_GC_STACKFRAME(&_hx_pos_5a224932378bec66_268_mk)
HXDLIN( 268)		return  ::hxjsonast::Json_obj::__alloc( HX_CTX ,value,pos);
            	}


HX_DEFINE_DYNAMIC_FUNC2(Parser_obj,mk,return )

 ::hxjsonast::Position Parser_obj::mkPos(int min,int max){
            	HX_GC_STACKFRAME(&_hx_pos_5a224932378bec66_272_mkPos)
HXDLIN( 272)		return  ::hxjsonast::Position_obj::__alloc( HX_CTX ,this->filename,min,max);
            	}


HX_DEFINE_DYNAMIC_FUNC2(Parser_obj,mkPos,return )

void Parser_obj::invalidChar(){
            	HX_GC_STACKFRAME(&_hx_pos_5a224932378bec66_275_invalidChar)
HXLINE( 276)		this->pos--;
HXLINE( 277)		::String _hx_tmp = (HX_("Invalid character: ",c6,27,6a,16) + this->source.charAt(this->pos));
HXDLIN( 277)		HX_STACK_DO_THROW(::haxe::Exception_obj::thrown( ::hxjsonast::Error_obj::__alloc( HX_CTX ,_hx_tmp, ::hxjsonast::Position_obj::__alloc( HX_CTX ,this->filename,this->pos,(this->pos + 1)))));
            	}


HX_DEFINE_DYNAMIC_FUNC0(Parser_obj,invalidChar,(void))

void Parser_obj::invalidNumber(int start){
            	HX_GC_STACKFRAME(&_hx_pos_5a224932378bec66_281_invalidNumber)
HXDLIN( 281)		::String _hx_tmp = (HX_("Invalid number: ",18,48,2f,e8) + this->source.substring(start,this->pos));
HXDLIN( 281)		HX_STACK_DO_THROW(::haxe::Exception_obj::thrown( ::hxjsonast::Error_obj::__alloc( HX_CTX ,_hx_tmp, ::hxjsonast::Position_obj::__alloc( HX_CTX ,this->filename,start,this->pos))));
            	}


HX_DEFINE_DYNAMIC_FUNC1(Parser_obj,invalidNumber,(void))

 ::hxjsonast::Json Parser_obj::parse(::String source,::String filename){
            	HX_GC_STACKFRAME(&_hx_pos_5a224932378bec66_17_parse)
HXDLIN(  17)		return  ::hxjsonast::Parser_obj::__alloc( HX_CTX ,source,filename)->parseRec();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Parser_obj,parse,return )


::hx::ObjectPtr< Parser_obj > Parser_obj::__new(::String source,::String filename) {
	::hx::ObjectPtr< Parser_obj > __this = new Parser_obj();
	__this->__construct(source,filename);
	return __this;
}

::hx::ObjectPtr< Parser_obj > Parser_obj::__alloc(::hx::Ctx *_hx_ctx,::String source,::String filename) {
	Parser_obj *__this = (Parser_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Parser_obj), true, "hxjsonast.Parser"));
	*(void **)__this = Parser_obj::_hx_vtable;
	__this->__construct(source,filename);
	return __this;
}

Parser_obj::Parser_obj()
{
}

void Parser_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Parser);
	HX_MARK_MEMBER_NAME(source,"source");
	HX_MARK_MEMBER_NAME(filename,"filename");
	HX_MARK_MEMBER_NAME(pos,"pos");
	HX_MARK_END_CLASS();
}

void Parser_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(source,"source");
	HX_VISIT_MEMBER_NAME(filename,"filename");
	HX_VISIT_MEMBER_NAME(pos,"pos");
}

::hx::Val Parser_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"mk") ) { return ::hx::Val( mk_dyn() ); }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"pos") ) { return ::hx::Val( pos ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"mkPos") ) { return ::hx::Val( mkPos_dyn() ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"source") ) { return ::hx::Val( source ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"filename") ) { return ::hx::Val( filename ); }
		if (HX_FIELD_EQ(inName,"parseRec") ) { return ::hx::Val( parseRec_dyn() ); }
		if (HX_FIELD_EQ(inName,"nextChar") ) { return ::hx::Val( nextChar_dyn() ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"parseString") ) { return ::hx::Val( parseString_dyn() ); }
		if (HX_FIELD_EQ(inName,"parseNumber") ) { return ::hx::Val( parseNumber_dyn() ); }
		if (HX_FIELD_EQ(inName,"invalidChar") ) { return ::hx::Val( invalidChar_dyn() ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"invalidNumber") ) { return ::hx::Val( invalidNumber_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

bool Parser_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"parse") ) { outValue = parse_dyn(); return true; }
	}
	return false;
}

::hx::Val Parser_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"pos") ) { pos=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"source") ) { source=inValue.Cast< ::String >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"filename") ) { filename=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Parser_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("source",db,b0,31,32));
	outFields->push(HX_("filename",c7,2e,6a,77));
	outFields->push(HX_("pos",94,5d,55,00));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Parser_obj_sMemberStorageInfo[] = {
	{::hx::fsString,(int)offsetof(Parser_obj,source),HX_("source",db,b0,31,32)},
	{::hx::fsString,(int)offsetof(Parser_obj,filename),HX_("filename",c7,2e,6a,77)},
	{::hx::fsInt,(int)offsetof(Parser_obj,pos),HX_("pos",94,5d,55,00)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *Parser_obj_sStaticStorageInfo = 0;
#endif

static ::String Parser_obj_sMemberFields[] = {
	HX_("source",db,b0,31,32),
	HX_("filename",c7,2e,6a,77),
	HX_("pos",94,5d,55,00),
	HX_("parseRec",dd,e2,78,d6),
	HX_("parseString",64,d5,6c,8c),
	HX_("parseNumber",5c,33,b7,1c),
	HX_("nextChar",69,05,8c,ed),
	HX_("mk",5e,5f,00,00),
	HX_("mkPos",d6,24,a4,09),
	HX_("invalidChar",6d,ad,ce,a9),
	HX_("invalidNumber",20,e9,eb,a6),
	::String(null()) };

::hx::Class Parser_obj::__mClass;

static ::String Parser_obj_sStaticFields[] = {
	HX_("parse",33,90,55,bd),
	::String(null())
};

void Parser_obj::__register()
{
	Parser_obj _hx_dummy;
	Parser_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("hxjsonast.Parser",e3,cf,d0,b8);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Parser_obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(Parser_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Parser_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Parser_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Parser_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Parser_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace hxjsonast
