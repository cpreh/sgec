#include <sgec/impl/systems/instance.hpp>
#include <sgec/input/keyboard/device_fwd.h>
#include <sgec/renderer/device/ffp_fwd.h>
#include <sgec/systems/instance.h>
#include <sgec/window/system_fwd.h>


extern "C"
struct sgec_systems_instance *
sgec_systems_instance_create(
	char const *const _window_name,
	unsigned const _initial_window_w,
	unsigned const _initial_window_h
)
try
{
	return
		new sgec_systems_instance(
			_window_name,
			_initial_window_w,
			_initial_window_h
		);
}
catch(
	...
)
{
	return
		nullptr;
}

extern "C"
bool
sgec_systems_instance_destroy(
	struct sgec_systems_instance *const _instance
)
try
{
	delete
		_instance;

	return
		true;
}
catch(
	...
)
{
	return
		false;
}

extern "C"
struct sgec_renderer_device_ffp *
sgec_systems_instance_renderer(
	struct sgec_systems_instance *const _instance
)
{
	return
		_instance->renderer();
}

extern "C"
struct sgec_input_keyboard_device *
sgec_systems_instance_keyboard(
	struct sgec_systems_instance *const _instance
)
{
	return
		_instance->keyboard();
}

struct sgec_window_system *
sgec_systems_instance_window_system(
	struct sgec_systems_instance *const _instance
)
{
	return
		_instance->window_system();
}
