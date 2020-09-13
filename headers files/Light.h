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
    glm::vec3 attenuation{};

    Light(glm::vec3 pos, glm::vec3 color, glm::vec3 attenuation = glm::vec3(1.0, 0.0, 0.0));

    ~Light() = default;

};

#endif //OPENGL_LIGHT_H
