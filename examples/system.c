#include <sgec/renderer/context/ffp.h>
#include <sgec/renderer/device/ffp.h>
#include <sgec/systems/instance.h>
#include <stdlib.h>


int
main()
{
	struct sgec_systems_instance *instance =
		sgec_systems_instance_create(
			"sgec test",
			1024u,
			768u
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

	struct sgec_renderer_context_ffp *context =
		sgec_renderer_device_ffp_begin_rendering(
			device
		);

	if(
		context == NULL
	)
		return
			EXIT_FAILURE;

	// May fail, ignore
	sgec_renderer_device_ffp_end_rendering(
		device,
		context
	);

	sgec_renderer_context_ffp_destroy(
		context
	);

	sgec_systems_instance_destroy(
		instance
	);

	return
		EXIT_SUCCESS;
}
