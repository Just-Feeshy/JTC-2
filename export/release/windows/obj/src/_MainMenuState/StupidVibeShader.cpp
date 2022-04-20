#include <hxcpp.h>

#ifndef INCLUDED__MainMenuState_StupidVibeShader
#include <_MainMenuState/StupidVibeShader.h>
#endif
#ifndef INCLUDED_flixel_graphics_tile_FlxGraphicsShader
#include <flixel/graphics/tile/FlxGraphicsShader.h>
#endif
#ifndef INCLUDED_openfl_display_GraphicsShader
#include <openfl/display/GraphicsShader.h>
#endif
#ifndef INCLUDED_openfl_display_Shader
#include <openfl/display/Shader.h>
#endif
#ifndef INCLUDED_openfl_display_ShaderParameter_Float
#include <openfl/display/ShaderParameter_Float.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_181230d548cf356a_57_new,"_MainMenuState.StupidVibeShader","new",0xec65acd8,"_MainMenuState.StupidVibeShader.new","MainMenuState.hx",57,0x0e5db805)
namespace _MainMenuState{

void StupidVibeShader_obj::__construct(Float vibeMeter){
            	HX_STACKFRAME(&_hx_pos_181230d548cf356a_57_new)
HXLINE( 182)		if (::hx::IsNull( this->_hx___glFragmentSource )) {
HXLINE( 184)			this->_hx___glFragmentSource = HX_("\r\n        varying float openfl_Alphav;\n\t\tvarying vec4 openfl_ColorMultiplierv;\n\t\tvarying vec4 openfl_ColorOffsetv;\n\t\tvarying vec2 openfl_TextureCoordv;\n\n\t\tuniform bool openfl_HasColorTransform;\n\t\tuniform vec2 openfl_TextureSize;\n\t\tuniform sampler2D bitmap;\n\n\t\tuniform bool hasTransform;\n\t\tuniform bool hasColorTransform;\n\n\t\tvec4 flixel_texture2D(sampler2D bitmap, vec2 coord)\n\t\t{\n\t\t\tvec4 color = texture2D(bitmap, coord);\n\t\t\tif (!hasTransform)\n\t\t\t{\n\t\t\t\treturn color;\n\t\t\t}\n\n\t\t\tif (color.a == 0.0)\n\t\t\t{\n\t\t\t\treturn vec4(0.0, 0.0, 0.0, 0.0);\n\t\t\t}\n\n\t\t\tif (!hasColorTransform)\n\t\t\t{\n\t\t\t\treturn color * openfl_Alphav;\n\t\t\t}\n\n\t\t\tcolor = vec4(color.rgb / color.a, color.a);\n\n\t\t\tmat4 colorMultiplier = mat4(0);\n\t\t\tcolorMultiplier[0][0] = openfl_ColorMultiplierv.x;\n\t\t\tcolorMultiplier[1][1] = openfl_ColorMultiplierv.y;\n\t\t\tcolorMultiplier[2][2] = openfl_ColorMultiplierv.z;\n\t\t\tcolorMultiplier[3][3] = openfl_ColorMultiplierv.w;\n\n\t\t\tcolor = clamp(openfl_ColorOffsetv + (color * colorMultiplier), 0.0, 1.0);\n\n\t\t\tif (color.a > 0.0)\n\t\t\t{\n\t\t\t\treturn vec4(color.rgb * color.a * openfl_Alphav, color.a * openfl_Alphav);\n\t\t\t}\n\t\t\treturn vec4(0.0, 0.0, 0.0, 0.0);\n\t\t}\n\t\n\r\n\r\n        uniform float vibe;\r\n\r\n\t\tvoid main() {\r\n\t\t\tvec4 color = flixel_texture2D(bitmap, openfl_TextureCoordv);\r\n\r\n\t\t\tgl_FragColor = vec4((vec3(color.r+color.g+color.b)/3.0) * (1.0 - vibe) + color.rgb * vibe, color.a);\r\n\t\t}\r\n    ",94,a3,df,7e);
            		}
HXLINE( 174)		if (::hx::IsNull( this->_hx___glVertexSource )) {
HXLINE( 176)			this->_hx___glVertexSource = HX_("\n\t\tattribute float openfl_Alpha;\n\t\tattribute vec4 openfl_ColorMultiplier;\n\t\tattribute vec4 openfl_ColorOffset;\n\t\tattribute vec4 openfl_Position;\n\t\tattribute vec2 openfl_TextureCoord;\n\n\t\tvarying float openfl_Alphav;\n\t\tvarying vec4 openfl_ColorMultiplierv;\n\t\tvarying vec4 openfl_ColorOffsetv;\n\t\tvarying vec2 openfl_TextureCoordv;\n\n\t\tuniform mat4 openfl_Matrix;\n\t\tuniform bool openfl_HasColorTransform;\n\t\tuniform vec2 openfl_TextureSize;\n\n\t\t\n\t\tattribute float alpha;\n\t\tattribute vec4 colorMultiplier;\n\t\tattribute vec4 colorOffset;\n\t\tuniform bool hasColorTransform;\n\t\t\n\t\tvoid main(void)\n\t\t{\n\t\t\topenfl_Alphav = openfl_Alpha;\n\t\topenfl_TextureCoordv = openfl_TextureCoord;\n\n\t\tif (openfl_HasColorTransform) {\n\n\t\t\topenfl_ColorMultiplierv = openfl_ColorMultiplier;\n\t\t\topenfl_ColorOffsetv = openfl_ColorOffset / 255.0;\n\n\t\t}\n\n\t\tgl_Position = openfl_Matrix * openfl_Position;\n\n\t\t\t\n\t\t\topenfl_Alphav = openfl_Alpha * alpha;\n\t\t\t\n\t\t\tif (hasColorTransform)\n\t\t\t{\n\t\t\t\topenfl_ColorOffsetv = colorOffset / 255.0;\n\t\t\t\topenfl_ColorMultiplierv = colorMultiplier;\n\t\t\t}\n\t\t}",f3,1e,fa,79);
            		}
HXLINE(  58)		super::__construct();
HXLINE(  60)		this->vibe->value = ::Array_obj< Float >::__new(1)->init(0,vibeMeter);
HXLINE(  44)		this->_hx___isGenerated = true;
HXDLIN(  44)		this->_hx___initGL();
            	}

Dynamic StupidVibeShader_obj::__CreateEmpty() { return new StupidVibeShader_obj; }

void *StupidVibeShader_obj::_hx_vtable = 0;

Dynamic StupidVibeShader_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< StupidVibeShader_obj > _hx_result = new StupidVibeShader_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool StupidVibeShader_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x1efca5b6) {
		if (inClassId<=(int)0x04f93fcd) {
			return inClassId==(int)0x00000001 || inClassId==(int)0x04f93fcd;
		} else {
			return inClassId==(int)0x1efca5b6;
		}
	} else {
		return inClassId==(int)0x23a00b58 || inClassId==(int)0x78d8d737;
	}
}


