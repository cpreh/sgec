#ifndef SGEC_INPUT_MOUSE_DEVICE_H_INCLUDED
#define SGEC_INPUT_MOUSE_DEVICE_H_INCLUDED

#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>
#include <sgec/detail/symbol.h>
#include <sgec/input/mouse/axis_callback.h>
#include <sgec/input/mouse/button_callback.h>
#include <sgec/input/mouse/device_fwd.h>


SGEC_DETAIL_HEADER

SGEC_DETAIL_SYMBOL
struct sgec_signal_connection *
sgec_input_mouse_device_connect_axis_callback(
	struct sgec_input_mouse_device *,
	sgec_input_mouse_axis_callback,
	void *userdata
);

SGEC_DETAIL_SYMBOL
struct sgec_signal_connection *
sgec_input_mouse_device_connect_button_callback(
	struct sgec_input_mouse_device *,
	sgec_input_mouse_button_callback,
	void *userdata
);

SGEC_DETAIL_FOOTER

#endif
