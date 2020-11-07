#ifndef SGEC_IMPL_INPUT_FOCUS_TRANSLATE_TEXT_EVENT_HPP_INCLUDED
#define SGEC_IMPL_INPUT_FOCUS_TRANSLATE_TEXT_EVENT_HPP_INCLUDED

#include <sgec/input/focus/text_event.h>
#include <sge/input/focus/event/text_fwd.hpp>


namespace sgec
{
namespace impl
{
namespace input
{
namespace focus
{

sgec_input_focus_text_event
translate_text_event(
	sge::input::focus::event::text const &
);

}
}
}
}

#endif
