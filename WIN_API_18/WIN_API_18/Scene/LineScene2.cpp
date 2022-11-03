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
	_line1->Update(); // 고정
	_line2->Update(); // 마우스
	_line3->Update(); // 그림자

	_line2->_endPos = mousePos;

	// 그림자 만들기
	Vector2 a = _line2->_endPos - _line2->_startPos;
	Vector2 b = _line1->_endPos - _line1->_startPos;
	b = b.Normallize();
	float length = a.Dot(b); // 교환법칙 성립
	_line3->_endPos = _line3->_startPos + b * length;
}

void LineScene2::Render(HDC hdc)
{
	_line1->Render(hdc);
	_line2->Render(hdc);
	_line3->Render(hdc);
}
