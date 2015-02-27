#ifndef SGEC_IMPL_FONT_SYSTEM_HPP_INCLUDED
#define SGEC_IMPL_FONT_SYSTEM_HPP_INCLUDED

#include <sgec/font/added_fwd.h>
#include <sgec/font/object_fwd.h>
#include <sgec/font/system_fwd.h>
#include <sgec/font/ttf_size.h>
#include <sge/font/system_fwd.hpp>
#include <fcppt/noncopyable.hpp>


struct sgec_font_system
{
	FCPPT_NONCOPYABLE(
		sgec_font_system
	);
public:
	explicit
	sgec_font_system(
		sge::font::system &
	);

	~sgec_font_system();

	sgec_font_object *
	create(
		char const *family,
		sgec_font_ttf_size
	);

	sgec_font_added *
	add(
		char const *path
	);

	sge::font::system &
	get();
private:
	sge::font::system &system_;
};

#endif
