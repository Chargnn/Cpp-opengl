//
// Created by acoulombe on 9/12/20.
//

#include "../headers files/Entity.h"

Entity::Entity(Mesh *mesh) {
    this->mesh = mesh;
    this->transform = Transform();
}