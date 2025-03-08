#include <sgec/impl/input/focus/make_id.hpp>
#include <sgec/impl/input/focus/translate_text_event.hpp>
#include <sgec/input/focus/text_event.h>
#include <sge/input/focus/event/text.hpp>
#include <fcppt/preprocessor/ignore_unsafe_buffer_usage_in_libc_call.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cwchar>
#include <fcppt/config/external_end.hpp>

sgec_input_focus_text_event
sgec::impl::input::focus::translate_text_event(sge::input::focus::event::text const &_event)
{
  wchar_t *const text{new wchar_t[_event.get().size() + 1U]};

FCPPT_PP_PUSH_WARNING
FCPPT_PP_IGNORE_UNSAFE_BUFFER_USAGE_IN_LIBC_CALL
  std::wcscpy(text, _event.get().c_str());
FCPPT_PP_POP_WARNING

  return sgec_input_focus_text_event{
      .id = sgec::impl::input::focus::make_id(*_event.focus()), .text = text};
}
