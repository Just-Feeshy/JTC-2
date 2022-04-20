#include <hxcpp.h>

#ifndef INCLUDED_AlphaCharacter
#include <AlphaCharacter.h>
#endif
#ifndef INCLUDED_Paths
#include <Paths.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxObject
#include <flixel/FlxObject.h>
#endif
#ifndef INCLUDED_flixel_FlxSprite
#include <flixel/FlxSprite.h>
#endif
#ifndef INCLUDED_flixel_animation_FlxAnimationController
#include <flixel/animation/FlxAnimationController.h>
#endif
#ifndef INCLUDED_flixel_graphics_FlxGraphic
#include <flixel/graphics/FlxGraphic.h>
#endif
#ifndef INCLUDED_flixel_graphics_frames_FlxAtlasFrames
#include <flixel/graphics/frames/FlxAtlasFrames.h>
#endif
#ifndef INCLUDED_flixel_graphics_frames_FlxFramesCollection
#include <flixel/graphics/frames/FlxFramesCollection.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxDestroyable
#include <flixel/util/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_haxe_Exception
#include <haxe/Exception.h>
#endif
#ifndef INCLUDED_lime_utils_Assets
#include <lime/utils/Assets.h>
#endif
#ifndef INCLUDED_sys_FileSystem
#include <sys/FileSystem.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_0b74b60e7bf66d88_271_new,"AlphaCharacter","new",0xcdf30efd,"AlphaCharacter.new","Alphabet.hx",271,0xc2e40fcb)
HX_LOCAL_STACK_FRAME(_hx_pos_0b74b60e7bf66d88_292_isBoldNumbers,"AlphaCharacter","isBoldNumbers",0x1bed4f98,"AlphaCharacter.isBoldNumbers","Alphabet.hx",292,0xc2e40fcb)
HX_LOCAL_STACK_FRAME(_hx_pos_0b74b60e7bf66d88_300_createBold,"AlphaCharacter","createBold",0x537dc1a4,"AlphaCharacter.createBold","Alphabet.hx",300,0xc2e40fcb)
HX_LOCAL_STACK_FRAME(_hx_pos_0b74b60e7bf66d88_307_createLetter,"AlphaCharacter","createLetter",0xc29272c5,"AlphaCharacter.createLetter","Alphabet.hx",307,0xc2e40fcb)
HX_LOCAL_STACK_FRAME(_hx_pos_0b74b60e7bf66d88_323_createNumber,"AlphaCharacter","createNumber",0xc1044ca8,"AlphaCharacter.createNumber","Alphabet.hx",323,0xc2e40fcb)
HX_LOCAL_STACK_FRAME(_hx_pos_0b74b60e7bf66d88_334_createSymbol,"AlphaCharacter","createSymbol",0x0e677537,"AlphaCharacter.createSymbol","Alphabet.hx",334,0xc2e40fcb)
HX_LOCAL_STACK_FRAME(_hx_pos_0b74b60e7bf66d88_273_boot,"AlphaCharacter","boot",0x5ed30ef5,"AlphaCharacter.boot","Alphabet.hx",273,0xc2e40fcb)
HX_LOCAL_STACK_FRAME(_hx_pos_0b74b60e7bf66d88_275_boot,"AlphaCharacter","boot",0x5ed30ef5,"AlphaCharacter.boot","Alphabet.hx",275,0xc2e40fcb)
HX_LOCAL_STACK_FRAME(_hx_pos_0b74b60e7bf66d88_277_boot,"AlphaCharacter","boot",0x5ed30ef5,"AlphaCharacter.boot","Alphabet.hx",277,0xc2e40fcb)

void AlphaCharacter_obj::__construct(Float x,Float y){
            	HX_STACKFRAME(&_hx_pos_0b74b60e7bf66d88_271_new)
HXLINE( 281)		this->row = 0;
HXLINE( 279)		this->spaceLocation = 0;
HXLINE( 285)		super::__construct(x,y,null());
HXLINE( 286)		::String library = null();
HXDLIN( 286)		 ::Dynamic cache = null();
HXDLIN( 286)		::String cacheFile = HX_("",00,00,00,00);
HXDLIN( 286)		if (( (bool)(cache) )) {
HXLINE( 286)			cacheFile = HX_("cache/",ad,5f,f2,b0);
            		}
HXDLIN( 286)		if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + HX_("alphabet",b3,7c,38,21)))) {
HXLINE( 286)			cacheFile = HX_("",00,00,00,00);
            		}
