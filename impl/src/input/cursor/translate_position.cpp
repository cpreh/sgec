#include <sgec/impl/input/cursor/translate_position.hpp>
#include <sgec/input/cursor/position.h>
#include <sge/input/cursor/position.hpp>

sgec_input_cursor_position
sgec::impl::input::cursor::translate_position(sge::input::cursor::position const &_position)
{
  return sgec_input_cursor_position{_position.x(), _position.y()};
}
