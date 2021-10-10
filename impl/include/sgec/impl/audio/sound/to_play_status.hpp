#ifndef SGEC_IMPL_AUDIO_SOUND_TO_PLAY_STATUS_HPP_INCLUDED
#define SGEC_IMPL_AUDIO_SOUND_TO_PLAY_STATUS_HPP_INCLUDED

#include <sgec/audio/sound/play_status.h>
#include <sge/audio/sound/play_status_fwd.hpp>

namespace sgec::impl::audio::sound
{

sgec_audio_sound_play_status to_play_status(sge::audio::sound::play_status);

}

#endif
