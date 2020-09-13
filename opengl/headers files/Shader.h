//
// Created by acoulombe on 9/8/20.
//

#ifndef OPENGL_SHADER_H
#define OPENGL_SHADER_H

#include <string>
#include <vector>
#include <GL/glew.h>
#include "Transform.h"
#include "Camera.h"
#include "Light.h"

class Shader {
public:
    void loadShader(const std::string &path, GLenum shaderType);

    void update(Camera& camera);

    void addLights(std::vector<Light> lights);

    void bindProgram() const;

    void unbindProgram() const;

    ~Shader();
    Shader();

    enum
    {
        TRANSFORM_U,
        VIEW_U,
        PROJECTION_U,

        LIGHTPOSITION_U,
        LIGHTCOLOR_U,

        NUM_UNIFORMS
    };

    GLuint programID;
    GLuint uniforms[NUM_UNIFORMS];
    std::vector<Light> lights;
};


#endif //OPENGL_SHADER_H
