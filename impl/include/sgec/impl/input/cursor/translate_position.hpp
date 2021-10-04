#ifndef SGEC_IMPL_INPUT_CURSOR_TRANSLATE_POSITION_HPP_INCLUDED
#define SGEC_IMPL_INPUT_CURSOR_TRANSLATE_POSITION_HPP_INCLUDED

#include <sgec/input/cursor/position.h>
#include <sge/input/cursor/position_fwd.hpp>


namespace sgec::impl::input::cursor
{

sgec_input_cursor_position
translate_position(
	sge::input::cursor::position const &
);

}

#endif
