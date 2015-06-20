#ifndef SGEC_AUDIO_PLAYER_H_INCLUDED
#define SGEC_AUDIO_PLAYER_H_INCLUDED

#include <sgec/audio/buffer_fwd.h>
#include <sgec/audio/file_fwd.h>
#include <sgec/audio/player_fwd.h>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>
#include <sgec/detail/symbol.h>


SGEC_DETAIL_HEADER

SGEC_DETAIL_SYMBOL
struct sgec_audio_buffer *
sgec_audio_player_create_buffer(
	struct sgec_audio_player *,
	struct sgec_audio_file *
);

SGEC_DETAIL_FOOTER

#endif
