#ifndef OPENGL_WINDOW_H
#define OPENGL_WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

class Window {
private:
    static Window* instance;

    explicit Window();
public:
    static GLFWwindow* windowID;

    static Window* getInstance();
    static void resizeWindowCallback(GLFWwindow* window, int fbw, int fbH);
};


#endif //OPENGL_WINDOW_H
