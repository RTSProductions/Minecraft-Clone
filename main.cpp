#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

int main(void)
{
    GLFWwindow* window;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

    if (!glfwInit())
    {
        std::cout << "Failed to initalize GLFW" << std::endl;
        return -1;
    }

    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Totally Minecraft", NULL, NULL);

    if (!window)
    {
        std::cout << "Failed to create GLFW window." << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initalize Glad" << std::endl;
        return -1;
    }

    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(250 / 255, 119 / 255, 110 / 255, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

     glfwTerminate();

    return 0;

}