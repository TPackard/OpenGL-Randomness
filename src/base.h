#ifndef BASE_H
#define BASE_H

#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>

#include <stdio.h>

#include "glfw_callbacks.h"
#include "vertex.h"

static int window_width = 640;
static int window_height = 480;

void load_media();
void main_loop(GLFWwindow *window);
void update(GLFWwindow *window);
void render(GLFWwindow *window);

#endif
