#ifndef SGEC_INPUT_KEYBOARD_KEY_CALLBACK_H_INCLUDED
#define SGEC_INPUT_KEYBOARD_KEY_CALLBACK_H_INCLUDED

#include <sgec/input/keyboard/key_event_fwd.h>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>


SGEC_DETAIL_HEADER

typedef
void
(*sgec_input_keyboard_key_callback)(
	struct sgec_input_keyboard_key_event const *,
	void *userdata
);

SGEC_DETAIL_FOOTER

#endif
