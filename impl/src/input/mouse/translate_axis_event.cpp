#include <sgec/impl/input/mouse/translate_axis_code.hpp>
#include <sgec/impl/input/mouse/translate_axis_event.hpp>
#include <sgec/input/mouse/axis_event.h>
#include <sge/input/mouse/event/axis.hpp>

sgec_input_mouse_axis_event
sgec::impl::input::mouse::translate_axis_event(sge::input::mouse::event::axis const &_event)
{
  return sgec_input_mouse_axis_event{
      .axis_code = sgec::impl::input::mouse::translate_axis_code(_event.code()),
      .axis_value = _event.value()};
}
