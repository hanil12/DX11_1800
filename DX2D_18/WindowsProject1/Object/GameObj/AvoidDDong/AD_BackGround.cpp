#include "framework.h"
#include "AD_BackGround.h"

AD_BackGround::AD_BackGround()
{
	_quad = make_shared<Quad>(L"BattleMaster.png");
	_quad->GetTransform()->GetPos() = { CENTER_X, CENTER_Y };
}

AD_BackGround::~AD_BackGround()
{
}

Vector2 AD_BackGround::LeftRight()
{
	Vector2 result;
	result.x = _quad->GetTransform()->GetPos().x - _quad->GetSize().x * 0.5f;
	result.y = _quad->GetTransform()->GetPos().x + _quad->GetSize().x * 0.5f;

	return result;
}

void AD_BackGround::Update()
{
	_quad->Update();
}

void AD_BackGround::Render()
{
	_quad->Render();
}
