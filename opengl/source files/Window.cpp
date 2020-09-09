//
// Created by acoulombe on 9/8/20.
//

#include <iostream>
#include "../headers files/Window.h"

Window* Window::instance = nullptr;
GLFWwindow* Window::windowID = nullptr;

Window::Window() {


    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    windowID = glfwCreateWindow(640, 480, "Title", NULL, NULL);

    glfwSetFramebufferSizeCallback(windowID, resizeWindowCallback);
    glfwMakeContextCurrent(windowID);

    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK)
    {
        std::cerr << "ERROR INIT GLEW" << std::endl;
    }

    /*glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);*/
}

Window* Window::getInstance() {
    if (instance == nullptr)
    {
        instance = new Window();
    }

    return instance;
}

void Window::resizeWindowCallback(GLFWwindow* window, int fbw, int fbh) {
    glViewport(0, 0, fbw, fbh);
}