#include <sgec/impl/renderer/context/ffp.hpp>
#include <sgec/renderer/context/ffp.h>


extern "C"
bool
sgec_renderer_context_ffp_clear(
	struct sgec_renderer_context_ffp *const _context
)
try
{
	_context->clear();

	return
		true;
}
catch(
	...
)
{
	return
		false;
}

extern "C"
bool
sgec_renderer_context_ffp_destroy(
	struct sgec_renderer_context_ffp *const _context
)
try
{
	delete
		_context;

	return
		true;
}
catch(
	...
)
{
	return
		false;
}
