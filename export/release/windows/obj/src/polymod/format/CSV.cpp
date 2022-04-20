#include <hxcpp.h>

#ifndef INCLUDED_EReg
#include <EReg.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_polymod_format_BaseParseFormat
#include <polymod/format/BaseParseFormat.h>
#endif
#ifndef INCLUDED_polymod_format_CSV
#include <polymod/format/CSV.h>
#endif
#ifndef INCLUDED_polymod_format_CSVParseFormat
#include <polymod/format/CSVParseFormat.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_4584945ff3f90518_9_new,"polymod.format.CSV","new",0x9493b4d9,"polymod.format.CSV.new","polymod/format/CSV.hx",9,0xda8f32d7)
HX_LOCAL_STACK_FRAME(_hx_pos_4584945ff3f90518_77_destroy,"polymod.format.CSV","destroy",0x4c0441f3,"polymod.format.CSV.destroy","polymod/format/CSV.hx",77,0xda8f32d7)
HX_LOCAL_STACK_FRAME(_hx_pos_4584945ff3f90518_91__parse,"polymod.format.CSV","_parse",0x1afe449b,"polymod.format.CSV._parse","polymod/format/CSV.hx",91,0xda8f32d7)
HX_LOCAL_STACK_FRAME(_hx_pos_4584945ff3f90518_101_clearArray,"polymod.format.CSV","clearArray",0xf2b63973,"polymod.format.CSV.clearArray","polymod/format/CSV.hx",101,0xda8f32d7)
HX_LOCAL_STACK_FRAME(_hx_pos_4584945ff3f90518_116_destroyThing,"polymod.format.CSV","destroyThing",0xa35fc4fb,"polymod.format.CSV.destroyThing","polymod/format/CSV.hx",116,0xda8f32d7)
HX_LOCAL_STACK_FRAME(_hx_pos_4584945ff3f90518_129_getCells,"polymod.format.CSV","getCells",0x0a6ba102,"polymod.format.CSV.getCells","polymod/format/CSV.hx",129,0xda8f32d7)
HX_LOCAL_STACK_FRAME(_hx_pos_4584945ff3f90518_155_getRows,"polymod.format.CSV","getRows",0x45afb9c8,"polymod.format.CSV.getRows","polymod/format/CSV.hx",155,0xda8f32d7)
HX_LOCAL_STACK_FRAME(_hx_pos_4584945ff3f90518_167_processCells,"polymod.format.CSV","processCells",0xcd4b2c09,"polymod.format.CSV.processCells","polymod/format/CSV.hx",167,0xda8f32d7)
HX_LOCAL_STACK_FRAME(_hx_pos_4584945ff3f90518_209_processRows,"polymod.format.CSV","processRows",0x8924aca1,"polymod.format.CSV.processRows","polymod/format/CSV.hx",209,0xda8f32d7)
HX_LOCAL_STACK_FRAME(_hx_pos_4584945ff3f90518_26_parse,"polymod.format.CSV","parse",0xccb244ec,"polymod.format.CSV.parse","polymod/format/CSV.hx",26,0xda8f32d7)
HX_LOCAL_STACK_FRAME(_hx_pos_4584945ff3f90518_39_parseWithFormat,"polymod.format.CSV","parseWithFormat",0x20c3e9e9,"polymod.format.CSV.parseWithFormat","polymod/format/CSV.hx",39,0xda8f32d7)
HX_LOCAL_STACK_FRAME(_hx_pos_4584945ff3f90518_57_parseSimple,"polymod.format.CSV","parseSimple",0x549a363e,"polymod.format.CSV.parseSimple","polymod/format/CSV.hx",57,0xda8f32d7)
namespace polymod{
namespace format{

void CSV_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_4584945ff3f90518_9_new)
HXLINE(  88)		this->_quoted = false;
HXLINE(  87)		this->_delimeter = HX_("",00,00,00,00);
HXLINE(  85)		this->_rgx = null();
            	}

Dynamic CSV_obj::__CreateEmpty() { return new CSV_obj; }

void *CSV_obj::_hx_vtable = 0;

Dynamic CSV_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< CSV_obj > _hx_result = new CSV_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool CSV_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x37ab9499;
}

void CSV_obj::destroy(){
            	HX_STACKFRAME(&_hx_pos_4584945ff3f90518_77_destroy)
HXLINE(  78)		this->clearArray(this->grid);
HXLINE(  79)		this->clearArray(this->fields);
HXLINE(  80)		this->grid = null();
HXLINE(  81)		this->fields = null();
            	}


HX_DEFINE_DYNAMIC_FUNC0(CSV_obj,destroy,(void))

