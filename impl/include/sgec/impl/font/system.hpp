#ifndef SGEC_IMPL_FONT_SYSTEM_HPP_INCLUDED
#define SGEC_IMPL_FONT_SYSTEM_HPP_INCLUDED

#include <sgec/font/added_fwd.h>
#include <sgec/font/object_fwd.h>
#include <sgec/font/system_fwd.h>
#include <sgec/font/ttf_size.h>
#include <sge/font/system_fwd.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/reference_impl.hpp>


struct sgec_font_system
{
	FCPPT_NONMOVABLE(
		sgec_font_system
	);
public:
	explicit
	sgec_font_system(
		fcppt::reference<
			sge::font::system
		>
	);

	~sgec_font_system(); // NOLINT(performance-trivially-destructible)

	[[nodiscard]]
	sgec_font_object *
	create(
		char const *family,
		sgec_font_ttf_size
	);

	[[nodiscard]]
	sgec_font_added *
	add(
		char const *path
	);

	[[nodiscard]]
	sge::font::system &
	get();
private:
	fcppt::reference<
		sge::font::system
	> const system_;
};

#endif
