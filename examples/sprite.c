#include <sgec/image/color/make_rgba.h>
#include <sgec/input/keyboard/device.h>
#include <sgec/input/keyboard/key_code.h>
#include <sgec/input/keyboard/key_state.h>
#include <sgec/renderer/context/ffp.h>
#include <sgec/renderer/device/ffp.h>
#include <sgec/renderer/texture/create_planar_from_path.h>
#include <sgec/renderer/texture/planar.h>
#include <sgec/signal/connection.h>
#include <sgec/sprite/draw.h>
#include <sgec/sprite/object.h>
#include <sgec/systems/instance.h>
#include <sgec/texture/part.h>
#include <sgec/texture/part_raw.h>
#include <sgec/window/system.h>
#include <sgec/window/system_poll_result.h>
#include <fcppt/config/external_begin.h>
#include <stdlib.h>
#include <fcppt/config/external_end.h>


static
void
key_callback(
	enum sgec_input_keyboard_key_code const _code,
	enum sgec_input_keyboard_key_state const _state,
	void *_userdata
)
{
	(void)_state;

	if(
		_code
		==
		sgec_input_keyboard_key_code_escape
	)
		sgec_window_system_quit(
			(struct sgec_window_system *)_userdata,
			EXIT_SUCCESS
		);
}

int
main()
{
	struct sgec_systems_instance *instance =
		sgec_systems_instance_create(
			"sgec sprite test"
		);

	if(
		instance == NULL
	)
		return
			EXIT_FAILURE;

	struct sgec_renderer_device_ffp *device =
		sgec_systems_instance_renderer(
			instance
		);

	struct sgec_window_system *window_system =
		sgec_systems_instance_window_system(
			instance
		);

	struct sgec_input_keyboard_device *keyboard =
		sgec_systems_instance_keyboard(
			instance
		);

	struct sgec_signal_connection *keyboard_connection =
		sgec_input_keyboard_device_connect_key_callback(
			keyboard,
			key_callback,
			window_system
		);

	int exit_code =
		EXIT_SUCCESS;

	if(
		keyboard_connection
		==
		NULL
	)
	{
		exit_code =
			EXIT_FAILURE;

		goto cleanup_instance;
	}

	struct sgec_renderer_texture_planar *texture =
		sgec_renderer_texture_create_planar_from_path(
			device,
			sgec_systems_instance_image2d_system(
				instance
			),
			// TODO: Add a proper path here
			"media/car.png"
		);
	if(
		texture
		==
		NULL
	)
	{
		exit_code =
			EXIT_FAILURE;

		goto cleanup_signal;
	}

	struct sgec_texture_part *texture_part =
		sgec_texture_part_raw(
			texture
		);

	if(
		texture_part
		==
		NULL
	)
	{
		exit_code =
			EXIT_FAILURE;

		goto cleanup_texture;
	}

	struct sgec_sprite_object my_sprite = {
		texture_part,
		0,
		0,
		100,
		100
	};

	while(
		sgec_window_system_poll(
			window_system
		)
		==
		sgec_window_system_poll_result_running
	)
	{
		struct sgec_renderer_context_ffp *context =
			sgec_renderer_device_ffp_begin_rendering(
				device
			);

		if(
			context
			==
			NULL
		)
			break;

		// May fail, ignore
		sgec_renderer_context_ffp_clear(
			context,
			sgec_image_color_make_rgba(
				0,
				0,
				0,
				0
			)
		);

		sgec_sprite_draw(
			device,
			context,
			&my_sprite,
			1u
		);

		sgec_renderer_device_ffp_end_rendering(
			device,
			context
		);

		sgec_renderer_context_ffp_destroy(
			context
		);
	}

	sgec_texture_part_destroy(
		texture_part
	);

cleanup_texture:
	sgec_renderer_texture_planar_destroy(
		texture
	);

cleanup_signal:
	sgec_signal_connection_destroy(
		keyboard_connection
	);

	if(
		exit_code
		==
		EXIT_SUCCESS
	)
		exit_code =
			sgec_window_system_exit_code(
				window_system
			);

cleanup_instance:
	sgec_systems_instance_destroy(
		instance
	);

	return
		exit_code;
}
