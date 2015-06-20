#include <sgec/audio/sound/repeat.h>
#include <sgec/impl/audio/sound/from_repeat.hpp>
#include <sge/audio/sound/repeat.hpp>
#include <fcppt/assert/unreachable.hpp>


sge::audio::sound::repeat
sgec::impl::audio::sound::from_repeat(
	sgec_audio_sound_repeat const _repeat
)
{
	switch(
		_repeat
	)
	{
	case sgec_audio_sound_repeat_once:
		return
			sge::audio::sound::repeat::once;
	case sgec_audio_sound_repeat_loop:
		return
			sge::audio::sound::repeat::loop;
	}

	FCPPT_ASSERT_UNREACHABLE;
}
