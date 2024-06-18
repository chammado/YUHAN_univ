#pragma comment(lib, "OpenGL32.lib")
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new (_NORMAL_BLOCK, __FILE__, __LINE__)
#else
#define DBG_NEW new
#endif

#include <GLFW/glfw3.h>
#include <stdio.h>
#include <chrono>
#include <thread>
#include <cmath>
#include "Object.h"
#include "Transform.h"

using namespace std::chrono;

// 전역 변수로 Player 객체 선언
Player player;
bool isCollision = false; // 충돌 여부 확인 변수

// 시간 측정을 위한 변수
high_resolution_clock::time_point lastTime;

// 점프 시간 측정을 위한 변수
bool spacePressed = false;
float jumpTime = 0.0f;
const float MAX_JUMP_TIME = 0.5f; // 최대 점프 시간 (0.5초)

void errorCallback(int error, const char* description) {
    printf("GLFW Error: %s", description);
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS && !player.isJumping) {
        spacePressed = true;
        jumpTime = 0.0f; // 점프 시간 초기화
    }
    if (key == GLFW_KEY_SPACE && action == GLFW_RELEASE && !player.isJumping) {
        spacePressed = false;
        player.velocityY = 1000.0f * (jumpTime / MAX_JUMP_TIME); // 점프 시작 (비례 속도 설정)
        player.isJumping = true;
        jumpTime = 0.0f; // 점프 시간 초기화
    }
}

int Physics() {
    return 0;
}

int Initialize() {
    glClearColor(0.0f, 0.11f, 0.25f, 1.0f);
    lastTime = high_resolution_clock::now();
    return 0;
}

int Update(EnemyBlock& enemy, Player& player, Star stars[], int starCount, float deltaTime) {
    float gravity = 9.8f * 100; // 중력 가속도 (픽셀 단위)

    if (isCollision) return 0;

    if (spacePressed && jumpTime < MAX_JUMP_TIME) {
        jumpTime += deltaTime; // 스페이스바를 누르는 동안 점프 시간 증가
    }

    // 플레이어 위치 업데이트
    applyGravityAndJump(player.posY, player.velocityY, player.isJumping, gravity, deltaTime);

    // 적 위치 업데이트
    float enemySpeed = 225.0f; // 적 이동 속도
    updateEnemyPosition(enemy.posX1, enemySpeed, deltaTime);
    updateEnemyPosition(enemy.posX2, enemySpeed, deltaTime);
    updateEnemyPosition(enemy.posX3, enemySpeed, deltaTime);
    updateEnemyPosition(enemy.posX4, enemySpeed, deltaTime);
    resetEnemyPositions(enemy, -10.0f);

    // 별 위치 업데이트
    float starSpeed = 75.0f; // 별 이동 속도
    for (int i = 0; i < starCount; ++i) {
        updateStarPosition(stars[i].posX, starSpeed, deltaTime);
        resetStarPosition(stars[i].posX, -10.0f, 810.0f);
    }

    // 충돌 검사
    if (PhysicsAABB(player, Object(enemy.posX1, 400.0f, 50.0f, 100.0f)) ||
        PhysicsAABB(player, Object(enemy.posX2, 200.0f, 50.0f, 300.0f)) ||
        PhysicsAABB(player, Object(enemy.posX3, 400.0f, 50.0f, 100.0f)) ||
        PhysicsAABB(player, Object(enemy.posX4, 200.0f, 50.0f, 300.0f))) {
        isCollision = true;
    }

    return 0;
}

int Render(EnemyBlock& enemy, Player& player, const Star stars[], int starCount) {
    glClear(GL_COLOR_BUFFER_BIT);

    for (int i = 0; i < starCount; ++i) {
        stars[i].drawStar();
    }
    Object other;
    player.OnCollisionEnter(other);
    Floor floor;
    floor.OnCollisionEnter(other);
    enemy.OnCollisionEnter(other);
    return 0;
}

int main(void) {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    if (!glfwInit())
        return -1;

    GLFWwindow* window;
    window = glfwCreateWindow(800, 600, "Dino Run Copy Game", NULL, NULL);

    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, keyCallback);

    Initialize();

    EnemyBlock enemy;

    // 5개의 별 생성
    const int starCount = 5;
    Star stars[starCount];
    for (int i = 0; i < starCount; ++i) {
        stars[i].posX = randomFloat(0.0f, 800.0f);
        stars[i].posY = randomFloat(0.0f, 300.0f);
        stars[i].size = randomFloat(30.0f, 60.0f); // 크기를 픽셀 단위로 지정
    }

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        // deltaTime 계산
        high_resolution_clock::time_point currentTime = high_resolution_clock::now();
        duration<float> elapsedTime = duration_cast<duration<float>>(currentTime - lastTime);
        float deltaTime = elapsedTime.count();
        lastTime = currentTime;

        Physics();
        Update(enemy, player, stars, starCount, deltaTime);
        Render(enemy, player, stars, starCount);
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}