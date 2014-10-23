cmake_minimum_required(
	VERSION 2.8.12
)

project(
	sgec
)

include(
	FcpptCMakeUtils
)

include(
	FcpptSymbol
)

# Find Boost

find_package(
	Boost 1.47.0 REQUIRED
)

include_directories(
	${Boost_INCLUDE_DIRS}
)

link_directories(
	${Boost_LIBRARY_DIRS}
)

# Find Fcppt
find_package(
	fcppt
	REQUIRED
)

# Find AWL

find_package(
	awl REQUIRED
)

# Find SGE
set(
	NEEDED_SGE_COMPONENTS
	core
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

# Find END

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

include_directories(
	${FCPPT_UTILS_PROJECT_SOURCE_DIR}/include
)

include_directories(
	${FCPPT_UTILS_PROJECT_BINARY_DIR}/include
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
