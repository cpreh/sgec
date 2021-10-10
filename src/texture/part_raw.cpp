#include <sgec/impl/renderer/texture/planar.hpp>
#include <sgec/impl/texture/part.hpp>
#include <sgec/renderer/texture/size.h>
#include <sgec/texture/part_raw.h>
#include <sge/renderer/lock_rect.hpp>
#include <sge/texture/part.hpp>
#include <sge/texture/part_raw_ref.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_to_base.hpp>

extern "C" struct sgec_texture_part *
sgec_texture_part_raw(struct sgec_renderer_texture_planar *const _texture)
try
{
  return new sgec_texture_part(fcppt::unique_ptr_to_base<sge::texture::part>(
      fcppt::make_unique_ptr<sge::texture::part_raw_ref>(_texture->get())));
}
catch (...)
{
  return nullptr;
}

extern "C" struct sgec_texture_part *sgec_texture_part_raw_rect(
    struct sgec_renderer_texture_planar *const _texture,
    sgec_renderer_texture_size const _x,
    sgec_renderer_texture_size const _y,
    sgec_renderer_texture_size const _w,
    sgec_renderer_texture_size const _h)
try
{
  return new sgec_texture_part(fcppt::unique_ptr_to_base<sge::texture::part>(
      fcppt::make_unique_ptr<sge::texture::part_raw_ref>(
          _texture->get(),
          sge::renderer::lock_rect{
              sge::renderer::lock_rect::vector{_x, _y}, sge::renderer::lock_rect::dim{_w, _h}})));
}
catch (...)
{
  return nullptr;
}
