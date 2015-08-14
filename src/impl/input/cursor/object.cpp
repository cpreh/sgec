#include <sgec/impl/input/cursor/object.hpp>
#include <sgec/impl/input/cursor/translate_button_code.hpp>
#include <sgec/impl/input/cursor/translate_scroll_code.hpp>
#include <sgec/impl/signal/connection.hpp>
#include <sgec/input/cursor/button_callback.h>
#include <sgec/input/cursor/button_state.h>
#include <sgec/input/cursor/move_callback.h>
#include <sgec/input/cursor/scroll_callback.h>
#include <sge/input/cursor/button_callback.hpp>
#include <sge/input/cursor/button_event.hpp>
#include <sge/input/cursor/move_callback.hpp>
#include <sge/input/cursor/move_event.hpp>
#include <sge/input/cursor/object.hpp>
#include <sge/input/cursor/position.hpp>
#include <sge/input/cursor/scroll_callback.hpp>
#include <sge/input/cursor/scroll_event.hpp>
#include <fcppt/maybe_void.hpp>
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
				sge::input::cursor::button_callback{
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
				}
			)
		);
}

sgec_signal_connection *
sgec_input_cursor_object::move_callback(
	sgec_input_cursor_move_callback const _callback,
	void *const _userdata
)
{
	return
		new
		sgec_signal_connection(
			object_.move_callback(
				sge::input::cursor::move_callback{
					[
						_callback,
						_userdata
					](
						sge::input::cursor::move_event const &_event
					)
					{
						// TODO: Should we create a cursor_leave_event?
						fcppt::maybe_void(
							_event.position(),
							[
								_callback,
								_userdata
							](
								sge::input::cursor::position const _position
							)
							{
								_callback(
									_position.x(),
									_position.y(),
									_userdata
								);
							}
						);
					}
				}
			)
		);
}

sgec_signal_connection *
sgec_input_cursor_object::scroll_callback(
	sgec_input_cursor_scroll_callback const _callback,
	void *const _userdata
)
{
	return
		new
		sgec_signal_connection(
			object_.scroll_callback(
				sge::input::cursor::scroll_callback{
					[
						_callback,
						_userdata
					](
						sge::input::cursor::scroll_event const &_event
					)
					{
						_callback(
							sgec::impl::input::cursor::translate_scroll_code(
								_event.code()
							),
							_event.value(),
							_userdata
						);
					}
				}
			)
		);
}
