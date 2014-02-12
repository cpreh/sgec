#ifndef SGEC_INPUT_KEYBOARD_KEY_CALLBACK_H_INCLUDED
#define SGEC_INPUT_KEYBOARD_KEY_CALLBACK_H_INCLUDED

#include <sgec/input/keyboard/key_code.h>
#include <sgec/input/keyboard/key_state.h>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>


SGEC_DETAIL_HEADER

typedef
void
(*sgec_input_keyboard_key_callback)(
	enum sgec_input_keyboard_key_code,
	enum sgec_input_keyboard_key_state,
	void *userdata
);

SGEC_DETAIL_FOOTER

#endif
