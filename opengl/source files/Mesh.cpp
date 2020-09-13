//
// Created by acoulombe on 9/9/20.
//

#include "../headers files/Mesh.h"
#include "../headers files/OBJLoader.h"

void Mesh::init(){
    objl::Loader Loader;

    Loader.LoadFile("../resource files/fixed_map.obj");

    for(auto const& vertex: Loader.LoadedMeshes[0].Vertices) {
        this->vertices.emplace_back(vertex.Position.X, vertex.Position.Y, vertex.Position.Z);
        this->normals.emplace_back(vertex.Normal.X, vertex.Normal.Y, vertex.Normal.Z);
    }

    this->indices = Loader.LoadedMeshes[0].Indices;

    glCreateVertexArrays(1, &vaoID);
    glBindVertexArray(vaoID);

    glGenBuffers(1,  &vboIDs[0]);
    glBindBuffer(GL_ARRAY_BUFFER, vboIDs[0]);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices.at(0), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glGenBuffers(1,  &vboIDs[1]);
    glBindBuffer(GL_ARRAY_BUFFER, vboIDs[1]);
    glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), &normals.at(0), GL_STATIC_DRAW);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glGenBuffers(1, &eboID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indices.size() * sizeof(indices[0]), &indices.at(0), GL_STATIC_DRAW);




    glBindVertexArray(0);
}

Mesh::~Mesh(){
    glDeleteVertexArrays(1, &vaoID);
}

Mesh::Mesh() {

}

