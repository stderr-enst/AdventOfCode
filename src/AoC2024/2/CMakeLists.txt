add_library(aoc24_2 aoc24_2.h aoc24_2.cpp)

add_executable(aoc24_2_main main.cpp)
target_include_directories(aoc24_2_main
  PRIVATE
    ${CMAKE_SOURCE_DIR}/src/AoC2024_2
)
target_link_libraries(aoc24_2_main
  PRIVATE
    aoc24_2
)
if("${COMPILE_WITH_COVERAGE}")
  append_coverage_compiler_flags_to_target(aoc24_2)
  append_coverage_compiler_flags_to_target(aoc24_2_main)
endif()

install(TARGETS aoc24_2_main DESTINATION bin)
