#ifndef SGEC_IMPL_INPUT_MOUSE_TRANSLATE_AXIS_EVENT_HPP_INCLUDED
#define SGEC_IMPL_INPUT_MOUSE_TRANSLATE_AXIS_EVENT_HPP_INCLUDED

#include <sgec/input/mouse/axis_event.h>
#include <sge/input/mouse/event/axis_fwd.hpp>


namespace sgec::impl::input::mouse
{

sgec_input_mouse_axis_event
translate_axis_event(
	sge::input::mouse::event::axis const &
);

}

#endif
