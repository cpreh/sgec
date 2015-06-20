#ifndef SGEC_AUDIO_SOUND_PLAY_STATUS_H_INCLUDED
#define SGEC_AUDIO_SOUND_PLAY_STATUS_H_INCLUDED

#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>


SGEC_DETAIL_HEADER

enum sgec_audio_sound_play_status
{
	sgec_audio_sound_play_status_stopped,
	sgec_audio_sound_play_status_playing,
	sgec_audio_sound_play_status_paused,
	sgec_audio_sound_play_status_error
};

SGEC_DETAIL_FOOTER

#endif
