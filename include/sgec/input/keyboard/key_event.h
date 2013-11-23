#ifndef SGEC_INPUT_KEYBOARD_KEY_EVENT_H_INCLUDED
#define SGEC_INPUT_KEYBOARD_KEY_EVENT_H_INCLUDED

#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>
#include <sgec/input/keyboard/key_code.h>
#include <sgec/input/keyboard/key_event_fwd.h>
#include <fcppt/config/external_begin.hpp>
#include <stdbool.h>
#include <fcppt/config/external_end.hpp>


SGEC_DETAIL_HEADER

struct sgec_input_keyboard_key_event
{
	enum sgec_input_keyboard_key_code code;

	bool pressed;
};

SGEC_DETAIL_FOOTER

#endif
