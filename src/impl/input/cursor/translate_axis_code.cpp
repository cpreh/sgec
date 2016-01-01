#include <sgec/impl/input/mouse/translate_axis_code.hpp>
#include <sgec/input/mouse/axis_code.h>
#include <sge/input/mouse/axis_code.hpp>
#include <fcppt/assert/unreachable.hpp>


sgec_input_mouse_axis_code
sgec::impl::input::mouse::translate_axis_code(
	sge::input::mouse::axis_code const _code
)
{
	#define TRANSLATE_CASE(\
		name\
	)\
	case sge::input::mouse::axis_code::name: \
		return \
			sgec_input_mouse_axis_code_ ## name

	switch(
		_code
	)
	{
		TRANSLATE_CASE(
			x
		);
		TRANSLATE_CASE(
			y
		);
		TRANSLATE_CASE(
			wheel
		);
		TRANSLATE_CASE(
			unknown
		);
	}

	FCPPT_ASSERT_UNREACHABLE;
}
