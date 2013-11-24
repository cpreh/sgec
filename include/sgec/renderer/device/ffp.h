#ifndef SGEC_RENDERER_DEVICE_FFP_H_INCLUDED
#define SGEC_RENDERER_DEVICE_FFP_H_INCLUDED

#include <sgec/result.h>
#include <sgec/symbol.hpp>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>
#include <sgec/renderer/context/ffp_fwd.h>
#include <sgec/renderer/device/ffp_fwd.h>


SGEC_DETAIL_HEADER

SGEC_SYMBOL
struct sgec_renderer_context_ffp *
sgec_renderer_device_ffp_begin_rendering(
	struct sgec_renderer_device_ffp *
);

SGEC_SYMBOL
enum sgec_result
sgec_renderer_device_ffp_end_rendering(
	struct sgec_renderer_device_ffp *,
	struct sgec_renderer_context_ffp *
);

SGEC_DETAIL_FOOTER

#endif
