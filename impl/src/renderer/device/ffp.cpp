#include <sgec/impl/renderer/context/ffp.hpp>
#include <sgec/impl/renderer/device/ffp.hpp>
#include <sgec/impl/renderer/target/onscreen.hpp>
#include <sgec/renderer/context/ffp_fwd.h>
#include <sge/renderer/context/ffp.hpp>
#include <sge/renderer/device/ffp.hpp>
#include <sge/renderer/device/ffp_ref.hpp>
#include <sge/renderer/target/base.hpp>
#include <sge/renderer/target/onscreen.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/reference_to_base.hpp>


sgec_renderer_device_ffp::sgec_renderer_device_ffp(
	sge::renderer::device::ffp_ref const _device
)
:
	device_(
		_device
	),
	onscreen_target_(
		fcppt::make_unique_ptr<
			sgec_renderer_target_onscreen
		>(
			fcppt::make_ref(
				device_.get().onscreen_target()
			)
		)
	)
{
}

sgec_renderer_device_ffp::~sgec_renderer_device_ffp()
= default;

sgec_renderer_context_ffp *
sgec_renderer_device_ffp::begin_rendering()
{
	return
		new
		sgec_renderer_context_ffp(
			device_.get().begin_rendering_ffp(
				fcppt::reference_to_base<
					sge::renderer::target::base
				>(
					fcppt::make_ref(
						device_.get().onscreen_target()
					)
				)
			)
		);
}

void
sgec_renderer_device_ffp::end_rendering(
	sgec_renderer_context_ffp *const _context
)
{
	device_.get().end_rendering_ffp(
		_context->get()
	);
}

sgec_renderer_target_onscreen &
sgec_renderer_device_ffp::onscreen_target() const
{
	return
		*onscreen_target_;
}

sge::renderer::device::ffp &
sgec_renderer_device_ffp::get()
{
	return
		device_.get();
}
