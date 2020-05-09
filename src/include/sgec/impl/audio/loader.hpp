#ifndef SGEC_IMPL_AUDIO_LOADER_HPP_INCLUDED
#define SGEC_IMPL_AUDIO_LOADER_HPP_INCLUDED

#include <sgec/audio/file_fwd.h>
#include <sgec/audio/loader_fwd.h>
#include <sge/audio/loader_ref.hpp>
#include <fcppt/noncopyable.hpp>


struct sgec_audio_loader
{
	FCPPT_NONCOPYABLE(
		sgec_audio_loader
	);
public:
	explicit
	sgec_audio_loader(
		sge::audio::loader_ref
	);

	~sgec_audio_loader();

	sgec_audio_file *
	load(
		char const *
	);
private:
	sge::audio::loader_ref const loader_;
};

#endif
