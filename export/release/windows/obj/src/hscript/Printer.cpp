#include <hxcpp.h>

#ifndef INCLUDED_Lambda
#include <Lambda.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif
#ifndef INCLUDED_hscript_CType
#include <hscript/CType.h>
#endif
#ifndef INCLUDED_hscript_Const
#include <hscript/Const.h>
#endif
#ifndef INCLUDED_hscript_Error
#include <hscript/Error.h>
#endif
#ifndef INCLUDED_hscript_Expr
#include <hscript/Expr.h>
#endif
#ifndef INCLUDED_hscript_Printer
#include <hscript/Printer.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_84208ede1804668b_30_new,"hscript.Printer","new",0x5623a331,"hscript.Printer.new","hscript/Printer.hx",30,0xabbaf8a0)
HX_LOCAL_STACK_FRAME(_hx_pos_84208ede1804668b_33_exprToString,"hscript.Printer","exprToString",0x86701210,"hscript.Printer.exprToString","hscript/Printer.hx",33,0xabbaf8a0)
HX_LOCAL_STACK_FRAME(_hx_pos_84208ede1804668b_40_typeToString,"hscript.Printer","typeToString",0x2b439495,"hscript.Printer.typeToString","hscript/Printer.hx",40,0xabbaf8a0)
HX_LOCAL_STACK_FRAME(_hx_pos_84208ede1804668b_47_add,"hscript.Printer","add",0x5619c4f2,"hscript.Printer.add","hscript/Printer.hx",47,0xabbaf8a0)
HX_LOCAL_STACK_FRAME(_hx_pos_84208ede1804668b_50_type,"hscript.Printer","type",0x0d1196c9,"hscript.Printer.type","hscript/Printer.hx",50,0xabbaf8a0)
static const ::String _hx_array_data_648c36bf_9[] = {
	HX_("<",3c,00,00,00),
};
static const ::String _hx_array_data_648c36bf_10[] = {
	HX_(", ",74,26,00,00),
};
static const ::String _hx_array_data_648c36bf_11[] = {
	HX_(">",3e,00,00,00),
};
HX_LOCAL_STACK_FRAME(_hx_pos_84208ede1804668b_69_type,"hscript.Printer","type",0x0d1196c9,"hscript.Printer.type","hscript/Printer.hx",69,0xabbaf8a0)
static const ::String _hx_array_data_648c36bf_13[] = {
	HX_("(",28,00,00,00),
};
static const ::String _hx_array_data_648c36bf_14[] = {
	HX_(")->",da,43,1f,00),
};
static const ::String _hx_array_data_648c36bf_15[] = {
	HX_("Void -> ",e3,e8,94,e3),
};
static const ::String _hx_array_data_648c36bf_16[] = {
	HX_(" -> ",6f,2f,49,15),
};
static const ::String _hx_array_data_648c36bf_17[] = {
	HX_("{",7b,00,00,00),
};
static const ::String _hx_array_data_648c36bf_18[] = {
	HX_(" ",20,00,00,00),
};
static const ::String _hx_array_data_648c36bf_19[] = {
	HX_(", ",74,26,00,00),
};
static const ::String _hx_array_data_648c36bf_20[] = {
	HX_("(",28,00,00,00),
};
static const ::String _hx_array_data_648c36bf_21[] = {
	HX_(")",29,00,00,00),
};
static const ::String _hx_array_data_648c36bf_22[] = {
	HX_("?",3f,00,00,00),
};
static const ::String _hx_array_data_648c36bf_23[] = {
	HX_(":",3a,00,00,00),
};
HX_LOCAL_STACK_FRAME(_hx_pos_84208ede1804668b_105_addType,"hscript.Printer","addType",0xef2644cc,"hscript.Printer.addType","hscript/Printer.hx",105,0xabbaf8a0)
static const ::String _hx_array_data_648c36bf_25[] = {
	HX_(" : ",c6,7a,18,00),
};
HX_LOCAL_STACK_FRAME(_hx_pos_84208ede1804668b_111_expr,"hscript.Printer","expr",0x0326a144,"hscript.Printer.expr","hscript/Printer.hx",111,0xabbaf8a0)
static const ::String _hx_array_data_648c36bf_36[] = {
	HX_("??NULL??",87,dc,8d,a2),
};
static const ::String _hx_array_data_648c36bf_37[] = {
	HX_("\"",22,00,00,00),
};
static const ::String _hx_array_data_648c36bf_38[] = {
	HX_("\"",22,00,00,00),
};
static const ::String _hx_array_data_648c36bf_39[] = {
	HX_(" = ",63,7d,18,00),
};
static const ::String _hx_array_data_648c36bf_40[] = {
	HX_("(",28,00,00,00),
};
static const ::String _hx_array_data_648c36bf_41[] = {
	HX_(")",29,00,00,00),
};
static const ::String _hx_array_data_648c36bf_42[] = {
	HX_("{}",a2,6b,00,00),
};
static const ::String _hx_array_data_648c36bf_43[] = {
	HX_("{\n",2f,6b,00,00),
};
static const ::String _hx_array_data_648c36bf_44[] = {
	HX_(";\n",6f,33,00,00),
};
static const ::String _hx_array_data_648c36bf_45[] = {
	HX_("}",7d,00,00,00),
};
static const ::String _hx_array_data_648c36bf_46[] = {
	HX_("(",28,00,00,00),
};
static const ::String _hx_array_data_648c36bf_47[] = {
	HX_(")",29,00,00,00),
};
static const ::String _hx_array_data_648c36bf_48[] = {
	HX_("(",28,00,00,00),
};
static const ::String _hx_array_data_648c36bf_49[] = {
	HX_(", ",74,26,00,00),
};
static const ::String _hx_array_data_648c36bf_50[] = {
	HX_(")",29,00,00,00),
};
static const ::String _hx_array_data_648c36bf_51[] = {
	HX_("if( ",15,f0,b4,45),
};
static const ::String _hx_array_data_648c36bf_52[] = {
	HX_(" ) ",f7,6b,18,00),
};
static const ::String _hx_array_data_648c36bf_53[] = {
	HX_(" else ",27,c9,9e,3a),
};
static const ::String _hx_array_data_648c36bf_54[] = {
	HX_("while( ",e9,74,5a,a6),
};
static const ::String _hx_array_data_648c36bf_55[] = {
	HX_(" ) ",f7,6b,18,00),
};
static const ::String _hx_array_data_648c36bf_56[] = {
	HX_(" ) ",f7,6b,18,00),
};
static const ::String _hx_array_data_648c36bf_57[] = {
	HX_("break",bf,24,ec,b8),
};
static const ::String _hx_array_data_648c36bf_58[] = {
	HX_("continue",67,e0,c8,31),
};
static const ::String _hx_array_data_648c36bf_59[] = {
	HX_("function",18,ab,52,14),
};
static const ::String _hx_array_data_648c36bf_60[] = {
	HX_("(",28,00,00,00),
};
static const ::String _hx_array_data_648c36bf_61[] = {
	HX_(", ",74,26,00,00),
};
static const ::String _hx_array_data_648c36bf_62[] = {
	HX_("?",3f,00,00,00),
};
static const ::String _hx_array_data_648c36bf_63[] = {
	HX_(")",29,00,00,00),
};
static const ::String _hx_array_data_648c36bf_64[] = {
	HX_(" ",20,00,00,00),
};
static const ::String _hx_array_data_648c36bf_65[] = {
	HX_("return",b0,a4,2d,09),
};
static const ::String _hx_array_data_648c36bf_66[] = {
	HX_(" ",20,00,00,00),
};
static const ::String _hx_array_data_648c36bf_67[] = {
	HX_("[",5b,00,00,00),
};
static const ::String _hx_array_data_648c36bf_68[] = {
	HX_("]",5d,00,00,00),
};
static const ::String _hx_array_data_648c36bf_69[] = {
	HX_("[",5b,00,00,00),
};
static const ::String _hx_array_data_648c36bf_70[] = {
	HX_(", ",74,26,00,00),
};
static const ::String _hx_array_data_648c36bf_71[] = {
	HX_("]",5d,00,00,00),
};
static const ::String _hx_array_data_648c36bf_72[] = {
	HX_(", ",74,26,00,00),
};
static const ::String _hx_array_data_648c36bf_73[] = {
	HX_(")",29,00,00,00),
};
static const ::String _hx_array_data_648c36bf_74[] = {
	HX_("throw ",3a,24,c1,8e),
};
static const ::String _hx_array_data_648c36bf_75[] = {
	HX_("try ",85,aa,03,4d),
};
static const ::String _hx_array_data_648c36bf_76[] = {
	HX_(") ",d7,23,00,00),
};
static const ::String _hx_array_data_648c36bf_77[] = {
	HX_("{}",a2,6b,00,00),
};
static const ::String _hx_array_data_648c36bf_78[] = {
	HX_("{\n",2f,6b,00,00),
};
static const ::String _hx_array_data_648c36bf_79[] = {
	HX_(",\n",5e,26,00,00),
};
static const ::String _hx_array_data_648c36bf_80[] = {
	HX_("}",7d,00,00,00),
};
static const ::String _hx_array_data_648c36bf_81[] = {
	HX_(" ? ",21,7f,18,00),
};
static const ::String _hx_array_data_648c36bf_82[] = {
	HX_(" : ",c6,7a,18,00),
};
static const ::String _hx_array_data_648c36bf_83[] = {
	HX_("switch( ",ec,d1,d6,0d),
};
static const ::String _hx_array_data_648c36bf_84[] = {
	HX_(") {",c4,38,1f,00),
};
static const ::String _hx_array_data_648c36bf_85[] = {
	HX_("case ",70,bb,20,41),
};
static const ::String _hx_array_data_648c36bf_86[] = {
	HX_(", ",74,26,00,00),
};
static const ::String _hx_array_data_648c36bf_87[] = {
	HX_(": ",a6,32,00,00),
};
static const ::String _hx_array_data_648c36bf_88[] = {
	HX_(";\n",6f,33,00,00),
};
static const ::String _hx_array_data_648c36bf_89[] = {
	HX_("default: ",a7,7d,fc,f6),
};
static const ::String _hx_array_data_648c36bf_90[] = {
	HX_(";\n",6f,33,00,00),
};
static const ::String _hx_array_data_648c36bf_91[] = {
	HX_("}",7d,00,00,00),
};
static const ::String _hx_array_data_648c36bf_92[] = {
	HX_("do ",35,42,4c,00),
};
static const ::String _hx_array_data_648c36bf_93[] = {
	HX_(" while ( ",27,ec,f2,46),
};
static const ::String _hx_array_data_648c36bf_94[] = {
	HX_(" )",09,1c,00,00),
};
static const ::String _hx_array_data_648c36bf_95[] = {
	HX_("@",40,00,00,00),
};
static const ::String _hx_array_data_648c36bf_96[] = {
	HX_("(",28,00,00,00),
};
static const ::String _hx_array_data_648c36bf_97[] = {
	HX_(", ",74,26,00,00),
};
static const ::String _hx_array_data_648c36bf_98[] = {
	HX_(")",29,00,00,00),
};
static const ::String _hx_array_data_648c36bf_99[] = {
	HX_(" ",20,00,00,00),
};
static const ::String _hx_array_data_648c36bf_100[] = {
	HX_("(",28,00,00,00),
};
static const ::String _hx_array_data_648c36bf_101[] = {
	HX_(" : ",c6,7a,18,00),
};
static const ::String _hx_array_data_648c36bf_102[] = {
	HX_(")",29,00,00,00),
};
HX_LOCAL_STACK_FRAME(_hx_pos_84208ede1804668b_329_toString,"hscript.Printer","toString",0xf69c283b,"hscript.Printer.toString","hscript/Printer.hx",329,0xabbaf8a0)
HX_LOCAL_STACK_FRAME(_hx_pos_84208ede1804668b_332_errorToString,"hscript.Printer","errorToString",0x894742a5,"hscript.Printer.errorToString","hscript/Printer.hx",332,0xabbaf8a0)
namespace hscript{

void Printer_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_84208ede1804668b_30_new)
            	}

