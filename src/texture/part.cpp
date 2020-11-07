#include <sgec/result.h>
#include <sgec/impl/texture/part.hpp>
#include <sgec/renderer/texture/size.h>
#include <sgec/texture/part.h>
#include <sge/renderer/dim2.hpp>


extern "C"
sgec_renderer_texture_size
sgec_texture_part_width(
	struct sgec_texture_part const *const _texture
)
{
	return
		_texture->size().w();
}

extern "C"
sgec_renderer_texture_size
sgec_texture_part_height(
	struct sgec_texture_part const *const _texture
)
{
	return
		_texture->size().h();
}

extern "C"
enum sgec_result
sgec_texture_part_destroy(
	struct sgec_texture_part *const _texture
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
