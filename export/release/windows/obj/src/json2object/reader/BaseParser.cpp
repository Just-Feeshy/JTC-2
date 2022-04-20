#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
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
#ifndef INCLUDED_json2object_Error
#include <json2object/Error.h>
#endif
#ifndef INCLUDED_json2object_InternalError
#include <json2object/InternalError.h>
#endif
#ifndef INCLUDED_json2object_PositionUtils
#include <json2object/PositionUtils.h>
#endif
#ifndef INCLUDED_json2object_reader_BaseParser
#include <json2object/reader/BaseParser.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_5bf07c625788d908_44_new,"json2object.reader.BaseParser","new",0x4d2b0ac8,"json2object.reader.BaseParser.new","json2object/reader/BaseParser.hx",44,0xbb4b1f88)
HX_LOCAL_STACK_FRAME(_hx_pos_5bf07c625788d908_50_fromJson,"json2object.reader.BaseParser","fromJson",0xb4081d4a,"json2object.reader.BaseParser.fromJson","json2object/reader/BaseParser.hx",50,0xbb4b1f88)
HX_LOCAL_STACK_FRAME(_hx_pos_5bf07c625788d908_63_loadJson,"json2object.reader.BaseParser","loadJson",0xc6dc2006,"json2object.reader.BaseParser.loadJson","json2object/reader/BaseParser.hx",63,0xbb4b1f88)
HX_LOCAL_STACK_FRAME(_hx_pos_5bf07c625788d908_77_loadJsonNull,"json2object.reader.BaseParser","loadJsonNull",0xdfbb65ad,"json2object.reader.BaseParser.loadJsonNull","json2object/reader/BaseParser.hx",77,0xbb4b1f88)
HX_LOCAL_STACK_FRAME(_hx_pos_5bf07c625788d908_81_loadJsonString,"json2object.reader.BaseParser","loadJsonString",0x41f98577,"json2object.reader.BaseParser.loadJsonString","json2object/reader/BaseParser.hx",81,0xbb4b1f88)
HX_LOCAL_STACK_FRAME(_hx_pos_5bf07c625788d908_84_loadString,"json2object.reader.BaseParser","loadString",0x7cbdba2f,"json2object.reader.BaseParser.loadString","json2object/reader/BaseParser.hx",84,0xbb4b1f88)
HX_LOCAL_STACK_FRAME(_hx_pos_5bf07c625788d908_93_loadJsonNumber,"json2object.reader.BaseParser","loadJsonNumber",0xd243e36f,"json2object.reader.BaseParser.loadJsonNumber","json2object/reader/BaseParser.hx",93,0xbb4b1f88)
HX_LOCAL_STACK_FRAME(_hx_pos_5bf07c625788d908_96_loadJsonUInt,"json2object.reader.BaseParser","loadJsonUInt",0xe43a82a0,"json2object.reader.BaseParser.loadJsonUInt","json2object/reader/BaseParser.hx",96,0xbb4b1f88)
HX_LOCAL_STACK_FRAME(_hx_pos_5bf07c625788d908_124_loadJsonInt,"json2object.reader.BaseParser","loadJsonInt",0x15a6ec89,"json2object.reader.BaseParser.loadJsonInt","json2object/reader/BaseParser.hx",124,0xbb4b1f88)
HX_LOCAL_STACK_FRAME(_hx_pos_5bf07c625788d908_132_loadJsonFloat,"json2object.reader.BaseParser","loadJsonFloat",0x43183fb6,"json2object.reader.BaseParser.loadJsonFloat","json2object/reader/BaseParser.hx",132,0xbb4b1f88)
HX_LOCAL_STACK_FRAME(_hx_pos_5bf07c625788d908_141_loadJsonBool,"json2object.reader.BaseParser","loadJsonBool",0xd7c84b50,"json2object.reader.BaseParser.loadJsonBool","json2object/reader/BaseParser.hx",141,0xbb4b1f88)
HX_LOCAL_STACK_FRAME(_hx_pos_5bf07c625788d908_145_loadJsonArray,"json2object.reader.BaseParser","loadJsonArray",0x6610e7b3,"json2object.reader.BaseParser.loadJsonArray","json2object/reader/BaseParser.hx",145,0xbb4b1f88)
HX_LOCAL_STACK_FRAME(_hx_pos_5bf07c625788d908_149_loadJsonArrayValue,"json2object.reader.BaseParser","loadJsonArrayValue",0x67113ebe,"json2object.reader.BaseParser.loadJsonArrayValue","json2object/reader/BaseParser.hx",149,0xbb4b1f88)
HX_LOCAL_STACK_FRAME(_hx_pos_5bf07c625788d908_166_loadJsonObject,"json2object.reader.BaseParser","loadJsonObject",0x4608db65,"json2object.reader.BaseParser.loadJsonObject","json2object/reader/BaseParser.hx",166,0xbb4b1f88)
HX_LOCAL_STACK_FRAME(_hx_pos_5bf07c625788d908_169_loadObjectField,"json2object.reader.BaseParser","loadObjectField",0x59f36b5d,"json2object.reader.BaseParser.loadObjectField","json2object/reader/BaseParser.hx",169,0xbb4b1f88)
HX_LOCAL_STACK_FRAME(_hx_pos_5bf07c625788d908_206_loadObjectFieldReflect,"json2object.reader.BaseParser","loadObjectFieldReflect",0xadee1660,"json2object.reader.BaseParser.loadObjectFieldReflect","json2object/reader/BaseParser.hx",206,0xbb4b1f88)
HX_LOCAL_STACK_FRAME(_hx_pos_5bf07c625788d908_220_objectSetupAssign,"json2object.reader.BaseParser","objectSetupAssign",0x5b582875,"json2object.reader.BaseParser.objectSetupAssign","json2object/reader/BaseParser.hx",220,0xbb4b1f88)
HX_LOCAL_STACK_FRAME(_hx_pos_5bf07c625788d908_225_objectErrors,"json2object.reader.BaseParser","objectErrors",0x0924c862,"json2object.reader.BaseParser.objectErrors","json2object/reader/BaseParser.hx",225,0xbb4b1f88)
HX_LOCAL_STACK_FRAME(_hx_pos_5bf07c625788d908_235_onIncorrectType,"json2object.reader.BaseParser","onIncorrectType",0xa7a13648,"json2object.reader.BaseParser.onIncorrectType","json2object/reader/BaseParser.hx",235,0xbb4b1f88)
HX_LOCAL_STACK_FRAME(_hx_pos_5bf07c625788d908_239_parsingThrow,"json2object.reader.BaseParser","parsingThrow",0xfebe2b6e,"json2object.reader.BaseParser.parsingThrow","json2object/reader/BaseParser.hx",239,0xbb4b1f88)
HX_LOCAL_STACK_FRAME(_hx_pos_5bf07c625788d908_244_objectThrow,"json2object.reader.BaseParser","objectThrow",0x5e735c4f,"json2object.reader.BaseParser.objectThrow","json2object/reader/BaseParser.hx",244,0xbb4b1f88)
HX_LOCAL_STACK_FRAME(_hx_pos_5bf07c625788d908_255_mapSet,"json2object.reader.BaseParser","mapSet",0x67b308fe,"json2object.reader.BaseParser.mapSet","json2object/reader/BaseParser.hx",255,0xbb4b1f88)
namespace json2object{
namespace reader{

void BaseParser_obj::__construct(::Array< ::Dynamic> errors, ::json2object::PositionUtils putils,int errorType){
            	HX_STACKFRAME(&_hx_pos_5bf07c625788d908_44_new)
HXLINE(  45)		this->errors = errors;
HXLINE(  46)		this->putils = putils;
HXLINE(  47)		this->errorType = errorType;
            	}

Dynamic BaseParser_obj::__CreateEmpty() { return new BaseParser_obj; }

void *BaseParser_obj::_hx_vtable = 0;

Dynamic BaseParser_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< BaseParser_obj > _hx_result = new BaseParser_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return _hx_result;
}

bool BaseParser_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x0f6d5b90;
}

 ::Dynamic BaseParser_obj::fromJson(::String jsonString,::String __o_filename){
            		::String filename = __o_filename;
            		if (::hx::IsNull(__o_filename)) filename = HX_("",00,00,00,00);
            	HX_GC_STACKFRAME(&_hx_pos_5bf07c625788d908_50_fromJson)
HXLINE(  51)		this->putils =  ::json2object::PositionUtils_obj::__alloc( HX_CTX ,jsonString);
HXLINE(  52)		this->errors = ::Array_obj< ::Dynamic>::__new(0);
HXLINE(  53)		try {
            			HX_STACK_CATCHABLE( ::Dynamic, 0);
HXLINE(  54)			 ::hxjsonast::Json json =  ::hxjsonast::Parser_obj::__alloc( HX_CTX ,jsonString,filename)->parseRec();
HXLINE(  55)			this->loadJson(json,null());
            		} catch( ::Dynamic _hx_e) {
            			if (_hx_e.IsClass<  ::Dynamic >() ){
            				HX_STACK_BEGIN_CATCH
            				 ::Dynamic _g = _hx_e;
HXLINE(  57)				{
HXLINE(  57)					null();
            				}
HXDLIN(  57)				 ::Dynamic _g1 = ::haxe::Exception_obj::caught(_g)->unwrap();
HXLINE(  53)				if (::Std_obj::isOfType(_g1,::hx::ClassOf< ::hxjsonast::Error >())) {
HXLINE(  57)					 ::hxjsonast::Error e = ( ( ::hxjsonast::Error)(_g1) );
HXLINE(  58)					{
HXLINE(  58)						::Array< ::Dynamic> _hx_tmp = this->errors;
HXDLIN(  58)						::String e1 = e->message;
HXDLIN(  58)						_hx_tmp->push(::json2object::Error_obj::ParserError(e1,this->putils->convertPosition(e->pos)));
            					}
            				}
            				else {
HXLINE(  53)					HX_STACK_DO_THROW(_g);
            				}
            			}
            			else {
            				HX_STACK_DO_THROW(_hx_e);
            			}
            		}
HXLINE(  60)		return this->value;
            	}


