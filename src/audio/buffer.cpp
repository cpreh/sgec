#include <sgec/result.h>
#include <sgec/audio/buffer.h>
#include <sgec/audio/sound/base_fwd.h>
#include <sgec/impl/audio/buffer.hpp>


extern "C"
struct sgec_audio_sound_base *
sgec_audio_buffer_create_nonpositional(
	struct sgec_audio_buffer *const _buffer
)
try
{
	return
		_buffer->create_nonpositional();
}
catch(
	...
)
{
	return
		nullptr;
}

extern "C"
enum sgec_result
sgec_audio_buffer_destroy(
	struct sgec_audio_buffer *const _audio
)
try
{
	delete
		_audio;

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
