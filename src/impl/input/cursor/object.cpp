#include <sgec/impl/input/cursor/object.hpp>
#include <sgec/impl/input/cursor/translate_button_code.hpp>
#include <sgec/impl/signal/connection.hpp>
#include <sgec/input/cursor/button_callback.h>
#include <sgec/input/cursor/button_state.h>
#include <sge/input/cursor/button_event.hpp>
#include <sge/input/cursor/object.hpp>
#include <fcppt/signal/auto_connection.hpp>


sgec_input_cursor_object::sgec_input_cursor_object(
	sge::input::cursor::object &_object
)
:
	object_(
		_object
	)
{
}

sgec_input_cursor_object::~sgec_input_cursor_object()
{
}

sgec_signal_connection *
sgec_input_cursor_object::button_callback(
	sgec_input_cursor_button_callback const _callback,
	void *const _userdata
)
{
	return
		new
		sgec_signal_connection(
			object_.button_callback(
				[
					_callback,
					_userdata
				](
					sge::input::cursor::button_event const &_event
				)
				{
					_callback(
						sgec::impl::input::cursor::translate_button_code(
							_event.button_code()
						),
						_event.pressed()
						?
							sgec_input_cursor_button_state_pressed
						:
							sgec_input_cursor_button_state_released
						,
						_event.position().x(),
						_event.position().y(),
						_userdata
					);
				}
			)
		);
}
