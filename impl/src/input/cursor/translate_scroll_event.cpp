#include <sgec/impl/input/cursor/make_id.hpp>
#include <sgec/impl/input/cursor/translate_scroll_code.hpp>
#include <sgec/impl/input/cursor/translate_scroll_event.hpp>
#include <sgec/input/cursor/scroll_event.h>
#include <sge/input/cursor/event/scroll.hpp>

sgec_input_cursor_scroll_event
sgec::impl::input::cursor::translate_scroll_event(sge::input::cursor::event::scroll const &_event)
{
  return sgec_input_cursor_scroll_event{
      .id = sgec::impl::input::cursor::make_id(*_event.cursor()),
      .code = sgec::impl::input::cursor::translate_scroll_code(_event.code()),
      .value = _event.value()};
}
