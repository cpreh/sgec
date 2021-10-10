#ifndef SGEC_IMPL_RENDERER_TEXTURE_PLANAR_HPP_INCLUDED
#define SGEC_IMPL_RENDERER_TEXTURE_PLANAR_HPP_INCLUDED

#include <sgec/renderer/texture/planar_fwd.h>
#include <sge/renderer/texture/planar_fwd.hpp>
#include <sge/renderer/texture/planar_unique_ptr.hpp>
#include <fcppt/nonmovable.hpp>

struct sgec_renderer_texture_planar
{
  FCPPT_NONMOVABLE(sgec_renderer_texture_planar);

public:
  explicit sgec_renderer_texture_planar(sge::renderer::texture::planar_unique_ptr &&);

  ~sgec_renderer_texture_planar();

  [[nodiscard]] sge::renderer::texture::planar &get();

private:
  sge::renderer::texture::planar_unique_ptr const texture_;
};

#endif
