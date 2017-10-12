#ifndef SGEC_INPUT_FOCUS_CHAR_EVENT_H_INCLUDED
#define SGEC_INPUT_FOCUS_CHAR_EVENT_H_INCLUDED

#include <sgec/input/focus/char_event_fwd.h>
#include <sgec/input/focus/id.h>
#include <sgec/input/key/code.h>
#include <sgec/input/key/state.h>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>
#include <fcppt/config/external_begin.h>
#include <wchar.h>
#include <fcppt/config/external_end.h>


SGEC_DETAIL_HEADER

struct sgec_input_focus_char_event
{
	sgec_input_focus_id id;

	wchar_t code;
};

SGEC_DETAIL_FOOTER

#endif
