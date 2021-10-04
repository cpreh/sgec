#ifndef SGEC_IMPL_INPUT_CURSOR_MAKE_ID_HPP_INCLUDED
#define SGEC_IMPL_INPUT_CURSOR_MAKE_ID_HPP_INCLUDED

#include <sgec/input/cursor/id.h>
#include <sge/input/cursor/object_fwd.hpp>


namespace sgec::impl::input::cursor
{

sgec_input_cursor_id
make_id(
	sge::input::cursor::object const &
);

}

#endif
