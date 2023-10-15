#include <sgec/impl/font/added.hpp>
#include <sge/font/added.hpp> // NOLINT(misc-include-cleaner)
#include <sge/font/added_unique_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

sgec_font_added::sgec_font_added(sge::font::added_unique_ptr &&_added) : added_(std::move(_added))
{
}

sgec_font_added::~sgec_font_added() = default;
