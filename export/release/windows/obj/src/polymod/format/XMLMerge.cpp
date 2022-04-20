#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
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
#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_haxe_xml__Access_AttribAccess_Impl_
#include <haxe/xml/_Access/AttribAccess_Impl_.h>
#endif
#ifndef INCLUDED_haxe_xml__Access_HasAttribAccess_Impl_
#include <haxe/xml/_Access/HasAttribAccess_Impl_.h>
#endif
#ifndef INCLUDED_haxe_xml__Access_HasNodeAccess_Impl_
#include <haxe/xml/_Access/HasNodeAccess_Impl_.h>
#endif
#ifndef INCLUDED_haxe_xml__Access_NodeAccess_Impl_
#include <haxe/xml/_Access/NodeAccess_Impl_.h>
#endif
#ifndef INCLUDED_polymod_format_XMLMerge
#include <polymod/format/XMLMerge.h>
#endif
#ifndef INCLUDED_polymod_util_Util
#include <polymod/util/Util.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_6834fb29b0c2424f_8_mergeXMLWork,"polymod.format.XMLMerge","mergeXMLWork",0xbc737b7e,"polymod.format.XMLMerge.mergeXMLWork","polymod/format/XMLMerge.hx",8,0xbc4ad77e)
HX_LOCAL_STACK_FRAME(_hx_pos_6834fb29b0c2424f_65_countNodes,"polymod.format.XMLMerge","countNodes",0xe7024d70,"polymod.format.XMLMerge.countNodes","polymod/format/XMLMerge.hx",65,0xbc4ad77e)
HX_LOCAL_STACK_FRAME(_hx_pos_6834fb29b0c2424f_75_mergeXML,"polymod.format.XMLMerge","mergeXML",0x208a430d,"polymod.format.XMLMerge.mergeXML","polymod/format/XMLMerge.hx",75,0xbc4ad77e)
HX_LOCAL_STACK_FRAME(_hx_pos_6834fb29b0c2424f_143_mergeXMLNodes,"polymod.format.XMLMerge","mergeXMLNodes",0xf9f2b5e4,"polymod.format.XMLMerge.mergeXMLNodes","polymod/format/XMLMerge.hx",143,0xbc4ad77e)
static const ::String _hx_array_data_f83e6120_29[] = {
	HX_("",00,00,00,00),
};
HX_LOCAL_STACK_FRAME(_hx_pos_6834fb29b0c2424f_154_getNodeMergeMap,"polymod.format.XMLMerge","getNodeMergeMap",0xbbf9954e,"polymod.format.XMLMerge.getNodeMergeMap","polymod/format/XMLMerge.hx",154,0xbc4ad77e)
HX_LOCAL_STACK_FRAME(_hx_pos_6834fb29b0c2424f_194_getNodeSignature,"polymod.format.XMLMerge","getNodeSignature",0x642ae92e,"polymod.format.XMLMerge.getNodeSignature","polymod/format/XMLMerge.hx",194,0xbc4ad77e)
HX_LOCAL_STACK_FRAME(_hx_pos_6834fb29b0c2424f_223_mergeMapsDestructively,"polymod.format.XMLMerge","mergeMapsDestructively",0xca999aee,"polymod.format.XMLMerge.mergeMapsDestructively","polymod/format/XMLMerge.hx",223,0xbc4ad77e)
namespace polymod{
namespace format{

void XMLMerge_obj::__construct() { }

Dynamic XMLMerge_obj::__CreateEmpty() { return new XMLMerge_obj; }

void *XMLMerge_obj::_hx_vtable = 0;

Dynamic XMLMerge_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< XMLMerge_obj > _hx_result = new XMLMerge_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool XMLMerge_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x6b7b2bae;
}

void XMLMerge_obj::mergeXMLWork( ::Xml a, ::Xml b,::hx::Null< bool >  __o_children,::hx::Null< bool >  __o_attributes){
            		bool children = __o_children.Default(true);
            		bool attributes = __o_attributes.Default(true);
            	HX_STACKFRAME(&_hx_pos_6834fb29b0c2424f_8_mergeXMLWork)
HXLINE(   9)		bool _hx_tmp;
HXDLIN(   9)		if (::hx::IsNotNull( a )) {
HXLINE(   9)			_hx_tmp = ::hx::IsNull( b );
            		}
            		else {
HXLINE(   9)			_hx_tmp = true;
            		}
HXDLIN(   9)		if (_hx_tmp) {
HXLINE(  10)			return;
            		}
HXLINE(  12)		if ((a->nodeType == 6)) {
HXLINE(  14)			a = a->firstElement();
            		}
HXLINE(  16)		if ((b->nodeType == 6)) {
HXLINE(  18)			b = b->firstElement();
            		}
HXLINE(  21)		bool _hx_tmp1;
HXDLIN(  21)		if ((a->nodeType == 0)) {
HXLINE(  21)			_hx_tmp1 = (b->nodeType != 0);
            		}
            		else {
HXLINE(  21)			_hx_tmp1 = true;
            		}
HXDLIN(  21)		if (_hx_tmp1) {
HXLINE(  23)			return;
            		}
HXLINE(  26)		bool _hx_tmp2;
HXDLIN(  26)		if ((a->nodeType != ::Xml_obj::Element)) {
HXLINE(  26)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, expected Element but found ",d8,90,8b,bb) + ::_Xml::XmlType_Impl__obj::toString(a->nodeType))));
            		}
HXDLIN(  26)		if ((a->nodeName != HX_("merge",b8,a2,c6,05))) {
HXLINE(  26)			if ((b->nodeType != ::Xml_obj::Element)) {
HXLINE(  26)				HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, expected Element but found ",d8,90,8b,bb) + ::_Xml::XmlType_Impl__obj::toString(b->nodeType))));
            			}
HXDLIN(  26)			_hx_tmp2 = (b->nodeName == HX_("merge",b8,a2,c6,05));
            		}
            		else {
HXLINE(  26)			_hx_tmp2 = true;
            		}
HXDLIN(  26)		if (_hx_tmp2) {
HXLINE(  27)			return;
            		}
HXLINE(  29)		if (children) {
HXLINE(  31)			 ::Dynamic el = b->elements();
HXDLIN(  31)			while(( (bool)(el->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE(  31)				 ::Xml el1 = ( ( ::Xml)(el->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXLINE(  33)				if (::hx::IsNull( el1 )) {
HXLINE(  34)					continue;
            				}
HXLINE(  35)				if ((el1->nodeType != ::Xml_obj::Element)) {
HXLINE(  35)					HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, expected Element but found ",d8,90,8b,bb) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            				}
HXDLIN(  35)				if ((el1->nodeName == HX_("merge",b8,a2,c6,05))) {
HXLINE(  36)					continue;
            				}
HXLINE(  38)				if ((el1->nodeType != ::Xml_obj::Element)) {
HXLINE(  38)					HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, expected Element but found ",d8,90,8b,bb) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            				}
HXDLIN(  38)				int aCount = ::polymod::format::XMLMerge_obj::countNodes(a,el1->nodeName);
HXLINE(  39)				if ((el1->nodeType != ::Xml_obj::Element)) {
HXLINE(  39)					HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, expected Element but found ",d8,90,8b,bb) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            				}
HXDLIN(  39)				int bCount = ::polymod::format::XMLMerge_obj::countNodes(b,el1->nodeName);
HXLINE(  41)				bool _hx_tmp;
HXDLIN(  41)				if ((aCount == 0)) {
HXLINE(  41)					_hx_tmp = (bCount > 0);
            				}
            				else {
HXLINE(  41)					_hx_tmp = false;
            				}
HXDLIN(  41)				if (_hx_tmp) {
HXLINE(  43)					 ::Xml parent = null();
HXDLIN(  43)					 ::Xml c = null();
HXDLIN(  43)					if ((el1->nodeType == ::Xml_obj::Element)) {
HXLINE(  43)						if ((el1->nodeType != ::Xml_obj::Element)) {
HXLINE(  43)							HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, expected Element but found ",d8,90,8b,bb) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            						}
HXDLIN(  43)						c = ::Xml_obj::createElement(el1->nodeName);
HXDLIN(  43)						{
HXLINE(  43)							 ::Dynamic att = el1->attributes();
HXDLIN(  43)							while(( (bool)(att->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE(  43)								::String att1 = ( (::String)(att->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXDLIN(  43)								c->set(att1,el1->get(att1));
            							}
            						}
HXDLIN(  43)						{
HXLINE(  43)							 ::Dynamic el = el1->elements();
HXDLIN(  43)							while(( (bool)(el->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE(  43)								 ::Xml el1 = ( ( ::Xml)(el->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXDLIN(  43)								 ::Xml c1 = null();
HXDLIN(  43)								if ((el1->nodeType == ::Xml_obj::Element)) {
HXLINE(  43)									if ((el1->nodeType != ::Xml_obj::Element)) {
HXLINE(  43)										HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, expected Element but found ",d8,90,8b,bb) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            									}
HXDLIN(  43)									c1 = ::Xml_obj::createElement(el1->nodeName);
HXDLIN(  43)									{
HXLINE(  43)										 ::Dynamic att = el1->attributes();
HXDLIN(  43)										while(( (bool)(att->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE(  43)											::String att1 = ( (::String)(att->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXDLIN(  43)											c1->set(att1,el1->get(att1));
            										}
            									}
HXDLIN(  43)									{
HXLINE(  43)										 ::Dynamic el = el1->elements();
HXDLIN(  43)										while(( (bool)(el->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE(  43)											 ::Xml el1 = ( ( ::Xml)(el->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXDLIN(  43)											c1->addChild(::polymod::util::Util_obj::copyXml(el1,c1));
            										}
            									}
            								}
            								else {
HXLINE(  43)									if ((el1->nodeType == ::Xml_obj::PCData)) {
HXLINE(  43)										bool c;
HXDLIN(  43)										if ((el1->nodeType != ::Xml_obj::Document)) {
HXLINE(  43)											c = (el1->nodeType == ::Xml_obj::Element);
            										}
            										else {
HXLINE(  43)											c = true;
            										}
HXDLIN(  43)										if (c) {
HXLINE(  43)											HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            										}
HXDLIN(  43)										c1 = ::Xml_obj::createPCData(el1->nodeValue);
            									}
            									else {
HXLINE(  43)										if ((el1->nodeType == ::Xml_obj::CData)) {
HXLINE(  43)											bool c;
HXDLIN(  43)											if ((el1->nodeType != ::Xml_obj::Document)) {
HXLINE(  43)												c = (el1->nodeType == ::Xml_obj::Element);
            											}
            											else {
HXLINE(  43)												c = true;
            											}
HXDLIN(  43)											if (c) {
HXLINE(  43)												HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            											}
HXDLIN(  43)											c1 = ::Xml_obj::createCData(el1->nodeValue);
            										}
            										else {
HXLINE(  43)											if ((el1->nodeType == ::Xml_obj::Comment)) {
HXLINE(  43)												bool c;
HXDLIN(  43)												if ((el1->nodeType != ::Xml_obj::Document)) {
HXLINE(  43)													c = (el1->nodeType == ::Xml_obj::Element);
            												}
            												else {
HXLINE(  43)													c = true;
            												}
HXDLIN(  43)												if (c) {
HXLINE(  43)													HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            												}
HXDLIN(  43)												c1 = ::Xml_obj::createComment(el1->nodeValue);
            											}
            											else {
HXLINE(  43)												if ((el1->nodeType == ::Xml_obj::DocType)) {
HXLINE(  43)													bool c;
HXDLIN(  43)													if ((el1->nodeType != ::Xml_obj::Document)) {
HXLINE(  43)														c = (el1->nodeType == ::Xml_obj::Element);
            													}
            													else {
HXLINE(  43)														c = true;
            													}
HXDLIN(  43)													if (c) {
HXLINE(  43)														HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            													}
HXDLIN(  43)													c1 = ::Xml_obj::createDocType(el1->nodeValue);
            												}
            												else {
HXLINE(  43)													if ((el1->nodeType == ::Xml_obj::ProcessingInstruction)) {
HXLINE(  43)														bool c;
HXDLIN(  43)														if ((el1->nodeType != ::Xml_obj::Document)) {
HXLINE(  43)															c = (el1->nodeType == ::Xml_obj::Element);
            														}
            														else {
HXLINE(  43)															c = true;
            														}
HXDLIN(  43)														if (c) {
HXLINE(  43)															HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            														}
HXDLIN(  43)														c1 = ::Xml_obj::createProcessingInstruction(el1->nodeValue);
            													}
            													else {
HXLINE(  43)														if ((el1->nodeType == ::Xml_obj::Document)) {
HXLINE(  43)															c1 = ::Xml_obj::createDocument();
HXDLIN(  43)															{
HXLINE(  43)																 ::Dynamic el = el1->elements();
HXDLIN(  43)																while(( (bool)(el->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE(  43)																	 ::Xml el1 = ( ( ::Xml)(el->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXDLIN(  43)																	c1->addChild(::polymod::util::Util_obj::copyXml(el1,c1));
            																}
            															}
            														}
            													}
            												}
            											}
            										}
            									}
            								}
HXDLIN(  43)								c1->parent = c;
HXDLIN(  43)								c->addChild(c1);
            							}
            						}
            					}
            					else {
HXLINE(  43)						if ((el1->nodeType == ::Xml_obj::PCData)) {
HXLINE(  43)							bool c1;
HXDLIN(  43)							if ((el1->nodeType != ::Xml_obj::Document)) {
HXLINE(  43)								c1 = (el1->nodeType == ::Xml_obj::Element);
            							}
            							else {
HXLINE(  43)								c1 = true;
            							}
HXDLIN(  43)							if (c1) {
HXLINE(  43)								HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            							}
HXDLIN(  43)							c = ::Xml_obj::createPCData(el1->nodeValue);
            						}
            						else {
HXLINE(  43)							if ((el1->nodeType == ::Xml_obj::CData)) {
HXLINE(  43)								bool c1;
HXDLIN(  43)								if ((el1->nodeType != ::Xml_obj::Document)) {
HXLINE(  43)									c1 = (el1->nodeType == ::Xml_obj::Element);
            								}
            								else {
HXLINE(  43)									c1 = true;
            								}
HXDLIN(  43)								if (c1) {
HXLINE(  43)									HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            								}
HXDLIN(  43)								c = ::Xml_obj::createCData(el1->nodeValue);
            							}
            							else {
HXLINE(  43)								if ((el1->nodeType == ::Xml_obj::Comment)) {
HXLINE(  43)									bool c1;
HXDLIN(  43)									if ((el1->nodeType != ::Xml_obj::Document)) {
HXLINE(  43)										c1 = (el1->nodeType == ::Xml_obj::Element);
            									}
            									else {
HXLINE(  43)										c1 = true;
            									}
HXDLIN(  43)									if (c1) {
HXLINE(  43)										HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            									}
HXDLIN(  43)									c = ::Xml_obj::createComment(el1->nodeValue);
            								}
            								else {
HXLINE(  43)									if ((el1->nodeType == ::Xml_obj::DocType)) {
HXLINE(  43)										bool c1;
HXDLIN(  43)										if ((el1->nodeType != ::Xml_obj::Document)) {
HXLINE(  43)											c1 = (el1->nodeType == ::Xml_obj::Element);
            										}
            										else {
HXLINE(  43)											c1 = true;
            										}
HXDLIN(  43)										if (c1) {
HXLINE(  43)											HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            										}
HXDLIN(  43)										c = ::Xml_obj::createDocType(el1->nodeValue);
            									}
            									else {
HXLINE(  43)										if ((el1->nodeType == ::Xml_obj::ProcessingInstruction)) {
HXLINE(  43)											bool c1;
HXDLIN(  43)											if ((el1->nodeType != ::Xml_obj::Document)) {
HXLINE(  43)												c1 = (el1->nodeType == ::Xml_obj::Element);
            											}
            											else {
HXLINE(  43)												c1 = true;
            											}
HXDLIN(  43)											if (c1) {
HXLINE(  43)												HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            											}
HXDLIN(  43)											c = ::Xml_obj::createProcessingInstruction(el1->nodeValue);
            										}
            										else {
HXLINE(  43)											if ((el1->nodeType == ::Xml_obj::Document)) {
HXLINE(  43)												c = ::Xml_obj::createDocument();
HXDLIN(  43)												{
HXLINE(  43)													 ::Dynamic el = el1->elements();
HXDLIN(  43)													while(( (bool)(el->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE(  43)														 ::Xml el1 = ( ( ::Xml)(el->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXDLIN(  43)														 ::Xml c1 = null();
HXDLIN(  43)														if ((el1->nodeType == ::Xml_obj::Element)) {
HXLINE(  43)															if ((el1->nodeType != ::Xml_obj::Element)) {
HXLINE(  43)																HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, expected Element but found ",d8,90,8b,bb) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            															}
HXDLIN(  43)															c1 = ::Xml_obj::createElement(el1->nodeName);
HXDLIN(  43)															{
HXLINE(  43)																 ::Dynamic att = el1->attributes();
HXDLIN(  43)																while(( (bool)(att->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE(  43)																	::String att1 = ( (::String)(att->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXDLIN(  43)																	c1->set(att1,el1->get(att1));
            																}
            															}
HXDLIN(  43)															{
HXLINE(  43)																 ::Dynamic el = el1->elements();
HXDLIN(  43)																while(( (bool)(el->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE(  43)																	 ::Xml el1 = ( ( ::Xml)(el->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXDLIN(  43)																	c1->addChild(::polymod::util::Util_obj::copyXml(el1,c1));
            																}
            															}
            														}
            														else {
HXLINE(  43)															if ((el1->nodeType == ::Xml_obj::PCData)) {
HXLINE(  43)																bool c;
HXDLIN(  43)																if ((el1->nodeType != ::Xml_obj::Document)) {
HXLINE(  43)																	c = (el1->nodeType == ::Xml_obj::Element);
            																}
            																else {
HXLINE(  43)																	c = true;
            																}
HXDLIN(  43)																if (c) {
HXLINE(  43)																	HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            																}
HXDLIN(  43)																c1 = ::Xml_obj::createPCData(el1->nodeValue);
            															}
            															else {
HXLINE(  43)																if ((el1->nodeType == ::Xml_obj::CData)) {
HXLINE(  43)																	bool c;
HXDLIN(  43)																	if ((el1->nodeType != ::Xml_obj::Document)) {
HXLINE(  43)																		c = (el1->nodeType == ::Xml_obj::Element);
            																	}
            																	else {
HXLINE(  43)																		c = true;
            																	}
HXDLIN(  43)																	if (c) {
HXLINE(  43)																		HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            																	}
HXDLIN(  43)																	c1 = ::Xml_obj::createCData(el1->nodeValue);
            																}
            																else {
HXLINE(  43)																	if ((el1->nodeType == ::Xml_obj::Comment)) {
HXLINE(  43)																		bool c;
HXDLIN(  43)																		if ((el1->nodeType != ::Xml_obj::Document)) {
HXLINE(  43)																			c = (el1->nodeType == ::Xml_obj::Element);
            																		}
            																		else {
HXLINE(  43)																			c = true;
            																		}
HXDLIN(  43)																		if (c) {
HXLINE(  43)																			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            																		}
HXDLIN(  43)																		c1 = ::Xml_obj::createComment(el1->nodeValue);
            																	}
            																	else {
HXLINE(  43)																		if ((el1->nodeType == ::Xml_obj::DocType)) {
HXLINE(  43)																			bool c;
HXDLIN(  43)																			if ((el1->nodeType != ::Xml_obj::Document)) {
HXLINE(  43)																				c = (el1->nodeType == ::Xml_obj::Element);
            																			}
            																			else {
HXLINE(  43)																				c = true;
            																			}
HXDLIN(  43)																			if (c) {
HXLINE(  43)																				HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            																			}
HXDLIN(  43)																			c1 = ::Xml_obj::createDocType(el1->nodeValue);
            																		}
            																		else {
HXLINE(  43)																			if ((el1->nodeType == ::Xml_obj::ProcessingInstruction)) {
HXLINE(  43)																				bool c;
HXDLIN(  43)																				if ((el1->nodeType != ::Xml_obj::Document)) {
HXLINE(  43)																					c = (el1->nodeType == ::Xml_obj::Element);
            																				}
            																				else {
HXLINE(  43)																					c = true;
            																				}
HXDLIN(  43)																				if (c) {
HXLINE(  43)																					HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            																				}
HXDLIN(  43)																				c1 = ::Xml_obj::createProcessingInstruction(el1->nodeValue);
            																			}
            																			else {
HXLINE(  43)																				if ((el1->nodeType == ::Xml_obj::Document)) {
HXLINE(  43)																					c1 = ::Xml_obj::createDocument();
HXDLIN(  43)																					{
HXLINE(  43)																						 ::Dynamic el = el1->elements();
HXDLIN(  43)																						while(( (bool)(el->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE(  43)																							 ::Xml el1 = ( ( ::Xml)(el->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXDLIN(  43)																							c1->addChild(::polymod::util::Util_obj::copyXml(el1,c1));
            																						}
            																					}
            																				}
            																			}
            																		}
            																	}
            																}
            															}
            														}
HXDLIN(  43)														c1->parent = c;
HXDLIN(  43)														c->addChild(c1);
            													}
            												}
            											}
            										}
            									}
            								}
            							}
            						}
            					}
HXDLIN(  43)					c->parent = parent;
HXDLIN(  43)					a->addChild(c);
            				}
            				else {
HXLINE(  45)					bool _hx_tmp;
HXDLIN(  45)					if ((el1->nodeType != ::Xml_obj::Element)) {
HXLINE(  45)						HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, expected Element but found ",d8,90,8b,bb) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            					}
HXDLIN(  45)					if ((::polymod::format::XMLMerge_obj::countNodes(a,el1->nodeName) == 1)) {
HXLINE(  45)						if ((el1->nodeType != ::Xml_obj::Element)) {
HXLINE(  45)							HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, expected Element but found ",d8,90,8b,bb) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            						}
HXDLIN(  45)						_hx_tmp = (::polymod::format::XMLMerge_obj::countNodes(b,el1->nodeName) == 1);
            					}
            					else {
HXLINE(  45)						_hx_tmp = false;
            					}
HXDLIN(  45)					if (_hx_tmp) {
HXLINE(  47)						if ((el1->nodeType != ::Xml_obj::Element)) {
HXLINE(  47)							HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, expected Element but found ",d8,90,8b,bb) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            						}
HXDLIN(  47)						::polymod::format::XMLMerge_obj::mergeXMLWork(( ( ::Xml)(a->elementsNamed(el1->nodeName)->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) ),el1,null(),null());
            					}
            					else {
HXLINE(  51)						 ::Xml parent = null();
HXDLIN(  51)						 ::Xml c = null();
HXDLIN(  51)						if ((el1->nodeType == ::Xml_obj::Element)) {
HXLINE(  51)							if ((el1->nodeType != ::Xml_obj::Element)) {
HXLINE(  51)								HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, expected Element but found ",d8,90,8b,bb) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            							}
HXDLIN(  51)							c = ::Xml_obj::createElement(el1->nodeName);
HXDLIN(  51)							{
HXLINE(  51)								 ::Dynamic att = el1->attributes();
HXDLIN(  51)								while(( (bool)(att->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE(  51)									::String att1 = ( (::String)(att->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXDLIN(  51)									c->set(att1,el1->get(att1));
            								}
            							}
HXDLIN(  51)							{
HXLINE(  51)								 ::Dynamic el = el1->elements();
HXDLIN(  51)								while(( (bool)(el->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE(  51)									 ::Xml el1 = ( ( ::Xml)(el->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXDLIN(  51)									 ::Xml c1 = null();
HXDLIN(  51)									if ((el1->nodeType == ::Xml_obj::Element)) {
HXLINE(  51)										if ((el1->nodeType != ::Xml_obj::Element)) {
HXLINE(  51)											HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, expected Element but found ",d8,90,8b,bb) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            										}
HXDLIN(  51)										c1 = ::Xml_obj::createElement(el1->nodeName);
HXDLIN(  51)										{
HXLINE(  51)											 ::Dynamic att = el1->attributes();
HXDLIN(  51)											while(( (bool)(att->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE(  51)												::String att1 = ( (::String)(att->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXDLIN(  51)												c1->set(att1,el1->get(att1));
            											}
            										}
HXDLIN(  51)										{
HXLINE(  51)											 ::Dynamic el = el1->elements();
HXDLIN(  51)											while(( (bool)(el->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE(  51)												 ::Xml el1 = ( ( ::Xml)(el->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXDLIN(  51)												c1->addChild(::polymod::util::Util_obj::copyXml(el1,c1));
            											}
            										}
            									}
            									else {
HXLINE(  51)										if ((el1->nodeType == ::Xml_obj::PCData)) {
HXLINE(  51)											bool c;
HXDLIN(  51)											if ((el1->nodeType != ::Xml_obj::Document)) {
HXLINE(  51)												c = (el1->nodeType == ::Xml_obj::Element);
            											}
            											else {
HXLINE(  51)												c = true;
            											}
HXDLIN(  51)											if (c) {
HXLINE(  51)												HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            											}
HXDLIN(  51)											c1 = ::Xml_obj::createPCData(el1->nodeValue);
            										}
            										else {
HXLINE(  51)											if ((el1->nodeType == ::Xml_obj::CData)) {
HXLINE(  51)												bool c;
HXDLIN(  51)												if ((el1->nodeType != ::Xml_obj::Document)) {
HXLINE(  51)													c = (el1->nodeType == ::Xml_obj::Element);
            												}
            												else {
HXLINE(  51)													c = true;
            												}
HXDLIN(  51)												if (c) {
HXLINE(  51)													HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            												}
HXDLIN(  51)												c1 = ::Xml_obj::createCData(el1->nodeValue);
            											}
            											else {
HXLINE(  51)												if ((el1->nodeType == ::Xml_obj::Comment)) {
HXLINE(  51)													bool c;
HXDLIN(  51)													if ((el1->nodeType != ::Xml_obj::Document)) {
HXLINE(  51)														c = (el1->nodeType == ::Xml_obj::Element);
            													}
            													else {
HXLINE(  51)														c = true;
            													}
HXDLIN(  51)													if (c) {
HXLINE(  51)														HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            													}
HXDLIN(  51)													c1 = ::Xml_obj::createComment(el1->nodeValue);
            												}
            												else {
HXLINE(  51)													if ((el1->nodeType == ::Xml_obj::DocType)) {
HXLINE(  51)														bool c;
HXDLIN(  51)														if ((el1->nodeType != ::Xml_obj::Document)) {
HXLINE(  51)															c = (el1->nodeType == ::Xml_obj::Element);
            														}
            														else {
HXLINE(  51)															c = true;
            														}
HXDLIN(  51)														if (c) {
HXLINE(  51)															HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            														}
HXDLIN(  51)														c1 = ::Xml_obj::createDocType(el1->nodeValue);
            													}
            													else {
HXLINE(  51)														if ((el1->nodeType == ::Xml_obj::ProcessingInstruction)) {
HXLINE(  51)															bool c;
HXDLIN(  51)															if ((el1->nodeType != ::Xml_obj::Document)) {
HXLINE(  51)																c = (el1->nodeType == ::Xml_obj::Element);
            															}
            															else {
HXLINE(  51)																c = true;
            															}
HXDLIN(  51)															if (c) {
HXLINE(  51)																HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            															}
HXDLIN(  51)															c1 = ::Xml_obj::createProcessingInstruction(el1->nodeValue);
            														}
            														else {
HXLINE(  51)															if ((el1->nodeType == ::Xml_obj::Document)) {
HXLINE(  51)																c1 = ::Xml_obj::createDocument();
HXDLIN(  51)																{
HXLINE(  51)																	 ::Dynamic el = el1->elements();
HXDLIN(  51)																	while(( (bool)(el->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE(  51)																		 ::Xml el1 = ( ( ::Xml)(el->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXDLIN(  51)																		c1->addChild(::polymod::util::Util_obj::copyXml(el1,c1));
            																	}
            																}
            															}
            														}
            													}
            												}
            											}
            										}
            									}
HXDLIN(  51)									c1->parent = c;
HXDLIN(  51)									c->addChild(c1);
            								}
            							}
            						}
            						else {
HXLINE(  51)							if ((el1->nodeType == ::Xml_obj::PCData)) {
HXLINE(  51)								bool c1;
HXDLIN(  51)								if ((el1->nodeType != ::Xml_obj::Document)) {
HXLINE(  51)									c1 = (el1->nodeType == ::Xml_obj::Element);
            								}
            								else {
HXLINE(  51)									c1 = true;
            								}
HXDLIN(  51)								if (c1) {
HXLINE(  51)									HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            								}
HXDLIN(  51)								c = ::Xml_obj::createPCData(el1->nodeValue);
            							}
            							else {
HXLINE(  51)								if ((el1->nodeType == ::Xml_obj::CData)) {
HXLINE(  51)									bool c1;
HXDLIN(  51)									if ((el1->nodeType != ::Xml_obj::Document)) {
HXLINE(  51)										c1 = (el1->nodeType == ::Xml_obj::Element);
            									}
            									else {
HXLINE(  51)										c1 = true;
            									}
HXDLIN(  51)									if (c1) {
HXLINE(  51)										HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            									}
HXDLIN(  51)									c = ::Xml_obj::createCData(el1->nodeValue);
            								}
            								else {
HXLINE(  51)									if ((el1->nodeType == ::Xml_obj::Comment)) {
HXLINE(  51)										bool c1;
HXDLIN(  51)										if ((el1->nodeType != ::Xml_obj::Document)) {
HXLINE(  51)											c1 = (el1->nodeType == ::Xml_obj::Element);
            										}
            										else {
HXLINE(  51)											c1 = true;
            										}
HXDLIN(  51)										if (c1) {
HXLINE(  51)											HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            										}
HXDLIN(  51)										c = ::Xml_obj::createComment(el1->nodeValue);
            									}
            									else {
HXLINE(  51)										if ((el1->nodeType == ::Xml_obj::DocType)) {
HXLINE(  51)											bool c1;
HXDLIN(  51)											if ((el1->nodeType != ::Xml_obj::Document)) {
HXLINE(  51)												c1 = (el1->nodeType == ::Xml_obj::Element);
            											}
            											else {
HXLINE(  51)												c1 = true;
            											}
HXDLIN(  51)											if (c1) {
HXLINE(  51)												HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            											}
HXDLIN(  51)											c = ::Xml_obj::createDocType(el1->nodeValue);
            										}
            										else {
HXLINE(  51)											if ((el1->nodeType == ::Xml_obj::ProcessingInstruction)) {
HXLINE(  51)												bool c1;
HXDLIN(  51)												if ((el1->nodeType != ::Xml_obj::Document)) {
HXLINE(  51)													c1 = (el1->nodeType == ::Xml_obj::Element);
            												}
            												else {
HXLINE(  51)													c1 = true;
            												}
HXDLIN(  51)												if (c1) {
HXLINE(  51)													HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            												}
HXDLIN(  51)												c = ::Xml_obj::createProcessingInstruction(el1->nodeValue);
            											}
            											else {
HXLINE(  51)												if ((el1->nodeType == ::Xml_obj::Document)) {
HXLINE(  51)													c = ::Xml_obj::createDocument();
HXDLIN(  51)													{
HXLINE(  51)														 ::Dynamic el = el1->elements();
HXDLIN(  51)														while(( (bool)(el->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE(  51)															 ::Xml el1 = ( ( ::Xml)(el->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXDLIN(  51)															 ::Xml c1 = null();
HXDLIN(  51)															if ((el1->nodeType == ::Xml_obj::Element)) {
HXLINE(  51)																if ((el1->nodeType != ::Xml_obj::Element)) {
HXLINE(  51)																	HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, expected Element but found ",d8,90,8b,bb) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            																}
HXDLIN(  51)																c1 = ::Xml_obj::createElement(el1->nodeName);
HXDLIN(  51)																{
HXLINE(  51)																	 ::Dynamic att = el1->attributes();
HXDLIN(  51)																	while(( (bool)(att->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE(  51)																		::String att1 = ( (::String)(att->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXDLIN(  51)																		c1->set(att1,el1->get(att1));
            																	}
            																}
HXDLIN(  51)																{
HXLINE(  51)																	 ::Dynamic el = el1->elements();
HXDLIN(  51)																	while(( (bool)(el->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE(  51)																		 ::Xml el1 = ( ( ::Xml)(el->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXDLIN(  51)																		c1->addChild(::polymod::util::Util_obj::copyXml(el1,c1));
            																	}
            																}
            															}
            															else {
HXLINE(  51)																if ((el1->nodeType == ::Xml_obj::PCData)) {
HXLINE(  51)																	bool c;
HXDLIN(  51)																	if ((el1->nodeType != ::Xml_obj::Document)) {
HXLINE(  51)																		c = (el1->nodeType == ::Xml_obj::Element);
            																	}
            																	else {
HXLINE(  51)																		c = true;
            																	}
HXDLIN(  51)																	if (c) {
HXLINE(  51)																		HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            																	}
HXDLIN(  51)																	c1 = ::Xml_obj::createPCData(el1->nodeValue);
            																}
            																else {
HXLINE(  51)																	if ((el1->nodeType == ::Xml_obj::CData)) {
HXLINE(  51)																		bool c;
HXDLIN(  51)																		if ((el1->nodeType != ::Xml_obj::Document)) {
HXLINE(  51)																			c = (el1->nodeType == ::Xml_obj::Element);
            																		}
            																		else {
HXLINE(  51)																			c = true;
            																		}
HXDLIN(  51)																		if (c) {
HXLINE(  51)																			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            																		}
HXDLIN(  51)																		c1 = ::Xml_obj::createCData(el1->nodeValue);
            																	}
            																	else {
HXLINE(  51)																		if ((el1->nodeType == ::Xml_obj::Comment)) {
HXLINE(  51)																			bool c;
HXDLIN(  51)																			if ((el1->nodeType != ::Xml_obj::Document)) {
HXLINE(  51)																				c = (el1->nodeType == ::Xml_obj::Element);
            																			}
            																			else {
HXLINE(  51)																				c = true;
            																			}
HXDLIN(  51)																			if (c) {
HXLINE(  51)																				HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            																			}
HXDLIN(  51)																			c1 = ::Xml_obj::createComment(el1->nodeValue);
            																		}
            																		else {
HXLINE(  51)																			if ((el1->nodeType == ::Xml_obj::DocType)) {
HXLINE(  51)																				bool c;
HXDLIN(  51)																				if ((el1->nodeType != ::Xml_obj::Document)) {
HXLINE(  51)																					c = (el1->nodeType == ::Xml_obj::Element);
            																				}
            																				else {
HXLINE(  51)																					c = true;
            																				}
HXDLIN(  51)																				if (c) {
HXLINE(  51)																					HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            																				}
HXDLIN(  51)																				c1 = ::Xml_obj::createDocType(el1->nodeValue);
            																			}
            																			else {
HXLINE(  51)																				if ((el1->nodeType == ::Xml_obj::ProcessingInstruction)) {
HXLINE(  51)																					bool c;
HXDLIN(  51)																					if ((el1->nodeType != ::Xml_obj::Document)) {
HXLINE(  51)																						c = (el1->nodeType == ::Xml_obj::Element);
            																					}
            																					else {
HXLINE(  51)																						c = true;
            																					}
HXDLIN(  51)																					if (c) {
HXLINE(  51)																						HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, unexpected ",be,79,d5,11) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            																					}
HXDLIN(  51)																					c1 = ::Xml_obj::createProcessingInstruction(el1->nodeValue);
            																				}
            																				else {
HXLINE(  51)																					if ((el1->nodeType == ::Xml_obj::Document)) {
HXLINE(  51)																						c1 = ::Xml_obj::createDocument();
HXDLIN(  51)																						{
HXLINE(  51)																							 ::Dynamic el = el1->elements();
HXDLIN(  51)																							while(( (bool)(el->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE(  51)																								 ::Xml el1 = ( ( ::Xml)(el->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXDLIN(  51)																								c1->addChild(::polymod::util::Util_obj::copyXml(el1,c1));
            																							}
            																						}
            																					}
            																				}
            																			}
            																		}
            																	}
            																}
            															}
HXDLIN(  51)															c1->parent = c;
HXDLIN(  51)															c->addChild(c1);
            														}
            													}
            												}
            											}
            										}
            									}
            								}
            							}
            						}
HXDLIN(  51)						c->parent = parent;
HXDLIN(  51)						a->addChild(c);
            					}
            				}
            			}
            		}
HXLINE(  55)		if (attributes) {
HXLINE(  57)			 ::Dynamic att = b->attributes();
HXDLIN(  57)			while(( (bool)(att->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE(  57)				::String att1 = ( (::String)(att->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXLINE(  59)				a->set(att1,b->get(att1));
            			}
            		}
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(XMLMerge_obj,mergeXMLWork,(void))

int XMLMerge_obj::countNodes( ::Xml xml,::String nodeName){
            	HX_STACKFRAME(&_hx_pos_6834fb29b0c2424f_65_countNodes)
HXLINE(  66)		int i = 0;
HXLINE(  67)		{
HXLINE(  67)			 ::Dynamic el = xml->elementsNamed(nodeName);
HXDLIN(  67)			while(( (bool)(el->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE(  67)				 ::Xml el1 = ( ( ::Xml)(el->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXLINE(  69)				i = (i + 1);
            			}
            		}
HXLINE(  71)		return i;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(XMLMerge_obj,countNodes,return )

void XMLMerge_obj::mergeXML( ::Xml a, ::Xml b,::Array< ::String > allSigs, ::haxe::ds::StringMap mergeMap){
            	HX_STACKFRAME(&_hx_pos_6834fb29b0c2424f_75_mergeXML)
HXLINE(  76)		::String aName;
HXDLIN(  76)		if ((a->nodeType == 6)) {
HXLINE(  76)			aName = HX_("",00,00,00,00);
            		}
            		else {
HXLINE(  76)			if ((a->nodeType != ::Xml_obj::Element)) {
HXLINE(  76)				HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, expected Element but found ",d8,90,8b,bb) + ::_Xml::XmlType_Impl__obj::toString(a->nodeType))));
            			}
HXDLIN(  76)			aName = a->nodeName;
            		}
HXLINE(  77)		::String bName;
HXDLIN(  77)		if ((b->nodeType == 6)) {
HXLINE(  77)			bName = HX_("",00,00,00,00);
            		}
            		else {
HXLINE(  77)			if ((b->nodeType != ::Xml_obj::Element)) {
HXLINE(  77)				HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, expected Element but found ",d8,90,8b,bb) + ::_Xml::XmlType_Impl__obj::toString(b->nodeType))));
            			}
HXDLIN(  77)			bName = b->nodeName;
            		}
HXLINE(  79)		if ((aName != bName)) {
HXLINE(  80)			return;
            		}
HXLINE(  82)		::String aSig = ::polymod::format::XMLMerge_obj::getNodeSignature(a);
HXLINE(  83)		::String bSig = ::polymod::format::XMLMerge_obj::getNodeSignature(b);
HXLINE(  85)		if ((aSig != bSig)) {
HXLINE(  86)			return;
            		}
HXLINE(  88)		{
HXLINE(  88)			int _g = 0;
HXDLIN(  88)			while((_g < allSigs->length)){
HXLINE(  88)				::String sig = allSigs->__get(_g);
HXDLIN(  88)				_g = (_g + 1);
HXLINE(  90)				if ((sig.indexOf(aSig,null()) == 0)) {
HXLINE(  92)					if ((sig == aSig)) {
HXLINE(  95)						::Array< ::String > keyValues = ( (::Array< ::String >)(mergeMap->get(sig)) );
HXLINE(  96)						if (::hx::IsNull( keyValues )) {
HXLINE(  98)							bool _hx_tmp;
HXDLIN(  98)							if ((sig == HX_("",00,00,00,00))) {
HXLINE(  98)								_hx_tmp = (aSig == HX_("",00,00,00,00));
            							}
            							else {
HXLINE(  98)								_hx_tmp = false;
            							}
HXDLIN(  98)							if (_hx_tmp) {
HXLINE( 100)								bool _hx_tmp;
HXDLIN( 100)								if ((a->nodeType == 6)) {
HXLINE( 100)									_hx_tmp = (b->nodeType == 6);
            								}
            								else {
HXLINE( 100)									_hx_tmp = false;
            								}
HXDLIN( 100)								if (_hx_tmp) {
HXLINE( 102)									 ::Xml a1 = a->firstElement();
HXLINE( 103)									 ::Xml b1 = b->firstElement();
HXLINE( 104)									::polymod::format::XMLMerge_obj::mergeXML(a1,b1,allSigs,mergeMap);
            								}
            								else {
HXLINE( 108)									return;
            								}
            							}
            						}
HXLINE( 112)						bool _hx_tmp;
HXDLIN( 112)						bool _hx_tmp1;
HXDLIN( 112)						if (::hx::IsNotNull( keyValues )) {
HXLINE( 112)							_hx_tmp1 = (::hx::Mod(keyValues->length,2) == 0);
            						}
            						else {
HXLINE( 112)							_hx_tmp1 = false;
            						}
HXDLIN( 112)						if (_hx_tmp1) {
HXLINE( 112)							_hx_tmp = (keyValues->length >= 2);
            						}
            						else {
HXLINE( 112)							_hx_tmp = false;
            						}
HXDLIN( 112)						if (_hx_tmp) {
HXLINE( 114)							int _g = 0;
HXDLIN( 114)							int _g1 = ::Std_obj::_hx_int((( (Float)(keyValues->length) ) / ( (Float)(2) )));
HXDLIN( 114)							while((_g < _g1)){
HXLINE( 114)								_g = (_g + 1);
HXDLIN( 114)								int i = (_g - 1);
HXLINE( 116)								::String key = keyValues->__get((i * 2));
HXLINE( 117)								::String value = keyValues->__get(((i * 2) + 1));
HXLINE( 118)								::String aValue = a->get(key);
HXLINE( 119)								if ((aValue == value)) {
HXLINE( 121)									::String bValue = b->get(key);
HXLINE( 122)									::polymod::format::XMLMerge_obj::mergeXMLWork(a,b,null(),null());
            								}
            							}
            						}
            					}
            					else {
HXLINE( 130)						 ::Dynamic aEl = a->elements();
HXDLIN( 130)						while(( (bool)(aEl->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE( 130)							 ::Xml aEl1 = ( ( ::Xml)(aEl->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXLINE( 132)							{
HXLINE( 132)								 ::Dynamic bEl = b->elements();
HXDLIN( 132)								while(( (bool)(bEl->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE( 132)									 ::Xml bEl1 = ( ( ::Xml)(bEl->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXLINE( 134)									::polymod::format::XMLMerge_obj::mergeXML(aEl1,bEl1,allSigs,mergeMap);
            								}
            							}
            						}
            					}
            				}
            			}
            		}
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(XMLMerge_obj,mergeXML,(void))

void XMLMerge_obj::mergeXMLNodes( ::Xml a, ::Xml b){
            	HX_STACKFRAME(&_hx_pos_6834fb29b0c2424f_143_mergeXMLNodes)
HXLINE( 144)		if (::hx::IsNull( b )) {
HXLINE( 145)			return;
            		}
HXLINE( 147)		::Array< ::String > allSigs = ::Array_obj< ::String >::fromData( _hx_array_data_f83e6120_29,1);
HXLINE( 148)		 ::haxe::ds::StringMap bMap = ::polymod::format::XMLMerge_obj::getNodeMergeMap(b,allSigs);
HXLINE( 150)		::polymod::format::XMLMerge_obj::mergeXML(a,b,allSigs,bMap);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(XMLMerge_obj,mergeXMLNodes,(void))

 ::haxe::ds::StringMap XMLMerge_obj::getNodeMergeMap( ::Xml xml,::Array< ::String > addToArray){
            	HX_GC_STACKFRAME(&_hx_pos_6834fb29b0c2424f_154_getNodeMergeMap)
HXLINE( 155)		 ::haxe::ds::StringMap map =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
HXLINE( 157)		if (::hx::IsNull( xml )) {
HXLINE( 158)			return map;
            		}
HXLINE( 160)		{
HXLINE( 160)			 ::Dynamic el = xml->elements();
HXDLIN( 160)			while(( (bool)(el->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE( 160)				 ::Xml el1 = ( ( ::Xml)(el->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXLINE( 162)				if ((el1->nodeType != ::Xml_obj::Element)) {
HXLINE( 162)					HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, expected Element but found ",d8,90,8b,bb) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            				}
HXDLIN( 162)				if ((el1->nodeName == HX_("merge",b8,a2,c6,05))) {
HXLINE( 163)					continue;
            				}
HXLINE( 164)				 ::haxe::ds::StringMap subMap = ::polymod::format::XMLMerge_obj::getNodeMergeMap(el1,addToArray);
HXLINE( 165)				map = ::polymod::format::XMLMerge_obj::mergeMapsDestructively(map,subMap);
HXLINE( 166)				::String sig = ::polymod::format::XMLMerge_obj::getNodeSignature(el1);
HXLINE( 168)				bool _hx_tmp;
HXDLIN( 168)				if ((el1->nodeType != ::Xml_obj::Document)) {
HXLINE( 168)					_hx_tmp = (el1->nodeType != ::Xml_obj::Element);
            				}
            				else {
HXLINE( 168)					_hx_tmp = false;
            				}
HXDLIN( 168)				if (_hx_tmp) {
HXLINE( 168)					HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Invalid nodeType ",3b,e0,cb,e1) + ::_Xml::XmlType_Impl__obj::toString(el1->nodeType))));
            				}
HXDLIN( 168)				 ::Xml this1 = el1;
HXDLIN( 168)				 ::Xml f = this1;
HXLINE( 169)				if (::haxe::xml::_Access::HasNodeAccess_Impl__obj::resolve(f,HX_("merge",b8,a2,c6,05))) {
HXLINE( 171)					if ((map->exists(sig) == false)) {
HXLINE( 173)						map->set(sig,::Array_obj< ::String >::__new(0));
            					}
HXLINE( 175)					::Array< ::String > arr = ( (::Array< ::String >)(map->get(sig)) );
HXLINE( 177)					::String mergeKey;
HXDLIN( 177)					if (::haxe::xml::_Access::HasAttribAccess_Impl__obj::resolve(::haxe::xml::_Access::NodeAccess_Impl__obj::resolve(f,HX_("merge",b8,a2,c6,05)),HX_("key",9f,89,51,00))) {
HXLINE( 177)						mergeKey = ::haxe::xml::_Access::AttribAccess_Impl__obj::resolve(::haxe::xml::_Access::NodeAccess_Impl__obj::resolve(f,HX_("merge",b8,a2,c6,05)),HX_("key",9f,89,51,00));
            					}
            					else {
HXLINE( 177)						mergeKey = HX_("",00,00,00,00);
            					}
HXLINE( 178)					::String mergeKeyValue = ::haxe::xml::_Access::NodeAccess_Impl__obj::resolve(f,HX_("merge",b8,a2,c6,05))->get(mergeKey);
HXLINE( 180)					arr->push(mergeKey);
HXLINE( 181)					arr->push(mergeKeyValue);
HXLINE( 183)					if ((addToArray->indexOf(sig,null()) == -1)) {
HXLINE( 185)						addToArray->push(sig);
            					}
            				}
            			}
            		}
HXLINE( 190)		return map;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(XMLMerge_obj,getNodeMergeMap,return )

::String XMLMerge_obj::getNodeSignature( ::Xml xml){
            	HX_STACKFRAME(&_hx_pos_6834fb29b0c2424f_194_getNodeSignature)
HXLINE( 195)		::Array< ::String > arr = ::Array_obj< ::String >::__new(0);
HXLINE( 196)		 ::Xml parent = xml;
HXLINE( 197)		while(true){
HXLINE( 197)			bool _hx_tmp;
HXDLIN( 197)			if (::hx::IsNotNull( parent )) {
HXLINE( 197)				_hx_tmp = (parent->nodeType == 0);
            			}
            			else {
HXLINE( 197)				_hx_tmp = false;
            			}
HXDLIN( 197)			if (!(_hx_tmp)) {
HXLINE( 197)				goto _hx_goto_32;
            			}
HXLINE( 199)			if ((parent->nodeType != ::Xml_obj::Element)) {
HXLINE( 199)				HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Bad node type, expected Element but found ",d8,90,8b,bb) + ::_Xml::XmlType_Impl__obj::toString(parent->nodeType))));
            			}
HXDLIN( 199)			arr->push(parent->nodeName);
HXLINE( 200)			if ((parent->nodeType == 0)) {
HXLINE( 202)				parent = parent->parent;
            			}
            			else {
HXLINE( 206)				parent = null();
            			}
            		}
            		_hx_goto_32:;
HXLINE( 209)		::String str = HX_("",00,00,00,00);
HXLINE( 210)		{
HXLINE( 210)			int _g = 0;
HXDLIN( 210)			int _g1 = arr->length;
HXDLIN( 210)			while((_g < _g1)){
HXLINE( 210)				_g = (_g + 1);
HXDLIN( 210)				int i = (_g - 1);
HXLINE( 212)				int j = ((arr->length - 1) - i);
HXLINE( 213)				str = (str + arr->__get(j));
HXLINE( 214)				if ((i != (arr->length - 1))) {
HXLINE( 216)					str = (str + HX_(".",2e,00,00,00));
            				}
            			}
            		}
HXLINE( 219)		return str;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(XMLMerge_obj,getNodeSignature,return )

 ::haxe::ds::StringMap XMLMerge_obj::mergeMapsDestructively( ::haxe::ds::StringMap a, ::haxe::ds::StringMap b){
            	HX_GC_STACKFRAME(&_hx_pos_6834fb29b0c2424f_223_mergeMapsDestructively)
HXLINE( 224)		if (::hx::IsNull( a )) {
HXLINE( 225)			a =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
            		}
HXLINE( 226)		if (::hx::IsNull( b )) {
HXLINE( 227)			return a;
            		}
HXLINE( 228)		{
HXLINE( 228)			 ::Dynamic bkey = b->keys();
HXDLIN( 228)			while(( (bool)(bkey->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE( 228)				::String bkey1 = ( (::String)(bkey->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXLINE( 230)				if (a->exists(bkey1)) {
HXLINE( 232)					::Array< ::String > aArr = ( (::Array< ::String >)(a->get(bkey1)) );
HXLINE( 233)					::Array< ::String > bArr = ( (::Array< ::String >)(b->get(bkey1)) );
HXLINE( 234)					{
HXLINE( 234)						int _g = 0;
HXDLIN( 234)						while((_g < bArr->length)){
HXLINE( 234)							::String bVal = bArr->__get(_g);
HXDLIN( 234)							_g = (_g + 1);
HXLINE( 236)							aArr->push(bVal);
            						}
            					}
            				}
            				else {
HXLINE( 241)					::Array< ::String > bArr = ( (::Array< ::String >)(b->get(bkey1)) );
HXLINE( 242)					a->set(bkey1,bArr);
HXLINE( 243)					b->remove(bkey1);
            				}
            			}
            		}
HXLINE( 246)		return a;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(XMLMerge_obj,mergeMapsDestructively,return )


XMLMerge_obj::XMLMerge_obj()
{
}

bool XMLMerge_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"mergeXML") ) { outValue = mergeXML_dyn(); return true; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"countNodes") ) { outValue = countNodes_dyn(); return true; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"mergeXMLWork") ) { outValue = mergeXMLWork_dyn(); return true; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"mergeXMLNodes") ) { outValue = mergeXMLNodes_dyn(); return true; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"getNodeMergeMap") ) { outValue = getNodeMergeMap_dyn(); return true; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getNodeSignature") ) { outValue = getNodeSignature_dyn(); return true; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"mergeMapsDestructively") ) { outValue = mergeMapsDestructively_dyn(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *XMLMerge_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *XMLMerge_obj_sStaticStorageInfo = 0;
#endif

::hx::Class XMLMerge_obj::__mClass;

static ::String XMLMerge_obj_sStaticFields[] = {
	HX_("mergeXMLWork",70,83,99,f8),
	HX_("countNodes",e2,14,12,6a),
	HX_("mergeXML",ff,e9,6c,e8),
	HX_("mergeXMLNodes",b2,a1,13,5f),
	HX_("getNodeMergeMap",9c,90,07,5c),
	HX_("getNodeSignature",20,d2,58,d0),
	HX_("mergeMapsDestructively",60,c5,6f,d9),
	::String(null())
};

void XMLMerge_obj::__register()
{
	XMLMerge_obj _hx_dummy;
	XMLMerge_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("polymod.format.XMLMerge",20,61,3e,f8);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &XMLMerge_obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(XMLMerge_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< XMLMerge_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = XMLMerge_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = XMLMerge_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace polymod
} // end namespace format
