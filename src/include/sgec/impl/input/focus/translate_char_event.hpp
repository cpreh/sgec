#ifndef SGEC_IMPL_INPUT_FOCUS_TRANSLATE_CHAR_EVENT_HPP_INCLUDED
#define SGEC_IMPL_INPUT_FOCUS_TRANSLATE_CHAR_EVENT_HPP_INCLUDED

#include <sgec/input/focus/char_event.h>
#include <sge/input/focus/event/char_fwd.hpp>


namespace sgec
{
namespace impl
{
namespace input
{
namespace focus
{

sgec_input_focus_char_event
translate_char_event(
	sge::input::focus::event::char_ const &
);

}
}
}
}

#endif