::hx::ObjectPtr< StupidVibeShader_obj > StupidVibeShader_obj::__new(Float vibeMeter) {
	::hx::ObjectPtr< StupidVibeShader_obj > __this = new StupidVibeShader_obj();
	__this->__construct(vibeMeter);
	return __this;
}

::hx::ObjectPtr< StupidVibeShader_obj > StupidVibeShader_obj::__alloc(::hx::Ctx *_hx_ctx,Float vibeMeter) {
	StupidVibeShader_obj *__this = (StupidVibeShader_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(StupidVibeShader_obj), true, "_MainMenuState.StupidVibeShader"));
	*(void **)__this = StupidVibeShader_obj::_hx_vtable;
	__this->__construct(vibeMeter);
	return __this;
}

StupidVibeShader_obj::StupidVibeShader_obj()
{
}

void StupidVibeShader_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(StupidVibeShader);
	HX_MARK_MEMBER_NAME(vibe,"vibe");
	 ::flixel::graphics::tile::FlxGraphicsShader_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void StupidVibeShader_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(vibe,"vibe");
	 ::flixel::graphics::tile::FlxGraphicsShader_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val StupidVibeShader_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"vibe") ) { return ::hx::Val( vibe ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val StupidVibeShader_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"vibe") ) { vibe=inValue.Cast<  ::openfl::display::ShaderParameter_Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void StupidVibeShader_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("vibe",b6,2f,4f,4e));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo StupidVibeShader_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::openfl::display::ShaderParameter_Float */ ,(int)offsetof(StupidVibeShader_obj,vibe),HX_("vibe",b6,2f,4f,4e)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *StupidVibeShader_obj_sStaticStorageInfo = 0;
#endif

static ::String StupidVibeShader_obj_sMemberFields[] = {
	HX_("vibe",b6,2f,4f,4e),
	::String(null()) };

::hx::Class StupidVibeShader_obj::__mClass;

void StupidVibeShader_obj::__register()
{
	StupidVibeShader_obj _hx_dummy;
	StupidVibeShader_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("_MainMenuState.StupidVibeShader",e6,a0,b0,2a);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(StupidVibeShader_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< StupidVibeShader_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = StupidVibeShader_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = StupidVibeShader_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace _MainMenuState
