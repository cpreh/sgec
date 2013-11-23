#ifndef SGEC_SIGNAL_CONNECTION_H_INCLUDED
#define SGEC_SIGNAL_CONNECTION_H_INCLUDED

#include <sgec/symbol.hpp>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>
#include <sgec/signal/connection_fwd.h>
#include <fcppt/config/external_begin.hpp>
#include <stdbool.h>
#include <fcppt/config/external_end.hpp>



SGEC_DETAIL_HEADER

SGEC_SYMBOL
bool
sgec_signal_connection_destroy(
	struct sgec_signal_connection *
);

SGEC_DETAIL_FOOTER

#endif
