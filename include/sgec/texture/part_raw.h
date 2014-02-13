#ifndef SGEC_TEXTURE_PART_RAW_H_INCLUDED
#define SGEC_TEXTURE_PART_RAW_H_INCLUDED

#include <sgec/symbol.hpp>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>
#include <sgec/renderer/texture/planar_fwd.h>
#include <sgec/texture/part_fwd.h>


SGEC_DETAIL_HEADER

SGEC_SYMBOL
struct sgec_texture_part *
sgec_texture_part_raw(
	sgec_renderer_texture_planar *
);

SGEC_DETAIL_FOOTER

#endif
