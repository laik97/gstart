
add_library(LevelCreator STATIC)

file(GLOB HEAD_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/LevelCreator/*.h)
file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

target_sources(LevelCreator
    PUBLIC
        ${HEAD_FILES}
    PRIVATE
        ${SRC_FILES}
        )

target_include_directories(LevelCreator
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(LevelCreator
    PUBLIC
    shapes
    sfml-graphics
    sfml-window
    sfml-system
    fmt
    Boost::program_options
    jsoncpp
    )


add_executable(level_creator creator.cpp)
target_link_libraries(level_creator PUBLIC LevelCreator)

############################
### Gstart python module ###
############################
add_library(ResolutionPy MODULE ${CMAKE_CURRENT_SOURCE_DIR}/ResolutionPy.cpp)
target_compile_options(ResolutionPy PRIVATE -O3)
target_link_libraries(ResolutionPy 
    PUBLIC 
    pybind11::module 
    pybind11::lto 
    pybind11::windows_extras 
    LevelCreator
    )
pybind11_extension(ResolutionPy)