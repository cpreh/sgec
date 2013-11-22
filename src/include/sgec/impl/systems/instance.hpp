#ifndef SGEC_IMPL_SYSTEMS_INSTANCE_HPP_INCLUDED
#define SGEC_IMPL_SYSTEMS_INSTANCE_HPP_INCLUDED

#include <sge/systems/instance_decl.hpp>
#include <sge/systems/keyboard_collector.hpp>
#include <sge/systems/renderer_caps.hpp>
#include <sge/systems/with_image2d.hpp>
#include <sge/systems/with_input.hpp>
#include <sge/systems/with_renderer.hpp>
#include <sge/systems/with_window.hpp>
#include <sgec/renderer/device/ffp_fwd.h>
#include <sgec/systems/instance_fwd.h>
#include <fcppt/noncopyable.hpp>
#include <fcppt/scoped_ptr_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <fcppt/config/external_end.hpp>


struct sgec_systems_instance
{
	FCPPT_NONCOPYABLE(
		sgec_systems_instance
	);
public:
	sgec_systems_instance(
		char const *const _window_name,
		unsigned const _initial_window_w,
		unsigned const _initial_window_h
	);

	~sgec_systems_instance();

	sgec_renderer_device_ffp *
	renderer();
private:
	typedef
	sge::systems::instance<
		boost::mpl::vector4<
			sge::systems::with_renderer<
				sge::systems::renderer_caps::ffp
			>,
			sge::systems::with_window,
			sge::systems::with_input<
				boost::mpl::vector1<
					sge::systems::keyboard_collector
				>
			>,
			sge::systems::with_image2d
		>
	>
	instance;

	instance impl_;

	typedef
	fcppt::scoped_ptr<
		sgec_renderer_device_ffp
	>
	scoped_renderer_ptr;

	scoped_renderer_ptr const renderer_;
};

#endif
