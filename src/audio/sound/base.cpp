#include <sgec/result.h>
#include <sgec/audio/sound/base.h>
#include <sgec/audio/sound/play_status.h>
#include <sgec/audio/sound/repeat.h>
#include <sgec/impl/audio/sound/base.hpp>

extern "C" enum sgec_result sgec_audio_sound_base_play(
    struct sgec_audio_sound_base *const _sound, enum sgec_audio_sound_repeat const _repeat)
try
{
  _sound->play(_repeat);

  return sgec_result_ok;
}
catch (...)
{
  return sgec_result_error;
}

extern "C" enum sgec_audio_sound_play_status
sgec_audio_sound_base_status(struct sgec_audio_sound_base *const _sound)
try
{
  return _sound->play_status();
}
catch (...)
{
  return sgec_audio_sound_play_status_error;
}

extern "C" enum sgec_result
sgec_audio_sound_base_destroy(struct sgec_audio_sound_base *const _sound)
try
{
  delete // NOLINT(cppcoreguidelines-owning-memory)
      _sound;

  return sgec_result_ok;
}
catch (...)
{
  return sgec_result_error;
}
