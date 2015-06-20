#ifndef SGEC_IMPL_AUDIO_BUFFER_HPP_INCLUDED
#define SGEC_IMPL_AUDIO_BUFFER_HPP_INCLUDED

#include <sgec/audio/buffer_fwd.h>
#include <sgec/audio/sound/base_fwd.h>
#include <sge/audio/buffer_unique_ptr.hpp>
#include <fcppt/noncopyable.hpp>


struct sgec_audio_buffer
{
	FCPPT_NONCOPYABLE(
		sgec_audio_buffer
	);
public:
	explicit
	sgec_audio_buffer(
		sge::audio::buffer_unique_ptr &&
	);

	~sgec_audio_buffer();

	sgec_audio_sound_base *
	create_nonpositional();
private:
	sge::audio::buffer_unique_ptr const buffer_;
};

#endif
