# COMMON SETUP OF CMAKE FOR INTERNAL LIBS
add_library(gstart ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_sources(gstart
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/gstart/ConsoleLog.h
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/ConsoleLog.cpp)

target_include_directories(gstart
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src)
