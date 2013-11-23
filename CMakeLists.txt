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

add_definitions(
	${fcppt_DEFINITIONS}
)

include_directories(
	${fcppt_INCLUDE_DIRS}
)

# Find Mizuiro

find_package(
	mizuiro REQUIRED
)

add_definitions(
	${mizuiro_definitions}
)

include_directories(
	${mizuiro_INCLUDE_DIRS}
)

# Find AWL

find_package(
	awl REQUIRED
)

add_definitions(
	${awl_DEFINITIONS}
)

include_directories(
	${awl_INCLUDE_DIRS}
)

# Find SGE
set(
	NEEDED_SGE_COMPONENTS
	core
	image
	imagecolor
	input
	renderer
	systems
	viewport
	window
)

find_package(
	sge REQUIRED
	COMPONENTS
	"${NEEDED_SGE_COMPONENTS}"
)

add_definitions(
	${sge_DEFINITIONS}
)

include_directories(
	${sge_INCLUDE_DIRS}
)

# Find END

fcppt_generate_symbol_header(
	"SGEC_STATIC_LINK"
	"sgec"
	"SGEC"
	"sgec"
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
