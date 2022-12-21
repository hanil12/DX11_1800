#include "framework.h"
#include "Player.h"

Player::Player()
{
	_quad = make_shared<Quad>(L"Player.png", Vector2(150, 70));

	_gun = make_shared<Gun>();
	_gun->GetTransform()->SetParent(_quad->GetTransform());
	_gun->GetTransform()->GetPos()._x += 100;

	_rectCol = make_shared<RectCollider>(Vector2(70, 70));
	_rectCol->GetTransform()->SetParent(_quad->GetTransform());
}

Player::~Player()
{
}

void Player::Update()
{
	_quad->Update();

	Vector2 temp = mousePos - _gun->GetTransform()->GetWorldPos();
	float angle = temp.Angle();
	_gun->GetTransform()->GetAngle() = angle;

	_gun->Update();
	_rectCol->Update();
}

void Player::Render()
{
	_quad->Render();

	_gun->Render();
	_rectCol->Render();
}

void Player::Move(const Vector2& pos)
{
	_quad->GetTransform()->GetPos() = pos;
}

void Player::Fire(const Vector2& mousePos)
{
	_gun->FireBullet(mousePos);
}
