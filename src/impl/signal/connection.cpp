#include <sgec/impl/signal/connection.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


sgec_signal_connection::sgec_signal_connection(
	fcppt::signal::auto_connection &&_connection
)
:
	connection_(
		std::move(
			_connection
		)
	)
{
}

sgec_signal_connection::~sgec_signal_connection()
{
}
