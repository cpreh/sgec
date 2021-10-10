#include <sgec/impl/renderer/target/onscreen.hpp>
#include <sgec/renderer/target/onscreen.h>
#include <sgec/renderer/target/size.h>
#include <sge/renderer/target/viewport.hpp>
#include <fcppt/cast/to_unsigned.hpp>

extern "C" sgec_renderer_target_size sgec_renderer_target_onscreen_viewport_width(
    struct sgec_renderer_target_onscreen const *const _target)
{
  return fcppt::cast::to_unsigned(_target->viewport().get().size().w());
}

extern "C" sgec_renderer_target_size sgec_renderer_target_onscreen_viewport_height(
    struct sgec_renderer_target_onscreen const *const _target)
{
  return fcppt::cast::to_unsigned(_target->viewport().get().size().h());
}
