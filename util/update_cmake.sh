#!/bin/sh

set -e -u

update_cmake \
	src/CMakeLists.txt \
	SGEC_FILES \
	src \
	impl \
	include
