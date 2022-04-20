#include <hxcpp.h>

#ifndef INCLUDED_Paths
#include <Paths.h>
#endif
#ifndef INCLUDED_Song
#include <Song.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_haxe_Exception
#include <haxe/Exception.h>
#endif
#ifndef INCLUDED_haxe_format_JsonParser
#include <haxe/format/JsonParser.h>
#endif
#ifndef INCLUDED_lime_utils_Assets
#include <lime/utils/Assets.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_4e288e2989890fc6_44_new,"Song","new",0xfb6c8f67,"Song.new","Song.hx",44,0x775e99e9)
HX_LOCAL_STACK_FRAME(_hx_pos_4e288e2989890fc6_72_loadFromJson,"Song","loadFromJson",0x10fda511,"Song.loadFromJson","Song.hx",72,0x775e99e9)
HX_LOCAL_STACK_FRAME(_hx_pos_4e288e2989890fc6_106_getRawJSON,"Song","getRawJSON",0x9dd4b9f3,"Song.getRawJSON","Song.hx",106,0x775e99e9)
HX_LOCAL_STACK_FRAME(_hx_pos_4e288e2989890fc6_110_parseJSONshit,"Song","parseJSONshit",0x7c7ff6e2,"Song.parseJSONshit","Song.hx",110,0x775e99e9)

void Song_obj::__construct(::String song,::Array< ::Dynamic> notes,int bpm,int fps){
            	HX_STACKFRAME(&_hx_pos_4e288e2989890fc6_44_new)
HXLINE(  51)		this->speed = ((Float)1);
HXLINE(  50)		this->needsVoices = true;
HXLINE(  65)		this->song = song;
HXLINE(  66)		this->notes = notes;
HXLINE(  67)		this->bpm = bpm;
HXLINE(  68)		this->fps = fps;
            	}

Dynamic Song_obj::__CreateEmpty() { return new Song_obj; }

void *Song_obj::_hx_vtable = 0;

Dynamic Song_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Song_obj > _hx_result = new Song_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return _hx_result;
}

bool Song_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x0b844619;
}

 ::Dynamic Song_obj::loadFromJson(::String jsonInput,::String folder, ::Dynamic __o_ifPlayState){
            		 ::Dynamic ifPlayState = __o_ifPlayState;
            		if (::hx::IsNull(__o_ifPlayState)) ifPlayState = true;
            	HX_STACKFRAME(&_hx_pos_4e288e2989890fc6_72_loadFromJson)
HXLINE(  73)		::String rawJson;
HXLINE(  75)		if (( (bool)(ifPlayState) )) {
HXLINE(  76)			::String key = (folder.toLowerCase() + HX_("/",2f,00,00,00));
HXDLIN(  76)			::String key1 = (key + jsonInput.toLowerCase());
HXDLIN(  76)			::String library = null();
HXDLIN(  76)			::String rawJson1;
HXDLIN(  76)			if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath(((HX_("data/",c5,0e,88,d4) + key1) + HX_(".json",56,f1,d6,c2)),HX_("TEXT",ad,94,ba,37),library),null())) {
HXLINE(  76)				rawJson1 = ::Paths_obj::getPath(((HX_("data/",c5,0e,88,d4) + key1) + HX_(".json",56,f1,d6,c2)),HX_("TEXT",ad,94,ba,37),library);
            			}
            			else {
HXLINE(  76)				HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate json file - ",13,f3,9f,29) + key1)));
            			}
HXDLIN(  76)			rawJson = ::StringTools_obj::trim(::lime::utils::Assets_obj::getText(rawJson1));
            		}
            		else {
HXLINE(  78)			rawJson = ::StringTools_obj::trim(::lime::utils::Assets_obj::getText(::Paths_obj::getPath((((folder.toLowerCase() + HX_("/",2f,00,00,00)) + jsonInput) + HX_(".json",56,f1,d6,c2)),HX_("TEXT",ad,94,ba,37),null())));
            		}
HXLINE(  80)		while(!(::StringTools_obj::endsWith(rawJson,HX_("}",7d,00,00,00)))){
HXLINE(  82)			rawJson = rawJson.substr(0,(rawJson.length - 1));
            		}
HXLINE( 102)		return ::Song_obj::parseJSONshit(rawJson);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Song_obj,loadFromJson,return )

