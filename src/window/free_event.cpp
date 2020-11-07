#include <sgec/window/event.h>
#include <sgec/window/event_type.h>
#include <sgec/window/free_event.h>


extern "C"
void
sgec_window_free_event(
	struct sgec_window_event *const _event
)
{
	if(
		_event->type
		==
		sgec_window_event_type_focus_text
	)
	{
		delete[] // NOLINT(cppcoreguidelines-owning-memory)
			_event->focus_text.text; // NOLINT(cppcoreguidelines-pro-type-union-access)
	}
}
