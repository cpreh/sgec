#ifndef SGEC_IMPL_INPUT_MOUSE_TRANSLATE_BUTTON_EVENT_HPP_INCLUDED
#define SGEC_IMPL_INPUT_MOUSE_TRANSLATE_BUTTON_EVENT_HPP_INCLUDED

#include <sgec/input/mouse/button_event.h>
#include <sge/input/mouse/event/button_fwd.hpp>

namespace sgec::impl::input::mouse
{

sgec_input_mouse_button_event translate_button_event(sge::input::mouse::event::button const &);

}

#endif
