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
    Camera(const glm::vec3 &pos, float fov, float aspect, float zNear, float zFar) {
        this->perspective = glm::perspective(fov, aspect, zNear, zFar);
        this->pos = pos;
        this->front = glm::vec3(0.0f, 0.0f, -1.0f);
        this->up = glm::vec3(0.0f, 1.0f, 0.0f);
    }

    glm::mat4 perspective;
    glm::vec3 pos;
    glm::vec3 front;
    glm::vec3 up;

    float yaw = -90.0f;
    float pitch;

    void updateInput(float);
    void updatePerspective(float fov, float aspect, float zNear = 0.001f, float zFar = 1000.0f);

    glm::mat4 getView(){
        return glm::lookAt(this->pos, this->pos + this->front, this->up);
    }

    glm::mat4 getProjection(){
        return this->perspective;
    }
};

#endif //OPENGL_CAMERA_H
