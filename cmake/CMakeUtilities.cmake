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

function(findSFML)
message(STATUS "Find SFML")
find_package(SFML PATHS "${CMAKE_SOURCE_DIR}/libs" COMPONENTS graphics window system REQUIRED)
message(STATUS "SFML version: ${SFML_VERSION}")
endfunction(findSFML)

function(findBoost)
message(STATUS "Find Boost")
find_package(Boost)
message(STATUS "Boost version: ${Boost_VERSION}")
endfunction(findBoost)

function(findEigen)
message(STATUS "Find Eigen3")
find_package(Eigen3 REQUIRED)
message(STATUS "Eigen3 version: ${Eigen3_VERSION}")
endfunction(findEigen)

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

function(addLibs)
add_subdirectory(libs/gtest)
endfunction(addLibs)

function(runCppCheck)
find_program(CMAKE_CXX_CPPCHECK NAMES cppcheck)
if (CMAKE_CXX_CPPCHECK)
list(
    APPEND CMAKE_CXX_CPPCHECK 
        "./src/"
        "--verbose"
)
endif()
endfunction(runCppCheck)
