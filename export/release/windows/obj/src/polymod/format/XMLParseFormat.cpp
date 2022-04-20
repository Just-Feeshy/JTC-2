#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Xml
#include <Xml.h>
#endif
#ifndef INCLUDED_haxe_Exception
#include <haxe/Exception.h>
#endif
#ifndef INCLUDED_haxe_xml_Printer
#include <haxe/xml/Printer.h>
#endif
#ifndef INCLUDED_polymod_format_BaseParseFormat
#include <polymod/format/BaseParseFormat.h>
#endif
#ifndef INCLUDED_polymod_format_TextFileFormat
#include <polymod/format/TextFileFormat.h>
#endif
#ifndef INCLUDED_polymod_format_XMLMerge
#include <polymod/format/XMLMerge.h>
#endif
#ifndef INCLUDED_polymod_format_XMLParseFormat
#include <polymod/format/XMLParseFormat.h>
#endif
#ifndef INCLUDED_polymod_util_Util
#include <polymod/util/Util.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_be220568d9d5b1fe_485_new,"polymod.format.XMLParseFormat","new",0x075e5a24,"polymod.format.XMLParseFormat.new","polymod/format/ParseRules.hx",485,0xc5c5c43b)
HX_LOCAL_STACK_FRAME(_hx_pos_be220568d9d5b1fe_506_parse,"polymod.format.XMLParseFormat","parse",0x836912f7,"polymod.format.XMLParseFormat.parse","polymod/format/ParseRules.hx",506,0xc5c5c43b)
HX_LOCAL_STACK_FRAME(_hx_pos_be220568d9d5b1fe_511_append,"polymod.format.XMLParseFormat","append",0x1ad2ca96,"polymod.format.XMLParseFormat.append","polymod/format/ParseRules.hx",511,0xc5c5c43b)
HX_LOCAL_STACK_FRAME(_hx_pos_be220568d9d5b1fe_522_merge,"polymod.format.XMLParseFormat","merge",0xcbda257c,"polymod.format.XMLParseFormat.merge","polymod/format/ParseRules.hx",522,0xc5c5c43b)
HX_LOCAL_STACK_FRAME(_hx_pos_be220568d9d5b1fe_550_print,"polymod.format.XMLParseFormat","print",0x8e9edaf1,"polymod.format.XMLParseFormat.print","polymod/format/ParseRules.hx",550,0xc5c5c43b)
namespace polymod{
namespace format{

void XMLParseFormat_obj::__construct(::hx::Null< bool >  __o_prettyPrint,::Array< ::String > headers,::Array< ::String > footers){
            		bool prettyPrint = __o_prettyPrint.Default(false);
            	HX_STACKFRAME(&_hx_pos_be220568d9d5b1fe_485_new)
HXLINE( 488)		this->prettyPrint = false;
HXLINE( 494)		if (::hx::IsNull( headers )) {
HXLINE( 495)			headers = ::Array_obj< ::String >::__new(0);
            		}
HXLINE( 496)		if (::hx::IsNull( footers )) {
HXLINE( 497)			footers = ::Array_obj< ::String >::__new(0);
            		}
HXLINE( 498)		this->stripHeaders = headers;
HXLINE( 499)		this->stripFooters = footers;
HXLINE( 500)		this->prettyPrint = prettyPrint;
HXLINE( 501)		this->format = ::polymod::format::TextFileFormat_obj::XML_dyn();
            	}

Dynamic XMLParseFormat_obj::__CreateEmpty() { return new XMLParseFormat_obj; }

void *XMLParseFormat_obj::_hx_vtable = 0;

Dynamic XMLParseFormat_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< XMLParseFormat_obj > _hx_result = new XMLParseFormat_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return _hx_result;
}

bool XMLParseFormat_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x7a35e140;
}

static ::polymod::format::BaseParseFormat_obj _hx_polymod_format_XMLParseFormat__hx_polymod_format_BaseParseFormat= {
	( ::String (::hx::Object::*)(::String,::String,::String))&::polymod::format::XMLParseFormat_obj::append,
	( ::String (::hx::Object::*)(::String,::String,::String))&::polymod::format::XMLParseFormat_obj::merge,
};

