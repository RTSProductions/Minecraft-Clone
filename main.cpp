// Headers
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>

// Variables
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

// Keyboard input
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    if (key == GLFW_KEY_TAB && action == GLFW_PRESS)
    {
        GLFWmonitor* monitor = glfwGetPrimaryMonitor();

        const GLFWvidmode* mode = glfwGetVideoMode(monitor);
 
        glfwSetWindowMonitor(window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);

        glfwSetWindowMonitor(window, monitor, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, mode->refreshRate);
    }
}

// Cursor input
void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
{

}

// Scroller input
void scrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{

}

int main(void)
{
    GLFWwindow* window;

    // Tell glfw what versions to use
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

    // Make sure it can initalize
    if (!glfwInit())
    {
        std::cout << "Failed to initalize GLFW" << std::endl;
        return -1;
    }

    // Create the window
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Totally Minecraft", NULL, NULL);

    // Make sure creating the window succeeded
    if (!window)
    {
        std::cout << "Failed to create GLFW window." << std::endl;
        glfwTerminate();
        return -1;
    }

    // Make the window's current context
    glfwMakeContextCurrent(window);

    // Set up key input reading
    glfwSetKeyCallback(window, keyCallback);

    // Set up mouse input reading
    glfwSetCursorPosCallback(window, cursorPositionCallback);

    // Set up mouse scroll input reading
    glfwSetScrollCallback(window, scrollCallback);

    // Make sure glad can load
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initalize Glad" << std::endl;
        return -1;
    }

    // Scale the viewport
    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    // Check if there is a controller present
    int present = glfwJoystickPresent(GLFW_JOYSTICK_1);

    // The game loop
    while (!glfwWindowShouldClose(window))
    {
        // Set the clear color
        glClearColor(0.980392, 0.466667, 0.431373, 1);

        // Clear the screan
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap the buffers
        glfwSwapBuffers(window);

        // Call all events
        glfwPollEvents();

        // Check if there is a controller present
        present = glfwJoystickPresent(GLFW_JOYSTICK_1);

        // Controller input
        if (present == GLFW_TRUE)
        {
            int axesCount;
            const float* axes = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &axesCount);
        }
    }

    // Terminate the window
    glfwTerminate();

    return 0;

}