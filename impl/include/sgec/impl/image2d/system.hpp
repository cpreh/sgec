#ifndef SGEC_IMPL_IMAGE2D_SYSTEM_HPP_INCLUDED
#define SGEC_IMPL_IMAGE2D_SYSTEM_HPP_INCLUDED

#include <sgec/image2d/system_fwd.h>
#include <sge/image2d/system_fwd.hpp>
#include <sge/image2d/system_ref.hpp>
#include <fcppt/nonmovable.hpp>


struct sgec_image2d_system
{
	FCPPT_NONMOVABLE(
		sgec_image2d_system
	);
public:
	explicit
	sgec_image2d_system(
		sge::image2d::system_ref
	);

	~sgec_image2d_system(); // NOLINT(performance-trivially-destructible)

	[[nodiscard]]
	sge::image2d::system &
	get();
private:
	sge::image2d::system_ref const system_;
};

#endif
