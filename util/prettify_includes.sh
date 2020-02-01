#!/usr/bin/env bash

LIBS=(--library sgec --library sge --library awl --library mizuiro --library fcppt)
DIRS=(examples src include)

prettify_includes "${LIBS[@]}" "${DIRS[@]}"
