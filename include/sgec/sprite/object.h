#ifndef SGEC_SPRITE_OBJECT_H_INCLUDED
#define SGEC_SPRITE_OBJECT_H_INCLUDED

#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>
#include <sgec/sprite/object_fwd.h>
#include <sgec/sprite/unit.h>
#include <sgec/texture/part_fwd.h>


struct sgec_sprite_object
{
	struct sgec_texture_part const *texture;

	sgec_sprite_unit pos_x;

	sgec_sprite_unit pos_y;

	sgec_sprite_unit width;

	sgec_sprite_unit height;
};

#endif
