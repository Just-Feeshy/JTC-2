#include <hxcpp.h>

#ifndef INCLUDED_BuiltInShaders
#include <BuiltInShaders.h>
#endif
#ifndef INCLUDED_ShaderType
#include <ShaderType.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
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
#ifndef INCLUDED_openfl_display_ShaderParameter_Int
#include <openfl/display/ShaderParameter_Int.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_3049b886310d8bd0_76_new,"BuiltInShaders","new",0xfccba7bd,"BuiltInShaders.new","BuiltInShaders.hx",76,0x092b5e53)
static const bool _hx_array_data_701c054b_1[] = {
	1,
};
static const bool _hx_array_data_701c054b_2[] = {
	0,
};
static const Float _hx_array_data_701c054b_3[] = {
	(Float)0,
};
HX_LOCAL_STACK_FRAME(_hx_pos_3049b886310d8bd0_89_set_shader,"BuiltInShaders","set_shader",0xc6ba4ba5,"BuiltInShaders.set_shader","BuiltInShaders.hx",89,0x092b5e53)
HX_LOCAL_STACK_FRAME(_hx_pos_3049b886310d8bd0_95_set_position,"BuiltInShaders","set_position",0x37704d29,"BuiltInShaders.set_position","BuiltInShaders.hx",95,0x092b5e53)
HX_LOCAL_STACK_FRAME(_hx_pos_3049b886310d8bd0_101_updateBitmap,"BuiltInShaders","updateBitmap",0x93328bdb,"BuiltInShaders.updateBitmap","BuiltInShaders.hx",101,0x092b5e53)

