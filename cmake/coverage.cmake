function(add_coverage_target)
    find_program(GCOV gcov)
    if (NOT GCOV)
        message(WARNING "program gcov not found")
    endif()

    find_program(LCOV lcov)
    if (NOT LCOV)
        message(WARNING "program lcov not found")
    endif()

    find_program(GENHTML genhtml)
    if (NOT GENHTML)
        message(WARNING "program genhtml not found")
    endif()

    if (LCOV AND GCOV AND GENHTML)
        set(covname cov.info)
        add_custom_target(cov DEPENDS ${covname})
        add_custom_command(
            OUTPUT  ${covname}
            COMMAND ${LCOV} -c -o ${covname} -d ${CMAKE_BINARY_DIR} -b ${CMAKE_BINARY_DIR} --gcov-tool ${GCOV}
            COMMAND ${LCOV} -r ${covname} -o ${covname} --ignore-errors unused '*/test/*' '*/_deps/*' '/usr/*'
            COMMAND ${LCOV} -l ${covname}
            COMMAND ${GENHTML} ${covname} --demangle-cpp -output coverage
            COMMAND ${LCOV} -l ${covname} 2>/dev/null | grep Total | sed 's/|//g' | sed 's/Total://g' | awk '{print $1}' | sed s/%//g > coverage/total
        )
        set_directory_properties(PROPERTIES
            ADDITIONAL_CLEAN_FILES ${covname}
        )
    else()
        message(WARNING "unable to add target `cov`: missing coverage tools")
    endif()
endfunction()
