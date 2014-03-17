#include <sgec/impl/renderer/texture/planar.hpp>
#include <sgec/impl/texture/part.hpp>
#include <sgec/texture/part_raw.h>
#include <sge/texture/part_raw_ref.hpp>
#include <fcppt/make_unique_ptr.hpp>


extern "C"
struct sgec_texture_part *
sgec_texture_part_raw(
	struct sgec_renderer_texture_planar *const _texture
)
try
{
	return
		new sgec_texture_part(
			fcppt::make_unique_ptr<
				sge::texture::part_raw_ref
			>(
				_texture->get()
			)
		);
}
catch(
	...
)
{
	return
		nullptr;
}
