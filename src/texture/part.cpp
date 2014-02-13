#include <sgec/result.h>
#include <sgec/impl/texture/part.hpp>
#include <sgec/texture/part.h>


extern "C"
enum sgec_result
sgec_texture_part_destroy(
	sgec_texture_part *const _texture
)
try
{
	delete
		_texture;

	return
		sgec_result_ok;
}
catch(
	...
)
{
	return
		sgec_result_error;
}
