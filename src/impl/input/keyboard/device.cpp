#include <sgec/impl/input/keyboard/device.hpp>
#include <sgec/impl/input/keyboard/translate_key_code.hpp>
#include <sgec/impl/signal/connection.hpp>
#include <sgec/input/keyboard/key_callback.h>
#include <sgec/input/keyboard/key_repeat_callback.h>
#include <sgec/input/keyboard/key_state.h>
#include <sge/input/keyboard/device.hpp>
#include <sge/input/keyboard/key_event.hpp>
#include <sge/input/keyboard/key_repeat_event.hpp>
#include <fcppt/signal/auto_connection.hpp>


sgec_input_keyboard_device::sgec_input_keyboard_device(
	sge::input::keyboard::device &_device
)
:
	device_(
		_device
	)
{
}

sgec_input_keyboard_device::~sgec_input_keyboard_device()
{
}

sgec_signal_connection *
sgec_input_keyboard_device::key_callback(
	sgec_input_keyboard_key_callback const _callback,
	void *const _userdata
)
{
	return
		new
		sgec_signal_connection(
			device_.key_callback(
				[
					_callback,
					_userdata
				](
					sge::input::keyboard::key_event const &_event
				)
				{
					_callback(
						sgec::impl::input::keyboard::translate_key_code(
							_event.key_code()
						),
						_event.pressed()
						?
							sgec_input_keyboard_key_state_pressed
						:
							sgec_input_keyboard_key_state_released
						,
						_userdata
					);
				}
			)
		);
}

sgec_signal_connection *
sgec_input_keyboard_device::key_repeat_callback(
	sgec_input_keyboard_key_repeat_callback const _callback,
	void *const _userdata
)
{
	return
		new
		sgec_signal_connection(
			device_.key_repeat_callback(
				[
					_callback,
					_userdata
				](
					sge::input::keyboard::key_repeat_event const &_event
				)
				{
					_callback(
						sgec::impl::input::keyboard::translate_key_code(
							_event.key_code()
						),
						_userdata
					);
				}
			)
		);
}
