#include <sgec/impl/input/mouse/translate_axis_code.hpp>
#include <sgec/input/mouse/axis_code.h>
#include <sge/input/mouse/axis_code.hpp>
#include <fcppt/enum/make_invalid.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>

sgec_input_mouse_axis_code
sgec::impl::input::mouse::translate_axis_code(sge::input::mouse::axis_code const _code)
{
#define TRANSLATE_CASE(name) \
  case sge::input::mouse::axis_code::name: \
    return sgec_input_mouse_axis_code_##name

  FCPPT_PP_PUSH_WARNING
  FCPPT_PP_DISABLE_GCC_WARNING(-Wswitch-default)
  switch (_code)
  {
    TRANSLATE_CASE(x);
    TRANSLATE_CASE(y);
    TRANSLATE_CASE(wheel);
    TRANSLATE_CASE(unknown);
  }
  FCPPT_PP_POP_WARNING

  throw fcppt::enum_::make_invalid(_code);
}
