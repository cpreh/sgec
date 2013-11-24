#include <sgec/result.h>
#include <sgec/impl/renderer/context/ffp.hpp>
#include <sgec/renderer/context/ffp.h>


extern "C"
sgec_result
sgec_renderer_context_ffp_clear(
	struct sgec_renderer_context_ffp *const _context
)
try
{
	_context->clear();

	return
		sgec_result_ok;
}
catch(
	...
)
{
	return
		sgec_result_error;
}

extern "C"
sgec_result
sgec_renderer_context_ffp_destroy(
	struct sgec_renderer_context_ffp *const _context
)
try
{
	delete
		_context;

	return
		sgec_result_ok;
}
catch(
	...
)
{
	return
		sgec_result_error;
}