HXDLIN( 286)		 ::flixel::graphics::frames::FlxAtlasFrames tex;
HXDLIN( 286)		::String cacheFile1 = HX_("",00,00,00,00);
HXDLIN( 286)		if (( (bool)(cache) )) {
HXLINE( 286)			cacheFile1 = HX_("cache/",ad,5f,f2,b0);
            		}
HXDLIN( 286)		if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + HX_("alphabet",b3,7c,38,21)))) {
HXLINE( 286)			cacheFile1 = HX_("",00,00,00,00);
            		}
HXDLIN( 286)		if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile1) + HX_("alphabet",b3,7c,38,21)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library),null())) {
HXLINE( 286)			if (::hx::IsNotNull( ::Paths_obj::ifImageCached((cacheFile + HX_("alphabet",b3,7c,38,21))) )) {
HXLINE( 286)				 ::flixel::graphics::FlxGraphic tex1 = ::Paths_obj::ifImageCached((cacheFile + HX_("alphabet",b3,7c,38,21)));
HXDLIN( 286)				tex = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSparrow(tex1,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + HX_("alphabet",b3,7c,38,21)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library));
            			}
            			else {
HXLINE( 286)				::String tex1 = ::Paths_obj::image((cacheFile + HX_("alphabet",b3,7c,38,21)),library);
HXDLIN( 286)				tex = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSparrow(tex1,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + HX_("alphabet",b3,7c,38,21)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library));
            			}
            		}
            		else {
HXLINE( 286)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate asset - ",17,30,f9,e8) + ::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + HX_("alphabet",b3,7c,38,21)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library))));
            		}
HXLINE( 287)		this->set_frames(tex);
HXLINE( 289)		this->set_antialiasing(true);
            	}

Dynamic AlphaCharacter_obj::__CreateEmpty() { return new AlphaCharacter_obj; }

void *AlphaCharacter_obj::_hx_vtable = 0;

Dynamic AlphaCharacter_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< AlphaCharacter_obj > _hx_result = new AlphaCharacter_obj();
	_hx_result->__construct(inArgs[0],inArgs[1]);
	return _hx_result;
}

bool AlphaCharacter_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x2c01639b) {
		if (inClassId<=(int)0x10d46877) {
			return inClassId==(int)0x00000001 || inClassId==(int)0x10d46877;
		} else {
			return inClassId==(int)0x2c01639b;
		}
	} else {
		return inClassId==(int)0x7ccf8994 || inClassId==(int)0x7dab0655;
	}
}

void AlphaCharacter_obj::isBoldNumbers(){
            	HX_STACKFRAME(&_hx_pos_0b74b60e7bf66d88_292_isBoldNumbers)
HXLINE( 293)		this->animation->destroyAnimations();
HXLINE( 295)		::String library = null();
HXDLIN( 295)		 ::Dynamic cache = null();
HXDLIN( 295)		::String cacheFile = HX_("",00,00,00,00);
HXDLIN( 295)		if (( (bool)(cache) )) {
HXLINE( 295)			cacheFile = HX_("cache/",ad,5f,f2,b0);
            		}
HXDLIN( 295)		if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + HX_("numbers-bold",68,5e,ab,00)))) {
HXLINE( 295)			cacheFile = HX_("",00,00,00,00);
            		}
HXDLIN( 295)		 ::flixel::graphics::frames::FlxAtlasFrames tex;
HXDLIN( 295)		::String cacheFile1 = HX_("",00,00,00,00);
HXDLIN( 295)		if (( (bool)(cache) )) {
HXLINE( 295)			cacheFile1 = HX_("cache/",ad,5f,f2,b0);
            		}
HXDLIN( 295)		if (::sys::FileSystem_obj::exists((HX_("mod_assets/images/",c8,63,40,54) + HX_("numbers-bold",68,5e,ab,00)))) {
HXLINE( 295)			cacheFile1 = HX_("",00,00,00,00);
            		}
