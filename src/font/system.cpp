#include <sgec/font/added_fwd.h>
#include <sgec/font/object_fwd.h>
#include <sgec/font/system.h>
#include <sgec/font/ttf_size.h>
#include <sgec/impl/font/system.hpp>

extern "C" struct sgec_font_object *sgec_font_system_create_font(
    struct sgec_font_system *const _system,
    char const *const _family,
    sgec_font_ttf_size const _ttf_size)
try
{
  return _system->create(_family, _ttf_size);
}
catch (...)
{
  return nullptr;
}

extern "C" struct sgec_font_added *
sgec_font_system_add_font(struct sgec_font_system *const _system, char const *const _path)
try
{
  return _system->add(_path);
}
catch (...)
{
  return nullptr;
}
