add_executable(gstartMain gstart.cpp)

add_subdirectory(gstart)

target_link_libraries(gstartMain 
    PUBLIC 
    SFML::System
    SFML::Graphics
    SFML::Window
    gstart)

target_compile_features(gstartMain PRIVATE
    cxx_constexpr
    cxx_variadic_templates)