#ifndef SGEC_INPUT_CURSOR_SCROLL_CALLBACK_H_INCLUDED
#define SGEC_INPUT_CURSOR_SCROLL_CALLBACK_H_INCLUDED

#include <sgec/input/cursor/scroll_code.h>
#include <sgec/input/cursor/scroll_value.h>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>


SGEC_DETAIL_HEADER

typedef
void
(*sgec_input_cursor_scroll_callback)(
	enum sgec_input_cursor_scroll_code,
	sgec_input_cursor_scroll_value,
	void *userdata
);

SGEC_DETAIL_FOOTER

#endif
