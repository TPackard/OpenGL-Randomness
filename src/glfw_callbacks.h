#ifndef GLFW_CALLBACKS_H
#define GLFW_CALLBACKS_H

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

void error_callback(int error, const char *description);
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

#endif
