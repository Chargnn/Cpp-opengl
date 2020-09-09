//
// Created by acoulombe on 9/9/20.
//

#ifndef OPENGL_MESH_H
#define OPENGL_MESH_H


#include <glm/common.hpp>
#include <vector>
#include <GL/glew.h>

class Vertex
{
public:
    Vertex(const glm::vec3& vec3)
    {
        this->vec3 = vec3;
    }
private:
    glm::vec3 vec3;
};

class Mesh {
public:
    Vertex* vertices;
    GLuint* indices;
    unsigned int numVertices;

    Mesh(Vertex* vertices, GLuint* indices, unsigned int numVertices);
    virtual ~Mesh();
private:
    Mesh(const Mesh& other);
    void operator=(const Mesh& other);
};


#endif //OPENGL_MESH_H