HX_DEFINE_DYNAMIC_FUNC2(BaseParser_obj,fromJson,return )

 ::Dynamic BaseParser_obj::loadJson( ::hxjsonast::Json json,::String __o_variable){
            		::String variable = __o_variable;
            		if (::hx::IsNull(__o_variable)) variable = HX_("",00,00,00,00);
            	HX_STACKFRAME(&_hx_pos_5bf07c625788d908_63_loadJson)
HXLINE(  64)		 ::Dynamic pos = this->putils->convertPosition(json->pos);
HXLINE(  65)		{
HXLINE(  65)			 ::hxjsonast::JsonValue _g = json->value;
HXDLIN(  65)			switch((int)(_g->_hx_getIndex())){
            				case (int)0: {
HXLINE(  67)					::String s = _g->_hx_getString(0);
HXDLIN(  67)					this->loadJsonString(s,pos,variable);
            				}
            				break;
            				case (int)1: {
HXLINE(  68)					::String n = _g->_hx_getString(0);
HXDLIN(  68)					this->loadJsonNumber(n,pos,variable);
            				}
            				break;
            				case (int)2: {
HXLINE(  71)					::Array< ::Dynamic> o = _g->_hx_getObject(0).StaticCast< ::Array< ::Dynamic> >();
HXDLIN(  71)					this->loadJsonObject(o,pos,variable);
            				}
            				break;
            				case (int)3: {
HXLINE(  70)					::Array< ::Dynamic> a = _g->_hx_getObject(0).StaticCast< ::Array< ::Dynamic> >();
HXDLIN(  70)					this->loadJsonArray(a,pos,variable);
            				}
            				break;
            				case (int)4: {
HXLINE(  69)					bool b = _g->_hx_getBool(0);
HXDLIN(  69)					this->loadJsonBool(b,pos,variable);
            				}
            				break;
            				case (int)5: {
HXLINE(  66)					this->loadJsonNull(pos,variable);
            				}
            				break;
            			}
            		}
HXLINE(  73)		return this->value;
            	}


