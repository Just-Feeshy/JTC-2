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
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_haxe_format_JsonParser
#include <haxe/format/JsonParser.h>
#endif
#ifndef INCLUDED_haxe_format_JsonPrinter
#include <haxe/format/JsonPrinter.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
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
#ifndef INCLUDED_polymod_format_JsonHelp
#include <polymod/format/JsonHelp.h>
#endif
#ifndef INCLUDED_polymod_util_SemanticVersion
#include <polymod/util/SemanticVersion.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_bf85bbb123aa7472_649_new,"polymod.ModMetadata","new",0xb8bfb12b,"polymod.ModMetadata.new","polymod/Polymod.hx",649,0xd80c6d61)
HX_LOCAL_STACK_FRAME(_hx_pos_bf85bbb123aa7472_632_get_author,"polymod.ModMetadata","get_author",0xddd3f8e9,"polymod.ModMetadata.get_author","polymod/Polymod.hx",632,0xd80c6d61)
HX_LOCAL_STACK_FRAME(_hx_pos_bf85bbb123aa7472_641_set_author,"polymod.ModMetadata","set_author",0xe151975d,"polymod.ModMetadata.set_author","polymod/Polymod.hx",641,0xd80c6d61)
HX_LOCAL_STACK_FRAME(_hx_pos_bf85bbb123aa7472_654_toJsonStr,"polymod.ModMetadata","toJsonStr",0xb10a2a39,"polymod.ModMetadata.toJsonStr","polymod/Polymod.hx",654,0xd80c6d61)
HX_LOCAL_STACK_FRAME(_hx_pos_bf85bbb123aa7472_675_fromJsonStr,"polymod.ModMetadata","fromJsonStr",0x1a576eea,"polymod.ModMetadata.fromJsonStr","polymod/Polymod.hx",675,0xd80c6d61)
namespace polymod{

void ModMetadata_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_bf85bbb123aa7472_649_new)
            	}

Dynamic ModMetadata_obj::__CreateEmpty() { return new ModMetadata_obj; }

void *ModMetadata_obj::_hx_vtable = 0;

Dynamic ModMetadata_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< ModMetadata_obj > _hx_result = new ModMetadata_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool ModMetadata_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x29416a7b;
}

::String ModMetadata_obj::get_author(){
            	HX_STACKFRAME(&_hx_pos_bf85bbb123aa7472_632_get_author)
HXLINE( 633)		if ((this->contributors->length > 0)) {
HXLINE( 635)			return ( (::String)(this->contributors->__get(0)->__Field(HX_("name",4b,72,ff,48),::hx::paccDynamic)) );
            		}
HXLINE( 637)		return this->_author;
            	}


HX_DEFINE_DYNAMIC_FUNC0(ModMetadata_obj,get_author,return )

::String ModMetadata_obj::set_author(::String v){
            	HX_STACKFRAME(&_hx_pos_bf85bbb123aa7472_641_set_author)
HXLINE( 642)		this->_author = v;
HXLINE( 643)		return v;
            	}


HX_DEFINE_DYNAMIC_FUNC1(ModMetadata_obj,set_author,return )

