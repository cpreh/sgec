#include <sgec/result.h>
#include <sgec/impl/signal/connection.hpp>
#include <sgec/signal/connection.h>


extern "C"
sgec_result
sgec_signal_connection_destroy(
	struct sgec_signal_connection *const _connection
)
try
{
	delete
		_connection;

	return
		sgec_result_ok;
}
catch(
	...
)
{
	return
		sgec_result_error;
}
