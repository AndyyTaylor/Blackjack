cmake_minimum_required(VERSION 3.7.0)
project(Blackjack)

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
file(COPY data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

include_directories(include)
link_directories(/usr/local/lib)

file(GLOB SOURCES src/*.cpp src/*/*.cpp)

add_executable(main ${SOURCES})
target_link_libraries(main libSDL2.a glew libSDL2_image.a)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
target_link_libraries(main ${OPENGL_LIBRARIES})