void *XMLParseFormat_obj::_hx_getInterface(int inHash) {
	switch(inHash) {
		case (int)0xa2d29dcc: return &_hx_polymod_format_XMLParseFormat__hx_polymod_format_BaseParseFormat;
	}
	#ifdef HXCPP_SCRIPTABLE
	return super::_hx_getInterface(inHash);
	#else
	return 0;
	#endif
}

 ::Xml XMLParseFormat_obj::parse(::String str){
            	HX_STACKFRAME(&_hx_pos_be220568d9d5b1fe_506_parse)
HXDLIN( 506)		return ::Xml_obj::parse(str);
            	}


HX_DEFINE_DYNAMIC_FUNC1(XMLParseFormat_obj,parse,return )

::String XMLParseFormat_obj::append(::String baseText,::String appendText,::String id){
            	HX_STACKFRAME(&_hx_pos_be220568d9d5b1fe_511_append)
HXDLIN( 511)		bool _hx_tmp;
HXDLIN( 511)		if (::hx::IsNotNull( this->stripHeaders )) {
HXDLIN( 511)			_hx_tmp = ::hx::IsNotNull( this->stripFooters );
            		}
            		else {
HXDLIN( 511)			_hx_tmp = false;
            		}
HXDLIN( 511)		if (_hx_tmp) {
HXLINE( 513)			return ::polymod::util::Util_obj::appendSpecialXML(baseText,appendText,this->stripHeaders,this->stripFooters);
            		}
            		else {
HXLINE( 517)			return ::polymod::util::Util_obj::appendXML(baseText,appendText);
            		}
HXLINE( 511)		return null();
            	}


HX_DEFINE_DYNAMIC_FUNC3(XMLParseFormat_obj,append,return )

::String XMLParseFormat_obj::merge(::String baseText,::String mergeText,::String id){
            	HX_STACKFRAME(&_hx_pos_be220568d9d5b1fe_522_merge)
HXLINE( 523)		 ::Xml basex = null();
HXLINE( 524)		 ::Xml mergex = null();
HXLINE( 526)		try {
            			HX_STACK_CATCHABLE( ::Dynamic, 0);
HXLINE( 528)			basex = ::Xml_obj::parse(baseText);
HXLINE( 529)			mergex = ::Xml_obj::parse(mergeText);
            		} catch( ::Dynamic _hx_e) {
            			if (_hx_e.IsClass<  ::Dynamic >() ){
            				HX_STACK_BEGIN_CATCH
            				 ::Dynamic _g = _hx_e;
HXLINE( 531)				{
HXLINE( 531)					null();
            				}
HXDLIN( 531)				 ::Dynamic msg = ::haxe::Exception_obj::caught(_g)->unwrap();
HXLINE( 533)				HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((((HX_("Error parsing XML files during merge (",5b,0b,12,8a) + id) + HX_("): ",0f,4f,1f,00)) + ::Std_obj::string(msg))));
            			}
            			else {
            				HX_STACK_DO_THROW(_hx_e);
            			}
            		}
HXLINE( 536)		try {
            			HX_STACK_CATCHABLE( ::Dynamic, 0);
HXLINE( 538)			::polymod::format::XMLMerge_obj::mergeXMLNodes(basex,mergex);
            		} catch( ::Dynamic _hx_e) {
            			if (_hx_e.IsClass<  ::Dynamic >() ){
            				HX_STACK_BEGIN_CATCH
            				 ::Dynamic _g = _hx_e;
HXLINE( 540)				{
HXLINE( 540)					null();
            				}
HXDLIN( 540)				 ::Dynamic msg = ::haxe::Exception_obj::caught(_g)->unwrap();
HXLINE( 542)				HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((((HX_("Error combining XML files during merge (",8f,b2,77,22) + id) + HX_("): ",0f,4f,1f,00)) + ::Std_obj::string(msg))));
            			}
            			else {
            				HX_STACK_DO_THROW(_hx_e);
            			}
            		}
HXLINE( 545)		return this->print(basex);
            	}


HX_DEFINE_DYNAMIC_FUNC3(XMLParseFormat_obj,merge,return )

::String XMLParseFormat_obj::print( ::Xml xml){
            	HX_STACKFRAME(&_hx_pos_be220568d9d5b1fe_550_print)
HXDLIN( 550)		return ::haxe::xml::Printer_obj::print(xml,this->prettyPrint);
            	}


HX_DEFINE_DYNAMIC_FUNC1(XMLParseFormat_obj,print,return )


