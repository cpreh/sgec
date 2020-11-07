#ifndef SGEC_IMPL_INPUT_CURSOR_TRANSLATE_SCROLL_EVENT_HPP_INCLUDED
#define SGEC_IMPL_INPUT_CURSOR_TRANSLATE_SCROLL_EVENT_HPP_INCLUDED

#include <sgec/input/cursor/scroll_event.h>
#include <sge/input/cursor/event/scroll_fwd.hpp>


namespace sgec
{
namespace impl
{
namespace input
{
namespace cursor
{

sgec_input_cursor_scroll_event
translate_scroll_event(
	sge::input::cursor::event::scroll const &
);

}
}
}
}

#endif
