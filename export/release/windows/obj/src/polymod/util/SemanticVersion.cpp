#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_Exception
#include <haxe/Exception.h>
#endif
#ifndef INCLUDED_polymod_util_SemanticVersion
#include <polymod/util/SemanticVersion.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_ad8fc9d174356b99_143_new,"polymod.util.SemanticVersion","new",0x2b1b6d90,"polymod.util.SemanticVersion.new","polymod/util/SemanticVersion.hx",143,0xe2d86840)
HX_LOCAL_STACK_FRAME(_hx_pos_ad8fc9d174356b99_152_checkCompatibility,"polymod.util.SemanticVersion","checkCompatibility",0x65d75718,"polymod.util.SemanticVersion.checkCompatibility","polymod/util/SemanticVersion.hx",152,0xe2d86840)
HX_LOCAL_STACK_FRAME(_hx_pos_ad8fc9d174356b99_171_compare,"polymod.util.SemanticVersion","compare",0xa9ff0dd5,"polymod.util.SemanticVersion.compare","polymod/util/SemanticVersion.hx",171,0xe2d86840)
HX_LOCAL_STACK_FRAME(_hx_pos_ad8fc9d174356b99_224_isEqualTo,"polymod.util.SemanticVersion","isEqualTo",0xa87d8cb5,"polymod.util.SemanticVersion.isEqualTo","polymod/util/SemanticVersion.hx",224,0xe2d86840)
HX_LOCAL_STACK_FRAME(_hx_pos_ad8fc9d174356b99_229_isNewerThan,"polymod.util.SemanticVersion","isNewerThan",0x099c1ab4,"polymod.util.SemanticVersion.isNewerThan","polymod/util/SemanticVersion.hx",229,0xe2d86840)
HX_LOCAL_STACK_FRAME(_hx_pos_ad8fc9d174356b99_234_toString,"polymod.util.SemanticVersion","toString",0xd50f657c,"polymod.util.SemanticVersion.toString","polymod/util/SemanticVersion.hx",234,0xe2d86840)
HX_LOCAL_STACK_FRAME(_hx_pos_ad8fc9d174356b99_11_fromString,"polymod.util.SemanticVersion","fromString",0xc9ff96ab,"polymod.util.SemanticVersion.fromString","polymod/util/SemanticVersion.hx",11,0xe2d86840)
namespace polymod{
namespace util{

void SemanticVersion_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_ad8fc9d174356b99_143_new)
            	}

Dynamic SemanticVersion_obj::__CreateEmpty() { return new SemanticVersion_obj; }

void *SemanticVersion_obj::_hx_vtable = 0;

Dynamic SemanticVersion_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< SemanticVersion_obj > _hx_result = new SemanticVersion_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool SemanticVersion_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x3992c45a;
}

int SemanticVersion_obj::checkCompatibility( ::polymod::util::SemanticVersion newer){
            	HX_STACKFRAME(&_hx_pos_ad8fc9d174356b99_152_checkCompatibility)
HXLINE( 153)		int score = 0;
HXLINE( 155)		bool _hx_tmp;
HXDLIN( 155)		bool _hx_tmp1;
HXDLIN( 155)		if ((newer->major != this->major)) {
HXLINE( 155)			_hx_tmp1 = (newer->major == -1);
            		}
            		else {
HXLINE( 155)			_hx_tmp1 = true;
            		}
HXDLIN( 155)		if (!(_hx_tmp1)) {
HXLINE( 155)			_hx_tmp = (this->major == -1);
            		}
            		else {
HXLINE( 155)			_hx_tmp = true;
            		}
HXDLIN( 155)		if (_hx_tmp) {
HXLINE( 157)			score = 1;
HXLINE( 158)			bool _hx_tmp;
HXDLIN( 158)			bool _hx_tmp1;
HXDLIN( 158)			if ((newer->minor < this->minor)) {
HXLINE( 158)				_hx_tmp1 = (newer->minor == -1);
            			}
            			else {
HXLINE( 158)				_hx_tmp1 = true;
            			}
HXDLIN( 158)			if (!(_hx_tmp1)) {
HXLINE( 158)				_hx_tmp = (this->minor == -1);
            			}
            			else {
HXLINE( 158)				_hx_tmp = true;
            			}
HXDLIN( 158)			if (_hx_tmp) {
HXLINE( 160)				score = 2;
HXLINE( 161)				bool _hx_tmp;
HXDLIN( 161)				bool _hx_tmp1;
HXDLIN( 161)				if ((newer->patch < this->patch)) {
HXLINE( 161)					_hx_tmp1 = (newer->patch == -1);
            				}
            				else {
HXLINE( 161)					_hx_tmp1 = true;
            				}
HXDLIN( 161)				if (!(_hx_tmp1)) {
HXLINE( 161)					_hx_tmp = (this->patch == -1);
            				}
            				else {
HXLINE( 161)					_hx_tmp = true;
            				}
HXDLIN( 161)				if (_hx_tmp) {
HXLINE( 163)					score = 3;
            				}
            			}
            		}
HXLINE( 167)		return score;
            	}


