add_library(shapes ${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB HEAD_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/shapes/*.h)
file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

target_sources(shapes
    PUBLIC
        ${HEAD_FILES}
    PRIVATE
        ${SRC_FILES}
        )



target_include_directories(shapes
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src)