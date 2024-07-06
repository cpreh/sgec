cmake_minimum_required(VERSION 3.27.0)

project(sgec)

find_package(fcppt REQUIRED)

# mizuiro uses too many default arguments
list(
  APPEND
  FCPPT_UTILS_CLANG_TIDY_ADDITIONAL_CHECKS
  "-cppcoreguidelines-avoid-const-or-ref-data-members"
  "-fuchsia-default-arguments-calls"
  "-fuchsia-default-arguments-declarations"
  "-misc-misplaced-const")

set(FCPPT_UTILS_CLANG_TIDY_WHITELIST "fcppt" "awl" "mizuiro" "sge" "sgec")

include(FcpptCMakeUtils)

if((CMAKE_COMPILER_IS_GNUCXX OR FCPPT_UTILS_COMPILER_IS_CLANGPP)
   AND FCPPT_UTILS_BUILD_HEADERS)
  list(APPEND FCPPT_UTILS_COMPILE_OPTIONS "-Wno-unused-macros")
endif()

include(FcpptSymbol)

find_package(awl REQUIRED)

# FIXME
find_package(mizuiro REQUIRED)

set(NEEDED_SGE_COMPONENTS
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
    window)

find_package(sge REQUIRED COMPONENTS "${NEEDED_SGE_COMPONENTS}")

fcppt_generate_symbol_header(
  STATIC_LINK_FLAG
  "SGEC_STATIC_LINK"
  EXPORTS_NAME
  "sgec"
  SYMBOL_NAME
  "SGEC_DETAIL"
  IS_C
  TRUE)

option(ENABLE_STATIC "BUild a static library" OFF)

option(ENABLE_SHARED "BUild a static library" ON)

add_subdirectory(src)

option(ENABLE_EXAMPLES "Build the examples" ON)

if(ENABLE_EXAMPLES)
  add_subdirectory(examples)
endif()
