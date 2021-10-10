#ifndef SGEC_IMPL_INPUT_MOUSE_TRANSLATE_BUTTON_STATE_HPP_INCLUDED
#define SGEC_IMPL_INPUT_MOUSE_TRANSLATE_BUTTON_STATE_HPP_INCLUDED

#include <sgec/input/mouse/button_state.h>
#include <sge/input/mouse/button_pressed.hpp>

namespace sgec::impl::input::mouse
{

sgec_input_mouse_button_state translate_button_state(sge::input::mouse::button_pressed);

}

#endif
