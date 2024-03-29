#include <sgec/audio/sound/repeat.h>
#include <sgec/impl/audio/sound/from_repeat.hpp>
#include <sge/audio/sound/repeat.hpp>
#include <fcppt/enum/make_invalid.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>

sge::audio::sound::repeat
sgec::impl::audio::sound::from_repeat(sgec_audio_sound_repeat const _repeat)
{
  FCPPT_PP_PUSH_WARNING
  FCPPT_PP_DISABLE_GCC_WARNING(-Wswitch-default)
  switch (_repeat)
  {
  case sgec_audio_sound_repeat_once:
    return sge::audio::sound::repeat::once;
  case sgec_audio_sound_repeat_loop:
    return sge::audio::sound::repeat::loop;
  }

  FCPPT_PP_POP_WARNING

  throw fcppt::enum_::make_invalid(_repeat);
}
