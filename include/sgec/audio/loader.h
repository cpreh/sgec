#ifndef SGEC_AUDIO_LOADER_H_INCLUDED
#define SGEC_AUDIO_LOADER_H_INCLUDED

#include <sgec/audio/file_fwd.h>
#include <sgec/audio/loader_fwd.h>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>
#include <sgec/detail/symbol.h>


SGEC_DETAIL_HEADER

SGEC_DETAIL_SYMBOL
struct sgec_audio_file *
sgec_audio_loader_load(
	struct sgec_audio_loader *,
	char const *path
);

SGEC_DETAIL_FOOTER

#endif
