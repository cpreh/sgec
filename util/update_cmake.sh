#!/bin/sh

set -e -u

update_cmake \
	src/CMakeLists.txt \
	SGEC_FILES \
	-e ".*\\..*" \
	src \
	impl \
	include
