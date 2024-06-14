#pragma comment(lib, "Opengl32.lib")

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
#define DBG_NEW new
#endif

#include <GLFW/glfw3.h>
#include <stdio.h>
#include <chrono>
#include <thread>
#include <cmath>
#include "Object.h"

void errorCallback(int error, const char* description)
{
	printf("GLFW Error: %s", description);
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{

}

int Physics()
{
	return 0;
}

int Initialize()
{
	return 0;
}

int Update()
{
	return 0;
}

int Render(GLFWwindow* window)
{
	int screenWidth, screenHeight;
	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	glViewport(0, 0, screenWidth, screenHeight);

	// 화면의 1px이 1cm와 같도록 변환 계수 계산
	float cmPerPixel = 1.0f / screenWidth; // 화면 가로 길이가 800px이므로 1cm당 pixel 수

	// 배경색을 하늘색으로 설정
	glClearColor(0.0f, 0.1176f, 0.3921f, 1.0f); // R: 0, G: 30, B: 100
	glClear(GL_COLOR_BUFFER_BIT);

	// Floor 객체 생성 및 렌더링
	Floor floor;
	floor.Render();

	// Player 객체 생성 및 렌더링
	Player player;
	player.Render();

	// 낮은 장애물 생성 및 렌더링
	EnemyBlock lowBlock(50.0f * cmPerPixel, 100.0f * cmPerPixel);
	glPushMatrix();
	glTranslatef(-0.5f, -0.25f, 0.0f); // 화면 왼쪽 중앙에 배치
	lowBlock.Render();
	glPopMatrix();

	// 높은 장애물 생성 및 렌더링
	EnemyBlock highBlock(50.0f * cmPerPixel, 300.0f * cmPerPixel);
	glPushMatrix();
	glTranslatef(0.5f, 0.5f, 0.0f); // 화면 오른쪽 상단에 배치
	highBlock.Render();
	glPopMatrix();

	return 0;
}


int main(void)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	//glfw라이브러리 초기화
	if (!glfwInit())
		return -1;

	GLFWwindow* window;
	window = glfwCreateWindow(800, 600, "Google Dino Run Copy Game", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetErrorCallback(errorCallback);
	glfwSetKeyCallback(window, keyCallback);

	Initialize();

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		Physics();
		Update();
		Render(window);
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;

}