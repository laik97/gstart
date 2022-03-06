add_executable(gstartMain main.cpp)

add_subdirectory(gstart)
add_subdirectory(shapes)
add_subdirectory(config)

target_link_libraries(gstartMain 
    PUBLIC 
    gstart)

target_compile_features(gstartMain PRIVATE
    cxx_constexpr)

target_compile_options(gstartMain 
    PRIVATE
    -std=c++1z
    -Wall
    -Wextra
    -fpermissive)