#ifndef SGEC_IMPL_INPUT_CURSOR_TRANSLATE_MOVE_EVENT_HPP_INCLUDED
#define SGEC_IMPL_INPUT_CURSOR_TRANSLATE_MOVE_EVENT_HPP_INCLUDED

#include <sgec/input/cursor/move_event.h>
#include <sge/input/cursor/event/move_fwd.hpp>

namespace sgec::impl::input::cursor
{

sgec_input_cursor_move_event translate_move_event(sge::input::cursor::event::move const &);

}

#endif
