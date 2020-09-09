//
// Created by acoulombe on 9/9/20.
//

#ifndef OPENGL_CAMERA_H
#define OPENGL_CAMERA_H

#define GLM_ENABLE_EXPERIMENTAL

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Camera {
public:
    Camera(const glm::vec3 &pos, float fov, float aspect, float zNear, float zFar) {
        this->perspective = glm::perspective(fov, aspect, zNear, zFar);
        this->pos = pos;
        this->forward = glm::vec3(0, 0, 1);
        this->up = glm::vec3(0, 1, 0);
    }

    inline glm::mat4 getViewProjection() const {
        return this->perspective * glm::lookAt(this->pos, this->pos + this->forward, this->up);
    }

    glm::mat4 perspective;
    glm::vec3 pos;
    glm::vec3 forward;
    glm::vec3 up;
};

#endif //OPENGL_CAMERA_H
