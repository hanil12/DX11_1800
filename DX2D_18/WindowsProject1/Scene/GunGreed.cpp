#include "framework.h"
#include "GunGreed.h"

GunGreed::GunGreed()
{
	_player = make_shared<Player>();
	_player->Move({ CENTER_X,CENTER_Y });

	_target = make_shared<RectCollider>(Vector2(50, 50));
	_target->GetTransform()->GetPos() = { CENTER_X + 300 ,CENTER_Y };
}

GunGreed::~GunGreed()
{
}

void GunGreed::Update()
{
	if (KEY_DOWN(VK_F1))
	{
		Collider::_isDebug = !Collider::_isDebug;
	}

	if (KEY_DOWN(VK_LBUTTON) && !ImGui::GetIO().WantCaptureMouse)
	{
		_player->Fire(mousePos);
	}

	for (auto bullet : _player->GetGun()->GetBullets())
	{
		if (bullet->IsCollision(_target))
		{
			_target->SetRED();
			break;
		}
		else
		{
			_target->SetGREEN();
		}
	}

	_player->Update();
	_target->Update();
}

void GunGreed::Render()
{
	_player->Render();
	_target->Render();

	ImGui::SliderFloat("PosX", &_player->GetTransform()->GetPos()._x, 0, WIN_WIDTH);
	ImGui::SliderFloat("PosY", &_player->GetTransform()->GetPos()._y, 0, WIN_HEIGHT);
}
