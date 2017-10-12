#include <sgec/result.h>
#include <sgec/impl/window/system.hpp>
#include <sgec/window/event_fwd.h>
#include <sgec/window/event_result.h>
#include <sgec/window/system.h>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <fcppt/config/external_end.hpp>


extern "C"
enum sgec_window_event_result
sgec_window_system_next_event(
	struct sgec_window_system *const _system,
	struct sgec_window_event *const _result
)
try
{
	return
		_system->next_event(
			*_result
		)
		?
			sgec_window_event_result_running
		:
			sgec_window_event_result_finished
		;
}
catch(
	...
)
{
	return
		sgec_window_event_result_error;
}

extern "C"
sgec_result
sgec_window_system_quit(
	struct sgec_window_system *const _system,
	int const _exit_code
)
try
{
	_system->quit(
		_exit_code
	);

	return
		sgec_result_ok;
}
catch(
	...
)
{
	return
		sgec_result_error;
}

extern "C"
int
sgec_window_system_exit_code(
	struct sgec_window_system *const _system
)
try
{
	return
		_system->exit_code();
}
catch(
	...
)
{
	return
		EXIT_FAILURE;
}
