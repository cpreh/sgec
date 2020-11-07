#ifndef SGEC_IMPL_RENDERER_TARGET_ONSCREEN_HPP_INCLUDED
#define SGEC_IMPL_RENDERER_TARGET_ONSCREEN_HPP_INCLUDED

#include <sgec/renderer/target/onscreen_fwd.h>
#include <sge/renderer/target/onscreen_fwd.hpp>
#include <sge/renderer/target/viewport_fwd.hpp>
#include <fcppt/noncopyable.hpp>


struct sgec_renderer_target_onscreen
{
	FCPPT_NONCOPYABLE(
		sgec_renderer_target_onscreen
	);
public:
	explicit
	sgec_renderer_target_onscreen(
		sge::renderer::target::onscreen &
	);

	~sgec_renderer_target_onscreen();

	sge::renderer::target::viewport const
	viewport() const;
private:
	sge::renderer::target::onscreen &target_;
};

#endif
