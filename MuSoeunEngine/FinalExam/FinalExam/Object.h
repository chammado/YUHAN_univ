#pragma once

#include <GLFW/glfw3.h>

class Object {
public:
    virtual void OnCollisionEnter(Object& other) {
        // �⺻������ �ƹ� ���۵� ���� ����
    }
    virtual void Render() {
        // �⺻������ �ƹ� �׸��� �׸��� ����
    }
};

class Player : public Object {
public:
    void Render() override {
        float size_cm = 0.5f; // �÷��̾� �� ���� ���� (50cm)
        float borderThickness_cm = 0.3f; // �׵θ� �β� (3cm)

        // ȭ���� 1px�� 1cm�� ���ٰ� ����
        float halfSize = size_cm / 2.0f;
        float halfBorderThickness = borderThickness_cm / 2.0f;

        // �÷��̾� ���� ���� (������)
        glColor3f(1.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
        glVertex2f(-halfSize, halfSize);  // ���� ��
        glVertex2f(halfSize, halfSize);   // ������ ��
        glVertex2f(halfSize, -halfSize);  // ������ �Ʒ�
        glVertex2f(-halfSize, -halfSize); // ���� �Ʒ�
        glEnd();

        // �÷��̾� �׵θ� �׸���
        glColor3f(0.0f, 0.0f, 0.0f); // ������
        glLineWidth(1.0f); // �β� 1px
        glBegin(GL_LINE_LOOP);
        glVertex2f(-halfSize - halfBorderThickness, halfSize + halfBorderThickness);  // ���� ��
        glVertex2f(halfSize + halfBorderThickness, halfSize + halfBorderThickness);   // ������ ��
        glVertex2f(halfSize + halfBorderThickness, -halfSize - halfBorderThickness);  // ������ �Ʒ�
        glVertex2f(-halfSize - halfBorderThickness, -halfSize - halfBorderThickness); // ���� �Ʒ�
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
        // �⺻������ �ƹ� ���۵� ���� ����
    }

    void Render() override {
        // ��ֹ��� ��� (R: 0, G: 255, B: 0)���� �׸���
        glColor3f(0.0f, 1.0f, 0.0f); // RGB ���� 0.0f���� 1.0f ������ ��ȯ
        glBegin(GL_QUADS);
        glVertex2f(-width / 2.0f, height / 2.0f);   // ���� ��
        glVertex2f(width / 2.0f, height / 2.0f);    // ������ ��
        glVertex2f(width / 2.0f, -height / 2.0f);   // ������ �Ʒ�
        glVertex2f(-width / 2.0f, -height / 2.0f);  // ���� �Ʒ�
        glEnd();
    }
};

class Floor : public Object {
public:
    void OnCollisionEnter(Object& other) override {
        // �⺻������ �ƹ� ���۵� ���� ����
    }

    void Render() override {
        // �ٴ��� Ȳ�� (R: 255, G: 200, B: 15)���� �׸���
        glColor3f(1.0f, 0.7843f, 0.0588f); // RGB ���� 0.0f���� 1.0f ������ ��ȯ
        glBegin(GL_QUADS);
        glVertex2f(-1.0f, -0.75f); // ���� �Ʒ� (�ٴ�)
        glVertex2f(1.0f, -0.75f);  // ������ �Ʒ� (�ٴ�)
        glVertex2f(1.0f, -1.0f);   // ������ �� (�ٴ�)
        glVertex2f(-1.0f, -1.0f);  // ���� �� (�ٴ�)
        glEnd();
    }
};

class Star : public Object {
public:
    void OnCollisionEnter(Object& other) override {
        // �⺻������ �ƹ� ���۵� ���� ����
    }
};

// ���� �浹 ó�� �Լ� (�̱���)
int PhysicsAABB(Object A, Object B) {
    return 0;
}
