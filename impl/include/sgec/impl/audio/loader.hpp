#ifndef SGEC_IMPL_AUDIO_LOADER_HPP_INCLUDED
#define SGEC_IMPL_AUDIO_LOADER_HPP_INCLUDED

#include <sgec/audio/file_fwd.h>
#include <sgec/audio/loader_fwd.h>
#include <sge/audio/loader_ref.hpp>
#include <fcppt/nonmovable.hpp>


struct sgec_audio_loader
{
	FCPPT_NONMOVABLE(
		sgec_audio_loader
	);
public:
	explicit
	sgec_audio_loader(
		sge::audio::loader_ref
	);

	~sgec_audio_loader(); // NOLINT(performance-trivially-destructible)

	[[nodiscard]]
	sgec_audio_file *
	load(
		char const *
	);
private:
	sge::audio::loader_ref const loader_;
};

#endif
