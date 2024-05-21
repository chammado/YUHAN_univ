//1. 삼각형으로 별을 그리시오
//2. 마우스 좌클릭 후에 드래그해서 드래그한만큼 별을 이동해주세요
//3. 우클릭하고 우측으로 드래그한만큼 확대 좌측으로 드래그한만큼 축소를 해주세요.
//   (별의 중점을 기준으로 확대/축소가 돼야합니다.)

#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>

float moveFactor = 0.0f;
float scaleFactor = 1.0f;
float angle = 0.0f;
float rotationSpeed = 0.001f; // 회전 속도를 조절하는 변수

void errorCallback(int error, const char* description)
{
    std::cerr << "GLFW Error: " << description << std::endl;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    if (key == GLFW_KEY_UP && action == GLFW_PRESS)
    {
        moveFactor += 0.01f;
    }
    if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
    {
        scaleFactor += 0.1f;
    }
}

void setVertexRotation(float x, float y, float angle_degree)
{
    glVertex2f(x * cos(angle_degree) - (y * sin(angle_degree)), x * sin(angle_degree) + (y * cos(angle_degree)));
}

void star(float x_shift, float y_shift, float star_radius)
{
    const float DEGINRAD = 3.14159 / 180;
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    setVertexRotation(cos(18 * DEGINRAD) * star_radius + x_shift, sin(18 * DEGINRAD) * star_radius + y_shift, angle);
    setVertexRotation(cos(162 * DEGINRAD) * star_radius + x_shift, sin(162 * DEGINRAD) * star_radius + y_shift, angle);
    setVertexRotation(cos(270 * DEGINRAD) * star_radius / 2 + x_shift, sin(270 * DEGINRAD) * star_radius / 2 + y_shift, angle);
    glEnd();
    glBegin(GL_POLYGON);
    setVertexRotation(cos(90 * DEGINRAD) * star_radius + x_shift, sin(90 * DEGINRAD) * star_radius + y_shift, angle);
    setVertexRotation(cos(234 * DEGINRAD) * star_radius + x_shift, sin(234 * DEGINRAD) * star_radius + y_shift, angle);
    setVertexRotation(cos(270 * DEGINRAD) * star_radius / 2 + x_shift, sin(270 * DEGINRAD) * star_radius / 2 + y_shift, angle);
    glEnd();
    glBegin(GL_POLYGON);
    setVertexRotation(cos(90 * DEGINRAD) * star_radius + x_shift, sin(90 * DEGINRAD) * star_radius + y_shift, angle);
    setVertexRotation(cos(306 * DEGINRAD) * star_radius + x_shift, sin(306 * DEGINRAD) * star_radius + y_shift, angle);
    setVertexRotation(cos(270 * DEGINRAD) * star_radius / 2 + x_shift, sin(270 * DEGINRAD) * star_radius / 2 + y_shift, angle);
    glEnd();
}

int main(void)
{
    if (!glfwInit())
        return -1;

    GLFWwindow* window;
    window = glfwCreateWindow(1000, 1000, "MuSoeunEngine", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, keyCallback);

    float star_radius = 0.6f; // 별의 크기를 조절하기 위한 변수

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        star(0.0f, 0.0f, star_radius); // 별의 중심 좌표를 (0, 0)으로 설정하여 호출

        angle += rotationSpeed;

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
