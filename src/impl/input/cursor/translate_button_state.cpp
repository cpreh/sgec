#include <sgec/impl/input/cursor/translate_button_state.hpp>
#include <sgec/input/cursor/button_state.h>
#include <sge/input/cursor/button_pressed.hpp>


sgec_input_cursor_button_state
sgec::impl::input::cursor::translate_button_state(
	sge::input::cursor::button_pressed const _pressed
)
{
	return
		_pressed.get()
		?
			sgec_input_cursor_button_state_pressed
		:
			sgec_input_cursor_button_state_released
		;
}
