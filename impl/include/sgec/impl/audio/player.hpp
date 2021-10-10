#ifndef SGEC_IMPL_AUDIO_PLAYER_HPP_INCLUDED
#define SGEC_IMPL_AUDIO_PLAYER_HPP_INCLUDED

#include <sgec/audio/buffer_fwd.h>
#include <sgec/audio/file_fwd.h>
#include <sgec/audio/player_fwd.h>
#include <sge/audio/player_fwd.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/reference_impl.hpp>

struct sgec_audio_player
{
  FCPPT_NONMOVABLE(sgec_audio_player);

public:
  explicit sgec_audio_player(fcppt::reference<sge::audio::player>);

  ~sgec_audio_player(); // NOLINT(performance-trivially-destructible)

  [[nodiscard]] sgec_audio_buffer *create_buffer(sgec_audio_file *);

private:
  fcppt::reference<sge::audio::player> const player_;
};

#endif
