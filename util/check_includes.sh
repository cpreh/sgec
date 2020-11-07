#!/bin/sh

INCLUDE_BINARY="check_includes"

"${INCLUDE_BINARY}" include || exit -1

"${INCLUDE_BINARY}" impl/include || exit -1
