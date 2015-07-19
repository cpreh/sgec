#ifndef SGEC_INPUT_MOUSE_BUTTON_CALLBACK_H_INCLUDED
#define SGEC_INPUT_MOUSE_BUTTON_CALLBACK_H_INCLUDED

#include <sgec/input/mouse/button_code.h>
#include <sgec/input/mouse/button_state.h>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>


SGEC_DETAIL_HEADER

typedef
void
(*sgec_input_mouse_button_callback)(
	enum sgec_input_mouse_button_code,
	enum sgec_input_mouse_button_state,
	void *userdata
);

SGEC_DETAIL_FOOTER

#endif
