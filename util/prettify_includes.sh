#!/bin/bash

if [[ $1 == 'run' ]]; then
	shift
	prettify_includes.py --reserved-prefix sgec --reserved-prefix sge --reserved-prefix majutsu --reserved-prefix awl --reserved-prefix mizuiro --reserved-prefix fcppt  "$@" 2>>/tmp/prettify_errors
else
	find examples src include \( -name '*.hpp' -o -name '*.cpp' \) \
	| xargs $0 run
fi
