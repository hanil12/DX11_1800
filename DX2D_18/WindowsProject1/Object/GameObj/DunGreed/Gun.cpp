#include "framework.h"
#include "Gun.h"

Gun::Gun()
{
	_quad = make_shared<Quad>(L"railgun.png", Vector2(200, 100));

	_bullet = make_shared<Bullet>();
	_bullet->_isActive = false;
}

Gun::~Gun()
{
}

void Gun::Update()
{
	_quad->Update();
	_bullet->Update();
}

void Gun::Render()
{
	_quad->Render();
	_bullet->Render();
}

void Gun::FireBullet(const Vector2& mousePos)
{
	Vector2 dir = mousePos - _quad->GetTransform()->GetWorldPos();

	_bullet->_isActive = true;
	_bullet->GetTransform()->GetPos() = _quad->GetTransform()->GetWorldPos();
	_bullet->SetDir(dir);
}
