//
// Created by acoulombe on 9/9/20.
//

#ifndef OPENGL_RENDERER_H
#define OPENGL_RENDERER_H


#include <GL/glew.h>
#include "Mesh.h"
#include "Shader.h"
#include "Entity.h"

class Renderer {
public:
    std::vector<Entity>* entities;
    Shader* shader;

    void render() const;

    Renderer(Shader* shader, std::vector<Entity>* entities);
};


#endif //OPENGL_RENDERER_H
