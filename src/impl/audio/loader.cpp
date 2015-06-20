#include <sgec/impl/audio/file.hpp>
#include <sgec/impl/audio/loader.hpp>
#include <sge/audio/file.hpp>
#include <sge/audio/file_unique_ptr.hpp>
#include <sge/audio/loader.hpp>
#include <fcppt/const.hpp>
#include <fcppt/maybe.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


sgec_audio_loader::sgec_audio_loader(
	sge::audio::loader &_loader
)
:
	loader_(
		_loader
	)
{
}

sgec_audio_loader::~sgec_audio_loader()
{
}

sgec_audio_file *
sgec_audio_loader::load(
	char const *const _path
)
{
	return
		fcppt::maybe(
			loader_.load(
				boost::filesystem::path(
					_path
				)
			),
			fcppt::const_<
				sgec_audio_file *
			>(
				nullptr
			),
			[](
				sge::audio::file_unique_ptr &&_file
			)
			{
				return
					new
					sgec_audio_file(
						std::move(
							_file
						)
					);
			}
		);
}
