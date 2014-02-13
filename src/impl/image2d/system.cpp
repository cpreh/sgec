#include <sgec/impl/image2d/system.hpp>
#include <sge/image2d/system_fwd.hpp>


sgec_image2d_system::sgec_image2d_system(
	sge::image2d::system &_system
)
:
	system_(
		_system
	)
{
}

sgec_image2d_system::~sgec_image2d_system()
{
}

sge::image2d::system &
sgec_image2d_system::get()
{
	return
		system_;
}