void BuiltInShaders_obj::__construct( ::openfl::display::BitmapData spriteBit){
            	HX_STACKFRAME(&_hx_pos_3049b886310d8bd0_76_new)
HXLINE( 182)		if (::hx::IsNull( this->_hx___glFragmentSource )) {
HXLINE( 184)			this->_hx___glFragmentSource = HX_("\r\n        varying float openfl_Alphav;\n\t\tvarying vec4 openfl_ColorMultiplierv;\n\t\tvarying vec4 openfl_ColorOffsetv;\n\t\tvarying vec2 openfl_TextureCoordv;\n\n\t\tuniform bool openfl_HasColorTransform;\n\t\tuniform vec2 openfl_TextureSize;\n\t\tuniform sampler2D bitmap;\n\n\t\tuniform bool hasTransform;\n\t\tuniform bool hasColorTransform;\n\n\t\tvec4 flixel_texture2D(sampler2D bitmap, vec2 coord)\n\t\t{\n\t\t\tvec4 color = texture2D(bitmap, coord);\n\t\t\tif (!hasTransform)\n\t\t\t{\n\t\t\t\treturn color;\n\t\t\t}\n\n\t\t\tif (color.a == 0.0)\n\t\t\t{\n\t\t\t\treturn vec4(0.0, 0.0, 0.0, 0.0);\n\t\t\t}\n\n\t\t\tif (!hasColorTransform)\n\t\t\t{\n\t\t\t\treturn color * openfl_Alphav;\n\t\t\t}\n\n\t\t\tcolor = vec4(color.rgb / color.a, color.a);\n\n\t\t\tmat4 colorMultiplier = mat4(0);\n\t\t\tcolorMultiplier[0][0] = openfl_ColorMultiplierv.x;\n\t\t\tcolorMultiplier[1][1] = openfl_ColorMultiplierv.y;\n\t\t\tcolorMultiplier[2][2] = openfl_ColorMultiplierv.z;\n\t\t\tcolorMultiplier[3][3] = openfl_ColorMultiplierv.w;\n\n\t\t\tcolor = clamp(openfl_ColorOffsetv + (color * colorMultiplier), 0.0, 1.0);\n\n\t\t\tif (color.a > 0.0)\n\t\t\t{\n\t\t\t\treturn vec4(color.rgb * color.a * openfl_Alphav, color.a * openfl_Alphav);\n\t\t\t}\n\t\t\treturn vec4(0.0, 0.0, 0.0, 0.0);\n\t\t}\n\t\n\r\n\r\n        uniform sampler2D bit;\r\n        uniform float shaderValue;\r\n        uniform bool useExternalBit;\r\n        uniform int shad;\r\n\r\n        const int MINING_SIM_LOADING = 0;\r\n        const int GLIM_SELECTION = 1;\r\n\r\n        mat2 setAngle(float rotation) {\r\n            return mat2(cos(rotation), -sin(rotation), sin(rotation), cos(rotation));\r\n        }\r\n\r\n        float drawRect(vec2 pixelCoord, vec2 width) {\r\n            vec2 bL = step(width, pixelCoord);\r\n            vec2 tR = step(width, 1.0 - pixelCoord);\r\n\r\n            return (bL.x * bL.y) * (tR.x * tR.y);\r\n        }\r\n\r\n        vec4 color() {\r\n            if(useExternalBit == true)\r\n                return flixel_texture2D(bit, openfl_TextureCoordv);\r\n            else\r\n                return flixel_texture2D(bitmap, openfl_TextureCoordv);\r\n        }\r\n\r\n        void robloxIntro() {\r\n            gl_FragColor = vec4((vec3(color().r+color().g+color().b)/3.0) * (1 - shaderValue) + color().rgb * shaderValue, color().a);\r\n        }\r\n\r\n        void objSelect() {\r\n            const float PI = 3.14159265358979323846;\r\n\r\n            vec2 pixelCoord = openfl_TextureCoordv;\r\n\r\n            pixelCoord -= vec2(sin(shaderValue * 3.0) / 2.0) + 0.5;\r\n            pixelCoord = setAngle(PI / 4.0) * pixelCoord;\r\n            pixelCoord += vec2(0.5);\r\n\r\n            float box = drawRect(pixelCoord, vec2(0.45, -0.45));\r\n\r\n            if(color().a != 0.0) {\r\n                if(box == 0.0) {\r\n                    gl_FragColor = color();\r\n                } else {\r\n                    gl_FragColor = vec4(vec3(1.0), color().a);\r\n                }\r\n            }\r\n        }\r\n\r\n        void main() {\r\n            if(shad == MINING_SIM_LOADING)\r\n                robloxIntro();\r\n            else if(shad == GLIM_SELECTION)\r\n                objSelect();\r\n        }\r\n    ",9c,cb,6c,1e);
            		}
HXLINE( 174)		if (::hx::IsNull( this->_hx___glVertexSource )) {
HXLINE( 176)			this->_hx___glVertexSource = HX_("\n\t\tattribute float openfl_Alpha;\n\t\tattribute vec4 openfl_ColorMultiplier;\n\t\tattribute vec4 openfl_ColorOffset;\n\t\tattribute vec4 openfl_Position;\n\t\tattribute vec2 openfl_TextureCoord;\n\n\t\tvarying float openfl_Alphav;\n\t\tvarying vec4 openfl_ColorMultiplierv;\n\t\tvarying vec4 openfl_ColorOffsetv;\n\t\tvarying vec2 openfl_TextureCoordv;\n\n\t\tuniform mat4 openfl_Matrix;\n\t\tuniform bool openfl_HasColorTransform;\n\t\tuniform vec2 openfl_TextureSize;\n\n\t\t\n\t\tattribute float alpha;\n\t\tattribute vec4 colorMultiplier;\n\t\tattribute vec4 colorOffset;\n\t\tuniform bool hasColorTransform;\n\t\t\n\t\tvoid main(void)\n\t\t{\n\t\t\topenfl_Alphav = openfl_Alpha;\n\t\topenfl_TextureCoordv = openfl_TextureCoord;\n\n\t\tif (openfl_HasColorTransform) {\n\n\t\t\topenfl_ColorMultiplierv = openfl_ColorMultiplier;\n\t\t\topenfl_ColorOffsetv = openfl_ColorOffset / 255.0;\n\n\t\t}\n\n\t\tgl_Position = openfl_Matrix * openfl_Position;\n\n\t\t\t\n\t\t\topenfl_Alphav = openfl_Alpha * alpha;\n\t\t\t\n\t\t\tif (hasColorTransform)\n\t\t\t{\n\t\t\t\topenfl_ColorOffsetv = colorOffset / 255.0;\n\t\t\t\topenfl_ColorMultiplierv = colorMultiplier;\n\t\t\t}\n\t\t}",f3,1e,fa,79);
            		}
HXLINE(  77)		super::__construct();
HXLINE(  79)		if (::hx::IsNotNull( spriteBit )) {
HXLINE(  80)			this->useExternalBit->value = ::Array_obj< bool >::fromData( _hx_array_data_701c054b_1,1);
HXLINE(  81)			this->bit->input = spriteBit;
            		}
            		else {
HXLINE(  83)			this->useExternalBit->value = ::Array_obj< bool >::fromData( _hx_array_data_701c054b_2,1);
            		}
HXLINE(  86)		this->shaderValue->value = ::Array_obj< Float >::fromData( _hx_array_data_701c054b_3,1);
HXLINE(  12)		this->_hx___isGenerated = true;
HXDLIN(  12)		this->_hx___initGL();
            	}

