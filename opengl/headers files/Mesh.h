//
// Created by acoulombe on 9/9/20.
//

#ifndef OPENGL_MESH_H
#define OPENGL_MESH_H


#include <glm/common.hpp>
#include <vector>
#include <GL/glew.h>

class Mesh {
public:
    std::vector<glm::vec3> vertices;
    std::vector<GLuint> indices;
    glm::vec3* normals;
    glm::vec3* uvs;
    unsigned int numVertices;

    GLuint vaoID = 0;
    GLuint vboIDs[1];
    GLuint eboID = 0;

    Mesh();
    void init();

    unsigned int numIndices;

    ~Mesh();
};


#endif //OPENGL_MESH_H
