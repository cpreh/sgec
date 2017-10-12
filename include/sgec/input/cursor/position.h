#ifndef SGEC_INPUT_CURSOR_POSITION_H_INCLUDED
#define SGEC_INPUT_CURSOR_POSITION_H_INCLUDED

#include <sgec/input/cursor/position_fwd.h>
#include <sgec/input/cursor/position_unit.h>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>


SGEC_DETAIL_HEADER

struct sgec_input_cursor_position
{
	sgec_input_cursor_position_unit pos_x;

	sgec_input_cursor_position_unit pos_y;
};

SGEC_DETAIL_FOOTER

#endif