HX_DEFINE_DYNAMIC_FUNC1(SemanticVersion_obj,checkCompatibility,return )

int SemanticVersion_obj::compare( ::polymod::util::SemanticVersion other){
            	HX_STACKFRAME(&_hx_pos_ad8fc9d174356b99_171_compare)
HXLINE( 172)		bool _hx_tmp;
HXDLIN( 172)		if ((this->major != -1)) {
HXLINE( 172)			_hx_tmp = (other->major == -1);
            		}
            		else {
HXLINE( 172)			_hx_tmp = true;
            		}
HXDLIN( 172)		if (_hx_tmp) {
HXLINE( 173)			return 0;
            		}
HXLINE( 174)		if ((this->major > other->major)) {
HXLINE( 175)			return -1;
            		}
HXLINE( 176)		if ((this->major < other->major)) {
HXLINE( 177)			return 1;
            		}
HXLINE( 178)		bool _hx_tmp1;
HXDLIN( 178)		if ((this->minor != -1)) {
HXLINE( 178)			_hx_tmp1 = (other->minor == -1);
            		}
            		else {
HXLINE( 178)			_hx_tmp1 = true;
            		}
HXDLIN( 178)		if (_hx_tmp1) {
HXLINE( 179)			return 0;
            		}
HXLINE( 180)		if ((this->minor > other->minor)) {
HXLINE( 181)			return -1;
            		}
HXLINE( 182)		if ((this->minor < other->minor)) {
HXLINE( 183)			return 1;
            		}
HXLINE( 184)		bool _hx_tmp2;
HXDLIN( 184)		if ((this->patch != -1)) {
HXLINE( 184)			_hx_tmp2 = (other->patch == -1);
            		}
            		else {
HXLINE( 184)			_hx_tmp2 = true;
            		}
HXDLIN( 184)		if (_hx_tmp2) {
HXLINE( 185)			return 0;
            		}
HXLINE( 186)		if ((this->patch > other->patch)) {
HXLINE( 187)			return -1;
            		}
HXLINE( 188)		if ((this->patch < other->patch)) {
HXLINE( 189)			return 1;
            		}
HXLINE( 190)		int bits = this->preRelease->length;
HXLINE( 191)		int otherBits = other->preRelease->length;
HXLINE( 192)		if ((otherBits > bits)) {
HXLINE( 193)			bits = otherBits;
            		}
HXLINE( 194)		{
HXLINE( 194)			int _g = 0;
HXDLIN( 194)			int _g1 = bits;
HXDLIN( 194)			while((_g < _g1)){
HXLINE( 194)				_g = (_g + 1);
HXDLIN( 194)				int i = (_g - 1);
HXLINE( 196)				::String bit;
HXDLIN( 196)				bool bit1;
HXDLIN( 196)				if (::hx::IsNotNull( this->preRelease )) {
HXLINE( 196)					bit1 = (this->preRelease->length > i);
            				}
            				else {
HXLINE( 196)					bit1 = false;
            				}
HXDLIN( 196)				if (bit1) {
HXLINE( 196)					bit = this->preRelease->__get(i);
            				}
            				else {
HXLINE( 196)					bit = HX_("",00,00,00,00);
            				}
HXLINE( 197)				::String otherBit;
HXDLIN( 197)				bool otherBit1;
HXDLIN( 197)				if (::hx::IsNotNull( other->preRelease )) {
HXLINE( 197)					otherBit1 = (other->preRelease->length > i);
            				}
            				else {
HXLINE( 197)					otherBit1 = false;
            				}
HXDLIN( 197)				if (otherBit1) {
HXLINE( 197)					otherBit = other->preRelease->__get(i);
            				}
            				else {
HXLINE( 197)					otherBit = HX_("",00,00,00,00);
            				}
HXLINE( 198)				bool _hx_tmp;
HXDLIN( 198)				if ((bit == HX_("",00,00,00,00))) {
HXLINE( 198)					_hx_tmp = (otherBit != HX_("",00,00,00,00));
            				}
            				else {
HXLINE( 198)					_hx_tmp = false;
            				}
HXDLIN( 198)				if (_hx_tmp) {
HXLINE( 199)					return -1;
            				}
HXLINE( 200)				bool _hx_tmp1;
HXDLIN( 200)				if ((bit != HX_("",00,00,00,00))) {
HXLINE( 200)					_hx_tmp1 = (otherBit == HX_("",00,00,00,00));
            				}
            				else {
HXLINE( 200)					_hx_tmp1 = false;
            				}
HXDLIN( 200)				if (_hx_tmp1) {
HXLINE( 201)					return 1;
            				}
HXLINE( 202)				 ::Dynamic i1 = ::Std_obj::parseInt(bit);
HXLINE( 203)				 ::Dynamic j = ::Std_obj::parseInt(otherBit);
HXLINE( 204)				bool _hx_tmp2;
HXDLIN( 204)				if (::hx::IsNotNull( i1 )) {
HXLINE( 204)					_hx_tmp2 = ::hx::IsNotNull( j );
            				}
            				else {
HXLINE( 204)					_hx_tmp2 = false;
            				}
HXDLIN( 204)				if (_hx_tmp2) {
HXLINE( 206)					if (::hx::IsGreater( i1,j )) {
HXLINE( 207)						return -1;
            					}
HXLINE( 208)					if (::hx::IsLess( i1,j )) {
HXLINE( 209)						return 1;
            					}
            				}
            				else {
HXLINE( 213)					if ((bit > otherBit)) {
HXLINE( 214)						return -1;
            					}
HXLINE( 215)					if ((bit < otherBit)) {
HXLINE( 216)						return 1;
            					}
            				}
            			}
            		}
HXLINE( 219)		return 0;
            	}


