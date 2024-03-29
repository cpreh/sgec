#include <sgec/impl/input/cursor/translate_button_code.hpp>
#include <sgec/input/cursor/button_code.h>
#include <sge/input/cursor/button_code.hpp>
#include <fcppt/enum/make_invalid.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>

sgec_input_cursor_button_code
sgec::impl::input::cursor::translate_button_code(sge::input::cursor::button_code const _code)
{
#define TRANSLATE_CASE(name) \
  case sge::input::cursor::button_code::name: \
    return sgec_input_cursor_button_code_##name

  FCPPT_PP_PUSH_WARNING
  FCPPT_PP_DISABLE_GCC_WARNING(-Wswitch-default)
  switch (_code)
  {
    TRANSLATE_CASE(left);
    TRANSLATE_CASE(middle);
    TRANSLATE_CASE(right);
    TRANSLATE_CASE(unknown);
  }
  FCPPT_PP_POP_WARNING

  throw fcppt::enum_::make_invalid(_code);
}
