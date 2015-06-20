#include <sgec/result.h>
#include <sgec/audio/file.h>
#include <sgec/impl/audio/file.hpp>


extern "C"
enum sgec_result
sgec_audio_file_destroy(
	struct sgec_audio_file *const _file
)
try
{
	delete
		_file;

	return
		sgec_result_ok;
}
catch(
	...
)
{
	return
		sgec_result_error;
}
