#ifndef SGEC_IMPL_SIGNAL_CONNECTION_HPP_INCLUDED
#define SGEC_IMPL_SIGNAL_CONNECTION_HPP_INCLUDED

#include <sgec/signal/connection_fwd.h>
#include <fcppt/noncopyable.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/auto_connection_fwd.hpp>


struct sgec_signal_connection
{
	FCPPT_NONCOPYABLE(
		sgec_signal_connection
	);
public:
	explicit
	sgec_signal_connection(
		fcppt::signal::auto_connection &&
	);

	~sgec_signal_connection();
private:
	fcppt::signal::auto_connection const connection_;
};

#endif
