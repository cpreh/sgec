#include <sgec/impl/audio/loader.hpp>
#include <sgec/impl/audio/player.hpp>
#include <sgec/impl/font/system.hpp>
#include <sgec/impl/image2d/system.hpp>
#include <sgec/impl/input/keyboard/device.hpp>
#include <sgec/impl/renderer/device/ffp.hpp>
#include <sgec/impl/systems/instance.hpp>
#include <sgec/impl/window/system.hpp>
#include <sgec/window/unit.h>
#include <sge/media/optional_extension_set.hpp>
#include <sge/renderer/display_mode/optional_object.hpp>
#include <sge/renderer/display_mode/parameters.hpp>
#include <sge/renderer/display_mode/vsync.hpp>
#include <sge/renderer/pixel_format/color.hpp>
#include <sge/renderer/pixel_format/depth_stencil.hpp>
#include <sge/renderer/pixel_format/object.hpp>
#include <sge/renderer/pixel_format/optional_multi_samples.hpp>
#include <sge/renderer/pixel_format/srgb.hpp>
#include <sge/systems/audio_loader.hpp>
#include <sge/systems/audio_player_default.hpp>
#include <sge/systems/cursor_option_field.hpp>
#include <sge/systems/font.hpp>
#include <sge/systems/image2d.hpp>
#include <sge/systems/input.hpp>
#include <sge/systems/instance.hpp>
#include <sge/systems/make_list.hpp>
#include <sge/systems/original_window.hpp>
#include <sge/systems/renderer.hpp>
#include <sge/systems/renderer_caps.hpp>
#include <sge/systems/window.hpp>
#include <sge/viewport/fill_on_resize.hpp>
#include <sge/viewport/fractional_aspect.hpp>
#include <sge/viewport/maintain_aspect.hpp>
#include <sge/window/dim.hpp>
#include <sge/window/size_hints.hpp>
#include <sge/window/title.hpp>
#include <fcppt/from_std_string.hpp>
#include <fcppt/make_unique_ptr_fcppt.hpp>
#include <fcppt/unique_ptr_impl.hpp>


sgec_systems_instance::sgec_systems_instance(
	char const *const _window_name,
	sgec_window_unit const _width,
	sgec_window_unit const _height
)
:
	sgec_systems_instance(
		_window_name,
		sge::window::dim(
			_width,
			_height
		)
	)
{
}

sgec_systems_instance::sgec_systems_instance(
	char const *const _window_name,
	sge::window::dim const _dim
)
:
	impl_(
		sge::systems::make_list
		(
			sge::systems::window(
				sge::systems::original_window(
					sge::window::title(
						fcppt::from_std_string(
							_window_name
						)
					)
				).size_hints(
					_dim.content()
					==
					0u
					?
						sge::window::size_hints()
					:
						sge::window::size_hints()
						.minimum_size_hint(
							_dim
						)
				)
			)
		)
		(
			sge::systems::renderer(
				sge::renderer::pixel_format::object(
					sge::renderer::pixel_format::color::depth32,
					sge::renderer::pixel_format::depth_stencil::off,
					sge::renderer::pixel_format::optional_multi_samples(),
					sge::renderer::pixel_format::srgb::no
				),
				sge::renderer::display_mode::parameters(
					sge::renderer::display_mode::vsync::on,
					sge::renderer::display_mode::optional_object()
				),
				_dim.content()
				==
				0u
				?
					sge::viewport::fill_on_resize()
				:
					sge::viewport::maintain_aspect(
						sge::viewport::fractional_aspect(
							_dim.w(),
							_dim.h()
						)
					)
			)
		)
		(
			sge::systems::input(
				sge::systems::cursor_option_field::null()
			)
		)
		(
			sge::systems::image2d(
				sge::media::optional_extension_set()
			)
		)
		(
			sge::systems::audio_loader(
				sge::media::optional_extension_set()
			)
		)
		(
			sge::systems::font()
		)
		(
			sge::systems::audio_player_default()
		)
	),
	renderer_(
		fcppt::make_unique_ptr_fcppt<
			sgec_renderer_device_ffp
		>(
			impl_.renderer_device_ffp()
		)
	),
	keyboard_(
		fcppt::make_unique_ptr_fcppt<
			sgec_input_keyboard_device
		>(
			impl_.keyboard_collector()
		)
	),
	window_system_(
		fcppt::make_unique_ptr_fcppt<
			sgec_window_system
		>(
			impl_.window_system()
		)
	),
	image2d_system_(
		fcppt::make_unique_ptr_fcppt<
			sgec_image2d_system
		>(
			impl_.image_system()
		)
	),
	font_system_(
		fcppt::make_unique_ptr_fcppt<
			sgec_font_system
		>(
			impl_.font_system()
		)
	),
	audio_loader_(
		fcppt::make_unique_ptr_fcppt<
			sgec_audio_loader
		>(
			impl_.audio_loader()
		)
	),
	audio_player_(
		fcppt::make_unique_ptr_fcppt<
			sgec_audio_player
		>(
			impl_.audio_player()
		)
	)
{
}

sgec_systems_instance::~sgec_systems_instance()
{
}

sgec_renderer_device_ffp *
sgec_systems_instance::renderer()
{
	return
		renderer_.get_pointer();
}

sgec_input_keyboard_device *
sgec_systems_instance::keyboard()
{
	return
		keyboard_.get_pointer();
}

sgec_window_system *
sgec_systems_instance::window_system()
{
	return
		window_system_.get_pointer();
}

sgec_image2d_system *
sgec_systems_instance::image2d_system()
{
	return
		image2d_system_.get_pointer();
}

sgec_font_system *
sgec_systems_instance::font_system()
{
	return
		font_system_.get_pointer();
}

sgec_audio_loader *
sgec_systems_instance::audio_loader()
{
	return
		audio_loader_.get_pointer();
}

sgec_audio_player *
sgec_systems_instance::audio_player()
{
	return
		audio_player_.get_pointer();
}
