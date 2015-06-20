#ifndef SGEC_AUDIO_SOUND_BASE_H_INCLUDED
#define SGEC_AUDIO_SOUND_BASE_H_INCLUDED

#include <sgec/result.h>
#include <sgec/audio/sound/base_fwd.h>
#include <sgec/audio/sound/play_status.h>
#include <sgec/audio/sound/repeat.h>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>
#include <sgec/detail/symbol.h>


SGEC_DETAIL_HEADER

SGEC_DETAIL_SYMBOL
enum sgec_result
sgec_audio_sound_base_play(
	struct sgec_audio_sound_base *,
	enum sgec_audio_sound_repeat
);

SGEC_DETAIL_SYMBOL
enum sgec_audio_sound_play_status
sgec_audio_sound_base_status(
	struct sgec_audio_sound_base *
);

SGEC_DETAIL_SYMBOL
enum sgec_result
sgec_audio_sound_base_destroy(
	struct sgec_audio_sound_base *
);

SGEC_DETAIL_FOOTER

#endif
