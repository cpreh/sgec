#ifndef SGEC_FONT_ADDED_H_INCLUDED
#define SGEC_FONT_ADDED_H_INCLUDED

#include <sgec/result.h>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>
#include <sgec/detail/symbol.h>
#include <sgec/font/added_fwd.h>


SGEC_DETAIL_HEADER

SGEC_DETAIL_SYMBOL
enum sgec_result
sgec_font_added_destroy(
	struct sgec_font_added *
);

SGEC_DETAIL_FOOTER

#endif
