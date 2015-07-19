#ifndef SGEC_IMPL_SYSTEMS_INSTANCE_HPP_INCLUDED
#define SGEC_IMPL_SYSTEMS_INSTANCE_HPP_INCLUDED

#include <sgec/audio/loader_fwd.h>
#include <sgec/audio/player_fwd.h>
#include <sgec/font/system_fwd.h>
#include <sgec/image2d/system_fwd.h>
#include <sgec/input/cursor/object_fwd.h>
#include <sgec/input/keyboard/device_fwd.h>
#include <sgec/renderer/device/ffp_fwd.h>
#include <sgec/systems/cursor_option.h>
#include <sgec/systems/instance_fwd.h>
#include <sgec/window/system_fwd.h>
#include <sgec/window/unit.h>
#include <sge/systems/cursor_demuxer.hpp>
#include <sge/systems/instance_decl.hpp>
#include <sge/systems/keyboard_collector.hpp>
#include <sge/systems/renderer_caps.hpp>
#include <sge/systems/with_audio_loader.hpp>
#include <sge/systems/with_audio_player.hpp>
#include <sge/systems/with_font.hpp>
#include <sge/systems/with_image2d.hpp>
#include <sge/systems/with_input.hpp>
#include <sge/systems/with_renderer.hpp>
#include <sge/systems/with_window.hpp>
#include <sge/window/dim_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/unique_ptr_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <fcppt/config/external_end.hpp>


struct sgec_systems_instance
{
	FCPPT_NONCOPYABLE(
		sgec_systems_instance
	);
public:
	sgec_systems_instance(
		char const *,
		sgec_window_unit,
		sgec_window_unit,
		sgec_systems_cursor_option
	);

	sgec_systems_instance(
		char const *,
		sge::window::dim,
		sgec_systems_cursor_option
	);

	~sgec_systems_instance();

	sgec_renderer_device_ffp *
	renderer();

	sgec_input_keyboard_device *
	keyboard();

	sgec_input_cursor_object *
	cursor();

	sgec_window_system *
	window_system();

	sgec_image2d_system *
	image2d_system();

	sgec_font_system *
	font_system();

	sgec_audio_loader *
	audio_loader();

	sgec_audio_player *
	audio_player();
private:
	typedef
	sge::systems::instance<
		boost::mpl::vector7<
			sge::systems::with_renderer<
				sge::systems::renderer_caps::ffp
			>,
			sge::systems::with_window,
			sge::systems::with_input<
				boost::mpl::vector2<
					sge::systems::cursor_demuxer,
					sge::systems::keyboard_collector
				>
			>,
			sge::systems::with_image2d,
			sge::systems::with_font,
			sge::systems::with_audio_loader,
			sge::systems::with_audio_player
		>
	>
	instance;

	instance impl_;

	typedef
	fcppt::unique_ptr<
		sgec_renderer_device_ffp
	>
	scoped_renderer_ptr;

	scoped_renderer_ptr const renderer_;

	typedef
	fcppt::unique_ptr<
		sgec_input_keyboard_device
	>
	scoped_keyboard_ptr;

	scoped_keyboard_ptr const keyboard_;

	typedef
	fcppt::unique_ptr<
		sgec_input_cursor_object
	>
	scoped_cursor_ptr;

	scoped_cursor_ptr const cursor_;

	typedef
	fcppt::unique_ptr<
		sgec_window_system
	>
	scoped_window_system_ptr;

	scoped_window_system_ptr const window_system_;

	typedef
	fcppt::unique_ptr<
		sgec_image2d_system
	>
	scoped_image2d_system_ptr;

	scoped_image2d_system_ptr const image2d_system_;

	typedef
	fcppt::unique_ptr<
		sgec_font_system
	>
	scoped_font_system_ptr;

	scoped_font_system_ptr const font_system_;

	typedef
	fcppt::unique_ptr<
		sgec_audio_loader
	>
	scoped_audio_loader_ptr;

	scoped_audio_loader_ptr const audio_loader_;

	typedef
	fcppt::unique_ptr<
		sgec_audio_player
	>
	scoped_audio_player_ptr;

	scoped_audio_player_ptr const audio_player_;
};

#endif
