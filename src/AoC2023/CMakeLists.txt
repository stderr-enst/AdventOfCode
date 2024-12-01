add_executable(aoc23_1 aoc23_1.cpp)
if("${COMPILE_WITH_COVERAGE}")
  append_coverage_compiler_flags_to_target(aoc23_1)
endif()

install(TARGETS aoc23_1 DESTINATION bin)