Dynamic Printer_obj::__CreateEmpty() { return new Printer_obj; }

void *Printer_obj::_hx_vtable = 0;

Dynamic Printer_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Printer_obj > _hx_result = new Printer_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool Printer_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x7ec3df13;
}

::String Printer_obj::exprToString( ::hscript::Expr e){
            	HX_GC_STACKFRAME(&_hx_pos_84208ede1804668b_33_exprToString)
HXLINE(  34)		this->buf =  ::StringBuf_obj::__alloc( HX_CTX );
HXLINE(  35)		this->tabs = HX_("",00,00,00,00);
HXLINE(  36)		this->expr(e);
HXLINE(  37)		return this->buf->toString();
            	}


HX_DEFINE_DYNAMIC_FUNC1(Printer_obj,exprToString,return )

::String Printer_obj::typeToString( ::hscript::CType t){
            	HX_GC_STACKFRAME(&_hx_pos_84208ede1804668b_40_typeToString)
HXLINE(  41)		this->buf =  ::StringBuf_obj::__alloc( HX_CTX );
HXLINE(  42)		this->tabs = HX_("",00,00,00,00);
HXLINE(  43)		this->type(t);
HXLINE(  44)		return this->buf->toString();
            	}


HX_DEFINE_DYNAMIC_FUNC1(Printer_obj,typeToString,return )

void Printer_obj::add( ::Dynamic s){
            	HX_STACKFRAME(&_hx_pos_84208ede1804668b_47_add)
HXDLIN(  47)		 ::StringBuf _this = this->buf;
HXDLIN(  47)		if (::hx::IsNotNull( _this->charBuf )) {
HXDLIN(  47)			_this->flush();
            		}
HXDLIN(  47)		if (::hx::IsNull( _this->b )) {
HXDLIN(  47)			_this->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(s));
            		}
            		else {
HXDLIN(  47)			::Array< ::String > _this1 = _this->b;
HXDLIN(  47)			_this1->push(::Std_obj::string(s));
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(Printer_obj,add,(void))

void Printer_obj::type( ::hscript::CType t){
            	HX_STACKFRAME(&_hx_pos_84208ede1804668b_50_type)
HXDLIN(  50)		switch((int)(t->_hx_getIndex())){
            			case (int)0: {
HXLINE(  54)				::Array< ::String > path = t->_hx_getObject(0).StaticCast< ::Array< ::String > >();
HXDLIN(  54)				::Array< ::Dynamic> params = t->_hx_getObject(1).StaticCast< ::Array< ::Dynamic> >();
HXDLIN(  54)				{
HXLINE(  55)					{
HXLINE(  55)						::String s = path->join(HX_(".",2e,00,00,00));
HXDLIN(  55)						 ::StringBuf _this = this->buf;
HXDLIN(  55)						if (::hx::IsNotNull( _this->charBuf )) {
HXLINE(  55)							_this->flush();
            						}
HXDLIN(  55)						if (::hx::IsNull( _this->b )) {
HXLINE(  55)							_this->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(s));
            						}
            						else {
HXLINE(  55)							::Array< ::String > _this1 = _this->b;
HXDLIN(  55)							_this1->push(::Std_obj::string(s));
            						}
            					}
HXLINE(  56)					if (::hx::IsNotNull( params )) {
HXLINE(  57)						{
HXLINE(  57)							 ::StringBuf _this = this->buf;
HXDLIN(  57)							if (::hx::IsNotNull( _this->charBuf )) {
HXLINE(  57)								_this->flush();
            							}
HXDLIN(  57)							if (::hx::IsNull( _this->b )) {
HXLINE(  57)								_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_9,1);
            							}
            							else {
HXLINE(  57)								_this->b->push(HX_("<",3c,00,00,00));
            							}
            						}
HXLINE(  58)						bool first = true;
HXLINE(  59)						{
HXLINE(  59)							int _g = 0;
HXDLIN(  59)							while((_g < params->length)){
HXLINE(  59)								 ::hscript::CType p = params->__get(_g).StaticCast<  ::hscript::CType >();
HXDLIN(  59)								_g = (_g + 1);
HXLINE(  60)								if (first) {
HXLINE(  60)									first = false;
            								}
            								else {
HXLINE(  60)									 ::StringBuf _this = this->buf;
HXDLIN(  60)									if (::hx::IsNotNull( _this->charBuf )) {
HXLINE(  60)										_this->flush();
            									}
HXDLIN(  60)									if (::hx::IsNull( _this->b )) {
HXLINE(  60)										_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_10,1);
            									}
            									else {
HXLINE(  60)										_this->b->push(HX_(", ",74,26,00,00));
            									}
            								}
HXLINE(  61)								this->type(p);
            							}
            						}
HXLINE(  63)						{
HXLINE(  63)							 ::StringBuf _this1 = this->buf;
HXDLIN(  63)							if (::hx::IsNotNull( _this1->charBuf )) {
HXLINE(  63)								_this1->flush();
            							}
HXDLIN(  63)							if (::hx::IsNull( _this1->b )) {
HXLINE(  63)								_this1->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_11,1);
            							}
            							else {
HXLINE(  63)								_this1->b->push(HX_(">",3e,00,00,00));
            							}
            						}
            					}
            				}
            			}
            			break;
            			case (int)1: {
HXLINE(  78)				::Array< ::Dynamic> _g = t->_hx_getObject(0).StaticCast< ::Array< ::Dynamic> >();
HXDLIN(  78)				 ::hscript::CType _g1 = t->_hx_getObject(1).StaticCast<  ::hscript::CType >();
HXLINE(  69)				{
            					HX_BEGIN_LOCAL_FUNC_S0(::hx::LocalFunc,_hx_Closure_0) HXARGC(1)
            					bool _hx_run( ::hscript::CType a){
            						HX_STACKFRAME(&_hx_pos_84208ede1804668b_69_type)
HXLINE(  69)						if ((a->_hx_getIndex() == 5)) {
HXLINE(  69)							::String _g = a->_hx_getString(0);
HXDLIN(  69)							 ::hscript::CType _g1 = a->_hx_getObject(1).StaticCast<  ::hscript::CType >();
HXDLIN(  69)							return true;
            						}
            						else {
HXLINE(  69)							return false;
            						}
HXDLIN(  69)						return false;
            					}
            					HX_END_LOCAL_FUNC1(return)

HXLINE(  69)					::Array< ::Dynamic> args = _g;
HXDLIN(  69)					 ::hscript::CType ret = _g1;
HXDLIN(  69)					if (::Lambda_obj::exists(args, ::Dynamic(new _hx_Closure_0()))) {
HXLINE(  70)						{
HXLINE(  70)							 ::StringBuf _this = this->buf;
HXDLIN(  70)							if (::hx::IsNotNull( _this->charBuf )) {
HXLINE(  70)								_this->flush();
            							}
HXDLIN(  70)							if (::hx::IsNull( _this->b )) {
HXLINE(  70)								_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_13,1);
            							}
            							else {
HXLINE(  70)								_this->b->push(HX_("(",28,00,00,00));
            							}
            						}
HXLINE(  71)						{
HXLINE(  71)							int _g = 0;
HXDLIN(  71)							while((_g < args->length)){
HXLINE(  71)								 ::hscript::CType a = args->__get(_g).StaticCast<  ::hscript::CType >();
HXDLIN(  71)								_g = (_g + 1);
HXLINE(  72)								if ((a->_hx_getIndex() == 5)) {
HXLINE(  73)									::String _g = a->_hx_getString(0);
HXDLIN(  73)									 ::hscript::CType _g1 = a->_hx_getObject(1).StaticCast<  ::hscript::CType >();
HXDLIN(  73)									this->type(a);
            								}
            								else {
HXLINE(  74)									this->type(::hscript::CType_obj::CTNamed(HX_("_",5f,00,00,00),a));
            								}
            							}
            						}
HXLINE(  76)						{
HXLINE(  76)							 ::StringBuf _this1 = this->buf;
HXDLIN(  76)							if (::hx::IsNotNull( _this1->charBuf )) {
HXLINE(  76)								_this1->flush();
            							}
HXDLIN(  76)							if (::hx::IsNull( _this1->b )) {
HXLINE(  76)								_this1->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_14,1);
            							}
            							else {
HXLINE(  76)								_this1->b->push(HX_(")->",da,43,1f,00));
            							}
            						}
HXLINE(  77)						this->type(ret);
            					}
            					else {
HXLINE(  78)						::Array< ::Dynamic> args = _g;
HXDLIN(  78)						 ::hscript::CType ret = _g1;
HXDLIN(  78)						{
HXLINE(  79)							if ((args->length == 0)) {
HXLINE(  80)								 ::StringBuf _this = this->buf;
HXDLIN(  80)								if (::hx::IsNotNull( _this->charBuf )) {
HXLINE(  80)									_this->flush();
            								}
HXDLIN(  80)								if (::hx::IsNull( _this->b )) {
HXLINE(  80)									_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_15,1);
            								}
            								else {
HXLINE(  80)									_this->b->push(HX_("Void -> ",e3,e8,94,e3));
            								}
            							}
            							else {
HXLINE(  82)								int _g = 0;
HXDLIN(  82)								while((_g < args->length)){
HXLINE(  82)									 ::hscript::CType a = args->__get(_g).StaticCast<  ::hscript::CType >();
HXDLIN(  82)									_g = (_g + 1);
HXLINE(  83)									this->type(a);
HXLINE(  84)									{
HXLINE(  84)										 ::StringBuf _this = this->buf;
HXDLIN(  84)										if (::hx::IsNotNull( _this->charBuf )) {
HXLINE(  84)											_this->flush();
            										}
HXDLIN(  84)										if (::hx::IsNull( _this->b )) {
HXLINE(  84)											_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_16,1);
            										}
            										else {
HXLINE(  84)											_this->b->push(HX_(" -> ",6f,2f,49,15));
            										}
            									}
            								}
            							}
HXLINE(  87)							this->type(ret);
            						}
            					}
            				}
            			}
            			break;
            			case (int)2: {
HXLINE(  88)				::Array< ::Dynamic> fields = t->_hx_getObject(0).StaticCast< ::Array< ::Dynamic> >();
HXDLIN(  88)				{
HXLINE(  89)					{
HXLINE(  89)						 ::StringBuf _this = this->buf;
HXDLIN(  89)						if (::hx::IsNotNull( _this->charBuf )) {
HXLINE(  89)							_this->flush();
            						}
HXDLIN(  89)						if (::hx::IsNull( _this->b )) {
HXLINE(  89)							_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_17,1);
            						}
            						else {
HXLINE(  89)							_this->b->push(HX_("{",7b,00,00,00));
            						}
            					}
HXLINE(  90)					bool first = true;
HXLINE(  91)					{
HXLINE(  91)						int _g = 0;
HXDLIN(  91)						while((_g < fields->length)){
HXLINE(  91)							 ::Dynamic f = fields->__get(_g);
HXDLIN(  91)							_g = (_g + 1);
HXLINE(  92)							if (first) {
HXLINE(  92)								first = false;
HXDLIN(  92)								{
HXLINE(  92)									 ::StringBuf _this = this->buf;
HXDLIN(  92)									if (::hx::IsNotNull( _this->charBuf )) {
HXLINE(  92)										_this->flush();
            									}
HXDLIN(  92)									if (::hx::IsNull( _this->b )) {
HXLINE(  92)										_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_18,1);
            									}
            									else {
HXLINE(  92)										_this->b->push(HX_(" ",20,00,00,00));
            									}
            								}
            							}
            							else {
HXLINE(  92)								 ::StringBuf _this = this->buf;
HXDLIN(  92)								if (::hx::IsNotNull( _this->charBuf )) {
HXLINE(  92)									_this->flush();
            								}
HXDLIN(  92)								if (::hx::IsNull( _this->b )) {
HXLINE(  92)									_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_19,1);
            								}
            								else {
HXLINE(  92)									_this->b->push(HX_(", ",74,26,00,00));
            								}
            							}
HXLINE(  93)							{
HXLINE(  93)								::String s = ( (::String)((f->__Field(HX_("name",4b,72,ff,48),::hx::paccDynamic) + HX_(" : ",c6,7a,18,00))) );
HXDLIN(  93)								 ::StringBuf _this = this->buf;
HXDLIN(  93)								if (::hx::IsNotNull( _this->charBuf )) {
HXLINE(  93)									_this->flush();
            								}
HXDLIN(  93)								if (::hx::IsNull( _this->b )) {
HXLINE(  93)									_this->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(s));
            								}
            								else {
HXLINE(  93)									::Array< ::String > _this1 = _this->b;
HXDLIN(  93)									_this1->push(::Std_obj::string(s));
            								}
            							}
