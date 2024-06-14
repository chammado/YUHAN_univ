#pragma once

#include <GLFW/glfw3.h>

class Object {
public:
    virtual void OnCollisionEnter(Object& other) {
        // 기본적으로 아무 동작도 하지 않음
    }
    virtual void Render() {
        // 기본적으로 아무 그림도 그리지 않음
    }
};

class Player : public Object {
public:
    void Render() override {
        float size_cm = 0.5f; // 플레이어 한 변의 길이 (50cm)
        float borderThickness_cm = 0.3f; // 테두리 두께 (3cm)

        // 화면의 1px이 1cm와 같다고 가정
        float halfSize = size_cm / 2.0f;
        float halfBorderThickness = borderThickness_cm / 2.0f;

        // 플레이어 색상 설정 (빨간색)
        glColor3f(1.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
        glVertex2f(-halfSize, halfSize);  // 왼쪽 위
        glVertex2f(halfSize, halfSize);   // 오른쪽 위
        glVertex2f(halfSize, -halfSize);  // 오른쪽 아래
        glVertex2f(-halfSize, -halfSize); // 왼쪽 아래
        glEnd();

        // 플레이어 테두리 그리기
        glColor3f(0.0f, 0.0f, 0.0f); // 검정색
        glLineWidth(1.0f); // 두께 1px
        glBegin(GL_LINE_LOOP);
        glVertex2f(-halfSize - halfBorderThickness, halfSize + halfBorderThickness);  // 왼쪽 위
        glVertex2f(halfSize + halfBorderThickness, halfSize + halfBorderThickness);   // 오른쪽 위
        glVertex2f(halfSize + halfBorderThickness, -halfSize - halfBorderThickness);  // 오른쪽 아래
        glVertex2f(-halfSize - halfBorderThickness, -halfSize - halfBorderThickness); // 왼쪽 아래
        glEnd();
    }
};

class EnemyBlock : public Object {
private:
    float width;
    float height;

public:
    EnemyBlock(float w, float h) : width(w), height(h) {}

    void OnCollisionEnter(Object& other) override {
        // 기본적으로 아무 동작도 하지 않음
    }

    void Render() override {
        // 장애물을 녹색 (R: 0, G: 255, B: 0)으로 그린다
        glColor3f(0.0f, 1.0f, 0.0f); // RGB 값을 0.0f에서 1.0f 범위로 변환
        glBegin(GL_QUADS);
        glVertex2f(-width / 2.0f, height / 2.0f);   // 왼쪽 위
        glVertex2f(width / 2.0f, height / 2.0f);    // 오른쪽 위
        glVertex2f(width / 2.0f, -height / 2.0f);   // 오른쪽 아래
        glVertex2f(-width / 2.0f, -height / 2.0f);  // 왼쪽 아래
        glEnd();
    }
};

class Floor : public Object {
public:
    void OnCollisionEnter(Object& other) override {
        // 기본적으로 아무 동작도 하지 않음
    }

    void Render() override {
        // 바닥을 황색 (R: 255, G: 200, B: 15)으로 그린다
        glColor3f(1.0f, 0.7843f, 0.0588f); // RGB 값을 0.0f에서 1.0f 범위로 변환
        glBegin(GL_QUADS);
        glVertex2f(-1.0f, -0.75f); // 왼쪽 아래 (바닥)
        glVertex2f(1.0f, -0.75f);  // 오른쪽 아래 (바닥)
        glVertex2f(1.0f, -1.0f);   // 오른쪽 위 (바닥)
        glVertex2f(-1.0f, -1.0f);  // 왼쪽 위 (바닥)
        glEnd();
    }
};

class Star : public Object {
public:
    void OnCollisionEnter(Object& other) override {
        // 기본적으로 아무 동작도 하지 않음
    }
};

// 물리 충돌 처리 함수 (미구현)
int PhysicsAABB(Object A, Object B) {
    return 0;
}
