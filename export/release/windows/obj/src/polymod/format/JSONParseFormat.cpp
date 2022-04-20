#include <hxcpp.h>

#ifndef INCLUDED_EReg
#include <EReg.h>
#endif
#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_Exception
#include <haxe/Exception.h>
#endif
#ifndef INCLUDED_haxe_format_JsonParser
#include <haxe/format/JsonParser.h>
#endif
#ifndef INCLUDED_haxe_format_JsonPrinter
#include <haxe/format/JsonPrinter.h>
#endif
#ifndef INCLUDED_polymod_Polymod
#include <polymod/Polymod.h>
#endif
#ifndef INCLUDED_polymod_format_BaseParseFormat
#include <polymod/format/BaseParseFormat.h>
#endif
#ifndef INCLUDED_polymod_format_JSONParseFormat
#include <polymod/format/JSONParseFormat.h>
#endif
#ifndef INCLUDED_polymod_format_TextFileFormat
#include <polymod/format/TextFileFormat.h>
#endif
#ifndef INCLUDED_polymod_util_Util
#include <polymod/util/Util.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_8feeea0724e4c481_578_new,"polymod.format.JSONParseFormat","new",0xfff4bb35,"polymod.format.JSONParseFormat.new","polymod/format/ParseRules.hx",578,0xc5c5c43b)
HX_LOCAL_STACK_FRAME(_hx_pos_8feeea0724e4c481_585_parse,"polymod.format.JSONParseFormat","parse",0x97269a48,"polymod.format.JSONParseFormat.parse","polymod/format/ParseRules.hx",585,0xc5c5c43b)
HX_LOCAL_STACK_FRAME(_hx_pos_8feeea0724e4c481_591_append,"polymod.format.JSONParseFormat","append",0x4cebaa25,"polymod.format.JSONParseFormat.append","polymod/format/ParseRules.hx",591,0xc5c5c43b)
HX_LOCAL_STACK_FRAME(_hx_pos_8feeea0724e4c481_614_merge,"polymod.format.JSONParseFormat","merge",0xdf97accd,"polymod.format.JSONParseFormat.merge","polymod/format/ParseRules.hx",614,0xc5c5c43b)
HX_LOCAL_STACK_FRAME(_hx_pos_8feeea0724e4c481_673__mergeJson,"polymod.format.JSONParseFormat","_mergeJson",0xb107928c,"polymod.format.JSONParseFormat._mergeJson","polymod/format/ParseRules.hx",673,0xc5c5c43b)
HX_LOCAL_STACK_FRAME(_hx_pos_8feeea0724e4c481_740__targSigElementToString,"polymod.format.JSONParseFormat","_targSigElementToString",0x44b7316d,"polymod.format.JSONParseFormat._targSigElementToString","polymod/format/ParseRules.hx",740,0xc5c5c43b)
HX_LOCAL_STACK_FRAME(_hx_pos_8feeea0724e4c481_757__inject,"polymod.format.JSONParseFormat","_inject",0xbe18d585,"polymod.format.JSONParseFormat._inject","polymod/format/ParseRules.hx",757,0xc5c5c43b)
HX_LOCAL_STACK_FRAME(_hx_pos_8feeea0724e4c481_795__mergeObjects,"polymod.format.JSONParseFormat","_mergeObjects",0x683b6ef0,"polymod.format.JSONParseFormat._mergeObjects","polymod/format/ParseRules.hx",795,0xc5c5c43b)
HX_LOCAL_STACK_FRAME(_hx_pos_8feeea0724e4c481_847_copyVal,"polymod.format.JSONParseFormat","copyVal",0xfb3ed381,"polymod.format.JSONParseFormat.copyVal","polymod/format/ParseRules.hx",847,0xc5c5c43b)
HX_LOCAL_STACK_FRAME(_hx_pos_8feeea0724e4c481_863_isPrimitive,"polymod.format.JSONParseFormat","isPrimitive",0xd2508732,"polymod.format.JSONParseFormat.isPrimitive","polymod/format/ParseRules.hx",863,0xc5c5c43b)
HX_LOCAL_STACK_FRAME(_hx_pos_8feeea0724e4c481_888__descend,"polymod.format.JSONParseFormat","_descend",0x5bcab8b6,"polymod.format.JSONParseFormat._descend","polymod/format/ParseRules.hx",888,0xc5c5c43b)
HX_LOCAL_STACK_FRAME(_hx_pos_8feeea0724e4c481_964__getTargetSignature,"polymod.format.JSONParseFormat","_getTargetSignature",0x1f3de665,"polymod.format.JSONParseFormat._getTargetSignature","polymod/format/ParseRules.hx",964,0xc5c5c43b)
HX_LOCAL_STACK_FRAME(_hx_pos_8feeea0724e4c481_1003_print,"polymod.format.JSONParseFormat","print",0xa25c6242,"polymod.format.JSONParseFormat.print","polymod/format/ParseRules.hx",1003,0xc5c5c43b)
namespace polymod{
namespace format{

void JSONParseFormat_obj::__construct(::String space, ::Dynamic replacer){
            	HX_STACKFRAME(&_hx_pos_8feeea0724e4c481_578_new)
HXLINE( 579)		this->replacer = replacer;
HXLINE( 580)		this->space = space;
HXLINE( 581)		this->format = ::polymod::format::TextFileFormat_obj::JSON_dyn();
            	}

Dynamic JSONParseFormat_obj::__CreateEmpty() { return new JSONParseFormat_obj; }

void *JSONParseFormat_obj::_hx_vtable = 0;

Dynamic JSONParseFormat_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< JSONParseFormat_obj > _hx_result = new JSONParseFormat_obj();
	_hx_result->__construct(inArgs[0],inArgs[1]);
	return _hx_result;
}

bool JSONParseFormat_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x14b3bff5;
}

