if(
	ENABLE_STATIC
)
	set(
		SGEC_TARGET
		sgec_static
	)
endif()

if(
	ENABLE_SHARED
)
	set(
		SGEC_TARGET
		sgec
	)
endif()

function(
	add_sgec_example
	EXAMPLE_NAME
)
	set(
		FULL_NAME
		sgec_example_${EXAMPLE_NAME}
	)

	add_executable(
		${FULL_NAME}
		${EXAMPLE_NAME}.c
	)

	# TODO: Add more warnings
	target_compile_options(
		${FULL_NAME}
		PRIVATE
		"-std=c99"
		"-Wall"
		"-Wextra"
	)

	target_link_libraries(
		${FULL_NAME}
		${SGEC_TARGET}
	)
endfunction()

add_sgec_example(
	font
)

add_sgec_example(
	sprite
)

add_sgec_example(
	system
)
