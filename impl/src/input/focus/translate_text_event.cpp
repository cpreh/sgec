#include <sgec/impl/input/focus/make_id.hpp>
#include <sgec/impl/input/focus/translate_text_event.hpp>
#include <sgec/input/focus/text_event.h>
#include <sge/input/focus/event/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cwchar>
#include <fcppt/config/external_end.hpp>

sgec_input_focus_text_event
sgec::impl::input::focus::translate_text_event(sge::input::focus::event::text const &_event)
{
  wchar_t *const text{new wchar_t[_event.get().size() + 1U]};

  std::wcscpy(text, _event.get().c_str());

  return sgec_input_focus_text_event{
      .id = sgec::impl::input::focus::make_id(*_event.focus()), .text = text};
}
