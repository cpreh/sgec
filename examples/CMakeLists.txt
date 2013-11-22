remove_definitions(
	-std=c++11
)

add_definitions(
	-std=c99
)

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

add_executable(
	example_system
	system.c
)

target_link_libraries(
	example_system
	${SGEC_TARGET}
)
