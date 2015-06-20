#ifndef SGEC_AUDIO_FILE_H_INCLUDED
#define SGEC_AUDIO_FILE_H_INCLUDED

#include <sgec/result.h>
#include <sgec/audio/file_fwd.h>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>
#include <sgec/detail/symbol.h>


SGEC_DETAIL_HEADER

SGEC_DETAIL_SYMBOL
enum sgec_result
sgec_audio_file_destroy(
	struct sgec_audio_file *
);

SGEC_DETAIL_FOOTER

#endif
