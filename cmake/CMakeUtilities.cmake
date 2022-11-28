function(printConfiguration)
    message("")
    message("    _______________________________________________________________________ ")
    message("   |                                                                       |")
    message("   |                                 gstart                                |")
    message("   |_______________________________________________________________________|")
    message("                                                                            ")
    message("                                  Configuration                             ")
    message("             CMAKE_DEFAULT_BUILD_TYPE:     ${CMAKE_DEFAULT_BUILD_TYPE}      ")
    message("                     CMAKE_BUILD_TYPE:     ${CMAKE_BUILD_TYPE}              ")
    message("                                                                            ")
    message("   _________________________________________________________________________")
    message("")
endfunction(printConfiguration)

macro(findSFML)
message(STATUS "Find SFML")
find_package(SFML PATHS "${CMAKE_SOURCE_DIR}/libs" COMPONENTS graphics window system REQUIRED)
message(STATUS "SFML version: ${SFML_VERSION}")
message(STATUS "SFML incl dir: ${SFML_PATH}")
endmacro(findSFML)

macro(findGtest)
message(STATUS "Find GTest")
add_subdirectory(${CMAKE_SOURCE_DIR}/libs/gtest)
endmacro(findGtest)

macro(findBoost)
message(STATUS "Find Boost")
find_package(Boost COMPONENTS program_options REQUIRED)
message(STATUS "Boost version: ${Boost_VERSION}")
message(STATUS "Boost found : ${Boost_PROGRAM_OPTIONS_LIBRARY}")
message("boost lib: ${Boost_LIBRARIES}")
message("boost inc: ${Boost_INCLUDE_DIR}")
endmacro(findBoost)

macro(findEigen)
message(STATUS "Find Eigen3")
find_package(Eigen3 REQUIRED)
message(STATUS "Eigen3 version: ${Eigen3_VERSION}")
endmacro(findEigen)

macro(findFMT)
message(STATUS "Find fmt")
add_subdirectory(${CMAKE_SOURCE_DIR}/libs/fmt)
endmacro(findFMT)

macro(findJsonCpp)
message(STATUS "Find JsonCpp")
add_subdirectory(${CMAKE_SOURCE_DIR}/libs/jsoncpp)
endmacro(findJsonCpp)

macro(findPyBind)
message(STATUS "Find PyBind11")
add_subdirectory(${CMAKE_SOURCE_DIR}/libs/pybind11)
message("pybind11_FOUND : ${pybind11_FOUND}")
endmacro(findPyBind)

function(integrateLibs)
findSFML()
findGtest()
findFMT()
findJsonCpp()
findBoost()
findPyBind()
# findEigen() not used for now
endfunction(integrateLibs)

function(buildTests)
enable_testing()
include(GoogleTest)
file(GLOB TEST_FILES ${CMAKE_CURRENT_SOURCE_DIR}/test/Test*)
foreach(test_file ${TEST_FILES})
    get_filename_component(exe_dst_name ${test_file} NAME_WLE)
    message(STATUS "Discovered test: ${exe_dst_name}")
    add_executable(${exe_dst_name} ${test_file})
    target_include_directories(${exe_dst_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
    target_link_libraries(${exe_dst_name} PRIVATE gtest_main sfml-graphics sfml-window sfml-system shapes)
    gtest_discover_tests(${exe_dst_name})
endforeach()
endfunction(buildTests)

function(runCppCheck)
find_program(CMAKE_CXX_CPPCHECK NAMES cppcheck)
if (CMAKE_CXX_CPPCHECK)
    set(CMAKE_CXX_CPPCHECK "${CMAKE_CXX_CPPCHECK} src")
endif()
endfunction(runCppCheck)

function(setCompileOptions)
add_compile_options(
    -std=c++17
    -O3
    -Wall
    -Wextra
    -fpermissive
    -Wpedantic
    -Wshadow 
    -Wconversion 
    -Wunreachable-code
    )
endfunction(setCompileOptions)