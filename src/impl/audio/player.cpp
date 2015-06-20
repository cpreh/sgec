#include <sgec/impl/audio/buffer.hpp>
#include <sgec/impl/audio/file.hpp>
#include <sgec/impl/audio/player.hpp>
#include <sge/audio/buffer.hpp>
#include <sge/audio/player.hpp>


sgec_audio_player::sgec_audio_player(
	sge::audio::player &_player
)
:
	player_(
		_player
	)
{
}

sgec_audio_player::~sgec_audio_player()
{
}

sgec_audio_buffer *
sgec_audio_player::create_buffer(
	sgec_audio_file *const _file
)
{
	return
		new
		sgec_audio_buffer(
			player_.create_buffer(
				_file->get()
			)
		);
}
