//
// Created by acoulombe on 9/9/20.
//

#include <iostream>
#include "../headers files/Renderer.h"

void Renderer::render() {
    glBindVertexArray(vaoID);
    glEnableVertexAttribArray(0);
    //glEnableVertexAttribArray(1);
    //glEnableVertexAttribArray(2);

    glUniformMatrix4fv(shader->uniforms[shader->TRANSFORM_U], 1, GL_FALSE, &entites->transform.getModel()[0][0]);

    glDrawElements(GL_TRIANGLES, entites->mesh.numVertices, GL_UNSIGNED_INT, 0);

    glDisableVertexAttribArray(0);
    //glDisableVertexAttribArray(1);
    //glDisableVertexAttribArray(2);
    glBindVertexArray(0);
}

void Renderer::createVao(int index) {
    glCreateVertexArrays(index, &vaoID);
    bindVao();
}

void Renderer::bindVao() const {
    glBindVertexArray(vaoID);
}

void Renderer::createVbo(int index) {
    int vboIndex = (int) sizeof(vboIDs) - 1;
    glGenBuffers(index,  &vboIDs[vboIndex]);
    bindVbo(vboIndex);
    glBufferData(GL_ARRAY_BUFFER, entites->mesh.numVertices * sizeof(entites->mesh.vertices[0]), entites->mesh.vertices, GL_STATIC_DRAW);
}

void Renderer::bindVbo(int vboIndex) const {
    glBindBuffer(GL_ARRAY_BUFFER, vboIDs[vboIndex]);
}

void Renderer::createEbo(int index) {
    glGenBuffers(index, &eboID);
    bindEbo();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(entites->mesh.indices) * sizeof(entites->mesh.indices[0]), entites->mesh.indices, GL_STATIC_DRAW);
}

void Renderer::bindEbo() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboID);
}

void Renderer::createRenderModel(){
    createVao(1);
    createVbo(1);
    createEbo(1);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    //glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*) offsetof(Vertex, color));
    //glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*) offsetof(Vertex, texCoords));

    glBindVertexArray(0);
}

Renderer::Renderer(Shader* shader, Entity* entites){
    this->entites = entites;
    this->shader = shader;
}
