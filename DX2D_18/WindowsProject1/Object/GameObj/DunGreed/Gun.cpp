#include "framework.h"
#include "Gun.h"

Gun::Gun()
{
	_quad = make_shared<Quad>(L"railgun.png", Vector2(200, 100));

	_muzzle = make_shared<Transform>();
	_muzzle->SetParent(_quad->GetTransform());
	_muzzle->GetPos()._x += 40;
	_muzzle->GetPos()._y += 5;

	for (int i = 0; i < _poolCount; i++)
	{
		shared_ptr<Bullet> bullet = make_shared<Bullet>();
		bullet->_isActive = false;
		_bullets.push_back(bullet);
	}
}

Gun::~Gun()
{
}

void Gun::Update()
{
	_quad->Update();
	_muzzle->Update();

	for (auto bullet : _bullets)
	{
		bullet->Update();
	}
}

void Gun::Render()
{
	for (int i = 0; i < 10; i++)
	{
		_bullets[i]->Render();
	}
	_quad->Render();
}

void Gun::FireBullet(const Vector2& mousePos)
{
	Vector2 dir = mousePos - _quad->GetTransform()->GetWorldPos();

	auto iter = std::find_if(_bullets.begin(), _bullets.end(), [](const shared_ptr<Bullet>& bullet) -> bool
		{
			if (bullet->_isActive == false)
				return true;
			return false;
		});

	if (iter != _bullets.end())
	{
		(*iter)->_isActive = true;
		(*iter)->GetTransform()->GetPos() = _muzzle->GetWorldPos();
		(*iter)->SetDir(dir);
		(*iter)->GetTransform()->GetAngle() = dir.Angle();
	}
	else
	{
		// ����ó��
	}
}
