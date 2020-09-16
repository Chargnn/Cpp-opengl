#ifndef OPENGL_WINDOW_H
#define OPENGL_WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

class Window {
public:
    static GLFWwindow *windowID;
    static Window *instance;
    static int width, height;

    static bool lockedCursor;
    static bool focusedCursor;

    static Window *getInstance();

    static void focusCursor(bool focus);

private:
    explicit Window();
};


#endif //OPENGL_WINDOW_H
