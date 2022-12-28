#include "framework.h"
#include "Cup_Player.h"

Cup_Player::Cup_Player()
{
	_sprite = make_shared<Sprite>(L"CupHead/Idle.png", Vector2(5, 1), Vector2(150, 150));
	_collider = make_shared<CircleCollider>(30);
	_collider->GetTransform()->SetParent(_sprite->GetTransform());
	CreateAction();

	_sprite->GetTransform()->GetPos() = { CENTER_X, CENTER_Y };
}

Cup_Player::~Cup_Player()
{
}

void Cup_Player::Input()
{
	if (KEY_PRESS('A'))
	{
		_sprite->GetTransform()->GetPos().x -= DELTA_TIME * _speed;
		_sprite->SetLeftRight(1);
	}
	if (KEY_PRESS('D'))
	{
		_sprite->GetTransform()->GetPos().x += DELTA_TIME * _speed;
		_sprite->SetLeftRight(0);
	}
}

void Cup_Player::Update()
{
	Input();

	_action->Update();
	_collider->Update();
	_sprite->Update();
}

void Cup_Player::Render()
{
	_sprite->SetSprite(_action->GetCurClip());
	_sprite->Render();
	_collider->Render();
}

void Cup_Player::PostRender()
{
	ImGui::Text(_text.c_str());
}

void Cup_Player::CreateAction()
{
	shared_ptr<SRV> srv = SRVManager::GetInstance()->AddSRV(L"CupHead/Idle.png");
	vector<Action::Clip> clips;

	// <sprite n = "cuphead_idle (0).png" x = "1" y = "1" w = "300" h = "300" pX = "0.5" pY = "0.5" / >
	// <sprite n = "cuphead_idle_0001 (1).png" x = "303" y = "1" w = "300" h = "300" pX = "0.5" pY = "0.5" / >
	// <sprite n = "cuphead_idle_0001 (2).png" x = "605" y = "1" w = "300" h = "300" pX = "0.5" pY = "0.5" / >
	// <sprite n = "cuphead_idle_0001 (3).png" x = "907" y = "1" w = "300" h = "300" pX = "0.5" pY = "0.5" / >
	// <sprite n = "cuphead_idle_0001 (4).png" x = "1209" y = "1" w = "300" h = "300" pX = "0.5" pY = "0.5" / >
	Action::Clip clip1 = Action::Clip(1, 1, 300, 300, srv);
	Action::Clip clip2 = Action::Clip(303, 1, 300, 300, srv);
	Action::Clip clip3 = Action::Clip(605, 1, 300, 300, srv);
	Action::Clip clip4 = Action::Clip(907, 1, 300, 300, srv);
	Action::Clip clip5 = Action::Clip(1209, 1, 300, 300, srv);
	clips.push_back(clip1);
	clips.push_back(clip2);
	clips.push_back(clip3);
	clips.push_back(clip4);
	clips.push_back(clip5);

	_action = make_shared<Action>(clips, "CUP_IDLE", Action::END, 0.2f);
	_action->Play();
}
