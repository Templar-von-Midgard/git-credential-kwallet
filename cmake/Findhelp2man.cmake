
find_program(HELP2MAN NAMES help2man)
mark_as_advanced(HELP2MAN)

if(HELP2MAN)
  execute_process(
    COMMAND ${HELP2MAN} --version
    OUTPUT_VARIABLE help2man_VERSION
  )
  string(REGEX REPLACE [[GNU help2man ([0-9]+\.[0-9]+\.[0-9]+).*]] ${help2man_VERSION} help2man_VERSION)
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(help2man
  REQUIRED_VARS HELP2MAN
  VERSION_VAR help2man_VERSION
)

if(help2man_FOUND)
  add_executable(help2man::help2man IMPORTED)
  set_target_properties(help2man::help2man PROPERTIES
    IMPORTED_LOCATION ${HELP2MAN}
  )

  function(add_man binary_target output)
    add_custom_command(
      OUTPUT "${output}"
      COMMAND ${CMAKE_COMMAND} -E env LC_ALL=C
              $<TARGET_FILE:help2man::help2man> $<TARGET_FILE:${binary_target}> -o "${output}"
      DEPENDS "${binary_target}"
    )
    add_custom_target("${binary_target}.man"
      DEPENDS "${binary_target}" "${output}"
    )
  endfunction()
endif()
