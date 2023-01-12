#include "framework.h"
#include "Cup_Boss.h"

Cup_Boss::Cup_Boss()
{
	CreateAction();
	CreateBullets();

	_transform = make_shared<Transform>();
	_firePos = make_shared<Transform>();

	_sprite->GetTransform()->SetParent(_transform);
	_collider->GetTransform()->SetParent(_transform);

	_transform->GetPos() = { CENTER_X, CENTER_Y };
	_firePos->SetParent(_transform);
	_firePos->GetPos().x -= 70.0f;

}

Cup_Boss::~Cup_Boss()
{
}

void Cup_Boss::CreateAction()
{
	MyXML xml = MyXML(L"CupHead/Boss/Clown_Page_Last_Spawn_Penguin_Start.png");
	vector<Action::Clip> clips = xml.GetClips();
	Vector2 averageSize = xml.GetAverage();
	_action = make_shared<Action>(clips, "BossIDLE");
	_sprite = make_shared<Sprite>(L"CupHead/Boss/Clown_Page_Last_Spawn_Penguin_Start.png", averageSize);
	averageSize.x *= 0.8f;
	averageSize.y *= 0.9f;
	_collider = make_shared<RectCollider>(averageSize);
}

void Cup_Boss::Update()
{
	_fireCheck += DELTA_TIME;

	_transform->Update();
	_firePos->Update();

	_action->Update();
	_sprite->SetSpriteAction(_action->GetCurClip());
	_sprite->Update();
	_collider->Update();

	for (auto bullet : _bullets)
	{
		bullet->Update();
	}
}

void Cup_Boss::Render()
{
	_sprite->Render();
	_collider->Render();

	for (auto bullet : _bullets)
	{
		bullet->Render();
	}
}

void Cup_Boss::CreateBullets()
{
	for (int i = 0; i < 30; i++)
	{
		shared_ptr<Cup_Bullet> bullet = make_shared<Cup_Bullet>();
		bullet->isActive = false;
		_bullets.push_back(bullet);
	}
}

void Cup_Boss::Fire(shared_ptr<Cup_Player> player)
{
	if (_fireCheck > _fireDelay)
		_fireCheck = 0.0f;
	else
		return;

	for (auto bullet : _bullets)
	{
		if (bullet->isActive == false)
		{
			bullet->isActive = true;

			Vector2 dir = player->GetTransform()->GetWorldPos() - _firePos->GetWorldPos();
			bullet->GetTransform()->SetPos(_firePos->GetWorldPos());
			bullet->SetDirection(dir.Normal());

			break;
		}
	}
}

void Cup_Boss::Attack(shared_ptr<Cup_Player> player)
{
	if (player == nullptr)
		return;

	for (auto bullet : _bullets)
	{
		if (bullet->IsCollision(player->GetCollider()))
		{
			bullet->isActive = false;
			return;
		}
	}
}

void Cup_Boss::Fire()
{
	if (_player.expired() == true)
		return;

	if (_fireCheck > _fireDelay)
		_fireCheck = 0.0f;
	else
		return;

	for (auto bullet : _bullets)
	{
		if (bullet->isActive == false)
		{
			bullet->isActive = true;

			Vector2 dir = _player.lock()->GetTransform()->GetWorldPos() - _firePos->GetWorldPos();
			bullet->GetTransform()->GetPos() = _firePos->GetWorldPos();
			bullet->SetDirection(dir.Normal());

			break;
		}
	}
}
