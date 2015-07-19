#ifndef SGEC_INPUT_MOUSE_AXIS_CALLBACK_H_INCLUDED
#define SGEC_INPUT_MOUSE_AXIS_CALLBACK_H_INCLUDED

#include <sgec/input/mouse/axis_code.h>
#include <sgec/input/mouse/axis_value.h>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>


SGEC_DETAIL_HEADER

typedef
void
(*sgec_input_mouse_axis_callback)(
	enum sgec_input_mouse_axis_code,
	sgec_input_mouse_axis_value,
	void *userdata
);

SGEC_DETAIL_FOOTER

#endif
