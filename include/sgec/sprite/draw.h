#ifndef SGEC_SPRITE_DRAW_H_INCLUDED
#define SGEC_SPRITE_DRAW_H_INCLUDED

#include <sgec/result.h>
#include <sgec/symbol.hpp>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>
#include <sgec/renderer/context/ffp_fwd.h>
#include <sgec/renderer/device/ffp_fwd.h>
#include <sgec/sprite/object_fwd.h>
#include <fcppt/config/external_begin.hpp>
#include <stddef.h>
#include <fcppt/config/external_end.hpp>


SGEC_DETAIL_HEADER

SGEC_SYMBOL
enum sgec_result
sgec_sprite_draw(
	struct sgec_renderer_device_ffp *,
	struct sgec_renderer_context_ffp *,
	struct sgec_sprite_object const *,
	size_t count
);

SGEC_DETAIL_FOOTER

#endif
