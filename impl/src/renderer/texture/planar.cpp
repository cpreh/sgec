#include <sgec/impl/renderer/texture/planar.hpp>
#include <sge/renderer/texture/planar.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


sgec_renderer_texture_planar::sgec_renderer_texture_planar(
	sge::renderer::texture::planar_unique_ptr &&_texture
)
:
	texture_(
		std::move(
			_texture
		)
	)
{
}

sgec_renderer_texture_planar::~sgec_renderer_texture_planar()
= default;

sge::renderer::texture::planar &
sgec_renderer_texture_planar::get()
{
	return
		*texture_;
}
