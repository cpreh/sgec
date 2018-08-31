#ifndef SGEC_WINDOW_EVENT_TYPE_H_INCLUDED
#define SGEC_WINDOW_EVENT_TYPE_H_INCLUDED

#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>


SGEC_DETAIL_HEADER

enum sgec_window_event_type
{
	sgec_window_event_type_cursor_button,
	sgec_window_event_type_cursor_move,
	sgec_window_event_type_cursor_scroll,
	sgec_window_event_type_focus_key,
	sgec_window_event_type_focus_key_repeat,
	sgec_window_event_type_focus_text,
	sgec_window_event_type_keyboard_key,
	sgec_window_event_type_mouse_axis,
	sgec_window_event_type_mouse_button,
	sgec_window_event_type_render
};

SGEC_DETAIL_FOOTER

#endif
