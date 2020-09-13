//
// Created by acoulombe on 9/12/20.
//

#ifndef OPENGL_LIGHT_H
#define OPENGL_LIGHT_H

#include <glm/vec3.hpp>

class Light {
public:
    glm::vec3 pos{};
    glm::vec3 color{};

    Light(glm::vec3 pos, glm::vec3 color);

    ~Light() = default;

};

#endif //OPENGL_LIGHT_H
