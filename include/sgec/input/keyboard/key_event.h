#ifndef SGEC_INPUT_KEYBOARD_KEY_EVENT_H_INCLUDED
#define SGEC_INPUT_KEYBOARD_KEY_EVENT_H_INCLUDED

#include <sgec/input/key/code.h>
#include <sgec/input/key/state.h>
#include <sgec/input/keyboard/key_event_fwd.h>
#include <sgec/input/keyboard/key_id.h>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>


SGEC_DETAIL_HEADER

struct sgec_input_keyboard_key_event
{
	enum sgec_input_key_code key_code;

	enum sgec_input_key_state key_state;

	sgec_input_keyboard_key_id key_id;
};

SGEC_DETAIL_FOOTER

#endif
