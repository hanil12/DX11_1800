#include "framework.h"
#include "GunGreed.h"

GunGreed::GunGreed()
{
	_player = make_shared<Quad>(L"player.png");
	_player2 = make_shared<Quad>(L"player.png");
	_gun = make_shared<Quad>(L"railgun.png");

	_player->GetTransform()->GetPos() = { CENTER_X, CENTER_Y };
	_player2->GetTransform()->GetPos() = { CENTER_X - 150, CENTER_Y - 150 };

	_player->GetTransform()->GetScale() *= 0.5;
	_player2->GetTransform()->GetScale() *= 0.5;

	_gun->GetTransform()->SetParent(_player->GetTransform());
	_gun->GetTransform()->GetPos()._x += 300;
}

GunGreed::~GunGreed()
{
}

void GunGreed::Update()
{
	_player->Update();
	_player2->Update();
	_gun->Update();

	Vector2 dest = mousePos - _gun->GetTransform()->GetWorldPos();

	_gun->GetTransform()->GetAngle() = dest.Angle();
}

void GunGreed::Render()
{
	_player->Render();
	_player2->Render();
	_gun->Render();
}