static ::polymod::format::BaseParseFormat_obj _hx_polymod_format_JSONParseFormat__hx_polymod_format_BaseParseFormat= {
	( ::String (::hx::Object::*)(::String,::String,::String))&::polymod::format::JSONParseFormat_obj::append,
	( ::String (::hx::Object::*)(::String,::String,::String))&::polymod::format::JSONParseFormat_obj::merge,
};

void *JSONParseFormat_obj::_hx_getInterface(int inHash) {
	switch(inHash) {
		case (int)0xa2d29dcc: return &_hx_polymod_format_JSONParseFormat__hx_polymod_format_BaseParseFormat;
	}
	#ifdef HXCPP_SCRIPTABLE
	return super::_hx_getInterface(inHash);
	#else
	return 0;
	#endif
}

 ::Dynamic JSONParseFormat_obj::parse(::String str){
            	HX_GC_STACKFRAME(&_hx_pos_8feeea0724e4c481_585_parse)
HXLINE( 586)		 ::Dynamic result =  ::haxe::format::JsonParser_obj::__alloc( HX_CTX , ::EReg_obj::__alloc( HX_CTX ,HX_("(\r|\n|\t)",29,6f,a8,1e),HX_("g",67,00,00,00))->replace(str,HX_("",00,00,00,00)))->doParse();
HXLINE( 587)		return result;
            	}


HX_DEFINE_DYNAMIC_FUNC1(JSONParseFormat_obj,parse,return )

::String JSONParseFormat_obj::append(::String baseText,::String appendText,::String id){
            	HX_STACKFRAME(&_hx_pos_8feeea0724e4c481_591_append)
HXLINE( 592)		int lastBracket = ::polymod::util::Util_obj::uLastIndexOf(baseText,HX_("}",7d,00,00,00),null());
HXLINE( 593)		::String baseFirst = ::polymod::util::Util_obj::uSubstr(baseText,0,lastBracket);
HXLINE( 594)		::String baseEnd = ::polymod::util::Util_obj::uSubstr(baseText,lastBracket,baseText.length);
HXLINE( 596)		int firstAppendBracket = ::polymod::util::Util_obj::uIndexOf(appendText,HX_("{",7b,00,00,00),null());
HXLINE( 597)		int lastAppendBracket = ::polymod::util::Util_obj::uLastIndexOf(appendText,HX_("}",7d,00,00,00),null());
HXLINE( 598)		::String injectText = ::polymod::util::Util_obj::uSubstring(appendText,(firstAppendBracket + 1),lastAppendBracket);
HXLINE( 600)		bool _hx_tmp;
HXDLIN( 600)		if (::hx::IsNotNull( injectText )) {
HXLINE( 600)			_hx_tmp = (injectText == HX_("",00,00,00,00));
            		}
            		else {
HXLINE( 600)			_hx_tmp = true;
            		}
HXDLIN( 600)		if (_hx_tmp) {
HXLINE( 601)			return baseText;
            		}
HXLINE( 605)		baseFirst = ::polymod::util::Util_obj::uTrimFinalEndlines(baseFirst);
HXLINE( 606)		injectText = ::polymod::util::Util_obj::uTrimFinalEndlines(injectText);
HXLINE( 607)		injectText = ::polymod::util::Util_obj::uTrimFirstEndlines(injectText);
HXLINE( 608)		baseEnd = ::polymod::util::Util_obj::uTrimFinalEndlines(baseEnd);
HXLINE( 610)		return ((((HX_("",00,00,00,00) + baseFirst) + HX_(",\n",5e,26,00,00)) + injectText) + baseEnd);
            	}


HX_DEFINE_DYNAMIC_FUNC3(JSONParseFormat_obj,append,return )

