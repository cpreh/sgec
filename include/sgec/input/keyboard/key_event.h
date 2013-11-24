#ifndef SGEC_INPUT_KEYBOARD_KEY_EVENT_H_INCLUDED
#define SGEC_INPUT_KEYBOARD_KEY_EVENT_H_INCLUDED

#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>
#include <sgec/input/keyboard/key_code.h>
#include <sgec/input/keyboard/key_event_fwd.h>
#include <sgec/input/keyboard/key_state.h>


SGEC_DETAIL_HEADER

struct sgec_input_keyboard_key_event
{
	enum sgec_input_keyboard_key_code code;

	enum sgec_input_keyboard_key_state state;
};

SGEC_DETAIL_FOOTER

#endif
