#ifndef SGEC_IMAGE_COLOR_RGBA_H_INCLUDED
#define SGEC_IMAGE_COLOR_RGBA_H_INCLUDED

#include <sgec/image/color/rgba_fwd.h>
#include <fcppt/config/external_begin.h>
#include <stdint.h>
#include <fcppt/config/external_end.h>


struct sgec_image_color_rgba
{
	uint8_t red;

	uint8_t green;

	uint8_t blue;

	uint8_t alpha;
};

#endif
