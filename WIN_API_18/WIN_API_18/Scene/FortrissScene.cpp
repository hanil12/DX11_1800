#include "framework.h"
#include "FortrissScene.h"

FortrissScene::FortrissScene()
{
	_cannon = make_shared<Cannon>();
	_cannon2 = make_shared<Cannon>();
}

FortrissScene::~FortrissScene()
{
}

void FortrissScene::Update()
{
	_cannon->Update();
	_cannon2->Update();

	if (GetAsyncKeyState(VK_LEFT))
		_cannon->MoveLeft();
	if (GetAsyncKeyState(VK_RIGHT))
		_cannon->MoveRight();
	if (GetAsyncKeyState(VK_UP))
		_angle -= 0.01f;
	if (GetAsyncKeyState(VK_DOWN))
		_angle += 0.01f;
	_cannon->SetAngle(_angle);

	if (GetAsyncKeyState(VK_SPACE) & 0x0001)
		_cannon->Fire();

	for (auto bullet : _cannon->GetBullets())
	{
		if (_cannon2->IsCollision(bullet))
		{
			_cannon2->_isActive = false;
			bullet->SetActive(false);
		}
	}
}

void FortrissScene::Render(HDC hdc)
{
	_cannon->Render(hdc);
	_cannon2->Render(hdc);
}
