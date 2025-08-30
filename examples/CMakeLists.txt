if(ENABLE_STATIC)
  set(SGEC_TARGET sgec_static)
endif()

if(ENABLE_SHARED)
  set(SGEC_TARGET sgec)
endif()

function(add_sgec_example EXAMPLE_NAME)
  set(FULL_NAME sgec_example_${EXAMPLE_NAME})

  add_executable(${FULL_NAME} ${EXAMPLE_NAME}.c)

  fcppt_utils_set_target_compiler_flags(
    ${FULL_NAME}
    IS_C
    ADDITIONAL_FLAGS
    "-Wall" "-Wextra")

  target_link_libraries(${FULL_NAME} PRIVATE ${SGEC_TARGET}
                                             fcppt_core_interface)
endfunction()

add_sgec_example(font)

add_sgec_example(sprite)

add_sgec_example(system)
