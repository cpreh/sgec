#include <sgec/impl/audio/buffer.hpp>
#include <sgec/impl/audio/file.hpp>
#include <sgec/impl/audio/player.hpp>
#include <sge/audio/buffer.hpp>
#include <sge/audio/player.hpp>
#include <fcppt/reference_impl.hpp>


sgec_audio_player::sgec_audio_player(
	fcppt::reference<
		sge::audio::player
	> const _player
)
:
	player_(
		_player
	)
{
}

sgec_audio_player::~sgec_audio_player()
= default;

sgec_audio_buffer *
sgec_audio_player::create_buffer(
	sgec_audio_file *const _file
)
{
	return
		new
		sgec_audio_buffer(
			player_.get().create_buffer(
				_file->get()
			)
		);
}
