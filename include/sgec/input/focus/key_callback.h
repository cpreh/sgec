#ifndef SGEC_INPUT_FOCUS_KEY_CALLBACK_H_INCLUDED
#define SGEC_INPUT_FOCUS_KEY_CALLBACK_H_INCLUDED

#include <sgec/input/key/code.h>
#include <sgec/input/key/state.h>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>


SGEC_DETAIL_HEADER

typedef
void
(*sgec_input_focus_key_callback)(
	enum sgec_input_key_code,
	enum sgec_input_key_state,
	void *userdata
);

SGEC_DETAIL_FOOTER

#endif
