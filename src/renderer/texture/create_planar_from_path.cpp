#include <sgec/image2d/system_fwd.h>
#include <sgec/impl/image2d/system.hpp>
#include <sgec/impl/renderer/device/ffp.hpp>
#include <sgec/impl/renderer/texture/planar.hpp>
#include <sgec/renderer/device/ffp_fwd.h>
#include <sgec/renderer/texture/create_planar_from_path.h>
#include <sge/renderer/resource_flags_field.hpp>
#include <sge/renderer/device/core.hpp>
#include <sge/renderer/device/ffp.hpp>
#include <sge/renderer/texture/create_planar_from_path.hpp>
#include <sge/renderer/texture/emulate_srgb.hpp>
#include <sge/renderer/texture/planar.hpp>
#include <sge/renderer/texture/mipmap/off.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/reference_to_base.hpp>
#include <fcppt/config/external_begin.hpp>
#include <filesystem>
#include <fcppt/config/external_end.hpp>

extern "C" struct sgec_renderer_texture_planar *sgec_renderer_texture_create_planar_from_path(
    struct sgec_renderer_device_ffp *const _renderer,
    struct sgec_image2d_system *const _image_system,
    char const *const _path)
try
{
  return new sgec_renderer_texture_planar(sge::renderer::texture::create_planar_from_path(
      std::filesystem::path(_path),
      fcppt::reference_to_base<sge::renderer::device::core>(fcppt::make_ref(_renderer->get())),
      _image_system->get(),
      sge::renderer::texture::mipmap::off(),
      sge::renderer::resource_flags_field{},
      sge::renderer::texture::emulate_srgb::no));
}
catch (...)
{
  return nullptr;
}
