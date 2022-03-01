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
find_package(SFML REQUIRED COMPONENTS System Graphics Window)
endfunction(findSFML)

function(findBoost)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.17 REQUIRED COMPONENTS core)
message(STATUS "Boost version: ${Boost_VERSION}")
endfunction(findBoost)