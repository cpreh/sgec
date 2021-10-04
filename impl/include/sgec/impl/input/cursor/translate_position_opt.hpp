#ifndef SGEC_IMPL_INPUT_CURSOR_TRANSLATE_POSITION_OPT_HPP_INCLUDED
#define SGEC_IMPL_INPUT_CURSOR_TRANSLATE_POSITION_OPT_HPP_INCLUDED

#include <sgec/input/cursor/position_opt.h>
#include <sge/input/cursor/optional_position_fwd.hpp>


namespace sgec::impl::input::cursor
{

sgec_input_cursor_position_opt
translate_position_opt(
	sge::input::cursor::optional_position const &
);

}

#endif
