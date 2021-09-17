if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  if(NOT DEFINED IN_SOURCE_BUILD)
    message(FATAL_ERROR
        "In-source build aren't allowed. Please, remove \"CMakeCache.txt\" and \"CMakeFiles/\" directory."
        "\n Or define IN_SOURCE_BUILD to force this option (not recommended!)"
    )
  endif()
endif()

cmake_minimum_required(VERSION 3.17)
project(2nd_course)

set(CMAKE_CXX_STANDARD 14)

include_directories(headers)

add_compile_options(
  "-Wall;-Wextra;-O2"
  "$<$<CONFIG:DEBUG>:-O0;-g3;-ggdb;-Werror>"
)

add_library(Subvector SHARED source/Subvector.cpp)

add_executable(main main.cpp)

target_link_libraries(main Subvector)
