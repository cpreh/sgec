#ifndef SGEC_SYSTEMS_INSTANCE_H_INCLUDED
#define SGEC_SYSTEMS_INSTANCE_H_INCLUDED

#include <sgec/symbol.hpp>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>
#include <sgec/renderer/device/ffp_fwd.h>
#include <sgec/systems/instance_fwd.h>
#include <fcppt/config/external_begin.hpp>
#include <stdbool.h>
#include <fcppt/config/external_end.hpp>


SGEC_DETAIL_HEADER

SGEC_SYMBOL
struct sgec_systems_instance *
sgec_systems_instance_create(
	char const *window_name,
	unsigned initial_window_w,
	unsigned initial_window_h
);

SGEC_SYMBOL
bool
sgec_systems_instance_destroy(
	struct sgec_systems_instance *
);

SGEC_SYMBOL
struct sgec_renderer_device_ffp *
sgec_systems_instance_renderer(
	struct sgec_systems_instance *
);

SGEC_DETAIL_FOOTER

#endif
