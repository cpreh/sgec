#ifndef SGEC_IMPL_WINDOW_SYSTEM_HPP_INCLUDED
#define SGEC_IMPL_WINDOW_SYSTEM_HPP_INCLUDED

#include <sgec/window/event_fwd.h>
#include <sgec/window/system_fwd.h>
#include <sge/window/system_fwd.hpp>
#include <awl/event/base_unique_ptr.hpp>
#include <awl/main/optional_exit_code.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <deque>
#include <fcppt/config/external_end.hpp>


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
	next_event(
		sgec_window_event &
	);

	void
	quit(
		int exit_code
	);

	int
	exit_code() const;
private:
	sge::window::system &system_;

	typedef
	std::deque<
		awl::event::base_unique_ptr
	>
	event_queue;

	event_queue event_queue_;

	awl::main::optional_exit_code exit_code_;
};

#endif