::String JSONParseFormat_obj::merge(::String baseText,::String mergeText,::String id){
            	HX_STACKFRAME(&_hx_pos_8feeea0724e4c481_614_merge)
HXLINE( 615)		 ::Dynamic base = null();
HXLINE( 616)		 ::Dynamic merge = null();
HXLINE( 618)		try {
            			HX_STACK_CATCHABLE( ::Dynamic, 0);
HXLINE( 620)			base = this->parse(baseText);
            		} catch( ::Dynamic _hx_e) {
            			if (_hx_e.IsClass<  ::Dynamic >() ){
            				HX_STACK_BEGIN_CATCH
            				 ::Dynamic _g = _hx_e;
HXLINE( 622)				{
HXLINE( 622)					null();
            				}
HXDLIN( 622)				 ::Dynamic msg = ::haxe::Exception_obj::caught(_g)->unwrap();
HXLINE( 624)				::polymod::Polymod_obj::error(HX_("merge_error",c1,8f,ea,85),(((HX_("JSON merge error (",70,b4,36,a6) + id) + HX_("): couldn't parse base text! : ",1d,bc,ce,fd)) + ::Std_obj::string(msg)),null());
            			}
            			else {
            				HX_STACK_DO_THROW(_hx_e);
            			}
            		}
HXLINE( 627)		try {
            			HX_STACK_CATCHABLE( ::Dynamic, 0);
HXLINE( 629)			merge = this->parse(mergeText);
            		} catch( ::Dynamic _hx_e) {
            			if (_hx_e.IsClass<  ::Dynamic >() ){
            				HX_STACK_BEGIN_CATCH
            				 ::Dynamic _g = _hx_e;
HXLINE( 631)				{
HXLINE( 631)					null();
            				}
HXDLIN( 631)				 ::Dynamic msg = ::haxe::Exception_obj::caught(_g)->unwrap();
HXLINE( 633)				::polymod::Polymod_obj::error(HX_("merge_error",c1,8f,ea,85),(((HX_("JSON merge error (",70,b4,36,a6) + id) + HX_("): couldn't parse merge text! : ",9e,b5,85,90)) + ::Std_obj::string(msg)),null());
HXLINE( 634)				return baseText;
            			}
            			else {
            				HX_STACK_DO_THROW(_hx_e);
            			}
            		}
HXLINE( 637)		if (::Reflect_obj::hasField(merge,HX_("merge",b8,a2,c6,05))) {
HXLINE( 639)			if (::Std_obj::isOfType( ::Dynamic(merge->__Field(HX_("merge",b8,a2,c6,05),::hx::paccDynamic)),::hx::ArrayBase::__mClass)) {
HXLINE( 641)				::Array< ::Dynamic> merge1 = ( (::Array< ::Dynamic>)(merge->__Field(HX_("merge",b8,a2,c6,05),::hx::paccDynamic)) );
HXLINE( 642)				{
HXLINE( 642)					int _g = 0;
HXDLIN( 642)					while((_g < merge1->length)){
HXLINE( 642)						 ::Dynamic entry = merge1->__get(_g);
HXDLIN( 642)						_g = (_g + 1);
HXLINE( 644)						::String target = null();
HXLINE( 645)						 ::Dynamic payload = null();
HXLINE( 647)						target = ( (::String)(entry->__Field(HX_("target",51,f3,ec,86),::hx::paccDynamic)) );
HXLINE( 648)						payload =  ::Dynamic(entry->__Field(HX_("payload",8e,bf,35,ed),::hx::paccDynamic));
HXLINE( 649)						try {
            							HX_STACK_CATCHABLE( ::Dynamic, 0);
HXLINE( 651)							base = this->_mergeJson(base,entry,id);
            						} catch( ::Dynamic _hx_e) {
            							if (_hx_e.IsClass<  ::Dynamic >() ){
            								HX_STACK_BEGIN_CATCH
            								 ::Dynamic _g = _hx_e;
HXLINE( 653)								{
HXLINE( 653)									null();
            								}
HXDLIN( 653)								 ::Dynamic msg = ::haxe::Exception_obj::caught(_g)->unwrap();
HXLINE( 655)								{
HXLINE( 655)									 ::Dynamic replacer = null();
HXDLIN( 655)									::String space = null();
HXDLIN( 655)									::String _hx_tmp = ((((HX_("JSON merge error (",70,b4,36,a6) + id) + HX_("): could not merge payload \"",0d,a9,75,a2)) + ::haxe::format::JsonPrinter_obj::print(payload,replacer,space)) + HX_("\" into target : ",d3,66,33,03));
HXDLIN( 655)									::polymod::Polymod_obj::error(HX_("merge_error",c1,8f,ea,85),(_hx_tmp + ::Std_obj::string(msg)),null());
            								}
            							}
            							else {
            								HX_STACK_DO_THROW(_hx_e);
            							}
            						}
            					}
            				}
            			}
            			else {
HXLINE( 661)				::polymod::Polymod_obj::error(HX_("merge_error",c1,8f,ea,85),((HX_("JSON merge error (",70,b4,36,a6) + id) + HX_("): merge file must contain a single top-level array named \"merge\" (expected an array, found an object)",e8,99,bf,3f)),null());
            			}
            		}
            		else {
HXLINE( 667)			::polymod::Polymod_obj::error(HX_("merge_error",c1,8f,ea,85),((HX_("JSON merge error (",70,b4,36,a6) + id) + HX_("): merge file must contain a single top-level array named \"merge\"",e7,37,d7,02)),null());
            		}
HXLINE( 669)		return this->print(base);
            	}