HXDLIN( 295)		if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile1) + HX_("numbers-bold",68,5e,ab,00)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library),null())) {
HXLINE( 295)			if (::hx::IsNotNull( ::Paths_obj::ifImageCached((cacheFile + HX_("numbers-bold",68,5e,ab,00))) )) {
HXLINE( 295)				 ::flixel::graphics::FlxGraphic tex1 = ::Paths_obj::ifImageCached((cacheFile + HX_("numbers-bold",68,5e,ab,00)));
HXDLIN( 295)				tex = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSparrow(tex1,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + HX_("numbers-bold",68,5e,ab,00)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library));
            			}
            			else {
HXLINE( 295)				::String tex1 = ::Paths_obj::image((cacheFile + HX_("numbers-bold",68,5e,ab,00)),library);
HXDLIN( 295)				tex = ::flixel::graphics::frames::FlxAtlasFrames_obj::fromSparrow(tex1,::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + HX_("numbers-bold",68,5e,ab,00)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library));
            			}
            		}
            		else {
HXLINE( 295)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("Error: could not locate asset - ",17,30,f9,e8) + ::Paths_obj::getPath((((HX_("images/",77,50,74,c1) + cacheFile) + HX_("numbers-bold",68,5e,ab,00)) + HX_(".xml",69,3e,c3,1e)),HX_("TEXT",ad,94,ba,37),library))));
            		}
HXLINE( 296)		this->set_frames(tex);
            	}


HX_DEFINE_DYNAMIC_FUNC0(AlphaCharacter_obj,isBoldNumbers,(void))

void AlphaCharacter_obj::createBold(::String letter){
            	HX_STACKFRAME(&_hx_pos_0b74b60e7bf66d88_300_createBold)
HXLINE( 301)		 ::flixel::animation::FlxAnimationController _hx_tmp = this->animation;
HXDLIN( 301)		_hx_tmp->addByPrefix(letter,(letter.toUpperCase() + HX_(" bold",a5,11,ee,ad)),24,null(),null(),null());
HXLINE( 302)		this->animation->play(letter,null(),null(),null());
HXLINE( 303)		this->updateHitbox();
            	}


HX_DEFINE_DYNAMIC_FUNC1(AlphaCharacter_obj,createBold,(void))

void AlphaCharacter_obj::createLetter(::String letter){
            	HX_STACKFRAME(&_hx_pos_0b74b60e7bf66d88_307_createLetter)
HXLINE( 308)		::String letterCase = HX_("lowercase",31,ad,a5,66);
HXLINE( 309)		if ((letter.toLowerCase() != letter)) {
HXLINE( 311)			letterCase = HX_("capital",a8,a6,0b,a0);
            		}
HXLINE( 314)		this->animation->addByPrefix(letter,((letter + HX_(" ",20,00,00,00)) + letterCase),24,null(),null(),null());
HXLINE( 315)		this->animation->play(letter,null(),null(),null());
HXLINE( 316)		this->updateHitbox();
HXLINE( 318)		this->set_y((( (Float)(110) ) - this->get_height()));
HXLINE( 319)		this->set_y((this->y + (this->row * 60)));
            	}


HX_DEFINE_DYNAMIC_FUNC1(AlphaCharacter_obj,createLetter,(void))

void AlphaCharacter_obj::createNumber(::String letter){
            	HX_STACKFRAME(&_hx_pos_0b74b60e7bf66d88_323_createNumber)
HXLINE( 324)		this->animation->addByPrefix(letter,letter,24,null(),null(),null());
HXLINE( 325)		this->animation->play(letter,null(),null(),null());
HXLINE( 327)		this->updateHitbox();
HXLINE( 329)		this->set_y((( (Float)(110) ) - this->get_height()));
HXLINE( 330)		this->set_y((this->y + (this->row * 60)));
            	}


HX_DEFINE_DYNAMIC_FUNC1(AlphaCharacter_obj,createNumber,(void))

