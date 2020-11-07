#include <sgec/impl/input/focus/make_id.hpp>
#include <sgec/impl/input/focus/translate_key_repeat_event.hpp>
#include <sgec/impl/input/key/translate_code.hpp>
#include <sgec/input/focus/key_repeat_event.h>
#include <sge/input/focus/event/key_repeat.hpp>


sgec_input_focus_key_repeat_event
sgec::impl::input::focus::translate_key_repeat_event(
	sge::input::focus::event::key_repeat const &_event
)
{
	return
		sgec_input_focus_key_repeat_event{
			sgec::impl::input::focus::make_id(
				*_event.focus()
			),
			sgec::impl::input::key::translate_code(
				_event.key().code()
			)
		};
}