HXLINE(  94)							this->type(f->__Field(HX_("t",74,00,00,00),::hx::paccDynamic));
            						}
            					}
HXLINE(  96)					{
HXLINE(  96)						::String s;
HXDLIN(  96)						if (first) {
HXLINE(  96)							s = HX_("}",7d,00,00,00);
            						}
            						else {
HXLINE(  96)							s = HX_(" }",5d,1c,00,00);
            						}
HXDLIN(  96)						 ::StringBuf _this1 = this->buf;
HXDLIN(  96)						if (::hx::IsNotNull( _this1->charBuf )) {
HXLINE(  96)							_this1->flush();
            						}
HXDLIN(  96)						if (::hx::IsNull( _this1->b )) {
HXLINE(  96)							_this1->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(s));
            						}
            						else {
HXLINE(  96)							::Array< ::String > _this = _this1->b;
HXDLIN(  96)							_this->push(::Std_obj::string(s));
            						}
            					}
            				}
            			}
            			break;
            			case (int)3: {
HXLINE(  97)				 ::hscript::CType t1 = t->_hx_getObject(0).StaticCast<  ::hscript::CType >();
HXDLIN(  97)				{
HXLINE(  98)					{
HXLINE(  98)						 ::StringBuf _this = this->buf;
HXDLIN(  98)						if (::hx::IsNotNull( _this->charBuf )) {
HXLINE(  98)							_this->flush();
            						}
HXDLIN(  98)						if (::hx::IsNull( _this->b )) {
HXLINE(  98)							_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_20,1);
            						}
            						else {
HXLINE(  98)							_this->b->push(HX_("(",28,00,00,00));
            						}
            					}
HXLINE(  99)					this->type(t1);
HXLINE( 100)					{
HXLINE( 100)						 ::StringBuf _this1 = this->buf;
HXDLIN( 100)						if (::hx::IsNotNull( _this1->charBuf )) {
HXLINE( 100)							_this1->flush();
            						}
HXDLIN( 100)						if (::hx::IsNull( _this1->b )) {
HXLINE( 100)							_this1->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_21,1);
            						}
            						else {
HXLINE( 100)							_this1->b->push(HX_(")",29,00,00,00));
            						}
            					}
            				}
            			}
            			break;
            			case (int)4: {
HXLINE(  51)				 ::hscript::CType t1 = t->_hx_getObject(0).StaticCast<  ::hscript::CType >();
HXDLIN(  51)				{
HXLINE(  52)					{
HXLINE(  52)						 ::StringBuf _this = this->buf;
HXDLIN(  52)						if (::hx::IsNotNull( _this->charBuf )) {
HXLINE(  52)							_this->flush();
            						}
HXDLIN(  52)						if (::hx::IsNull( _this->b )) {
HXLINE(  52)							_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_22,1);
            						}
            						else {
HXLINE(  52)							_this->b->push(HX_("?",3f,00,00,00));
            						}
            					}
HXLINE(  53)					this->type(t1);
            				}
            			}
            			break;
            			case (int)5: {
HXLINE(  65)				::String name = t->_hx_getString(0);
HXDLIN(  65)				 ::hscript::CType t1 = t->_hx_getObject(1).StaticCast<  ::hscript::CType >();
HXDLIN(  65)				{
HXLINE(  66)					{
HXLINE(  66)						 ::StringBuf _this = this->buf;
HXDLIN(  66)						if (::hx::IsNotNull( _this->charBuf )) {
HXLINE(  66)							_this->flush();
            						}
HXDLIN(  66)						if (::hx::IsNull( _this->b )) {
HXLINE(  66)							_this->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(name));
            						}
            						else {
HXLINE(  66)							::Array< ::String > _this1 = _this->b;
HXDLIN(  66)							_this1->push(::Std_obj::string(name));
            						}
            					}
HXLINE(  67)					{
HXLINE(  67)						 ::StringBuf _this1 = this->buf;
HXDLIN(  67)						if (::hx::IsNotNull( _this1->charBuf )) {
HXLINE(  67)							_this1->flush();
            						}
HXDLIN(  67)						if (::hx::IsNull( _this1->b )) {
HXLINE(  67)							_this1->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_23,1);
            						}
            						else {
HXLINE(  67)							_this1->b->push(HX_(":",3a,00,00,00));
            						}
            					}
HXLINE(  68)					this->type(t1);
            				}
            			}
            			break;
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(Printer_obj,type,(void))

void Printer_obj::addType( ::hscript::CType t){
            	HX_STACKFRAME(&_hx_pos_84208ede1804668b_105_addType)
HXDLIN( 105)		if (::hx::IsNotNull( t )) {
HXLINE( 106)			{
HXLINE( 106)				 ::StringBuf _this = this->buf;
HXDLIN( 106)				if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 106)					_this->flush();
            				}
HXDLIN( 106)				if (::hx::IsNull( _this->b )) {
HXLINE( 106)					_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_25,1);
            				}
            				else {
HXLINE( 106)					_this->b->push(HX_(" : ",c6,7a,18,00));
            				}
            			}
HXLINE( 107)			this->type(t);
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(Printer_obj,addType,(void))

void Printer_obj::expr( ::hscript::Expr e){
            	HX_STACKFRAME(&_hx_pos_84208ede1804668b_111_expr)
HXLINE( 112)		if (::hx::IsNull( e )) {
HXLINE( 113)			{
HXLINE( 113)				 ::StringBuf _this = this->buf;
HXDLIN( 113)				if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 113)					_this->flush();
            				}
HXDLIN( 113)				if (::hx::IsNull( _this->b )) {
HXLINE( 113)					_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_36,1);
            				}
            				else {
HXLINE( 113)					_this->b->push(HX_("??NULL??",87,dc,8d,a2));
            				}
            			}
HXLINE( 114)			return;
            		}
HXLINE( 116)		switch((int)(e->_hx_getIndex())){
            			case (int)0: {
HXLINE( 117)				 ::hscript::Const c = e->_hx_getObject(0).StaticCast<  ::hscript::Const >();
HXLINE( 118)				switch((int)(c->_hx_getIndex())){
            					case (int)0: {
HXLINE( 119)						int i = c->_hx_getInt(0);
HXDLIN( 119)						{
HXLINE( 119)							 ::StringBuf _this = this->buf;
HXDLIN( 119)							if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 119)								_this->flush();
            							}
HXDLIN( 119)							if (::hx::IsNull( _this->b )) {
HXLINE( 119)								_this->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(i));
            							}
            							else {
HXLINE( 119)								::Array< ::String > _this1 = _this->b;
HXDLIN( 119)								_this1->push(::Std_obj::string(i));
            							}
            						}
            					}
            					break;
            					case (int)1: {
HXLINE( 120)						Float f = c->_hx_getFloat(0);
HXDLIN( 120)						{
HXLINE( 120)							 ::StringBuf _this = this->buf;
HXDLIN( 120)							if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 120)								_this->flush();
            							}
HXDLIN( 120)							if (::hx::IsNull( _this->b )) {
HXLINE( 120)								_this->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(f));
            							}
            							else {
HXLINE( 120)								::Array< ::String > _this1 = _this->b;
HXDLIN( 120)								_this1->push(::Std_obj::string(f));
            							}
            						}
            					}
            					break;
            					case (int)2: {
HXLINE( 121)						::String s = c->_hx_getString(0);
HXDLIN( 121)						{
HXLINE( 121)							{
HXLINE( 121)								 ::StringBuf _this = this->buf;
HXDLIN( 121)								if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 121)									_this->flush();
            								}
HXDLIN( 121)								if (::hx::IsNull( _this->b )) {
HXLINE( 121)									_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_37,1);
            								}
            								else {
HXLINE( 121)									_this->b->push(HX_("\"",22,00,00,00));
            								}
            							}
HXDLIN( 121)							{
HXLINE( 121)								::String s1 = s.split(HX_("\"",22,00,00,00))->join(HX_("\\\"",46,50,00,00)).split(HX_("\n",0a,00,00,00))->join(HX_("\\n",92,50,00,00)).split(HX_("\r",0d,00,00,00))->join(HX_("\\r",96,50,00,00)).split(HX_("\t",09,00,00,00))->join(HX_("\\t",98,50,00,00));
HXDLIN( 121)								 ::StringBuf _this1 = this->buf;
HXDLIN( 121)								if (::hx::IsNotNull( _this1->charBuf )) {
HXLINE( 121)									_this1->flush();
            								}
HXDLIN( 121)								if (::hx::IsNull( _this1->b )) {
HXLINE( 121)									_this1->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(s1));
            								}
            								else {
HXLINE( 121)									::Array< ::String > _this = _this1->b;
HXDLIN( 121)									_this->push(::Std_obj::string(s1));
            								}
            							}
HXDLIN( 121)							{
HXLINE( 121)								 ::StringBuf _this2 = this->buf;
HXDLIN( 121)								if (::hx::IsNotNull( _this2->charBuf )) {
HXLINE( 121)									_this2->flush();
            								}
HXDLIN( 121)								if (::hx::IsNull( _this2->b )) {
HXLINE( 121)									_this2->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_38,1);
            								}
            								else {
HXLINE( 121)									_this2->b->push(HX_("\"",22,00,00,00));
            								}
            							}
            						}
            					}
            					break;
            				}
            			}
            			break;
            			case (int)1: {
HXLINE( 123)				::String v = e->_hx_getString(0);
HXLINE( 124)				{
HXLINE( 124)					 ::StringBuf _this = this->buf;
HXDLIN( 124)					if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 124)						_this->flush();
            					}
HXDLIN( 124)					if (::hx::IsNull( _this->b )) {
HXLINE( 124)						_this->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(v));
            					}
            					else {
HXLINE( 124)						::Array< ::String > _this1 = _this->b;
HXDLIN( 124)						_this1->push(::Std_obj::string(v));
            					}
            				}
            			}
            			break;
            			case (int)2: {
HXLINE( 125)				::String n = e->_hx_getString(0);
HXDLIN( 125)				 ::hscript::CType t = e->_hx_getObject(1).StaticCast<  ::hscript::CType >();
HXDLIN( 125)				 ::hscript::Expr e1 = e->_hx_getObject(2).StaticCast<  ::hscript::Expr >();
HXDLIN( 125)				{
HXLINE( 126)					{
HXLINE( 126)						::String s = (HX_("var ",59,2b,49,4e) + n);
HXDLIN( 126)						 ::StringBuf _this = this->buf;
HXDLIN( 126)						if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 126)							_this->flush();
            						}
HXDLIN( 126)						if (::hx::IsNull( _this->b )) {
HXLINE( 126)							_this->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(s));
            						}
            						else {
HXLINE( 126)							::Array< ::String > _this1 = _this->b;
HXDLIN( 126)							_this1->push(::Std_obj::string(s));
            						}
            					}
