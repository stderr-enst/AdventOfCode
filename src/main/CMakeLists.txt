add_executable(main main.cpp)
target_include_directories(main
    PRIVATE
        "${CMAKE_SOURCE_DIR}/src/bla/include"
)
target_link_libraries(main PRIVATE bla)
if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
  target_compile_options(main PRIVATE -fprofile-arcs -ftest-coverage)
  target_link_options(main INTERFACE --coverage)
endif()

install(TARGETS main DESTINATION bin)
