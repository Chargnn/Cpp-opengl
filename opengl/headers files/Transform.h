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
    Transform(const glm::vec3 &pos = glm::vec3(), const glm::vec3 &rot = glm::vec3(),
              const glm::vec3 &scale = glm::vec3(1.f, 1.f, 1.f)) :
            pos(pos),
            rot(rot),
            scale(scale) {}

    inline glm::mat4 getModel() const {
        glm::mat4 posMatrix = glm::translate(this->pos);
        glm::mat4 rotXMatrix = glm::rotate(this->rot.x, glm::vec3(1, 0, 0));
        glm::mat4 rotYMatrix = glm::rotate(this->rot.y, glm::vec3(0, 1, 0));
        glm::mat4 rotZMatrix = glm::rotate(this->rot.z, glm::vec3(0, 0, 1));
        glm::mat4 scaleMatrix = glm::scale(this->scale);

        glm::mat4 rotMatrix = rotZMatrix * rotYMatrix * rotXMatrix;

        return posMatrix * rotMatrix * scaleMatrix;
    }

    inline glm::vec3 &getPos() { return this->pos; }

    inline glm::vec3 &getRot() { return this->rot; }

    inline glm::vec3 &getScale() { return this->scale; }

    inline glm::vec3 &setPos(glm::vec3 &pos) { this->pos = pos; }

    inline glm::vec3 &setRot(glm::vec3 &rot) { this->rot = rot; }

    inline glm::vec3 &setScale(glm::vec3 &scale) { this->scale = scale; }

private:
    glm::vec3 pos;
    glm::vec3 rot;
    glm::vec3 scale;
};


#endif //OPENGL_TRANSFORM_H
