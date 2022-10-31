#include "framework.h"
#include "FortrissScene.h"

FortrissScene::FortrissScene()
{
	_cannon = make_shared<Cannon>();
}

FortrissScene::~FortrissScene()
{
}

void FortrissScene::Update()
{
	_cannon->Update();

	if (GetAsyncKeyState(VK_LEFT))
		_cannon->MoveLeft();
	if (GetAsyncKeyState(VK_RIGHT))
		_cannon->MoveRight();
	if (GetAsyncKeyState(VK_UP))
		_cannon->GetAngle() -= 0.01f;
	if (GetAsyncKeyState(VK_DOWN))
		_cannon->GetAngle() += 0.01f;
}

void FortrissScene::Render(HDC hdc)
{
	_cannon->Render(hdc);
}
