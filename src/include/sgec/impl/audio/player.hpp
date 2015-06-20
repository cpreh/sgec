#ifndef SGEC_IMPL_AUDIO_PLAYER_HPP_INCLUDED
#define SGEC_IMPL_AUDIO_PLAYER_HPP_INCLUDED

#include <sgec/audio/buffer_fwd.h>
#include <sgec/audio/file_fwd.h>
#include <sgec/audio/player_fwd.h>
#include <sge/audio/player_fwd.hpp>
#include <fcppt/noncopyable.hpp>


struct sgec_audio_player
{
	FCPPT_NONCOPYABLE(
		sgec_audio_player
	);
public:
	explicit
	sgec_audio_player(
		sge::audio::player &
	);

	~sgec_audio_player();

	sgec_audio_buffer *
	create_buffer(
		sgec_audio_file *
	);
private:
	sge::audio::player &player_;
};

#endif
