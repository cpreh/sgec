#include <sgec/impl/input/cursor/make_id.hpp>
#include <sgec/impl/input/cursor/translate_move_event.hpp>
#include <sgec/impl/input/cursor/translate_position_opt.hpp>
#include <sgec/input/cursor/move_event.h>
#include <sge/input/cursor/event/move.hpp>


sgec_input_cursor_move_event
sgec::impl::input::cursor::translate_move_event(
	sge::input::cursor::event::move const &_event
)
{
	return
		sgec_input_cursor_move_event{
			sgec::impl::input::cursor::make_id(
				*_event.cursor()
			),
			sgec::impl::input::cursor::translate_position_opt(
				_event.position()
			)
		};
}
