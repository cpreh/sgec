#include <sgec/font/ttf_size.h>
#include <sgec/impl/font/added.hpp>
#include <sgec/impl/font/object.hpp>
#include <sgec/impl/font/system.hpp>
#include <sge/font/added.hpp> // NOLINT(misc-include-cleaner)
#include <sge/font/object.hpp> // NOLINT(misc-include-cleaner)
#include <sge/font/parameters.hpp>
#include <sge/font/system.hpp>
#include <fcppt/from_std_string.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/config/external_begin.hpp>
#include <filesystem>
#include <string>
#include <fcppt/config/external_end.hpp>

sgec_font_system::sgec_font_system(fcppt::reference<sge::font::system> const _system)
    : system_(_system)
{
}

sgec_font_system::~sgec_font_system() = default;

sgec_font_object *
sgec_font_system::create(char const *const _family, sgec_font_ttf_size const _size)
{
  sge::font::parameters parameters{};

  if (_family != nullptr)
  {
    parameters.family(fcppt::from_std_string(std::string(_family)));
  }

  if (_size != -1)
  {
    parameters.ttf_size(fcppt::cast::to_unsigned(_size));
  }

  // NOLINTNEXTLINE(cppcoreguidelines-owning-memory)
  return new sgec_font_object(system_.get().create_font(parameters));
}

sgec_font_added *sgec_font_system::add(char const *const _path)
{
  // NOLINTNEXTLINE(cppcoreguidelines-owning-memory)
  return new sgec_font_added(system_.get().add_font(std::filesystem::path(_path)));
}

sge::font::system &sgec_font_system::get() { return system_.get(); }
