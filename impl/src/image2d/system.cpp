#include <sgec/impl/image2d/system.hpp>
#include <sge/image2d/system_fwd.hpp>
#include <sge/image2d/system_ref.hpp>


sgec_image2d_system::sgec_image2d_system(
	sge::image2d::system_ref const _system
)
:
	system_(
		_system
	)
{
}

sgec_image2d_system::~sgec_image2d_system()
= default;

sge::image2d::system &
sgec_image2d_system::get()
{
	return
		system_.get();
}
