# COMMON SETUP OF CMAKE FOR INTERNAL LIBS
add_library(config ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_sources(config
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/config/globalConfig.h
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/globalConfig.cpp)

target_include_directories(config
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src)


target_compile_options(config
    PRIVATE
    -std=c++2a)