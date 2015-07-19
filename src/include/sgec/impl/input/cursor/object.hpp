#ifndef SGEC_IMPL_INPUT_CURSOR_OBJECT_HPP_INCLUDED
#define SGEC_IMPL_INPUT_CURSOR_OBJECT_HPP_INCLUDED

#include <sgec/input/cursor/button_callback.h>
#include <sgec/input/cursor/move_callback.h>
#include <sgec/input/cursor/object_fwd.h>
#include <sgec/signal/connection_fwd.h>
#include <sge/input/cursor/object_fwd.hpp>
#include <fcppt/noncopyable.hpp>


struct sgec_input_cursor_object
{
	FCPPT_NONCOPYABLE(
		sgec_input_cursor_object
	);
public:
	explicit
	sgec_input_cursor_object(
		sge::input::cursor::object &
	);

	~sgec_input_cursor_object();

	sgec_signal_connection *
	button_callback(
		sgec_input_cursor_button_callback,
		void *userdata
	);

	sgec_signal_connection *
	move_callback(
		sgec_input_cursor_move_callback,
		void *userdata
	);
private:
	sge::input::cursor::object &object_;
};

#endif
