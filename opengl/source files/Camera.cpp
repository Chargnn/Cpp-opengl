//
// Created by acoulombe on 9/10/20.
//

#include "../headers files/Camera.h"

void Camera::updateInput(float delta) {
    if (glfwGetKey(Window::windowID, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        Window::cursorUnfocus();
    }

    if (glfwGetKey(Window::windowID, GLFW_KEY_W) == GLFW_PRESS) {
        this->pos += this->front * delta;
    }

    if (glfwGetKey(Window::windowID, GLFW_KEY_S) == GLFW_PRESS) {
        this->pos -= this->front * delta;
    }

    if (glfwGetKey(Window::windowID, GLFW_KEY_A) == GLFW_PRESS) {
        this->pos -= glm::normalize(glm::cross(this->front, this->up)) * delta;
    }

    if (glfwGetKey(Window::windowID, GLFW_KEY_D) == GLFW_PRESS) {
        this->pos += glm::normalize(glm::cross(this->front, this->up)) * delta;
    }
}

void Camera::updatePerspective(float fov, float aspect, float zNear, float zFar) {
    this->perspective = glm::perspective(fov, aspect, zNear, zFar);
}
