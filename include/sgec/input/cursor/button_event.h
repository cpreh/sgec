#ifndef SGEC_INPUT_CURSOR_BUTTON_EVENT_H_INCLUDED
#define SGEC_INPUT_CURSOR_BUTTON_EVENT_H_INCLUDED

#include <sgec/input/cursor/button_code.h>
#include <sgec/input/cursor/button_event_fwd.h>
#include <sgec/input/cursor/button_state.h>
#include <sgec/input/cursor/id.h>
#include <sgec/input/cursor/position.h>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>


SGEC_DETAIL_HEADER

struct sgec_input_cursor_button_event
{
	sgec_input_cursor_id id;

	enum sgec_input_cursor_button_code code;

	enum sgec_input_cursor_button_state state;

	struct sgec_input_cursor_position pos;
};

SGEC_DETAIL_FOOTER

#endif
