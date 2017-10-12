#include <sgec/impl/input/mouse/translate_button_code.hpp>
#include <sgec/impl/input/mouse/translate_button_event.hpp>
#include <sgec/impl/input/mouse/translate_button_state.hpp>
#include <sgec/input/mouse/button_event.h>
#include <sge/input/mouse/button_pressed.hpp>
#include <sge/input/mouse/event/button.hpp>


sgec_input_mouse_button_event
sgec::impl::input::mouse::translate_button_event(
	sge::input::mouse::event::button const &_event
)
{
	return
		sgec_input_mouse_button_event{
			sgec::impl::input::mouse::translate_button_code(
				_event.button_code()
			),
			sgec::impl::input::mouse::translate_button_state(
				sge::input::mouse::button_pressed{
					_event.pressed()
				}
			)
		};
}
