#include <sgec/result.h>
#include <sgec/impl/renderer/texture/planar.hpp>
#include <sgec/renderer/texture/planar.h>


extern "C"
enum sgec_result
sgec_renderer_texture_planar_destroy(
	struct sgec_renderer_texture_planar *const _texture
)
try
{
	delete // NOLINT(cppcoreguidelines-owning-memory)
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
