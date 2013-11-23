#include <sgec/impl/renderer/context/ffp.hpp>
#include <sge/image/color/predef.hpp>
#include <sge/renderer/clear/parameters.hpp>
#include <sge/renderer/context/ffp.hpp>
#include <sge/renderer/context/ffp_unique_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


sgec_renderer_context_ffp::sgec_renderer_context_ffp(
	sge::renderer::context::ffp_unique_ptr &&_context
)
:
	context_(
		std::move(
			_context
		)
	)
{
}

sgec_renderer_context_ffp::~sgec_renderer_context_ffp()
{
}

void
sgec_renderer_context_ffp::clear()
{
	context_->clear(
		sge::renderer::clear::parameters()
		.back_buffer(
			sge::image::color::predef::black()
		)
	);
}

sge::renderer::context::ffp &
sgec_renderer_context_ffp::get()
{
	return
		*context_;
}
