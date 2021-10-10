#include <sgec/audio/buffer_fwd.h>
#include <sgec/audio/file_fwd.h>
#include <sgec/audio/player.h>
#include <sgec/impl/audio/player.hpp>

extern "C" struct sgec_audio_buffer *sgec_audio_player_create_buffer(
    struct sgec_audio_player *const _player, struct sgec_audio_file *const _file)
try
{
  return _player->create_buffer(_file);
}
catch (...)
{
  return nullptr;
}
