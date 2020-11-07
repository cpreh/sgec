#include <sgec/impl/audio/file.hpp>
#include <sge/audio/file.hpp>
#include <sge/audio/file_unique_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


sgec_audio_file::sgec_audio_file(
	sge::audio::file_unique_ptr &&_file
)
:
	file_(
		std::move(
			_file
		)
	)
{
}

sgec_audio_file::~sgec_audio_file()
{
}

sge::audio::file &
sgec_audio_file::get()
{
	return
		*file_;
}
