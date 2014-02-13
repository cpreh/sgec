#ifndef SGEC_IMPL_RENDERER_TEXTURE_PLANAR_HPP_INCLUDED
#define SGEC_IMPL_RENDERER_TEXTURE_PLANAR_HPP_INCLUDED

#include <sgec/renderer/texture/planar_fwd.h>
#include <sge/renderer/texture/planar_fwd.hpp>
#include <sge/renderer/texture/planar_unique_ptr.hpp>
#include <sge/renderer/texture/planar_scoped_ptr.hpp>
#include <fcppt/noncopyable.hpp>


struct sgec_renderer_texture_planar
{
	FCPPT_NONCOPYABLE(
		sgec_renderer_texture_planar
	);
public:
	explicit
	sgec_renderer_texture_planar(
		sge::renderer::texture::planar_unique_ptr &&
	);

	~sgec_renderer_texture_planar();

	sge::renderer::texture::planar &
	get();
private:
	sge::renderer::texture::planar_scoped_ptr const texture_;
};

#endif
