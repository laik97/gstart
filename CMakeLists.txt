cmake_minimum_required(VERSION 3.18)

project(gstart VERSION 1.0)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/CMakeUtilities.cmake)

message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

printConfiguration()

# add the SFML lib (must be preinstalled)
find_package(SFML COMPONENTS System Graphics Window REQUIRED)

add_subdirectory(src)
add_subdirectory(libs)