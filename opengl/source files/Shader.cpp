//
// Created by acoulombe on 9/8/20.
//

#include <string>
#include <fstream>
#include <iostream>
#include "../headers files/Shader.h"

void Shader::loadShader(const std::string &path, GLenum shaderType) {
    char infoLog[1024];
    GLint success;

    std::string temp;
    std::string src;

    std::ifstream file;

    file.open(path);

    if (file.is_open()) {
        while (std::getline(file, temp)) {
            src += temp + "\n";
        }
    }

    file.close();

    GLuint shader = glCreateShader(shaderType);
    const GLchar *shaderSrc = src.c_str();
    glShaderSource(shader, 1, &shaderSrc, nullptr);
    glCompileShader(shader);

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
        std::cerr << "ERROR ON SHADER COMPILE" << std::endl;
        std::cerr << infoLog << std::endl;
    }

    if (programID == 0) {
        programID = glCreateProgram();
    }

    glAttachShader(programID, shader);
    glLinkProgram(programID);

    glGetProgramiv(programID, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shader, 1024, nullptr, infoLog);
        std::cerr << "ERROR ON SHADER LINK" << std::endl;
        std::cerr << infoLog << std::endl;
    }

    uniforms[TRANSFORM_U] = glGetUniformLocation(programID, "transform");
    uniforms[PROJECTION_U] = glGetUniformLocation(programID, "projection");

    unbindProgram();
    glDeleteShader(shader);
}

void Shader::unbindProgram() const {
    glUseProgram(0);
}

void Shader::bindProgram() const {
    glUseProgram(programID);
}

void Shader::update(Camera& camera) {
    glm::mat4 projection = camera.getViewProjection();
    glUniformMatrix4fv(uniforms[PROJECTION_U], 1, GL_FALSE, &projection[0][0]);
}

Shader::~Shader() {
    glDeleteProgram(programID);
}