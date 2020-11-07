#ifndef SGEC_IMPL_RENDERER_DEVICE_FFP_HPP_INCLUDED
#define SGEC_IMPL_RENDERER_DEVICE_FFP_HPP_INCLUDED

#include <sgec/renderer/context/ffp_fwd.h>
#include <sgec/renderer/device/ffp_fwd.h>
#include <sgec/renderer/target/onscreen_fwd.h>
#include <sge/renderer/device/ffp_fwd.hpp>
#include <sge/renderer/device/ffp_ref.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/unique_ptr_impl.hpp>


struct sgec_renderer_device_ffp
{
	FCPPT_NONMOVABLE(
		sgec_renderer_device_ffp
	);
public:
	explicit
	sgec_renderer_device_ffp(
		sge::renderer::device::ffp_ref
	);

	~sgec_renderer_device_ffp();

	sgec_renderer_context_ffp *
	begin_rendering();

	void
	end_rendering(
		sgec_renderer_context_ffp *
	);

	[[nodiscard]]
	sgec_renderer_target_onscreen &
	onscreen_target() const;

	[[nodiscard]]
	sge::renderer::device::ffp &
	get();
private:
	sge::renderer::device::ffp_ref const device_;

	using
	scoped_target_onscreen_ptr
	=
	fcppt::unique_ptr<
		sgec_renderer_target_onscreen
	>;

	scoped_target_onscreen_ptr const onscreen_target_;
};

#endif
