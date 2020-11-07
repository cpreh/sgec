#include <sgec/impl/input/cursor/translate_position.hpp>
#include <sgec/impl/input/cursor/translate_position_opt.hpp>
#include <sgec/input/cursor/position_opt.h>
#include <sge/input/cursor/optional_position.hpp>
#include <sge/input/cursor/position.hpp>
#include <fcppt/math/vector/null.hpp>
#include <fcppt/optional/maybe.hpp>


sgec_input_cursor_position_opt
sgec::impl::input::cursor::translate_position_opt(
	sge::input::cursor::optional_position const &_position
)
{
	return
		fcppt::optional::maybe(
			_position,
			[]{
				return
					sgec_input_cursor_position_opt{
						sgec::impl::input::cursor::translate_position(
							fcppt::math::vector::null<
								sge::input::cursor::position
							>()
						),
						false
					};
			},
			[](
				sge::input::cursor::position const &_pos
			)
			{
				return
					sgec_input_cursor_position_opt{
						sgec::impl::input::cursor::translate_position(
							_pos
						),
						true
					};
			}
		);
}
