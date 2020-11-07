#include <sgec/impl/font/object.hpp>
#include <sge/font/object.hpp>
#include <sge/font/object_unique_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


sgec_font_object::sgec_font_object(
	sge::font::object_unique_ptr &&_object
)
:
	object_(
		std::move(
			_object
		)
	)
{
}

sgec_font_object::~sgec_font_object()
= default;

sge::font::object &
sgec_font_object::get()
{
	return
		*object_;
}
