#ifndef SGEC_INPUT_MOUSE_AXIS_EVENT_H_INCLUDED
#define SGEC_INPUT_MOUSE_AXIS_EVENT_H_INCLUDED

#include <sgec/input/mouse/axis_code.h>
#include <sgec/input/mouse/axis_event_fwd.h>
#include <sgec/input/mouse/axis_value.h>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>


SGEC_DETAIL_HEADER

struct sgec_input_mouse_axis_event
{
	enum sgec_input_mouse_axis_code axis_code;

	sgec_input_mouse_axis_value axis_value;
};

SGEC_DETAIL_FOOTER

#endif