Dynamic BuiltInShaders_obj::__CreateEmpty() { return new BuiltInShaders_obj; }

void *BuiltInShaders_obj::_hx_vtable = 0;

Dynamic BuiltInShaders_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< BuiltInShaders_obj > _hx_result = new BuiltInShaders_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool BuiltInShaders_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x1efca5b6) {
		if (inClassId<=(int)0x04f93fcd) {
			return inClassId==(int)0x00000001 || inClassId==(int)0x04f93fcd;
		} else {
			return inClassId==(int)0x1efca5b6;
		}
	} else {
		return inClassId==(int)0x5207880b || inClassId==(int)0x78d8d737;
	}
}

 ::ShaderType BuiltInShaders_obj::set_shader( ::ShaderType v){
            	HX_STACKFRAME(&_hx_pos_3049b886310d8bd0_89_set_shader)
HXLINE(  90)		this->shader = v;
HXLINE(  91)		::Array< ::String > _hx_tmp = ::Type_obj::getEnumConstructs(::hx::ClassOf< ::ShaderType >());
HXDLIN(  91)		int _hx_tmp1 = _hx_tmp->indexOf(::Std_obj::string(v),null());
HXDLIN(  91)		this->shad->value = ::Array_obj< int >::__new(1)->init(0,_hx_tmp1);
HXLINE(  92)		return v;
            	}


HX_DEFINE_DYNAMIC_FUNC1(BuiltInShaders_obj,set_shader,return )

Float BuiltInShaders_obj::set_position(Float v){
            	HX_STACKFRAME(&_hx_pos_3049b886310d8bd0_95_set_position)
HXLINE(  96)		this->position = v;
HXLINE(  97)		this->shaderValue->value = ::Array_obj< Float >::__new(1)->init(0,this->position);
HXLINE(  98)		return v;
            	}


HX_DEFINE_DYNAMIC_FUNC1(BuiltInShaders_obj,set_position,return )

 ::openfl::display::BitmapData BuiltInShaders_obj::updateBitmap( ::openfl::display::BitmapData v){
            	HX_STACKFRAME(&_hx_pos_3049b886310d8bd0_101_updateBitmap)
HXLINE( 102)		this->bit->input = v;
HXLINE( 103)		return v;
            	}


HX_DEFINE_DYNAMIC_FUNC1(BuiltInShaders_obj,updateBitmap,return )


::hx::ObjectPtr< BuiltInShaders_obj > BuiltInShaders_obj::__new( ::openfl::display::BitmapData spriteBit) {
	::hx::ObjectPtr< BuiltInShaders_obj > __this = new BuiltInShaders_obj();
	__this->__construct(spriteBit);
	return __this;
}

::hx::ObjectPtr< BuiltInShaders_obj > BuiltInShaders_obj::__alloc(::hx::Ctx *_hx_ctx, ::openfl::display::BitmapData spriteBit) {
	BuiltInShaders_obj *__this = (BuiltInShaders_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(BuiltInShaders_obj), true, "BuiltInShaders"));
	*(void **)__this = BuiltInShaders_obj::_hx_vtable;
	__this->__construct(spriteBit);
	return __this;
}

BuiltInShaders_obj::BuiltInShaders_obj()
{
}

