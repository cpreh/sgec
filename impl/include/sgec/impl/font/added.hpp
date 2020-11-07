#ifndef SGEC_IMPL_FONT_ADDED_HPP_INCLUDED
#define SGEC_IMPL_FONT_ADDED_HPP_INCLUDED

#include <sgec/font/added_fwd.h>
#include <sge/font/added_unique_ptr.hpp>
#include <fcppt/nonmovable.hpp>


struct sgec_font_added
{
	FCPPT_NONMOVABLE(
		sgec_font_added
	);
public:
	explicit
	sgec_font_added(
		sge::font::added_unique_ptr &&
	);

	~sgec_font_added();
private:
	sge::font::added_unique_ptr const added_;
};

#endif
