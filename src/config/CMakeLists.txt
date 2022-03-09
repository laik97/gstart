# COMMON SETUP OF CMAKE FOR INTERNAL LIBS
add_library(config ${CMAKE_CURRENT_SOURCE_DIR}/include)

set_target_properties(config PROPERTIES LINKER_LANGUAGE CXX)

file(GLOB HEAD_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/config/*.h)
file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

target_sources(config
    PUBLIC
        ${HEAD_FILES}
    PRIVATE
        ${SRC_FILES})

target_include_directories(config
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src)