HX_DEFINE_DYNAMIC_FUNC1(SemanticVersion_obj,compare,return )

bool SemanticVersion_obj::isEqualTo( ::polymod::util::SemanticVersion other){
            	HX_STACKFRAME(&_hx_pos_ad8fc9d174356b99_224_isEqualTo)
HXDLIN( 224)		return (this->compare(other) == 0);
            	}


HX_DEFINE_DYNAMIC_FUNC1(SemanticVersion_obj,isEqualTo,return )

bool SemanticVersion_obj::isNewerThan( ::polymod::util::SemanticVersion other){
            	HX_STACKFRAME(&_hx_pos_ad8fc9d174356b99_229_isNewerThan)
HXDLIN( 229)		return (this->compare(other) == -1);
            	}


HX_DEFINE_DYNAMIC_FUNC1(SemanticVersion_obj,isNewerThan,return )

::String SemanticVersion_obj::toString(){
            	HX_STACKFRAME(&_hx_pos_ad8fc9d174356b99_234_toString)
HXDLIN( 234)		return this->effective;
            	}


HX_DEFINE_DYNAMIC_FUNC0(SemanticVersion_obj,toString,return )

 ::polymod::util::SemanticVersion SemanticVersion_obj::fromString(::String str){
            	HX_GC_STACKFRAME(&_hx_pos_ad8fc9d174356b99_11_fromString)
HXLINE(  12)		 ::polymod::util::SemanticVersion v =  ::polymod::util::SemanticVersion_obj::__alloc( HX_CTX );
HXLINE(  13)		v->original = str;
HXLINE(  14)		bool _hx_tmp;
HXDLIN(  14)		if ((str != HX_("",00,00,00,00))) {
HXLINE(  14)			_hx_tmp = ::hx::IsNull( str );
            		}
            		else {
HXLINE(  14)			_hx_tmp = true;
            		}
HXDLIN(  14)		if (_hx_tmp) {
HXLINE(  15)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(HX_("SemanticVersion.hx: string is empty!",6d,e3,65,74)));
            		}
