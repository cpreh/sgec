#ifndef SGEC_INPUT_CURSOR_SCROLL_EVENT_H_INCLUDED
#define SGEC_INPUT_CURSOR_SCROLL_EVENT_H_INCLUDED

#include <sgec/input/cursor/id.h>
#include <sgec/input/cursor/scroll_code.h>
#include <sgec/input/cursor/scroll_event_fwd.h>
#include <sgec/input/cursor/scroll_value.h>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>


SGEC_DETAIL_HEADER

struct sgec_input_cursor_scroll_event
{
	sgec_input_cursor_id id;

	enum sgec_input_cursor_scroll_code code;

	sgec_input_cursor_scroll_value value;
};

SGEC_DETAIL_FOOTER

#endif
