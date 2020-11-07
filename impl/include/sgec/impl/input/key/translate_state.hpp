#ifndef SGEC_IMPL_INPUT_KEY_TRANSLATE_STATE_HPP_INCLUDED
#define SGEC_IMPL_INPUT_KEY_TRANSLATE_STATE_HPP_INCLUDED

#include <sgec/input/key/state.h>
#include <sge/input/key/pressed.hpp>


namespace sgec
{
namespace impl
{
namespace input
{
namespace key
{

sgec_input_key_state
translate_state(
	sge::input::key::pressed
);

}
}
}
}

#endif
