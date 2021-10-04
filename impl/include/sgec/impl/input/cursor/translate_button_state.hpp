#ifndef SGEC_IMPL_INPUT_CURSOR_TRANSLATE_BUTTON_STATE_HPP_INCLUDED
#define SGEC_IMPL_INPUT_CURSOR_TRANSLATE_BUTTON_STATE_HPP_INCLUDED

#include <sgec/input/cursor/button_state.h>
#include <sge/input/cursor/button_pressed.hpp>


namespace sgec::impl::input::cursor
{

sgec_input_cursor_button_state
translate_button_state(
	sge::input::cursor::button_pressed
);

}

#endif
