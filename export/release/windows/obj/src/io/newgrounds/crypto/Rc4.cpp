#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_io_newgrounds_crypto_Rc4
#include <io/newgrounds/crypto/Rc4.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_cf73e025e0469b26_32_new,"io.newgrounds.crypto.Rc4","new",0xf4715d82,"io.newgrounds.crypto.Rc4.new","io/newgrounds/crypto/Rc4.hx",32,0x20dc4d4f)
HX_LOCAL_STACK_FRAME(_hx_pos_cf73e025e0469b26_49_swap,"io.newgrounds.crypto.Rc4","swap",0xf21c1b31,"io.newgrounds.crypto.Rc4.swap","io/newgrounds/crypto/Rc4.hx",49,0x20dc4d4f)
HX_LOCAL_STACK_FRAME(_hx_pos_cf73e025e0469b26_55_crypt,"io.newgrounds.crypto.Rc4","crypt",0xacd68d10,"io.newgrounds.crypto.Rc4.crypt","io/newgrounds/crypto/Rc4.hx",55,0x20dc4d4f)
namespace io{
namespace newgrounds{
namespace crypto{

void Rc4_obj::__construct( ::haxe::io::Bytes key){
            	HX_STACKFRAME(&_hx_pos_cf73e025e0469b26_32_new)
HXLINE(  35)		this->index2 = 0;
HXLINE(  34)		this->index1 = 0;
HXLINE(  33)		this->perm = ::haxe::io::Bytes_obj::alloc(256);
HXLINE(  38)		{
HXLINE(  38)			int _g = 0;
HXDLIN(  38)			while((_g < 256)){
HXLINE(  38)				_g = (_g + 1);
HXDLIN(  38)				int i = (_g - 1);
HXLINE(  39)				this->perm->b[i] = ( (unsigned char)(i) );
            			}
            		}
HXLINE(  42)		int j = 0;
HXLINE(  43)		{
HXLINE(  43)			int _g1 = 0;
HXDLIN(  43)			while((_g1 < 256)){
HXLINE(  43)				_g1 = (_g1 + 1);
HXDLIN(  43)				int i = (_g1 - 1);
HXLINE(  44)				j = ::hx::Mod(((j + this->perm->b->__get(i)) + key->b->__get(::hx::Mod(i,key->length))),256);
HXLINE(  45)				{
HXLINE(  45)					int temp = ( (int)(this->perm->b->__get(i)) );
HXDLIN(  45)					this->perm->b[i] = this->perm->b->__get(j);
HXDLIN(  45)					this->perm->b[j] = ( (unsigned char)(temp) );
            				}
            			}
            		}
            	}

Dynamic Rc4_obj::__CreateEmpty() { return new Rc4_obj; }

void *Rc4_obj::_hx_vtable = 0;

Dynamic Rc4_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Rc4_obj > _hx_result = new Rc4_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool Rc4_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x649f6b90;
}

void Rc4_obj::swap(int i,int j){
            	HX_STACKFRAME(&_hx_pos_cf73e025e0469b26_49_swap)
HXLINE(  50)		int temp = ( (int)(this->perm->b->__get(i)) );
HXLINE(  51)		this->perm->b[i] = this->perm->b->__get(j);
HXLINE(  52)		this->perm->b[j] = ( (unsigned char)(temp) );
            	}


HX_DEFINE_DYNAMIC_FUNC2(Rc4_obj,swap,(void))

