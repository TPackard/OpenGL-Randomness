#include "base.h"

int main(int argc, char *argv[]) {
    // Initialize GLFW (and GLU too)
    if (!glfwInit()) {
        perror("ERROR: Could not intialize GLFW!");
        return 1;
    }

    glfwSwapInterval(1); // Time between buffer swaps
    glfwSetErrorCallback(error_callback);

    GLFWwindow* window = glfwCreateWindow(640, 480, "OpenGL Randomness", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return 2;
    }

    glfwGetFramebufferSize(window, &window_width, &window_height); // Loads the window's dimensions into the variables
    glfwMakeContextCurrent(window); // Uses the window's OpenGL context
    glfwSetKeyCallback(window, key_callback);

    // Set up OpenGL
    glViewport(0.0, 0.0, window_width, window_height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 640, 480, 0.0, 1.0, -1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClearColor(0.0, 0.0, 0.0, 1.0);

    GLenum gl_error = glGetError();
    if (gl_error != GL_NO_ERROR) {
        printf("ERROR: Could not initialize OpenGL! %s\n", gluErrorString(gl_error));
        return 4;
    }

    load_media();

    // Main loop
    while(!glfwWindowShouldClose(window)) {
        main_loop(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
