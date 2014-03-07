#include <sgec/impl/image2d/system.hpp>
#include <sgec/impl/input/keyboard/device.hpp>
#include <sgec/impl/renderer/device/ffp.hpp>
#include <sgec/impl/systems/instance.hpp>
#include <sgec/window/size_unit.h>
#include <sgec/impl/window/system.hpp>
#include <sge/image/capabilities_field.hpp>
#include <sge/media/optional_extension_set.hpp>
#include <sge/renderer/display_mode/optional_object.hpp>
#include <sge/renderer/display_mode/parameters.hpp>
#include <sge/renderer/display_mode/vsync.hpp>
#include <sge/renderer/pixel_format/color.hpp>
#include <sge/renderer/pixel_format/depth_stencil.hpp>
#include <sge/renderer/pixel_format/object.hpp>
#include <sge/renderer/pixel_format/optional_multi_samples.hpp>
#include <sge/renderer/pixel_format/srgb.hpp>
#include <sge/systems/cursor_option_field.hpp>
#include <sge/systems/image2d.hpp>
#include <sge/systems/input.hpp>
#include <sge/systems/instance.hpp>
#include <sge/systems/make_list.hpp>
#include <sge/systems/renderer.hpp>
#include <sge/systems/renderer_caps.hpp>
#include <sge/systems/window.hpp>
#include <sge/viewport/fill_on_resize.hpp>
#include <sge/window/dim.hpp>
#include <sge/window/parameters.hpp>
#include <sge/window/title.hpp>
#include <fcppt/from_std_string.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/scoped_ptr_impl.hpp>


sgec_systems_instance::sgec_systems_instance(
	char const *const _window_name,
	sgec_window_size_unit const _initial_window_w,
	sgec_window_size_unit const _initial_window_h
)
:
	impl_(
		sge::systems::make_list
		(
			sge::systems::window(
				sge::window::parameters(
					sge::window::title(
						fcppt::from_std_string(
							_window_name
						)
					),
					sge::window::dim(
						_initial_window_w,
						_initial_window_h
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
				sge::viewport::fill_on_resize()
			)
		)
		(
			sge::systems::input(
				sge::systems::cursor_option_field::null()
			)
		)
		(
			sge::systems::image2d(
				sge::image::capabilities_field::null(),
				sge::media::optional_extension_set()
			)
		)
	),
	renderer_(
		fcppt::make_unique_ptr<
			sgec_renderer_device_ffp
		>(
			impl_.renderer_device_ffp()
		)
	),
	keyboard_(
		fcppt::make_unique_ptr<
			sgec_input_keyboard_device
		>(
			impl_.keyboard_collector()
		)
	),
	window_system_(
		fcppt::make_unique_ptr<
			sgec_window_system
		>(
			impl_.window_system()
		)
	),
	image2d_system_(
		fcppt::make_unique_ptr<
			sgec_image2d_system
		>(
			impl_.image_system()
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
		renderer_.get();
}

sgec_input_keyboard_device *
sgec_systems_instance::keyboard()
{
	return
		keyboard_.get();
}

sgec_window_system *
sgec_systems_instance::window_system()
{
	return
		window_system_.get();
}

sgec_image2d_system *
sgec_systems_instance::image2d_system()
{
	return
		image2d_system_.get();
}
