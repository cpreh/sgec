#include <sgec/image/color/rgba.h>
#include <sgec/impl/image/color/translate_rgba.hpp>
#include <sge/image/color/rgba8.hpp>
#include <sge/image/color/init/alpha.hpp>
#include <sge/image/color/init/blue.hpp>
#include <sge/image/color/init/green.hpp>
#include <sge/image/color/init/red.hpp>


sge::image::color::rgba8 const
sgec::impl::image::color::translate_rgba(
	sgec_image_color_rgba const _color
)
{
	return
		sge::image::color::rgba8(
			(sge::image::color::init::red() = _color.red)
			(sge::image::color::init::blue() = _color.blue)
			(sge::image::color::init::green() = _color.green)
			(sge::image::color::init::alpha() = _color.alpha)
		);
}