 ::haxe::io::Bytes Rc4_obj::crypt( ::haxe::io::Bytes input){
            	HX_STACKFRAME(&_hx_pos_cf73e025e0469b26_55_crypt)
HXLINE(  56)		 ::haxe::io::Bytes output = ::haxe::io::Bytes_obj::alloc(input->length);
HXLINE(  58)		{
HXLINE(  58)			int _g = 0;
HXDLIN(  58)			int _g1 = input->length;
HXDLIN(  58)			while((_g < _g1)){
HXLINE(  58)				_g = (_g + 1);
HXDLIN(  58)				int i = (_g - 1);
HXLINE(  59)				this->index1 = ::hx::Mod((this->index1 + 1),256);
HXLINE(  60)				this->index2 = ::hx::Mod((this->index2 + this->perm->b->__get(this->index1)),256);
HXLINE(  61)				{
HXLINE(  61)					int i1 = this->index1;
HXDLIN(  61)					int j = this->index2;
HXDLIN(  61)					int temp = ( (int)(this->perm->b->__get(i1)) );
HXDLIN(  61)					this->perm->b[i1] = this->perm->b->__get(j);
HXDLIN(  61)					this->perm->b[j] = ( (unsigned char)(temp) );
            				}
HXLINE(  62)				int j1 = ::hx::Mod((this->perm->b->__get(this->index1) + this->perm->b->__get(this->index2)),256);
HXLINE(  63)				output->b[i] = ( (unsigned char)((( (int)(input->b->__get(i)) ) ^ ( (int)(this->perm->b->__get(j1)) ))) );
            			}
            		}
HXLINE(  66)		return output;
            	}


HX_DEFINE_DYNAMIC_FUNC1(Rc4_obj,crypt,return )


::hx::ObjectPtr< Rc4_obj > Rc4_obj::__new( ::haxe::io::Bytes key) {
	::hx::ObjectPtr< Rc4_obj > __this = new Rc4_obj();
	__this->__construct(key);
	return __this;
}

::hx::ObjectPtr< Rc4_obj > Rc4_obj::__alloc(::hx::Ctx *_hx_ctx, ::haxe::io::Bytes key) {
	Rc4_obj *__this = (Rc4_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Rc4_obj), true, "io.newgrounds.crypto.Rc4"));
	*(void **)__this = Rc4_obj::_hx_vtable;
	__this->__construct(key);
	return __this;
}

Rc4_obj::Rc4_obj()
{
}

void Rc4_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Rc4);
	HX_MARK_MEMBER_NAME(perm,"perm");
	HX_MARK_MEMBER_NAME(index1,"index1");
	HX_MARK_MEMBER_NAME(index2,"index2");
	HX_MARK_END_CLASS();
}

void Rc4_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(perm,"perm");
	HX_VISIT_MEMBER_NAME(index1,"index1");
	HX_VISIT_MEMBER_NAME(index2,"index2");
}

::hx::Val Rc4_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"perm") ) { return ::hx::Val( perm ); }
		if (HX_FIELD_EQ(inName,"swap") ) { return ::hx::Val( swap_dyn() ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"crypt") ) { return ::hx::Val( crypt_dyn() ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"index1") ) { return ::hx::Val( index1 ); }
		if (HX_FIELD_EQ(inName,"index2") ) { return ::hx::Val( index2 ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val Rc4_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"perm") ) { perm=inValue.Cast<  ::haxe::io::Bytes >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"index1") ) { index1=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"index2") ) { index2=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Rc4_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("perm",f0,ec,54,4a));
	outFields->push(HX_("index1",df,14,f3,93));
	outFields->push(HX_("index2",e0,14,f3,93));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Rc4_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::haxe::io::Bytes */ ,(int)offsetof(Rc4_obj,perm),HX_("perm",f0,ec,54,4a)},
	{::hx::fsInt,(int)offsetof(Rc4_obj,index1),HX_("index1",df,14,f3,93)},
	{::hx::fsInt,(int)offsetof(Rc4_obj,index2),HX_("index2",e0,14,f3,93)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *Rc4_obj_sStaticStorageInfo = 0;
#endif

static ::String Rc4_obj_sMemberFields[] = {
	HX_("perm",f0,ec,54,4a),
	HX_("index1",df,14,f3,93),
	HX_("index2",e0,14,f3,93),
	HX_("swap",93,2a,5e,4c),
	HX_("crypt",6e,f3,61,4c),
	::String(null()) };

::hx::Class Rc4_obj::__mClass;

void Rc4_obj::__register()
{
	Rc4_obj _hx_dummy;
	Rc4_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("io.newgrounds.crypto.Rc4",90,34,d8,49);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Rc4_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Rc4_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Rc4_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Rc4_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace io
} // end namespace newgrounds
} // end namespace crypto