HXLINE(  16)		::String extra = HX_("",00,00,00,00);
HXLINE(  17)		if ((str.indexOf(HX_("+",2b,00,00,00),null()) != -1)) {
HXLINE(  19)			::Array< ::String > arr = str.split(HX_("+",2b,00,00,00));
HXLINE(  20)			str = arr->__get(0);
            		}
HXLINE(  22)		if ((str.indexOf(HX_("-",2d,00,00,00),null()) != -1)) {
HXLINE(  24)			::Array< ::String > arr = str.split(HX_("-",2d,00,00,00));
HXLINE(  25)			str = arr->__get(0);
HXLINE(  26)			extra = arr->__get(1);
            		}
HXLINE(  28)		::Array< ::String > arr = str.split(HX_(".",2e,00,00,00));
HXLINE(  29)		if ((arr->length < 3)) {
HXLINE(  30)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(((HX_("SemanticVersion.hx: needs major, minor, and patch versions! \"",56,72,c3,31) + str) + HX_("\"",22,00,00,00))));
            		}
HXLINE(  31)		{
HXLINE(  31)			int _g = 0;
HXDLIN(  31)			int _g1 = arr->length;
HXDLIN(  31)			while((_g < _g1)){
HXLINE(  31)				_g = (_g + 1);
HXDLIN(  31)				int ii = (_g - 1);
HXLINE(  33)				::String substr = arr->__get(ii);
HXLINE(  34)				bool _hx_tmp;
HXDLIN(  34)				if ((substr.length > 1)) {
HXLINE(  34)					_hx_tmp = (substr.charAt(0) == HX_("0",30,00,00,00));
            				}
            				else {
HXLINE(  34)					_hx_tmp = false;
            				}
HXDLIN(  34)				if (_hx_tmp) {
HXLINE(  36)					HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(((HX_("SemanticVersion.hx: no leading zeroes allowed! \"",1e,d6,ff,51) + str) + HX_("\"",22,00,00,00))));
            				}
HXLINE(  38)				{
HXLINE(  38)					int _g1 = 0;
HXDLIN(  38)					int _g2 = substr.length;
HXDLIN(  38)					while((_g1 < _g2)){
HXLINE(  38)						_g1 = (_g1 + 1);
HXDLIN(  38)						int i = (_g1 - 1);
HXLINE(  40)						::String _hx_char = substr.charAt(i);
HXLINE(  41)						::String _hx_switch_0 = _hx_char;
            						if (  (_hx_switch_0==HX_("*",2a,00,00,00)) ||  (_hx_switch_0==HX_("0",30,00,00,00)) ||  (_hx_switch_0==HX_("1",31,00,00,00)) ||  (_hx_switch_0==HX_("2",32,00,00,00)) ||  (_hx_switch_0==HX_("3",33,00,00,00)) ||  (_hx_switch_0==HX_("4",34,00,00,00)) ||  (_hx_switch_0==HX_("5",35,00,00,00)) ||  (_hx_switch_0==HX_("6",36,00,00,00)) ||  (_hx_switch_0==HX_("7",37,00,00,00)) ||  (_hx_switch_0==HX_("8",38,00,00,00)) ||  (_hx_switch_0==HX_("9",39,00,00,00)) ){
HXLINE(  43)							goto _hx_goto_9;
            						}
            						/* default */{
HXLINE(  46)							::String word;
HXDLIN(  46)							switch((int)(ii)){
            								case (int)0: {
HXLINE(  46)									word = HX_("major",39,bd,1b,03);
            								}
            								break;
            								case (int)1: {
HXLINE(  46)									word = HX_("minor",35,7b,68,08);
            								}
            								break;
            								case (int)2: {
HXLINE(  46)									word = HX_("patch",c8,06,57,bd);
            								}
            								break;
            								default:{
HXLINE(  46)									word = HX_("",00,00,00,00);
            								}
            							}
HXLINE(  53)							HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(((((HX_("SemanticVersion.hx: couldn't parse ",21,61,91,29) + word) + HX_(" version \"",fa,f4,da,13)) + str) + HX_("\"",22,00,00,00))));
            						}
            						_hx_goto_9:;
            					}
            				}
            			}
            		}
