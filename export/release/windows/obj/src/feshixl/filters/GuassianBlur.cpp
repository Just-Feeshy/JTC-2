#include <hxcpp.h>

#ifndef INCLUDED_feshixl_filters_GuassianBlur
#include <feshixl/filters/GuassianBlur.h>
#endif
#ifndef INCLUDED_flixel_graphics_tile_FlxGraphicsShader
#include <flixel/graphics/tile/FlxGraphicsShader.h>
#endif
#ifndef INCLUDED_openfl_display_BitmapData
#include <openfl/display/BitmapData.h>
#endif
#ifndef INCLUDED_openfl_display_GraphicsShader
#include <openfl/display/GraphicsShader.h>
#endif
#ifndef INCLUDED_openfl_display_IBitmapDrawable
#include <openfl/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl_display_Shader
#include <openfl/display/Shader.h>
#endif
#ifndef INCLUDED_openfl_display_ShaderInput_openfl_display_BitmapData
#include <openfl/display/ShaderInput_openfl_display_BitmapData.h>
#endif
#ifndef INCLUDED_openfl_display_ShaderParameter_Bool
#include <openfl/display/ShaderParameter_Bool.h>
#endif
#ifndef INCLUDED_openfl_display_ShaderParameter_Float
#include <openfl/display/ShaderParameter_Float.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_0ec0183b593c1cf7_49_new,"feshixl.filters.GuassianBlur","new",0xfa98c094,"feshixl.filters.GuassianBlur.new","feshixl/filters/GuassianBlur.hx",49,0x76d8769a)
static const bool _hx_array_data_c6e826a2_1[] = {
	1,
};
static const bool _hx_array_data_c6e826a2_2[] = {
	0,
};
HX_LOCAL_STACK_FRAME(_hx_pos_0ec0183b593c1cf7_63_setSpriteBitmap,"feshixl.filters.GuassianBlur","setSpriteBitmap",0x98aaf2ca,"feshixl.filters.GuassianBlur.setSpriteBitmap","feshixl/filters/GuassianBlur.hx",63,0x76d8769a)
static const bool _hx_array_data_c6e826a2_4[] = {
	1,
};
static const bool _hx_array_data_c6e826a2_5[] = {
	0,
};
HX_LOCAL_STACK_FRAME(_hx_pos_0ec0183b593c1cf7_71_set_size,"feshixl.filters.GuassianBlur","set_size",0x3acf890a,"feshixl.filters.GuassianBlur.set_size","feshixl/filters/GuassianBlur.hx",71,0x76d8769a)
HX_LOCAL_STACK_FRAME(_hx_pos_0ec0183b593c1cf7_77_get_size,"feshixl.filters.GuassianBlur","get_size",0x8c722f96,"feshixl.filters.GuassianBlur.get_size","feshixl/filters/GuassianBlur.hx",77,0x76d8769a)
HX_LOCAL_STACK_FRAME(_hx_pos_0ec0183b593c1cf7_13_boot,"feshixl.filters.GuassianBlur","boot",0x4328c17e,"feshixl.filters.GuassianBlur.boot","feshixl/filters/GuassianBlur.hx",13,0x76d8769a)
namespace feshixl{
namespace filters{

void GuassianBlur_obj::__construct(::hx::Null< Float >  __o_sizeValue, ::openfl::display::BitmapData spriteBit){
            		Float sizeValue = __o_sizeValue.Default(8);
            	HX_STACKFRAME(&_hx_pos_0ec0183b593c1cf7_49_new)
HXLINE( 182)		if (::hx::IsNull( this->_hx___glFragmentSource )) {
HXLINE( 184)			this->_hx___glFragmentSource = HX_("\r\n        varying float openfl_Alphav;\n\t\tvarying vec4 openfl_ColorMultiplierv;\n\t\tvarying vec4 openfl_ColorOffsetv;\n\t\tvarying vec2 openfl_TextureCoordv;\n\n\t\tuniform bool openfl_HasColorTransform;\n\t\tuniform vec2 openfl_TextureSize;\n\t\tuniform sampler2D bitmap;\n\n\t\tuniform bool hasTransform;\n\t\tuniform bool hasColorTransform;\n\n\t\tvec4 flixel_texture2D(sampler2D bitmap, vec2 coord)\n\t\t{\n\t\t\tvec4 color = texture2D(bitmap, coord);\n\t\t\tif (!hasTransform)\n\t\t\t{\n\t\t\t\treturn color;\n\t\t\t}\n\n\t\t\tif (color.a == 0.0)\n\t\t\t{\n\t\t\t\treturn vec4(0.0, 0.0, 0.0, 0.0);\n\t\t\t}\n\n\t\t\tif (!hasColorTransform)\n\t\t\t{\n\t\t\t\treturn color * openfl_Alphav;\n\t\t\t}\n\n\t\t\tcolor = vec4(color.rgb / color.a, color.a);\n\n\t\t\tmat4 colorMultiplier = mat4(0);\n\t\t\tcolorMultiplier[0][0] = openfl_ColorMultiplierv.x;\n\t\t\tcolorMultiplier[1][1] = openfl_ColorMultiplierv.y;\n\t\t\tcolorMultiplier[2][2] = openfl_ColorMultiplierv.z;\n\t\t\tcolorMultiplier[3][3] = openfl_ColorMultiplierv.w;\n\n\t\t\tcolor = clamp(openfl_ColorOffsetv + (color * colorMultiplier), 0.0, 1.0);\n\n\t\t\tif (color.a > 0.0)\n\t\t\t{\n\t\t\t\treturn vec4(color.rgb * color.a * openfl_Alphav, color.a * openfl_Alphav);\n\t\t\t}\n\t\t\treturn vec4(0.0, 0.0, 0.0, 0.0);\n\t\t}\n\t\n\r\n\r\n        uniform sampler2D bit;\r\n        uniform float _size;\r\n\r\n        uniform bool useExternalBit;\r\n\r\n        const float directions = 16.0;\r\n        const float quality = 4.0;\r\n\r\n        const float PI = 3.14159265358979323846;\r\n\r\n        vec4 color(vec2 pt) {\r\n            if(useExternalBit == true)\r\n                return texture2D(bit, pt);\r\n            else\r\n                return texture2D(bitmap, pt);\r\n        }\r\n\r\n        void main() {\r\n            vec4 Color = color(openfl_TextureCoordv);\r\n\r\n            for(float d = 0.0; d < PI * 2.0; d += (PI * 2.0)/directions) {\r\n                for(float i = 1.0 / quality; i <= 1.0; i += 1.0/quality) {\r\n                    Color += color(openfl_TextureCoordv + vec2(cos(d), sin(d)) * (_size / 1280.0) * i);\r\n                }\r\n            }\r\n\r\n            Color /= quality * directions - 15.0;\r\n            gl_FragColor = Color;\r\n        }\r\n    ",7d,c5,31,46);
            		}
HXLINE( 174)		if (::hx::IsNull( this->_hx___glVertexSource )) {
HXLINE( 176)			this->_hx___glVertexSource = HX_("\n\t\tattribute float openfl_Alpha;\n\t\tattribute vec4 openfl_ColorMultiplier;\n\t\tattribute vec4 openfl_ColorOffset;\n\t\tattribute vec4 openfl_Position;\n\t\tattribute vec2 openfl_TextureCoord;\n\n\t\tvarying float openfl_Alphav;\n\t\tvarying vec4 openfl_ColorMultiplierv;\n\t\tvarying vec4 openfl_ColorOffsetv;\n\t\tvarying vec2 openfl_TextureCoordv;\n\n\t\tuniform mat4 openfl_Matrix;\n\t\tuniform bool openfl_HasColorTransform;\n\t\tuniform vec2 openfl_TextureSize;\n\n\t\t\n\t\tattribute float alpha;\n\t\tattribute vec4 colorMultiplier;\n\t\tattribute vec4 colorOffset;\n\t\tuniform bool hasColorTransform;\n\t\t\n\t\tvoid main(void)\n\t\t{\n\t\t\topenfl_Alphav = openfl_Alpha;\n\t\topenfl_TextureCoordv = openfl_TextureCoord;\n\n\t\tif (openfl_HasColorTransform) {\n\n\t\t\topenfl_ColorMultiplierv = openfl_ColorMultiplier;\n\t\t\topenfl_ColorOffsetv = openfl_ColorOffset / 255.0;\n\n\t\t}\n\n\t\tgl_Position = openfl_Matrix * openfl_Position;\n\n\t\t\t\n\t\t\topenfl_Alphav = openfl_Alpha * alpha;\n\t\t\t\n\t\t\tif (hasColorTransform)\n\t\t\t{\n\t\t\t\topenfl_ColorOffsetv = colorOffset / 255.0;\n\t\t\t\topenfl_ColorMultiplierv = colorMultiplier;\n\t\t\t}\n\t\t}",f3,1e,fa,79);
            		}
HXLINE(  50)		super::__construct();
HXLINE(  52)		if (::hx::IsNotNull( spriteBit )) {
HXLINE(  53)			this->useExternalBit->value = ::Array_obj< bool >::fromData( _hx_array_data_c6e826a2_1,1);
HXLINE(  54)			this->bit->input = spriteBit;
            		}
            		else {
HXLINE(  56)			this->useExternalBit->value = ::Array_obj< bool >::fromData( _hx_array_data_c6e826a2_2,1);
            		}
HXLINE(  59)		this->_size->value = ::Array_obj< Float >::__new(1)->init(0,sizeValue);
HXLINE(  13)		this->_hx___isGenerated = true;
HXDLIN(  13)		this->_hx___initGL();
            	}

Dynamic GuassianBlur_obj::__CreateEmpty() { return new GuassianBlur_obj; }

void *GuassianBlur_obj::_hx_vtable = 0;

Dynamic GuassianBlur_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< GuassianBlur_obj > _hx_result = new GuassianBlur_obj();
	_hx_result->__construct(inArgs[0],inArgs[1]);
	return _hx_result;
}

bool GuassianBlur_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x1efca5b6) {
		if (inClassId<=(int)0x04f93fcd) {
			return inClassId==(int)0x00000001 || inClassId==(int)0x04f93fcd;
		} else {
			return inClassId==(int)0x1efca5b6;
		}
	} else {
		return inClassId==(int)0x51501b88 || inClassId==(int)0x78d8d737;
	}
}

