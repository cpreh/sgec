#include <sgec/impl/input/key/translate_code.hpp>
#include <sgec/impl/input/keyboard/device.hpp>
#include <sgec/impl/signal/connection.hpp>
#include <sgec/input/key/state.h>
#include <sgec/input/keyboard/key_callback.h>
#include <sge/input/keyboard/device.hpp>
#include <sge/input/keyboard/key_callback.hpp>
#include <sge/input/keyboard/key_event.hpp>
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
				sge::input::keyboard::key_callback{
					[
						_callback,
						_userdata
					](
						sge::input::keyboard::key_event const &_event
					)
					{
						_callback(
							sgec::impl::input::key::translate_code(
								_event.key().code()
							),
							_event.pressed()
							?
								sgec_input_key_state_pressed
							:
								sgec_input_key_state_released
							,
							_userdata
						);
					}
				}
			)
		);
}
