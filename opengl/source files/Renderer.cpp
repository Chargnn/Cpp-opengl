//
// Created by acoulombe on 9/9/20.
//

#include <iostream>
#include "../headers files/Renderer.h"

void Renderer::render() {
    for(Entity entity : *entities){
        glBindVertexArray(entity.mesh.vaoID);
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glUniformMatrix4fv(shader->uniforms[shader->TRANSFORM_U], 1, GL_FALSE, &entity.transform.getModel()[0][0]);

        //glDrawArrays(GL_TRIANGLES, 0, entity.mesh.vertices.size());
        glDrawElements(GL_TRIANGLES, entity.mesh.vertices.size(), GL_UNSIGNED_INT, 0);

        glDisableVertexAttribArray(1);
        glDisableVertexAttribArray(0);
        glBindVertexArray(0);
    }
}

Renderer::Renderer(Shader* shader, std::vector<Entity>* entities){
    this->entities = entities;
    this->shader = shader;
}