void GuassianBlur_obj::setSpriteBitmap( ::openfl::display::BitmapData spriteBit){
            	HX_STACKFRAME(&_hx_pos_0ec0183b593c1cf7_63_setSpriteBitmap)
HXDLIN(  63)		if (::hx::IsNotNull( spriteBit )) {
HXLINE(  64)			this->useExternalBit->value = ::Array_obj< bool >::fromData( _hx_array_data_c6e826a2_4,1);
HXLINE(  65)			this->bit->input = spriteBit;
            		}
            		else {
HXLINE(  67)			this->useExternalBit->value = ::Array_obj< bool >::fromData( _hx_array_data_c6e826a2_5,1);
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(GuassianBlur_obj,setSpriteBitmap,(void))

Float GuassianBlur_obj::set_size(Float Value){
            	HX_STACKFRAME(&_hx_pos_0ec0183b593c1cf7_71_set_size)
HXLINE(  72)		this->_size->value = ::Array_obj< Float >::__new(1)->init(0,Value);
HXLINE(  73)		return Value;
            	}


HX_DEFINE_DYNAMIC_FUNC1(GuassianBlur_obj,set_size,return )

Float GuassianBlur_obj::get_size(){
            	HX_STACKFRAME(&_hx_pos_0ec0183b593c1cf7_77_get_size)
HXDLIN(  77)		return this->_size->value->__get(0);
            	}


HX_DEFINE_DYNAMIC_FUNC0(GuassianBlur_obj,get_size,return )


::hx::ObjectPtr< GuassianBlur_obj > GuassianBlur_obj::__new(::hx::Null< Float >  __o_sizeValue, ::openfl::display::BitmapData spriteBit) {
	::hx::ObjectPtr< GuassianBlur_obj > __this = new GuassianBlur_obj();
	__this->__construct(__o_sizeValue,spriteBit);
	return __this;
}

::hx::ObjectPtr< GuassianBlur_obj > GuassianBlur_obj::__alloc(::hx::Ctx *_hx_ctx,::hx::Null< Float >  __o_sizeValue, ::openfl::display::BitmapData spriteBit) {
	GuassianBlur_obj *__this = (GuassianBlur_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(GuassianBlur_obj), true, "feshixl.filters.GuassianBlur"));
	*(void **)__this = GuassianBlur_obj::_hx_vtable;
	__this->__construct(__o_sizeValue,spriteBit);
	return __this;
}

GuassianBlur_obj::GuassianBlur_obj()
{
}

void GuassianBlur_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GuassianBlur);
	HX_MARK_MEMBER_NAME(bit,"bit");
	HX_MARK_MEMBER_NAME(_size,"_size");
	HX_MARK_MEMBER_NAME(useExternalBit,"useExternalBit");
	 ::flixel::graphics::tile::FlxGraphicsShader_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void GuassianBlur_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(bit,"bit");
	HX_VISIT_MEMBER_NAME(_size,"_size");
	HX_VISIT_MEMBER_NAME(useExternalBit,"useExternalBit");
	 ::flixel::graphics::tile::FlxGraphicsShader_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val GuassianBlur_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"bit") ) { return ::hx::Val( bit ); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"size") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_size() ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_size") ) { return ::hx::Val( _size ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"set_size") ) { return ::hx::Val( set_size_dyn() ); }
		if (HX_FIELD_EQ(inName,"get_size") ) { return ::hx::Val( get_size_dyn() ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"useExternalBit") ) { return ::hx::Val( useExternalBit ); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"setSpriteBitmap") ) { return ::hx::Val( setSpriteBitmap_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val GuassianBlur_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"bit") ) { bit=inValue.Cast<  ::openfl::display::ShaderInput_openfl_display_BitmapData >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"size") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_size(inValue.Cast< Float >()) ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_size") ) { _size=inValue.Cast<  ::openfl::display::ShaderParameter_Float >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"useExternalBit") ) { useExternalBit=inValue.Cast<  ::openfl::display::ShaderParameter_Bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void GuassianBlur_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("size",c1,a0,53,4c));
	outFields->push(HX_("bit",cd,b8,4a,00));
	outFields->push(HX_("_size",a0,bc,64,ff));
	outFields->push(HX_("useExternalBit",3b,c2,9f,e5));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo GuassianBlur_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::openfl::display::ShaderInput_openfl_display_BitmapData */ ,(int)offsetof(GuassianBlur_obj,bit),HX_("bit",cd,b8,4a,00)},
	{::hx::fsObject /*  ::openfl::display::ShaderParameter_Float */ ,(int)offsetof(GuassianBlur_obj,_size),HX_("_size",a0,bc,64,ff)},
	{::hx::fsObject /*  ::openfl::display::ShaderParameter_Bool */ ,(int)offsetof(GuassianBlur_obj,useExternalBit),HX_("useExternalBit",3b,c2,9f,e5)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *GuassianBlur_obj_sStaticStorageInfo = 0;
#endif

static ::String GuassianBlur_obj_sMemberFields[] = {
	HX_("setSpriteBitmap",96,84,a4,a7),
	HX_("set_size",be,b5,6b,7a),
	HX_("get_size",4a,5c,0e,cc),
	HX_("bit",cd,b8,4a,00),
	HX_("_size",a0,bc,64,ff),
	HX_("useExternalBit",3b,c2,9f,e5),
	::String(null()) };

::hx::Class GuassianBlur_obj::__mClass;

void GuassianBlur_obj::__register()
{
	GuassianBlur_obj _hx_dummy;
	GuassianBlur_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("feshixl.filters.GuassianBlur",a2,26,e8,c6);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(GuassianBlur_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< GuassianBlur_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = GuassianBlur_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = GuassianBlur_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void GuassianBlur_obj::__boot()
{
{
            	HX_STACKFRAME(&_hx_pos_0ec0183b593c1cf7_13_boot)
HXDLIN(  13)		__mClass->__meta__ =  ::Dynamic(::hx::Anon_obj::Create(1)
            			->setFixed(0,HX_("obj",f7,8f,54,00), ::Dynamic(::hx::Anon_obj::Create(1)
            				->setFixed(0,HX_("author",8b,ea,7b,73),::cpp::VirtualArray_obj::__new(1)->init(0,HX_("Feeshy",de,03,8e,67))))));
            	}
}

} // end namespace feshixl
} // end namespace filters
