#include <sgec/impl/input/mouse/device.hpp>
#include <sgec/impl/input/mouse/translate_axis_code.hpp>
#include <sgec/impl/input/mouse/translate_button_code.hpp>
#include <sgec/impl/signal/connection.hpp>
#include <sgec/input/mouse/axis_callback.h>
#include <sgec/input/mouse/button_callback.h>
#include <sgec/input/mouse/button_state.h>
#include <sge/input/mouse/axis_event.hpp>
#include <sge/input/mouse/button_event.hpp>
#include <sge/input/mouse/device.hpp>
#include <fcppt/signal/auto_connection.hpp>


sgec_input_mouse_device::sgec_input_mouse_device(
	sge::input::mouse::device &_device
)
:
	device_(
		_device
	)
{
}

sgec_input_mouse_device::~sgec_input_mouse_device()
{
}

sgec_signal_connection *
sgec_input_mouse_device::axis_callback(
	sgec_input_mouse_axis_callback const _callback,
	void *const _userdata
)
{
	return
		new
		sgec_signal_connection(
			device_.axis_callback(
				[
					_callback,
					_userdata
				](
					sge::input::mouse::axis_event const &_event
				)
				{
					_callback(
						sgec::impl::input::mouse::translate_axis_code(
							_event.code()
						),
						_event.value(),
						_userdata
					);
				}
			)
		);
}

sgec_signal_connection *
sgec_input_mouse_device::button_callback(
	sgec_input_mouse_button_callback const _callback,
	void *const _userdata
)
{
	return
		new
		sgec_signal_connection(
			device_.button_callback(
				[
					_callback,
					_userdata
				](
					sge::input::mouse::button_event const &_event
				)
				{
					_callback(
						sgec::impl::input::mouse::translate_button_code(
							_event.button_code()
						),
						_event.pressed()
						?
							sgec_input_mouse_button_state_pressed
						:
							sgec_input_mouse_button_state_released
						,
						_userdata
					);
				}
			)
		);
}
