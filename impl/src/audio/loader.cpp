#include <sgec/impl/audio/file.hpp>
#include <sgec/impl/audio/loader.hpp>
#include <sge/audio/file.hpp>
#include <sge/audio/file_unique_ptr.hpp>
#include <sge/audio/load.hpp>
#include <sge/audio/loader_ref.hpp>
#include <fcppt/const.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/config/external_begin.hpp>
#include <filesystem>
#include <utility>
#include <fcppt/config/external_end.hpp>

sgec_audio_loader::sgec_audio_loader(sge::audio::loader_ref const _loader) : loader_(_loader) {}

sgec_audio_loader::~sgec_audio_loader() = default;

sgec_audio_file *sgec_audio_loader::load(char const *const _path)
{
  return fcppt::optional::maybe(
      sge::audio::load(
          loader_,
          std::filesystem::path( // NOLINT(fuchsia-default-arguments-calls)
              _path)),
      fcppt::const_<sgec_audio_file *>(nullptr),
      [](sge::audio::file_unique_ptr &&_file)
      {
        return // NOLINT(cppcoreguidelines-owning-memory)
            new sgec_audio_file(std::move(_file));
      });
}