HX_DEFINE_DYNAMIC_FUNC3(JSONParseFormat_obj,merge,return )

 ::Dynamic JSONParseFormat_obj::_mergeJson( ::Dynamic base, ::Dynamic entry,::String id){
            	HX_STACKFRAME(&_hx_pos_8feeea0724e4c481_673__mergeJson)
HXLINE( 674)		::Array< ::Dynamic> sig = this->_getTargetSignature(( (::String)(entry->__Field(HX_("target",51,f3,ec,86),::hx::paccDynamic)) ));
HXLINE( 675)		 ::Dynamic obj = base;
HXLINE( 676)		 ::Dynamic currTarget = sig->__get(0);
HXLINE( 677)		if (::hx::IsNull( currTarget )) {
HXLINE( 679)			::polymod::Polymod_obj::warning(HX_("merge_error",c1,8f,ea,85),(((HX_("JSON merge failed (",65,8c,1e,e4) + id) + HX_("), sig was ",23,fe,16,b9)) + ::Std_obj::string(sig)),null());
HXLINE( 680)			return obj;
            		}
HXLINE( 683)		bool done = false;
HXLINE( 684)		 ::Dynamic last = obj;
HXLINE( 685)		int i = 0;
HXLINE( 686)		::String signatureSoFar = HX_("",00,00,00,00);
HXLINE( 687)		 ::Dynamic _hx_struct =  ::Dynamic(::hx::Anon_obj::Create(4)
            			->setFixed(0,HX_("target",51,f3,ec,86),null())
            			->setFixed(1,HX_("parent",2a,05,7e,ed),null())
            			->setFixed(2,HX_("arrIndex",f1,4c,9d,16),-1)
            			->setFixed(3,HX_("next",f3,84,02,49),null()));
HXLINE( 699)		 ::Dynamic next = null();
HXLINE( 700)		while(!(done)){
HXLINE( 702)			_hx_struct = this->_descend(last,currTarget,signatureSoFar,_hx_struct);
HXLINE( 703)			if (::hx::IsNull( _hx_struct )) {
HXLINE( 705)				next = null();
            			}
            			else {
HXLINE( 709)				next =  ::Dynamic(_hx_struct->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic));
            			}
HXLINE( 712)			if ((signatureSoFar != HX_("",00,00,00,00))) {
HXLINE( 713)				signatureSoFar = (signatureSoFar + HX_(".",2e,00,00,00));
            			}
HXLINE( 714)			signatureSoFar = (signatureSoFar + this->_targSigElementToString(currTarget));
HXLINE( 715)			i = (i + 1);
HXLINE( 717)			if (::hx::IsNull( next )) {
HXLINE( 719)				::polymod::Polymod_obj::warning(HX_("merge_error",c1,8f,ea,85),((((HX_("JSON merge failed (",65,8c,1e,e4) + id) + HX_("), could not find object \"",5f,55,9e,7d)) + signatureSoFar) + HX_("\"",22,00,00,00)),null());
HXLINE( 720)				done = true;
            			}
            			else {
HXLINE( 724)				if ((i < sig->length)) {
HXLINE( 726)					currTarget = sig->__get(i);
            				}
            				else {
HXLINE( 730)					this->_inject( ::Dynamic(_hx_struct->__Field(HX_("parent",2a,05,7e,ed),::hx::paccDynamic)),( (::String)(_hx_struct->__Field(HX_("target",51,f3,ec,86),::hx::paccDynamic)) ),( (int)(_hx_struct->__Field(HX_("arrIndex",f1,4c,9d,16),::hx::paccDynamic)) ), ::Dynamic(entry->__Field(HX_("payload",8e,bf,35,ed),::hx::paccDynamic)),signatureSoFar);
HXLINE( 731)					done = true;
            				}
            			}
HXLINE( 734)			last = next;
            		}
HXLINE( 736)		return obj;
            	}


HX_DEFINE_DYNAMIC_FUNC3(JSONParseFormat_obj,_mergeJson,return )

::String JSONParseFormat_obj::_targSigElementToString( ::Dynamic target){
            	HX_STACKFRAME(&_hx_pos_8feeea0724e4c481_740__targSigElementToString)
HXLINE( 741)		::String str = ( (::String)(target->__Field(HX_("value",71,7f,b8,31),::hx::paccDynamic)) );
HXLINE( 742)		bool _hx_tmp;
HXDLIN( 742)		if (::hx::IsNotNull( target->__Field(HX_("arrayIndeces",12,fc,0e,92),::hx::paccDynamic) )) {
HXLINE( 742)			_hx_tmp = (( (::Array< int >)(target->__Field(HX_("arrayIndeces",12,fc,0e,92),::hx::paccDynamic)) )->length > 0);
            		}
            		else {
HXLINE( 742)			_hx_tmp = false;
            		}
HXDLIN( 742)		if (_hx_tmp) {
HXLINE( 744)			int _g = 0;
HXDLIN( 744)			::Array< int > _g1 = ( (::Array< int >)(target->__Field(HX_("arrayIndeces",12,fc,0e,92),::hx::paccDynamic)) );
HXDLIN( 744)			while((_g < _g1->length)){
HXLINE( 744)				int arri = _g1->__get(_g);
HXDLIN( 744)				_g = (_g + 1);
HXLINE( 746)				if ((arri >= 0)) {
HXLINE( 748)					str = (str + ((HX_("[",5b,00,00,00) + arri) + HX_("]",5d,00,00,00)));
            				}
            			}
            		}
HXLINE( 752)		return str;
            	}


HX_DEFINE_DYNAMIC_FUNC1(JSONParseFormat_obj,_targSigElementToString,return )

