find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(visualizer main_visualizer.cpp)
target_link_libraries(visualizer core sfml-graphics sfml-window sfml-system)
