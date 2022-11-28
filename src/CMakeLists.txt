add_executable(gstartMain main.cpp)

target_compile_features(gstartMain PRIVATE
    cxx_constexpr)

target_compile_options(gstartMain 
    PRIVATE
    -std=c++2a
    -O3
    -Wall
    -Wextra
    -fpermissive
    -pedantic
    -Wshadow 
    -Wconversion 
    -Wunreachable-code
    )

add_subdirectory(gstart)
add_subdirectory(shapes)
add_subdirectory(LevelCreator)

target_link_libraries(gstartMain 
    PUBLIC
    LevelCreator
    gstart
    Boost::program_options)
