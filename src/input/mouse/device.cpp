#include <sgec/impl/input/mouse/device.hpp>
#include <sgec/input/mouse/axis_callback.h>
#include <sgec/input/mouse/button_callback.h>
#include <sgec/input/mouse/device.h>
#include <sgec/signal/connection_fwd.h>


extern "C"
struct sgec_signal_connection *
sgec_input_mouse_device_connect_axis_callback(
	struct sgec_input_mouse_device *const _device,
	sgec_input_mouse_axis_callback const _callback,
	void *const _userdata
)
try
{
	return
		_device->axis_callback(
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
sgec_input_mouse_device_connect_button_callback(
	struct sgec_input_mouse_device *const _device,
	sgec_input_mouse_button_callback const _callback,
	void *const _userdata
)
try
{
	return
		_device->button_callback(
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