HXLINE( 127)					this->addType(t);
HXLINE( 128)					if (::hx::IsNotNull( e1 )) {
HXLINE( 129)						{
HXLINE( 129)							 ::StringBuf _this = this->buf;
HXDLIN( 129)							if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 129)								_this->flush();
            							}
HXDLIN( 129)							if (::hx::IsNull( _this->b )) {
HXLINE( 129)								_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_39,1);
            							}
            							else {
HXLINE( 129)								_this->b->push(HX_(" = ",63,7d,18,00));
            							}
            						}
HXLINE( 130)						this->expr(e1);
            					}
            				}
            			}
            			break;
            			case (int)3: {
HXLINE( 132)				 ::hscript::Expr e1 = e->_hx_getObject(0).StaticCast<  ::hscript::Expr >();
HXDLIN( 132)				{
HXLINE( 133)					{
HXLINE( 133)						 ::StringBuf _this = this->buf;
HXDLIN( 133)						if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 133)							_this->flush();
            						}
HXDLIN( 133)						if (::hx::IsNull( _this->b )) {
HXLINE( 133)							_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_40,1);
            						}
            						else {
HXLINE( 133)							_this->b->push(HX_("(",28,00,00,00));
            						}
            					}
HXDLIN( 133)					this->expr(e1);
HXDLIN( 133)					{
HXLINE( 133)						 ::StringBuf _this1 = this->buf;
HXDLIN( 133)						if (::hx::IsNotNull( _this1->charBuf )) {
HXLINE( 133)							_this1->flush();
            						}
HXDLIN( 133)						if (::hx::IsNull( _this1->b )) {
HXLINE( 133)							_this1->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_41,1);
            						}
            						else {
HXLINE( 133)							_this1->b->push(HX_(")",29,00,00,00));
            						}
            					}
            				}
            			}
            			break;
            			case (int)4: {
HXLINE( 134)				::Array< ::Dynamic> el = e->_hx_getObject(0).StaticCast< ::Array< ::Dynamic> >();
HXLINE( 135)				if ((el->length == 0)) {
HXLINE( 136)					 ::StringBuf _this = this->buf;
HXDLIN( 136)					if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 136)						_this->flush();
            					}
HXDLIN( 136)					if (::hx::IsNull( _this->b )) {
HXLINE( 136)						_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_42,1);
            					}
            					else {
HXLINE( 136)						_this->b->push(HX_("{}",a2,6b,00,00));
            					}
            				}
            				else {
HXLINE( 138)					 ::hscript::Printer _hx_tmp = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN( 138)					_hx_tmp->tabs = (_hx_tmp->tabs + HX_("\t",09,00,00,00));
HXLINE( 139)					{
HXLINE( 139)						 ::StringBuf _this = this->buf;
HXDLIN( 139)						if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 139)							_this->flush();
            						}
HXDLIN( 139)						if (::hx::IsNull( _this->b )) {
HXLINE( 139)							_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_43,1);
            						}
            						else {
HXLINE( 139)							_this->b->push(HX_("{\n",2f,6b,00,00));
            						}
            					}
HXLINE( 140)					{
HXLINE( 140)						int _g = 0;
HXDLIN( 140)						while((_g < el->length)){
HXLINE( 140)							 ::hscript::Expr e = el->__get(_g).StaticCast<  ::hscript::Expr >();
HXDLIN( 140)							_g = (_g + 1);
HXLINE( 141)							{
HXLINE( 141)								::String s = this->tabs;
HXDLIN( 141)								 ::StringBuf _this = this->buf;
HXDLIN( 141)								if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 141)									_this->flush();
            								}
HXDLIN( 141)								if (::hx::IsNull( _this->b )) {
HXLINE( 141)									_this->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(s));
            								}
            								else {
HXLINE( 141)									::Array< ::String > _this1 = _this->b;
HXDLIN( 141)									_this1->push(::Std_obj::string(s));
            								}
            							}
HXLINE( 142)							this->expr(e);
HXLINE( 143)							{
HXLINE( 143)								 ::StringBuf _this1 = this->buf;
HXDLIN( 143)								if (::hx::IsNotNull( _this1->charBuf )) {
HXLINE( 143)									_this1->flush();
            								}
HXDLIN( 143)								if (::hx::IsNull( _this1->b )) {
HXLINE( 143)									_this1->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_44,1);
            								}
            								else {
HXLINE( 143)									_this1->b->push(HX_(";\n",6f,33,00,00));
            								}
            							}
            						}
            					}
HXLINE( 145)					this->tabs = this->tabs.substr(1,null());
HXLINE( 146)					{
HXLINE( 146)						 ::StringBuf _this1 = this->buf;
HXDLIN( 146)						if (::hx::IsNotNull( _this1->charBuf )) {
HXLINE( 146)							_this1->flush();
            						}
HXDLIN( 146)						if (::hx::IsNull( _this1->b )) {
HXLINE( 146)							_this1->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_45,1);
            						}
            						else {
HXLINE( 146)							_this1->b->push(HX_("}",7d,00,00,00));
            						}
            					}
            				}
            			}
            			break;
            			case (int)5: {
HXLINE( 148)				 ::hscript::Expr e1 = e->_hx_getObject(0).StaticCast<  ::hscript::Expr >();
HXDLIN( 148)				::String f = e->_hx_getString(1);
HXDLIN( 148)				{
HXLINE( 149)					this->expr(e1);
HXLINE( 150)					{
HXLINE( 150)						::String s = (HX_(".",2e,00,00,00) + f);
HXDLIN( 150)						 ::StringBuf _this = this->buf;
HXDLIN( 150)						if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 150)							_this->flush();
            						}
HXDLIN( 150)						if (::hx::IsNull( _this->b )) {
HXLINE( 150)							_this->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(s));
            						}
            						else {
HXLINE( 150)							::Array< ::String > _this1 = _this->b;
HXDLIN( 150)							_this1->push(::Std_obj::string(s));
            						}
            					}
            				}
            			}
            			break;
            			case (int)6: {
HXLINE( 151)				::String op = e->_hx_getString(0);
HXDLIN( 151)				 ::hscript::Expr e1 = e->_hx_getObject(1).StaticCast<  ::hscript::Expr >();
HXDLIN( 151)				 ::hscript::Expr e2 = e->_hx_getObject(2).StaticCast<  ::hscript::Expr >();
HXDLIN( 151)				{
HXLINE( 152)					this->expr(e1);
HXLINE( 153)					{
HXLINE( 153)						::String s = ((HX_(" ",20,00,00,00) + op) + HX_(" ",20,00,00,00));
HXDLIN( 153)						 ::StringBuf _this = this->buf;
HXDLIN( 153)						if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 153)							_this->flush();
            						}
HXDLIN( 153)						if (::hx::IsNull( _this->b )) {
HXLINE( 153)							_this->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(s));
            						}
            						else {
HXLINE( 153)							::Array< ::String > _this1 = _this->b;
HXDLIN( 153)							_this1->push(::Std_obj::string(s));
            						}
            					}
HXLINE( 154)					this->expr(e2);
            				}
            			}
            			break;
            			case (int)7: {
HXLINE( 155)				::String op = e->_hx_getString(0);
HXDLIN( 155)				bool pre = e->_hx_getBool(1);
HXDLIN( 155)				 ::hscript::Expr e1 = e->_hx_getObject(2).StaticCast<  ::hscript::Expr >();
HXLINE( 156)				if (pre) {
HXLINE( 157)					{
HXLINE( 157)						 ::StringBuf _this = this->buf;
HXDLIN( 157)						if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 157)							_this->flush();
            						}
HXDLIN( 157)						if (::hx::IsNull( _this->b )) {
HXLINE( 157)							_this->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(op));
            						}
            						else {
HXLINE( 157)							::Array< ::String > _this1 = _this->b;
HXDLIN( 157)							_this1->push(::Std_obj::string(op));
            						}
            					}
HXLINE( 158)					this->expr(e1);
            				}
            				else {
HXLINE( 160)					this->expr(e1);
HXLINE( 161)					{
HXLINE( 161)						 ::StringBuf _this = this->buf;
HXDLIN( 161)						if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 161)							_this->flush();
            						}
HXDLIN( 161)						if (::hx::IsNull( _this->b )) {
HXLINE( 161)							_this->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(op));
            						}
            						else {
HXLINE( 161)							::Array< ::String > _this1 = _this->b;
HXDLIN( 161)							_this1->push(::Std_obj::string(op));
            						}
            					}
            				}
            			}
            			break;
            			case (int)8: {
HXLINE( 163)				 ::hscript::Expr e1 = e->_hx_getObject(0).StaticCast<  ::hscript::Expr >();
HXDLIN( 163)				::Array< ::Dynamic> args = e->_hx_getObject(1).StaticCast< ::Array< ::Dynamic> >();
HXDLIN( 163)				{
HXLINE( 164)					if (::hx::IsNull( e1 )) {
HXLINE( 165)						this->expr(e1);
            					}
            					else {
HXLINE( 166)						switch((int)(e1->_hx_getIndex())){
            							case (int)0: {
HXLINE( 167)								 ::hscript::Const _g = e1->_hx_getObject(0).StaticCast<  ::hscript::Const >();
HXLINE( 168)								this->expr(e1);
            							}
            							break;
            							case (int)1: {
HXLINE( 167)								::String _g = e1->_hx_getString(0);
HXLINE( 168)								this->expr(e1);
            							}
            							break;
            							case (int)5: {
HXLINE( 167)								 ::hscript::Expr _g = e1->_hx_getObject(0).StaticCast<  ::hscript::Expr >();
HXDLIN( 167)								::String _g1 = e1->_hx_getString(1);
HXLINE( 168)								this->expr(e1);
            							}
            							break;
            							default:{
HXLINE( 170)								{
HXLINE( 170)									 ::StringBuf _this = this->buf;
HXDLIN( 170)									if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 170)										_this->flush();
            									}
HXDLIN( 170)									if (::hx::IsNull( _this->b )) {
HXLINE( 170)										_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_46,1);
            									}
            									else {
HXLINE( 170)										_this->b->push(HX_("(",28,00,00,00));
            									}
            								}
HXLINE( 171)								this->expr(e1);
HXLINE( 172)								{
HXLINE( 172)									 ::StringBuf _this1 = this->buf;
HXDLIN( 172)									if (::hx::IsNotNull( _this1->charBuf )) {
HXLINE( 172)										_this1->flush();
            									}
HXDLIN( 172)									if (::hx::IsNull( _this1->b )) {
HXLINE( 172)										_this1->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_47,1);
            									}
            									else {
HXLINE( 172)										_this1->b->push(HX_(")",29,00,00,00));
            									}
            								}
            							}
            						}
            					}
HXLINE( 174)					{
HXLINE( 174)						 ::StringBuf _this = this->buf;
HXDLIN( 174)						if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 174)							_this->flush();
            						}
HXDLIN( 174)						if (::hx::IsNull( _this->b )) {
HXLINE( 174)							_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_48,1);
            						}
            						else {
HXLINE( 174)							_this->b->push(HX_("(",28,00,00,00));
            						}
            					}
HXLINE( 175)					bool first = true;
HXLINE( 176)					{
HXLINE( 176)						int _g = 0;
HXDLIN( 176)						while((_g < args->length)){
HXLINE( 176)							 ::hscript::Expr a = args->__get(_g).StaticCast<  ::hscript::Expr >();
HXDLIN( 176)							_g = (_g + 1);
HXLINE( 177)							if (first) {
HXLINE( 177)								first = false;
            							}
            							else {
HXLINE( 177)								 ::StringBuf _this = this->buf;
HXDLIN( 177)								if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 177)									_this->flush();
            								}
HXDLIN( 177)								if (::hx::IsNull( _this->b )) {
HXLINE( 177)									_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_49,1);
            								}
            								else {
HXLINE( 177)									_this->b->push(HX_(", ",74,26,00,00));
            								}
            							}
