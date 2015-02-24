#ifndef SGEC_RENDERER_TARGET_ONSCREEN_H_INCLUDED
#define SGEC_RENDERER_TARGET_ONSCREEN_H_INCLUDED

#include <sgec/detail/symbol.h>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>
#include <sgec/renderer/target/onscreen_fwd.h>
#include <sgec/renderer/target/size.h>


SGEC_DETAIL_HEADER

SGEC_DETAIL_SYMBOL
sgec_renderer_target_size
sgec_renderer_target_onscreen_viewport_width(
	struct sgec_renderer_target_onscreen const *
);

SGEC_DETAIL_SYMBOL
sgec_renderer_target_size
sgec_renderer_target_onscreen_viewport_height(
	struct sgec_renderer_target_onscreen const *
);

SGEC_DETAIL_FOOTER

#endif