::String ModMetadata_obj::toJsonStr(){
            	HX_STACKFRAME(&_hx_pos_bf85bbb123aa7472_654_toJsonStr)
HXLINE( 655)		 ::Dynamic json =  ::Dynamic(::hx::Anon_obj::Create(0));
HXLINE( 656)		::Reflect_obj::setField(json,HX_("title",98,15,3b,10),this->title);
HXLINE( 657)		::Reflect_obj::setField(json,HX_("description",fc,08,1d,5f),this->description);
HXLINE( 658)		::Reflect_obj::setField(json,HX_("author",8b,ea,7b,73),this->_author);
HXLINE( 659)		::Reflect_obj::setField(json,HX_("contributors",38,1c,7c,e3),this->contributors);
HXLINE( 660)		::Reflect_obj::setField(json,HX_("homepage",ee,9f,fd,4a),this->homepage);
HXLINE( 661)		::Reflect_obj::setField(json,HX_("api_version",33,67,89,30),this->apiVersion->toString());
HXLINE( 662)		::Reflect_obj::setField(json,HX_("mod_version",5b,e9,f4,5b),this->modVersion->toString());
HXLINE( 663)		::Reflect_obj::setField(json,HX_("license",81,d3,48,ca),this->license);
HXLINE( 664)		::Reflect_obj::setField(json,HX_("license_ref",55,46,81,a0),this->licenseRef);
HXLINE( 665)		 ::Dynamic meta =  ::Dynamic(::hx::Anon_obj::Create(0));
HXLINE( 666)		{
HXLINE( 666)			 ::Dynamic key = this->metaData->keys();
HXDLIN( 666)			while(( (bool)(key->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE( 666)				::String key1 = ( (::String)(key->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXLINE( 668)				::Reflect_obj::setField(meta,key1,this->metaData->get(key1));
            			}
            		}
HXLINE( 670)		::Reflect_obj::setField(json,HX_("metadata",6f,e7,19,40),meta);
HXLINE( 671)		 ::Dynamic replacer = null();
HXDLIN( 671)		return ::haxe::format::JsonPrinter_obj::print(json,replacer,HX_("    ",00,38,3f,15));
            	}


HX_DEFINE_DYNAMIC_FUNC0(ModMetadata_obj,toJsonStr,return )

 ::polymod::ModMetadata ModMetadata_obj::fromJsonStr(::String str){
            	HX_GC_STACKFRAME(&_hx_pos_bf85bbb123aa7472_675_fromJsonStr)
HXLINE( 676)		bool _hx_tmp;
HXDLIN( 676)		if (::hx::IsNotNull( str )) {
HXLINE( 676)			_hx_tmp = (str == HX_("",00,00,00,00));
            		}
            		else {
HXLINE( 676)			_hx_tmp = true;
            		}
HXDLIN( 676)		if (_hx_tmp) {
HXLINE( 678)			::polymod::Polymod_obj::error(HX_("parse_mod_meta",6e,d9,47,43),HX_("Error parsing mod metadata file, was null or empty.",17,3e,d7,21),null());
HXLINE( 679)			return null();
            		}
HXLINE( 682)		 ::Dynamic json = null();
HXLINE( 683)		try {
            			HX_STACK_CATCHABLE( ::Dynamic, 0);
HXLINE( 685)			json =  ::haxe::format::JsonParser_obj::__alloc( HX_CTX ,str)->doParse();
            		} catch( ::Dynamic _hx_e) {
            			if (_hx_e.IsClass<  ::Dynamic >() ){
            				HX_STACK_BEGIN_CATCH
            				 ::Dynamic _g = _hx_e;
HXLINE( 687)				{
HXLINE( 687)					null();
            				}
HXDLIN( 687)				 ::Dynamic msg = ::haxe::Exception_obj::caught(_g)->unwrap();
HXLINE( 689)				::polymod::Polymod_obj::error(HX_("parse_mod_meta",6e,d9,47,43),((HX_("Error parsing mod metadata file: (",9b,f8,66,65) + ::Std_obj::string(msg)) + HX_(")",29,00,00,00)),null());
HXLINE( 690)				return null();
            			}
            			else {
            				HX_STACK_DO_THROW(_hx_e);
            			}
            		}
HXLINE( 693)		 ::polymod::ModMetadata m =  ::polymod::ModMetadata_obj::__alloc( HX_CTX );
HXLINE( 694)		m->title = ::polymod::format::JsonHelp_obj::str(json,HX_("title",98,15,3b,10),null());
HXLINE( 695)		m->description = ::polymod::format::JsonHelp_obj::str(json,HX_("description",fc,08,1d,5f),null());
HXLINE( 696)		m->_author = ::polymod::format::JsonHelp_obj::str(json,HX_("author",8b,ea,7b,73),null());
HXLINE( 697)		m->contributors = ::polymod::format::JsonHelp_obj::arrType(json,HX_("contributors",38,1c,7c,e3),null());
HXLINE( 698)		m->homepage = ::polymod::format::JsonHelp_obj::str(json,HX_("homepage",ee,9f,fd,4a),null());
HXLINE( 699)		::String apiVersionStr = ::polymod::format::JsonHelp_obj::str(json,HX_("api_version",33,67,89,30),null());
HXLINE( 700)		::String modVersionStr = ::polymod::format::JsonHelp_obj::str(json,HX_("mod_version",5b,e9,f4,5b),null());
HXLINE( 701)		try {
            			HX_STACK_CATCHABLE( ::Dynamic, 0);
HXLINE( 703)			m->apiVersion = ::polymod::util::SemanticVersion_obj::fromString(apiVersionStr);
            		} catch( ::Dynamic _hx_e) {
            			if (_hx_e.IsClass<  ::Dynamic >() ){
            				HX_STACK_BEGIN_CATCH
            				 ::Dynamic _g = _hx_e;
HXLINE( 705)				{
HXLINE( 705)					null();
            				}
HXDLIN( 705)				 ::Dynamic msg = ::haxe::Exception_obj::caught(_g)->unwrap();
HXLINE( 707)				::String _hx_tmp = ((HX_("Error parsing API version: (",f8,97,84,65) + ::Std_obj::string(msg)) + HX_(") ",d7,23,00,00));
HXDLIN( 707)				::polymod::Polymod_obj::error(HX_("parse_mod_api_version",aa,ef,f5,4c),(((_hx_tmp + ::polymod::PolymodConfig_obj::get_modMetadataFile()) + HX_(" was ",f7,f2,c4,bb)) + str),null());
HXLINE( 708)				return null();
            			}
            			else {
            				HX_STACK_DO_THROW(_hx_e);
            			}
            		}
HXLINE( 710)		try {
            			HX_STACK_CATCHABLE( ::Dynamic, 0);
HXLINE( 712)			m->modVersion = ::polymod::util::SemanticVersion_obj::fromString(modVersionStr);
            		} catch( ::Dynamic _hx_e) {
            			if (_hx_e.IsClass<  ::Dynamic >() ){
            				HX_STACK_BEGIN_CATCH
            				 ::Dynamic _g = _hx_e;
HXLINE( 714)				{
HXLINE( 714)					null();
            				}
HXDLIN( 714)				 ::Dynamic msg = ::haxe::Exception_obj::caught(_g)->unwrap();
HXLINE( 716)				::String _hx_tmp = ((HX_("Error parsing mod version: (",b0,ae,ce,3c) + ::Std_obj::string(msg)) + HX_(") ",d7,23,00,00));
HXDLIN( 716)				::polymod::Polymod_obj::error(HX_("parse_mod_version",0f,28,c5,d6),(((_hx_tmp + ::polymod::PolymodConfig_obj::get_modMetadataFile()) + HX_(" was ",f7,f2,c4,bb)) + str),null());
HXLINE( 717)				return null();
            			}
            			else {
            				HX_STACK_DO_THROW(_hx_e);
            			}
            		}
HXLINE( 719)		m->license = ::polymod::format::JsonHelp_obj::str(json,HX_("license",81,d3,48,ca),null());
HXLINE( 720)		m->licenseRef = ::polymod::format::JsonHelp_obj::str(json,HX_("license_ref",55,46,81,a0),null());
HXLINE( 721)		m->metaData = ::polymod::format::JsonHelp_obj::mapStr(json,HX_("metadata",6f,e7,19,40));
HXLINE( 722)		return m;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ModMetadata_obj,fromJsonStr,return )


::hx::ObjectPtr< ModMetadata_obj > ModMetadata_obj::__new() {
	::hx::ObjectPtr< ModMetadata_obj > __this = new ModMetadata_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< ModMetadata_obj > ModMetadata_obj::__alloc(::hx::Ctx *_hx_ctx) {
	ModMetadata_obj *__this = (ModMetadata_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(ModMetadata_obj), true, "polymod.ModMetadata"));
	*(void **)__this = ModMetadata_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

ModMetadata_obj::ModMetadata_obj()
{
}

void ModMetadata_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ModMetadata);
	HX_MARK_MEMBER_NAME(id,"id");
	HX_MARK_MEMBER_NAME(title,"title");
	HX_MARK_MEMBER_NAME(description,"description");
	HX_MARK_MEMBER_NAME(homepage,"homepage");
	HX_MARK_MEMBER_NAME(apiVersion,"apiVersion");
	HX_MARK_MEMBER_NAME(modVersion,"modVersion");
	HX_MARK_MEMBER_NAME(license,"license");
	HX_MARK_MEMBER_NAME(licenseRef,"licenseRef");
	HX_MARK_MEMBER_NAME(icon,"icon");
	HX_MARK_MEMBER_NAME(metaData,"metaData");
	HX_MARK_MEMBER_NAME(_author,"_author");
	HX_MARK_MEMBER_NAME(contributors,"contributors");
	HX_MARK_END_CLASS();
}

void ModMetadata_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(id,"id");
	HX_VISIT_MEMBER_NAME(title,"title");
	HX_VISIT_MEMBER_NAME(description,"description");
	HX_VISIT_MEMBER_NAME(homepage,"homepage");
	HX_VISIT_MEMBER_NAME(apiVersion,"apiVersion");
	HX_VISIT_MEMBER_NAME(modVersion,"modVersion");
	HX_VISIT_MEMBER_NAME(license,"license");
	HX_VISIT_MEMBER_NAME(licenseRef,"licenseRef");
	HX_VISIT_MEMBER_NAME(icon,"icon");
	HX_VISIT_MEMBER_NAME(metaData,"metaData");
	HX_VISIT_MEMBER_NAME(_author,"_author");
	HX_VISIT_MEMBER_NAME(contributors,"contributors");
}

::hx::Val ModMetadata_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return ::hx::Val( id ); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"icon") ) { return ::hx::Val( icon ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"title") ) { return ::hx::Val( title ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"author") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_author() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"license") ) { return ::hx::Val( license ); }
		if (HX_FIELD_EQ(inName,"_author") ) { return ::hx::Val( _author ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"homepage") ) { return ::hx::Val( homepage ); }
		if (HX_FIELD_EQ(inName,"metaData") ) { return ::hx::Val( metaData ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"toJsonStr") ) { return ::hx::Val( toJsonStr_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"apiVersion") ) { return ::hx::Val( apiVersion ); }
		if (HX_FIELD_EQ(inName,"modVersion") ) { return ::hx::Val( modVersion ); }
		if (HX_FIELD_EQ(inName,"licenseRef") ) { return ::hx::Val( licenseRef ); }
		if (HX_FIELD_EQ(inName,"get_author") ) { return ::hx::Val( get_author_dyn() ); }
		if (HX_FIELD_EQ(inName,"set_author") ) { return ::hx::Val( set_author_dyn() ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"description") ) { return ::hx::Val( description ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"contributors") ) { return ::hx::Val( contributors ); }
	}
	return super::__Field(inName,inCallProp);
}

