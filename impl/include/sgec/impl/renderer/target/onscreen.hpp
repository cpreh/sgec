#ifndef SGEC_IMPL_RENDERER_TARGET_ONSCREEN_HPP_INCLUDED
#define SGEC_IMPL_RENDERER_TARGET_ONSCREEN_HPP_INCLUDED

#include <sgec/renderer/target/onscreen_fwd.h>
#include <sge/renderer/target/onscreen_fwd.hpp>
#include <sge/renderer/target/viewport_fwd.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/reference_impl.hpp>

struct sgec_renderer_target_onscreen
{
  FCPPT_NONMOVABLE(sgec_renderer_target_onscreen);

public:
  explicit sgec_renderer_target_onscreen(fcppt::reference<sge::renderer::target::onscreen>);

  ~sgec_renderer_target_onscreen(); // NOLINT(performance-trivially-destructible)

  [[nodiscard]] sge::renderer::target::viewport viewport() const;

private:
  fcppt::reference<sge::renderer::target::onscreen> const target_;
};

#endif
