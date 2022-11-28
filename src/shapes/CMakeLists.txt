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

target_link_libraries(gstart 
    PUBLIC
    sfml-graphics
    sfml-window
    sfml-system
    )

# buildTests()

############################
### Worker python module ###
############################
add_library(WorkerPy MODULE ${CMAKE_CURRENT_SOURCE_DIR}/WorkerPy.cpp)
target_compile_options(WorkerPy PRIVATE -O3)
target_link_libraries(WorkerPy 
    PUBLIC 
    pybind11::module 
    pybind11::lto 
    pybind11::windows_extras 
    sfml-graphics
    shapes
    )
pybind11_extension(WorkerPy)