HXLINE( 178)							this->expr(a);
            						}
            					}
HXLINE( 180)					{
HXLINE( 180)						 ::StringBuf _this1 = this->buf;
HXDLIN( 180)						if (::hx::IsNotNull( _this1->charBuf )) {
HXLINE( 180)							_this1->flush();
            						}
HXDLIN( 180)						if (::hx::IsNull( _this1->b )) {
HXLINE( 180)							_this1->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_50,1);
            						}
            						else {
HXLINE( 180)							_this1->b->push(HX_(")",29,00,00,00));
            						}
            					}
            				}
            			}
            			break;
            			case (int)9: {
HXLINE( 181)				 ::hscript::Expr cond = e->_hx_getObject(0).StaticCast<  ::hscript::Expr >();
HXDLIN( 181)				 ::hscript::Expr e1 = e->_hx_getObject(1).StaticCast<  ::hscript::Expr >();
HXDLIN( 181)				 ::hscript::Expr e2 = e->_hx_getObject(2).StaticCast<  ::hscript::Expr >();
HXDLIN( 181)				{
HXLINE( 182)					{
HXLINE( 182)						 ::StringBuf _this = this->buf;
HXDLIN( 182)						if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 182)							_this->flush();
            						}
HXDLIN( 182)						if (::hx::IsNull( _this->b )) {
HXLINE( 182)							_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_51,1);
            						}
            						else {
HXLINE( 182)							_this->b->push(HX_("if( ",15,f0,b4,45));
            						}
            					}
HXLINE( 183)					this->expr(cond);
HXLINE( 184)					{
HXLINE( 184)						 ::StringBuf _this1 = this->buf;
HXDLIN( 184)						if (::hx::IsNotNull( _this1->charBuf )) {
HXLINE( 184)							_this1->flush();
            						}
HXDLIN( 184)						if (::hx::IsNull( _this1->b )) {
HXLINE( 184)							_this1->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_52,1);
            						}
            						else {
HXLINE( 184)							_this1->b->push(HX_(" ) ",f7,6b,18,00));
            						}
            					}
HXLINE( 185)					this->expr(e1);
HXLINE( 186)					if (::hx::IsNotNull( e2 )) {
HXLINE( 187)						{
HXLINE( 187)							 ::StringBuf _this = this->buf;
HXDLIN( 187)							if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 187)								_this->flush();
            							}
HXDLIN( 187)							if (::hx::IsNull( _this->b )) {
HXLINE( 187)								_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_53,1);
            							}
            							else {
HXLINE( 187)								_this->b->push(HX_(" else ",27,c9,9e,3a));
            							}
            						}
HXLINE( 188)						this->expr(e2);
            					}
            				}
            			}
            			break;
            			case (int)10: {
HXLINE( 190)				 ::hscript::Expr cond = e->_hx_getObject(0).StaticCast<  ::hscript::Expr >();
HXDLIN( 190)				 ::hscript::Expr e1 = e->_hx_getObject(1).StaticCast<  ::hscript::Expr >();
HXDLIN( 190)				{
HXLINE( 191)					{
HXLINE( 191)						 ::StringBuf _this = this->buf;
HXDLIN( 191)						if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 191)							_this->flush();
            						}
HXDLIN( 191)						if (::hx::IsNull( _this->b )) {
HXLINE( 191)							_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_54,1);
            						}
            						else {
HXLINE( 191)							_this->b->push(HX_("while( ",e9,74,5a,a6));
            						}
            					}
HXLINE( 192)					this->expr(cond);
HXLINE( 193)					{
HXLINE( 193)						 ::StringBuf _this1 = this->buf;
HXDLIN( 193)						if (::hx::IsNotNull( _this1->charBuf )) {
HXLINE( 193)							_this1->flush();
            						}
HXDLIN( 193)						if (::hx::IsNull( _this1->b )) {
HXLINE( 193)							_this1->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_55,1);
            						}
            						else {
HXLINE( 193)							_this1->b->push(HX_(" ) ",f7,6b,18,00));
            						}
            					}
HXLINE( 194)					this->expr(e1);
            				}
            			}
            			break;
            			case (int)11: {
HXLINE( 201)				::String v = e->_hx_getString(0);
HXDLIN( 201)				 ::hscript::Expr it = e->_hx_getObject(1).StaticCast<  ::hscript::Expr >();
HXDLIN( 201)				 ::hscript::Expr e1 = e->_hx_getObject(2).StaticCast<  ::hscript::Expr >();
HXDLIN( 201)				{
HXLINE( 202)					{
HXLINE( 202)						::String s = ((HX_("for( ",41,7e,94,04) + v) + HX_(" in ",7b,e0,76,15));
HXDLIN( 202)						 ::StringBuf _this = this->buf;
HXDLIN( 202)						if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 202)							_this->flush();
            						}
HXDLIN( 202)						if (::hx::IsNull( _this->b )) {
HXLINE( 202)							_this->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(s));
            						}
            						else {
HXLINE( 202)							::Array< ::String > _this1 = _this->b;
HXDLIN( 202)							_this1->push(::Std_obj::string(s));
            						}
            					}
HXLINE( 203)					this->expr(it);
HXLINE( 204)					{
HXLINE( 204)						 ::StringBuf _this1 = this->buf;
HXDLIN( 204)						if (::hx::IsNotNull( _this1->charBuf )) {
HXLINE( 204)							_this1->flush();
            						}
HXDLIN( 204)						if (::hx::IsNull( _this1->b )) {
HXLINE( 204)							_this1->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_56,1);
            						}
            						else {
HXLINE( 204)							_this1->b->push(HX_(" ) ",f7,6b,18,00));
            						}
            					}
HXLINE( 205)					this->expr(e1);
            				}
            			}
            			break;
            			case (int)12: {
HXLINE( 207)				 ::StringBuf _this = this->buf;
HXDLIN( 207)				if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 207)					_this->flush();
            				}
HXDLIN( 207)				if (::hx::IsNull( _this->b )) {
HXLINE( 207)					_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_57,1);
            				}
            				else {
HXLINE( 207)					_this->b->push(HX_("break",bf,24,ec,b8));
            				}
            			}
            			break;
            			case (int)13: {
HXLINE( 209)				 ::StringBuf _this = this->buf;
HXDLIN( 209)				if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 209)					_this->flush();
            				}
HXDLIN( 209)				if (::hx::IsNull( _this->b )) {
HXLINE( 209)					_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_58,1);
            				}
            				else {
HXLINE( 209)					_this->b->push(HX_("continue",67,e0,c8,31));
            				}
            			}
            			break;
            			case (int)14: {
HXLINE( 210)				::Array< ::Dynamic> params = e->_hx_getObject(0).StaticCast< ::Array< ::Dynamic> >();
HXDLIN( 210)				 ::hscript::Expr e1 = e->_hx_getObject(1).StaticCast<  ::hscript::Expr >();
HXDLIN( 210)				::String name = e->_hx_getString(2);
HXDLIN( 210)				 ::hscript::CType ret = e->_hx_getObject(3).StaticCast<  ::hscript::CType >();
HXDLIN( 210)				{
HXLINE( 211)					{
HXLINE( 211)						 ::StringBuf _this = this->buf;
HXDLIN( 211)						if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 211)							_this->flush();
            						}
HXDLIN( 211)						if (::hx::IsNull( _this->b )) {
HXLINE( 211)							_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_59,1);
            						}
            						else {
HXLINE( 211)							_this->b->push(HX_("function",18,ab,52,14));
            						}
            					}
HXLINE( 212)					if (::hx::IsNotNull( name )) {
HXLINE( 213)						::String s = (HX_(" ",20,00,00,00) + name);
HXDLIN( 213)						 ::StringBuf _this = this->buf;
HXDLIN( 213)						if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 213)							_this->flush();
            						}
HXDLIN( 213)						if (::hx::IsNull( _this->b )) {
HXLINE( 213)							_this->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(s));
            						}
            						else {
HXLINE( 213)							::Array< ::String > _this1 = _this->b;
HXDLIN( 213)							_this1->push(::Std_obj::string(s));
            						}
            					}
HXLINE( 214)					{
HXLINE( 214)						 ::StringBuf _this1 = this->buf;
HXDLIN( 214)						if (::hx::IsNotNull( _this1->charBuf )) {
HXLINE( 214)							_this1->flush();
            						}
HXDLIN( 214)						if (::hx::IsNull( _this1->b )) {
HXLINE( 214)							_this1->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_60,1);
            						}
            						else {
HXLINE( 214)							_this1->b->push(HX_("(",28,00,00,00));
            						}
            					}
HXLINE( 215)					bool first = true;
HXLINE( 216)					{
HXLINE( 216)						int _g = 0;
HXDLIN( 216)						while((_g < params->length)){
HXLINE( 216)							 ::Dynamic a = params->__get(_g);
HXDLIN( 216)							_g = (_g + 1);
HXLINE( 217)							if (first) {
HXLINE( 217)								first = false;
            							}
            							else {
HXLINE( 217)								 ::StringBuf _this = this->buf;
HXDLIN( 217)								if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 217)									_this->flush();
            								}
HXDLIN( 217)								if (::hx::IsNull( _this->b )) {
HXLINE( 217)									_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_61,1);
            								}
            								else {
HXLINE( 217)									_this->b->push(HX_(", ",74,26,00,00));
            								}
            							}
HXLINE( 218)							if (( (bool)(a->__Field(HX_("opt",33,9c,54,00),::hx::paccDynamic)) )) {
HXLINE( 218)								 ::StringBuf _this = this->buf;
HXDLIN( 218)								if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 218)									_this->flush();
            								}
HXDLIN( 218)								if (::hx::IsNull( _this->b )) {
HXLINE( 218)									_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_62,1);
            								}
            								else {
HXLINE( 218)									_this->b->push(HX_("?",3f,00,00,00));
            								}
            							}
HXLINE( 219)							{
HXLINE( 219)								::String s = ( (::String)(a->__Field(HX_("name",4b,72,ff,48),::hx::paccDynamic)) );
HXDLIN( 219)								 ::StringBuf _this = this->buf;
HXDLIN( 219)								if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 219)									_this->flush();
            								}
HXDLIN( 219)								if (::hx::IsNull( _this->b )) {
HXLINE( 219)									_this->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(s));
            								}
            								else {
HXLINE( 219)									::Array< ::String > _this1 = _this->b;
HXDLIN( 219)									_this1->push(::Std_obj::string(s));
            								}
            							}
HXLINE( 220)							this->addType(a->__Field(HX_("t",74,00,00,00),::hx::paccDynamic));
            						}
            					}
HXLINE( 222)					{
HXLINE( 222)						 ::StringBuf _this2 = this->buf;
HXDLIN( 222)						if (::hx::IsNotNull( _this2->charBuf )) {
HXLINE( 222)							_this2->flush();
            						}
HXDLIN( 222)						if (::hx::IsNull( _this2->b )) {
HXLINE( 222)							_this2->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_63,1);
            						}
            						else {
HXLINE( 222)							_this2->b->push(HX_(")",29,00,00,00));
            						}
            					}
HXLINE( 223)					this->addType(ret);
HXLINE( 224)					{
HXLINE( 224)						 ::StringBuf _this3 = this->buf;
HXDLIN( 224)						if (::hx::IsNotNull( _this3->charBuf )) {
HXLINE( 224)							_this3->flush();
            						}
HXDLIN( 224)						if (::hx::IsNull( _this3->b )) {
HXLINE( 224)							_this3->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_64,1);
            						}
            						else {
HXLINE( 224)							_this3->b->push(HX_(" ",20,00,00,00));
            						}
            					}
