#include <sgec/image/color/make_rgba.h>
#include <sgec/image/color/rgba.h>
#include <sgec/image/color/rgba_channel.h>
#include <fcppt/cast/size.hpp>

extern "C" sgec_image_color_rgba sgec_image_color_make_rgba(
    sgec_image_color_rgba_channel const _red,
    sgec_image_color_rgba_channel const _green,
    sgec_image_color_rgba_channel const _blue,
    sgec_image_color_rgba_channel const _alpha)
{
  auto const translate(
      [](sgec_image_color_rgba_channel const _arg,
         unsigned int const _shift) -> sgec_image_color_rgba
      { return fcppt::cast::size<sgec_image_color_rgba>(_arg) << _shift; });

  return translate(
             _red,
             24U // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
             ) |
         translate(
             _green,
             16U // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
             ) |
         translate(
             _blue,
             8U // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
             ) |
         translate(
             _alpha,
             0U // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
         );
}
