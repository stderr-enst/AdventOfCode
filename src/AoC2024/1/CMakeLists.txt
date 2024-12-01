add_library(aoc24_1 aoc24_1.h aoc24_1.cpp)

add_executable(aoc24_1_main main.cpp)
target_include_directories(aoc24_1_main
  PRIVATE
    aoc24_1.h
)
target_link_libraries(aoc24_1_main
  PRIVATE
    aoc24_1
)
if("${COMPILE_WITH_COVERAGE}")
  append_coverage_compiler_flags_to_target(aoc24_1)
  append_coverage_compiler_flags_to_target(aoc24_1_main)
endif()

install(TARGETS aoc24_1_main DESTINATION bin)
