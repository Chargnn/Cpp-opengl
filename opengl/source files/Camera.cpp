//
// Created by acoulombe on 9/10/20.
//

#include "../headers files/Camera.h"
#include "../headers files/Window.h"

void Camera::updateInput() {
    if (glfwGetKey(Window::windowID, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(Window::windowID, GL_TRUE);
    }

    if(glfwGetKey(Window::windowID, GLFW_KEY_W) == GLFW_PRESS) {
        this->pos.z ++;
    }

    if(glfwGetKey(Window::windowID, GLFW_KEY_S) == GLFW_PRESS) {
        this->pos.z --;
    }
}
