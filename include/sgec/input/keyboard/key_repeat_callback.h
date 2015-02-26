#ifndef SGEC_INPUT_KEYBOARD_KEY_REPEAT_CALLBACK_H_INCLUDED
#define SGEC_INPUT_KEYBOARD_KEY_REPEAT_CALLBACK_H_INCLUDED

#include <sgec/input/keyboard/key_code.h>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>


SGEC_DETAIL_HEADER

typedef
void
(*sgec_input_keyboard_key_repeat_callback)(
	enum sgec_input_keyboard_key_code,
	void *userdata
);

SGEC_DETAIL_FOOTER

#endif