bool ModMetadata_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"fromJsonStr") ) { outValue = fromJsonStr_dyn(); return true; }
	}
	return false;
}

::hx::Val ModMetadata_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { id=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"icon") ) { icon=inValue.Cast<  ::haxe::io::Bytes >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"title") ) { title=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"author") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_author(inValue.Cast< ::String >()) ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"license") ) { license=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_author") ) { _author=inValue.Cast< ::String >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"homepage") ) { homepage=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"metaData") ) { metaData=inValue.Cast<  ::haxe::ds::StringMap >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"apiVersion") ) { apiVersion=inValue.Cast<  ::polymod::util::SemanticVersion >(); return inValue; }
		if (HX_FIELD_EQ(inName,"modVersion") ) { modVersion=inValue.Cast<  ::polymod::util::SemanticVersion >(); return inValue; }
		if (HX_FIELD_EQ(inName,"licenseRef") ) { licenseRef=inValue.Cast< ::String >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"description") ) { description=inValue.Cast< ::String >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"contributors") ) { contributors=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ModMetadata_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("id",db,5b,00,00));
	outFields->push(HX_("title",98,15,3b,10));
	outFields->push(HX_("description",fc,08,1d,5f));
	outFields->push(HX_("homepage",ee,9f,fd,4a));
	outFields->push(HX_("apiVersion",9e,39,c9,e5));
	outFields->push(HX_("modVersion",76,34,59,f8));
	outFields->push(HX_("license",81,d3,48,ca));
	outFields->push(HX_("licenseRef",52,24,40,a0));
	outFields->push(HX_("icon",79,e7,b2,45));
	outFields->push(HX_("metaData",8f,13,f3,2a));
	outFields->push(HX_("author",8b,ea,7b,73));
	outFields->push(HX_("_author",2a,fc,f2,e1));
	outFields->push(HX_("contributors",38,1c,7c,e3));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo ModMetadata_obj_sMemberStorageInfo[] = {
	{::hx::fsString,(int)offsetof(ModMetadata_obj,id),HX_("id",db,5b,00,00)},
	{::hx::fsString,(int)offsetof(ModMetadata_obj,title),HX_("title",98,15,3b,10)},
	{::hx::fsString,(int)offsetof(ModMetadata_obj,description),HX_("description",fc,08,1d,5f)},
	{::hx::fsString,(int)offsetof(ModMetadata_obj,homepage),HX_("homepage",ee,9f,fd,4a)},
	{::hx::fsObject /*  ::polymod::util::SemanticVersion */ ,(int)offsetof(ModMetadata_obj,apiVersion),HX_("apiVersion",9e,39,c9,e5)},
	{::hx::fsObject /*  ::polymod::util::SemanticVersion */ ,(int)offsetof(ModMetadata_obj,modVersion),HX_("modVersion",76,34,59,f8)},
	{::hx::fsString,(int)offsetof(ModMetadata_obj,license),HX_("license",81,d3,48,ca)},
	{::hx::fsString,(int)offsetof(ModMetadata_obj,licenseRef),HX_("licenseRef",52,24,40,a0)},
	{::hx::fsObject /*  ::haxe::io::Bytes */ ,(int)offsetof(ModMetadata_obj,icon),HX_("icon",79,e7,b2,45)},
	{::hx::fsObject /*  ::haxe::ds::StringMap */ ,(int)offsetof(ModMetadata_obj,metaData),HX_("metaData",8f,13,f3,2a)},
	{::hx::fsString,(int)offsetof(ModMetadata_obj,_author),HX_("_author",2a,fc,f2,e1)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(ModMetadata_obj,contributors),HX_("contributors",38,1c,7c,e3)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *ModMetadata_obj_sStaticStorageInfo = 0;
#endif

static ::String ModMetadata_obj_sMemberFields[] = {
	HX_("id",db,5b,00,00),
	HX_("title",98,15,3b,10),
	HX_("description",fc,08,1d,5f),
	HX_("homepage",ee,9f,fd,4a),
	HX_("apiVersion",9e,39,c9,e5),
	HX_("modVersion",76,34,59,f8),
	HX_("license",81,d3,48,ca),
	HX_("licenseRef",52,24,40,a0),
	HX_("icon",79,e7,b2,45),
	HX_("metaData",8f,13,f3,2a),
	HX_("_author",2a,fc,f2,e1),
	HX_("get_author",54,5a,03,64),
	HX_("set_author",c8,f8,80,67),
	HX_("contributors",38,1c,7c,e3),
	HX_("toJsonStr",2e,1f,f1,94),
	::String(null()) };

::hx::Class ModMetadata_obj::__mClass;

static ::String ModMetadata_obj_sStaticFields[] = {
	HX_("fromJsonStr",1f,4b,9d,fd),
	::String(null())
};

void ModMetadata_obj::__register()
{
	ModMetadata_obj _hx_dummy;
	ModMetadata_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("polymod.ModMetadata",b9,3f,d7,1e);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &ModMetadata_obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(ModMetadata_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(ModMetadata_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< ModMetadata_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = ModMetadata_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = ModMetadata_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace polymod
