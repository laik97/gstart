# COMMON SETUP OF CMAKE FOR INTERNAL LIBS
add_library(gstart ${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB HEAD_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/config/*.h)
file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

target_sources(gstart
    PUBLIC
        ${HEAD_FILES}
    PRIVATE
        ${SRC_FILES}
        )

target_include_directories(gstart
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(gstart 
    PUBLIC
    config
    shapes
    SFML::Graphics
    SFML::Window
    )
