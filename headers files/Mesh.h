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
    std::vector<glm::vec3> normals;

    enum {
        VBO_POSITION,
        VBO_NORMAL,

        NUM_VBO
    };

    GLuint vaoID;
    GLuint vboIDs[NUM_VBO];
    GLuint eboID;

    Mesh();

    void init();

    ~Mesh();

private:
    void addToVbo(int index, std::vector<glm::vec3> data);
};


#endif //OPENGL_MESH_H
