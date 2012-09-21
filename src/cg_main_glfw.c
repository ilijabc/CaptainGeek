/**
 * Project: Captain Geek
 * File: cg_main_glfw.c
 * Author: Ilija Djukic
 */

#include "cg_context.h"
#include <GL/glfw.h>

CG_Context_t cgInitContext_GLFW(void);
void cgFreeContext_GLFW(CG_Context_t context);
void cgRunContext_GLFW(CG_Context_t context);

int main(int argc, char **argv)
{
    CG_Context_t context;
    context = cgInitContext_GLFW();
    if (!context)
        return 1;
    cgLoadBook(context);
    cgRunContext_GLFW(context);
    cgFreeContext_GLFW(context);
    return 0;
}

CG_Context_t cgInitContext_GLFW(void)
{
    const int window_width = 800;
    const int window_height = 600;

    if (glfwInit() != GL_TRUE)
        return NULL;

    if (glfwOpenWindow(window_width, window_height,
                       8, 8, 8, 8,
                       0, 0, GLFW_WINDOW) != GL_TRUE)
        return NULL;
    glfwSetWindowTitle("Captain Geek");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, window_width, 0, window_height, -1, 1);
    glMatrixMode(GL_MODELVIEW);

    CG_Context_t context = cgCreateContext();
    cgResizeContext(context, window_width, window_height);
    return context;
}

void cgFreeContext_GLFW(CG_Context_t context)
{
    cgFreeContext(context);
    glfwTerminate();
}

void cgRunContext_GLFW(CG_Context_t context)
{
    double old_time = glfwGetTime();
    while(1)
    {
        // update context
        double current_time = glfwGetTime();
        cgUpdateContext(context, current_time - old_time);
        old_time = current_time;
        // escape to quit, arrow keys to rotate view
        if (glfwGetKey(GLFW_KEY_ESC) == GLFW_PRESS)
            break;
        // clear the buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // draw the figure
        cgDrawContext(context);
        // swap back and front buffers
        glfwSwapBuffers();
    }
}
