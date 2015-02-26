#ifndef SGEC_IMPL_INPUT_KEYBOARD_DEVICE_HPP_INCLUDED
#define SGEC_IMPL_INPUT_KEYBOARD_DEVICE_HPP_INCLUDED

#include <sgec/input/keyboard/device_fwd.h>
#include <sgec/input/keyboard/key_callback.h>
#include <sgec/input/keyboard/key_repeat_callback.h>
#include <sgec/signal/connection_fwd.h>
#include <sge/input/keyboard/device_fwd.hpp>
#include <fcppt/noncopyable.hpp>


struct sgec_input_keyboard_device
{
	FCPPT_NONCOPYABLE(
		sgec_input_keyboard_device
	);
public:
	explicit
	sgec_input_keyboard_device(
		sge::input::keyboard::device &
	);

	~sgec_input_keyboard_device();

	sgec_signal_connection *
	key_callback(
		sgec_input_keyboard_key_callback,
		void *userdata
	);

	sgec_signal_connection *
	key_repeat_callback(
		sgec_input_keyboard_key_repeat_callback,
		void *userdata
	);
private:
	sge::input::keyboard::device &device_;
};

#endif
