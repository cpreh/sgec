#include <sgec/impl/input/focus/make_id.hpp>
#include <sgec/impl/input/focus/translate_key_event.hpp>
#include <sgec/impl/input/key/translate_code.hpp>
#include <sgec/impl/input/key/translate_state.hpp>
#include <sgec/input/focus/key_event.h>
#include <sge/input/focus/event/key.hpp>
#include <sge/input/key/pressed.hpp>

sgec_input_focus_key_event
sgec::impl::input::focus::translate_key_event(sge::input::focus::event::key const &_event)
{
  return sgec_input_focus_key_event{
      sgec::impl::input::focus::make_id(*_event.focus()),
      sgec::impl::input::key::translate_code(_event.get().code()),
      sgec::impl::input::key::translate_state(sge::input::key::pressed{_event.pressed()})};
}
