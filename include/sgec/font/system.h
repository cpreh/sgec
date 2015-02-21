#ifndef SGEC_FONT_SYSTEM_H_INCLUDED
#define SGEC_FONT_SYSTEM_H_INCLUDED

#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>
#include <sgec/detail/symbol.h>
#include <sgec/font/object_fwd.h>
#include <sgec/font/system_fwd.h>


SGEC_DETAIL_HEADER

SGEC_DETAIL_SYMBOL
struct sgec_font_object *
sgec_font_create(
	struct sgec_font_system *
);

SGEC_DETAIL_FOOTER

#endif