HX_DEFINE_DYNAMIC_FUNC2(BaseParser_obj,loadJson,return )

void BaseParser_obj::loadJsonNull( ::Dynamic pos,::String variable){
            	HX_STACKFRAME(&_hx_pos_5bf07c625788d908_77_loadJsonNull)
HXDLIN(  77)		this->onIncorrectType(pos,variable);
            	}


HX_DEFINE_DYNAMIC_FUNC2(BaseParser_obj,loadJsonNull,(void))

void BaseParser_obj::loadJsonString(::String s, ::Dynamic pos,::String variable){
            	HX_STACKFRAME(&_hx_pos_5bf07c625788d908_81_loadJsonString)
HXDLIN(  81)		this->onIncorrectType(pos,variable);
            	}


HX_DEFINE_DYNAMIC_FUNC3(BaseParser_obj,loadJsonString,(void))

::String BaseParser_obj::loadString(::String s, ::Dynamic pos,::String variable,::Array< ::String > validValues,::String defaultValue){
            	HX_STACKFRAME(&_hx_pos_5bf07c625788d908_84_loadString)
HXLINE(  85)		if ((validValues->indexOf(s,null()) != -1)) {
HXLINE(  86)			return s;
            		}
HXLINE(  88)		this->onIncorrectType(pos,variable);
HXLINE(  89)		return defaultValue;
            	}


