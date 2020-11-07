#include <sgec/impl/texture/part.hpp>
#include <sge/renderer/dim2.hpp>
#include <sge/texture/part.hpp>
#include <sge/texture/part_unique_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


sgec_texture_part::sgec_texture_part(
	sge::texture::part_unique_ptr &&_texture
)
:
	texture_(
		std::move(
			_texture
		)
	)
{
}

sgec_texture_part::~sgec_texture_part()
= default;

sge::renderer::dim2
sgec_texture_part::size() const
{
	return
		texture_->size();
}

sge::texture::part const &
sgec_texture_part::get() const
{
	return
		*texture_;
}
