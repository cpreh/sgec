#ifndef SGEC_INPUT_FOCUS_KEY_REPEAT_EVENT_H_INCLUDED
#define SGEC_INPUT_FOCUS_KEY_REPEAT_EVENT_H_INCLUDED

#include <sgec/input/focus/id.h>
#include <sgec/input/focus/key_repeat_event_fwd.h>
#include <sgec/input/key/code.h>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>


SGEC_DETAIL_HEADER

struct sgec_input_focus_key_repeat_event
{
	sgec_input_focus_id id;

	enum sgec_input_key_code key_code;
};

SGEC_DETAIL_FOOTER

#endif
