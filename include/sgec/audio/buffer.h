#ifndef SGEC_AUDIO_BUFFER_H_INCLUDED
#define SGEC_AUDIO_BUFFER_H_INCLUDED

#include <sgec/result.h>
#include <sgec/audio/buffer_fwd.h>
#include <sgec/audio/sound/base_fwd.h>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>
#include <sgec/detail/symbol.h>


SGEC_DETAIL_HEADER

SGEC_DETAIL_SYMBOL
struct sgec_audio_sound_base *
sgec_audio_buffer_create_nonpositional(
	struct sgec_audio_buffer *
);

SGEC_DETAIL_SYMBOL
enum sgec_result
sgec_audio_buffer_destroy(
	struct sgec_audio_buffer *
);

SGEC_DETAIL_FOOTER

#endif