HXLINE( 225)					this->expr(e1);
            				}
            			}
            			break;
            			case (int)15: {
HXLINE( 226)				 ::hscript::Expr e1 = e->_hx_getObject(0).StaticCast<  ::hscript::Expr >();
HXDLIN( 226)				{
HXLINE( 227)					{
HXLINE( 227)						 ::StringBuf _this = this->buf;
HXDLIN( 227)						if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 227)							_this->flush();
            						}
HXDLIN( 227)						if (::hx::IsNull( _this->b )) {
HXLINE( 227)							_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_65,1);
            						}
            						else {
HXLINE( 227)							_this->b->push(HX_("return",b0,a4,2d,09));
            						}
            					}
HXLINE( 228)					if (::hx::IsNotNull( e1 )) {
HXLINE( 229)						{
HXLINE( 229)							 ::StringBuf _this = this->buf;
HXDLIN( 229)							if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 229)								_this->flush();
            							}
HXDLIN( 229)							if (::hx::IsNull( _this->b )) {
HXLINE( 229)								_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_66,1);
            							}
            							else {
HXLINE( 229)								_this->b->push(HX_(" ",20,00,00,00));
            							}
            						}
HXLINE( 230)						this->expr(e1);
            					}
            				}
            			}
            			break;
            			case (int)16: {
HXLINE( 232)				 ::hscript::Expr e1 = e->_hx_getObject(0).StaticCast<  ::hscript::Expr >();
HXDLIN( 232)				 ::hscript::Expr index = e->_hx_getObject(1).StaticCast<  ::hscript::Expr >();
HXDLIN( 232)				{
HXLINE( 233)					this->expr(e1);
HXLINE( 234)					{
HXLINE( 234)						 ::StringBuf _this = this->buf;
HXDLIN( 234)						if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 234)							_this->flush();
            						}
HXDLIN( 234)						if (::hx::IsNull( _this->b )) {
HXLINE( 234)							_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_67,1);
            						}
            						else {
HXLINE( 234)							_this->b->push(HX_("[",5b,00,00,00));
            						}
            					}
HXLINE( 235)					this->expr(index);
HXLINE( 236)					{
HXLINE( 236)						 ::StringBuf _this1 = this->buf;
HXDLIN( 236)						if (::hx::IsNotNull( _this1->charBuf )) {
HXLINE( 236)							_this1->flush();
            						}
HXDLIN( 236)						if (::hx::IsNull( _this1->b )) {
HXLINE( 236)							_this1->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_68,1);
            						}
            						else {
HXLINE( 236)							_this1->b->push(HX_("]",5d,00,00,00));
            						}
            					}
            				}
            			}
            			break;
            			case (int)17: {
HXLINE( 237)				::Array< ::Dynamic> el = e->_hx_getObject(0).StaticCast< ::Array< ::Dynamic> >();
HXDLIN( 237)				{
HXLINE( 238)					{
HXLINE( 238)						 ::StringBuf _this = this->buf;
HXDLIN( 238)						if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 238)							_this->flush();
            						}
HXDLIN( 238)						if (::hx::IsNull( _this->b )) {
HXLINE( 238)							_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_69,1);
            						}
            						else {
HXLINE( 238)							_this->b->push(HX_("[",5b,00,00,00));
            						}
            					}
HXLINE( 239)					bool first = true;
HXLINE( 240)					{
HXLINE( 240)						int _g = 0;
HXDLIN( 240)						while((_g < el->length)){
HXLINE( 240)							 ::hscript::Expr e = el->__get(_g).StaticCast<  ::hscript::Expr >();
HXDLIN( 240)							_g = (_g + 1);
HXLINE( 241)							if (first) {
HXLINE( 241)								first = false;
            							}
            							else {
HXLINE( 241)								 ::StringBuf _this = this->buf;
HXDLIN( 241)								if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 241)									_this->flush();
            								}
HXDLIN( 241)								if (::hx::IsNull( _this->b )) {
HXLINE( 241)									_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_70,1);
            								}
            								else {
HXLINE( 241)									_this->b->push(HX_(", ",74,26,00,00));
            								}
            							}
HXLINE( 242)							this->expr(e);
            						}
            					}
HXLINE( 244)					{
HXLINE( 244)						 ::StringBuf _this1 = this->buf;
HXDLIN( 244)						if (::hx::IsNotNull( _this1->charBuf )) {
HXLINE( 244)							_this1->flush();
            						}
HXDLIN( 244)						if (::hx::IsNull( _this1->b )) {
HXLINE( 244)							_this1->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_71,1);
            						}
            						else {
HXLINE( 244)							_this1->b->push(HX_("]",5d,00,00,00));
            						}
            					}
            				}
            			}
            			break;
            			case (int)18: {
HXLINE( 245)				::String cl = e->_hx_getString(0);
HXDLIN( 245)				::Array< ::Dynamic> args = e->_hx_getObject(1).StaticCast< ::Array< ::Dynamic> >();
HXDLIN( 245)				{
HXLINE( 246)					{
HXLINE( 246)						::String s = ((HX_("new ",c0,83,02,49) + cl) + HX_("(",28,00,00,00));
HXDLIN( 246)						 ::StringBuf _this = this->buf;
HXDLIN( 246)						if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 246)							_this->flush();
            						}
HXDLIN( 246)						if (::hx::IsNull( _this->b )) {
HXLINE( 246)							_this->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(s));
            						}
            						else {
HXLINE( 246)							::Array< ::String > _this1 = _this->b;
HXDLIN( 246)							_this1->push(::Std_obj::string(s));
            						}
            					}
HXLINE( 247)					bool first = true;
HXLINE( 248)					{
HXLINE( 248)						int _g = 0;
HXDLIN( 248)						while((_g < args->length)){
HXLINE( 248)							 ::hscript::Expr e = args->__get(_g).StaticCast<  ::hscript::Expr >();
HXDLIN( 248)							_g = (_g + 1);
HXLINE( 249)							if (first) {
HXLINE( 249)								first = false;
            							}
            							else {
HXLINE( 249)								 ::StringBuf _this = this->buf;
HXDLIN( 249)								if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 249)									_this->flush();
            								}
HXDLIN( 249)								if (::hx::IsNull( _this->b )) {
HXLINE( 249)									_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_72,1);
            								}
            								else {
HXLINE( 249)									_this->b->push(HX_(", ",74,26,00,00));
            								}
            							}
HXLINE( 250)							this->expr(e);
            						}
            					}
HXLINE( 252)					{
HXLINE( 252)						 ::StringBuf _this1 = this->buf;
HXDLIN( 252)						if (::hx::IsNotNull( _this1->charBuf )) {
HXLINE( 252)							_this1->flush();
            						}
HXDLIN( 252)						if (::hx::IsNull( _this1->b )) {
HXLINE( 252)							_this1->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_73,1);
            						}
            						else {
HXLINE( 252)							_this1->b->push(HX_(")",29,00,00,00));
            						}
            					}
            				}
            			}
            			break;
            			case (int)19: {
HXLINE( 253)				 ::hscript::Expr e1 = e->_hx_getObject(0).StaticCast<  ::hscript::Expr >();
HXDLIN( 253)				{
HXLINE( 254)					{
HXLINE( 254)						 ::StringBuf _this = this->buf;
HXDLIN( 254)						if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 254)							_this->flush();
            						}
HXDLIN( 254)						if (::hx::IsNull( _this->b )) {
HXLINE( 254)							_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_74,1);
            						}
            						else {
HXLINE( 254)							_this->b->push(HX_("throw ",3a,24,c1,8e));
            						}
            					}
HXLINE( 255)					this->expr(e1);
            				}
            			}
            			break;
            			case (int)20: {
HXLINE( 256)				 ::hscript::Expr e1 = e->_hx_getObject(0).StaticCast<  ::hscript::Expr >();
HXDLIN( 256)				::String v = e->_hx_getString(1);
HXDLIN( 256)				 ::hscript::CType t = e->_hx_getObject(2).StaticCast<  ::hscript::CType >();
HXDLIN( 256)				 ::hscript::Expr ecatch = e->_hx_getObject(3).StaticCast<  ::hscript::Expr >();
HXDLIN( 256)				{
HXLINE( 257)					{
HXLINE( 257)						 ::StringBuf _this = this->buf;
HXDLIN( 257)						if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 257)							_this->flush();
            						}
HXDLIN( 257)						if (::hx::IsNull( _this->b )) {
HXLINE( 257)							_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_75,1);
            						}
            						else {
HXLINE( 257)							_this->b->push(HX_("try ",85,aa,03,4d));
            						}
            					}
HXLINE( 258)					this->expr(e1);
HXLINE( 259)					{
HXLINE( 259)						::String s = (HX_(" catch( ",d3,a7,f3,0f) + v);
HXDLIN( 259)						 ::StringBuf _this1 = this->buf;
HXDLIN( 259)						if (::hx::IsNotNull( _this1->charBuf )) {
HXLINE( 259)							_this1->flush();
            						}
HXDLIN( 259)						if (::hx::IsNull( _this1->b )) {
HXLINE( 259)							_this1->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(s));
            						}
            						else {
HXLINE( 259)							::Array< ::String > _this = _this1->b;
HXDLIN( 259)							_this->push(::Std_obj::string(s));
            						}
            					}
HXLINE( 260)					this->addType(t);
HXLINE( 261)					{
HXLINE( 261)						 ::StringBuf _this2 = this->buf;
HXDLIN( 261)						if (::hx::IsNotNull( _this2->charBuf )) {
HXLINE( 261)							_this2->flush();
            						}
HXDLIN( 261)						if (::hx::IsNull( _this2->b )) {
HXLINE( 261)							_this2->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_76,1);
            						}
            						else {
HXLINE( 261)							_this2->b->push(HX_(") ",d7,23,00,00));
            						}
            					}
HXLINE( 262)					this->expr(ecatch);
            				}
            			}
            			break;
            			case (int)21: {
HXLINE( 263)				::Array< ::Dynamic> fl = e->_hx_getObject(0).StaticCast< ::Array< ::Dynamic> >();
HXLINE( 264)				if ((fl->length == 0)) {
HXLINE( 265)					 ::StringBuf _this = this->buf;
HXDLIN( 265)					if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 265)						_this->flush();
            					}
HXDLIN( 265)					if (::hx::IsNull( _this->b )) {
HXLINE( 265)						_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_77,1);
            					}
            					else {
HXLINE( 265)						_this->b->push(HX_("{}",a2,6b,00,00));
            					}
            				}
            				else {
HXLINE( 267)					 ::hscript::Printer _hx_tmp = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN( 267)					_hx_tmp->tabs = (_hx_tmp->tabs + HX_("\t",09,00,00,00));
HXLINE( 268)					{
HXLINE( 268)						 ::StringBuf _this = this->buf;
HXDLIN( 268)						if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 268)							_this->flush();
            						}
HXDLIN( 268)						if (::hx::IsNull( _this->b )) {
HXLINE( 268)							_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_78,1);
            						}
            						else {
HXLINE( 268)							_this->b->push(HX_("{\n",2f,6b,00,00));
            						}
            					}
HXLINE( 269)					{
HXLINE( 269)						int _g = 0;
HXDLIN( 269)						while((_g < fl->length)){
HXLINE( 269)							 ::Dynamic f = fl->__get(_g);
HXDLIN( 269)							_g = (_g + 1);
HXLINE( 270)							{
HXLINE( 270)								::String s = this->tabs;
HXDLIN( 270)								 ::StringBuf _this = this->buf;
HXDLIN( 270)								if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 270)									_this->flush();
            								}
HXDLIN( 270)								if (::hx::IsNull( _this->b )) {
HXLINE( 270)									_this->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(s));
            								}
            								else {
HXLINE( 270)									::Array< ::String > _this1 = _this->b;
HXDLIN( 270)									_this1->push(::Std_obj::string(s));
            								}
            							}
