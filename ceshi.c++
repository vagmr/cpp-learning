#include <GLFW/glfw3.h>

int main()
{
    // 初始化 GLFW
    if (!glfwInit())
    {
        return -1;
    }

    // 创建窗口
    GLFWwindow *window = glfwCreateWindow(800, 600, "My OpenGL App", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // 设置当前上下文
    glfwMakeContextCurrent(window);

    // 主循环
    while (!glfwWindowShouldClose(window))
    {
        // 清除颜色缓冲区
        glClear(GL_COLOR_BUFFER_BIT);

        // 在这里添加你的OpenGL渲染代码

        // 交换缓冲区
        glfwSwapBuffers(window);

        // 处理事件
        glfwPollEvents();
    }

    // 清理
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
