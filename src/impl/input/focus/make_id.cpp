#include <sgec/impl/input/focus/make_id.hpp>
#include <sgec/input/focus/id.h>
#include <sge/input/focus/object_fwd.hpp>
#include <fcppt/cast/to_uint_ptr.hpp>


sgec_input_focus_id
sgec::impl::input::focus::make_id(
	sge::input::focus::object const &_focus
)
{
	return
		fcppt::cast::to_uint_ptr(
			&_focus
		);
}