void AlphaCharacter_obj::createSymbol(::String letter){
            	HX_STACKFRAME(&_hx_pos_0b74b60e7bf66d88_334_createSymbol)
HXLINE( 335)		::String _hx_switch_0 = letter;
            		if (  (_hx_switch_0==HX_("!",21,00,00,00)) ){
HXLINE( 349)			this->animation->addByPrefix(letter,HX_("exclamation point",dd,17,c1,eb),24,null(),null(),null());
HXLINE( 350)			this->animation->play(letter,null(),null(),null());
HXLINE( 348)			goto _hx_goto_5;
            		}
            		if (  (_hx_switch_0==HX_("'",27,00,00,00)) ){
HXLINE( 342)			this->animation->addByPrefix(letter,HX_("apostraphie",04,43,cf,ad),24,null(),null(),null());
HXLINE( 343)			this->animation->play(letter,null(),null(),null());
HXLINE( 344)			this->set_y(this->y);
HXLINE( 341)			goto _hx_goto_5;
            		}
            		if (  (_hx_switch_0==HX_(".",2e,00,00,00)) ){
HXLINE( 338)			this->animation->addByPrefix(letter,HX_("period",01,61,1b,3b),24,null(),null(),null());
HXLINE( 339)			this->animation->play(letter,null(),null(),null());
HXLINE( 340)			this->set_y((this->y + 50));
HXLINE( 337)			goto _hx_goto_5;
            		}
            		if (  (_hx_switch_0==HX_("<",3c,00,00,00)) ){
HXLINE( 355)			this->animation->addByPrefix(letter,HX_("left arrow",f0,4c,77,eb),24,null(),null(),null());
HXLINE( 356)			this->animation->play(letter,null(),null(),null());
HXLINE( 354)			goto _hx_goto_5;
            		}
            		if (  (_hx_switch_0==HX_(">",3e,00,00,00)) ){
HXLINE( 352)			this->animation->addByPrefix(letter,HX_("right arrow",85,5e,eb,25),24,null(),null(),null());
HXLINE( 353)			this->animation->play(letter,null(),null(),null());
HXLINE( 351)			goto _hx_goto_5;
            		}
            		if (  (_hx_switch_0==HX_("?",3f,00,00,00)) ){
HXLINE( 346)			this->animation->addByPrefix(letter,HX_("question mark",47,0b,f6,d2),24,null(),null(),null());
HXLINE( 347)			this->animation->play(letter,null(),null(),null());
HXLINE( 345)			goto _hx_goto_5;
            		}
            		if (  (_hx_switch_0==HX_("^",5e,00,00,00)) ){
HXLINE( 358)			this->animation->addByPrefix(letter,HX_("up arrow",44,22,6d,46),24,null(),null(),null());
HXLINE( 359)			this->animation->play(letter,null(),null(),null());
HXLINE( 357)			goto _hx_goto_5;
            		}
            		_hx_goto_5:;
HXLINE( 362)		this->updateHitbox();
            	}


HX_DEFINE_DYNAMIC_FUNC1(AlphaCharacter_obj,createSymbol,(void))

::String AlphaCharacter_obj::alphabet;

::String AlphaCharacter_obj::numbers;

::String AlphaCharacter_obj::symbols;


::hx::ObjectPtr< AlphaCharacter_obj > AlphaCharacter_obj::__new(Float x,Float y) {
	::hx::ObjectPtr< AlphaCharacter_obj > __this = new AlphaCharacter_obj();
	__this->__construct(x,y);
	return __this;
}

::hx::ObjectPtr< AlphaCharacter_obj > AlphaCharacter_obj::__alloc(::hx::Ctx *_hx_ctx,Float x,Float y) {
	AlphaCharacter_obj *__this = (AlphaCharacter_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(AlphaCharacter_obj), true, "AlphaCharacter"));
	*(void **)__this = AlphaCharacter_obj::_hx_vtable;
	__this->__construct(x,y);
	return __this;
}

AlphaCharacter_obj::AlphaCharacter_obj()
{
}

::hx::Val AlphaCharacter_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"row") ) { return ::hx::Val( row ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"createBold") ) { return ::hx::Val( createBold_dyn() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"createLetter") ) { return ::hx::Val( createLetter_dyn() ); }
		if (HX_FIELD_EQ(inName,"createNumber") ) { return ::hx::Val( createNumber_dyn() ); }
		if (HX_FIELD_EQ(inName,"createSymbol") ) { return ::hx::Val( createSymbol_dyn() ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"spaceLocation") ) { return ::hx::Val( spaceLocation ); }
		if (HX_FIELD_EQ(inName,"isBoldNumbers") ) { return ::hx::Val( isBoldNumbers_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

bool AlphaCharacter_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"numbers") ) { outValue = ( numbers ); return true; }
		if (HX_FIELD_EQ(inName,"symbols") ) { outValue = ( symbols ); return true; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"alphabet") ) { outValue = ( alphabet ); return true; }
	}
	return false;
}

