//
// Created by acoulombe on 9/10/20.
//

#include "../headers files/Camera.h"

Camera::Camera(const glm::vec3 &pos, float fov, float aspect, float zNear, float zFar) {
    this->perspective = glm::perspective(fov, aspect, zNear, zFar);
    this->pos = pos;
    this->front = glm::vec3(0.0f, 0.0f, -1.0f);
    this->up = glm::vec3(0.0f, 1.0f, 0.0f);
}

void Camera::updateInput(float delta) {
    if (glfwGetKey(Window::windowID, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        Window::focusCursor(false);
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

void Camera::updateMouseInput(bool &firstMouse, double &lastX, double &lastY, double &xpos, double &ypos){
    if (firstMouse) {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = (float) (xpos - lastX);
    float yoffset = (float) (lastY - ypos);
    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    front = glm::normalize(direction);
}

void Camera::updatePerspective(float fov, float aspect, float zNear, float zFar) {
    this->perspective = glm::perspective(fov, aspect, zNear, zFar);
}

glm::mat4 Camera::getView() const{
    return glm::lookAt(this->pos, this->pos + this->front, this->up);
}

glm::mat4 Camera::getProjection() const{
    return this->perspective;
}