::hx::ObjectPtr< XMLParseFormat_obj > XMLParseFormat_obj::__new(::hx::Null< bool >  __o_prettyPrint,::Array< ::String > headers,::Array< ::String > footers) {
	::hx::ObjectPtr< XMLParseFormat_obj > __this = new XMLParseFormat_obj();
	__this->__construct(__o_prettyPrint,headers,footers);
	return __this;
}

::hx::ObjectPtr< XMLParseFormat_obj > XMLParseFormat_obj::__alloc(::hx::Ctx *_hx_ctx,::hx::Null< bool >  __o_prettyPrint,::Array< ::String > headers,::Array< ::String > footers) {
	XMLParseFormat_obj *__this = (XMLParseFormat_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(XMLParseFormat_obj), true, "polymod.format.XMLParseFormat"));
	*(void **)__this = XMLParseFormat_obj::_hx_vtable;
	__this->__construct(__o_prettyPrint,headers,footers);
	return __this;
}

XMLParseFormat_obj::XMLParseFormat_obj()
{
}

void XMLParseFormat_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(XMLParseFormat);
	HX_MARK_MEMBER_NAME(format,"format");
	HX_MARK_MEMBER_NAME(prettyPrint,"prettyPrint");
	HX_MARK_MEMBER_NAME(stripHeaders,"stripHeaders");
	HX_MARK_MEMBER_NAME(stripFooters,"stripFooters");
	HX_MARK_END_CLASS();
}

void XMLParseFormat_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(format,"format");
	HX_VISIT_MEMBER_NAME(prettyPrint,"prettyPrint");
	HX_VISIT_MEMBER_NAME(stripHeaders,"stripHeaders");
	HX_VISIT_MEMBER_NAME(stripFooters,"stripFooters");
}

::hx::Val XMLParseFormat_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
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
	case 11:
		if (HX_FIELD_EQ(inName,"prettyPrint") ) { return ::hx::Val( prettyPrint ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"stripHeaders") ) { return ::hx::Val( stripHeaders ); }
		if (HX_FIELD_EQ(inName,"stripFooters") ) { return ::hx::Val( stripFooters ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val XMLParseFormat_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"format") ) { format=inValue.Cast<  ::polymod::format::TextFileFormat >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"prettyPrint") ) { prettyPrint=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"stripHeaders") ) { stripHeaders=inValue.Cast< ::Array< ::String > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"stripFooters") ) { stripFooters=inValue.Cast< ::Array< ::String > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void XMLParseFormat_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("format",37,8f,8e,fd));
	outFields->push(HX_("prettyPrint",97,b1,33,bb));
	outFields->push(HX_("stripHeaders",4e,b2,5f,4a));
	outFields->push(HX_("stripFooters",80,e9,f5,10));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo XMLParseFormat_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::polymod::format::TextFileFormat */ ,(int)offsetof(XMLParseFormat_obj,format),HX_("format",37,8f,8e,fd)},
	{::hx::fsBool,(int)offsetof(XMLParseFormat_obj,prettyPrint),HX_("prettyPrint",97,b1,33,bb)},
	{::hx::fsObject /* ::Array< ::String > */ ,(int)offsetof(XMLParseFormat_obj,stripHeaders),HX_("stripHeaders",4e,b2,5f,4a)},
	{::hx::fsObject /* ::Array< ::String > */ ,(int)offsetof(XMLParseFormat_obj,stripFooters),HX_("stripFooters",80,e9,f5,10)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *XMLParseFormat_obj_sStaticStorageInfo = 0;
#endif

static ::String XMLParseFormat_obj_sMemberFields[] = {
	HX_("format",37,8f,8e,fd),
	HX_("prettyPrint",97,b1,33,bb),
	HX_("stripHeaders",4e,b2,5f,4a),
	HX_("stripFooters",80,e9,f5,10),
	HX_("parse",33,90,55,bd),
	HX_("append",da,e1,d3,8f),
	HX_("merge",b8,a2,c6,05),
	HX_("print",2d,58,8b,c8),
	::String(null()) };

::hx::Class XMLParseFormat_obj::__mClass;

void XMLParseFormat_obj::__register()
{
	XMLParseFormat_obj _hx_dummy;
	XMLParseFormat_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("polymod.format.XMLParseFormat",32,b8,5d,f1);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(XMLParseFormat_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< XMLParseFormat_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = XMLParseFormat_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = XMLParseFormat_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace polymod
} // end namespace format
