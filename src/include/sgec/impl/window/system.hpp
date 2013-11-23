#ifndef SGEC_IMPL_WINDOW_SYSTEM_HPP_INCLUDED
#define SGEC_IMPL_WINDOW_SYSTEM_HPP_INCLUDED

#include <sgec/window/system_fwd.h>
#include <sge/window/system_fwd.hpp>
#include <fcppt/noncopyable.hpp>


struct sgec_window_system
{
	FCPPT_NONCOPYABLE(
		sgec_window_system
	);
public:
	explicit
	sgec_window_system(
		sge::window::system &
	);

	~sgec_window_system();

	bool
	poll();

	void
	quit(
		int exit_code
	);

	int
	exit_code() const;
private:
	sge::window::system &system_;
};

#endif
