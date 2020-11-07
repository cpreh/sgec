#ifndef SGEC_IMPL_IMAGE2D_SYSTEM_HPP_INCLUDED
#define SGEC_IMPL_IMAGE2D_SYSTEM_HPP_INCLUDED

#include <sgec/image2d/system_fwd.h>
#include <sge/image2d/system_fwd.hpp>
#include <fcppt/noncopyable.hpp>


struct sgec_image2d_system
{
	FCPPT_NONCOPYABLE(
		sgec_image2d_system
	);
public:
	explicit
	sgec_image2d_system(
		sge::image2d::system &
	);

	~sgec_image2d_system();

	sge::image2d::system &
	get();
private:
	sge::image2d::system &system_;
};

#endif