::String Song_obj::getRawJSON(::String jsonInput,::String folder){
            	HX_STACKFRAME(&_hx_pos_4e288e2989890fc6_106_getRawJSON)
HXDLIN( 106)		::String key = (folder.toLowerCase() + HX_("/",2f,00,00,00));
HXDLIN( 106)		::String key1 = (key + jsonInput.toLowerCase());
HXDLIN( 106)		::String library = null();
HXDLIN( 106)		::String _hx_tmp;
HXDLIN( 106)		if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath(((HX_("data/",c5,0e,88,d4) + key1) + HX_(".json",56,f1,d6,c2)),HX_("TEXT",ad,94,ba,37),library),null())) {
HXDLIN( 106)			_hx_tmp = ::Paths_obj::getPath(((HX_("data/",c5,0e,88,d4) + key1) + HX_(".json",56,f1,d6,c2)),HX_("TEXT",ad,94,ba,37),library);
            		}
            		else {
HXDLIN( 106)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate json file - ",13,f3,9f,29) + key1)));
            		}
HXDLIN( 106)		return ::StringTools_obj::trim(::lime::utils::Assets_obj::getText(_hx_tmp));
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Song_obj,getRawJSON,return )

 ::Dynamic Song_obj::parseJSONshit(::String rawJson){
            	HX_GC_STACKFRAME(&_hx_pos_4e288e2989890fc6_110_parseJSONshit)
HXLINE( 111)		 ::Dynamic swagShit =  ::haxe::format::JsonParser_obj::__alloc( HX_CTX ,rawJson)->doParse()->__Field(HX_("song",d5,23,58,4c),::hx::paccDynamic);
HXLINE( 112)		swagShit->__SetField(HX_("validScore",b6,dc,18,c7),true,::hx::paccDynamic);
HXLINE( 113)		return swagShit;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Song_obj,parseJSONshit,return )


Song_obj::Song_obj()
{
}

void Song_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Song);
	HX_MARK_MEMBER_NAME(song,"song");
	HX_MARK_MEMBER_NAME(notes,"notes");
	HX_MARK_MEMBER_NAME(modifiers,"modifiers");
	HX_MARK_MEMBER_NAME(bpm,"bpm");
	HX_MARK_MEMBER_NAME(needsVoices,"needsVoices");
	HX_MARK_MEMBER_NAME(speed,"speed");
	HX_MARK_MEMBER_NAME(colorMapping,"colorMapping");
	HX_MARK_MEMBER_NAME(fps,"fps");
	HX_MARK_MEMBER_NAME(player1X,"player1X");
	HX_MARK_MEMBER_NAME(player1Y,"player1Y");
	HX_MARK_MEMBER_NAME(player2X,"player2X");
	HX_MARK_MEMBER_NAME(player2Y,"player2Y");
	HX_MARK_MEMBER_NAME(fifthKey,"fifthKey");
	HX_MARK_END_CLASS();
}

void Song_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(song,"song");
	HX_VISIT_MEMBER_NAME(notes,"notes");
	HX_VISIT_MEMBER_NAME(modifiers,"modifiers");
	HX_VISIT_MEMBER_NAME(bpm,"bpm");
	HX_VISIT_MEMBER_NAME(needsVoices,"needsVoices");
	HX_VISIT_MEMBER_NAME(speed,"speed");
	HX_VISIT_MEMBER_NAME(colorMapping,"colorMapping");
	HX_VISIT_MEMBER_NAME(fps,"fps");
	HX_VISIT_MEMBER_NAME(player1X,"player1X");
	HX_VISIT_MEMBER_NAME(player1Y,"player1Y");
	HX_VISIT_MEMBER_NAME(player2X,"player2X");
	HX_VISIT_MEMBER_NAME(player2Y,"player2Y");
	HX_VISIT_MEMBER_NAME(fifthKey,"fifthKey");
}

::hx::Val Song_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"bpm") ) { return ::hx::Val( bpm ); }
		if (HX_FIELD_EQ(inName,"fps") ) { return ::hx::Val( fps ); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"song") ) { return ::hx::Val( song ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"notes") ) { return ::hx::Val( notes ); }
		if (HX_FIELD_EQ(inName,"speed") ) { return ::hx::Val( speed ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"player1X") ) { return ::hx::Val( player1X ); }
		if (HX_FIELD_EQ(inName,"player1Y") ) { return ::hx::Val( player1Y ); }
		if (HX_FIELD_EQ(inName,"player2X") ) { return ::hx::Val( player2X ); }
		if (HX_FIELD_EQ(inName,"player2Y") ) { return ::hx::Val( player2Y ); }
		if (HX_FIELD_EQ(inName,"fifthKey") ) { return ::hx::Val( fifthKey ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"modifiers") ) { return ::hx::Val( modifiers ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"needsVoices") ) { return ::hx::Val( needsVoices ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"colorMapping") ) { return ::hx::Val( colorMapping ); }
	}
	return super::__Field(inName,inCallProp);
}

