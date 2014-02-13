#ifndef SGEC_IMPL_TEXTURE_PART_HPP_INCLUDED
#define SGEC_IMPL_TEXTURE_PART_HPP_INCLUDED

#include <sgec/texture/part_fwd.h>
#include <sge/texture/part_fwd.hpp>
#include <sge/texture/part_unique_ptr.hpp>
#include <sge/texture/part_scoped_ptr.hpp>
#include <fcppt/noncopyable.hpp>


struct sgec_texture_part
{
	FCPPT_NONCOPYABLE(
		sgec_texture_part
	);
public:
	explicit
	sgec_texture_part(
		sge::texture::part_unique_ptr &&
	);

	~sgec_texture_part();

	sge::texture::part const &
	get() const;
private:
	sge::texture::part_scoped_ptr const texture_;
};

#endif
