#ifndef SGEC_RENDERER_TEXTURE_CREATE_PLANAR_FROM_PATH_H_INCLUDED
#define SGEC_RENDERER_TEXTURE_CREATE_PLANAR_FROM_PATH_H_INCLUDED

#include <sgec/detail/symbol.h>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>
#include <sgec/image2d/system_fwd.h>
#include <sgec/renderer/device/ffp_fwd.h>


SGEC_DETAIL_HEADER

SGEC_DETAIL_SYMBOL
struct sgec_renderer_texture_planar *
sgec_renderer_texture_create_planar_from_path(
	struct sgec_renderer_device_ffp *,
	struct sgec_image2d_system *,
	char const *
);

SGEC_DETAIL_FOOTER

#endif
