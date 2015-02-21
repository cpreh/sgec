#include <sgec/font/system.h>
#include <sgec/impl/font/object.hpp>
#include <sgec/impl/font/system.hpp>


extern "C"
struct sgec_font_object *
sgec_font_create(
	struct sgec_font_system *const _system
)
try
{
	return
		_system->create();
}
catch(
	...
)
{
	return
		nullptr;
}
