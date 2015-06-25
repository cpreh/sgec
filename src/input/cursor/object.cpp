#include <sgec/impl/input/cursor/object.hpp>
#include <sgec/input/cursor/button_callback.h>
#include <sgec/input/cursor/object.h>
#include <sgec/signal/connection_fwd.h>


extern "C"
struct sgec_signal_connection *
sgec_input_cursor_object_connect_button_callback(
	struct sgec_input_cursor_object *const _object,
	sgec_input_cursor_button_callback const _callback,
	void *const _userdata
)
try
{
	return
		_object->button_callback(
			_callback,
			_userdata
		);
}
catch(
	...
)
{
	return
		nullptr;
}