HX_DEFINE_DYNAMIC_FUNC5(BaseParser_obj,loadString,return )

void BaseParser_obj::loadJsonNumber(::String f, ::Dynamic pos,::String variable){
            	HX_STACKFRAME(&_hx_pos_5bf07c625788d908_93_loadJsonNumber)
HXDLIN(  93)		this->onIncorrectType(pos,variable);
            	}


HX_DEFINE_DYNAMIC_FUNC3(BaseParser_obj,loadJsonNumber,(void))

int BaseParser_obj::loadJsonUInt(::String f, ::Dynamic pos,::String variable,int value){
            	HX_STACKFRAME(&_hx_pos_5bf07c625788d908_96_loadJsonUInt)
HXLINE(  97)		int uint = 0;
HXLINE(  98)		f = ::StringTools_obj::trim(f);
HXLINE(  99)		bool neg = (f.charAt(0) == HX_("-",2d,00,00,00));
HXLINE( 100)		if (neg) {
HXLINE( 101)			f = f.substr(1,null());
            		}
HXLINE( 103)		bool hex = ::StringTools_obj::startsWith(f,HX_("0x",48,2a,00,00));
HXLINE( 104)		if (hex) {
HXLINE( 105)			f = f.substr(2,null());
            		}
HXLINE( 108)		int base;
HXDLIN( 108)		if (hex) {
HXLINE( 108)			base = 16;
            		}
            		else {
HXLINE( 108)			base = 10;
            		}
HXLINE( 109)		int pow = 1;
HXLINE( 110)		int i = (f.length - 1);
HXLINE( 111)		while((i >= 0)){
HXLINE( 112)			 ::Dynamic cur;
HXDLIN( 112)			if (hex) {
HXLINE( 112)				cur = ::Std_obj::parseInt((HX_("0x",48,2a,00,00) + f.charAt(i)));
            			}
            			else {
HXLINE( 112)				cur = ::Std_obj::parseInt(f.charAt(i));
            			}
HXLINE( 113)			if (::hx::IsNull( cur )) {
HXLINE( 114)				this->onIncorrectType(pos,variable);
HXLINE( 115)				return value;
            			}
HXLINE( 117)			uint = (uint + (pow * ( (int)(cur) )));
HXLINE( 118)			pow = (pow * base);
HXLINE( 119)			i = (i - 1);
            		}
HXLINE( 121)		return uint;
            	}


HX_DEFINE_DYNAMIC_FUNC4(BaseParser_obj,loadJsonUInt,return )

int BaseParser_obj::loadJsonInt(::String f, ::Dynamic pos,::String variable,int value){
            	HX_STACKFRAME(&_hx_pos_5bf07c625788d908_124_loadJsonInt)
HXLINE( 125)		bool _hx_tmp;
HXDLIN( 125)		if (::hx::IsNotNull( ::Std_obj::parseInt(f) )) {
HXLINE( 125)			 ::Dynamic _hx_tmp1 = ::Std_obj::parseInt(f);
HXDLIN( 125)			_hx_tmp = ::hx::IsEq( _hx_tmp1,::Std_obj::parseFloat(f) );
            		}
            		else {
HXLINE( 125)			_hx_tmp = false;
            		}
HXDLIN( 125)		if (_hx_tmp) {
HXLINE( 126)			return ( (int)(::Std_obj::parseInt(f)) );
            		}
HXLINE( 128)		this->onIncorrectType(pos,variable);
HXLINE( 129)		return value;
            	}


HX_DEFINE_DYNAMIC_FUNC4(BaseParser_obj,loadJsonInt,return )

Float BaseParser_obj::loadJsonFloat(::String f, ::Dynamic pos,::String variable,Float value){
            	HX_STACKFRAME(&_hx_pos_5bf07c625788d908_132_loadJsonFloat)
HXLINE( 133)		if (::hx::IsNotNull( ::Std_obj::parseInt(f) )) {
HXLINE( 134)			return ::Std_obj::parseFloat(f);
            		}
HXLINE( 136)		this->onIncorrectType(pos,variable);
HXLINE( 137)		return value;
            	}


HX_DEFINE_DYNAMIC_FUNC4(BaseParser_obj,loadJsonFloat,return )

