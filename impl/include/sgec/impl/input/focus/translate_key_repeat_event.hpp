#ifndef SGEC_IMPL_INPUT_FOCUS_TRANSLATE_KEY_REPEAT_EVENT_HPP_INCLUDED
#define SGEC_IMPL_INPUT_FOCUS_TRANSLATE_KEY_REPEAT_EVENT_HPP_INCLUDED

#include <sgec/input/focus/key_repeat_event.h>
#include <sge/input/focus/event/key_repeat_fwd.hpp>


namespace sgec
{
namespace impl
{
namespace input
{
namespace focus
{

sgec_input_focus_key_repeat_event
translate_key_repeat_event(
	sge::input::focus::event::key_repeat const &
);

}
}
}
}

#endif
