#include <sgec/impl/input/keyboard/device.hpp>
#include <sgec/input/keyboard/device.h>
#include <sgec/input/keyboard/key_callback.h>
#include <sgec/input/keyboard/key_repeat_callback.h>
#include <sgec/signal/connection_fwd.h>


extern "C"
struct sgec_signal_connection *
sgec_input_keyboard_device_connect_key_callback(
	struct sgec_input_keyboard_device *const _device,
	sgec_input_keyboard_key_callback const _callback,
	void *const _userdata
)
try
{
	return
		_device->key_callback(
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
sgec_input_keyboard_device_connect_key_repeat_callback(
	struct sgec_input_keyboard_device *const _device,
	sgec_input_keyboard_key_repeat_callback const _callback,
	void *const _userdata
)
try
{
	return
		_device->key_repeat_callback(
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
