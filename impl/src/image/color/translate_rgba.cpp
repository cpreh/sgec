#include <sgec/image/color/rgba.h>
#include <sgec/impl/image/color/translate_rgba.hpp>
#include <sge/image/channel8.hpp>
#include <sge/image/color/rgba8.hpp>
#include <sge/image/color/init/alpha.hpp>
#include <sge/image/color/init/blue.hpp>
#include <sge/image/color/init/green.hpp>
#include <sge/image/color/init/red.hpp>
#include <fcppt/literal.hpp>
#include <fcppt/cast/size.hpp>

sge::image::color::rgba8
sgec::impl::image::color::translate_rgba(sgec_image_color_rgba const _color)
{
  auto const translate(
      [_color](unsigned int const _shift) -> sge::image::channel8
      {
        return fcppt::cast::size<sge::image::channel8>(
            ((fcppt::literal<sgec_image_color_rgba>(
                  0xFFU // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
                  )
              << _shift) &
             _color) >>
            _shift);
      });

  return sge::image::color::rgba8(
      (sge::image::color::init::red() = translate(
           24U)) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
      (sge::image::color::init::blue() = translate(
           16U)) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
      (sge::image::color::init::green() =
           translate(8U)) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
      (sge::image::color::init::alpha() =
           translate(0U)) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
  );
}
