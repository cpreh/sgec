#ifndef SGEC_INPUT_KEYBOARD_DEVICE_H_INCLUDED
#define SGEC_INPUT_KEYBOARD_DEVICE_H_INCLUDED

#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>
#include <sgec/detail/symbol.h>
#include <sgec/input/keyboard/device_fwd.h>
#include <sgec/input/keyboard/key_callback.h>
#include <sgec/input/keyboard/key_repeat_callback.h>


SGEC_DETAIL_HEADER

SGEC_DETAIL_SYMBOL
struct sgec_signal_connection *
sgec_input_keyboard_device_connect_key_callback(
	struct sgec_input_keyboard_device *,
	sgec_input_keyboard_key_callback,
	void *userdata
);

SGEC_DETAIL_SYMBOL
struct sgec_signal_connection *
sgec_input_keyboard_device_connect_key_repeat_callback(
	struct sgec_input_keyboard_device *,
	sgec_input_keyboard_key_repeat_callback,
	void *userdata
);

SGEC_DETAIL_FOOTER

#endif
