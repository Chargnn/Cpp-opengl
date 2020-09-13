//
// Created by acoulombe on 9/8/20.
//

#include <iostream>
#include "../headers files/Window.h"

Window* Window::instance = nullptr;
GLFWwindow* Window::windowID = nullptr;

int Window::width = 640;
int Window::height = 480;

bool Window::lockedCursor = false;

Window::Window() {

    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    windowID = glfwCreateWindow(Window::width, Window::height, "Title", NULL, NULL);

    glfwMakeContextCurrent(windowID);

    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK)
    {
        std::cerr << "ERROR INIT GLEW" << std::endl;
    }

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);
}

Window* Window::getInstance() {
    if (instance == nullptr)
    {
        instance = new Window();
    }

    return instance;
}

void Window::cursorFocus() {
    glfwSetInputMode(Window::windowID, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    Window::lockedCursor = true;
}

void Window::cursorUnfocus() {
    glfwSetInputMode(Window::windowID, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    Window::lockedCursor = false;
}
