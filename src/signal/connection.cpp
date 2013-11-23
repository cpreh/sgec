#include <sgec/impl/signal/connection.hpp>
#include <sgec/signal/connection.h>


extern "C"
bool
sgec_signal_connection_destroy(
	struct sgec_signal_connection *const _connection
)
try
{
	delete
		_connection;

	return
		true;
}
catch(
	...
)
{
	return
		false;
}
