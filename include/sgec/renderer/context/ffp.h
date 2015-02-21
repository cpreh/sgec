#ifndef SGEC_RENDERER_CONTEXT_FFP_H_INCLUDED
#define SGEC_RENDERER_CONTEXT_FFP_H_INCLUDED

#include <sgec/result.h>
#include <sgec/detail/symbol.h>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>
#include <sgec/image/color/rgba_fwd.h>
#include <sgec/renderer/context/ffp_fwd.h>


SGEC_DETAIL_HEADER

SGEC_DETAIL_SYMBOL
enum sgec_result
sgec_renderer_context_ffp_clear(
	struct sgec_renderer_context_ffp *,
	struct sgec_image_color_rgba
);

SGEC_DETAIL_SYMBOL
enum sgec_result
sgec_renderer_context_ffp_destroy(
	struct sgec_renderer_context_ffp *
);

SGEC_DETAIL_FOOTER

#endif
