//
// Created by acoulombe on 9/9/20.
//

#include <iostream>
#include "../headers files/Renderer.h"

void Renderer::render() {
    for(Entity entity : *entities){
        glBindVertexArray(entity.mesh.vaoID);
        glEnableVertexAttribArray(0);

        glUniformMatrix4fv(shader->uniforms[shader->TRANSFORM_U], 1, GL_FALSE, &entity.transform.getModel()[0][0]);

        glDrawElements(GL_TRIANGLES, entity.mesh.numVertices, GL_UNSIGNED_INT, 0);

        glDisableVertexAttribArray(0);
        glBindVertexArray(0);
    }
}

Renderer::Renderer(Shader* shader, std::vector<Entity>* entities){
    this->entities = entities;
    this->shader = shader;
}
