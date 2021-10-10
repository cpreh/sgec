#include <sgec/impl/input/mouse/translate_button_state.hpp>
#include <sgec/input/mouse/button_state.h>
#include <sge/input/mouse/button_pressed.hpp>

sgec_input_mouse_button_state
sgec::impl::input::mouse::translate_button_state(sge::input::mouse::button_pressed const _pressed)
{
  return _pressed.get() ? sgec_input_mouse_button_state_pressed
                        : sgec_input_mouse_button_state_released;
}
