#!/bin/sh

set -e -u

update_cmake.sh \
	files.txt \
	src \
	impl \
	include