HXLINE( 271)							{
HXLINE( 271)								::String s1 = ( (::String)((f->__Field(HX_("name",4b,72,ff,48),::hx::paccDynamic) + HX_(" : ",c6,7a,18,00))) );
HXDLIN( 271)								 ::StringBuf _this1 = this->buf;
HXDLIN( 271)								if (::hx::IsNotNull( _this1->charBuf )) {
HXLINE( 271)									_this1->flush();
            								}
HXDLIN( 271)								if (::hx::IsNull( _this1->b )) {
HXLINE( 271)									_this1->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(s1));
            								}
            								else {
HXLINE( 271)									::Array< ::String > _this = _this1->b;
HXDLIN( 271)									_this->push(::Std_obj::string(s1));
            								}
            							}
HXLINE( 272)							this->expr(f->__Field(HX_("e",65,00,00,00),::hx::paccDynamic));
HXLINE( 273)							{
HXLINE( 273)								 ::StringBuf _this2 = this->buf;
HXDLIN( 273)								if (::hx::IsNotNull( _this2->charBuf )) {
HXLINE( 273)									_this2->flush();
            								}
HXDLIN( 273)								if (::hx::IsNull( _this2->b )) {
HXLINE( 273)									_this2->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_79,1);
            								}
            								else {
HXLINE( 273)									_this2->b->push(HX_(",\n",5e,26,00,00));
            								}
            							}
            						}
            					}
HXLINE( 275)					this->tabs = this->tabs.substr(1,null());
HXLINE( 276)					{
HXLINE( 276)						 ::StringBuf _this1 = this->buf;
HXDLIN( 276)						if (::hx::IsNotNull( _this1->charBuf )) {
HXLINE( 276)							_this1->flush();
            						}
HXDLIN( 276)						if (::hx::IsNull( _this1->b )) {
HXLINE( 276)							_this1->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_80,1);
            						}
            						else {
HXLINE( 276)							_this1->b->push(HX_("}",7d,00,00,00));
            						}
            					}
            				}
            			}
            			break;
            			case (int)22: {
HXLINE( 278)				 ::hscript::Expr c = e->_hx_getObject(0).StaticCast<  ::hscript::Expr >();
HXDLIN( 278)				 ::hscript::Expr e1 = e->_hx_getObject(1).StaticCast<  ::hscript::Expr >();
HXDLIN( 278)				 ::hscript::Expr e2 = e->_hx_getObject(2).StaticCast<  ::hscript::Expr >();
HXDLIN( 278)				{
HXLINE( 279)					this->expr(c);
HXLINE( 280)					{
HXLINE( 280)						 ::StringBuf _this = this->buf;
HXDLIN( 280)						if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 280)							_this->flush();
            						}
HXDLIN( 280)						if (::hx::IsNull( _this->b )) {
HXLINE( 280)							_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_81,1);
            						}
            						else {
HXLINE( 280)							_this->b->push(HX_(" ? ",21,7f,18,00));
            						}
            					}
HXLINE( 281)					this->expr(e1);
HXLINE( 282)					{
HXLINE( 282)						 ::StringBuf _this1 = this->buf;
HXDLIN( 282)						if (::hx::IsNotNull( _this1->charBuf )) {
HXLINE( 282)							_this1->flush();
            						}
HXDLIN( 282)						if (::hx::IsNull( _this1->b )) {
HXLINE( 282)							_this1->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_82,1);
            						}
            						else {
HXLINE( 282)							_this1->b->push(HX_(" : ",c6,7a,18,00));
            						}
            					}
HXLINE( 283)					this->expr(e2);
            				}
            			}
            			break;
            			case (int)23: {
HXLINE( 284)				 ::hscript::Expr e1 = e->_hx_getObject(0).StaticCast<  ::hscript::Expr >();
HXDLIN( 284)				::Array< ::Dynamic> cases = e->_hx_getObject(1).StaticCast< ::Array< ::Dynamic> >();
HXDLIN( 284)				 ::hscript::Expr def = e->_hx_getObject(2).StaticCast<  ::hscript::Expr >();
HXDLIN( 284)				{
HXLINE( 285)					{
HXLINE( 285)						 ::StringBuf _this = this->buf;
HXDLIN( 285)						if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 285)							_this->flush();
            						}
HXDLIN( 285)						if (::hx::IsNull( _this->b )) {
HXLINE( 285)							_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_83,1);
            						}
            						else {
HXLINE( 285)							_this->b->push(HX_("switch( ",ec,d1,d6,0d));
            						}
            					}
HXLINE( 286)					this->expr(e1);
HXLINE( 287)					{
HXLINE( 287)						 ::StringBuf _this1 = this->buf;
HXDLIN( 287)						if (::hx::IsNotNull( _this1->charBuf )) {
HXLINE( 287)							_this1->flush();
            						}
HXDLIN( 287)						if (::hx::IsNull( _this1->b )) {
HXLINE( 287)							_this1->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_84,1);
            						}
            						else {
HXLINE( 287)							_this1->b->push(HX_(") {",c4,38,1f,00));
            						}
            					}
HXLINE( 288)					{
HXLINE( 288)						int _g = 0;
HXDLIN( 288)						while((_g < cases->length)){
HXLINE( 288)							 ::Dynamic c = cases->__get(_g);
HXDLIN( 288)							_g = (_g + 1);
HXLINE( 289)							{
HXLINE( 289)								 ::StringBuf _this = this->buf;
HXDLIN( 289)								if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 289)									_this->flush();
            								}
HXDLIN( 289)								if (::hx::IsNull( _this->b )) {
HXLINE( 289)									_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_85,1);
            								}
            								else {
HXLINE( 289)									_this->b->push(HX_("case ",70,bb,20,41));
            								}
            							}
HXLINE( 290)							bool first = true;
HXLINE( 291)							{
HXLINE( 291)								int _g1 = 0;
HXDLIN( 291)								::Array< ::Dynamic> _g2 = ( (::Array< ::Dynamic>)(c->__Field(HX_("values",e2,03,b7,4f),::hx::paccDynamic)) );
HXDLIN( 291)								while((_g1 < _g2->length)){
HXLINE( 291)									 ::hscript::Expr v = _g2->__get(_g1).StaticCast<  ::hscript::Expr >();
HXDLIN( 291)									_g1 = (_g1 + 1);
HXLINE( 292)									if (first) {
HXLINE( 292)										first = false;
            									}
            									else {
HXLINE( 292)										 ::StringBuf _this = this->buf;
HXDLIN( 292)										if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 292)											_this->flush();
            										}
HXDLIN( 292)										if (::hx::IsNull( _this->b )) {
HXLINE( 292)											_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_86,1);
            										}
            										else {
HXLINE( 292)											_this->b->push(HX_(", ",74,26,00,00));
            										}
            									}
HXLINE( 293)									this->expr(v);
            								}
            							}
HXLINE( 295)							{
HXLINE( 295)								 ::StringBuf _this1 = this->buf;
HXDLIN( 295)								if (::hx::IsNotNull( _this1->charBuf )) {
HXLINE( 295)									_this1->flush();
            								}
HXDLIN( 295)								if (::hx::IsNull( _this1->b )) {
HXLINE( 295)									_this1->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_87,1);
            								}
            								else {
HXLINE( 295)									_this1->b->push(HX_(": ",a6,32,00,00));
            								}
            							}
HXLINE( 296)							this->expr(c->__Field(HX_("expr",35,fd,1d,43),::hx::paccDynamic));
HXLINE( 297)							{
HXLINE( 297)								 ::StringBuf _this2 = this->buf;
HXDLIN( 297)								if (::hx::IsNotNull( _this2->charBuf )) {
HXLINE( 297)									_this2->flush();
            								}
HXDLIN( 297)								if (::hx::IsNull( _this2->b )) {
HXLINE( 297)									_this2->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_88,1);
            								}
            								else {
HXLINE( 297)									_this2->b->push(HX_(";\n",6f,33,00,00));
            								}
            							}
            						}
            					}
HXLINE( 299)					if (::hx::IsNotNull( def )) {
HXLINE( 300)						{
HXLINE( 300)							 ::StringBuf _this = this->buf;
HXDLIN( 300)							if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 300)								_this->flush();
            							}
HXDLIN( 300)							if (::hx::IsNull( _this->b )) {
HXLINE( 300)								_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_89,1);
            							}
            							else {
HXLINE( 300)								_this->b->push(HX_("default: ",a7,7d,fc,f6));
            							}
            						}
HXLINE( 301)						this->expr(def);
HXLINE( 302)						{
HXLINE( 302)							 ::StringBuf _this1 = this->buf;
HXDLIN( 302)							if (::hx::IsNotNull( _this1->charBuf )) {
HXLINE( 302)								_this1->flush();
            							}
HXDLIN( 302)							if (::hx::IsNull( _this1->b )) {
HXLINE( 302)								_this1->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_90,1);
            							}
            							else {
HXLINE( 302)								_this1->b->push(HX_(";\n",6f,33,00,00));
            							}
            						}
            					}
HXLINE( 304)					{
HXLINE( 304)						 ::StringBuf _this2 = this->buf;
HXDLIN( 304)						if (::hx::IsNotNull( _this2->charBuf )) {
HXLINE( 304)							_this2->flush();
            						}
HXDLIN( 304)						if (::hx::IsNull( _this2->b )) {
HXLINE( 304)							_this2->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_91,1);
            						}
            						else {
HXLINE( 304)							_this2->b->push(HX_("}",7d,00,00,00));
            						}
            					}
            				}
            			}
            			break;
            			case (int)24: {
HXLINE( 195)				 ::hscript::Expr cond = e->_hx_getObject(0).StaticCast<  ::hscript::Expr >();
HXDLIN( 195)				 ::hscript::Expr e1 = e->_hx_getObject(1).StaticCast<  ::hscript::Expr >();
HXDLIN( 195)				{
HXLINE( 196)					{
HXLINE( 196)						 ::StringBuf _this = this->buf;
HXDLIN( 196)						if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 196)							_this->flush();
            						}
HXDLIN( 196)						if (::hx::IsNull( _this->b )) {
HXLINE( 196)							_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_92,1);
            						}
            						else {
HXLINE( 196)							_this->b->push(HX_("do ",35,42,4c,00));
            						}
            					}
HXLINE( 197)					this->expr(e1);
HXLINE( 198)					{
HXLINE( 198)						 ::StringBuf _this1 = this->buf;
HXDLIN( 198)						if (::hx::IsNotNull( _this1->charBuf )) {
HXLINE( 198)							_this1->flush();
            						}
HXDLIN( 198)						if (::hx::IsNull( _this1->b )) {
HXLINE( 198)							_this1->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_93,1);
            						}
            						else {
HXLINE( 198)							_this1->b->push(HX_(" while ( ",27,ec,f2,46));
            						}
            					}
HXLINE( 199)					this->expr(cond);
HXLINE( 200)					{
HXLINE( 200)						 ::StringBuf _this2 = this->buf;
HXDLIN( 200)						if (::hx::IsNotNull( _this2->charBuf )) {
HXLINE( 200)							_this2->flush();
            						}
HXDLIN( 200)						if (::hx::IsNull( _this2->b )) {
HXLINE( 200)							_this2->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_94,1);
            						}
            						else {
HXLINE( 200)							_this2->b->push(HX_(" )",09,1c,00,00));
            						}
            					}
            				}
            			}
            			break;
            			case (int)25: {
HXLINE( 305)				::String name = e->_hx_getString(0);
HXDLIN( 305)				::Array< ::Dynamic> args = e->_hx_getObject(1).StaticCast< ::Array< ::Dynamic> >();
HXDLIN( 305)				 ::hscript::Expr e1 = e->_hx_getObject(2).StaticCast<  ::hscript::Expr >();
HXDLIN( 305)				{
HXLINE( 306)					{
HXLINE( 306)						 ::StringBuf _this = this->buf;
HXDLIN( 306)						if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 306)							_this->flush();
            						}
HXDLIN( 306)						if (::hx::IsNull( _this->b )) {
HXLINE( 306)							_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_95,1);
            						}
            						else {
HXLINE( 306)							_this->b->push(HX_("@",40,00,00,00));
            						}
            					}