void JSONParseFormat_obj::_inject( ::Dynamic obj,::String target,int arrIndex, ::Dynamic payload,::String __o_signatureSoFar){
            		::String signatureSoFar = __o_signatureSoFar;
            		if (::hx::IsNull(__o_signatureSoFar)) signatureSoFar = HX_("",00,00,00,00);
            	HX_STACKFRAME(&_hx_pos_8feeea0724e4c481_757__inject)
HXDLIN( 757)		if ((arrIndex == -1)) {
HXLINE( 759)			if (::Reflect_obj::hasField(obj,target)) {
HXLINE( 761)				 ::Dynamic baseObject = ::Reflect_obj::field(obj,target);
HXLINE( 762)				 ::Dynamic mergedValue = this->_mergeObjects(baseObject,payload,signatureSoFar);
HXLINE( 763)				::Reflect_obj::setField(obj,target,mergedValue);
            			}
            			else {
HXLINE( 767)				::Reflect_obj::setField(obj,target,payload);
            			}
            		}
            		else {
HXLINE( 772)			if (::Std_obj::isOfType(obj,::hx::ArrayBase::__mClass)) {
HXLINE( 774)				::cpp::VirtualArray arr = ( (::cpp::VirtualArray)(obj) );
HXLINE( 775)				if ((arr->get_length() > arrIndex)) {
HXLINE( 777)					 ::Dynamic baseObject = arr->__get(arrIndex);
HXLINE( 778)					 ::Dynamic mergedValue = this->_mergeObjects(baseObject,payload,signatureSoFar);
            				}
            				else {
HXLINE( 782)					::polymod::Polymod_obj::warning(HX_("merge_error",c1,8f,ea,85),(((((HX_("JSON merge failed, array index (",a2,4c,16,8f) + arrIndex) + HX_(") out of bounds for array of length (",6e,14,f7,6a)) + arr->get_length()) + HX_(") at ",56,9c,de,b0)) + signatureSoFar),null());
            				}
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC5(JSONParseFormat_obj,_inject,(void))

 ::Dynamic JSONParseFormat_obj::_mergeObjects( ::Dynamic a, ::Dynamic b,::String __o_signatureSoFar){
            		::String signatureSoFar = __o_signatureSoFar;
            		if (::hx::IsNull(__o_signatureSoFar)) signatureSoFar = HX_("",00,00,00,00);
            	HX_STACKFRAME(&_hx_pos_8feeea0724e4c481_795__mergeObjects)
HXLINE( 796)		bool _hx_tmp;
HXDLIN( 796)		if (::Std_obj::isOfType(a,::hx::ArrayBase::__mClass)) {
HXLINE( 796)			_hx_tmp = ::Std_obj::isOfType(b,::hx::ArrayBase::__mClass);
            		}
            		else {
HXLINE( 796)			_hx_tmp = false;
            		}
HXDLIN( 796)		if (_hx_tmp) {
HXLINE( 799)			return b;
            		}
            		else {
HXLINE( 801)			bool _hx_tmp;
HXDLIN( 801)			if (!(::Std_obj::isOfType(a,::hx::ArrayBase::__mClass))) {
HXLINE( 801)				_hx_tmp = !(::Std_obj::isOfType(b,::hx::ArrayBase::__mClass));
            			}
            			else {
HXLINE( 801)				_hx_tmp = false;
            			}
HXDLIN( 801)			if (_hx_tmp) {
HXLINE( 803)				bool aPrimitive = this->isPrimitive(a);
HXLINE( 804)				bool bPrimitive = this->isPrimitive(b);
HXLINE( 805)				bool _hx_tmp;
HXDLIN( 805)				if (aPrimitive) {
HXLINE( 805)					_hx_tmp = bPrimitive;
            				}
            				else {
HXLINE( 805)					_hx_tmp = false;
            				}
HXDLIN( 805)				if (_hx_tmp) {
HXLINE( 808)					return b;
            				}
            				else {
HXLINE( 810)					if ((aPrimitive != bPrimitive)) {
HXLINE( 813)						return a;
            					}
            					else {
HXLINE( 818)						int _g = 0;
HXDLIN( 818)						::Array< ::String > _g1 = ::Reflect_obj::fields(b);
HXDLIN( 818)						while((_g < _g1->length)){
HXLINE( 818)							::String field = _g1->__get(_g);
HXDLIN( 818)							_g = (_g + 1);
HXLINE( 820)							if (::Reflect_obj::hasField(a,field)) {
HXLINE( 823)								 ::Dynamic aValue = ::Reflect_obj::field(a,field);
HXLINE( 824)								 ::Dynamic bValue = ::Reflect_obj::field(b,field);
HXLINE( 825)								 ::Dynamic mergedValue = this->copyVal(this->_mergeObjects(aValue,bValue,(((HX_("",00,00,00,00) + signatureSoFar) + HX_(".",2e,00,00,00)) + field)));
HXLINE( 826)								::Reflect_obj::setField(a,field,mergedValue);
            							}
            							else {
HXLINE( 831)								::Reflect_obj::setField(a,field,::Reflect_obj::field(b,field));
            							}
            						}
            					}
            				}
            			}
            			else {
HXLINE( 839)				::String aArr;
HXDLIN( 839)				if (::Std_obj::isOfType(a,::hx::ArrayBase::__mClass)) {
HXLINE( 839)					aArr = HX_("array",99,6d,8f,25);
            				}
            				else {
HXLINE( 839)					aArr = HX_("object",bf,7e,3f,15);
            				}
HXLINE( 840)				::String bArr;
HXDLIN( 840)				if (::Std_obj::isOfType(b,::hx::ArrayBase::__mClass)) {
HXLINE( 840)					bArr = HX_("array",99,6d,8f,25);
            				}
            				else {
HXLINE( 840)					bArr = HX_("object",bf,7e,3f,15);
            				}
HXLINE( 841)				::polymod::Polymod_obj::warning(HX_("merge_error",c1,8f,ea,85),((((((HX_("JSON can't merge @ (",85,71,3f,d3) + signatureSoFar) + HX_(") because base is (",50,8e,37,ae)) + aArr) + HX_(") but payload is (",5a,2e,59,4c)) + bArr) + HX_(")",29,00,00,00)),null());
            			}
            		}
HXLINE( 843)		return a;
            	}


HX_DEFINE_DYNAMIC_FUNC3(JSONParseFormat_obj,_mergeObjects,return )

 ::Dynamic JSONParseFormat_obj::copyVal( ::Dynamic a){
            	HX_STACKFRAME(&_hx_pos_8feeea0724e4c481_847_copyVal)
HXLINE( 848)		 ::Dynamic b = null();
HXLINE( 849)		if (::Std_obj::isOfType(a,::hx::ClassOf< int >())) {
HXLINE( 850)			b = ::Std_obj::_hx_int(( (Float)(a) ));
            		}
HXLINE( 851)		if (::Std_obj::isOfType(a,::hx::ClassOf< ::Float >())) {
HXLINE( 852)			b = ::hx::TCast< Float >::cast(a);
            		}
HXLINE( 853)		if (::Std_obj::isOfType(a,::hx::ClassOf< ::String >())) {
HXLINE( 854)			b = ::Std_obj::string(b);
            		}
HXLINE( 855)		if (::Std_obj::isOfType(a,::hx::ClassOf< bool >())) {
HXLINE( 856)			b = ::hx::IsEq( a,true );
            		}
            		else {
HXLINE( 858)			b = ::Std_obj::string(a);
            		}
HXLINE( 859)		return b;
            	}


HX_DEFINE_DYNAMIC_FUNC1(JSONParseFormat_obj,copyVal,return )

bool JSONParseFormat_obj::isPrimitive( ::Dynamic a){
            	HX_STACKFRAME(&_hx_pos_8feeea0724e4c481_863_isPrimitive)
HXLINE( 864)		if (::Std_obj::isOfType(a,::hx::ClassOf< ::String >())) {
HXLINE( 865)			return true;
            		}
HXLINE( 866)		if (::Std_obj::isOfType(a,::hx::ClassOf< ::Float >())) {
HXLINE( 867)			return true;
            		}
HXLINE( 868)		if (::Std_obj::isOfType(a,::hx::ClassOf< int >())) {
HXLINE( 869)			return true;
            		}
HXLINE( 870)		if (::Std_obj::isOfType(a,::hx::ClassOf< bool >())) {
HXLINE( 871)			return true;
            		}
HXLINE( 872)		return false;
            	}


HX_DEFINE_DYNAMIC_FUNC1(JSONParseFormat_obj,isPrimitive,return )

 ::Dynamic JSONParseFormat_obj::_descend( ::Dynamic obj, ::Dynamic target,::String __o_signatureSoFar, ::Dynamic _hx_struct){
            		::String signatureSoFar = __o_signatureSoFar;
            		if (::hx::IsNull(__o_signatureSoFar)) signatureSoFar = HX_("",00,00,00,00);
            	HX_STACKFRAME(&_hx_pos_8feeea0724e4c481_888__descend)
HXLINE( 889)		if (::hx::IsNull( _hx_struct )) {
HXLINE( 891)			_hx_struct =  ::Dynamic(::hx::Anon_obj::Create(4)
            				->setFixed(0,HX_("target",51,f3,ec,86),null())
            				->setFixed(1,HX_("parent",2a,05,7e,ed),null())
            				->setFixed(2,HX_("arrIndex",f1,4c,9d,16),-1)
            				->setFixed(3,HX_("next",f3,84,02,49),null()));
            		}
HXLINE( 898)		if (::hx::IsNull( obj )) {
HXLINE( 899)			return null();
            		}
HXLINE( 900)		if (::hx::IsNull( target )) {
HXLINE( 901)			return null();
            		}
HXLINE( 903)		if ((::Reflect_obj::hasField(obj,( (::String)(target->__Field(HX_("value",71,7f,b8,31),::hx::paccDynamic)) )) == false)) {
HXLINE( 905)			::polymod::Polymod_obj::warning(HX_("merge_error",c1,8f,ea,85),( (::String)(((((HX_("JSON merge error : object (",e5,d3,7c,c6) + signatureSoFar) + HX_(") has no field (",80,c1,77,e8)) + target->__Field(HX_("value",71,7f,b8,31),::hx::paccDynamic)) + HX_(")",29,00,00,00))) ),null());
HXLINE( 906)			return null();
            		}
HXLINE( 908)		 ::Dynamic next = ::Reflect_obj::field(obj,( (::String)(target->__Field(HX_("value",71,7f,b8,31),::hx::paccDynamic)) ));
HXLINE( 910)		_hx_struct->__SetField(HX_("next",f3,84,02,49),next,::hx::paccDynamic);
HXLINE( 911)		_hx_struct->__SetField(HX_("parent",2a,05,7e,ed),obj,::hx::paccDynamic);
HXLINE( 912)		_hx_struct->__SetField(HX_("target",51,f3,ec,86),target->__Field(HX_("value",71,7f,b8,31),::hx::paccDynamic),::hx::paccDynamic);
HXLINE( 914)		if (::hx::IsNull( next )) {
HXLINE( 916)			return _hx_struct;
            		}
HXLINE( 918)		if ((( (::Array< int >)(target->__Field(HX_("arrayIndeces",12,fc,0e,92),::hx::paccDynamic)) )->length > 0)) {
HXLINE( 920)			_hx_struct->__SetField(HX_("next",f3,84,02,49),next,::hx::paccDynamic);
HXLINE( 921)			if (::Std_obj::isOfType(next,::hx::ArrayBase::__mClass)) {
HXLINE( 923)				::cpp::VirtualArray arr = ( (::cpp::VirtualArray)(next) );
HXLINE( 924)				::Array< int > arrIndeces = ( (::Array< int >)(target->__Field(HX_("arrayIndeces",12,fc,0e,92),::hx::paccDynamic)) )->copy();
HXLINE( 925)				bool done = false;
HXLINE( 926)				signatureSoFar = ( (::String)((signatureSoFar + (HX_(".",2e,00,00,00) + target->__Field(HX_("value",71,7f,b8,31),::hx::paccDynamic)))) );
HXLINE( 927)				while((arrIndeces->length > 0)){
HXLINE( 929)					 ::Dynamic arrIndex = arrIndeces->shift();
HXLINE( 930)					if (::hx::IsLess( arrIndex,arr->get_length() )) {
HXLINE( 932)						_hx_struct->__SetField(HX_("parent",2a,05,7e,ed),next,::hx::paccDynamic);
HXLINE( 933)						next = arr->__get(( (int)(arrIndex) ));
HXLINE( 934)						_hx_struct->__SetField(HX_("next",f3,84,02,49),next,::hx::paccDynamic);
HXLINE( 935)						_hx_struct->__SetField(HX_("arrIndex",f1,4c,9d,16),arrIndex,::hx::paccDynamic);
HXLINE( 936)						if (::Std_obj::isOfType(next,::hx::ArrayBase::__mClass)) {
HXLINE( 938)							arr = ( (::cpp::VirtualArray)(next) );
            						}
            						else {
HXLINE( 942)							::polymod::Polymod_obj::warning(HX_("merge_error",c1,8f,ea,85),((((HX_("JSON merge error : invalid array access [",2d,d9,47,04) + arrIndex) + HX_("] on target \"",71,b4,05,40)) + signatureSoFar) + HX_("\"",22,00,00,00)),null());
HXLINE( 943)							done = true;
            						}
            					}
            					else {
HXLINE( 948)						::polymod::Polymod_obj::warning(HX_("merge_error",c1,8f,ea,85),(((((HX_("JSON merge error : array index (",f5,d1,14,72) + arrIndex) + HX_(") out of bounds on target \"",29,e2,45,b0)) + signatureSoFar) + HX_("\" with length ",1e,a7,04,80)) + arr->get_length()),null());
HXLINE( 950)						done = true;
            					}
HXLINE( 952)					signatureSoFar = (signatureSoFar + ((HX_("[",5b,00,00,00) + arrIndex) + HX_("]",5d,00,00,00)));
            				}
            			}
            			else {
HXLINE( 957)				return null();
            			}
            		}
HXLINE( 960)		return _hx_struct;
            	}


HX_DEFINE_DYNAMIC_FUNC4(JSONParseFormat_obj,_descend,return )

::Array< ::Dynamic> JSONParseFormat_obj::_getTargetSignature(::String str){
            	HX_STACKFRAME(&_hx_pos_8feeea0724e4c481_964__getTargetSignature)
HXLINE( 965)		if (::hx::IsNull( str )) {
HXLINE( 966)			return ::Array_obj< ::Dynamic>::__new(0);
            		}
HXLINE( 967)		::Array< ::Dynamic> result = ::Array_obj< ::Dynamic>::__new(0);
HXLINE( 968)		::Array< ::String > arr = str.split(HX_(".",2e,00,00,00));
HXLINE( 969)		{
HXLINE( 969)			int _g = 0;
HXDLIN( 969)			while((_g < arr->length)){
HXLINE( 969)				::String bit = arr->__get(_g);
HXDLIN( 969)				_g = (_g + 1);
HXLINE( 971)				if ((bit.indexOf(HX_("[",5b,00,00,00),null()) != -1)) {
HXLINE( 973)					::Array< ::String > arr2 = bit.split(HX_("[",5b,00,00,00));
HXLINE( 974)					::String value = ( (::String)(arr2->shift()) );
HXLINE( 975)					::Array< ::Dynamic> arrayIndeces = ::Array_obj< ::Dynamic>::__new(0);
HXLINE( 976)					while((arr2->length > 0)){
HXLINE( 978)						::String value2 = ( (::String)(arr2->shift()) );
HXLINE( 979)						value2 = ::polymod::util::Util_obj::uTrimFinalCharIf(value2,HX_("]",5d,00,00,00));
HXLINE( 980)						 ::Dynamic arrIndex = ::Std_obj::parseInt(value2);
HXLINE( 981)						bool _hx_tmp;
HXDLIN( 981)						if (::hx::IsNotNull( arrIndex )) {
HXLINE( 981)							_hx_tmp = ::hx::IsGreaterEq( arrIndex,0 );
            						}
            						else {
HXLINE( 981)							_hx_tmp = false;
            						}
HXDLIN( 981)						if (_hx_tmp) {
HXLINE( 983)							arrayIndeces->push(arrIndex);
            						}
            						else {
HXLINE( 987)							::polymod::Polymod_obj::warning(HX_("merge_error",c1,8f,ea,85),((((HX_("JSON merge error: found invalid array index (",7e,22,f3,0f) + value2) + HX_(") in signature (",5c,ce,b9,91)) + str) + HX_(")",29,00,00,00)),null());
HXLINE( 988)							goto _hx_goto_17;
            						}
            					}
            					_hx_goto_17:;
HXLINE( 991)					result->push( ::Dynamic(::hx::Anon_obj::Create(2)
            						->setFixed(0,HX_("arrayIndeces",12,fc,0e,92),arrayIndeces)
            						->setFixed(1,HX_("value",71,7f,b8,31),value)));
            				}
            				else {
HXLINE( 995)					result->push( ::Dynamic(::hx::Anon_obj::Create(2)
            						->setFixed(0,HX_("arrayIndeces",12,fc,0e,92),::Array_obj< ::Dynamic>::__new(0))
            						->setFixed(1,HX_("value",71,7f,b8,31),bit)));
            				}
            			}
            		}
HXLINE( 998)		return result;
            	}


HX_DEFINE_DYNAMIC_FUNC1(JSONParseFormat_obj,_getTargetSignature,return )

::String JSONParseFormat_obj::print( ::Dynamic data){
            	HX_STACKFRAME(&_hx_pos_8feeea0724e4c481_1003_print)
HXDLIN(1003)		return ::haxe::format::JsonPrinter_obj::print(data,this->replacer,this->space);
            	}


HX_DEFINE_DYNAMIC_FUNC1(JSONParseFormat_obj,print,return )


::hx::ObjectPtr< JSONParseFormat_obj > JSONParseFormat_obj::__new(::String space, ::Dynamic replacer) {
	::hx::ObjectPtr< JSONParseFormat_obj > __this = new JSONParseFormat_obj();
	__this->__construct(space,replacer);
	return __this;
}

::hx::ObjectPtr< JSONParseFormat_obj > JSONParseFormat_obj::__alloc(::hx::Ctx *_hx_ctx,::String space, ::Dynamic replacer) {
	JSONParseFormat_obj *__this = (JSONParseFormat_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(JSONParseFormat_obj), true, "polymod.format.JSONParseFormat"));
	*(void **)__this = JSONParseFormat_obj::_hx_vtable;
	__this->__construct(space,replacer);
	return __this;
}

JSONParseFormat_obj::JSONParseFormat_obj()
{
}

void JSONParseFormat_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(JSONParseFormat);
	HX_MARK_MEMBER_NAME(format,"format");
	HX_MARK_MEMBER_NAME(space,"space");
	HX_MARK_MEMBER_NAME(replacer,"replacer");
	HX_MARK_END_CLASS();
}

void JSONParseFormat_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(format,"format");
	HX_VISIT_MEMBER_NAME(space,"space");
	HX_VISIT_MEMBER_NAME(replacer,"replacer");
}

