#include <sgec/image/color/make_rgba.h>
#include <sgec/input/key/code.h>
#include <sgec/input/key/state.h>
#include <sgec/input/keyboard/device.h>
#include <sgec/input/keyboard/key_id.h>
#include <sgec/renderer/context/ffp.h>
#include <sgec/renderer/device/ffp.h>
#include <sgec/signal/connection.h>
#include <sgec/systems/cursor_option.h>
#include <sgec/systems/instance.h>
#include <sgec/window/system.h>
#include <sgec/window/system_poll_result.h>
#include <fcppt/config/external_begin.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcppt/config/external_end.h>


static
void
key_callback(
	enum sgec_input_key_code const _code,
	enum sgec_input_key_state const _state,
	sgec_input_keyboard_key_id const _id,
	void *_userdata
)
{
	printf(
		"key: %d, id: %d, pressed: %d\n",
		(int)_code,
		(int)_id,
		(int)_state
	);

	if(
		_code
		==
		sgec_input_key_code_escape
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
			"sgec test",
			0u,
			0u,
			sgec_systems_cursor_option_normal
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

		sgec_renderer_device_ffp_end_rendering(
			device,
			context
		);

		sgec_renderer_context_ffp_destroy(
			context
		);
	}

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
