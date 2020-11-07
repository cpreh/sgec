#include <sgec/impl/renderer/target/onscreen.hpp>
#include <sge/renderer/target/onscreen.hpp>
#include <sge/renderer/target/viewport.hpp>


sgec_renderer_target_onscreen::sgec_renderer_target_onscreen(
	sge::renderer::target::onscreen &_target
)
:
	target_(
		_target
	)
{
}

sgec_renderer_target_onscreen::~sgec_renderer_target_onscreen()
{
}

sge::renderer::target::viewport const
sgec_renderer_target_onscreen::viewport() const
{
	return
		target_.viewport();
}

