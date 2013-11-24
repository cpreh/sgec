#ifndef SGEC_WINDOW_SYSTEM_H_INCLUDED
#define SGEC_WINDOW_SYSTEM_H_INCLUDED

#include <sgec/result.h>
#include <sgec/symbol.hpp>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>
#include <sgec/window/system_fwd.h>
#include <sgec/window/system_poll_result.h>


SGEC_DETAIL_HEADER

SGEC_SYMBOL
enum sgec_window_system_poll_result
sgec_window_system_poll(
	struct sgec_window_system *
);

SGEC_SYMBOL
enum sgec_result
sgec_window_system_quit(
	struct sgec_window_system *,
	int exit_code
);

SGEC_SYMBOL
int
sgec_window_system_exit_code(
	struct sgec_window_system *
);

SGEC_DETAIL_FOOTER

#endif
