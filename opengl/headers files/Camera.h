//
// Created by acoulombe on 9/9/20.
//

#ifndef OPENGL_CAMERA_H
#define OPENGL_CAMERA_H

#define GLM_ENABLE_EXPERIMENTAL

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <iostream>
#include "Window.h"

class Camera {
public:
    glm::mat4 perspective;
    glm::vec3 pos;
    glm::vec3 front;
    glm::vec3 up;

    float yaw = -90;
    float pitch;

    Camera(const glm::vec3 &pos, float fov, float aspect, float zNear, float zFar);

    void updateInput(float);

    void updatePerspective(float fov, float aspect, float zNear = 0.001f, float zFar = 1000.0f);

    glm::mat4 getView();

    glm::mat4 getProjection();

    ~Camera() = default;
};

#endif //OPENGL_CAMERA_H
