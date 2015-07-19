#ifndef SGEC_INPUT_CURSOR_OBJECT_H_INCLUDED
#define SGEC_INPUT_CURSOR_OBJECT_H_INCLUDED

#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>
#include <sgec/detail/symbol.h>
#include <sgec/input/cursor/button_callback.h>
#include <sgec/input/cursor/move_callback.h>
#include <sgec/input/cursor/object_fwd.h>


SGEC_DETAIL_HEADER

SGEC_DETAIL_SYMBOL
struct sgec_signal_connection *
sgec_input_cursor_object_connect_button_callback(
	struct sgec_input_cursor_object *,
	sgec_input_cursor_button_callback,
	void *userdata
);

SGEC_DETAIL_SYMBOL
struct sgec_signal_connection *
sgec_input_cursor_object_connect_move_callback(
	struct sgec_input_cursor_object *,
	sgec_input_cursor_move_callback,
	void *userdata
);

SGEC_DETAIL_FOOTER

#endif
