#ifndef SGEC_IMPL_INPUT_FOCUS_OBJECT_HPP_INCLUDED
#define SGEC_IMPL_INPUT_FOCUS_OBJECT_HPP_INCLUDED

#include <sgec/input/focus/key_callback.h>
#include <sgec/input/focus/key_repeat_callback.h>
#include <sgec/input/focus/object_fwd.h>
#include <sgec/signal/connection_fwd.h>
#include <sge/input/focus/object_fwd.hpp>
#include <fcppt/noncopyable.hpp>


struct sgec_input_focus_object
{
	FCPPT_NONCOPYABLE(
		sgec_input_focus_object
	);
public:
	explicit
	sgec_input_focus_object(
		sge::input::focus::object &
	);

	~sgec_input_focus_object();

	sgec_signal_connection *
	key_callback(
		sgec_input_focus_key_callback,
		void *userdata
	);

	sgec_signal_connection *
	key_repeat_callback(
		sgec_input_focus_key_repeat_callback,
		void *userdata
	);
private:
	sge::input::focus::object &object_;
};

#endif
