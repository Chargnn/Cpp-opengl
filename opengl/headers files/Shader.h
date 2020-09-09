//
// Created by acoulombe on 9/8/20.
//

#ifndef OPENGL_SHADER_H
#define OPENGL_SHADER_H

#include <string>
#include <GL/glew.h>
#include "Transform.h"
#include "Camera.h"

class Shader {
public:
    void loadShader(const std::string &path, GLenum shaderType);

    void update(const Camera& camera);

    void bindProgram() const;

    void unbindProgram() const;

    ~Shader();

    enum
    {
        TRANSFORM_U,
        PROJECTION_U,
        NUM_UNIFORMS
    };

    GLuint programID;
    GLuint uniforms[NUM_UNIFORMS];
};


#endif //OPENGL_SHADER_H
