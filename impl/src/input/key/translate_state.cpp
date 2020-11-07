#include <sgec/impl/input/key/translate_state.hpp>
#include <sgec/input/key/state.h>
#include <sge/input/key/pressed.hpp>


sgec_input_key_state
sgec::impl::input::key::translate_state(
	sge::input::key::pressed const _pressed
)
{
	return
		_pressed.get()
		?
			sgec_input_key_state_pressed
		:
			sgec_input_key_state_released
		;
}
