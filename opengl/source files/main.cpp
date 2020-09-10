#include <iostream>
#include <glm/glm.hpp>

#include "../headers files/Window.h"
#include "../headers files/Shader.h"
#include "../headers files/Mesh.h"
#include "../headers files/Renderer.h"
#include "../headers files/Camera.h"
#include "../headers files/Entity.h"

Vertex vertices[] = {
        glm::vec3(0.0f, 0.5f, 0.0f),
        glm::vec3(-0.5f, -0.5f, 0.0f),
        glm::vec3(0.5f, -0.5f, 0.0f),
};

GLuint indices[] = {
        0, 1, 2
};

Mesh mesh(vertices, indices, sizeof(vertices) / sizeof(vertices[0]), sizeof(indices) / sizeof(indices[0]));
Transform entityTransform;
Entity entity(mesh, entityTransform);
Shader shader = Shader();
Renderer renderer = Renderer(&shader, &entity);
Camera camera(glm::vec3(0, 0, -13), 70.0f, (float) 640 / (float) 480, 0.01f, 1000.0f);

float counter = 0.f;

void init();

void update();

void render();

int main() {
    if (!glfwInit()) {
        std::cerr << "Can't init glfw" << std::endl;
    }

    Window::getInstance();

    init();

    while (!glfwWindowShouldClose(Window::windowID)) {
        glfwPollEvents();

        shader.bindProgram();
        render();
        update();
        shader.unbindProgram();
    }

    glfwTerminate();
    return 0;
}

void init() {
    shader.loadShader("../resource files/vertex.glsl", GL_VERTEX_SHADER);
    shader.loadShader("../resource files/fragment.glsl", GL_FRAGMENT_SHADER);

    mesh.init();
}

void update() {
    entity.transform.getPos().z = sinf(counter * 50);
    shader.update(camera);

    camera.updateInput();

    counter += 0.01f;

    glfwSwapBuffers(Window::windowID);
    glFlush();
}

void render() {
    glClearColor(1.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    renderer.render();
}