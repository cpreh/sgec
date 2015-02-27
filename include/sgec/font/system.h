#ifndef SGEC_FONT_SYSTEM_H_INCLUDED
#define SGEC_FONT_SYSTEM_H_INCLUDED

#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>
#include <sgec/detail/symbol.h>
#include <sgec/font/added_fwd.h>
#include <sgec/font/object_fwd.h>
#include <sgec/font/system_fwd.h>
#include <sgec/font/ttf_size.h>


SGEC_DETAIL_HEADER

SGEC_DETAIL_SYMBOL
struct sgec_font_object *
sgec_font_system_create_font(
	struct sgec_font_system *,
	char const *family, /* may be NULL */
	sgec_font_ttf_size /* -1 for default */
);

SGEC_DETAIL_SYMBOL
struct sgec_font_added *
sgec_font_system_add_font(
	struct sgec_font_system *,
	char const *path
);

SGEC_DETAIL_FOOTER

#endif
