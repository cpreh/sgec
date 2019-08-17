#include <sgec/impl/input/key/translate_code.hpp>
#include <sgec/impl/input/key/translate_state.hpp>
#include <sgec/impl/input/keyboard/translate_key_event.hpp>
#include <sgec/input/keyboard/key_event.h>
#include <sge/input/key/pressed.hpp>
#include <sge/input/keyboard/event/key.hpp>


sgec_input_keyboard_key_event
sgec::impl::input::keyboard::translate_key_event(
	sge::input::keyboard::event::key const &_event
)
{
	return
		sgec_input_keyboard_key_event{
			sgec::impl::input::key::translate_code(
				_event.get().code()
			),
			sgec::impl::input::key::translate_state(
				sge::input::key::pressed{
					_event.pressed()
				}
			),
			_event.get().id().get()
		};
}
