#include <sgec/impl/audio/buffer.hpp>
#include <sgec/impl/audio/sound/base.hpp>
#include <sge/audio/buffer.hpp> // NOLINT(misc-include-cleaner)
#include <sge/audio/buffer_unique_ptr.hpp>
#include <sge/audio/sound/base.hpp> // NOLINT(misc-include-cleaner)
#include <sge/audio/sound/nonpositional_parameters.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

sgec_audio_buffer::sgec_audio_buffer(sge::audio::buffer_unique_ptr &&_buffer)
    : buffer_(std::move(_buffer))
{
}

sgec_audio_buffer::~sgec_audio_buffer() = default;

sgec_audio_sound_base *sgec_audio_buffer::create_nonpositional()
{
  // NOLINTNEXTLINE(cppcoreguidelines-owning-memory)
  return new sgec_audio_sound_base(
      buffer_->create_nonpositional(sge::audio::sound::nonpositional_parameters()));
}