HXLINE(  57)		 ::Dynamic maj = null();
HXLINE(  58)		 ::Dynamic min = null();
HXLINE(  59)		 ::Dynamic pat = null();
HXLINE(  60)		if ((arr->__get(0) == HX_("*",2a,00,00,00))) {
HXLINE(  61)			maj = -1;
            		}
HXLINE(  62)		if ((arr->__get(1) == HX_("*",2a,00,00,00))) {
HXLINE(  63)			min = -1;
            		}
HXLINE(  64)		if ((arr->__get(2) == HX_("*",2a,00,00,00))) {
HXLINE(  65)			pat = -1;
            		}
HXLINE(  66)		if (::hx::IsNull( maj )) {
HXLINE(  67)			maj = ::Std_obj::parseInt(arr->__get(0));
            		}
HXLINE(  68)		if (::hx::IsNull( min )) {
HXLINE(  69)			min = ::Std_obj::parseInt(arr->__get(1));
            		}
HXLINE(  70)		if (::hx::IsNull( pat )) {
HXLINE(  71)			pat = ::Std_obj::parseInt(arr->__get(2));
            		}
HXLINE(  72)		if (::hx::IsNull( maj )) {
HXLINE(  73)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(((HX_("SemanticVersion.hx: couldn't parse major version! \"",f3,64,a0,0f) + str) + HX_("\"",22,00,00,00))));
            		}
HXLINE(  74)		if (::hx::IsNull( min )) {
HXLINE(  75)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(((HX_("SemanticVersion.hx: couldn't parse minor version! \"",77,b0,32,c2) + str) + HX_("\"",22,00,00,00))));
            		}
HXLINE(  76)		if (::hx::IsNull( pat )) {
HXLINE(  77)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(((HX_("SemanticVersion.hx: couldn't parse patch version! \"",c4,f7,75,29) + str) + HX_("\"",22,00,00,00))));
            		}
HXLINE(  79)		if (::hx::IsEq( maj,-1 )) {
HXLINE(  81)			min = -1;
HXLINE(  82)			pat = -1;
            		}
HXLINE(  84)		if (::hx::IsEq( min,-1 )) {
HXLINE(  86)			pat = -1;
            		}
HXLINE(  89)		v->major = ( (int)(maj) );
HXLINE(  90)		v->minor = ( (int)(min) );
HXLINE(  91)		v->patch = ( (int)(pat) );
HXLINE(  92)		v->preRelease = ::Array_obj< ::String >::__new(0);
HXLINE(  94)		bool _hx_tmp1;
HXDLIN(  94)		bool _hx_tmp2;
HXDLIN(  94)		if (::hx::IsNotEq( maj,-1 )) {
HXLINE(  94)			_hx_tmp2 = ::hx::IsEq( min,-1 );
            		}
            		else {
HXLINE(  94)			_hx_tmp2 = true;
            		}
HXDLIN(  94)		if (!(_hx_tmp2)) {
HXLINE(  94)			_hx_tmp1 = ::hx::IsEq( pat,-1 );
            		}
            		else {
HXLINE(  94)			_hx_tmp1 = true;
            		}
HXDLIN(  94)		if (_hx_tmp1) {
HXLINE(  96)			extra = HX_("",00,00,00,00);
            		}
HXLINE(  99)		bool _hx_tmp3;
HXDLIN(  99)		if (::hx::IsNotNull( extra )) {
HXLINE(  99)			_hx_tmp3 = (extra != HX_("",00,00,00,00));
            		}
            		else {
HXLINE(  99)			_hx_tmp3 = false;
            		}
HXDLIN(  99)		if (_hx_tmp3) {
HXLINE( 101)			if (::hx::IsGreater( maj,1 )) {
HXLINE( 102)				HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(((HX_("SemanticVersion.hx: pre-release version not allowed post 1.0.0! \"",ec,ab,29,6f) + str) + HX_("\"",22,00,00,00))));
            			}
