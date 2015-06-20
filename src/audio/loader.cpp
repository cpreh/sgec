#include <sgec/audio/file_fwd.h>
#include <sgec/audio/loader.h>
#include <sgec/impl/audio/loader.hpp>


extern "C"
struct sgec_audio_file *
sgec_audio_loader_load(
	struct sgec_audio_loader *const _loader,
	char const *const _path
)
{
	return
		_loader->load(
			_path
		);
}
