#ifndef SGEC_WINDOW_EVENT_H_INCLUDED
#define SGEC_WINDOW_EVENT_H_INCLUDED

#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>
#include <sgec/input/cursor/button_event.h>
#include <sgec/input/cursor/move_event.h>
#include <sgec/input/cursor/scroll_event.h>
#include <sgec/input/focus/char_event.h>
#include <sgec/input/focus/key_event.h>
#include <sgec/input/focus/key_repeat_event.h>
#include <sgec/input/keyboard/key_event.h>
#include <sgec/input/mouse/axis_event.h>
#include <sgec/input/mouse/button_event.h>
#include <sgec/renderer/render_event.h>
#include <sgec/window/event_fwd.h>
#include <sgec/window/event_type.h>


SGEC_DETAIL_HEADER

struct sgec_window_event
{
	enum sgec_window_event_type type;

	union
	{
		struct sgec_input_cursor_button_event cursor_button;

		struct sgec_input_cursor_move_event cursor_move;

		struct sgec_input_cursor_scroll_event cursor_scroll;

		struct sgec_input_focus_char_event focus_char;

		struct sgec_input_focus_key_event focus_key;

		struct sgec_input_focus_key_repeat_event focus_key_repeat;

		struct sgec_input_keyboard_key_event keyboard_key;

		struct sgec_input_mouse_axis_event mouse_axis;

		struct sgec_input_mouse_button_event mouse_button;

		struct sgec_renderer_render_event render;
	};
};

SGEC_DETAIL_FOOTER

#endif
