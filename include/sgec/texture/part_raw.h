#ifndef SGEC_TEXTURE_PART_RAW_H_INCLUDED
#define SGEC_TEXTURE_PART_RAW_H_INCLUDED

#include <sgec/detail/symbol.h>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>
#include <sgec/renderer/texture/planar_fwd.h>
#include <sgec/renderer/texture/size.h>
#include <sgec/texture/part_fwd.h>


SGEC_DETAIL_HEADER

SGEC_DETAIL_SYMBOL
struct sgec_texture_part *
sgec_texture_part_raw(
	struct sgec_renderer_texture_planar *
);

SGEC_DETAIL_SYMBOL
struct sgec_texture_part *
sgec_texture_part_raw_rect(
	struct sgec_renderer_texture_planar *,
	sgec_renderer_texture_size x,
	sgec_renderer_texture_size y,
	sgec_renderer_texture_size w,
	sgec_renderer_texture_size h
);

SGEC_DETAIL_FOOTER

#endif
