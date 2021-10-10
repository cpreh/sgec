#include <sgec/audio/sound/play_status.h>
#include <sgec/impl/audio/sound/to_play_status.hpp>
#include <sge/audio/sound/play_status.hpp>
#include <fcppt/assert/unreachable.hpp>

sgec_audio_sound_play_status
sgec::impl::audio::sound::to_play_status(sge::audio::sound::play_status const _play_status)
{
  switch (_play_status)
  {
  case sge::audio::sound::play_status::stopped:
    return sgec_audio_sound_play_status_stopped;
  case sge::audio::sound::play_status::paused:
    return sgec_audio_sound_play_status_paused;
  case sge::audio::sound::play_status::playing:
    return sgec_audio_sound_play_status_playing;
  }

  FCPPT_ASSERT_UNREACHABLE;
}
