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
    enum {
        NUM_BUFFERS
    };

    GLuint vaoID = 0;
    GLuint vboIDs[NUM_BUFFERS];
    GLuint eboID = 0;
    Entity* entites;
    Shader* shader;

    void createVao(int index);
    void bindVao() const;

    void createVbo(int index);
    void bindVbo(int vboIndex) const;

    void createEbo(int index);
    void bindEbo() const;

    void render();
    void createRenderModel();

    Renderer(Shader* shader, Entity* entities);
};


#endif //OPENGL_RENDERER_H
