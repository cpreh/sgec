#ifndef SGEC_IMPL_RENDERER_CONTEXT_FFP_HPP_INCLUDED
#define SGEC_IMPL_RENDERER_CONTEXT_FFP_HPP_INCLUDED

#include <sgec/renderer/context/ffp_fwd.h>
#include <sge/renderer/context/ffp_fwd.hpp>
#include <sge/renderer/context/ffp_unique_ptr.hpp>
#include <fcppt/noncopyable.hpp>


struct sgec_renderer_context_ffp
{
	FCPPT_NONCOPYABLE(
		sgec_renderer_context_ffp
	);
public:
	explicit
	sgec_renderer_context_ffp(
		sge::renderer::context::ffp_unique_ptr &&
	);

	~sgec_renderer_context_ffp();

	void
	clear();

	sge::renderer::context::ffp &
	get();
private:
	sge::renderer::context::ffp_unique_ptr const context_;
};

#endif
