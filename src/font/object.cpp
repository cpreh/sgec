#include <sgec/result.h>
#include <sgec/font/object.h>
#include <sgec/impl/font/object.hpp>


extern "C"
enum sgec_result
sgec_font_object_destroy(
	struct sgec_font_object *const _font
)
try
{
	delete
		_font;

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
