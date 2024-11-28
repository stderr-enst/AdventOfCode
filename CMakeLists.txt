cmake_minimum_required(VERSION 3.25)

project(
  CPPCMakeTemplate
  VERSION 0.1
  LANGUAGES CXX)

# Define standard and basic build options
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Define target for analysis with CLANG_TIDY
find_program(CLANG_TIDY_COMMAND NAMES clang-tidy)
if(NOT CLANG_TIDY_COMMAND)
  message(ERROR "clang-tidy not found. Skipping corresponding checks.")
else()
  set(CMAKE_CXX_CLANG_TIDY ${CLANG_TIDY_COMMAND} --config-file=${CMAKE_SOURCE_DIR}/.clang-tidy -p=${CMAKE_BINARY_DIR})
endif()

# Enable code coverage in Debug build
if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
  set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${PROJECT_SOURCE_DIR}/cmake")
  include(coverage)
  add_coverage_target()
endif()

# Executables and internal libraries
add_subdirectory(src)

# Tests
enable_testing()
add_subdirectory(test)