HXLINE( 307)					{
HXLINE( 307)						 ::StringBuf _this1 = this->buf;
HXDLIN( 307)						if (::hx::IsNotNull( _this1->charBuf )) {
HXLINE( 307)							_this1->flush();
            						}
HXDLIN( 307)						if (::hx::IsNull( _this1->b )) {
HXLINE( 307)							_this1->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(name));
            						}
            						else {
HXLINE( 307)							::Array< ::String > _this = _this1->b;
HXDLIN( 307)							_this->push(::Std_obj::string(name));
            						}
            					}
HXLINE( 308)					bool _hx_tmp;
HXDLIN( 308)					if (::hx::IsNotNull( args )) {
HXLINE( 308)						_hx_tmp = (args->length > 0);
            					}
            					else {
HXLINE( 308)						_hx_tmp = false;
            					}
HXDLIN( 308)					if (_hx_tmp) {
HXLINE( 309)						{
HXLINE( 309)							 ::StringBuf _this = this->buf;
HXDLIN( 309)							if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 309)								_this->flush();
            							}
HXDLIN( 309)							if (::hx::IsNull( _this->b )) {
HXLINE( 309)								_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_96,1);
            							}
            							else {
HXLINE( 309)								_this->b->push(HX_("(",28,00,00,00));
            							}
            						}
HXLINE( 310)						bool first = true;
HXLINE( 311)						{
HXLINE( 311)							int _g = 0;
HXDLIN( 311)							while((_g < args->length)){
HXLINE( 311)								 ::hscript::Expr a = args->__get(_g).StaticCast<  ::hscript::Expr >();
HXDLIN( 311)								_g = (_g + 1);
HXLINE( 312)								if (first) {
HXLINE( 312)									first = false;
            								}
            								else {
HXLINE( 312)									 ::StringBuf _this = this->buf;
HXDLIN( 312)									if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 312)										_this->flush();
            									}
HXDLIN( 312)									if (::hx::IsNull( _this->b )) {
HXLINE( 312)										_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_97,1);
            									}
            									else {
HXLINE( 312)										_this->b->push(HX_(", ",74,26,00,00));
            									}
            								}
HXLINE( 313)								this->expr(e1);
            							}
            						}
HXLINE( 315)						{
HXLINE( 315)							 ::StringBuf _this1 = this->buf;
HXDLIN( 315)							if (::hx::IsNotNull( _this1->charBuf )) {
HXLINE( 315)								_this1->flush();
            							}
HXDLIN( 315)							if (::hx::IsNull( _this1->b )) {
HXLINE( 315)								_this1->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_98,1);
            							}
            							else {
HXLINE( 315)								_this1->b->push(HX_(")",29,00,00,00));
            							}
            						}
            					}
HXLINE( 317)					{
HXLINE( 317)						 ::StringBuf _this2 = this->buf;
HXDLIN( 317)						if (::hx::IsNotNull( _this2->charBuf )) {
HXLINE( 317)							_this2->flush();
            						}
HXDLIN( 317)						if (::hx::IsNull( _this2->b )) {
HXLINE( 317)							_this2->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_99,1);
            						}
            						else {
HXLINE( 317)							_this2->b->push(HX_(" ",20,00,00,00));
            						}
            					}
HXLINE( 318)					this->expr(e1);
            				}
            			}
            			break;
            			case (int)26: {
HXLINE( 319)				 ::hscript::Expr e1 = e->_hx_getObject(0).StaticCast<  ::hscript::Expr >();
HXDLIN( 319)				 ::hscript::CType t = e->_hx_getObject(1).StaticCast<  ::hscript::CType >();
HXDLIN( 319)				{
HXLINE( 320)					{
HXLINE( 320)						 ::StringBuf _this = this->buf;
HXDLIN( 320)						if (::hx::IsNotNull( _this->charBuf )) {
HXLINE( 320)							_this->flush();
            						}
HXDLIN( 320)						if (::hx::IsNull( _this->b )) {
HXLINE( 320)							_this->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_100,1);
            						}
            						else {
HXLINE( 320)							_this->b->push(HX_("(",28,00,00,00));
            						}
            					}
HXLINE( 321)					this->expr(e1);
HXLINE( 322)					{
HXLINE( 322)						 ::StringBuf _this1 = this->buf;
HXDLIN( 322)						if (::hx::IsNotNull( _this1->charBuf )) {
HXLINE( 322)							_this1->flush();
            						}
HXDLIN( 322)						if (::hx::IsNull( _this1->b )) {
HXLINE( 322)							_this1->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_101,1);
            						}
            						else {
HXLINE( 322)							_this1->b->push(HX_(" : ",c6,7a,18,00));
            						}
            					}
HXLINE( 323)					this->addType(t);
HXLINE( 324)					{
HXLINE( 324)						 ::StringBuf _this2 = this->buf;
HXDLIN( 324)						if (::hx::IsNotNull( _this2->charBuf )) {
HXLINE( 324)							_this2->flush();
            						}
HXDLIN( 324)						if (::hx::IsNull( _this2->b )) {
HXLINE( 324)							_this2->b = ::Array_obj< ::String >::fromData( _hx_array_data_648c36bf_102,1);
            						}
            						else {
HXLINE( 324)							_this2->b->push(HX_(")",29,00,00,00));
            						}
            					}
            				}
            			}
            			break;
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(Printer_obj,expr,(void))

::String Printer_obj::toString( ::hscript::Expr e){
            	HX_GC_STACKFRAME(&_hx_pos_84208ede1804668b_329_toString)
HXDLIN( 329)		return  ::hscript::Printer_obj::__alloc( HX_CTX )->exprToString(e);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Printer_obj,toString,return )

::String Printer_obj::errorToString( ::hscript::Error e){
            	HX_STACKFRAME(&_hx_pos_84208ede1804668b_332_errorToString)
HXLINE( 333)		::String message;
HXDLIN( 333)		switch((int)(e->_hx_getIndex())){
            			case (int)0: {
HXLINE( 334)				int c = e->_hx_getInt(0);
HXDLIN( 334)				::String message1;
HXDLIN( 334)				if ((c == 0)) {
HXLINE( 334)					message1 = HX_("EOF",9c,a0,34,00);
            				}
            				else {
HXLINE( 334)					message1 = ::String::fromCharCode(c);
            				}
HXLINE( 333)				message = ((((HX_("Invalid character: '",a1,a5,78,86) + message1) + HX_("' (",ef,b3,1d,00)) + c) + HX_(")",29,00,00,00));
            			}
            			break;
            			case (int)1: {
HXLINE( 335)				::String s = e->_hx_getString(0);
HXLINE( 333)				message = ((HX_("Unexpected token: \"",72,bd,eb,db) + s) + HX_("\"",22,00,00,00));
            			}
            			break;
            			case (int)2: {
HXLINE( 333)				message = HX_("Unterminated string",d5,ed,a8,63);
            			}
            			break;
            			case (int)3: {
HXLINE( 333)				message = HX_("Unterminated comment",db,18,a4,58);
            			}
            			break;
            			case (int)4: {
HXLINE( 338)				::String str = e->_hx_getString(0);
HXLINE( 333)				message = ((HX_("Invalid preprocessor (",c0,ad,45,7c) + str) + HX_(")",29,00,00,00));
            			}
            			break;
            			case (int)5: {
HXLINE( 339)				::String v = e->_hx_getString(0);
HXLINE( 333)				message = (HX_("Unknown variable: ",d8,ac,05,6b) + v);
            			}
            			break;
            			case (int)6: {
HXLINE( 340)				::String v = e->_hx_getString(0);
HXLINE( 333)				message = (HX_("Invalid iterator: ",bd,0a,a8,b4) + v);
            			}
            			break;
            			case (int)7: {
HXLINE( 341)				::String op = e->_hx_getString(0);
HXLINE( 333)				message = (HX_("Invalid operator: ",f3,35,a1,ea) + op);
            			}
            			break;
            			case (int)8: {
HXLINE( 342)				::String f = e->_hx_getString(0);
HXLINE( 333)				message = (HX_("Invalid access to field ",18,98,cb,c3) + f);
            			}
            			break;
            			case (int)9: {
HXLINE( 343)				::String msg = e->_hx_getString(0);
HXLINE( 333)				message = msg;
            			}
            			break;
            		}
HXLINE( 348)		return message;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Printer_obj,errorToString,return )


::hx::ObjectPtr< Printer_obj > Printer_obj::__new() {
	::hx::ObjectPtr< Printer_obj > __this = new Printer_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< Printer_obj > Printer_obj::__alloc(::hx::Ctx *_hx_ctx) {
	Printer_obj *__this = (Printer_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Printer_obj), true, "hscript.Printer"));
	*(void **)__this = Printer_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

Printer_obj::Printer_obj()
{
}

void Printer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Printer);
	HX_MARK_MEMBER_NAME(buf,"buf");
	HX_MARK_MEMBER_NAME(tabs,"tabs");
	HX_MARK_END_CLASS();
}

void Printer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(buf,"buf");
	HX_VISIT_MEMBER_NAME(tabs,"tabs");
}

::hx::Val Printer_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"buf") ) { return ::hx::Val( buf ); }
		if (HX_FIELD_EQ(inName,"add") ) { return ::hx::Val( add_dyn() ); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"tabs") ) { return ::hx::Val( tabs ); }
		if (HX_FIELD_EQ(inName,"type") ) { return ::hx::Val( type_dyn() ); }
		if (HX_FIELD_EQ(inName,"expr") ) { return ::hx::Val( expr_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"addType") ) { return ::hx::Val( addType_dyn() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"exprToString") ) { return ::hx::Val( exprToString_dyn() ); }
		if (HX_FIELD_EQ(inName,"typeToString") ) { return ::hx::Val( typeToString_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

bool Printer_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { outValue = toString_dyn(); return true; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"errorToString") ) { outValue = errorToString_dyn(); return true; }
	}
	return false;
}

::hx::Val Printer_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"buf") ) { buf=inValue.Cast<  ::StringBuf >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"tabs") ) { tabs=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Printer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("buf",33,c3,4a,00));
	outFields->push(HX_("tabs",7e,b0,f6,4c));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Printer_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::StringBuf */ ,(int)offsetof(Printer_obj,buf),HX_("buf",33,c3,4a,00)},
	{::hx::fsString,(int)offsetof(Printer_obj,tabs),HX_("tabs",7e,b0,f6,4c)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *Printer_obj_sStaticStorageInfo = 0;
#endif

static ::String Printer_obj_sMemberFields[] = {
	HX_("buf",33,c3,4a,00),
	HX_("tabs",7e,b0,f6,4c),
	HX_("exprToString",01,47,fe,7a),
	HX_("typeToString",86,c9,d1,1f),
	HX_("add",21,f2,49,00),
	HX_("type",ba,f2,08,4d),
	HX_("addType",7b,35,46,89),
	HX_("expr",35,fd,1d,43),
	::String(null()) };

::hx::Class Printer_obj::__mClass;

static ::String Printer_obj_sStaticFields[] = {
	HX_("toString",ac,d0,6e,38),
	HX_("errorToString",94,60,27,91),
	::String(null())
};

void Printer_obj::__register()
{
	Printer_obj _hx_dummy;
	Printer_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("hscript.Printer",bf,36,8c,64);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Printer_obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(Printer_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Printer_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Printer_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Printer_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Printer_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace hscript
