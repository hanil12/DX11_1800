#include "framework.h"
#include "DDong.h"

DDong::DDong()
{
	_quad = make_shared<Quad>(L"DDong.png", Vector2(100, 100));
	_quad->GetTransform()->GetPos() = Vector2(CENTER_X, CENTER_Y);

	_circleCol = make_shared<CircleCollider>(25);
	_circleCol->GetTransform()->SetParent(_quad->GetTransform());
}

DDong::~DDong()
{
}

void DDong::Update()
{
	if (_isActive == false)
		return;

	if (_quad->GetTransform()->GetPos().y < 0)
	{
		Init();
		return;
	}

	_quad->GetTransform()->GetPos().y -= _speed * DELTA_TIME;

	_quad->Update();
	_circleCol->Update();
}

void DDong::Render()
{
	if (_isActive == false)
		return;

	_quad->Render();
	_circleCol->Render();
}

void DDong::Init()
{
	_quad->GetTransform()->GetPos().x = rand() % WIN_WIDTH;
	_quad->GetTransform()->GetPos().y = WIN_HEIGHT + 50;
	_quad->GetTransform()->Update();
	_isActive = false;
}

bool DDong::IsCollisionWithPlayer(shared_ptr<AvoidPlayer> player)
{
	if (_isActive == false || player->_isActive == false)
		return false;

	return _circleCol->IsCollision(player->GetCollider());
}
