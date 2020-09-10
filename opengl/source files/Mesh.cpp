//
// Created by acoulombe on 9/9/20.
//

#include "../headers files/Mesh.h"

Mesh::Mesh(Vertex* vertices, GLuint* indices, unsigned int numVertices, unsigned int numIndices) {
    this->vertices = vertices;
    this->indices = indices;
    this->numVertices = numVertices;
    this->numIndices = numIndices;
}

void Mesh::init(){
    glCreateVertexArrays(1, &vaoID);
    glBindVertexArray(vaoID);

    int vboIndex = (int) sizeof(vboIDs);
    glGenBuffers(1,  &vboIDs[vboIndex]);
    glBindBuffer(GL_ARRAY_BUFFER, vboIDs[vboIndex]);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &eboID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, numIndices * sizeof(indices[0]), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindVertexArray(0);
}

Mesh::~Mesh(){
    glDeleteVertexArrays(1, &vaoID);
}

