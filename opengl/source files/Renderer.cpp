//
// Created by acoulombe on 9/9/20.
//

#include <iostream>
#include "../headers files/Renderer.h"

void Renderer::render() {
    glBindVertexArray(entites->mesh.vaoID);
    glEnableVertexAttribArray(0);

    glUniformMatrix4fv(shader->uniforms[shader->TRANSFORM_U], 1, GL_FALSE, &entites->transform.getModel()[0][0]);

    glDrawElements(GL_TRIANGLES, entites->mesh.numVertices, GL_UNSIGNED_INT, 0);

    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
}

Renderer::Renderer(Shader* shader, Entity* entites){
    this->entites = entites;
    this->shader = shader;
}
