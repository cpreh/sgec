#ifndef SGEC_INPUT_CURSOR_POSITION_OPT_H_INCLUDED
#define SGEC_INPUT_CURSOR_POSITION_OPT_H_INCLUDED

#include <sgec/input/cursor/position.h>
#include <sgec/input/cursor/position_opt_fwd.h>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>
#include <fcppt/config/external_begin.h>
#include <stdbool.h>
#include <fcppt/config/external_end.h>


SGEC_DETAIL_HEADER

struct sgec_input_cursor_position_opt
{
	struct sgec_input_cursor_position pos;

	bool valid;
};

SGEC_DETAIL_FOOTER

#endif
