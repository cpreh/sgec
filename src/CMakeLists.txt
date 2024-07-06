include(GNUInstallDirs)

fcppt_utils_load_source_files(files.txt SGEC_FILES)

fcppt_utils_append_source_dir_and_make_groups(
  "${SGEC_FILES}" SGEC_FILES_ABS HEADER_ONLY_EXCEPTIONS
  include/sgec/detail/footer.h include/sgec/detail/header.h)

function(add_sgec_library VARIANT)
  if("${VARIANT}" STREQUAL "STATIC")
    set(TARGET_NAME sgec_static)
  else()
    set(TARGET_NAME sgec)
  endif()

  add_library(${TARGET_NAME} ${VARIANT} ${SGEC_FILES_ABS})

  fcppt_utils_set_target_compiler_flags(${TARGET_NAME})

  target_include_directories(
    ${TARGET_NAME}
    PUBLIC ${FCPPT_UTILS_PROJECT_BINARY_DIR}/include
    PRIVATE ${FCPPT_UTILS_PROJECT_SOURCE_DIR}/impl/include)

  target_include_directories(${TARGET_NAME} SYSTEM
                             PUBLIC ${FCPPT_UTILS_PROJECT_SOURCE_DIR}/include)

  target_link_libraries(
    ${TARGET_NAME}
    PRIVATE ${fcppt_core_TARGET}
            ${awl_TARGET}
            ${sgeaudio_TARGET}
            ${sgecore_TARGET}
            ${sgefont_TARGET}
            ${sgefontdraw_TARGET}
            ${sgeimage_TARGET}
            ${sgeimagecolor_TARGET}
            ${sgeinput_TARGET}
            ${sgerenderer_TARGET}
            ${sgesprite_TARGET}
            ${sgesystems_TARGET}
            ${sgetexture_TARGET}
            ${sgeviewport_TARGET}
            ${sgewindow_TARGET})

  install(TARGETS ${TARGET_NAME} DESTINATION "${CMAKE_INSTALL_LIBDIR}")
endfunction()

if(ENABLE_SHARED)
  add_sgec_library(SHARED)
endif()

if(ENABLE_STATIC)
  add_sgec_library(STATIC)
endif()

set(INCLUDE_DIRS ${FCPPT_UTILS_PROJECT_SOURCE_DIR}/include
                 ${FCPPT_UTILS_PROJECT_BINARY_DIR}/include)

install(DIRECTORY ${INCLUDE_DIRS} DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")
