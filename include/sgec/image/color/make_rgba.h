#ifndef SGEC_IMAGE_COLOR_MAKE_RGBA_H_INCLUDED
#define SGEC_IMAGE_COLOR_MAKE_RGBA_H_INCLUDED

#include <sgec/detail/symbol.h>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>
#include <sgec/image/color/rgba.h>
#include <sgec/image/color/rgba_channel.h>


SGEC_DETAIL_HEADER

SGEC_DETAIL_SYMBOL
sgec_image_color_rgba
sgec_image_color_make_rgba(
	sgec_image_color_rgba_channel red,
	sgec_image_color_rgba_channel green,
	sgec_image_color_rgba_channel blue,
	sgec_image_color_rgba_channel alpha
);

SGEC_DETAIL_FOOTER

#endif