void CSV_obj::_parse(::String input,::String __o_delimeter,::hx::Null< bool >  __o_quoted){
            		::String delimeter = __o_delimeter;
            		if (::hx::IsNull(__o_delimeter)) delimeter = HX_(",",2c,00,00,00);
            		bool quoted = __o_quoted.Default(true);
            	HX_STACKFRAME(&_hx_pos_4584945ff3f90518_91__parse)
HXLINE(  92)		this->_delimeter = delimeter;
HXLINE(  93)		this->_quoted = quoted;
HXLINE(  94)		if ((input != HX_("",00,00,00,00))) {
HXLINE(  96)			this->processRows(this->getRows(input));
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC3(CSV_obj,_parse,(void))

void CSV_obj::clearArray(::cpp::VirtualArray array){
            	HX_STACKFRAME(&_hx_pos_4584945ff3f90518_101_clearArray)
HXLINE( 102)		if (::hx::IsNull( array )) {
HXLINE( 103)			return;
            		}
HXLINE( 104)		int i = (array->get_length() - 1);
HXLINE( 105)		while((i >= 0)){
HXLINE( 107)			this->destroyThing(array->__get(i));
HXLINE( 108)			array->set(i,null());
HXLINE( 109)			array->splice(i,1);
HXLINE( 110)			i = (i - 1);
            		}
HXLINE( 112)		array = null();
            	}


HX_DEFINE_DYNAMIC_FUNC1(CSV_obj,clearArray,(void))

void CSV_obj::destroyThing( ::Dynamic thing){
            	HX_STACKFRAME(&_hx_pos_4584945ff3f90518_116_destroyThing)
HXLINE( 117)		if (::hx::IsNull( thing )) {
HXLINE( 118)			return;
            		}
HXLINE( 120)		if (::Std_obj::isOfType(thing,::hx::ArrayBase::__mClass)) {
HXLINE( 122)			this->clearArray(( (::cpp::VirtualArray)(thing) ));
            		}
HXLINE( 125)		thing = null();
            	}


HX_DEFINE_DYNAMIC_FUNC1(CSV_obj,destroyThing,(void))

::Array< ::String > CSV_obj::getCells(::String row){
            	HX_GC_STACKFRAME(&_hx_pos_4584945ff3f90518_129_getCells)
HXLINE( 130)		if (::hx::IsNull( this->_rgx )) {
HXLINE( 133)			::String _hx_tmp = row.charAt((row.length - 1));
HXDLIN( 133)			if ((_hx_tmp == this->_delimeter)) {
HXLINE( 135)				row = row.substr(0,(row.length - 1));
            			}
HXLINE( 138)			if ((this->_delimeter == HX_(",",2c,00,00,00))) {
HXLINE( 140)				this->_rgx =  ::EReg_obj::__alloc( HX_CTX ,HX_(",(?=(?:[^\\x22]*\\x22[^\\x22]*\\x22)*(?![^\\x22]*\\x22))",78,aa,0d,3d),HX_("gm",26,5a,00,00));
            			}
            			else {
HXLINE( 148)				this->_rgx =  ::EReg_obj::__alloc( HX_CTX ,(this->_delimeter + HX_("(?=(?:[^\"]*\"[^\"]*\")*(?![^\"]*\"))",56,98,5a,ba)),HX_("gm",26,5a,00,00));
            			}
            		}
HXLINE( 151)		return this->_rgx->split(row);
            	}


HX_DEFINE_DYNAMIC_FUNC1(CSV_obj,getCells,return )

::Array< ::String > CSV_obj::getRows(::String input){
            	HX_STACKFRAME(&_hx_pos_4584945ff3f90518_155_getRows)
HXLINE( 156)		::String endl = HX_("\r\n",5d,0b,00,00);
HXLINE( 158)		if ((input.indexOf(HX_("\r\n",5d,0b,00,00),null()) == -1)) {
HXLINE( 160)			endl = HX_("\n",0a,00,00,00);
            		}
HXLINE( 163)		return input.split(endl);
            	}


HX_DEFINE_DYNAMIC_FUNC1(CSV_obj,getRows,return )

void CSV_obj::processCells(::Array< ::String > cells,::hx::Null< int >  __o_row){
            		int row = __o_row.Default(0);
            	HX_STACKFRAME(&_hx_pos_4584945ff3f90518_167_processCells)
HXLINE( 168)		int col = 0;
HXLINE( 169)		bool newline = false;
HXLINE( 170)		::Array< ::String > row_array = null();
HXLINE( 172)		if (::hx::IsNull( this->grid )) {
HXLINE( 174)			this->grid = ::Array_obj< ::Dynamic>::__new();
HXLINE( 175)			this->fields = ::Array_obj< ::String >::__new(0);
            		}
HXLINE( 178)		row_array = ::Array_obj< ::String >::__new(0);
HXLINE( 180)		{
HXLINE( 180)			int _g = 0;
HXDLIN( 180)			int _g1 = cells->length;
HXDLIN( 180)			while((_g < _g1)){
HXLINE( 180)				_g = (_g + 1);
HXDLIN( 180)				int i = (_g - 1);
HXLINE( 182)				::String cell = HX_("",00,00,00,00);
HXLINE( 183)				if (this->_quoted) {
HXLINE( 185)					cell = cells->__get(i).substr(1,(cells->__get(i).length - 2));
            				}
            				else {
HXLINE( 189)					cell = cells->__get(i);
            				}
HXLINE( 192)				if ((row == 0)) {
HXLINE( 194)					this->fields->push(cell);
            				}
            				else {
HXLINE( 198)					row_array->push(cell);
            				}
            			}
            		}
HXLINE( 202)		this->grid->push(row_array);
HXLINE( 203)		this->clearArray(cells);
HXLINE( 204)		cells = null();
            	}


HX_DEFINE_DYNAMIC_FUNC2(CSV_obj,processCells,(void))

void CSV_obj::processRows(::Array< ::String > rows){
            	HX_STACKFRAME(&_hx_pos_4584945ff3f90518_209_processRows)
HXDLIN( 209)		int _g = 0;
HXDLIN( 209)		int _g1 = rows->length;
HXDLIN( 209)		while((_g < _g1)){
HXDLIN( 209)			_g = (_g + 1);
HXDLIN( 209)			int i = (_g - 1);
HXLINE( 211)			this->processCells(this->getCells(rows->__get(i)),i);
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(CSV_obj,processRows,(void))

 ::polymod::format::CSV CSV_obj::parse(::String input,::String __o_delimeter,::hx::Null< bool >  __o_quotedCells){
            		::String delimeter = __o_delimeter;
            		if (::hx::IsNull(__o_delimeter)) delimeter = HX_(",",2c,00,00,00);
            		bool quotedCells = __o_quotedCells.Default(true);
            	HX_GC_STACKFRAME(&_hx_pos_4584945ff3f90518_26_parse)
HXLINE(  27)		 ::polymod::format::CSV csv =  ::polymod::format::CSV_obj::__alloc( HX_CTX );
HXLINE(  28)		csv->_parse(input,delimeter,quotedCells);
HXLINE(  29)		return csv;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(CSV_obj,parse,return )

 ::polymod::format::CSV CSV_obj::parseWithFormat(::String input, ::polymod::format::CSVParseFormat format){
            	HX_STACKFRAME(&_hx_pos_4584945ff3f90518_39_parseWithFormat)
HXDLIN(  39)		if (format->get_isSimpleMode()) {
HXLINE(  41)			return ::polymod::format::CSV_obj::parseSimple(input);
            		}
            		else {
HXLINE(  45)			return ::polymod::format::CSV_obj::parse(input,format->delimeter,format->quotedCells);
            		}
HXLINE(  39)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(CSV_obj,parseWithFormat,return )

 ::polymod::format::CSV CSV_obj::parseSimple(::String input){
            	HX_GC_STACKFRAME(&_hx_pos_4584945ff3f90518_57_parseSimple)
HXLINE(  58)		::String endline = HX_("\n",0a,00,00,00);
HXLINE(  59)		if ((input.indexOf(HX_("\r\n",5d,0b,00,00),null()) != -1)) {
HXLINE(  60)			endline = HX_("\r\n",5d,0b,00,00);
            		}
HXLINE(  61)		::Array< ::String > lines = input.split(endline);
HXLINE(  62)		::String fieldLine = ( (::String)(lines->shift()) );
HXLINE(  63)		::Array< ::String > fields = fieldLine.split(HX_(",",2c,00,00,00));
HXLINE(  64)		::Array< ::Dynamic> grid = ::Array_obj< ::Dynamic>::__new(0);
HXLINE(  65)		{
HXLINE(  65)			int _g = 0;
HXDLIN(  65)			while((_g < lines->length)){
HXLINE(  65)				::String line = lines->__get(_g);
HXDLIN(  65)				_g = (_g + 1);
HXLINE(  67)				::Array< ::String > cells = line.split(HX_(",",2c,00,00,00));
HXLINE(  68)				grid->push(cells);
            			}
            		}
HXLINE(  70)		 ::polymod::format::CSV csv =  ::polymod::format::CSV_obj::__alloc( HX_CTX );
HXLINE(  71)		csv->fields = fields;
HXLINE(  72)		csv->grid = grid;
HXLINE(  73)		return csv;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSV_obj,parseSimple,return )


::hx::ObjectPtr< CSV_obj > CSV_obj::__new() {
	::hx::ObjectPtr< CSV_obj > __this = new CSV_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< CSV_obj > CSV_obj::__alloc(::hx::Ctx *_hx_ctx) {
	CSV_obj *__this = (CSV_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(CSV_obj), true, "polymod.format.CSV"));
	*(void **)__this = CSV_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

CSV_obj::CSV_obj()
{
}

void CSV_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CSV);
	HX_MARK_MEMBER_NAME(fields,"fields");
	HX_MARK_MEMBER_NAME(grid,"grid");
	HX_MARK_MEMBER_NAME(_rgx,"_rgx");
	HX_MARK_MEMBER_NAME(_delimeter,"_delimeter");
	HX_MARK_MEMBER_NAME(_quoted,"_quoted");
	HX_MARK_END_CLASS();
}

void CSV_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(fields,"fields");
	HX_VISIT_MEMBER_NAME(grid,"grid");
	HX_VISIT_MEMBER_NAME(_rgx,"_rgx");
	HX_VISIT_MEMBER_NAME(_delimeter,"_delimeter");
	HX_VISIT_MEMBER_NAME(_quoted,"_quoted");
}

::hx::Val CSV_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"grid") ) { return ::hx::Val( grid ); }
		if (HX_FIELD_EQ(inName,"_rgx") ) { return ::hx::Val( _rgx ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"fields") ) { return ::hx::Val( fields ); }
		if (HX_FIELD_EQ(inName,"_parse") ) { return ::hx::Val( _parse_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return ::hx::Val( destroy_dyn() ); }
		if (HX_FIELD_EQ(inName,"_quoted") ) { return ::hx::Val( _quoted ); }
		if (HX_FIELD_EQ(inName,"getRows") ) { return ::hx::Val( getRows_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getCells") ) { return ::hx::Val( getCells_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_delimeter") ) { return ::hx::Val( _delimeter ); }
		if (HX_FIELD_EQ(inName,"clearArray") ) { return ::hx::Val( clearArray_dyn() ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"processRows") ) { return ::hx::Val( processRows_dyn() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"destroyThing") ) { return ::hx::Val( destroyThing_dyn() ); }
		if (HX_FIELD_EQ(inName,"processCells") ) { return ::hx::Val( processCells_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

bool CSV_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"parse") ) { outValue = parse_dyn(); return true; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"parseSimple") ) { outValue = parseSimple_dyn(); return true; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"parseWithFormat") ) { outValue = parseWithFormat_dyn(); return true; }
	}
	return false;
}

