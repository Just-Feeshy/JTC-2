#ifndef INCLUDED_io_newgrounds_ICallable
#define INCLUDED_io_newgrounds_ICallable

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(io,newgrounds,ICallable)

namespace io{
namespace newgrounds{


class HXCPP_CLASS_ATTRIBUTES ICallable_obj {
	public:
		typedef ::hx::Object super;
		HX_DO_INTERFACE_RTTI;

		void (::hx::Object :: *_hx_send)(); 
		static inline void send( ::Dynamic _hx_) {
			(_hx_.mPtr->*( ::hx::interface_cast< ::io::newgrounds::ICallable_obj *>(_hx_.mPtr->_hx_getInterface(0xda87fdcf)))->_hx_send)();
		}
		void (::hx::Object :: *_hx_queue)(); 
		static inline void queue( ::Dynamic _hx_) {
			(_hx_.mPtr->*( ::hx::interface_cast< ::io::newgrounds::ICallable_obj *>(_hx_.mPtr->_hx_getInterface(0xda87fdcf)))->_hx_queue)();
		}
		void (::hx::Object :: *_hx_destroy)(); 
		static inline void destroy( ::Dynamic _hx_) {
			(_hx_.mPtr->*( ::hx::interface_cast< ::io::newgrounds::ICallable_obj *>(_hx_.mPtr->_hx_getInterface(0xda87fdcf)))->_hx_destroy)();
		}
};

} // end namespace io
} // end namespace newgrounds

#endif /* INCLUDED_io_newgrounds_ICallable */ 
