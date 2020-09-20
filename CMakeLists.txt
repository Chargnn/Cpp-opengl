cmake_minimum_required(VERSION 3.17)
project(opengl)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_BUILD_TYPE DEBUG)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(./vendor/glfw ./vendor/glfw/src)
FIND_PACKAGE(OpenGL REQUIRED)

add_executable(opengl "source files/main.cpp" "source files/Window.cpp" "headers files/Window.h" "source files/Shader.cpp" "headers files/Shader.h" "source files/Renderer.cpp" "headers files/Renderer.h" "source files/Mesh.cpp" "headers files/Mesh.h" "headers files/Transform.h" "headers files/Camera.h" "headers files/Entity.h" "source files/Camera.cpp" "headers files/OBJLoader.h" "source files/Light.cpp" "headers files/Light.h" "source files/Entity.cpp")
target_link_libraries(opengl glfw)
target_link_libraries(opengl -lglut -lGLEW -lGL -lGLU)
target_link_libraries(opengl m)