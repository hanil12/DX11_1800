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
	if (KEY_DOWN(VK_LBUTTON))
	{

		_player->Fire(mousePos);
	}

	_player->Update();
}

void GunGreed::Render()
{
	_player->Render();
}
