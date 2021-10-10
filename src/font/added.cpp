#include <sgec/result.h>
#include <sgec/font/added.h>
#include <sgec/impl/font/added.hpp>

extern "C" enum sgec_result sgec_font_added_destroy(struct sgec_font_added *const _added)
try
{
  delete // NOLINT(cppcoreguidelines-owning-memory)
      _added;

  return sgec_result_ok;
}
catch (...)
{
  return sgec_result_error;
}
