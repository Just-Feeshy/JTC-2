#ifndef INCLUDED_Song
#define INCLUDED_Song

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_STACK_FRAME(_hx_pos_4e288e2989890fc6_44_new)
HX_DECLARE_CLASS0(Song)



class HXCPP_CLASS_ATTRIBUTES Song_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef Song_obj OBJ_;
		Song_obj();

	public:
		enum { _hx_ClassId = 0x0b844619 };

		void __construct(::String song,::Array< ::Dynamic> notes,int bpm,int fps);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="Song")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"Song"); }

		inline static ::hx::ObjectPtr< Song_obj > __new(::String song,::Array< ::Dynamic> notes,int bpm,int fps) {
			::hx::ObjectPtr< Song_obj > __this = new Song_obj();
			__this->__construct(song,notes,bpm,fps);
			return __this;
		}

		inline static ::hx::ObjectPtr< Song_obj > __alloc(::hx::Ctx *_hx_ctx,::String song,::Array< ::Dynamic> notes,int bpm,int fps) {
			Song_obj *__this = (Song_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Song_obj), true, "Song"));
			*(void **)__this = Song_obj::_hx_vtable;
{
            	HX_STACKFRAME(&_hx_pos_4e288e2989890fc6_44_new)
HXLINE(  51)		( ( ::Song)(__this) )->speed = ((Float)1);
HXLINE(  50)		( ( ::Song)(__this) )->needsVoices = true;
HXLINE(  65)		( ( ::Song)(__this) )->song = song;
HXLINE(  66)		( ( ::Song)(__this) )->notes = notes;
HXLINE(  67)		( ( ::Song)(__this) )->bpm = bpm;
HXLINE(  68)		( ( ::Song)(__this) )->fps = fps;
            	}
		
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Song_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Song",f5,4f,31,37); }

		static  ::Dynamic loadFromJson(::String jsonInput,::String folder, ::Dynamic ifPlayState);
		static ::Dynamic loadFromJson_dyn();

		static ::String getRawJSON(::String jsonInput,::String folder);
		static ::Dynamic getRawJSON_dyn();

		static  ::Dynamic parseJSONshit(::String rawJson);
		static ::Dynamic parseJSONshit_dyn();

		::String song;
		::Array< ::Dynamic> notes;
		::Array< ::Dynamic> modifiers;
		int bpm;
		bool needsVoices;
		Float speed;
		int colorMapping;
		int fps;
		Float player1X;
		Float player1Y;
		Float player2X;
		Float player2Y;
		bool fifthKey;
};


#endif /* INCLUDED_Song */ 
