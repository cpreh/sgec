#ifndef SGEC_FONT_DRAW_SIMPLE_H_INCLUDED
#define SGEC_FONT_DRAW_SIMPLE_H_INCLUDED

#include <sgec/result.h>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>
#include <sgec/detail/symbol.h>
#include <sgec/font/object_fwd.h>
#include <sgec/font/unit.h>
#include <sgec/image/color/rgba.h>
#include <sgec/renderer/context/ffp_fwd.h>
#include <sgec/renderer/device/ffp_fwd.h>
#include <fcppt/config/external_begin.h>
#include <wchar.h>
#include <fcppt/config/external_end.h>


SGEC_DETAIL_HEADER

SGEC_DETAIL_SYMBOL
enum sgec_result
sgec_font_draw_simple(
	struct sgec_renderer_device_ffp *,
	struct sgec_renderer_context_ffp *,
	struct sgec_font_object *,
	wchar_t const *text,
	sgec_font_unit x,
	sgec_font_unit y,
	sgec_image_color_rgba
);

SGEC_DETAIL_FOOTER

#endif
