#ifndef SGEC_SIGNAL_CONNECTION_H_INCLUDED
#define SGEC_SIGNAL_CONNECTION_H_INCLUDED

#include <sgec/result.h>
#include <sgec/detail/symbol.h>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>
#include <sgec/signal/connection_fwd.h>


SGEC_DETAIL_HEADER

SGEC_DETAIL_SYMBOL
enum sgec_result
sgec_signal_connection_destroy(
	struct sgec_signal_connection *
);

SGEC_DETAIL_FOOTER

#endif
