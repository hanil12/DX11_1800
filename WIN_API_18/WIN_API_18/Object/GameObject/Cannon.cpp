#include "framework.h"
#include "Cannon.h"

Cannon::Cannon()
{
	_body = make_shared<CircleCollider>(Vector2(CENTER_X, CENTER_Y), 30);
	_barrel = make_shared<Barrel>();
	_barrel->_startPos = _body->GetCenter();
	_barrel->_endPos = _barrel->_startPos + Vector2(_barrelSize, 0);
}

Cannon::~Cannon()
{
}

void Cannon::Update()
{
	_barrel->Update();
	_body->Update();

	_barrel->_startPos = _body->GetCenter();
	_barrel->_endPos._x = _body->GetCenter()._x + _barrelSize * cosf(_angle);
	_barrel->_endPos._y = _body->GetCenter()._y + _barrelSize * sinf(_angle);
}

void Cannon::Render(HDC hdc)
{
	_barrel->Render(hdc);
	_body->Render(hdc);
}

void Cannon::MoveLeft()
{
	Vector2 temp = _body->GetCenter();
	temp._x -= _speed;
	_body->SetCenter(temp);
}

void Cannon::MoveRight()
{
	Vector2 temp = _body->GetCenter();
	temp._x += _speed;
	_body->SetCenter(temp);
}
