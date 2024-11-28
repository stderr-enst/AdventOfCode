add_executable(aoc23_1 aoc23_1.cpp)
if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
  target_compile_options(aoc23_1 PRIVATE -fprofile-arcs -ftest-coverage)
  target_link_options(aoc23_1 INTERFACE --coverage)
endif()

install(TARGETS aoc23_1 DESTINATION bin)
