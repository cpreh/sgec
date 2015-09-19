#include <sgec/impl/input/focus/object.hpp>
#include <sgec/input/focus/key_callback.h>
#include <sgec/input/focus/key_repeat_callback.h>
#include <sgec/input/focus/object.h>
#include <sgec/signal/connection_fwd.h>


extern "C"
struct sgec_signal_connection *
sgec_input_focus_object_connect_key_callback(
	struct sgec_input_focus_object *const _object,
	sgec_input_focus_key_callback const _callback,
	void *const _userdata
)
try
{
	return
		_object->key_callback(
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

extern "C"
struct sgec_signal_connection *
sgec_input_focus_object_connect_key_repeat_callback(
	struct sgec_input_focus_object *const _object,
	sgec_input_focus_key_repeat_callback const _callback,
	void *const _userdata
)
try
{
	return
		_object->key_repeat_callback(
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
