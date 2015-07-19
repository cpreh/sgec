#include <sgec/input/mouse/button_code.h>
#include <sgec/impl/input/mouse/translate_button_code.hpp>
#include <sge/input/mouse/button_code.hpp>
#include <fcppt/assert/unreachable.hpp>


sgec_input_mouse_button_code
sgec::impl::input::mouse::translate_button_code(
	sge::input::mouse::button_code const _code
)
{
	#define TRANSLATE_CASE(\
		name\
	)\
	case sge::input::mouse::button_code::name: \
		return \
			sgec_input_mouse_button_code_ ## name

	switch(
		_code
	)
	{
		TRANSLATE_CASE(
			left
		);
		TRANSLATE_CASE(
			middle
		);
		TRANSLATE_CASE(
			right
		);
		TRANSLATE_CASE(
			unknown
		);
	}

	FCPPT_ASSERT_UNREACHABLE;
}
