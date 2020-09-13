//
// Created by acoulombe on 9/9/20.
//

#include "../headers files/Mesh.h"
#include "../headers files/OBJLoader.h"

void Mesh::init() {
    objl::Loader loader;

    loader.LoadFile("../resource files/fixed_map.obj");

    for (auto const &vertex: loader.LoadedMeshes[0].Vertices) {
        this->vertices.emplace_back(vertex.Position.X, vertex.Position.Y, vertex.Position.Z);
        this->normals.emplace_back(vertex.Normal.X, vertex.Normal.Y, vertex.Normal.Z);
    }

    this->indices = loader.LoadedMeshes[0].Indices;

    glCreateVertexArrays(1, &vaoID);
    glBindVertexArray(vaoID);

    addToVbo(VBO_POSITION, this->vertices);
    addToVbo(VBO_NORMAL, this->normals);

    glGenBuffers(1, &eboID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indices.size() * sizeof(indices[0]), &indices.at(0), GL_STATIC_DRAW);

    glBindVertexArray(0);
}

void Mesh::addToVbo(int index, std::vector<glm::vec3> data) {
    glGenBuffers(1, &vboIDs[index]);
    glBindBuffer(GL_ARRAY_BUFFER, vboIDs[index]);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(data.at(0)), &data.at(0), GL_STATIC_DRAW);
    glVertexAttribPointer(index, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Mesh::~Mesh() {
    glDeleteVertexArrays(1, &vaoID);
}

Mesh::Mesh() {

}

