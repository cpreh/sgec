#ifndef SGEC_INPUT_CURSOR_MOVE_CALLBACK_H_INCLUDED
#define SGEC_INPUT_CURSOR_MOVE_CALLBACK_H_INCLUDED

#include <sgec/input/cursor/position_unit.h>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>


SGEC_DETAIL_HEADER

typedef
void
(*sgec_input_cursor_move_callback)(
	sgec_input_cursor_position_unit pos_x,
	sgec_input_cursor_position_unit pos_y,
	void *userdata
);

SGEC_DETAIL_FOOTER

#endif
