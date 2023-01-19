#include "framework.h"
#include "Cup_Player.h"

Cup_Player::Cup_Player()
{
	_transform = make_shared<Transform>();
	_firePos = make_shared<Transform>();
	_firePos->SetParent(_transform);
	_firePos->GetPos().x += 50;
	_collider = make_shared<CircleCollider>(30);
	_collider->GetTransform()->SetParent(_transform);
	CreateAction("Idle");
	CreateAction("Run");
	CreateAction("AimStraightShot");
	CreateAction("Jump");

	_actions[State::IDLE]->SetSpeed(0.1f);
	_actions[State::RUN]->SetSpeed(0.07f);
	_actions[State::SHOT]->SetRepeatType(Action::Type::END);
	_actions[State::SHOT]->SetEndEvent(std::bind(&Cup_Player::SetIdle, this));

	_transform->GetPos() = { CENTER_X, CENTER_Y - 200 };

	for (int i = 0; i < 30; i++)
	{
		shared_ptr<Cup_Bullet> bullet = make_shared<Cup_Bullet>();
		_bullets.push_back(bullet);
	}

	SOUND->Add("cup_jump", "Resource/Sound/jump.wav");
	EFFECT->AddEffect(L"Effects/JumpDustA.png", Vector2(2, 10), Vector2(70, 70), 0.1f, Action::END, true);

	_state = State::JUMP;
}

Cup_Player::~Cup_Player()
{
}

void Cup_Player::Update()
{
	Jump();
	Shot();
	Input();

	_transform->Update();
	_firePos->Update();
	_collider->Update();
	_actions[_state]->Update();
	_sprites[_state]->Update();

	for (auto bullet : _bullets)
		bullet->Update();
}

void Cup_Player::Render()
{
	_sprites[_state]->SetSpriteAction(_actions[_state]->GetCurClip());
	_sprites[_state]->Render();
	_collider->Render();

	for (auto bullet : _bullets)
		bullet->Render();
}

void Cup_Player::PostRender()
{
	ImGui::SliderInt("State", (int*)&_state, 0, 1);
}


void Cup_Player::Init()
{
	for (auto bullet : _bullets)
		bullet->isActive = false;
}

void Cup_Player::Input()
{
	if (_state == State::SHOT || _state == State::JUMP)
		return;

	_state = State::IDLE;
	if (KEY_PRESS('A'))
	{
		_transform->GetPos().x -= DELTA_TIME * _speed;
		SetLeft();
		_state = State::RUN;
	}
	if (KEY_PRESS('D'))
	{
		_transform->GetPos().x += DELTA_TIME * _speed;
		SetRight();
		_state = State::RUN;
	}
}

void Cup_Player::Jump()
{
	if (KEY_DOWN(VK_SPACE))
	{
		_state = State::JUMP;
		_actions[_state]->Play();
		_jumpPower = 500.0f;
		SOUND->Play("cup_jump");
	}

	if (KEY_PRESS('A') && _state == JUMP)
	{
		_transform->GetPos().x -= DELTA_TIME * _speed;
		SetLeft();
	}
	if (KEY_PRESS('D') && _state == JUMP)
	{
		_transform->GetPos().x += DELTA_TIME * _speed;
		SetRight();
	}

	_transform->GetPos().y += _jumpPower * DELTA_TIME;

	_jumpPower -= GRAVITY * GRAVITY * DELTA_TIME;

	if (_transform->GetPos().y < 160.0f)
	{
		_transform->GetPos().y = 160.0f;
		_jumpPower = 0.0f;

		if (_state == State::JUMP)
		{
			Vector2 dustPos = _transform->GetPos();
			dustPos.y -= 50;
			EFFECT->Play("JumpDustA", dustPos);
			_state = State::IDLE;
		}
	}
}

void Cup_Player::Shot()
{
	if (KEY_DOWN(VK_LBUTTON))
	{
		_state = State::SHOT;
		_actions[_state]->Play();

		for (auto bullet : _bullets)
		{
			if (bullet->isActive == false)
			{
				bullet->isActive = true;
				bullet->SetDirection(_firePos->GetPos().Normal());
				bullet->GetTransform()->GetPos() = _firePos->GetWorldPos();
				bullet->GetTransform()->Update();
				break;
			}
		}
	}
}

void Cup_Player::SetIdle()
{
	_state = State::IDLE;
}

void Cup_Player::CreateAction(string state)
{
	wstring path = wstring(state.begin(), state.end());
	path = L"CupHead/Player/" + path + L".png";
	MyXML xml = MyXML(path);

	shared_ptr<Sprite> sprite;
	
	Vector2 averWH = xml.GetAverage();
	sprite = make_shared<Sprite>(path, averWH);
	sprite->GetTransform()->SetParent(_transform);

	_sprites.push_back(sprite);
	vector<Action::Clip> clips = xml.GetClips();
	shared_ptr<Action> action = make_shared<Action>(clips, state, Action::LOOP, 0.1f);
	action->Play();
	_actions.push_back(action);
}

void Cup_Player::SetLeft()
{
	_firePos->GetPos().x = -30;
	for (auto sprite : _sprites)
	{
		sprite->SetLeft();
	}
}

void Cup_Player::SetRight()
{
	_firePos->GetPos().x = 30;
	for (auto sprite : _sprites)
	{
		sprite->SetRight();
	}
}
