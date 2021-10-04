#ifndef SGEC_IMPL_RENDERER_TRANSLATE_RENDER_EVENT_HPP_INCLUDED
#define SGEC_IMPL_RENDERER_TRANSLATE_RENDER_EVENT_HPP_INCLUDED

#include <sgec/renderer/render_event.h>
#include <sge/renderer/event/render_fwd.hpp>


namespace sgec::impl::renderer
{

sgec_renderer_render_event
translate_render_event(
	sge::renderer::event::render const &
);

}

#endif
