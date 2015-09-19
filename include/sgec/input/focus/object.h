#ifndef SGEC_INPUT_FOCUS_OBJECT_H_INCLUDED
#define SGEC_INPUT_FOCUS_OBJECT_H_INCLUDED

#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>
#include <sgec/detail/symbol.h>
#include <sgec/input/focus/object_fwd.h>
#include <sgec/input/focus/key_callback.h>
#include <sgec/input/focus/key_repeat_callback.h>


SGEC_DETAIL_HEADER

SGEC_DETAIL_SYMBOL
struct sgec_signal_connection *
sgec_input_focus_object_connect_key_callback(
	struct sgec_input_focus_object *,
	sgec_input_focus_key_callback,
	void *userdata
);

SGEC_DETAIL_SYMBOL
struct sgec_signal_connection *
sgec_input_focus_object_connect_key_repeat_callback(
	struct sgec_input_focus_object *,
	sgec_input_focus_key_repeat_callback,
	void *userdata
);

SGEC_DETAIL_FOOTER

#endif
