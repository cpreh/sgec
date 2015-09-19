#include <sgec/impl/input/focus/object.hpp>
#include <sgec/impl/input/key/translate_code.hpp>
#include <sgec/impl/signal/connection.hpp>
#include <sgec/input/focus/key_callback.h>
#include <sgec/input/focus/key_repeat_callback.h>
#include <sgec/input/key/state.h>
#include <sge/input/focus/key_callback.hpp>
#include <sge/input/focus/key_event.hpp>
#include <sge/input/focus/key_repeat_callback.hpp>
#include <sge/input/focus/key_repeat_event.hpp>
#include <sge/input/focus/object.hpp>
#include <fcppt/signal/auto_connection.hpp>


sgec_input_focus_object::sgec_input_focus_object(
	sge::input::focus::object &_object
)
:
	object_(
		_object
	)
{
}

sgec_input_focus_object::~sgec_input_focus_object()
{
}

sgec_signal_connection *
sgec_input_focus_object::key_callback(
	sgec_input_focus_key_callback const _callback,
	void *const _userdata
)
{
	return
		new
		sgec_signal_connection(
			object_.key_callback(
				sge::input::focus::key_callback{
					[
						_callback,
						_userdata
					](
						sge::input::focus::key_event const &_event
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

sgec_signal_connection *
sgec_input_focus_object::key_repeat_callback(
	sgec_input_focus_key_repeat_callback const _callback,
	void *const _userdata
)
{
	return
		new
		sgec_signal_connection(
			object_.key_repeat_callback(
				sge::input::focus::key_repeat_callback{
					[
						_callback,
						_userdata
					](
						sge::input::focus::key_repeat_event const &_event
					)
					{
						_callback(
							sgec::impl::input::key::translate_code(
								_event.key().code()
							),
							_userdata
						);
					}
				}
			)
		);
}
