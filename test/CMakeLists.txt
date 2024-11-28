# Set up doctest
include(CTest)

# Add lizard as ctest target
find_program(LIZARD_COMMAND NAMES lizard)
if(LIZARD_COMMAND)
  add_test(NAME lizard COMMAND ${LIZARD_COMMAND} "${CMAKE_SOURCE_DIR}/src" "${CMAKE_SOURCE_DIR}/include" "${CMAKE_SOURCE_DIR}/test")
endif()

include(FetchContent)
FetchContent_Declare(
  doctest
  GIT_REPOSITORY https://github.com/doctest/doctest
  GIT_TAG master # or any SHA, Branch or tag like v2.4.9
)
FetchContent_MakeAvailable(doctest)

include(${doctest_SOURCE_DIR}/scripts/cmake/doctest.cmake)

# Include doctest.h as -isystem to silence clang-tidy warnings
get_property(DOCTEST_INCLUDE_DIR TARGET doctest PROPERTY INTERFACE_INCLUDE_DIRECTORIES)
include_directories(SYSTEM ${DOCTEST_INCLUDE_DIR})

# Building tests
add_executable(mydoctest)
target_sources(mydoctest PRIVATE dtest.cpp)
target_link_libraries(mydoctest PRIVATE doctest::doctest)
doctest_discover_tests(mydoctest WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

add_executable(testbla)
target_sources(testbla PRIVATE test_bla.cpp)
target_include_directories(testbla
    PRIVATE
        "${CMAKE_SOURCE_DIR}/src/bla/include"
)
target_link_libraries(testbla PRIVATE doctest::doctest bla)
doctest_discover_tests(testbla WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