HXLINE( 103)			if (::hx::IsEq( maj,1 )) {
HXLINE( 105)				if (::hx::IsGreater( min,0 )) {
HXLINE( 106)					HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(((HX_("SemanticVersion.hx: pre-release version not allowed post 1.0.0! \"",ec,ab,29,6f) + str) + HX_("\"",22,00,00,00))));
            				}
HXLINE( 107)				if (::hx::IsGreater( pat,0 )) {
HXLINE( 108)					HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(((HX_("SemanticVersion.hx: pre-release version not allowed post 1.0.0! \"",ec,ab,29,6f) + str) + HX_("\"",22,00,00,00))));
            				}
            			}
HXLINE( 110)			::Array< ::String > arr = extra.split(HX_(".",2e,00,00,00));
HXLINE( 111)			bool _hx_tmp;
HXDLIN( 111)			if (::hx::IsNotNull( arr )) {
HXLINE( 111)				_hx_tmp = (arr->length > 0);
            			}
            			else {
HXLINE( 111)				_hx_tmp = false;
            			}
HXDLIN( 111)			if (_hx_tmp) {
HXLINE( 113)				int _g = 0;
HXDLIN( 113)				while((_g < arr->length)){
HXLINE( 113)					::String substr = arr->__get(_g);
HXDLIN( 113)					_g = (_g + 1);
HXLINE( 115)					 ::Dynamic i = ::Std_obj::parseInt(substr);
HXLINE( 116)					if (::hx::IsNotNull( i )) {
HXLINE( 118)						bool _hx_tmp;
HXDLIN( 118)						if ((substr.length > 0)) {
HXLINE( 118)							_hx_tmp = (substr.charAt(0) == HX_("0",30,00,00,00));
            						}
            						else {
HXLINE( 118)							_hx_tmp = false;
            						}
HXDLIN( 118)						if (_hx_tmp) {
HXLINE( 120)							HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(((HX_("SemanticVersion.hx: no leading zeroes allowed! \"",1e,d6,ff,51) + str) + HX_("\"",22,00,00,00))));
            						}
            					}
HXLINE( 123)					v->preRelease->push(substr);
            				}
            			}
            		}
HXLINE( 127)		v->effective = (((((HX_("",00,00,00,00) + v->major) + HX_(".",2e,00,00,00)) + v->minor) + HX_(".",2e,00,00,00)) + v->patch);
HXLINE( 128)		bool _hx_tmp4;
HXDLIN( 128)		if (::hx::IsNotNull( v->preRelease )) {
HXLINE( 128)			_hx_tmp4 = (v->preRelease->length > 0);
            		}
            		else {
HXLINE( 128)			_hx_tmp4 = false;
            		}
HXDLIN( 128)		if (_hx_tmp4) {
HXLINE( 130)			 ::polymod::util::SemanticVersion v1 = v;
HXDLIN( 130)			::String v2 = v1->effective;
HXDLIN( 130)			v1->effective = (v2 + (HX_("-",2d,00,00,00) + v->preRelease->join(HX_(".",2e,00,00,00))));
            		}
HXLINE( 132)		return v;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(SemanticVersion_obj,fromString,return )


::hx::ObjectPtr< SemanticVersion_obj > SemanticVersion_obj::__new() {
	::hx::ObjectPtr< SemanticVersion_obj > __this = new SemanticVersion_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< SemanticVersion_obj > SemanticVersion_obj::__alloc(::hx::Ctx *_hx_ctx) {
	SemanticVersion_obj *__this = (SemanticVersion_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(SemanticVersion_obj), true, "polymod.util.SemanticVersion"));
	*(void **)__this = SemanticVersion_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

SemanticVersion_obj::SemanticVersion_obj()
{
}

void SemanticVersion_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SemanticVersion);
	HX_MARK_MEMBER_NAME(original,"original");
	HX_MARK_MEMBER_NAME(effective,"effective");
	HX_MARK_MEMBER_NAME(major,"major");
	HX_MARK_MEMBER_NAME(minor,"minor");
	HX_MARK_MEMBER_NAME(patch,"patch");
	HX_MARK_MEMBER_NAME(preRelease,"preRelease");
	HX_MARK_END_CLASS();
}

