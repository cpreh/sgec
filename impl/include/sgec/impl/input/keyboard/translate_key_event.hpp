#ifndef SGEC_IMPL_INPUT_KEYBOARD_TRANSLATE_KEY_EVENT_HPP_INCLUDED
#define SGEC_IMPL_INPUT_KEYBOARD_TRANSLATE_KEY_EVENT_HPP_INCLUDED

#include <sgec/input/keyboard/key_event.h>
#include <sge/input/keyboard/event/key_fwd.hpp>


namespace sgec
{
namespace impl
{
namespace input
{
namespace keyboard
{

sgec_input_keyboard_key_event
translate_key_event(
	sge::input::keyboard::event::key const &
);

}
}
}
}

#endif
