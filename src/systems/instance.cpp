#include <sgec/result.h>
#include <sgec/audio/loader_fwd.h>
#include <sgec/audio/player_fwd.h>
#include <sgec/font/system_fwd.h>
#include <sgec/image2d/system_fwd.h>
#include <sgec/impl/systems/instance.hpp>
#include <sgec/renderer/device/ffp_fwd.h>
#include <sgec/systems/cursor_option.h>
#include <sgec/systems/instance.h>
#include <sgec/window/system_fwd.h>
#include <sgec/window/unit.h>

extern "C" struct sgec_systems_instance *sgec_systems_instance_create(
    char const *const _window_name,
    sgec_window_unit const _width,
    sgec_window_unit const _height,
    enum sgec_systems_cursor_option const _cursor_option)
try
{
  return // NOLINT(cppcoreguidelines-owning-memory)
      new sgec_systems_instance(_window_name, _width, _height, _cursor_option);
}
catch (...)
{
  return nullptr;
}

extern "C" sgec_result sgec_systems_instance_destroy(struct sgec_systems_instance *const _instance)
try
{
  delete // NOLINT(cppcoreguidelines-owning-memory)
      _instance;

  return sgec_result_ok;
}
catch (...)
{
  return sgec_result_error;
}

extern "C" struct sgec_renderer_device_ffp *
sgec_systems_instance_renderer(struct sgec_systems_instance *const _instance)
{
  return _instance->renderer();
}

extern "C" struct sgec_window_system *
sgec_systems_instance_window_system(struct sgec_systems_instance *const _instance)
{
  return _instance->window_system();
}

extern "C" struct sgec_image2d_system *
sgec_systems_instance_image2d_system(struct sgec_systems_instance *const _instance)
{
  return _instance->image2d_system();
}

extern "C" struct sgec_font_system *
sgec_systems_instance_font_system(struct sgec_systems_instance *const _instance)
{
  return _instance->font_system();
}

extern "C" struct sgec_audio_loader *
sgec_systems_instance_audio_loader(struct sgec_systems_instance *const _instance)
{
  return _instance->audio_loader();
}

extern "C" struct sgec_audio_player *
sgec_systems_instance_audio_player(struct sgec_systems_instance *const _instance)
{
  return _instance->audio_player();
}
