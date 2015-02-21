#ifndef SGEC_FONT_OBJECT_H_INCLUDED
#define SGEC_FONT_OBJECT_H_INCLUDED

#include <sgec/result.h>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>
#include <sgec/detail/symbol.h>
#include <sgec/font/object_fwd.h>


SGEC_DETAIL_HEADER

SGEC_DETAIL_SYMBOL
enum sgec_result
sgec_font_object_destroy(
	struct sgec_font_object *
);

SGEC_DETAIL_FOOTER

#endif