::hx::Val JSONParseFormat_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"space") ) { return ::hx::Val( space ); }
		if (HX_FIELD_EQ(inName,"parse") ) { return ::hx::Val( parse_dyn() ); }
		if (HX_FIELD_EQ(inName,"merge") ) { return ::hx::Val( merge_dyn() ); }
		if (HX_FIELD_EQ(inName,"print") ) { return ::hx::Val( print_dyn() ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"format") ) { return ::hx::Val( format ); }
		if (HX_FIELD_EQ(inName,"append") ) { return ::hx::Val( append_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_inject") ) { return ::hx::Val( _inject_dyn() ); }
		if (HX_FIELD_EQ(inName,"copyVal") ) { return ::hx::Val( copyVal_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"replacer") ) { return ::hx::Val( replacer ); }
		if (HX_FIELD_EQ(inName,"_descend") ) { return ::hx::Val( _descend_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_mergeJson") ) { return ::hx::Val( _mergeJson_dyn() ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"isPrimitive") ) { return ::hx::Val( isPrimitive_dyn() ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_mergeObjects") ) { return ::hx::Val( _mergeObjects_dyn() ); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_getTargetSignature") ) { return ::hx::Val( _getTargetSignature_dyn() ); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"_targSigElementToString") ) { return ::hx::Val( _targSigElementToString_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val JSONParseFormat_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"space") ) { space=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"format") ) { format=inValue.Cast<  ::polymod::format::TextFileFormat >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"replacer") ) { replacer=inValue.Cast<  ::Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void JSONParseFormat_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("format",37,8f,8e,fd));
	outFields->push(HX_("space",c6,8c,66,81));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo JSONParseFormat_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::polymod::format::TextFileFormat */ ,(int)offsetof(JSONParseFormat_obj,format),HX_("format",37,8f,8e,fd)},
	{::hx::fsString,(int)offsetof(JSONParseFormat_obj,space),HX_("space",c6,8c,66,81)},
	{::hx::fsObject /*  ::Dynamic */ ,(int)offsetof(JSONParseFormat_obj,replacer),HX_("replacer",be,e5,16,18)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *JSONParseFormat_obj_sStaticStorageInfo = 0;
#endif

static ::String JSONParseFormat_obj_sMemberFields[] = {
	HX_("format",37,8f,8e,fd),
	HX_("space",c6,8c,66,81),
	HX_("replacer",be,e5,16,18),
	HX_("parse",33,90,55,bd),
	HX_("append",da,e1,d3,8f),
	HX_("merge",b8,a2,c6,05),
	HX_("_mergeJson",c1,48,5e,c9),
	HX_("_targSigElementToString",18,fe,c8,b5),
	HX_("_inject",30,5c,61,06),
	HX_("_mergeObjects",db,c7,82,19),
	HX_("copyVal",2c,5a,87,43),
	HX_("isPrimitive",5d,3f,d9,05),
	HX_("_descend",ab,07,f8,52),
	HX_("_getTargetSignature",90,41,cb,0c),
	HX_("print",2d,58,8b,c8),
	::String(null()) };

::hx::Class JSONParseFormat_obj::__mClass;

void JSONParseFormat_obj::__register()
{
	JSONParseFormat_obj _hx_dummy;
	JSONParseFormat_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("polymod.format.JSONParseFormat",c3,fc,67,e0);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(JSONParseFormat_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< JSONParseFormat_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = JSONParseFormat_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = JSONParseFormat_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace polymod
} // end namespace format
