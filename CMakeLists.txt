cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(gstart VERSION 1.0)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/CMakeUtilities.cmake)

message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

printConfiguration()

findSFML()
findGtest()

runCppCheck()

enable_testing()

add_subdirectory(src)