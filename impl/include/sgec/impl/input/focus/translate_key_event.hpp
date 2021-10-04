#ifndef SGEC_IMPL_INPUT_FOCUS_TRANSLATE_KEY_EVENT_HPP_INCLUDED
#define SGEC_IMPL_INPUT_FOCUS_TRANSLATE_KEY_EVENT_HPP_INCLUDED

#include <sgec/input/focus/key_event.h>
#include <sge/input/focus/event/key_fwd.hpp>


namespace sgec::impl::input::focus
{

sgec_input_focus_key_event
translate_key_event(
	sge::input::focus::event::key const &
);

}

#endif
