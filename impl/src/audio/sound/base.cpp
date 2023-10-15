#include <sgec/audio/sound/play_status.h>
#include <sgec/audio/sound/repeat.h>
#include <sgec/impl/audio/sound/base.hpp>
#include <sgec/impl/audio/sound/from_repeat.hpp>
#include <sgec/impl/audio/sound/to_play_status.hpp>
#include <sge/audio/sound/base.hpp> // NOLINT(misc-include-cleaner)
#include <sge/audio/sound/base_unique_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

sgec_audio_sound_base::sgec_audio_sound_base(sge::audio::sound::base_unique_ptr &&_sound)
    : sound_(std::move(_sound))
{
}

sgec_audio_sound_base::~sgec_audio_sound_base() = default;

void sgec_audio_sound_base::play(sgec_audio_sound_repeat const _repeat)
{
  sound_->play(sgec::impl::audio::sound::from_repeat(_repeat));
}

sgec_audio_sound_play_status sgec_audio_sound_base::play_status() const
{
  return sgec::impl::audio::sound::to_play_status(sound_->status());
}
