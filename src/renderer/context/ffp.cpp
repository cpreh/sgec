#include <sgec/result.h>
#include <sgec/image/color/rgba.h>
#include <sgec/impl/renderer/context/ffp.hpp>
#include <sgec/renderer/context/ffp.h>


extern "C"
sgec_result
sgec_renderer_context_ffp_clear(
	struct sgec_renderer_context_ffp *const _context,
	sgec_image_color_rgba const _color
)
try
{
	_context->clear(
		_color
	);

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
	delete // NOLINT(cppcoreguidelines-owning-memory)
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
