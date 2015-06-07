#include <sgec/result.h>
#include <sgec/impl/renderer/context/ffp.hpp>
#include <sgec/impl/renderer/device/ffp.hpp>
#include <sgec/impl/texture/part.hpp>
#include <sgec/sprite/draw.h>
#include <sgec/sprite/object.h>
#include <sgec/sprite/scalar.h>
#include <sgec/sprite/unit.h>
#include <sgec/window/unit.h>
#include <sge/renderer/screen_size.hpp>
#include <sge/renderer/context/ffp.hpp>
#include <sge/renderer/device/ffp.hpp>
#include <sge/sprite/object.hpp>
#include <sge/sprite/projection_dim.hpp>
#include <sge/sprite/buffers/option.hpp>
#include <sge/sprite/buffers/single.hpp>
#include <sge/sprite/buffers/with_declaration.hpp>
#include <sge/sprite/compare/default.hpp>
#include <sge/sprite/config/choices.hpp>
#include <sge/sprite/config/float_type.hpp>
#include <sge/sprite/config/normal_size.hpp>
#include <sge/sprite/config/pos.hpp>
#include <sge/sprite/config/pos_option.hpp>
#include <sge/sprite/config/texture_coordinates.hpp>
#include <sge/sprite/config/texture_level_count.hpp>
#include <sge/sprite/config/texture_ownership.hpp>
#include <sge/sprite/config/texture_size_option.hpp>
#include <sge/sprite/config/type_choices.hpp>
#include <sge/sprite/config/unit_type.hpp>
#include <sge/sprite/config/with_rotation.hpp>
#include <sge/sprite/config/with_texture.hpp>
#include <sge/sprite/geometry/make_random_access_range.hpp>
#include <sge/sprite/process/default_options.hpp>
#include <sge/sprite/process/with_options.hpp>
#include <sge/sprite/roles/pos.hpp>
#include <sge/sprite/roles/rotation.hpp>
#include <sge/sprite/roles/size.hpp>
#include <sge/sprite/roles/texture0.hpp>
#include <sge/sprite/state/all_choices.hpp>
#include <sge/sprite/state/default_options.hpp>
#include <sge/sprite/state/object.hpp>
#include <sge/sprite/state/parameters.hpp>
#include <sge/texture/const_optional_part_ref.hpp>
#include <sge/window/dim.hpp>
#include <fcppt/algorithm/repeat.hpp>
#include <fcppt/cast/size_fun.hpp>
#include <fcppt/math/dim/structure_cast.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <stddef.h>
#include <vector>
#include <fcppt/config/external_end.hpp>


extern "C"
sgec_result
sgec_sprite_draw(
	struct sgec_renderer_device_ffp *const _render_device,
	struct sgec_renderer_context_ffp *const _render_context,
	sgec_window_unit const _width,
	sgec_window_unit const _height,
	struct sgec_sprite_object const *_sprites,
	size_t const _count
)
try
{
	typedef
	sge::sprite::config::type_choices<
		sge::sprite::config::unit_type<
			sgec_sprite_unit
		>,
		sge::sprite::config::float_type<
			sgec_sprite_scalar
		>
	>
	sprite_type_choices;

	typedef
	sge::sprite::config::choices<
		sprite_type_choices,
		sge::sprite::config::pos<
			sge::sprite::config::pos_option::pos
		>,
		sge::sprite::config::normal_size<
			sge::sprite::config::texture_size_option::never
		>,
		boost::mpl::vector2<
			sge::sprite::config::with_texture<
				sge::sprite::config::texture_level_count<
					1
				>,
				sge::sprite::config::texture_coordinates::automatic,
				sge::sprite::config::texture_ownership::reference
			>,
			sge::sprite::config::with_rotation
		>
	>
	sprite_choices;

	typedef
	sge::sprite::buffers::with_declaration<
		sge::sprite::buffers::single<
			sprite_choices
		>
	>
	sprite_buffers_type;

	typedef
	sge::sprite::object<
		sprite_choices
	>
	sprite_object;

	typedef
	sge::sprite::state::all_choices
	sprite_state_choices;

	typedef
	sge::sprite::state::object<
		sprite_state_choices
	>
	sprite_state_object;

	typedef
	sge::sprite::state::parameters<
		sprite_state_choices
	>
	sprite_state_parameters;

	sprite_state_object sprite_state(
		_render_device->get(),
		sprite_state_parameters()
	);

	sprite_buffers_type sprite_buffers(
		_render_device->get(),
		sge::sprite::buffers::option::dynamic
	);

	typedef
	std::vector<
		sprite_object
	>
	sprite_vector;

	// TODO: Use an algorithm for this
	sprite_vector sprite_objects;

	sprite_objects.reserve(
		_count
	);

	fcppt::algorithm::repeat(
		_count,
		[
			&sprite_objects,
			&_sprites
		]
		{
			sprite_objects.push_back(
				sprite_object(
					sge::sprite::roles::pos{} =
						sprite_object::vector(
							_sprites->pos_x,
							_sprites->pos_y
						),
					sge::sprite::roles::size{} =
						sprite_object::dim(
							_sprites->width,
							_sprites->height
						),
					sge::sprite::roles::texture0{} =
						// TODO: Pointer to optional?
						_sprites->texture
						?
							sge::texture::const_optional_part_ref(
								_sprites->texture->get()
							)
						:
							sge::texture::const_optional_part_ref()
						,
					sge::sprite::roles::rotation{} =
						_sprites->rotation
				)
			);

			++_sprites;
		}
	);

	sge::window::dim const projection_dim(
		_width,
		_height
	);

	using compare_sprites
	=
	sge::sprite::compare::default_;

	sge::sprite::process::with_options<
		sge::sprite::process::default_options<
			sprite_choices,
			compare_sprites
		>
	>(
		_render_context->get(),
		sge::sprite::geometry::make_random_access_range(
			sprite_objects
		),
		sprite_buffers,
		compare_sprites(),
		sprite_state,
		projection_dim.content()
		!=
		0u
		?
			sge::sprite::state::default_options<
				sprite_state_choices
			>().fixed_projection(
				sge::sprite::projection_dim(
					fcppt::math::dim::structure_cast<
						sge::renderer::screen_size,
						fcppt::cast::size_fun
					>(
						projection_dim
					)
				)
			)
		:
			sge::sprite::state::default_options<
				sprite_state_choices
			>()
	);

	return
		sgec_result_ok;
}
catch(
	...
)
{
	return
		sgec_result_error;
}