void BaseParser_obj::loadJsonBool(bool b, ::Dynamic pos,::String variable){
            	HX_STACKFRAME(&_hx_pos_5bf07c625788d908_141_loadJsonBool)
HXDLIN( 141)		this->onIncorrectType(pos,variable);
            	}


HX_DEFINE_DYNAMIC_FUNC3(BaseParser_obj,loadJsonBool,(void))

void BaseParser_obj::loadJsonArray(::Array< ::Dynamic> a, ::Dynamic pos,::String variable){
            	HX_STACKFRAME(&_hx_pos_5bf07c625788d908_145_loadJsonArray)
HXDLIN( 145)		this->onIncorrectType(pos,variable);
            	}


HX_DEFINE_DYNAMIC_FUNC3(BaseParser_obj,loadJsonArray,(void))

::cpp::VirtualArray BaseParser_obj::loadJsonArrayValue(::Array< ::Dynamic> a, ::Dynamic loadJsonFn,::String variable){
            	HX_STACKFRAME(&_hx_pos_5bf07c625788d908_149_loadJsonArrayValue)
HXDLIN( 149)		::cpp::VirtualArray _g = ::cpp::VirtualArray_obj::__new(0);
HXLINE( 150)		{
HXLINE( 150)			int _g1 = 0;
HXDLIN( 150)			while((_g1 < a->length)){
HXLINE( 150)				 ::hxjsonast::Json j = a->__get(_g1).StaticCast<  ::hxjsonast::Json >();
HXDLIN( 150)				_g1 = (_g1 + 1);
HXLINE( 152)				 ::Dynamic _hx_tmp;
HXDLIN( 152)				try {
            					HX_STACK_CATCHABLE( ::Dynamic, 0);
HXLINE( 152)					_hx_tmp = loadJsonFn(j,variable);
            				} catch( ::Dynamic _hx_e) {
            					if (_hx_e.IsClass<  ::Dynamic >() ){
            						HX_STACK_BEGIN_CATCH
            						 ::Dynamic _g = _hx_e;
HXLINE( 154)						{
HXLINE( 154)							null();
            						}
HXDLIN( 154)						 ::Dynamic _g1 = ::haxe::Exception_obj::caught(_g)->unwrap();
HXLINE( 152)						if (::Std_obj::isOfType(_g1,::hx::ClassOf< ::json2object::InternalError >())) {
HXLINE( 154)							 ::json2object::InternalError e = _g1;
HXLINE( 155)							if (::hx::IsPointerNotEq( e,::json2object::InternalError_obj::ParsingThrow_dyn() )) {
HXLINE( 156)								HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(e));
            							}
HXLINE( 159)							continue;
            						}
            						else {
HXLINE( 152)							HX_STACK_DO_THROW(_g);
            						}
            					}
            					else {
            						HX_STACK_DO_THROW(_hx_e);
            					}
            				}
HXDLIN( 152)				_g->push(_hx_tmp);
            			}
            		}
HXLINE( 149)		return _g;
            	}


HX_DEFINE_DYNAMIC_FUNC3(BaseParser_obj,loadJsonArrayValue,return )

void BaseParser_obj::loadJsonObject(::Array< ::Dynamic> o, ::Dynamic pos,::String variable){
            	HX_STACKFRAME(&_hx_pos_5bf07c625788d908_166_loadJsonObject)
HXDLIN( 166)		this->onIncorrectType(pos,variable);
            	}


HX_DEFINE_DYNAMIC_FUNC3(BaseParser_obj,loadJsonObject,(void))

 ::Dynamic BaseParser_obj::loadObjectField( ::Dynamic loadJsonFn, ::hxjsonast::JObjectField field,::String name, ::haxe::ds::StringMap assigned, ::Dynamic defaultValue, ::Dynamic pos){
            	HX_STACKFRAME(&_hx_pos_5bf07c625788d908_169_loadObjectField)
HXLINE( 170)		try {
            			HX_STACK_CATCHABLE( ::Dynamic, 0);
HXLINE( 171)			 ::Dynamic ret = loadJsonFn(field->value,field->name);
HXLINE( 172)			assigned->set(name,true);
HXLINE( 173)			return ret;
            		} catch( ::Dynamic _hx_e) {
            			if (_hx_e.IsClass<  ::Dynamic >() ){
            				HX_STACK_BEGIN_CATCH
            				 ::Dynamic _g = _hx_e;
HXLINE( 174)				{
HXLINE( 174)					null();
            				}
HXDLIN( 174)				 ::Dynamic _g1 = ::haxe::Exception_obj::caught(_g)->unwrap();
HXLINE( 170)				if (::Std_obj::isOfType(_g1,::hx::ClassOf< ::json2object::InternalError >())) {
HXLINE( 174)					 ::json2object::InternalError e = _g1;
HXLINE( 175)					if (::hx::IsPointerNotEq( e,::json2object::InternalError_obj::ParsingThrow_dyn() )) {
HXLINE( 176)						HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(e));
            					}
            				}
            				else {
HXLINE( 199)					 ::Dynamic e = _g1;
HXLINE( 200)					this->errors->push(::json2object::Error_obj::CustomFunctionException(e,pos));
            				}
            			}
            			else {
            				HX_STACK_DO_THROW(_hx_e);
            			}
            		}
