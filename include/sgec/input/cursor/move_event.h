#ifndef SGEC_INPUT_CURSOR_MOVE_EVENT_H_INCLUDED
#define SGEC_INPUT_CURSOR_MOVE_EVENT_H_INCLUDED

#include <sgec/input/cursor/id.h>
#include <sgec/input/cursor/move_event_fwd.h>
#include <sgec/input/cursor/position_opt.h>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>


SGEC_DETAIL_HEADER

struct sgec_input_cursor_move_event
{
	sgec_input_cursor_id id;

	struct sgec_input_cursor_position_opt pos;
};

SGEC_DETAIL_FOOTER

#endif
