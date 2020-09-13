#include <iostream>
#include <glm/glm.hpp>

#include "../headers files/Window.h"
#include "../headers files/Shader.h"
#include "../headers files/Mesh.h"
#include "../headers files/Renderer.h"

Mesh mesh = Mesh();
Transform entityTransform;
Entity entity(mesh, entityTransform);
Light light = Light(glm::vec3(450, 70, -2450), glm::vec3(1, 1, 1));
std::vector<Entity> entities;
std::vector<Light> lights;

Shader shader = Shader();
Renderer* renderer;
Camera camera(glm::vec3(-782, 50, -3228), 70.0f, (float) Window::width / (float) Window::height, 0.01f, 5000.0f);

float counter = 0.f;

void init();

void update(float);

void render();

void mouse_callback(GLFWwindow *window, double xpos, double ypos);
void resizeWindowCallback(GLFWwindow* window, int fbw, int fbh);

int main() {
    if (!glfwInit()) {
        std::cerr << "Can't init glfw" << std::endl;
    }

    Window::getInstance();

    init();

    double lastTime = glfwGetTime();
    double lastTime2 = glfwGetTime();
    int nbFrames = 0;
    int fps = 0;
    double deltaTime;
    double deltaTime2;
    double updateTimer = 0;
    while (!glfwWindowShouldClose(Window::windowID)) {

        // Measure speed
        double currentTime = glfwGetTime();
        nbFrames++;
        deltaTime = currentTime - lastTime;
        deltaTime2 = currentTime - lastTime2;
        lastTime2 = currentTime;
        updateTimer += deltaTime2;

        if (updateTimer >= 1.0 / 60.0) {
            fps++;
            glfwPollEvents();

            shader.bindProgram();
            render();
            update(4);
            shader.unbindProgram();
        }

        if (deltaTime >= 1.0) {
            printf("%f ms/frame\n", 1000.0 / double(nbFrames));
            printf("%d fps\n", fps);
            nbFrames = 0;
            fps = 0;
            lastTime += 1.0;
        }
    }

    glfwTerminate();
    return 0;
}

void init() {
    lights.push_back(light);
    shader.addLights(lights);

    mesh.init();
    entities.push_back(entity);

    renderer = new Renderer(&shader, &entities);

    shader.loadShader("../resource files/vertex.glsl", GL_VERTEX_SHADER);
    shader.loadShader("../resource files/fragment.glsl", GL_FRAGMENT_SHADER);

    glfwSetFramebufferSizeCallback(Window::windowID, resizeWindowCallback);
    glfwSetCursorPosCallback(Window::windowID, mouse_callback);
    Window::cursorFocus();

}

void update(float delta) {
    shader.update(camera);

    camera.updateInput(delta);

    counter += 0.01f;

    glfwSwapBuffers(Window::windowID);
    glFlush();
}

void render() {
    glClearColor(1.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    renderer->render();
}

bool firstMouse = true;
double lastX = 0, lastY = 0;

void mouse_callback(GLFWwindow *window, double xpos, double ypos) {
    if(Window::lockedCursor) {
        if (firstMouse) {
            lastX = xpos;
            lastY = ypos;
            firstMouse = false;
        }

        float xoffset = xpos - lastX;
        float yoffset = lastY - ypos;
        lastX = xpos;
        lastY = ypos;

        float sensitivity = 0.1f;
        xoffset *= sensitivity;
        yoffset *= sensitivity;

        camera.yaw += xoffset;
        camera.pitch += yoffset;

        if (camera.pitch > 89.0f)
            camera.pitch = 89.0f;
        if (camera.pitch < -89.0f)
            camera.pitch = -89.0f;

        glm::vec3 direction;
        direction.x = cos(glm::radians(camera.yaw)) * cos(glm::radians(camera.pitch));
        direction.y = sin(glm::radians(camera.pitch));
        direction.z = sin(glm::radians(camera.yaw)) * cos(glm::radians(camera.pitch));
        camera.front = glm::normalize(direction);
    }
}

void resizeWindowCallback(GLFWwindow* window, int fbw, int fbh) {
    Window::width = fbw;
    Window::height = fbh;

    glViewport(0, 0, Window::width, Window::height);
    camera.updatePerspective(70.0f, (float) Window::width / (float) Window::height);
}