void SemanticVersion_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(original,"original");
	HX_VISIT_MEMBER_NAME(effective,"effective");
	HX_VISIT_MEMBER_NAME(major,"major");
	HX_VISIT_MEMBER_NAME(minor,"minor");
	HX_VISIT_MEMBER_NAME(patch,"patch");
	HX_VISIT_MEMBER_NAME(preRelease,"preRelease");
}

::hx::Val SemanticVersion_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"major") ) { return ::hx::Val( major ); }
		if (HX_FIELD_EQ(inName,"minor") ) { return ::hx::Val( minor ); }
		if (HX_FIELD_EQ(inName,"patch") ) { return ::hx::Val( patch ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"compare") ) { return ::hx::Val( compare_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"original") ) { return ::hx::Val( original ); }
		if (HX_FIELD_EQ(inName,"toString") ) { return ::hx::Val( toString_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"effective") ) { return ::hx::Val( effective ); }
		if (HX_FIELD_EQ(inName,"isEqualTo") ) { return ::hx::Val( isEqualTo_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"preRelease") ) { return ::hx::Val( preRelease ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"isNewerThan") ) { return ::hx::Val( isNewerThan_dyn() ); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"checkCompatibility") ) { return ::hx::Val( checkCompatibility_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

bool SemanticVersion_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"fromString") ) { outValue = fromString_dyn(); return true; }
	}
	return false;
}

::hx::Val SemanticVersion_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"major") ) { major=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"minor") ) { minor=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"patch") ) { patch=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"original") ) { original=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"effective") ) { effective=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"preRelease") ) { preRelease=inValue.Cast< ::Array< ::String > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SemanticVersion_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("original",51,34,e8,e0));
	outFields->push(HX_("effective",e7,e9,98,44));
	outFields->push(HX_("major",39,bd,1b,03));
	outFields->push(HX_("minor",35,7b,68,08));
	outFields->push(HX_("patch",c8,06,57,bd));
	outFields->push(HX_("preRelease",e4,e7,3a,c7));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo SemanticVersion_obj_sMemberStorageInfo[] = {
	{::hx::fsString,(int)offsetof(SemanticVersion_obj,original),HX_("original",51,34,e8,e0)},
	{::hx::fsString,(int)offsetof(SemanticVersion_obj,effective),HX_("effective",e7,e9,98,44)},
	{::hx::fsInt,(int)offsetof(SemanticVersion_obj,major),HX_("major",39,bd,1b,03)},
	{::hx::fsInt,(int)offsetof(SemanticVersion_obj,minor),HX_("minor",35,7b,68,08)},
	{::hx::fsInt,(int)offsetof(SemanticVersion_obj,patch),HX_("patch",c8,06,57,bd)},
	{::hx::fsObject /* ::Array< ::String > */ ,(int)offsetof(SemanticVersion_obj,preRelease),HX_("preRelease",e4,e7,3a,c7)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *SemanticVersion_obj_sStaticStorageInfo = 0;
#endif

static ::String SemanticVersion_obj_sMemberFields[] = {
	HX_("original",51,34,e8,e0),
	HX_("effective",e7,e9,98,44),
	HX_("major",39,bd,1b,03),
	HX_("minor",35,7b,68,08),
	HX_("patch",c8,06,57,bd),
	HX_("preRelease",e4,e7,3a,c7),
	HX_("checkCompatibility",48,9e,7e,76),
	HX_("compare",a5,18,69,83),
	HX_("isEqualTo",85,eb,9b,38),
	HX_("isNewerThan",84,cd,2b,a5),
	HX_("toString",ac,d0,6e,38),
	::String(null()) };

::hx::Class SemanticVersion_obj::__mClass;

static ::String SemanticVersion_obj_sStaticFields[] = {
	HX_("fromString",db,2d,74,54),
	::String(null())
};

void SemanticVersion_obj::__register()
{
	SemanticVersion_obj _hx_dummy;
	SemanticVersion_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("polymod.util.SemanticVersion",9e,a5,d9,14);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &SemanticVersion_obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(SemanticVersion_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(SemanticVersion_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< SemanticVersion_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = SemanticVersion_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = SemanticVersion_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace polymod
} // end namespace util
