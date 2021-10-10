#include <sgec/impl/input/cursor/make_id.hpp>
#include <sgec/input/cursor/id.h>
#include <sge/input/cursor/object_fwd.hpp>
#include <fcppt/cast/to_uint_ptr.hpp>

sgec_input_cursor_id sgec::impl::input::cursor::make_id(sge::input::cursor::object const &_cursor)
{
  return fcppt::cast::to_uint_ptr(&_cursor);
}
