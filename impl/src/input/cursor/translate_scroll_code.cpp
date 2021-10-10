#include <sgec/impl/input/cursor/translate_scroll_code.hpp>
#include <sgec/input/cursor/scroll_code.h>
#include <sge/input/cursor/scroll_code.hpp>
#include <fcppt/assert/unreachable.hpp>

sgec_input_cursor_scroll_code
sgec::impl::input::cursor::translate_scroll_code(sge::input::cursor::scroll_code const _code)
{
#define TRANSLATE_CASE(name) \
  case sge::input::cursor::scroll_code::name: \
    return sgec_input_cursor_scroll_code_##name

  switch (_code)
  {
    TRANSLATE_CASE(vertical);
    TRANSLATE_CASE(horizontal);
  }

  FCPPT_ASSERT_UNREACHABLE;
}
