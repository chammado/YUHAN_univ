#pragma once
#include <GLFW/glfw3.h>

void PixelToOpenGL(float FloorXpixel, float FloorYpixel);

// 기본 클래스
class Object {
public:
    float posX, posY, width, height;
    Object(float x = 0.0f, float y = 0.0f, float w = 0.0f, float h = 0.0f)
        : posX(x), posY(y), width(w), height(h) {}

    virtual void OnCollisionEnter(Object& other) {}
};

// Player 클래스
class Player : public Object {
public:
    float velocityY = 0.0f; // y 축 속도
    bool isJumping = false; // 점프 상태

    Player() : Object(100.0f, 450.0f, 50.0f, 50.0f) {}

    void OnCollisionEnter(Object& other) override {
        drawPlayer();
    }
    void drawPlayer();
};

// EnemyBlock 클래스
class EnemyBlock : public Object {
public:
    float posX1 = 800.0f;
    float posX2 = 1600.0f;
    float posX3 = 2400.0f;
    float posX4 = 2500.0f;

    EnemyBlock() : Object(0.0f, 0.0f, 50.0f, 100.0f) {}

    void OnCollisionEnter(Object& other) override {
        drawCac();
    }
    void drawCac();
};

// Floor 클래스
class Floor : public Object {
public:
    void OnCollisionEnter(Object& other) override {
        drawFloor();
    }
    void drawFloor();
};

// Star 클래스
class Star : public Object {
public:
    float size;

    Star() : Object(), size(0.0f) {}

    void OnCollisionEnter(Object& other) override {
        drawStar();
    }
    void drawStar() const;
};

// PhysicsAABB 함수
int PhysicsAABB(const Object& A, const Object& B);
