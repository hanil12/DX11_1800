#include "framework.h"
#include "PaintScene.h"

PaintScene::PaintScene()
{
    _brushes[0] = CreateSolidBrush(RED); // 빨강
    _brushes[1] = CreateSolidBrush(GREEN); // 초록
    _brushes[2] = CreateSolidBrush(BLUE); // 파랑

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
    // 선은 파랑색
    // 원은 내부를 빨강 선은 파랑
    // 사각형 내부를 초록 선은 파랑

    SelectObject(hdc, _pens[2]);
    //SelectObject(hdc, _brushes[2]);

    MoveToEx(hdc, 150, 150, NULL);
    LineTo(hdc, mousePosX, mousePosY);

    SelectObject(hdc, _pens[2]);
    SelectObject(hdc, _brushes[1]);
    _rect->Render(hdc);

    SelectObject(hdc, _pens[2]);
    SelectObject(hdc, _brushes[0]);
    //Ellipse(hdc, 50, 50, 150, 150); // 렌더 순서 -> 과제

    // Collider
}