::hx::Val AlphaCharacter_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"row") ) { row=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"spaceLocation") ) { spaceLocation=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool AlphaCharacter_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"numbers") ) { numbers=ioValue.Cast< ::String >(); return true; }
		if (HX_FIELD_EQ(inName,"symbols") ) { symbols=ioValue.Cast< ::String >(); return true; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"alphabet") ) { alphabet=ioValue.Cast< ::String >(); return true; }
	}
	return false;
}

void AlphaCharacter_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("spaceLocation",1b,ed,81,42));
	outFields->push(HX_("row",1a,e2,56,00));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo AlphaCharacter_obj_sMemberStorageInfo[] = {
	{::hx::fsInt,(int)offsetof(AlphaCharacter_obj,spaceLocation),HX_("spaceLocation",1b,ed,81,42)},
	{::hx::fsInt,(int)offsetof(AlphaCharacter_obj,row),HX_("row",1a,e2,56,00)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo AlphaCharacter_obj_sStaticStorageInfo[] = {
	{::hx::fsString,(void *) &AlphaCharacter_obj::alphabet,HX_("alphabet",b3,7c,38,21)},
	{::hx::fsString,(void *) &AlphaCharacter_obj::numbers,HX_("numbers",8a,69,bb,a9)},
	{::hx::fsString,(void *) &AlphaCharacter_obj::symbols,HX_("symbols",1b,be,1b,13)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static ::String AlphaCharacter_obj_sMemberFields[] = {
	HX_("spaceLocation",1b,ed,81,42),
	HX_("row",1a,e2,56,00),
	HX_("isBoldNumbers",bb,ca,2c,8b),
	HX_("createBold",a1,42,a9,53),
	HX_("createLetter",02,ed,5d,c5),
	HX_("createNumber",e5,c6,cf,c3),
	HX_("createSymbol",74,ef,32,11),
	::String(null()) };

static void AlphaCharacter_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AlphaCharacter_obj::alphabet,"alphabet");
	HX_MARK_MEMBER_NAME(AlphaCharacter_obj::numbers,"numbers");
	HX_MARK_MEMBER_NAME(AlphaCharacter_obj::symbols,"symbols");
};

#ifdef HXCPP_VISIT_ALLOCS
static void AlphaCharacter_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AlphaCharacter_obj::alphabet,"alphabet");
	HX_VISIT_MEMBER_NAME(AlphaCharacter_obj::numbers,"numbers");
	HX_VISIT_MEMBER_NAME(AlphaCharacter_obj::symbols,"symbols");
};

#endif

::hx::Class AlphaCharacter_obj::__mClass;

static ::String AlphaCharacter_obj_sStaticFields[] = {
	HX_("alphabet",b3,7c,38,21),
	HX_("numbers",8a,69,bb,a9),
	HX_("symbols",1b,be,1b,13),
	::String(null())
};

void AlphaCharacter_obj::__register()
{
	AlphaCharacter_obj _hx_dummy;
	AlphaCharacter_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("AlphaCharacter",8b,cc,2e,b9);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &AlphaCharacter_obj::__GetStatic;
	__mClass->mSetStaticField = &AlphaCharacter_obj::__SetStatic;
	__mClass->mMarkFunc = AlphaCharacter_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(AlphaCharacter_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(AlphaCharacter_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< AlphaCharacter_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = AlphaCharacter_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = AlphaCharacter_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = AlphaCharacter_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void AlphaCharacter_obj::__boot()
{
{
            	HX_STACKFRAME(&_hx_pos_0b74b60e7bf66d88_273_boot)
HXDLIN( 273)		alphabet = HX_("abcdefghijklmnopqrstuvwxyz",6d,97,f1,fb);
            	}
{
            	HX_STACKFRAME(&_hx_pos_0b74b60e7bf66d88_275_boot)
HXDLIN( 275)		numbers = HX_("1234567890",5b,2e,e3,45);
            	}
{
            	HX_STACKFRAME(&_hx_pos_0b74b60e7bf66d88_277_boot)
HXDLIN( 277)		symbols = HX_("|~#$%()*+-:;<=>@[]^_.,'!?",f7,99,8c,d3);
            	}
}

