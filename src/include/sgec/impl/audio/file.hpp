#ifndef SGEC_IMPL_AUDIO_FILE_HPP_INCLUDED
#define SGEC_IMPL_AUDIO_FILE_HPP_INCLUDED

#include <sgec/audio/file_fwd.h>
#include <sge/audio/file_fwd.hpp>
#include <sge/audio/file_unique_ptr.hpp>
#include <fcppt/noncopyable.hpp>


struct sgec_audio_file
{
	FCPPT_NONCOPYABLE(
		sgec_audio_file
	);
public:
	explicit
	sgec_audio_file(
		sge::audio::file_unique_ptr &&
	);

	~sgec_audio_file();

	sge::audio::file &
	get();
private:
	sge::audio::file_unique_ptr const file_;
};

#endif
