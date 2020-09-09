cmake_minimum_required(VERSION 3.17)
project(opengl)

set(CMAKE_CXX_STANDARD 14)

add_executable(opengl "source files/main.cpp" "source files/Window.cpp" "headers files/Window.h" "source files/Shader.cpp" "headers files/Shader.h" "source files/Renderer.cpp" "headers files/Renderer.h" "source files/Mesh.cpp" "headers files/Mesh.h" "headers files/Transform.h" "headers files/Camera.h" "headers files/Entity.h")
target_link_libraries(opengl -lglut -lglfw -lGLEW -lGL -lGLU)
target_link_libraries(opengl m)