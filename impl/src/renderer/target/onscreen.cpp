#include <sgec/impl/renderer/target/onscreen.hpp>
#include <sge/renderer/target/onscreen.hpp>
#include <sge/renderer/target/viewport.hpp>
#include <fcppt/reference_impl.hpp>

sgec_renderer_target_onscreen::sgec_renderer_target_onscreen(
    fcppt::reference<sge::renderer::target::onscreen> const _target)
    : target_(_target)
{
}

sgec_renderer_target_onscreen::~sgec_renderer_target_onscreen() = default;

sge::renderer::target::viewport sgec_renderer_target_onscreen::viewport() const
{
  return target_.get().viewport();
}
