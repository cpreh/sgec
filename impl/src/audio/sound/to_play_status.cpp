#include <sgec/audio/sound/play_status.h>
#include <sgec/impl/audio/sound/to_play_status.hpp>
#include <sge/audio/sound/play_status.hpp>
#include <fcppt/enum/make_invalid.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>

sgec_audio_sound_play_status
sgec::impl::audio::sound::to_play_status(sge::audio::sound::play_status const _play_status)
{
  FCPPT_PP_PUSH_WARNING
  FCPPT_PP_DISABLE_GCC_WARNING(-Wswitch-default)
  switch (_play_status)
  {
  case sge::audio::sound::play_status::stopped:
    return sgec_audio_sound_play_status_stopped;
  case sge::audio::sound::play_status::paused:
    return sgec_audio_sound_play_status_paused;
  case sge::audio::sound::play_status::playing:
    return sgec_audio_sound_play_status_playing;
  }
  FCPPT_PP_POP_WARNING

  throw fcppt::enum_::make_invalid(_play_status);
}