void BuiltInShaders_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BuiltInShaders);
	HX_MARK_MEMBER_NAME(shader,"shader");
	HX_MARK_MEMBER_NAME(position,"position");
	HX_MARK_MEMBER_NAME(bit,"bit");
	HX_MARK_MEMBER_NAME(shaderValue,"shaderValue");
	HX_MARK_MEMBER_NAME(useExternalBit,"useExternalBit");
	HX_MARK_MEMBER_NAME(shad,"shad");
	 ::flixel::graphics::tile::FlxGraphicsShader_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void BuiltInShaders_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(shader,"shader");
	HX_VISIT_MEMBER_NAME(position,"position");
	HX_VISIT_MEMBER_NAME(bit,"bit");
	HX_VISIT_MEMBER_NAME(shaderValue,"shaderValue");
	HX_VISIT_MEMBER_NAME(useExternalBit,"useExternalBit");
	HX_VISIT_MEMBER_NAME(shad,"shad");
	 ::flixel::graphics::tile::FlxGraphicsShader_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val BuiltInShaders_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"bit") ) { return ::hx::Val( bit ); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"shad") ) { return ::hx::Val( shad ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"shader") ) { return ::hx::Val( shader ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { return ::hx::Val( position ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"set_shader") ) { return ::hx::Val( set_shader_dyn() ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"shaderValue") ) { return ::hx::Val( shaderValue ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"set_position") ) { return ::hx::Val( set_position_dyn() ); }
		if (HX_FIELD_EQ(inName,"updateBitmap") ) { return ::hx::Val( updateBitmap_dyn() ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"useExternalBit") ) { return ::hx::Val( useExternalBit ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val BuiltInShaders_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"bit") ) { bit=inValue.Cast<  ::openfl::display::ShaderInput_openfl_display_BitmapData >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"shad") ) { shad=inValue.Cast<  ::openfl::display::ShaderParameter_Int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"shader") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_shader(inValue.Cast<  ::ShaderType >()) );shader=inValue.Cast<  ::ShaderType >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_position(inValue.Cast< Float >()) );position=inValue.Cast< Float >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"shaderValue") ) { shaderValue=inValue.Cast<  ::openfl::display::ShaderParameter_Float >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"useExternalBit") ) { useExternalBit=inValue.Cast<  ::openfl::display::ShaderParameter_Bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BuiltInShaders_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("shader",25,bf,20,1d));
	outFields->push(HX_("position",a9,a0,fa,ca));
	outFields->push(HX_("bit",cd,b8,4a,00));
	outFields->push(HX_("shaderValue",0c,2a,e5,08));
	outFields->push(HX_("useExternalBit",3b,c2,9f,e5));
	outFields->push(HX_("shad",b8,c8,52,4c));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo BuiltInShaders_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::ShaderType */ ,(int)offsetof(BuiltInShaders_obj,shader),HX_("shader",25,bf,20,1d)},
	{::hx::fsFloat,(int)offsetof(BuiltInShaders_obj,position),HX_("position",a9,a0,fa,ca)},
	{::hx::fsObject /*  ::openfl::display::ShaderInput_openfl_display_BitmapData */ ,(int)offsetof(BuiltInShaders_obj,bit),HX_("bit",cd,b8,4a,00)},
	{::hx::fsObject /*  ::openfl::display::ShaderParameter_Float */ ,(int)offsetof(BuiltInShaders_obj,shaderValue),HX_("shaderValue",0c,2a,e5,08)},
	{::hx::fsObject /*  ::openfl::display::ShaderParameter_Bool */ ,(int)offsetof(BuiltInShaders_obj,useExternalBit),HX_("useExternalBit",3b,c2,9f,e5)},
	{::hx::fsObject /*  ::openfl::display::ShaderParameter_Int */ ,(int)offsetof(BuiltInShaders_obj,shad),HX_("shad",b8,c8,52,4c)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *BuiltInShaders_obj_sStaticStorageInfo = 0;
#endif

static ::String BuiltInShaders_obj_sMemberFields[] = {
	HX_("shader",25,bf,20,1d),
	HX_("position",a9,a0,fa,ca),
	HX_("set_shader",62,cd,25,11),
	HX_("set_position",26,78,0d,95),
	HX_("updateBitmap",d8,b6,cf,f0),
	HX_("bit",cd,b8,4a,00),
	HX_("shaderValue",0c,2a,e5,08),
	HX_("useExternalBit",3b,c2,9f,e5),
	HX_("shad",b8,c8,52,4c),
	::String(null()) };

::hx::Class BuiltInShaders_obj::__mClass;

void BuiltInShaders_obj::__register()
{
	BuiltInShaders_obj _hx_dummy;
	BuiltInShaders_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("BuiltInShaders",4b,05,1c,70);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(BuiltInShaders_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< BuiltInShaders_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = BuiltInShaders_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = BuiltInShaders_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

