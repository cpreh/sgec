#ifndef SGEC_INPUT_MOUSE_BUTTON_EVENT_H_INCLUDED
#define SGEC_INPUT_MOUSE_BUTTON_EVENT_H_INCLUDED

#include <sgec/input/mouse/button_code.h>
#include <sgec/input/mouse/button_event_fwd.h>
#include <sgec/input/mouse/button_state.h>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>


SGEC_DETAIL_HEADER

struct sgec_input_mouse_button_event
{
	enum sgec_input_mouse_button_code button_code;

	enum sgec_input_mouse_button_state button_state;
};

SGEC_DETAIL_FOOTER

#endif