bool Song_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"getRawJSON") ) { outValue = getRawJSON_dyn(); return true; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"loadFromJson") ) { outValue = loadFromJson_dyn(); return true; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"parseJSONshit") ) { outValue = parseJSONshit_dyn(); return true; }
	}
	return false;
}

::hx::Val Song_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"bpm") ) { bpm=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fps") ) { fps=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"song") ) { song=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"notes") ) { notes=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
		if (HX_FIELD_EQ(inName,"speed") ) { speed=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"player1X") ) { player1X=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"player1Y") ) { player1Y=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"player2X") ) { player2X=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"player2Y") ) { player2Y=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fifthKey") ) { fifthKey=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"modifiers") ) { modifiers=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"needsVoices") ) { needsVoices=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"colorMapping") ) { colorMapping=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Song_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("song",d5,23,58,4c));
	outFields->push(HX_("notes",41,dc,ca,9f));
	outFields->push(HX_("modifiers",3c,11,18,d8));
	outFields->push(HX_("bpm",df,be,4a,00));
	outFields->push(HX_("needsVoices",be,05,e9,0d));
	outFields->push(HX_("speed",87,97,69,81));
	outFields->push(HX_("colorMapping",eb,73,d1,6d));
	outFields->push(HX_("fps",e9,c7,4d,00));
	outFields->push(HX_("player1X",a8,70,53,48));
	outFields->push(HX_("player1Y",a9,70,53,48));
	outFields->push(HX_("player2X",87,71,53,48));
	outFields->push(HX_("player2Y",88,71,53,48));
	outFields->push(HX_("fifthKey",e8,b7,40,b0));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Song_obj_sMemberStorageInfo[] = {
	{::hx::fsString,(int)offsetof(Song_obj,song),HX_("song",d5,23,58,4c)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(Song_obj,notes),HX_("notes",41,dc,ca,9f)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(Song_obj,modifiers),HX_("modifiers",3c,11,18,d8)},
	{::hx::fsInt,(int)offsetof(Song_obj,bpm),HX_("bpm",df,be,4a,00)},
	{::hx::fsBool,(int)offsetof(Song_obj,needsVoices),HX_("needsVoices",be,05,e9,0d)},
	{::hx::fsFloat,(int)offsetof(Song_obj,speed),HX_("speed",87,97,69,81)},
	{::hx::fsInt,(int)offsetof(Song_obj,colorMapping),HX_("colorMapping",eb,73,d1,6d)},
	{::hx::fsInt,(int)offsetof(Song_obj,fps),HX_("fps",e9,c7,4d,00)},
	{::hx::fsFloat,(int)offsetof(Song_obj,player1X),HX_("player1X",a8,70,53,48)},
	{::hx::fsFloat,(int)offsetof(Song_obj,player1Y),HX_("player1Y",a9,70,53,48)},
	{::hx::fsFloat,(int)offsetof(Song_obj,player2X),HX_("player2X",87,71,53,48)},
	{::hx::fsFloat,(int)offsetof(Song_obj,player2Y),HX_("player2Y",88,71,53,48)},
	{::hx::fsBool,(int)offsetof(Song_obj,fifthKey),HX_("fifthKey",e8,b7,40,b0)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *Song_obj_sStaticStorageInfo = 0;
#endif

static ::String Song_obj_sMemberFields[] = {
	HX_("song",d5,23,58,4c),
	HX_("notes",41,dc,ca,9f),
	HX_("modifiers",3c,11,18,d8),
	HX_("bpm",df,be,4a,00),
	HX_("needsVoices",be,05,e9,0d),
	HX_("speed",87,97,69,81),
	HX_("colorMapping",eb,73,d1,6d),
	HX_("fps",e9,c7,4d,00),
	HX_("player1X",a8,70,53,48),
	HX_("player1Y",a9,70,53,48),
	HX_("player2X",87,71,53,48),
	HX_("player2Y",88,71,53,48),
	HX_("fifthKey",e8,b7,40,b0),
	::String(null()) };

::hx::Class Song_obj::__mClass;

static ::String Song_obj_sStaticFields[] = {
	HX_("loadFromJson",f8,fc,9c,5d),
	HX_("getRawJSON",1a,7a,66,52),
	HX_("parseJSONshit",1b,89,4d,3b),
	::String(null())
};

void Song_obj::__register()
{
	Song_obj _hx_dummy;
	Song_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("Song",f5,4f,31,37);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Song_obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(Song_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Song_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Song_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Song_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Song_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

