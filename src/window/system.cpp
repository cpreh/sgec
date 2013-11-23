#include <sgec/impl/window/system.hpp>
#include <sgec/window/system.h>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <fcppt/config/external_end.hpp>


extern "C"
bool
sgec_window_system_poll(
	struct sgec_window_system *const _system
)
try
{
	return
		_system->poll();
}
catch(
	...
)
{
	// TODO: Error code!
	return
		false;
}

extern "C"
bool
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
		true;
}
catch(
	...
)
{
	return
		false;
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
