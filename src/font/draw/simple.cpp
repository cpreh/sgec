#include <sgec/result.h>
#include <sgec/font/unit.h>
#include <sgec/font/draw/simple.h>
#include <sgec/impl/font/object.hpp>
#include <sgec/impl/renderer/context/ffp.hpp>
#include <sgec/impl/renderer/device/ffp.hpp>
#include <sge/font/string.hpp>
#include <sge/font/text_parameters.hpp>
#include <sge/font/vector.hpp>
#include <sge/font/align_h/left.hpp>
#include <sge/font/draw/simple.hpp>
#include <sge/image/color/predef.hpp>
#include <sge/renderer/texture/emulate_srgb.hpp>


extern "C"
enum sgec_result
sgec_font_draw_simple(
	struct sgec_renderer_device_ffp *const _render_device,
	struct sgec_renderer_context_ffp *const _render_context,
	struct sgec_font_object *const _font,
	wchar_t const *const _text,
	sgec_font_unit const _x,
	sgec_font_unit const _y
)
try
{
	sge::font::draw::simple(
		_render_device->get(),
		_render_context->get(),
		_font->get(),
		sge::font::string(
			_text
		),
		sge::font::text_parameters(
			sge::font::align_h::left{}
		),
		sge::font::vector{
			_x,
			_y
		},
		sge::image::color::predef::white(), // TODO
		sge::renderer::texture::emulate_srgb::no
	);

	return
		sgec_result_ok;
}
catch(
	...
)
{
	return
		sgec_result_error;
}
