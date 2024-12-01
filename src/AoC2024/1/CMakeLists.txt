add_executable(aoc24_1 aoc24_1.cpp)
if("${COMPILE_WITH_COVERAGE}")
  append_coverage_compiler_flags_to_target(aoc24_1)
endif()

install(TARGETS aoc24_1 DESTINATION bin)
