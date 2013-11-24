#include <sgec/result.h>
#include <sgec/impl/window/system.hpp>
#include <sgec/window/system.h>
#include <sgec/window/system_poll_result.h>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <fcppt/config/external_end.hpp>


extern "C"
sgec_window_system_poll_result
sgec_window_system_poll(
	struct sgec_window_system *const _system
)
try
{
	return
		_system->poll()
		?
			sgec_window_system_poll_result_running
		:
			sgec_window_system_poll_result_finished
		;
}
catch(
	...
)
{
	return
		sgec_window_system_poll_result_error;
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
