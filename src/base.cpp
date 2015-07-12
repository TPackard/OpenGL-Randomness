#include "base.h"

Vertex vertices[4];
GLuint indices[4];

GLuint vertex_buffer = 0;
GLuint index_buffer = 0;

/// Sets the vertex positions and order and binds them to buffers in the memory
void load_media() {
    for (int i = 0; i < 4; ++i) {
        vertices[i].x = i % 3 == 0 ? window_width / 4.0 : window_width * 3.0 / 4.0;
        vertices[i].y = i < 2 ? window_height / 4.0 : window_height *3.0 / 4.0;
        indices[i] = i;
    }

    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vertex), vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &index_buffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 4 * sizeof(GLuint), indices, GL_STATIC_DRAW);
}

/// The main loop that updates, renders, and polls input
void main_loop(GLFWwindow *window) {
    update(window);
    render(window);
    glfwPollEvents();
}

/// Updates things that will eventually need to be updated
void update(GLFWwindow *window) {

}

/// Renders the graphics
void render(GLFWwindow *window) {
    glClear(GL_COLOR_BUFFER_BIT);

    glEnableClientState(GL_VERTEX_ARRAY);

    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glVertexPointer(2, GL_FLOAT, 0, NULL);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer);
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_INT, NULL);

    glDisableClientState(GL_VERTEX_ARRAY);

    glfwSwapBuffers(window);
}
