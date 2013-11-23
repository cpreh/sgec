#include <sgec/impl/window/system.hpp>
#include <sge/window/system.hpp>
#include <awl/main/exit_code.hpp>


sgec_window_system::sgec_window_system(
	sge::window::system &_system
)
:
	system_(
		_system
	)
{
}

sgec_window_system::~sgec_window_system()
{
}

bool
sgec_window_system::poll()
{
	return
		system_.poll();
}

void
sgec_window_system::quit(
	int const _exit_code
)
{
	system_.quit(
		awl::main::exit_code(
			_exit_code
		)
	);
}

int
sgec_window_system::exit_code() const
{
	return
		system_.exit_code().get();
}
