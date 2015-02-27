#include <sgec/font/ttf_size.h>
#include <sgec/impl/font/added.hpp>
#include <sgec/impl/font/object.hpp>
#include <sgec/impl/font/system.hpp>
#include <sge/font/added.hpp>
#include <sge/font/object.hpp>
#include <sge/font/parameters.hpp>
#include <sge/font/system.hpp>
#include <fcppt/from_std_string.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


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
sgec_font_system::create(
	char const *const _family,
	sgec_font_ttf_size const _size
)
{
	sge::font::parameters parameters{};

	if(
		_family
	)
		parameters.family(
			fcppt::from_std_string(
				std::string(
					_family
				)
			)
		);

	if(
		_size
		!=
		-1
	)
		parameters.ttf_size(
			fcppt::cast::to_unsigned(
				_size
			)
		);

	return
		new
		sgec_font_object(
			system_.create_font(
				parameters
			)
		);
}

sgec_font_added *
sgec_font_system::add(
	char const *const _path
)
{
	return
		new
		sgec_font_added(
			system_.add_font(
				boost::filesystem::path(
					_path
				)
			)
		);
}

sge::font::system &
sgec_font_system::get()
{
	return
		system_;
}