::hx::Val CSV_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"grid") ) { grid=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_rgx") ) { _rgx=inValue.Cast<  ::EReg >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"fields") ) { fields=inValue.Cast< ::Array< ::String > >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_quoted") ) { _quoted=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_delimeter") ) { _delimeter=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CSV_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("fields",79,8e,8e,80));
	outFields->push(HX_("grid",c6,d6,6b,44));
	outFields->push(HX_("_rgx",24,20,22,3f));
	outFields->push(HX_("_delimeter",4c,a8,25,df));
	outFields->push(HX_("_quoted",47,c3,63,44));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo CSV_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /* ::Array< ::String > */ ,(int)offsetof(CSV_obj,fields),HX_("fields",79,8e,8e,80)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(CSV_obj,grid),HX_("grid",c6,d6,6b,44)},
	{::hx::fsObject /*  ::EReg */ ,(int)offsetof(CSV_obj,_rgx),HX_("_rgx",24,20,22,3f)},
	{::hx::fsString,(int)offsetof(CSV_obj,_delimeter),HX_("_delimeter",4c,a8,25,df)},
	{::hx::fsBool,(int)offsetof(CSV_obj,_quoted),HX_("_quoted",47,c3,63,44)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *CSV_obj_sStaticStorageInfo = 0;
#endif

static ::String CSV_obj_sMemberFields[] = {
	HX_("fields",79,8e,8e,80),
	HX_("grid",c6,d6,6b,44),
	HX_("destroy",fa,2c,86,24),
	HX_("_rgx",24,20,22,3f),
	HX_("_delimeter",4c,a8,25,df),
	HX_("_quoted",47,c3,63,44),
	HX_("_parse",74,d7,3c,b9),
	HX_("clearArray",cc,ac,99,fa),
	HX_("destroyThing",94,80,89,01),
	HX_("getCells",1b,5c,97,a3),
	HX_("getRows",cf,a4,31,1e),
	HX_("processCells",a2,e7,74,2b),
	HX_("processRows",28,27,46,68),
	::String(null()) };

::hx::Class CSV_obj::__mClass;

static ::String CSV_obj_sStaticFields[] = {
	HX_("parse",33,90,55,bd),
	HX_("parseWithFormat",f0,b3,42,42),
	HX_("parseSimple",c5,b0,bb,33),
	::String(null())
};

void CSV_obj::__register()
{
	CSV_obj _hx_dummy;
	CSV_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("polymod.format.CSV",67,54,d8,32);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &CSV_obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(CSV_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(CSV_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< CSV_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = CSV_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = CSV_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace polymod
} // end namespace format
