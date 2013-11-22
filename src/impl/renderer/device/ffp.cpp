#include <sgec/renderer/context/ffp_fwd.h>
#include <sgec/impl/renderer/context/ffp.hpp>
#include <sgec/impl/renderer/device/ffp.hpp>
#include <sge/renderer/context/ffp.hpp>
#include <sge/renderer/device/ffp.hpp>
#include <sge/renderer/target/onscreen.hpp>


sgec_renderer_device_ffp::sgec_renderer_device_ffp(
	sge::renderer::device::ffp &_device
)
:
	device_(
		_device
	)
{
}

sgec_renderer_device_ffp::~sgec_renderer_device_ffp()
{
}

sgec_renderer_context_ffp *
sgec_renderer_device_ffp::begin_rendering()
{
	return
		new
		sgec_renderer_context_ffp(
			device_.begin_rendering_ffp(
				device_.onscreen_target()
			)
		);
}

void
sgec_renderer_device_ffp::end_rendering(
	sgec_renderer_context_ffp *const _context
)
{
	device_.end_rendering_ffp(
		_context->get()
	);
}
