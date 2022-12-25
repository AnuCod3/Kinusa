cmake_minimum_required(VERSION 3.24)
project(Mario)

set(CMAKE_CXX_STANDARD 23)

add_executable(Mario main.cpp Player.cpp Player.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML-2.5.1/include)
target_link_libraries(Mario sfml-system sfml-window sfml-graphics sfml-audio)
