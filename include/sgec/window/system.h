#ifndef SGEC_WINDOW_SYSTEM_H_INCLUDED
#define SGEC_WINDOW_SYSTEM_H_INCLUDED

#include <sgec/result.h>
#include <sgec/detail/symbol.h>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>
#include <sgec/window/event_fwd.h>
#include <sgec/window/event_result.h>
#include <sgec/window/system_fwd.h>


SGEC_DETAIL_HEADER

SGEC_DETAIL_SYMBOL
enum sgec_window_event_result
sgec_window_system_next_event(
	struct sgec_window_system *,
	struct sgec_window_event *
);

SGEC_DETAIL_SYMBOL
enum sgec_result
sgec_window_system_quit(
	struct sgec_window_system *,
	int exit_code
);

SGEC_DETAIL_SYMBOL
int
sgec_window_system_exit_code(
	struct sgec_window_system *
);

SGEC_DETAIL_FOOTER

#endif
