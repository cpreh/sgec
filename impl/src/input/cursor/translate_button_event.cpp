#include <sgec/impl/input/cursor/make_id.hpp>
#include <sgec/impl/input/cursor/translate_button_code.hpp>
#include <sgec/impl/input/cursor/translate_button_event.hpp>
#include <sgec/impl/input/cursor/translate_button_state.hpp>
#include <sgec/impl/input/cursor/translate_position.hpp>
#include <sgec/input/cursor/button_event.h>
#include <sge/input/cursor/button_pressed.hpp>
#include <sge/input/cursor/event/button.hpp>


sgec_input_cursor_button_event
sgec::impl::input::cursor::translate_button_event(
	sge::input::cursor::event::button const &_event
)
{
	return
		sgec_input_cursor_button_event{
			sgec::impl::input::cursor::make_id(
				*_event.cursor()
			),
			sgec::impl::input::cursor::translate_button_code(
				_event.button_code()
			),
			sgec::impl::input::cursor::translate_button_state(
				sge::input::cursor::button_pressed{
					_event.pressed()
				}
			),
			sgec::impl::input::cursor::translate_position(
				_event.position()
			)
		};
}
