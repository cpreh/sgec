#ifndef SGEC_IMPL_AUDIO_SOUND_BASE_HPP_INCLUDED
#define SGEC_IMPL_AUDIO_SOUND_BASE_HPP_INCLUDED

#include <sgec/audio/sound/base_fwd.h>
#include <sgec/audio/sound/play_status.h>
#include <sgec/audio/sound/repeat.h>
#include <sge/audio/sound/base_unique_ptr.hpp>
#include <fcppt/nonmovable.hpp>


struct sgec_audio_sound_base
{
	FCPPT_NONMOVABLE(
		sgec_audio_sound_base
	);
public:
	explicit
	sgec_audio_sound_base(
		sge::audio::sound::base_unique_ptr &&
	);

	~sgec_audio_sound_base();

	void
	play(
		sgec_audio_sound_repeat
	);

	[[nodiscard]]
	sgec_audio_sound_play_status
	play_status() const;
private:
	sge::audio::sound::base_unique_ptr const sound_;
};

#endif
