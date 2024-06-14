#pragma comment(lib, "OpenGL32.lib")

#include <GLFW/glfw3.h>
#include <iostream>
#include <chrono>

float blueBoxY = -0.95f;
float blueBoxSpeed = 0.0f;
const float blueJumpSpeed = 5.0f; // 점프 힘 적용
const float gravity = -9.8f;  // 중력 가속도 적용
bool isJumping = false;

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS & !isJumping) // 스페이스를 눌린 상태에서 점프상태가 아닐 때 작동
    {
        isJumping = true; // 점프 상태라는 걸 표시
        blueBoxSpeed = blueJumpSpeed; // blueBoxSpeed에 blueJumpSpeed를 대입
    }
}

void errorCallback(int error, const char* description)
{
    std::cerr << "GLFW Error: " << description << std::endl;
}

void gravityBox(float deltaTime)
{
    blueBoxSpeed += gravity * deltaTime;  // blueBoxSpeed에 gravity를 값을 더함
    blueBoxY += blueBoxSpeed * deltaTime;  // blueBoxSpeed를 적용하여 blueBoxY의 위치를 변경
    if (blueBoxY <= -0.95f)
    {
        blueBoxY = -0.95f; // 파란색 사각형 위치를 고정
        blueBoxSpeed = 0.0f;  // 파란색 사각형의 속도 제거
        isJumping = false; // 점프 상태가 아니라는 표시
    }
}

void render()
{
    // 땅 그리기
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-1.0f, -0.95f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.95f);
    glEnd();

    // 파란색 사각형 그리기
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-0.1f, blueBoxY + 0.2f); // 위쪽 꼭짓점들은 한 변의 길이를 더 더하여 사각형의 형태 유지
    glVertex2f(-0.1f, blueBoxY);
    glVertex2f(0.1f, blueBoxY);
    glVertex2f(0.1f, blueBoxY + 0.2f); // 동일한거 아시죠?
    glEnd();
}

int main()
{
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(700, 700, "MuSoeunEngine", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, keyCallback);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    auto previousTime = std::chrono::high_resolution_clock::now(); //이전 시간에 컴퓨터의 현재 시간을 불러옴

    while (!glfwWindowShouldClose(window))
    {
        auto currentTime = std::chrono::high_resolution_clock::now(); //현재 시간에 컴퓨터의 현재 시간을 불러옴
        std::chrono::duration<float> deltaTime = currentTime - previousTime; //deltaTime 변수에 현재 시간에서 이전 시간을 빼서 컴퓨터의 처리 속도 계산
        previousTime = currentTime; // 이전 시간을 현재 시간으로 변환

        glfwPollEvents();
        glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        gravityBox(deltaTime.count());
        render();

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}