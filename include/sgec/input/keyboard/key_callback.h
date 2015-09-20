#ifndef SGEC_INPUT_KEYBOARD_KEY_CALLBACK_H_INCLUDED
#define SGEC_INPUT_KEYBOARD_KEY_CALLBACK_H_INCLUDED

#include <sgec/input/key/code.h>
#include <sgec/input/key/state.h>
#include <sgec/input/keyboard/key_id.h>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>


SGEC_DETAIL_HEADER

typedef
void
(*sgec_input_keyboard_key_callback)(
	enum sgec_input_key_code,
	enum sgec_input_key_state,
	sgec_input_keyboard_key_id,
	void *userdata
);

SGEC_DETAIL_FOOTER

#endif
