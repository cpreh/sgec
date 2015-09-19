#include <sgec/font/object.h>
#include <sgec/font/system.h>
#include <sgec/font/draw/simple.h>
#include <sgec/image/color/make_rgba.h>
#include <sgec/input/key/code.h>
#include <sgec/input/key/state.h>
#include <sgec/input/keyboard/device.h>
#include <sgec/renderer/context/ffp.h>
#include <sgec/renderer/device/ffp.h>
#include <sgec/signal/connection.h>
#include <sgec/systems/cursor_option.h>
#include <sgec/systems/instance.h>
#include <sgec/window/system.h>
#include <sgec/window/system_poll_result.h>
#include <fcppt/config/external_begin.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcppt/config/external_end.h>


static
void
key_callback(
	enum sgec_input_key_code const _code,
	enum sgec_input_key_state const _state,
	void *_userdata
)
{
	(void)_state;

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
			"sgec font test",
			640u,
			480u,
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

	struct sgec_font_object *font =
		sgec_font_system_create_font(
			sgec_systems_instance_font_system(
				instance
			),
			NULL,
			-1
		);

	if(
		font
		==
		NULL
	)
	{
		exit_code =
			EXIT_FAILURE;

		goto cleanup_signal;
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

		// May fail, ignore
		sgec_font_draw_simple(
			device,
			context,
			font,
			L"TEST123",
			100,
			200,
			sgec_image_color_make_rgba(
				255,
				255,
				255,
				255
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

	sgec_font_object_destroy(
		font
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
