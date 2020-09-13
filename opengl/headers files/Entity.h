//
// Created by acoulombe on 9/9/20.
//

#ifndef OPENGL_ENTITY_H
#define OPENGL_ENTITY_H


#include "Mesh.h"
#include "Transform.h"

class Entity {
public:
    Mesh& mesh;
    Transform& transform;

    Entity(Mesh &mesh, Transform& transform);
    ~Entity() = default;
};


#endif //OPENGL_ENTITY_H
