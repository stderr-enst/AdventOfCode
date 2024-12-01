add_executable(aoc24_1 aoc24_1.cpp)
if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
  target_compile_options(aoc24_1 PRIVATE -fprofile-arcs -ftest-coverage)
  target_link_options(aoc24_1 INTERFACE --coverage)
endif()

install(TARGETS aoc24_1 DESTINATION bin)
