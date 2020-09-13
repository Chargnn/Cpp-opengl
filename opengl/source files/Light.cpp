//
// Created by acoulombe on 9/12/20.
//

#include "../headers files/Light.h"

Light::Light(glm::vec3 pos, glm::vec3 color, glm::vec3 attenuation) {
    this->pos = pos;
    this->color = color;
    this->attenuation = attenuation;
}

