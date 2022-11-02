#include "framework.h"
#include "LineScene2.h"

LineScene2::LineScene2()
{
	_line1 = make_shared<Line>(Vector2(50, 500), Vector2(800, 500));
	_line2 = make_shared<Line>(Vector2(50, 100), Vector2(50, 100));
	_line3 = make_shared<Line>(Vector2(50, 450), Vector2(100, 450));
}

LineScene2::~LineScene2()
{
}

void LineScene2::Update()
{
	_line1->Update();
	_line2->Update();
	_line3->Update();

	_line2->_endPos = mousePos;
}

void LineScene2::Render(HDC hdc)
{
	_line1->Render(hdc);
	_line2->Render(hdc);
	_line3->Render(hdc);
}
