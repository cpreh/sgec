cmake_minimum_required(
	VERSION
	2.8.12
)

project(
	sgec
)

find_package(
	fcppt
	REQUIRED
)

# mizuiro uses too many default arguments
set(
	FCPPT_UTILS_CLANG_TIDY_ADDITIONAL_CHECKS
	"-fuchsia-default-arguments-calls"
	"-fuchsia-default-arguments-declarations"
)

include(
	FcpptCMakeUtils
)

include(
	FcpptSymbol
)

find_package(
	Metal
	REQUIRED
)

find_package(
	awl
	REQUIRED
)

# FIXME
find_package(
	mizuiro
	REQUIRED
)

set(
	NEEDED_SGE_COMPONENTS
	audio
	core
	font
	fontdraw
	image
	imagecolor
	input
	renderer
	sprite
	systems
	texture
	viewport
	window
)

find_package(
	sge REQUIRED
	COMPONENTS
	"${NEEDED_SGE_COMPONENTS}"
)

fcppt_generate_symbol_header(
	STATIC_LINK_FLAG
		"SGEC_STATIC_LINK"
	EXPORTS_NAME
		"sgec"
	SYMBOL_NAME
		"SGEC_DETAIL"
	IS_C
		TRUE
)

option(
	ENABLE_STATIC
	"BUild a static library"
	OFF
)

option(
	ENABLE_SHARED
	"BUild a static library"
	ON
)

add_subdirectory(
	src
)

option(
	ENABLE_EXAMPLES
	"Build the examples"
	ON
)

if(
	ENABLE_EXAMPLES
)
	add_subdirectory(
		examples
	)
endif()
