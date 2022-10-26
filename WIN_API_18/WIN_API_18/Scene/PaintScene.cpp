#include "framework.h"
#include "PaintScene.h"

PaintScene::PaintScene()
{
}

PaintScene::~PaintScene()
{
}

void PaintScene::Update()
{
}

void PaintScene::Render(HDC hdc)
{
    MoveToEx(hdc, 150, 150, NULL);
    LineTo(hdc, mousePosX, mousePosY);
    Rectangle(hdc, 150, 150, 300, 300);
    Ellipse(hdc, 50, 50, 150, 150); // ·»´õ ¼ø¼­
}
