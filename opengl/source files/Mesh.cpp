//
// Created by acoulombe on 9/9/20.
//

#include "../headers files/Mesh.h"

Mesh::Mesh(Vertex* vertices, GLuint* indices, unsigned int numVertices) {
    this->vertices = vertices;
    this->indices = indices;
    this->numVertices = numVertices;
}

Mesh::~Mesh() {

}