HXLINE( 202)		return defaultValue;
            	}


HX_DEFINE_DYNAMIC_FUNC6(BaseParser_obj,loadObjectField,return )

void BaseParser_obj::loadObjectFieldReflect( ::Dynamic loadJsonFn, ::hxjsonast::JObjectField field,::String name, ::haxe::ds::StringMap assigned, ::Dynamic pos){
            	HX_STACKFRAME(&_hx_pos_5bf07c625788d908_206_loadObjectFieldReflect)
HXDLIN( 206)		try {
            			HX_STACK_CATCHABLE( ::Dynamic, 0);
HXLINE( 207)			 ::Dynamic _hx_tmp = this->value;
HXDLIN( 207)			::Reflect_obj::setField(_hx_tmp,name,loadJsonFn(field->value,field->name));
HXLINE( 208)			assigned->set(name,true);
            		} catch( ::Dynamic _hx_e) {
            			if (_hx_e.IsClass<  ::Dynamic >() ){
            				HX_STACK_BEGIN_CATCH
            				 ::Dynamic _g = _hx_e;
HXLINE( 209)				{
HXLINE( 209)					null();
            				}
HXDLIN( 209)				 ::Dynamic _g1 = ::haxe::Exception_obj::caught(_g)->unwrap();
HXLINE( 206)				if (::Std_obj::isOfType(_g1,::hx::ClassOf< ::json2object::InternalError >())) {
HXLINE( 209)					 ::json2object::InternalError e = _g1;
HXLINE( 210)					if (::hx::IsPointerNotEq( e,::json2object::InternalError_obj::ParsingThrow_dyn() )) {
HXLINE( 211)						HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(e));
            					}
            				}
            				else {
HXLINE( 214)					 ::Dynamic e = _g1;
HXLINE( 215)					this->errors->push(::json2object::Error_obj::CustomFunctionException(e,pos));
            				}
            			}
            			else {
            				HX_STACK_DO_THROW(_hx_e);
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC5(BaseParser_obj,loadObjectFieldReflect,(void))

void BaseParser_obj::objectSetupAssign( ::haxe::ds::StringMap assigned,::Array< ::String > keys,::Array< bool > values){
            	HX_STACKFRAME(&_hx_pos_5bf07c625788d908_220_objectSetupAssign)
HXDLIN( 220)		int _g = 0;
HXDLIN( 220)		int _g1 = keys->length;
HXDLIN( 220)		while((_g < _g1)){
HXDLIN( 220)			_g = (_g + 1);
HXDLIN( 220)			int i = (_g - 1);
HXLINE( 221)			assigned->set(keys->__get(i),values->__get(i));
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC3(BaseParser_obj,objectSetupAssign,(void))

void BaseParser_obj::objectErrors( ::haxe::ds::StringMap assigned, ::Dynamic pos){
            	HX_GC_STACKFRAME(&_hx_pos_5bf07c625788d908_225_objectErrors)
HXLINE( 226)		 ::json2object::PositionUtils lastPos = this->putils;
HXDLIN( 226)		 ::Dynamic lastPos1 = lastPos->convertPosition( ::hxjsonast::Position_obj::__alloc( HX_CTX ,( (::String)(pos->__Field(HX_("file",7c,ce,bb,43),::hx::paccDynamic)) ),(( (int)(pos->__Field(HX_("max",a4,0a,53,00),::hx::paccDynamic)) ) - 1),(( (int)(pos->__Field(HX_("max",a4,0a,53,00),::hx::paccDynamic)) ) - 1)));
HXLINE( 227)		{
HXLINE( 227)			 ::Dynamic s = assigned->keys();
HXDLIN( 227)			while(( (bool)(s->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE( 227)				::String s1 = ( (::String)(s->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXLINE( 228)				if (!(( (bool)(assigned->get(s1)) ))) {
HXLINE( 229)					this->errors->push(::json2object::Error_obj::UninitializedVariable(s1,lastPos1));
            				}
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC2(BaseParser_obj,objectErrors,(void))

void BaseParser_obj::onIncorrectType( ::Dynamic pos,::String variable){
            	HX_STACKFRAME(&_hx_pos_5bf07c625788d908_235_onIncorrectType)
HXDLIN( 235)		this->parsingThrow();
            	}


HX_DEFINE_DYNAMIC_FUNC2(BaseParser_obj,onIncorrectType,(void))

void BaseParser_obj::parsingThrow(){
            	HX_STACKFRAME(&_hx_pos_5bf07c625788d908_239_parsingThrow)
HXDLIN( 239)		if ((this->errorType != 0)) {
HXLINE( 240)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(::json2object::InternalError_obj::ParsingThrow_dyn()));
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC0(BaseParser_obj,parsingThrow,(void))

void BaseParser_obj::objectThrow( ::Dynamic pos,::String variable){
            	HX_STACKFRAME(&_hx_pos_5bf07c625788d908_244_objectThrow)
HXLINE( 245)		if ((this->errorType == 2)) {
HXLINE( 246)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(::json2object::InternalError_obj::ParsingThrow_dyn()));
            		}
HXLINE( 249)		if ((this->errorType == 1)) {
HXLINE( 250)			this->errors->push(::json2object::Error_obj::UninitializedVariable(variable,pos));
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC2(BaseParser_obj,objectThrow,(void))

void BaseParser_obj::mapSet( ::haxe::ds::StringMap map,::String key,bool value){
            	HX_STACKFRAME(&_hx_pos_5bf07c625788d908_255_mapSet)
HXDLIN( 255)		map->set(key,value);
            	}


HX_DEFINE_DYNAMIC_FUNC3(BaseParser_obj,mapSet,(void))


::hx::ObjectPtr< BaseParser_obj > BaseParser_obj::__new(::Array< ::Dynamic> errors, ::json2object::PositionUtils putils,int errorType) {
	::hx::ObjectPtr< BaseParser_obj > __this = new BaseParser_obj();
	__this->__construct(errors,putils,errorType);
	return __this;
}

::hx::ObjectPtr< BaseParser_obj > BaseParser_obj::__alloc(::hx::Ctx *_hx_ctx,::Array< ::Dynamic> errors, ::json2object::PositionUtils putils,int errorType) {
	BaseParser_obj *__this = (BaseParser_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(BaseParser_obj), true, "json2object.reader.BaseParser"));
	*(void **)__this = BaseParser_obj::_hx_vtable;
	__this->__construct(errors,putils,errorType);
	return __this;
}

BaseParser_obj::BaseParser_obj()
{
}

void BaseParser_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BaseParser);
	HX_MARK_MEMBER_NAME(value,"value");
	HX_MARK_MEMBER_NAME(errors,"errors");
	HX_MARK_MEMBER_NAME(errorType,"errorType");
	HX_MARK_MEMBER_NAME(putils,"putils");
	HX_MARK_END_CLASS();
}

void BaseParser_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(value,"value");
	HX_VISIT_MEMBER_NAME(errors,"errors");
	HX_VISIT_MEMBER_NAME(errorType,"errorType");
	HX_VISIT_MEMBER_NAME(putils,"putils");
}

::hx::Val BaseParser_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { return ::hx::Val( value ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"errors") ) { return ::hx::Val( errors ); }
		if (HX_FIELD_EQ(inName,"putils") ) { return ::hx::Val( putils ); }
		if (HX_FIELD_EQ(inName,"mapSet") ) { return ::hx::Val( mapSet_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"fromJson") ) { return ::hx::Val( fromJson_dyn() ); }
		if (HX_FIELD_EQ(inName,"loadJson") ) { return ::hx::Val( loadJson_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"errorType") ) { return ::hx::Val( errorType ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"loadString") ) { return ::hx::Val( loadString_dyn() ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"loadJsonInt") ) { return ::hx::Val( loadJsonInt_dyn() ); }
		if (HX_FIELD_EQ(inName,"objectThrow") ) { return ::hx::Val( objectThrow_dyn() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"loadJsonNull") ) { return ::hx::Val( loadJsonNull_dyn() ); }
		if (HX_FIELD_EQ(inName,"loadJsonUInt") ) { return ::hx::Val( loadJsonUInt_dyn() ); }
		if (HX_FIELD_EQ(inName,"loadJsonBool") ) { return ::hx::Val( loadJsonBool_dyn() ); }
		if (HX_FIELD_EQ(inName,"objectErrors") ) { return ::hx::Val( objectErrors_dyn() ); }
		if (HX_FIELD_EQ(inName,"parsingThrow") ) { return ::hx::Val( parsingThrow_dyn() ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"loadJsonFloat") ) { return ::hx::Val( loadJsonFloat_dyn() ); }
		if (HX_FIELD_EQ(inName,"loadJsonArray") ) { return ::hx::Val( loadJsonArray_dyn() ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"loadJsonString") ) { return ::hx::Val( loadJsonString_dyn() ); }
		if (HX_FIELD_EQ(inName,"loadJsonNumber") ) { return ::hx::Val( loadJsonNumber_dyn() ); }
		if (HX_FIELD_EQ(inName,"loadJsonObject") ) { return ::hx::Val( loadJsonObject_dyn() ); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"loadObjectField") ) { return ::hx::Val( loadObjectField_dyn() ); }
		if (HX_FIELD_EQ(inName,"onIncorrectType") ) { return ::hx::Val( onIncorrectType_dyn() ); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"objectSetupAssign") ) { return ::hx::Val( objectSetupAssign_dyn() ); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"loadJsonArrayValue") ) { return ::hx::Val( loadJsonArrayValue_dyn() ); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"loadObjectFieldReflect") ) { return ::hx::Val( loadObjectFieldReflect_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val BaseParser_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { value=inValue.Cast<  ::Dynamic >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"errors") ) { errors=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
		if (HX_FIELD_EQ(inName,"putils") ) { putils=inValue.Cast<  ::json2object::PositionUtils >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"errorType") ) { errorType=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BaseParser_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("value",71,7f,b8,31));
	outFields->push(HX_("errors",ab,83,68,51));
	outFields->push(HX_("errorType",a2,6e,71,73));
	outFields->push(HX_("putils",c1,13,d7,72));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo BaseParser_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::Dynamic */ ,(int)offsetof(BaseParser_obj,value),HX_("value",71,7f,b8,31)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(BaseParser_obj,errors),HX_("errors",ab,83,68,51)},
	{::hx::fsInt,(int)offsetof(BaseParser_obj,errorType),HX_("errorType",a2,6e,71,73)},
	{::hx::fsObject /*  ::json2object::PositionUtils */ ,(int)offsetof(BaseParser_obj,putils),HX_("putils",c1,13,d7,72)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *BaseParser_obj_sStaticStorageInfo = 0;
#endif

static ::String BaseParser_obj_sMemberFields[] = {
	HX_("value",71,7f,b8,31),
	HX_("errors",ab,83,68,51),
	HX_("errorType",a2,6e,71,73),
	HX_("putils",c1,13,d7,72),
	HX_("fromJson",b2,10,34,a4),
	HX_("loadJson",6e,13,08,b7),
	HX_("loadJsonNull",15,2d,09,02),
	HX_("loadJsonString",df,f6,d5,e8),
	HX_("loadString",97,57,5b,c6),
	HX_("loadJsonNumber",d7,54,20,79),
	HX_("loadJsonUInt",08,4a,88,06),
	HX_("loadJsonInt",21,0a,f3,35),
	HX_("loadJsonFloat",4e,f3,d8,24),
	HX_("loadJsonBool",b8,12,16,fa),
	HX_("loadJsonArray",4b,9b,d1,47),
	HX_("loadJsonArrayValue",26,84,26,d5),
	HX_("loadJsonObject",cd,4c,e5,ec),
	HX_("loadObjectField",f5,34,fa,b3),
	HX_("loadObjectFieldReflect",c8,2f,36,d2),
	HX_("objectSetupAssign",0d,88,d6,5b),
	HX_("objectErrors",ca,8f,72,2b),
	HX_("onIncorrectType",e0,ff,a7,01),
	HX_("parsingThrow",d6,f2,0b,21),
	HX_("objectThrow",e7,79,bf,7e),
	HX_("mapSet",66,d2,0b,b9),
	::String(null()) };

::hx::Class BaseParser_obj::__mClass;

void BaseParser_obj::__register()
{
	BaseParser_obj _hx_dummy;
	BaseParser_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("json2object.reader.BaseParser",d6,46,14,50);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(BaseParser_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< BaseParser_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = BaseParser_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = BaseParser_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace json2object
} // end namespace reader
