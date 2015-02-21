#include <sgec/impl/font/object.hpp>
#include <sgec/impl/font/system.hpp>
#include <sge/font/object.hpp>
#include <sge/font/parameters.hpp>
#include <sge/font/system.hpp>


sgec_font_system::sgec_font_system(
	sge::font::system &_system
)
:
	system_(
		_system
	)
{
}

sgec_font_system::~sgec_font_system()
{
}

sgec_font_object *
sgec_font_system::create()
{
	return
		new
		sgec_font_object(
			system_.create_font(
				sge::font::parameters{}
			)
		);
}

sge::font::system &
sgec_font_system::get()
{
	return
		system_;
}
