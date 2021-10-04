#ifndef SGEC_IMPL_WINDOW_TRANSLATE_EVENT_HPP_INCLUDED
#define SGEC_IMPL_WINDOW_TRANSLATE_EVENT_HPP_INCLUDED

#include <sgec/window/event.h>
#include <awl/event/base_fwd.hpp>
#include <fcppt/optional/object_impl.hpp>


namespace sgec::impl::window
{

fcppt::optional::object<
	sgec_window_event
>
translate_event(
	awl::event::base const &
);

}

#endif
