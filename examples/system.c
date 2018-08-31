#include <sgec/image/color/make_rgba.h>
#include <sgec/input/key/code.h>
#include <sgec/input/key/state.h>
#include <sgec/input/keyboard/key_event.h>
#include <sgec/renderer/context/ffp.h>
#include <sgec/renderer/device/ffp.h>
#include <sgec/systems/cursor_option.h>
#include <sgec/systems/instance.h>
#include <sgec/window/event.h>
#include <sgec/window/event_result.h>
#include <sgec/window/event_type.h>
#include <sgec/window/free_event.h>
#include <sgec/window/system.h>
#include <fcppt/config/external_begin.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcppt/config/external_end.h>


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
		instance
		==
		NULL
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

	struct sgec_window_event next_event;

	while(
		sgec_window_system_next_event(
			window_system,
			&next_event
		)
		==
		sgec_window_event_result_running
	)
	{
		if(
			next_event.type
			==
			sgec_window_event_type_render
		)
		{
			struct sgec_renderer_context_ffp *context =
				sgec_renderer_device_ffp_begin_rendering(
					device
				);

			if(
				context
				!=
				NULL
			)
			{
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
		}
		else if(
			next_event.type
			==
			sgec_window_event_type_keyboard_key
		)
		{
			struct sgec_input_keyboard_key_event const key_event =
				next_event.keyboard_key;

			printf(
				"key: %d, id: %d, pressed: %d\n",
				(int)key_event.key_code,
				(int)key_event.key_id,
				(int)key_event.key_state
			);

			if(
				key_event.key_state
				==
				sgec_input_key_state_pressed
				&&
				key_event.key_code
				==
				sgec_input_key_code_escape
			)
				sgec_window_system_quit(
					window_system,
					EXIT_SUCCESS
				);
		}

		sgec_window_free_event(
			&next_event
		);
	}

	int const exit_code =
		sgec_window_system_exit_code(
			window_system
		);

	sgec_systems_instance_destroy(
		instance
	);

	return
		exit_code;
}
