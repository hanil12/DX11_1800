#include "framework.h"
#include "AvoidDDong.h"

AvoidDDong::AvoidDDong()
{
	_player = make_shared<AvoidPlayer>();
	_bg = make_shared<AD_BackGround>();
	_bg->Update();

	_player->SetLeftRight(_bg->LeftRight());

	for (int i = 0; i < 50; i++)
	{
		shared_ptr<DDong> ddong = make_shared<DDong>();
		ddong->Init();
		_ddongs.push_back(ddong);
	}
}

AvoidDDong::~AvoidDDong()
{
}

void AvoidDDong::PreRender()
{
	_bg->Render();
}

void AvoidDDong::Update()
{
	_player->Update();

	for (auto ddong : _ddongs)
		ddong->Update();

	for (auto ddong : _ddongs)
	{
		if (ddong->IsCollisionWithPlayer(_player))
		{
			ddong->Init();
			--_player->GetHP();
		}
	}

	if (_check > _delay)
	{
		for (auto ddong : _ddongs)
		{
			if (ddong->_isActive == false)
			{
				ddong->_isActive = true;
				_check = 0.0f;
				break;
			}
		}
	}

	_check += DELTA_TIME;

	if (_player->GetHP() <= 0)
		_player->_isActive = false;
}

void AvoidDDong::Render()
{
	_player->Render();

	for (auto ddong : _ddongs)
		ddong->Render();

	int playerHP = _player->GetHP();
	ImGui::SliderInt("HP", &playerHP, 0, 10);
}
