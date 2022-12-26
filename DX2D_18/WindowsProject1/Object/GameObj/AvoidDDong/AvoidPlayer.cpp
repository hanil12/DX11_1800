#include "framework.h"
#include "AvoidPlayer.h"

AvoidPlayer::AvoidPlayer()
{
	_quad = make_shared<Quad>(L"Player.png", Vector2(150, 70));

	_rectCol = make_shared<RectCollider>(Vector2(70, 70));
	_rectCol->GetTransform()->SetParent(_quad->GetTransform());

	_quad->GetTransform()->GetPos() = Vector2(CENTER_X, CENTER_Y - 300);
}

AvoidPlayer::~AvoidPlayer()
{
}

void AvoidPlayer::Update()
{
	if (_isActive == false)
		return;
	Input();

	_quad->Update();
	_rectCol->Update();
}

void AvoidPlayer::Render()
{
	if (_isActive == false)
		return;
	_quad->Render();
	_rectCol->Render();
}

void AvoidPlayer::Input()
{
	if (KEY_PRESS('A') && (_quad->GetTransform()->GetPos().x > _leftRight.x))
	{
		_quad->GetTransform()->GetPos().x -= _speed * DELTA_TIME;
	}
	if (KEY_PRESS('D') && ((_quad->GetTransform()->GetPos().x < _leftRight.y)))
	{
		_quad->GetTransform()->GetPos().x += _speed * DELTA_TIME;
	}
}
