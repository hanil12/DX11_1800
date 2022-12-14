#include "framework.h"
#include "GunGreed.h"

GunGreed::GunGreed()
{
	_player = make_shared<Player>();
	_player->Move({ CENTER_X,CENTER_Y });
}

GunGreed::~GunGreed()
{
}

void GunGreed::Update()
{
	if (KEY_DOWN(VK_LBUTTON) && !ImGui::GetIO().WantCaptureMouse)
	{
		_player->Fire(mousePos);
	}

	_player->Update();
}

void GunGreed::Render()
{
	_player->Render();

	ImGui::SliderFloat("PosX", &_player->GetTransform()->GetPos()._x, 0, WIN_WIDTH);
	ImGui::SliderFloat("PosY", &_player->GetTransform()->GetPos()._y, 0, WIN_HEIGHT);
}
