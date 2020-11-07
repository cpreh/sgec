#ifndef SGEC_IMPL_INPUT_CURSOR_TRANSLATE_BUTTON_EVENT_HPP_INCLUDED
#define SGEC_IMPL_INPUT_CURSOR_TRANSLATE_BUTTON_EVENT_HPP_INCLUDED

#include <sgec/input/cursor/button_event.h>
#include <sge/input/cursor/event/button_fwd.hpp>


namespace sgec
{
namespace impl
{
namespace input
{
namespace cursor
{

sgec_input_cursor_button_event
translate_button_event(
	sge::input::cursor::event::button const &
);

}
}
}
}

#endif
