#ifndef SGEC_IMPL_INPUT_MOUSE_DEVICE_HPP_INCLUDED
#define SGEC_IMPL_INPUT_MOUSE_DEVICE_HPP_INCLUDED

#include <sgec/input/mouse/axis_callback.h>
#include <sgec/input/mouse/button_callback.h>
#include <sgec/input/mouse/device_fwd.h>
#include <sgec/signal/connection_fwd.h>
#include <sge/input/mouse/device_fwd.hpp>
#include <fcppt/noncopyable.hpp>


struct sgec_input_mouse_device
{
	FCPPT_NONCOPYABLE(
		sgec_input_mouse_device
	);
public:
	explicit
	sgec_input_mouse_device(
		sge::input::mouse::device &
	);

	~sgec_input_mouse_device();

	sgec_signal_connection *
	axis_callback(
		sgec_input_mouse_axis_callback,
		void *userdata
	);

	sgec_signal_connection *
	button_callback(
		sgec_input_mouse_button_callback,
		void *userdata
	);
private:
	sge::input::mouse::device &device_;
};

#endif
