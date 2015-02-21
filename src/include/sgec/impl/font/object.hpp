#ifndef SGEC_IMPL_FONT_OBJECT_HPP_INCLUDED
#define SGEC_IMPL_FONT_OBJECT_HPP_INCLUDED

#include <sgec/font/object_fwd.h>
#include <sge/font/object_fwd.hpp>
#include <sge/font/object_unique_ptr.hpp>
#include <fcppt/noncopyable.hpp>


struct sgec_font_object
{
	FCPPT_NONCOPYABLE(
		sgec_font_object
	);
public:
	explicit
	sgec_font_object(
		sge::font::object_unique_ptr &&
	);

	~sgec_font_object();

	sge::font::object &
	get();
private:
	sge::font::object_unique_ptr const object_;
};

#endif
