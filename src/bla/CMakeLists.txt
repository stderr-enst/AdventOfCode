# Library
add_library(bla)
target_sources(bla
  PRIVATE
    bla.cpp
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
    FILES
      include/bla.h
)

# Link library with another library
#find_library(BLUB_LIB blub)
#target_link_libraries(bla PUBLIC ${BLUB_LIB})
#target_compile_definitions(bla PUBLIC ${USE_BLUB})
target_include_directories(bla PUBLIC ${CMAKE_CURRENT_LIST_DIR})
if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
  target_compile_options(bla PRIVATE -fprofile-arcs -ftest-coverage)
  target_link_options(bla INTERFACE --coverage)
endif()
