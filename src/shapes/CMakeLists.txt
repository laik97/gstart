add_library(shapes ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_sources(shapes
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/shapes/lineShape.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/shapes/workerShape.h
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/lineShape.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/workerShape.cpp
        )

target_include_directories(shapes
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src)