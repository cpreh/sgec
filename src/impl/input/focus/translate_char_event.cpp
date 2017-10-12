#include <sgec/impl/input/focus/make_id.hpp>
#include <sgec/impl/input/focus/translate_char_event.hpp>
#include <sgec/input/focus/char_event.h>
#include <sge/input/focus/event/char.hpp>


sgec_input_focus_char_event
sgec::impl::input::focus::translate_char_event(
	sge::input::focus::event::char_ const &_event
)
{
	return
		sgec_input_focus_char_event{
			sgec::impl::input::focus::make_id(
				*_event.focus()
			),
			_event.character()
		};
}
