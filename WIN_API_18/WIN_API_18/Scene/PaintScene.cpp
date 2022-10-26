#include "framework.h"
#include "PaintScene.h"

PaintScene::PaintScene()
{
    _brushes[0] = CreateSolidBrush(RED); // ����
    _brushes[1] = CreateSolidBrush(GREEN); // �ʷ�
    _brushes[2] = CreateSolidBrush(BLUE); // �Ķ�

    _pens[0] = CreatePen(0, 3, RED);
    _pens[1] = CreatePen(0, 3, GREEN);
    _pens[2] = CreatePen(0, 3, BLUE);

    _rect = make_shared<RectCollider>(Vector2(225, 255), Vector2(150, 150));
}

PaintScene::~PaintScene()
{
}

void PaintScene::Update()
{
    _rect->GetCenter()._x += 0.5f;
}

void PaintScene::Render(HDC hdc)
{
    // ���� �Ķ���
    // ���� ���θ� ���� ���� �Ķ�
    // �簢�� ���θ� �ʷ� ���� �Ķ�

    SelectObject(hdc, _pens[2]);
    //SelectObject(hdc, _brushes[2]);

    MoveToEx(hdc, 150, 150, NULL);
    LineTo(hdc, mousePosX, mousePosY);

    SelectObject(hdc, _pens[2]);
    SelectObject(hdc, _brushes[1]);
    _rect->Render(hdc);

    SelectObject(hdc, _pens[2]);
    SelectObject(hdc, _brushes[0]);
    //Ellipse(hdc, 50, 50, 150, 150); // ���� ���� -> ����

    // Collider
}
