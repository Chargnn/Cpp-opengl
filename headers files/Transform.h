//
// Created by acoulombe on 9/9/20.
//

#ifndef OPENGL_TRANSFORM_H
#define OPENGL_TRANSFORM_H

#define GLM_ENABLE_EXPERIMENTAL

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Transform {
public:
    glm::vec3 pos;
    glm::vec3 rot;
    glm::vec3 scale;

    Transform(const glm::vec3 &pos = glm::vec3(), const glm::vec3 &rot = glm::vec3(), const glm::vec3 &scale = glm::vec3(1)) : pos(pos), rot(rot), scale(scale) {}

    inline glm::mat4 getModel() const {
        glm::mat4 posMatrix = glm::translate(this->pos);
        glm::mat4 rotXMatrix = glm::rotate(this->rot.x, glm::vec3(1, 0, 0));
        glm::mat4 rotYMatrix = glm::rotate(this->rot.y, glm::vec3(0, 1, 0));
        glm::mat4 rotZMatrix = glm::rotate(this->rot.z, glm::vec3(0, 0, 1));
        glm::mat4 scaleMatrix = glm::scale(this->scale);

        glm::mat4 rotMatrix = rotZMatrix * rotYMatrix * rotXMatrix;

        return posMatrix * rotMatrix * scaleMatrix;
    }
};


#endif //OPENGL_TRANSFORM_H
